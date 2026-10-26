/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SOFTRONICS data structures, moved out of the legacy schema family. */
#include "../../xx_format_schema_legacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxl_softronics_header_fields[] = {
    SX_FIELD("header_size", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("reserved", "uint8", 1, 1, SX_RESERVED),
    SX_FIELD("signature", "bytes", 2, 40, SX_SIGNATURE),
    SX_FIELD("packed_size", "uint32", 42, 4, SX_SIZE),
};
const sx_layout sxl_softronics_header = { UINT32_C(0x600A000D), "softronics_header", sxl_softronics_header_fields, SX_COUNT(sxl_softronics_header_fields), SX_LE };
static const xx_data_struct_field_desc sxl_softronics_metadata_fields[] = {
    SX_FIELD("original_size", "uint32", 0, 4, SX_SIZE),
    SX_FIELD("dos_time", "uint16", 4, 2, SX_NONE),
    SX_FIELD("dos_date", "uint16", 6, 2, SX_NONE),
};
const sx_layout sxl_softronics_metadata = { UINT32_C(0x600A000E), "softronics_metadata", sxl_softronics_metadata_fields, SX_COUNT(sxl_softronics_metadata_fields), SX_LE };
static bool sxl_softronics(sx_context *c)
{
    int64_t at;uint8_t size;uint32_t packed,n;
    if(!sxl_byte(c,0,&size)||!sxl_sig(c,1,"\0",1)||!sxl_sig(c,2,"Softronics Compressed File\0Version 2.00\0",40)||!sx_u32(c,42,false,&packed)||!packed||!sx_add(c,&sxl_softronics_header,0,46)||!sxl_name(c,46,c->size<59?c->size:59,&at)||at+8!=size||!sx_u32(c,at,false,&n)||!n||!sx_add(c,&sxl_softronics_metadata,at,8))return false;
    return sxl_span(c,size,packed)&&(uint64_t)size+packed==(uint64_t)c->size;
}
bool sx_softronics_build(sx_context*c)
{
    return sxl_softronics(c);
}
