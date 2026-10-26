/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * dec_sixel data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_sixel_parameter_fields[]={
 SX_FIELD("sixel_parameter","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_sixel_parameter={0x60710032U,"textwire_sixel_parameter",sxtw_sixel_parameter_fields,SX_COUNT(sxtw_sixel_parameter_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_aspect_numerator_fields[]={
 SX_FIELD("aspect_numerator","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_aspect_numerator={0x60710033U,"textwire_aspect_numerator",sxtw_aspect_numerator_fields,SX_COUNT(sxtw_aspect_numerator_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_aspect_denominator_fields[]={
 SX_FIELD("aspect_denominator","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_aspect_denominator={0x60710034U,"textwire_aspect_denominator",sxtw_aspect_denominator_fields,SX_COUNT(sxtw_aspect_denominator_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_width_fields[]={
 SX_FIELD("width","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_width={0x60710035U,"textwire_width",sxtw_width_fields,SX_COUNT(sxtw_width_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_height_fields[]={
 SX_FIELD("height","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_height={0x60710036U,"textwire_height",sxtw_height_fields,SX_COUNT(sxtw_height_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_color_register_fields[]={
 SX_FIELD("color_register","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_color_register={0x60710037U,"textwire_color_register",sxtw_color_register_fields,SX_COUNT(sxtw_color_register_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_color_mode_fields[]={
 SX_FIELD("color_mode","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_color_mode={0x60710038U,"textwire_color_mode",sxtw_color_mode_fields,SX_COUNT(sxtw_color_mode_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_red_percent_fields[]={
 SX_FIELD("red_percent","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_red_percent={0x60710039U,"textwire_red_percent",sxtw_red_percent_fields,SX_COUNT(sxtw_red_percent_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_green_percent_fields[]={
 SX_FIELD("green_percent","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_green_percent={0x6071003aU,"textwire_green_percent",sxtw_green_percent_fields,SX_COUNT(sxtw_green_percent_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_blue_percent_fields[]={
 SX_FIELD("blue_percent","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_blue_percent={0x6071003bU,"textwire_blue_percent",sxtw_blue_percent_fields,SX_COUNT(sxtw_blue_percent_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_repeat_count_fields[]={
 SX_FIELD("repeat_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxtw_repeat_count={0x6071003cU,"textwire_repeat_count",sxtw_repeat_count_fields,SX_COUNT(sxtw_repeat_count_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_sixel_symbol_fields[]={
 SX_FIELD("symbol","uint8",0,1,SX_NONE),
};
const sx_layout sxtw_sixel_symbol={0x60710047U,"textwire_sixel_symbol",sxtw_sixel_symbol_fields,SX_COUNT(sxtw_sixel_symbol_fields),SX_LE};
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_sixel_number(sxtw_cursor*q,int64_t*pos,const sx_layout*l)
{
 int64_t a=*pos;while(*pos<q->n&&q->b[*pos]>='0'&&q->b[*pos]<='9')(*pos)++;return *pos>a&&sxtw_emit(q,l,a,*pos-a);
}
static bool sxtw_sixel(sxtw_cursor*q)
{
 if(q->n<12||q->b[0]!=27||q->b[1]!='P')return false;TW_EMIT(signature,0,2);int64_t p=2;
 while(p<q->n&&q->b[p]!='q'){if(!sxtw_sixel_number(q,&p,&sxtw_sixel_parameter))return false;if(p<q->n&&q->b[p]==';')p++;}
 if(q->n-p<2||q->b[p++]!='q'||q->b[p++]!='"')return false;const sx_layout*l[]={&sxtw_aspect_numerator,&sxtw_aspect_denominator,&sxtw_width,&sxtw_height};
 for(unsigned i=0;i<4;i++){if(!sxtw_sixel_number(q,&p,l[i]))return false;if(i<3&&(p==q->n||q->b[p++]!=';'))return false;}
 while(p<q->n-2){if(q->c->count>=32000)return true;unsigned c=q->b[p++];
  if(c=='#'){if(!sxtw_sixel_number(q,&p,&sxtw_color_register))return false;if(p<q->n&&q->b[p]==';'){p++;const sx_layout*color[]={&sxtw_color_mode,&sxtw_red_percent,&sxtw_green_percent,&sxtw_blue_percent};for(unsigned i=0;i<4;i++){if(!sxtw_sixel_number(q,&p,color[i]))return false;if(i<3&&(p==q->n||q->b[p++]!=';'))return false;}}}
  else if(c=='!'){if(!sxtw_sixel_number(q,&p,&sxtw_repeat_count)||p>=q->n-2)return false;TW_EMIT(sixel_symbol,p,1);p++;}
  else if(c=='$'||c=='-'){TW_EMIT(control,p-1,1);}
  else if(c>='?'&&c<='~'){TW_EMIT(sixel_symbol,p-1,1);}else return false;
 }if(p!=q->n-2||q->b[p]!=27||q->b[p+1]!='\\')return false;TW_EMIT(signature,p,2);return true;
}
bool sx_dec_sixel_build(sxtw_cursor*q)
{
 return sxtw_sixel(q);
}
#undef TW_EMIT
