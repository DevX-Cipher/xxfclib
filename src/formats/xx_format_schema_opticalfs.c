/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ISO9660 ECMA-119 and UDF ECMA-167 physical metadata.
 * Logical block numbers retain their physical units. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_opticalfs.h"

static const xx_data_struct_field_desc sxo_iso_directory_record_fields[] = {
    SX_FIELD("record_length", "uint8", 0, 1, SX_SIZE),
    SX_FIELD("extended_attribute_blocks", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("extent_lba_le", "uint32", 2, 4, SX_NONE),
    SX_FIELD("extent_lba_be", "uint32be", 6, 4, SX_NONE),
    SX_FIELD("data_length_le", "uint32", 10, 4, SX_SIZE),
    SX_FIELD("data_length_be", "uint32be", 14, 4, SX_SIZE),
    SX_FIELD("recorded_year_since_1900", "uint8", 18, 1, SX_NONE),
    SX_FIELD("recorded_month", "uint8", 19, 1, SX_NONE),
    SX_FIELD("recorded_day", "uint8", 20, 1, SX_NONE),
    SX_FIELD("recorded_hour", "uint8", 21, 1, SX_NONE),
    SX_FIELD("recorded_minute", "uint8", 22, 1, SX_NONE),
    SX_FIELD("recorded_second", "uint8", 23, 1, SX_NONE),
    SX_FIELD("recorded_timezone_quarters", "int8", 24, 1, SX_NONE),
    SX_FIELD("flags", "uint8", 25, 1, SX_FLAGS),
    SX_FIELD("file_unit_blocks", "uint8", 26, 1, SX_COUNT_PROP),
    SX_FIELD("interleave_gap_blocks", "uint8", 27, 1, SX_COUNT_PROP),
    SX_FIELD("volume_sequence_le", "uint16", 28, 2, SX_NONE),
    SX_FIELD("volume_sequence_be", "uint16be", 30, 2, SX_NONE),
    SX_FIELD("identifier_length", "uint8", 32, 1, SX_SIZE),
};
const sx_layout sxo_iso_directory_record = {UINT32_C(0x60130001),"iso_directory_record",sxo_iso_directory_record_fields,SX_COUNT(sxo_iso_directory_record_fields),SX_LE};
static const xx_data_struct_field_desc sxo_iso_volume_descriptor_header_fields[] = {
    SX_FIELD("descriptor_type", "uint8", 0, 1, SX_ID),
    SX_FIELD("standard_identifier", "char[5]", 1, 5, SX_SIGNATURE),
    SX_FIELD("descriptor_version", "uint8", 6, 1, SX_ID),
};
const sx_layout sxo_iso_volume_descriptor_header = {UINT32_C(0x60130009),"iso_volume_descriptor_header",sxo_iso_volume_descriptor_header_fields,SX_COUNT(sxo_iso_volume_descriptor_header_fields),SX_LE};
static const xx_data_struct_field_desc sxo_hfsplus_volume_header_fields[] = {
    SX_FIELD("signature", "uint16", 0, 2, SX_SIGNATURE),
    SX_FIELD("version", "uint16", 2, 2, SX_ID),
    SX_FIELD("attributes", "uint32", 4, 4, SX_FLAGS),
    SX_FIELD("last_mounted_version", "uint32", 8, 4, SX_ID),
    SX_FIELD("journal_info_block", "uint32", 12, 4, SX_NONE),
    SX_FIELD("create_date", "uint32", 16, 4, SX_TIME),
    SX_FIELD("modify_date", "uint32", 20, 4, SX_TIME),
    SX_FIELD("backup_date", "uint32", 24, 4, SX_TIME),
    SX_FIELD("checked_date", "uint32", 28, 4, SX_TIME),
    SX_FIELD("file_count", "uint32", 32, 4, SX_COUNT_PROP),
    SX_FIELD("folder_count", "uint32", 36, 4, SX_COUNT_PROP),
    SX_FIELD("block_size", "uint32", 40, 4, SX_SIZE),
    SX_FIELD("total_blocks", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("free_blocks", "uint32", 48, 4, SX_COUNT_PROP),
    SX_FIELD("next_allocation_block", "uint32", 52, 4, SX_NONE),
    SX_FIELD("resource_clump_size", "uint32", 56, 4, SX_SIZE),
    SX_FIELD("data_clump_size", "uint32", 60, 4, SX_SIZE),
    SX_FIELD("next_catalog_id", "uint32", 64, 4, SX_ID),
    SX_FIELD("write_count", "uint32", 68, 4, SX_COUNT_PROP),
    SX_FIELD("encodings_bitmap", "uint64", 72, 8, SX_FLAGS),
    SX_FIELD("finder_info0", "uint32", 80, 4, SX_NONE),
    SX_FIELD("finder_info1", "uint32", 84, 4, SX_NONE),
    SX_FIELD("finder_info2", "uint32", 88, 4, SX_NONE),
    SX_FIELD("finder_info3", "uint32", 92, 4, SX_NONE),
    SX_FIELD("finder_info4", "uint32", 96, 4, SX_NONE),
    SX_FIELD("finder_info5", "uint32", 100, 4, SX_NONE),
    SX_FIELD("finder_info6", "uint32", 104, 4, SX_NONE),
    SX_FIELD("finder_info7", "uint32", 108, 4, SX_NONE),
    SX_FIELD("allocation_logical_size", "uint64", 112, 8, SX_SIZE),
    SX_FIELD("allocation_clump_size", "uint32", 120, 4, SX_SIZE),
    SX_FIELD("allocation_total_blocks", "uint32", 124, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent0_start_block", "uint32", 128, 4, SX_NONE),
    SX_FIELD("allocation_extent0_block_count", "uint32", 132, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent1_start_block", "uint32", 136, 4, SX_NONE),
    SX_FIELD("allocation_extent1_block_count", "uint32", 140, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent2_start_block", "uint32", 144, 4, SX_NONE),
    SX_FIELD("allocation_extent2_block_count", "uint32", 148, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent3_start_block", "uint32", 152, 4, SX_NONE),
    SX_FIELD("allocation_extent3_block_count", "uint32", 156, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent4_start_block", "uint32", 160, 4, SX_NONE),
    SX_FIELD("allocation_extent4_block_count", "uint32", 164, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent5_start_block", "uint32", 168, 4, SX_NONE),
    SX_FIELD("allocation_extent5_block_count", "uint32", 172, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent6_start_block", "uint32", 176, 4, SX_NONE),
    SX_FIELD("allocation_extent6_block_count", "uint32", 180, 4, SX_COUNT_PROP),
    SX_FIELD("allocation_extent7_start_block", "uint32", 184, 4, SX_NONE),
    SX_FIELD("allocation_extent7_block_count", "uint32", 188, 4, SX_COUNT_PROP),
    SX_FIELD("extents_logical_size", "uint64", 192, 8, SX_SIZE),
    SX_FIELD("extents_clump_size", "uint32", 200, 4, SX_SIZE),
    SX_FIELD("extents_total_blocks", "uint32", 204, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent0_start_block", "uint32", 208, 4, SX_NONE),
    SX_FIELD("extents_extent0_block_count", "uint32", 212, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent1_start_block", "uint32", 216, 4, SX_NONE),
    SX_FIELD("extents_extent1_block_count", "uint32", 220, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent2_start_block", "uint32", 224, 4, SX_NONE),
    SX_FIELD("extents_extent2_block_count", "uint32", 228, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent3_start_block", "uint32", 232, 4, SX_NONE),
    SX_FIELD("extents_extent3_block_count", "uint32", 236, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent4_start_block", "uint32", 240, 4, SX_NONE),
    SX_FIELD("extents_extent4_block_count", "uint32", 244, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent5_start_block", "uint32", 248, 4, SX_NONE),
    SX_FIELD("extents_extent5_block_count", "uint32", 252, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent6_start_block", "uint32", 256, 4, SX_NONE),
    SX_FIELD("extents_extent6_block_count", "uint32", 260, 4, SX_COUNT_PROP),
    SX_FIELD("extents_extent7_start_block", "uint32", 264, 4, SX_NONE),
    SX_FIELD("extents_extent7_block_count", "uint32", 268, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_logical_size", "uint64", 272, 8, SX_SIZE),
    SX_FIELD("catalog_clump_size", "uint32", 280, 4, SX_SIZE),
    SX_FIELD("catalog_total_blocks", "uint32", 284, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent0_start_block", "uint32", 288, 4, SX_NONE),
    SX_FIELD("catalog_extent0_block_count", "uint32", 292, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent1_start_block", "uint32", 296, 4, SX_NONE),
    SX_FIELD("catalog_extent1_block_count", "uint32", 300, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent2_start_block", "uint32", 304, 4, SX_NONE),
    SX_FIELD("catalog_extent2_block_count", "uint32", 308, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent3_start_block", "uint32", 312, 4, SX_NONE),
    SX_FIELD("catalog_extent3_block_count", "uint32", 316, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent4_start_block", "uint32", 320, 4, SX_NONE),
    SX_FIELD("catalog_extent4_block_count", "uint32", 324, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent5_start_block", "uint32", 328, 4, SX_NONE),
    SX_FIELD("catalog_extent5_block_count", "uint32", 332, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent6_start_block", "uint32", 336, 4, SX_NONE),
    SX_FIELD("catalog_extent6_block_count", "uint32", 340, 4, SX_COUNT_PROP),
    SX_FIELD("catalog_extent7_start_block", "uint32", 344, 4, SX_NONE),
    SX_FIELD("catalog_extent7_block_count", "uint32", 348, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_logical_size", "uint64", 352, 8, SX_SIZE),
    SX_FIELD("attributes_clump_size", "uint32", 360, 4, SX_SIZE),
    SX_FIELD("attributes_total_blocks", "uint32", 364, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent0_start_block", "uint32", 368, 4, SX_NONE),
    SX_FIELD("attributes_extent0_block_count", "uint32", 372, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent1_start_block", "uint32", 376, 4, SX_NONE),
    SX_FIELD("attributes_extent1_block_count", "uint32", 380, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent2_start_block", "uint32", 384, 4, SX_NONE),
    SX_FIELD("attributes_extent2_block_count", "uint32", 388, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent3_start_block", "uint32", 392, 4, SX_NONE),
    SX_FIELD("attributes_extent3_block_count", "uint32", 396, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent4_start_block", "uint32", 400, 4, SX_NONE),
    SX_FIELD("attributes_extent4_block_count", "uint32", 404, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent5_start_block", "uint32", 408, 4, SX_NONE),
    SX_FIELD("attributes_extent5_block_count", "uint32", 412, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent6_start_block", "uint32", 416, 4, SX_NONE),
    SX_FIELD("attributes_extent6_block_count", "uint32", 420, 4, SX_COUNT_PROP),
    SX_FIELD("attributes_extent7_start_block", "uint32", 424, 4, SX_NONE),
    SX_FIELD("attributes_extent7_block_count", "uint32", 428, 4, SX_COUNT_PROP),
    SX_FIELD("startup_logical_size", "uint64", 432, 8, SX_SIZE),
    SX_FIELD("startup_clump_size", "uint32", 440, 4, SX_SIZE),
    SX_FIELD("startup_total_blocks", "uint32", 444, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent0_start_block", "uint32", 448, 4, SX_NONE),
    SX_FIELD("startup_extent0_block_count", "uint32", 452, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent1_start_block", "uint32", 456, 4, SX_NONE),
    SX_FIELD("startup_extent1_block_count", "uint32", 460, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent2_start_block", "uint32", 464, 4, SX_NONE),
    SX_FIELD("startup_extent2_block_count", "uint32", 468, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent3_start_block", "uint32", 472, 4, SX_NONE),
    SX_FIELD("startup_extent3_block_count", "uint32", 476, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent4_start_block", "uint32", 480, 4, SX_NONE),
    SX_FIELD("startup_extent4_block_count", "uint32", 484, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent5_start_block", "uint32", 488, 4, SX_NONE),
    SX_FIELD("startup_extent5_block_count", "uint32", 492, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent6_start_block", "uint32", 496, 4, SX_NONE),
    SX_FIELD("startup_extent6_block_count", "uint32", 500, 4, SX_COUNT_PROP),
    SX_FIELD("startup_extent7_start_block", "uint32", 504, 4, SX_NONE),
    SX_FIELD("startup_extent7_block_count", "uint32", 508, 4, SX_COUNT_PROP),
};
const sx_layout sxo_hfsplus_volume_header = {UINT32_C(0x6013001A),"hfsplus_volume_header",sxo_hfsplus_volume_header_fields,SX_COUNT(sxo_hfsplus_volume_header_fields),SX_BE};
static const xx_data_struct_field_desc sxo_hfsplus_btree_node_descriptor_fields[] = {
    SX_FIELD("forward_link", "uint32", 0, 4, SX_NONE),
    SX_FIELD("backward_link", "uint32", 4, 4, SX_NONE),
    SX_FIELD("kind", "int8", 8, 1, SX_ID),
    SX_FIELD("height", "uint8", 9, 1, SX_NONE),
    SX_FIELD("record_count", "uint16", 10, 2, SX_COUNT_PROP),
    SX_FIELD("reserved", "uint16", 12, 2, SX_RESERVED),
};
const sx_layout sxo_hfsplus_btree_node_descriptor = {UINT32_C(0x6013001B),"hfsplus_btree_node_descriptor",sxo_hfsplus_btree_node_descriptor_fields,SX_COUNT(sxo_hfsplus_btree_node_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxo_hfsplus_catalog_thread_fields[] = {
    SX_FIELD("record_type", "int16", 0, 2, SX_ID),
    SX_FIELD("reserved", "int16", 2, 2, SX_RESERVED),
    SX_FIELD("parent_id", "uint32", 4, 4, SX_ID),
    SX_FIELD("name_code_units", "uint16", 8, 2, SX_COUNT_PROP),
};
const sx_layout sxo_hfsplus_catalog_thread = {UINT32_C(0x60130021),"hfsplus_catalog_thread",sxo_hfsplus_catalog_thread_fields,SX_COUNT(sxo_hfsplus_catalog_thread_fields),SX_BE};
static const sx_layout *const sx_opticalfs_layouts[] = {
    &sxo_iso_directory_record,
    &sxo_iso_path_table_l,
    &sxo_iso_path_table_m,
    &sxo_iso_primary_volume_descriptor,
    &sxo_iso_supplementary_volume_descriptor,
    &sxo_iso_boot_record,
    &sxo_iso_volume_partition_descriptor,
    &sxo_iso_volume_descriptor_terminator,
    &sxo_iso_volume_descriptor_header,
    &sxo_udf_volume_recognition_descriptor,
    &sxo_udf_descriptor_tag,
    &sxo_udf_anchor_volume_descriptor,
    &sxo_udf_primary_volume_descriptor,
    &sxo_udf_partition_descriptor,
    &sxo_udf_logical_volume_descriptor,
    &sxo_udf_partition_map_type1,
    &sxo_udf_partition_map_header,
    &sxo_udf_terminating_descriptor,
    &sxo_udf_file_set_descriptor,
    &sxo_udf_file_entry,
    &sxo_udf_extended_file_entry,
    &sxo_udf_file_identifier_descriptor,
    &sxo_udf_short_allocation_descriptor,
    &sxo_udf_long_allocation_descriptor,
    &sxo_udf_extended_allocation_descriptor,
    &sxo_hfsplus_volume_header,
    &sxo_hfsplus_btree_node_descriptor,
    &sxo_hfsplus_btree_header,
    &sxo_hfsplus_btree_record_offset,
    &sxo_hfsplus_catalog_key,
    &sxo_hfsplus_catalog_folder,
    &sxo_hfsplus_catalog_file,
    &sxo_hfsplus_catalog_thread,
};
static bool sx_opticalfs_supports(xx_file_type_t t){return t==XX_FILE_TYPE_ISO9660||t==XX_FILE_TYPE_UDF||t==XX_FILE_TYPE_HFSPLUS;}
uint32_t sxo_u32(const uint8_t *p){return xx_data_get_u32(p,4,0,false);}
uint16_t sxo_u16(const uint8_t *p){return xx_data_get_u16(p,2,0,false);}
bool sxo_can(sx_context *c,int64_t at,uint64_t n){return at>=0&&at<=c->size&&n<=(uint64_t)(c->size-at)&&!xx_pd_is_stopped(c->pd);}
bool sxo_add(sx_context *c,const sx_layout *l,int64_t at,int64_t n)
{
    if(n<=0||!sxo_can(c,at,(uint64_t)n)||at>INT64_MAX-c->f->base_address)return false;
    for(size_t i=0;i<c->count;i++)if(c->items[i].offset==c->f->base_address+at&&c->items[i].id==l->id&&c->items[i].total_size==n)return true;
    return sx_add(c,l,at,n);
}
static bool sxo_finish(sx_context *c)
{
    size_t count=c->count;int64_t end=0;
    for(size_t i=1;i<count;i++){xx_data_struct d=c->items[i];size_t j=i;while(j&&c->items[j-1].offset>d.offset){c->items[j]=c->items[j-1];j--;}c->items[j]=d;}
    for(size_t i=0;i<count;i++){int64_t at=c->items[i].offset-c->f->base_address,n=c->items[i].total_size;if(at<end)return false;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+n;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    for(size_t i=1;i<c->count;i++){xx_data_struct d=c->items[i];size_t j=i;while(j&&c->items[j-1].offset>d.offset){c->items[j]=c->items[j-1];j--;}c->items[j]=d;}
    return !c->failed;
}
static bool sx_opticalfs_build(sx_context *c)
{
    if(!c->f->handle_base_info||!xx_format_handle_base_info(c->f,c->pd)||!c->f->is_valid)return false;
    bool ok=c->f->file_type==XX_FILE_TYPE_ISO9660?sx_iso9660_build(c):c->f->file_type==XX_FILE_TYPE_UDF?sx_udf_build(c):c->f->file_type==XX_FILE_TYPE_HFSPLUS?sx_hfsplus_build(c):false;
    return ok&&c->count&&sxo_finish(c);
}
static bool sxo_has(const wchar_t *s,const wchar_t *p){size_t n=xx_rt_wcslen(p);for(;*s;s++)if(!xx_rt_wcsncmp(s,p,n))return true;return false;}
static bool sx_opticalfs_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x60130000)||id>=UINT32_C(0x60140000))return true;
    const wchar_t *n=r->name,*text=NULL;uint64_t v=xx_var_get_u64(&r->value);
    if(sxo_has(n,L"_lba")||sxo_has(n,L"_location")||sxo_has(n,L"logical_block")||!xx_rt_wcscmp(n,L"starting_location"))text=L"Logical block number; byte position depends on the volume or partition origin and logical block size";
    if(sxo_has(n,L"_blocks")||sxo_has(n,L"logical_blocks_recorded"))text=L"Logical blocks, not bytes; multiply by the logical block size";
    if(sxo_has(n,L"timezone_quarters"))text=L"Signed offset from UTC in 15-minute units";
    if(sxo_has(n,L"type_timezone"))text=L"High 4 bits: timestamp type; low 12 bits: signed UTC offset in minutes (0x801 means unspecified)";
    if(sxo_has(n,L"extent_length_flags"))text=L"Bits 0..29: extent length in bytes; bits 30..31: recorded, allocated/unrecorded, unallocated, or continuation";
    if(!xx_rt_wcscmp(n,L"descriptor_type"))text=v==0?L"BOOT_RECORD":v==1?L"PRIMARY_VOLUME_DESCRIPTOR":v==2?L"SUPPLEMENTARY_VOLUME_DESCRIPTOR":v==3?L"VOLUME_PARTITION_DESCRIPTOR":v==255?L"VOLUME_DESCRIPTOR_SET_TERMINATOR":NULL;
    if(!xx_rt_wcscmp(n,L"tag_identifier"))text=v==1?L"PRIMARY_VOLUME_DESCRIPTOR":v==2?L"ANCHOR_VOLUME_DESCRIPTOR_POINTER":v==5?L"PARTITION_DESCRIPTOR":v==6?L"LOGICAL_VOLUME_DESCRIPTOR":v==8?L"TERMINATING_DESCRIPTOR":v==256?L"FILE_SET_DESCRIPTOR":v==257?L"FILE_IDENTIFIER_DESCRIPTOR":v==261?L"FILE_ENTRY":v==266?L"EXTENDED_FILE_ENTRY":NULL;
    if(!xx_rt_wcscmp(n,L"icb_flags"))text=L"Bits 0..2: short/long/extended/embedded allocation descriptors; bit 3 sorted, bit 4 non-relocatable, bit 9 contiguous, bit 12 multiple versions";
    if(!xx_rt_wcscmp(n,L"file_characteristics"))text=L"Bits: 0 hidden, 1 directory, 2 deleted, 3 parent, 4 metadata";
    if((id==sxo_iso_directory_record.id&&!xx_rt_wcscmp(n,L"flags"))||sxo_has(n,L"root_flags"))text=L"Bits: 0 hidden, 1 directory, 2 associated, 3 record, 4 protection, 7 multiple extents";
    if(id<sxo_hfsplus_volume_header.id&&!xx_rt_wcscmp(n,L"file_type"))text=v==4?L"DIRECTORY":v==5?L"REGULAR_FILE":v==12?L"SYMBOLIC_LINK":NULL;
    if(id>=sxo_hfsplus_volume_header.id&&id<=sxo_hfsplus_catalog_thread.id){
        if(sxo_has(n,L"_block")||sxo_has(n,L"_blocks"))text=L"Allocation block units; byte position or length = value * volume block size";
        if(sxo_has(n,L"_node")||!xx_rt_wcscmp(n,L"forward_link")||!xx_rt_wcscmp(n,L"backward_link"))text=L"B-tree node number; byte position within the special file = value * node size";
        if(!xx_rt_wcscmp(n,L"total_nodes")||!xx_rt_wcscmp(n,L"free_nodes"))text=L"Count of B-tree nodes";
        if(!xx_rt_wcscmp(n,L"file_type")||!xx_rt_wcscmp(n,L"file_creator")||!xx_rt_wcscmp(n,L"last_mounted_version"))text=L"Four-character code stored as a big-endian 32-bit integer";
        if(id==sxo_hfsplus_volume_header.id&&!xx_rt_wcscmp(n,L"signature"))text=v==0x482b?L"HFS_PLUS_SIGNATURE":v==0x4858?L"HFSX_SIGNATURE":NULL;
        if(sxo_has(n,L"_date"))text=L"Seconds since 1904-01-01 (HFS epoch)";
        if(!xx_rt_wcscmp(n,L"record_type"))text=v==1?L"HFS_PLUS_FOLDER_RECORD":v==2?L"HFS_PLUS_FILE_RECORD":v==3?L"HFS_PLUS_FOLDER_THREAD_RECORD":v==4?L"HFS_PLUS_FILE_THREAD_RECORD":NULL;
        if(id==sxo_hfsplus_btree_node_descriptor.id&&!xx_rt_wcscmp(n,L"kind"))text=xx_var_get_i64(&r->value)==-1?L"LEAF_NODE":v==0?L"INDEX_NODE":v==1?L"HEADER_NODE":v==2?L"MAP_NODE":NULL;
        if(id==sxo_hfsplus_volume_header.id&&!xx_rt_wcscmp(n,L"attributes"))text=L"Bit 8: unmounted cleanly; bit 9: spared blocks; bit 11: inconsistent; bit 13: journaled; bit 15: software locked";
    }
    return !text||xx_data_struct_record_set_comment(r,text);
}
const sx_family sx_opticalfs_family={sx_opticalfs_supports,sx_opticalfs_build,sx_opticalfs_layouts,SX_COUNT(sx_opticalfs_layouts),sx_opticalfs_comment};
