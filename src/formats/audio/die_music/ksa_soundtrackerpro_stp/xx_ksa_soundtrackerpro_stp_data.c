/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Ksa Soundtrackerpro Stp data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_stp_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("positions_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("samples_offset","uint16",7,2,SX_OFFSET),
 SX_FIELD("fixes_count","uint8",9,1,SX_COUNT_PROP),
};
const sx_layout sxzxm_stp_header={UINT32_C(0x608A0044),"stp_header",sxzxm_stp_header_fields,SX_COUNT(sxzxm_stp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stp_identity_fields[]={
 SX_FIELD("identifier","char[28]",0,28,SX_NONE),
 SX_FIELD("title","char[25]",28,25,SX_NONE),
};
const sx_layout sxzxm_stp_identity={UINT32_C(0x608A0045),"stp_identity",sxzxm_stp_identity_fields,SX_COUNT(sxzxm_stp_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stp_positions_fields[]={
 SX_FIELD("position_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
};
const sx_layout sxzxm_stp_positions={UINT32_C(0x608A0046),"stp_positions",sxzxm_stp_positions_fields,SX_COUNT(sxzxm_stp_positions_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_stp(sx_context*c){
 uint8_t h[10],n;if(!sxzxm_read(c,0,h,10)||!SXZXM_ADD(c,stp_header,0))return false;unsigned pos=sxzxm16(h+1),pt=sxzxm16(h+3),op=sxzxm16(h+5),sp=sxzxm16(h+7),patterns=0;
 if(sxzxm_eq(c,10,"KSA SOFTWARE COMPILATION OF ",28)&&!sxzxm_opt(c,&sxzxm_stp_identity,10,1))return false;
 if(sxzxm_u8(c,pos,&n)){if(!sxzxm_opt(c,&sxzxm_stp_positions,pos,1)||!sxzxm_opt(c,&sxzxm_stp_position,pos+2U,n))return false;for(unsigned i=0;i<n;i++){uint8_t v;if(!sxzxm_u8(c,(uint64_t)pos+2+2U*i,&v)||v%6||v/6U>=32)break;if(v/6U+1>patterns)patterns=v/6U+1;}}
 if(!sxzxm_opt(c,&sxzxm_zx_pattern_channels,pt,patterns))return false;
 for(unsigned k=0;k<2;k++){unsigned tab=k?op:sp,count=k?16:15;if(!sxzxm_opt(c,k?&sxzxm_zx_ornament_offset:&sxzxm_zx_sample_offset,tab,count))return false;for(unsigned i=0;i<count;i++){uint16_t p;if(!sxzxm_u16(c,(uint64_t)tab+2U*i,&p))break;if(p>=10&&!sxzxm_object(c,p,k?11:10))return false;}}
 return true;
}
bool sx_ksa_soundtrackerpro_stp_build(sx_context*c)
{
 return sxzxm_stp(c);
}
