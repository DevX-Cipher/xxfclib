/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Java class file data structures, moved out of the vmmeta schema family. */
#include "../../xx_format_schema_vmmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_vm_java_class_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("minor_version","uint16",4,2,SX_ID),
    SX_FIELD("major_version","uint16",6,2,SX_ID),
    SX_FIELD("constant_pool_count","uint16",8,2,SX_COUNT_PROP),
};
const sx_layout sx_vm_java_class_header = {0x60160001U,"java_class_header",sx_vm_java_class_header_fields,SX_COUNT(sx_vm_java_class_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_utf8_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("byte_length","uint16",1,2,SX_SIZE),
};
const sx_layout sx_vm_java_constant_utf8 = {0x60160002U,"java_constant_utf8",sx_vm_java_constant_utf8_fields,SX_COUNT(sx_vm_java_constant_utf8_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_integer_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("value","int32",1,4,SX_NONE),
};
const sx_layout sx_vm_java_constant_integer = {0x60160003U,"java_constant_integer",sx_vm_java_constant_integer_fields,SX_COUNT(sx_vm_java_constant_integer_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_float_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("ieee754_bits","uint32",1,4,SX_NONE),
};
const sx_layout sx_vm_java_constant_float = {0x60160004U,"java_constant_float",sx_vm_java_constant_float_fields,SX_COUNT(sx_vm_java_constant_float_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_long_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("high_bytes","uint32",1,4,SX_NONE),
    SX_FIELD("low_bytes","uint32",5,4,SX_NONE),
};
const sx_layout sx_vm_java_constant_long = {0x60160005U,"java_constant_long",sx_vm_java_constant_long_fields,SX_COUNT(sx_vm_java_constant_long_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_double_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("high_bytes","uint32",1,4,SX_NONE),
    SX_FIELD("low_bytes","uint32",5,4,SX_NONE),
};
const sx_layout sx_vm_java_constant_double = {0x60160006U,"java_constant_double",sx_vm_java_constant_double_fields,SX_COUNT(sx_vm_java_constant_double_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_class_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("name_index","uint16",1,2,SX_ID),
};
const sx_layout sx_vm_java_constant_class = {0x60160007U,"java_constant_class",sx_vm_java_constant_class_fields,SX_COUNT(sx_vm_java_constant_class_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_string_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("string_index","uint16",1,2,SX_ID),
};
const sx_layout sx_vm_java_constant_string = {0x60160008U,"java_constant_string",sx_vm_java_constant_string_fields,SX_COUNT(sx_vm_java_constant_string_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_method_type_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("descriptor_index","uint16",1,2,SX_ID),
};
const sx_layout sx_vm_java_constant_method_type = {0x60160009U,"java_constant_method_type",sx_vm_java_constant_method_type_fields,SX_COUNT(sx_vm_java_constant_method_type_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_module_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("name_index","uint16",1,2,SX_ID),
};
const sx_layout sx_vm_java_constant_module = {0x6016000aU,"java_constant_module",sx_vm_java_constant_module_fields,SX_COUNT(sx_vm_java_constant_module_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_package_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("name_index","uint16",1,2,SX_ID),
};
const sx_layout sx_vm_java_constant_package = {0x6016000bU,"java_constant_package",sx_vm_java_constant_package_fields,SX_COUNT(sx_vm_java_constant_package_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_fieldref_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("class_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
const sx_layout sx_vm_java_constant_fieldref = {0x6016000cU,"java_constant_fieldref",sx_vm_java_constant_fieldref_fields,SX_COUNT(sx_vm_java_constant_fieldref_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_methodref_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("class_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
const sx_layout sx_vm_java_constant_methodref = {0x6016000dU,"java_constant_methodref",sx_vm_java_constant_methodref_fields,SX_COUNT(sx_vm_java_constant_methodref_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_interface_methodref_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("class_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
const sx_layout sx_vm_java_constant_interface_methodref = {0x6016000eU,"java_constant_interface_methodref",sx_vm_java_constant_interface_methodref_fields,SX_COUNT(sx_vm_java_constant_interface_methodref_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_name_and_type_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("name_index","uint16",1,2,SX_ID),
    SX_FIELD("descriptor_index","uint16",3,2,SX_ID),
};
const sx_layout sx_vm_java_constant_name_and_type = {0x6016000fU,"java_constant_name_and_type",sx_vm_java_constant_name_and_type_fields,SX_COUNT(sx_vm_java_constant_name_and_type_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_dynamic_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("bootstrap_method_attr_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
const sx_layout sx_vm_java_constant_dynamic = {0x60160010U,"java_constant_dynamic",sx_vm_java_constant_dynamic_fields,SX_COUNT(sx_vm_java_constant_dynamic_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_invoke_dynamic_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("bootstrap_method_attr_index","uint16",1,2,SX_ID),
    SX_FIELD("name_and_type_index","uint16",3,2,SX_ID),
};
const sx_layout sx_vm_java_constant_invoke_dynamic = {0x60160011U,"java_constant_invoke_dynamic",sx_vm_java_constant_invoke_dynamic_fields,SX_COUNT(sx_vm_java_constant_invoke_dynamic_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_constant_method_handle_fields[] = {
    SX_FIELD("tag","uint8",0,1,SX_ID),
    SX_FIELD("reference_kind","uint8",1,1,SX_ID),
    SX_FIELD("reference_index","uint16",2,2,SX_ID),
};
const sx_layout sx_vm_java_constant_method_handle = {0x60160012U,"java_constant_method_handle",sx_vm_java_constant_method_handle_fields,SX_COUNT(sx_vm_java_constant_method_handle_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_interface_fields[] = {
    SX_FIELD("class_index","uint16",0,2,SX_ID),
};
const sx_layout sx_vm_java_interface = {0x60160014U,"java_interface",sx_vm_java_interface_fields,SX_COUNT(sx_vm_java_interface_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_fields_count_fields[] = {
    SX_FIELD("fields_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sx_vm_java_fields_count = {0x60160015U,"java_fields_count",sx_vm_java_fields_count_fields,SX_COUNT(sx_vm_java_fields_count_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_methods_count_fields[] = {
    SX_FIELD("methods_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sx_vm_java_methods_count = {0x60160016U,"java_methods_count",sx_vm_java_methods_count_fields,SX_COUNT(sx_vm_java_methods_count_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_attributes_count_fields[] = {
    SX_FIELD("attributes_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sx_vm_java_attributes_count = {0x60160017U,"java_attributes_count",sx_vm_java_attributes_count_fields,SX_COUNT(sx_vm_java_attributes_count_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_attribute_info_fields[] = {
    SX_FIELD("attribute_name_index","uint16",0,2,SX_ID),
    SX_FIELD("attribute_length","uint32",2,4,SX_SIZE),
};
const sx_layout sx_vm_java_attribute_info = {0x6016001aU,"java_attribute_info",sx_vm_java_attribute_info_fields,SX_COUNT(sx_vm_java_attribute_info_fields),SX_BE};
static bool sx_vm_get16(sx_context *c,uint64_t *at,uint16_t *v){if(!sx_vm_span(c,*at,2)||!sx_u16(c,(int64_t)*at,true,v))return false;*at+=2;return true;}
static bool sx_vm_java_attributes(sx_context *c,uint64_t *at,uint16_t count)
{
    for(uint16_t i=0;i<count;i++){
        uint8_t b[6];if(!sx_vm_span(c,*at,6)||!sx_read(c,(int64_t)*at,b,6))return false;
        uint32_t n=xx_data_get_u32(b,6,2,true);if(!sx_vm_span(c,*at+6,n)||!sx_add(c,&sx_vm_java_attribute_info,(int64_t)*at,6))return false;*at+=6+(uint64_t)n;
    }return true;
}
static bool sx_vm_java(sx_context *c)
{
    uint16_t total;uint64_t at=8;
    if(!sx_vm_get16(c,&at,&total)||total<2||!sx_add(c,&sx_vm_java_class_header,0,10))return false;
    for(uint32_t i=1;i<total;i++){
        uint8_t tag;uint32_t n=0;const sx_layout *l=NULL;
        if(!sx_vm_span(c,at,1)||!sx_read(c,(int64_t)at,&tag,1))return false;
        switch(tag){
        case 1:{uint16_t len;if(!sx_vm_span(c,at,3)||!sx_u16(c,(int64_t)at+1,true,&len)||!sx_vm_span(c,at+3,len)||!sx_add(c,&sx_vm_java_constant_utf8,(int64_t)at,3))return false;at+=3+(uint64_t)len;continue;}
        case 3:l=&sx_vm_java_constant_integer;n=5;break;
        case 4:l=&sx_vm_java_constant_float;n=5;break;
        case 5:l=&sx_vm_java_constant_long;n=9;if(++i>=total)return false;break;
        case 6:l=&sx_vm_java_constant_double;n=9;if(++i>=total)return false;break;
        case 7:l=&sx_vm_java_constant_class;n=3;break;
        case 8:l=&sx_vm_java_constant_string;n=3;break;
        case 9:l=&sx_vm_java_constant_fieldref;n=5;break;
        case 10:l=&sx_vm_java_constant_methodref;n=5;break;
        case 11:l=&sx_vm_java_constant_interface_methodref;n=5;break;
        case 12:l=&sx_vm_java_constant_name_and_type;n=5;break;
        case 15:l=&sx_vm_java_constant_method_handle;n=4;break;
        case 16:l=&sx_vm_java_constant_method_type;n=3;break;
        case 17:l=&sx_vm_java_constant_dynamic;n=5;break;
        case 18:l=&sx_vm_java_constant_invoke_dynamic;n=5;break;
        case 19:l=&sx_vm_java_constant_module;n=3;break;
        case 20:l=&sx_vm_java_constant_package;n=3;break;
        default:return false;
        }
        if(!sx_add(c,l,(int64_t)at,n))return false;at+=n;
    }
    uint16_t count;
    if(!sx_vm_span(c,at,8)||!sx_u16(c,(int64_t)at+6,true,&count)||!sx_add(c,&sx_vm_java_class_identity,(int64_t)at,8))return false;at+=8;
    if(!sx_vm_span(c,at,(uint64_t)count*2)||!sx_table(c,&sx_vm_java_interface,(int64_t)at,2,count))return false;at+=(uint64_t)count*2;
    for(unsigned k=0;k<2;k++){
        if(!sx_add(c,k?&sx_vm_java_methods_count:&sx_vm_java_fields_count,(int64_t)at,2)||!sx_vm_get16(c,&at,&count))return false;
        for(uint16_t j=0;j<count;j++){
            uint16_t attrs;if(!sx_vm_span(c,at,8)||!sx_u16(c,(int64_t)at+6,true,&attrs)||!sx_add(c,k?&sx_vm_java_method_info:&sx_vm_java_field_info,(int64_t)at,8))return false;at+=8;
            if(!sx_vm_java_attributes(c,&at,attrs))return false;
        }
    }
    if(!sx_add(c,&sx_vm_java_attributes_count,(int64_t)at,2)||!sx_vm_get16(c,&at,&count)||!sx_vm_java_attributes(c,&at,count))return false;
    return at<=(uint64_t)c->size;
}
bool sx_java_class_build(sx_context*c)
{
    return sx_vm_java(c);
}
