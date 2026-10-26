/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LZV1 data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_lzv1_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("format_marker", "bytes", 4, 6, SX_SIGNATURE),
    SX_FIELD("maximum_codes", "uint16", 10, 2, SX_COUNT_PROP),
};
const sx_layout sxl_lzv1_header = { UINT32_C(0x600A0008), "lzv1_header", sxl_lzv1_header_fields, SX_COUNT(sxl_lzv1_header_fields), SX_BE };
bool sx_lzv1_build(sx_context*c)
{
    uint16_t n;return sxl_sig(c,0,"LZV1\x5d\x19\x01\xad\0\0",10)&&sx_u16(c,10,true,&n)&&n>256&&n<16384&&sxl_span(c,12,1)&&sx_add(c,&sxl_lzv1_header,0,12);
}
