/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sigma x3f data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_x3f_header20_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("unique_identifier","uint8[16]",8,16,SX_ID),
    SX_FIELD("mark_bits","uint32",24,4,SX_FLAGS),
    SX_FIELD("columns","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("rows","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("rotation_degrees","uint32",36,4,SX_NONE),
};
const sx_layout sxrm_x3f_header20 = {UINT32_C(0x601d0068),"x3f_header20",sxrm_x3f_header20_fields,SX_COUNT(sxrm_x3f_header20_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_header21_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("unique_identifier","uint8[16]",8,16,SX_ID),
    SX_FIELD("mark_bits","uint32",24,4,SX_FLAGS),
    SX_FIELD("columns","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("rows","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("rotation_degrees","uint32",36,4,SX_NONE),
    SX_FIELD("white_balance","char[32]",40,32,SX_STRING),
    SX_FIELD("extended_types","uint8[32]",72,32,SX_ID),
    SX_FIELD("extended_data","float32[32]",104,128,SX_NONE),
};
const sx_layout sxrm_x3f_header21 = {UINT32_C(0x601d0069),"x3f_header21",sxrm_x3f_header21_fields,SX_COUNT(sxrm_x3f_header21_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_header23_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("unique_identifier","uint8[16]",8,16,SX_ID),
    SX_FIELD("mark_bits","uint32",24,4,SX_FLAGS),
    SX_FIELD("columns","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("rows","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("rotation_degrees","uint32",36,4,SX_NONE),
    SX_FIELD("white_balance","char[32]",40,32,SX_STRING),
    SX_FIELD("color_mode","char[32]",72,32,SX_STRING),
    SX_FIELD("extended_types","uint8[32]",104,32,SX_ID),
    SX_FIELD("extended_data","float32[32]",136,128,SX_NONE),
};
const sx_layout sxrm_x3f_header23 = {UINT32_C(0x601d006a),"x3f_header23",sxrm_x3f_header23_fields,SX_COUNT(sxrm_x3f_header23_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_directory_offset_fields[] = {
    SX_FIELD("directory_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxrm_x3f_directory_offset = {UINT32_C(0x601d006b),"x3f_directory_offset",sxrm_x3f_directory_offset_fields,SX_COUNT(sxrm_x3f_directory_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_directory_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("entry_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxrm_x3f_directory = {UINT32_C(0x601d006c),"x3f_directory",sxrm_x3f_directory_fields,SX_COUNT(sxrm_x3f_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_directory_entry_fields[] = {
    SX_FIELD("section_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("section_size","uint32",4,4,SX_SIZE),
    SX_FIELD("section_type","char[4]",8,4,SX_ID),
};
const sx_layout sxrm_x3f_directory_entry = {UINT32_C(0x601d006d),"x3f_directory_entry",sxrm_x3f_directory_entry_fields,SX_COUNT(sxrm_x3f_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_image_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("image_type","uint32",8,4,SX_ID),
    SX_FIELD("image_format","uint32",12,4,SX_ID),
    SX_FIELD("width","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("row_stride","uint32",24,4,SX_SIZE),
};
const sx_layout sxrm_x3f_image = {UINT32_C(0x601d006e),"x3f_image",sxrm_x3f_image_fields,SX_COUNT(sxrm_x3f_image_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_camf2_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("type","uint32",8,4,SX_ID),
    SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
    SX_FIELD("information_type","uint32",16,4,SX_ID),
    SX_FIELD("information_type_version","uint32",20,4,SX_ID),
    SX_FIELD("encryption_key","uint32",24,4,SX_ID),
};
const sx_layout sxrm_x3f_camf2 = {UINT32_C(0x601d006f),"x3f_camf2",sxrm_x3f_camf2_fields,SX_COUNT(sxrm_x3f_camf2_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_properties_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("property_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("character_format","uint32",12,4,SX_ID),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
    SX_FIELD("string_pool_codeunits","uint32",20,4,SX_COUNT_PROP),
};
const sx_layout sxrm_x3f_properties = {UINT32_C(0x601d0070),"x3f_properties",sxrm_x3f_properties_fields,SX_COUNT(sxrm_x3f_properties_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_x3f_property_fields[] = {
    SX_FIELD("name_index","uint32",0,4,SX_NONE),
    SX_FIELD("value_index","uint32",4,4,SX_NONE),
};
const sx_layout sxrm_x3f_property = {UINT32_C(0x601d0071),"x3f_property",sxrm_x3f_property_fields,SX_COUNT(sxrm_x3f_property_fields),SX_LE};
static bool sxrm_x3f(sx_context *c)
{
 uint8_t h[40];if(!sxrm_read(c,0,h,40)||xx_rt_memcmp(h,"FOVb",4))return false;uint32_t version=sxrm32(h+4,false);if(version<0x20000||version>0x20003)return false;uint64_t head=version==0x20000?40:version<0x20003?232:264;
 if(!sxrm_add(c,version==0x20000?&sxrm_x3f_header20:version<0x20003?&sxrm_x3f_header21:&sxrm_x3f_header23,0))return false;
 if(c->size<(int64_t)head+4||!sxrm_read(c,(uint64_t)c->size-4,h,4))return true;uint64_t dir=sxrm32(h,false);if(!sxrm_add(c,&sxrm_x3f_directory_offset,(uint64_t)c->size-4))return false;
 if(dir<head||!sxrm_read(c,dir,h,12)||xx_rt_memcmp(h,"SECd",4))return true;unsigned n=sxrm32(h+8,false);if(n>32||!sxrm_span(c,dir+12,(uint64_t)n*12))return true;
 if(!sxrm_add(c,&sxrm_x3f_directory,dir)||!sxrm_table(c,&sxrm_x3f_directory_entry,dir+12,n))return false;
 for(unsigned i=0;i<n;i++){if(!sxrm_read(c,dir+12+(uint64_t)i*12,h,12))return false;uint64_t q=sxrm32(h,false);uint32_t z=sxrm32(h+4,false);if(q<head||z<24||!sxrm_span(c,q,z)||!sxrm_read(c,q,h,24))continue;
  if(!xx_rt_memcmp(h,"SECi",4)&&z>=28){if(!sxrm_add(c,&sxrm_x3f_image,q))return false;}
  else if(!xx_rt_memcmp(h,"SECc",4)&&z>=28&&sxrm32(h+8,false)==2){if(!sxrm_add(c,&sxrm_x3f_camf2,q))return false;}
  else if(!xx_rt_memcmp(h,"SECp",4)){if(!sxrm_add(c,&sxrm_x3f_properties,q))return false;uint32_t count=sxrm32(h+8,false);if(count<=20000&&(uint64_t)count*8<=z-24&&!sxrm_table(c,&sxrm_x3f_property,q+24,count))return false;}
 }return !c->failed;
}
bool sx_sigma_x3f_build(sx_context*c)
{
 return sxrm_x3f(c);
}
