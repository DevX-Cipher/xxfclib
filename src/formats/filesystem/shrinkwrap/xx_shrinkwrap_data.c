/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ShrinkWrap data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_shrinkwrap_header_fields[] = {
    SX_FIELD("name_length","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("disk_name","char[63]",1,63,SX_NONE),
    SX_FIELD("data_size","uint32",64,4,SX_SIZE),
    SX_FIELD("tag_size","uint32",68,4,SX_SIZE),
    SX_FIELD("data_checksum","uint32",72,4,SX_CHECKSUM),
    SX_FIELD("tag_checksum","uint32",76,4,SX_CHECKSUM),
    SX_FIELD("disk_format","uint8",80,1,SX_ID),
    SX_FIELD("format_byte","uint8",81,1,SX_ID),
    SX_FIELD("private_word","uint16",82,2,SX_ID),
};
const sx_layout sxdleg_shrinkwrap_header = {0x60750001U,"shrinkwrap_header",sxdleg_shrinkwrap_header_fields,SX_COUNT(sxdleg_shrinkwrap_header_fields),SX_BE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_shrinkwrap(sx_context*c){uint8_t h[84];if(!sxdleg_read(c,0,h,84)||h[0]>63||sxdleg16(h+82,1)!=256)return false;return SXDLEG_ADD(c,shrinkwrap_header,0);}
#undef SXDLEG_ADD
bool sx_shrinkwrap_build(sx_context*c)
{
 return sxdleg_shrinkwrap(c);
}
