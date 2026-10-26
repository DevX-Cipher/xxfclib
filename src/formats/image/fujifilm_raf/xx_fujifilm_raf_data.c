/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * fujifilm raf data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_raf_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("format_version","char[4]",16,4,SX_STRING),
    SX_FIELD("camera_identifier","uint8[8]",20,8,SX_ID),
    SX_FIELD("camera_name","char[32]",28,32,SX_STRING),
    SX_FIELD("directory_version","char[4]",60,4,SX_STRING),
    SX_FIELD("unknown","uint8[20]",64,20,SX_NONE),
    SX_FIELD("jpeg_offset","uint32",84,4,SX_OFFSET),
    SX_FIELD("jpeg_size","uint32",88,4,SX_SIZE),
    SX_FIELD("metadata_offset","uint32",92,4,SX_OFFSET),
    SX_FIELD("metadata_size","uint32",96,4,SX_SIZE),
    SX_FIELD("cfa_offset","uint32",100,4,SX_OFFSET),
    SX_FIELD("cfa_size","uint32",104,4,SX_SIZE),
};
const sx_layout sxrm_raf_header = {UINT32_C(0x601d0064),"raf_header",sxrm_raf_header_fields,SX_COUNT(sxrm_raf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_raf_metadata_count_fields[] = {
    SX_FIELD("entries","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxrm_raf_metadata_count = {UINT32_C(0x601d0065),"raf_metadata_count",sxrm_raf_metadata_count_fields,SX_COUNT(sxrm_raf_metadata_count_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_raf_metadata_entry_fields[] = {
    SX_FIELD("tag","uint16",0,2,SX_ID),
    SX_FIELD("data_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxrm_raf_metadata_entry = {UINT32_C(0x601d0066),"raf_metadata_entry",sxrm_raf_metadata_entry_fields,SX_COUNT(sxrm_raf_metadata_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_raf_dimensions_fields[] = {
    SX_FIELD("height","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("width","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxrm_raf_dimensions = {UINT32_C(0x601d0067),"raf_dimensions",sxrm_raf_dimensions_fields,SX_COUNT(sxrm_raf_dimensions_fields),SX_BE};
static bool sxrm_raf(sx_context *c)
{
 uint8_t h[108];if(!sxrm_read(c,0,h,108)||xx_rt_memcmp(h,"FUJIFILMCCD-RAW ",16)||!sxrm_add(c,&sxrm_raf_header,0))return false;
 uint64_t p=sxrm32(h+92,true),z=sxrm32(h+96,true);if(p<108||z<4||!sxrm_span(c,p,z)||!sxrm_read(c,p,h,4))return true;unsigned count=sxrm32(h,true);uint64_t end=p+z;if(count>1024)return true;
 if(!sxrm_add(c,&sxrm_raf_metadata_count,p))return false;p+=4;for(unsigned i=0;i<count;i++){if(end-p<4||!sxrm_read(c,p,h,4))break;unsigned tag=sxrm16(h,true),n=sxrm16(h+2,true);if(n>end-p-4)break;if(!sxrm_add(c,&sxrm_raf_metadata_entry,p))return false;if(tag==0x100&&n==4&&!sxrm_add(c,&sxrm_raf_dimensions,p+4))return false;p+=4+n;}return !c->failed;
}
bool sx_fujifilm_raf_build(sx_context*c)
{
 return sxrm_raf(c);
}
