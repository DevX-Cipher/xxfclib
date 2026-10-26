/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TEKTRONIX ISF data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_x_increment_fields[]={SX_FIELD("x_increment","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_x_increment={0x60630040U,"mesh_x_increment",sxsm_x_increment_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_x_zero_fields[]={SX_FIELD("x_zero","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_x_zero={0x60630041U,"mesh_x_zero",sxsm_x_zero_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_point_offset_fields[]={SX_FIELD("point_offset","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_point_offset={0x60630042U,"mesh_point_offset",sxsm_point_offset_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_y_multiplier_fields[]={SX_FIELD("y_multiplier","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_y_multiplier={0x60630043U,"mesh_y_multiplier",sxsm_y_multiplier_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_y_zero_fields[]={SX_FIELD("y_zero","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_y_zero={0x60630044U,"mesh_y_zero",sxsm_y_zero_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_y_offset_fields[]={SX_FIELD("y_offset","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_y_offset={0x60630045U,"mesh_y_offset",sxsm_y_offset_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_length_digits_fields[]={SX_FIELD("length_digits","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_length_digits={0x60630046U,"mesh_length_digits",sxsm_length_digits_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_payload_bytes_fields[]={SX_FIELD("payload_bytes","ascii_signed",0,0,SX_SIZE)};
const sx_layout sxsm_payload_bytes={0x60630047U,"mesh_payload_bytes",sxsm_payload_bytes_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_isf(sxsm_cursor*q){if(q->n<8)return false;SM_EMIT(signature,((sxsm_token){0,8}));int64_t p=8;while(p<q->n&&p<32768){if(q->c->count>=24000)return true;if(q->n-p>=6&&!xx_rt_memcmp(q->b+p,":CURVE",6)){SM_EMIT(keyword,((sxsm_token){p,6}));p+=6;while(p<q->n&&q->b[p]==' ')p++;if(q->n-p<2||q->b[p]!='#')return false;p++;unsigned digits=q->b[p]-'0';if(digits<1||digits>9||q->n-p-1<digits)return false;SM_EMIT(length_digits,((sxsm_token){p,1}));SM_EMIT(payload_bytes,((sxsm_token){p+1,digits}));return true;}
 int64_t a=p;bool quote=false;while(p<q->n){uint8_t c=q->b[p];if(c=='"')quote=!quote;if(!quote&&c==';')break;p++;}if(p==q->n||quote)return false;sxsm_token line=sxsm_trim(q,(sxsm_token){a,p-a}),key,value;int64_t i=0;while(i<line.z&&!sxsm_space(q->b[line.a+i]))i++;key=(sxsm_token){line.a,i};value=sxsm_trim(q,(sxsm_token){line.a+i,line.z-i});SM_EMIT(key,key);const sx_layout*l=sxsm_eq(q,key,"BYT_NR")?&sxsm_sample_bytes:sxsm_eq(q,key,"BIT_NR")?&sxsm_sample_bits:sxsm_eq(q,key,"NR_PT")?&sxsm_value_count:sxsm_eq(q,key,"XINCR")?&sxsm_x_increment:sxsm_eq(q,key,"XZERO")?&sxsm_x_zero:sxsm_eq(q,key,"PT_OFF")?&sxsm_point_offset:sxsm_eq(q,key,"YMULT")?&sxsm_y_multiplier:sxsm_eq(q,key,"YZERO")?&sxsm_y_zero:sxsm_eq(q,key,"YOFF")?&sxsm_y_offset:sxsm_eq(q,key,"XUNIT")||sxsm_eq(q,key,"YUNIT")?&sxsm_units:sxsm_eq(q,key,"BYT_OR")?&sxsm_endian:sxsm_eq(q,key,"ENCDG")?&sxsm_encoding:&sxsm_option_value;if(!sxsm_emit(q,l,value))return false;p++;}return false;}
bool sx_tektronix_isf_build(sxsm_cursor*q)
{
 return sxsm_isf(q);
}
#undef SM_EMIT
