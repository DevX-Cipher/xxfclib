/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Amiga Plus archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_amplus_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("form_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
const sx_layout sxag_amplus_header = {UINT32_C(0x60250001),"amplus_header",sxag_amplus_header_fields,SX_COUNT(sxag_amplus_header_fields),SX_BE};
static const xx_data_struct_field_desc sxag_amplus_chunk_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxag_amplus_chunk = {UINT32_C(0x60250002),"amplus_chunk",sxag_amplus_chunk_fields,SX_COUNT(sxag_amplus_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxag_amplus_data_fields[] = {
 SX_FIELD("compression","uint16",0,2,SX_ID),
 SX_FIELD("packed_size_hint","uint32",2,4,SX_SIZE),
 SX_FIELD("checksum","uint32",6,4,SX_CHECKSUM),
};
const sx_layout sxag_amplus_data = {UINT32_C(0x60250003),"amplus_data",sxag_amplus_data_fields,SX_COUNT(sxag_amplus_data_fields),SX_BE};
static const xx_data_struct_field_desc sxag_amplus_file_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("unpacked_size","uint32",8,4,SX_SIZE),
 SX_FIELD("days","int32",12,4,SX_NONE),
 SX_FIELD("minutes","int32",16,4,SX_NONE),
 SX_FIELD("ticks","int32",20,4,SX_NONE),
 SX_FIELD("protection","uint32",24,4,SX_FLAGS),
};
const sx_layout sxag_amplus_file = {UINT32_C(0x60250004),"amplus_file",sxag_amplus_file_fields,SX_COUNT(sxag_amplus_file_fields),SX_BE};
#define SXAG_LIMIT 20000U
static bool sxag_amplus(sx_context *c){uint8_t b[36];if(!sxag_read(c,0,b,12)||!sxag_add(c,&sxag_amplus_header,0))return false;uint64_t p=12;for(unsigned i=0;i<SXAG_LIMIT&&p<(uint64_t)c->size;i++){if(!sxag_read(c,p,b,8))break;uint64_t n=sxag32(b+4,true),end=p+8+n,at=p+8;if(!sxag_span(c,at,n))break;if(!sxag_add(c,&sxag_amplus_chunk,p))return false;
 bool help=!xx_rt_memcmp(b,"HELP",4),data=!xx_rt_memcmp(b,"DATA",4)||!xx_rt_memcmp(b,"PACK",4);if(help||data){if(data){if(end-at<10||!sxag_add(c,&sxag_amplus_data,at))break;at+=10;}if(end-at<36||!sxag_read(c,at,b,36)||xx_rt_memcmp(b,"FILE",4)||xx_rt_memcmp(b+28,"NAME",4))break;if(!sxag_add(c,&sxag_amplus_file,at)||!sxag_add(c,&sxag_amplus_chunk,at+28))return false;uint64_t names=sxag32(b+32,true);at+=36;if(names>end-at)break;at+=names;if(end-at<8||!sxag_read(c,at,b,8)||sxag32(b+4,true)>end-at-8)break;if(!sxag_add(c,&sxag_amplus_chunk,at))return false;}p=end+(n&1);}
 return true;}
bool sx_amplus_build(sx_context*c)
{
 return sxag_amplus(c);
}
