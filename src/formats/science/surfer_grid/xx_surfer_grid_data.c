/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SURFER GRID data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_scalar_min_fields[]={SX_FIELD("scalar_min","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_scalar_min={0x60630034U,"mesh_scalar_min",sxsm_scalar_min_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsm_scalar_max_fields[]={SX_FIELD("scalar_max","ascii_real",0,0,SX_NONE)};
const sx_layout sxsm_scalar_max={0x60630035U,"mesh_scalar_max",sxsm_scalar_max_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_surfer(sxsm_cursor*q){sxsm_token line,t[512];unsigned n;if(!sxsm_next(q,&line,t,512,&n,"#")||n!=1)return false;SM_EMIT(signature,t[0]);if(!sxsm_next(q,&line,t,512,&n,"#")||n!=2||!sxsm_each(q,t,2,&sxsm_axis_count))return false;const sx_layout*lo[]={&sxsm_box_min_x,&sxsm_box_min_y,&sxsm_scalar_min},*hi[]={&sxsm_box_max_x,&sxsm_box_max_y,&sxsm_scalar_max};for(unsigned i=0;i<3;i++){if(!sxsm_next(q,&line,t,512,&n,"#")||n!=2||!sxsm_emit(q,lo[i],t[0])||!sxsm_emit(q,hi[i],t[1]))return false;}while(sxsm_next(q,&line,t,512,&n,"#")){if(q->c->count>=24000)return true;if(!sxsm_each(q,t,n,&sxsm_scalar_value))return false;}return true;}
bool sx_surfer_grid_build(sxsm_cursor*q)
{
 return sxsm_surfer(q);
}
#undef SM_EMIT
