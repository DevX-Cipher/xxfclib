/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical classic filesystem metadata; encoded payload remains raw.
 * Scope and sources: docs/data_struct_retrofs_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_retrofs.h"
static const xx_data_struct_field_desc sxrfs_apple_dos_vtoc_fields[] = {
    SX_FIELD("unused0","uint8",0,1,SX_RESERVED),
    SX_FIELD("catalog_track","uint8",1,1,SX_NONE),
    SX_FIELD("catalog_sector","uint8",2,1,SX_NONE),
    SX_FIELD("dos_release","uint8",3,1,SX_ID),
    SX_FIELD("unused4","byte[2]",4,2,SX_RESERVED),
    SX_FIELD("volume_number","uint8",6,1,SX_ID),
    SX_FIELD("unused7","byte[32]",7,32,SX_RESERVED),
    SX_FIELD("maximum_ts_pairs","uint8",39,1,SX_COUNT_PROP),
    SX_FIELD("unused40","byte[8]",40,8,SX_RESERVED),
    SX_FIELD("last_allocated_track","uint8",48,1,SX_NONE),
    SX_FIELD("allocation_direction","int8",49,1,SX_NONE),
    SX_FIELD("unused50","byte[2]",50,2,SX_RESERVED),
    SX_FIELD("track_count","uint8",52,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",53,1,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint16",54,2,SX_SIZE),
};
static const sx_layout sxrfs_apple_dos_vtoc = {0x6065000bU,"apple_dos_vtoc",sxrfs_apple_dos_vtoc_fields,SX_COUNT(sxrfs_apple_dos_vtoc_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_apple_dos_bitmap_fields[] = {
    SX_FIELD("free_sector_bits","byte[4]",0,4,SX_FLAGS),
};
static const sx_layout sxrfs_apple_dos_bitmap = {0x6065000cU,"apple_dos_bitmap",sxrfs_apple_dos_bitmap_fields,SX_COUNT(sxrfs_apple_dos_bitmap_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_apple_dos_catalog_header_fields[] = {
    SX_FIELD("unused0","uint8",0,1,SX_RESERVED),
    SX_FIELD("next_track","uint8",1,1,SX_NONE),
    SX_FIELD("next_sector","uint8",2,1,SX_NONE),
    SX_FIELD("unused3","byte[8]",3,8,SX_RESERVED),
};
static const sx_layout sxrfs_apple_dos_catalog_header = {0x6065000dU,"apple_dos_catalog_header",sxrfs_apple_dos_catalog_header_fields,SX_COUNT(sxrfs_apple_dos_catalog_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_apple_dos_file_entry_fields[] = {
    SX_FIELD("ts_list_track","uint8",0,1,SX_NONE),
    SX_FIELD("ts_list_sector","uint8",1,1,SX_NONE),
    SX_FIELD("file_type_and_lock","uint8",2,1,SX_FLAGS),
    SX_FIELD("high_bit_name","byte[30]",3,30,SX_NONE),
    SX_FIELD("sector_count","uint16",33,2,SX_COUNT_PROP),
};
static const sx_layout sxrfs_apple_dos_file_entry = {0x6065000eU,"apple_dos_file_entry",sxrfs_apple_dos_file_entry_fields,SX_COUNT(sxrfs_apple_dos_file_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_apple_dos_ts_header_fields[] = {
    SX_FIELD("unused0","uint8",0,1,SX_RESERVED),
    SX_FIELD("next_track","uint8",1,1,SX_NONE),
    SX_FIELD("next_sector","uint8",2,1,SX_NONE),
    SX_FIELD("unused3","byte[2]",3,2,SX_RESERVED),
    SX_FIELD("first_file_sector_index","uint16",5,2,SX_NONE),
    SX_FIELD("unused7","byte[5]",7,5,SX_RESERVED),
};
static const sx_layout sxrfs_apple_dos_ts_header = {0x6065000fU,"apple_dos_ts_header",sxrfs_apple_dos_ts_header_fields,SX_COUNT(sxrfs_apple_dos_ts_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_apple_dos_ts_pair_fields[] = {
    SX_FIELD("track","uint8",0,1,SX_NONE),
    SX_FIELD("sector","uint8",1,1,SX_NONE),
};
static const sx_layout sxrfs_apple_dos_ts_pair = {0x60650010U,"apple_dos_ts_pair",sxrfs_apple_dos_ts_pair_fields,SX_COUNT(sxrfs_apple_dos_ts_pair_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_sector_link_fields[] = {
    SX_FIELD("next_track","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector_or_last_byte","uint8",1,1,SX_NONE),
};
static const sx_layout sxrfs_cbm_sector_link = {0x60650029U,"cbm_sector_link",sxrfs_cbm_sector_link_fields,SX_COUNT(sxrfs_cbm_sector_link_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_directory_entry_fields[] = {
    SX_FIELD("file_type_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("first_track","uint8",1,1,SX_NONE),
    SX_FIELD("first_sector","uint8",2,1,SX_NONE),
    SX_FIELD("name_petscii","byte[16]",3,16,SX_NONE),
    SX_FIELD("rel_side_track","uint8",19,1,SX_NONE),
    SX_FIELD("rel_side_sector","uint8",20,1,SX_NONE),
    SX_FIELD("record_length","uint8",21,1,SX_SIZE),
    SX_FIELD("reserved","byte[6]",22,6,SX_RESERVED),
    SX_FIELD("block_count","uint16",28,2,SX_COUNT_PROP),
};
static const sx_layout sxrfs_cbm_directory_entry = {0x6065002aU,"cbm_directory_entry",sxrfs_cbm_directory_entry_fields,SX_COUNT(sxrfs_cbm_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_d64_bam_header_fields[] = {
    SX_FIELD("directory_track","uint8",0,1,SX_NONE),
    SX_FIELD("directory_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("double_sided_flag","uint8",3,1,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_d64_bam_header = {0x6065002bU,"cbm_d64_bam_header",sxrfs_cbm_d64_bam_header_fields,SX_COUNT(sxrfs_cbm_d64_bam_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_bam_entry3_fields[] = {
    SX_FIELD("free_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("free_sector_bits","byte[3]",1,3,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_bam_entry3 = {0x6065002cU,"cbm_bam_entry3",sxrfs_cbm_bam_entry3_fields,SX_COUNT(sxrfs_cbm_bam_entry3_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_bam_entry4_fields[] = {
    SX_FIELD("free_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("free_sector_bits","byte[4]",1,4,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_bam_entry4 = {0x6065002dU,"cbm_bam_entry4",sxrfs_cbm_bam_entry4_fields,SX_COUNT(sxrfs_cbm_bam_entry4_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_bam_entry5_fields[] = {
    SX_FIELD("free_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("free_sector_bits","byte[5]",1,5,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_bam_entry5 = {0x6065002eU,"cbm_bam_entry5",sxrfs_cbm_bam_entry5_fields,SX_COUNT(sxrfs_cbm_bam_entry5_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_bitmap3_fields[] = {
    SX_FIELD("free_sector_bits","byte[3]",0,3,SX_FLAGS),
};
static const sx_layout sxrfs_cbm_bitmap3 = {0x6065002fU,"cbm_bitmap3",sxrfs_cbm_bitmap3_fields,SX_COUNT(sxrfs_cbm_bitmap3_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_free_count_fields[] = {
    SX_FIELD("free_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxrfs_cbm_free_count = {0x60650030U,"cbm_free_count",sxrfs_cbm_free_count_fields,SX_COUNT(sxrfs_cbm_free_count_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_d64_disk_identity_fields[] = {
    SX_FIELD("disk_name_petscii","byte[16]",0,16,SX_NONE),
    SX_FIELD("padding","byte[2]",16,2,SX_RESERVED),
    SX_FIELD("disk_id","byte[2]",18,2,SX_ID),
    SX_FIELD("padding164","uint8",20,1,SX_RESERVED),
    SX_FIELD("dos_type","byte[2]",21,2,SX_ID),
    SX_FIELD("padding167","byte[4]",23,4,SX_RESERVED),
};
static const sx_layout sxrfs_cbm_d64_disk_identity = {0x60650031U,"cbm_d64_disk_identity",sxrfs_cbm_d64_disk_identity_fields,SX_COUNT(sxrfs_cbm_d64_disk_identity_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_d81_header_fields[] = {
    SX_FIELD("directory_track","uint8",0,1,SX_NONE),
    SX_FIELD("directory_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved3","uint8",3,1,SX_RESERVED),
    SX_FIELD("disk_name_petscii","byte[16]",4,16,SX_NONE),
    SX_FIELD("padding20","byte[2]",20,2,SX_RESERVED),
    SX_FIELD("disk_id","byte[2]",22,2,SX_ID),
    SX_FIELD("padding24","uint8",24,1,SX_RESERVED),
    SX_FIELD("dos_type","byte[2]",25,2,SX_ID),
};
static const sx_layout sxrfs_cbm_d81_header = {0x60650032U,"cbm_d81_header",sxrfs_cbm_d81_header_fields,SX_COUNT(sxrfs_cbm_d81_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_d81_bam_header_fields[] = {
    SX_FIELD("next_track","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("version_complement","uint8",3,1,SX_NONE),
    SX_FIELD("disk_id","byte[2]",4,2,SX_ID),
    SX_FIELD("io_flags","uint8",6,1,SX_FLAGS),
    SX_FIELD("autoboot","uint8",7,1,SX_FLAGS),
    SX_FIELD("reserved","byte[8]",8,8,SX_RESERVED),
};
static const sx_layout sxrfs_cbm_d81_bam_header = {0x60650033U,"cbm_d81_bam_header",sxrfs_cbm_d81_bam_header_fields,SX_COUNT(sxrfs_cbm_d81_bam_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_d8x_header_fields[] = {
    SX_FIELD("bam_track","uint8",0,1,SX_NONE),
    SX_FIELD("bam_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved3","byte[3]",3,3,SX_RESERVED),
    SX_FIELD("disk_name_petscii","byte[16]",6,16,SX_NONE),
    SX_FIELD("padding22","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("disk_id","byte[2]",24,2,SX_ID),
    SX_FIELD("padding26","uint8",26,1,SX_RESERVED),
    SX_FIELD("dos_type","byte[2]",27,2,SX_ID),
};
static const sx_layout sxrfs_cbm_d8x_header = {0x60650034U,"cbm_d8x_header",sxrfs_cbm_d8x_header_fields,SX_COUNT(sxrfs_cbm_d8x_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_d8x_bam_header_fields[] = {
    SX_FIELD("next_track","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector","uint8",1,1,SX_NONE),
    SX_FIELD("dos_version","uint8",2,1,SX_ID),
    SX_FIELD("reserved3","uint8",3,1,SX_RESERVED),
    SX_FIELD("first_track","uint8",4,1,SX_NONE),
    SX_FIELD("end_track","uint8",5,1,SX_NONE),
};
static const sx_layout sxrfs_cbm_d8x_bam_header = {0x60650035U,"cbm_d8x_bam_header",sxrfs_cbm_d8x_bam_header_fields,SX_COUNT(sxrfs_cbm_d8x_bam_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_d90_config_fields[] = {
    SX_FIELD("bad_sector_track","uint8",0,1,SX_NONE),
    SX_FIELD("bad_sector_number","uint8",1,1,SX_NONE),
    SX_FIELD("reserved2","uint8",2,1,SX_RESERVED),
    SX_FIELD("reserved3","uint8",3,1,SX_RESERVED),
    SX_FIELD("directory_track","uint8",4,1,SX_NONE),
    SX_FIELD("directory_sector","uint8",5,1,SX_NONE),
    SX_FIELD("header_track","uint8",6,1,SX_NONE),
    SX_FIELD("header_sector","uint8",7,1,SX_NONE),
    SX_FIELD("bam_track","uint8",8,1,SX_NONE),
    SX_FIELD("bam_sector","uint8",9,1,SX_NONE),
    SX_FIELD("disk_id","byte[2]",10,2,SX_ID),
};
static const sx_layout sxrfs_cbm_d90_config = {0x60650036U,"cbm_d90_config",sxrfs_cbm_d90_config_fields,SX_COUNT(sxrfs_cbm_d90_config_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_d90_header_fields[] = {
    SX_FIELD("directory_track","uint8",0,1,SX_NONE),
    SX_FIELD("directory_sector","uint8",1,1,SX_NONE),
    SX_FIELD("reserved2","byte[4]",2,4,SX_RESERVED),
    SX_FIELD("disk_name_petscii","byte[16]",6,16,SX_NONE),
    SX_FIELD("padding22","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("disk_id","byte[2]",24,2,SX_ID),
    SX_FIELD("padding26","uint8",26,1,SX_RESERVED),
    SX_FIELD("dos_type","byte[2]",27,2,SX_ID),
};
static const sx_layout sxrfs_cbm_d90_header = {0x60650037U,"cbm_d90_header",sxrfs_cbm_d90_header_fields,SX_COUNT(sxrfs_cbm_d90_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_cbm_d90_bam_header_fields[] = {
    SX_FIELD("next_track","uint8",0,1,SX_NONE),
    SX_FIELD("next_sector","uint8",1,1,SX_NONE),
    SX_FIELD("previous_track","uint8",2,1,SX_NONE),
    SX_FIELD("previous_sector","uint8",3,1,SX_NONE),
    SX_FIELD("first_track","uint8",4,1,SX_NONE),
    SX_FIELD("end_track","uint8",5,1,SX_NONE),
    SX_FIELD("reserved6","byte[10]",6,10,SX_RESERVED),
};
static const sx_layout sxrfs_cbm_d90_bam_header = {0x60650038U,"cbm_d90_bam_header",sxrfs_cbm_d90_bam_header_fields,SX_COUNT(sxrfs_cbm_d90_bam_header_fields),SX_LE};
static const xx_data_struct_field_desc sxrfs_apple_dos_bitmap16_fields[] = {
    SX_FIELD("free_sector_bits","byte[2]",0,2,SX_FLAGS),
};
static const sx_layout sxrfs_apple_dos_bitmap16 = {0x6065004bU,"apple_dos_bitmap16",sxrfs_apple_dos_bitmap16_fields,SX_COUNT(sxrfs_apple_dos_bitmap16_fields),SX_LE};
static const sx_layout *const sx_retrofs_layouts[] = {
    &sxrfs_aodos_directory_entry,
    &sxrfs_prodos_directory_links,
    &sxrfs_prodos_volume_header,
    &sxrfs_prodos_subdirectory_header,
    &sxrfs_prodos_file_entry,
    &sxrfs_prodos_fork_descriptor,
    &sxrfs_prodos_index_low,
    &sxrfs_prodos_index_high,
    &sxrfs_pascal_volume_header,
    &sxrfs_pascal_file_entry,
    &sxrfs_apple_dos_vtoc,
    &sxrfs_apple_dos_bitmap,
    &sxrfs_apple_dos_catalog_header,
    &sxrfs_apple_dos_file_entry,
    &sxrfs_apple_dos_ts_header,
    &sxrfs_apple_dos_ts_pair,
    &sxrfs_mfs_master_directory,
    &sxrfs_mfs_allocation_pair,
    &sxrfs_mfs_file_entry,
    &sxrfs_adfs_map0,
    &sxrfs_adfs_map1,
    &sxrfs_adfs_directory_start,
    &sxrfs_adfs_directory_entry,
    &sxrfs_acorn_dfs_title,
    &sxrfs_acorn_dfs_name,
    &sxrfs_acorn_dfs_catalog_header,
    &sxrfs_acorn_dfs_file_metadata,
    &sxrfs_atari_atr_header,
    &sxrfs_atari_dos2_vtoc,
    &sxrfs_atari_dos2_directory_entry,
    &sxrfs_atari_dos2_sector_trailer,
    &sxrfs_ti99_vib,
    &sxrfs_ti99_directory_pointer,
    &sxrfs_ti99_file_descriptor,
    &sxrfs_ti99_cluster,
    &sxrfs_os9_disk_descriptor,
    &sxrfs_os9_path_options,
    &sxrfs_os9_file_descriptor,
    &sxrfs_os9_segment,
    &sxrfs_os9_directory_entry,
    &sxrfs_cbm_sector_link,
    &sxrfs_cbm_directory_entry,
    &sxrfs_cbm_d64_bam_header,
    &sxrfs_cbm_bam_entry3,
    &sxrfs_cbm_bam_entry4,
    &sxrfs_cbm_bam_entry5,
    &sxrfs_cbm_bitmap3,
    &sxrfs_cbm_free_count,
    &sxrfs_cbm_d64_disk_identity,
    &sxrfs_cbm_d81_header,
    &sxrfs_cbm_d81_bam_header,
    &sxrfs_cbm_d8x_header,
    &sxrfs_cbm_d8x_bam_header,
    &sxrfs_cbm_d90_config,
    &sxrfs_cbm_d90_header,
    &sxrfs_cbm_d90_bam_header,
    &sxrfs_adf_boot_header,
    &sxrfs_adf_root_block,
    &sxrfs_adf_block_prefix,
    &sxrfs_adf_block_pointer,
    &sxrfs_adf_classic_entry_tail,
    &sxrfs_adf_bitmap_block,
    &sxrfs_hfs_master_directory,
    &sxrfs_hfs_btree_node,
    &sxrfs_hfs_btree_header,
    &sxrfs_hfs_node_record_offset,
    &sxrfs_hfs_catalog_key_prefix,
    &sxrfs_hfs_extents_key,
    &sxrfs_hfs_extent,
    &sxrfs_hfs_btree_child,
    &sxrfs_hfs_catalog_folder,
    &sxrfs_hfs_catalog_file,
    &sxrfs_hfs_catalog_thread,
    &sxrfs_atari_dos25_extended_vtoc,
    &sxrfs_apple_dos_bitmap16,
    &sxrfs_adfs_directory_tail,
};
typedef struct sxrfs_flag {uint64_t mask;const wchar_t*name;} sxrfs_flag;
static bool sxrfs_flags(xx_data_struct_record*r,uint64_t value,const sxrfs_flag*bits,size_t n){
 wchar_t out[1024];size_t used=0;uint64_t known=0;
 for(size_t i=0;i<n;i++){known|=bits[i].mask;if(!(value&bits[i].mask))continue;const wchar_t*p=bits[i].name;size_t z=xx_rt_wcslen(p);if(z+used+24>=SX_COUNT(out))return false;if(used)out[used++]=L'|';while(*p)out[used++]=*p++;}
 uint64_t unknown=value&~known;if(unknown){if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';bool start=false;for(int shift=60;shift>=0;shift-=4){unsigned d=(unsigned)((unknown>>shift)&15);if(d||start||!shift){out[used++]=L"0123456789ABCDEF"[d];start=true;}}}
 if(!used)out[used++]=L'0';out[used]=0;return xx_data_struct_record_set_comment(r,out);
}
static bool sx_retrofs_comment(xx_data_struct_record*r,uint32_t id){
    if(!r||!r->name||id<0x60650000U||id>=0x60660000U)return true;
    const wchar_t *s=NULL;
    xx_var_type_t value_type=xx_var_get_type(&r->value);
    bool integer=value_type>=XX_VAR_TYPE_INT8&&value_type<=XX_VAR_TYPE_UINT64;
    uint64_t value=integer?xx_var_get_u64(&r->value):0;(void)value;
    if(id==0x6065002aU&&!xx_rt_wcscmp(r->name,L"file_type_flags")&&integer){static const sxrfs_flag bits[]={{64U,L"Locked"},{128U,L"Closed"}};return sxrfs_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60650005U&&!xx_rt_wcscmp(r->name,L"access")&&integer){static const sxrfs_flag bits[]={{1U,L"Read"},{2U,L"Write"},{4U,L"Invisible"},{32U,L"Backup"},{64U,L"Rename"},{128U,L"Destroy"}};return sxrfs_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x6065003fU&&!xx_rt_wcscmp(r->name,L"attributes")&&integer){static const sxrfs_flag bits[]={{128U,L"Hardware locked"},{256U,L"Unmounted cleanly"},{512U,L"Bad blocks spared"},{1024U,L"No cache required"},{32768U,L"Software locked"}};return sxrfs_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60650026U&&!xx_rt_wcscmp(r->name,L"attributes")&&integer){static const sxrfs_flag bits[]={{1U,L"Owner read"},{2U,L"Owner write"},{4U,L"Owner execute"},{8U,L"Public read"},{16U,L"Public write"},{32U,L"Public execute"},{64U,L"Shareable"},{128U,L"Directory"}};return sxrfs_flags(r,value,bits,SX_COUNT(bits));}
    if(id==0x60650040U&&!xx_rt_wcscmp(r->name,L"kind")&&integer){switch(value){
    case 0U:return xx_data_struct_record_set_comment(r,L"Index node");
    case 1U:return xx_data_struct_record_set_comment(r,L"Header node");
    case 2U:return xx_data_struct_record_set_comment(r,L"Map node");
    default:break;}}
    if(id==0x60650047U&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 256U:return xx_data_struct_record_set_comment(r,L"Folder record");
    default:break;}}
    if(id==0x60650048U&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 512U:return xx_data_struct_record_set_comment(r,L"File record");
    default:break;}}
    if(id==0x60650049U&&!xx_rt_wcscmp(r->name,L"record_type")&&integer){switch(value){
    case 768U:return xx_data_struct_record_set_comment(r,L"Folder thread");
    case 1024U:return xx_data_struct_record_set_comment(r,L"File thread");
    default:break;}}
    switch(id){
    case 0x60650001U:
        if(!xx_rt_wcscmp(r->name,L"status_and_folder_ids"))s=L"Low byte status/folder ID; high byte parent folder in AO-DOS variant";
        else if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"512-byte logical block number";
        break;
    case 0x60650002U:
        if(!xx_rt_wcscmp(r->name,L"previous_block"))s=L"512-byte logical block number; zero terminates";
        else if(!xx_rt_wcscmp(r->name,L"next_block"))s=L"512-byte logical block number; zero terminates";
        break;
    case 0x60650003U:
        if(!xx_rt_wcscmp(r->name,L"modification_packed"))s=L"Packed ProDOS date/time; GS/OS extension";
        else if(!xx_rt_wcscmp(r->name,L"creation_packed"))s=L"Packed date/time words, not Unix seconds";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_block"))s=L"512-byte logical block number";
        break;
    case 0x60650004U:
        if(!xx_rt_wcscmp(r->name,L"creation_packed"))s=L"Packed ProDOS date/time words";
        else if(!xx_rt_wcscmp(r->name,L"parent_block"))s=L"512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"parent_entry_number"))s=L"One-based directory slot index";
        break;
    case 0x60650005U:
        if(!xx_rt_wcscmp(r->name,L"key_block"))s=L"512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"creation_packed"))s=L"Packed ProDOS date/time words";
        else if(!xx_rt_wcscmp(r->name,L"version_and_case"))s=L"Version/minimum-version bytes or lowercase flag union";
        else if(!xx_rt_wcscmp(r->name,L"modification_packed"))s=L"Packed ProDOS date/time words";
        else if(!xx_rt_wcscmp(r->name,L"header_block"))s=L"512-byte logical directory header block";
        break;
    case 0x60650006U:
        if(!xx_rt_wcscmp(r->name,L"key_block"))s=L"512-byte logical block number";
        break;
    case 0x60650007U:
        if(!xx_rt_wcscmp(r->name,L"block_number_low_bytes"))s=L"Low bytes of 256 block numbers; high bytes are a separate plane";
        break;
    case 0x60650008U:
        if(!xx_rt_wcscmp(r->name,L"block_number_high_bytes"))s=L"High bytes of 256 block numbers; low bytes are a separate plane";
        break;
    case 0x60650009U:
        if(!xx_rt_wcscmp(r->name,L"directory_end_block"))s=L"Exclusive 512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"last_access_time"))s=L"UCSD Pascal access-time word";
        else if(!xx_rt_wcscmp(r->name,L"last_set_date"))s=L"Packed month/day/year date";
        break;
    case 0x6065000aU:
        if(!xx_rt_wcscmp(r->name,L"first_block"))s=L"512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"end_block"))s=L"Exclusive 512-byte logical block number";
        else if(!xx_rt_wcscmp(r->name,L"modification_date"))s=L"Packed month/day/year date";
        break;
    case 0x6065000bU:
        if(!xx_rt_wcscmp(r->name,L"allocation_direction"))s=L"Signed track allocation direction";
        break;
    case 0x6065000cU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Track free-sector bitmap in DOS on-disk bit order";
        break;
    case 0x6065000eU:
        if(!xx_rt_wcscmp(r->name,L"ts_list_track"))s=L"0 deleted/unused; FF deleted in DOS3.3";
        else if(!xx_rt_wcscmp(r->name,L"high_bit_name"))s=L"Apple DOS characters with bit7 set";
        break;
    case 0x60650011U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since 1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since 1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"directory_start_sector"))s=L"512-byte physical sector number";
        else if(!xx_rt_wcscmp(r->name,L"allocation_start_sector"))s=L"512-byte physical sector number";
        break;
    case 0x60650012U:
        if(!xx_rt_wcscmp(r->name,L"two_packed_12bit_links"))s=L"First chain link in high12 bits; second in low12 bits; 0 free,1 terminal";
        break;
    case 0x60650013U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since 1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since 1904-01-01";
        break;
    case 0x60650014U:
        if(!xx_rt_wcscmp(r->name,L"free_start_sector_triplets"))s=L"82 little-endian 24-bit sector numbers";
        break;
    case 0x60650015U:
        if(!xx_rt_wcscmp(r->name,L"free_length_sector_triplets"))s=L"82 little-endian 24-bit sector counts";
        break;
    case 0x60650017U:
        if(!xx_rt_wcscmp(r->name,L"name_and_attributes"))s=L"Bit7 of name bytes encodes access attributes";
        else if(!xx_rt_wcscmp(r->name,L"load_address"))s=L"Load address or encoded timestamp/filetype union";
        else if(!xx_rt_wcscmp(r->name,L"execution_address"))s=L"Execution address or encoded timestamp union";
        else if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"256-byte logical sector number";
        break;
    case 0x60650019U:
        if(!xx_rt_wcscmp(r->name,L"directory_and_locked"))s=L"Low7 ASCII directory, bit7 locked";
        break;
    case 0x6065001aU:
        if(!xx_rt_wcscmp(r->name,L"file_entry_bytes"))s=L"Number of files multiplied by8";
        else if(!xx_rt_wcscmp(r->name,L"boot_and_sector_high"))s=L"Boot bits4..5; high2 total-sector bits0..1";
        else if(!xx_rt_wcscmp(r->name,L"total_sector_low"))s=L"Low byte of10-bit sector count";
        break;
    case 0x6065001bU:
        if(!xx_rt_wcscmp(r->name,L"load_address_low"))s=L"Low16 bits; high2 bits in packed_high";
        else if(!xx_rt_wcscmp(r->name,L"execution_address_low"))s=L"Low16 bits; high2 bits in packed_high";
        else if(!xx_rt_wcscmp(r->name,L"length_low"))s=L"Low16 bits of18-bit byte length";
        else if(!xx_rt_wcscmp(r->name,L"packed_high"))s=L"High2 bits: start0..1,load2..3,length4..5,execution6..7";
        else if(!xx_rt_wcscmp(r->name,L"start_sector_low"))s=L"Low8 bits of10-bit sector number";
        break;
    case 0x6065001cU:
        if(!xx_rt_wcscmp(r->name,L"paragraphs_low"))s=L"Low16 bits of data size in16-byte paragraphs";
        else if(!xx_rt_wcscmp(r->name,L"paragraphs_high"))s=L"High8 bits of24-bit paragraph count";
        break;
    case 0x6065001eU:
        if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"One-based sector number";
        break;
    case 0x6065001fU:
        if(!xx_rt_wcscmp(r->name,L"file_index_and_next_high"))s=L"High6 bits directory slot; low2 high sector bits";
        break;
    case 0x60650021U:
        if(!xx_rt_wcscmp(r->name,L"file_descriptor_sector"))s=L"256-byte logical sector number; zero terminates";
        break;
    case 0x60650022U:
        if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))s=L"0 means256; otherwise byte count";
        else if(!xx_rt_wcscmp(r->name,L"record_count"))s=L"Little endian even though other FDR words are big endian";
        break;
    case 0x60650023U:
        if(!xx_rt_wcscmp(r->name,L"packed_sector_and_end"))s=L"Two12-bit values: physical start sector and inclusive file-sector index";
        break;
    case 0x60650024U:
        if(!xx_rt_wcscmp(r->name,L"root_fd_sector"))s=L"256-byte logical sector number";
        else if(!xx_rt_wcscmp(r->name,L"creation_ymdhm"))s=L"Calendar bytes, year relative1900";
        else if(!xx_rt_wcscmp(r->name,L"volume_name"))s=L"Last character has bit7 set";
        break;
    case 0x60650025U:
        if(!xx_rt_wcscmp(r->name,L"segment_allocation_size"))s=L"Sector allocation increment";
        else if(!xx_rt_wcscmp(r->name,L"record_extension"))s=L"Path extension for record locking";
        else if(!xx_rt_wcscmp(r->name,L"directory_entry_offset"))s=L"Byte position relative to the current directory, not a memory pointer";
        break;
    case 0x60650026U:
        if(!xx_rt_wcscmp(r->name,L"modification_ymdhm"))s=L"Calendar bytes, year relative1900";
        else if(!xx_rt_wcscmp(r->name,L"creation_ymd"))s=L"Calendar bytes, year relative1900";
        break;
    case 0x60650027U:
        if(!xx_rt_wcscmp(r->name,L"first_sector"))s=L"256-byte logical sector number";
        break;
    case 0x60650028U:
        if(!xx_rt_wcscmp(r->name,L"name"))s=L"Last character has bit7 set";
        else if(!xx_rt_wcscmp(r->name,L"file_descriptor_sector"))s=L"256-byte logical sector number";
        break;
    case 0x60650029U:
        if(!xx_rt_wcscmp(r->name,L"next_track"))s=L"0 marks terminal sector";
        else if(!xx_rt_wcscmp(r->name,L"next_sector_or_last_byte"))s=L"Sector number when next_track nonzero; terminal final-byte index otherwise";
        break;
    case 0x6065002aU:
        if(!xx_rt_wcscmp(r->name,L"file_type_flags"))s=L"Low3 type, bit6 locked, bit7 closed";
        break;
    case 0x6065002cU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Least significant bit selects first sector";
        break;
    case 0x6065002dU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Least significant bit selects first sector";
        break;
    case 0x6065002eU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Least significant bit selects first sector";
        break;
    case 0x6065002fU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Least significant bit selects first sector";
        break;
    case 0x60650035U:
        if(!xx_rt_wcscmp(r->name,L"end_track"))s=L"Exclusive track index";
        break;
    case 0x60650038U:
        if(!xx_rt_wcscmp(r->name,L"end_track"))s=L"Exclusive cylinder index";
        break;
    case 0x60650039U:
        if(!xx_rt_wcscmp(r->name,L"dos_flags"))s=L"Bit0 FFS, bit1 international, bit2 directory-cache/long-name variant";
        else if(!xx_rt_wcscmp(r->name,L"root_block"))s=L"512-byte logical block hint; native reader validates candidate root";
        break;
    case 0x6065003aU:
        if(!xx_rt_wcscmp(r->name,L"hash_block_numbers"))s=L"512-byte logical block numbers";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_blocks"))s=L"512-byte logical block numbers";
        else if(!xx_rt_wcscmp(r->name,L"modification_days"))s=L"Days since1978-01-01; combine with minutes/ticks";
        else if(!xx_rt_wcscmp(r->name,L"modification_ticks"))s=L"50Hz ticks";
        else if(!xx_rt_wcscmp(r->name,L"volume_modification_ticks"))s=L"50Hz ticks";
        else if(!xx_rt_wcscmp(r->name,L"creation_ticks"))s=L"50Hz ticks";
        break;
    case 0x6065003bU:
        if(!xx_rt_wcscmp(r->name,L"data_size_or_table_size"))s=L"Variant-dependent word: byte count in OFS data, table size in headers";
        break;
    case 0x6065003cU:
        if(!xx_rt_wcscmp(r->name,L"block_number"))s=L"512-byte logical block number";
        break;
    case 0x6065003dU:
        if(!xx_rt_wcscmp(r->name,L"modification_days"))s=L"Days since1978-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_ticks"))s=L"50Hz ticks";
        break;
    case 0x6065003eU:
        if(!xx_rt_wcscmp(r->name,L"free_block_bits"))s=L"Bit0 is first block in each32-bit group, starting volume block2";
        break;
    case 0x6065003fU:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_start_sector"))s=L"512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"allocation_search_pointer"))s=L"Allocation-block index";
        else if(!xx_rt_wcscmp(r->name,L"allocation_start_sector"))s=L"512-byte sector number";
        else if(!xx_rt_wcscmp(r->name,L"backup_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"volume_cache_or_embedded_signature"))s=L"Classic drVCSize cache-size word; HFS+ wrapper uses drEmbedSigWord";
        else if(!xx_rt_wcscmp(r->name,L"bitmap_cache_or_embedded_start"))s=L"Classic drVBMCSize cache-size word; HFS+ wrapper uses embedded allocation-block start";
        else if(!xx_rt_wcscmp(r->name,L"control_cache_or_embedded_count"))s=L"Classic drCtlCSize cache-size word; HFS+ wrapper uses embedded allocation-block count";
        else if(!xx_rt_wcscmp(r->name,L"extents_file_initial_extents"))s=L"Three (start allocation block,count) pairs";
        else if(!xx_rt_wcscmp(r->name,L"catalog_file_initial_extents"))s=L"Three (start allocation block,count) pairs";
        break;
    case 0x60650040U:
        if(!xx_rt_wcscmp(r->name,L"forward_link"))s=L"B-tree node number";
        else if(!xx_rt_wcscmp(r->name,L"backward_link"))s=L"B-tree node number";
        break;
    case 0x60650042U:
        if(!xx_rt_wcscmp(r->name,L"record_offset"))s=L"Byte offset from B-tree node start; stored in reverse order at node end";
        break;
    case 0x60650046U:
        if(!xx_rt_wcscmp(r->name,L"child_node"))s=L"B-tree node number";
        break;
    case 0x60650047U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"backup_time"))s=L"Seconds since1904-01-01";
        break;
    case 0x60650048U:
        if(!xx_rt_wcscmp(r->name,L"creation_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"modification_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"backup_time"))s=L"Seconds since1904-01-01";
        else if(!xx_rt_wcscmp(r->name,L"data_initial_extents"))s=L"Three allocation block/count pairs";
        else if(!xx_rt_wcscmp(r->name,L"resource_initial_extents"))s=L"Three allocation block/count pairs";
        break;
    case 0x6065004bU:
        if(!xx_rt_wcscmp(r->name,L"free_sector_bits"))s=L"Basis108 80-track free-sector bitmap in on-disk bit order";
        break;
    case 0x6065004cU:
        if(!xx_rt_wcscmp(r->name,L"parent_sector"))s=L"256-byte logical sector number";
        break;
    default:break;}
    return !s||xx_data_struct_record_set_comment(r,s);
}
/* Every coordinate is relative to the borrowed volume base.  No native
 * subclass state, host mounts, or journal replay is required.  Display caps
 * retain validated earlier records; undecoded metadata and payload stay raw. */
#define SXRFS_LIMIT 24000U
bool sxrfs_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxrfs_read(sx_context*c,uint64_t p,void*b,size_t n){return !xx_pd_is_stopped(c->pd)&&sxrfs_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxrfs16(const uint8_t*b,unsigned o){return o==1?(uint16_t)((uint16_t)b[0]<<8|b[1]):(uint16_t)((uint16_t)b[1]<<8|b[0]);}
uint32_t sxrfs32(const uint8_t*b,unsigned o){if(o==2)return (uint32_t)sxrfs16(b,0)<<16|sxrfs16(b+2,0);return o==1?(uint32_t)sxrfs16(b,1)<<16|sxrfs16(b+2,1):(uint32_t)sxrfs16(b+2,0)<<16|sxrfs16(b,0);}
bool sxrfs_pow(uint64_t v){return v&&!(v&(v-1));}
bool sxrfs_put(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){
 if(!n)return true;const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);size_t lo=0,hi=c->count;
 if(n>1048576U||n>UINT64_MAX/z||!sxrfs_span(c,p,n*z)||xx_pd_is_stopped(c->pd))return false;
 if(c->count>=SXRFS_LIMIT)return true;
 while(lo<hi){size_t m=lo+(hi-lo)/2;uint64_t at=(uint64_t)(c->items[m].offset-c->f->base_address);if(at<p)lo=m+1;else hi=m;}
 if(lo&&(uint64_t)(c->items[lo-1].offset-c->f->base_address)+(uint64_t)c->items[lo-1].total_size>p)return true;
 if(lo<c->count&&(uint64_t)(c->items[lo].offset-c->f->base_address)<p+n*z)return true;
 size_t prior=c->count;if(!sx_table(c,l,(int64_t)p,(int64_t)z,n))return false;
 if(lo<prior){xx_data_struct row=c->items[prior];xx_rt_memmove(c->items+lo+1,c->items+lo,(prior-lo)*sizeof(*c->items));c->items[lo]=row;}return true;
}
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
#define SXRFS_TABLE(c,l,p,n) sxrfs_put(c,&sxrfs_##l,p,n)
#define SXRFS_ORDER(l,o) ((o)==1?&sxrfs_##l##_be:&sxrfs_##l##_le)
uint32_t sxrfs24(const uint8_t*b,bool be){return be?((uint32_t)b[0]<<16|(uint32_t)b[1]<<8|b[2]):((uint32_t)b[2]<<16|(uint32_t)b[1]<<8|b[0]);}
/* Apple sector-order mapping. A record crossing a remapped sector boundary is
 * omitted unless its physical bytes really remain adjacent. */
static uint64_t sxrfs_apple_pos(uint64_t p,bool dos){static const uint8_t map[16]={0,14,13,12,11,10,9,8,7,6,5,4,3,2,1,15};return dos?(p/4096)*4096+(uint64_t)map[(p/256)%16]*256+p%256:p;}
bool sxrfs_apple_read(sx_context*c,uint64_t p,void*out,size_t n,bool dos){uint8_t*b=out;while(n){size_t z=256-p%256;if(z>n)z=n;if(!sxrfs_read(c,sxrfs_apple_pos(p,dos),b,z))return false;p+=z;b+=z;n-=z;}return true;}
bool sxrfs_apple_put(sx_context*c,const sx_layout*l,uint64_t p,bool dos){const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t n=f->rel_offset+f->size,at=sxrfs_apple_pos(p,dos);for(uint64_t q=0;q<n;){uint64_t z=256-(p+q)%256;if(sxrfs_apple_pos(p+q,dos)!=at+q)return true;q+=z;}return sxrfs_put(c,l,at,1);}
static bool sxrfs_dos_catalog_contains(sx_context*c,const uint8_t*v,bool remap,uint64_t physical){uint8_t seen[1280]={0},h[3];unsigned t=v[1],s=v[2];for(unsigned i=0;i<1280&&t;i++){if(t>=v[52]||s>=16)break;unsigned ix=t*16+s;if(seen[ix])break;seen[ix]=1;uint64_t p=(uint64_t)ix*256;if(sxrfs_apple_pos(p,remap)==physical)return true;if(!sxrfs_apple_read(c,p,h,3,remap))break;t=h[1];s=h[2];}return false;}
static bool sxrfs_dos_authenticated_order(sx_context*c,const uint8_t*v,bool fallback){
 if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->free_archive_records_reading)return fallback;
 xx_archive_record_state*s=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!s)return fallback;const xx_archive_record*r=(c->f->get_current_archive_record)(c->f,s);if(r&&r->header_offset>=c->f->base_address&&r->header_size==35){uint64_t p=(uint64_t)(r->header_offset-c->f->base_address);p-=p%256;bool a=sxrfs_dos_catalog_contains(c,v,false,p),b=sxrfs_dos_catalog_contains(c,v,true,p);if(a!=b)fallback=b;}(c->f->free_archive_records_reading)(c->f,s);return fallback;
}
bool sxrfs_apple_dos(sx_context*c){unsigned spt=c->f->file_type==XX_FILE_TYPE_APPLE_DOS32?13:c->f->file_type==XX_FILE_TYPE_APPLE_DOS33_32?32:16;uint64_t vp=(uint64_t)17*spt*256;uint8_t v[256],b[256];bool remap=false;if(!sxrfs_read(c,vp,v,256))return false;
 if(v[53]!=spt||v[52]<18||v[52]>80||sxrfs16(v+54,0)!=256||v[39]!=122){if(spt!=16||!sxrfs_apple_read(c,vp,v,256,true)||v[53]!=16||v[52]<18||v[52]>80||sxrfs16(v+54,0)!=256||v[39]!=122)return false;remap=true;}
 if(spt==16)remap=sxrfs_dos_authenticated_order(c,v,remap);unsigned tracks=v[52];if((uint64_t)tracks*spt*256>(uint64_t)c->size||!sxrfs_apple_put(c,&sxrfs_apple_dos_vtoc,vp,remap))return false;for(unsigned j=0;j<tracks;j++)if(!sxrfs_apple_put(c,tracks>50?&sxrfs_apple_dos_bitmap16:&sxrfs_apple_dos_bitmap,vp+56+j*(tracks>50?2:4),remap))return false;
 uint8_t seen[2560]={0};unsigned t=v[1],s=v[2];for(unsigned walk=0;walk<2560&&t&&c->count<SXRFS_LIMIT;walk++){if(t>=tracks||s>=spt)break;unsigned index=t*spt+s;if(seen[index])break;seen[index]=1;uint64_t p=(uint64_t)index*256;if(!sxrfs_apple_read(c,p,b,256,remap))break;if(!sxrfs_apple_put(c,&sxrfs_apple_dos_catalog_header,p,remap))return false;unsigned nextt=b[1],nexts=b[2];
  for(unsigned j=0;j<7;j++){uint8_t*e=b+11+j*35;if(!e[0]||e[0]==255)continue;if(!sxrfs_apple_put(c,&sxrfs_apple_dos_file_entry,p+11+j*35,remap))return false;unsigned ft=e[0],fs=e[1];for(unsigned k=0;k<2560&&ft;k++){if(ft>=tracks||fs>=spt)break;unsigned ix=ft*spt+fs;if(seen[ix])break;seen[ix]=1;uint64_t at=(uint64_t)ix*256;uint8_t ts[12];if(!sxrfs_apple_read(c,at,ts,12,remap))break;if(!sxrfs_apple_put(c,&sxrfs_apple_dos_ts_header,at,remap))return false;for(unsigned a=0;a<122;a++)if(!sxrfs_apple_put(c,&sxrfs_apple_dos_ts_pair,at+12+a*2,remap))return false;ft=ts[1];fs=ts[2];}}
  t=nextt;s=nexts;
 }return true;}
static unsigned sxrfs_cb_spt(xx_file_type_t type,unsigned track){if(type==XX_FILE_TYPE_CBM_D81)return 40;if(type==XX_FILE_TYPE_CBM_D90)return 192;if(type==XX_FILE_TYPE_CBM_D8X){track=(track-1)%77+1;return track<=39?29:track<=53?27:track<=64?25:23;}track=(track-1)%35+1;return track<=17?21:track<=24?(type==XX_FILE_TYPE_CBM_D67?20:19):track<=30?18:17;}
static uint64_t sxrfs_cb_pos(xx_file_type_t type,unsigned track,unsigned sector,unsigned heads){if(type==XX_FILE_TYPE_CBM_D90)return track<153&&sector<heads*32?((uint64_t)track*heads*32+sector)*256:UINT64_MAX;unsigned max=type==XX_FILE_TYPE_CBM_D81?80:type==XX_FILE_TYPE_CBM_D71?70:type==XX_FILE_TYPE_CBM_D8X?154:40;if(!track||track>max||sector>=sxrfs_cb_spt(type,track))return UINT64_MAX;uint64_t n=sector;for(unsigned i=1;i<track;i++)n+=sxrfs_cb_spt(type,i);return n*256;}
bool sxrfs_cbm(sx_context*c){xx_file_type_t type=c->f->file_type;unsigned heads=c->f->format_size==5013504?4:6,track=18,sector=1;uint8_t h[256];uint64_t base=sxrfs_cb_pos(type,18,0,heads);
 if(type==XX_FILE_TYPE_CBM_D81){base=sxrfs_cb_pos(type,40,0,heads);if(!sxrfs_read(c,base,h,256)||h[2]!='D'||!SXRFS_ADD(c,cbm_d81_header,base))return false;track=h[0];sector=h[1];for(unsigned i=1;i<=2;i++)if(!SXRFS_ADD(c,cbm_d81_bam_header,base+i*256)||!SXRFS_TABLE(c,cbm_bam_entry5,base+i*256+16,40))return false;
 }else if(type==XX_FILE_TYPE_CBM_D8X){base=sxrfs_cb_pos(type,39,0,heads);if(!sxrfs_read(c,base,h,256)||h[2]!='C'||!SXRFS_ADD(c,cbm_d8x_header,base))return false;track=39;sector=1;unsigned bt=h[0],bs=h[1];for(unsigned j=0;j<4&&bt==38;j++){uint64_t at=sxrfs_cb_pos(type,bt,bs,heads);if(!sxrfs_read(c,at,h,256)||h[2]!='C'||h[5]<=h[4]||h[5]-h[4]>50)break;if(!SXRFS_ADD(c,cbm_d8x_bam_header,at)||!SXRFS_TABLE(c,cbm_bam_entry4,at+6,h[5]-h[4]))return false;bt=h[0];bs=h[1];}
 }else if(type==XX_FILE_TYPE_CBM_D90){if(!sxrfs_read(c,0,h,12)||h[4]!=76||h[5]!=10||h[6]!=76||h[7]!=20||!SXRFS_ADD(c,cbm_d90_config,0))return false;/* Geometry can be inferred from the authenticated physical header. */if(!sxrfs_read(c,sxrfs_cb_pos(type,76,20,heads),h,29)||h[27]!='3'||h[28]!='A'){heads=4;if(!sxrfs_read(c,sxrfs_cb_pos(type,76,20,4),h,29)||h[27]!='3'||h[28]!='A')return true;}base=sxrfs_cb_pos(type,76,20,heads);if(!SXRFS_ADD(c,cbm_d90_header,base))return false;track=76;sector=10;unsigned bt=1,bs=0;for(unsigned j=0;j<20&&bt!=255;j++){uint64_t p=sxrfs_cb_pos(type,bt,bs,heads);if(!sxrfs_read(c,p,h,256)||h[5]<=h[4]||(h[5]-h[4])*heads>48)break;if(!SXRFS_ADD(c,cbm_d90_bam_header,p)||!SXRFS_TABLE(c,cbm_bam_entry4,p+16,(h[5]-h[4])*heads))return false;bt=h[0];bs=h[1];}
 }else{if(!sxrfs_read(c,base,h,256)||h[0]!=18||h[1]!=1||!SXRFS_ADD(c,cbm_d64_bam_header,base)||!SXRFS_TABLE(c,cbm_bam_entry3,base+4,35)||!SXRFS_ADD(c,cbm_d64_disk_identity,base+144))return false;track=h[0];sector=h[1];if(type==XX_FILE_TYPE_CBM_D71){if(!SXRFS_TABLE(c,cbm_free_count,base+221,35)||!SXRFS_TABLE(c,cbm_bitmap3,sxrfs_cb_pos(type,53,0,heads),35))return false;}}
 uint64_t visited[4096];size_t seen=0;for(unsigned k=0;k<4096&&track&&c->count<SXRFS_LIMIT;k++){uint64_t p=sxrfs_cb_pos(type,track,sector,heads);bool repeat=false;for(size_t j=0;j<seen;j++)if(visited[j]==p)repeat=true;if(repeat||!sxrfs_read(c,p,h,256))break;visited[seen++]=p;if(!SXRFS_ADD(c,cbm_sector_link,p))return false;unsigned nextt=h[0],nexts=h[1];for(unsigned j=0;j<8;j++){uint8_t*e=h+2+j*32;if(!(e[0]&7))continue;if(!SXRFS_ADD(c,cbm_directory_entry,p+2+j*32))return false;unsigned ft=e[1],fs=e[2],blocks=sxrfs16(e+28,0);for(unsigned a=0;a<blocks&&a<32768&&ft&&c->count<SXRFS_LIMIT;a++){uint64_t at=sxrfs_cb_pos(type,ft,fs,heads);uint8_t link[2];if(!sxrfs_read(c,at,link,2))break;if(!SXRFS_ADD(c,cbm_sector_link,at))return false;ft=link[0];fs=link[1];}}track=nextt;sector=nexts;}return true;}
static int sxrfs_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxrfs_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p>end&&!sx_raw(c,end,p-end))return false;if(p+z>end)end=p+z;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxrfs_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
static bool sx_retrofs_supports(xx_file_type_t t){switch(t){
case XX_FILE_TYPE_AODOS:case XX_FILE_TYPE_ADF:case XX_FILE_TYPE_PRODOS:case XX_FILE_TYPE_APPLE_PASCAL:case XX_FILE_TYPE_MFS:case XX_FILE_TYPE_HFS:case XX_FILE_TYPE_ADFS:case XX_FILE_TYPE_ACORN_DFS:case XX_FILE_TYPE_ATARI_DOS2:case XX_FILE_TYPE_TI99_DSK:case XX_FILE_TYPE_OS9_RBF:case XX_FILE_TYPE_APPLE_DOS33:case XX_FILE_TYPE_APPLE_DOS32:case XX_FILE_TYPE_APPLE_DOS33_32:case XX_FILE_TYPE_CBM_D64:case XX_FILE_TYPE_CBM_D71:case XX_FILE_TYPE_CBM_D81:case XX_FILE_TYPE_CBM_D67:case XX_FILE_TYPE_CBM_D8X:case XX_FILE_TYPE_CBM_D90:return true;default:return false;}}
static bool sx_retrofs_build(sx_context*c){bool ok=false;switch(c->f->file_type){
case XX_FILE_TYPE_AODOS:ok=sx_aodos_build(c);break;
case XX_FILE_TYPE_ADF:ok=sx_adf_build(c);break;
case XX_FILE_TYPE_PRODOS:ok=sx_prodos_build(c);break;
case XX_FILE_TYPE_APPLE_PASCAL:ok=sx_apple_pascal_build(c);break;
case XX_FILE_TYPE_MFS:ok=sx_mfs_build(c);break;
case XX_FILE_TYPE_HFS:ok=sx_hfs_build(c);break;
case XX_FILE_TYPE_ADFS:ok=sx_acorn_adfs_build(c);break;
case XX_FILE_TYPE_ACORN_DFS:ok=sx_acorn_dfs_build(c);break;
case XX_FILE_TYPE_ATARI_DOS2:ok=sx_atari_dos2_build(c);break;
case XX_FILE_TYPE_TI99_DSK:ok=sx_ti99_dsk_build(c);break;
case XX_FILE_TYPE_OS9_RBF:ok=sx_os9_rbf_build(c);break;
case XX_FILE_TYPE_APPLE_DOS33:ok=sx_apple_dos33_build(c);break;
case XX_FILE_TYPE_APPLE_DOS32:ok=sx_apple_dos32_build(c);break;
case XX_FILE_TYPE_APPLE_DOS33_32:ok=sx_apple_dos33_32_build(c);break;
case XX_FILE_TYPE_CBM_D64:ok=sx_cbm_d64_build(c);break;
case XX_FILE_TYPE_CBM_D71:ok=sx_cbm_d71_build(c);break;
case XX_FILE_TYPE_CBM_D81:ok=sx_cbm_d81_build(c);break;
case XX_FILE_TYPE_CBM_D67:ok=sx_cbm_d67_build(c);break;
case XX_FILE_TYPE_CBM_D8X:ok=sx_cbm_d8x_build(c);break;
case XX_FILE_TYPE_CBM_D90:ok=sx_cbm_d90_build(c);break;
default:return false;}return (ok||c->count)&&c->count&&!c->failed&&!xx_pd_is_stopped(c->pd)&&sxrfs_finish(c);}
#undef SXRFS_ADD
#undef SXRFS_TABLE
#undef SXRFS_ORDER
#undef SXRFS_LIMIT
const sx_family sx_retrofs_family={sx_retrofs_supports,sx_retrofs_build,sx_retrofs_layouts,SX_COUNT(sx_retrofs_layouts),sx_retrofs_comment};
