/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MS-COMPRESS (SZDD/SZ) data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_szdd_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
    SX_FIELD("method", "uint8", 8, 1, SX_ID),
    SX_FIELD("missing_filename_character", "char[1]", 9, 1, SX_STRING),
    SX_FIELD("original_size", "uint32", 10, 4, SX_SIZE),
};
const sx_layout sxl_szdd_header = { UINT32_C(0x600A0001), "szdd_header", sxl_szdd_header_fields, SX_COUNT(sxl_szdd_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_sz_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 7, SX_SIGNATURE),
    SX_FIELD("volume_marker", "uint8", 7, 1, SX_ID),
    SX_FIELD("original_size", "uint32", 8, 4, SX_SIZE),
};
const sx_layout sxl_sz_header = { UINT32_C(0x600A0002), "sz_header", sxl_sz_header_fields, SX_COUNT(sxl_sz_header_fields), SX_LE };
bool sx_mscompress_build(sx_context*c)
{
    bool ok=false;
        if(sxl_sig(c,0,"SZDD\x88\xf0\x27\x33",8)){ok=sxl_sig(c,8,"A",1)&&sxl_span(c,14,0)&&sx_add(c,&sxl_szdd_header,0,14);}
        else ok=sxl_sig(c,0,"SZ \x88\xf0\x27\x33\xd1",8)&&sx_add(c,&sxl_sz_header,0,12);
    return ok;
}
