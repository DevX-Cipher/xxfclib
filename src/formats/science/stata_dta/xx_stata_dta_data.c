/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Stata DTA data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_stata117_prefix_le_fields[] = {
    SX_FIELD("prefix","char[28]",0,28,SX_SIGNATURE),
    SX_FIELD("release","char[3]",28,3,SX_ID),
    SX_FIELD("release_end","char[21]",31,21,SX_NONE),
    SX_FIELD("byte_order","char[3]",52,3,SX_ID),
    SX_FIELD("byte_order_end","char[15]",55,15,SX_NONE),
    SX_FIELD("variable_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("variable_count_end","char[7]",72,7,SX_NONE),
    SX_FIELD("observation_count","uint32",79,4,SX_COUNT_PROP),
};
const sx_layout sxsw_stata117_prefix_le = {UINT32_C(0x602d0040),"stata117_prefix_le",sxsw_stata117_prefix_le_fields,SX_COUNT(sxsw_stata117_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_label_size_le_fields[] = {
    SX_FIELD("label_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxsw_stata117_label_size_le = {UINT32_C(0x602d0041),"stata117_label_size_le",sxsw_stata117_label_size_le_fields,SX_COUNT(sxsw_stata117_label_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_variable_name_fields[] = {
    SX_FIELD("variable_name","char[33]",0,33,SX_STRING),
};
const sx_layout sxsw_stata117_variable_name = {UINT32_C(0x602d0042),"stata117_variable_name",sxsw_stata117_variable_name_fields,SX_COUNT(sxsw_stata117_variable_name_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_display_format_fields[] = {
    SX_FIELD("display_format","char[49]",0,49,SX_STRING),
};
const sx_layout sxsw_stata117_display_format = {UINT32_C(0x602d0043),"stata117_display_format",sxsw_stata117_display_format_fields,SX_COUNT(sxsw_stata117_display_format_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_value_label_name_fields[] = {
    SX_FIELD("value_label_name","char[33]",0,33,SX_STRING),
};
const sx_layout sxsw_stata117_value_label_name = {UINT32_C(0x602d0044),"stata117_value_label_name",sxsw_stata117_value_label_name_fields,SX_COUNT(sxsw_stata117_value_label_name_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_variable_label_fields[] = {
    SX_FIELD("variable_label","char[81]",0,81,SX_STRING),
};
const sx_layout sxsw_stata117_variable_label = {UINT32_C(0x602d0045),"stata117_variable_label",sxsw_stata117_variable_label_fields,SX_COUNT(sxsw_stata117_variable_label_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_prefix_le_fields[] = {
    SX_FIELD("prefix","char[28]",0,28,SX_SIGNATURE),
    SX_FIELD("release","char[3]",28,3,SX_ID),
    SX_FIELD("release_end","char[21]",31,21,SX_NONE),
    SX_FIELD("byte_order","char[3]",52,3,SX_ID),
    SX_FIELD("byte_order_end","char[15]",55,15,SX_NONE),
    SX_FIELD("variable_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("variable_count_end","char[7]",72,7,SX_NONE),
    SX_FIELD("observation_count","uint64",79,8,SX_COUNT_PROP),
};
const sx_layout sxsw_stata118_prefix_le = {UINT32_C(0x602d0046),"stata118_prefix_le",sxsw_stata118_prefix_le_fields,SX_COUNT(sxsw_stata118_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_label_size_le_fields[] = {
    SX_FIELD("label_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxsw_stata118_label_size_le = {UINT32_C(0x602d0047),"stata118_label_size_le",sxsw_stata118_label_size_le_fields,SX_COUNT(sxsw_stata118_label_size_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_variable_name_fields[] = {
    SX_FIELD("variable_name","char[129]",0,129,SX_STRING),
};
const sx_layout sxsw_stata118_variable_name = {UINT32_C(0x602d0048),"stata118_variable_name",sxsw_stata118_variable_name_fields,SX_COUNT(sxsw_stata118_variable_name_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_display_format_fields[] = {
    SX_FIELD("display_format","char[57]",0,57,SX_STRING),
};
const sx_layout sxsw_stata118_display_format = {UINT32_C(0x602d0049),"stata118_display_format",sxsw_stata118_display_format_fields,SX_COUNT(sxsw_stata118_display_format_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_value_label_name_fields[] = {
    SX_FIELD("value_label_name","char[129]",0,129,SX_STRING),
};
const sx_layout sxsw_stata118_value_label_name = {UINT32_C(0x602d004a),"stata118_value_label_name",sxsw_stata118_value_label_name_fields,SX_COUNT(sxsw_stata118_value_label_name_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata118_variable_label_fields[] = {
    SX_FIELD("variable_label","char[321]",0,321,SX_STRING),
};
const sx_layout sxsw_stata118_variable_label = {UINT32_C(0x602d004b),"stata118_variable_label",sxsw_stata118_variable_label_fields,SX_COUNT(sxsw_stata118_variable_label_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata_map_le_fields[] = {
    SX_FIELD("start","char[5]",0,5,SX_NONE),
    SX_FIELD("file_start","uint64",5,8,SX_OFFSET),
    SX_FIELD("map_offset","uint64",13,8,SX_OFFSET),
    SX_FIELD("variable_types_offset","uint64",21,8,SX_OFFSET),
    SX_FIELD("variable_names_offset","uint64",29,8,SX_OFFSET),
    SX_FIELD("sortlist_offset","uint64",37,8,SX_OFFSET),
    SX_FIELD("formats_offset","uint64",45,8,SX_OFFSET),
    SX_FIELD("value_label_names_offset","uint64",53,8,SX_OFFSET),
    SX_FIELD("variable_labels_offset","uint64",61,8,SX_OFFSET),
    SX_FIELD("characteristics_offset","uint64",69,8,SX_OFFSET),
    SX_FIELD("data_offset","uint64",77,8,SX_OFFSET),
    SX_FIELD("strls_offset","uint64",85,8,SX_OFFSET),
    SX_FIELD("value_labels_offset","uint64",93,8,SX_OFFSET),
    SX_FIELD("file_end_tag_offset","uint64",101,8,SX_OFFSET),
    SX_FIELD("file_end","uint64",109,8,SX_OFFSET),
    SX_FIELD("end","char[6]",117,6,SX_NONE),
};
const sx_layout sxsw_stata_map_le = {UINT32_C(0x602d004c),"stata_map_le",sxsw_stata_map_le_fields,SX_COUNT(sxsw_stata_map_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata_sort_index_le_fields[] = {
    SX_FIELD("variable_index","uint16",0,2,SX_ID),
};
const sx_layout sxsw_stata_sort_index_le = {UINT32_C(0x602d004e),"stata_sort_index_le",sxsw_stata_sort_index_le_fields,SX_COUNT(sxsw_stata_sort_index_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_stata117_prefix_be_fields[] = {
    SX_FIELD("prefix","char[28]",0,28,SX_SIGNATURE),
    SX_FIELD("release","char[3]",28,3,SX_ID),
    SX_FIELD("release_end","char[21]",31,21,SX_NONE),
    SX_FIELD("byte_order","char[3]",52,3,SX_ID),
    SX_FIELD("byte_order_end","char[15]",55,15,SX_NONE),
    SX_FIELD("variable_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("variable_count_end","char[7]",72,7,SX_NONE),
    SX_FIELD("observation_count","uint32",79,4,SX_COUNT_PROP),
};
const sx_layout sxsw_stata117_prefix_be = {UINT32_C(0x602d004f),"stata117_prefix_be",sxsw_stata117_prefix_be_fields,SX_COUNT(sxsw_stata117_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata117_label_size_be_fields[] = {
    SX_FIELD("label_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxsw_stata117_label_size_be = {UINT32_C(0x602d0050),"stata117_label_size_be",sxsw_stata117_label_size_be_fields,SX_COUNT(sxsw_stata117_label_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata118_prefix_be_fields[] = {
    SX_FIELD("prefix","char[28]",0,28,SX_SIGNATURE),
    SX_FIELD("release","char[3]",28,3,SX_ID),
    SX_FIELD("release_end","char[21]",31,21,SX_NONE),
    SX_FIELD("byte_order","char[3]",52,3,SX_ID),
    SX_FIELD("byte_order_end","char[15]",55,15,SX_NONE),
    SX_FIELD("variable_count","uint16",70,2,SX_COUNT_PROP),
    SX_FIELD("variable_count_end","char[7]",72,7,SX_NONE),
    SX_FIELD("observation_count","uint64",79,8,SX_COUNT_PROP),
};
const sx_layout sxsw_stata118_prefix_be = {UINT32_C(0x602d0051),"stata118_prefix_be",sxsw_stata118_prefix_be_fields,SX_COUNT(sxsw_stata118_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata118_label_size_be_fields[] = {
    SX_FIELD("label_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxsw_stata118_label_size_be = {UINT32_C(0x602d0052),"stata118_label_size_be",sxsw_stata118_label_size_be_fields,SX_COUNT(sxsw_stata118_label_size_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata_map_be_fields[] = {
    SX_FIELD("start","char[5]",0,5,SX_NONE),
    SX_FIELD("file_start","uint64",5,8,SX_OFFSET),
    SX_FIELD("map_offset","uint64",13,8,SX_OFFSET),
    SX_FIELD("variable_types_offset","uint64",21,8,SX_OFFSET),
    SX_FIELD("variable_names_offset","uint64",29,8,SX_OFFSET),
    SX_FIELD("sortlist_offset","uint64",37,8,SX_OFFSET),
    SX_FIELD("formats_offset","uint64",45,8,SX_OFFSET),
    SX_FIELD("value_label_names_offset","uint64",53,8,SX_OFFSET),
    SX_FIELD("variable_labels_offset","uint64",61,8,SX_OFFSET),
    SX_FIELD("characteristics_offset","uint64",69,8,SX_OFFSET),
    SX_FIELD("data_offset","uint64",77,8,SX_OFFSET),
    SX_FIELD("strls_offset","uint64",85,8,SX_OFFSET),
    SX_FIELD("value_labels_offset","uint64",93,8,SX_OFFSET),
    SX_FIELD("file_end_tag_offset","uint64",101,8,SX_OFFSET),
    SX_FIELD("file_end","uint64",109,8,SX_OFFSET),
    SX_FIELD("end","char[6]",117,6,SX_NONE),
};
const sx_layout sxsw_stata_map_be = {UINT32_C(0x602d0053),"stata_map_be",sxsw_stata_map_be_fields,SX_COUNT(sxsw_stata_map_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata_sort_index_be_fields[] = {
    SX_FIELD("variable_index","uint16",0,2,SX_ID),
};
const sx_layout sxsw_stata_sort_index_be = {UINT32_C(0x602d0055),"stata_sort_index_be",sxsw_stata_sort_index_be_fields,SX_COUNT(sxsw_stata_sort_index_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_stata_timestamp_size_fields[] = {
    SX_FIELD("timestamp_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxsw_stata_timestamp_size = {UINT32_C(0x602d0056),"stata_timestamp_size",sxsw_stata_timestamp_size_fields,SX_COUNT(sxsw_stata_timestamp_size_fields),SX_LE};
static uint64_t sxsw64(const uint8_t *p,bool be){return xx_data_get_u64(p,8,0,be);}
static bool sxsw_literal(sx_context *c,int64_t *at,const char *s)
{
 size_t n=xx_rt_strlen(s);uint8_t b[128];if(n>sizeof(b)||!sx_read(c,*at,b,n)||xx_rt_memcmp(b,s,n))return false;*at+=(int64_t)n;return true;
}
static bool sxsw_stata(sx_context *c)
{
 uint8_t b[128];if(!sx_read(c,0,b,79))return false;bool v118=b[30]=='8',be=!xx_rt_memcmp(b+50,"MSF",3);unsigned width=v118?8:4;
 /* Prefix locations are fixed by the mandatory release/byte-order tags. */
 int64_t at=0;if(!sxsw_literal(c,&at,"<stata_dta><header><release>"))return false;at+=3;if(!sxsw_literal(c,&at,"</release><byteorder>"))return false;
 if(!sx_read(c,at,b,3))return false;be=!xx_rt_memcmp(b,"MSF",3);at+=3;
 if(!sxsw_literal(c,&at,"</byteorder><K>"))return false;uint16_t vars;if(!sx_u16(c,at,be,&vars)||!vars||vars>4096)return false;at+=2;
 if(!sxsw_literal(c,&at,"</K><N>"))return false;at+=width;
 const sx_layout *prefix=v118?(be?&sxsw_stata118_prefix_be:&sxsw_stata118_prefix_le):(be?&sxsw_stata117_prefix_be:&sxsw_stata117_prefix_le);
 if(!sxsw_add(c,prefix,0,at)||!sxsw_literal(c,&at,"</N><label>"))return false;
 unsigned n;if(v118){uint16_t x;if(!sx_u16(c,at,be,&x))return false;n=x;}else{if(!sx_read(c,at,b,1))return false;n=b[0];}
 if(!sxsw_add(c,v118?(be?&sxsw_stata118_label_size_be:&sxsw_stata118_label_size_le):(be?&sxsw_stata117_label_size_be:&sxsw_stata117_label_size_le),at,v118?2:1)||!sxsw_span(c,at+(v118?2:1),n))return false;at+=(v118?2:1)+n;
 if(!sxsw_literal(c,&at,"</label><timestamp>")||!sx_read(c,at,b,1)||!sxsw_add(c,&sxsw_stata_timestamp_size,at,1)||!sxsw_span(c,at+1,b[0]))return false;at+=1+b[0];
 if(!sxsw_literal(c,&at,"</timestamp></header>")||!sx_read(c,at,b,123)||!sxsw_add(c,be?&sxsw_stata_map_be:&sxsw_stata_map_le,at,123))return false;
 uint64_t offsets[14];for(unsigned i=0;i<14;i++){offsets[i]=sxsw64(b+5+i*8,be);if(offsets[i]>(uint64_t)c->size)return false;}
 const char *tags[]={"<variable_types>","<varnames>","<sortlist>","<formats>","<value_label_names>","<variable_labels>"};
 const sx_layout *layouts[]={be?&sxsw_stata_type_be:&sxsw_stata_type_le,v118?&sxsw_stata118_variable_name:&sxsw_stata117_variable_name,be?&sxsw_stata_sort_index_be:&sxsw_stata_sort_index_le,v118?&sxsw_stata118_display_format:&sxsw_stata117_display_format,v118?&sxsw_stata118_value_label_name:&sxsw_stata117_value_label_name,v118?&sxsw_stata118_variable_label:&sxsw_stata117_variable_label};
 const unsigned widths[]={2,v118?129:33,2,v118?57:49,v118?129:33,v118?321:81};
 for(unsigned i=0;i<6;i++){at=(int64_t)offsets[i+2];if(!sxsw_literal(c,&at,tags[i])||!sxsw_table(c,layouts[i],at,widths[i],vars+(i==2)))return false;}return true;
}
bool sx_stata_dta_build(sx_context*c)
{
 return sxsw_stata(c);
}
