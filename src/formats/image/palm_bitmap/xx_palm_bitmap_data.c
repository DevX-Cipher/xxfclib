/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PALM BITMAP data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_palm_bitmap_header_fields[]={
 SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("row_bytes","uint16",4,2,SX_SIZE),
 SX_FIELD("flags","uint16",6,2,SX_FLAGS),
 SX_FIELD("pixel_bits","uint8",8,1,SX_NONE),
 SX_FIELD("version","uint8",9,1,SX_ID),
 SX_FIELD("next_bitmap_words","uint16",10,2,SX_NONE),
 SX_FIELD("transparent_index","uint8",12,1,SX_ID),
 SX_FIELD("compression","uint8",13,1,SX_ID),
 SX_FIELD("reserved","uint16",14,2,SX_RESERVED),
};
const sx_layout sxnx_palm_bitmap_header={UINT32_C(0x60320020),"palm_bitmap_header",sxnx_palm_bitmap_header_fields,SX_COUNT(sxnx_palm_bitmap_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_palm_palette_header_fields[]={
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxnx_palm_palette_header={UINT32_C(0x60320021),"palm_palette_header",sxnx_palm_palette_header_fields,SX_COUNT(sxnx_palm_palette_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_palm_palette_entry_fields[]={
 SX_FIELD("index","uint8",0,1,SX_ID),
 SX_FIELD("red","uint8",1,1,SX_NONE),
 SX_FIELD("green","uint8",2,1,SX_NONE),
 SX_FIELD("blue","uint8",3,1,SX_NONE),
};
const sx_layout sxnx_palm_palette_entry={UINT32_C(0x60320022),"palm_palette_entry",sxnx_palm_palette_entry_fields,SX_COUNT(sxnx_palm_palette_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_palm_compressed_header_fields[]={
 SX_FIELD("packed_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxnx_palm_compressed_header={UINT32_C(0x60320023),"palm_compressed_header",sxnx_palm_compressed_header_fields,SX_COUNT(sxnx_palm_compressed_header_fields),SX_BE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_palm(sxnx_view*v)
{if(!SN_ROW(palm_bitmap_header,0,v->n))return false;size_t p=16;unsigned flags=sxnx_u16(v->p+6,true);if(v->p[8]==8&&(flags&0x4000)){if(!SN_ROW(palm_palette_header,p,v->n))return false;unsigned n=sxnx_u16(v->p+p,true);p+=2;if(!sxnx_table(v,&sxnx_palm_palette_entry,p,n,v->n))return false;p+=4*(size_t)n;}return !(flags&0x8000)||SN_ROW(palm_compressed_header,p,v->n);}
bool sx_palm_bitmap_build(sxnx_view*v)
{
 return sxnx_palm(v);
}
#undef SN_ROW
