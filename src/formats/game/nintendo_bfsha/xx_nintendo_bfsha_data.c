/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo bfsha data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_fsha_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("byte_order","uint16",8,2,SX_ID),
 SX_FIELD("header_size","uint16",10,2,SX_SIZE),
 SX_FIELD("file_size","uint32",12,4,SX_SIZE),
 SX_FIELD("alignment","uint32",16,4,SX_SIZE),
 SX_FIELD("name_relative","int32",20,4,SX_OFFSET),
 SX_FIELD("string_pool_size","uint32",24,4,SX_SIZE),
 SX_FIELD("string_pool_relative","int32",28,4,SX_OFFSET),
 SX_FIELD("path_relative","int32",32,4,SX_OFFSET),
 SX_FIELD("model_count","uint16",36,2,SX_COUNT_PROP),
 SX_FIELD("unknown_26","uint16",38,2,SX_NONE),
 SX_FIELD("unknown_28","uint32",40,4,SX_NONE),
 SX_FIELD("model_dictionary_relative","int32",44,4,SX_OFFSET),
 SX_FIELD("unknown_30","uint32",48,4,SX_NONE),
 SX_FIELD("unknown_34","uint32",52,4,SX_NONE),
};
const sx_layout sxmx_fsha_header={UINT32_C(0x602E0076),"fsha_header",sxmx_fsha_header_fields,SX_COUNT(sxmx_fsha_header_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_string_length_fields[]={
 SX_FIELD("byte_length","uint32",0,4,SX_SIZE),
};
const sx_layout sxmx_fsha_string_length={UINT32_C(0x602E0077),"fsha_string_length",sxmx_fsha_string_length_fields,SX_COUNT(sxmx_fsha_string_length_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_model_fields[]={
 SX_FIELD("opaque_0","bytes",0,6,SX_NONE),
 SX_FIELD("program_count","uint16",6,2,SX_COUNT_PROP),
 SX_FIELD("opaque_8","bytes",8,20,SX_NONE),
 SX_FIELD("program_index","uint32",28,4,SX_ID),
 SX_FIELD("name_relative","int32",32,4,SX_OFFSET),
 SX_FIELD("opaque_24","bytes",36,52,SX_NONE),
 SX_FIELD("programs_relative","int32",88,4,SX_OFFSET),
 SX_FIELD("unknown_5c","uint32",92,4,SX_NONE),
 SX_FIELD("archive_relative","int32",96,4,SX_OFFSET),
 SX_FIELD("unknown_64","bytes",100,12,SX_NONE),
};
const sx_layout sxmx_fsha_model={UINT32_C(0x602E0078),"fsha_model",sxmx_fsha_model_fields,SX_COUNT(sxmx_fsha_model_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_program_fields[]={
 SX_FIELD("opaque_0","bytes",0,40,SX_NONE),
 SX_FIELD("vertex_shader_relative","int32",40,4,SX_OFFSET),
 SX_FIELD("geometry_shader_relative","int32",44,4,SX_OFFSET),
 SX_FIELD("pixel_shader_relative","int32",48,4,SX_OFFSET),
 SX_FIELD("model_relative","int32",52,4,SX_OFFSET),
};
const sx_layout sxmx_fsha_program={UINT32_C(0x602E0079),"fsha_program",sxmx_fsha_program_fields,SX_COUNT(sxmx_fsha_program_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_vertex_shader_fields[]={
 SX_FIELD("gpu_registers","bytes",0,208,SX_NONE),
 SX_FIELD("code_size","uint32",208,4,SX_SIZE),
 SX_FIELD("code_relative","int32",212,4,SX_OFFSET),
 SX_FIELD("shader_mode","uint32",216,4,SX_ID),
 SX_FIELD("unused_native_metadata","bytes",220,88,SX_NONE),
};
const sx_layout sxmx_fsha_vertex_shader={UINT32_C(0x602E007A),"fsha_vertex_shader",sxmx_fsha_vertex_shader_fields,SX_COUNT(sxmx_fsha_vertex_shader_fields),SX_BE};
static const xx_data_struct_field_desc sxmx_fsha_pixel_shader_fields[]={
 SX_FIELD("gpu_registers","bytes",0,164,SX_NONE),
 SX_FIELD("code_size","uint32",164,4,SX_SIZE),
 SX_FIELD("code_relative","int32",168,4,SX_OFFSET),
 SX_FIELD("shader_mode","uint32",172,4,SX_ID),
 SX_FIELD("unused_native_metadata","bytes",176,56,SX_NONE),
};
const sx_layout sxmx_fsha_pixel_shader={UINT32_C(0x602E007B),"fsha_pixel_shader",sxmx_fsha_pixel_shader_fields,SX_COUNT(sxmx_fsha_pixel_shader_fields),SX_BE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_fsha_shader(sxmx_view*v,size_t word,bool pixel)
{size_t at;if(!sxmx_relative(v,word,true,&at))return false;if(at==word&&!sxmx_u32(v->p+word,true))return true;return sxmx_row(v,pixel?&sxmx_fsha_pixel_shader:&sxmx_fsha_vertex_shader,at,v->n);}
static bool sxmx_fsha(sxmx_view*v)
{size_t dict,pool;if(!SM_ROW(fsha_header,0,v->n)||!sxmx_relative(v,44,true,&dict)||!SM_ROW(bfres_dictionary,dict,v->n)||!sxmx_relative(v,28,true,&pool))return false;uint32_t n=sxmx_u32(v->p+dict+4,true);if(n>32||!sxmx_table(v,&sxmx_bfres_node,dict+8,(uint64_t)n+1,v->n))return false;size_t size=sxmx_u32(v->p+24,true);if(!sxmx_need(v,pool,size,v->n))return false;size_t at=pool,end=pool+size;while(at<end){if(!SM_ROW(fsha_string_length,at,end))return false;uint32_t z=sxmx_u32(v->p+at,true);at+=4;if(!sxmx_need(v,at,(uint64_t)z+1,end))return false;at=(at+z+1+3)&~(size_t)3;if(at>end)return false;}for(uint32_t i=1;i<=n;i++){size_t model,program;if(!sxmx_relative(v,dict+8+(size_t)i*16+12,true,&model)||!SM_ROW(fsha_model,model,v->n)||!sxmx_relative(v,model+88,true,&program))return false;uint32_t count=sxmx_u16(v->p+model+6,true);if(count>256||!sxmx_table(v,&sxmx_fsha_program,program,count,v->n))return false;for(uint32_t j=0;j<count;j++){size_t p=program+(size_t)j*56;if(!sxmx_fsha_shader(v,p+40,false)||!sxmx_fsha_shader(v,p+48,true))return false;}}return true;}
bool sx_nintendo_bfsha_build(sxmx_view*v)
{
 return sxmx_fsha(v);
}
#undef SM_ROW
