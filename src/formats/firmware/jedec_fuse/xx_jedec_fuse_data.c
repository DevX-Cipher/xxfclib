/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * jedec fuse data structures, moved out of the vectortext schema family. */
#include "../../xx_format_schema_vectortext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvtx_fuse_count_fields[]={
 SX_FIELD("fuse_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxvtx_fuse_count={0x6062002fU,"vectortext_fuse_count",sxvtx_fuse_count_fields,SX_COUNT(sxvtx_fuse_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_pin_count_fields[]={
 SX_FIELD("pin_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxvtx_pin_count={0x60620030U,"vectortext_pin_count",sxvtx_pin_count_fields,SX_COUNT(sxvtx_pin_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_fuse_index_fields[]={
 SX_FIELD("fuse_index","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_fuse_index={0x60620031U,"vectortext_fuse_index",sxvtx_fuse_index_fields,SX_COUNT(sxvtx_fuse_index_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_default_fuse_fields[]={
 SX_FIELD("default_fuse","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_default_fuse={0x60620032U,"vectortext_default_fuse",sxvtx_default_fuse_fields,SX_COUNT(sxvtx_default_fuse_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_security_fuse_fields[]={
 SX_FIELD("security_fuse","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxvtx_security_fuse={0x60620033U,"vectortext_security_fuse",sxvtx_security_fuse_fields,SX_COUNT(sxvtx_security_fuse_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_checksum_fields[]={
 SX_FIELD("checksum","ascii_hex",0,0,SX_CHECKSUM),
};
const sx_layout sxvtx_checksum={0x6062009eU,"vectortext_checksum",sxvtx_checksum_fields,SX_COUNT(sxvtx_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_transmission_checksum_fields[]={
 SX_FIELD("transmission_checksum","ascii_hex",0,0,SX_CHECKSUM),
};
const sx_layout sxvtx_transmission_checksum={0x6062009fU,"vectortext_transmission_checksum",sxvtx_transmission_checksum_fields,SX_COUNT(sxvtx_transmission_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_fuse_bits_fields[]={
 SX_FIELD("fuse_bits","char",0,0,SX_STRING),
};
const sx_layout sxvtx_fuse_bits={0x606200a2U,"vectortext_fuse_bits",sxvtx_fuse_bits_fields,SX_COUNT(sxvtx_fuse_bits_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_jedec_stx_fields[]={
 SX_FIELD("start_of_text","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxvtx_jedec_stx={0x606200a3U,"vectortext_jedec_stx",sxvtx_jedec_stx_fields,SX_COUNT(sxvtx_jedec_stx_fields),SX_LE};
static const xx_data_struct_field_desc sxvtx_jedec_etx_fields[]={
 SX_FIELD("end_of_text","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxvtx_jedec_etx={0x606200a4U,"vectortext_jedec_etx",sxvtx_jedec_etx_fields,SX_COUNT(sxvtx_jedec_etx_fields),SX_LE};
#define VT_EMIT(n,a,z) do{if(!sxvtx_emit(q,&sxvtx_##n,(a),(z)))return false;}while(0)
/* Physical JEDEC records; decoded fuse arrays never invent file offsets. */
static bool sxvtx_jedec(sxvtx_cursor*q)
{
 if(q->n<2||q->b[0]!=2)return false;VT_EMIT(jedec_stx,0,1);
 int64_t p=1;while(p<q->n&&q->b[p]!='*')p++;if(p==q->n)return false;VT_EMIT(string_value,1,p-1);
 while(p<q->n&&q->b[p]=='*'){
  if(q->c->count>=32000)return true;int64_t a=++p,end=p;while(end<q->n&&q->b[end]!='*'&&q->b[end]!=3)end++;
  while(a<end&&sxvtx_space(q->b[a]))a++;int64_t stop=end;while(stop>a&&sxvtx_space(q->b[stop-1]))stop--;
  if(a<stop){unsigned width=q->b[a]=='Q'?2:1;if(stop-a<(int64_t)width)return false;VT_EMIT(keyword,a,width);uint8_t kind=q->b[a];bool pins=width==2&&q->b[a+1]=='P';a+=width;while(a<stop&&sxvtx_space(q->b[a]))a++;
   if(kind=='L'){
    int64_t first=a;while(a<stop&&!sxvtx_space(q->b[a]))a++;VT_EMIT(fuse_index,first,a-first);
    while(a<stop){while(a<stop&&sxvtx_space(q->b[a]))a++;first=a;while(a<stop&&!sxvtx_space(q->b[a])&&a-first<4096)a++;VT_EMIT(fuse_bits,first,a-first);}
   }else if(kind=='N'){VT_EMIT(string_value,a,stop-a);}
   else if(kind=='Q'){if(!sxvtx_emit(q,pins?&sxvtx_pin_count:&sxvtx_fuse_count,a,stop-a))return false;}
   else if(kind=='F'){VT_EMIT(default_fuse,a,stop-a);}
   else if(kind=='G'){VT_EMIT(security_fuse,a,stop-a);}
   else if(kind=='C'){VT_EMIT(checksum,a,stop-a);}
   else return false;
  }
  p=end;
 }
 if(p>=q->n||q->b[p]!=3)return false;VT_EMIT(jedec_etx,p,1);p++;int64_t a=p;while(p<q->n&&!sxvtx_space(q->b[p]))p++;if(p-a!=4)return false;VT_EMIT(transmission_checksum,a,4);return true;
}
bool sx_jedec_fuse_build(sxvtx_cursor*q)
{
 return sxvtx_jedec(q);
}
#undef VT_EMIT
