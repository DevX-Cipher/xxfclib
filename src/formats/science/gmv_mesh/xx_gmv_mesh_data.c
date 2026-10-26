/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GMV MESH data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_topology_name_fields[]={SX_FIELD("topology_name","char",0,0,SX_STRING)};
const sx_layout sxsm_topology_name={0x60630077U,"mesh_topology_name",sxsm_topology_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_variable_name_fields[]={SX_FIELD("variable_name","char",0,0,SX_STRING)};
const sx_layout sxsm_variable_name={0x60630078U,"mesh_variable_name",sxsm_variable_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_material_name_fields[]={SX_FIELD("material_name","char",0,0,SX_STRING)};
const sx_layout sxsm_material_name={0x60630079U,"mesh_material_name",sxsm_material_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_material_id_fields[]={SX_FIELD("material_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_material_id={0x6063007bU,"mesh_material_id",sxsm_material_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_count_fields[]={SX_FIELD("binary_count","int32",0,4,SX_COUNT_PROP)};
const sx_layout sxsm_binary_count={0x60630086U,"mesh_binary_count",sxsm_binary_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_arity_fields[]={SX_FIELD("binary_arity","int32",0,4,SX_COUNT_PROP)};
const sx_layout sxsm_binary_arity={0x60630087U,"mesh_binary_arity",sxsm_binary_arity_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_node_index_fields[]={SX_FIELD("binary_node_index","int32",0,4,SX_ID)};
const sx_layout sxsm_binary_node_index={0x60630088U,"mesh_binary_node_index",sxsm_binary_node_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_material_id_fields[]={SX_FIELD("binary_material_id","int32",0,4,SX_ID)};
const sx_layout sxsm_binary_material_id={0x60630089U,"mesh_binary_material_id",sxsm_binary_material_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_flag_value_fields[]={SX_FIELD("binary_flag_value","int32",0,4,SX_ID)};
const sx_layout sxsm_binary_flag_value={0x6063008aU,"mesh_binary_flag_value",sxsm_binary_flag_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_cycle_fields[]={SX_FIELD("binary_cycle","int32",0,4,SX_ID)};
const sx_layout sxsm_binary_cycle={0x6063008bU,"mesh_binary_cycle",sxsm_binary_cycle_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_location_fields[]={SX_FIELD("binary_location","int32",0,4,SX_NONE)};
const sx_layout sxsm_binary_location={0x6063008cU,"mesh_binary_location",sxsm_binary_location_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_scalar_fields[]={SX_FIELD("binary_scalar","float",0,4,SX_NONE)};
const sx_layout sxsm_binary_scalar={0x6063008dU,"mesh_binary_scalar",sxsm_binary_scalar_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_coordinate_fields[]={SX_FIELD("binary_coordinate","float",0,4,SX_NONE)};
const sx_layout sxsm_binary_coordinate={0x6063008eU,"mesh_binary_coordinate",sxsm_binary_coordinate_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_velocity_fields[]={SX_FIELD("binary_velocity","float",0,4,SX_NONE)};
const sx_layout sxsm_binary_velocity={0x6063008fU,"mesh_binary_velocity",sxsm_binary_velocity_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_time_fields[]={SX_FIELD("binary_time","float",0,4,SX_NONE)};
const sx_layout sxsm_binary_time={0x60630090U,"mesh_binary_time",sxsm_binary_time_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_binary_name_fields[]={SX_FIELD("binary_name","char[8]",0,8,SX_STRING)};
const sx_layout sxsm_binary_name={0x60630091U,"mesh_binary_name",sxsm_binary_name_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static unsigned sxsm_gmv_arity(sxsm_cursor*q,sxsm_token t){return sxsm_eq(q,t,"line")?2:sxsm_eq(q,t,"tri")?3:sxsm_eq(q,t,"quad")||sxsm_eq(q,t,"tet")?4:sxsm_eq(q,t,"pyramid")?5:sxsm_eq(q,t,"prism")?6:sxsm_eq(q,t,"hex")?8:0;}
static bool sxsm_gmv_ascii(sxsm_cursor*q){sxsm_token t;uint64_t nodes=0,cells=0,n,location;if(!sxsm_lex(q,&t,true))return false;SM_EMIT(signature,t);if(!sxsm_one(q,&sxsm_encoding,true))return false;while(sxsm_lex(q,&t,true)){if(q->c->count>=24000)return true;SM_EMIT(section,t);if(sxsm_eq(q,t,"nodes")){if(!sxsm_count(q,&sxsm_node_count,&nodes,true))return false;const sx_layout*cols[]={&sxsm_coordinate_x,&sxsm_coordinate_y,&sxsm_coordinate_z};for(unsigned k=0;k<3;k++)if(!sxsm_many(q,cols[k],nodes,true))return false;}
 else if(sxsm_eq(q,t,"cells")){if(!sxsm_count(q,&sxsm_element_count,&cells,true))return false;for(uint64_t i=0;i<cells;i++){if(q->c->count>=24000)return true;if(!sxsm_lex(q,&t,true))return false;SM_EMIT(topology_name,t);unsigned arity=sxsm_gmv_arity(q,t);if(!arity||!sxsm_count(q,&sxsm_component_count,&n,true)||n!=arity||!sxsm_many(q,&sxsm_node_index,n,true))return false;}}
 else if(sxsm_eq(q,t,"material")){if(!sxsm_count(q,&sxsm_value_count,&n,true)||!sxsm_count(q,&sxsm_integer_value,&location,true)||location>1)return false;if(!sxsm_many(q,&sxsm_material_name,n,true)||!sxsm_many(q,&sxsm_material_id,location?nodes:cells,true))return false;}
 else if(sxsm_eq(q,t,"variable")){while(sxsm_lex(q,&t,true)){if(q->c->count>=24000)return true;if(sxsm_eq(q,t,"endvars")){SM_EMIT(keyword,t);break;}SM_EMIT(variable_name,t);if(!sxsm_count(q,&sxsm_integer_value,&location,true)||location>1||!sxsm_many(q,&sxsm_scalar_value,location?nodes:cells,true))return false;}}
 else if(sxsm_eq(q,t,"cycleno")){if(!sxsm_one(q,&sxsm_step_index,true))return false;}else if(sxsm_eq(q,t,"probtime")){if(!sxsm_one(q,&sxsm_simulation_time,true))return false;}else if(sxsm_eq(q,t,"endgmv"))return true;else return false;}return false;}
static bool sxsm_btake(sxsm_cursor*q,const sx_layout*l,uint64_t count){uint64_t z=(uint64_t)l->fields[0].size;if(!z||count>1000000||count>(uint64_t)(q->n-q->p)/z||xx_pd_is_stopped(q->c->pd))return false;for(uint64_t i=0;i<count;i++){if(q->c->count>=24000){q->p+=(int64_t)((count-i)*z);return true;}if(!sxsm_emit(q,l,(sxsm_token){q->p,(int64_t)z}))return false;q->p+=(int64_t)z;}return true;}
static bool sxsm_bcount(sxsm_cursor*q,const sx_layout*l,uint64_t*v){if(q->n-q->p<4)return false;*v=xx_data_get_u32(q->b+q->p,4,0,false);return *v<=1000000&&sxsm_btake(q,l,1);}
static bool sxsm_bname(sxsm_cursor*q,sxsm_token*t){if(q->n-q->p<8)return false;*t=sxsm_trim(q,(sxsm_token){q->p,8});return sxsm_btake(q,&sxsm_binary_name,1);}
static bool sxsm_gmv_binary(sxsm_cursor*q){uint64_t nodes=0,cells=0,n,loc,types; sxsm_token t;if(!sxsm_btake(q,&sxsm_binary_name,2))return false;while(q->p<q->n){if(q->c->count>=24000)return true;if(++q->work>2000000||!sxsm_bname(q,&t))return false;
 if(sxsm_eq(q,t,"nodes")){if(!sxsm_bcount(q,&sxsm_binary_count,&nodes))return false;for(unsigned k=0;k<3;k++)if(!sxsm_btake(q,&sxsm_binary_coordinate,nodes))return false;}
 else if(sxsm_eq(q,t,"cells")){if(!sxsm_bcount(q,&sxsm_binary_count,&cells))return false;for(uint64_t i=0;i<cells;i++){if(q->c->count>=24000)return true;if(!sxsm_bname(q,&t))return false;unsigned arity=sxsm_gmv_arity(q,t);if(!arity||!sxsm_bcount(q,&sxsm_binary_arity,&n)||n!=arity||!sxsm_btake(q,&sxsm_binary_node_index,n))return false;}}
 else if(sxsm_eq(q,t,"material")){if(!sxsm_bcount(q,&sxsm_binary_count,&n)||!sxsm_bcount(q,&sxsm_binary_location,&loc)||loc>1||!sxsm_btake(q,&sxsm_binary_name,n)||!sxsm_btake(q,&sxsm_binary_material_id,loc?nodes:cells))return false;}
 else if(sxsm_eq(q,t,"variable")){for(unsigned i=0;i<4096;i++){if(q->c->count>=24000)return true;if(!sxsm_bname(q,&t))return false;if(sxsm_eq(q,t,"endvars"))break;if(!sxsm_bcount(q,&sxsm_binary_location,&loc)||loc>1||!sxsm_btake(q,&sxsm_binary_scalar,loc?nodes:cells))return false;}}
 else if(sxsm_eq(q,t,"velocity")){if(!sxsm_bcount(q,&sxsm_binary_location,&loc)||loc>1)return false;for(unsigned k=0;k<3;k++)if(!sxsm_btake(q,&sxsm_binary_velocity,loc?nodes:cells))return false;}
 else if(sxsm_eq(q,t,"flags")){for(unsigned i=0;i<4096;i++){if(q->c->count>=24000)return true;if(!sxsm_bname(q,&t))return false;if(sxsm_eq(q,t,"endflag"))break;if(!sxsm_bcount(q,&sxsm_binary_count,&types)||!sxsm_bcount(q,&sxsm_binary_location,&loc)||loc>1||!sxsm_btake(q,&sxsm_binary_name,types)||!sxsm_btake(q,&sxsm_binary_flag_value,loc?nodes:cells))return false;}}
 else if(sxsm_eq(q,t,"polygons")){for(unsigned i=0;i<1000000;i++){if(q->c->count>=24000)return true;if(q->n-q->p<8)return false;t=sxsm_trim(q,(sxsm_token){q->p,8});if(sxsm_eq(q,t,"endpoly")){if(!sxsm_btake(q,&sxsm_binary_name,1))return false;break;}if(!sxsm_bcount(q,&sxsm_binary_material_id,&n)||!sxsm_bcount(q,&sxsm_binary_count,&n)||n>64)return false;for(unsigned k=0;k<3;k++)if(!sxsm_btake(q,&sxsm_binary_coordinate,n))return false;}}
 else if(sxsm_eq(q,t,"cycleno")){if(!sxsm_btake(q,&sxsm_binary_cycle,1))return false;}else if(sxsm_eq(q,t,"probtime")){if(!sxsm_btake(q,&sxsm_binary_time,1))return false;}else if(sxsm_eq(q,t,"endgmv"))return true;else return false;}return false;}
static bool sxsm_gmv(sxsm_cursor*q){return q->n>=16&&!xx_rt_memcmp(q->b+8,"ieee    ",8)?sxsm_gmv_binary(q):sxsm_gmv_ascii(q);}
bool sx_gmv_mesh_build(sxsm_cursor*q)
{
 return sxsm_gmv(q);
}
#undef SM_EMIT
