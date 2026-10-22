/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT */
#include "../../adapters/xx_reader_adapter.h"
#include "xxfclib/formats/video/scummvm_dxa/xx_scummvm_dxa.h"
static Abstractformat *sdxa_open(xx_io_device *d) { return (Abstractformat *)xx_scummvm_dxa_create(d, 0); }
static void sdxa_close(Abstractformat *f) { xx_scummvm_dxa_free((xx_scummvm_dxa *)f); }
static const xx_file_type_t sdxa_types[] = {XX_FILE_TYPE_SCUMMVM_DXA};
static const uint8_t sdxa_magic[] = {'D', 'E', 'X', 'A'};
static const xx_format_search_anchor sdxa_anchors[] = {{sdxa_magic, 4U, 0U}};
static const xx_format_search_desc sdxa_descriptor = {sdxa_types, 1U, sdxa_anchors, 1U, sdxa_open, sdxa_close, true};
XX_FORMAT_DEFINE_ABSTRACT_EXTRACTOR(scummvm_dxa, sdxa_descriptor)
