/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * protein_pdb data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_pdb_atom_name_fields[]={SX_FIELD("pdb_atom_name","char",0,0,SX_STRING)};
const sx_layout sxsa_pdb_atom_name={0x60510056U,"science_pdb_atom_name",sxsa_pdb_atom_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_altloc_fields[]={SX_FIELD("pdb_altloc","char",0,0,SX_STRING)};
const sx_layout sxsa_pdb_altloc={0x60510057U,"science_pdb_altloc",sxsa_pdb_altloc_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_residue_fields[]={SX_FIELD("pdb_residue","char",0,0,SX_STRING)};
const sx_layout sxsa_pdb_residue={0x60510058U,"science_pdb_residue",sxsa_pdb_residue_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_chain_fields[]={SX_FIELD("pdb_chain","char",0,0,SX_STRING)};
const sx_layout sxsa_pdb_chain={0x60510059U,"science_pdb_chain",sxsa_pdb_chain_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_icode_fields[]={SX_FIELD("pdb_icode","char",0,0,SX_STRING)};
const sx_layout sxsa_pdb_icode={0x6051005aU,"science_pdb_icode",sxsa_pdb_icode_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_element_fields[]={SX_FIELD("pdb_element","char",0,0,SX_STRING)};
const sx_layout sxsa_pdb_element={0x6051005bU,"science_pdb_element",sxsa_pdb_element_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_charge_fields[]={SX_FIELD("pdb_charge","char",0,0,SX_STRING)};
const sx_layout sxsa_pdb_charge={0x6051005cU,"science_pdb_charge",sxsa_pdb_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_serial_fields[]={SX_FIELD("pdb_serial","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_pdb_serial={0x6051005dU,"science_pdb_serial",sxsa_pdb_serial_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_residue_sequence_fields[]={SX_FIELD("pdb_residue_sequence","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_pdb_residue_sequence={0x6051005eU,"science_pdb_residue_sequence",sxsa_pdb_residue_sequence_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_x_fields[]={SX_FIELD("pdb_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_pdb_x={0x6051005fU,"science_pdb_x",sxsa_pdb_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_y_fields[]={SX_FIELD("pdb_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_pdb_y={0x60510060U,"science_pdb_y",sxsa_pdb_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_z_fields[]={SX_FIELD("pdb_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_pdb_z={0x60510061U,"science_pdb_z",sxsa_pdb_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_occupancy_fields[]={SX_FIELD("pdb_occupancy","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_pdb_occupancy={0x60510062U,"science_pdb_occupancy",sxsa_pdb_occupancy_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_temperature_fields[]={SX_FIELD("pdb_temperature","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_pdb_temperature={0x60510063U,"science_pdb_temperature",sxsa_pdb_temperature_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_u11_fields[]={SX_FIELD("pdb_u11","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_pdb_u11={0x60510064U,"science_pdb_u11",sxsa_pdb_u11_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_u22_fields[]={SX_FIELD("pdb_u22","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_pdb_u22={0x60510065U,"science_pdb_u22",sxsa_pdb_u22_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_u33_fields[]={SX_FIELD("pdb_u33","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_pdb_u33={0x60510066U,"science_pdb_u33",sxsa_pdb_u33_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_u12_fields[]={SX_FIELD("pdb_u12","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_pdb_u12={0x60510067U,"science_pdb_u12",sxsa_pdb_u12_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_u13_fields[]={SX_FIELD("pdb_u13","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_pdb_u13={0x60510068U,"science_pdb_u13",sxsa_pdb_u13_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_pdb_u23_fields[]={SX_FIELD("pdb_u23","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_pdb_u23={0x60510069U,"science_pdb_u23",sxsa_pdb_u23_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
#define SA_COL(n,o,z) do{if(!sxsa_column(q,&sxsa_##n,line,(o),(z)))return false;}while(0)
static bool sxsa_pdb(sxsa_cursor*q){sxsa_token line;while(sxsa_line(q,&line)){if(q->c->count>=24000)return true;if(line.z<3)return false;sxsa_token k=sxsa_trim(q,(sxsa_token){line.a,line.z<6?line.z:6});SA_EMIT(record_type,k);bool atom=sxsa_eq(q,k,"ATOM")||sxsa_eq(q,k,"HETATM"),aniso=sxsa_eq(q,k,"ANISOU"),ter=sxsa_eq(q,k,"TER");if(atom||aniso||ter){SA_COL(pdb_serial,6,5);if(!ter){SA_COL(pdb_atom_name,12,4);SA_COL(pdb_altloc,16,1);}SA_COL(pdb_residue,17,3);SA_COL(pdb_chain,21,1);SA_COL(pdb_residue_sequence,22,4);SA_COL(pdb_icode,26,1);if(atom){SA_COL(pdb_x,30,8);SA_COL(pdb_y,38,8);SA_COL(pdb_z,46,8);SA_COL(pdb_occupancy,54,6);SA_COL(pdb_temperature,60,6);}if(aniso){const sx_layout*u[]={&sxsa_pdb_u11,&sxsa_pdb_u22,&sxsa_pdb_u33,&sxsa_pdb_u12,&sxsa_pdb_u13,&sxsa_pdb_u23};for(unsigned i=0;i<6;i++)if(!sxsa_column(q,u[i],line,28+7*i,7))return false;}if(line.z>=78)SA_COL(pdb_element,76,2);if(line.z>=80)SA_COL(pdb_charge,78,2);}else if(sxsa_eq(q,k,"CONECT")){for(unsigned o=6;o+5<=(uint64_t)line.z;o+=5)SA_COL(pdb_serial,o,5);}else if(line.z>6)SA_EMIT(comment,((sxsa_token){line.a+6,line.z-6}));}return true;}
bool sx_protein_pdb_build(sxsa_cursor*q)
{
 return sxsa_pdb(q);
}
#undef SA_EMIT
#undef SA_COL
