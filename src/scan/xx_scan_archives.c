/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#include "xx_scan_archives_internal.h"
#include "xxfclib/formats/archive/zip/xx_zip.h"
#include "xxfclib/formats/archive/lha/xx_lha.h"
#include "xxfclib/formats/archive/gz/xx_gz.h"
#include "xxfclib/formats/archive/bz2/xx_bz2.h"
#include "xxfclib/formats/executable/machofat/xx_machofat.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/global/xx_global.h"

#define XX_SCAN_ARCHIVE_MEMBER_DEFAULT (UINT64_C(256) * 1024U * 1024U)
#define XX_SCAN_ARCHIVE_TOTAL_DEFAULT (UINT64_C(1024) * 1024U * 1024U)
#define XX_SCAN_ARCHIVE_COUNT_DEFAULT UINT32_C(100000)

typedef struct xx_scan_archive_sink {
    uint8_t *data;
    uint64_t size;
    size_t capacity;
    uint64_t limit;
    uint64_t memory_threshold;
    xx_io_device *temporary;
    bool discard;
    bool failed;
    xx_pd_struct *pd;
} xx_scan_archive_sink;

static bool xx_scan_archive_error(xx_pd_struct *pd, int error, const char *message)
{
    if (pd && !pd->last_error && !xx_pd_is_stopped(pd)) xx_pd_set_error(pd, error, message);
    return false;
}

static bool xx_scan_archive_stopped(xx_pd_struct *pd)
{
    return xx_pd_is_stopped(pd) || (pd && pd->last_error);
}

static bool xx_scan_archive_sink_error(xx_scan_archive_sink *sink, int error, const char *message)
{
    sink->failed = true;
    return xx_scan_archive_error(sink->pd, error, message);
}

/* A short temporary-file write is a storage failure. Do not retry a buffered
 * file write after an error: stdio may already have discarded buffered bytes. */
static bool xx_scan_archive_temp_write(xx_scan_archive_sink *sink, xx_io_device *temporary, const void *data, size_t size)
{
    const uint8_t *bytes = (const uint8_t *)data;
    while (size) {
        size_t amount = size > 65536U ? 65536U : size;
        if (xx_scan_archive_stopped(sink->pd)) return false;
        if (xx_io_write(temporary, bytes, amount) != (ssize_t)amount)
            return xx_scan_archive_sink_error(sink, XXFC_ERR_IO, "Cannot write temporary archive member");
        bytes += amount;
        size -= amount;
    }
    return true;
}

static bool xx_scan_archive_spill(xx_scan_archive_sink *sink)
{
    xx_io_device *temporary = xx_io_temp_open();
    if (!temporary) return xx_scan_archive_sink_error(sink, XXFC_ERR_IO, "Cannot create temporary archive member");
    if (!xx_scan_archive_temp_write(sink, temporary, sink->data, (size_t)sink->size)) {
        xx_io_close(temporary);
        return false;
    }
    xx_mem_free(sink->data);
    sink->data = NULL;
    sink->capacity = 0;
    sink->temporary = temporary;
    return true;
}

/* Small decoded members stay in memory. Known large members start in a temp
 * file; unknown GZIP/BZIP2 output spills as soon as it reaches the global
 * file-buffer threshold. Independent archive size limits still apply. */
static ssize_t xx_scan_archive_write(xx_io_device *device, const void *data, size_t size)
{
    xx_scan_archive_sink *sink = (xx_scan_archive_sink *)device->priv;
    uint64_t required;
    size_t capacity;
    uint8_t *grown;
    if (sink->failed || xx_scan_archive_stopped(sink->pd)) return -1;
    if ((!data && size) || size > (size_t)PTRDIFF_MAX || sink->size > sink->limit ||
        (uint64_t)size > sink->limit - sink->size || sink->size > (uint64_t)INT64_MAX ||
        (uint64_t)size > (uint64_t)INT64_MAX - sink->size) {
        xx_scan_archive_sink_error(sink, XXFC_ERR_OUT_OF_BOUNDS, "Decoded archive member exceeds the scan size limit");
        return -1;
    }
    if (!size) return 0;
    required = sink->size + (uint64_t)size;
    if (sink->discard) {
        sink->size = required;
        return (ssize_t)size;
    }
    if (!sink->temporary && required >= sink->memory_threshold && !xx_scan_archive_spill(sink)) return -1;
    if (sink->temporary) {
        if (!xx_scan_archive_temp_write(sink, sink->temporary, data, size)) return -1;
        sink->size = required;
        return (ssize_t)size;
    }
    if (required > (uint64_t)SIZE_MAX) {
        xx_scan_archive_sink_error(sink, XXFC_ERR_OUT_OF_BOUNDS, "Archive memory size cannot be represented");
        return -1;
    }
    if (required > sink->capacity) {
        capacity = sink->capacity ? sink->capacity : 4096U;
        while (capacity < required) {
            if (capacity > SIZE_MAX / 2U) { capacity = (size_t)required; break; }
            capacity *= 2U;
        }
        if ((uint64_t)capacity > sink->limit || (uint64_t)capacity >= sink->memory_threshold) capacity = (size_t)required;
        grown = (uint8_t *)xx_mem_realloc(sink->data, capacity);
        if (!grown) {
            xx_scan_archive_sink_error(sink, XXFC_ERR_OUT_OF_MEMORY, "Cannot allocate decoded archive member");
            return -1;
        }
        sink->data = grown;
        sink->capacity = capacity;
    }
    xx_mem_copy(sink->data + (size_t)sink->size, data, size);
    sink->size = required;
    return (ssize_t)size;
}

static int64_t xx_scan_archive_sink_size(xx_io_device *device)
{
    return (int64_t)((xx_scan_archive_sink *)device->priv)->size;
}

static bool xx_scan_archive_sink_init(xx_scan_archive_sink *sink, xx_io_device *device, uint64_t limit,
                                      uint64_t expected_size, bool discard, xx_pd_struct *pd)
{
    xx_mem_zero(sink, sizeof(*sink));
    xx_mem_zero(device, sizeof(*device));
    sink->limit = limit;
    sink->memory_threshold = (uint64_t)xx_get_file_buffer_size();
    sink->discard = discard;
    sink->pd = pd;
    device->priv = sink;
    device->write = xx_scan_archive_write;
    device->tell = xx_scan_archive_sink_size;
    device->total_size = xx_scan_archive_sink_size;
    return discard || expected_size == UINT64_MAX || expected_size < sink->memory_threshold || xx_scan_archive_spill(sink);
}

static bool xx_scan_archive_sink_cleanup(xx_scan_archive_sink *sink)
{
    bool result = true;
    if (sink->temporary && xx_io_close(sink->temporary) != 0)
        result = xx_scan_archive_sink_error(sink, XXFC_ERR_IO, "Cannot close temporary archive member");
    sink->temporary = NULL;
    xx_mem_free(sink->data);
    sink->data = NULL;
    return result;
}

static bool xx_scan_archive_publish(xx_scan_archive_sink *sink, const char *name, int64_t offset, int64_t source_size,
                                    bool compressed, xx_scan_archive_callback callback, void *context, xx_pd_struct *pd)
{
    xx_scan_archive_member member;
    bool result;
    if (sink->failed || sink->discard || xx_scan_archive_stopped(pd)) return false;
    if (sink->temporary) {
        /* Repositioning is also the update-stream write/read barrier. Only
         * expose the completed, verified extent to the scanner. */
        if (xx_io_seek64(sink->temporary, 0, SEEK_SET) != 0 || xx_io_total_size(sink->temporary) != (int64_t)sink->size)
            return xx_scan_archive_sink_error(sink, XXFC_ERR_IO, "Cannot prepare temporary archive member for scanning");
        member.device = xx_io_sub_open_ro(sink->temporary, 0, (int64_t)sink->size);
    } else member.device = xx_io_mem_open_ro(sink->data, (size_t)sink->size);
    if (!member.device) return xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_MEMORY, "Cannot create decoded archive member device");
    member.name = name;
    member.source_offset = offset;
    member.source_size = source_size;
    member.size = (int64_t)sink->size;
    member.is_compressed = compressed;
    result = callback(context, &member, pd);
    xx_io_close(member.device);
    return result && !xx_scan_archive_stopped(pd);
}

static bool xx_scan_archive_is_zip(xx_file_type_t type)
{
    return type == XX_FILE_TYPE_ZIP || type == XX_FILE_TYPE_ZIP64 || type == XX_FILE_TYPE_JAR ||
           type == XX_FILE_TYPE_APK || type == XX_FILE_TYPE_IPA;
}

static bool xx_scan_archive_stream(Abstractformat *format, xx_file_type_t type, int64_t origin, int64_t range_size,
                                   uint64_t member_limit, uint64_t total_limit, uint32_t count_limit,
                                   xx_scan_archive_callback callback, void *context, xx_pd_struct *pd)
{
    xx_archive_record limits;
    xx_archive_record_state *state = NULL;
    const xx_archive_record *record;
    uint64_t consumed = 0U;
    uint32_t count = 0U;
    bool result = false;
    char *owned_name = NULL;
    uint64_t memory_limit = member_limit > UINT64_MAX / 2U ? UINT64_MAX : member_limit * 2U;

    xx_archive_record_init(&limits);
    if (!xx_archive_record_set_meta_u64(&limits, XX_META_ID_OPT_MAX_MEMBER_SIZE, member_limit) ||
        !xx_archive_record_set_meta_u64(&limits, XX_META_ID_OPT_MEMORY_LIMIT, memory_limit)) {
        xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_MEMORY, "Cannot allocate archive scan limits");
        goto done;
    }
    state = xx_format_create_archive_records_reading(format, &limits.list_meta, pd);
    if (!state || xx_scan_archive_stopped(pd)) goto done;
    /* These native readers all expose an exact count. Comparing the visited
     * count also distinguishes normal EOF from a damaged later entry or an
     * allocation failure while advancing the native iterator. */
    if (state->total_records < 0 || (uint64_t)state->total_records > (uint64_t)count_limit) {
        xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_BOUNDS, "Archive record count exceeds the scan limit");
        goto done;
    }
    while ((record = xx_format_get_current_archive_record(format, state)) != NULL) {
        uint64_t decoded_size, remaining, method;
        const char *name;
        xx_str_free(owned_name);
        owned_name = NULL;
        if (xx_scan_archive_stopped(pd)) goto done;
        if (count == count_limit) {
            xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_BOUNDS, "Archive record count exceeds the scan limit");
            goto done;
        }
        ++count;
        if (record->data_offset < 0 || record->compressed_size < 0 || record->data_offset > range_size ||
            record->compressed_size > range_size - record->data_offset) {
            xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_BOUNDS, "Invalid archive member source range");
            goto done;
        }
        if (xx_archive_record_get_meta_bool(record, XX_META_ID_IS_ENCRYPTED, false)) {
            xx_scan_archive_error(pd, XXFC_ERR_INVALID_ARG, "Encrypted archive members require a password and cannot be scanned");
            goto done;
        }
        if (!xx_archive_record_get_meta_bool(record, XX_META_ID_IS_FOLDER, false)) {
            decoded_size = xx_archive_record_get_meta_u64(record, XX_META_ID_UNCOMPRESSED_SIZE, UINT64_MAX);
            remaining = total_limit - consumed;
            if (decoded_size > member_limit || decoded_size > remaining || decoded_size > (uint64_t)INT64_MAX) {
                xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_BOUNDS, "Archive member exceeds the scan size limit");
                goto done;
            }
            name = xx_archive_record_get_original_name(record);
            if (!name) {
                const wchar_t *wide_name = xx_archive_record_get_original_name_w(record);
                if (wide_name) {
                    owned_name = xx_str_unicode_to_utf8(wide_name);
                    if (!owned_name) {
                        xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_MEMORY, "Cannot convert archive member name");
                        goto done;
                    }
                    name = owned_name;
                } else name = "archive-member";
            }
            method = xx_archive_record_get_meta_u64(record, XX_META_ID_COMPRESSION_METHOD, UINT64_MAX);
            if (type == XX_FILE_TYPE_MACHOFAT ||
                (xx_scan_archive_is_zip(type) && method == 0U) ||
                (type == XX_FILE_TYPE_LHA && !((xx_lha *)format)->sfx_boa_mask &&
                 (method == UINT64_C(0x6c6830) || method == UINT64_C(0x6c7a34)))) {
                xx_scan_archive_member member;
                bool visited;
                if (decoded_size != (uint64_t)record->compressed_size) {
                    xx_scan_archive_error(pd, XXFC_ERR_INVALID_ARG, "Stored archive member has inconsistent sizes");
                    goto done;
                }
                if (type != XX_FILE_TYPE_MACHOFAT) {
                    xx_scan_archive_sink sink;
                    xx_io_device destination;
                    bool verified;
                    /* Native readers verify sizes and CRC while the sink
                     * counts and discards bytes. Scan the original extent
                     * only after verification, without copying the member. */
                    if (!xx_scan_archive_sink_init(&sink, &destination, decoded_size, decoded_size, true, pd)) goto done;
                    verified = type == XX_FILE_TYPE_LHA ? xx_lha_unpack_current_archive_record_to_device(format, state, &destination, pd) :
                                                         xx_zip_unpack_current_archive_record_to_device(format, state, &destination, pd);
                    verified = verified && !sink.failed && sink.size == decoded_size;
                    if (!xx_scan_archive_sink_cleanup(&sink)) verified = false;
                    if (!verified || xx_scan_archive_stopped(pd)) goto done;
                }
                member.device = xx_io_sub_open_ro(format->device, record->data_offset, record->compressed_size);
                if (!member.device) {
                    xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_MEMORY, "Cannot create stored archive member view");
                    goto done;
                }
                member.name = name;
                member.source_offset = origin + record->data_offset;
                member.source_size = record->compressed_size;
                member.size = (int64_t)decoded_size;
                member.is_compressed = false;
                visited = callback(context, &member, pd);
                xx_io_close(member.device);
                if (!visited || xx_scan_archive_stopped(pd)) goto done;
            } else {
                xx_scan_archive_sink sink;
                xx_io_device destination;
                bool decoded, visited = false;
                if (!xx_scan_archive_sink_init(&sink, &destination, decoded_size, decoded_size, false, pd)) {
                    xx_scan_archive_sink_cleanup(&sink);
                    goto done;
                }
                decoded = type == XX_FILE_TYPE_LHA ? xx_lha_unpack_current_archive_record_to_device(format, state, &destination, pd) :
                                                    xx_zip_unpack_current_archive_record_to_device(format, state, &destination, pd);
                if (decoded && !sink.failed && sink.size == decoded_size && !xx_scan_archive_stopped(pd))
                    visited = xx_scan_archive_publish(&sink, name, origin + record->data_offset, record->compressed_size, true, callback, context, pd);
                if (!xx_scan_archive_sink_cleanup(&sink)) visited = false;
                if (!visited) goto done;
            }
            consumed += decoded_size;
        } else if (xx_scan_archive_is_zip(type)) {
            xx_scan_archive_sink sink;
            xx_io_device destination;
            bool verified;
            /* Empty Deflate directory streams are valid ZIP records. Use
             * the native verifier to reject hidden data or a forged CRC,
             * even though a directory does not produce a child scan. */
            if (!xx_scan_archive_sink_init(&sink, &destination, 0U, 0U, true, pd)) goto done;
            verified = xx_zip_unpack_current_archive_record_to_device(format, state, &destination, pd);
            verified = verified && !sink.failed && sink.size == 0U;
            if (!xx_scan_archive_sink_cleanup(&sink)) verified = false;
            if (!verified || xx_scan_archive_stopped(pd)) goto done;
        } else if (type == XX_FILE_TYPE_LHA && (record->compressed_size != 0 ||
                   xx_archive_record_get_meta_u64(record, XX_META_ID_UNCOMPRESSED_SIZE, UINT64_MAX) != 0U)) {
            xx_scan_archive_error(pd, XXFC_ERR_INVALID_ARG, "LHA directory contains an unexpected payload");
            goto done;
        }
        if (!xx_format_archive_record_move_to_next(format, state, pd)) break;
    }
    result = !xx_scan_archive_stopped(pd) && (uint64_t)count == (uint64_t)state->total_records;
    if (xx_scan_archive_is_zip(type) && ((xx_zip *)format)->directory_damaged) result = false;
done:
    xx_str_free(owned_name);
    if (state) xx_format_free_archive_records_reading(format, state);
    xx_archive_record_cleanup(&limits);
    return result || xx_scan_archive_error(pd, XXFC_ERR_INVALID_ARG, "Cannot decode archive member or enumerate complete archive");
}

static bool xx_scan_archive_compressed_stream(xx_io_device *view, xx_file_type_t type, int64_t origin,
                                              uint64_t limit, xx_scan_archive_callback callback, void *context, xx_pd_struct *pd)
{
    xx_scan_archive_sink sink;
    xx_io_device destination;
    int64_t stream_size = -1;
    bool decoded, result = false;
    if (!xx_scan_archive_sink_init(&sink, &destination, limit, UINT64_MAX, false, pd)) {
        xx_scan_archive_sink_cleanup(&sink);
        return false;
    }
    decoded = type == XX_FILE_TYPE_GZ ? xx_gz_decode_stream(view, 0, &destination, &stream_size, NULL, NULL, pd) :
                                       xx_bz2_decode_stream(view, 0, &destination, &stream_size, NULL, pd);
    if (decoded && !sink.failed && stream_size > 0 && stream_size <= xx_io_total_size(view) && !xx_scan_archive_stopped(pd))
        result = xx_scan_archive_publish(&sink, type == XX_FILE_TYPE_GZ ? "gzip-content" : "bzip2-content",
                                         origin, stream_size, true, callback, context, pd);
    if (!xx_scan_archive_sink_cleanup(&sink)) result = false;
    return result || xx_scan_archive_error(pd, XXFC_ERR_INVALID_ARG, "Cannot decode complete compressed archive stream");
}

bool xx_scan_visit_archives(xx_io_device *device, const xx_scan_options *options,
                            xx_scan_archive_callback callback, void *context, xx_pd_struct *pd)
{
    xx_io_device *view = NULL;
    int64_t saved, total_size, range_size;
    uint64_t member_limit, total_limit;
    uint32_t count_limit;
    xx_file_type_t type;
    bool result = false;
    if (!device || !options || !callback) return xx_scan_archive_error(pd, XXFC_ERR_NULL_PARAM, "Missing archive scan argument");
    if (xx_scan_archive_stopped(pd)) return false;
    if (options->offset < 0 || options->size < -1 || (options->size >= 0 && options->size > INT64_MAX - options->offset))
        return xx_scan_archive_error(pd, XXFC_ERR_INVALID_ARG, "Invalid archive scan range");
    type = options->file_type;
    if (type == XX_FILE_TYPE_NPM) type = XX_FILE_TYPE_GZ;
    if (!xx_scan_archive_is_zip(type) && type != XX_FILE_TYPE_LHA && type != XX_FILE_TYPE_GZ && type != XX_FILE_TYPE_BZ2 && type != XX_FILE_TYPE_MACHOFAT)
        return true;
    member_limit = options->archive_max_member_size ? options->archive_max_member_size : XX_SCAN_ARCHIVE_MEMBER_DEFAULT;
    total_limit = options->archive_max_total_size ? options->archive_max_total_size : XX_SCAN_ARCHIVE_TOTAL_DEFAULT;
    count_limit = options->archive_max_members ? options->archive_max_members : XX_SCAN_ARCHIVE_COUNT_DEFAULT;
    saved = xx_io_tell(device);
    if (saved < 0) return xx_scan_archive_error(pd, XXFC_ERR_IO, "Cannot save archive scan input position");
    total_size = xx_io_total_size(device);
    if ((total_size >= 0 && (options->offset > total_size || (options->size >= 0 && options->size > total_size - options->offset))) ||
        (total_size < 0 && options->size < 0)) {
        xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_BOUNDS, "Archive scan range exceeds input");
        goto done;
    }
    range_size = options->size >= 0 ? options->size : total_size - options->offset;
    view = xx_io_sub_open_ro(device, options->offset, range_size);
    if (!view) {
        xx_scan_archive_error(pd, XXFC_ERR_OUT_OF_MEMORY, "Cannot create bounded archive scan view");
        goto done;
    }
    if (type == XX_FILE_TYPE_GZ || type == XX_FILE_TYPE_BZ2) {
        result = xx_scan_archive_compressed_stream(view, type, options->offset, member_limit < total_limit ? member_limit : total_limit, callback, context, pd);
    } else if (type == XX_FILE_TYPE_LHA) {
        xx_lha reader;
        xx_lha_init(&reader, view, 0);
        result = xx_scan_archive_stream(&reader.format, type, options->offset, range_size, member_limit, total_limit, count_limit, callback, context, pd);
        xx_lha_destroy(&reader);
    } else if (type == XX_FILE_TYPE_MACHOFAT) {
        xx_machofat reader;
        xx_machofat_init(&reader, view, 0);
        result = xx_scan_archive_stream(&reader.format, type, options->offset, range_size, member_limit, total_limit, count_limit, callback, context, pd);
        xx_machofat_destroy(&reader);
    } else {
        xx_zip reader;
        xx_zip_init(&reader, view, 0);
        result = xx_scan_archive_stream(&reader.format, type, options->offset, range_size, member_limit, total_limit, count_limit, callback, context, pd);
        xx_zip_destroy(&reader);
    }
done:
    if (view) xx_io_close(view);
    if (xx_io_seek64(device, saved, SEEK_SET) != 0)
        return xx_scan_archive_error(pd, XXFC_ERR_IO, "Cannot restore archive scan input position");
    return result && !xx_scan_archive_stopped(pd);
}
