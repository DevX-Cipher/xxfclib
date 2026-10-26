/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Bzyk Soundtracker Stc Zxs data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_stc_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("positions_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("ornaments_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("patterns_offset","uint16",5,2,SX_OFFSET),
 SX_FIELD("identifier","char[18]",7,18,SX_NONE),
 SX_FIELD("declared_size","uint16",25,2,SX_SIZE),
};
const sx_layout sxzxm_stc_header={UINT32_C(0x608A0036),"stc_header",sxzxm_stc_header_fields,SX_COUNT(sxzxm_stc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_position_fields[]={
 SX_FIELD("pattern_number","uint8",0,1,SX_NONE),
 SX_FIELD("transposition","int8",1,1,SX_NONE),
};
const sx_layout sxzxm_stc_position={UINT32_C(0x608A0038),"stc_position",sxzxm_stc_position_fields,SX_COUNT(sxzxm_stc_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_pattern_fields[]={
 SX_FIELD("pattern_number","uint8",0,1,SX_NONE),
 SX_FIELD("channel_a_offset","uint16",1,2,SX_OFFSET),
 SX_FIELD("channel_b_offset","uint16",3,2,SX_OFFSET),
 SX_FIELD("channel_c_offset","uint16",5,2,SX_OFFSET),
};
const sx_layout sxzxm_stc_pattern={UINT32_C(0x608A0039),"stc_pattern",sxzxm_stc_pattern_fields,SX_COUNT(sxzxm_stc_pattern_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_sample_prefix_fields[]={
 SX_FIELD("sample_number","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_stc_sample_prefix={UINT32_C(0x608A003A),"stc_sample_prefix",sxzxm_stc_sample_prefix_fields,SX_COUNT(sxzxm_stc_sample_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_sample_line_fields[]={
 SX_FIELD("effect_high_volume","uint8",0,1,SX_FLAGS),
 SX_FIELD("noise_masks","uint8",1,1,SX_FLAGS),
 SX_FIELD("effect_low","uint8",2,1,SX_NONE),
};
const sx_layout sxzxm_stc_sample_line={UINT32_C(0x608A003B),"stc_sample_line",sxzxm_stc_sample_line_fields,SX_COUNT(sxzxm_stc_sample_line_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_sample_loop_fields[]={
 SX_FIELD("loop_index","uint8",0,1,SX_NONE),
 SX_FIELD("loop_length","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxzxm_stc_sample_loop={UINT32_C(0x608A003C),"stc_sample_loop",sxzxm_stc_sample_loop_fields,SX_COUNT(sxzxm_stc_sample_loop_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_stc_ornament_prefix_fields[]={
 SX_FIELD("ornament_number","uint8",0,1,SX_NONE),
};
const sx_layout sxzxm_stc_ornament_prefix={UINT32_C(0x608A003D),"stc_ornament_prefix",sxzxm_stc_ornament_prefix_fields,SX_COUNT(sxzxm_stc_ornament_prefix_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_stc(sx_context*c){
 uint8_t h[27],n;if(!sxzxm_read(c,0,h,27)||!SXZXM_ADD(c,stc_header,0))return false;unsigned pos=sxzxm16(h+1),orn=sxzxm16(h+3),pat=sxzxm16(h+5);
 if(sxzxm_u8(c,pos,&n)&&(!SXZXM_ADD(c,stc_positions,pos)||!sxzxm_opt(c,&sxzxm_stc_position,pos+1U,(unsigned)n+1)))return false;
 unsigned before=pos;if(orn>=27&&orn<before)before=orn;if(pat>=27&&pat<before)before=pat;
 if(before>=27){unsigned sc=(before-27)/99;if(sc>16)sc=16;for(unsigned i=0;i<sc;i++){uint64_t p=27+99U*i;if(!SXZXM_ADD(c,stc_sample_prefix,p)||!sxzxm_opt(c,&sxzxm_stc_sample_line,p+1,32)||!SXZXM_ADD(c,stc_sample_loop,p+97))return false;}}
 if(pat>=orn){unsigned oc=(pat-orn)/33;if(oc>16)oc=16;for(unsigned i=0;i<oc;i++){uint64_t p=(uint64_t)orn+33U*i;if(!sxzxm_span(c,p,33))break;if(!SXZXM_ADD(c,stc_ornament_prefix,p)||!sxzxm_opt(c,&sxzxm_zx_ornament_step,p+1,32))return false;}}
 for(unsigned i=0;i<32;i++){uint64_t p=(uint64_t)pat+7U*i;if(!sxzxm_u8(c,p,&n))break;if(n==255){if(!SXZXM_ADD(c,zx_marker,p))return false;break;}if(!sxzxm_span(c,p,7))break;if(!SXZXM_ADD(c,stc_pattern,p))return false;}
 return true;
}
bool sx_bzyk_soundtracker_stc_zxs_build(sx_context*c)
{
 return sxzxm_stc(c);
}
