/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * amber_restart data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_amber_time_fields[]={SX_FIELD("amber_time","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_amber_time={0x605100c6U,"science_amber_time",sxsa_amber_time_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_amber_coordinate_fields[]={SX_FIELD("amber_coordinate","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_amber_coordinate={0x605100c7U,"science_amber_coordinate",sxsa_amber_coordinate_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_amber_velocity_fields[]={SX_FIELD("amber_velocity","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_amber_velocity={0x605100c8U,"science_amber_velocity",sxsa_amber_velocity_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_amber_box_length_fields[]={SX_FIELD("amber_box_length","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_amber_box_length={0x605100c9U,"science_amber_box_length",sxsa_amber_box_length_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_amber_box_angle_fields[]={SX_FIELD("amber_box_angle","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_amber_box_angle={0x605100caU,"science_amber_box_angle",sxsa_amber_box_angle_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
static bool sxsa_amber(sxsa_cursor*q){sxsa_token line,t[2];uint64_t atoms;if(!sxsa_line(q,&line))return false;SA_EMIT(title,line);if(!sxsa_line(q,&line))return false;unsigned n=sxsa_split(q,line,t,2,false);if(!n||n>2||!sxsa_number(q,t[0],&atoms)||atoms>100000)return false;SA_EMIT(atom_count,t[0]);if(n>1)SA_EMIT(amber_time,t[1]);int64_t data=q->p;uint64_t values=0;while(sxsa_line(q,&line)){if(line.z%12)return false;values+=(uint64_t)line.z/12;}uint64_t xyz=atoms*3,tail=values>=xyz?values-xyz:0;if(values<xyz)return false;bool velocities=tail==xyz||tail==xyz+6;uint64_t i=0;q->p=data;while(sxsa_line(q,&line)){for(int64_t o=0;o+12<=line.z;o+=12,i++){const sx_layout*l=i<xyz?&sxsa_amber_coordinate:velocities&&i<xyz*2?&sxsa_amber_velocity:(i-(velocities?xyz*2:xyz))<3?&sxsa_amber_box_length:&sxsa_amber_box_angle;if(!sxsa_emit(q,l,(sxsa_token){line.a+o,12}))return false;}if(q->c->count>=24000)return true;}return true;}
bool sx_amber_restart_build(sxsa_cursor*q)
{
 return sxsa_amber(q);
}
#undef SA_EMIT
