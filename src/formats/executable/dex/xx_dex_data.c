/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DEX data structures, moved out of the executable schema family. */
#include "../../xx_format_schema_executable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_dex_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("signature","uint8[20]",12,20,SX_NONE),
    SX_FIELD("file_size","uint32",32,4,SX_SIZE),
    SX_FIELD("header_size","uint32",36,4,SX_SIZE),
    SX_FIELD("endian_tag","uint32",40,4,SX_ID),
    SX_FIELD("link_size","uint32",44,4,SX_SIZE),
    SX_FIELD("link_off","uint32",48,4,SX_OFFSET),
    SX_FIELD("map_off","uint32",52,4,SX_OFFSET),
    SX_FIELD("string_ids_size","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("string_ids_off","uint32",60,4,SX_OFFSET),
    SX_FIELD("type_ids_size","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("type_ids_off","uint32",68,4,SX_OFFSET),
    SX_FIELD("proto_ids_size","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("proto_ids_off","uint32",76,4,SX_OFFSET),
    SX_FIELD("field_ids_size","uint32",80,4,SX_COUNT_PROP),
    SX_FIELD("field_ids_off","uint32",84,4,SX_OFFSET),
    SX_FIELD("method_ids_size","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("method_ids_off","uint32",92,4,SX_OFFSET),
    SX_FIELD("class_defs_size","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("class_defs_off","uint32",100,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",104,4,SX_SIZE),
    SX_FIELD("data_off","uint32",108,4,SX_OFFSET),
};
const sx_layout sx_dex_header_le = {0x60030001U,"dex_header_le",sx_dex_header_fields,SX_COUNT(sx_dex_header_fields),SX_LE};
const sx_layout sx_dex_header_be = {0x60030002U,"dex_header_be",sx_dex_header_fields,SX_COUNT(sx_dex_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_map_list_fields[] = {
    SX_FIELD("size","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_dex_map_list_le = {0x60030003U,"dex_map_list_le",sx_dex_map_list_fields,SX_COUNT(sx_dex_map_list_fields),SX_LE};
const sx_layout sx_dex_map_list_be = {0x60030004U,"dex_map_list_be",sx_dex_map_list_fields,SX_COUNT(sx_dex_map_list_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_map_item_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("unused","uint16",2,2,SX_RESERVED),
    SX_FIELD("size","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sx_dex_map_item_le = {0x60030005U,"dex_map_item_le",sx_dex_map_item_fields,SX_COUNT(sx_dex_map_item_fields),SX_LE};
const sx_layout sx_dex_map_item_be = {0x60030006U,"dex_map_item_be",sx_dex_map_item_fields,SX_COUNT(sx_dex_map_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_string_id_item_fields[] = {
    SX_FIELD("string_data_off","uint32",0,4,SX_OFFSET),
};
const sx_layout sx_dex_string_id_item_le = {0x60030007U,"dex_string_id_item_le",sx_dex_string_id_item_fields,SX_COUNT(sx_dex_string_id_item_fields),SX_LE};
const sx_layout sx_dex_string_id_item_be = {0x60030008U,"dex_string_id_item_be",sx_dex_string_id_item_fields,SX_COUNT(sx_dex_string_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_type_id_item_fields[] = {
    SX_FIELD("descriptor_idx","uint32",0,4,SX_ID),
};
const sx_layout sx_dex_type_id_item_le = {0x60030009U,"dex_type_id_item_le",sx_dex_type_id_item_fields,SX_COUNT(sx_dex_type_id_item_fields),SX_LE};
const sx_layout sx_dex_type_id_item_be = {0x6003000AU,"dex_type_id_item_be",sx_dex_type_id_item_fields,SX_COUNT(sx_dex_type_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_proto_id_item_fields[] = {
    SX_FIELD("shorty_idx","uint32",0,4,SX_ID),
    SX_FIELD("return_type_idx","uint32",4,4,SX_ID),
    SX_FIELD("parameters_off","uint32",8,4,SX_OFFSET),
};
const sx_layout sx_dex_proto_id_item_le = {0x6003000BU,"dex_proto_id_item_le",sx_dex_proto_id_item_fields,SX_COUNT(sx_dex_proto_id_item_fields),SX_LE};
const sx_layout sx_dex_proto_id_item_be = {0x6003000CU,"dex_proto_id_item_be",sx_dex_proto_id_item_fields,SX_COUNT(sx_dex_proto_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_field_id_item_fields[] = {
    SX_FIELD("class_idx","uint16",0,2,SX_ID),
    SX_FIELD("type_idx","uint16",2,2,SX_ID),
    SX_FIELD("name_idx","uint32",4,4,SX_ID),
};
const sx_layout sx_dex_field_id_item_le = {0x6003000DU,"dex_field_id_item_le",sx_dex_field_id_item_fields,SX_COUNT(sx_dex_field_id_item_fields),SX_LE};
const sx_layout sx_dex_field_id_item_be = {0x6003000EU,"dex_field_id_item_be",sx_dex_field_id_item_fields,SX_COUNT(sx_dex_field_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_method_id_item_fields[] = {
    SX_FIELD("class_idx","uint16",0,2,SX_ID),
    SX_FIELD("proto_idx","uint16",2,2,SX_ID),
    SX_FIELD("name_idx","uint32",4,4,SX_ID),
};
const sx_layout sx_dex_method_id_item_le = {0x6003000FU,"dex_method_id_item_le",sx_dex_method_id_item_fields,SX_COUNT(sx_dex_method_id_item_fields),SX_LE};
const sx_layout sx_dex_method_id_item_be = {0x60030010U,"dex_method_id_item_be",sx_dex_method_id_item_fields,SX_COUNT(sx_dex_method_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_class_def_item_fields[] = {
    SX_FIELD("class_idx","uint32",0,4,SX_ID),
    SX_FIELD("access_flags","uint32",4,4,SX_FLAGS),
    SX_FIELD("superclass_idx","uint32",8,4,SX_ID),
    SX_FIELD("interfaces_off","uint32",12,4,SX_OFFSET),
    SX_FIELD("source_file_idx","uint32",16,4,SX_ID),
    SX_FIELD("annotations_off","uint32",20,4,SX_OFFSET),
    SX_FIELD("class_data_off","uint32",24,4,SX_OFFSET),
    SX_FIELD("static_values_off","uint32",28,4,SX_OFFSET),
};
const sx_layout sx_dex_class_def_item_le = {0x60030011U,"dex_class_def_item_le",sx_dex_class_def_item_fields,SX_COUNT(sx_dex_class_def_item_fields),SX_LE};
const sx_layout sx_dex_class_def_item_be = {0x60030012U,"dex_class_def_item_be",sx_dex_class_def_item_fields,SX_COUNT(sx_dex_class_def_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_call_site_id_item_fields[] = {
    SX_FIELD("call_site_off","uint32",0,4,SX_OFFSET),
};
const sx_layout sx_dex_call_site_id_item_le = {0x60030013U,"dex_call_site_id_item_le",sx_dex_call_site_id_item_fields,SX_COUNT(sx_dex_call_site_id_item_fields),SX_LE};
const sx_layout sx_dex_call_site_id_item_be = {0x60030014U,"dex_call_site_id_item_be",sx_dex_call_site_id_item_fields,SX_COUNT(sx_dex_call_site_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_method_handle_item_fields[] = {
    SX_FIELD("method_handle_type","uint16",0,2,SX_ID),
    SX_FIELD("unused1","uint16",2,2,SX_RESERVED),
    SX_FIELD("field_or_method_id","uint16",4,2,SX_ID),
    SX_FIELD("unused2","uint16",6,2,SX_RESERVED),
};
const sx_layout sx_dex_method_handle_item_le = {0x60030015U,"dex_method_handle_item_le",sx_dex_method_handle_item_fields,SX_COUNT(sx_dex_method_handle_item_fields),SX_LE};
const sx_layout sx_dex_method_handle_item_be = {0x60030016U,"dex_method_handle_item_be",sx_dex_method_handle_item_fields,SX_COUNT(sx_dex_method_handle_item_fields),SX_BE};
#define SX_DEX_LAYOUT(n) (be?&sx_##n##_be:&sx_##n##_le)
static bool sx_dex_build(sx_context *c)
{
    uint8_t h[112]; uint32_t map,filesize,header,n;
    bool be;
    const sx_layout *fixed[6];
    const unsigned widths[]={4,4,12,8,8,32};
    if(!sx_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"dex\n",4))return false;
    if(xx_data_get_u32(h,112,40,false)==0x12345678U)be=false;
    else if(xx_data_get_u32(h,112,40,false)==0x78563412U)be=true;else return false;
    filesize=xx_data_get_u32(h,112,32,be);header=xx_data_get_u32(h,112,36,be);
    if(header!=112||filesize<112||filesize>(uint64_t)c->size)return false;
    c->size=filesize;
    if(!sx_add(c,SX_DEX_LAYOUT(dex_header),0,112))return false;
    fixed[0]=SX_DEX_LAYOUT(dex_string_id_item);fixed[1]=SX_DEX_LAYOUT(dex_type_id_item);fixed[2]=SX_DEX_LAYOUT(dex_proto_id_item);
    fixed[3]=SX_DEX_LAYOUT(dex_field_id_item);fixed[4]=SX_DEX_LAYOUT(dex_method_id_item);fixed[5]=SX_DEX_LAYOUT(dex_class_def_item);
    for(unsigned i=0;i<6;i++) {
        n=xx_data_get_u32(h,112,56+i*8,be);
        uint32_t off=xx_data_get_u32(h,112,60+i*8,be);
        if(n&&(!off||!sx_table(c,fixed[i],off,widths[i],n)))return false;
    }
    map=xx_data_get_u32(h,112,52,be);
    if(map) {
        if(!sx_u32(c,map,be,&n)||n>65536||!sx_add(c,SX_DEX_LAYOUT(dex_map_list),map,4)||!sx_table(c,SX_DEX_LAYOUT(dex_map_item),(int64_t)map+4,12,n))return false;
        for(uint32_t i=0;i<n;i++) {
            uint8_t entry[12];uint16_t type;uint32_t count,off;
            if(!sx_read(c,(int64_t)map+4+(int64_t)i*12,entry,12))return false;
            type=xx_data_get_u16(entry,12,0,be);count=xx_data_get_u32(entry,12,4,be);off=xx_data_get_u32(entry,12,8,be);
            if(type==7&&!sx_table(c,SX_DEX_LAYOUT(dex_call_site_id_item),off,4,count))return false;
            if(type==8&&!sx_table(c,SX_DEX_LAYOUT(dex_method_handle_item),off,8,count))return false;
        }
    }
    /* Variable DEX items remain explicit raw data until their individual
     * encoded-value, debug-info and instruction grammars have schemas. */
    n=xx_data_get_u32(h,112,104,be);
    if(n&&!sx_raw(c,xx_data_get_u32(h,112,108,be),n))return false;
    return true;
}
#undef SX_DEX_LAYOUT
bool sx_dex_schema_build(sx_context*c)
{
    return sx_dex_build(c);
}
