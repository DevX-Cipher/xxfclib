/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OPENFOAM POINTS data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_foam(sxsm_cursor*q){sxsm_token t,key,value;if(!sxsm_lex(q,&t,false))return false;SM_EMIT(signature,t);if(!sxsm_expect(q,"{",false))return false;while(sxsm_lex(q,&key,false)){if(sxsm_eq(q,key,"}"))break;SM_EMIT(key,key);if(!sxsm_lex(q,&value,false)||!sxsm_emit(q,sxsm_eq(q,key,"version")?&sxsm_real_value:&sxsm_option_value,value)||!sxsm_expect(q,";",false))return false;}
 uint64_t n;if(!sxsm_count(q,&sxsm_node_count,&n,false)||!sxsm_expect(q,"(",false))return false;for(uint64_t i=0;i<n;i++){if(q->c->count>=24000)return true;if(!sxsm_expect(q,"(",false)||!sxsm_one(q,&sxsm_coordinate_x,false)||!sxsm_one(q,&sxsm_coordinate_y,false)||!sxsm_one(q,&sxsm_coordinate_z,false)||!sxsm_expect(q,")",false))return false;}return sxsm_expect(q,")",false);}
bool sx_openfoam_points_build(sxsm_cursor*q)
{
 return sxsm_foam(q);
}
#undef SM_EMIT
