/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QDA archives data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_qda_header_fields[] = {
 SX_FIELD("packed","uint32",0,4,SX_NONE),
 SX_FIELD("signature","char[4]",4,4,SX_SIGNATURE),
 SX_FIELD("member_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint32",12,4,SX_NONE),
 SX_FIELD("unused","uint8[240]",16,240,SX_NONE),
};
const sx_layout sxafr_qda_header = {UINT32_C(0x6054001e),"qda_header",sxafr_qda_header_fields,SX_COUNT(sxafr_qda_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_qda_member_fields[] = {
 SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("name","char[256]",12,256,SX_NONE),
};
const sx_layout sxafr_qda_member = {UINT32_C(0x6054001f),"qda_member",sxafr_qda_member_fields,SX_COUNT(sxafr_qda_member_fields),SX_LE};
static bool sxafr_qda(sx_context*c){uint64_t n;if(!sxafr_word(c,8,4,false,&n)||!sxafr_add(c,&sxafr_qda_header,0)||n>((uint64_t)c->size-256)/268)return false;for(uint64_t i=0;i<n;i++)if(!sxafr_add(c,&sxafr_qda_member,256+i*268))return false;return true;}
bool sx_qda_build(sx_context*c)
{
 return sxafr_qda(c);
}
