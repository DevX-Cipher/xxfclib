/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SONY_PSF data structures, moved out of the storage schema family. */
#include "../../xx_format_schema_storage.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_st_psf_header_fields[] = {
    SX_FIELD("signature", "byte[3]", 0, 3, SX_SIGNATURE),
    SX_FIELD("version", "uint8", 3, 1, SX_NONE),
    SX_FIELD("reserved_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("compressed_program_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("compressed_program_crc32", "uint32", 12, 4, SX_CHECKSUM),
};
const sx_layout sx_st_psf_header = {0x60080012U, "psf_header", sx_st_psf_header_fields, SX_COUNT(sx_st_psf_header_fields), SX_LE};
bool sx_sony_psf_build(sx_context*c)
{
    bool ok=false;
    ok=sx_add(c,&sx_st_psf_header,0,16);
    return ok&&sx_st_finish(c);
}
