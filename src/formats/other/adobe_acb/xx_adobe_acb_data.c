/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * adobe acb data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_acb_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_NONE),
 SX_FIELD("book_id","uint16",6,2,SX_ID),
};
const sx_layout sxbx_acb_header = {UINT32_C(0x6030006d),"acb_header",sxbx_acb_header_fields,SX_COUNT(sxbx_acb_header_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_acb_string_length_fields[] = {
 SX_FIELD("utf16_unit_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbx_acb_string_length = {UINT32_C(0x6030006e),"acb_string_length",sxbx_acb_string_length_fields,SX_COUNT(sxbx_acb_string_length_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_acb_palette_fields[] = {
 SX_FIELD("color_count","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("colors_per_page","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("page_offset","uint16",4,2,SX_NONE),
 SX_FIELD("color_space","uint16",6,2,SX_ID),
};
const sx_layout sxbx_acb_palette = {UINT32_C(0x6030006f),"acb_palette",sxbx_acb_palette_fields,SX_COUNT(sxbx_acb_palette_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_acb_color_rgb_fields[] = {
 SX_FIELD("code","char[6]",0,6,SX_NONE),
 SX_FIELD("component_0","uint8",6,1,SX_NONE),
 SX_FIELD("component_1","uint8",7,1,SX_NONE),
 SX_FIELD("component_2","uint8",8,1,SX_NONE),
};
const sx_layout sxbx_acb_color_rgb = {UINT32_C(0x60300070),"acb_color_rgb",sxbx_acb_color_rgb_fields,SX_COUNT(sxbx_acb_color_rgb_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_acb_color_cmyk_fields[] = {
 SX_FIELD("code","char[6]",0,6,SX_NONE),
 SX_FIELD("component_0","uint8",6,1,SX_NONE),
 SX_FIELD("component_1","uint8",7,1,SX_NONE),
 SX_FIELD("component_2","uint8",8,1,SX_NONE),
 SX_FIELD("component_3","uint8",9,1,SX_NONE),
};
const sx_layout sxbx_acb_color_cmyk = {UINT32_C(0x60300071),"acb_color_cmyk",sxbx_acb_color_cmyk_fields,SX_COUNT(sxbx_acb_color_cmyk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_acb_color_lab_fields[] = {
 SX_FIELD("code","char[6]",0,6,SX_NONE),
 SX_FIELD("component_0","uint8",6,1,SX_NONE),
 SX_FIELD("component_1","uint8",7,1,SX_NONE),
 SX_FIELD("component_2","uint8",8,1,SX_NONE),
};
const sx_layout sxbx_acb_color_lab = {UINT32_C(0x60300072),"acb_color_lab",sxbx_acb_color_lab_fields,SX_COUNT(sxbx_acb_color_lab_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_acb_trailer_fields[] = {
 SX_FIELD("mode","char[8]",0,8,SX_ID),
};
const sx_layout sxbx_acb_trailer = {UINT32_C(0x60300073),"acb_trailer",sxbx_acb_trailer_fields,SX_COUNT(sxbx_acb_trailer_fields),SX_LE};
static bool sxbx_acb(sx_context*c){uint64_t p=8,end=(uint64_t)c->size,n,space;if(!sxbx_add(c,&sxbx_acb_header,0))return false;for(unsigned i=0;i<4;i++)if(!sxbx_counted(c,&p,end,&sxbx_acb_string_length,4,true,2))return true;if(!sxbx_word(c,p,2,true,&n)||!sxbx_word(c,p+6,2,true,&space)||!sxbx_add(c,&sxbx_acb_palette,p)||n>4094||(space!=0&&space!=2&&space!=7))return true;p+=8;unsigned width=space==2?10:9;const sx_layout*l=space==2?&sxbx_acb_color_cmyk:space==7?&sxbx_acb_color_lab:&sxbx_acb_color_rgb;for(uint64_t i=0;i<n;i++){if(!sxbx_counted(c,&p,end,&sxbx_acb_string_length,4,true,2)||p>end||width>end-p||!sxbx_add(c,l,p))return true;p+=width;}if(end-p==8&&!sxbx_add(c,&sxbx_acb_trailer,p))return false;return true;}
bool sx_adobe_acb_build(sx_context*c)
{
 return sxbx_acb(c);
}
