/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RISC OS sprite file (filetype &FF9) data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_sprite_area_fields[]={
 SX_FIELD("sprite_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("first_sprite_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("free_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxnx_sprite_area={UINT32_C(0x6032005E),"sprite_area",sxnx_sprite_area_fields,SX_COUNT(sxnx_sprite_area_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_sprite_header_fields[]={
 SX_FIELD("next_sprite_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name","char[12]",4,12,SX_STRING),
 SX_FIELD("width_words_minus_one","uint32",16,4,SX_NONE),
 SX_FIELD("height_minus_one","uint32",20,4,SX_NONE),
 SX_FIELD("first_used_bit","uint32",24,4,SX_NONE),
 SX_FIELD("last_used_bit","uint32",28,4,SX_NONE),
 SX_FIELD("image_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("mask_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("mode","uint32",40,4,SX_FLAGS),
};
const sx_layout sxnx_sprite_header={UINT32_C(0x6032005F),"sprite_header",sxnx_sprite_header_fields,SX_COUNT(sxnx_sprite_header_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_sprite_palette_fields[]={
 SX_FIELD("color1","uint32",0,4,SX_NONE),
 SX_FIELD("color2","uint32",4,4,SX_NONE),
};
const sx_layout sxnx_sprite_palette={UINT32_C(0x60320060),"sprite_palette",sxnx_sprite_palette_fields,SX_COUNT(sxnx_sprite_palette_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_sprite(sxnx_view*v)
{if(!SN_ROW(sprite_area,0,v->n))return false;unsigned n=sxnx_u32(v->p,false),start=sxnx_u32(v->p+4,false);if(start<4||n>10000)return false;size_t p=start-4;
 for(unsigned i=0;i<n;i++){if(!SN_ROW(sprite_header,p,v->n))return false;unsigned z=sxnx_u32(v->p+p,false),img=sxnx_u32(v->p+p+32,false);if(z<44||img<44||img>z||!sxnx_need(v,p,z,v->n))return false;if(!sxnx_table(v,&sxnx_sprite_palette,p+44,(img-44)/8,p+img))return false;p+=z;}return true;}
bool sx_risc_os_sprite_build(sxnx_view*v)
{
 return sxnx_sprite(v);
}
#undef SN_ROW
