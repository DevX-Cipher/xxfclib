/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * turbomole_coord data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_turbomole_units_fields[]={SX_FIELD("turbomole_units","char",0,0,SX_STRING)};
const sx_layout sxsa_turbomole_units={0x605100d7U,"science_turbomole_units",sxsa_turbomole_units_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_turbomole_bohr_x_fields[]={SX_FIELD("turbomole_bohr_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_turbomole_bohr_x={0x605100d8U,"science_turbomole_bohr_x",sxsa_turbomole_bohr_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_turbomole_bohr_y_fields[]={SX_FIELD("turbomole_bohr_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_turbomole_bohr_y={0x605100d9U,"science_turbomole_bohr_y",sxsa_turbomole_bohr_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_turbomole_bohr_z_fields[]={SX_FIELD("turbomole_bohr_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_turbomole_bohr_z={0x605100daU,"science_turbomole_bohr_z",sxsa_turbomole_bohr_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_turbomole_angstrom_x_fields[]={SX_FIELD("turbomole_angstrom_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_turbomole_angstrom_x={0x605100dbU,"science_turbomole_angstrom_x",sxsa_turbomole_angstrom_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_turbomole_angstrom_y_fields[]={SX_FIELD("turbomole_angstrom_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_turbomole_angstrom_y={0x605100dcU,"science_turbomole_angstrom_y",sxsa_turbomole_angstrom_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_turbomole_angstrom_z_fields[]={SX_FIELD("turbomole_angstrom_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_turbomole_angstrom_z={0x605100ddU,"science_turbomole_angstrom_z",sxsa_turbomole_angstrom_z_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
static bool sxsa_turbomole(sxsa_cursor*q){sxsa_token line,t[4];bool ang=false;while(sxsa_line(q,&line)){if(q->c->count>=24000)return true;line=sxsa_trim(q,line);if(!line.z)continue;int64_t hash=0;while(hash<line.z&&q->b[line.a+hash]!='#')hash++;if(hash<line.z){SA_EMIT(comment,((sxsa_token){line.a+hash,line.z-hash}));line.z=hash;line=sxsa_trim(q,line);if(!line.z)continue;}unsigned n=sxsa_split(q,line,t,4,false);if(!n||n>4)return false;if(q->b[line.a]=='$'){SA_EMIT(record_type,t[0]);if(n>1){SA_EMIT(turbomole_units,t[1]);ang=sxsa_eq(q,t[1],"angs");}continue;}const sx_layout*atom[]={ang?&sxsa_turbomole_angstrom_x:&sxsa_turbomole_bohr_x,ang?&sxsa_turbomole_angstrom_y:&sxsa_turbomole_bohr_y,ang?&sxsa_turbomole_angstrom_z:&sxsa_turbomole_bohr_z,&sxsa_element};if(n!=4||!sxsa_fields(q,t,4,atom,4))return false;}return true;}
bool sx_turbomole_coord_build(sxsa_cursor*q)
{
 return sxsa_turbomole(q);
}
#undef SA_EMIT
