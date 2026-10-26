/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Ken Silverman's Digital Music module (.KDM) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmr_kdm_header_fields[]={
 SX_FIELD("version","int32",0,4,SX_ID),
 SX_FIELD("notes","int32",4,4,SX_COUNT_PROP),
 SX_FIELD("tracks","int32",8,4,SX_COUNT_PROP),
};
const sx_layout sxmr_kdm_header={UINT32_C(0x607D0035),"kdm_header",sxmr_kdm_header_fields,SX_COUNT(sxmr_kdm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_instrument_fields[]={
 SX_FIELD("wave_index","uint8",0,1,SX_ID),
};
const sx_layout sxmr_kdm_instrument={UINT32_C(0x607D0036),"kdm_instrument",sxmr_kdm_instrument_fields,SX_COUNT(sxmr_kdm_instrument_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_quantization_fields[]={
 SX_FIELD("quantization","uint8",0,1,SX_NONE),
};
const sx_layout sxmr_kdm_quantization={UINT32_C(0x607D0037),"kdm_quantization",sxmr_kdm_quantization_fields,SX_COUNT(sxmr_kdm_quantization_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
const sx_layout sxmr_kdm_volume={UINT32_C(0x607D0038),"kdm_volume",sxmr_kdm_volume_fields,SX_COUNT(sxmr_kdm_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_track_fields[]={
 SX_FIELD("track","uint8",0,1,SX_ID),
};
const sx_layout sxmr_kdm_track={UINT32_C(0x607D003A),"kdm_track",sxmr_kdm_track_fields,SX_COUNT(sxmr_kdm_track_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_pitch_fields[]={
 SX_FIELD("pitch","uint8",0,1,SX_NONE),
};
const sx_layout sxmr_kdm_pitch={UINT32_C(0x607D003B),"kdm_pitch",sxmr_kdm_pitch_fields,SX_COUNT(sxmr_kdm_pitch_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_kdm_effect_fields[]={
 SX_FIELD("effect","uint8",0,1,SX_ID),
};
const sx_layout sxmr_kdm_effect={UINT32_C(0x607D003C),"kdm_effect",sxmr_kdm_effect_fields,SX_COUNT(sxmr_kdm_effect_fields),SX_LE};
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_kdm(sxmr_view*v)
{uint64_t end=v->c->size,n,t,x,p=12;const sx_layout*tr[4]={&sxmr_kdm_instrument,&sxmr_kdm_quantization,&sxmr_kdm_volume,&sxmr_kdm_volume};const sx_layout*nt[7]={&sxmr_kdm_track,&sxmr_kdm_pitch,&sxmr_kdm_volume,&sxmr_kdm_volume,&sxmr_kdm_effect,&sxmr_kdm_effect,&sxmr_kdm_effect};
 if(!sxmr_u(v,0,4,&x,end)||x||!sxmr_u(v,4,4,&n,end)||!n||n>8192||!sxmr_u(v,8,4,&t,end)||!t||t>256||!MR_ROW(kdm_header,0,end)||(end!=12+4*t+11*n&&end!=12+4*t+10*n))return false;
 for(unsigned i=0;i<4;i++){if(!sxmr_table(v,tr[i],p,t,end))return false;p+=t;}
 if(!sxmr_table(v,&sxmr_kdm_time,p,n,end))return false;p+=4*n;
 for(unsigned i=0;i<7&&p<end;i++){if(!sxmr_table(v,nt[i],p,n,end))return false;p+=n;}return true;}
bool sx_silverman_digitalmusic_kdm_build(sxmr_view*v)
{
 return sxmr_kdm(v);
}
#undef MR_ROW
