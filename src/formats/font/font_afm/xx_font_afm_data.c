/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * font_afm data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_character_code_hex_fields[]={
 SX_FIELD("character_code_hex","ascii_hex",0,0,SX_ID),
};
const sx_layout sxmt_character_code_hex={0x60520060U,"modeltext_character_code_hex",sxmt_character_code_hex_fields,SX_COUNT(sxmt_character_code_hex_fields),SX_LE};
#define MT_VALUE(n,e,v) do{if(!sxmt_value(q,&sxmt_##n,(e),(v)))return false;}while(0)
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)
static bool sxmt_afm(sxmt_cursor*q){int64_t a,e;while(sxmt_line(q,&a,&e,false)){if(q->c->count>=32000)return true;int64_t next=q->p;for(int64_t start=a;start<e;){int64_t stop=start;while(stop<e&&q->b[stop]!=';')stop++;q->p=start;int64_t k,z;if(!sxmt_token(q,stop,&k,&z,false)){start=stop+1;continue;}MT_EMIT(keyword,k,z);const sx_layout*l=&sxmt_string_value;
 if(sxmt_eq(q,k,z,"Comment")){/* comments can contain semicolons */if(!sxmt_remainder(q,l,e))return false;break;}
 if(sxmt_eq(q,k,z,"StartFontMetrics"))l=&sxmt_version;
 else if(sxmt_eq(q,k,z,"C"))l=&sxmt_codepoint;
 else if(sxmt_eq(q,k,z,"CH")){while(q->p<stop&&sxmt_space(q->b[q->p]))q->p++;if(q->p<stop&&q->b[q->p]=='<'){int64_t n=++q->p;while(q->p<stop&&q->b[q->p]!='>')q->p++;MT_EMIT(character_code_hex,n,q->p-n);}start=stop+1;continue;}
 else if(sxmt_eq(q,k,z,"N"))l=&sxmt_glyph_name;
 else if(sxmt_eq(q,k,z,"StartCharMetrics")||sxmt_eq(q,k,z,"StartKernPairs")||sxmt_eq(q,k,z,"StartKernPairs0")||sxmt_eq(q,k,z,"StartKernPairs1")||sxmt_eq(q,k,z,"StartTrackKern")||sxmt_eq(q,k,z,"StartComposites")||sxmt_eq(q,k,z,"StartDirection"))l=&sxmt_integer_value;
 else if(sxmt_eq(q,k,z,"WX")||sxmt_eq(q,k,z,"WY")||sxmt_eq(q,k,z,"W0X")||sxmt_eq(q,k,z,"W0Y")||sxmt_eq(q,k,z,"W1X")||sxmt_eq(q,k,z,"W1Y")||sxmt_eq(q,k,z,"W")||sxmt_eq(q,k,z,"W0")||sxmt_eq(q,k,z,"W1")||sxmt_eq(q,k,z,"B")||sxmt_eq(q,k,z,"VV")||sxmt_eq(q,k,z,"FontBBox")||sxmt_eq(q,k,z,"UnderlinePosition")||sxmt_eq(q,k,z,"UnderlineThickness")||sxmt_eq(q,k,z,"ItalicAngle")||sxmt_eq(q,k,z,"CapHeight")||sxmt_eq(q,k,z,"XHeight")||sxmt_eq(q,k,z,"Ascender")||sxmt_eq(q,k,z,"Descender")||sxmt_eq(q,k,z,"StdHW")||sxmt_eq(q,k,z,"StdVW")||sxmt_eq(q,k,z,"CharWidth"))l=&sxmt_font_metric;
 else if(sxmt_eq(q,k,z,"KPX")||sxmt_eq(q,k,z,"KPY")||sxmt_eq(q,k,z,"KP")){MT_VALUE(glyph_name,stop,NULL);MT_VALUE(glyph_name,stop,NULL);l=&sxmt_font_metric;}
 else if(sxmt_eq(q,k,z,"TrackKern")){MT_VALUE(integer_value,stop,NULL);l=&sxmt_font_metric;}
 else if(sxmt_eq(q,k,z,"CC")){MT_VALUE(glyph_name,stop,NULL);l=&sxmt_property_total;}
 else if(sxmt_eq(q,k,z,"PCC")){MT_VALUE(glyph_name,stop,NULL);l=&sxmt_font_metric;}
 if(l==&sxmt_string_value){if(!sxmt_remainder(q,l,stop))return false;}else if(!sxmt_many(q,l,stop))return false;start=stop+1;}q->p=next;}return true;}
bool sx_font_afm_build(sxmt_cursor*q)
{
 return sxmt_afm(q);
}
#undef MT_VALUE
#undef MT_EMIT
