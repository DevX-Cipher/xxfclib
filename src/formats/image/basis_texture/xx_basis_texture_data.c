/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * basis texture data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_basis_header_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("version","uint16",2,2,SX_ID),
    SX_FIELD("header_size","uint16",4,2,SX_SIZE),
    SX_FIELD("header_crc16","uint16",6,2,SX_CHECKSUM),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
    SX_FIELD("data_crc16","uint16",12,2,SX_CHECKSUM),
    SX_FIELD("slice_count","uint24",14,3,SX_COUNT_PROP),
    SX_FIELD("image_count","uint24",17,3,SX_COUNT_PROP),
    SX_FIELD("texture_format","uint8",20,1,SX_ID),
    SX_FIELD("flags","uint16",21,2,SX_FLAGS),
    SX_FIELD("texture_type","uint8",23,1,SX_ID),
    SX_FIELD("microseconds_per_frame","uint24",24,3,SX_NONE),
    SX_FIELD("reserved","uint32",27,4,SX_RESERVED),
    SX_FIELD("user_data0","uint32",31,4,SX_NONE),
    SX_FIELD("user_data1","uint32",35,4,SX_NONE),
    SX_FIELD("endpoint_count","uint16",39,2,SX_COUNT_PROP),
    SX_FIELD("endpoint_offset","uint32",41,4,SX_OFFSET),
    SX_FIELD("endpoint_size","uint24",45,3,SX_SIZE),
    SX_FIELD("selector_count","uint16",48,2,SX_COUNT_PROP),
    SX_FIELD("selector_offset","uint32",50,4,SX_OFFSET),
    SX_FIELD("selector_size","uint24",54,3,SX_SIZE),
    SX_FIELD("tables_offset","uint32",57,4,SX_OFFSET),
    SX_FIELD("tables_size","uint32",61,4,SX_SIZE),
    SX_FIELD("slice_descriptors_offset","uint32",65,4,SX_OFFSET),
    SX_FIELD("extended_offset","uint32",69,4,SX_OFFSET),
    SX_FIELD("extended_size","uint32",73,4,SX_SIZE),
};
const sx_layout sxrm_basis_header = {UINT32_C(0x601d0078),"basis_header",sxrm_basis_header_fields,SX_COUNT(sxrm_basis_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_basis_slice_fields[] = {
    SX_FIELD("image_index","uint24",0,3,SX_ID),
    SX_FIELD("level_index","uint8",3,1,SX_ID),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("width","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",7,2,SX_COUNT_PROP),
    SX_FIELD("blocks_x","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("blocks_y","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("data_offset","uint32",13,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",17,4,SX_SIZE),
    SX_FIELD("slice_crc16","uint16",21,2,SX_CHECKSUM),
};
const sx_layout sxrm_basis_slice = {UINT32_C(0x601d0079),"basis_slice",sxrm_basis_slice_fields,SX_COUNT(sxrm_basis_slice_fields),SX_LE};
static bool sxrm_basis(sx_context *c)
{
 uint8_t h[77];if(!sxrm_read(c,0,h,77)||xx_rt_memcmp(h,"sB",2)||!sxrm_add(c,&sxrm_basis_header,0))return false;uint64_t p=sxrm32(h+65,false),n=sxrm_uint(h+14,3,false);
 if(p>=77&&n<=4087&&sxrm_span(c,p,n*23)&&!sxrm_table(c,&sxrm_basis_slice,p,n))return false;return !c->failed;
}
bool sx_basis_texture_build(sx_context*c)
{
 return sxrm_basis(c);
}
