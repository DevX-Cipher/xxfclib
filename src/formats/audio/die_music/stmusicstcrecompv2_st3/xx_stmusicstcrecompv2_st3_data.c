/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Stmusicstcrecompv2 St3 data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_zx_positions_count_fields[]={
 SX_FIELD("position_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxzxm_zx_positions_count={UINT32_C(0x608A0009),"zx_positions_count",sxzxm_zx_positions_count_fields,SX_COUNT(sxzxm_zx_positions_count_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("positions_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("samples_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",7,2,SX_OFFSET),
};
const sx_layout sxzxm_st3_header={UINT32_C(0x608A003E),"st3_header",sxzxm_st3_header_fields,SX_COUNT(sxzxm_st3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_identity_fields[]={
 SX_FIELD("identifier","char[28]",0,28,SX_NONE),
 SX_FIELD("title","char[27]",28,27,SX_NONE),
};
const sx_layout sxzxm_st3_identity={UINT32_C(0x608A003F),"st3_identity",sxzxm_st3_identity_fields,SX_COUNT(sxzxm_st3_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_object_table_fields[]={
 SX_FIELD("object_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxzxm_st3_object_table={UINT32_C(0x608A0041),"st3_object_table",sxzxm_st3_object_table_fields,SX_COUNT(sxzxm_st3_object_table_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_st3_sample_line_fields[]={
 SX_FIELD("vibrato","int16",0,2,SX_NONE),
 SX_FIELD("level_mask","uint8",2,1,SX_FLAGS),
 SX_FIELD("noise","uint8",3,1,SX_NONE),
};
const sx_layout sxzxm_st3_sample_line={UINT32_C(0x608A0043),"st3_sample_line",sxzxm_st3_sample_line_fields,SX_COUNT(sxzxm_st3_sample_line_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_st3(sx_context*c){
 uint8_t h[9],n;if(!sxzxm_read(c,0,h,9)||!SXZXM_ADD(c,st3_header,0))return false;unsigned pos=sxzxm16(h+1),sp=sxzxm16(h+3),op=sxzxm16(h+5),pt=sxzxm16(h+7),patterns=0;
 bool id=sxzxm_eq(c,9,"KSA SOFTWARE COMPILATION OF ",28);
 if(id&&!sxzxm_opt(c,&sxzxm_st3_identity,9,1))return false;
 uint16_t first;unsigned origin=id?64:9,base=0;bool have_base=sxzxm_u16(c,(uint64_t)sp+1,&first)&&first>=origin;if(have_base)base=first-origin;
 if(sxzxm_u8(c,pos,&n)){if(!SXZXM_ADD(c,zx_positions_count,pos)||!sxzxm_opt(c,&sxzxm_st3_position,pos+1U,n))return false;for(unsigned i=0;i<n;i++){uint8_t v;if(!sxzxm_u8(c,(uint64_t)pos+2+2U*i,&v)||v%6||v/6U>=32)break;if(v/6U+1>patterns)patterns=v/6U+1;}}
 if(!sxzxm_opt(c,&sxzxm_zx_pattern_channels,pt,patterns))return false;
 for(unsigned k=0;k<2;k++){unsigned tab=k?op:sp;if(!sxzxm_u8(c,tab,&n)||n>16)continue;if(!SXZXM_ADD(c,st3_object_table,tab)||!sxzxm_opt(c,base?(k?&sxzxm_zx_ornament_address:&sxzxm_zx_sample_address):(k?&sxzxm_zx_ornament_offset:&sxzxm_zx_sample_offset),tab+1U,n))return false;
  for(unsigned i=0;i<n;i++){uint16_t p;if(!sxzxm_u16(c,(uint64_t)tab+1+2U*i,&p))break;if(!have_base||p<base||p-base<origin)continue;p=(uint16_t)(p-base);if(k){if(!sxzxm_opt(c,&sxzxm_zx_ornament_step,p,32))return false;}else if(sxzxm_span(c,p,2)&&(!SXZXM_ADD(c,st3_sample,p)||!sxzxm_opt(c,&sxzxm_st3_sample_line,p+2U,32)))return false;}}
 return true;
}
bool sx_stmusicstcrecompv2_st3_build(sx_context*c)
{
 return sxzxm_st3(c);
}
