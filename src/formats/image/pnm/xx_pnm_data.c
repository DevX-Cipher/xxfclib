/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pnm data structures, moved out of the textimages schema family. */
#include "../../xx_format_schema_textimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxti_tuple_type_fields[]={
 SX_FIELD("tuple_type","char",0,0,SX_STRING),
};
const sx_layout sxti_tuple_type={0x60410003U,"textimage_tuple_type",sxti_tuple_type_fields,SX_COUNT(sxti_tuple_type_fields),SX_LE};
static const xx_data_struct_field_desc sxti_depth_fields[]={
 SX_FIELD("depth","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_depth={0x60410016U,"textimage_depth",sxti_depth_fields,SX_COUNT(sxti_depth_fields),SX_LE};
static const xx_data_struct_field_desc sxti_maxval_fields[]={
 SX_FIELD("maxval","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_maxval={0x60410017U,"textimage_maxval",sxti_maxval_fields,SX_COUNT(sxti_maxval_fields),SX_LE};
static const xx_data_struct_field_desc sxti_sample_fields[]={
 SX_FIELD("sample","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxti_sample={0x60410050U,"textimage_sample",sxti_sample_fields,SX_COUNT(sxti_sample_fields),SX_LE};
static bool sxti_delimiter(sxti_cursor*q){if(q->p>=q->n||!sxti_space(q->b[q->p]))return false;uint8_t x=q->b[q->p++];if(x=='\r'&&q->p<q->n&&q->b[q->p]=='\n')q->p++;return true;}
#define TI_VALUE(n,e,v) do{if(!sxti_value(q,&sxti_##n,(e),(v)))return false;}while(0)
#define TI_EMIT(n,a,z) do{if(!sxti_emit(q,&sxti_##n,(a),(z)))return false;}while(0)
static bool sxti_pnm(sxti_cursor*q)
{
 unsigned images=0;while(q->p<q->n&&q->c->count<32000){while(q->p<q->n&&sxti_space(q->b[q->p]))q->p++;if(q->p==q->n)break;if(q->n-q->p<3||q->b[q->p]!='P'||++images>1024)return false;unsigned kind=q->b[q->p+1]-'0';if(kind<1||kind>7)return false;TI_EMIT(magic,q->p,2);q->p+=2;uint64_t w=0,h=0,depth=kind==3||kind==6?3:1,max=1;
  if(kind==7){if(!sxti_delimiter(q))return false;int64_t a,end;bool ended=false;while(sxti_line(q,&a,&end,true)){int64_t next=q->p;q->p=a;int64_t key,z;if(!sxti_token(q,end,&key,&z,false))return false;if(sxti_eq(q,key,z,"ENDHDR")){ended=true;q->p=next;break;}const sx_layout*l=NULL;uint64_t*out=NULL;if(sxti_eq(q,key,z,"WIDTH")){l=&sxti_width;out=&w;}else if(sxti_eq(q,key,z,"HEIGHT")){l=&sxti_height;out=&h;}else if(sxti_eq(q,key,z,"DEPTH")){l=&sxti_depth;out=&depth;}else if(sxti_eq(q,key,z,"MAXVAL")){l=&sxti_maxval;out=&max;}else if(sxti_eq(q,key,z,"TUPLTYPE")){while(q->p<end&&sxti_space(q->b[q->p]))q->p++;TI_EMIT(tuple_type,q->p,end-q->p);}else return false;if(l&&!sxti_value(q,l,end,out))return false;q->p=next;}if(!ended)return false;
  }else{TI_VALUE(width,q->n,&w);TI_VALUE(height,q->n,&h);if(kind!=1&&kind!=4)TI_VALUE(maxval,q->n,&max);if(!sxti_delimiter(q))return false;}
  if(!w||!h||!depth||depth>16||!max||max>65535||w>16777216/depth||h>16777216/depth/w)return false;uint64_t count=w*h*depth;
  if(kind<4){for(uint64_t i=0;i<count;i++){if(q->c->count>=32000)return true;if(kind==1){while(q->p<q->n){if(sxti_space(q->b[q->p]))q->p++;else if(q->b[q->p]=='#'){while(q->p<q->n&&q->b[q->p]!='\n')q->p++;}else break;}if(q->p==q->n||(q->b[q->p]!='0'&&q->b[q->p]!='1'))return false;TI_EMIT(sample,q->p,1);q->p++;}else{uint64_t sample;TI_VALUE(sample,q->n,&sample);if(sample>max)return false;}}if(!sxti_delimiter(q))return false;}
  else{uint64_t width=max>255?2:1,bytes=kind==4?((w+7)/8)*h:count*width;if(bytes>(uint64_t)(q->n-q->p))return false;if(kind!=4&&!sxti_table(q,width==2?&sxti_sample_u16_be:&sxti_sample_u8,q->p,(int64_t)width,count))return false;q->p+=(int64_t)bytes;}
  while(q->p<q->n){if(sxti_space(q->b[q->p]))q->p++;else if(q->b[q->p]=='#'){while(q->p<q->n&&q->b[q->p]!='\n')q->p++;}else break;}
 }return images>0;
}
bool sx_pnm_build(sxti_cursor*q)
{
 return sxti_pnm(q);
}
#undef TI_VALUE
#undef TI_EMIT
