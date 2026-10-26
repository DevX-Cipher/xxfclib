/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * APPLE PICT data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_pict_header_fields[]={
 SX_FIELD("picture_size","uint16",0,2,SX_SIZE),
 SX_FIELD("frame_top","int16",2,2,SX_NONE),
 SX_FIELD("frame_left","int16",4,2,SX_NONE),
 SX_FIELD("frame_bottom","int16",6,2,SX_NONE),
 SX_FIELD("frame_right","int16",8,2,SX_NONE),
 SX_FIELD("version_opcode","uint16",10,2,SX_ID),
 SX_FIELD("version","uint16",12,2,SX_ID),
 SX_FIELD("header_opcode","uint16",14,2,SX_ID),
 SX_FIELD("header_version","int16",16,2,SX_NONE),
 SX_FIELD("reserved","uint16",18,2,SX_RESERVED),
 SX_FIELD("horizontal_resolution_fixed","uint32",20,4,SX_NONE),
 SX_FIELD("vertical_resolution_fixed","uint32",24,4,SX_NONE),
 SX_FIELD("source_top","int16",28,2,SX_NONE),
 SX_FIELD("source_left","int16",30,2,SX_NONE),
 SX_FIELD("source_bottom","int16",32,2,SX_NONE),
 SX_FIELD("source_right","int16",34,2,SX_NONE),
 SX_FIELD("reserved_tail","uint32",36,4,SX_RESERVED),
};
const sx_layout sxnx_pict_header={UINT32_C(0x60320058),"pict_header",sxnx_pict_header_fields,SX_COUNT(sxnx_pict_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pict_clip_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("region_size","uint16",2,2,SX_SIZE),
 SX_FIELD("top","int16",4,2,SX_NONE),
 SX_FIELD("left","int16",6,2,SX_NONE),
 SX_FIELD("bottom","int16",8,2,SX_NONE),
 SX_FIELD("right","int16",10,2,SX_NONE),
};
const sx_layout sxnx_pict_clip={UINT32_C(0x60320059),"pict_clip",sxnx_pict_clip_fields,SX_COUNT(sxnx_pict_clip_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pict_directbits_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
 SX_FIELD("base_address","uint32",2,4,SX_POINTER),
 SX_FIELD("row_bytes_and_flag","uint16",6,2,SX_FLAGS),
 SX_FIELD("top","int16",8,2,SX_NONE),
 SX_FIELD("left","int16",10,2,SX_NONE),
 SX_FIELD("bottom","int16",12,2,SX_NONE),
 SX_FIELD("right","int16",14,2,SX_NONE),
 SX_FIELD("pixmap_version","uint16",16,2,SX_ID),
 SX_FIELD("pack_type","uint16",18,2,SX_ID),
 SX_FIELD("pack_size","uint32",20,4,SX_SIZE),
 SX_FIELD("horizontal_resolution_fixed","uint32",24,4,SX_NONE),
 SX_FIELD("vertical_resolution_fixed","uint32",28,4,SX_NONE),
 SX_FIELD("pixel_type","uint16",32,2,SX_ID),
 SX_FIELD("pixel_bits","uint16",34,2,SX_NONE),
 SX_FIELD("component_count","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("component_bits","uint16",38,2,SX_NONE),
 SX_FIELD("plane_bytes","uint32",40,4,SX_SIZE),
 SX_FIELD("color_table","uint32",44,4,SX_POINTER),
 SX_FIELD("reserved","uint32",48,4,SX_RESERVED),
 SX_FIELD("source_top","int16",52,2,SX_NONE),
 SX_FIELD("source_left","int16",54,2,SX_NONE),
 SX_FIELD("source_bottom","int16",56,2,SX_NONE),
 SX_FIELD("source_right","int16",58,2,SX_NONE),
 SX_FIELD("destination_top","int16",60,2,SX_NONE),
 SX_FIELD("destination_left","int16",62,2,SX_NONE),
 SX_FIELD("destination_bottom","int16",64,2,SX_NONE),
 SX_FIELD("destination_right","int16",66,2,SX_NONE),
 SX_FIELD("transfer_mode","uint16",68,2,SX_ID),
};
const sx_layout sxnx_pict_directbits={UINT32_C(0x6032005A),"pict_directbits",sxnx_pict_directbits_fields,SX_COUNT(sxnx_pict_directbits_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pict_row_short_fields[]={
 SX_FIELD("packed_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxnx_pict_row_short={UINT32_C(0x6032005B),"pict_row_short",sxnx_pict_row_short_fields,SX_COUNT(sxnx_pict_row_short_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_pict_row_long_fields[]={
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxnx_pict_row_long={UINT32_C(0x6032005C),"pict_row_long",sxnx_pict_row_long_fields,SX_COUNT(sxnx_pict_row_long_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_pict_end_fields[]={
 SX_FIELD("opcode","uint16",0,2,SX_ID),
};
const sx_layout sxnx_pict_end={UINT32_C(0x6032005D),"pict_end",sxnx_pict_end_fields,SX_COUNT(sxnx_pict_end_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_pict(sxnx_view*v)
{size_t base=0;if(sxnx_need(v,0,14,v->n)){bool zero=true;for(unsigned i=0;i<14;i++)if(v->p[i])zero=false;if(zero)base=512;}if(!SN_ROW(pict_header,base,v->n)||!SN_ROW(pict_clip,base+40,v->n)||!SN_ROW(pict_directbits,base+52,v->n))return false;int32_t height=(int32_t)xx_data_get_i16(v->p+base+6,2,0,true)-(int32_t)xx_data_get_i16(v->p+base+2,2,0,true);if(height<=0||height>4091)return false;unsigned h=(unsigned)height,rb=sxnx_u16(v->p+base+58,true)&0x7fff;size_t p=base+122;
 for(unsigned i=0;i<h;i++){if(!sxnx_row(v,rb>250?&sxnx_pict_row_long:&sxnx_pict_row_short,p,v->n))return false;unsigned n=rb>250?sxnx_u16(v->p+p,true):v->p[p];p+=rb>250?2:1;if(!sxnx_need(v,p,n,v->n))return false;p+=n;}if((p-base)&1)p++;return SN_ROW(pict_end,p,v->n)&&p+2==v->n;}
bool sx_apple_pict_build(sxnx_view*v)
{
 return sxnx_pict(v);
}
#undef SN_ROW
