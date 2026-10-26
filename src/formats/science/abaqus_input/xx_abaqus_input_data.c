/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ABAQUS INPUT data structures, moved out of the sciencemesh schema family. */
#include "../../xx_format_schema_sciencemesh.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsm_surface_face_fields[]={SX_FIELD("surface_face","char",0,0,SX_STRING)};
const sx_layout sxsm_surface_face={0x6063007aU,"mesh_surface_face",sxsm_surface_face_fields,1,SX_LE};
#define SM_EMIT(n,t) do{if(!sxsm_emit(q,&sxsm_##n,(t)))return false;}while(0)
static bool sxsm_abaqus(sxsm_cursor*q){sxsm_token line,t[32];unsigned n,mode=0;while(sxsm_line(q,&line)){if(q->c->count>=24000)return true;line=sxsm_trim(q,line);if(!line.z)continue;if(line.z>=2&&q->b[line.a]=='*'&&q->b[line.a+1]=='*'){SM_EMIT(comment,line);continue;}n=sxsm_csv(q,line,t,32);if(!n||n>32)return false;if(q->b[line.a]=='*'){SM_EMIT(section,t[0]);mode=sxsm_ci(q,t[0],"*heading")?1:sxsm_ci(q,t[0],"*node")?2:sxsm_ci(q,t[0],"*element")?3:sxsm_ci(q,t[0],"*nset")?4:sxsm_ci(q,t[0],"*elset")?5:sxsm_ci(q,t[0],"*surface")?6:0;for(unsigned i=1;i<n;i++){sxsm_token key,value;if(!sxsm_keyvalue(q,t[i],'=',&key,&value))return false;SM_EMIT(key,key);SM_EMIT(option_value,value);}continue;}
 if(mode==1){SM_EMIT(title,line);continue;}while(n&&!t[n-1].z)n--;if(!n)return false;if(mode==2){if(n!=4)return false;SM_EMIT(node_id,t[0]);if(!sxsm_xyz(q,t+1,0))return false;}else if(mode==3){SM_EMIT(element_id,t[0]);if(!sxsm_each(q,t+1,n-1,&sxsm_node_index))return false;}else if(mode==4||mode==5){if(!sxsm_each(q,t,n,mode==4?&sxsm_node_index:&sxsm_element_id))return false;}else if(mode==6){if(n!=2)return false;SM_EMIT(element_id,t[0]);SM_EMIT(surface_face,t[1]);}else return false;}return true;}
bool sx_abaqus_input_build(sxsm_cursor*q)
{
 return sxsm_abaqus(q);
}
#undef SM_EMIT
