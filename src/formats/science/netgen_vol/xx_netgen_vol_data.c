/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NETGEN VOL data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_region_id_fields[]={SX_FIELD("region_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_region_id={0x6063001dU,"mesh_region_id",sxsm_region_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_surface_id_fields[]={SX_FIELD("surface_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_surface_id={0x60630066U,"mesh_surface_id",sxsm_surface_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_inside_domain_fields[]={SX_FIELD("inside_domain","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_inside_domain={0x60630068U,"mesh_inside_domain",sxsm_inside_domain_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_outside_domain_fields[]={SX_FIELD("outside_domain","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_outside_domain={0x60630069U,"mesh_outside_domain",sxsm_outside_domain_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_region_fields[]={SX_FIELD("edge_region","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_edge_region={0x6063006aU,"mesh_edge_region",sxsm_edge_region_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_triangle_fields[]={SX_FIELD("edge_triangle","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_edge_triangle={0x6063006bU,"mesh_edge_triangle",sxsm_edge_triangle_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_surface_fields[]={SX_FIELD("edge_surface","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_edge_surface={0x6063006cU,"mesh_edge_surface",sxsm_edge_surface_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_id_fields[]={SX_FIELD("edge_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_edge_id={0x6063006dU,"mesh_edge_id",sxsm_edge_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_edge_distance_fields[]={SX_FIELD("edge_distance","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_edge_distance={0x6063006eU,"mesh_edge_distance",sxsm_edge_distance_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_geometry_type_fields[]={SX_FIELD("geometry_type","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_geometry_type={0x6063006fU,"mesh_geometry_type",sxsm_geometry_type_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_netgen(sxsm_cursor*q){sxsm_token line,t[40];unsigned n;if(!sxsm_next(q,&line,t,40,&n,"#"))return false;SM_EMIT(signature,t[0]);while(sxsm_next(q,&line,t,40,&n,"#")){if(q->c->count>=24000)return true;SM_EMIT(section,t[0]);if(sxsm_eq(q,t[0],"endmesh"))return true;unsigned mode=sxsm_eq(q,t[0],"dimension")?1:sxsm_eq(q,t[0],"geomtype")?2:sxsm_eq(q,t[0],"points")?3:sxsm_eq(q,t[0],"surfaceelements")?4:sxsm_eq(q,t[0],"volumeelements")?5:sxsm_eq(q,t[0],"edgesegments")?6:sxsm_eq(q,t[0],"edgesegmentsgi2")?7:sxsm_eq(q,t[0],"face_colours")?8:0;uint64_t count;if(!mode||!sxsm_next(q,&line,t,40,&n,"#")||n!=1||!sxsm_number(q,t[0],&count)||count>1000000)return false;if(!sxsm_emit(q,mode==1?&sxsm_dimension:mode==2?&sxsm_geometry_type:mode==3?&sxsm_node_count:mode==8?&sxsm_value_count:&sxsm_element_count,t[0]))return false;if(mode<=2)continue;
 for(uint64_t i=0;i<count;i++){if(q->c->count>=24000)return true;if(!sxsm_next(q,&line,t,40,&n,"#"))return false;if(mode==3){if(n!=3||!sxsm_xyz(q,t,0))return false;}else if(mode==4){if(n<6)return false;const sx_layout*cols[]={&sxsm_surface_id,&sxsm_boundary_id,&sxsm_inside_domain,&sxsm_outside_domain,&sxsm_component_count};if(!sxsm_fields(q,t,5,cols,5)||!sxsm_each(q,t+5,n-5,&sxsm_node_index))return false;}else if(mode==5){if(n<3)return false;SM_EMIT(region_id,t[0]);SM_EMIT(component_count,t[1]);if(!sxsm_each(q,t+2,n-2,&sxsm_node_index))return false;}else if(mode==8){if(n!=4)return false;SM_EMIT(surface_id,t[0]);const sx_layout*cols[]={&sxsm_red,&sxsm_green,&sxsm_blue};if(!sxsm_fields(q,t+1,3,cols,3))return false;}else{if(n!=(mode==6?4U:12U))return false;for(unsigned j=0;j<n;j++)if(!sxsm_emit(q,j==0?&sxsm_edge_region:j==1?&sxsm_integer_value:j==2||j==3?&sxsm_node_index:j==4||j==5?&sxsm_edge_triangle:j==6||j==7?&sxsm_edge_surface:j==9||j==11?&sxsm_edge_distance:&sxsm_edge_id,t[j]))return false;}}}return true;}
bool sx_netgen_vol_build(sxsm_cursor*q)
{
 return sxsm_netgen(q);
}
#undef SM_EMIT
