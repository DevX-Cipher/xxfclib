/* Copyright (c) 2026 hors<horsicq@gmail.com> -- SPDX-License-Identifier: MIT
 * XArchive/archives/xlarcpfx.cpp: GEMDOS LArc PFX carrier. Known PFX 1.13P
 * instruction bodies use either an overstated LZ5 packed length bounded by
 * GEMDOS DATA, or an ordered chain of bounded members. This producer's LZ5
 * CRC field is non-authoritative; unrelated LHA and LH1 checks stay strict.
 * No executable bytes are run. */
#include "xxfclib/formats/archive/larc_pfx/xx_larc_pfx.h"
#include "xxfclib/data/xx_data.h"
#include "../lha/xx_lha_legacy_native.h"
#include "xxfclib/algo/lzh/xx_lzh.h"
#include "../../xx_payload_members.h"
#include "xx_larc_pfx_stub.h"
#define PFX_MAX_BUFFER (UINT64_C(256) * 1024U * 1024U)
typedef struct pfx_member {
    int64_t header_offset, header_size;
    uint32_t method;
    uint16_t crc;
    bool producer_crc;
} pfx_member;
static uint32_t pfx_be32(const uint8_t *p)
{
    return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | p[3];
}
static bool pfx_name(const uint8_t *p, size_t n, char *out)
{
    size_t i, component = 0;
    if (!n || n > 255 || p[0] == '/' || p[0] == '\\') return false;
    for (i = 0; i < n; ++i) {
        unsigned c = p[i];
        if (i == 1 && c == ':' && ((p[0] >= 'A' && p[0] <= 'Z') || (p[0] >= 'a' && p[0] <= 'z'))) c = '_';
        if (c == '\\') c = '/';
        if (c < 0x21 || c > 0x7e || c == ':' || c == '*' || c == '?' || c == '"' || c == '<' || c == '>' || c == '|') return false;
        if (c == '/') {
            if (i == component || (i - component == 1 && out[component] == '.') ||
                (i - component == 2 && out[component] == '.' && out[component + 1] == '.')) return false;
            component = i + 1;
        }
        out[i] = (char)c;
    }
    out[n] = 0;
    return component < n && xx_rt_strcmp(out + component, ".") && xx_rt_strcmp(out + component, "..");
}
static bool pfx_producer(Abstractformat *f, uint64_t text)
{
    uint8_t bytes[556];
    size_t size;
    const uint8_t *body;
    unsigned i;
    bool erased = true;
    if (text == sizeof(pfx_113p_standard_body) + 46U) {
        size = sizeof(pfx_113p_standard_body);
        body = pfx_113p_standard_body;
    } else if (text == sizeof(pfx_113p_compact_body) + 46U) {
        size = sizeof(pfx_113p_compact_body);
        body = pfx_113p_compact_body;
    } else if (text == sizeof(pfx_113p_long534_body) + 46U) {
        size = sizeof(pfx_113p_long534_body);
        body = pfx_113p_long534_body;
    } else if (text == sizeof(pfx_113p_long556_body) + 46U) {
        size = sizeof(pfx_113p_long556_body);
        body = pfx_113p_long556_body;
    } else return false;
    if (!pm_read(f, 28, bytes, 46) || bytes[0] != 0x60 || bytes[1] != 0x2c ||
        !pm_read(f, 74, bytes + 46, size) || xx_rt_memcmp(bytes + 46, body, size)) return false;
    for (i = 2; i < 46; ++i)
        if (bytes[i]) erased = false;
    /* Some PFX programs erase the text banner, while preserving every
     * instruction byte. A banner alone never relaxes payload checks. */
    return erased || !xx_rt_memcmp(bytes + 2, "LArc's PFX 1.13P", 16);
}
static uint16_t pfx_crc16(const uint8_t *bytes, size_t size)
{
    size_t i;
    unsigned bit;
    uint16_t crc = 0;
    for (i = 0; i < size; ++i) {
        crc ^= bytes[i];
        for (bit = 0; bit < 8; ++bit) crc = (uint16_t)((crc >> 1) ^ ((crc & 1) ? 0xa001 : 0));
    }
    return crc;
}
static bool pfx_read_all(Abstractformat *f, pm_member *m, xx_io_device *out, xx_pd_struct *pd)
{
    uint8_t *packed = NULL, *plain = NULL;
    size_t at = 0;
    bool valid = false;
    pfx_member *context = (pfx_member *)m->context;
    const xx_var *limit = xx_format_resolve_extra_parameter(f, NULL, XX_META_ID_OPT_MEMORY_LIMIT);
    if (m->packed_size <= 0 || m->size <= 0 || (uint64_t)m->packed_size > PFX_MAX_BUFFER || (uint64_t)m->size > PFX_MAX_BUFFER ||
        (limit && (uint64_t)m->packed_size + (uint64_t)m->size > xx_var_get_u64(limit)) || (pd && xx_pd_is_stopped(pd)))
        return false;
    packed = (uint8_t *)xx_mem_alloc((size_t)m->packed_size);
    plain = (uint8_t *)xx_mem_alloc((size_t)m->size);
    if (!packed || !plain) goto done;
    while (at < (size_t)m->packed_size) {
        size_t n = (size_t)m->packed_size - at;
        if (n > 65536) n = 65536;
        if ((pd && xx_pd_is_stopped(pd)) || !pm_read(f, m->offset - f->base_address + (int64_t)at, packed + at, n)) goto done;
        at += n;
    }
    if (context->method == XX_LHA_LEGACY_LZ5) {
        if (!xx_lha_legacy_decode_native(XX_LHA_LEGACY_LZ5, packed, (size_t)m->packed_size, plain, (size_t)m->size, pd)) goto done;
    } else if (context->method == UINT32_C(0x6c6831)) {
        size_t written = 0;
        if (!xx_lzh1_decode_memory(packed, (size_t)m->packed_size, plain, (size_t)m->size, &written) || written != (size_t)m->size) goto done;
    } else goto done;
    if (!context->producer_crc && pfx_crc16(plain, (size_t)m->size) != context->crc) {
        xx_pd_set_error(pd, 1, "PFX member payload CRC mismatch");
        goto done;
    }
    for (at = 0; out && at < (size_t)m->size;) {
        size_t n = (size_t)m->size - at;
        ssize_t wrote;
        if (n > 65536) n = 65536;
        if (pd && xx_pd_is_stopped(pd)) goto done;
        wrote = xx_io_write(out, plain + at, n);
        if (wrote <= 0 || (size_t)wrote > n) goto done;
        at += (size_t)wrote;
    }
    valid = !(pd && xx_pd_is_stopped(pd));
done:
    xx_mem_free(packed);
    xx_mem_free(plain);
    return valid;
}
static bool pfx_add(Abstractformat *f, pm_stream *s, const uint8_t *header, uint64_t at, unsigned hs, uint64_t packed, bool producer_crc, bool fallback_name)
{
    char name[256];
    pm_member *m;
    pfx_member *context;
    uint32_t method = xx_rt_memcmp(header + 2, "-lz5-", 5) ? UINT32_C(0x6c6831) : XX_LHA_LEGACY_LZ5;
    if (!pfx_name(header + 22, header[21], name)) {
        const char *source = xx_io_source_path(f->device), *leaf = source, *p;
        if (!fallback_name) return false;
        for (p = source; p && *p; ++p)
            if (*p == '/' || *p == '\\') leaf = p + 1;
        if (!leaf || !pfx_name((const uint8_t *)leaf, xx_rt_strlen(leaf), name)) xx_mem_copy(name, "data", 5);
    }
    if (!pm_add(f, s, "payload", (int64_t)(at + hs), (int64_t)packed)) return false;
    m = &s->items[s->count - 1];
    m->size = xx_data_get_u32(header + 11, 4, 0, false);
    m->read_all = pfx_read_all;
    m->display_name = xx_str_dup(name);
    context = (pfx_member *)xx_mem_alloc(sizeof(*context));
    if (!context || !m->display_name) {
        xx_mem_free(context);
        return false;
    }
    context->header_offset = f->base_address + (int64_t)at;
    context->header_size = hs;
    context->method = method;
    context->crc = xx_data_get_u16(header + 22 + header[21], 2, 0, false);
    context->producer_crc = producer_crc && method == XX_LHA_LEGACY_LZ5;
    m->context = context;
    m->free_context = xx_mem_free;
    return true;
}
static bool pm_parse(Abstractformat *f, pm_stream *s, xx_pd_struct *pd)
{
    uint8_t program[28], marker[4], header[257], tail[4];
    uint64_t text, data, bss, symbols, at, end, packed, plain, stream;
    unsigned hs, i, sum;
    bool bounded_producer;
    int64_t size = pm_available(f);
    if (size < 60 || size > INT32_MAX || (pd && xx_pd_is_stopped(pd)) || !pm_read(f, 0, program, sizeof(program)) || program[0] != 0x60 || program[1] != 0x1a)
        return false;
    text = pfx_be32(program + 2);
    data = pfx_be32(program + 6);
    bss = pfx_be32(program + 10);
    symbols = pfx_be32(program + 14);
    if (text < 32 || text > INT32_MAX || !data || data > INT32_MAX || bss > INT32_MAX || symbols > INT32_MAX) return false;
    at = 28 + text;
    end = at + data;
    if (at > (uint64_t)size || end > (uint64_t)size || data < 24 || !pm_read(f, (int64_t)at - 4, marker, 4) || xx_rt_memcmp(marker, "\xde\xad\xfa\xce", 4) ||
        !pfx_producer(f, text)) return false;
    bounded_producer = text == 392 || text == 386;
    while (at < end) {
        if (pd && xx_pd_is_stopped(pd)) return false;
        /* GEMDOS DATA may include up to two zero alignment bytes, or one
         * relocation byte immediately before its four-zero trailer. */
        if (s->count && end - at <= 2) {
            if (!pm_read(f, (int64_t)at, tail, (size_t)(end - at))) return false;
            if (!tail[0] && (end - at == 1 || !tail[1])) break;
            if (end - at == 1 && end <= (uint64_t)size - 4 && pm_read(f, (int64_t)end, tail, 4) &&
                !tail[0] && !tail[1] && !tail[2] && !tail[3]) break;
            return false;
        }
        if (s->count >= 1024 || end - at < 24 || !pm_read(f, (int64_t)at, header, 24)) return false;
        hs = (unsigned)header[0] + 2U;
        if (hs < 24 || hs > end - at || !pm_read(f, (int64_t)at, header, hs) || header[20] != 0 ||
            (xx_rt_memcmp(header + 2, "-lz5-", 5) && (s->count == 0 || xx_rt_memcmp(header + 2, "-lh1-", 5)))) return false;
        sum = 0;
        for (i = 2; i < hs; ++i) sum += header[i];
        if ((uint8_t)sum != header[1] || 24U + header[21] > hs) return false;
        packed = xx_data_get_u32(header + 7, 4, 0, false);
        plain = xx_data_get_u32(header + 11, 4, 0, false);
        stream = end - at - hs;
        if (!packed || !plain || plain > PFX_MAX_BUFFER || packed > INT32_MAX) return false;
        if (packed > stream) {
            /* Original PFX layout counts bytes absent from the DATA segment.
             * The exact known instruction body gates this producer policy. */
            if (s->count || !stream || plain > stream * 9U + 144U || !pfx_add(f, s, header, at, hs, stream, true, true)) return false;
            at = end;
            break;
        }
        if (!bounded_producer || plain > packed * 9U + 144U || !pfx_add(f, s, header, at, hs, packed, true, false)) return false;
        at += hs + packed;
    }
    if (!s->count) return false;
    s->size = size;
    xx_format_set_version(f, "LArc PFX 1.13P");
    return !(pd && xx_pd_is_stopped(pd));
}
static bool pfx_record_context(xx_archive_record_state *st)
{
    pm_stream *s;
    pfx_member *m;
    if (!st || !st->has_record) return false;
    s = (pm_stream *)st->internal_state;
    m = (pfx_member *)s->items[s->index].context;
    st->current_record.header_offset = m->header_offset;
    st->current_record.header_size = m->header_size;
    return xx_archive_record_set_meta_u64(&st->current_record, XX_META_ID_COMPRESSION_METHOD, m->method);
}
static xx_archive_record_state *pfx_records(Abstractformat *f, const xx_list_s *opts, xx_pd_struct *pd)
{
    xx_archive_record_state *st = pm_create_records(f, opts, pd);
    if (st && st->has_record && !pfx_record_context(st)) {
        pm_free_records(f, st);
        return NULL;
    }
    return st;
}
static bool pfx_next(Abstractformat *f, xx_archive_record_state *st, xx_pd_struct *pd)
{
    if (!pm_next(f, st, pd)) return false;
    st->has_record = pfx_record_context(st);
    return st->has_record;
}
void xx_larc_pfx_init(xx_larc_pfx *r, xx_io_device *d, int64_t base)
{
    if (r) {
        xx_mem_zero(r, sizeof(*r));
        pm_init(&r->format, d, base, XX_FILE_TYPE_LARC_PFX, "prg");
        r->format.endian = XX_ENDIAN_BIG;
        xx_format_set_mime_type(&r->format, "application/x-atari-st-executable");
        r->format.create_archive_records_reading = pfx_records;
        r->format.archive_record_move_to_next = pfx_next;
    }
}
xx_larc_pfx *xx_larc_pfx_create(xx_io_device *d, int64_t base)
{
    xx_larc_pfx *r = (xx_larc_pfx *)xx_mem_alloc(sizeof(*r));
    if (r) xx_larc_pfx_init(r, d, base);
    return r;
}
void xx_larc_pfx_destroy(xx_larc_pfx *r)
{
    if (r) xx_format_cleanup_extra_parameters(&r->format);
}
void xx_larc_pfx_free(xx_larc_pfx *r)
{
    if (r) {
        xx_larc_pfx_destroy(r);
        xx_mem_free(r);
    }
}
bool xx_larc_pfx_check_is_valid(Abstractformat *f, xx_pd_struct *pd)
{
    return pm_valid(f, pd);
}
bool xx_larc_pfx_handle_base_info(Abstractformat *f, xx_pd_struct *pd)
{
    return pm_handle(f, pd);
}
xx_file_type_t xx_larc_pfx_detect(xx_io_device *d, int64_t base)
{
    xx_larc_pfx r;
    bool valid;
    xx_larc_pfx_init(&r, d, base);
    valid = pm_valid(&r.format, NULL);
    xx_larc_pfx_destroy(&r);
    return valid ? XX_FILE_TYPE_LARC_PFX : XX_FILE_TYPE_UNKNOWN;
}
