/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OPENDX FIELD data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_dx(sxsm_cursor*q){sxsm_token line,t[512];unsigned n;uint64_t left=0;bool data=false;while(sxsm_next(q,&line,t,512,&n,"#")){if(q->c->count>=24000)return true;if(data&&left){if(n>left||!sxsm_each(q,t,n,&sxsm_scalar_value))return false;left-=n;continue;}SM_EMIT(keyword,t[0]);if(sxsm_eq(q,t[0],"origin")||sxsm_eq(q,t[0],"delta")){if(n!=4||!sxsm_xyz(q,t+1,sxsm_eq(q,t[0],"origin")?1:3))return false;}else if(sxsm_eq(q,t[0],"object")&&n==8){SM_EMIT(entity_id,t[1]);if(!sxsm_each(q,t+2,3,&sxsm_keyword)||!sxsm_each(q,t+5,3,&sxsm_axis_count))return false;}else if(sxsm_eq(q,t[0],"object")&&n==12){SM_EMIT(entity_id,t[1]);for(unsigned i=2;i<n;i++){if(i==5)SM_EMIT(type_name,t[i]);else if(i==7)SM_EMIT(dimension,t[i]);else if(i==9){SM_EMIT(value_count,t[i]);if(!sxsm_number(q,t[i],&left))return false;}else SM_EMIT(keyword,t[i]);}data=true;}else if(sxsm_eq(q,t[0],"object")&&n>=4){int64_t stop=t[n-2].a;SM_EMIT(name,sxsm_trim(q,(sxsm_token){t[1].a,stop-t[1].a}));if(!sxsm_each(q,t+n-2,2,&sxsm_keyword))return false;}else if(sxsm_eq(q,t[0],"component")&&n==4){SM_EMIT(name,t[1]);SM_EMIT(keyword,t[2]);SM_EMIT(entity_id,t[3]);}else if(!sxsm_each(q,t+1,n-1,&sxsm_option_value))return false;}return true;}
bool sx_opendx_field_build(sxsm_cursor*q)
{
 return sxsm_dx(q);
}
#undef SM_EMIT
