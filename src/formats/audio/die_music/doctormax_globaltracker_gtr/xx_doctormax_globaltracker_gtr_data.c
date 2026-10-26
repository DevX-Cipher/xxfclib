/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Doctormax Globaltracker Gtr data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_globaltracker_header_fields[]={
 SX_FIELD("tempo","uint8",0,1,SX_NONE),
 SX_FIELD("identifier","bytes",1,3,SX_NONE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("load_address","uint16",5,2,SX_ADDRESS),
 SX_FIELD("title","char[32]",7,32,SX_NONE),
};
const sx_layout sxzxm_globaltracker_header={UINT32_C(0x608A001D),"globaltracker_header",sxzxm_globaltracker_header_fields,SX_COUNT(sxzxm_globaltracker_header_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_globaltracker_positions_fields[]={
 SX_FIELD("position_count","uint8",0,1,SX_COUNT_PROP),
 SX_FIELD("loop_position","uint8",1,1,SX_NONE),
};
const sx_layout sxzxm_globaltracker_positions={UINT32_C(0x608A001E),"globaltracker_positions",sxzxm_globaltracker_positions_fields,SX_COUNT(sxzxm_globaltracker_positions_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_global(sx_context*c){
 uint16_t base;if(!SXZXM_ADD(c,globaltracker_header,0)||!sxzxm_u16(c,5,&base))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_sample_address,39,15)||!sxzxm_opt(c,&sxzxm_zx_ornament_address,69,16)||!sxzxm_opt(c,&sxzxm_zx_pattern_addresses,101,32)||!sxzxm_opt(c,&sxzxm_globaltracker_positions,293,1))return false;
 uint8_t n;if(sxzxm_u8(c,293,&n)&&!sxzxm_opt(c,&sxzxm_globaltracker_position,295,n))return false;
 for(unsigned k=0;k<2;k++)for(unsigned i=0;i<(k?16:15);i++){uint16_t p;if(!sxzxm_u16(c,(k?69:39)+2*i,&p))break;if(p>=base&&p-base>=295&&!sxzxm_object(c,p-base,k?4:5))return false;}
 return true;
}
bool sx_doctormax_globaltracker_gtr_build(sx_context*c)
{
 return sxzxm_global(c);
}
