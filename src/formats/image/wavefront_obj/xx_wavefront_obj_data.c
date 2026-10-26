/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * wavefront_obj data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_group_name_fields[]={
 SX_FIELD("group_name","utf8",0,0,SX_STRING),
};
const sx_layout sxmt_group_name={0x6052000bU,"modeltext_group_name",sxmt_group_name_fields,SX_COUNT(sxmt_group_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_texture_index_fields[]={
 SX_FIELD("texture_index","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_texture_index={0x6052001dU,"modeltext_texture_index",sxmt_texture_index_fields,SX_COUNT(sxmt_texture_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_normal_index_fields[]={
 SX_FIELD("normal_index","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_normal_index={0x6052001eU,"modeltext_normal_index",sxmt_normal_index_fields,SX_COUNT(sxmt_normal_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_smoothing_group_fields[]={
 SX_FIELD("smoothing_group","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_smoothing_group={0x60520021U,"modeltext_smoothing_group",sxmt_smoothing_group_fields,SX_COUNT(sxmt_smoothing_group_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_w_fields[]={
 SX_FIELD("w","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_w={0x6052003cU,"modeltext_w",sxmt_w_fields,SX_COUNT(sxmt_w_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_normal_x_fields[]={
 SX_FIELD("normal_x","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_normal_x={0x6052003fU,"modeltext_normal_x",sxmt_normal_x_fields,SX_COUNT(sxmt_normal_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_normal_y_fields[]={
 SX_FIELD("normal_y","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_normal_y={0x60520040U,"modeltext_normal_y",sxmt_normal_y_fields,SX_COUNT(sxmt_normal_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_normal_z_fields[]={
 SX_FIELD("normal_z","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_normal_z={0x60520041U,"modeltext_normal_z",sxmt_normal_z_fields,SX_COUNT(sxmt_normal_z_fields),SX_LE};
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)
static bool sxmt_obj(sxmt_cursor*q){int64_t a,end;while(sxmt_line(q,&a,&end,true)){if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;int64_t k,z;if(!sxmt_token(q,end,&k,&z,false))return false;MT_EMIT(keyword,k,z);
 if(sxmt_eq(q,k,z,"v")||sxmt_eq(q,k,z,"vt")||sxmt_eq(q,k,z,"vn")){bool tex=sxmt_eq(q,k,z,"vt"),normal=sxmt_eq(q,k,z,"vn");const sx_layout*ls[]={tex?&sxmt_u:normal?&sxmt_normal_x:&sxmt_x,tex?&sxmt_v:normal?&sxmt_normal_y:&sxmt_y,tex?&sxmt_w:normal?&sxmt_normal_z:&sxmt_z,&sxmt_w};unsigned i=0;while(sxmt_token(q,end,&a,&z,true)){if(i>=4||!sxmt_emit(q,ls[i++],a,z))return false;}}
 else if(sxmt_eq(q,k,z,"f")){while(sxmt_token(q,end,&a,&z,true)){int64_t start=a,stop=a+z;unsigned i=0;const sx_layout*ls[]={&sxmt_vertex_index,&sxmt_texture_index,&sxmt_normal_index};for(int64_t p=a;p<=stop;p++)if(p==stop||q->b[p]=='/'){if(i>=3)return false;if(p>start&&!sxmt_emit(q,ls[i],start,p-start))return false;start=p+1;i++;}}}
 else {while(q->p<end&&sxmt_space(q->b[q->p]))q->p++;const sx_layout*l=sxmt_eq(q,k,z,"s")?(sxmt_eq(q,q->p,end-q->p,"off")?&sxmt_string_value:&sxmt_smoothing_group):(sxmt_eq(q,k,z,"usemtl")||sxmt_eq(q,k,z,"mtllib"))?&sxmt_material_name:&sxmt_group_name;if(!sxmt_emit(q,l,q->p,end-q->p))return false;}q->p=next;}return q->c->count>0;}
bool sx_wavefront_obj_build(sxmt_cursor*q)
{
 return sxmt_obj(q);
}
#undef MT_EMIT
