/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * alignment_maf data structures, moved out of the sciencesequence schema family. */
#include "../../xx_format_schema_sciencesequence.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxseq_maf_scoring_fields[]={SX_FIELD("maf_scoring","char",0,0,SX_STRING)};
const sx_layout sxseq_maf_scoring={0x60730021U,"sequence_maf_scoring",sxseq_maf_scoring_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_alignment_score_fields[]={SX_FIELD("alignment_score","ascii_real",0,0,SX_NONE)};
const sx_layout sxseq_alignment_score={0x60730022U,"sequence_alignment_score",sxseq_alignment_score_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_maf_start_fields[]={SX_FIELD("maf_start","ascii_signed",0,0,SX_NONE)};
const sx_layout sxseq_maf_start={0x60730023U,"sequence_maf_start",sxseq_maf_start_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_maf_size_fields[]={SX_FIELD("maf_size","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxseq_maf_size={0x60730024U,"sequence_maf_size",sxseq_maf_size_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_source_length_fields[]={SX_FIELD("source_length","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxseq_source_length={0x60730025U,"sequence_source_length",sxseq_source_length_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_version_fields[]={SX_FIELD("version","char",0,0,SX_STRING)};
const sx_layout sxseq_version={0x6073003aU,"sequence_version",sxseq_version_fields,1,SX_LE};
static bool sxseq_fields(sxseq_cursor*q,sxseq_token*t,unsigned n,const sx_layout*const*l,unsigned max){if(n>max)return false;for(unsigned i=0;i<n;i++)if(l[i]&&!sxseq_emit(q,l[i],t[i]))return false;return true;}
#define SEQ_EMIT(n,t) do{if(!sxseq_emit(q,&sxseq_##n,(t)))return false;}while(0)
static bool sxseq_maf(sxseq_cursor*q)
{
 sxseq_token line,t[8];if(!sxseq_line(q,&line))return false;unsigned n=sxseq_split(q,line,t,8,false);if(n<2||n>3)return false;SEQ_EMIT(signature,t[0]);SEQ_EMIT(version,t[1]);if(n==3){if(t[2].z<=8)return false;SEQ_EMIT(field_key,((sxseq_token){t[2].a,7}));SEQ_EMIT(maf_scoring,((sxseq_token){t[2].a+8,t[2].z-8}));}
 while(sxseq_line(q,&line)){if(q->c->count>=24000)return true;line=sxseq_trim(q,line);if(!line.z)continue;if(q->b[line.a]=='#'){SEQ_EMIT(comment,line);continue;}n=sxseq_split(q,line,t,8,false);if(!n||n>8)return false;SEQ_EMIT(keyword,t[0]);if(sxseq_eq(q,t[0],"a")){if(n==2){if(t[1].z<=6)return false;SEQ_EMIT(field_key,((sxseq_token){t[1].a,5}));SEQ_EMIT(alignment_score,((sxseq_token){t[1].a+6,t[1].z-6}));}else if(n!=1)return false;}
  else{if(n!=7||!sxseq_eq(q,t[0],"s"))return false;const sx_layout*l[]={&sxseq_identifier,&sxseq_maf_start,&sxseq_maf_size,&sxseq_strand,&sxseq_source_length};if(!sxseq_fields(q,t+1,5,l,5)||!sxseq_chunks(q,&sxseq_sequence_text,t[6]))return false;}
 }return true;
}
bool sx_alignment_maf_build(sxseq_cursor*q)
{
 return sxseq_maf(q);
}
#undef SEQ_EMIT
