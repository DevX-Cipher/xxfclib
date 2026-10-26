/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * polygon_ply data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_element_name_fields[]={
 SX_FIELD("element_name","char",0,0,SX_STRING),
};
const sx_layout sxmt_element_name={0x60520004U,"modeltext_element_name",sxmt_element_name_fields,SX_COUNT(sxmt_element_name_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_property_type_fields[]={
 SX_FIELD("property_type","char",0,0,SX_STRING),
};
const sx_layout sxmt_property_type={0x60520006U,"modeltext_property_type",sxmt_property_type_fields,SX_COUNT(sxmt_property_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_count_type_fields[]={
 SX_FIELD("count_type","char",0,0,SX_STRING),
};
const sx_layout sxmt_count_type={0x60520007U,"modeltext_count_type",sxmt_count_type_fields,SX_COUNT(sxmt_count_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_element_count_fields[]={
 SX_FIELD("element_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_element_count={0x60520017U,"modeltext_element_count",sxmt_element_count_fields,SX_COUNT(sxmt_element_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_list_uint8_le_fields[]={
 SX_FIELD("list_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxmt_list_uint8_le={0x60520069U,"modeltext_list_uint8_le",sxmt_list_uint8_le_fields,SX_COUNT(sxmt_list_uint8_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_list_uint16_le_fields[]={
 SX_FIELD("list_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmt_list_uint16_le={0x6052006aU,"modeltext_list_uint16_le",sxmt_list_uint16_le_fields,SX_COUNT(sxmt_list_uint16_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_list_uint32_le_fields[]={
 SX_FIELD("list_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmt_list_uint32_le={0x6052006bU,"modeltext_list_uint32_le",sxmt_list_uint32_le_fields,SX_COUNT(sxmt_list_uint32_le_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_list_uint8_be_fields[]={
 SX_FIELD("list_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxmt_list_uint8_be={0x60520074U,"modeltext_list_uint8_be",sxmt_list_uint8_be_fields,SX_COUNT(sxmt_list_uint8_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_list_uint16_be_fields[]={
 SX_FIELD("list_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxmt_list_uint16_be={0x60520075U,"modeltext_list_uint16_be",sxmt_list_uint16_be_fields,SX_COUNT(sxmt_list_uint16_be_fields),SX_BE};
static const xx_data_struct_field_desc sxmt_list_uint32_be_fields[]={
 SX_FIELD("list_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxmt_list_uint32_be={0x60520076U,"modeltext_list_uint32_be",sxmt_list_uint32_be_fields,SX_COUNT(sxmt_list_uint32_be_fields),SX_BE};
typedef struct sxmt_property {unsigned kind,width,list_width;} sxmt_property;
typedef struct sxmt_element {uint64_t count;unsigned fields;sxmt_property props[64];} sxmt_element;
static bool sxmt_ply_type(sxmt_cursor*q,int64_t a,int64_t z,sxmt_property*p){
 static const char*names[]={"char","int8","uchar","uint8","short","int16","ushort","uint16","int","int32","uint","uint32","float","float32","double","float64"};
 for(unsigned i=0;i<SX_COUNT(names);i++)if(sxmt_eq(q,a,z,names[i])){p->kind=i<4?(i<2?'I':'U'):i<8?(i<6?'I':'U'):i<12?(i<10?'I':'U'):'F';p->width=i<4?1:i<8?2:i<14?4:8;return true;}return false;}
static bool sxmt_ply(sxmt_cursor*q){sxmt_element*es=xx_mem_alloc(sizeof(*es)*32);if(!es)return false;xx_rt_memset(es,0,sizeof(*es)*32);bool ok=false,be=false,ended=false;unsigned ne=0;int64_t a,e,z,k;
 if(!sxmt_line(q,&a,&e,false)||!sxmt_emit(q,&sxmt_signature,a,e-a)||!sxmt_line(q,&a,&e,false))goto done;int64_t next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false)||!sxmt_value(q,&sxmt_encoding,e,NULL)||!sxmt_value(q,&sxmt_version,e,NULL))goto done;be=e-a>=24&&!xx_rt_memcmp(q->b+a,"format binary_big_endian",23);q->p=next;
 while(sxmt_line(q,&a,&e,false)){if(q->p>65536)goto done;next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false))goto done;
  if(sxmt_eq(q,k,z,"end_header")){q->p=next;ended=true;break;}
  if(sxmt_eq(q,k,z,"comment")||sxmt_eq(q,k,z,"obj_info")){q->p=next;continue;}
  if(sxmt_eq(q,k,z,"element")){if(ne==32||!sxmt_value(q,&sxmt_element_name,e,NULL)||!sxmt_value(q,&sxmt_element_count,e,&es[ne].count)||es[ne].count>1000000)goto done;ne++;}
  else if(sxmt_eq(q,k,z,"property")){if(!ne||es[ne-1].fields==64||!sxmt_token(q,e,&a,&z,false))goto done;sxmt_property*prop=&es[ne-1].props[es[ne-1].fields++];if(sxmt_eq(q,a,z,"list")){sxmt_property cp={0};if(!sxmt_token(q,e,&a,&z,false)||!sxmt_ply_type(q,a,z,&cp)||cp.kind!='U'||!sxmt_emit(q,&sxmt_count_type,a,z))goto done;prop->list_width=cp.width;if(!sxmt_token(q,e,&a,&z,false))goto done;}if(!sxmt_ply_type(q,a,z,prop)||!sxmt_emit(q,&sxmt_property_type,a,z)||!sxmt_value(q,&sxmt_property_name,e,NULL))goto done;}
  else goto done;q->p=next;
 }if(!ended||!ne)goto done;
 for(unsigned el=0;el<ne;el++)for(uint64_t row=0;row<es[el].count;row++)for(unsigned f=0;f<es[el].fields;f++){if(q->c->count>=32000){ok=true;goto done;}sxmt_property*p=&es[el].props[f];uint64_t count=1;const sx_layout*l=sxmt_binary_type(p->kind,p->width,be);if(!l)goto done;
  if(p->list_width){unsigned w=p->list_width;if(w>(uint64_t)(q->n-q->p))goto done;count=w==1?q->b[q->p]:w==2?xx_data_get_u16(q->b+q->p,2,0,be):xx_data_get_u32(q->b+q->p,4,0,be);if(count>65536)goto done;const sx_layout*cl=w==1?(be?&sxmt_list_uint8_be:&sxmt_list_uint8_le):w==2?(be?&sxmt_list_uint16_be:&sxmt_list_uint16_le):(be?&sxmt_list_uint32_be:&sxmt_list_uint32_le);if(!sxmt_emit(q,cl,q->p,w))goto done;q->p+=w;}
  if(!sxmt_table(q,l,q->p,p->width,count))goto done;q->p+=(int64_t)(count*p->width);
 }ok=true;
done:xx_mem_free(es);return ok;}
bool sx_polygon_ply_build(sxmt_cursor*q)
{
 return sxmt_ply(q);
}
