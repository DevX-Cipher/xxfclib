/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Smart Install Maker data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_sim_stored_file_fields[]={
 SX_FIELD("unknown_00","uint8[4]",0,4,SX_NONE),
 SX_FIELD("size","uint32le",4,4,SX_SIZE),
 SX_FIELD("unknown_08","uint8[16]",8,16,SX_NONE),
};
const sx_layout sxir_sim_stored_file={0x60800016U,"sim_stored_file",sxir_sim_stored_file_fields,SX_COUNT(sxir_sim_stored_file_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_sim(sxir_view*v)
{uint64_t end=v->c->size;if(end<4132)return false;uint64_t footer=end-36,so,ro,rl,co,n,compressed,runtime;
 if(!IR_U(footer,8,so,end)||!IR_U(footer+8,8,rl,end)||!IR_U(footer+16,8,ro,end)||!IR_U(footer+24,8,co,end)||!IR_U(footer+32,1,compressed,end)||!IR_U(footer+33,1,runtime,end)||!IR_U(footer+34,1,n,end)||n<119||compressed>1||!sxir_eq(v,footer+35,"\xf1",1,end)||so<4096||so>=ro||ro>co||co>footer||rl!=co-ro||!IR_ROW(sim_footer,footer,end))return false;
 if(!sxir_eq(v,so,"Smart Install Maker v.",21,ro)){uint64_t found;if(!sxir_find(v,4096,footer,"Smart Install Maker v.",21,true,&found))return false;if(found>=so){uint64_t delta=found-so;if(delta>footer-co)return false;ro+=delta;co+=delta;}else{uint64_t delta=so-found;if(delta>ro||delta>co)return false;ro-=delta;co-=delta;}so=found;if(so>=ro||ro>co||co>footer||rl!=co-ro)return false;}
 uint64_t at=so,chunks=0,rest=0;for(uint64_t i=0;at<ro;i++){uint64_t start=at,len;if(!sxir_zstr(v,&at,ro,&len))return false;if(i==117||i==118){uint64_t value=0;if(!len||len>10)return false;for(uint64_t k=0;k<len;k++){uint64_t b;if(!IR_U(start+k,1,b,ro)||b<'0'||b>'9'||value>(UINT32_MAX-(b-'0'))/10)return false;value=value*10+b-'0';}if(i==117)chunks=value;else rest=value;}}
 if(!compressed){at=ro;for(uint64_t i=0;i<runtime;i++){uint64_t len,start,size=0;if(!sxir_zstr(v,&at,co,&len))return false;start=at;if(!sxir_zstr(v,&at,co,&len)||!len||len>10)return false;for(uint64_t k=0;k<len;k++){uint64_t b;if(!IR_U(start+k,1,b,co)||b<'0'||b>'9'||size>(UINT32_MAX-(b-'0'))/10)return false;size=size*10+b-'0';}if(!sxir_span(v,at,size,co))return false;at+=size;}if(at!=co)return false;}
 if(!chunks&&!rest){at=co;while(at<footer){uint64_t size;if(!IR_U(at+4,4,size,footer)||!IR_ROW(sim_stored_file,at,footer)||!sxir_span(v,at+24,size,footer))return false;at+=24+size;}}
 return true;}
bool sx_smart_install_maker_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_sim(v);
}
#undef IR_ROW
#undef IR_U
