/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * valve vtf data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_vtf70_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint32",4,4,SX_ID),
    SX_FIELD("version_minor","uint32",8,4,SX_ID),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("width","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("frames","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("first_frame","uint16",26,2,SX_ID),
    SX_FIELD("padding0","uint8[4]",28,4,SX_RESERVED),
    SX_FIELD("reflectivity_red","float32",32,4,SX_NONE),
    SX_FIELD("reflectivity_green","float32",36,4,SX_NONE),
    SX_FIELD("reflectivity_blue","float32",40,4,SX_NONE),
    SX_FIELD("padding1","uint8[4]",44,4,SX_RESERVED),
    SX_FIELD("bumpmap_scale","float32",48,4,SX_NONE),
    SX_FIELD("high_resolution_format","int32",52,4,SX_ID),
    SX_FIELD("mipmap_count","uint8",56,1,SX_COUNT_PROP),
    SX_FIELD("low_resolution_format","int32",57,4,SX_ID),
    SX_FIELD("low_resolution_width","uint8",61,1,SX_COUNT_PROP),
    SX_FIELD("low_resolution_height","uint8",62,1,SX_COUNT_PROP),
};
const sx_layout sxrm_vtf70_header = {UINT32_C(0x601d0001),"vtf70_header",sxrm_vtf70_header_fields,SX_COUNT(sxrm_vtf70_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_vtf72_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint32",4,4,SX_ID),
    SX_FIELD("version_minor","uint32",8,4,SX_ID),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("width","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("frames","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("first_frame","uint16",26,2,SX_ID),
    SX_FIELD("padding0","uint8[4]",28,4,SX_RESERVED),
    SX_FIELD("reflectivity_red","float32",32,4,SX_NONE),
    SX_FIELD("reflectivity_green","float32",36,4,SX_NONE),
    SX_FIELD("reflectivity_blue","float32",40,4,SX_NONE),
    SX_FIELD("padding1","uint8[4]",44,4,SX_RESERVED),
    SX_FIELD("bumpmap_scale","float32",48,4,SX_NONE),
    SX_FIELD("high_resolution_format","int32",52,4,SX_ID),
    SX_FIELD("mipmap_count","uint8",56,1,SX_COUNT_PROP),
    SX_FIELD("low_resolution_format","int32",57,4,SX_ID),
    SX_FIELD("low_resolution_width","uint8",61,1,SX_COUNT_PROP),
    SX_FIELD("low_resolution_height","uint8",62,1,SX_COUNT_PROP),
    SX_FIELD("depth","uint16",63,2,SX_COUNT_PROP),
};
const sx_layout sxrm_vtf72_header = {UINT32_C(0x601d0002),"vtf72_header",sxrm_vtf72_header_fields,SX_COUNT(sxrm_vtf72_header_fields),SX_LE};
static bool sxrm_vtf(sx_context *c)
{
 uint8_t h[16];if(!sxrm_read(c,0,h,16)||xx_rt_memcmp(h,"VTF\0",4)||sxrm32(h+4,false)!=7||sxrm32(h+8,false)>2)return false;
 return sxrm_add(c,sxrm32(h+8,false)==2?&sxrm_vtf72_header:&sxrm_vtf70_header,0);
}
bool sx_valve_vtf_build(sx_context*c)
{
 return sxrm_vtf(c);
}
