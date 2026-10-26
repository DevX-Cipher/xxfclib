/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * mtree data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_type_name_fields[]={
 SX_FIELD("type_name","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_type_name={0x60710016U,"textwire_type_name",sxtw_type_name_fields,SX_COUNT(sxtw_type_name_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_time_text_fields[]={
 SX_FIELD("time_text","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_time_text={0x60710017U,"textwire_time_text",sxtw_time_text_fields,SX_COUNT(sxtw_time_text_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_inode_fields[]={
 SX_FIELD("inode","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxtw_inode={0x6071002eU,"textwire_inode",sxtw_inode_fields,SX_COUNT(sxtw_inode_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_link_count_fields[]={
 SX_FIELD("link_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxtw_link_count={0x6071002fU,"textwire_link_count",sxtw_link_count_fields,SX_COUNT(sxtw_link_count_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_checksum_decimal_fields[]={
 SX_FIELD("checksum_decimal","ascii_signed",0,0,SX_CHECKSUM),
};
const sx_layout sxtw_checksum_decimal={0x60710030U,"textwire_checksum_decimal",sxtw_checksum_decimal_fields,SX_COUNT(sxtw_checksum_decimal_fields),SX_LE};
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_mtree(sxtw_cursor*q)
{
 int64_t a,end;bool continued=false;while(sxtw_line(q,&a,&end)){
  if(q->c->count>=32000)return true;unsigned slash=0;for(int64_t i=end;i>a&&q->b[i-1]=='\\';i--)slash++;bool next=(slash&1)!=0;
  /* A token can cross a continuation, so those physical lines stay raw. */
  if(continued||next){continued=next;continue;}sxtw_trim(q,&a,&end);if(a==end)continue;
  if(q->b[a]=='#'){if(sxtw_eq(q,a,end-a,"#mtree")){TW_EMIT(signature,a,end-a);}continue;}
  bool first=true;while(a<end){while(a<end&&sxtw_space(q->b[a]))a++;int64_t p=a;while(p<end&&!sxtw_space(q->b[p]))p++;if(p==a)break;int64_t e=a;while(e<p&&q->b[e]!='=')e++;
   if(e==p){if(first){TW_EMIT(path,a,p-a);}else{TW_EMIT(field_name,a,p-a);}}
   else{TW_EMIT(field_name,a,e-a);const sx_layout*l=&sxtw_field_value;
    if(sxtw_eq(q,a,e-a,"size"))l=&sxtw_declared_size;else if(sxtw_eq(q,a,e-a,"uid"))l=&sxtw_uid;else if(sxtw_eq(q,a,e-a,"gid"))l=&sxtw_gid;else if(sxtw_eq(q,a,e-a,"inode"))l=&sxtw_inode;else if(sxtw_eq(q,a,e-a,"nlink"))l=&sxtw_link_count;else if(sxtw_eq(q,a,e-a,"cksum"))l=&sxtw_checksum_decimal;else if(sxtw_eq(q,a,e-a,"mode"))l=&sxtw_octal_mode;else if(sxtw_eq(q,a,e-a,"time"))l=&sxtw_time_text;else if(sxtw_eq(q,a,e-a,"type"))l=&sxtw_type_name;
    if(!sxtw_emit(q,l,e+1,p-e-1))return false;
   }first=false;a=p;if(q->c->count>=32000)return true;
  }
 }return true;
}
bool sx_mtree_build(sxtw_cursor*q)
{
 return sxtw_mtree(q);
}
#undef TW_EMIT
