/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Text data structures, moved out of the documentwire schema family. */
#include "../../xx_format_schema_documentwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdw_text_bom2_fields[]={
 SX_FIELD("byte_order_mark","uint8[2]",0,2,SX_SIGNATURE),
};
const sx_layout sxdw_text_bom2={0x60740054U,"documentwire_text_bom2",sxdw_text_bom2_fields,SX_COUNT(sxdw_text_bom2_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_bom3_fields[]={
 SX_FIELD("byte_order_mark","uint8[3]",0,3,SX_SIGNATURE),
};
const sx_layout sxdw_text_bom3={0x60740055U,"documentwire_text_bom3",sxdw_text_bom3_fields,SX_COUNT(sxdw_text_bom3_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_bom4_fields[]={
 SX_FIELD("byte_order_mark","uint8[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxdw_text_bom4={0x60740056U,"documentwire_text_bom4",sxdw_text_bom4_fields,SX_COUNT(sxdw_text_bom4_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_utf16le_fields[]={
 SX_FIELD("code_unit","uint16le",0,2,SX_NONE),
};
const sx_layout sxdw_text_utf16le={0x60740057U,"documentwire_text_utf16le",sxdw_text_utf16le_fields,SX_COUNT(sxdw_text_utf16le_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_utf16be_fields[]={
 SX_FIELD("code_unit","uint16be",0,2,SX_NONE),
};
const sx_layout sxdw_text_utf16be={0x60740058U,"documentwire_text_utf16be",sxdw_text_utf16be_fields,SX_COUNT(sxdw_text_utf16be_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_utf32le_fields[]={
 SX_FIELD("code_unit","uint32le",0,4,SX_NONE),
};
const sx_layout sxdw_text_utf32le={0x60740059U,"documentwire_text_utf32le",sxdw_text_utf32le_fields,SX_COUNT(sxdw_text_utf32le_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_utf32be_fields[]={
 SX_FIELD("code_unit","uint32be",0,4,SX_NONE),
};
const sx_layout sxdw_text_utf32be={0x6074005aU,"documentwire_text_utf32be",sxdw_text_utf32be_fields,SX_COUNT(sxdw_text_utf32be_fields),SX_LE};
static const xx_data_struct_field_desc sxdw_text_line_fields[]={
 SX_FIELD("text_line","utf8",0,0,SX_STRING),
};
const sx_layout sxdw_text_line={0x6074005bU,"documentwire_text_line",sxdw_text_line_fields,SX_COUNT(sxdw_text_line_fields),SX_LE};
static bool sxdw_text(sxdw_cursor*q)
{
 /* Read the common validated metadata; never downcast a factory wrapper. */
 const char*v=xx_format_get_version(q->c->f);unsigned width=1,bom=0;const sx_layout*l=NULL;
 if(v&&!xx_rt_strcmp(v,"UTF-16LE")){width=2;l=&sxdw_text_utf16le;}
 else if(v&&!xx_rt_strcmp(v,"UTF-16BE")){width=2;l=&sxdw_text_utf16be;}
 else if(v&&!xx_rt_strcmp(v,"UTF-32LE")){width=4;l=&sxdw_text_utf32le;}
 else if(v&&!xx_rt_strcmp(v,"UTF-32BE")){width=4;l=&sxdw_text_utf32be;}
 if(width==4&&q->n>=4&&((q->b[0]==255&&q->b[1]==254&&!q->b[2]&&!q->b[3])||(!q->b[0]&&!q->b[1]&&q->b[2]==254&&q->b[3]==255)))bom=4;
 else if(width==2&&q->n>=2&&((q->b[0]==255&&q->b[1]==254)||(q->b[0]==254&&q->b[1]==255)))bom=2;
 else if(width==1&&q->n>=3&&q->b[0]==239&&q->b[1]==187&&q->b[2]==191)bom=3;
 if(bom&&!sxdw_emit(q,bom==2?&sxdw_text_bom2:bom==3?&sxdw_text_bom3:&sxdw_text_bom4,0,bom))return false;q->p=bom;
 if(width>1){while(q->p<q->n&&q->c->count<32000){if(!sxdw_emit(q,l,q->p,width))return false;q->p+=width;}}
 else{int64_t a,e;while(q->c->count<32000&&sxdw_line(q,&a,&e))if(!sxdw_value(q,&sxdw_text_line,a,q->p-a))return false;}
 return !xx_pd_is_stopped(q->c->pd);
}
bool sx_text_build(sxdw_cursor*q)
{
 return sxdw_text(q);
}
