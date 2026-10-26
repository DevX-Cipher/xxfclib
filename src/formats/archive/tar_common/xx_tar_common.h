/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/** @file xx_tar_common.h @brief Shared compressed-TAR adapter support. */

#ifndef XXFCLIB_FORMAT_TAR_COMMON_H
#define XXFCLIB_FORMAT_TAR_COMMON_H

#include "xxfclib/formats/archive/tar/xx_tar.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Internal entry point for carriers with rooted installation paths. The
 * supplied relative name is checked by TAR's normal path-safety rules. */
bool xx_tar_unpack_current_archive_record_as(Abstractformat *, xx_archive_record_state *, xx_pd_struct *, const char *relative_name);

/* Internal entry point for the decoded prefix of a cut stream: base info of
 * a TAR whose data may end anywhere, in a header or in a member's data (see
 * xx_tar_parse_archive). */
bool xx_tar_handle_base_info_prefix(Abstractformat *self, xx_pd_struct *pd);

/**
 * Decode the compressed stream represented by @p outer into @p destination.
 * On success, @p compressed_size receives the exact number of source bytes
 * occupied by the compressed stream (excluding an optional outer overlay).
 * A stream that ends before it is complete (a cut file) fails after calling
 * xx_tar_common_stream_cut(destination): what it wrote is then its decoded
 * prefix, no byte of which the stream's own checks refused. A damaged stream
 * (a failed check, invalid data) fails without that call. Either way, whole
 * or cut, it reports what its checks vouch for (xx_tar_common_stream_checked):
 * a whole stream's TAR can still be cut.
 */
typedef bool (*xx_tar_common_decode_fn)(Abstractformat *outer, xx_io_device *destination, int64_t *compressed_size, xx_pd_struct *pd);

/** Report to the cache, the destination of a decode function, that the
 * stream ends before it is complete. Ignored for any other device. */
void xx_tar_common_stream_cut(xx_io_device *destination);

/** Report to the cache, the destination of a decode function, that a check
 * of the stream vouches for the first @p size bytes it wrote; in a cut
 * stream, a member that ends past them is read without one. Ignored for any
 * other device. */
void xx_tar_common_stream_checked(xx_io_device *destination, uint64_t size);

/* Internal: in a TAR read by xx_tar_handle_base_info_prefix, mark each
 * member before the cut whose header or data ends past @p checked_size as
 * read without a check (it is still read, as GNU tar reads it); true when
 * there is one. xx_tar_last_unverified tells whether the last member
 * unpacked is one of them, or a hard link to one; xx_tar_last_cut whether
 * it is the member the cut runs through, or a hard link to it. */
bool xx_tar_prefix_checked(Abstractformat *self, int64_t checked_size);
bool xx_tar_last_unverified(const Abstractformat *self);
bool xx_tar_last_cut(const Abstractformat *self);

/* Internal: whether the 512 bytes at @p block are a TAR header (not zero,
 * its checksum right), as the first of a cut stream's TAR with a member is:
 * a cut stream that holds something else is left to its own reader before
 * it is cached. */
bool xx_tar_block_is_header(const void *block);

/* Whether @p size bytes at @p data are a whole TAR, as the plain TAR reader
 * takes one. */
bool xx_tar_common_is_whole_tar(const uint8_t *data, size_t size, xx_pd_struct *pd);

/**
 * Encode a finalized logical TAR stream into the transport owned by @p outer.
 * Implementations must start writing at outer->base_address and return the
 * exact encoded transport size through @p compressed_size.
 */
typedef bool (*xx_tar_common_encode_fn)(Abstractformat *outer, const xx_list_s *options, xx_io_device *tar_source, int64_t tar_size, int64_t *compressed_size,
                                        xx_pd_struct *pd);

/** Private state embedded by the tar.gz, tar.bz2, and tar.xz readers.
 * The decoded TAR is kept in RAM (decoded_data) up to a threshold, beyond
 * which it moves to a temporary file (spill) unless a memory-only scope is
 * active; decoded_size counts all of it. */
typedef struct xx_tar_common_s {
    uint8_t *decoded_data;
    size_t decoded_size;
    size_t decoded_capacity;
    xx_io_device *spill;
    xx_io_device *decoded_device;
    xx_tar *tar;
    int64_t compressed_size;
    bool attempted;
    bool valid;
    /* The stream ends before it is complete, or the TAR in a whole one is
     * cut: the TAR is a decoded prefix. */
    bool cut;
    /* In a cut stream, the decoded bytes from the start that a check of the
     * stream vouches for (xx_tar_common_stream_checked). */
    size_t checked_size;
    /* In a cut stream, a member before the cut ends past them. */
    bool unverified;
    /* The TAR is larger than the RAM a memory-only scope lets it use: not
     * opened. */
    bool too_large;
    /* The TAR in a temporary file grew past the RAM maximum to more than
     * XX_TAR_COMMON_MAX_RATIO times source_size (a decompression bomb): not
     * opened. */
    bool too_dense;
    /* No temporary file could take it (a full disk): not opened. */
    bool no_room;
    bool spill_failed;
    /* The bytes from the stream's start to the end of the input. */
    int64_t source_size;
    /* The reader that loaded it, whose priv points here. */
    Abstractformat *outer;
} xx_tar_common;

void xx_tar_common_init(xx_tar_common *common);
void xx_tar_common_cleanup(xx_tar_common *common);

bool xx_tar_common_load(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode, xx_pd_struct *pd);
bool xx_tar_common_handle_base_info(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode, xx_pd_struct *pd);
int64_t xx_tar_common_get_format_size(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode, xx_pd_struct *pd);
uint64_t xx_tar_common_get_number_of_archive_records(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode, xx_pd_struct *pd);

xx_archive_record_state *xx_tar_common_create_archive_records_reading(xx_tar_common *common, Abstractformat *outer, xx_tar_common_decode_fn decode,
                                                                      const xx_list_s *options, xx_pd_struct *pd);
const xx_archive_record *xx_tar_common_get_current_archive_record(xx_tar_common *common, xx_archive_record_state *state);
bool xx_tar_common_unpack_current_archive_record(xx_tar_common *common, xx_archive_record_state *state, xx_pd_struct *pd);
bool xx_tar_common_archive_record_move_to_next(xx_tar_common *common, xx_archive_record_state *state, xx_pd_struct *pd);
void xx_tar_common_free_archive_records_reading(xx_tar_common *common, xx_archive_record_state *state);

xx_archive_write_state *xx_tar_common_create_archive_records_writing(Abstractformat *outer, const xx_list_s *options, xx_tar_common_encode_fn encode, xx_pd_struct *pd);
bool xx_tar_common_pack_archive_record(Abstractformat *outer, xx_archive_write_state *state, const xx_archive_record *record, xx_io_device *source_dev, xx_pd_struct *pd);
bool xx_tar_common_finalize_archive_records_writing(Abstractformat *outer, xx_archive_write_state *state, xx_pd_struct *pd);
void xx_tar_common_free_archive_records_writing(Abstractformat *outer, xx_archive_write_state *state);

#ifdef __cplusplus
}
#endif

#endif /* XXFCLIB_FORMAT_TAR_COMMON_H */
