/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WORDPERFECT WPG data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_wpg_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("data_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("product_type","uint8",8,1,SX_ID),
 SX_FIELD("file_type","uint8",9,1,SX_ID),
 SX_FIELD("major_version","uint8",10,1,SX_ID),
 SX_FIELD("minor_version","uint8",11,1,SX_ID),
 SX_FIELD("encryption_key","uint16",12,2,SX_ID),
 SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
};
const sx_layout sxnx_wpg_header={UINT32_C(0x6032002D),"wpg_header",sxnx_wpg_header_fields,SX_COUNT(sxnx_wpg_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_record_short_fields[]={
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("data_size","uint8",1,1,SX_SIZE),
};
const sx_layout sxnx_wpg_record_short={UINT32_C(0x6032002E),"wpg_record_short",sxnx_wpg_record_short_fields,SX_COUNT(sxnx_wpg_record_short_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_record_medium_fields[]={
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("length_marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("data_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxnx_wpg_record_medium={UINT32_C(0x6032002F),"wpg_record_medium",sxnx_wpg_record_medium_fields,SX_COUNT(sxnx_wpg_record_medium_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_record_long_fields[]={
 SX_FIELD("record_type","uint8",0,1,SX_ID),
 SX_FIELD("length_marker","uint8",1,1,SX_SIGNATURE),
 SX_FIELD("length_high15_and_flag","uint16",2,2,SX_FLAGS),
 SX_FIELD("length_low16","uint16",4,2,SX_NONE),
};
const sx_layout sxnx_wpg_record_long={UINT32_C(0x60320030),"wpg_record_long",sxnx_wpg_record_long_fields,SX_COUNT(sxnx_wpg_record_long_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_start_fields[]={
 SX_FIELD("version","uint16",0,2,SX_ID),
 SX_FIELD("canvas_width","uint16",2,2,SX_NONE),
 SX_FIELD("canvas_height","uint16",4,2,SX_NONE),
};
const sx_layout sxnx_wpg_start={UINT32_C(0x60320031),"wpg_start",sxnx_wpg_start_fields,SX_COUNT(sxnx_wpg_start_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_palette_fields[]={
 SX_FIELD("first_index","uint16",0,2,SX_ID),
 SX_FIELD("end_index","uint16",2,2,SX_ID),
};
const sx_layout sxnx_wpg_palette={UINT32_C(0x60320032),"wpg_palette",sxnx_wpg_palette_fields,SX_COUNT(sxnx_wpg_palette_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_wpg_bitmap_fields[]={
 SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("depth","uint16",4,2,SX_NONE),
 SX_FIELD("horizontal_resolution","uint16",6,2,SX_NONE),
 SX_FIELD("vertical_resolution","uint16",8,2,SX_NONE),
};
const sx_layout sxnx_wpg_bitmap={UINT32_C(0x60320034),"wpg_bitmap",sxnx_wpg_bitmap_fields,SX_COUNT(sxnx_wpg_bitmap_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_wpg(sxnx_view*v)
{if(!SN_ROW(wpg_header,0,v->n))return false;size_t p=16;unsigned work=0;
 while(p<v->n){if(++work>1024||!sxnx_need(v,p,2,v->n))return false;unsigned kind=v->p[p];uint32_t n=v->p[p+1];const sx_layout*l=&sxnx_wpg_record_short;unsigned hs=2;if(n==255){if(!sxnx_need(v,p,4,v->n))return false;n=sxnx_u16(v->p+p+2,false);hs=4;l=&sxnx_wpg_record_medium;if(n&0x8000){if(!sxnx_need(v,p,6,v->n))return false;n=((n&0x7fff)<<16)|sxnx_u16(v->p+p+4,false);hs=6;l=&sxnx_wpg_record_long;}}
 if(!sxnx_row(v,l,p,v->n))return false;p+=hs;if(!sxnx_need(v,p,n,v->n))return false;size_t end=p+n;
 if(kind==0x0f){if(!SN_ROW(wpg_start,p,end))return false;}else if(kind==0x0e){if(!SN_ROW(wpg_palette,p,end))return false;unsigned first=sxnx_u16(v->p+p,false),last=sxnx_u16(v->p+p+2,false);if(last<first||!sxnx_table(v,&sxnx_rgb_palette_entry,p+4,last-first,end))return false;}else if(kind==0x0b){if(!SN_ROW(wpg_bitmap,p,end))return false;}p=end;}return true;}
bool sx_wordperfect_wpg_build(sxnx_view*v)
{
 return sxnx_wpg(v);
}
#undef SN_ROW
