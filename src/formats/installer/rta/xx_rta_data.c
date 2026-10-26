/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RTA data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_rta_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxae_rta_header = {UINT32_C(0x6017000d),"rta_header",sxae_rta_header_fields,SX_COUNT(sxae_rta_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_rta_string_size_fields[] = {
    SX_FIELD("string_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxae_rta_string_size = {UINT32_C(0x6017000e),"rta_string_size",sxae_rta_string_size_fields,SX_COUNT(sxae_rta_string_size_fields),SX_LE};
static const xx_data_struct_field_desc sxae_rta_member_fields[] = {
    SX_FIELD("attributes","uint8",0,1,SX_FLAGS),
    SX_FIELD("date","uint16",1,2,SX_NONE),
    SX_FIELD("time","uint16",3,2,SX_NONE),
    SX_FIELD("unpacked_size","int32",5,4,SX_SIZE),
    SX_FIELD("packed_size","int32",9,4,SX_SIZE),
};
const sx_layout sxae_rta_member = {UINT32_C(0x6017000f),"rta_member",sxae_rta_member_fields,SX_COUNT(sxae_rta_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_rta_codec_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("raw_literal_flag","uint8",2,1,SX_FLAGS),
    SX_FIELD("marker","uint8",3,1,SX_SIGNATURE),
};
const sx_layout sxae_rta_codec_header = {UINT32_C(0x60170010),"rta_codec_header",sxae_rta_codec_header_fields,SX_COUNT(sxae_rta_codec_header_fields),SX_BE};
static const xx_data_struct_field_desc sxae_rta_end_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxae_rta_end = {UINT32_C(0x60170011),"rta_end",sxae_rta_end_fields,SX_COUNT(sxae_rta_end_fields),SX_LE};
static bool sxae_rta(sx_context *c)
{
 uint8_t b[13],n;int64_t p=4;if(!sx_read(c,0,b,4)||xx_rt_memcmp(b,"KJd\0",4)||!sxae_add(c,&sxae_rta_header,0))return false;
 for(unsigned i=0;i<20000;i++){if(!sx_read(c,p,&n,1))return false;if(!n)return sxae_add(c,&sxae_rta_end,p);if(!sxae_add(c,&sxae_rta_string_size,p)||!sxae_bound(c,p+1,n))return false;p+=1+n;
 if(!sx_read(c,p,&n,1)||!sxae_add(c,&sxae_rta_string_size,p)||!sxae_bound(c,p+1,n))return false;p+=1+n;
 if(!sx_read(c,p,b,13)||!sxae_add(c,&sxae_rta_member,p))return false;uint32_t z=sxae32(b+9);p+=13;if(z>INT32_MAX||!sxae_bound(c,p,z))return false;
 if(z){uint8_t h[4];if(z<4||!sx_read(c,p,h,4)||h[0]!=0xb5||h[1]!=0x9c||h[2]>1||h[3]!=255||!sxae_add(c,&sxae_rta_codec_header,p)||!sxae_data(c,p+4,z-4))return false;}p+=z;}return false;
}
bool sx_rta_build(sx_context*c)
{
 return sxae_rta(c);
}
