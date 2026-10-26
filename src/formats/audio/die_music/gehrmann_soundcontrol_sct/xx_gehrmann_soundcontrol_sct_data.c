/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * gehrmann_soundcontrol_sct data structures, moved out of the nextmusic schema family. */
#include "../../../xx_format_schema_nextmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnextm_sct_header_fields[]={
 SX_FIELD("title","char[16]",0,16,SX_NONE),
 SX_FIELD("track_section_bytes","uint32",16,4,SX_SIZE),
 SX_FIELD("sample_section_bytes","uint32",20,4,SX_SIZE),
 SX_FIELD("position_section_bytes","uint32",24,4,SX_SIZE),
 SX_FIELD("instrument_section_bytes","uint32",28,4,SX_SIZE),
 SX_FIELD("format_word","uint16",32,2,SX_ID),
 SX_FIELD("speed","uint16",34,2,SX_NONE),
 SX_FIELD("unknown","bytes",36,28,SX_NONE),
};
const sx_layout sxnextm_sct_header={UINT32_C(0x608B004A),"sct_header",sxnextm_sct_header_fields,SX_COUNT(sxnextm_sct_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnextm_sct_track_fields[]={
 SX_FIELD("name","char[16]",0,16,SX_NONE),
};
const sx_layout sxnextm_sct_track={UINT32_C(0x608B004B),"sct_track",sxnextm_sct_track_fields,SX_COUNT(sxnextm_sct_track_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_sct_position_fields[]={
 SX_FIELD("track_index","uint8",0,1,SX_ID),
 SX_FIELD("ignored","uint8",1,1,SX_NONE),
};
const sx_layout sxnextm_sct_position={UINT32_C(0x608B004C),"sct_position",sxnextm_sct_position_fields,SX_COUNT(sxnextm_sct_position_fields),SX_LE};
static const xx_data_struct_field_desc sxnextm_sct_command_fields[]={
 SX_FIELD("command","uint16",0,2,SX_ID),
 SX_FIELD("argument1","uint16",2,2,SX_NONE),
 SX_FIELD("argument2","uint16",4,2,SX_NONE),
};
const sx_layout sxnextm_sct_command={UINT32_C(0x608B004E),"sct_command",sxnextm_sct_command_fields,SX_COUNT(sxnextm_sct_command_fields),SX_BE};
#define NX_ROW(l,at,end) sxnextm_row(v,&sxnextm_##l,(at),(end))
static bool sxnextm_sct(sxnextm_view*v){uint64_t e=(uint64_t)v->c->size,b[4],z[4],p=64,off,n;
 if(!NX_ROW(sct_header,0,e))return false;for(unsigned i=0;i<4;i++){if(!sxnextm_be(v,16+i*4,4,&z[i],e)||!sxnextm_span(v,p,z[i],e))return false;b[i]=p;p+=z[i];}
 if(!sxnextm_table(v,&sxnextm_offset16,b[0],256,b[0]+z[0])||!sxnextm_table(v,&sxnextm_offset32be,b[1],256,b[1]+z[1])||z[2]%12||!sxnextm_table(v,&sxnextm_sct_position,b[2],z[2]/2,b[2]+z[2]))return false;
 if(z[3]&&!sxnextm_table(v,&sxnextm_offset16,b[3],256,b[3]+z[3]))return false;
 for(unsigned i=0;i<256;i++){if(!sxnextm_be(v,b[0]+i*2,2,&off,e))return false;if(off&&!NX_ROW(sct_track,b[0]+off,b[0]+z[0]))return false;
 if(!sxnextm_be(v,b[1]+i*4,4,&off,e))return false;if(off){p=b[1]+off;if(!NX_ROW(sct_sample,p,b[1]+z[1])||!sxnextm_be(v,p+60,4,&n,e)||n<64||!sxnextm_span(v,p,n,b[1]+z[1]))return false;}
 if(z[3]){if(!sxnextm_be(v,b[3]+i*2,2,&off,e))return false;if(off){p=b[3]+off;if(!NX_ROW(sct_instrument,p,b[3]+z[3])||!sxnextm_be(v,p+16,2,&n,e)||n%6||!sxnextm_table(v,&sxnextm_sct_command,p+48,n/6,b[3]+z[3]))return false;}}}
 return true;}
bool sx_gehrmann_soundcontrol_sct_build(sxnextm_view*v)
{
 return sxnextm_sct(v);
}
#undef NX_ROW
