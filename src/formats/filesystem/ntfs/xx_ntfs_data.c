/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NTFS data structures, moved out of the filesystems schema family. */
#include "../../xx_format_schema_filesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fs_ntfs_boot_sector_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("system_id","char[8]",3,8,SX_SIGNATURE),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("unused1","byte[7]",14,7,SX_RESERVED),
    SX_FIELD("media_type","uint8",21,1,SX_ID),
    SX_FIELD("unused2","byte[2]",22,2,SX_RESERVED),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("unused3","byte[4]",32,4,SX_RESERVED),
    SX_FIELD("bios_drive_number","uint8",36,1,SX_ID),
    SX_FIELD("unused4","uint8",37,1,SX_RESERVED),
    SX_FIELD("extended_signature","uint8",38,1,SX_SIGNATURE),
    SX_FIELD("unused5","uint8",39,1,SX_RESERVED),
    SX_FIELD("sector_count","uint64",40,8,SX_COUNT_PROP),
    SX_FIELD("mft_cluster","uint64",48,8,SX_ID),
    SX_FIELD("mft_mirror_cluster","uint64",56,8,SX_ID),
    SX_FIELD("record_size_encoding","int8",64,1,SX_NONE),
    SX_FIELD("unused6","byte[3]",65,3,SX_RESERVED),
    SX_FIELD("index_size_encoding","int8",68,1,SX_NONE),
    SX_FIELD("unused7","byte[3]",69,3,SX_RESERVED),
    SX_FIELD("volume_serial","uint64",72,8,SX_ID),
    SX_FIELD("checksum","uint32",80,4,SX_CHECKSUM),
    SX_FIELD("boot_code","byte[426]",84,426,SX_NONE),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
const sx_layout sx_fs_ntfs_boot_sector = {0x60100015U,"ntfs_boot_sector",sx_fs_ntfs_boot_sector_fields,SX_COUNT(sx_fs_ntfs_boot_sector_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_ntfs_update_sequence_fields[] = {
    SX_FIELD("sequence_value","uint16",0,2,SX_ID),
};
const sx_layout sx_fs_ntfs_update_sequence = {0x60100017U,"ntfs_update_sequence",sx_fs_ntfs_update_sequence_fields,SX_COUNT(sx_fs_ntfs_update_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_ntfs_attribute_resident_fields[] = {
    SX_FIELD("value_length","uint32",0,4,SX_SIZE),
    SX_FIELD("value_offset","uint16",4,2,SX_OFFSET),
    SX_FIELD("resident_flags","uint8",6,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",7,1,SX_RESERVED),
};
const sx_layout sx_fs_ntfs_attribute_resident = {0x60100019U,"ntfs_attribute_resident",sx_fs_ntfs_attribute_resident_fields,SX_COUNT(sx_fs_ntfs_attribute_resident_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_ntfs_attribute_nonresident_fields[] = {
    SX_FIELD("lowest_vcn","uint64",0,8,SX_ID),
    SX_FIELD("highest_vcn","uint64",8,8,SX_ID),
    SX_FIELD("mapping_pairs_offset","uint16",16,2,SX_OFFSET),
    SX_FIELD("compression_unit_shift","uint8",18,1,SX_NONE),
    SX_FIELD("reserved","byte[5]",19,5,SX_RESERVED),
    SX_FIELD("allocated_length","uint64",24,8,SX_SIZE),
    SX_FIELD("file_length","uint64",32,8,SX_SIZE),
    SX_FIELD("valid_data_length","uint64",40,8,SX_SIZE),
};
const sx_layout sx_fs_ntfs_attribute_nonresident = {0x6010001aU,"ntfs_attribute_nonresident",sx_fs_ntfs_attribute_nonresident_fields,SX_COUNT(sx_fs_ntfs_attribute_nonresident_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_ntfs_attribute_end_fields[] = {
    SX_FIELD("attribute_type","uint32",0,4,SX_ID),
};
const sx_layout sx_fs_ntfs_attribute_end = {0x6010001bU,"ntfs_attribute_end",sx_fs_ntfs_attribute_end_fields,SX_COUNT(sx_fs_ntfs_attribute_end_fields),SX_LE};
/* USA protection replaces the last word of each sector. Never label a logical
 * field crossing that word as if its fixed-up value were physically present. */
static bool sx_fs_ntfs_unprotected(uint64_t o,uint64_t n,uint32_t sector)
{
    if(!n)return false;
    uint64_t tail=(o/sector+1)*sector-2;
    return o<tail&&n<=tail-o;
}
static bool sx_fs_ntfs_record(sx_context *c,uint64_t at,uint64_t bytes,uint32_t sector,bool prefix_only)
{
    uint8_t h[48];
    if(!sx_fs_fits(c,at,bytes)||!sx_read(c,(int64_t)at,h,sizeof(h))||xx_rt_memcmp(h,"FILE",4))return true;
    uint64_t used=xx_data_get_u32(h,48,24,false),off=xx_data_get_u16(h,48,20,false),usa=xx_data_get_u16(h,48,4,false),count=xx_data_get_u16(h,48,6,false);
    if(used>bytes||off<48||off>used||usa<48||usa>bytes||count>(bytes-usa)/2)return true;
    if(!sx_fs_emit(c,&sx_fs_ntfs_file_record_header,at,48,1))return false;
    /* The public entry offset identifies only the first mapped fragment. */
    if(prefix_only)return true;
    if(sx_fs_ntfs_unprotected(usa,count*2,sector)&&!sx_fs_emit(c,&sx_fs_ntfs_update_sequence,at+usa,2,count))return false;
    for(unsigned index=0;index<256&&off+4<=used;index++) {
        uint8_t a[24];uint32_t type;
        if(!sx_u32(c,(int64_t)(at+off),false,&type))return false;
        if(type==UINT32_MAX) {
            if(sx_fs_ntfs_unprotected(off,4,sector)&&!sx_fs_emit(c,&sx_fs_ntfs_attribute_end,at+off,4,1))return false;
            break;
        }
        if(off+24>used||!sx_fs_ntfs_unprotected(off,24,sector))break;
        if(!sx_read(c,(int64_t)(at+off),a,sizeof(a)))return false;
        uint32_t n=xx_data_get_u32(a,24,4,false);uint64_t head=a[8]?64:24;
        if(a[8]>1||n<head||n>used-off||(n&7))break;
        if(!sx_fs_emit(c,&sx_fs_ntfs_attribute_common,at+off,16,1))return false;
        if(sx_fs_ntfs_unprotected(off+16,head-16,sector))
            if(!sx_fs_emit(c,a[8]?&sx_fs_ntfs_attribute_nonresident:&sx_fs_ntfs_attribute_resident,at+off+16,head-16,1))return false;
        off+=n;
    }
    return true;
}
static bool sx_fs_ntfs(sx_context *c)
{
    uint8_t b[512];if(!sx_read(c,0,b,sizeof(b))||!sx_add(c,&sx_fs_ntfs_boot_sector,0,512))return false;
    uint32_t sector=xx_data_get_u16(b,512,11,false),spc=b[13];int encoded=(int)(int8_t)b[64];
    if((sector!=512&&sector!=1024&&sector!=2048&&sector!=4096)||!spc||spc>128)return false;
    uint64_t cluster=(uint64_t)sector*spc,record=0,mft=xx_data_get_u64(b,512,48,false),mirror=xx_data_get_u64(b,512,56,false);
    if(encoded<0&&encoded>=-16)record=UINT64_C(1)<<(unsigned)-encoded;
    else if(encoded>0)record=(uint64_t)encoded*cluster;
    if(record<sector||record>65536||record%sector)return false;
    if(mft<=sx_fs_limit(c)/cluster&&!sx_fs_ntfs_record(c,mft*cluster,record,sector,false))return false;
    if(mirror&&mirror<=sx_fs_limit(c)/cluster&&!sx_fs_ntfs_record(c,mirror*cluster,record,sector,false))return false;
    /* Native archive entries expose original physical MFT offsets. No file
     * contents are decoded here, and fragmented record bodies remain raw. */
    xx_archive_record_state *s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);
    if(s) {
        unsigned n=0;
        do {
            const xx_archive_record *r=xx_format_get_current_archive_record(c->f,s);if(!r)break;
            if(r->header_offset>=c->f->base_address&&!sx_fs_ntfs_record(c,(uint64_t)(r->header_offset-c->f->base_address),record,sector,true)) {
                xx_format_free_archive_records_reading(c->f,s);return false;
            }
        }while(++n<4096&&xx_format_archive_record_move_to_next(c->f,s,c->pd));
        xx_format_free_archive_records_reading(c->f,s);
    }
    return !xx_pd_is_stopped(c->pd);
}
bool sx_ntfs_build(sx_context*c)
{
    return sx_fs_ntfs(c);
}
