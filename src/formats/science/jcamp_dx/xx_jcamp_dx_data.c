/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JCAMP DX data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_jcamp_version_fields[]={SX_FIELD("jcamp_version","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_jcamp_version={0x6063004cU,"mesh_jcamp_version",sxsm_jcamp_version_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_first_x_fields[]={SX_FIELD("first_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_first_x={0x6063004dU,"mesh_first_x",sxsm_first_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_last_x_fields[]={SX_FIELD("last_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_last_x={0x6063004eU,"mesh_last_x",sxsm_last_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_x_factor_fields[]={SX_FIELD("x_factor","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_x_factor={0x6063004fU,"mesh_x_factor",sxsm_x_factor_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_y_factor_fields[]={SX_FIELD("y_factor","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_y_factor={0x60630050U,"mesh_y_factor",sxsm_y_factor_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spectral_x_fields[]={SX_FIELD("spectral_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_spectral_x={0x60630051U,"mesh_spectral_x",sxsm_spectral_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_spectral_y_fields[]={SX_FIELD("spectral_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_spectral_y={0x60630052U,"mesh_spectral_y",sxsm_spectral_y_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_jcamp(sxsm_cursor*q){sxsm_token line,t[128],key,value;unsigned n;bool data=false,pairs=false;while(sxsm_line(q,&line)){if(q->c->count>=24000)return true;if(!line.z)continue;if(line.z>=2&&q->b[line.a]=='#'&&q->b[line.a+1]=='#'){if(!sxsm_keyvalue(q,(sxsm_token){line.a+2,line.z-2},'=',&key,&value))return false;SM_EMIT(key,key);char k[64];unsigned used=0;for(int64_t i=0;i<key.z;i++){uint8_t ch=q->b[key.a+i];if(ch==' '||ch=='-'||ch=='/'||ch=='_')continue;if(ch>='a'&&ch<='z')ch-=32;if(used==63)return false;k[used++]=(char)ch;}k[used]=0;
 const sx_layout*l=!xx_rt_strcmp(k,"TITLE")?&sxsm_title:!xx_rt_strcmp(k,"JCAMPDX")?&sxsm_jcamp_version:!xx_rt_strcmp(k,"FIRSTX")?&sxsm_first_x:!xx_rt_strcmp(k,"LASTX")?&sxsm_last_x:!xx_rt_strcmp(k,"XFACTOR")?&sxsm_x_factor:!xx_rt_strcmp(k,"YFACTOR")?&sxsm_y_factor:!xx_rt_strcmp(k,"NPOINTS")?&sxsm_value_count:!xx_rt_strcmp(k,"XUNITS")||!xx_rt_strcmp(k,"YUNITS")?&sxsm_units:&sxsm_option_value;if(!sxsm_emit(q,l,value))return false;if(!xx_rt_strcmp(k,"END"))return true;if(!xx_rt_strcmp(k,"XYDATA")||!xx_rt_strcmp(k,"XYPOINTS")){data=true;pairs=!xx_rt_strcmp(k,"XYPOINTS");}}
 else if(data){n=sxsm_split(q,line,t,128,false);if(n>128)return false;for(unsigned i=0;i<n;i++)if(!sxsm_emit(q,(pairs?!(i&1):i==0)?&sxsm_spectral_x:&sxsm_spectral_y,t[i]))return false;}else return false;}return false;}
bool sx_jcamp_dx_build(sxsm_cursor*q)
{
 return sxsm_jcamp(q);
}
#undef SM_EMIT
