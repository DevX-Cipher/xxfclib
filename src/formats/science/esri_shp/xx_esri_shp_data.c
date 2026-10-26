/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Esri shapefile data structures, moved out of the sciencemeta schema family. */
#include "../../xx_format_schema_sciencemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsc_shp_file_header_fields[] = {
    SX_FIELD("file_code","int32be",0,4,SX_SIGNATURE),
    SX_FIELD("unused","int32be[5]",4,20,SX_RESERVED),
    SX_FIELD("file_length_words","int32be",24,4,SX_NONE),
    SX_FIELD("version","int32le",28,4,SX_ID),
    SX_FIELD("shape_type","int32le",32,4,SX_ID),
    SX_FIELD("xmin","float64",36,8,SX_NONE),
    SX_FIELD("ymin","float64",44,8,SX_NONE),
    SX_FIELD("xmax","float64",52,8,SX_NONE),
    SX_FIELD("ymax","float64",60,8,SX_NONE),
    SX_FIELD("zmin","float64",68,8,SX_NONE),
    SX_FIELD("zmax","float64",76,8,SX_NONE),
    SX_FIELD("mmin","float64",84,8,SX_NONE),
    SX_FIELD("mmax","float64",92,8,SX_NONE),
};
const sx_layout sxsc_shp_file_header = {UINT32_C(0x60280004),"shp_file_header",sxsc_shp_file_header_fields,SX_COUNT(sxsc_shp_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_record_header_fields[] = {
    SX_FIELD("record_number","int32be",0,4,SX_ID),
    SX_FIELD("content_length_words","int32be",4,4,SX_NONE),
};
const sx_layout sxsc_shp_record_header = {UINT32_C(0x60280005),"shp_record_header",sxsc_shp_record_header_fields,SX_COUNT(sxsc_shp_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_shape_type_fields[] = {
    SX_FIELD("shape_type","int32",0,4,SX_ID),
};
const sx_layout sxsc_shp_shape_type = {UINT32_C(0x60280006),"shp_shape_type",sxsc_shp_shape_type_fields,SX_COUNT(sxsc_shp_shape_type_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_point_fields[] = {
    SX_FIELD("shape_type","int32",0,4,SX_ID),
    SX_FIELD("x","float64",4,8,SX_NONE),
    SX_FIELD("y","float64",12,8,SX_NONE),
};
const sx_layout sxsc_shp_point = {UINT32_C(0x60280007),"shp_point",sxsc_shp_point_fields,SX_COUNT(sxsc_shp_point_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_multipoint_fields[] = {
    SX_FIELD("shape_type","int32",0,4,SX_ID),
    SX_FIELD("xmin","float64",4,8,SX_NONE),
    SX_FIELD("ymin","float64",12,8,SX_NONE),
    SX_FIELD("xmax","float64",20,8,SX_NONE),
    SX_FIELD("ymax","float64",28,8,SX_NONE),
    SX_FIELD("point_count","int32",36,4,SX_COUNT_PROP),
};
const sx_layout sxsc_shp_multipoint = {UINT32_C(0x60280008),"shp_multipoint",sxsc_shp_multipoint_fields,SX_COUNT(sxsc_shp_multipoint_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_polyline_polygon_fields[] = {
    SX_FIELD("shape_type","int32",0,4,SX_ID),
    SX_FIELD("xmin","float64",4,8,SX_NONE),
    SX_FIELD("ymin","float64",12,8,SX_NONE),
    SX_FIELD("xmax","float64",20,8,SX_NONE),
    SX_FIELD("ymax","float64",28,8,SX_NONE),
    SX_FIELD("part_count","int32",36,4,SX_COUNT_PROP),
    SX_FIELD("point_count","int32",40,4,SX_COUNT_PROP),
};
const sx_layout sxsc_shp_polyline_polygon = {UINT32_C(0x60280009),"shp_polyline_polygon",sxsc_shp_polyline_polygon_fields,SX_COUNT(sxsc_shp_polyline_polygon_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_part_fields[] = {
    SX_FIELD("first_point_index","int32",0,4,SX_ID),
};
const sx_layout sxsc_shp_part = {UINT32_C(0x6028000a),"shp_part",sxsc_shp_part_fields,SX_COUNT(sxsc_shp_part_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_shp_xy_fields[] = {
    SX_FIELD("x","float64",0,8,SX_NONE),
    SX_FIELD("y","float64",8,8,SX_NONE),
};
const sx_layout sxsc_shp_xy = {UINT32_C(0x6028000b),"shp_xy",sxsc_shp_xy_fields,SX_COUNT(sxsc_shp_xy_fields),SX_LE};
static bool sxsc_shp(sx_context *c)
{
 uint8_t b[44];uint32_t words;if(!sx_u32(c,24,true,&words)||!sxsc_add(c,&sxsc_shp_file_header,0,100))return false;
 int64_t end=(int64_t)words*2,at=100;if(!sxsc_span(c,0,end)||end<100)return false;
 for(unsigned n=0;at<end;n++){
  if(n>=4095||end-at<12||!sx_read(c,at,b,12))return false;uint64_t size=(uint64_t)sxsc32(b+4,true)*2;uint32_t kind=sxsc32(b+8,false);int64_t data=at+8;
  if(size<4||size>(uint64_t)(end-data)||!sxsc_add(c,&sxsc_shp_record_header,at,8))return false;
  if(kind==0){if(size!=4||!sxsc_add(c,&sxsc_shp_shape_type,data,4))return false;}
  else if(kind==1){if(size!=20||!sxsc_add(c,&sxsc_shp_point,data,20))return false;}
  else if(kind==3||kind==5||kind==8){
   unsigned h=kind==8?40:44;uint32_t parts=0,points;if(size<h||!sx_read(c,data,b,h))return false;
   if(kind==8)points=sxsc32(b+36,false);else{parts=sxsc32(b+36,false);points=sxsc32(b+40,false);}
   if(parts>4096||points>1000000||size!=h+(uint64_t)parts*4+(uint64_t)points*16||!sxsc_add(c,kind==8?&sxsc_shp_multipoint:&sxsc_shp_polyline_polygon,data,h)||!sxsc_table(c,&sxsc_shp_part,data+h,4,parts)||!sxsc_table(c,&sxsc_shp_xy,data+h+(int64_t)parts*4,16,points))return false;
  }else return false;
  at=data+(int64_t)size;
 }return at==end;
}
bool sx_esri_shp_build(sx_context*c)
{
 return sxsc_shp(c);
}
