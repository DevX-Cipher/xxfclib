/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tex gf data structures, moved out of the fontbinary schema family. */
#include "../../xx_format_schema_fontbinary.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxfb_gf_boc_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("character_code","int32",1,4,SX_ID),
    SX_FIELD("previous_boc_offset","int32",5,4,SX_OFFSET),
    SX_FIELD("minimum_m","int32",9,4,SX_NONE),
    SX_FIELD("maximum_m","int32",13,4,SX_NONE),
    SX_FIELD("minimum_n","int32",17,4,SX_NONE),
    SX_FIELD("maximum_n","int32",21,4,SX_NONE),
};
const sx_layout sxfb_gf_boc = {UINT32_C(0x60190037),"gf_boc",sxfb_gf_boc_fields,SX_COUNT(sxfb_gf_boc_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_boc1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("character_code","uint8",1,1,SX_ID),
    SX_FIELD("delta_m","uint8",2,1,SX_NONE),
    SX_FIELD("maximum_m","uint8",3,1,SX_NONE),
    SX_FIELD("delta_n","uint8",4,1,SX_NONE),
    SX_FIELD("maximum_n","uint8",5,1,SX_NONE),
};
const sx_layout sxfb_gf_boc1 = {UINT32_C(0x60190038),"gf_boc1",sxfb_gf_boc1_fields,SX_COUNT(sxfb_gf_boc1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_paint1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("pixel_count","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxfb_gf_paint1 = {UINT32_C(0x60190039),"gf_paint1",sxfb_gf_paint1_fields,SX_COUNT(sxfb_gf_paint1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_skip1_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("extra_rows","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxfb_gf_skip1 = {UINT32_C(0x6019003a),"gf_skip1",sxfb_gf_skip1_fields,SX_COUNT(sxfb_gf_skip1_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_paint2_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("pixel_count","uint16",1,2,SX_COUNT_PROP),
};
const sx_layout sxfb_gf_paint2 = {UINT32_C(0x6019003b),"gf_paint2",sxfb_gf_paint2_fields,SX_COUNT(sxfb_gf_paint2_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_skip2_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("extra_rows","uint16",1,2,SX_COUNT_PROP),
};
const sx_layout sxfb_gf_skip2 = {UINT32_C(0x6019003c),"gf_skip2",sxfb_gf_skip2_fields,SX_COUNT(sxfb_gf_skip2_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_paint3_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("pixel_count","uint24",1,3,SX_COUNT_PROP),
};
const sx_layout sxfb_gf_paint3 = {UINT32_C(0x6019003d),"gf_paint3",sxfb_gf_paint3_fields,SX_COUNT(sxfb_gf_paint3_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_skip3_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("extra_rows","uint24",1,3,SX_COUNT_PROP),
};
const sx_layout sxfb_gf_skip3 = {UINT32_C(0x6019003e),"gf_skip3",sxfb_gf_skip3_fields,SX_COUNT(sxfb_gf_skip3_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_post_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("previous_eoc_offset","int32",1,4,SX_OFFSET),
    SX_FIELD("design_size","int32",5,4,SX_NONE),
    SX_FIELD("checksum","uint32",9,4,SX_CHECKSUM),
    SX_FIELD("horizontal_pixels_per_point","int32",13,4,SX_NONE),
    SX_FIELD("vertical_pixels_per_point","int32",17,4,SX_NONE),
    SX_FIELD("minimum_m","int32",21,4,SX_NONE),
    SX_FIELD("maximum_m","int32",25,4,SX_NONE),
    SX_FIELD("minimum_n","int32",29,4,SX_NONE),
    SX_FIELD("maximum_n","int32",33,4,SX_NONE),
};
const sx_layout sxfb_gf_post = {UINT32_C(0x6019003f),"gf_post",sxfb_gf_post_fields,SX_COUNT(sxfb_gf_post_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_char_loc_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("character_code","uint8",1,1,SX_ID),
    SX_FIELD("dx","int32",2,4,SX_NONE),
    SX_FIELD("dy","int32",6,4,SX_NONE),
    SX_FIELD("tfm_width","int32",10,4,SX_NONE),
    SX_FIELD("packet_offset","int32",14,4,SX_OFFSET),
};
const sx_layout sxfb_gf_char_loc = {UINT32_C(0x60190040),"gf_char_loc",sxfb_gf_char_loc_fields,SX_COUNT(sxfb_gf_char_loc_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_char_loc0_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("character_code","uint8",1,1,SX_ID),
    SX_FIELD("dx","uint8",2,1,SX_NONE),
    SX_FIELD("tfm_width","int32",3,4,SX_NONE),
    SX_FIELD("packet_offset","int32",7,4,SX_OFFSET),
};
const sx_layout sxfb_gf_char_loc0 = {UINT32_C(0x60190041),"gf_char_loc0",sxfb_gf_char_loc0_fields,SX_COUNT(sxfb_gf_char_loc0_fields),SX_BE};
static const xx_data_struct_field_desc sxfb_gf_postpost_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("postamble_offset","int32",1,4,SX_OFFSET),
    SX_FIELD("format_id","uint8",5,1,SX_ID),
};
const sx_layout sxfb_gf_postpost = {UINT32_C(0x60190042),"gf_postpost",sxfb_gf_postpost_fields,SX_COUNT(sxfb_gf_postpost_fields),SX_BE};
static bool sxfb_gf(sx_context *c)
{
 uint64_t p;if(!sxfb_preamble(c,131,&p))return false;
 for(unsigned step=0;p<(uint64_t)c->size&&step<20000;step++){uint8_t op;if(!sxfb_read(c,p,&op,1))return false;const sx_layout *l=NULL;unsigned size=1;
  if(op>=239&&op<=242){if(!sxfb_special(c,&p,op-238))break;continue;}
  if(op<=63||op==69||op==70||(op>=74&&op<=238)||op==244)l=&sxfb_tex_opcode;
  else if(op>=64&&op<=66){const sx_layout *a[]={&sxfb_gf_paint1,&sxfb_gf_paint2,&sxfb_gf_paint3};l=a[op-64];size=op-62;}
  else if(op>=71&&op<=73){const sx_layout *a[]={&sxfb_gf_skip1,&sxfb_gf_skip2,&sxfb_gf_skip3};l=a[op-71];size=op-69;}
  else if(op==67){l=&sxfb_gf_boc;size=25;}else if(op==68){l=&sxfb_gf_boc1;size=6;}
  else if(op==243){l=&sxfb_tex_numeric_special;size=5;}else if(op==245){l=&sxfb_gf_char_loc;size=18;}
  else if(op==246){l=&sxfb_gf_char_loc0;size=11;}else if(op==248){l=&sxfb_gf_post;size=37;}
  else if(op==249){if(sxfb_span(c,p,6)&&!sxfb_add(c,&sxfb_gf_postpost,p))return false;break;}
  else break;if(!sxfb_span(c,p,size))break;if(!sxfb_add(c,l,p))return false;p+=size;
 }return !c->failed;
}
bool sx_tex_gf_build(sx_context*c)
{
 return sxfb_gf(c);
}
