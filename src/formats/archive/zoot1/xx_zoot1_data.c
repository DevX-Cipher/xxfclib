/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Zoot v1 notes data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_zoot1_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("directory_size","uint32",4,4,SX_SIZE),
 SX_FIELD("version","uint16",8,2,SX_NONE),
 SX_FIELD("directory_count","uint16",10,2,SX_COUNT_PROP),
};
const sx_layout sxas_zoot1_header = {UINT32_C(0x60430004),"zoot1_header",sxas_zoot1_header_fields,SX_COUNT(sxas_zoot1_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_zoot1_entry137_fields[] = {
 SX_FIELD("name","char[60]",0,60,SX_NONE),
 SX_FIELD("opaque0","uint8[33]",60,33,SX_NONE),
 SX_FIELD("payload_offset","uint32",93,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",97,4,SX_SIZE),
 SX_FIELD("opaque1","uint8[2]",101,2,SX_NONE),
 SX_FIELD("status","uint16",103,2,SX_NONE),
 SX_FIELD("class_word","uint16",105,2,SX_NONE),
 SX_FIELD("opaque_tail","uint8[30]",107,30,SX_NONE),
};
const sx_layout sxas_zoot1_entry137 = {UINT32_C(0x60430005),"zoot1_entry137",sxas_zoot1_entry137_fields,SX_COUNT(sxas_zoot1_entry137_fields),SX_LE};
static const xx_data_struct_field_desc sxas_zoot1_entry235_fields[] = {
 SX_FIELD("name","char[60]",0,60,SX_NONE),
 SX_FIELD("opaque0","uint8[33]",60,33,SX_NONE),
 SX_FIELD("payload_offset","uint32",93,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",97,4,SX_SIZE),
 SX_FIELD("opaque1","uint8[2]",101,2,SX_NONE),
 SX_FIELD("status","uint16",103,2,SX_NONE),
 SX_FIELD("class_word","uint16",105,2,SX_NONE),
 SX_FIELD("opaque_tail","uint8[128]",107,128,SX_NONE),
};
const sx_layout sxas_zoot1_entry235 = {UINT32_C(0x60430006),"zoot1_entry235",sxas_zoot1_entry235_fields,SX_COUNT(sxas_zoot1_entry235_fields),SX_LE};
static bool sxas_zoot(sx_context*c){uint64_t size,version,dirs;if(!sxas_word(c,4,4,false,&size)||!sxas_word(c,8,2,false,&version)||!sxas_word(c,10,2,false,&dirs)||!sxas_span(c,12,size)||!sxas_add(c,&sxas_zoot1_header,0))return false;unsigned ds=version==0x272e?116:76,es=version==0x2739?235:137;if(version!=0x272e&&version!=0x2738&&version!=0x2739)return false;if(dirs>size/ds)return false;uint64_t p=12+dirs*ds,count=(size-dirs*ds)/es;for(uint64_t i=0;i<count;i++)if(!sxas_add(c,es==235?&sxas_zoot1_entry235:&sxas_zoot1_entry137,p+i*es))return false;return true;}
bool sx_zoot1_build(sx_context*c)
{
 return sxas_zoot(c);
}
