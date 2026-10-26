/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RNC data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_bullfrog_tag_fields[] = {
    SX_FIELD("signature", "bytes", 0, 8, SX_SIGNATURE),
};
const sx_layout sxl_bullfrog_tag = { UINT32_C(0x600A001F), "bullfrog_tag", sxl_bullfrog_tag_fields, SX_COUNT(sxl_bullfrog_tag_fields), SX_BE };
static const xx_data_struct_field_desc sxl_rnc_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 3, SX_SIGNATURE),
    SX_FIELD("method", "uint8", 3, 1, SX_ID),
    SX_FIELD("original_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("packed_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("original_crc16", "uint16", 12, 2, SX_CHECKSUM),
    SX_FIELD("packed_crc16", "uint16", 14, 2, SX_CHECKSUM),
    SX_FIELD("leeway", "uint8", 16, 1, SX_SIZE),
    SX_FIELD("chunk_count", "uint8", 17, 1, SX_COUNT_PROP),
};
const sx_layout sxl_rnc_header = { UINT32_C(0x600A0020), "rnc_header", sxl_rnc_header_fields, SX_COUNT(sxl_rnc_header_fields), SX_BE };
static bool sxl_rnc(sx_context *c)
{
    int64_t at=0;uint8_t h[4];uint32_t packed,n;
    if(!sx_read(c,0,h,4))return false;if(!xx_rt_memcmp(h,"BULL",4)){if(!sxl_sig(c,0,"BULLFROG",8)||!sx_add(c,&sxl_bullfrog_tag,0,8))return false;at=8;}
    return sx_read(c,at,h,4)&&!xx_rt_memcmp(h,"RNC",3)&&(h[3]==1||h[3]==2)&&sx_u32(c,at+4,true,&n)&&n&&sx_u32(c,at+8,true,&packed)&&packed&&sxl_span(c,at+18,packed)&&sx_add(c,&sxl_rnc_header,at,18);
}
bool sx_rnc_build(sx_context*c)
{
    return sxl_rnc(c);
}
