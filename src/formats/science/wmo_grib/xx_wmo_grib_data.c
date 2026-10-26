/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WMO GRIB data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_grib2_indicator_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("reserved","uint8[2]",4,2,SX_RESERVED),
    SX_FIELD("discipline","uint8",6,1,SX_ID),
    SX_FIELD("edition","uint8",7,1,SX_ID),
    SX_FIELD("total_size","uint64",8,8,SX_SIZE),
};
const sx_layout sxsw_grib2_indicator = {UINT32_C(0x602d002b),"grib2_indicator",sxsw_grib2_indicator_fields,SX_COUNT(sxsw_grib2_indicator_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_identification_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("centre","uint16",5,2,SX_ID),
    SX_FIELD("subcentre","uint16",7,2,SX_ID),
    SX_FIELD("master_table","uint8",9,1,SX_ID),
    SX_FIELD("local_table","uint8",10,1,SX_ID),
    SX_FIELD("reference_time_significance","uint8",11,1,SX_ID),
    SX_FIELD("year","uint16",12,2,SX_NONE),
    SX_FIELD("month","uint8",14,1,SX_NONE),
    SX_FIELD("day","uint8",15,1,SX_NONE),
    SX_FIELD("hour","uint8",16,1,SX_NONE),
    SX_FIELD("minute","uint8",17,1,SX_NONE),
    SX_FIELD("second","uint8",18,1,SX_NONE),
    SX_FIELD("production_status","uint8",19,1,SX_ID),
    SX_FIELD("data_type","uint8",20,1,SX_ID),
};
const sx_layout sxsw_grib2_identification = {UINT32_C(0x602d002d),"grib2_identification",sxsw_grib2_identification_fields,SX_COUNT(sxsw_grib2_identification_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_grid_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("source","uint8",5,1,SX_ID),
    SX_FIELD("point_count","uint32",6,4,SX_COUNT_PROP),
    SX_FIELD("list_entry_size","uint8",10,1,SX_SIZE),
    SX_FIELD("list_interpretation","uint8",11,1,SX_ID),
    SX_FIELD("template_number","uint16",12,2,SX_ID),
};
const sx_layout sxsw_grib2_grid = {UINT32_C(0x602d002e),"grib2_grid",sxsw_grib2_grid_fields,SX_COUNT(sxsw_grib2_grid_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_product_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("coordinate_count","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("template_number","uint16",7,2,SX_ID),
};
const sx_layout sxsw_grib2_product = {UINT32_C(0x602d002f),"grib2_product",sxsw_grib2_product_fields,SX_COUNT(sxsw_grib2_product_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_grib2_representation_fields[] = {
    SX_FIELD("section_size","uint32",0,4,SX_SIZE),
    SX_FIELD("section_number","uint8",4,1,SX_ID),
    SX_FIELD("value_count","uint32",5,4,SX_COUNT_PROP),
    SX_FIELD("template_number","uint16",9,2,SX_ID),
};
const sx_layout sxsw_grib2_representation = {UINT32_C(0x602d0030),"grib2_representation",sxsw_grib2_representation_fields,SX_COUNT(sxsw_grib2_representation_fields),SX_BE};
static bool sxsw_grib(sx_context *c)
{
 int64_t at=0;for(unsigned msg=0;at<c->size&&msg<400;msg++){
  uint64_t size;if(!sx_u64(c,at+8,true,&size)||size<20||!sxsw_span(c,at,size)||!sxsw_add(c,&sxsw_grib2_indicator,at,16))return false;int64_t end=at+(int64_t)size-4;at+=16;
  while(at<end){uint8_t b[5];if(!sx_read(c,at,b,5))return false;uint32_t n=sxsw32(b,true);unsigned id=b[4];const sx_layout *l=&sxsw_grib2_section;unsigned width=5;
   if(id==1){l=&sxsw_grib2_identification;width=21;}else if(id==3){l=&sxsw_grib2_grid;width=14;}else if(id==4){l=&sxsw_grib2_product;width=9;}else if(id==5){l=&sxsw_grib2_representation;width=11;}else if(id==6){l=&sxsw_grib2_bitmap;width=6;}
   if(n<width||n>(uint64_t)(end-at)||!sxsw_add(c,l,at,width))return false;at+=n;
  }if(at!=end||!sxsw_add(c,&sxsw_wmo_end,at,4))return false;at+=4;
 }return at==c->size;
}
bool sx_wmo_grib_build(sx_context*c)
{
 return sxsw_grib(c);
}
