/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ensight_gold_geometry data structures, moved out of the scientificextra schema family. */
#include "../../xx_format_schema_scientificextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxscx_ensight_header_fields[] = {
    SX_FIELD("encoding","char[80]",0,80,SX_SIGNATURE),
    SX_FIELD("description1","char[80]",80,80,SX_STRING),
    SX_FIELD("description2","char[80]",160,80,SX_STRING),
    SX_FIELD("node_id_mode","char[80]",240,80,SX_ID),
    SX_FIELD("element_id_mode","char[80]",320,80,SX_ID),
};
const sx_layout sxscx_ensight_header = {UINT32_C(0x6031000d),"ensight_header",sxscx_ensight_header_fields,SX_COUNT(sxscx_ensight_header_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_part_fields[] = {
    SX_FIELD("part_marker","char[80]",0,80,SX_SIGNATURE),
    SX_FIELD("part_id","int32",80,4,SX_ID),
    SX_FIELD("description","char[80]",84,80,SX_STRING),
    SX_FIELD("coordinates_marker","char[80]",164,80,SX_SIGNATURE),
    SX_FIELD("node_count","int32",244,4,SX_COUNT_PROP),
};
const sx_layout sxscx_ensight_part = {UINT32_C(0x6031000e),"ensight_part",sxscx_ensight_part_fields,SX_COUNT(sxscx_ensight_part_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_elements_fields[] = {
    SX_FIELD("element_type","char[80]",0,80,SX_ID),
    SX_FIELD("element_count","int32",80,4,SX_COUNT_PROP),
};
const sx_layout sxscx_ensight_elements = {UINT32_C(0x6031000f),"ensight_elements",sxscx_ensight_elements_fields,SX_COUNT(sxscx_ensight_elements_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_given_id_fields[] = {
    SX_FIELD("identifier","int32",0,4,SX_ID),
};
const sx_layout sxscx_ensight_given_id = {UINT32_C(0x60310010),"ensight_given_id",sxscx_ensight_given_id_fields,SX_COUNT(sxscx_ensight_given_id_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_coordinate_fields[] = {
    SX_FIELD("coordinate","float32",0,4,SX_NONE),
};
const sx_layout sxscx_ensight_coordinate = {UINT32_C(0x60310011),"ensight_coordinate",sxscx_ensight_coordinate_fields,SX_COUNT(sxscx_ensight_coordinate_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_ensight_connectivity_fields[] = {
    SX_FIELD("local_node_index","int32",0,4,SX_NONE),
};
const sx_layout sxscx_ensight_connectivity = {UINT32_C(0x60310012),"ensight_connectivity",sxscx_ensight_connectivity_fields,SX_COUNT(sxscx_ensight_connectivity_fields),SX_LE};
static bool sxscx_ensight(sx_context *c,const uint8_t *b,size_t n)
{
 if(n<400||!sxscx_add(c,&sxscx_ensight_header,0))return false;bool nodeids=!xx_rt_memcmp(b+240,"node id given",13),elementids=!xx_rt_memcmp(b+320,"element id given",16);uint64_t at=400;
 for(unsigned part=0;at<n&&part<1000;part++){
  if(!sxscx_span(c,at,248)||!sxscx_add(c,&sxscx_ensight_part,at))return false;uint32_t nodes=sxscx32(b+at+244,false);at+=248;if(!nodes||nodes>1000000)return false;
  if(nodeids){if(!sxscx_table(c,&sxscx_ensight_given_id,at,nodes))return false;at+=(uint64_t)nodes*4;}
  if(!sxscx_table(c,&sxscx_ensight_coordinate,at,(uint64_t)nodes*3))return false;at+=(uint64_t)nodes*12;
  while(at<n){
   if(!sxscx_span(c,at,80))return false;if(!xx_rt_memcmp(b+at,"part",4))break;
   static const char *const names[]={"point","bar2","tria3","quad4","tetra4","pyramid5","penta6","hexa8"};static const unsigned widths[]={1,2,3,4,4,5,6,8};unsigned arity=0;
   for(unsigned i=0;i<8;i++)if(!xx_rt_memcmp(b+at,names[i],xx_rt_strlen(names[i]))){arity=widths[i];break;}
   if(!arity||!sxscx_span(c,at,84)||!sxscx_add(c,&sxscx_ensight_elements,at))return false;uint32_t count=sxscx32(b+at+80,false);if(!count||count>1000000)return false;at+=84;
   if(elementids){if(!sxscx_table(c,&sxscx_ensight_given_id,at,count))return false;at+=(uint64_t)count*4;}
   if(!sxscx_table(c,&sxscx_ensight_connectivity,at,(uint64_t)count*arity))return false;at+=(uint64_t)count*arity*4;
  }
 }return at==n;
}
bool sx_ensight_gold_geometry_build(sx_context *c,uint8_t *b)
{
 return sxscx_ensight(c,b,(size_t)c->size);
}
