/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * iff ilbm data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_ilbm_form_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("form_size","uint32",4,4,SX_SIZE),
    SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
const sx_layout sxrm_ilbm_form = {UINT32_C(0x601d0023),"ilbm_form",sxrm_ilbm_form_fields,SX_COUNT(sxrm_ilbm_form_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_ilbm_chunk_fields[] = {
    SX_FIELD("chunk_type","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxrm_ilbm_chunk = {UINT32_C(0x601d0024),"ilbm_chunk",sxrm_ilbm_chunk_fields,SX_COUNT(sxrm_ilbm_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_ilbm_bitmap_header_fields[] = {
    SX_FIELD("width","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("height","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("x","int16",4,2,SX_NONE),
    SX_FIELD("y","int16",6,2,SX_NONE),
    SX_FIELD("planes","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("masking","uint8",9,1,SX_ID),
    SX_FIELD("compression","uint8",10,1,SX_ID),
    SX_FIELD("padding","uint8",11,1,SX_RESERVED),
    SX_FIELD("transparent_color","uint16",12,2,SX_ID),
    SX_FIELD("x_aspect","uint8",14,1,SX_NONE),
    SX_FIELD("y_aspect","uint8",15,1,SX_NONE),
    SX_FIELD("page_width","int16",16,2,SX_COUNT_PROP),
    SX_FIELD("page_height","int16",18,2,SX_COUNT_PROP),
};
const sx_layout sxrm_ilbm_bitmap_header = {UINT32_C(0x601d0025),"ilbm_bitmap_header",sxrm_ilbm_bitmap_header_fields,SX_COUNT(sxrm_ilbm_bitmap_header_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_ilbm_palette_entry_fields[] = {
    SX_FIELD("red","uint8",0,1,SX_NONE),
    SX_FIELD("green","uint8",1,1,SX_NONE),
    SX_FIELD("blue","uint8",2,1,SX_NONE),
};
const sx_layout sxrm_ilbm_palette_entry = {UINT32_C(0x601d0026),"ilbm_palette_entry",sxrm_ilbm_palette_entry_fields,SX_COUNT(sxrm_ilbm_palette_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_ilbm_view_mode_fields[] = {
    SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxrm_ilbm_view_mode = {UINT32_C(0x601d0027),"ilbm_view_mode",sxrm_ilbm_view_mode_fields,SX_COUNT(sxrm_ilbm_view_mode_fields),SX_BE};
static bool sxrm_ilbm(sx_context *c)
{
 uint8_t h[12];if(!sxrm_read(c,0,h,12)||xx_rt_memcmp(h,"FORM",4)||xx_rt_memcmp(h+8,"ILBM",4)||!sxrm_add(c,&sxrm_ilbm_form,0))return false;
 uint64_t end=(uint64_t)sxrm32(h+4,true)+8,p=12;if(end>(uint64_t)c->size)end=(uint64_t)c->size;
 for(unsigned step=0;p<end&&step<4096;step++){if(end-p<8||!sxrm_read(c,p,h,8))break;uint32_t n=sxrm32(h+4,true);if(n>end-p-8)break;if(!sxrm_add(c,&sxrm_ilbm_chunk,p))return false;
  if(!xx_rt_memcmp(h,"BMHD",4)&&n>=20){if(!sxrm_add(c,&sxrm_ilbm_bitmap_header,p+8))return false;}
  else if(!xx_rt_memcmp(h,"CMAP",4)&&n/3<=256&&n>=3){if(!sxrm_table(c,&sxrm_ilbm_palette_entry,p+8,n/3))return false;}
  else if(!xx_rt_memcmp(h,"CAMG",4)&&n>=4){if(!sxrm_add(c,&sxrm_ilbm_view_mode,p+8))return false;}p+=8+(uint64_t)n+(n&1U);
 }return !c->failed;
}
bool sx_iff_ilbm_build(sx_context*c)
{
 return sxrm_ilbm(c);
}
