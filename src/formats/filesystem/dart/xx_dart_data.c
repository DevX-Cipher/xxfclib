/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * dart data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_dart_header_fields[] = {
    SX_FIELD("compression","uint8",0,1,SX_ID),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
    SX_FIELD("disk_size_kib","uint16",2,2,SX_NONE),
};
const sx_layout sxdleg_dart_header = {0x60750005U,"dart_header",sxdleg_dart_header_fields,SX_COUNT(sxdleg_dart_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdleg_dart_block_length_fields[] = {
    SX_FIELD("encoded_length","uint16",0,2,SX_NONE),
};
const sx_layout sxdleg_dart_block_length = {0x60750006U,"dart_block_length",sxdleg_dart_block_length_fields,SX_COUNT(sxdleg_dart_block_length_fields),SX_BE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
#define SXDLEG_TABLE(c,l,p,n) sxdleg_put(c,&sxdleg_##l,p,n)
static bool sxdleg_dart(sx_context*c){uint8_t h[4];if(!sxdleg_read(c,0,h,4)||h[0]>2)return false;unsigned kib=sxdleg16(h+2,1),n=kib<=800?40:72;if(!kib||!sxdleg_span(c,4,n*2))return false;return SXDLEG_ADD(c,dart_header,0)&&SXDLEG_TABLE(c,dart_block_length,4,n);}
#undef SXDLEG_ADD
#undef SXDLEG_TABLE
bool sx_dart_build(sx_context*c)
{
 return sxdleg_dart(c);
}
