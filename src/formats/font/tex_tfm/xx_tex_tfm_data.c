/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tex tfm data structures, moved out of the fontbinary schema family. */
#include "../../xx_format_schema_fontbinary.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxfb_tfm_counts_fields[] = {
    SX_FIELD("file_words","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("header_words","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("first_character","uint16",4,2,SX_ID),
    SX_FIELD("last_character","uint16",6,2,SX_ID),
    SX_FIELD("width_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("height_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("depth_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("italic_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("ligature_kern_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("kern_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("recipe_count","uint16",20,2,SX_COUNT_PROP),
    SX_FIELD("parameter_count","uint16",22,2,SX_COUNT_PROP),
};
const sx_layout sxfb_tfm_counts = {UINT32_C(0x6019001e),"tfm_counts",sxfb_tfm_counts_fields,SX_COUNT(sxfb_tfm_counts_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_header_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("design_size","int32",4,4,SX_NONE),
};
const sx_layout sxfb_tfm_header = {UINT32_C(0x6019001f),"tfm_header",sxfb_tfm_header_fields,SX_COUNT(sxfb_tfm_header_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_coding_scheme_fields[] = {
    SX_FIELD("string_length","uint8",0,1,SX_SIZE),
    SX_FIELD("coding_scheme","char[39]",1,39,SX_STRING),
};
const sx_layout sxfb_tfm_coding_scheme = {UINT32_C(0x60190020),"tfm_coding_scheme",sxfb_tfm_coding_scheme_fields,SX_COUNT(sxfb_tfm_coding_scheme_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_family_fields[] = {
    SX_FIELD("string_length","uint8",0,1,SX_SIZE),
    SX_FIELD("family","char[19]",1,19,SX_STRING),
};
const sx_layout sxfb_tfm_family = {UINT32_C(0x60190021),"tfm_family",sxfb_tfm_family_fields,SX_COUNT(sxfb_tfm_family_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_face_fields[] = {
    SX_FIELD("seven_bit_safe","uint8",0,1,SX_FLAGS),
    SX_FIELD("unused","uint8[2]",1,2,SX_RESERVED),
    SX_FIELD("face","uint8",3,1,SX_ID),
};
const sx_layout sxfb_tfm_face = {UINT32_C(0x60190022),"tfm_face",sxfb_tfm_face_fields,SX_COUNT(sxfb_tfm_face_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_character_fields[] = {
    SX_FIELD("width_index","uint8",0,1,SX_ID),
    SX_FIELD("height_depth_indexes","uint8",1,1,SX_NONE),
    SX_FIELD("italic_index_and_tag","uint8",2,1,SX_NONE),
    SX_FIELD("remainder","uint8",3,1,SX_ID),
};
const sx_layout sxfb_tfm_character = {UINT32_C(0x60190023),"tfm_character",sxfb_tfm_character_fields,SX_COUNT(sxfb_tfm_character_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_width_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxfb_tfm_width = {UINT32_C(0x60190024),"tfm_width",sxfb_tfm_width_fields,SX_COUNT(sxfb_tfm_width_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_height_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxfb_tfm_height = {UINT32_C(0x60190025),"tfm_height",sxfb_tfm_height_fields,SX_COUNT(sxfb_tfm_height_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_depth_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxfb_tfm_depth = {UINT32_C(0x60190026),"tfm_depth",sxfb_tfm_depth_fields,SX_COUNT(sxfb_tfm_depth_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_italic_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxfb_tfm_italic = {UINT32_C(0x60190027),"tfm_italic",sxfb_tfm_italic_fields,SX_COUNT(sxfb_tfm_italic_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_kern_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxfb_tfm_kern = {UINT32_C(0x60190028),"tfm_kern",sxfb_tfm_kern_fields,SX_COUNT(sxfb_tfm_kern_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_parameter_fields[] = {
    SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxfb_tfm_parameter = {UINT32_C(0x60190029),"tfm_parameter",sxfb_tfm_parameter_fields,SX_COUNT(sxfb_tfm_parameter_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_ligature_kern_fields[] = {
    SX_FIELD("skip_byte","uint8",0,1,SX_NONE),
    SX_FIELD("next_character","uint8",1,1,SX_ID),
    SX_FIELD("operation_byte","uint8",2,1,SX_NONE),
    SX_FIELD("remainder","uint8",3,1,SX_NONE),
};
const sx_layout sxfb_tfm_ligature_kern = {UINT32_C(0x6019002a),"tfm_ligature_kern",sxfb_tfm_ligature_kern_fields,SX_COUNT(sxfb_tfm_ligature_kern_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_tfm_extensible_recipe_fields[] = {
    SX_FIELD("top_character","uint8",0,1,SX_ID),
    SX_FIELD("middle_character","uint8",1,1,SX_ID),
    SX_FIELD("bottom_character","uint8",2,1,SX_ID),
    SX_FIELD("repeat_character","uint8",3,1,SX_ID),
};
const sx_layout sxfb_tfm_extensible_recipe = {UINT32_C(0x6019002b),"tfm_extensible_recipe",sxfb_tfm_extensible_recipe_fields,SX_COUNT(sxfb_tfm_extensible_recipe_fields),SX_BE};
static bool sxfb_tfm(sx_context *c)
{
 uint8_t h[24];if(!sxfb_read(c,0,h,24))return false;uint32_t q[12];for(unsigned i=0;i<12;i++)q[i]=sxfb16(h+i*2,true);
 if(q[1]<2||q[1]>1024||q[2]>255||q[3]>255||!sxfb_span(c,0,(uint64_t)q[0]*4)||!sxfb_add(c,&sxfb_tfm_counts,0))return false;
 uint64_t p=24,header=(uint64_t)q[1]*4;if(!sxfb_span(c,p,header))return true;if(!sxfb_add(c,&sxfb_tfm_header,p))return false;
 if(header>=48&&!sxfb_add(c,&sxfb_tfm_coding_scheme,p+8))return false;
 if(header>=68&&!sxfb_add(c,&sxfb_tfm_family,p+48))return false;
 if(header>=72&&!sxfb_add(c,&sxfb_tfm_face,p+68))return false;p+=header;
 const sx_layout *tables[]={&sxfb_tfm_character,&sxfb_tfm_width,&sxfb_tfm_height,&sxfb_tfm_depth,&sxfb_tfm_italic,&sxfb_tfm_ligature_kern,&sxfb_tfm_kern,&sxfb_tfm_extensible_recipe,&sxfb_tfm_parameter};
 for(unsigned i=0;i<9;i++){uint32_t n=i?q[i+3]:(q[3]>=q[2]?q[3]-q[2]+1:0);if(!sxfb_span(c,p,(uint64_t)n*4))break;if(n&&!sx_table(c,tables[i],(int64_t)p,4,n))return false;p+=(uint64_t)n*4;}return true;
}
bool sx_tex_tfm_build(sx_context*c)
{
 return sxfb_tfm(c);
}
