/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VTK LEGACY data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_vtk(sxsm_cursor*q){sxsm_token line,t[16];unsigned n;if(!sxsm_line(q,&line))return false;SM_EMIT(signature,line);if(!sxsm_line(q,&line))return false;SM_EMIT(title,line);while(sxsm_next(q,&line,t,16,&n,"")){if(q->c->count>=24000)return true;SM_EMIT(keyword,t[0]);if(sxsm_eq(q,t[0],"BINARY"))continue;if(sxsm_eq(q,t[0],"DATASET")){if(n!=2)return false;SM_EMIT(type_name,t[1]);}else if(sxsm_eq(q,t[0],"DIMENSIONS")){if(n!=4||!sxsm_each(q,t+1,3,&sxsm_axis_count))return false;}else if(sxsm_eq(q,t[0],"ORIGIN")||sxsm_eq(q,t[0],"SPACING")){if(n!=4||!sxsm_xyz(q,t+1,sxsm_eq(q,t[0],"ORIGIN")?1:2))return false;}else if(sxsm_eq(q,t[0],"POINT_DATA")||sxsm_eq(q,t[0],"CELL_DATA")){if(n!=2)return false;SM_EMIT(value_count,t[1]);}else if(sxsm_eq(q,t[0],"SCALARS")){if(n!=3&&n!=4)return false;SM_EMIT(name,t[1]);SM_EMIT(type_name,t[2]);if(n==4)SM_EMIT(component_count,t[3]);}else if(sxsm_eq(q,t[0],"LOOKUP_TABLE")){if(n!=2)return false;SM_EMIT(name,t[1]);return true;}else return false;}return false;}
bool sx_vtk_legacy_build(sxsm_cursor*q)
{
 return sxsm_vtk(q);
}
#undef SM_EMIT
