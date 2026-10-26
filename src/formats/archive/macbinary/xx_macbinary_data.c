/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MacBinary data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_macbinary1_header_fields[] = {
    SX_FIELD("old_version","uint8",0,1,SX_ID),
    SX_FIELD("name_size","uint8",1,1,SX_SIZE),
    SX_FIELD("name","char[63]",2,63,SX_STRING),
    SX_FIELD("file_type","char[4]",65,4,SX_ID),
    SX_FIELD("creator","char[4]",69,4,SX_ID),
    SX_FIELD("finder_flags_high","uint8",73,1,SX_FLAGS),
    SX_FIELD("zero74","uint8",74,1,SX_RESERVED),
    SX_FIELD("window_vertical","int16",75,2,SX_NONE),
    SX_FIELD("window_horizontal","int16",77,2,SX_NONE),
    SX_FIELD("folder_id","uint16",79,2,SX_ID),
    SX_FIELD("protected_flag","uint8",81,1,SX_FLAGS),
    SX_FIELD("zero82","uint8",82,1,SX_RESERVED),
    SX_FIELD("data_fork_size","uint32",83,4,SX_SIZE),
    SX_FIELD("resource_fork_size","uint32",87,4,SX_SIZE),
    SX_FIELD("created","uint32",91,4,SX_NONE),
    SX_FIELD("modified","uint32",95,4,SX_NONE),
    SX_FIELD("unused_tail","uint8[29]",99,29,SX_NONE),
};
const sx_layout sxar_macbinary1_header = {UINT32_C(0x601c000e),"macbinary1_header",sxar_macbinary1_header_fields,SX_COUNT(sxar_macbinary1_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_macbinary2_header_fields[] = {
    SX_FIELD("old_version","uint8",0,1,SX_ID),
    SX_FIELD("name_size","uint8",1,1,SX_SIZE),
    SX_FIELD("name","char[63]",2,63,SX_STRING),
    SX_FIELD("file_type","char[4]",65,4,SX_ID),
    SX_FIELD("creator","char[4]",69,4,SX_ID),
    SX_FIELD("finder_flags_high","uint8",73,1,SX_FLAGS),
    SX_FIELD("zero74","uint8",74,1,SX_RESERVED),
    SX_FIELD("window_vertical","int16",75,2,SX_NONE),
    SX_FIELD("window_horizontal","int16",77,2,SX_NONE),
    SX_FIELD("folder_id","uint16",79,2,SX_ID),
    SX_FIELD("protected_flag","uint8",81,1,SX_FLAGS),
    SX_FIELD("zero82","uint8",82,1,SX_RESERVED),
    SX_FIELD("data_fork_size","uint32",83,4,SX_SIZE),
    SX_FIELD("resource_fork_size","uint32",87,4,SX_SIZE),
    SX_FIELD("created","uint32",91,4,SX_NONE),
    SX_FIELD("modified","uint32",95,4,SX_NONE),
    SX_FIELD("comment_size","uint16",99,2,SX_SIZE),
    SX_FIELD("finder_flags_low","uint8",101,1,SX_FLAGS),
    SX_FIELD("unused_signature_area","uint8[14]",102,14,SX_NONE),
    SX_FIELD("total_unpacked_size","uint32",116,4,SX_SIZE),
    SX_FIELD("secondary_header_size","uint16",120,2,SX_SIZE),
    SX_FIELD("writer_version","uint8",122,1,SX_ID),
    SX_FIELD("minimum_version","uint8",123,1,SX_ID),
    SX_FIELD("header_crc16","uint16",124,2,SX_CHECKSUM),
    SX_FIELD("reserved_tail","uint16",126,2,SX_RESERVED),
};
const sx_layout sxar_macbinary2_header = {UINT32_C(0x601c000f),"macbinary2_header",sxar_macbinary2_header_fields,SX_COUNT(sxar_macbinary2_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_macbinary3_header_fields[] = {
    SX_FIELD("old_version","uint8",0,1,SX_ID),
    SX_FIELD("name_size","uint8",1,1,SX_SIZE),
    SX_FIELD("name","char[63]",2,63,SX_STRING),
    SX_FIELD("file_type","char[4]",65,4,SX_ID),
    SX_FIELD("creator","char[4]",69,4,SX_ID),
    SX_FIELD("finder_flags_high","uint8",73,1,SX_FLAGS),
    SX_FIELD("zero74","uint8",74,1,SX_RESERVED),
    SX_FIELD("window_vertical","int16",75,2,SX_NONE),
    SX_FIELD("window_horizontal","int16",77,2,SX_NONE),
    SX_FIELD("folder_id","uint16",79,2,SX_ID),
    SX_FIELD("protected_flag","uint8",81,1,SX_FLAGS),
    SX_FIELD("zero82","uint8",82,1,SX_RESERVED),
    SX_FIELD("data_fork_size","uint32",83,4,SX_SIZE),
    SX_FIELD("resource_fork_size","uint32",87,4,SX_SIZE),
    SX_FIELD("created","uint32",91,4,SX_NONE),
    SX_FIELD("modified","uint32",95,4,SX_NONE),
    SX_FIELD("comment_size","uint16",99,2,SX_SIZE),
    SX_FIELD("finder_flags_low","uint8",101,1,SX_FLAGS),
    SX_FIELD("signature","char[4]",102,4,SX_SIGNATURE),
    SX_FIELD("script","uint8",106,1,SX_ID),
    SX_FIELD("extended_finder_flags","uint8",107,1,SX_FLAGS),
    SX_FIELD("reserved","uint8[8]",108,8,SX_RESERVED),
    SX_FIELD("total_unpacked_size","uint32",116,4,SX_SIZE),
    SX_FIELD("secondary_header_size","uint16",120,2,SX_SIZE),
    SX_FIELD("writer_version","uint8",122,1,SX_ID),
    SX_FIELD("minimum_version","uint8",123,1,SX_ID),
    SX_FIELD("header_crc16","uint16",124,2,SX_CHECKSUM),
    SX_FIELD("reserved_tail","uint16",126,2,SX_RESERVED),
};
const sx_layout sxar_macbinary3_header = {UINT32_C(0x601c0010),"macbinary3_header",sxar_macbinary3_header_fields,SX_COUNT(sxar_macbinary3_header_fields),SX_BE};
static bool sxar_macbinary(sx_context *c){uint8_t b[128];if(!sxar_read(c,0,b,128))return false;const sx_layout *l=b[122]==130&&!xx_rt_memcmp(b+102,"mBIN",4)?&sxar_macbinary3_header:b[122]>=129?&sxar_macbinary2_header:&sxar_macbinary1_header;return sxar_add(c,l,0);}
bool sx_macbinary_build(sx_context*c)
{
 return sxar_macbinary(c);
}
