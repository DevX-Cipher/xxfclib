/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical filesystem metadata; see docs/data_struct_filesystems_scope.txt.
 * Encoded payloads and unwalked trees remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_filesystems.h"
static const xx_data_struct_field_desc sx_fs_fat_long_name_entry_fields[] = {
    SX_FIELD("sequence_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("name_part1","uint16[5]",1,10,SX_STRING),
    SX_FIELD("attributes","uint8",11,1,SX_FLAGS),
    SX_FIELD("entry_type","uint8",12,1,SX_ID),
    SX_FIELD("short_name_checksum","uint8",13,1,SX_CHECKSUM),
    SX_FIELD("name_part2","uint16[6]",14,12,SX_STRING),
    SX_FIELD("reserved_cluster","uint16",26,2,SX_RESERVED),
    SX_FIELD("name_part3","uint16[2]",28,4,SX_STRING),
};
const sx_layout sx_fs_fat_long_name_entry = {0x60100007U,"fat_long_name_entry",sx_fs_fat_long_name_entry_fields,SX_COUNT(sx_fs_fat_long_name_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_exfat_file_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("secondary_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("set_checksum","uint16",2,2,SX_CHECKSUM),
    SX_FIELD("file_attributes","uint16",4,2,SX_FLAGS),
    SX_FIELD("reserved1","uint16",6,2,SX_RESERVED),
    SX_FIELD("creation_timestamp","uint32",8,4,SX_NONE),
    SX_FIELD("modification_timestamp","uint32",12,4,SX_NONE),
    SX_FIELD("access_timestamp","uint32",16,4,SX_NONE),
    SX_FIELD("creation_centiseconds","uint8",20,1,SX_NONE),
    SX_FIELD("modification_centiseconds","uint8",21,1,SX_NONE),
    SX_FIELD("creation_utc_offset","uint8",22,1,SX_NONE),
    SX_FIELD("modification_utc_offset","uint8",23,1,SX_NONE),
    SX_FIELD("access_utc_offset","uint8",24,1,SX_NONE),
    SX_FIELD("reserved2","byte[7]",25,7,SX_RESERVED),
};
const sx_layout sx_fs_exfat_file_entry = {0x60100011U,"exfat_file_entry",sx_fs_exfat_file_entry_fields,SX_COUNT(sx_fs_exfat_file_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_ntfs_file_record_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("update_sequence_offset","uint16",4,2,SX_OFFSET),
    SX_FIELD("update_sequence_count","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("log_sequence_number","uint64",8,8,SX_ID),
    SX_FIELD("sequence_number","uint16",16,2,SX_ID),
    SX_FIELD("hard_link_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("first_attribute_offset","uint16",20,2,SX_OFFSET),
    SX_FIELD("flags","uint16",22,2,SX_FLAGS),
    SX_FIELD("bytes_in_use","uint32",24,4,SX_SIZE),
    SX_FIELD("bytes_allocated","uint32",28,4,SX_SIZE),
    SX_FIELD("base_file_reference","uint64",32,8,SX_ID),
    SX_FIELD("next_attribute_id","uint16",40,2,SX_ID),
    SX_FIELD("reserved","uint16",42,2,SX_RESERVED),
    SX_FIELD("record_number","uint32",44,4,SX_ID),
};
const sx_layout sx_fs_ntfs_file_record_header = {0x60100016U,"ntfs_file_record_header",sx_fs_ntfs_file_record_header_fields,SX_COUNT(sx_fs_ntfs_file_record_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_ntfs_attribute_common_fields[] = {
    SX_FIELD("attribute_type","uint32",0,4,SX_ID),
    SX_FIELD("record_length","uint32",4,4,SX_SIZE),
    SX_FIELD("nonresident","uint8",8,1,SX_ID),
    SX_FIELD("name_length","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("name_offset","uint16",10,2,SX_OFFSET),
    SX_FIELD("flags","uint16",12,2,SX_FLAGS),
    SX_FIELD("attribute_id","uint16",14,2,SX_ID),
};
const sx_layout sx_fs_ntfs_attribute_common = {0x60100018U,"ntfs_attribute_common",sx_fs_ntfs_attribute_common_fields,SX_COUNT(sx_fs_ntfs_attribute_common_fields),SX_LE};
static const sx_layout *const sx_filesystems_layouts[] = {
    &sx_fs_fat_bpb,
    &sx_fs_fat16_boot_sector,
    &sx_fs_fat32_boot_sector,
    &sx_fs_fat32_fsinfo,
    &sx_fs_fat32_directory_entry,
    &sx_fs_fat16_directory_entry,
    &sx_fs_fat_long_name_entry,
    &sx_fs_fat16_entry,
    &sx_fs_fat32_entry,
    &sx_fs_boot_signature,
    &sx_fs_exfat_boot_sector,
    &sx_fs_exfat_extended_boot_signature,
    &sx_fs_exfat_boot_checksum,
    &sx_fs_exfat_bitmap_entry,
    &sx_fs_exfat_upcase_entry,
    &sx_fs_exfat_volume_label_entry,
    &sx_fs_exfat_file_entry,
    &sx_fs_exfat_stream_entry,
    &sx_fs_exfat_name_entry,
    &sx_fs_exfat_fat_entry,
    &sx_fs_ntfs_boot_sector,
    &sx_fs_ntfs_file_record_header,
    &sx_fs_ntfs_update_sequence,
    &sx_fs_ntfs_attribute_common,
    &sx_fs_ntfs_attribute_resident,
    &sx_fs_ntfs_attribute_nonresident,
    &sx_fs_ntfs_attribute_end,
};
static bool sx_filesystems_supports(xx_file_type_t type)
{
    return type==XX_FILE_TYPE_FAT||type==XX_FILE_TYPE_EXFAT||type==XX_FILE_TYPE_NTFS;
}
uint64_t sx_fs_limit(const sx_context *c)
{
    return c->f->format_size>0&&c->f->format_size<=c->size?(uint64_t)c->f->format_size:(uint64_t)c->size;
}
bool sx_fs_fits(const sx_context *c,uint64_t o,uint64_t n)
{
    uint64_t size=sx_fs_limit(c);return o<=size&&n<=size-o;
}
static bool sx_fs_free(const sx_context *c,uint64_t o,uint64_t n)
{
    if(!sx_fs_fits(c,o,n)||c->count>=20000)return false;
    for(size_t i=0;i<c->count;i++) {
        uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;
        if(o<a+z&&a<o+n)return false;
    }
    return true;
}
/* A conflicting optional pointer is left raw. Required headers use sx_add. */
bool sx_fs_emit(sx_context *c,const sx_layout *l,uint64_t o,uint64_t n,uint64_t count)
{
    if(!count)return true;
    if(!n||n>INT64_MAX/count)return false;
    return !sx_fs_free(c,o,n*count)||sx_table(c,l,(int64_t)o,(int64_t)n,count);
}
static void sx_fs_sort(sx_context *c)
{
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++) {
        xx_data_struct d=c->items[i];size_t j=i;
        while(j>=gap&&c->items[j-gap].offset>d.offset){c->items[j]=c->items[j-gap];j-=gap;}
        c->items[j]=d;
    }
}
static bool sx_fs_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;sx_fs_sort(c);
    for(size_t i=0;i<n;i++) {
        int64_t off=c->items[i].offset-c->f->base_address;
        if(off<end)return false;
        if(off>end&&!sx_raw(c,end,off-end))return false;
        end=off+c->items[i].total_size;
    }
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    sx_fs_sort(c);return !c->failed;
}
static bool sx_filesystems_build(sx_context *c)
{
    if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    bool ok=false;
    switch(c->f->file_type) {
    case XX_FILE_TYPE_FAT:ok=sx_fat_schema_build(c);break;
    case XX_FILE_TYPE_EXFAT:ok=sx_exfat_build(c);break;
    case XX_FILE_TYPE_NTFS:ok=sx_ntfs_build(c);break;
    default:break;
    }
    return ok&&sx_fs_finish(c);
}
typedef struct sx_fs_flag {uint64_t mask;const wchar_t *name;} sx_fs_flag;
static bool sx_fs_flags(xx_data_struct_record *r,const sx_fs_flag *flags,size_t count)
{
    wchar_t out[256];size_t used=0;uint64_t value=xx_var_get_u64(&r->value),known=0;
    for(size_t i=0;i<count;i++) {
        known|=flags[i].mask;if(!(value&flags[i].mask))continue;
        if(used+32>=SX_COUNT(out))return false;
        if(used)out[used++]=L'|';
        const wchar_t *p=flags[i].name;while(*p&&used+24<SX_COUNT(out))out[used++]=*p++;
        if(*p)return false;
    }
    uint64_t unknown=value&~known;
    if(unknown) {
        if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';
        bool started=false;
        for(int shift=60;shift>=0;shift-=4) {unsigned digit=(unsigned)((unknown>>shift)&15);if(digit||started||!shift){out[used++]=L"0123456789ABCDEF"[digit];started=true;}}
    }
    if(!used)out[used++]=L'0';out[used]=0;
    return xx_data_struct_record_set_comment(r,out);
}
static bool sx_filesystems_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60100000U||id>=0x60110000U)return true;
    const wchar_t *n=r->name,*text=NULL;
    if(!xx_rt_wcscmp(n,L"attributes")||!xx_rt_wcscmp(n,L"file_attributes")) {
        static const sx_fs_flag e[]={{1,L"READ_ONLY"},{2,L"HIDDEN"},{4,L"SYSTEM"},{16,L"DIRECTORY"},{32,L"ARCHIVE"}};
        if(id==sx_fs_exfat_file_entry.id)return sx_fs_flags(r,e,SX_COUNT(e));
        static const sx_fs_flag f[]={{1,L"READ_ONLY"},{2,L"HIDDEN"},{4,L"SYSTEM"},{8,L"VOLUME_LABEL"},{16,L"DIRECTORY"},{32,L"ARCHIVE"}};
        if(id==sx_fs_fat_long_name_entry.id&&xx_var_get_u64(&r->value)==15)return xx_data_struct_record_set_comment(r,L"ATTR_LONG_NAME");
        return sx_fs_flags(r,f,SX_COUNT(f));
    }
    if(!xx_rt_wcscmp(n,L"volume_flags")) {
        static const sx_fs_flag f[]={{1,L"ACTIVE_FAT"},{2,L"VOLUME_DIRTY"},{4,L"MEDIA_FAILURE"},{8,L"CLEAR_TO_ZERO"}};
        return sx_fs_flags(r,f,SX_COUNT(f));
    }
    if(!xx_rt_wcscmp(n,L"flags")&&id==sx_fs_ntfs_file_record_header.id) {
        static const sx_fs_flag f[]={{1,L"IN_USE"},{2,L"DIRECTORY"}};
        return sx_fs_flags(r,f,SX_COUNT(f));
    }
    if(!xx_rt_wcscmp(n,L"flags")&&id==sx_fs_ntfs_attribute_common.id) {
        static const sx_fs_flag f[]={{1,L"COMPRESSED"},{0x4000,L"ENCRYPTED"},{0x8000,L"SPARSE"}};
        return sx_fs_flags(r,f,SX_COUNT(f));
    }
    if(!xx_rt_wcscmp(n,L"fsinfo_sector")||!xx_rt_wcscmp(n,L"backup_boot_sector")||!xx_rt_wcscmp(n,L"partition_sector_offset")||!xx_rt_wcscmp(n,L"fat_sector_offset")||!xx_rt_wcscmp(n,L"cluster_heap_sector_offset"))text=L"Offset in logical sectors; multiply by the volume sector size for bytes";
    else if(!xx_rt_wcscmp(n,L"value_offset")||!xx_rt_wcscmp(n,L"mapping_pairs_offset")||!xx_rt_wcscmp(n,L"name_offset"))text=L"Byte offset relative to the start of the complete attribute";
    else if(!xx_rt_wcscmp(n,L"bytes_per_sector_shift"))text=L"Encoded exponent: sector bytes = 1 << value";
    else if(!xx_rt_wcscmp(n,L"sectors_per_cluster_shift"))text=L"Encoded exponent: sectors per cluster = 1 << value";
    else if(!xx_rt_wcscmp(n,L"record_size_encoding")||!xx_rt_wcscmp(n,L"index_size_encoding"))text=L"Positive: cluster count; negative: byte size = 1 << -value";
    else if(!xx_rt_wcscmp(n,L"creation_centiseconds")||!xx_rt_wcscmp(n,L"modification_centiseconds"))text=L"Encoded 10-millisecond increment in the range 0..199";
    else if(!xx_rt_wcscmp(n,L"creation_time")||!xx_rt_wcscmp(n,L"modification_time"))text=L"DOS packed time: hour[15:11], minute[10:5], seconds/2[4:0]";
    else if(!xx_rt_wcscmp(n,L"creation_date")||!xx_rt_wcscmp(n,L"modification_date")||!xx_rt_wcscmp(n,L"access_date"))text=L"DOS packed date: year since 1980[15:9], month[8:5], day[4:0]";
    else if(!xx_rt_wcscmp(n,L"creation_timestamp")||!xx_rt_wcscmp(n,L"modification_timestamp")||!xx_rt_wcscmp(n,L"access_timestamp"))text=L"Packed date in the high word and DOS time in the low word";
    else if(!xx_rt_wcscmp(n,L"creation_utc_offset")||!xx_rt_wcscmp(n,L"modification_utc_offset")||!xx_rt_wcscmp(n,L"access_utc_offset"))text=L"Bit 7 marks validity; signed 7-bit offset in 15-minute units";
    else if(!xx_rt_wcscmp(n,L"compression_unit_shift"))text=L"Compression-unit cluster count is 1 << value; zero means uncompressed";
    else if(!xx_rt_wcscmp(n,L"volume_flags"))text=L"ACTIVE_FAT=0x1, VOLUME_DIRTY=0x2, MEDIA_FAILURE=0x4, CLEAR_TO_ZERO=0x8";
    else if(!xx_rt_wcscmp(n,L"extended_flags"))text=L"Bit 7 disables FAT mirroring; low four bits select the active FAT";
    else if(!xx_rt_wcscmp(n,L"attributes")||!xx_rt_wcscmp(n,L"file_attributes"))text=L"READ_ONLY=0x01, HIDDEN=0x02, SYSTEM=0x04, VOLUME_LABEL=0x08, DIRECTORY=0x10, ARCHIVE=0x20";
    else if(!xx_rt_wcscmp(n,L"general_secondary_flags"))text=L"ALLOCATION_POSSIBLE=0x01, NO_FAT_CHAIN=0x02";
    else if(!xx_rt_wcscmp(n,L"sequence_flags"))text=L"Low five bits: long-name sequence; LAST_LONG_ENTRY=0x40";
    else if(!xx_rt_wcscmp(n,L"case_flags"))text=L"LOWERCASE_BASENAME=0x08, LOWERCASE_EXTENSION=0x10";
    else if(!xx_rt_wcscmp(n,L"state_flags"))text=L"DIRTY=0x01; other bits are implementation-specific";
    else if(!xx_rt_wcscmp(n,L"cluster_link_flags"))text=L"Low 28 bits are a cluster link; high four bits are reserved";
    else if(!xx_rt_wcscmp(n,L"free_cluster_count")||!xx_rt_wcscmp(n,L"next_free_cluster"))text=L"0xFFFFFFFF means unknown";
    else if(!xx_rt_wcscmp(n,L"percent_in_use"))text=L"Percentage 0..100; 0xFF means unknown";
    else if(!xx_rt_wcscmp(n,L"first_cluster")||!xx_rt_wcscmp(n,L"root_cluster")||!xx_rt_wcscmp(n,L"mft_cluster")||!xx_rt_wcscmp(n,L"mft_mirror_cluster"))text=L"Logical cluster number; not a byte offset";
    else if(!xx_rt_wcscmp(n,L"entry_type")) {
        switch(xx_var_get_u64(&r->value)) {
        case 0x81:text=L"ALLOCATION_BITMAP";break;case 0x82:text=L"UPCASE_TABLE";break;case 0x83:text=L"VOLUME_LABEL";break;
        case 0x85:text=L"FILE";break;case 0xc0:text=L"STREAM_EXTENSION";break;case 0xc1:text=L"FILE_NAME";break;default:break;
        }
    } else if(!xx_rt_wcscmp(n,L"attribute_type")) {
        switch(xx_var_get_u64(&r->value)) {
        case 0x10:text=L"$STANDARD_INFORMATION";break;case 0x20:text=L"$ATTRIBUTE_LIST";break;case 0x30:text=L"$FILE_NAME";break;case 0x40:text=L"$OBJECT_ID";break;
        case 0x50:text=L"$SECURITY_DESCRIPTOR";break;case 0x60:text=L"$VOLUME_NAME";break;case 0x70:text=L"$VOLUME_INFORMATION";break;case 0x80:text=L"$DATA";break;
        case 0x90:text=L"$INDEX_ROOT";break;case 0xa0:text=L"$INDEX_ALLOCATION";break;case 0xb0:text=L"$BITMAP";break;case 0xc0:text=L"$REPARSE_POINT";break;
        case 0xd0:text=L"$EA_INFORMATION";break;case 0xe0:text=L"$EA";break;case 0x100:text=L"$LOGGED_UTILITY_STREAM";break;case UINT32_MAX:text=L"ATTRIBUTE_END";break;default:break;
        }
    }
    return !text||xx_data_struct_record_set_comment(r,text);
}
const sx_family sx_filesystems_family={sx_filesystems_supports,sx_filesystems_build,sx_filesystems_layouts,SX_COUNT(sx_filesystems_layouts),sx_filesystems_comment};
