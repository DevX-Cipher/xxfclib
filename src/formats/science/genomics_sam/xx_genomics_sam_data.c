/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * genomics_sam data structures, moved out of the scienceascii schema family. */
#include "../../xx_format_schema_scienceascii.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsa_reference_length_fields[]={SX_FIELD("reference_length","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxsa_reference_length={0x6051001fU,"science_reference_length",sxsa_reference_length_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_mapping_quality_fields[]={SX_FIELD("mapping_quality","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_mapping_quality={0x60510030U,"science_mapping_quality",sxsa_mapping_quality_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_query_name_fields[]={SX_FIELD("sam_query_name","char",0,0,SX_STRING)};
const sx_layout sxsa_sam_query_name={0x6051003dU,"science_sam_query_name",sxsa_sam_query_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_reference_fields[]={SX_FIELD("sam_reference","char",0,0,SX_STRING)};
const sx_layout sxsa_sam_reference={0x6051003eU,"science_sam_reference",sxsa_sam_reference_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_cigar_fields[]={SX_FIELD("sam_cigar","char",0,0,SX_STRING)};
const sx_layout sxsa_sam_cigar={0x6051003fU,"science_sam_cigar",sxsa_sam_cigar_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_mate_reference_fields[]={SX_FIELD("sam_mate_reference","char",0,0,SX_STRING)};
const sx_layout sxsa_sam_mate_reference={0x60510040U,"science_sam_mate_reference",sxsa_sam_mate_reference_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_tag_fields[]={SX_FIELD("sam_tag","char",0,0,SX_STRING)};
const sx_layout sxsa_sam_tag={0x60510041U,"science_sam_tag",sxsa_sam_tag_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_tag_type_fields[]={SX_FIELD("sam_tag_type","char",0,0,SX_STRING)};
const sx_layout sxsa_sam_tag_type={0x60510042U,"science_sam_tag_type",sxsa_sam_tag_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_text_value_fields[]={SX_FIELD("sam_text_value","char",0,0,SX_STRING)};
const sx_layout sxsa_sam_text_value={0x60510043U,"science_sam_text_value",sxsa_sam_text_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_hex_value_fields[]={SX_FIELD("sam_hex_value","char",0,0,SX_STRING)};
const sx_layout sxsa_sam_hex_value={0x60510044U,"science_sam_hex_value",sxsa_sam_hex_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_flag_fields[]={SX_FIELD("sam_flag","ascii_signed",0,0,SX_FLAGS)};
const sx_layout sxsa_sam_flag={0x60510045U,"science_sam_flag",sxsa_sam_flag_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_template_length_fields[]={SX_FIELD("sam_template_length","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_sam_template_length={0x60510046U,"science_sam_template_length",sxsa_sam_template_length_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_integer_value_fields[]={SX_FIELD("sam_integer_value","ascii_signed",0,0,SX_NONE)};
const sx_layout sxsa_sam_integer_value={0x60510047U,"science_sam_integer_value",sxsa_sam_integer_value_fields,1,SX_LE};
static const xx_data_struct_field_desc sxsa_sam_real_value_fields[]={SX_FIELD("sam_real_value","ascii_real",0,0,SX_NONE)};
const sx_layout sxsa_sam_real_value={0x60510048U,"science_sam_real_value",sxsa_sam_real_value_fields,1,SX_LE};
#define SA_EMIT(n,t) do{if(!sxsa_emit(q,&sxsa_##n,(t)))return false;}while(0)
static bool sxsa_sam(sxsa_cursor*q){sxsa_token line,t[150];const sx_layout*cols[]={&sxsa_sam_query_name,&sxsa_sam_flag,&sxsa_sam_reference,&sxsa_position_1,&sxsa_mapping_quality,&sxsa_sam_cigar,&sxsa_sam_mate_reference,&sxsa_position_1,&sxsa_sam_template_length,&sxsa_sequence,&sxsa_quality};while(sxsa_line(q,&line)){if(q->c->count>=24000)return true;unsigned n=sxsa_split(q,line,t,150,true);if(!n||n>150)return false;if(q->b[line.a]=='@'){SA_EMIT(record_type,t[0]);for(unsigned i=1;i<n;i++){if(sxsa_eq(q,t[0],"@CO")){SA_EMIT(comment,t[i]);continue;}if(t[i].z<4)return false;SA_EMIT(sam_tag,((sxsa_token){t[i].a,2}));const sx_layout*l=sxsa_eq(q,(sxsa_token){t[i].a,2},"LN")?&sxsa_reference_length:&sxsa_sam_text_value;if(!sxsa_emit(q,l,(sxsa_token){t[i].a+3,t[i].z-3}))return false;}continue;}if(n<11||!sxsa_fields(q,t,11,cols,11))return false;for(unsigned i=11;i<n;i++){if(t[i].z<6)return false;SA_EMIT(sam_tag,((sxsa_token){t[i].a,2}));SA_EMIT(sam_tag_type,((sxsa_token){t[i].a+3,1}));unsigned ty=q->b[t[i].a+3];sxsa_token v={t[i].a+5,t[i].z-5};if(ty=='B'){if(v.z<3)return false;SA_EMIT(sam_tag_type,((sxsa_token){v.a,1}));if(!sxsa_csv(q,(sxsa_token){v.a+2,v.z-2},q->b[v.a]=='f'?&sxsa_sam_real_value:&sxsa_sam_integer_value))return false;}else if(!sxsa_emit(q,ty=='i'?&sxsa_sam_integer_value:ty=='f'?&sxsa_sam_real_value:ty=='H'?&sxsa_sam_hex_value:&sxsa_sam_text_value,v))return false;}}return true;}
bool sx_genomics_sam_build(sxsa_cursor*q)
{
 return sxsa_sam(q);
}
#undef SA_EMIT
