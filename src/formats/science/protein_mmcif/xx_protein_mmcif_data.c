/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * protein_mmcif data structures, moved out of the sciencechem schema family. */
#include "../../xx_format_schema_sciencechem.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsch_cif_data_block_fields[]={SX_FIELD("cif_data_block","char",0,0,SX_STRING)};
const sx_layout sxsch_cif_data_block={0x60610078U,"chemistry_cif_data_block",sxsch_cif_data_block_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cif_tag_fields[]={SX_FIELD("cif_tag","char",0,0,SX_STRING)};
const sx_layout sxsch_cif_tag={0x60610079U,"chemistry_cif_tag",sxsch_cif_tag_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cif_group_fields[]={SX_FIELD("cif_group","char",0,0,SX_STRING)};
const sx_layout sxsch_cif_group={0x6061007aU,"chemistry_cif_group",sxsch_cif_group_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cif_value_fields[]={SX_FIELD("cif_value","char",0,0,SX_STRING)};
const sx_layout sxsch_cif_value={0x6061007bU,"chemistry_cif_value",sxsch_cif_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsch_cif_atom_id_fields[]={SX_FIELD("cif_atom_id","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsch_cif_atom_id={0x6061007cU,"chemistry_cif_atom_id",sxsch_cif_atom_id_fields,1,SX_LE};
#define SC_EMIT(n,t) do{if(!sxsch_emit(q,&sxsch_##n,(t)))return false;}while(0)
static bool sxsch_cif_next(sxsch_cursor*q,sxsch_token*t,bool*quoted,bool*have){*have=false;*quoted=false;while(q->p<q->n){if(sxsch_space(q->b[q->p])){q->p++;continue;}if(q->b[q->p]=='#'){int64_t start=q->p;while(q->p<q->n&&q->b[q->p]!='\n')q->p++;SC_EMIT(comment,((sxsch_token){start,q->p-start}));continue;}break;}if(q->p==q->n)return true;if(++q->work>2000000||xx_pd_is_stopped(q->c->pd))return false;int64_t begin=q->p;unsigned ch=q->b[q->p];if(ch=='\''||ch=='"'){*quoted=true;begin=++q->p;while(q->p<q->n){if(q->b[q->p]=='\n'||q->b[q->p]=='\r')return false;if(q->b[q->p]==ch&&(q->p+1==q->n||sxsch_space(q->b[q->p+1]))){*t=(sxsch_token){begin,q->p-begin};q->p++;*have=true;return true;}q->p++;}return false;}if(ch==';'&&(!q->p||q->b[q->p-1]=='\n')){*quoted=true;begin=++q->p;while(q->p<q->n){if(q->b[q->p]==';'&&q->b[q->p-1]=='\n'){*t=(sxsch_token){begin,q->p-begin};q->p++;*have=true;return true;}q->p++;}return false;}while(q->p<q->n&&!sxsch_space(q->b[q->p]))q->p++;*t=(sxsch_token){begin,q->p-begin};*have=true;return true;}
static bool sxsch_cif_reserved(sxsch_cursor*q,sxsch_token t,bool quoted){return !quoted&&t.z&&(q->b[t.a]=='_'||sxsch_ci(q,t,"loop_")||sxsch_ci(q,t,"stop_")||sxsch_ci(q,t,"global_")||(t.z>=5&&(sxsch_ci(q,(sxsch_token){t.a,5},"data_")||sxsch_ci(q,(sxsch_token){t.a,5},"save_"))));}
static const sx_layout*sxsch_cif_type(sxsch_cursor*q,sxsch_token t){const char*names[]={"_atom_site.group_pdb","_atom_site.id","_atom_site.type_symbol","_atom_site.label_atom_id","_atom_site.label_comp_id","_atom_site.cartn_x","_atom_site.cartn_y","_atom_site.cartn_z"};const sx_layout*types[]={&sxsch_cif_group,&sxsch_cif_atom_id,&sxsch_element,&sxsch_atom_name,&sxsch_residue_name,&sxsch_angstrom_x,&sxsch_angstrom_y,&sxsch_angstrom_z};for(unsigned i=0;i<SX_COUNT(names);i++)if(sxsch_ci(q,t,names[i]))return types[i];return &sxsch_cif_value;}
static bool sxsch_cif(sxsch_cursor*q){sxsch_token t;bool quoted,have;if(!sxsch_cif_next(q,&t,&quoted,&have)||!have)return false;SC_EMIT(cif_data_block,t);if(!sxsch_cif_next(q,&t,&quoted,&have))return false;while(have){if(q->c->count>=24000)return true;if(!quoted&&sxsch_ci(q,t,"loop_")){SC_EMIT(keyword,t);const sx_layout*cols[128];unsigned n=0;if(!sxsch_cif_next(q,&t,&quoted,&have))return false;while(have&&!quoted&&t.z&&q->b[t.a]=='_'){if(n==128)return false;cols[n++]=sxsch_cif_type(q,t);SC_EMIT(cif_tag,t);if(!sxsch_cif_next(q,&t,&quoted,&have))return false;}if(!n)return false;uint64_t index=0;while(have&&!sxsch_cif_reserved(q,t,quoted)){if(!sxsch_emit(q,cols[index%n],t))return false;index++;if(q->c->count>=24000)return true;if(!sxsch_cif_next(q,&t,&quoted,&have))return false;}if(index%n)return false;}else if(!quoted&&t.z&&q->b[t.a]=='_'){const sx_layout*l=sxsch_cif_type(q,t);SC_EMIT(cif_tag,t);if(!sxsch_cif_next(q,&t,&quoted,&have)||!have||!sxsch_emit(q,l,t)||!sxsch_cif_next(q,&t,&quoted,&have))return false;}else return false;}return true;}
bool sx_protein_mmcif_build(sxsch_cursor*q)
{
 return sxsch_cif(q);
}
#undef SC_EMIT
