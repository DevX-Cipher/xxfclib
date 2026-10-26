/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LiDAR LAS point clouds data structures, moved out of the sciencemeta schema family. */
#include "../../xx_format_schema_sciencemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsc_las_vlr_fields[] = {
    SX_FIELD("reserved","uint16",0,2,SX_RESERVED),
    SX_FIELD("user_id","char[16]",2,16,SX_STRING),
    SX_FIELD("record_id","uint16",18,2,SX_ID),
    SX_FIELD("payload_size","uint16",20,2,SX_SIZE),
    SX_FIELD("description","char[32]",22,32,SX_STRING),
};
const sx_layout sxsc_las_vlr = {UINT32_C(0x6028000d),"las_vlr",sxsc_las_vlr_fields,SX_COUNT(sxsc_las_vlr_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las_point0_fields[] = {
    SX_FIELD("x","int32",0,4,SX_NONE),
    SX_FIELD("y","int32",4,4,SX_NONE),
    SX_FIELD("z","int32",8,4,SX_NONE),
    SX_FIELD("intensity","uint16",12,2,SX_NONE),
    SX_FIELD("return_flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("classification","uint8",15,1,SX_FLAGS),
    SX_FIELD("scan_angle_rank","int8",16,1,SX_NONE),
    SX_FIELD("user_data","uint8",17,1,SX_NONE),
    SX_FIELD("point_source_id","uint16",18,2,SX_ID),
};
const sx_layout sxsc_las_point0 = {UINT32_C(0x6028000e),"las_point0",sxsc_las_point0_fields,SX_COUNT(sxsc_las_point0_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las_point1_fields[] = {
    SX_FIELD("x","int32",0,4,SX_NONE),
    SX_FIELD("y","int32",4,4,SX_NONE),
    SX_FIELD("z","int32",8,4,SX_NONE),
    SX_FIELD("intensity","uint16",12,2,SX_NONE),
    SX_FIELD("return_flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("classification","uint8",15,1,SX_FLAGS),
    SX_FIELD("scan_angle_rank","int8",16,1,SX_NONE),
    SX_FIELD("user_data","uint8",17,1,SX_NONE),
    SX_FIELD("point_source_id","uint16",18,2,SX_ID),
    SX_FIELD("gps_time","float64",20,8,SX_NONE),
};
const sx_layout sxsc_las_point1 = {UINT32_C(0x6028000f),"las_point1",sxsc_las_point1_fields,SX_COUNT(sxsc_las_point1_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las_point2_fields[] = {
    SX_FIELD("x","int32",0,4,SX_NONE),
    SX_FIELD("y","int32",4,4,SX_NONE),
    SX_FIELD("z","int32",8,4,SX_NONE),
    SX_FIELD("intensity","uint16",12,2,SX_NONE),
    SX_FIELD("return_flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("classification","uint8",15,1,SX_FLAGS),
    SX_FIELD("scan_angle_rank","int8",16,1,SX_NONE),
    SX_FIELD("user_data","uint8",17,1,SX_NONE),
    SX_FIELD("point_source_id","uint16",18,2,SX_ID),
    SX_FIELD("red","uint16",20,2,SX_NONE),
    SX_FIELD("green","uint16",22,2,SX_NONE),
    SX_FIELD("blue","uint16",24,2,SX_NONE),
};
const sx_layout sxsc_las_point2 = {UINT32_C(0x60280010),"las_point2",sxsc_las_point2_fields,SX_COUNT(sxsc_las_point2_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_las_point3_fields[] = {
    SX_FIELD("x","int32",0,4,SX_NONE),
    SX_FIELD("y","int32",4,4,SX_NONE),
    SX_FIELD("z","int32",8,4,SX_NONE),
    SX_FIELD("intensity","uint16",12,2,SX_NONE),
    SX_FIELD("return_flags","uint8",14,1,SX_FLAGS),
    SX_FIELD("classification","uint8",15,1,SX_FLAGS),
    SX_FIELD("scan_angle_rank","int8",16,1,SX_NONE),
    SX_FIELD("user_data","uint8",17,1,SX_NONE),
    SX_FIELD("point_source_id","uint16",18,2,SX_ID),
    SX_FIELD("gps_time","float64",20,8,SX_NONE),
    SX_FIELD("red","uint16",28,2,SX_NONE),
    SX_FIELD("green","uint16",30,2,SX_NONE),
    SX_FIELD("blue","uint16",32,2,SX_NONE),
};
const sx_layout sxsc_las_point3 = {UINT32_C(0x60280011),"las_point3",sxsc_las_point3_fields,SX_COUNT(sxsc_las_point3_fields),SX_LE};
static bool sxsc_las(sx_context *c)
{
 uint8_t b[227];if(!sx_read(c,0,b,sizeof(b))||xx_rt_memcmp(b,"LASF",4)||b[24]!=1||b[25]!=2||!sxsc_add(c,&sxsc_las12_header,0,227))return false;
 uint32_t data=sxsc32(b+96,false),vlrs=sxsc32(b+100,false),count=sxsc32(b+107,false);unsigned fmt=b[104],width=sxsc16(b+105,false);int64_t at=sxsc16(b+94,false);
 const sx_layout *ls[]={&sxsc_las_point0,&sxsc_las_point1,&sxsc_las_point2,&sxsc_las_point3};const unsigned widths[]={20,28,26,34};
 if(at<227||data<(uint64_t)at||vlrs>1024||fmt>3||width<widths[fmt]||count>1000000||!sxsc_span(c,data,(uint64_t)width*count))return false;
 for(uint32_t i=0;i<vlrs;i++){if(data-(uint64_t)at<54||!sx_read(c,at,b,54)||!sxsc_add(c,&sxsc_las_vlr,at,54))return false;uint64_t n=54U+sxsc16(b+20,false);if(n>data-(uint64_t)at)return false;at+=(int64_t)n;}
 /* Vendor point extensions remain raw. A stride is not represented as fields. */
 if(width==widths[fmt])return sxsc_table(c,ls[fmt],data,width,count);
 if(count>16000)return true;
 for(uint32_t i=0;i<count;i++)if(!sxsc_add(c,ls[fmt],(int64_t)data+(int64_t)i*width,widths[fmt]))return false;
 return true;
}
bool sx_lidar_las_build(sx_context*c)
{
 return sxsc_las(c);
}
