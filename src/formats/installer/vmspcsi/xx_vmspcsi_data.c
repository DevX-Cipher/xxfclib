/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VMSPCSI data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_vmspcsi_header_fields[] = {
 SX_FIELD("banner","char[32]",0,32,SX_SIGNATURE),
 SX_FIELD("unknown1","uint8[24]",32,24,SX_NONE),
 SX_FIELD("table_size","uint32",56,4,SX_SIZE),
 SX_FIELD("unknown2","uint8[4]",60,4,SX_NONE),
 SX_FIELD("record_count","uint32",64,4,SX_COUNT_PROP),
 SX_FIELD("unknown3","uint8[12]",68,12,SX_NONE),
};
const sx_layout sxap_vmspcsi_header = {UINT32_C(0x60720043),"vmspcsi_header",sxap_vmspcsi_header_fields,SX_COUNT(sxap_vmspcsi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_table_fields[] = {
 SX_FIELD("table_size","uint32",0,4,SX_SIZE),
 SX_FIELD("reserved1","uint32",4,4,SX_NONE),
 SX_FIELD("magic","uint32",8,4,SX_SIGNATURE),
 SX_FIELD("reserved2","uint32",12,4,SX_NONE),
 SX_FIELD("context_count","uint16",16,2,SX_COUNT_PROP),
 SX_FIELD("header_size","uint16",18,2,SX_SIZE),
};
const sx_layout sxap_vmspcsi_table = {UINT32_C(0x60720044),"vmspcsi_table",sxap_vmspcsi_table_fields,SX_COUNT(sxap_vmspcsi_table_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_context_fields[] = {
 SX_FIELD("block_size","uint16",0,2,SX_SIZE),
 SX_FIELD("first_symbol","uint8",2,1,SX_NONE),
 SX_FIELD("last_symbol","uint8",3,1,SX_NONE),
 SX_FIELD("reserved","uint16",4,2,SX_NONE),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
 SX_FIELD("node_offset","uint16",8,2,SX_OFFSET),
 SX_FIELD("map_offset","uint16",10,2,SX_OFFSET),
};
const sx_layout sxap_vmspcsi_context = {UINT32_C(0x60720045),"vmspcsi_context",sxap_vmspcsi_context_fields,SX_COUNT(sxap_vmspcsi_context_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_bitmap_fields[] = {
 SX_FIELD("leaf_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxap_vmspcsi_bitmap = {UINT32_C(0x60720046),"vmspcsi_bitmap",sxap_vmspcsi_bitmap_fields,SX_COUNT(sxap_vmspcsi_bitmap_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_node_fields[] = {
 SX_FIELD("symbol_or_child","uint8",0,1,SX_NONE),
};
const sx_layout sxap_vmspcsi_node = {UINT32_C(0x60720047),"vmspcsi_node",sxap_vmspcsi_node_fields,SX_COUNT(sxap_vmspcsi_node_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_context_map_fields[] = {
 SX_FIELD("next_context","uint16",0,2,SX_NONE),
};
const sx_layout sxap_vmspcsi_context_map = {UINT32_C(0x60720048),"vmspcsi_context_map",sxap_vmspcsi_context_map_fields,SX_COUNT(sxap_vmspcsi_context_map_fields),SX_LE};
static const xx_data_struct_field_desc sxap_vmspcsi_record_fields[] = {
 SX_FIELD("unknown_record_word","uint16",0,2,SX_NONE),
};
const sx_layout sxap_vmspcsi_record = {UINT32_C(0x60720049),"vmspcsi_record",sxap_vmspcsi_record_fields,SX_COUNT(sxap_vmspcsi_record_fields),SX_LE};
static bool sxap_pcsi(sx_context*c){uint64_t n,p=532;if(!sxap_add(c,&sxap_vmspcsi_header,0)||!sxap_add(c,&sxap_vmspcsi_table,512)||!sxap_word(c,528,2,false,&n))return false;for(uint64_t i=0;i<n;i++){uint8_t h[12];if(!sxap_read(c,p,h,12)||!sxap_add(c,&sxap_vmspcsi_context,p))return false;uint64_t z=sxap_uint(h,2,false),nodes=sxap_uint(h+8,2,false),map=sxap_uint(h+10,2,false),node_end=map?map:z;if(z<12||nodes<=12||node_end<nodes||node_end>z||!sxap_span(c,p,z))return true;if(!sxap_table(c,&sxap_vmspcsi_bitmap,p+12,1,nodes-12)||!sxap_table(c,&sxap_vmspcsi_node,p+nodes,1,node_end-nodes))return false;if(map&&(z-map)%2==0&&!sxap_table(c,&sxap_vmspcsi_context_map,p+map,2,(z-map)/2))return false;p+=z;}p=(p+511)&~UINT64_C(511);return !sxap_span(c,p,2)||sxap_add(c,&sxap_vmspcsi_record,p);}
bool sx_vmspcsi_build(sx_context*c)
{
 return sxap_pcsi(c);
}
