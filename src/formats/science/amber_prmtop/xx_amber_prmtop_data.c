/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * amber_prmtop data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_format_string_fields[]={SX_FIELD("format_string","char",0,0,SX_STRING)};
const sx_layout sxsch_format_string={0x60610012U,"chemistry_format_string",sxsch_format_string_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_flag_fields[]={SX_FIELD("amber_flag","char",0,0,SX_STRING)};
const sx_layout sxsch_amber_flag={0x6061007dU,"chemistry_amber_flag",sxsch_amber_flag_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_atom_name_fields[]={SX_FIELD("amber_atom_name","char",0,0,SX_STRING)};
const sx_layout sxsch_amber_atom_name={0x6061007eU,"chemistry_amber_atom_name",sxsch_amber_atom_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_residue_label_fields[]={SX_FIELD("amber_residue_label","char",0,0,SX_STRING)};
const sx_layout sxsch_amber_residue_label={0x6061007fU,"chemistry_amber_residue_label",sxsch_amber_residue_label_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_atom_type_index_fields[]={SX_FIELD("amber_atom_type_index","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_amber_atom_type_index={0x60610080U,"chemistry_amber_atom_type_index",sxsch_amber_atom_type_index_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_excluded_count_fields[]={SX_FIELD("amber_excluded_count","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_excluded_count={0x60610081U,"chemistry_amber_excluded_count",sxsch_amber_excluded_count_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_residue_pointer_fields[]={SX_FIELD("amber_residue_pointer","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_amber_residue_pointer={0x60610082U,"chemistry_amber_residue_pointer",sxsch_amber_residue_pointer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_charge_fields[]={SX_FIELD("amber_charge","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_amber_charge={0x60610083U,"chemistry_amber_charge",sxsch_amber_charge_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mass_fields[]={SX_FIELD("amber_mass","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_amber_mass={0x60610084U,"chemistry_amber_mass",sxsch_amber_mass_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_integer_fields[]={SX_FIELD("amber_integer","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_amber_integer={0x60610085U,"chemistry_amber_integer",sxsch_amber_integer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_real_fields[]={SX_FIELD("amber_real","ascii_real",0,0,SX_NONE)};
const sx_layout sxsch_amber_real={0x60610086U,"chemistry_amber_real",sxsch_amber_real_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_string_fields[]={SX_FIELD("amber_string","char",0,0,SX_STRING)};
const sx_layout sxsch_amber_string={0x60610087U,"chemistry_amber_string",sxsch_amber_string_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_natom_fields[]={SX_FIELD("amber_natom","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_natom={0x60610088U,"chemistry_amber_natom",sxsch_amber_natom_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ntypes_fields[]={SX_FIELD("amber_ntypes","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_ntypes={0x60610089U,"chemistry_amber_ntypes",sxsch_amber_ntypes_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nbonh_fields[]={SX_FIELD("amber_nbonh","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_nbonh={0x6061008aU,"chemistry_amber_nbonh",sxsch_amber_nbonh_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mbona_fields[]={SX_FIELD("amber_mbona","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_mbona={0x6061008bU,"chemistry_amber_mbona",sxsch_amber_mbona_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ntheth_fields[]={SX_FIELD("amber_ntheth","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_ntheth={0x6061008cU,"chemistry_amber_ntheth",sxsch_amber_ntheth_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mtheta_fields[]={SX_FIELD("amber_mtheta","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_mtheta={0x6061008dU,"chemistry_amber_mtheta",sxsch_amber_mtheta_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nphih_fields[]={SX_FIELD("amber_nphih","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_nphih={0x6061008eU,"chemistry_amber_nphih",sxsch_amber_nphih_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mphia_fields[]={SX_FIELD("amber_mphia","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_mphia={0x6061008fU,"chemistry_amber_mphia",sxsch_amber_mphia_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nhparm_fields[]={SX_FIELD("amber_nhparm","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_amber_nhparm={0x60610090U,"chemistry_amber_nhparm",sxsch_amber_nhparm_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nparm_fields[]={SX_FIELD("amber_nparm","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_amber_nparm={0x60610091U,"chemistry_amber_nparm",sxsch_amber_nparm_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_next_fields[]={SX_FIELD("amber_next","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_next={0x60610092U,"chemistry_amber_next",sxsch_amber_next_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nres_fields[]={SX_FIELD("amber_nres","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_nres={0x60610093U,"chemistry_amber_nres",sxsch_amber_nres_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nbona_fields[]={SX_FIELD("amber_nbona","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_nbona={0x60610094U,"chemistry_amber_nbona",sxsch_amber_nbona_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ntheta_fields[]={SX_FIELD("amber_ntheta","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_ntheta={0x60610095U,"chemistry_amber_ntheta",sxsch_amber_ntheta_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nphia_fields[]={SX_FIELD("amber_nphia","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_nphia={0x60610096U,"chemistry_amber_nphia",sxsch_amber_nphia_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_numbnd_fields[]={SX_FIELD("amber_numbnd","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_numbnd={0x60610097U,"chemistry_amber_numbnd",sxsch_amber_numbnd_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_numang_fields[]={SX_FIELD("amber_numang","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_numang={0x60610098U,"chemistry_amber_numang",sxsch_amber_numang_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nptra_fields[]={SX_FIELD("amber_nptra","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_nptra={0x60610099U,"chemistry_amber_nptra",sxsch_amber_nptra_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_natyp_fields[]={SX_FIELD("amber_natyp","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_natyp={0x6061009aU,"chemistry_amber_natyp",sxsch_amber_natyp_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nphb_fields[]={SX_FIELD("amber_nphb","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_nphb={0x6061009bU,"chemistry_amber_nphb",sxsch_amber_nphb_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ifpert_fields[]={SX_FIELD("amber_ifpert","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_amber_ifpert={0x6061009cU,"chemistry_amber_ifpert",sxsch_amber_ifpert_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nbper_fields[]={SX_FIELD("amber_nbper","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_nbper={0x6061009dU,"chemistry_amber_nbper",sxsch_amber_nbper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ngper_fields[]={SX_FIELD("amber_ngper","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_ngper={0x6061009eU,"chemistry_amber_ngper",sxsch_amber_ngper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ndper_fields[]={SX_FIELD("amber_ndper","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_ndper={0x6061009fU,"chemistry_amber_ndper",sxsch_amber_ndper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mbper_fields[]={SX_FIELD("amber_mbper","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_mbper={0x606100a0U,"chemistry_amber_mbper",sxsch_amber_mbper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mgper_fields[]={SX_FIELD("amber_mgper","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_mgper={0x606100a1U,"chemistry_amber_mgper",sxsch_amber_mgper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_mdper_fields[]={SX_FIELD("amber_mdper","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_mdper={0x606100a2U,"chemistry_amber_mdper",sxsch_amber_mdper_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ifbox_fields[]={SX_FIELD("amber_ifbox","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_amber_ifbox={0x606100a3U,"chemistry_amber_ifbox",sxsch_amber_ifbox_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_nmxrs_fields[]={SX_FIELD("amber_nmxrs","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_nmxrs={0x606100a4U,"chemistry_amber_nmxrs",sxsch_amber_nmxrs_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ifcap_fields[]={SX_FIELD("amber_ifcap","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_amber_ifcap={0x606100a5U,"chemistry_amber_ifcap",sxsch_amber_ifcap_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_numextra_fields[]={SX_FIELD("amber_numextra","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_numextra={0x606100a6U,"chemistry_amber_numextra",sxsch_amber_numextra_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_amber_ncopy_fields[]={SX_FIELD("amber_ncopy","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsch_amber_ncopy={0x606100a7U,"chemistry_amber_ncopy",sxsch_amber_ncopy_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_prmtop(sxsch_cursor*q){sxsch_token l,t[4];unsigned n,width=0,pointer_index=0;bool real=false,chars=false,ptr=false;const sx_layout*layout=&sxsch_amber_string;if(!sxsch_line(q,&l))return false;SC_EMIT(text_value,l);while(sxsch_line(q,&l)){if(q->c->count>=24000)return true;if(l.z&&q->b[l.a]=='%'){n=sxsch_split(q,l,t,4,false);if(n==2&&sxsch_eq(q,t[0],"%FLAG")){SC_EMIT(keyword,t[0]);SC_EMIT(amber_flag,t[1]);sxsch_token name=t[1];if(!sxsch_line(q,&l))return false;SC_EMIT(format_string,l);l=sxsch_trim(q,l);ptr=sxsch_eq(q,name,"POINTERS");pointer_index=0;chars=sxsch_eq(q,l,"%FORMAT(20a4)")||sxsch_eq(q,l,"%FORMAT(20A4)")||sxsch_eq(q,l,"%FORMAT(1a80)")||sxsch_eq(q,l,"%FORMAT(1A80)");real=sxsch_eq(q,l,"%FORMAT(5E16.8)");width=chars?(sxsch_eq(q,l,"%FORMAT(1a80)")||sxsch_eq(q,l,"%FORMAT(1A80)")?80:4):real?16:8;
 layout=sxsch_eq(q,name,"ATOM_NAME")?&sxsch_amber_atom_name:sxsch_eq(q,name,"CHARGE")?&sxsch_amber_charge:sxsch_eq(q,name,"MASS")?&sxsch_amber_mass:sxsch_eq(q,name,"ATOM_TYPE_INDEX")?&sxsch_amber_atom_type_index:sxsch_eq(q,name,"NUMBER_EXCLUDED_ATOMS")?&sxsch_amber_excluded_count:sxsch_eq(q,name,"RESIDUE_LABEL")?&sxsch_amber_residue_label:sxsch_eq(q,name,"RESIDUE_POINTER")?&sxsch_amber_residue_pointer:sxsch_eq(q,name,"ATOMIC_NUMBER")?&sxsch_atomic_number:chars?&sxsch_amber_string:real?&sxsch_amber_real:&sxsch_amber_integer;
 }else SC_EMIT(comment,l);}else{if(!width||l.z%width)return false;for(int64_t o=0;o<l.z;o+=width){const sx_layout*item=layout;if(ptr){const sx_layout*const pointers[]={&sxsch_amber_natom,&sxsch_amber_ntypes,&sxsch_amber_nbonh,&sxsch_amber_mbona,&sxsch_amber_ntheth,&sxsch_amber_mtheta,&sxsch_amber_nphih,&sxsch_amber_mphia,&sxsch_amber_nhparm,&sxsch_amber_nparm,&sxsch_amber_next,&sxsch_amber_nres,&sxsch_amber_nbona,&sxsch_amber_ntheta,&sxsch_amber_nphia,&sxsch_amber_numbnd,&sxsch_amber_numang,&sxsch_amber_nptra,&sxsch_amber_natyp,&sxsch_amber_nphb,&sxsch_amber_ifpert,&sxsch_amber_nbper,&sxsch_amber_ngper,&sxsch_amber_ndper,&sxsch_amber_mbper,&sxsch_amber_mgper,&sxsch_amber_mdper,&sxsch_amber_ifbox,&sxsch_amber_nmxrs,&sxsch_amber_ifcap,&sxsch_amber_numextra,&sxsch_amber_ncopy};if(!sxsch_trim(q,(sxsch_token){l.a+o,width}).z)continue;if(pointer_index>=SX_COUNT(pointers))return false;item=pointers[pointer_index++];}if(!sxsch_column(q,item,l,(unsigned)o,width))return false;}}}return true;}
bool sx_amber_prmtop_build(sxsch_cursor*q)
{
 return sxsch_prmtop(q);
}
#undef SC_EMIT
