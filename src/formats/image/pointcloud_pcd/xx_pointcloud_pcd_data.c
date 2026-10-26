/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pointcloud_pcd data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_field_type_fields[]={
 SX_FIELD("field_type","char",0,0,SX_STRING),
};
const sx_layout sxmt_field_type={0x60520008U,"modeltext_field_type",sxmt_field_type_fields,SX_COUNT(sxmt_field_type_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_point_count_fields[]={
 SX_FIELD("point_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_point_count={0x60520018U,"modeltext_point_count",sxmt_point_count_fields,SX_COUNT(sxmt_point_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_width_fields[]={
 SX_FIELD("width","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_width={0x60520019U,"modeltext_width",sxmt_width_fields,SX_COUNT(sxmt_width_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_height_fields[]={
 SX_FIELD("height","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_height={0x6052001aU,"modeltext_height",sxmt_height_fields,SX_COUNT(sxmt_height_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_sample_count_fields[]={
 SX_FIELD("sample_count","ascii_signed",0,0,SX_COUNT_PROP),
};
const sx_layout sxmt_sample_count={0x6052001bU,"modeltext_sample_count",sxmt_sample_count_fields,SX_COUNT(sxmt_sample_count_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_data_bytes_fields[]={
 SX_FIELD("data_bytes","ascii_signed",0,0,SX_SIZE),
};
const sx_layout sxmt_data_bytes={0x60520023U,"modeltext_data_bytes",sxmt_data_bytes_fields,SX_COUNT(sxmt_data_bytes_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_quaternion_w_fields[]={
 SX_FIELD("quaternion_w","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_quaternion_w={0x60520049U,"modeltext_quaternion_w",sxmt_quaternion_w_fields,SX_COUNT(sxmt_quaternion_w_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_quaternion_x_fields[]={
 SX_FIELD("quaternion_x","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_quaternion_x={0x6052004aU,"modeltext_quaternion_x",sxmt_quaternion_x_fields,SX_COUNT(sxmt_quaternion_x_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_quaternion_y_fields[]={
 SX_FIELD("quaternion_y","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_quaternion_y={0x6052004bU,"modeltext_quaternion_y",sxmt_quaternion_y_fields,SX_COUNT(sxmt_quaternion_y_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_quaternion_z_fields[]={
 SX_FIELD("quaternion_z","ascii_real",0,0,SX_NONE),
};
const sx_layout sxmt_quaternion_z={0x6052004cU,"modeltext_quaternion_z",sxmt_quaternion_z_fields,SX_COUNT(sxmt_quaternion_z_fields),SX_LE};
static bool sxmt_pcd(sxmt_cursor*q){uint64_t sizes[64]={0},counts[64],points=0;unsigned kinds[64]={0},nf=0;int64_t a,e,z,k;bool ended=false;for(unsigned i=0;i<64;i++)counts[i]=1;
 while(sxmt_line(q,&a,&e,true)){if(q->p>65536)return false;int64_t next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false))return false;
  const sx_layout*l=NULL;uint64_t*out=NULL;
  if(sxmt_eq(q,k,z,"VERSION"))l=&sxmt_version;
  else if(sxmt_eq(q,k,z,"WIDTH"))l=&sxmt_width;
  else if(sxmt_eq(q,k,z,"HEIGHT"))l=&sxmt_height;
  else if(sxmt_eq(q,k,z,"POINTS")){l=&sxmt_point_count;out=&points;}
  else if(sxmt_eq(q,k,z,"DATA")){if(!sxmt_value(q,&sxmt_encoding,e,NULL))return false;q->p=next;ended=true;break;}
  else if(sxmt_eq(q,k,z,"VIEWPOINT")){const sx_layout*ls[]={&sxmt_translate_x,&sxmt_translate_y,&sxmt_translate_z,&sxmt_quaternion_w,&sxmt_quaternion_x,&sxmt_quaternion_y,&sxmt_quaternion_z};for(unsigned i=0;i<7;i++)if(!sxmt_value(q,ls[i],e,NULL))return false;}
  else {unsigned index=0;bool fields=sxmt_eq(q,k,z,"FIELDS"),sz=sxmt_eq(q,k,z,"SIZE"),ty=sxmt_eq(q,k,z,"TYPE"),co=sxmt_eq(q,k,z,"COUNT");if(!fields&&!sz&&!ty&&!co)return false;
   while(sxmt_token(q,e,&a,&z,true)){if(index>=64)return false;if(fields){if(!sxmt_emit(q,&sxmt_property_name,a,z))return false;nf++;}else if(ty){if(z!=1||!sxmt_emit(q,&sxmt_field_type,a,z))return false;kinds[index]=q->b[a];}else {uint64_t n;if(!sxmt_uint_token(q,a,z,&n)||!sxmt_emit(q,sz?&sxmt_data_bytes:&sxmt_sample_count,a,z))return false;if(sz)sizes[index]=n;else counts[index]=n;}index++;}if(!fields&&index!=nf)return false;
  }if(l&&!sxmt_value(q,l,e,out))return false;q->p=next;
 }if(!ended||!nf||!points||points>1000000)return false;
 for(uint64_t i=0;i<points;i++)for(unsigned j=0;j<nf;j++){if(q->c->count>=32000)return true;if(sizes[j]>8||!counts[j]||counts[j]>65536)return false;const sx_layout*l=sxmt_binary_type(kinds[j],(unsigned)sizes[j],false);if(!l||!sxmt_table(q,l,q->p,(int64_t)sizes[j],counts[j]))return false;q->p+=(int64_t)(sizes[j]*counts[j]);}return true;}
bool sx_pointcloud_pcd_build(sxmt_cursor*q)
{
 return sxmt_pcd(q);
}
