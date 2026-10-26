/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sony_psp_pbp data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_pbp_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("param_sfo_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("icon0_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("icon1_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("pic0_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("pic1_offset","uint32",24,4,SX_OFFSET),
 SX_FIELD("snd0_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("data_psp_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("data_psar_offset","uint32",36,4,SX_OFFSET),
};
const sx_layout sxgp_pbp_header={UINT32_C(0x60360016),"pbp_header",sxgp_pbp_header_fields,SX_COUNT(sxgp_pbp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_sfo_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("key_table_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("data_table_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",16,4,SX_COUNT_PROP),
};
const sx_layout sxgp_sfo_header={UINT32_C(0x60360017),"sfo_header",sxgp_sfo_header_fields,SX_COUNT(sxgp_sfo_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_sfo_entry_fields[]={
 SX_FIELD("key_offset","uint16",0,2,SX_OFFSET),
 SX_FIELD("data_format","uint16",2,2,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
 SX_FIELD("maximum_data_size","uint32",8,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sxgp_sfo_entry={UINT32_C(0x60360018),"sfo_entry",sxgp_sfo_entry_fields,SX_COUNT(sxgp_sfo_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_sfo_int32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxgp_sfo_int32={UINT32_C(0x60360037),"sfo_int32",sxgp_sfo_int32_fields,SX_COUNT(sxgp_sfo_int32_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_pbp(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,sf,stop,count,data;if(!SG_ROW(pbp_header,0,end)||!sxgp_word(v,8,4,false,&sf,end)||!sxgp_word(v,12,4,false,&stop,end)||!sxgp_span(v,sf,20,stop)||!SG_ROW(sfo_header,sf,stop)||!sxgp_word(v,sf+16,4,false,&count,stop)||count>256||!sxgp_table(v,&sxgp_sfo_entry,sf+20,count,stop)||!sxgp_word(v,sf+12,4,false,&data,stop))return false;
 if(data>stop-sf)return false;data+=sf;
 for(uint64_t i=0;i<count;i++){uint64_t type,off,p=sf+20+i*16;if(!sxgp_word(v,p+2,2,false,&type,stop)||!sxgp_word(v,p+12,4,false,&off,stop))return false;if(type==0x404){if(off>stop-data||!SG_ROW(sfo_int32,data+off,stop))return false;}}
 return true;}
bool sx_sony_psp_pbp_build(sxgp_view*v)
{
 return sxgp_pbp(v);
}
#undef SG_ROW
