/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * openexr data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_exr_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("version_and_flags","uint32",4,4,SX_FLAGS),
};
const sx_layout sxrm_exr_header = {UINT32_C(0x601d0003),"exr_header",sxrm_exr_header_fields,SX_COUNT(sxrm_exr_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_attribute_length_fields[] = {
    SX_FIELD("value_size","int32",0,4,SX_SIZE),
};
const sx_layout sxrm_exr_attribute_length = {UINT32_C(0x601d0004),"exr_attribute_length",sxrm_exr_attribute_length_fields,SX_COUNT(sxrm_exr_attribute_length_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_channel_fields[] = {
    SX_FIELD("pixel_type","int32",0,4,SX_ID),
    SX_FIELD("perceptually_linear","uint8",4,1,SX_FLAGS),
    SX_FIELD("reserved","uint8[3]",5,3,SX_RESERVED),
    SX_FIELD("x_sampling","int32",8,4,SX_NONE),
    SX_FIELD("y_sampling","int32",12,4,SX_NONE),
};
const sx_layout sxrm_exr_channel = {UINT32_C(0x601d0005),"exr_channel",sxrm_exr_channel_fields,SX_COUNT(sxrm_exr_channel_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_box2i_fields[] = {
    SX_FIELD("minimum_x","int32",0,4,SX_NONE),
    SX_FIELD("minimum_y","int32",4,4,SX_NONE),
    SX_FIELD("maximum_x","int32",8,4,SX_NONE),
    SX_FIELD("maximum_y","int32",12,4,SX_NONE),
};
const sx_layout sxrm_exr_box2i = {UINT32_C(0x601d0006),"exr_box2i",sxrm_exr_box2i_fields,SX_COUNT(sxrm_exr_box2i_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_float_fields[] = {
    SX_FIELD("value","float32",0,4,SX_NONE),
};
const sx_layout sxrm_exr_float = {UINT32_C(0x601d0007),"exr_float",sxrm_exr_float_fields,SX_COUNT(sxrm_exr_float_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_v2f_fields[] = {
    SX_FIELD("x","float32",0,4,SX_NONE),
    SX_FIELD("y","float32",4,4,SX_NONE),
};
const sx_layout sxrm_exr_v2f = {UINT32_C(0x601d0008),"exr_v2f",sxrm_exr_v2f_fields,SX_COUNT(sxrm_exr_v2f_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_compression_fields[] = {
    SX_FIELD("method","uint8",0,1,SX_ID),
};
const sx_layout sxrm_exr_compression = {UINT32_C(0x601d0009),"exr_compression",sxrm_exr_compression_fields,SX_COUNT(sxrm_exr_compression_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_line_order_fields[] = {
    SX_FIELD("order","uint8",0,1,SX_ID),
};
const sx_layout sxrm_exr_line_order = {UINT32_C(0x601d000a),"exr_line_order",sxrm_exr_line_order_fields,SX_COUNT(sxrm_exr_line_order_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_chunk_offset_fields[] = {
    SX_FIELD("chunk_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sxrm_exr_chunk_offset = {UINT32_C(0x601d000b),"exr_chunk_offset",sxrm_exr_chunk_offset_fields,SX_COUNT(sxrm_exr_chunk_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_exr_scanline_chunk_fields[] = {
    SX_FIELD("y_coordinate","int32",0,4,SX_NONE),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
};
const sx_layout sxrm_exr_scanline_chunk = {UINT32_C(0x601d000c),"exr_scanline_chunk",sxrm_exr_scanline_chunk_fields,SX_COUNT(sxrm_exr_scanline_chunk_fields),SX_LE};
static bool sxrm_string(sx_context *c,uint64_t *p,uint64_t end,char *out,size_t cap)
{
 for(size_t i=0;i<cap;i++){uint8_t b;if(*p>=end||!sxrm_read(c,(*p)++,&b,1))return false;out[i]=(char)b;if(!b)return true;}return false;
}
static bool sxrm_exr(sx_context *c)
{
 uint8_t h[16];if(!sxrm_read(c,0,h,8)||sxrm32(h,false)!=20000630U||!sxrm_add(c,&sxrm_exr_header,0))return false;
 uint64_t p=8;int32_t ymin=0,ymax=-1;unsigned compression=99;bool terminal=false;
 for(unsigned step=0;step<4096;step++){
  char name[258],type[258];if(!sxrm_string(c,&p,(uint64_t)c->size,name,sizeof(name)))break;if(!name[0]){terminal=true;break;}
  if(!sxrm_string(c,&p,(uint64_t)c->size,type,sizeof(type))||!sxrm_read(c,p,h,4))break;uint32_t n=sxrm32(h,false);if(n>INT32_MAX||!sxrm_span(c,p+4,n))break;
  if(!sxrm_add(c,&sxrm_exr_attribute_length,p))return false;p+=4;
  if(!xx_rt_strcmp(type,"chlist")){uint64_t q=p;for(unsigned ch=0;ch<256;ch++){char channel[258];if(!sxrm_string(c,&q,p+n,channel,sizeof(channel))||!channel[0]||p+n-q<16)break;if(!sxrm_add(c,&sxrm_exr_channel,q))return false;q+=16;}}
  else if(!xx_rt_strcmp(type,"box2i")&&n==16){if(!sxrm_add(c,&sxrm_exr_box2i,p))return false;if(!xx_rt_strcmp(name,"dataWindow")){if(!sxrm_read(c,p,h,16))return false;ymin=(int32_t)sxrm32(h+4,false);ymax=(int32_t)sxrm32(h+12,false);}}
  else if(!xx_rt_strcmp(type,"float")&&n==4){if(!sxrm_add(c,&sxrm_exr_float,p))return false;}
  else if(!xx_rt_strcmp(type,"v2f")&&n==8){if(!sxrm_add(c,&sxrm_exr_v2f,p))return false;}
  else if(!xx_rt_strcmp(type,"compression")&&n==1){if(!sxrm_read(c,p,h,1)||!sxrm_add(c,&sxrm_exr_compression,p))return false;compression=h[0];}
  else if(!xx_rt_strcmp(type,"lineOrder")&&n==1){if(!sxrm_add(c,&sxrm_exr_line_order,p))return false;}
  p+=n;
 }
 if(terminal&&compression<12&&ymax>=ymin){static const unsigned lines[]={1,1,1,16,32,16,32,32,32,256,256,32};uint64_t n=((uint64_t)((int64_t)ymax-ymin+1)+lines[compression]-1)/lines[compression];
  if(n<=4096&&sxrm_span(c,p,n*8)){if(!sxrm_table(c,&sxrm_exr_chunk_offset,p,n))return false;for(uint64_t i=0;i<n;i++){if(!sxrm_read(c,p+i*8,h,8))return false;uint64_t q=sxrm_uint(h,8,false);if(q<p+n*8||!sxrm_read(c,q,h,8))continue;if(sxrm_span(c,q+8,sxrm32(h+4,false))&&!sxrm_add(c,&sxrm_exr_scanline_chunk,q))return false;}}
 }return !c->failed;
}
bool sx_openexr_build(sx_context*c)
{
 return sxrm_exr(c);
}
