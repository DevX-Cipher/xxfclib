/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * assembly_gfa data structures, moved out of the sciencesequence schema family. */
#include "../../xx_format_schema_sciencesequence.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxseq_gfa_record_type_fields[]={SX_FIELD("gfa_record_type","char",0,0,SX_STRING)};
const sx_layout sxseq_gfa_record_type={0x6073002bU,"sequence_gfa_record_type",sxseq_gfa_record_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_segment_name_fields[]={SX_FIELD("segment_name","char",0,0,SX_STRING)};
const sx_layout sxseq_segment_name={0x6073002cU,"sequence_segment_name",sxseq_segment_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_path_name_fields[]={SX_FIELD("path_name","char",0,0,SX_STRING)};
const sx_layout sxseq_path_name={0x6073002dU,"sequence_path_name",sxseq_path_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_orientation_fields[]={SX_FIELD("orientation","char",0,0,SX_STRING)};
const sx_layout sxseq_orientation={0x6073002eU,"sequence_orientation",sxseq_orientation_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_overlap_length_fields[]={SX_FIELD("overlap_length","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxseq_overlap_length={0x6073002fU,"sequence_overlap_length",sxseq_overlap_length_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_cigar_operation_fields[]={SX_FIELD("cigar_operation","char",0,0,SX_STRING)};
const sx_layout sxseq_cigar_operation={0x60730030U,"sequence_cigar_operation",sxseq_cigar_operation_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_missing_overlap_fields[]={SX_FIELD("missing_overlap","char",0,0,SX_STRING)};
const sx_layout sxseq_missing_overlap={0x60730031U,"sequence_missing_overlap",sxseq_missing_overlap_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_tag_name_fields[]={SX_FIELD("tag_name","char",0,0,SX_STRING)};
const sx_layout sxseq_tag_name={0x60730032U,"sequence_tag_name",sxseq_tag_name_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_tag_type_fields[]={SX_FIELD("tag_type","char",0,0,SX_STRING)};
const sx_layout sxseq_tag_type={0x60730033U,"sequence_tag_type",sxseq_tag_type_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_tag_integer_fields[]={SX_FIELD("tag_integer","ascii_signed",0,0,SX_NONE)};
const sx_layout sxseq_tag_integer={0x60730034U,"sequence_tag_integer",sxseq_tag_integer_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_tag_real_fields[]={SX_FIELD("tag_real","ascii_real",0,0,SX_NONE)};
const sx_layout sxseq_tag_real={0x60730035U,"sequence_tag_real",sxseq_tag_real_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_tag_string_fields[]={SX_FIELD("tag_string","char",0,0,SX_STRING)};
const sx_layout sxseq_tag_string={0x60730036U,"sequence_tag_string",sxseq_tag_string_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_tag_character_fields[]={SX_FIELD("tag_character","char",0,0,SX_STRING)};
const sx_layout sxseq_tag_character={0x60730037U,"sequence_tag_character",sxseq_tag_character_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_tag_hex_bytes_fields[]={SX_FIELD("tag_hex_bytes","char",0,0,SX_STRING)};
const sx_layout sxseq_tag_hex_bytes={0x60730038U,"sequence_tag_hex_bytes",sxseq_tag_hex_bytes_fields,1,SX_LE};
static const xx_data_struct_field_desc sxseq_gfa_declared_length_fields[]={SX_FIELD("gfa_declared_length","ascii_signed",0,0,SX_COUNT_PROP)};
const sx_layout sxseq_gfa_declared_length={0x60730039U,"sequence_gfa_declared_length",sxseq_gfa_declared_length_fields,1,SX_LE};
#define SEQ_EMIT(n,t) do{if(!sxseq_emit(q,&sxseq_##n,(t)))return false;}while(0)
static unsigned sxseq_csv(sxseq_cursor*q,sxseq_token line,sxseq_token*t,unsigned cap){unsigned n=0;int64_t p=line.a,end=p+line.z;do{int64_t a=p;while(p<end&&q->b[p]!=',')p++;if(n==cap)return cap+1;t[n++]=sxseq_trim(q,(sxseq_token){a,p-a});if(p==end)break;p++;}while(p<=end);return n;}
static bool sxseq_overlap(sxseq_cursor*q,sxseq_token token)
{
 if(token.z<2||q->b[token.a+token.z-1]!='M')return false;SEQ_EMIT(overlap_length,((sxseq_token){token.a,token.z-1}));SEQ_EMIT(cigar_operation,((sxseq_token){token.a+token.z-1,1}));return true;
}
static bool sxseq_gfa_tags(sxseq_cursor*q,sxseq_token*t,unsigned n)
{
 for(unsigned i=0;i<n;i++){
  sxseq_token tag=t[i];if(tag.z<6||q->b[tag.a+2]!=':'||q->b[tag.a+4]!=':')return false;
  sxseq_token name={tag.a,2},type={tag.a+3,1},value={tag.a+5,tag.z-5};SEQ_EMIT(tag_name,name);SEQ_EMIT(tag_type,type);
  const sx_layout*l=NULL;switch(q->b[type.a]){
  case 'i':l=sxseq_eq(q,name,"LN")?&sxseq_gfa_declared_length:&sxseq_tag_integer;break;
  case 'f':l=&sxseq_tag_real;break;case 'A':l=&sxseq_tag_character;break;case 'Z':l=&sxseq_tag_string;break;case 'H':l=&sxseq_tag_hex_bytes;break;default:return false;}
  if(!sxseq_emit(q,l,value))return false;
 }return true;
}
static bool sxseq_gfa(sxseq_cursor*q)
{
 sxseq_token line,t[128],parts[128];
 while(sxseq_line(q,&line)){
  if(q->c->count>=24000)return true;if(!line.z)continue;if(q->b[line.a]=='#'){SEQ_EMIT(comment,line);continue;}
  unsigned n=sxseq_split(q,line,t,128,true),tags;if(!n||n>128)return false;SEQ_EMIT(gfa_record_type,t[0]);
  if(sxseq_eq(q,t[0],"H")){tags=1;}
  else if(sxseq_eq(q,t[0],"S")){if(n<3)return false;SEQ_EMIT(segment_name,t[1]);if(!sxseq_chunks(q,&sxseq_sequence_text,t[2]))return false;tags=3;}
  else if(sxseq_eq(q,t[0],"L")){if(n<6)return false;SEQ_EMIT(segment_name,t[1]);SEQ_EMIT(orientation,t[2]);SEQ_EMIT(segment_name,t[3]);SEQ_EMIT(orientation,t[4]);if(!sxseq_overlap(q,t[5]))return false;tags=6;}
  else if(sxseq_eq(q,t[0],"P")){
   if(n<4)return false;SEQ_EMIT(path_name,t[1]);unsigned count=sxseq_csv(q,t[2],parts,128);if(count>128)return false;
   for(unsigned i=0;i<count;i++){if(parts[i].z<2)return false;SEQ_EMIT(segment_name,((sxseq_token){parts[i].a,parts[i].z-1}));SEQ_EMIT(orientation,((sxseq_token){parts[i].a+parts[i].z-1,1}));}
   if(sxseq_eq(q,t[3],"*")){SEQ_EMIT(missing_overlap,t[3]);}else{count=sxseq_csv(q,t[3],parts,128);if(count>128)return false;for(unsigned i=0;i<count;i++)if(!sxseq_overlap(q,parts[i]))return false;}
   tags=4;
  }else return false;
  if(!sxseq_gfa_tags(q,t+tags,n-tags))return false;
 }return true;
}
bool sx_assembly_gfa_build(sxseq_cursor*q)
{
 return sxseq_gfa(q);
}
#undef SEQ_EMIT
