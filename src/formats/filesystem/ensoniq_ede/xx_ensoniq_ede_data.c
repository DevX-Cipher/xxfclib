/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ensoniq ede data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_ede_text_header_fields[] = {
    SX_FIELD("line_start","byte[2]",0,2,SX_SIGNATURE),
    SX_FIELD("description","char[76]",2,76,SX_NONE),
    SX_FIELD("line_end","byte[2]",78,2,SX_SIGNATURE),
};
const sx_layout sxdleg_ede_text_header = {0x60750035U,"ede_text_header",sxdleg_ede_text_header_fields,SX_COUNT(sxdleg_ede_text_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ede_bitmap_marker_fields[] = {
    SX_FIELD("text_end","byte[3]",0,3,SX_SIGNATURE),
};
const sx_layout sxdleg_ede_bitmap_marker = {0x60750036U,"ede_bitmap_marker",sxdleg_ede_bitmap_marker_fields,SX_COUNT(sxdleg_ede_bitmap_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ede_bitmap_byte_fields[] = {
    SX_FIELD("sector_bitmap","uint8",0,1,SX_FLAGS),
};
const sx_layout sxdleg_ede_bitmap_byte = {0x60750037U,"ede_bitmap_byte",sxdleg_ede_bitmap_byte_fields,SX_COUNT(sxdleg_ede_bitmap_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_ede_format_fields[] = {
    SX_FIELD("computer_format","uint8",0,1,SX_FLAGS),
    SX_FIELD("disk_type","uint8",1,1,SX_ID),
};
const sx_layout sxdleg_ede_format = {0x60750038U,"ede_format",sxdleg_ede_format_fields,SX_COUNT(sxdleg_ede_format_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
#define SXDLEG_TABLE(c,l,p,n) sxdleg_put(c,&sxdleg_##l,p,n)
static bool sxdleg_ede(sx_context*c){uint8_t h[512];if(!sxdleg_read(c,0,h,512)||h[0]!=13||h[1]!=10||h[78]!=13||h[79]!=10)return false;unsigned t=h[511],heads=t==1?1:2,sectors=t==1||t==2?6:t==203||t==204?20:10,bitmap=t==203||t==204?96:160,n=(80*heads*sectors+7)/8;if(bitmap+n>510)return false;return SXDLEG_ADD(c,ede_text_header,0)&&SXDLEG_ADD(c,ede_bitmap_marker,bitmap-3)&&SXDLEG_TABLE(c,ede_bitmap_byte,bitmap,n)&&SXDLEG_ADD(c,ede_format,510);}
#undef SXDLEG_ADD
#undef SXDLEG_TABLE
bool sx_ensoniq_ede_build(sx_context*c)
{
 return sxdleg_ede(c);
}
