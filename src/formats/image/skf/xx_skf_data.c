/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SKF data structures, moved out of the resourceextra schema family. */
#include "../../xx_format_schema_resourceextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxre_skf_short_string_length_fields[] = {
 SX_FIELD("string_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxre_skf_short_string_length = {UINT32_C(0x603f000f),"skf_short_string_length",sxre_skf_short_string_length_fields,SX_COUNT(sxre_skf_short_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_long_string_length_fields[] = {
 SX_FIELD("string_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxre_skf_long_string_length = {UINT32_C(0x603f0010),"skf_long_string_length",sxre_skf_long_string_length_fields,SX_COUNT(sxre_skf_long_string_length_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_object_count_fields[] = {
 SX_FIELD("object_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxre_skf_object_count = {UINT32_C(0x603f0011),"skf_object_count",sxre_skf_object_count_fields,SX_COUNT(sxre_skf_object_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_property_count_fields[] = {
 SX_FIELD("property_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxre_skf_property_count = {UINT32_C(0x603f0012),"skf_property_count",sxre_skf_property_count_fields,SX_COUNT(sxre_skf_property_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_property_id_fields[] = {
 SX_FIELD("property_id","uint16",0,2,SX_NONE),
};
const sx_layout sxre_skf_property_id = {UINT32_C(0x603f0013),"skf_property_id",sxre_skf_property_id_fields,SX_COUNT(sxre_skf_property_id_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_resource_count_fields[] = {
 SX_FIELD("resource_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxre_skf_resource_count = {UINT32_C(0x603f0014),"skf_resource_count",sxre_skf_resource_count_fields,SX_COUNT(sxre_skf_resource_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_resource_prefix_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
 SX_FIELD("opaque_word","uint16",4,2,SX_NONE),
};
const sx_layout sxre_skf_resource_prefix = {UINT32_C(0x603f0015),"skf_resource_prefix",sxre_skf_resource_prefix_fields,SX_COUNT(sxre_skf_resource_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_record6_count_fields[] = {
 SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxre_skf_record6_count = {UINT32_C(0x603f0016),"skf_record6_count",sxre_skf_record6_count_fields,SX_COUNT(sxre_skf_record6_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_optional_flag_fields[] = {
 SX_FIELD("present","uint32",0,4,SX_NONE),
};
const sx_layout sxre_skf_optional_flag = {UINT32_C(0x603f0017),"skf_optional_flag",sxre_skf_optional_flag_fields,SX_COUNT(sxre_skf_optional_flag_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_record14_count_fields[] = {
 SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxre_skf_record14_count = {UINT32_C(0x603f0018),"skf_record14_count",sxre_skf_record14_count_fields,SX_COUNT(sxre_skf_record14_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_variable_record_count_fields[] = {
 SX_FIELD("record_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxre_skf_variable_record_count = {UINT32_C(0x603f0019),"skf_variable_record_count",sxre_skf_variable_record_count_fields,SX_COUNT(sxre_skf_variable_record_count_fields),SX_LE};
static const xx_data_struct_field_desc sxre_skf_payload_size_fields[] = {
 SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxre_skf_payload_size = {UINT32_C(0x603f001a),"skf_payload_size",sxre_skf_payload_size_fields,SX_COUNT(sxre_skf_payload_size_fields),SX_LE};
static bool sxre_skip(sx_context*c,uint64_t*p,uint64_t n){if(!sxre_span(c,*p,n))return false;*p+=n;return true;}
static bool sxre_scalar(sx_context*c,const sx_layout*l,uint64_t*p,unsigned width,uint64_t*v){if(!sxre_word(c,*p,width,false,v)||!sxre_add(c,l,*p))return false;*p+=width;return true;}
static bool sxre_name(sx_context*c,uint64_t*p,bool big){uint64_t n;return sxre_scalar(c,big?&sxre_skf_long_string_length:&sxre_skf_short_string_length,p,big?4:1,&n)&&n<=1024&&sxre_skip(c,p,n);}
static bool sxre_group(sx_context*c,uint64_t*p,unsigned version){uint64_t count,n;if(!sxre_scalar(c,&sxre_skf_resource_count,p,4,&count)||count>1000000)return false;for(uint64_t i=0;i<count;i++){
 if((version>218&&!sxre_skip(c,p,4))||!sxre_word(c,*p,4,false,&n)||n>INT32_MAX||!sxre_add(c,&sxre_skf_resource_prefix,*p)||!sxre_skip(c,p,6)||!sxre_skip(c,p,n)||!sxre_skip(c,p,version>205?24:20))return false;}
 if(!sxre_scalar(c,&sxre_skf_record6_count,p,4,&n)||n>INT32_MAX/6||!sxre_skip(c,p,n*6))return false;
 if(version>201){if(!sxre_scalar(c,&sxre_skf_record6_count,p,4,&n)||n>INT32_MAX/6||!sxre_skip(c,p,n*6))return false;if(version>206){if(!sxre_scalar(c,&sxre_skf_optional_flag,p,4,&n))return false;if(n&&(!sxre_skip(c,p,27)||!sxre_name(c,p,false)))return false;}if(version>218&&!sxre_skip(c,p,4))return false;}
 return sxre_skip(c,p,4);}
static bool sxre_skf(sx_context*c){uint8_t h[16];uint64_t p=0,n,objects;if(!sxre_word(c,0,1,false,&n)||n<6||n>15||!sxre_read(c,1,h,(size_t)n)||xx_rt_memcmp(h,"SKF",3)||h[3]<'0'||h[3]>'9'||h[4]!='.'||h[5]<'0'||h[5]>'9')return false;
 unsigned version=(h[3]-'0')*100+h[5]-'0';if(n>6){if(n!=7||h[6]<'0'||h[6]>'9')return false;version=(h[3]-'0')*100+(h[5]-'0')*10+h[6]-'0';}if(version<200||version>299||!sxre_name(c,&p,false))return false;
 for(unsigned i=0;i<(version>218?10U:4U);i++)if(!sxre_name(c,&p,true))return false;
 if(!sxre_scalar(c,&sxre_skf_object_count,&p,4,&objects)||objects>1000000)return false;
 for(uint64_t i=0;i<objects;i++){uint64_t properties;if(!sxre_name(c,&p,false)||!sxre_scalar(c,&sxre_skf_property_count,&p,4,&properties)||properties>65535)return false;
  for(uint64_t j=0;j<properties;j++){uint64_t prop;if(!sxre_scalar(c,&sxre_skf_property_id,&p,2,&prop)||!prop||!sxre_group(c,&p,version))return false;
   if(prop==13){if(!sxre_skip(c,&p,4))return false;}else if(prop==44){if(!sxre_scalar(c,&sxre_skf_payload_size,&p,4,&n)||n>INT32_MAX||!sxre_skip(c,&p,n))return false;}else if(prop==2){
    for(unsigned k=0;k<4;k++){uint64_t m;if(!sxre_group(c,&p,version)||!sxre_scalar(c,&sxre_skf_record14_count,&p,4,&n)||n>INT32_MAX/14||!sxre_skip(c,&p,n*14)||!sxre_scalar(c,&sxre_skf_variable_record_count,&p,4,&m)||m>1000000)return false;
     for(uint64_t l=0;l<m;l++)if(!sxre_skip(c,&p,14)||!sxre_scalar(c,&sxre_skf_payload_size,&p,4,&n)||n>INT32_MAX||!sxre_skip(c,&p,n))return false;
     if(version<209&&!sxre_skip(c,&p,4))return false;}
    if(!sxre_group(c,&p,version)||(version<=208&&!sxre_skip(c,&p,version==200?100:version==201?148:76)))return false;
   }
  }
 }
 return true;}
bool sx_skf_build(sx_context*c)
{
return sxre_skf(c);
}
