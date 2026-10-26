/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * unifont_hex data structures, moved out of the textimages schema family. */
#include "../../xx_format_schema_textimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxti_unicode_codepoint_fields[]={
 SX_FIELD("unicode_codepoint","ascii_hex",0,0,SX_ID),
};
const sx_layout sxti_unicode_codepoint={0x60410055U,"textimage_unicode_codepoint",sxti_unicode_codepoint_fields,SX_COUNT(sxti_unicode_codepoint_fields),SX_LE};
#define TI_EMIT(n,a,z) do{if(!sxti_emit(q,&sxti_##n,(a),(z)))return false;}while(0)
static bool sxti_unifont(sxti_cursor*q)
{
 int64_t a,end;unsigned lines=0;while(sxti_line(q,&a,&end,false)){if(q->c->count>=32000)return true;int64_t colon=a;while(colon<end&&q->b[colon]!=':')colon++;if(colon-a<4||colon-a>6||(end-colon-1!=32&&end-colon-1!=64))return false;TI_EMIT(unicode_codepoint,a,colon-a);for(int64_t i=colon+1;i<end;i+=2)TI_EMIT(bitmap_byte,i,2);lines++;}return lines>0;
}
bool sx_unifont_hex_build(sxti_cursor*q)
{
 return sxti_unifont(q);
}
#undef TI_EMIT
