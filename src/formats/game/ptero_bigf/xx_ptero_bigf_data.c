/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PTERO_BIGF data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_ptero_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_NONE),
 SX_FIELD("marker","char[3]",5,3,SX_SIGNATURE),
 SX_FIELD("archive_size","uint64",8,8,SX_SIZE),
 SX_FIELD("member_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("directory_offset","uint64",20,8,SX_OFFSET),
 SX_FIELD("directory_size","uint64",28,8,SX_SIZE),
 SX_FIELD("data_offset","uint64",36,8,SX_OFFSET),
 SX_FIELD("unknown","uint8[20]",44,20,SX_NONE),
};
const sx_layout sxan_ptero_header = {UINT32_C(0x60770031),"ptero_header",sxan_ptero_header_fields,SX_COUNT(sxan_ptero_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ptero_member_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("marker","uint32",8,4,SX_NONE),
 SX_FIELD("timestamp","uint64",12,8,SX_NONE),
 SX_FIELD("uncompressed_size","uint64",20,8,SX_SIZE),
 SX_FIELD("compressed_size","uint32",28,4,SX_SIZE),
 SX_FIELD("method","uint32",32,4,SX_NONE),
 SX_FIELD("unknown","uint32",36,4,SX_NONE),
};
const sx_layout sxan_ptero_member = {UINT32_C(0x60770032),"ptero_member",sxan_ptero_member_fields,SX_COUNT(sxan_ptero_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_ptero_block_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("compressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxan_ptero_block = {UINT32_C(0x60770033),"ptero_block",sxan_ptero_block_fields,SX_COUNT(sxan_ptero_block_fields),SX_LE};
static bool sxan_ptero(sx_context*c){uint64_t n,p,z,end,len,at,packed,method;if(!sxan_add(c,&sxan_ptero_header,0)||!sxan_word(c,16,4,false,&n)||!sxan_word(c,20,8,false,&p)||!sxan_word(c,28,8,false,&z)||!sxan_span(c,p,z))return false;end=p+z;for(uint64_t i=0;i<n;i++){if(p>end||end-p<40||!sxan_add(c,&sxan_ptero_member,p)||!sxan_word(c,p,8,false,&at)||!sxan_word(c,p+28,4,false,&packed)||!sxan_word(c,p+32,4,false,&method)||!sxan_zlen(c,p+40,end,&len)||!sxan_named(c,p+40,len))return false;p+=40+len;if(method==1&&sxan_span(c,at,packed)){uint64_t stop=at+packed;while(at<stop){uint8_t h[12];if(stop-at<12||!sxan_read(c,at,h,12)||xx_rt_memcmp(h,"[..]",4))break;z=sxan_uint(h+4,4,false);if(z>stop-at-12||!sxan_add(c,&sxan_ptero_block,at))return false;at+=12+z;}}}return true;}
bool sx_ptero_bigf_build(sx_context*c)
{
bool ok=false;
ok=sxan_ptero(c);
(void)ok;return c->count&&sxan_finish(c);
}
