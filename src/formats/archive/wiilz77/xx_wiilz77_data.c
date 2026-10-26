/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WII LZ77 data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_imd5_header_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
    SX_FIELD("content_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("reserved", "bytes", 8, 8, SX_RESERVED),
    SX_FIELD("md5", "bytes", 16, 16, SX_CHECKSUM),
};
const sx_layout sxl_imd5_header = { UINT32_C(0x600A0003), "imd5_header", sxl_imd5_header_fields, SX_COUNT(sxl_imd5_header_fields), SX_BE };
static const xx_data_struct_field_desc sxl_wii_lz77_tag_fields[] = {
    SX_FIELD("signature", "bytes", 0, 4, SX_SIGNATURE),
};
const sx_layout sxl_wii_lz77_tag = { UINT32_C(0x600A0004), "wii_lz77_tag", sxl_wii_lz77_tag_fields, SX_COUNT(sxl_wii_lz77_tag_fields), SX_LE };
static const xx_data_struct_field_desc sxl_wii_lz77_extended_size_fields[] = {
    SX_FIELD("original_size", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sxl_wii_lz77_extended_size = { UINT32_C(0x600A0006), "wii_lz77_extended_size", sxl_wii_lz77_extended_size_fields, SX_COUNT(sxl_wii_lz77_extended_size_fields), SX_LE };
static bool sxl_wii(sx_context *c)
{
    int64_t at=0;uint8_t h[4];uint32_t n;
    if(!sx_read(c,0,h,4))return false;
    if(!xx_rt_memcmp(h,"IMD5",4)){if(!sx_add(c,&sxl_imd5_header,0,32))return false;at=32;if(!sxl_sig(c,at,"LZ77",4))return false;}
    if(!sx_read(c,at,h,4))return false;
    if(!xx_rt_memcmp(h,"LZ77",4)){if(!sx_add(c,&sxl_wii_lz77_tag,at,4))return false;at+=4;if(!sx_read(c,at,h,4))return false;}
    if((h[0]!=0x10&&h[0]!=0x11)||!sx_add(c,&sxl_wii_lz77_header,at,4))return false;
    at+=4;n=(uint32_t)h[1]|((uint32_t)h[2]<<8)|((uint32_t)h[3]<<16);
    if(!n){if(!sx_u32(c,at,false,&n)||!sx_add(c,&sxl_wii_lz77_extended_size,at,4))return false;at+=4;}
    return n>0&&sxl_span(c,(uint64_t)at,2);
}
bool sx_wiilz77_build(sx_context*c)
{
    return sxl_wii(c);
}
