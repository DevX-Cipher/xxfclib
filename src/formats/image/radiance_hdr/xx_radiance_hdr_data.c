/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * radiance_hdr data structures, moved out of the textimages schema family. */
#include "../../xx_format_schema_textimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxti_axis_y_fields[]={
 SX_FIELD("axis_y","char",0,0,SX_STRING),
};
const sx_layout sxti_axis_y={0x60410006U,"textimage_axis_y",sxti_axis_y_fields,SX_COUNT(sxti_axis_y_fields),SX_LE};
static const xx_data_struct_field_desc sxti_axis_x_fields[]={
 SX_FIELD("axis_x","char",0,0,SX_STRING),
};
const sx_layout sxti_axis_x={0x60410007U,"textimage_axis_x",sxti_axis_x_fields,SX_COUNT(sxti_axis_x_fields),SX_LE};
static const xx_data_struct_field_desc sxti_radiance_scanline_header_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("width","uint16",2,2,SX_NONE),
};
const sx_layout sxti_radiance_scanline_header={0x60410060U,"textimage_radiance_scanline_header",sxti_radiance_scanline_header_fields,SX_COUNT(sxti_radiance_scanline_header_fields),SX_BE};
static const xx_data_struct_field_desc sxti_radiance_run_fields[]={
 SX_FIELD("run_code","uint8",0,1,SX_NONE),
 SX_FIELD("sample","uint8",1,1,SX_NONE),
};
const sx_layout sxti_radiance_run={0x60410061U,"textimage_radiance_run",sxti_radiance_run_fields,SX_COUNT(sxti_radiance_run_fields),SX_LE};
static const xx_data_struct_field_desc sxti_radiance_literal_fields[]={
 SX_FIELD("sample_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxti_radiance_literal={0x60410062U,"textimage_radiance_literal",sxti_radiance_literal_fields,SX_COUNT(sxti_radiance_literal_fields),SX_LE};
#define TI_VALUE(n,e,v) do{if(!sxti_value(q,&sxti_##n,(e),(v)))return false;}while(0)
#define TI_EMIT(n,a,z) do{if(!sxti_emit(q,&sxti_##n,(a),(z)))return false;}while(0)
static bool sxti_radiance(sxti_cursor*q)
{
 int64_t a,end;bool header=true;uint64_t w=0,h=0;
 if(!sxti_line(q,&a,&end,false))return false;TI_EMIT(magic,a,end-a);
 while(q->p<q->n&&header){a=q->p;while(q->p<q->n&&q->b[q->p]!='\n')q->p++;end=q->p;if(q->p<q->n)q->p++;if(end>a&&q->b[end-1]=='\r')end--;if(a==end){header=false;break;}
  int64_t eq=a;while(eq<end&&q->b[eq]!='=')eq++;if(eq<end){TI_EMIT(define_name,a,eq-a);TI_EMIT(metadata_text,eq+1,end-eq-1);}else TI_EMIT(metadata_text,a,end-a);
 }
 if(header||!sxti_line(q,&a,&end,false))return false;int64_t next=q->p;q->p=a;TI_VALUE(axis_y,end,NULL);TI_VALUE(height,end,&h);TI_VALUE(axis_x,end,NULL);TI_VALUE(width,end,&w);q->p=next;if(!w||!h||w>32767||h>4096)return false;
 for(uint64_t row=0;row<h;row++){if(q->n-q->p<4)return false;uint8_t*b=q->b+q->p;bool rle=w>=8&&b[0]==2&&b[1]==2&&!(b[2]&128);if(rle){TI_EMIT(radiance_scanline_header,q->p,4);if(((unsigned)b[2]*256+b[3])!=w)return false;q->p+=4;for(unsigned channel=0;channel<4;channel++){uint64_t samples=0;while(samples<w){if(q->p==q->n)return false;unsigned op=q->b[q->p],n=op>128?op-128:op;if(!n||n>w-samples)return false;unsigned bytes=op>128?2:n+1;if(bytes>(uint64_t)(q->n-q->p))return false;if(op>128){TI_EMIT(radiance_run,q->p,2);}else{TI_EMIT(radiance_literal,q->p,1);}q->p+=bytes;samples+=n;}}}
  else{if(w>(uint64_t)(q->n-q->p)/4)return false;q->p+=(int64_t)(w*4);}if(q->c->count>=32000)return true;
 }return true;
}
bool sx_radiance_hdr_build(sxti_cursor*q)
{
 return sxti_radiance(q);
}
#undef TI_VALUE
#undef TI_EMIT
