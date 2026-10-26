/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MEDIT MESH data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_label_id_fields[]={SX_FIELD("label_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_label_id={0x6063001fU,"mesh_label_id",sxsm_label_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_mesh_version_fields[]={SX_FIELD("mesh_version","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_mesh_version={0x60630060U,"mesh_mesh_version",sxsm_mesh_version_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_medit(sxsm_cursor*q){sxsm_token t;uint64_t dim;if(!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);if(!sxsm_one(q,&sxsm_mesh_version,true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);if(!sxsm_count(q,&sxsm_dimension,&dim,true)||(dim!=2&&dim!=3))return false;while(sxsm_lex(q,&t,true)){if(q->c->count>=24000)return true;SM_EMIT(section,t);if(sxsm_eq(q,t,"End"))return true;bool vertices=sxsm_eq(q,t,"Vertices"),ref=sxsm_eq(q,t,"Corners")||sxsm_eq(q,t,"RequiredVertices");unsigned arity=vertices?(unsigned)dim:ref?1:sxsm_eq(q,t,"Edges")?2:sxsm_eq(q,t,"Triangles")?3:sxsm_eq(q,t,"Quadrilaterals")||sxsm_eq(q,t,"Tetrahedra")?4:sxsm_eq(q,t,"Hexahedra")?8:0;uint64_t n;if(!arity||!sxsm_count(q,vertices?&sxsm_node_count:&sxsm_element_count,&n,true))return false;for(uint64_t i=0;i<n;i++){if(q->c->count>=24000)return true;if(vertices){if(!sxsm_one(q,&sxsm_coordinate_x,true)||!sxsm_one(q,&sxsm_coordinate_y,true)||(dim==3&&!sxsm_one(q,&sxsm_coordinate_z,true)))return false;}else if(!sxsm_many(q,&sxsm_node_index,arity,true))return false;if(!ref&&!sxsm_one(q,&sxsm_label_id,true))return false;}}return true;}
bool sx_medit_mesh_build(sxsm_cursor*q)
{
 return sxsm_medit(q);
}
#undef SM_EMIT
