/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ROS bag v1 data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_rosbag_signature_fields[] = {
    SX_FIELD("signature","char[13]",0,13,SX_SIGNATURE),
};
const sx_layout sxsw_rosbag_signature = {UINT32_C(0x602d0057),"rosbag_signature",sxsw_rosbag_signature_fields,SX_COUNT(sxsw_rosbag_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_header_size_fields[] = {
    SX_FIELD("header_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxsw_rosbag_header_size = {UINT32_C(0x602d0058),"rosbag_header_size",sxsw_rosbag_header_size_fields,SX_COUNT(sxsw_rosbag_header_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_field_size_fields[] = {
    SX_FIELD("field_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxsw_rosbag_field_size = {UINT32_C(0x602d0059),"rosbag_field_size",sxsw_rosbag_field_size_fields,SX_COUNT(sxsw_rosbag_field_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_data_size_fields[] = {
    SX_FIELD("data_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxsw_rosbag_data_size = {UINT32_C(0x602d005a),"rosbag_data_size",sxsw_rosbag_data_size_fields,SX_COUNT(sxsw_rosbag_data_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_conn_fields[] = {
    SX_FIELD("connection_id","uint32",0,4,SX_ID),
};
const sx_layout sxsw_rosbag_conn = {UINT32_C(0x602d005c),"rosbag_conn",sxsw_rosbag_conn_fields,SX_COUNT(sxsw_rosbag_conn_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_size_fields[] = {
    SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxsw_rosbag_size = {UINT32_C(0x602d005d),"rosbag_size",sxsw_rosbag_size_fields,SX_COUNT(sxsw_rosbag_size_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_count_fields[] = {
    SX_FIELD("count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsw_rosbag_count = {UINT32_C(0x602d005e),"rosbag_count",sxsw_rosbag_count_fields,SX_COUNT(sxsw_rosbag_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_ver_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
};
const sx_layout sxsw_rosbag_ver = {UINT32_C(0x602d005f),"rosbag_ver",sxsw_rosbag_ver_fields,SX_COUNT(sxsw_rosbag_ver_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_index_pos_fields[] = {
    SX_FIELD("index_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxsw_rosbag_index_pos = {UINT32_C(0x602d0060),"rosbag_index_pos",sxsw_rosbag_index_pos_fields,SX_COUNT(sxsw_rosbag_index_pos_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_chunk_pos_fields[] = {
    SX_FIELD("chunk_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxsw_rosbag_chunk_pos = {UINT32_C(0x602d0061),"rosbag_chunk_pos",sxsw_rosbag_chunk_pos_fields,SX_COUNT(sxsw_rosbag_chunk_pos_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_conn_count_fields[] = {
    SX_FIELD("connection_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsw_rosbag_conn_count = {UINT32_C(0x602d0062),"rosbag_conn_count",sxsw_rosbag_conn_count_fields,SX_COUNT(sxsw_rosbag_conn_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_chunk_count_fields[] = {
    SX_FIELD("chunk_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsw_rosbag_chunk_count = {UINT32_C(0x602d0063),"rosbag_chunk_count",sxsw_rosbag_chunk_count_fields,SX_COUNT(sxsw_rosbag_chunk_count_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_time_fields[] = {
    SX_FIELD("seconds","uint32",0,4,SX_TIME),
    SX_FIELD("nanoseconds","uint32",4,4,SX_NONE),
};
const sx_layout sxsw_rosbag_time = {UINT32_C(0x602d0064),"rosbag_time",sxsw_rosbag_time_fields,SX_COUNT(sxsw_rosbag_time_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_index_fields[] = {
    SX_FIELD("seconds","uint32",0,4,SX_TIME),
    SX_FIELD("nanoseconds","uint32",4,4,SX_NONE),
    SX_FIELD("record_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxsw_rosbag_index = {UINT32_C(0x602d0065),"rosbag_index",sxsw_rosbag_index_fields,SX_COUNT(sxsw_rosbag_index_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_rosbag_connection_count_fields[] = {
    SX_FIELD("connection_id","uint32",0,4,SX_ID),
    SX_FIELD("message_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxsw_rosbag_connection_count = {UINT32_C(0x602d0066),"rosbag_connection_count",sxsw_rosbag_connection_count_fields,SX_COUNT(sxsw_rosbag_connection_count_fields),SX_LE};
static bool sxsw_rb_fields(sx_context *c,int64_t at,int64_t end,unsigned *op,uint32_t *count)
{
 for(unsigned i=0;at<end;i++){
  uint32_t n;uint8_t b[64];if(i>=16||at>end-4||!sx_u32(c,at,false,&n)||n>(uint64_t)(end-at-4)||!sxsw_add(c,&sxsw_rosbag_field_size,at,4))return false;at+=4;
  unsigned key=0;for(;key<n&&key<64;key++){if(!sx_read(c,at+key,b+key,1))return false;if(b[key]=='=')break;}
  if(!key||key>=n||key>63)return false;b[key]=0;int64_t value=at+key+1;uint32_t size=n-key-1;const sx_layout *l=NULL;unsigned expected=4;
  if(!xx_rt_strcmp((const char*)b,"op")){l=&sxsw_rosbag_op;expected=1;uint8_t v;if(size==1&&sx_read(c,value,&v,1))*op=v;}
  else if(!xx_rt_strcmp((const char*)b,"conn"))l=&sxsw_rosbag_conn;
  else if(!xx_rt_strcmp((const char*)b,"size"))l=&sxsw_rosbag_size;
  else if(!xx_rt_strcmp((const char*)b,"count")){l=&sxsw_rosbag_count;if(size==4&&!sx_u32(c,value,false,count))return false;}
  else if(!xx_rt_strcmp((const char*)b,"ver"))l=&sxsw_rosbag_ver;
  else if(!xx_rt_strcmp((const char*)b,"conn_count"))l=&sxsw_rosbag_conn_count;
  else if(!xx_rt_strcmp((const char*)b,"chunk_count"))l=&sxsw_rosbag_chunk_count;
  else if(!xx_rt_strcmp((const char*)b,"index_pos")){l=&sxsw_rosbag_index_pos;expected=8;}
  else if(!xx_rt_strcmp((const char*)b,"chunk_pos")){l=&sxsw_rosbag_chunk_pos;expected=8;}
  else if(!xx_rt_strcmp((const char*)b,"time")||!xx_rt_strcmp((const char*)b,"start_time")||!xx_rt_strcmp((const char*)b,"end_time")){l=&sxsw_rosbag_time;expected=8;}
  if(l&&size==expected&&!sxsw_add(c,l,value,expected))return false;at+=n;
 }return at==end;
}
static bool sxsw_rb_records(sx_context *c,int64_t at,int64_t end,unsigned depth)
{
 if(depth>2)return false;
 for(unsigned i=0;at<end;i++){
  uint32_t n,bytes,count=0;unsigned op=0;
  if(i>=8192||at>end-4||!sxsw_span(c,at,4)||!sx_u32(c,at,false,&n)||n>65536||n>(uint64_t)(end-at-4)||!sxsw_add(c,&sxsw_rosbag_header_size,at,4))return false;at+=4;
  if(!sxsw_rb_fields(c,at,at+n,&op,&count))return false;at+=n;
  if(at>end-4||!sx_u32(c,at,false,&bytes)||bytes>(uint64_t)(end-at-4)||!sxsw_add(c,&sxsw_rosbag_data_size,at,4))return false;at+=4;
  if(op==5){if(!sxsw_rb_records(c,at,at+bytes,depth+1))return false;}
  else if(op==7){unsigned unused_op=0;uint32_t unused_count=0;if(!sxsw_rb_fields(c,at,at+bytes,&unused_op,&unused_count))return false;}
  else if(op==4){if(count>4090||(uint64_t)count*12!=bytes||!sxsw_table(c,&sxsw_rosbag_index,at,12,count))return false;}
  else if(op==6){if(count>128||(uint64_t)count*8!=bytes||!sxsw_table(c,&sxsw_rosbag_connection_count,at,8,count))return false;}
  at+=bytes;
 }return at==end;
}
static bool sxsw_rosbag(sx_context *c){return sxsw_add(c,&sxsw_rosbag_signature,0,13)&&sxsw_rb_records(c,13,c->size,0);}
bool sx_rosbag1_build(sx_context*c)
{
 return sxsw_rosbag(c);
}
