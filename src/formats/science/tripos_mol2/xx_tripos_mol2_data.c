/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * tripos_mol2 data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_molecule_type_fields[]={SX_FIELD("molecule_type","char",0,0,SX_STRING)};
const sx_layout sxsa_molecule_type={0x60510012U,"science_molecule_type",sxsa_molecule_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_charge_type_fields[]={SX_FIELD("charge_type","char",0,0,SX_STRING)};
const sx_layout sxsa_charge_type={0x60510013U,"science_charge_type",sxsa_charge_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_section_fields[]={SX_FIELD("section","char",0,0,SX_STRING)};
const sx_layout sxsa_section={0x60510014U,"science_section",sxsa_section_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_substructure_count_fields[]={SX_FIELD("substructure_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_substructure_count={0x60510017U,"science_substructure_count",sxsa_substructure_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_set_count_fields[]={SX_FIELD("set_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_set_count={0x60510019U,"science_set_count",sxsa_set_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_atom_id_fields[]={SX_FIELD("mol2_atom_id","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol2_atom_id={0x605100a5U,"science_mol2_atom_id",sxsa_mol2_atom_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_substructure_id_fields[]={SX_FIELD("mol2_substructure_id","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol2_substructure_id={0x605100a6U,"science_mol2_substructure_id",sxsa_mol2_substructure_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_bond_id_fields[]={SX_FIELD("mol2_bond_id","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol2_bond_id={0x605100a7U,"science_mol2_bond_id",sxsa_mol2_bond_id_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_bond_origin_fields[]={SX_FIELD("mol2_bond_origin","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol2_bond_origin={0x605100a8U,"science_mol2_bond_origin",sxsa_mol2_bond_origin_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_bond_target_fields[]={SX_FIELD("mol2_bond_target","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol2_bond_target={0x605100a9U,"science_mol2_bond_target",sxsa_mol2_bond_target_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_root_atom_fields[]={SX_FIELD("mol2_root_atom","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol2_root_atom={0x605100aaU,"science_mol2_root_atom",sxsa_mol2_root_atom_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_dictionary_type_fields[]={SX_FIELD("mol2_dictionary_type","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol2_dictionary_type={0x605100abU,"science_mol2_dictionary_type",sxsa_mol2_dictionary_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_inter_bonds_fields[]={SX_FIELD("mol2_inter_bonds","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mol2_inter_bonds={0x605100acU,"science_mol2_inter_bonds",sxsa_mol2_inter_bonds_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_atom_name_fields[]={SX_FIELD("mol2_atom_name","char",0,0,SX_STRING)};
const sx_layout sxsa_mol2_atom_name={0x605100adU,"science_mol2_atom_name",sxsa_mol2_atom_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_atom_type_fields[]={SX_FIELD("mol2_atom_type","char",0,0,SX_STRING)};
const sx_layout sxsa_mol2_atom_type={0x605100aeU,"science_mol2_atom_type",sxsa_mol2_atom_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_substructure_name_fields[]={SX_FIELD("mol2_substructure_name","char",0,0,SX_STRING)};
const sx_layout sxsa_mol2_substructure_name={0x605100afU,"science_mol2_substructure_name",sxsa_mol2_substructure_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_bond_type_fields[]={SX_FIELD("mol2_bond_type","char",0,0,SX_STRING)};
const sx_layout sxsa_mol2_bond_type={0x605100b0U,"science_mol2_bond_type",sxsa_mol2_bond_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_substructure_type_fields[]={SX_FIELD("mol2_substructure_type","char",0,0,SX_STRING)};
const sx_layout sxsa_mol2_substructure_type={0x605100b1U,"science_mol2_substructure_type",sxsa_mol2_substructure_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_chain_fields[]={SX_FIELD("mol2_chain","char",0,0,SX_STRING)};
const sx_layout sxsa_mol2_chain={0x605100b2U,"science_mol2_chain",sxsa_mol2_chain_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_substructure_subtype_fields[]={SX_FIELD("mol2_substructure_subtype","char",0,0,SX_STRING)};
const sx_layout sxsa_mol2_substructure_subtype={0x605100b3U,"science_mol2_substructure_subtype",sxsa_mol2_substructure_subtype_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_status_fields[]={SX_FIELD("mol2_status","char",0,0,SX_STRING)};
const sx_layout sxsa_mol2_status={0x605100b4U,"science_mol2_status",sxsa_mol2_status_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_x_fields[]={SX_FIELD("mol2_x","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_mol2_x={0x605100b5U,"science_mol2_x",sxsa_mol2_x_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_y_fields[]={SX_FIELD("mol2_y","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_mol2_y={0x605100b6U,"science_mol2_y",sxsa_mol2_y_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_z_fields[]={SX_FIELD("mol2_z","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_mol2_z={0x605100b7U,"science_mol2_z",sxsa_mol2_z_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mol2_charge_fields[]={SX_FIELD("mol2_charge","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_mol2_charge={0x605100b8U,"science_mol2_charge",sxsa_mol2_charge_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
static bool sxsa_mol2(sxsa_cursor*q){sxsa_token line,t[16];unsigned phase=0,section=0;const sx_layout*counts[]={&sxsa_atom_count,&sxsa_bond_count,&sxsa_substructure_count,&sxsa_feature_count,&sxsa_set_count};const sx_layout*atom[]={&sxsa_mol2_atom_id,&sxsa_mol2_atom_name,&sxsa_mol2_x,&sxsa_mol2_y,&sxsa_mol2_z,&sxsa_mol2_atom_type,&sxsa_mol2_substructure_id,&sxsa_mol2_substructure_name,&sxsa_mol2_charge};const sx_layout*bond[]={&sxsa_mol2_bond_id,&sxsa_mol2_bond_origin,&sxsa_mol2_bond_target,&sxsa_mol2_bond_type};const sx_layout*sub[]={&sxsa_mol2_substructure_id,&sxsa_mol2_substructure_name,&sxsa_mol2_root_atom,&sxsa_mol2_substructure_type,&sxsa_mol2_dictionary_type,&sxsa_mol2_chain,&sxsa_mol2_substructure_subtype,&sxsa_mol2_inter_bonds,&sxsa_mol2_status};while(sxsa_line(q,&line)){if(q->c->count>=24000)return true;sxsa_token tr=sxsa_trim(q,line);if(!tr.z)continue;if(q->b[tr.a]=='@'){SA_EMIT(section,tr);section=sxsa_eq(q,tr,"@<TRIPOS>MOLECULE")?0:sxsa_eq(q,tr,"@<TRIPOS>ATOM")?1:sxsa_eq(q,tr,"@<TRIPOS>BOND")?2:3;continue;}unsigned n=sxsa_split(q,line,t,16,false);if(!section){if(phase==0)SA_EMIT(title,line);else if(phase==1){if(n<2||n>5||!sxsa_fields(q,t,n,counts,5))return false;}else if(phase==2)SA_EMIT(molecule_type,tr);else if(phase==3)SA_EMIT(charge_type,tr);else SA_EMIT(comment,line);phase++;}else if(!sxsa_fields(q,t,n,section==1?atom:section==2?bond:sub,section==2?4:9))return false;}return true;}
bool sx_tripos_mol2_build(sxsa_cursor*q)
{
 return sxsa_mol2(q);
}
#undef SA_EMIT
