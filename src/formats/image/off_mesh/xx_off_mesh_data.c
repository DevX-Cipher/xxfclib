/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * off_mesh data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_list_count_fields[]={
 SX_FIELD("list_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_list_count={0x60520016U,"modeltext_list_count",sxmt_list_count_fields,SX_COUNT(sxmt_list_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_alpha_fields[]={
 SX_FIELD("alpha","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_alpha={0x60520045U,"modeltext_alpha",sxmt_alpha_fields,SX_COUNT(sxmt_alpha_fields),SX_LE};
static bool sxmt_values(sxmt_cursor*q,int64_t a,int64_t end,const sx_layout*const*layouts,unsigned count){int64_t save=q->p;q->p=a;bool ok=true;for(unsigned i=0;i<count;i++)if(!sxmt_value(q,layouts[i],end,NULL)){ok=false;break;}q->p=save;return ok;}
#define MT_VALUE(n,e,v) do{if(!sxmt_value(q,&sxmt_##n,(e),(v)))return false;}while(0)
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)
static bool sxmt_off(sxmt_cursor*q){int64_t a,e;if(!sxmt_line(q,&a,&e,true))return false;MT_EMIT(signature,a,e-a);if(!sxmt_line(q,&a,&e,true))return false;int64_t next=q->p;q->p=a;uint64_t nv,nf,ne;MT_VALUE(vertex_count,e,&nv);MT_VALUE(face_count,e,&nf);MT_VALUE(edge_count,e,&ne);q->p=next;if(nv>1000000||nf>1000000)return false;
 const sx_layout*xyz[]={&sxmt_x,&sxmt_y,&sxmt_z};for(uint64_t i=0;i<nv;i++){if(q->c->count>=32000)return true;if(!sxmt_line(q,&a,&e,true)||!sxmt_values(q,a,e,xyz,3))return false;}
 for(uint64_t i=0;i<nf;i++){if(q->c->count>=32000)return true;if(!sxmt_line(q,&a,&e,true))return false;next=q->p;q->p=a;uint64_t n;MT_VALUE(list_count,e,&n);if(n>1000000)return false;for(uint64_t j=0;j<n;j++){if(q->c->count>=32000)return true;MT_VALUE(vertex_index,e,NULL);}const sx_layout*colors[]={&sxmt_red,&sxmt_green,&sxmt_blue,&sxmt_alpha};unsigned j=0;int64_t z;while(sxmt_token(q,e,&a,&z,true)){if(j>=4||!sxmt_emit(q,colors[j++],a,z))return false;}q->p=next;}return true;}
bool sx_off_mesh_build(sxmt_cursor*q)
{
 return sxmt_off(q);
}
#undef MT_VALUE
#undef MT_EMIT
