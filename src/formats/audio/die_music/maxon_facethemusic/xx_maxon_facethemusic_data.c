/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * maxon_facethemusic data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_ftm_sample_fields[]={
 SX_FIELD("name","char[30]",0,30,SX_NONE),
 SX_FIELD("unknown","uint8",30,1,SX_NONE),
 SX_FIELD("iff_octave","uint8",31,1,SX_NONE),
};
const sx_layout sxnextm_ftm_sample={UINT32_C(0x608B0025),"ftm_sample",sxnextm_ftm_sample_fields,SX_COUNT(sxnextm_ftm_sample_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_ftm_script_header_fields[]={
 SX_FIELD("script_lines","uint16",0,2,SX_COUNT_PROP),
 SX_FIELD("effect_index","uint16",2,2,SX_ID),
};
const sx_layout sxnextm_ftm_script_header={UINT32_C(0x608B0026),"ftm_script_header",sxnextm_ftm_script_header_fields,SX_COUNT(sxnextm_ftm_script_header_fields),SX_BE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
#define NX_TAKE(l,p,n,end) sxnextm_take(v,&sxnextm_##l,(p),(n),(end))
static bool sxnextm_ftm(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,p=82,n,fx,z;if(!sxnextm_eq(v,0,"FTMN\x03",5,e)||!NX_ROW(ftm_header,0,e)||!sxnextm_u(v,5,1,&n,e)||!sxnextm_u(v,80,1,&fx,e)||!NX_TAKE(ftm_sample,&p,n,e))return false;
 for(uint64_t i=0;i<fx;i++){if(!sxnextm_be(v,p,2,&z,e)||!NX_TAKE(ftm_script_header,&p,1,e)||!NX_TAKE(ftm_script_event,&p,z,e))return false;}return true;}
bool sx_maxon_facethemusic_build(sxnextm_view*v)
{
 return sxnextm_ftm(v);
}
#undef NX_ROW
#undef NX_TAKE
