/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * xpm data structures, moved out of the textimages schema family. */
#include "../../xx_format_schema_textimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxti_color_key_fields[]={
 SX_FIELD("color_key","char",0,0,SX_STRING),
};
const sx_layout sxti_color_key={0x6041000bU,"textimage_color_key",sxti_color_key_fields,SX_COUNT(sxti_color_key_fields),SX_LE};
static const xx_data_struct_field_desc sxti_color_specification_fields[]={
 SX_FIELD("color_specification","char",0,0,SX_STRING),
};
const sx_layout sxti_color_specification={0x6041000cU,"textimage_color_specification",sxti_color_specification_fields,SX_COUNT(sxti_color_specification_fields),SX_LE};
static const xx_data_struct_field_desc sxti_characters_per_pixel_fields[]={
 SX_FIELD("characters_per_pixel","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_characters_per_pixel={0x60410025U,"textimage_characters_per_pixel",sxti_characters_per_pixel_fields,SX_COUNT(sxti_characters_per_pixel_fields),SX_LE};
#define TI_VALUE(n,e,v) do{if(!sxti_value(q,&sxti_##n,(e),(v)))return false;}while(0)
#define TI_EMIT(n,a,z) do{if(!sxti_emit(q,&sxti_##n,(a),(z)))return false;}while(0)
static bool sxti_xpm_string(sxti_cursor*q,int64_t*a,int64_t*z)
{
 while(sxti_cskip(q)&&q->p<q->n){if(q->b[q->p]=='"'){q->p++;*a=q->p;while(q->p<q->n&&q->b[q->p]!='"'){if(q->b[q->p]=='\\'||q->b[q->p]<32)return false;q->p++;}if(q->p==q->n)return false;*z=q->p-*a;q->p++;return true;}q->p++;}return false;
}
static bool sxti_xpm(sxti_cursor*q)
{
 int64_t a,z;if(!sxti_xpm_string(q,&a,&z))return false;int64_t next=q->p,end=a+z;uint64_t w,h,colors,cpp;q->p=a;TI_VALUE(width,end,&w);TI_VALUE(height,end,&h);TI_VALUE(color_count,end,&colors);TI_VALUE(characters_per_pixel,end,&cpp);while(q->p<end&&sxti_space(q->b[q->p]))q->p++;if(q->p<end){TI_VALUE(hotspot_x,end,NULL);TI_VALUE(hotspot_y,end,NULL);}q->p=next;
 if(!w||!h||w>4096||h>4096||!colors||colors>4096||(cpp!=1&&cpp!=2))return false;
 for(uint64_t i=0;i<colors;i++){if(!sxti_xpm_string(q,&a,&z)||z<(int64_t)cpp+3)return false;TI_EMIT(color_key,a,(int64_t)cpp);int64_t p=a+(int64_t)cpp;while(p<a+z&&sxti_space(q->b[p]))p++;if(p==a+z||q->b[p++]!='c')return false;while(p<a+z&&sxti_space(q->b[p]))p++;TI_EMIT(color_specification,p,a+z-p);}
 /* Pixel strings are original encoded keys. Their meaning is in the color table. */
 return true;
}
bool sx_xpm_build(sxti_cursor*q)
{
 return sxti_xpm(q);
}
#undef TI_VALUE
#undef TI_EMIT
