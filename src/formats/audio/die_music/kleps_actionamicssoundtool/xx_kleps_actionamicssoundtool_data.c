/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * kleps_actionamicssoundtool data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_ast_banner_fields[]={
 SX_FIELD("signature","bytes",0,22,SX_SIGNATURE),
 SX_FIELD("unknown","bytes",22,2,SX_NONE),
 SX_FIELD("version_text","char[3]",24,3,SX_NONE),
};
const sx_layout sxnextm_ast_banner={UINT32_C(0x608B000C),"ast_banner",sxnextm_ast_banner_fields,SX_COUNT(sxnextm_ast_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ast_module_size_fields[]={
 SX_FIELD("module_bytes","uint32",0,4,SX_SIZE),
};
const sx_layout sxnextm_ast_module_size={UINT32_C(0x608B000D),"ast_module_size",sxnextm_ast_module_size_fields,SX_COUNT(sxnextm_ast_module_size_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_ast_instrument_fields[]={
 SX_FIELD("sample_list_index","uint8",0,1,SX_ID),
 SX_FIELD("sample_value_count","uint8",1,1,SX_COUNT_PROP),
 SX_FIELD("sample_start_counter_delta","uint8",2,1,SX_NONE),
 SX_FIELD("sample_counter_end","uint8",3,1,SX_NONE),
 SX_FIELD("arpeggio_list_index","uint8",4,1,SX_ID),
 SX_FIELD("arpeggio_value_count","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("arpeggio_start_counter_delta","uint8",6,1,SX_NONE),
 SX_FIELD("arpeggio_counter_end","uint8",7,1,SX_NONE),
 SX_FIELD("frequency_list_index","uint8",8,1,SX_ID),
 SX_FIELD("frequency_value_count","uint8",9,1,SX_COUNT_PROP),
 SX_FIELD("frequency_start_counter_delta","uint8",10,1,SX_NONE),
 SX_FIELD("frequency_counter_end","uint8",11,1,SX_NONE),
 SX_FIELD("portamento_increment","int8",12,1,SX_NONE),
 SX_FIELD("portamento_delay","uint8",13,1,SX_NONE),
 SX_FIELD("note_transpose","int8",14,1,SX_NONE),
 SX_FIELD("unknown0","uint8",15,1,SX_NONE),
 SX_FIELD("attack_end_volume","uint8",16,1,SX_NONE),
 SX_FIELD("attack_speed","uint8",17,1,SX_NONE),
 SX_FIELD("decay_end_volume","uint8",18,1,SX_NONE),
 SX_FIELD("decay_speed","uint8",19,1,SX_NONE),
 SX_FIELD("sustain_delay","uint8",20,1,SX_NONE),
 SX_FIELD("release_end_volume","uint8",21,1,SX_NONE),
 SX_FIELD("release_speed","uint8",22,1,SX_NONE),
 SX_FIELD("unknown_tail","bytes",23,9,SX_NONE),
};
const sx_layout sxnextm_ast_instrument={UINT32_C(0x608B000E),"ast_instrument",sxnextm_ast_instrument_fields,SX_COUNT(sxnextm_ast_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ast_subsong_fields[]={
 SX_FIELD("first_position","uint8",0,1,SX_ID),
 SX_FIELD("last_position","uint8",1,1,SX_ID),
 SX_FIELD("loop_position","uint8",2,1,SX_ID),
 SX_FIELD("speed","uint8",3,1,SX_NONE),
};
const sx_layout sxnextm_ast_subsong={UINT32_C(0x608B000F),"ast_subsong",sxnextm_ast_subsong_fields,SX_COUNT(sxnextm_ast_subsong_fields),SX_LE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
static bool sxnextm_ast(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,len[15],at[15],p=62;
 if(!sxnextm_eq(v,62,"ACTIONAMICS SOUND TOOL",22,e)||!NX_ROW(ast_header,0,e)||!NX_ROW(ast_banner,62,e))return false;
 for(unsigned i=0;i<15;i++){if(!sxnextm_be(v,2+4*i,4,&len[i],e)||!sxnextm_span(v,p,len[i],e))return false;at[i]=p;p+=len[i];}
 if(len[0]<27||len[1]<4||len[2]!=len[3]||len[2]!=len[4]||len[2]%4||len[5]%32||len[6]%16||len[7]%16||len[8]%16||len[11]%4||len[13]%64||len[14]%2||!NX_ROW(ast_module_size,at[1],at[1]+len[1]))return false;
 if(!sxnextm_table(v,&sxnextm_u8,at[2],len[2],e)||!sxnextm_table(v,&sxnextm_i8,at[3],len[3]+len[4],e)||!sxnextm_table(v,&sxnextm_ast_instrument,at[5],len[5]/32,e))return false;
 for(unsigned i=6;i<=8;i++)if(!sxnextm_table(v,&sxnextm_i8,at[i],len[i],e))return false;
 if(!sxnextm_table(v,&sxnextm_ast_subsong,at[11],len[11]/4,e)||!sxnextm_table(v,&sxnextm_ast_sample,at[13],len[13]/64,e)||!sxnextm_table(v,&sxnextm_offset16,at[14],len[14]/2,e))return false;
 /* Track opcodes and sample waveforms remain raw; each pointer remains a
    physical field without assigning decoded or runtime coordinates. */
 return true;}
bool sx_kleps_actionamicssoundtool_build(sxnextm_view*v)
{
 return sxnextm_ast(v);
}
#undef NX_ROW
