/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ac3d_model data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_material_index_fields[]={
 SX_FIELD("material_index","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_material_index={0x60520020U,"modeltext_material_index",sxmt_material_index_fields,SX_COUNT(sxmt_material_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_child_count_fields[]={
 SX_FIELD("child_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_child_count={0x60520022U,"modeltext_child_count",sxmt_child_count_fields,SX_COUNT(sxmt_child_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_surface_count_fields[]={
 SX_FIELD("surface_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_surface_count={0x60520024U,"modeltext_surface_count",sxmt_surface_count_fields,SX_COUNT(sxmt_surface_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_reference_count_fields[]={
 SX_FIELD("reference_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_reference_count={0x60520025U,"modeltext_reference_count",sxmt_reference_count_fields,SX_COUNT(sxmt_reference_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_rotation_value_fields[]={
 SX_FIELD("rotation_value","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_rotation_value={0x6052004fU,"modeltext_rotation_value",sxmt_rotation_value_fields,SX_COUNT(sxmt_rotation_value_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_transparency_fields[]={
 SX_FIELD("transparency","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_transparency={0x60520050U,"modeltext_transparency",sxmt_transparency_fields,SX_COUNT(sxmt_transparency_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_shininess_fields[]={
 SX_FIELD("shininess","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_shininess={0x60520051U,"modeltext_shininess",sxmt_shininess_fields,SX_COUNT(sxmt_shininess_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_ambient_red_fields[]={
 SX_FIELD("ambient_red","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_ambient_red={0x60520052U,"modeltext_ambient_red",sxmt_ambient_red_fields,SX_COUNT(sxmt_ambient_red_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_ambient_green_fields[]={
 SX_FIELD("ambient_green","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_ambient_green={0x60520053U,"modeltext_ambient_green",sxmt_ambient_green_fields,SX_COUNT(sxmt_ambient_green_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_ambient_blue_fields[]={
 SX_FIELD("ambient_blue","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_ambient_blue={0x60520054U,"modeltext_ambient_blue",sxmt_ambient_blue_fields,SX_COUNT(sxmt_ambient_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_emission_red_fields[]={
 SX_FIELD("emission_red","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_emission_red={0x60520055U,"modeltext_emission_red",sxmt_emission_red_fields,SX_COUNT(sxmt_emission_red_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_emission_green_fields[]={
 SX_FIELD("emission_green","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_emission_green={0x60520056U,"modeltext_emission_green",sxmt_emission_green_fields,SX_COUNT(sxmt_emission_green_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_emission_blue_fields[]={
 SX_FIELD("emission_blue","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_emission_blue={0x60520057U,"modeltext_emission_blue",sxmt_emission_blue_fields,SX_COUNT(sxmt_emission_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_specular_red_fields[]={
 SX_FIELD("specular_red","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_specular_red={0x60520058U,"modeltext_specular_red",sxmt_specular_red_fields,SX_COUNT(sxmt_specular_red_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_specular_green_fields[]={
 SX_FIELD("specular_green","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_specular_green={0x60520059U,"modeltext_specular_green",sxmt_specular_green_fields,SX_COUNT(sxmt_specular_green_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_specular_blue_fields[]={
 SX_FIELD("specular_blue","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_specular_blue={0x6052005aU,"modeltext_specular_blue",sxmt_specular_blue_fields,SX_COUNT(sxmt_specular_blue_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_surface_flags_fields[]={
 SX_FIELD("surface_flags","ascii_hex",0,0,SX_FLAGS),
};
const sx_layout sxmt_surface_flags={0x6052005dU,"modeltext_surface_flags",sxmt_surface_flags_fields,SX_COUNT(sxmt_surface_flags_fields),SX_LE};
#define MT_VALUE(n,e,v) do{if(!sxmt_value(q,&sxmt_##n,(e),(v)))return false;}while(0)
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)
static bool sxmt_ac(sxmt_cursor*q){int64_t a,e;uint64_t vertices=0,refs=0;while(sxmt_line(q,&a,&e,true)){if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;
 if(vertices){MT_VALUE(x,e,NULL);MT_VALUE(y,e,NULL);MT_VALUE(z,e,NULL);vertices--;}
 else if(refs){MT_VALUE(vertex_index,e,NULL);MT_VALUE(u,e,NULL);MT_VALUE(v,e,NULL);refs--;}
 else {int64_t k,z;if(!sxmt_token(q,e,&k,&z,false))return false;MT_EMIT(keyword,k,z);
 if(sxmt_eq(q,k,z,"AC3Db")){}
 else if(sxmt_eq(q,k,z,"OBJECT")){MT_VALUE(object_type,e,NULL);}
 else if(sxmt_eq(q,k,z,"name")||sxmt_eq(q,k,z,"texture")||sxmt_eq(q,k,z,"url")){if(!sxmt_quoted(q,&sxmt_name,e))return false;}
 else if(sxmt_eq(q,k,z,"numvert")){MT_VALUE(vertex_count,e,&vertices);if(vertices>1000000)return false;}
 else if(sxmt_eq(q,k,z,"refs")){MT_VALUE(reference_count,e,&refs);if(refs>256)return false;}
 else if(sxmt_eq(q,k,z,"numsurf")){MT_VALUE(surface_count,e,NULL);}
 else if(sxmt_eq(q,k,z,"kids")){MT_VALUE(child_count,e,NULL);}
 else if(sxmt_eq(q,k,z,"mat")){MT_VALUE(material_index,e,NULL);}
 else if(sxmt_eq(q,k,z,"SURF")){if(!sxmt_token(q,e,&a,&z,false)||z<3||q->b[a]!='0'||q->b[a+1]!='x')return false;MT_EMIT(surface_flags,a+2,z-2);}
 else if(sxmt_eq(q,k,z,"loc")){MT_VALUE(translate_x,e,NULL);MT_VALUE(translate_y,e,NULL);MT_VALUE(translate_z,e,NULL);}
 else if(sxmt_eq(q,k,z,"rot")){if(!sxmt_many(q,&sxmt_rotation_value,e))return false;}
 else if(sxmt_eq(q,k,z,"texrep")||sxmt_eq(q,k,z,"texoff")){MT_VALUE(u,e,NULL);MT_VALUE(v,e,NULL);}
 else if(sxmt_eq(q,k,z,"MATERIAL")){if(!sxmt_quoted(q,&sxmt_material_name,e))return false;const sx_layout*ls[]={&sxmt_red,&sxmt_green,&sxmt_blue,&sxmt_ambient_red,&sxmt_ambient_green,&sxmt_ambient_blue,&sxmt_emission_red,&sxmt_emission_green,&sxmt_emission_blue,&sxmt_specular_red,&sxmt_specular_green,&sxmt_specular_blue};for(unsigned i=0;i<4;i++){MT_VALUE(keyword,e,NULL);for(unsigned j=0;j<3;j++)if(!sxmt_value(q,ls[i*3+j],e,NULL))return false;}MT_VALUE(keyword,e,NULL);MT_VALUE(shininess,e,NULL);MT_VALUE(keyword,e,NULL);MT_VALUE(transparency,e,NULL);}
 else return false;}
 q->p=next;}return true;}
bool sx_ac3d_model_build(sxmt_cursor*q)
{
 return sxmt_ac(q);
}
#undef MT_VALUE
#undef MT_EMIT
