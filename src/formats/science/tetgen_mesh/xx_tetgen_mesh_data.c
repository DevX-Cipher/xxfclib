/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TETGEN MESH data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_attribute_count_fields[]={SX_FIELD("attribute_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsm_attribute_count={0x60630018U,"mesh_attribute_count",sxsm_attribute_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_boundary_marker_fields[]={SX_FIELD("boundary_marker","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_boundary_marker={0x60630065U,"mesh_boundary_marker",sxsm_boundary_marker_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_tetgen(sxsm_cursor*q){sxsm_token line,t[128];unsigned n;uint64_t count,dim,attrs,marker=0;if(!sxsm_next(q,&line,t,128,&n,"#")||(n!=3&&n!=4)||!sxsm_number(q,t[0],&count)||!sxsm_number(q,t[1],&dim)||!sxsm_number(q,t[2],&attrs)||attrs>64||dim>10)return false;bool node=n==4;if(!sxsm_emit(q,node?&sxsm_node_count:&sxsm_element_count,t[0]))return false;if(node)SM_EMIT(dimension,t[1]);else SM_EMIT(component_count,t[1]);SM_EMIT(attribute_count,t[2]);if(node){if(!sxsm_number(q,t[3],&marker)||marker>1)return false;SM_EMIT(boundary_marker,t[3]);}for(uint64_t i=0;i<count;i++){if(q->c->count>=24000)return true;if(!sxsm_next(q,&line,t,128,&n,"#")||n!=1+dim+attrs+marker)return false;if(node){SM_EMIT(node_id,t[0]);for(unsigned j=0;j<dim;j++){const sx_layout*l=j==0?&sxsm_coordinate_x:j==1?&sxsm_coordinate_y:&sxsm_coordinate_z;if(!sxsm_emit(q,l,t[1+j]))return false;}}else{SM_EMIT(element_id,t[0]);if(!sxsm_each(q,t+1,(unsigned)dim,&sxsm_node_index))return false;}if(!sxsm_each(q,t+1+dim,(unsigned)attrs,&sxsm_attribute_value))return false;if(marker)SM_EMIT(boundary_marker,t[n-1]);}return true;}
bool sx_tetgen_mesh_build(sxsm_cursor*q)
{
 return sxsm_tetgen(q);
}
#undef SM_EMIT
