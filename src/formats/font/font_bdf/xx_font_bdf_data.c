/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * font_bdf data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_font_name_fields[]={
 SX_FIELD("font_name","utf8",0,0,SX_STRING),
};
const sx_layout sxmt_font_name={0x6052000dU,"modeltext_font_name",sxmt_font_name_fields,SX_COUNT(sxmt_font_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_font_size_fields[]={
 SX_FIELD("font_size","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_font_size={0x6052002aU,"modeltext_font_size",sxmt_font_size_fields,SX_COUNT(sxmt_font_size_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_resolution_x_fields[]={
 SX_FIELD("resolution_x","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_resolution_x={0x6052002bU,"modeltext_resolution_x",sxmt_resolution_x_fields,SX_COUNT(sxmt_resolution_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_resolution_y_fields[]={
 SX_FIELD("resolution_y","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_resolution_y={0x6052002cU,"modeltext_resolution_y",sxmt_resolution_y_fields,SX_COUNT(sxmt_resolution_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bbox_width_fields[]={
 SX_FIELD("bbox_width","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_bbox_width={0x6052002dU,"modeltext_bbox_width",sxmt_bbox_width_fields,SX_COUNT(sxmt_bbox_width_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bbox_height_fields[]={
 SX_FIELD("bbox_height","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_bbox_height={0x6052002eU,"modeltext_bbox_height",sxmt_bbox_height_fields,SX_COUNT(sxmt_bbox_height_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bbox_x_fields[]={
 SX_FIELD("bbox_x","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_bbox_x={0x6052002fU,"modeltext_bbox_x",sxmt_bbox_x_fields,SX_COUNT(sxmt_bbox_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bbox_y_fields[]={
 SX_FIELD("bbox_y","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_bbox_y={0x60520030U,"modeltext_bbox_y",sxmt_bbox_y_fields,SX_COUNT(sxmt_bbox_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_swidth_x_fields[]={
 SX_FIELD("swidth_x","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_swidth_x={0x60520031U,"modeltext_swidth_x",sxmt_swidth_x_fields,SX_COUNT(sxmt_swidth_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_swidth_y_fields[]={
 SX_FIELD("swidth_y","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_swidth_y={0x60520032U,"modeltext_swidth_y",sxmt_swidth_y_fields,SX_COUNT(sxmt_swidth_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dwidth_x_fields[]={
 SX_FIELD("dwidth_x","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_dwidth_x={0x60520033U,"modeltext_dwidth_x",sxmt_dwidth_x_fields,SX_COUNT(sxmt_dwidth_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dwidth_y_fields[]={
 SX_FIELD("dwidth_y","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_dwidth_y={0x60520034U,"modeltext_dwidth_y",sxmt_dwidth_y_fields,SX_COUNT(sxmt_dwidth_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_glyph_attributes_fields[]={
 SX_FIELD("glyph_attributes","ascii_hex",0,0,SX_FLAGS),
};
const sx_layout sxmt_glyph_attributes={0x6052005eU,"modeltext_glyph_attributes",sxmt_glyph_attributes_fields,SX_COUNT(sxmt_glyph_attributes_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_bitmap_byte_fields[]={
 SX_FIELD("bitmap_byte","ascii_hex",0,0,SX_FLAGS),
};
const sx_layout sxmt_bitmap_byte={0x6052005fU,"modeltext_bitmap_byte",sxmt_bitmap_byte_fields,SX_COUNT(sxmt_bitmap_byte_fields),SX_LE};
#define MT_VALUE(n,e,v) do{if(!sxmt_value(q,&sxmt_##n,(e),(v)))return false;}while(0)
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)
static bool sxmt_bdf(sxmt_cursor*q){int64_t a,e,k,z;bool bitmap=false,properties=false;while(sxmt_line(q,&a,&e,false)){if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false))return false;
 if(sxmt_eq(q,k,z,"COMMENT")){q->p=next;continue;}
 if(bitmap&&!sxmt_eq(q,k,z,"ENDCHAR")){if((e-a)%2)return false;for(int64_t i=a;i<e;i+=2)MT_EMIT(bitmap_byte,i,2);q->p=next;continue;}
 MT_EMIT(keyword,k,z);
 if(sxmt_eq(q,k,z,"ENDCHAR"))bitmap=false;else if(sxmt_eq(q,k,z,"BITMAP"))bitmap=true;else if(sxmt_eq(q,k,z,"ENDPROPERTIES"))properties=false;
 else if(sxmt_eq(q,k,z,"STARTFONT")){MT_VALUE(version,e,NULL);}
 else if(sxmt_eq(q,k,z,"FONT")){if(!sxmt_remainder(q,&sxmt_font_name,e))return false;}
 else if(sxmt_eq(q,k,z,"STARTCHAR")){if(!sxmt_remainder(q,&sxmt_glyph_name,e))return false;}
 else if(sxmt_eq(q,k,z,"SIZE")){MT_VALUE(font_size,e,NULL);MT_VALUE(resolution_x,e,NULL);MT_VALUE(resolution_y,e,NULL);}
 else if(sxmt_eq(q,k,z,"FONTBOUNDINGBOX")||sxmt_eq(q,k,z,"BBX")){MT_VALUE(bbox_width,e,NULL);MT_VALUE(bbox_height,e,NULL);MT_VALUE(bbox_x,e,NULL);MT_VALUE(bbox_y,e,NULL);}
 else if(sxmt_eq(q,k,z,"SWIDTH")){MT_VALUE(swidth_x,e,NULL);MT_VALUE(swidth_y,e,NULL);}
 else if(sxmt_eq(q,k,z,"DWIDTH")){MT_VALUE(dwidth_x,e,NULL);MT_VALUE(dwidth_y,e,NULL);}
 else if(sxmt_eq(q,k,z,"STARTPROPERTIES")){MT_VALUE(property_total,e,NULL);properties=true;}
 else if(sxmt_eq(q,k,z,"CHARS")){MT_VALUE(glyph_count,e,NULL);}
 else if(sxmt_eq(q,k,z,"ENCODING")){MT_VALUE(codepoint,e,NULL);}
 else if(sxmt_eq(q,k,z,"ATTRIBUTES")){MT_VALUE(glyph_attributes,e,NULL);}
 else if(properties){while(q->p<e&&sxmt_space(q->b[q->p]))q->p++;if(!sxmt_remainder(q,q->p<e&&q->b[q->p]=='"'?&sxmt_string_value:&sxmt_integer_value,e))return false;}
 q->p=next;}return !bitmap;}
bool sx_font_bdf_build(sxmt_cursor*q)
{
 return sxmt_bdf(q);
}
#undef MT_VALUE
#undef MT_EMIT
