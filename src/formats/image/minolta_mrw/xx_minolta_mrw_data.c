/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * minolta mrw data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_mrw_header_fields[] = {
    SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
    SX_FIELD("metadata_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxrm_mrw_header = {UINT32_C(0x601d0072),"mrw_header",sxrm_mrw_header_fields,SX_COUNT(sxrm_mrw_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_mrw_chunk_fields[] = {
    SX_FIELD("chunk_type","uint8[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxrm_mrw_chunk = {UINT32_C(0x601d0073),"mrw_chunk",sxrm_mrw_chunk_fields,SX_COUNT(sxrm_mrw_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_mrw_prd_fields[] = {
    SX_FIELD("version","char[8]",0,8,SX_STRING),
    SX_FIELD("sensor_rows","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("sensor_columns","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("image_height","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("image_width","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("storage_bits","uint8",16,1,SX_NONE),
    SX_FIELD("valid_bits","uint8",17,1,SX_NONE),
    SX_FIELD("packing","uint8",18,1,SX_ID),
    SX_FIELD("unknown","uint8[4]",19,4,SX_NONE),
    SX_FIELD("bayer_pattern","uint8",23,1,SX_ID),
};
const sx_layout sxrm_mrw_prd = {UINT32_C(0x601d0074),"mrw_prd",sxrm_mrw_prd_fields,SX_COUNT(sxrm_mrw_prd_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_mrw_white_balance_fields[] = {
    SX_FIELD("denominator_exponents","uint8[4]",0,4,SX_NONE),
    SX_FIELD("channel0_numerator","uint16",4,2,SX_NONE),
    SX_FIELD("channel1_numerator","uint16",6,2,SX_NONE),
    SX_FIELD("channel2_numerator","uint16",8,2,SX_NONE),
    SX_FIELD("channel3_numerator","uint16",10,2,SX_NONE),
};
const sx_layout sxrm_mrw_white_balance = {UINT32_C(0x601d0075),"mrw_white_balance",sxrm_mrw_white_balance_fields,SX_COUNT(sxrm_mrw_white_balance_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_mrw_tiff_header_le_fields[] = {
    SX_FIELD("byte_order","char[2]",0,2,SX_ID),
    SX_FIELD("version","uint16",2,2,SX_ID),
    SX_FIELD("first_ifd_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxrm_mrw_tiff_header_le = {UINT32_C(0x601d0076),"mrw_tiff_header_le",sxrm_mrw_tiff_header_le_fields,SX_COUNT(sxrm_mrw_tiff_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_mrw_tiff_header_be_fields[] = {
    SX_FIELD("byte_order","char[2]",0,2,SX_ID),
    SX_FIELD("version","uint16",2,2,SX_ID),
    SX_FIELD("first_ifd_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxrm_mrw_tiff_header_be = {UINT32_C(0x601d0077),"mrw_tiff_header_be",sxrm_mrw_tiff_header_be_fields,SX_COUNT(sxrm_mrw_tiff_header_be_fields),SX_BE};
static bool sxrm_mrw(sx_context *c)
{
 uint8_t h[8];if(!sxrm_read(c,0,h,8)||xx_rt_memcmp(h,"\0MRM",4)||!sxrm_add(c,&sxrm_mrw_header,0))return false;uint64_t p=8,end=8+(uint64_t)sxrm32(h+4,true);if(end>(uint64_t)c->size)end=(uint64_t)c->size;
 for(unsigned i=0;i<32&&p<end;i++){if(end-p<8||!sxrm_read(c,p,h,8))break;uint32_t n=sxrm32(h+4,true);if(n>end-p-8)break;if(!sxrm_add(c,&sxrm_mrw_chunk,p))return false;
  if(!xx_rt_memcmp(h,"\0PRD",4)&&n>=24){if(!sxrm_add(c,&sxrm_mrw_prd,p+8))return false;}
  else if(!xx_rt_memcmp(h,"\0WBG",4)&&n>=12){if(!sxrm_add(c,&sxrm_mrw_white_balance,p+8))return false;}
  else if(!xx_rt_memcmp(h,"\0TTW",4)&&n>=8){if(!sxrm_read(c,p+8,h,8))return false;if(!xx_rt_memcmp(h,"II\x2a\0",4)){if(!sxrm_add(c,&sxrm_mrw_tiff_header_le,p+8))return false;}else if(!xx_rt_memcmp(h,"MM\0\x2a",4)&&!sxrm_add(c,&sxrm_mrw_tiff_header_be,p+8))return false;}p+=8+n;
 }return !c->failed;
}
bool sx_minolta_mrw_build(sx_context*c)
{
 return sxrm_mrw(c);
}
