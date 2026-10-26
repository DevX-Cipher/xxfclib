/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NETCDF_CLASSIC data structures, moved out of the scienceheaders schema family. */
#include "../../xx_format_schema_scienceheaders.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsh_netcdf_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("version","uint8",3,1,SX_ID),
    SX_FIELD("record_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxsh_netcdf_header = {UINT32_C(0x602a001b),"netcdf_header",sxsh_netcdf_header_fields,SX_COUNT(sxsh_netcdf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_list_fields[] = {
    SX_FIELD("tag","uint32",0,4,SX_ID),
    SX_FIELD("count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxsh_netcdf_list = {UINT32_C(0x602a001c),"netcdf_list",sxsh_netcdf_list_fields,SX_COUNT(sxsh_netcdf_list_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_name_size_fields[] = {
    SX_FIELD("name_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxsh_netcdf_name_size = {UINT32_C(0x602a001d),"netcdf_name_size",sxsh_netcdf_name_size_fields,SX_COUNT(sxsh_netcdf_name_size_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_dimension_fields[] = {
    SX_FIELD("dimension_length","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsh_netcdf_dimension = {UINT32_C(0x602a001e),"netcdf_dimension",sxsh_netcdf_dimension_fields,SX_COUNT(sxsh_netcdf_dimension_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_rank_fields[] = {
    SX_FIELD("dimension_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsh_netcdf_rank = {UINT32_C(0x602a001f),"netcdf_rank",sxsh_netcdf_rank_fields,SX_COUNT(sxsh_netcdf_rank_fields),SX_BE};
static const xx_data_struct_field_desc sxsh_netcdf_dimension_id_fields[] = {
    SX_FIELD("dimension_id","uint32",0,4,SX_ID),
};
const sx_layout sxsh_netcdf_dimension_id = {UINT32_C(0x602a0020),"netcdf_dimension_id",sxsh_netcdf_dimension_id_fields,SX_COUNT(sxsh_netcdf_dimension_id_fields),SX_BE};
static bool sxsh_nc_name(sx_context *c,int64_t *at)
{
 uint32_t n;if(!sx_u32(c,*at,true,&n)||!n||n>255||!sxsh_span(c,*at,4+((n+3U)&~3U))||!sxsh_add(c,&sxsh_netcdf_name_size,*at,4))return false;*at+=4+((n+3U)&~3U);return true;
}
static bool sxsh_nc_list(sx_context *c,int64_t *at,uint32_t wanted,uint32_t limit,uint32_t *n)
{
 uint32_t tag;if(!sx_u32(c,*at,true,&tag)||!sx_u32(c,*at+4,true,n)||*n>limit||!((tag==0&&!*n)||tag==wanted)||!sxsh_add(c,&sxsh_netcdf_list,*at,8))return false;*at+=8;return true;
}
static bool sxsh_nc_attrs(sx_context *c,int64_t *at)
{
 uint32_t count;if(!sxsh_nc_list(c,at,12,1024,&count))return false;
 for(uint32_t i=0;i<count;i++){
  uint32_t type,n;if(!sxsh_nc_name(c,at)||!sx_u32(c,*at,true,&type)||!sx_u32(c,*at+4,true,&n)||!type||type>6||!sxsh_add(c,&sxsh_netcdf_attribute,*at,8))return false;
  uint32_t width=type<=2?1:type==3?2:type==6?8:4;uint64_t bytes=((uint64_t)n*width+3)&~UINT64_C(3);
  if(!sxsh_span(c,*at+8,bytes))return false;*at+=8+(int64_t)bytes;
 }return true;
}
static bool sxsh_nc(sx_context *c)
{
 uint8_t b[8];int64_t at=8;uint32_t dims,vars;
 if(!sx_read(c,0,b,8)||xx_rt_memcmp(b,"CDF",3)||(b[3]!=1&&b[3]!=2)||!sxsh_add(c,&sxsh_netcdf_header,0,8)||!sxsh_nc_list(c,&at,10,128,&dims))return false;
 for(uint32_t i=0;i<dims;i++){if(!sxsh_nc_name(c,&at)||!sxsh_add(c,&sxsh_netcdf_dimension,at,4))return false;at+=4;}
 if(!sxsh_nc_attrs(c,&at)||!sxsh_nc_list(c,&at,11,256,&vars)||!vars)return false;
 for(uint32_t i=0;i<vars;i++){
  uint32_t n;if(!sxsh_nc_name(c,&at)||!sx_u32(c,at,true,&n)||n>128||!sxsh_add(c,&sxsh_netcdf_rank,at,4)||!sxsh_table(c,&sxsh_netcdf_dimension_id,at+4,4,n))return false;
  for(uint32_t j=0;j<n;j++){uint32_t id;if(!sx_u32(c,at+4+j*4,true,&id)||id>=dims)return false;}
  at+=4+(int64_t)n*4;if(!sxsh_nc_attrs(c,&at)||!sxsh_add(c,b[3]==1?&sxsh_netcdf_variable32:&sxsh_netcdf_variable64,at,b[3]==1?12:16))return false;at+=b[3]==1?12:16;
 }return true;
}
bool sx_netcdf_classic_build(sx_context*c)
{
 bool ok=false;
 ok=sxsh_nc(c);
 return ok&&sxsh_finish(c);
}
