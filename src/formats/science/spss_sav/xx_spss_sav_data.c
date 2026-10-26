/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SPSS SAV data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_sav_header_le_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("product","char[60]",4,60,SX_STRING),
    SX_FIELD("layout_code","int32",64,4,SX_ID),
    SX_FIELD("case_size","int32",68,4,SX_COUNT_PROP),
    SX_FIELD("compression","int32",72,4,SX_ID),
    SX_FIELD("weight_index","int32",76,4,SX_ID),
    SX_FIELD("case_count","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("bias","float64",84,8,SX_NONE),
    SX_FIELD("creation_date","char[9]",92,9,SX_STRING),
    SX_FIELD("creation_time","char[8]",101,8,SX_STRING),
    SX_FIELD("file_label","char[64]",109,64,SX_STRING),
    SX_FIELD("padding","uint8[3]",173,3,SX_RESERVED),
};
const sx_layout sxsw_sav_header_le = {UINT32_C(0x602d0005),"sav_header_le",sxsw_sav_header_le_fields,SX_COUNT(sxsw_sav_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_variable_le_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("variable_type","int32",4,4,SX_ID),
    SX_FIELD("has_label","int32",8,4,SX_FLAGS),
    SX_FIELD("missing_value_count","int32",12,4,SX_NONE),
    SX_FIELD("print_format","int32",16,4,SX_FLAGS),
    SX_FIELD("write_format","int32",20,4,SX_FLAGS),
    SX_FIELD("name","char[8]",24,8,SX_STRING),
};
const sx_layout sxsw_sav_variable_le = {UINT32_C(0x602d0006),"sav_variable_le",sxsw_sav_variable_le_fields,SX_COUNT(sxsw_sav_variable_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_extension_le_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("subtype","int32",4,4,SX_ID),
    SX_FIELD("entry_size","int32",8,4,SX_SIZE),
    SX_FIELD("entry_count","int32",12,4,SX_COUNT_PROP),
};
const sx_layout sxsw_sav_extension_le = {UINT32_C(0x602d0007),"sav_extension_le",sxsw_sav_extension_le_fields,SX_COUNT(sxsw_sav_extension_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_count_record_le_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("count","int32",4,4,SX_COUNT_PROP),
};
const sx_layout sxsw_sav_count_record_le = {UINT32_C(0x602d0008),"sav_count_record_le",sxsw_sav_count_record_le_fields,SX_COUNT(sxsw_sav_count_record_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_dictionary_end_le_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("filler","int32",4,4,SX_RESERVED),
};
const sx_layout sxsw_sav_dictionary_end_le = {UINT32_C(0x602d0009),"sav_dictionary_end_le",sxsw_sav_dictionary_end_le_fields,SX_COUNT(sxsw_sav_dictionary_end_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_label_size_le_fields[] = {
    SX_FIELD("label_size","int32",0,4,SX_SIZE),
};
const sx_layout sxsw_sav_label_size_le = {UINT32_C(0x602d000a),"sav_label_size_le",sxsw_sav_label_size_le_fields,SX_COUNT(sxsw_sav_label_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_variable_index_le_fields[] = {
    SX_FIELD("variable_index","int32",0,4,SX_ID),
};
const sx_layout sxsw_sav_variable_index_le = {UINT32_C(0x602d000b),"sav_variable_index_le",sxsw_sav_variable_index_le_fields,SX_COUNT(sxsw_sav_variable_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_value_label_le_fields[] = {
    SX_FIELD("value_bytes","uint8[8]",0,8,SX_NONE),
    SX_FIELD("label_size","uint8",8,1,SX_SIZE),
};
const sx_layout sxsw_sav_value_label_le = {UINT32_C(0x602d000c),"sav_value_label_le",sxsw_sav_value_label_le_fields,SX_COUNT(sxsw_sav_value_label_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_machine_integer_le_fields[] = {
    SX_FIELD("version_major","int32",0,4,SX_ID),
    SX_FIELD("version_minor","int32",4,4,SX_ID),
    SX_FIELD("version_revision","int32",8,4,SX_ID),
    SX_FIELD("machine_code","int32",12,4,SX_ID),
    SX_FIELD("floating_point_representation","int32",16,4,SX_ID),
    SX_FIELD("compression_code","int32",20,4,SX_ID),
    SX_FIELD("endianness","int32",24,4,SX_ID),
    SX_FIELD("character_code","int32",28,4,SX_ID),
};
const sx_layout sxsw_sav_machine_integer_le = {UINT32_C(0x602d000d),"sav_machine_integer_le",sxsw_sav_machine_integer_le_fields,SX_COUNT(sxsw_sav_machine_integer_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_sav_header_be_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("product","char[60]",4,60,SX_STRING),
    SX_FIELD("layout_code","int32",64,4,SX_ID),
    SX_FIELD("case_size","int32",68,4,SX_COUNT_PROP),
    SX_FIELD("compression","int32",72,4,SX_ID),
    SX_FIELD("weight_index","int32",76,4,SX_ID),
    SX_FIELD("case_count","int32",80,4,SX_COUNT_PROP),
    SX_FIELD("bias","float64",84,8,SX_NONE),
    SX_FIELD("creation_date","char[9]",92,9,SX_STRING),
    SX_FIELD("creation_time","char[8]",101,8,SX_STRING),
    SX_FIELD("file_label","char[64]",109,64,SX_STRING),
    SX_FIELD("padding","uint8[3]",173,3,SX_RESERVED),
};
const sx_layout sxsw_sav_header_be = {UINT32_C(0x602d000e),"sav_header_be",sxsw_sav_header_be_fields,SX_COUNT(sxsw_sav_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_variable_be_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("variable_type","int32",4,4,SX_ID),
    SX_FIELD("has_label","int32",8,4,SX_FLAGS),
    SX_FIELD("missing_value_count","int32",12,4,SX_NONE),
    SX_FIELD("print_format","int32",16,4,SX_FLAGS),
    SX_FIELD("write_format","int32",20,4,SX_FLAGS),
    SX_FIELD("name","char[8]",24,8,SX_STRING),
};
const sx_layout sxsw_sav_variable_be = {UINT32_C(0x602d000f),"sav_variable_be",sxsw_sav_variable_be_fields,SX_COUNT(sxsw_sav_variable_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_extension_be_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("subtype","int32",4,4,SX_ID),
    SX_FIELD("entry_size","int32",8,4,SX_SIZE),
    SX_FIELD("entry_count","int32",12,4,SX_COUNT_PROP),
};
const sx_layout sxsw_sav_extension_be = {UINT32_C(0x602d0010),"sav_extension_be",sxsw_sav_extension_be_fields,SX_COUNT(sxsw_sav_extension_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_count_record_be_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("count","int32",4,4,SX_COUNT_PROP),
};
const sx_layout sxsw_sav_count_record_be = {UINT32_C(0x602d0011),"sav_count_record_be",sxsw_sav_count_record_be_fields,SX_COUNT(sxsw_sav_count_record_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_dictionary_end_be_fields[] = {
    SX_FIELD("record_type","int32",0,4,SX_ID),
    SX_FIELD("filler","int32",4,4,SX_RESERVED),
};
const sx_layout sxsw_sav_dictionary_end_be = {UINT32_C(0x602d0012),"sav_dictionary_end_be",sxsw_sav_dictionary_end_be_fields,SX_COUNT(sxsw_sav_dictionary_end_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_label_size_be_fields[] = {
    SX_FIELD("label_size","int32",0,4,SX_SIZE),
};
const sx_layout sxsw_sav_label_size_be = {UINT32_C(0x602d0013),"sav_label_size_be",sxsw_sav_label_size_be_fields,SX_COUNT(sxsw_sav_label_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_variable_index_be_fields[] = {
    SX_FIELD("variable_index","int32",0,4,SX_ID),
};
const sx_layout sxsw_sav_variable_index_be = {UINT32_C(0x602d0014),"sav_variable_index_be",sxsw_sav_variable_index_be_fields,SX_COUNT(sxsw_sav_variable_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_value_label_be_fields[] = {
    SX_FIELD("value_bytes","uint8[8]",0,8,SX_NONE),
    SX_FIELD("label_size","uint8",8,1,SX_SIZE),
};
const sx_layout sxsw_sav_value_label_be = {UINT32_C(0x602d0015),"sav_value_label_be",sxsw_sav_value_label_be_fields,SX_COUNT(sxsw_sav_value_label_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_machine_integer_be_fields[] = {
    SX_FIELD("version_major","int32",0,4,SX_ID),
    SX_FIELD("version_minor","int32",4,4,SX_ID),
    SX_FIELD("version_revision","int32",8,4,SX_ID),
    SX_FIELD("machine_code","int32",12,4,SX_ID),
    SX_FIELD("floating_point_representation","int32",16,4,SX_ID),
    SX_FIELD("compression_code","int32",20,4,SX_ID),
    SX_FIELD("endianness","int32",24,4,SX_ID),
    SX_FIELD("character_code","int32",28,4,SX_ID),
};
const sx_layout sxsw_sav_machine_integer_be = {UINT32_C(0x602d0016),"sav_machine_integer_be",sxsw_sav_machine_integer_be_fields,SX_COUNT(sxsw_sav_machine_integer_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_sav_document_line_fields[] = {
    SX_FIELD("text","char[80]",0,80,SX_STRING),
};
const sx_layout sxsw_sav_document_line = {UINT32_C(0x602d0017),"sav_document_line",sxsw_sav_document_line_fields,SX_COUNT(sxsw_sav_document_line_fields),SX_LE};
static bool sxsw_sav(sx_context *c)
{
 uint8_t b[176];if(!sx_read(c,0,b,176))return false;bool be=sxsw32(b+64,true)==2;int64_t at=176;
 if(!sxsw_add(c,be?&sxsw_sav_header_be:&sxsw_sav_header_le,0,176))return false;
 while(at<c->size){
  uint32_t tag,n;if(!sx_u32(c,at,be,&tag))return false;
  if(tag==2){if(!sx_read(c,at,b,32)||!sxsw_add(c,be?&sxsw_sav_variable_be:&sxsw_sav_variable_le,at,32))return false;uint32_t label=sxsw32(b+8,be);int32_t missing=(int32_t)sxsw32(b+12,be);at+=32;
   if(label){if(!sx_u32(c,at,be,&n)||n>16777216||!sxsw_add(c,be?&sxsw_sav_label_size_be:&sxsw_sav_label_size_le,at,4)||!sxsw_span(c,at+4,((uint64_t)n+3)&~UINT64_C(3)))return false;at+=4+((n+3U)&~3U);}
   if(missing<-3||missing>3||!sxsw_span(c,at,(unsigned)(missing<0?-missing:missing)*8))return false;at+=(missing<0?-missing:missing)*8;
  }else if(tag==3||tag==4||tag==6){
   if(!sx_u32(c,at+4,be,&n)||n>4096||!sxsw_add(c,be?&sxsw_sav_count_record_be:&sxsw_sav_count_record_le,at,8))return false;at+=8;
   if(tag==3){for(uint32_t j=0;j<n;j++){if(!sx_read(c,at,b,9)||!sxsw_add(c,be?&sxsw_sav_value_label_be:&sxsw_sav_value_label_le,at,9))return false;uint32_t bytes=8+((1U+b[8]+7)&~7U);if(!sxsw_span(c,at,bytes))return false;at+=bytes;}}
   else {uint32_t width=tag==4?4:80;const sx_layout *l=tag==4?(be?&sxsw_sav_variable_index_be:&sxsw_sav_variable_index_le):&sxsw_sav_document_line;if(!sxsw_table(c,l,at,width,n))return false;at+=(int64_t)n*width;}
  }else if(tag==7){
   if(!sx_read(c,at,b,16)||!sxsw_add(c,be?&sxsw_sav_extension_be:&sxsw_sav_extension_le,at,16))return false;uint32_t subtype=sxsw32(b+4,be),width=sxsw32(b+8,be);n=sxsw32(b+12,be);uint64_t bytes=(uint64_t)width*n;at+=16;if(!sxsw_span(c,at,bytes))return false;
   if(subtype==3&&width==4&&n==8&&!sxsw_add(c,be?&sxsw_sav_machine_integer_be:&sxsw_sav_machine_integer_le,at,32))return false;at+=(int64_t)bytes;
  }else if(tag==999)return sxsw_add(c,be?&sxsw_sav_dictionary_end_be:&sxsw_sav_dictionary_end_le,at,8);
  else return false;
 }return false;
}
bool sx_spss_sav_build(sx_context*c)
{
 return sxsw_sav(c);
}
