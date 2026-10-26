/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * genomics_genbank data structures, moved out of the sciencesequence schema family. */
#include "../../xx_format_schema_sciencesequence.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxseq_molecule_type_fields[]={SX_FIELD("molecule_type","char",0,0,SX_STRING)};
const sx_layout sxseq_molecule_type={0x60730006U,"sequence_molecule_type",sxseq_molecule_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_sequence_position_fields[]={SX_FIELD("sequence_position","ascii_signed",0,0,SX_NONE)};
const sx_layout sxseq_sequence_position={0x60730019U,"sequence_sequence_position",sxseq_sequence_position_fields,1,SX_LE};
#define SEQ_EMIT(n,t) do{if(!sxseq_emit(q,&sxseq_##n,(t)))return false;}while(0)
static bool sxseq_genbank(sxseq_cursor*q)
{
 sxseq_token line,t[64];bool sequence=false,features=false;
 while(sxseq_line(q,&line)){
  if(q->c->count>=24000)return true;sxseq_token trim=sxseq_trim(q,line);if(!trim.z)continue;
  if(sxseq_eq(q,trim,"//")){SEQ_EMIT(terminator,trim);sequence=features=false;continue;}
  if(sequence){unsigned n=sxseq_split(q,line,t,64,false);if(n<2||n>64)return false;SEQ_EMIT(sequence_position,t[0]);for(unsigned i=1;i<n;i++)SEQ_EMIT(sequence_text,t[i]);continue;}
  unsigned n=sxseq_split(q,line,t,64,false);
  if(n&&n<=64&&sxseq_eq(q,t[0],"LOCUS")){if(n<7)return false;SEQ_EMIT(keyword,t[0]);SEQ_EMIT(identifier,t[1]);SEQ_EMIT(sequence_length,t[2]);SEQ_EMIT(unit,t[3]);SEQ_EMIT(molecule_type,t[4]);SEQ_EMIT(locus_options,((sxseq_token){t[5].a,line.a+line.z-t[5].a}));continue;}
  if(sxseq_eq(q,trim,"ORIGIN")){SEQ_EMIT(keyword,trim);sequence=true;continue;}
  if(line.z<12)return false;
  if(features){if(line.z<=21)return false;sxseq_token key=sxseq_trim(q,(sxseq_token){line.a+5,16}),value=sxseq_trim(q,(sxseq_token){line.a+21,line.z-21});if(key.z){SEQ_EMIT(feature_key,key);SEQ_EMIT(feature_location,value);}else{SEQ_EMIT(feature_qualifier,value);}continue;}
  sxseq_token key=sxseq_trim(q,(sxseq_token){line.a,12}),value=sxseq_trim(q,(sxseq_token){line.a+12,line.z-12});SEQ_EMIT(field_key,key);
  if(sxseq_eq(q,key,"FEATURES")){features=true;SEQ_EMIT(field_text,value);}
  else if(sxseq_eq(q,key,"ACCESSION")){SEQ_EMIT(accession,value);}else{SEQ_EMIT(field_text,value);}
 }return true;
}
bool sx_genomics_genbank_build(sxseq_cursor*q)
{
 return sxseq_genbank(q);
}
#undef SEQ_EMIT
