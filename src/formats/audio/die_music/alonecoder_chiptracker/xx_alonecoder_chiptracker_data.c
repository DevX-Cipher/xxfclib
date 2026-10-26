/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Alonecoder Chiptracker data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxzxm_chiptracker_note_fields[]={
 SX_FIELD("note_command","uint8",0,1,SX_FLAGS),
};
const sx_layout sxzxm_chiptracker_note={UINT32_C(0x608A0052),"chiptracker_note",sxzxm_chiptracker_note_fields,SX_COUNT(sxzxm_chiptracker_note_fields),SX_LE};
static const xx_data_struct_field_desc sxzxm_chiptracker_parameter_fields[]={
 SX_FIELD("sample_parameter","uint8",0,1,SX_FLAGS),
};
const sx_layout sxzxm_chiptracker_parameter={UINT32_C(0x608A0053),"chiptracker_parameter",sxzxm_chiptracker_parameter_fields,SX_COUNT(sxzxm_chiptracker_parameter_fields),SX_LE};
#define SXZXM_ADD(c,n,p) sxzxm_put(c,&sxzxm_##n,p,1)
static bool sxzxm_chip(sx_context*c){
 uint8_t n,v;if(!SXZXM_ADD(c,chiptracker_header,0))return false;
 if(!sxzxm_opt(c,&sxzxm_chiptracker_sample,43,16)||!sxzxm_opt(c,&sxzxm_chiptracker_sample_name,128,16)||!sxzxm_opt(c,&sxzxm_zx_position,256,256))return false;
 unsigned patterns=0;if(sxzxm_u8(c,41,&n))for(unsigned i=0;i<=(unsigned)n;i++){if(!sxzxm_u8(c,256+i,&v)||v>=31)break;if((unsigned)v+1>patterns)patterns=v+1;}
 for(unsigned i=0;i<patterns;i++){uint64_t p=512+512U*i;if(!sxzxm_opt(c,&sxzxm_chiptracker_note,p,256)||!sxzxm_opt(c,&sxzxm_chiptracker_parameter,p+256,256))return false;}return true;
}
bool sx_alonecoder_chiptracker_build(sx_context*c)
{
 return sxzxm_chip(c);
}
