/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NASTRAN BULK data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_coordinate_system_fields[]={SX_FIELD("coordinate_system","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_coordinate_system={0x6063007cU,"mesh_coordinate_system",sxsm_coordinate_system_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_displacement_coordinate_system_fields[]={SX_FIELD("displacement_coordinate_system","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_displacement_coordinate_system={0x6063007dU,"mesh_displacement_coordinate_system",sxsm_displacement_coordinate_system_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_permanent_constraints_fields[]={SX_FIELD("permanent_constraints","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsm_permanent_constraints={0x6063007eU,"mesh_permanent_constraints",sxsm_permanent_constraints_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_superelement_id_fields[]={SX_FIELD("superelement_id","ascii_signed",0,0,SX_ID)};
const sx_layout sxsm_superelement_id={0x6063007fU,"mesh_superelement_id",sxsm_superelement_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_nastran_x_fields[]={SX_FIELD("nastran_x","ascii_nastran_real",0,0,SX_NONE)};
const sx_layout sxsm_nastran_x={0x60630080U,"mesh_nastran_x",sxsm_nastran_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_nastran_y_fields[]={SX_FIELD("nastran_y","ascii_nastran_real",0,0,SX_NONE)};
const sx_layout sxsm_nastran_y={0x60630081U,"mesh_nastran_y",sxsm_nastran_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_nastran_z_fields[]={SX_FIELD("nastran_z","ascii_nastran_real",0,0,SX_NONE)};
const sx_layout sxsm_nastran_z={0x60630082U,"mesh_nastran_z",sxsm_nastran_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_bar_orientation_x_fields[]={SX_FIELD("bar_orientation_x","ascii_nastran_real",0,0,SX_NONE)};
const sx_layout sxsm_bar_orientation_x={0x60630083U,"mesh_bar_orientation_x",sxsm_bar_orientation_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_bar_orientation_y_fields[]={SX_FIELD("bar_orientation_y","ascii_nastran_real",0,0,SX_NONE)};
const sx_layout sxsm_bar_orientation_y={0x60630084U,"mesh_bar_orientation_y",sxsm_bar_orientation_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_bar_orientation_z_fields[]={SX_FIELD("bar_orientation_z","ascii_nastran_real",0,0,SX_NONE)};
const sx_layout sxsm_bar_orientation_z={0x60630085U,"mesh_bar_orientation_z",sxsm_bar_orientation_z_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_nastran(sxsm_cursor*q){sxsm_token line,t[24];unsigned n;while(sxsm_line(q,&line)){if(q->c->count>=24000)return true;int64_t p=0;bool comma=false;while(p<line.z&&q->b[line.a+p]!='$'){if(q->b[line.a+p]==',')comma=true;p++;}if(p<line.z){SM_EMIT(comment,((sxsm_token){line.a+p,line.z-p}));line.z=p;}sxsm_token trimmed=sxsm_trim(q,line);if(!trimmed.z)continue;if(trimmed.z>=5&&!xx_rt_memcmp(q->b+trimmed.a,"BEGIN",5)){SM_EMIT(keyword,line);continue;}if(sxsm_eq(q,trimmed,"ENDDATA")){SM_EMIT(keyword,line);continue;}
 if(comma)n=sxsm_csv(q,line,t,24);else{n=0;for(int64_t at=0;at<line.z;at+=8){if(n==24)return false;t[n++]=sxsm_trim(q,(sxsm_token){line.a+at,line.z-at<8?line.z-at:8});}}while(n&&!t[n-1].z)n--;if(n<2||n>24)return false;SM_EMIT(keyword,t[0]);bool grid=sxsm_eq(q,t[0],"GRID"),bar=sxsm_eq(q,t[0],"CBAR");if(grid){if(n<6)return false;SM_EMIT(node_id,t[1]);SM_EMIT(coordinate_system,t[2]);SM_EMIT(nastran_x,t[3]);SM_EMIT(nastran_y,t[4]);SM_EMIT(nastran_z,t[5]);const sx_layout*extra[]={&sxsm_displacement_coordinate_system,&sxsm_permanent_constraints,&sxsm_superelement_id};if(!sxsm_fields(q,t+6,n-6,extra,3))return false;}else{if(n<5||(bar&&n!=8))return false;SM_EMIT(element_id,t[1]);SM_EMIT(property_id,t[2]);if(!sxsm_each(q,t+3,n-3-(bar?3:0),&sxsm_node_index))return false;if(bar){if(n!=8)return false;SM_EMIT(bar_orientation_x,t[5]);SM_EMIT(bar_orientation_y,t[6]);SM_EMIT(bar_orientation_z,t[7]);}}}return true;}
bool sx_nastran_bulk_build(sxsm_cursor*q)
{
 return sxsm_nastran(q);
}
#undef SM_EMIT
