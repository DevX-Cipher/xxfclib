/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apache Arrow file data structures, moved out of the columnar schema family. */
#include "../../xx_format_schema_columnar.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxq_arrow_file_header_fields[] = {
    SX_FIELD("magic", "char[6]", 0, 6, SX_SIGNATURE),
    SX_FIELD("padding", "bytes", 6, 2, SX_RESERVED),
};
const sx_layout sxq_arrow_file_header = {UINT32_C(0x601F0001),"arrow_file_header",sxq_arrow_file_header_fields,SX_COUNT(sxq_arrow_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_file_trailer_fields[] = {
    SX_FIELD("footer_length", "int32", 0, 4, SX_SIZE),
    SX_FIELD("magic", "char[6]", 4, 6, SX_SIGNATURE),
};
const sx_layout sxq_arrow_file_trailer = {UINT32_C(0x601F0002),"arrow_file_trailer",sxq_arrow_file_trailer_fields,SX_COUNT(sxq_arrow_file_trailer_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_message_prefix_fields[] = {
    SX_FIELD("metadata_length", "int32", 0, 4, SX_SIZE),
};
const sx_layout sxq_arrow_message_prefix = {UINT32_C(0x601F0003),"arrow_message_prefix",sxq_arrow_message_prefix_fields,SX_COUNT(sxq_arrow_message_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_continuation_prefix_fields[] = {
    SX_FIELD("continuation", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("metadata_length", "int32", 4, 4, SX_SIZE),
};
const sx_layout sxq_arrow_continuation_prefix = {UINT32_C(0x601F0004),"arrow_continuation_prefix",sxq_arrow_continuation_prefix_fields,SX_COUNT(sxq_arrow_continuation_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_flatbuffer_root_fields[] = {
    SX_FIELD("root_offset", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_flatbuffer_root = {UINT32_C(0x601F0005),"arrow_flatbuffer_root",sxq_arrow_flatbuffer_root_fields,SX_COUNT(sxq_arrow_flatbuffer_root_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_table_header_fields[] = {
    SX_FIELD("vtable_displacement", "int32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_table_header = {UINT32_C(0x601F0006),"arrow_table_header",sxq_arrow_table_header_fields,SX_COUNT(sxq_arrow_table_header_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_vtable_header_fields[] = {
    SX_FIELD("vtable_size", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("object_size", "uint16", 2, 2, SX_SIZE),
};
const sx_layout sxq_arrow_vtable_header = {UINT32_C(0x601F0007),"arrow_vtable_header",sxq_arrow_vtable_header_fields,SX_COUNT(sxq_arrow_vtable_header_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_vtable_entry_fields[] = {
    SX_FIELD("field_offset", "uint16", 0, 2, SX_OFFSET),
};
const sx_layout sxq_arrow_vtable_entry = {UINT32_C(0x601F0008),"arrow_vtable_entry",sxq_arrow_vtable_entry_fields,SX_COUNT(sxq_arrow_vtable_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_vector_header_fields[] = {
    SX_FIELD("element_count", "uint32", 0, 4, SX_COUNT_PROP),
};
const sx_layout sxq_arrow_vector_header = {UINT32_C(0x601F0009),"arrow_vector_header",sxq_arrow_vector_header_fields,SX_COUNT(sxq_arrow_vector_header_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_vector_reference_fields[] = {
    SX_FIELD("object_offset", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_vector_reference = {UINT32_C(0x601F000A),"arrow_vector_reference",sxq_arrow_vector_reference_fields,SX_COUNT(sxq_arrow_vector_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_string_header_fields[] = {
    SX_FIELD("byte_length", "uint32", 0, 4, SX_SIZE),
};
const sx_layout sxq_arrow_string_header = {UINT32_C(0x601F000B),"arrow_string_header",sxq_arrow_string_header_fields,SX_COUNT(sxq_arrow_string_header_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_block_fields[] = {
    SX_FIELD("message_offset", "int64", 0, 8, SX_OFFSET),
    SX_FIELD("metadata_length", "int32", 8, 4, SX_SIZE),
    SX_FIELD("alignment_padding", "bytes", 12, 4, SX_RESERVED),
    SX_FIELD("body_length", "int64", 16, 8, SX_SIZE),
};
const sx_layout sxq_arrow_block = {UINT32_C(0x601F000C),"arrow_block",sxq_arrow_block_fields,SX_COUNT(sxq_arrow_block_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_field_node_fields[] = {
    SX_FIELD("length", "int64", 0, 8, SX_COUNT_PROP),
    SX_FIELD("null_count", "int64", 8, 8, SX_COUNT_PROP),
};
const sx_layout sxq_arrow_field_node = {UINT32_C(0x601F000D),"arrow_field_node",sxq_arrow_field_node_fields,SX_COUNT(sxq_arrow_field_node_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_buffer_fields[] = {
    SX_FIELD("body_offset", "int64", 0, 8, SX_OFFSET),
    SX_FIELD("byte_length", "int64", 8, 8, SX_SIZE),
};
const sx_layout sxq_arrow_buffer = {UINT32_C(0x601F000E),"arrow_buffer",sxq_arrow_buffer_fields,SX_COUNT(sxq_arrow_buffer_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_footer_schema_fields[] = {
    SX_FIELD("schema", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_footer_schema = {UINT32_C(0x601F0010),"arrow_footer_schema",sxq_arrow_footer_schema_fields,SX_COUNT(sxq_arrow_footer_schema_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_footer_dictionaries_fields[] = {
    SX_FIELD("dictionaries", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_footer_dictionaries = {UINT32_C(0x601F0011),"arrow_footer_dictionaries",sxq_arrow_footer_dictionaries_fields,SX_COUNT(sxq_arrow_footer_dictionaries_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_footer_record_batches_fields[] = {
    SX_FIELD("record_batches", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_footer_record_batches = {UINT32_C(0x601F0012),"arrow_footer_record_batches",sxq_arrow_footer_record_batches_fields,SX_COUNT(sxq_arrow_footer_record_batches_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_footer_custom_metadata_fields[] = {
    SX_FIELD("custom_metadata", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_footer_custom_metadata = {UINT32_C(0x601F0013),"arrow_footer_custom_metadata",sxq_arrow_footer_custom_metadata_fields,SX_COUNT(sxq_arrow_footer_custom_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_schema_endianness_fields[] = {
    SX_FIELD("endianness", "int16", 0, 2, SX_ID),
};
const sx_layout sxq_arrow_schema_endianness = {UINT32_C(0x601F0014),"arrow_schema_endianness",sxq_arrow_schema_endianness_fields,SX_COUNT(sxq_arrow_schema_endianness_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_schema_fields_fields[] = {
    SX_FIELD("fields", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_schema_fields = {UINT32_C(0x601F0015),"arrow_schema_fields",sxq_arrow_schema_fields_fields,SX_COUNT(sxq_arrow_schema_fields_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_schema_custom_metadata_fields[] = {
    SX_FIELD("custom_metadata", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_schema_custom_metadata = {UINT32_C(0x601F0016),"arrow_schema_custom_metadata",sxq_arrow_schema_custom_metadata_fields,SX_COUNT(sxq_arrow_schema_custom_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_schema_features_fields[] = {
    SX_FIELD("features", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_schema_features = {UINT32_C(0x601F0017),"arrow_schema_features",sxq_arrow_schema_features_fields,SX_COUNT(sxq_arrow_schema_features_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_field_name_fields[] = {
    SX_FIELD("name", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_field_name = {UINT32_C(0x601F0018),"arrow_field_name",sxq_arrow_field_name_fields,SX_COUNT(sxq_arrow_field_name_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_field_nullable_fields[] = {
    SX_FIELD("nullable", "uint8", 0, 1, SX_FLAGS),
};
const sx_layout sxq_arrow_field_nullable = {UINT32_C(0x601F0019),"arrow_field_nullable",sxq_arrow_field_nullable_fields,SX_COUNT(sxq_arrow_field_nullable_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_field_type_tag_fields[] = {
    SX_FIELD("type_tag", "uint8", 0, 1, SX_ID),
};
const sx_layout sxq_arrow_field_type_tag = {UINT32_C(0x601F001A),"arrow_field_type_tag",sxq_arrow_field_type_tag_fields,SX_COUNT(sxq_arrow_field_type_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_field_type_fields[] = {
    SX_FIELD("type", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_field_type = {UINT32_C(0x601F001B),"arrow_field_type",sxq_arrow_field_type_fields,SX_COUNT(sxq_arrow_field_type_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_field_children_fields[] = {
    SX_FIELD("children", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_field_children = {UINT32_C(0x601F001C),"arrow_field_children",sxq_arrow_field_children_fields,SX_COUNT(sxq_arrow_field_children_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_field_custom_metadata_fields[] = {
    SX_FIELD("custom_metadata", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_field_custom_metadata = {UINT32_C(0x601F001D),"arrow_field_custom_metadata",sxq_arrow_field_custom_metadata_fields,SX_COUNT(sxq_arrow_field_custom_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_int_type_bit_width_fields[] = {
    SX_FIELD("bit_width", "int32", 0, 4, SX_COUNT_PROP),
};
const sx_layout sxq_arrow_int_type_bit_width = {UINT32_C(0x601F001E),"arrow_int_type_bit_width",sxq_arrow_int_type_bit_width_fields,SX_COUNT(sxq_arrow_int_type_bit_width_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_int_type_is_signed_fields[] = {
    SX_FIELD("is_signed", "uint8", 0, 1, SX_FLAGS),
};
const sx_layout sxq_arrow_int_type_is_signed = {UINT32_C(0x601F001F),"arrow_int_type_is_signed",sxq_arrow_int_type_is_signed_fields,SX_COUNT(sxq_arrow_int_type_is_signed_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_message_header_tag_fields[] = {
    SX_FIELD("header_tag", "uint8", 0, 1, SX_ID),
};
const sx_layout sxq_arrow_message_header_tag = {UINT32_C(0x601F0021),"arrow_message_header_tag",sxq_arrow_message_header_tag_fields,SX_COUNT(sxq_arrow_message_header_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_message_header_fields[] = {
    SX_FIELD("header", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_message_header = {UINT32_C(0x601F0022),"arrow_message_header",sxq_arrow_message_header_fields,SX_COUNT(sxq_arrow_message_header_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_message_body_length_fields[] = {
    SX_FIELD("body_length", "int64", 0, 8, SX_SIZE),
};
const sx_layout sxq_arrow_message_body_length = {UINT32_C(0x601F0023),"arrow_message_body_length",sxq_arrow_message_body_length_fields,SX_COUNT(sxq_arrow_message_body_length_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_message_custom_metadata_fields[] = {
    SX_FIELD("custom_metadata", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_message_custom_metadata = {UINT32_C(0x601F0024),"arrow_message_custom_metadata",sxq_arrow_message_custom_metadata_fields,SX_COUNT(sxq_arrow_message_custom_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_record_batch_length_fields[] = {
    SX_FIELD("length", "int64", 0, 8, SX_COUNT_PROP),
};
const sx_layout sxq_arrow_record_batch_length = {UINT32_C(0x601F0025),"arrow_record_batch_length",sxq_arrow_record_batch_length_fields,SX_COUNT(sxq_arrow_record_batch_length_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_record_batch_nodes_fields[] = {
    SX_FIELD("nodes", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_record_batch_nodes = {UINT32_C(0x601F0026),"arrow_record_batch_nodes",sxq_arrow_record_batch_nodes_fields,SX_COUNT(sxq_arrow_record_batch_nodes_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_record_batch_buffers_fields[] = {
    SX_FIELD("buffers", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_record_batch_buffers = {UINT32_C(0x601F0027),"arrow_record_batch_buffers",sxq_arrow_record_batch_buffers_fields,SX_COUNT(sxq_arrow_record_batch_buffers_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_record_batch_variadic_buffer_counts_fields[] = {
    SX_FIELD("variadic_buffer_counts", "uint32", 0, 4, SX_OFFSET),
};
const sx_layout sxq_arrow_record_batch_variadic_buffer_counts = {UINT32_C(0x601F0028),"arrow_record_batch_variadic_buffer_counts",sxq_arrow_record_batch_variadic_buffer_counts_fields,SX_COUNT(sxq_arrow_record_batch_variadic_buffer_counts_fields),SX_LE};
static const sx_layout *const sxq_arrow_footer_rows[]={&sxq_arrow_footer_version,&sxq_arrow_footer_schema,&sxq_arrow_footer_dictionaries,&sxq_arrow_footer_record_batches,&sxq_arrow_footer_custom_metadata};
static const sx_layout *const sxq_arrow_schema_rows[]={&sxq_arrow_schema_endianness,&sxq_arrow_schema_fields,&sxq_arrow_schema_custom_metadata,&sxq_arrow_schema_features};
static const sx_layout *const sxq_arrow_field_rows[]={&sxq_arrow_field_name,&sxq_arrow_field_nullable,&sxq_arrow_field_type_tag,&sxq_arrow_field_type,NULL,&sxq_arrow_field_children,&sxq_arrow_field_custom_metadata};
static const sx_layout *const sxq_arrow_int_type_rows[]={&sxq_arrow_int_type_bit_width,&sxq_arrow_int_type_is_signed};
static const sx_layout *const sxq_arrow_message_rows[]={&sxq_arrow_message_version,&sxq_arrow_message_header_tag,&sxq_arrow_message_header,&sxq_arrow_message_body_length,&sxq_arrow_message_custom_metadata};
static const sx_layout *const sxq_arrow_record_batch_rows[]={&sxq_arrow_record_batch_length,&sxq_arrow_record_batch_nodes,&sxq_arrow_record_batch_buffers,NULL,&sxq_arrow_record_batch_variadic_buffer_counts};
#define SXQ_RECORD_LIMIT 100000U
#define SXQ_META_LIMIT (16U*1024U*1024U)
static uint16_t sxq16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
static uint64_t sxq64(const uint8_t *p){return xx_data_get_u64(p,8,0,false);}
static bool sxq_table(sxq_window *w,const sx_layout *l,uint64_t p,uint64_t n,uint64_t count){
 return !count||(count<=SXQ_RECORD_LIMIT&&n&&count<=UINT64_MAX/n&&sxq_span(w,p,n*count)&&sx_table(w->c,l,(int64_t)(w->base+p),(int64_t)n,count));
}
/* FlatBuffers offsets are relative to their own physical words; vtable displacement
 * is signed and is subtracted from the table address. */
static bool sxq_a_field(sxq_window *w,uint64_t t,unsigned id,unsigned width,uint64_t *out){
 if(!sxq_span(w,t,4))return false;int64_t delta=(int32_t)sxq32(w->b+t);int64_t vt=(int64_t)t-delta;
 if(vt<0||!sxq_span(w,(uint64_t)vt,4))return false;uint16_t vn=sxq16(w->b+vt),on=sxq16(w->b+vt+2);
 if(vn<4||(vn&1)||on<4||!sxq_span(w,(uint64_t)vt,vn)||!sxq_span(w,t,on))return false;
 *out=0;if((uint64_t)id*2+6>vn)return true;uint16_t off=sxq16(w->b+vt+4+id*2);
 if(!off)return true;if(off<4||off>on||width>on-off)return false;*out=t+off;return true;
}
static bool sxq_a_ref(sxq_window *w,uint64_t field,uint64_t *out){
 if(!field){*out=0;return true;}if(!sxq_span(w,field,4))return false;uint32_t d=sxq32(w->b+field);if(d<4||!sxq_span(w,field+d,4))return false;*out=field+d;return true;
}
static bool sxq_a_parse(sxq_window *w,uint64_t t,unsigned kind,unsigned depth);
static bool sxq_a_vector(sxq_window *w,uint64_t field,unsigned width,const sx_layout *l,int child,unsigned depth){
 uint64_t v;if(!sxq_a_ref(w,field,&v))return false;if(!v)return true;uint32_t n=sxq32(w->b+v);
 if(n>SXQ_RECORD_LIMIT||!sxq_span(w,v+4,(uint64_t)n*width)||!sxq_wadd(w,&sxq_arrow_vector_header,v))return false;
 if(l&&!sxq_table(w,l,v+4,width,n))return false;
 if(child>=0)for(uint32_t i=0;i<n;i++){uint64_t at=v+4+(uint64_t)i*4,p;if(!sxq_wadd(w,&sxq_arrow_vector_reference,at)||!sxq_a_ref(w,at,&p)||!sxq_a_parse(w,p,(unsigned)child,depth+1))return false;}
 return true;
}
static bool sxq_a_parse(sxq_window *w,uint64_t t,unsigned kind,unsigned depth){
 static const sx_layout *const *const sets[]={sxq_arrow_footer_rows,sxq_arrow_schema_rows,sxq_arrow_field_rows,sxq_arrow_int_type_rows,sxq_arrow_message_rows,sxq_arrow_record_batch_rows};
 static const unsigned counts[]={5,4,7,2,5,5};
 if(kind>=6||depth>24||++w->work>SXQ_RECORD_LIMIT||!sxq_span(w,t,4))return false;
 int64_t vt=(int64_t)t-(int32_t)sxq32(w->b+t);if(vt<0||!sxq_span(w,(uint64_t)vt,4))return false;
 uint16_t vn=sxq16(w->b+vt);uint64_t fields[7]={0};
 if(!sxq_wadd(w,&sxq_arrow_table_header,t)||!sxq_wadd(w,&sxq_arrow_vtable_header,(uint64_t)vt)||vn<4||(vn&1)||!sxq_table(w,&sxq_arrow_vtable_entry,(uint64_t)vt+4,2,(vn-4)/2))return false;
 for(unsigned i=0;i<counts[kind];i++){
  const sx_layout *l=sets[kind][i];unsigned z=l?(unsigned)l->fields[0].size:4;
  if(!sxq_a_field(w,t,i,z,&fields[i]))return false;
  if(fields[i]&&l&&!sxq_wadd(w,l,fields[i]))return false;
 }
 uint64_t target=0;
 if(kind==0){
  if(!sxq_a_ref(w,fields[1],&target)||!target||!sxq_a_parse(w,target,1,depth+1))return false;
  return sxq_a_vector(w,fields[2],24,&sxq_arrow_block,-1,depth)&&sxq_a_vector(w,fields[3],24,&sxq_arrow_block,-1,depth)&&sxq_a_vector(w,fields[4],4,NULL,-1,depth);
 }
 if(kind==1)return sxq_a_vector(w,fields[1],4,NULL,2,depth)&&sxq_a_vector(w,fields[2],4,NULL,-1,depth)&&sxq_a_vector(w,fields[3],8,NULL,-1,depth);
 if(kind==2){
  if(!sxq_a_ref(w,fields[0],&target)||!target)return false;uint32_t n=sxq32(w->b+target);
  if(!sxq_span(w,target+4,(uint64_t)n+1)||!sxq_wadd(w,&sxq_arrow_string_header,target)||!sxq_a_ref(w,fields[3],&target)||!target||!sxq_a_parse(w,target,3,depth+1))return false;
  return !fields[4]&&sxq_a_vector(w,fields[5],4,NULL,-1,depth)&&sxq_a_vector(w,fields[6],4,NULL,-1,depth);
 }
 if(kind==4){
  if(!fields[1]||!sxq_a_ref(w,fields[2],&target)||!target)return false;unsigned tag=w->b[fields[1]];if(tag!=1&&tag!=3)return false;
  return sxq_a_parse(w,target,tag==1?1:5,depth+1)&&sxq_a_vector(w,fields[4],4,NULL,-1,depth);
 }
 if(kind==5)return !fields[3]&&sxq_a_vector(w,fields[1],16,&sxq_arrow_field_node,-1,depth)&&sxq_a_vector(w,fields[2],16,&sxq_arrow_buffer,-1,depth)&&sxq_a_vector(w,fields[4],8,NULL,-1,depth);
 return true;
}
static bool sxq_a_message(sx_context *c,uint64_t p,uint64_t expected,uint64_t *after){
 uint8_t b[8];if(!sxq_file_span(c,p,8)||!sx_read(c,(int64_t)p,b,8))return false;
 unsigned prefix=sxq32(b)==UINT32_MAX?8:4;uint32_t n=sxq32(b+prefix-4);
 if(n<4||n>SXQ_META_LIMIT||(expected&&n+prefix!=expected)||!sxq_add(c,prefix==8?&sxq_arrow_continuation_prefix:&sxq_arrow_message_prefix,p))return false;
 sxq_window w;if(!sxq_window_open(&w,c,p+prefix,n))return false;uint64_t root=sxq32(w.b),field=0;bool ok=sxq_wadd(&w,&sxq_arrow_flatbuffer_root,0)&&sxq_a_parse(&w,root,4,0)&&sxq_a_field(&w,root,3,8,&field);
 uint64_t body=field?sxq64(w.b+field):0;if(ok)ok=body<=INT64_MAX&&sxq_file_span(c,p,n+prefix+body);
 if(ok)*after=p+n+prefix+body;xx_mem_free(w.b);return ok;
}
static bool sxq_arrow(sx_context *c){
 uint8_t tail[10];if(c->size<18||!sx_read(c,c->size-10,tail,10))return false;uint32_t n=sxq32(tail);
 if(n<4||n>SXQ_META_LIMIT||n>(uint64_t)c->size-18||!sxq_add(c,&sxq_arrow_file_header,0)||!sxq_add(c,&sxq_arrow_file_trailer,(uint64_t)c->size-10))return false;
 uint64_t footer=(uint64_t)c->size-10-n;sxq_window w;if(!sxq_window_open(&w,c,footer,n))return false;
 uint64_t root=sxq32(w.b),field=0,v=0,after=0;bool ok=sxq_wadd(&w,&sxq_arrow_flatbuffer_root,0)&&sxq_a_parse(&w,root,0,0)&&sxq_a_field(&w,root,3,4,&field)&&sxq_a_ref(&w,field,&v)&&v;
 uint32_t count=ok?sxq32(w.b+v):0;if(ok)ok=sxq_span(&w,v+4,(uint64_t)count*24)&&sxq_a_message(c,8,0,&after);
 for(uint32_t i=0;ok&&i<count;i++){
  const uint8_t *b=w.b+v+4+(size_t)i*24;uint64_t at=sxq64(b),body=sxq64(b+16);uint32_t meta=sxq32(b+8);
  ok=at==after&&meta<=SXQ_META_LIMIT&&sxq_a_message(c,at,meta,&after)&&after<=footer&&body==after-at-meta;
 }
 if(ok&&after!=footer){uint8_t eos[8];ok=footer-after==8&&sx_read(c,(int64_t)after,eos,8)&&sxq32(eos)==UINT32_MAX&&!sxq32(eos+4)&&sxq_add(c,&sxq_arrow_continuation_prefix,after);}
 xx_mem_free(w.b);return ok;
}
bool sx_apache_arrow_file_build(sx_context*c)
{
 return sxq_arrow(c)&&sxq_finish(c);
}
