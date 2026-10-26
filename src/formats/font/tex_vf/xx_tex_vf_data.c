/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tex vf data structures, moved out of the fontbinary schema family. */
#include "../../xx_format_schema_fontbinary.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxfb_vf_metrics_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("design_size","int32",4,4,SX_NONE),
};
const sx_layout sxfb_vf_metrics = {UINT32_C(0x60190043),"vf_metrics",sxfb_vf_metrics_fields,SX_COUNT(sxfb_vf_metrics_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_font_definition1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("font_number","uint8",1,1,SX_ID),
    SX_FIELD("checksum","uint32",2,4,SX_CHECKSUM),
    SX_FIELD("scale","int32",6,4,SX_NONE),
    SX_FIELD("design_size","int32",10,4,SX_NONE),
    SX_FIELD("area_length","uint8",14,1,SX_SIZE),
    SX_FIELD("name_length","uint8",15,1,SX_SIZE),
};
const sx_layout sxfb_vf_font_definition1 = {UINT32_C(0x60190044),"vf_font_definition1",sxfb_vf_font_definition1_fields,SX_COUNT(sxfb_vf_font_definition1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_font_definition2_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("font_number","uint16",1,2,SX_ID),
    SX_FIELD("checksum","uint32",3,4,SX_CHECKSUM),
    SX_FIELD("scale","int32",7,4,SX_NONE),
    SX_FIELD("design_size","int32",11,4,SX_NONE),
    SX_FIELD("area_length","uint8",15,1,SX_SIZE),
    SX_FIELD("name_length","uint8",16,1,SX_SIZE),
};
const sx_layout sxfb_vf_font_definition2 = {UINT32_C(0x60190045),"vf_font_definition2",sxfb_vf_font_definition2_fields,SX_COUNT(sxfb_vf_font_definition2_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_font_definition3_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("font_number","uint24",1,3,SX_ID),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("scale","int32",8,4,SX_NONE),
    SX_FIELD("design_size","int32",12,4,SX_NONE),
    SX_FIELD("area_length","uint8",16,1,SX_SIZE),
    SX_FIELD("name_length","uint8",17,1,SX_SIZE),
};
const sx_layout sxfb_vf_font_definition3 = {UINT32_C(0x60190046),"vf_font_definition3",sxfb_vf_font_definition3_fields,SX_COUNT(sxfb_vf_font_definition3_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_font_definition4_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("font_number","int32",1,4,SX_ID),
    SX_FIELD("checksum","uint32",5,4,SX_CHECKSUM),
    SX_FIELD("scale","int32",9,4,SX_NONE),
    SX_FIELD("design_size","int32",13,4,SX_NONE),
    SX_FIELD("area_length","uint8",17,1,SX_SIZE),
    SX_FIELD("name_length","uint8",18,1,SX_SIZE),
};
const sx_layout sxfb_vf_font_definition4 = {UINT32_C(0x60190047),"vf_font_definition4",sxfb_vf_font_definition4_fields,SX_COUNT(sxfb_vf_font_definition4_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_short_packet_fields[] = {
    SX_FIELD("packet_size","uint8",0,1,SX_SIZE),
    SX_FIELD("character_code","uint8",1,1,SX_ID),
    SX_FIELD("tfm_width","uint24",2,3,SX_NONE),
};
const sx_layout sxfb_vf_short_packet = {UINT32_C(0x60190048),"vf_short_packet",sxfb_vf_short_packet_fields,SX_COUNT(sxfb_vf_short_packet_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_vf_long_packet_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("packet_size","int32",1,4,SX_SIZE),
    SX_FIELD("character_code","int32",5,4,SX_ID),
    SX_FIELD("tfm_width","int32",9,4,SX_NONE),
};
const sx_layout sxfb_vf_long_packet = {UINT32_C(0x60190049),"vf_long_packet",sxfb_vf_long_packet_fields,SX_COUNT(sxfb_vf_long_packet_fields),SX_BE};
static bool sxfb_vf(sx_context *c)
{
 uint64_t p;if(!sxfb_preamble(c,202,&p)||!sxfb_span(c,p,8)||!sxfb_add(c,&sxfb_vf_metrics,p))return false;p+=8;
 for(unsigned step=0;p<(uint64_t)c->size&&step<20000;step++){uint8_t h[19];if(!sxfb_read(c,p,h,1))return false;unsigned op=h[0],size=0;uint64_t payload=0;const sx_layout *l=NULL;
  if(op<=241){size=5;payload=op;l=&sxfb_vf_short_packet;}
  else if(op==242){size=13;if(!sxfb_read(c,p,h,size))break;payload=sxfb32(h+1,true);l=&sxfb_vf_long_packet;}
  else if(op<=246){unsigned width=op-242;size=15+width;if(!sxfb_read(c,p,h,size))break;payload=(unsigned)h[width+13]+h[width+14];const sx_layout *a[]={&sxfb_vf_font_definition1,&sxfb_vf_font_definition2,&sxfb_vf_font_definition3,&sxfb_vf_font_definition4};l=a[width-1];}
  else if(op==248){size=1;l=&sxfb_tex_opcode;}else break;
  if(!sxfb_span(c,p,size+payload))break;if(!sxfb_add(c,l,p))return false;p+=size+payload;
 }return !c->failed;
}
bool sx_tex_vf_build(sx_context*c)
{
 return sxfb_vf(c);
}
