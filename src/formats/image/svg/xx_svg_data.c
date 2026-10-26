/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * svg data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_xml_element_fields[]={
 SX_FIELD("xml_element","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_xml_element={0x60710018U,"textwire_xml_element",sxtw_xml_element_fields,SX_COUNT(sxtw_xml_element_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_xml_attribute_fields[]={
 SX_FIELD("xml_attribute","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_xml_attribute={0x60710019U,"textwire_xml_attribute",sxtw_xml_attribute_fields,SX_COUNT(sxtw_xml_attribute_fields),SX_LE};
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
/* SVG native validation is broader than XML grammar. A bounded physical tag
 * scan exposes quoted attributes without claiming reconstructed XML semantics. */
static bool sxtw_svg(sxtw_cursor*q)
{
 int64_t p=0;while(p<q->n){if(q->c->count>=32000)return true;if(xx_pd_is_stopped(q->c->pd))return false;if(q->b[p]!='<'){p++;continue;}int64_t start=p++;
  if(p<q->n&&(q->b[p]=='!'||q->b[p]=='?')){unsigned quote=0;while(p<q->n){unsigned c=q->b[p++];if(quote){if(c==quote)quote=0;}else if(c=='"'||c=='\'')quote=c;else if(c=='>')break;}TW_EMIT(text,start,p-start);continue;}
  if(p<q->n&&q->b[p]=='/')p++;int64_t a=p;while(p<q->n&&!sxtw_space(q->b[p])&&q->b[p]!='/'&&q->b[p]!='>')p++;if(p==a)continue;TW_EMIT(xml_element,a,p-a);
  while(p<q->n&&q->b[p]!='>'){
   while(p<q->n&&(sxtw_space(q->b[p])||q->b[p]=='/'))p++;if(p==q->n||q->b[p]=='>')break;a=p;while(p<q->n&&!sxtw_space(q->b[p])&&q->b[p]!='='&&q->b[p]!='>')p++;int64_t z=p-a;while(p<q->n&&sxtw_space(q->b[p]))p++;if(!z||p==q->n||q->b[p++]!='=')return true;while(p<q->n&&sxtw_space(q->b[p]))p++;if(p==q->n||(q->b[p]!='"'&&q->b[p]!='\''))return true;unsigned quote=q->b[p++];int64_t v=p;while(p<q->n&&q->b[p]!=quote)p++;if(p==q->n)return true;TW_EMIT(xml_attribute,a,z);TW_EMIT(field_value,v,p-v);p++;if(q->c->count>=32000)return true;
  }if(p<q->n)p++;
 }return true;
}
bool sx_svg_build(sxtw_cursor*q)
{
 return sxtw_svg(q);
}
#undef TW_EMIT
