/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * jch_edlibtracker_raw data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_d00_end_fields[]={
 SX_FIELD("end_marker","uint16",0,2,SX_ID),
};
const sx_layout sxnextm_d00_end={UINT32_C(0x608B003F),"d00_end",sxnextm_d00_end_fields,SX_COUNT(sxnextm_d00_end_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_d00_speed_fields[]={
 SX_FIELD("track_speed","uint16",0,2,SX_NONE),
};
const sx_layout sxnextm_d00_speed={UINT32_C(0x608B0041),"d00_speed",sxnextm_d00_speed_fields,SX_COUNT(sxnextm_d00_speed_fields),SX_LE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
static bool sxnextm_d00(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,ver,n,p,q;
 if(!sxnextm_u(v,0,1,&ver,e)||ver>1||!sxnextm_u(v,2,1,&n,e)||!n||!NX_ROW(d00_header,0,e))return false;
 if(ver==1&&!NX_ROW(offset16le,11,e))return false;if(!NX_ROW(d00_end,ver?13:11,e)||!sxnextm_u(v,3,2,&p,e)||!sxnextm_table(v,&sxnextm_d00_tracks,p,n,e))return false;
 for(uint64_t i=0;i<n;i++)for(unsigned ch=0;ch<9;ch++){if(!sxnextm_u(v,p+i*32+ch*2,2,&q,e))return false;if(q&&!NX_ROW(d00_speed,q,e))return false;}
 return true;}
bool sx_jch_edlibtracker_raw_build(sxnextm_view*v)
{
 return sxnextm_d00(v);
}
#undef NX_ROW
