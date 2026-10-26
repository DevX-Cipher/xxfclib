/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GOCAD MODEL data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_alpha_fields[]={SX_FIELD("alpha","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_alpha={0x60630073U,"mesh_alpha",sxsm_alpha_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_z_direction_fields[]={SX_FIELD("z_direction","char",0,0,SX_STRING)};
const sx_layout sxsm_z_direction={0x60630076U,"mesh_z_direction",sxsm_z_direction_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_gocad(sxsm_cursor*q){sxsm_token line,t[128];unsigned n;while(sxsm_next(q,&line,t,128,&n,"#")){if(q->c->count>=24000)return true;SM_EMIT(keyword,t[0]);if(sxsm_eq(q,t[0],"VRTX")||sxsm_eq(q,t[0],"PVRTX")){if(n<5)return false;SM_EMIT(node_id,t[1]);if(!sxsm_xyz(q,t+2,0)||!sxsm_each(q,t+5,n-5,&sxsm_attribute_value))return false;}else if(sxsm_eq(q,t[0],"ATOM")){if(n!=3)return false;SM_EMIT(node_id,t[1]);SM_EMIT(node_index,t[2]);}else if(sxsm_eq(q,t[0],"TRGL")||sxsm_eq(q,t[0],"BSTONE")){if(!sxsm_each(q,t+1,n-1,&sxsm_node_index))return false;}else if(sxsm_eq(q,t[0],"BORDER")){if(n!=4)return false;SM_EMIT(boundary_id,t[1]);if(!sxsm_each(q,t+2,2,&sxsm_node_index))return false;}else if(sxsm_eq(q,t[0],"*solid*color:")){if(n!=5)return false;const sx_layout*cols[]={&sxsm_red,&sxsm_green,&sxsm_blue,&sxsm_alpha};if(!sxsm_fields(q,t+1,4,cols,4))return false;}else if(sxsm_eq(q,t[0],"ESIZES")){if(!sxsm_each(q,t+1,n-1,&sxsm_component_count))return false;}else if(sxsm_eq(q,t[0],"ZPOSITIVE")){if(n!=2)return false;SM_EMIT(z_direction,t[1]);}else if(n>1){SM_EMIT(text_value,((sxsm_token){t[1].a,line.a+line.z-t[1].a}));}}return true;}
bool sx_gocad_model_build(sxsm_cursor*q)
{
 return sxsm_gocad(q);
}
#undef SM_EMIT
