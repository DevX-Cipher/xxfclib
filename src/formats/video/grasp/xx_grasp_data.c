/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GRASP data structures, moved out of the videotail schema family. */
#include "../../xx_format_schema_videotail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvt_grasp_header_fields[] = {
 SX_FIELD("index_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxvt_grasp_header = {UINT32_C(0x60390001),"grasp_header",sxvt_grasp_header_fields,SX_COUNT(sxvt_grasp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_grasp_entry_fields[] = {
 SX_FIELD("member_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name","char[13]",4,13,SX_STRING),
};
const sx_layout sxvt_grasp_entry = {UINT32_C(0x60390002),"grasp_entry",sxvt_grasp_entry_fields,SX_COUNT(sxvt_grasp_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_grasp_member_size_fields[] = {
 SX_FIELD("member_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxvt_grasp_member_size = {UINT32_C(0x60390003),"grasp_member_size",sxvt_grasp_member_size_fields,SX_COUNT(sxvt_grasp_member_size_fields),SX_LE};
static bool sxvt_grasp(sx_context*c){uint64_t z;if(!sxvt_word(c,0,2,false,&z)||z%17||!sxvt_span(c,2,z)||!sxvt_add(c,&sxvt_grasp_header,0))return false;for(uint64_t p=2;p<2+z;p+=17){uint64_t off,n;if(!sxvt_word(c,p,4,false,&off)||!sxvt_add(c,&sxvt_grasp_entry,p))return false;if(!off)break;if(!sxvt_word(c,off,4,false,&n)||!sxvt_span(c,off+4,n)||!sxvt_add(c,&sxvt_grasp_member_size,off))return false;}return true;}
bool sx_grasp_build(sx_context*c)
{
 return sxvt_grasp(c);
}
