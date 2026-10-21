/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XX_SCAN_ARCHIVES_INTERNAL_H
#define XX_SCAN_ARCHIVES_INTERNAL_H

#include "xxfclib/scan/xx_scan.h"

typedef struct xx_scan_archive_member {
    xx_io_device *device;   /* Borrowed, read-only decoded contents, based at zero. */
    const char *name;       /* Borrowed; no archive-derived pathname is opened. */
    int64_t source_offset; /* Absolute compressed payload/slice offset in the parent. */
    int64_t source_size;   /* Stored source extent; decoded size may differ. */
    int64_t size;          /* Size of device. */
    bool is_compressed;   /* Decoded offsets do not map to parent bytes when true. */
} xx_scan_archive_member;

/* The member, its device and name are lent only for this synchronous call.
 * Returning false aborts enumeration. The callback must not close the device. */
typedef bool (*xx_scan_archive_callback)(void *context, const xx_scan_archive_member *member, xx_pd_struct *pd);

/* Visit verified ZIP/LHA payloads, decoded concatenated GZIP/BZIP2 streams,
 * and Mach-O FAT slices within options.offset/size. ZIP Store, ordinary LHA
 * LH0/LZ4 and Mach-O FAT use bounded xx_io_sub source views after required
 * integrity validation. Decoded output stays in memory only below
 * xx_get_file_buffer_size(); equality or a larger size uses xx_io_temp_open,
 * including a spill as GZIP/BZIP2 output grows. Temporary storage is cleaned
 * up after the callback and respects an active memory-only policy. Archive
 * child scans use these devices directly without an eager input copy.
 * Other formats succeed without callbacks. Empty files are visited;
 * directories are skipped. Encrypted, damaged, unsupported or oversized
 * members fail explicitly. No archive-derived output path is opened; parent
 * ownership and cursor are preserved. options.archive_max_* bounds member
 * size, total decoded size and count (zero selects defaults). Decoder-internal
 * buffers are independent of the output storage threshold. */
bool xx_scan_visit_archives(xx_io_device *device, const xx_scan_options *options,
                            xx_scan_archive_callback callback, void *context, xx_pd_struct *pd);

#endif /* XX_SCAN_ARCHIVES_INTERNAL_H */
