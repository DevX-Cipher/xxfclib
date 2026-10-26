/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PCOMM OS/2 data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_pcomm_literal_fields[]={
 SX_FIELD("control","uint8",0,1,SX_NONE),
};
const sx_layout sxarm_pcomm_literal={UINT32_C(0x607c0016),"pcomm_literal",sxarm_pcomm_literal_fields,SX_COUNT(sxarm_pcomm_literal_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_pcomm_near_match_fields[]={
 SX_FIELD("length_and_distance_high","uint8",0,1,SX_NONE),
 SX_FIELD("distance_low","uint8",1,1,SX_NONE),
};
const sx_layout sxarm_pcomm_near_match={UINT32_C(0x607c0017),"pcomm_near_match",sxarm_pcomm_near_match_fields,SX_COUNT(sxarm_pcomm_near_match_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_pcomm_far_match_fields[]={
 SX_FIELD("length_code","uint8",0,1,SX_NONE),
 SX_FIELD("decoded_block_source","uint16",1,2,SX_OFFSET),
};
const sx_layout sxarm_pcomm_far_match={UINT32_C(0x607c0018),"pcomm_far_match",sxarm_pcomm_far_match_fields,SX_COUNT(sxarm_pcomm_far_match_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_pcomm_block_end_fields[]={
 SX_FIELD("end_code","uint8",0,1,SX_ID),
};
const sx_layout sxarm_pcomm_block_end={UINT32_C(0x607c0019),"pcomm_block_end",sxarm_pcomm_block_end_fields,SX_COUNT(sxarm_pcomm_block_end_fields),SX_LE};
static bool sxarm_pcomm(sx_context*c){uint8_t gate[2];if(c->size<4||!sxarm_read(c,0,gate,1)||gate[0]<0xe1||!sxarm_read(c,(uint64_t)c->size-2,gate,2)||gate[0]!=0xe0||gate[1]!=0xe0)return false;uint64_t p=0;while(p<(uint64_t)c->size){uint64_t b;if(!sxarm_word(c,p,1,false,&b))return false;if(b==224){if(!sxarm_add(c,&sxarm_pcomm_block_end,p++))return false;}else if(b>=225){if(!sxarm_add(c,&sxarm_pcomm_literal,p)||!sxarm_span(c,p+1,b-224))return false;p+=1+b-224;}else{unsigned z=b>=32?2:3;if(!sxarm_add(c,b>=32?&sxarm_pcomm_near_match:&sxarm_pcomm_far_match,p))return false;p+=z;}}return true;}
bool sx_pcommos2_build(sx_context*c)
{
 return sxarm_pcomm(c);
}
