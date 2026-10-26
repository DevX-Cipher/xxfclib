/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GMSH MSH data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_tag_count_fields[]={SX_FIELD("tag_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_tag_count={0x60630017U,"mesh_tag_count",sxsm_tag_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_element_type_fields[]={SX_FIELD("element_type","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_element_type={0x60630061U,"mesh_element_type",sxsm_element_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_tag_value_fields[]={SX_FIELD("tag_value","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_tag_value={0x60630062U,"mesh_tag_value",sxsm_tag_value_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_gmsh_data(sxsm_cursor*q){sxsm_token line,t[32];unsigned n;uint64_t count,components=0,entries=0;for(unsigned kind=0;kind<3;kind++){if(!sxsm_next(q,&line,t,32,&n,"#")||n!=1||!sxsm_number(q,t[0],&count)||count>16)return false;SM_EMIT(tag_count,t[0]);for(uint64_t i=0;i<count;i++){if(!sxsm_line(q,&line))return false;line=sxsm_trim(q,line);const sx_layout*l=kind==0?&sxsm_name:kind==1?(i==0?&sxsm_simulation_time:&sxsm_real_value):i==0?&sxsm_step_index:i==1?&sxsm_component_count:i==2?&sxsm_value_count:&sxsm_integer_value;if(!sxsm_emit(q,l,line))return false;if(kind==2&&i==1&&!sxsm_number(q,line,&components))return false;if(kind==2&&i==2&&!sxsm_number(q,line,&entries))return false;}}
 if(!components||components>16||entries>1000000)return false;for(uint64_t i=0;i<entries;i++){if(q->c->count>=24000)return true;if(!sxsm_next(q,&line,t,32,&n,"#")||n!=1+components)return false;SM_EMIT(entity_id,t[0]);if(!sxsm_each(q,t+1,n-1,&sxsm_scalar_value))return false;}return true;}
static bool sxsm_gmsh(sxsm_cursor*q){sxsm_token line,t[128];unsigned n;while(sxsm_next(q,&line,t,128,&n,"#")){if(q->c->count>=24000)return true;SM_EMIT(section,t[0]);if(sxsm_eq(q,t[0],"$MeshFormat")){if(!sxsm_next(q,&line,t,128,&n,"#")||n!=3)return false;SM_EMIT(real_value,t[0]);SM_EMIT(integer_value,t[1]);SM_EMIT(sample_bytes,t[2]);continue;}
 if(sxsm_eq(q,t[0],"$NodeData")||sxsm_eq(q,t[0],"$ElementData")){if(!sxsm_gmsh_data(q))return false;continue;}
 unsigned mode=sxsm_eq(q,t[0],"$Nodes")?1:sxsm_eq(q,t[0],"$Elements")?2:sxsm_eq(q,t[0],"$PhysicalNames")?3:0;if(!mode)continue;uint64_t count;if(!sxsm_next(q,&line,t,128,&n,"#")||n!=1||!sxsm_number(q,t[0],&count)||count>1000000)return false;if(!sxsm_emit(q,mode==1?&sxsm_node_count:mode==2?&sxsm_element_count:&sxsm_value_count,t[0]))return false;
 for(uint64_t i=0;i<count;i++){if(q->c->count>=24000)return true;if(!sxsm_next(q,&line,t,128,&n,"#"))return false;if(mode==1){if(n!=4)return false;SM_EMIT(node_id,t[0]);if(!sxsm_xyz(q,t+1,0))return false;}else if(mode==2){uint64_t tags;if(n<4||!sxsm_number(q,t[2],&tags)||tags>16||tags>n-3)return false;SM_EMIT(element_id,t[0]);SM_EMIT(element_type,t[1]);SM_EMIT(tag_count,t[2]);if(!sxsm_each(q,t+3,(unsigned)tags,&sxsm_tag_value)||!sxsm_each(q,t+3+tags,n-3-(unsigned)tags,&sxsm_node_index))return false;}else{if(n<3)return false;SM_EMIT(dimension,t[0]);SM_EMIT(property_id,t[1]);SM_EMIT(name,((sxsm_token){t[2].a,line.a+line.z-t[2].a}));}}}return true;}
bool sx_gmsh_msh_build(sxsm_cursor*q)
{
 return sxsm_gmsh(q);
}
#undef SM_EMIT
