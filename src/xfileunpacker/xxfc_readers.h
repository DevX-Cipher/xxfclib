/* Copyright (c) 2026 hors <horsicq@gmail.com>
 * SPDX-License-Identifier: MIT */
#ifndef XXFC_UNPACK_READERS_H
#define XXFC_UNPACK_READERS_H

#include "xxfclib/formats/xx_format.h"

typedef void (*xxfc_release_fn)(Abstractformat *format);
typedef struct xxfc_opened {
    Abstractformat *format;
    xx_file_type_t type;
    const char *reader_name;
    char name_storage[128];
} xxfc_opened;

bool xxfc_open_type(xxfc_opened *, xx_io_device *, int64_t, xx_file_type_t);
bool xxfc_open_named(xxfc_opened *, xx_io_device *, int64_t, const char *);
bool xxfc_open_extension(xxfc_opened *, xx_io_device *, int64_t, const char *, xx_pd_struct *);
bool xxfc_open_extension_fast(xxfc_opened *, xx_io_device *, int64_t, const char *, xx_pd_struct *);
bool xxfc_open_fallback(xxfc_opened *, xx_io_device *, int64_t, const char *, const char *, xx_file_type_t, xx_pd_struct *);
void xxfc_close(xxfc_opened *);
void xxfc_attach_source_files(xxfc_opened *, const char *);
void xxfc_refresh_sevenzip_type(xxfc_opened *);
bool xxfc_reader_uses_helper(const xxfc_opened *);
bool xxfc_is_incomplete(const xxfc_opened *);
Abstractformat *xxfc_make_writer(const char *, xx_io_device *, xxfc_release_fn *);

#endif
