/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * jpeg2000 jp2 data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_jp2_box_fields[] = {
    SX_FIELD("box_size","uint32",0,4,SX_SIZE),
    SX_FIELD("box_type","char[4]",4,4,SX_ID),
};
const sx_layout sxrm_jp2_box = {UINT32_C(0x601d000d),"jp2_box",sxrm_jp2_box_fields,SX_COUNT(sxrm_jp2_box_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_extended_size_fields[] = {
    SX_FIELD("box_size","uint64",0,8,SX_SIZE),
};
const sx_layout sxrm_jp2_extended_size = {UINT32_C(0x601d000e),"jp2_extended_size",sxrm_jp2_extended_size_fields,SX_COUNT(sxrm_jp2_extended_size_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_signature_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxrm_jp2_signature = {UINT32_C(0x601d000f),"jp2_signature",sxrm_jp2_signature_fields,SX_COUNT(sxrm_jp2_signature_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_file_type_fields[] = {
    SX_FIELD("brand","char[4]",0,4,SX_ID),
    SX_FIELD("minor_version","uint32",4,4,SX_ID),
};
const sx_layout sxrm_jp2_file_type = {UINT32_C(0x601d0010),"jp2_file_type",sxrm_jp2_file_type_fields,SX_COUNT(sxrm_jp2_file_type_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_compatible_brand_fields[] = {
    SX_FIELD("brand","char[4]",0,4,SX_ID),
};
const sx_layout sxrm_jp2_compatible_brand = {UINT32_C(0x601d0011),"jp2_compatible_brand",sxrm_jp2_compatible_brand_fields,SX_COUNT(sxrm_jp2_compatible_brand_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_image_header_fields[] = {
    SX_FIELD("height","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("width","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("components","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("bits_per_component","uint8",10,1,SX_NONE),
    SX_FIELD("compression_type","uint8",11,1,SX_ID),
    SX_FIELD("unknown_colorspace","uint8",12,1,SX_FLAGS),
    SX_FIELD("intellectual_property","uint8",13,1,SX_FLAGS),
};
const sx_layout sxrm_jp2_image_header = {UINT32_C(0x601d0012),"jp2_image_header",sxrm_jp2_image_header_fields,SX_COUNT(sxrm_jp2_image_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_color_header_fields[] = {
    SX_FIELD("method","uint8",0,1,SX_ID),
    SX_FIELD("precedence","uint8",1,1,SX_NONE),
    SX_FIELD("approximation","uint8",2,1,SX_NONE),
};
const sx_layout sxrm_jp2_color_header = {UINT32_C(0x601d0013),"jp2_color_header",sxrm_jp2_color_header_fields,SX_COUNT(sxrm_jp2_color_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_jp2_enumerated_color_fields[] = {
    SX_FIELD("colorspace","uint32",0,4,SX_ID),
};
const sx_layout sxrm_jp2_enumerated_color = {UINT32_C(0x601d0014),"jp2_enumerated_color",sxrm_jp2_enumerated_color_fields,SX_COUNT(sxrm_jp2_enumerated_color_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_marker_fields[] = {
    SX_FIELD("marker","uint16",0,2,SX_ID),
};
const sx_layout sxrm_j2k_marker = {UINT32_C(0x601d0015),"j2k_marker",sxrm_j2k_marker_fields,SX_COUNT(sxrm_j2k_marker_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_segment_length_fields[] = {
    SX_FIELD("segment_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxrm_j2k_segment_length = {UINT32_C(0x601d0016),"j2k_segment_length",sxrm_j2k_segment_length_fields,SX_COUNT(sxrm_j2k_segment_length_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_siz_fields[] = {
    SX_FIELD("capabilities","uint16",0,2,SX_FLAGS),
    SX_FIELD("reference_grid_width","uint32",2,4,SX_COUNT_PROP),
    SX_FIELD("reference_grid_height","uint32",6,4,SX_COUNT_PROP),
    SX_FIELD("image_origin_x","uint32",10,4,SX_NONE),
    SX_FIELD("image_origin_y","uint32",14,4,SX_NONE),
    SX_FIELD("tile_width","uint32",18,4,SX_COUNT_PROP),
    SX_FIELD("tile_height","uint32",22,4,SX_COUNT_PROP),
    SX_FIELD("tile_origin_x","uint32",26,4,SX_NONE),
    SX_FIELD("tile_origin_y","uint32",30,4,SX_NONE),
    SX_FIELD("components","uint16",34,2,SX_COUNT_PROP),
};
const sx_layout sxrm_j2k_siz = {UINT32_C(0x601d0017),"j2k_siz",sxrm_j2k_siz_fields,SX_COUNT(sxrm_j2k_siz_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_component_fields[] = {
    SX_FIELD("precision_and_sign","uint8",0,1,SX_NONE),
    SX_FIELD("horizontal_separation","uint8",1,1,SX_NONE),
    SX_FIELD("vertical_separation","uint8",2,1,SX_NONE),
};
const sx_layout sxrm_j2k_component = {UINT32_C(0x601d0018),"j2k_component",sxrm_j2k_component_fields,SX_COUNT(sxrm_j2k_component_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_j2k_sot_fields[] = {
    SX_FIELD("tile_index","uint16",0,2,SX_ID),
    SX_FIELD("tile_part_size","uint32",2,4,SX_SIZE),
    SX_FIELD("tile_part_index","uint8",6,1,SX_ID),
    SX_FIELD("tile_part_count","uint8",7,1,SX_COUNT_PROP),
};
const sx_layout sxrm_j2k_sot = {UINT32_C(0x601d0019),"j2k_sot",sxrm_j2k_sot_fields,SX_COUNT(sxrm_j2k_sot_fields),SX_BE};
static bool sxrm_j2k(sx_context *c,uint64_t p,uint64_t end)
{
 uint64_t tile_end=0;for(unsigned step=0;p<end&&step<20000;step++){
  uint8_t h[40];if(end-p<2||!sxrm_read(c,p,h,2))break;uint16_t marker=sxrm16(h,true);if((marker&0xff00)!=0xff00)break;
  if(!sxrm_add(c,&sxrm_j2k_marker,p))return false;p+=2;if(marker==0xff4f)continue;if(marker==0xffd9)break;
  if(marker==0xff93){if(tile_end<p||tile_end>end)break;p=tile_end;continue;}
  if(end-p<2||!sxrm_read(c,p,h,2))break;uint32_t n=sxrm16(h,true);if(n<2||n>end-p)break;if(!sxrm_add(c,&sxrm_j2k_segment_length,p))return false;
  if(marker==0xff51&&n>=38){if(!sxrm_read(c,p+2,h,36)||!sxrm_add(c,&sxrm_j2k_siz,p+2))return false;uint32_t count=sxrm16(h+34,true);if(count&&count<=16384&&(uint64_t)count*3<=n-38&&!sxrm_table(c,&sxrm_j2k_component,p+38,count))return false;}
  else if(marker==0xff90&&n==10){if(!sxrm_read(c,p+2,h,8)||!sxrm_add(c,&sxrm_j2k_sot,p+2))return false;uint32_t z=sxrm32(h+2,true);tile_end=z&&z<=end-(p-2)?p-2+z:end;}
  p+=n;
 }return !c->failed;
}
static bool sxrm_jp2_boxes(sx_context *c,uint64_t p,uint64_t end,unsigned depth,unsigned *budget)
{
 while(p<end&&*budget<20000){(*budget)++;uint8_t h[16];if(end-p<8||!sxrm_read(c,p,h,8))break;uint64_t n=sxrm32(h,true),head=8;
  if(n==1){if(end-p<16||!sxrm_read(c,p+8,h+8,8))break;n=sxrm_uint(h+8,8,true);head=16;}else if(!n)n=end-p;if(n<head||n>end-p)break;
  if(!sxrm_add(c,&sxrm_jp2_box,p)||(head==16&&!sxrm_add(c,&sxrm_jp2_extended_size,p+8)))return false;uint64_t q=p+head,z=n-head;
  if(!xx_rt_memcmp(h+4,"jP  ",4)&&z==4){if(!sxrm_add(c,&sxrm_jp2_signature,q))return false;}
  else if(!xx_rt_memcmp(h+4,"ftyp",4)&&z>=8){if(!sxrm_add(c,&sxrm_jp2_file_type,q))return false;uint64_t count=(z-8)/4;if(count&&count<=20000&&!sxrm_table(c,&sxrm_jp2_compatible_brand,q+8,count))return false;}
  else if(!xx_rt_memcmp(h+4,"jp2h",4)&&depth<2){if(!sxrm_jp2_boxes(c,q,p+n,depth+1,budget))return false;}
  else if(!xx_rt_memcmp(h+4,"ihdr",4)&&z>=14){if(!sxrm_add(c,&sxrm_jp2_image_header,q))return false;}
  else if(!xx_rt_memcmp(h+4,"colr",4)&&z>=3){if(!sxrm_add(c,&sxrm_jp2_color_header,q)||!sxrm_read(c,q,h,1))return false;if(h[0]==1&&z>=7&&!sxrm_add(c,&sxrm_jp2_enumerated_color,q+3))return false;}
  else if(!xx_rt_memcmp(h+4,"jp2c",4)){if(!sxrm_j2k(c,q,p+n))return false;}
  p+=n;
 }return !c->failed;
}
bool sx_jpeg2000_jp2_build(sx_context*c)
{
 bool ok=false;unsigned budget=0;ok=sxrm_jp2_boxes(c,0,(uint64_t)c->size,0,&budget);return ok;
}
