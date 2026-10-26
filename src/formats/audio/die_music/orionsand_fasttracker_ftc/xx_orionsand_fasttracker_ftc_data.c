/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Orionsand Fasttracker Ftc data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_fasttracker_position_fields[]={
 SX_FIELD("pattern_index","uint8",0,1,SX_NONE),
 SX_FIELD("transposition","int8",1,1,SX_NONE),
};
const sx_layout sxzxm_fasttracker_position={UINT32_C(0x608A0023),"fasttracker_position",sxzxm_fasttracker_position_fields,SX_COUNT(sxzxm_fasttracker_position_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_fasttracker_pattern_end_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
};
const sx_layout sxzxm_fasttracker_pattern_end={UINT32_C(0x608A0027),"fasttracker_pattern_end",sxzxm_fasttracker_pattern_end_fields,SX_COUNT(sxzxm_fasttracker_pattern_end_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_fast(sx_context*c){
 uint16_t pt;if(!SXZXM_ADD(c,fasttracker_header,0)||!sxzxm_u16(c,75,&pt))return false;
 if(!sxzxm_opt(c,&sxzxm_zx_sample_address,82,32)||!sxzxm_opt(c,&sxzxm_zx_ornament_address,146,33))return false;
 uint8_t b;unsigned n=0;for(;n<255&&sxzxm_u8(c,212+2U*n,&b)&&b<128;n++){}if(!sxzxm_opt(c,&sxzxm_fasttracker_position,212,n))return false;if(sxzxm_u8(c,212+2U*n,&b)&&b==255&&!SXZXM_ADD(c,zx_marker,212+2U*n))return false;
 uint16_t first=0,end;unsigned count=0;bool terminated=false;for(;count<32;count++){if(!sxzxm_u16(c,(uint64_t)pt+6U*count,&end))break;if(end==65535){terminated=true;break;}if(!first&&end)first=end;}
 if(!sxzxm_opt(c,&sxzxm_zx_pattern_addresses,pt,count))return false;
 uint64_t after=(uint64_t)pt+6U*count+2;if(!terminated||first<after)return true;
 if(!SXZXM_ADD(c,fasttracker_pattern_end,after-2))return false;uint64_t base=first-after;
 for(unsigned k=0;k<2;k++)for(unsigned i=0;i<(k?33:32);i++){uint16_t p;if(!sxzxm_u16(c,(k?146:82)+2U*i,&p))break;if(p>=base&&p-base>=after&&!sxzxm_object(c,p-base,k?7:6))return false;}
 return true;
}
bool sx_orionsand_fasttracker_ftc_build(sx_context*c)
{
 return sxzxm_fast(c);
}
