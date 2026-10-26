/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AppleSingle / AppleDouble data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_applesingle_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("home_filesystem_or_filler","char[16]",8,16,SX_NONE),
    SX_FIELD("entry_count","uint16",24,2,SX_COUNT_PROP),
};
const sx_layout sxar_applesingle_header = {UINT32_C(0x601c000c),"applesingle_header",sxar_applesingle_header_fields,SX_COUNT(sxar_applesingle_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_applesingle_entry_fields[] = {
    SX_FIELD("entry_id","uint32",0,4,SX_ID),
    SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxar_applesingle_entry = {UINT32_C(0x601c000d),"applesingle_entry",sxar_applesingle_entry_fields,SX_COUNT(sxar_applesingle_entry_fields),SX_BE};
static bool sxar_applesingle(sx_context *c){uint8_t b[26];if(!sxar_read(c,0,b,26)||!sxar_add(c,&sxar_applesingle_header,0))return false;uint32_t n=sxar16(b+24,true);return sxar_span(c,26,(uint64_t)n*12)&&sx_table(c,&sxar_applesingle_entry,26,12,n);}
bool sx_applesingle_build(sx_context*c)
{
 return sxar_applesingle(c);
}
