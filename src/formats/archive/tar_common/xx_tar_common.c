/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xx_tar_common.h"

#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"

#include <limits.h>
#include <stdio.h>
#include <string.h>

/* Composite readers retain the decoded TAR so its ordinary random-access
 * reader can serve all later record operations.  Up to the threshold it
 * stays in RAM; beyond it, it moves to a temporary file, so its size is
 * bound by the free disk. A memory-only scope (Test) cannot write one:
 * there, as when no temporary file can be made or the disk fills, RAM holds
 * at most the maximum, which also keeps malformed streams from growing the
 * cache without bound. In a temporary file a TAR grows past that maximum
 * only while it stays within the ratio times the size of its compressed
 * input: more is a decompression bomb (a few hundred KiB of bzip2 decode
 * to many GiB of zeros), which would fill the disk. */
#define XX_TAR_COMMON_MAX_DECODED_SIZE ((size_t)1024U * (size_t)1024U * (size_t)1024U)
#define XX_TAR_COMMON_SPILL_THRESHOLD ((size_t)256U * (size_t)1024U * (size_t)1024U)
#define XX_TAR_COMMON_MAX_RATIO 4096U
#define XX_TAR_COMMON_INITIAL_CAPACITY ((size_t)64U * (size_t)1024U)

typedef struct xx_tar_common_writer_s {
    uint8_t *data;
    size_t size;
    size_t capacity;
    size_t position;
    xx_io_device device;
    xx_tar tar;
    xx_archive_write_state *tar_state;
    xx_tar_common_encode_fn encode;
    bool tar_finalized;
    bool finalized;
} xx_tar_common_writer;

static void xx_tar_common_release_payload(xx_tar_common *common)
{
    if (!common) return;
    if (common->tar) {
        xx_tar_free(common->tar);
        common->tar = NULL;
    }
    if (common->decoded_device) {
        /* The temporary file itself when the TAR spilled to one. */
        if (common->decoded_device == common->spill) common->spill = NULL;
        xx_io_close(common->decoded_device);
        common->decoded_device = NULL;
    }
    if (common->spill) {
        xx_io_close(common->spill);
        common->spill = NULL;
    }
    if (common->decoded_data) {
        xx_mem_free(common->decoded_data);
        common->decoded_data = NULL;
    }
    common->decoded_size = 0U;
    common->decoded_capacity = 0U;
    common->compressed_size = -1;
    common->valid = false;
    common->cut = false;
    common->checked_size = 0U;
    common->unverified = false;
}

static bool xx_tar_common_load_failed(xx_tar_common *common)
{
    bool too_large = common && common->too_large;
    bool too_dense = common && common->too_dense;
    bool no_room = common && common->no_room;
    xx_tar_common_release_payload(common);
    if (common) {
        common->attempted = false;
        common->too_large = too_large;
        common->too_dense = too_dense;
        common->no_room = no_room;
    }
    return false;
}

/* A temporary file takes all of a write or fails: a short count is an error
 * (a full disk), after which the C library may drop what it had buffered,
 * so it is never retried. */
static bool xx_tar_common_write_all(xx_io_device *device, const uint8_t *data, size_t size)
{
    return size == 0U || xx_io_write(device, data, size) == (ssize_t)size;
}

/* Move the RAM copy to a temporary file. False, with RAM as it was, when
 * none can be made or written (a full disk). */
static bool xx_tar_common_spill(xx_tar_common *common)
{
    xx_io_device *spill;
    if (!(spill = xx_io_temp_open())) return false;
    if (!xx_tar_common_write_all(spill, common->decoded_data, common->decoded_size)) {
        xx_io_close(spill);
        return false;
    }
    xx_mem_free(common->decoded_data);
    common->decoded_data = NULL;
    common->decoded_capacity = 0U;
    common->spill = spill;
    return true;
}

static ssize_t xx_tar_common_sink_write(xx_io_device *device, const void *data, size_t size)
{
    xx_tar_common *common = device ? (xx_tar_common *)device->priv : NULL;
    size_t required;
    size_t capacity;
    uint8_t *grown;
    if (!common || (!data && size != 0U)) return -1;
    if (size == 0U) return 0;
    if (size > SIZE_MAX - common->decoded_size || (uint64_t)common->decoded_size + size > (uint64_t)INT64_MAX) {
        common->too_large = true;
        return -1;
    }
    required = common->decoded_size + size;
    /* Past the maximum (where a memory-only scope stops anyway), a TAR over
     * the ratio is a decompression bomb's: it is decoded no further. */
    if (required > XX_TAR_COMMON_MAX_DECODED_SIZE && (uint64_t)required / XX_TAR_COMMON_MAX_RATIO > (uint64_t)common->source_size && !xx_io_memory_only_active()) {
        common->too_dense = true;
        return -1;
    }
    /* Tried once: RAM holds on (to the maximum) when no file takes it. */
    if (!common->spill && !common->spill_failed && required > XX_TAR_COMMON_SPILL_THRESHOLD && !xx_io_memory_only_active()) {
        common->spill_failed = !xx_tar_common_spill(common);
    }
    if (common->spill) {
        if (!xx_tar_common_write_all(common->spill, (const uint8_t *)data, size)) {
            common->no_room = true;
            return -1;
        }
        common->decoded_size = required;
        return (ssize_t)size;
    }
    if (required > XX_TAR_COMMON_MAX_DECODED_SIZE) {
        /* Over the RAM it may use: as a temporary file could not take it,
         * or in a memory-only scope, where none may be written. */
        if (common->spill_failed) common->no_room = true;
        else common->too_large = true;
        return -1;
    }
    if (required > common->decoded_capacity) {
        capacity = common->decoded_capacity;
        if (capacity == 0U) capacity = XX_TAR_COMMON_INITIAL_CAPACITY;
        while (capacity < required) {
            if (capacity > XX_TAR_COMMON_MAX_DECODED_SIZE / 2U) {
                capacity = XX_TAR_COMMON_MAX_DECODED_SIZE;
            } else {
                capacity *= 2U;
            }
        }
        grown = (uint8_t *)xx_mem_realloc(common->decoded_data, capacity);
        if (!grown) return -1;
        common->decoded_data = grown;
        common->decoded_capacity = capacity;
    }
    xx_mem_copy(common->decoded_data + common->decoded_size, data, size);
    common->decoded_size = required;
    return (ssize_t)size;
}

static int64_t xx_tar_common_sink_size(xx_io_device *device)
{
    const xx_tar_common *common = device ? (const xx_tar_common *)device->priv : NULL;
    return common && (uint64_t)common->decoded_size <= (uint64_t)INT64_MAX ? (int64_t)common->decoded_size : -1;
}

void xx_tar_common_stream_cut(xx_io_device *destination)
{
    if (destination && destination->write == xx_tar_common_sink_write && destination->priv) {
        ((xx_tar_common *)destination->priv)->cut = true;
    }
}

void xx_tar_common_stream_checked(xx_io_device *destination, uint64_t size)
{
    if (destination && destination->write == xx_tar_common_sink_write && destination->priv) {
        xx_tar_common *common = (xx_tar_common *)destination->priv;
        common->checked_size = size < (uint64_t)common->decoded_size ? (size_t)size : common->decoded_size;
    }
}

bool xx_tar_common_is_whole_tar(const uint8_t *data, size_t size, xx_pd_struct *pd)
{
    xx_io_device *device = data ? xx_io_mem_open_ro(data, size) : NULL;
    xx_tar *tar = device ? xx_tar_create(device, 0) : NULL;
    bool whole = tar && xx_format_handle_base_info(&tar->format, pd);
    if (tar) xx_tar_free(tar);
    if (device) xx_io_close(device);
    return whole;
}

/* Whether the decoded data holds a byte other than zero. */
static bool xx_tar_common_has_nonzero(xx_io_device *device, int64_t size)
{
    uint8_t buffer[4096];
    int64_t offset = 0;
    while (offset < size) {
        size_t amount = size - offset < (int64_t)sizeof(buffer) ? (size_t)(size - offset) : sizeof(buffer);
        size_t i;
        if (!xx_io_read_at(device, offset, buffer, amount)) return true;
        for (i = 0U; i < amount; ++i) {
            if (buffer[i] != 0U) return true;
        }
        offset += (int64_t)amount;
    }
    return false;
}

void xx_tar_common_init(xx_tar_common *common)
{
    if (!common) return;
    xx_mem_zero(common, sizeof(*common));
    common->compressed_size = -1;
}

void xx_tar_common_cleanup(xx_tar_common *common)
{
    if (!common) return;
    xx_tar_common_release_payload(common);
    common->attempted = false;
    if (common->outer && common->outer->priv == common) common->outer->priv = NULL;
    common->outer = NULL;
}

bool xx_tar_common_load(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode, xx_pd_struct *pd)
{
    xx_io_device sink;
    int64_t total_size;
    int64_t compressed_size = -1;
    bool decoded;
    if (!common || !outer || !outer->device || !decode || outer->base_address < 0 || outer->base_address > LONG_MAX) {
        return false;
    }
    if (common->attempted) return common->valid;
    xx_tar_common_release_payload(common);
    common->attempted = true;
    common->too_large = false;
    common->too_dense = false;
    common->no_room = false;
    common->spill_failed = false;
    /* How xx_tar_compressed_* find this state from the reader alone. */
    common->outer = outer;
    outer->priv = common;

    total_size = xx_io_total_size(outer->device);
    if (total_size <= outer->base_address) return xx_tar_common_load_failed(common);
    common->source_size = total_size - outer->base_address;

    xx_mem_zero(&sink, sizeof(sink));
    sink.write = xx_tar_common_sink_write;
    sink.total_size = xx_tar_common_sink_size;
    sink.get_total_size = xx_tar_common_sink_size;
    sink.size = xx_tar_common_sink_size;
    sink.priv = common;
    for (;;) {
        compressed_size = -1;
        common->checked_size = 0U;
        decoded = decode(outer, &sink, &compressed_size, pd);
        /* What the C library still buffered reaches the temporary file now:
         * a file shorter than what was written lost data to a full disk. */
        if (common->spill && !common->no_room && (decoded || common->cut) &&
            (xx_io_seek64(common->spill, 0, SEEK_SET) != 0 || xx_io_total_size(common->spill) != (int64_t)common->decoded_size)) {
            common->no_room = true;
            decoded = false;
        }
        if (!common->no_room || !common->spill || common->decoded_size > XX_TAR_COMMON_MAX_DECODED_SIZE || (pd && xx_pd_is_stopped(pd))) break;
        /* The disk filled after the TAR moved to it: decoded once more, in
         * RAM alone, which holds one up to the maximum. */
        xx_tar_common_release_payload(common);
        common->no_room = false;
        common->spill_failed = true;
    }
    if (decoded) {
        common->cut = false;
        if (compressed_size <= 0 || compressed_size > total_size - outer->base_address) return xx_tar_common_load_failed(common);
    } else if (!common->cut || common->too_large || common->too_dense || common->no_room || (pd && xx_pd_is_stopped(pd))) {
        return xx_tar_common_load_failed(common);
    } else {
        /* A cut file: its stream runs to the end of the input, and the
         * members are those of the decoded prefix (xx_tar_parse_archive). */
        compressed_size = total_size - outer->base_address;
    }
    if (common->decoded_size == 0U || (uint64_t)common->decoded_size > (uint64_t)INT64_MAX) {
        return xx_tar_common_load_failed(common);
    }

    if (common->spill) {
        common->decoded_device = common->spill;
        if (xx_io_seek64(common->decoded_device, 0, SEEK_SET) != 0) return xx_tar_common_load_failed(common);
    } else {
        common->decoded_device = xx_io_mem_open_ro(common->decoded_data, common->decoded_size);
    }
    if (!common->decoded_device || xx_io_total_size(common->decoded_device) != (int64_t)common->decoded_size) {
        return xx_tar_common_load_failed(common);
    }
    common->tar = xx_tar_create(common->decoded_device, 0);
    if (!common->tar) return xx_tar_common_load_failed(common);
    if (common->cut) {
        /* A cut stream's TAR holds a member: one that decodes to zeros alone
         * is no believable cut TAR, but a cut stream of its own type. */
        if (!xx_tar_handle_base_info_prefix(&common->tar->format, pd) || common->tar->format.number_of_archive_records == 0U) {
            return xx_tar_common_load_failed(common);
        }
    } else if (!xx_format_handle_base_info(&common->tar->format, pd)) {
        /* A whole stream whose TAR ends in a member, or after one without
         * its end marker (a file cut where a gzip member, an xz or bzip2
         * stream or a zstd frame ends, or a TAR cut before it was
         * compressed): a cut TAR, read as far as it goes, when it holds a
         * member. Any other defect of the TAR fails its prefix too. */
        if ((pd && xx_pd_is_stopped(pd)) || !xx_tar_handle_base_info_prefix(&common->tar->format, pd) || common->tar->format.number_of_archive_records == 0U) {
            return xx_tar_common_load_failed(common);
        }
        common->cut = true;
    }
    /* The members before the cut are read whether or not a check covers
     * them, as GNU tar reads them; those no check covers are marked. */
    if (common->cut)
        common->unverified =
            xx_tar_prefix_checked(&common->tar->format, (uint64_t)common->checked_size <= (uint64_t)INT64_MAX ? (int64_t)common->checked_size : INT64_MAX);
    /* The tar reader rightly takes a zero block for the end-of-archive
     * marker, so any payload that merely STARTS with 512 zero bytes parses
     * as an empty tar. A compressed ISO image or disk dump does exactly that
     * (an ISO's first 32 KiB are zero), and claiming it as an empty tar.xx
     * loses the whole payload. An empty tar is only believable when the
     * payload is nothing but zero blocks; otherwise this is not a tar and
     * the stream belongs to the plain decompressor. */
    if (common->tar->format.number_of_archive_records == 0U && xx_tar_common_has_nonzero(common->decoded_device, (int64_t)common->decoded_size)) {
        return xx_tar_common_load_failed(common);
    }
    common->compressed_size = compressed_size;
    common->valid = true;
    return true;
}

/* The shared state of a compressed TAR reader, or NULL for any other format.
 * A load points the reader's priv, which these readers do not use
 * otherwise, at its state (and the state back at the reader): that way no
 * reader is named here, so that a library with only some of them links. */
static const xx_tar_common *xx_tar_common_of(const Abstractformat *format)
{
    const xx_tar_common *common;
    if (!format || !format->priv) return NULL;
    switch (format->file_type) {
        case XX_FILE_TYPE_TAR_GZ:
        case XX_FILE_TYPE_NPM:
        case XX_FILE_TYPE_TAR_BZ2:
        case XX_FILE_TYPE_TAR_XZ:
        case XX_FILE_TYPE_TAR_LZMA:
        case XX_FILE_TYPE_TAR_LZIP:
        case XX_FILE_TYPE_TAR_LZ4:
        case XX_FILE_TYPE_TAR_LZOP:
        case XX_FILE_TYPE_TAR_ZSTD:
        case XX_FILE_TYPE_TAR_COMPRESS: break;
        default: return NULL; /* Another format's priv is its own. */
    }
    common = (const xx_tar_common *)format->priv;
    return common->outer == format ? common : NULL;
}

bool xx_tar_compressed_is_incomplete(const Abstractformat *format)
{
    const xx_tar_common *common = xx_tar_common_of(format);
    return common && common->valid && common->cut;
}

bool xx_tar_compressed_last_cut(const Abstractformat *format)
{
    const xx_tar_common *common = xx_tar_common_of(format);
    return common && common->valid && common->cut && common->tar && xx_tar_last_cut(&common->tar->format);
}

bool xx_tar_compressed_unverified(const Abstractformat *format)
{
    const xx_tar_common *common = xx_tar_common_of(format);
    return common && common->valid && common->cut && common->unverified;
}

bool xx_tar_compressed_last_unverified(const Abstractformat *format)
{
    const xx_tar_common *common = xx_tar_common_of(format);
    return common && common->valid && common->cut && common->unverified && common->tar && xx_tar_last_unverified(&common->tar->format);
}

bool xx_tar_compressed_too_large(const Abstractformat *format, uint64_t *limit)
{
    const xx_tar_common *common = xx_tar_common_of(format);
    if (limit) *limit = (uint64_t)XX_TAR_COMMON_MAX_DECODED_SIZE;
    return common && !common->valid && common->too_large;
}

bool xx_tar_compressed_too_dense(const Abstractformat *format, uint32_t *ratio)
{
    const xx_tar_common *common = xx_tar_common_of(format);
    if (ratio) *ratio = XX_TAR_COMMON_MAX_RATIO;
    return common && !common->valid && common->too_dense;
}

bool xx_tar_compressed_no_room(const Abstractformat *format)
{
    const xx_tar_common *common = xx_tar_common_of(format);
    return common && !common->valid && common->no_room;
}

bool xx_tar_common_handle_base_info(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode, xx_pd_struct *pd)
{
    int64_t total_size;
    int64_t stream_end;
    if (!xx_tar_common_load(common, outer, decode, pd) || !common->tar || common->compressed_size > INT64_MAX - outer->base_address) {
        if (outer) {
            outer->format_size = -1;
            outer->overlay_offset = -1;
            outer->overlay_size = 0;
            outer->number_of_archive_records = 0U;
            outer->is_valid = false;
            outer->base_info_handled = false;
        }
        return false;
    }
    total_size = xx_io_total_size(outer->device);
    stream_end = outer->base_address + common->compressed_size;
    outer->format_size = common->compressed_size;
    if (total_size > stream_end) {
        outer->overlay_offset = stream_end;
        outer->overlay_size = total_size - stream_end;
    } else {
        outer->overlay_offset = -1;
        outer->overlay_size = 0;
    }
    outer->number_of_archive_records = common->tar->format.number_of_archive_records;
    outer->format_type = XX_TYPE_ARCHIVE;
    outer->is_archive = true;
    outer->is_executable = false;
    outer->is_crypted = false;
    outer->is_valid = true;
    outer->base_info_handled = true;
    return true;
}

int64_t xx_tar_common_get_format_size(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode, xx_pd_struct *pd)
{
    if (!outer || (!outer->base_info_handled && !xx_tar_common_handle_base_info(common, outer, decode, pd))) {
        return -1;
    }
    return outer->format_size;
}

uint64_t xx_tar_common_get_number_of_archive_records(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode, xx_pd_struct *pd)
{
    if (!outer || (!outer->base_info_handled && !xx_tar_common_handle_base_info(common, outer, decode, pd))) {
        return 0U;
    }
    return outer->number_of_archive_records;
}

xx_archive_record_state *xx_tar_common_create_archive_records_reading(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode,
                                                                      const xx_list_s *options, xx_pd_struct *pd)
{
    if (!outer || (!outer->base_info_handled && !xx_tar_common_handle_base_info(common, outer, decode, pd)) || !common || !common->tar) {
        return NULL;
    }
    return xx_tar_create_archive_records_reading(&common->tar->format, options, pd);
}

const xx_archive_record *xx_tar_common_get_current_archive_record(xx_tar_common *common, xx_archive_record_state *state)
{
    return common && common->tar ? xx_tar_get_current_archive_record(&common->tar->format, state) : NULL;
}

bool xx_tar_common_unpack_current_archive_record(xx_tar_common *common, xx_archive_record_state *state, xx_pd_struct *pd)
{
    return common && common->tar && xx_tar_unpack_current_archive_record(&common->tar->format, state, pd);
}

bool xx_tar_common_archive_record_move_to_next(xx_tar_common *common, xx_archive_record_state *state, xx_pd_struct *pd)
{
    return common && common->tar && xx_tar_archive_record_move_to_next(&common->tar->format, state, pd);
}

void xx_tar_common_free_archive_records_reading(xx_tar_common *common, xx_archive_record_state *state)
{
    if (common && common->tar) {
        xx_tar_free_archive_records_reading(&common->tar->format, state);
    } else {
        xx_archive_record_state_free(state);
    }
}

static bool xx_tar_common_copy_write_options(xx_list_s *destination, const xx_list_s *source)
{
    size_t index;
    if (!destination || !source) return source == NULL;
    for (index = 0U; index < source->count; ++index) {
        const xx_meta *item = (const xx_meta *)xx_list_at((const xx_list_t *)source, index);
        xx_meta copy;
        if (!item) continue;
        xx_meta_init(&copy, item->meta_id);
        if (!xx_var_copy(&copy.var, &item->var) || !xx_list_append(destination, &copy)) {
            xx_meta_cleanup(&copy);
            return false;
        }
    }
    return true;
}

static bool xx_tar_common_writer_reserve(xx_tar_common_writer *writer, size_t required)
{
    size_t capacity;
    uint8_t *grown;
    if (!writer || required > XX_TAR_COMMON_MAX_DECODED_SIZE) return false;
    if (required <= writer->capacity) return true;
    capacity = writer->capacity ? writer->capacity : XX_TAR_COMMON_INITIAL_CAPACITY;
    while (capacity < required) {
        if (capacity > XX_TAR_COMMON_MAX_DECODED_SIZE / 2U) {
            capacity = XX_TAR_COMMON_MAX_DECODED_SIZE;
        } else {
            capacity *= 2U;
        }
    }
    grown = (uint8_t *)xx_mem_realloc(writer->data, capacity);
    if (!grown) return false;
    writer->data = grown;
    writer->capacity = capacity;
    return true;
}

static ssize_t xx_tar_common_writer_read(xx_io_device *device, void *data, size_t size)
{
    xx_tar_common_writer *writer = device ? (xx_tar_common_writer *)device->priv : NULL;
    size_t available;
    size_t amount;
    if (!writer || (!data && size != 0U)) return -1;
    if (size == 0U) return 0;
    if (writer->position >= writer->size) return 0;
    available = writer->size - writer->position;
    amount = size < available ? size : available;
    xx_mem_copy(data, writer->data + writer->position, amount);
    writer->position += amount;
    return (ssize_t)amount;
}

static ssize_t xx_tar_common_writer_write(xx_io_device *device, const void *data, size_t size)
{
    xx_tar_common_writer *writer = device ? (xx_tar_common_writer *)device->priv : NULL;
    size_t required;
    if (!writer || (!data && size != 0U)) return -1;
    if (size == 0U) return 0;
    if (writer->position > XX_TAR_COMMON_MAX_DECODED_SIZE || size > XX_TAR_COMMON_MAX_DECODED_SIZE - writer->position) {
        return -1;
    }
    required = writer->position + size;
    if (!xx_tar_common_writer_reserve(writer, required)) return -1;
    if (writer->position > writer->size) {
        xx_mem_zero(writer->data + writer->size, writer->position - writer->size);
    }
    xx_mem_copy(writer->data + writer->position, data, size);
    writer->position = required;
    if (required > writer->size) writer->size = required;
    return (ssize_t)size;
}

static int xx_tar_common_writer_seek(xx_io_device *device, long offset, int origin)
{
    xx_tar_common_writer *writer = device ? (xx_tar_common_writer *)device->priv : NULL;
    size_t base;
    size_t position;
    uint64_t distance;
    if (!writer) return -1;
    if (origin == SEEK_SET) base = 0;
    else if (origin == SEEK_CUR) base = writer->position;
    else if (origin == SEEK_END) base = writer->size;
    else return -1;

    if (offset >= 0L) {
        distance = (uint64_t)(unsigned long)offset;
        if (distance > (uint64_t)XX_TAR_COMMON_MAX_DECODED_SIZE - (uint64_t)base) {
            return -1;
        }
        position = base + (size_t)distance;
    } else {
        /* Avoid negating LONG_MIN directly. */
        distance = (uint64_t)(unsigned long)(-(offset + 1L)) + 1U;
        if (distance > (uint64_t)base) return -1;
        position = base - (size_t)distance;
    }
    writer->position = position;
    return 0;
}

static int64_t xx_tar_common_writer_size(xx_io_device *device)
{
    const xx_tar_common_writer *writer = device ? (const xx_tar_common_writer *)device->priv : NULL;
    return writer ? (int64_t)writer->size : -1;
}

static void xx_tar_common_writer_free(void *pointer)
{
    xx_tar_common_writer *writer = (xx_tar_common_writer *)pointer;
    if (!writer) return;
    if (writer->tar_state) {
        xx_format_free_archive_records_writing(&writer->tar.format, writer->tar_state);
        writer->tar_state = NULL;
    }
    xx_tar_destroy(&writer->tar);
    if (writer->data) xx_mem_free(writer->data);
    xx_mem_free(writer);
}

xx_archive_write_state *xx_tar_common_create_archive_records_writing(Abstractformat *outer, const xx_list_s *options, xx_tar_common_encode_fn encode, xx_pd_struct *pd)
{
    xx_archive_write_state *state;
    xx_tar_common_writer *writer;
    if (!outer || !outer->device || !outer->device->write || !outer->device->seek || !encode || outer->base_address < 0 || outer->base_address > LONG_MAX ||
        (pd && xx_pd_is_stopped(pd))) {
        return NULL;
    }
    state = (xx_archive_write_state *)xx_mem_alloc(sizeof(*state));
    writer = (xx_tar_common_writer *)xx_mem_calloc(1U, sizeof(*writer));
    if (!state || !writer) {
        if (state) xx_mem_free(state);
        if (writer) xx_mem_free(writer);
        return NULL;
    }
    xx_archive_write_state_init(state, outer);
    if (!xx_tar_common_copy_write_options(&state->options, options)) {
        xx_archive_write_state_free(state);
        xx_mem_free(writer);
        return NULL;
    }
    writer->device.read = xx_tar_common_writer_read;
    writer->device.write = xx_tar_common_writer_write;
    writer->device.seek = xx_tar_common_writer_seek;
    writer->device.total_size = xx_tar_common_writer_size;
    writer->device.get_total_size = xx_tar_common_writer_size;
    writer->device.size = xx_tar_common_writer_size;
    writer->device.priv = writer;
    writer->encode = encode;
    xx_tar_init(&writer->tar, &writer->device, 0);
    writer->tar_state = xx_format_create_archive_records_writing(&writer->tar.format, NULL, pd);
    if (!writer->tar_state) {
        xx_tar_destroy(&writer->tar);
        xx_archive_write_state_free(state);
        xx_mem_free(writer);
        return NULL;
    }
    state->internal_state = writer;
    state->free_internal = xx_tar_common_writer_free;
    state->current_index = -1;
    state->total_records = 0;
    outer->format_size = -1;
    outer->number_of_archive_records = 0U;
    outer->overlay_offset = -1;
    outer->overlay_size = 0;
    outer->is_valid = false;
    outer->base_info_handled = false;
    return state;
}

bool xx_tar_common_pack_archive_record(Abstractformat *outer, xx_archive_write_state *state, const xx_archive_record *record, xx_io_device *source_dev, xx_pd_struct *pd)
{
    xx_tar_common_writer *writer;
    bool result;
    if (!outer || !state || state->format != outer || !record || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    writer = (xx_tar_common_writer *)state->internal_state;
    if (writer->tar_finalized || writer->finalized || !writer->tar_state) {
        return false;
    }
    result = xx_format_pack_archive_record(&writer->tar.format, writer->tar_state, record, source_dev, pd);
    if (result) {
        state->current_index = writer->tar_state->current_index;
        state->total_records = writer->tar_state->total_records;
    }
    return result;
}

bool xx_tar_common_finalize_archive_records_writing(Abstractformat *outer, xx_archive_write_state *state, xx_pd_struct *pd)
{
    xx_tar_common_writer *writer;
    int64_t compressed_size = -1;
    int64_t total_size;
    int64_t stream_end;
    if (!outer || !state || state->format != outer || !state->internal_state || (pd && xx_pd_is_stopped(pd))) {
        return false;
    }
    writer = (xx_tar_common_writer *)state->internal_state;
    if (writer->finalized || !writer->tar_state || !writer->encode) {
        return false;
    }
    if (!writer->tar_finalized) {
        if (!xx_format_finalize_archive_records_writing(&writer->tar.format, writer->tar_state, pd)) {
            return false;
        }
        writer->tar_finalized = true;
    }
    writer->position = 0U;
    if (writer->size == 0U || (uint64_t)writer->size > (uint64_t)INT64_MAX ||
        !writer->encode(outer, &state->options, &writer->device, (int64_t)writer->size, &compressed_size, pd) || compressed_size <= 0 ||
        compressed_size > INT64_MAX - outer->base_address) {
        return false;
    }
    writer->finalized = true;
    state->current_index = writer->tar_state->current_index;
    state->total_records = writer->tar_state->total_records;
    outer->format_size = compressed_size;
    outer->number_of_archive_records = state->total_records > 0 ? (uint64_t)state->total_records : 0U;
    outer->is_valid = true;
    /* The transport is valid, but there is no parsed read cache for the new
     * bytes yet. A subsequent read/getter must rebuild that cache. */
    outer->base_info_handled = false;
    stream_end = outer->base_address + compressed_size;
    total_size = xx_io_total_size(outer->device);
    if (total_size > stream_end) {
        outer->overlay_offset = stream_end;
        outer->overlay_size = total_size - stream_end;
    } else {
        outer->overlay_offset = -1;
        outer->overlay_size = 0;
    }
    return true;
}

void xx_tar_common_free_archive_records_writing(Abstractformat *outer, xx_archive_write_state *state)
{
    (void)outer;
    xx_archive_write_state_free(state);
}
