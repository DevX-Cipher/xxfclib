/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * mdl_molfile data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_mol_program_fields[]={SX_FIELD("mol_program","char",0,0,SX_STRING)};
const sx_layout sxsa_mol_program={0x60510080U,"science_mol_program",sxsa_mol_program_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_comment_fields[]={SX_FIELD("mol_comment","char",0,0,SX_STRING)};
const sx_layout sxsa_mol_comment={0x60510081U,"science_mol_comment",sxsa_mol_comment_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_version_fields[]={SX_FIELD("mol_version","char",0,0,SX_STRING)};
const sx_layout sxsa_mol_version={0x60510082U,"science_mol_version",sxsa_mol_version_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_atom_list_count_fields[]={SX_FIELD("mol_atom_list_count","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_atom_list_count={0x60510083U,"science_mol_atom_list_count",sxsa_mol_atom_list_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_obsolete_count_fields[]={SX_FIELD("mol_obsolete_count","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_obsolete_count={0x60510084U,"science_mol_obsolete_count",sxsa_mol_obsolete_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_chiral_flag_fields[]={SX_FIELD("mol_chiral_flag","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_chiral_flag={0x60510085U,"science_mol_chiral_flag",sxsa_mol_chiral_flag_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_stext_count_fields[]={SX_FIELD("mol_stext_count","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_stext_count={0x60510086U,"science_mol_stext_count",sxsa_mol_stext_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_obsolete_18_fields[]={SX_FIELD("mol_obsolete_18","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_obsolete_18={0x60510087U,"science_mol_obsolete_18",sxsa_mol_obsolete_18_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_obsolete_21_fields[]={SX_FIELD("mol_obsolete_21","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_obsolete_21={0x60510088U,"science_mol_obsolete_21",sxsa_mol_obsolete_21_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_obsolete_24_fields[]={SX_FIELD("mol_obsolete_24","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_obsolete_24={0x60510089U,"science_mol_obsolete_24",sxsa_mol_obsolete_24_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_obsolete_27_fields[]={SX_FIELD("mol_obsolete_27","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_obsolete_27={0x6051008aU,"science_mol_obsolete_27",sxsa_mol_obsolete_27_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_property_count_fields[]={SX_FIELD("mol_property_count","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_property_count={0x6051008bU,"science_mol_property_count",sxsa_mol_property_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_x_fields[]={SX_FIELD("mol_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_mol_x={0x6051008cU,"science_mol_x",sxsa_mol_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_y_fields[]={SX_FIELD("mol_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_mol_y={0x6051008dU,"science_mol_y",sxsa_mol_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_z_fields[]={SX_FIELD("mol_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_mol_z={0x6051008eU,"science_mol_z",sxsa_mol_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_mass_difference_fields[]={SX_FIELD("mol_mass_difference","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_mass_difference={0x6051008fU,"science_mol_mass_difference",sxsa_mol_mass_difference_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_charge_code_fields[]={SX_FIELD("mol_charge_code","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_charge_code={0x60510090U,"science_mol_charge_code",sxsa_mol_charge_code_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_stereo_parity_fields[]={SX_FIELD("mol_stereo_parity","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_stereo_parity={0x60510091U,"science_mol_stereo_parity",sxsa_mol_stereo_parity_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_hydrogen_count_fields[]={SX_FIELD("mol_hydrogen_count","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_hydrogen_count={0x60510092U,"science_mol_hydrogen_count",sxsa_mol_hydrogen_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_stereo_care_fields[]={SX_FIELD("mol_stereo_care","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_stereo_care={0x60510093U,"science_mol_stereo_care",sxsa_mol_stereo_care_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_valence_fields[]={SX_FIELD("mol_valence","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_valence={0x60510094U,"science_mol_valence",sxsa_mol_valence_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_h0_designator_fields[]={SX_FIELD("mol_h0_designator","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_h0_designator={0x60510095U,"science_mol_h0_designator",sxsa_mol_h0_designator_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_unused_1_fields[]={SX_FIELD("mol_unused_1","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_unused_1={0x60510096U,"science_mol_unused_1",sxsa_mol_unused_1_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_unused_2_fields[]={SX_FIELD("mol_unused_2","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_unused_2={0x60510097U,"science_mol_unused_2",sxsa_mol_unused_2_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_mapping_number_fields[]={SX_FIELD("mol_mapping_number","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_mapping_number={0x60510098U,"science_mol_mapping_number",sxsa_mol_mapping_number_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_inversion_fields[]={SX_FIELD("mol_inversion","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_inversion={0x60510099U,"science_mol_inversion",sxsa_mol_inversion_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_exact_change_fields[]={SX_FIELD("mol_exact_change","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_exact_change={0x6051009aU,"science_mol_exact_change",sxsa_mol_exact_change_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_bond_atom_1_fields[]={SX_FIELD("mol_bond_atom_1","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_bond_atom_1={0x6051009bU,"science_mol_bond_atom_1",sxsa_mol_bond_atom_1_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_bond_atom_2_fields[]={SX_FIELD("mol_bond_atom_2","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_bond_atom_2={0x6051009cU,"science_mol_bond_atom_2",sxsa_mol_bond_atom_2_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_bond_type_fields[]={SX_FIELD("mol_bond_type","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_bond_type={0x6051009dU,"science_mol_bond_type",sxsa_mol_bond_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_bond_stereo_fields[]={SX_FIELD("mol_bond_stereo","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_bond_stereo={0x6051009eU,"science_mol_bond_stereo",sxsa_mol_bond_stereo_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_bond_unused_fields[]={SX_FIELD("mol_bond_unused","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_bond_unused={0x6051009fU,"science_mol_bond_unused",sxsa_mol_bond_unused_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_bond_topology_fields[]={SX_FIELD("mol_bond_topology","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_bond_topology={0x605100a0U,"science_mol_bond_topology",sxsa_mol_bond_topology_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_bond_reaction_fields[]={SX_FIELD("mol_bond_reaction","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_bond_reaction={0x605100a1U,"science_mol_bond_reaction",sxsa_mol_bond_reaction_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_property_fields[]={SX_FIELD("mol_property","char",0,0,SX_STRING)};
const sx_layout sxsa_mol_property={0x605100a2U,"science_mol_property",sxsa_mol_property_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_property_atom_fields[]={SX_FIELD("mol_property_atom","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_property_atom={0x605100a3U,"science_mol_property_atom",sxsa_mol_property_atom_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol_property_value_fields[]={SX_FIELD("mol_property_value","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol_property_value={0x605100a4U,"science_mol_property_value",sxsa_mol_property_value_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
#define SA_COL(n,o,z) do{if(!sxsa_column(q,&sxsa_##n,line,(o),(z)))return false;}while(0)
static bool sxsa_mol(sxsa_cursor*q){sxsa_token line,t[20];uint64_t atoms,bonds;for(unsigned i=0;i<3;i++){if(!sxsa_line(q,&line))return false;if(!sxsa_emit(q,i==0?&sxsa_title:i==1?&sxsa_mol_program:&sxsa_mol_comment,line))return false;}if(!sxsa_line(q,&line)||line.z<39||!sxsa_number(q,(sxsa_token){line.a,3},&atoms)||!sxsa_number(q,(sxsa_token){line.a+3,3},&bonds))return false;const sx_layout*counts[]={&sxsa_atom_count,&sxsa_bond_count,&sxsa_mol_atom_list_count,&sxsa_mol_obsolete_count,&sxsa_mol_chiral_flag,&sxsa_mol_stext_count,&sxsa_mol_obsolete_18,&sxsa_mol_obsolete_21,&sxsa_mol_obsolete_24,&sxsa_mol_obsolete_27,&sxsa_mol_property_count};for(unsigned i=0;i<11;i++)if(!sxsa_column(q,counts[i],line,3*i,3))return false;SA_COL(mol_version,34,5);
 const sx_layout*atom[]={&sxsa_mol_charge_code,&sxsa_mol_stereo_parity,&sxsa_mol_hydrogen_count,&sxsa_mol_stereo_care,&sxsa_mol_valence,&sxsa_mol_h0_designator,&sxsa_mol_unused_1,&sxsa_mol_unused_2,&sxsa_mol_mapping_number,&sxsa_mol_inversion,&sxsa_mol_exact_change};for(uint64_t i=0;i<atoms;i++){if(!sxsa_line(q,&line))return false;SA_COL(mol_x,0,10);SA_COL(mol_y,10,10);SA_COL(mol_z,20,10);SA_COL(element,31,3);if(line.z>=36)SA_COL(mol_mass_difference,34,2);for(unsigned j=0;j<11&&39+3*j<=(uint64_t)line.z;j++)if(!sxsa_column(q,atom[j],line,36+3*j,3))return false;if(q->c->count>=24000)return true;}
 const sx_layout*bond[]={&sxsa_mol_bond_atom_1,&sxsa_mol_bond_atom_2,&sxsa_mol_bond_type,&sxsa_mol_bond_stereo,&sxsa_mol_bond_unused,&sxsa_mol_bond_topology,&sxsa_mol_bond_reaction};for(uint64_t i=0;i<bonds;i++){if(!sxsa_line(q,&line))return false;for(unsigned j=0;j<7&&3+3*j<=(uint64_t)line.z;j++)if(!sxsa_column(q,bond[j],line,3*j,3))return false;}
 while(sxsa_line(q,&line)){unsigned n=sxsa_split(q,line,t,20,false);if(!n)continue;if(n<2)return false;SA_EMIT(record_type,t[0]);SA_EMIT(mol_property,t[1]);if(sxsa_eq(q,t[1],"END"))break;if(n<3)return false;SA_EMIT(feature_count,t[2]);for(unsigned i=3;i+1<n;i+=2){SA_EMIT(mol_property_atom,t[i]);SA_EMIT(mol_property_value,t[i+1]);}}return true;}
bool sx_mdl_molfile_build(sxsa_cursor*q)
{
 return sxsa_mol(q);
}
#undef SA_EMIT
#undef SA_COL
