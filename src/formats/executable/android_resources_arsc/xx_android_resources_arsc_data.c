/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Android resources (ARSC) data structures, moved out of the androidmeta schema family. */
#include "../../xx_format_schema_androidmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_am_android_table_header_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("package_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sx_am_android_table_header = {0x601b000bU,"android_table_header",sx_am_android_table_header_fields,SX_COUNT(sx_am_android_table_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_package_header_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("package_id","uint32",8,4,SX_ID),
    SX_FIELD("package_name","uint16[128]",12,256,SX_NONE),
    SX_FIELD("type_strings","uint32",268,4,SX_OFFSET),
    SX_FIELD("last_public_type","uint32",272,4,SX_ID),
    SX_FIELD("key_strings","uint32",276,4,SX_OFFSET),
    SX_FIELD("last_public_key","uint32",280,4,SX_ID),
};
const sx_layout sx_am_android_package_header = {0x601b000cU,"android_package_header",sx_am_android_package_header_fields,SX_COUNT(sx_am_android_package_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_package_header_extended_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("package_id","uint32",8,4,SX_ID),
    SX_FIELD("package_name","uint16[128]",12,256,SX_NONE),
    SX_FIELD("type_strings","uint32",268,4,SX_OFFSET),
    SX_FIELD("last_public_type","uint32",272,4,SX_ID),
    SX_FIELD("key_strings","uint32",276,4,SX_OFFSET),
    SX_FIELD("last_public_key","uint32",280,4,SX_ID),
    SX_FIELD("type_id_offset","uint32",284,4,SX_ID),
};
const sx_layout sx_am_android_package_header_extended = {0x601b000dU,"android_package_header_extended",sx_am_android_package_header_extended_fields,SX_COUNT(sx_am_android_package_header_extended_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_type_spec_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("type_id","uint8",8,1,SX_ID),
    SX_FIELD("reserved","uint8",9,1,SX_RESERVED),
    SX_FIELD("type_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sx_am_android_type_spec = {0x601b000eU,"android_type_spec",sx_am_android_type_spec_fields,SX_COUNT(sx_am_android_type_spec_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_type_spec_flags_fields[] = {
    SX_FIELD("configuration_flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sx_am_android_type_spec_flags = {0x601b000fU,"android_type_spec_flags",sx_am_android_type_spec_flags_fields,SX_COUNT(sx_am_android_type_spec_flags_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_config_size_fields[] = {
    SX_FIELD("config_size","uint32",0,4,SX_SIZE),
};
const sx_layout sx_am_android_config_size = {0x601b0011U,"android_config_size",sx_am_android_config_size_fields,SX_COUNT(sx_am_android_config_size_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_config_base_fields[] = {
    SX_FIELD("config_size","uint32",0,4,SX_SIZE),
    SX_FIELD("mobile_country_code","uint16",4,2,SX_ID),
    SX_FIELD("mobile_network_code","uint16",6,2,SX_ID),
    SX_FIELD("language","byte[2]",8,2,SX_NONE),
    SX_FIELD("country","byte[2]",10,2,SX_NONE),
    SX_FIELD("orientation","uint8",12,1,SX_ID),
    SX_FIELD("touchscreen","uint8",13,1,SX_ID),
    SX_FIELD("density","uint16",14,2,SX_NONE),
    SX_FIELD("keyboard","uint8",16,1,SX_ID),
    SX_FIELD("navigation","uint8",17,1,SX_ID),
    SX_FIELD("input_flags","uint8",18,1,SX_FLAGS),
    SX_FIELD("grammatical_inflection","uint8",19,1,SX_ID),
    SX_FIELD("screen_width","uint16",20,2,SX_NONE),
    SX_FIELD("screen_height","uint16",22,2,SX_NONE),
    SX_FIELD("sdk_version","uint16",24,2,SX_ID),
    SX_FIELD("minor_version","uint16",26,2,SX_RESERVED),
};
const sx_layout sx_am_android_config_base = {0x601b0012U,"android_config_base",sx_am_android_config_base_fields,SX_COUNT(sx_am_android_config_base_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_config_screen_fields[] = {
    SX_FIELD("screen_layout","uint8",0,1,SX_FLAGS),
    SX_FIELD("ui_mode","uint8",1,1,SX_FLAGS),
    SX_FIELD("smallest_screen_width_dp","uint16",2,2,SX_NONE),
};
const sx_layout sx_am_android_config_screen = {0x601b0013U,"android_config_screen",sx_am_android_config_screen_fields,SX_COUNT(sx_am_android_config_screen_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_config_size_dp_fields[] = {
    SX_FIELD("screen_width_dp","uint16",0,2,SX_NONE),
    SX_FIELD("screen_height_dp","uint16",2,2,SX_NONE),
};
const sx_layout sx_am_android_config_size_dp = {0x601b0014U,"android_config_size_dp",sx_am_android_config_size_dp_fields,SX_COUNT(sx_am_android_config_size_dp_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_config_locale_fields[] = {
    SX_FIELD("locale_script","char[4]",0,4,SX_NONE),
    SX_FIELD("locale_variant","char[8]",4,8,SX_NONE),
};
const sx_layout sx_am_android_config_locale = {0x601b0015U,"android_config_locale",sx_am_android_config_locale_fields,SX_COUNT(sx_am_android_config_locale_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_config_color_fields[] = {
    SX_FIELD("screen_layout2","uint8",0,1,SX_FLAGS),
    SX_FIELD("color_mode","uint8",1,1,SX_FLAGS),
    SX_FIELD("reserved","uint16",2,2,SX_RESERVED),
};
const sx_layout sx_am_android_config_color = {0x601b0016U,"android_config_color",sx_am_android_config_color_fields,SX_COUNT(sx_am_android_config_color_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_entry_offset_fields[] = {
    SX_FIELD("entry_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sx_am_android_entry_offset = {0x601b0017U,"android_entry_offset",sx_am_android_entry_offset_fields,SX_COUNT(sx_am_android_entry_offset_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_value_fields[] = {
    SX_FIELD("value_size","uint16",0,2,SX_SIZE),
    SX_FIELD("reserved","uint8",2,1,SX_RESERVED),
    SX_FIELD("data_type","uint8",3,1,SX_ID),
    SX_FIELD("data","uint32",4,4,SX_NONE),
};
const sx_layout sx_am_android_value = {0x601b001aU,"android_value",sx_am_android_value_fields,SX_COUNT(sx_am_android_value_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_table_map_fields[] = {
    SX_FIELD("name_resource_id","uint32",0,4,SX_ID),
    SX_FIELD("value_size","uint16",4,2,SX_SIZE),
    SX_FIELD("reserved","uint8",6,1,SX_RESERVED),
    SX_FIELD("data_type","uint8",7,1,SX_ID),
    SX_FIELD("data","uint32",8,4,SX_NONE),
};
const sx_layout sx_am_android_table_map = {0x601b001bU,"android_table_map",sx_am_android_table_map_fields,SX_COUNT(sx_am_android_table_map_fields),SX_LE};
static bool sx_am_config(sx_context *c,uint64_t at,uint64_t end)
{
    uint32_t n;if(!sx_u32(c,(int64_t)at,false,&n)||n<4||at>end||n>end-at)return false;
    if(n<28)return sx_add(c,&sx_am_android_config_size,(int64_t)at,4);
    if(!sx_add(c,&sx_am_android_config_base,(int64_t)at,28))return false;
    if(n>=32&&!sx_add(c,&sx_am_android_config_screen,(int64_t)at+28,4))return false;
    if(n>=36&&!sx_add(c,&sx_am_android_config_size_dp,(int64_t)at+32,4))return false;
    if(n>=48&&!sx_add(c,&sx_am_android_config_locale,(int64_t)at+36,12))return false;
    if(n>=52&&!sx_add(c,&sx_am_android_config_color,(int64_t)at+48,4))return false;
    return true;
}
static bool sx_am_type(sx_context *c,const sx_am_chunk_info *q)
{
    uint8_t b[20];if(q->header<24||!sx_read(c,(int64_t)q->at,b,20)||!sx_add(c,&sx_am_android_type_header,(int64_t)q->at,20)||!sx_am_config(c,q->at+20,q->at+q->header))return false;
    uint32_t n=xx_data_get_u32(b,20,12,false),start=xx_data_get_u32(b,20,16,false);
    if(b[9]||n>65536||start<q->header+(uint64_t)n*4||start>q->end-q->at||!sx_table(c,&sx_am_android_entry_offset,(int64_t)(q->at+q->header),4,n))return false;
    for(uint32_t i=0;i<n;i++){
        uint32_t off;if(!sx_u32(c,(int64_t)(q->at+q->header+(uint64_t)i*4),false,&off))return false;
        if(off==UINT32_MAX)continue;
        uint64_t pos=q->at+start+(uint64_t)off;if(pos>q->end||q->end-pos<8||!sx_read(c,(int64_t)pos,b,8))return false;
        uint16_t size=xx_data_get_u16(b,8,0,false),flags=xx_data_get_u16(b,8,2,false);
        if(flags&1){
            uint32_t count;if(size!=16||q->end-pos<16||!sx_u32(c,(int64_t)pos+12,false,&count)||count>4096||(uint64_t)count*12>q->end-pos-16||!sx_add(c,&sx_am_android_table_map_entry,(int64_t)pos,16)||!sx_table(c,&sx_am_android_table_map,(int64_t)pos+16,12,count))return false;
        }else if(size!=8||q->end-pos<16||!sx_add(c,&sx_am_android_table_entry,(int64_t)pos,8)||!sx_add(c,&sx_am_android_value,(int64_t)pos+8,8))return false;
    }return true;
}
static bool sx_am_package(sx_context *c,const sx_am_chunk_info *q)
{
    if((q->header!=284&&q->header!=288)||!sx_add(c,q->header==284?&sx_am_android_package_header:&sx_am_android_package_header_extended,(int64_t)q->at,q->header))return false;
    uint64_t at=q->at+q->header;unsigned chunks=0;
    while(at<q->end){
        sx_am_chunk_info z;if(++chunks>100000||!sx_am_chunk(c,at,q->end,&z))return false;
        if(z.type==1){if(!sx_am_pool(c,&z))return false;}
        else if(z.type==514){
            uint32_t n;if(z.header!=16||!sx_u32(c,(int64_t)at+12,false,&n)||n>65536||(uint64_t)n*4>z.end-at-16||!sx_add(c,&sx_am_android_type_spec,(int64_t)at,16)||!sx_table(c,&sx_am_android_type_spec_flags,(int64_t)at+16,4,n))return false;
        }else if(z.type==513){if(!sx_am_type(c,&z))return false;}
        else return false;at=z.end;
    }return at==q->end;
}
static bool sx_am_table(sx_context *c,const sx_am_chunk_info *root)
{
    if(root->type!=2||root->header!=12||!sx_add(c,&sx_am_android_table_header,0,12))return false;
    uint64_t at=12;unsigned chunks=0;
    while(at<root->end){
        sx_am_chunk_info q;if(++chunks>100000||!sx_am_chunk(c,at,root->end,&q))return false;
        if(q.type==1){if(!sx_am_pool(c,&q))return false;}else if(q.type==512){if(!sx_am_package(c,&q))return false;}else return false;at=q.end;
    }return at==root->end;
}
bool sx_android_resources_arsc_build(sx_context*c,sx_am_chunk_info root)
{
 return sx_am_table(c,&root);
}
