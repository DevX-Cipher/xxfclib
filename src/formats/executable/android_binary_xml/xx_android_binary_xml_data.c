/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Android binary XML data structures, moved out of the androidmeta schema family. */
#include "../../xx_format_schema_androidmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_am_android_chunk_header_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
};
const sx_layout sx_am_android_chunk_header = {0x601b0001U,"android_chunk_header",sx_am_android_chunk_header_fields,SX_COUNT(sx_am_android_chunk_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_xml_node_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("line_number","uint32",8,4,SX_NONE),
    SX_FIELD("comment_index","uint32",12,4,SX_ID),
};
const sx_layout sx_am_android_xml_node = {0x601b0004U,"android_xml_node",sx_am_android_xml_node_fields,SX_COUNT(sx_am_android_xml_node_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_xml_namespace_fields[] = {
    SX_FIELD("prefix_index","uint32",0,4,SX_ID),
    SX_FIELD("uri_index","uint32",4,4,SX_ID),
};
const sx_layout sx_am_android_xml_namespace = {0x601b0005U,"android_xml_namespace",sx_am_android_xml_namespace_fields,SX_COUNT(sx_am_android_xml_namespace_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_xml_start_element_fields[] = {
    SX_FIELD("namespace_index","uint32",0,4,SX_ID),
    SX_FIELD("name_index","uint32",4,4,SX_ID),
    SX_FIELD("attribute_start","uint16",8,2,SX_OFFSET),
    SX_FIELD("attribute_size","uint16",10,2,SX_SIZE),
    SX_FIELD("attribute_count","uint16",12,2,SX_COUNT_PROP),
    SX_FIELD("id_index","uint16",14,2,SX_ID),
    SX_FIELD("class_index","uint16",16,2,SX_ID),
    SX_FIELD("style_index","uint16",18,2,SX_ID),
};
const sx_layout sx_am_android_xml_start_element = {0x601b0006U,"android_xml_start_element",sx_am_android_xml_start_element_fields,SX_COUNT(sx_am_android_xml_start_element_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_xml_end_element_fields[] = {
    SX_FIELD("namespace_index","uint32",0,4,SX_ID),
    SX_FIELD("name_index","uint32",4,4,SX_ID),
};
const sx_layout sx_am_android_xml_end_element = {0x601b0007U,"android_xml_end_element",sx_am_android_xml_end_element_fields,SX_COUNT(sx_am_android_xml_end_element_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_xml_attribute_fields[] = {
    SX_FIELD("namespace_index","uint32",0,4,SX_ID),
    SX_FIELD("name_index","uint32",4,4,SX_ID),
    SX_FIELD("raw_value_index","uint32",8,4,SX_ID),
    SX_FIELD("value_size","uint16",12,2,SX_SIZE),
    SX_FIELD("reserved","uint8",14,1,SX_RESERVED),
    SX_FIELD("data_type","uint8",15,1,SX_ID),
    SX_FIELD("data","uint32",16,4,SX_NONE),
};
const sx_layout sx_am_android_xml_attribute = {0x601b0008U,"android_xml_attribute",sx_am_android_xml_attribute_fields,SX_COUNT(sx_am_android_xml_attribute_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_xml_cdata_fields[] = {
    SX_FIELD("data_index","uint32",0,4,SX_ID),
    SX_FIELD("value_size","uint16",4,2,SX_SIZE),
    SX_FIELD("reserved","uint8",6,1,SX_RESERVED),
    SX_FIELD("data_type","uint8",7,1,SX_ID),
    SX_FIELD("data","uint32",8,4,SX_NONE),
};
const sx_layout sx_am_android_xml_cdata = {0x601b0009U,"android_xml_cdata",sx_am_android_xml_cdata_fields,SX_COUNT(sx_am_android_xml_cdata_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_resource_id_fields[] = {
    SX_FIELD("resource_id","uint32",0,4,SX_ID),
};
const sx_layout sx_am_android_resource_id = {0x601b000aU,"android_resource_id",sx_am_android_resource_id_fields,SX_COUNT(sx_am_android_resource_id_fields),SX_LE};
static bool sx_am_xml(sx_context *c,const sx_am_chunk_info *root)
{
    if(root->type!=3||!sx_add(c,&sx_am_android_chunk_header,0,8))return false;
    uint64_t at=root->header;unsigned nodes=0;
    while(at<root->end){
        sx_am_chunk_info q;if(++nodes>100000||!sx_am_chunk(c,at,root->end,&q))return false;uint64_t ext=at+q.header;
        if(q.type==1){if(!sx_am_pool(c,&q))return false;}
        else if(q.type==384){
            uint64_t n=(q.end-ext)/4;if(q.header!=8||(q.end-ext)%4||n>65536||!sx_add(c,&sx_am_android_chunk_header,(int64_t)at,8)||!sx_table(c,&sx_am_android_resource_id,(int64_t)ext,4,n))return false;
        }else{
            if(q.header<16||!sx_add(c,&sx_am_android_xml_node,(int64_t)at,16))return false;
            if(q.type==256||q.type==257){if(q.end-ext<8||!sx_add(c,&sx_am_android_xml_namespace,(int64_t)ext,8))return false;}
            else if(q.type==259){if(q.end-ext<8||!sx_add(c,&sx_am_android_xml_end_element,(int64_t)ext,8))return false;}
            else if(q.type==260){if(q.end-ext<12||!sx_add(c,&sx_am_android_xml_cdata,(int64_t)ext,12))return false;}
            else if(q.type==258){
                uint8_t b[20];if(q.end-ext<20||!sx_read(c,(int64_t)ext,b,20)||!sx_add(c,&sx_am_android_xml_start_element,(int64_t)ext,20))return false;
                uint16_t start=xx_data_get_u16(b,20,8,false),width=xx_data_get_u16(b,20,10,false),n=xx_data_get_u16(b,20,12,false);
                if(start<20||width<20||n>2048||start>q.end-ext||(uint64_t)n*width>q.end-ext-start)return false;
                if(width==20){if(!sx_table(c,&sx_am_android_xml_attribute,(int64_t)(ext+start),20,n))return false;}
                else for(uint16_t i=0;i<n;i++)if(!sx_add(c,&sx_am_android_xml_attribute,(int64_t)(ext+start+(uint64_t)i*width),20))return false;
            }else return false;
        }at=q.end;
    }return at==root->end;
}
bool sx_android_binary_xml_build(sx_context*c,sx_am_chunk_info root)
{
 return sx_am_xml(c,&root);
}
