/* Copyright (c) 2026 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "xxfclib/rt/xx_rt.h"
#include "xx_lzma_internal.h"
#include "platforms/xx_lzma_platform.h"
#include "xx_lzma2_filters_internal.h"
#include "asm/xx_lzma_asm.h"
#include <string.h>
#include "LzmaDec.c"

/* Memory allocator adapter for 7-Zip CLzmaDec */
static void *xx_sz_alloc(ISzAllocPtr p, size_t size) { (void)p; return xx_mem_alloc(size); }
static void xx_sz_free(ISzAllocPtr p, void *address) { (void)p; xx_mem_free(address); }
static const ISzAlloc g_xx_sz_alloc = { xx_sz_alloc, xx_sz_free };

/* =========================================================================
 * Range decoder
 * ========================================================================= */

static bool rd_refill(lzma_range_dec *rd)
{
    if (rd->error || rd->eof) return false;
    if (rd->ibuf_pos < rd->ibuf_len) return true;

    if (!rd->ibuf) {
        if (!rd->ibuf_capacity) rd->ibuf_capacity = xx_get_file_buffer_size();
        if (rd->ibuf_capacity < (256 * 1024)) rd->ibuf_capacity = (256 * 1024);
        rd->ibuf = (uint8_t *)xx_mem_alloc(rd->ibuf_capacity);
        if (!rd->ibuf) {
            rd->error = true;
            return false;
        }
    }
    size_t want = rd->ibuf_capacity;
    if (rd->remaining >= 0) {
        if (rd->remaining == 0) {
            rd->eof = true;
            return false;
        }
        if ((uint64_t)want > (uint64_t)rd->remaining) want = (size_t)rd->remaining;
    }

    ssize_t got;
    if (rd->dev) {
        got = xx_io_read(rd->dev, rd->ibuf, want);
    } else {
        size_t avail = rd->mem_size - rd->mem_pos;
        got = avail == 0 ? 0 : (ssize_t)(avail < want ? avail : want);
        if (got > 0) {
            xx_rt_memcpy(rd->ibuf, rd->mem + rd->mem_pos, (size_t)got);
            rd->mem_pos += (size_t)got;
        }
    }
    if (got <= 0 || (size_t)got > want) {
        rd->eof = true;
        rd->error = true;
        return false;
    }
    if (rd->remaining >= 0) rd->remaining -= got;
    rd->ibuf_pos = 0;
    rd->ibuf_len = (size_t)got;
    return true;
}

static XX_LZMA_INLINE uint8_t rd_byte(lzma_range_dec *rd)
{
    if (rd->ibuf_pos < rd->ibuf_len) {
        return rd->ibuf[rd->ibuf_pos++];
    }
    if (!rd_refill(rd)) {
        rd->error = true;
        return 0;
    }
    return rd->ibuf[rd->ibuf_pos++];
}

static uint64_t rd_bytes_left(const lzma_range_dec *rd)
{
    uint64_t buffered = (uint64_t)(rd->ibuf_len - rd->ibuf_pos);
    return buffered + (rd->remaining > 0 ? (uint64_t)rd->remaining : 0u);
}

static bool rd_read_exact(lzma_range_dec *rd, uint8_t *data, size_t size, xx_pd_struct *pd, const xx_lzma_platform *platform)
{
    while (size != 0) {
        size_t amount;
        if (pd && xx_pd_is_stopped(pd)) return false;
        if (!rd_refill(rd)) {
            rd->error = true;
            return false;
        }
        amount = rd->ibuf_len - rd->ibuf_pos;
        if (amount > size) amount = size;
        if (pd && amount > 4096) amount = 4096;
        platform->copy(data, rd->ibuf + rd->ibuf_pos, amount);
        rd->ibuf_pos += amount;
        data += amount;
        size -= amount;
    }
    return true;
}

static bool lzma_rd_init_sized(lzma_range_dec *rd, xx_io_device *dev, const uint8_t *mem, size_t mem_size, int64_t remaining, size_t capacity)
{
    xx_rt_memset(rd, 0, sizeof(*rd));
    rd->dev = dev;
    rd->mem = mem;
    rd->mem_size = mem_size;
    rd->remaining = remaining;
    rd->range = 0xFFFFFFFFu;
    rd->ibuf_capacity = capacity;
    if ((!dev && !mem) || (remaining >= 0 && remaining < 5) || (mem && (uint64_t)remaining > (uint64_t)mem_size)) return false;
    return true;
}

bool lzma_rd_init(lzma_range_dec *rd, xx_io_device *dev, const uint8_t *mem, size_t mem_size, int64_t remaining)
{
    return lzma_rd_init_sized(rd, dev, mem, mem_size, remaining, xx_get_file_buffer_size());
}

void lzma_rd_free(lzma_range_dec *rd)
{
    if (!rd) return;
    xx_mem_free(rd->ibuf);
    rd->ibuf = NULL;
    rd->ibuf_capacity = rd->ibuf_pos = rd->ibuf_len = 0;
}

/* =========================================================================
 * LZMA properties
 * ========================================================================= */

bool lzma_parse_props(const uint8_t *props, size_t props_size, lzma_props *out)
{
    if (!props || props_size < XX_LZMA_PROPS_SIZE) return false;
    int d = props[0];
    if (d >= 9 * 5 * 5) return false;
    out->pb = d / (9 * 5);
    d -= out->pb * 9 * 5;
    out->lp = d / 9;
    out->lc = d - out->lp * 9;
    if (out->lc + out->lp > 4) return false;
    uint32_t ds = (uint32_t)props[1] | ((uint32_t)props[2] << 8) | ((uint32_t)props[3] << 16) | ((uint32_t)props[4] << 24);
    if (ds > XX_LZMA_MAX_DICT_SIZE) return false;
    out->dict_size = ds;
    return true;
}

/* =========================================================================
 * Output helpers (Direct Dictionary Output)
 * ========================================================================= */

typedef struct {
    xx_io_device *dev;
    uint8_t *mem;
    size_t mem_cap;
    size_t mem_written;
    uint64_t total_written;
    bool error;
    xx_pd_struct *pd;
} lzma_out;

static bool flush_direct(lzma_out *o, const uint8_t *src, size_t count)
{
    if (count == 0) return true;
    if (o->dev) {
        size_t done = 0;
        while (done < count) {
            if (o->pd && xx_pd_is_stopped(o->pd)) {
                o->error = true;
                return false;
            }
            ssize_t amount = xx_io_write(o->dev, src + done, count - done);
            if (amount <= 0 || (size_t)amount > count - done) {
                o->error = true;
                return false;
            }
            done += (size_t)amount;
        }
    } else if (o->mem) {
        if (o->mem_written > o->mem_cap || count > o->mem_cap - o->mem_written) {
            o->error = true;
            return false;
        }
        xx_rt_memcpy(o->mem + o->mem_written, src, count);
        o->mem_written += count;
    } else {
        /* Discard sink (dry run / test mode) */
    }
    o->total_written += count;
    return true;
}

/* =========================================================================
 * Decoder state lifecycle
 * ========================================================================= */


static bool lzma_dict_flush(lzma_decoder *dec, lzma_out *o)
{
    while (dec->dec.dicPos > dec->dict_flush_pos) {
        size_t start = (size_t)dec->dict_flush_pos;
        size_t end = (size_t)dec->dec.dicPos;
        size_t count = end - start;
        if (count == 0) break;
        if (!flush_direct(o, dec->dec.dic + start, count)) return false;
        dec->dict_flush_pos += count;
    }
    return true;
}

static void lzma_dec_reset_dictionary(lzma_decoder *dec)
{
    LzmaDec_InitDicAndState(&dec->dec, True, True);
    dec->dict_flush_pos = 0;
    dec->dict_filled = 0;
}

static void lzma_dec_reset_model(lzma_decoder *dec)
{
    LzmaDec_InitDicAndState(&dec->dec, False, True);
}

static bool lzma_dec_set_lclppb(lzma_decoder *dec, int lc, int lp, int pb)
{
    if (lc < 0 || lp < 0 || pb < 0 || lc > 8 || lp > 4 || pb > 4 || lc + lp > 4) return false;
    dec->dec.prop.lc = (Byte)lc;
    dec->dec.prop.lp = (Byte)lp;
    dec->dec.prop.pb = (Byte)pb;
    dec->props.lc = lc;
    dec->props.lp = lp;
    dec->props.pb = pb;
    return true;
}

static uint32_t lzma_dict_index(const lzma_decoder *dec, uint64_t position)
{
    if ((dec->dict_limit & (dec->dict_limit - 1u)) == 0) return (uint32_t)position & (dec->dict_limit - 1u);
    return (uint32_t)(position % dec->dict_limit);
}

lzma_decoder *lzma_dec_create(const lzma_props *props)
{
    lzma_decoder *dec = (lzma_decoder *)xx_mem_alloc(sizeof(lzma_decoder));
    if (!dec) return NULL;
    xx_rt_memset(dec, 0, sizeof(*dec));
    dec->props = *props;

    Byte raw_props[5];
    raw_props[0] = (Byte)((props->pb * 5 + props->lp) * 9 + props->lc);
    raw_props[1] = (Byte)(props->dict_size);
    raw_props[2] = (Byte)(props->dict_size >> 8);
    raw_props[3] = (Byte)(props->dict_size >> 16);
    raw_props[4] = (Byte)(props->dict_size >> 24);

    LzmaDec_Construct(&dec->dec);
    SRes res = LzmaDec_Allocate(&dec->dec, raw_props, 5, &g_xx_sz_alloc);
    if (res != SZ_OK) {
        xx_mem_free(dec);
        return NULL;
    }
    LzmaDec_Init(&dec->dec);

    dec->dict_limit = props->dict_size;
    dec->dict_mask = (dec->dec.dicBufSize & (dec->dec.dicBufSize - 1)) == 0 ? (uint32_t)(dec->dec.dicBufSize - 1) : UINT32_MAX;
    dec->dict_flush_pos = 0;
    dec->dict_filled = 0;
    return dec;
}

void lzma_dec_free(lzma_decoder *dec)
{
    if (!dec) return;
    LzmaDec_Free(&dec->dec, &g_xx_sz_alloc);
    xx_mem_free(dec);
}

/* =========================================================================
 * LZMA block decompression
 * ========================================================================= */

static bool lzma_decode_block(lzma_range_dec *rd, lzma_decoder *dec, int64_t uncomp_size, lzma_out *out, xx_pd_struct *pd)
{
    CLzmaDec *p = &dec->dec;
    int64_t total_out = 0;

    while (uncomp_size < 0 || total_out < uncomp_size) {
        if (rd->error || out->error || (pd && xx_pd_is_stopped(pd))) return false;

        /* Dictionary wrap-around */
        if (p->dicPos == p->dicBufSize) {
            if (!lzma_dict_flush(dec, out)) return false;
            p->dicPos = 0;
            dec->dict_flush_pos = 0;
        }

        size_t dic_limit = p->dicBufSize;
        if (uncomp_size >= 0) {
            int64_t rem = uncomp_size - total_out;
            if ((size_t)rem < dic_limit - p->dicPos) {
                dic_limit = p->dicPos + (size_t)rem;
            }
        }

        if (rd->ibuf_pos >= rd->ibuf_len) {
            if (!rd_refill(rd)) {
                if (uncomp_size < 0) {
                    SizeT in_size = 0;
                    ELzmaStatus status;
                    (void)LzmaDec_DecodeToDic(p, dic_limit, p->tempBuf, &in_size, LZMA_FINISH_END, &status);
                }
                break;
            }
        }

        SizeT in_size = rd->ibuf_len - rd->ibuf_pos;
        ELzmaStatus status;
        SizeT cur_dic_pos = p->dicPos;
        ELzmaFinishMode finish_mode = (uncomp_size < 0) ? LZMA_FINISH_END : LZMA_FINISH_ANY;

        SRes res = LzmaDec_DecodeToDic(p, dic_limit, rd->ibuf + rd->ibuf_pos, &in_size, finish_mode, &status);
        rd->ibuf_pos += in_size;

        size_t produced = p->dicPos - cur_dic_pos;
        total_out += produced;
        dec->dict_filled += (uint32_t)produced;
        if (dec->dict_filled > dec->dict_limit) dec->dict_filled = dec->dict_limit;

        /* Direct Dictionary flush: threshold 1MB */
        if (p->dicPos - dec->dict_flush_pos >= 1048576) {
            if (!lzma_dict_flush(dec, out)) return false;
        }

        if (res != SZ_OK) return false;
        if (status == LZMA_STATUS_FINISHED_WITH_MARK) break;
        if (uncomp_size >= 0 && total_out >= uncomp_size) break;
        if (status == LZMA_STATUS_MAYBE_FINISHED_WITHOUT_MARK && (uncomp_size >= 0 && total_out == uncomp_size)) break;
        if (in_size == 0 && produced == 0) {
            if (rd->ibuf_pos >= rd->ibuf_len && rd->eof) break;
        }
    }

    if (!lzma_dict_flush(dec, out)) return false;
    rd->range = p->range;
    rd->code = p->code;
    return !rd->error && !out->error;
}

/* =========================================================================
 * Public LZMA decompression entry point
 * ========================================================================= */

bool xx_lzma_decompress_stream(lzma_range_dec *rd, const lzma_props *props, int64_t uncomp_size, xx_io_device *dst_dev, uint8_t *mem_dst, size_t mem_cap,
                               size_t *out_written, xx_pd_struct *pd)
{
    lzma_decoder *dec = lzma_dec_create(props);
    if (!dec) return false;

    lzma_out out;
    xx_rt_memset(&out, 0, sizeof(out));
    out.dev = dst_dev;
    out.mem = mem_dst;
    out.mem_cap = mem_cap;
    out.pd = pd;

    bool ok = lzma_decode_block(rd, dec, uncomp_size, &out, pd);

    if (ok) ok = lzma_dict_flush(dec, &out);
    else if (rd->eof && !out.error && !(pd && xx_pd_is_stopped(pd))) (void)lzma_dict_flush(dec, &out);
    if (ok && uncomp_size >= 0 && (int64_t)out.total_written != uncomp_size) ok = false;
    if (out_written) *out_written = ok ? (size_t)out.total_written : 0;

    lzma_dec_free(dec);
    return ok && !out.error;
}

/* =========================================================================
 * LZMA2 decompression
 * ========================================================================= */

bool xx_lzma2_decompress_stream(lzma_range_dec *rd, uint8_t props2_byte, xx_io_device *dst_dev, uint8_t *mem_dst, size_t mem_cap, size_t *out_written, xx_pd_struct *pd)
{
    const xx_lzma_platform *platform = xx_lzma_platform_select();
    uint32_t logical_dict;
    uint32_t allocation_size = 4096;
    uint8_t *packed = NULL;
    lzma_decoder *dec = NULL;
    bool dictionary_initialized = false;
    bool state_initialized = false;
    bool properties_initialized = false;
    bool saw_end = false;
    bool ok = false;
    lzma_out out;
    lzma_props props;

    if (out_written) *out_written = 0;
    if (!rd || (!dst_dev && !mem_dst && mem_cap != 0) || !xx_lzma2_parse_property(props2_byte, &logical_dict) || rd_bytes_left(rd) == 0) return false;
    xx_rt_memset(&out, 0, sizeof(out));
    if (!rd->ibuf_capacity) rd->ibuf_capacity = xx_get_file_buffer_size();

    while ((uint64_t)allocation_size < logical_dict) allocation_size <<= 1;

    xx_rt_memset(&props, 0, sizeof(props));
    props.lc = 3;
    props.lp = 0;
    props.pb = 2;
    props.dict_size = allocation_size;
    dec = lzma_dec_create(&props);
    if (!dec) return false;
    dec->dict_limit = (uint32_t)logical_dict;

    packed = (uint8_t *)xx_mem_alloc(65536u);
    if (!packed) goto cleanup;

    out.dev = dst_dev;
    out.mem = mem_dst;
    out.mem_cap = mem_cap;
    out.pd = pd;

    while (!saw_end) {
        uint8_t ctrl;
        if (pd && xx_pd_is_stopped(pd)) goto cleanup;
        ctrl = rd_byte(rd);
        if (rd->error) goto cleanup;

        if (ctrl == LZMA2_CONTROL_EOF) {
            if (rd_bytes_left(rd) != 0) goto cleanup;
            saw_end = true;
            break;
        }

        if (ctrl == LZMA2_CONTROL_COPY_NO_DICT || ctrl == LZMA2_CONTROL_COPY_DICT) {
            uint8_t size_bytes[2];
            uint32_t chunk_size;
            if (!rd_read_exact(rd, size_bytes, sizeof(size_bytes), pd, platform)) goto cleanup;
            chunk_size = (((uint32_t)size_bytes[0] << 8) | size_bytes[1]) + 1u;
            if (ctrl == LZMA2_CONTROL_COPY_NO_DICT) {
                if (!lzma_dict_flush(dec, &out)) goto cleanup;
                lzma_dec_reset_dictionary(dec);
                dictionary_initialized = true;
                state_initialized = false;
                properties_initialized = false;
            } else if (!dictionary_initialized) {
                goto cleanup;
            }
            if (!rd_read_exact(rd, packed, chunk_size, pd, platform)) goto cleanup;
            for (size_t at = 0; at < chunk_size;) {
                if (dec->dec.dicPos == dec->dec.dicBufSize) {
                    if (!lzma_dict_flush(dec, &out)) goto cleanup;
                    dec->dec.dicPos = 0;
                    dec->dict_flush_pos = 0;
                }
                size_t amount = dec->dec.dicBufSize - dec->dec.dicPos;
                if (amount > chunk_size - at) amount = chunk_size - at;
                xx_rt_memcpy(dec->dec.dic + dec->dec.dicPos, packed + at, amount);
                dec->dec.dicPos += amount;
                at += amount;
            }
            if (chunk_size >= dec->dict_limit - dec->dict_filled) dec->dict_filled = dec->dict_limit;
            else dec->dict_filled += chunk_size;
            if (!lzma_dict_flush(dec, &out)) goto cleanup;
            continue;
        }

        if (ctrl < 0x80) goto cleanup;
        {
            uint8_t header[4];
            uint8_t mode = (uint8_t)((ctrl >> 5) & 3u);
            uint32_t unpack_size;
            uint32_t packed_size;
            lzma_range_dec chunk_rd;

            if (!rd_read_exact(rd, header, sizeof(header), pd, platform)) goto cleanup;
            unpack_size = (((uint32_t)ctrl & 0x1Fu) << 16) | ((uint32_t)header[0] << 8) | header[1];
            packed_size = ((uint32_t)header[2] << 8) | header[3];
            unpack_size++;
            packed_size++;

            if (mode == 3) {
                if (!lzma_dict_flush(dec, &out)) goto cleanup;
                lzma_dec_reset_dictionary(dec);
                dictionary_initialized = true;
            } else if (!dictionary_initialized) {
                goto cleanup;
            }

            if (mode >= 2) {
                uint8_t property = rd_byte(rd);
                int lc, lp, pb;
                if (rd->error || property >= 9 * 5 * 5) goto cleanup;
                lc = property % 9;
                property = (uint8_t)(property / 9);
                lp = property % 5;
                pb = property / 5;
                if (!lzma_dec_set_lclppb(dec, lc, lp, pb)) goto cleanup;
                properties_initialized = true;
            } else if (!properties_initialized) {
                goto cleanup;
            }

            if (mode >= 1) {
                lzma_dec_reset_model(dec);
                state_initialized = true;
            } else if (!state_initialized) {
                goto cleanup;
            } else {
                LzmaDec_InitDicAndState(&dec->dec, False, False);
            }

            if (packed_size < RC_INIT_BYTES || !rd_read_exact(rd, packed, packed_size, pd, platform) ||
                !lzma_rd_init_sized(&chunk_rd, NULL, packed, packed_size, (int64_t)packed_size, rd->ibuf_capacity))
                goto cleanup;
            {
                bool chunk_ok = lzma_decode_block(&chunk_rd, dec, (int64_t)unpack_size, &out, pd);
                bool ran_out = !chunk_ok && chunk_rd.eof;
                chunk_ok = chunk_ok && !chunk_rd.error;
                lzma_rd_free(&chunk_rd);
                if (!chunk_ok) {
                    if (ran_out && !out.error && !(pd && xx_pd_is_stopped(pd))) (void)lzma_dict_flush(dec, &out);
                    goto cleanup;
                }
            }
            state_initialized = true;
        }
    }

    if (!saw_end) goto cleanup;
    if (!lzma_dict_flush(dec, &out)) goto cleanup;
    ok = true;

cleanup:
    if (out_written) *out_written = ok ? (size_t)out.total_written : 0;
    xx_mem_free(packed);
    lzma_dec_free(dec);
    return ok;
}
