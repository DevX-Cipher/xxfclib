/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LIM archives data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_lim_header_fields[] = {
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("reserved","uint8",4,1,SX_NONE),
 SX_FIELD("unused","uint8",5,1,SX_NONE),
 SX_FIELD("marker","uint16",6,2,SX_SIGNATURE),
};
const sx_layout sxafr_lim_header = {UINT32_C(0x6054001b),"lim_header",sxafr_lim_header_fields,SX_COUNT(sxafr_lim_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_lim_chunk_fields[] = {
 SX_FIELD("tag","uint16",0,2,SX_NONE),
 SX_FIELD("chunk_size","int16",2,2,SX_SIZE),
};
const sx_layout sxafr_lim_chunk = {UINT32_C(0x6054001c),"lim_chunk",sxafr_lim_chunk_fields,SX_COUNT(sxafr_lim_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_lim_member_fields[] = {
 SX_FIELD("unused1","uint8[2]",0,2,SX_NONE),
 SX_FIELD("dos_time","uint16",2,2,SX_NONE),
 SX_FIELD("dos_date","uint16",4,2,SX_NONE),
 SX_FIELD("attributes","uint8",6,1,SX_FLAGS),
 SX_FIELD("unused2","uint8",7,1,SX_NONE),
 SX_FIELD("method","uint8",8,1,SX_NONE),
 SX_FIELD("uncompressed_size","int32",9,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("crc32","uint32",17,4,SX_CHECKSUM),
};
const sx_layout sxafr_lim_member = {UINT32_C(0x6054001d),"lim_member",sxafr_lim_member_fields,SX_COUNT(sxafr_lim_member_fields),SX_LE};
static bool sxafr_zstr(sx_context*c,uint64_t*p,uint64_t end,unsigned cap){for(unsigned i=0;i<cap&&*p<end;i++){uint8_t b;if(!sxafr_read(c,(*p)++,&b,1))return false;if(!b)return true;}return false;}
static bool sxafr_lim(sx_context*c){uint64_t p=8;if(!sxafr_add(c,&sxafr_lim_header,0))return false;while(p<(uint64_t)c->size){uint64_t tag,sz;if(!sxafr_word(c,p,2,false,&tag)||!sxafr_word(c,p+2,2,false,&sz)||sz<4||sz>INT16_MAX||(tag!=0xd180&&tag!=0xf123)||!sxafr_add(c,&sxafr_lim_chunk,p))return false;p+=4;uint64_t z=0;if(tag==0xf123){if(!sxafr_word(c,p+13,4,false,&z)||z>INT32_MAX||!sxafr_add(c,&sxafr_lim_member,p))return false;p+=21;}if(!sxafr_zstr(c,&p,(uint64_t)c->size,4096)||!sxafr_span(c,p,z))return false;p+=z;}return true;}
bool sx_lim_build(sx_context*c)
{
 return sxafr_lim(c);
}
