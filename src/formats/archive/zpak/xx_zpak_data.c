/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZPAK data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_zpak_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxae_zpak_header = {UINT32_C(0x6017002a),"zpak_header",sxae_zpak_header_fields,SX_COUNT(sxae_zpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_zpak_member_fields[] = {
    SX_FIELD("name","char[12]",0,12,SX_STRING),
    SX_FIELD("padding","uint8",12,1,SX_RESERVED),
    SX_FIELD("data_offset","int32",13,4,SX_OFFSET),
    SX_FIELD("packed_size","int32",17,4,SX_SIZE),
    SX_FIELD("date","uint16",21,2,SX_NONE),
    SX_FIELD("time","uint16",23,2,SX_NONE),
    SX_FIELD("crc_low","uint16",25,2,SX_CHECKSUM),
    SX_FIELD("crc_high","uint16",27,2,SX_CHECKSUM),
    SX_FIELD("unpacked_size","int32",29,4,SX_SIZE),
};
const sx_layout sxae_zpak_member = {UINT32_C(0x6017002b),"zpak_member",sxae_zpak_member_fields,SX_COUNT(sxae_zpak_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_zpak_chunk_marker_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxae_zpak_chunk_marker = {UINT32_C(0x6017002c),"zpak_chunk_marker",sxae_zpak_chunk_marker_fields,SX_COUNT(sxae_zpak_chunk_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxae_zpak_chunk_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxae_zpak_chunk = {UINT32_C(0x6017002d),"zpak_chunk",sxae_zpak_chunk_fields,SX_COUNT(sxae_zpak_chunk_fields),SX_LE};
typedef struct sxae_extent {int64_t start,end;} sxae_extent;
static int sxae_extent_order(const void *a,const void *b){const sxae_extent *x=a,*y=b;return x->start<y->start?-1:x->start>y->start?1:x->end<y->end?-1:x->end>y->end?1:0;}
static bool sxae_zpak_frame(sx_context *c,int64_t p,int64_t end)
{
 if(end-p<2)return false;uint8_t ch;int64_t stop=end-1;
 if(!sx_read(c,p,&ch,1)||ch!=0xca||!sx_read(c,stop,&ch,1)||ch)return false;
 if(!sxae_add(c,&sxae_zpak_chunk_marker,p++)||!sxae_add(c,&sxae_zpak_chunk_marker,stop))return false;
 for(unsigned k=0;p<stop&&k<20000;k++){uint16_t q;if(p+2>stop||!sx_u16(c,p,false,&q)||q>(uint64_t)(stop-p-2)||!sxae_add(c,&sxae_zpak_chunk,p))return false;p+=2;if(!q)return true;if(!sxae_data(c,p,q))return false;p+=q;}
 return p==stop;
}
static bool sxae_zpak(sx_context *c)
{
 uint8_t h[6];if(!sx_read(c,0,h,6)||(xx_rt_memcmp(h,"zpak",4)&&xx_rt_memcmp(h,"zpk2",4)))return false;uint16_t n=sxae16(h+4);int64_t end=6+(int64_t)n*33;
 if(!n||n>20000||!sxae_bound(c,0,end)||!sxae_add(c,&sxae_zpak_header,0)||!sx_table(c,&sxae_zpak_member,6,33,n))return false;
 sxae_extent *spans=xx_mem_alloc((size_t)n*sizeof(*spans));if(!spans)return false;size_t count=0;bool ok=false;
 for(unsigned i=0;i<n;i++){uint8_t b[33];if(!sx_read(c,6+(int64_t)i*33,b,33))goto done;uint32_t p=sxae32(b+13),z=sxae32(b+17);if(p>INT32_MAX||z>INT32_MAX||p<end||!sxae_bound(c,p,z))goto done;if(z)spans[count++]=(sxae_extent){p,(int64_t)p+z};}
 xx_rt_qsort(spans,count,sizeof(*spans),sxae_extent_order);
 /* Distinct overlapping member spans cannot establish unambiguous framing.
  * Exact aliases share one physical stream. Both keep their directory rows. */
 for(size_t i=0;i<count;){size_t j=i+1;int64_t stop=spans[i].end;bool ambiguous=false;
  while(j<count&&spans[j].start<stop){if(spans[j].start!=spans[i].start||spans[j].end!=spans[i].end)ambiguous=true;if(spans[j].end>stop)stop=spans[j].end;j++;}
  if(!ambiguous&&h[3]=='k'){size_t saved=c->count;if(!sxae_zpak_frame(c,spans[i].start,spans[i].end)){if(c->failed)goto done;c->count=saved;}}
  i=j;
 }ok=true;
 done:xx_mem_free(spans);return ok;
}
bool sx_zpak_build(sx_context*c)
{
 return sxae_zpak(c);
}
