/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WMO BUFR data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_bufr4_indicator_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("total_size","uint24",4,3,SX_SIZE),
    SX_FIELD("edition","uint8",7,1,SX_ID),
};
const sx_layout sxsw_bufr4_indicator = {UINT32_C(0x602d0033),"bufr4_indicator",sxsw_bufr4_indicator_fields,SX_COUNT(sxsw_bufr4_indicator_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_bufr4_identification_fields[] = {
    SX_FIELD("section_size","uint24",0,3,SX_SIZE),
    SX_FIELD("master_table","uint8",3,1,SX_ID),
    SX_FIELD("centre","uint16",4,2,SX_ID),
    SX_FIELD("subcentre","uint16",6,2,SX_ID),
    SX_FIELD("update_sequence","uint8",8,1,SX_ID),
    SX_FIELD("optional_section","uint8",9,1,SX_FLAGS),
    SX_FIELD("data_category","uint8",10,1,SX_ID),
    SX_FIELD("international_subcategory","uint8",11,1,SX_ID),
    SX_FIELD("local_subcategory","uint8",12,1,SX_ID),
    SX_FIELD("master_table_version","uint8",13,1,SX_ID),
    SX_FIELD("local_table_version","uint8",14,1,SX_ID),
    SX_FIELD("year","uint16",15,2,SX_NONE),
    SX_FIELD("month","uint8",17,1,SX_NONE),
    SX_FIELD("day","uint8",18,1,SX_NONE),
    SX_FIELD("hour","uint8",19,1,SX_NONE),
    SX_FIELD("minute","uint8",20,1,SX_NONE),
    SX_FIELD("second","uint8",21,1,SX_NONE),
};
const sx_layout sxsw_bufr4_identification = {UINT32_C(0x602d0034),"bufr4_identification",sxsw_bufr4_identification_fields,SX_COUNT(sxsw_bufr4_identification_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_bufr4_section_fields[] = {
    SX_FIELD("section_size","uint24",0,3,SX_SIZE),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
};
const sx_layout sxsw_bufr4_section = {UINT32_C(0x602d0035),"bufr4_section",sxsw_bufr4_section_fields,SX_COUNT(sxsw_bufr4_section_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_bufr4_data_description_fields[] = {
    SX_FIELD("section_size","uint24",0,3,SX_SIZE),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("subset_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint8",6,1,SX_FLAGS),
};
const sx_layout sxsw_bufr4_data_description = {UINT32_C(0x602d0036),"bufr4_data_description",sxsw_bufr4_data_description_fields,SX_COUNT(sxsw_bufr4_data_description_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_bufr_descriptor_fields[] = {
    SX_FIELD("descriptor","uint16",0,2,SX_ID),
};
const sx_layout sxsw_bufr_descriptor = {UINT32_C(0x602d0037),"bufr_descriptor",sxsw_bufr_descriptor_fields,SX_COUNT(sxsw_bufr_descriptor_fields),SX_BE};
static uint32_t sxsw24(const uint8_t *b){return ((uint32_t)b[0]<<16)|((uint32_t)b[1]<<8)|b[2];}
static bool sxsw_bufr(sx_context *c)
{
 int64_t at=0;for(unsigned msg=0;at<c->size&&msg<600;msg++){
  uint8_t b[22];if(!sx_read(c,at,b,8))return false;uint32_t size=sxsw24(b+4);if(size<12||!sxsw_span(c,at,size)||!sxsw_add(c,&sxsw_bufr4_indicator,at,8))return false;int64_t end=at+size-4;at+=8;
  if(!sx_read(c,at,b,22))return false;uint32_t n=sxsw24(b);bool optional=(b[9]&128)!=0;if(n<22||n>(uint64_t)(end-at)||!sxsw_add(c,&sxsw_bufr4_identification,at,22))return false;at+=n;
  if(optional){if(!sx_read(c,at,b,4))return false;n=sxsw24(b);if(n<4||n>(uint64_t)(end-at)||!sxsw_add(c,&sxsw_bufr4_section,at,4))return false;at+=n;}
  if(!sx_read(c,at,b,7))return false;n=sxsw24(b);if(n<7||(n-7)%2||n>(uint64_t)(end-at)||!sxsw_add(c,&sxsw_bufr4_data_description,at,7)||!sxsw_table(c,&sxsw_bufr_descriptor,at+7,2,(n-7)/2))return false;at+=n;
  if(!sx_read(c,at,b,4))return false;n=sxsw24(b);if(n<4||n>(uint64_t)(end-at)||!sxsw_add(c,&sxsw_bufr4_section,at,4))return false;at+=n;
  if(at!=end||!sxsw_add(c,&sxsw_wmo_end,at,4))return false;at+=4;
 }return at==c->size;
}
bool sx_wmo_bufr_build(sx_context*c)
{
 return sxsw_bufr(c);
}
