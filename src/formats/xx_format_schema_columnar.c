/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical Arrow IPC/FlatBuffers and Parquet Compact Thrift metadata. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_columnar.h"
static const xx_data_struct_field_desc sxq_arrow_footer_version_fields[] = {
    SX_FIELD("version", "int16", 0, 2, SX_ID),
};
const sx_layout sxq_arrow_footer_version = {UINT32_C(0x601F000F),"arrow_footer_version",sxq_arrow_footer_version_fields,SX_COUNT(sxq_arrow_footer_version_fields),SX_LE};
static const xx_data_struct_field_desc sxq_arrow_message_version_fields[] = {
    SX_FIELD("version", "int16", 0, 2, SX_ID),
};
const sx_layout sxq_arrow_message_version = {UINT32_C(0x601F0020),"arrow_message_version",sxq_arrow_message_version_fields,SX_COUNT(sxq_arrow_message_version_fields),SX_LE};
static const sx_layout *const sx_columnar_layouts[] = {
    &sxq_arrow_file_header,
    &sxq_arrow_file_trailer,
    &sxq_arrow_message_prefix,
    &sxq_arrow_continuation_prefix,
    &sxq_arrow_flatbuffer_root,
    &sxq_arrow_table_header,
    &sxq_arrow_vtable_header,
    &sxq_arrow_vtable_entry,
    &sxq_arrow_vector_header,
    &sxq_arrow_vector_reference,
    &sxq_arrow_string_header,
    &sxq_arrow_block,
    &sxq_arrow_field_node,
    &sxq_arrow_buffer,
    &sxq_arrow_footer_version,
    &sxq_arrow_footer_schema,
    &sxq_arrow_footer_dictionaries,
    &sxq_arrow_footer_record_batches,
    &sxq_arrow_footer_custom_metadata,
    &sxq_arrow_schema_endianness,
    &sxq_arrow_schema_fields,
    &sxq_arrow_schema_custom_metadata,
    &sxq_arrow_schema_features,
    &sxq_arrow_field_name,
    &sxq_arrow_field_nullable,
    &sxq_arrow_field_type_tag,
    &sxq_arrow_field_type,
    &sxq_arrow_field_children,
    &sxq_arrow_field_custom_metadata,
    &sxq_arrow_int_type_bit_width,
    &sxq_arrow_int_type_is_signed,
    &sxq_arrow_message_version,
    &sxq_arrow_message_header_tag,
    &sxq_arrow_message_header,
    &sxq_arrow_message_body_length,
    &sxq_arrow_message_custom_metadata,
    &sxq_arrow_record_batch_length,
    &sxq_arrow_record_batch_nodes,
    &sxq_arrow_record_batch_buffers,
    &sxq_arrow_record_batch_variadic_buffer_counts,
    &sxq_parquet_file_header,
    &sxq_parquet_file_trailer,
    &sxq_thrift_field_header,
    &sxq_thrift_list_header,
    &sxq_thrift_map_types,
    &sxq_thrift_boolean_value,
    &sxq_thrift_byte_value,
    &sxq_thrift_double_bits,
    &sxq_columnar_varuint_size_1,
    &sxq_columnar_varuint_size_2,
    &sxq_columnar_varuint_size_3,
    &sxq_columnar_varuint_size_4,
    &sxq_columnar_varuint_size_5,
    &sxq_columnar_varuint_size_6,
    &sxq_columnar_varuint_size_7,
    &sxq_columnar_varuint_size_8,
    &sxq_columnar_varuint_size_9,
    &sxq_columnar_varuint_size_10,
    &sxq_columnar_varuint_count_1,
    &sxq_columnar_varuint_count_2,
    &sxq_columnar_varuint_count_3,
    &sxq_columnar_varuint_count_4,
    &sxq_columnar_varuint_count_5,
    &sxq_columnar_varuint_count_6,
    &sxq_columnar_varuint_count_7,
    &sxq_columnar_varuint_count_8,
    &sxq_columnar_varuint_count_9,
    &sxq_columnar_varuint_count_10,
    &sxq_thrift_i16_id_1,
    &sxq_thrift_i16_id_2,
    &sxq_thrift_i16_id_3,
    &sxq_thrift_i16_id_4,
    &sxq_thrift_i16_id_5,
    &sxq_thrift_i16_id_6,
    &sxq_thrift_i16_id_7,
    &sxq_thrift_i16_id_8,
    &sxq_thrift_i16_id_9,
    &sxq_thrift_i16_id_10,
    &sxq_thrift_i16_value_1,
    &sxq_thrift_i16_value_2,
    &sxq_thrift_i16_value_3,
    &sxq_thrift_i16_value_4,
    &sxq_thrift_i16_value_5,
    &sxq_thrift_i16_value_6,
    &sxq_thrift_i16_value_7,
    &sxq_thrift_i16_value_8,
    &sxq_thrift_i16_value_9,
    &sxq_thrift_i16_value_10,
    &sxq_thrift_i32_id_1,
    &sxq_thrift_i32_id_2,
    &sxq_thrift_i32_id_3,
    &sxq_thrift_i32_id_4,
    &sxq_thrift_i32_id_5,
    &sxq_thrift_i32_id_6,
    &sxq_thrift_i32_id_7,
    &sxq_thrift_i32_id_8,
    &sxq_thrift_i32_id_9,
    &sxq_thrift_i32_id_10,
    &sxq_thrift_i32_value_1,
    &sxq_thrift_i32_value_2,
    &sxq_thrift_i32_value_3,
    &sxq_thrift_i32_value_4,
    &sxq_thrift_i32_value_5,
    &sxq_thrift_i32_value_6,
    &sxq_thrift_i32_value_7,
    &sxq_thrift_i32_value_8,
    &sxq_thrift_i32_value_9,
    &sxq_thrift_i32_value_10,
    &sxq_thrift_i32_size_1,
    &sxq_thrift_i32_size_2,
    &sxq_thrift_i32_size_3,
    &sxq_thrift_i32_size_4,
    &sxq_thrift_i32_size_5,
    &sxq_thrift_i32_size_6,
    &sxq_thrift_i32_size_7,
    &sxq_thrift_i32_size_8,
    &sxq_thrift_i32_size_9,
    &sxq_thrift_i32_size_10,
    &sxq_thrift_i32_count_1,
    &sxq_thrift_i32_count_2,
    &sxq_thrift_i32_count_3,
    &sxq_thrift_i32_count_4,
    &sxq_thrift_i32_count_5,
    &sxq_thrift_i32_count_6,
    &sxq_thrift_i32_count_7,
    &sxq_thrift_i32_count_8,
    &sxq_thrift_i32_count_9,
    &sxq_thrift_i32_count_10,
    &sxq_thrift_i64_value_1,
    &sxq_thrift_i64_value_2,
    &sxq_thrift_i64_value_3,
    &sxq_thrift_i64_value_4,
    &sxq_thrift_i64_value_5,
    &sxq_thrift_i64_value_6,
    &sxq_thrift_i64_value_7,
    &sxq_thrift_i64_value_8,
    &sxq_thrift_i64_value_9,
    &sxq_thrift_i64_value_10,
    &sxq_thrift_i64_offset_1,
    &sxq_thrift_i64_offset_2,
    &sxq_thrift_i64_offset_3,
    &sxq_thrift_i64_offset_4,
    &sxq_thrift_i64_offset_5,
    &sxq_thrift_i64_offset_6,
    &sxq_thrift_i64_offset_7,
    &sxq_thrift_i64_offset_8,
    &sxq_thrift_i64_offset_9,
    &sxq_thrift_i64_offset_10,
    &sxq_thrift_i64_size_1,
    &sxq_thrift_i64_size_2,
    &sxq_thrift_i64_size_3,
    &sxq_thrift_i64_size_4,
    &sxq_thrift_i64_size_5,
    &sxq_thrift_i64_size_6,
    &sxq_thrift_i64_size_7,
    &sxq_thrift_i64_size_8,
    &sxq_thrift_i64_size_9,
    &sxq_thrift_i64_size_10,
    &sxq_thrift_i64_count_1,
    &sxq_thrift_i64_count_2,
    &sxq_thrift_i64_count_3,
    &sxq_thrift_i64_count_4,
    &sxq_thrift_i64_count_5,
    &sxq_thrift_i64_count_6,
    &sxq_thrift_i64_count_7,
    &sxq_thrift_i64_count_8,
    &sxq_thrift_i64_count_9,
    &sxq_thrift_i64_count_10,
};
/* Read only metadata windows. Column payload bytes remain on the original device. */
#define SXQ_RECORD_LIMIT 100000U
#define SXQ_META_LIMIT (16U*1024U*1024U)
bool sxq_span(const sxq_window *w,uint64_t p,uint64_t n){return p<=w->n&&n<=w->n-p;}
bool sxq_file_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
uint32_t sxq32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
bool sxq_window_open(sxq_window *w,sx_context *c,uint64_t base,uint64_t n){
 xx_mem_zero(w,sizeof(*w));if(n<4||n>SXQ_META_LIMIT||!sxq_file_span(c,base,n))return false;
 w->c=c;w->n=(size_t)n;w->base=base;w->b=xx_mem_alloc(w->n);if(!w->b)return false;
 if(!sx_read(c,(int64_t)base,w->b,w->n)){xx_mem_free(w->b);w->b=NULL;return false;}return true;
}
bool sxq_add(sx_context *c,const sx_layout *l,uint64_t p){
 const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)f->rel_offset+(uint64_t)f->size;
 return c->count<SXQ_RECORD_LIMIT&&sxq_file_span(c,p,n)&&sx_add(c,l,(int64_t)p,(int64_t)n);
}
bool sxq_wadd(sxq_window *w,const sx_layout *l,uint64_t p){
 const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];return sxq_span(w,p,(uint64_t)f->rel_offset+(uint64_t)f->size)&&sxq_add(w->c,l,w->base+p);
}
static int sxq_order(const void *a,const void *b){
 const xx_data_struct *x=a,*y=b;if(x->offset!=y->offset)return x->offset<y->offset?-1:1;
 if(x->id!=y->id)return x->id<y->id?-1:1;if(x->total_size!=y->total_size)return x->total_size<y->total_size?-1:1;return 0;
}
bool sxq_finish(sx_context *c){
 xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxq_order);size_t kept=0;
 for(size_t i=0;i<c->count;i++){
  if(kept&&c->items[kept-1].offset==c->items[i].offset&&c->items[kept-1].id==c->items[i].id&&c->items[kept-1].total_size==c->items[i].total_size&&c->items[kept-1].entry_size==c->items[i].entry_size&&c->items[kept-1].count==c->items[i].count){continue;}
  if(kept!=i){c->items[kept]=c->items[i];xx_mem_zero(&c->items[i],sizeof(c->items[i]));}kept++;
 }
 c->count=kept;int64_t end=0;for(size_t i=0;i<kept;i++){
  int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;
 }
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxq_order);return !c->failed;
}
static bool sx_columnar_supports(xx_file_type_t t){return t==XX_FILE_TYPE_APACHE_ARROW_FILE||t==XX_FILE_TYPE_APACHE_PARQUET;}
static bool sx_columnar_build(sx_context *c){
 if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 if(c->f->file_type==XX_FILE_TYPE_APACHE_ARROW_FILE)return sx_apache_arrow_file_build(c);
 if(c->f->file_type==XX_FILE_TYPE_APACHE_PARQUET)return sx_apache_parquet_build(c);
 return false;
}
static bool sx_columnar_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x601f0000U||id>=0x60200000U)return true;const wchar_t *t=NULL;
 if(xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;
 if(!xx_rt_wcscmp(r->name,L"version")&&(id==sxq_arrow_footer_version.id||id==sxq_arrow_message_version.id)){
  uint64_t v=xx_var_get_u64(&r->value);static const wchar_t *const names[]={L"MetadataVersion_V1",L"MetadataVersion_V2",L"MetadataVersion_V3",L"MetadataVersion_V4",L"MetadataVersion_V5"};if(v<SX_COUNT(names))t=names[v];
 }else if(!xx_rt_wcscmp(r->name,L"endianness")){uint64_t v=xx_var_get_u64(&r->value);t=v==0?L"Endianness_Little":v==1?L"Endianness_Big":L"Unknown Arrow endianness";}
 else if(!xx_rt_wcscmp(r->name,L"type_tag")){if(xx_var_get_u64(&r->value)==2)t=L"Type_Int";}
 else if(!xx_rt_wcscmp(r->name,L"header_tag")){uint64_t v=xx_var_get_u64(&r->value);t=v==1?L"MessageHeader_Schema":v==2?L"MessageHeader_DictionaryBatch":v==3?L"MessageHeader_RecordBatch":L"Unknown IPC message header tag";}
 else if(!xx_rt_wcscmp(r->name,L"nullable")||!xx_rt_wcscmp(r->name,L"is_signed")){uint64_t v=xx_var_get_u64(&r->value);t=v==0?L"false":v==1?L"true":L"Invalid Boolean";}
 if(t)return xx_data_struct_record_set_comment(r,t);

 if(!xx_rt_wcscmp(r->name,L"field_delta_and_type")||!xx_rt_wcscmp(r->name,L"count_and_element_type")||!xx_rt_wcscmp(r->name,L"key_and_value_type")){
  static const char *const names[]={"STOP","BOOLEAN_TRUE","BOOLEAN_FALSE","BYTE","I16","I32","I64","DOUBLE","BINARY","LIST","SET","MAP","STRUCT","UNKNOWN","UNKNOWN","UNKNOWN"};
  unsigned v=(unsigned)xx_var_get_u64(&r->value);char b[192];wchar_t out[192];int n;
  if(!xx_rt_wcscmp(r->name,L"field_delta_and_type"))n=xx_rt_snprintf(b,sizeof(b),"Compact Thrift %s; field-ID delta %u%s",names[v&15],v>>4,!v?"; end of structure":!(v>>4)?"; explicit ZigZag field ID follows":"");
  else if(!xx_rt_wcscmp(r->name,L"count_and_element_type"))n=xx_rt_snprintf(b,sizeof(b),"Compact Thrift %s elements; %s %u",names[v&15],(v>>4)==15?"ULEB count follows; marker":"inline count",v>>4);
  else n=xx_rt_snprintf(b,sizeof(b),"Compact Thrift map: %s keys, %s values",names[(v>>4)&15],names[v&15]);
  if(n<0||n>=(int)sizeof(b))return false;for(int i=0;i<=n;i++)out[i]=(unsigned char)b[i];return xx_data_struct_record_set_comment(r,out);
 }
 if(!xx_rt_wcscmp(r->name,L"vtable_displacement"))t=L"Signed displacement subtracted from the table offset to locate its vtable.";
 else if(!xx_rt_wcscmp(r->name,L"field_offset"))t=L"Byte offset from the FlatBuffers table start; zero means the field is absent.";
 else if(!xx_rt_wcscmp(r->name,L"root_offset")||!xx_rt_wcscmp(r->name,L"object_offset"))t=L"Unsigned forward byte offset from this physical word.";
 else if(!xx_rt_wcscmp(r->name,L"body_offset"))t=L"Byte offset relative to the IPC record-batch body.";
 else if(!xx_rt_wcscmp(r->name,L"bit_width"))t=L"Number of bits in each integer value; not bytes.";
 else if(!xx_rt_wcscmp(r->name,L"field_delta_and_type"))t=L"High nibble is the field-ID delta; low nibble is Compact Thrift type. Zero ends the structure.";
 else if(!xx_rt_wcscmp(r->name,L"count_and_element_type"))t=L"High nibble is the element count (15 means a following ULEB count); low nibble is the element type.";
 else if(!xx_rt_wcscmp(r->name,L"key_and_value_type"))t=L"High nibble is the map key type; low nibble is its value type.";
 else if(!xx_rt_wcscmp(r->name,L"boolean_type"))t=L"Compact Thrift collection Boolean: 1 true; 2 false.";
 else if(!xx_rt_wcscmp(r->name,L"ieee754_binary64_bits"))t=L"Little-endian IEEE 754 binary64 wire representation.";
 return !t||xx_data_struct_record_set_comment(r,t);
}
const sx_family sx_columnar_family={sx_columnar_supports,sx_columnar_build,sx_columnar_layouts,SX_COUNT(sx_columnar_layouts),sx_columnar_comment};
