/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AMIRA MESH data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_box_min_z_fields[]={SX_FIELD("box_min_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_box_min_z={0x60630030U,"mesh_box_min_z",sxsm_box_min_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_box_max_z_fields[]={SX_FIELD("box_max_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_box_max_z={0x60630033U,"mesh_box_max_z",sxsm_box_max_z_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_amira(sxsm_cursor*q){sxsm_token line,t;if(!sxsm_line(q,&line))return false;SM_EMIT(signature,line);for(unsigned i=0;i<2;i++){if(!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);}if(!sxsm_many(q,&sxsm_axis_count,3,true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);if(!sxsm_expect(q,"{",true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(key,t);const sx_layout*cols[]={&sxsm_box_min_x,&sxsm_box_max_x,&sxsm_box_min_y,&sxsm_box_max_y,&sxsm_box_min_z,&sxsm_box_max_z};for(unsigned i=0;i<6;i++){if(!sxsm_one(q,cols[i],true))return false;}
 if(!sxsm_lex(q,&t,true))return false;if(sxsm_eq(q,t,",")){if(!sxsm_lex(q,&t,true))return false;}SM_EMIT(key,t);if(!sxsm_one(q,&sxsm_option_value,true)||!sxsm_expect(q,"}",true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(keyword,t);if(!sxsm_expect(q,"{",true)||!sxsm_lex(q,&t,true))return false;SM_EMIT(type_name,t);if(!sxsm_lex(q,&t,true))return false;if(sxsm_eq(q,t,"[")){if(!sxsm_one(q,&sxsm_component_count,true)||!sxsm_expect(q,"]",true)||!sxsm_lex(q,&t,true))return false;}SM_EMIT(name,t);if(!sxsm_expect(q,"}",true))return false;for(unsigned i=0;i<2;i++){if(!sxsm_expect(q,"@",true)||!sxsm_one(q,&sxsm_entity_id,true))return false;}return true;}
bool sx_amira_mesh_build(sxsm_cursor*q)
{
 return sxsm_amira(q);
}
#undef SM_EMIT
