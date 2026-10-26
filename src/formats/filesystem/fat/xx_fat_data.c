/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FAT data structures, moved out of the filesystems schema family. */
#include "../../xx_format_schema_filesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fs_fat_bpb_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("oem_name","char[8]",3,8,SX_STRING),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat_16","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors_32","uint32",32,4,SX_COUNT_PROP),
};
const sx_layout sx_fs_fat_bpb = {0x60100001U,"fat_bpb",sx_fs_fat_bpb_fields,SX_COUNT(sx_fs_fat_bpb_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_fat16_boot_sector_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("oem_name","char[8]",3,8,SX_STRING),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat_16","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors_32","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("drive_number","uint8",36,1,SX_ID),
    SX_FIELD("state_flags","uint8",37,1,SX_FLAGS),
    SX_FIELD("extended_boot_signature","uint8",38,1,SX_SIGNATURE),
    SX_FIELD("volume_serial","uint32",39,4,SX_ID),
    SX_FIELD("volume_label","char[11]",43,11,SX_STRING),
    SX_FIELD("filesystem_type","char[8]",54,8,SX_STRING),
    SX_FIELD("boot_code","byte[448]",62,448,SX_NONE),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
const sx_layout sx_fs_fat16_boot_sector = {0x60100002U,"fat16_boot_sector",sx_fs_fat16_boot_sector_fields,SX_COUNT(sx_fs_fat16_boot_sector_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_fat32_boot_sector_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("oem_name","char[8]",3,8,SX_STRING),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_count","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat_16","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors_32","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_fat_32","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("extended_flags","uint16",40,2,SX_FLAGS),
    SX_FIELD("filesystem_version","uint16",42,2,SX_ID),
    SX_FIELD("root_cluster","uint32",44,4,SX_ID),
    SX_FIELD("fsinfo_sector","uint16",48,2,SX_OFFSET),
    SX_FIELD("backup_boot_sector","uint16",50,2,SX_OFFSET),
    SX_FIELD("reserved","byte[12]",52,12,SX_RESERVED),
    SX_FIELD("drive_number","uint8",64,1,SX_ID),
    SX_FIELD("state_flags","uint8",65,1,SX_FLAGS),
    SX_FIELD("extended_boot_signature","uint8",66,1,SX_SIGNATURE),
    SX_FIELD("volume_serial","uint32",67,4,SX_ID),
    SX_FIELD("volume_label","char[11]",71,11,SX_STRING),
    SX_FIELD("filesystem_type","char[8]",82,8,SX_STRING),
    SX_FIELD("boot_code","byte[420]",90,420,SX_NONE),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
const sx_layout sx_fs_fat32_boot_sector = {0x60100003U,"fat32_boot_sector",sx_fs_fat32_boot_sector_fields,SX_COUNT(sx_fs_fat32_boot_sector_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_fat32_fsinfo_fields[] = {
    SX_FIELD("lead_signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("reserved1","byte[480]",4,480,SX_RESERVED),
    SX_FIELD("structure_signature","uint32",484,4,SX_SIGNATURE),
    SX_FIELD("free_cluster_count","uint32",488,4,SX_COUNT_PROP),
    SX_FIELD("next_free_cluster","uint32",492,4,SX_ID),
    SX_FIELD("reserved2","byte[12]",496,12,SX_RESERVED),
    SX_FIELD("trail_signature","uint32",508,4,SX_SIGNATURE),
};
const sx_layout sx_fs_fat32_fsinfo = {0x60100004U,"fat32_fsinfo",sx_fs_fat32_fsinfo_fields,SX_COUNT(sx_fs_fat32_fsinfo_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_fat32_directory_entry_fields[] = {
    SX_FIELD("short_name","char[11]",0,11,SX_STRING),
    SX_FIELD("attributes","uint8",11,1,SX_FLAGS),
    SX_FIELD("case_flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("creation_centiseconds","uint8",13,1,SX_NONE),
    SX_FIELD("creation_time","uint16",14,2,SX_NONE),
    SX_FIELD("creation_date","uint16",16,2,SX_NONE),
    SX_FIELD("access_date","uint16",18,2,SX_NONE),
    SX_FIELD("first_cluster_high","uint16",20,2,SX_ID),
    SX_FIELD("modification_time","uint16",22,2,SX_NONE),
    SX_FIELD("modification_date","uint16",24,2,SX_NONE),
    SX_FIELD("first_cluster_low","uint16",26,2,SX_ID),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
const sx_layout sx_fs_fat32_directory_entry = {0x60100005U,"fat32_directory_entry",sx_fs_fat32_directory_entry_fields,SX_COUNT(sx_fs_fat32_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_fat16_directory_entry_fields[] = {
    SX_FIELD("short_name","char[11]",0,11,SX_STRING),
    SX_FIELD("attributes","uint8",11,1,SX_FLAGS),
    SX_FIELD("case_flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("creation_centiseconds","uint8",13,1,SX_NONE),
    SX_FIELD("creation_time","uint16",14,2,SX_NONE),
    SX_FIELD("creation_date","uint16",16,2,SX_NONE),
    SX_FIELD("access_date","uint16",18,2,SX_NONE),
    SX_FIELD("reserved_cluster_high","uint16",20,2,SX_RESERVED),
    SX_FIELD("modification_time","uint16",22,2,SX_NONE),
    SX_FIELD("modification_date","uint16",24,2,SX_NONE),
    SX_FIELD("first_cluster_low","uint16",26,2,SX_ID),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
};
const sx_layout sx_fs_fat16_directory_entry = {0x60100006U,"fat16_directory_entry",sx_fs_fat16_directory_entry_fields,SX_COUNT(sx_fs_fat16_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_fat16_entry_fields[] = {
    SX_FIELD("cluster_link","uint16",0,2,SX_ID),
};
const sx_layout sx_fs_fat16_entry = {0x60100008U,"fat16_entry",sx_fs_fat16_entry_fields,SX_COUNT(sx_fs_fat16_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_fat32_entry_fields[] = {
    SX_FIELD("cluster_link_flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sx_fs_fat32_entry = {0x60100009U,"fat32_entry",sx_fs_fat32_entry_fields,SX_COUNT(sx_fs_fat32_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_boot_signature_fields[] = {
    SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sx_fs_boot_signature = {0x6010000aU,"boot_signature",sx_fs_boot_signature_fields,SX_COUNT(sx_fs_boot_signature_fields),SX_LE};
static bool sx_fs_fat_directory(sx_context *c,uint64_t off,uint64_t slots,bool fat32,bool *ended)
{
    if(slots>8192)slots=8192;
    for(uint64_t i=0;i<slots;i++) {
        uint8_t b[32];uint64_t at=off+i*32;
        /* Native FAT deliberately accepts cylinder-truncated disk copies. */
        if(!sx_fs_fits(c,at,32)){*ended=true;return true;}
        if(!sx_read(c,(int64_t)at,b,32))return false;
        if(!b[0]){*ended=true;break;}
        const sx_layout *l=b[11]==0x0f?&sx_fs_fat_long_name_entry:fat32?&sx_fs_fat32_directory_entry:&sx_fs_fat16_directory_entry;
        if(!sx_fs_emit(c,l,at,32,1))return false;
    }
    return true;
}
static bool sx_fs_fat(sx_context *c)
{
    uint8_t b[512];uint64_t total,fat,root_sectors,data_start,clusters,root,heap;
    if(!sx_read(c,0,b,sizeof(b)))return false;
    uint32_t sector=xx_data_get_u16(b,sizeof(b),11,false),spc=b[13],reserved=xx_data_get_u16(b,sizeof(b),14,false),fats=b[16],entries=xx_data_get_u16(b,sizeof(b),17,false);
    if((sector!=512&&sector!=1024&&sector!=2048&&sector!=4096)||!spc||(spc&(spc-1))||spc>128||!fats||fats>2)return false;
    /* Native foreign BPBs can encode zero reserved sectors, meaning one. */
    if(!reserved)reserved=1;
    total=xx_data_get_u16(b,sizeof(b),19,false);if(!total)total=xx_data_get_u32(b,sizeof(b),32,false);
    fat=xx_data_get_u16(b,sizeof(b),22,false);if(!fat)fat=xx_data_get_u32(b,sizeof(b),36,false);
    root_sectors=((uint64_t)entries*32+sector-1)/sector;data_start=reserved+fat*fats+root_sectors;
    if(!fat||total<=data_start)return false;
    clusters=(total-data_start)/spc;bool fat32=clusters>=65525;
    if(fat32) {
        if(!sx_add(c,&sx_fs_fat32_boot_sector,0,512))return false;
        uint32_t info=xx_data_get_u16(b,sizeof(b),48,false),backup=xx_data_get_u16(b,sizeof(b),50,false);
        if(info&&info<reserved&&sx_fs_fits(c,(uint64_t)info*sector,512)) {
            uint8_t h[512];if(!sx_read(c,(int64_t)info*sector,h,sizeof(h)))return false;
            if(xx_data_get_u32(h,512,0,false)==0x41615252&&xx_data_get_u32(h,512,484,false)==0x61417272&&xx_data_get_u32(h,512,508,false)==0xaa550000)
                if(!sx_fs_emit(c,&sx_fs_fat32_fsinfo,(uint64_t)info*sector,512,1))return false;
        }
        if(backup&&backup<reserved&&sx_fs_fits(c,(uint64_t)backup*sector,512)) {
            uint8_t h[512];if(!sx_read(c,(int64_t)backup*sector,h,sizeof(h)))return false;
            /* Only a matching BPB is a safely identified backup boot sector. */
            if(!xx_rt_memcmp(h+11,b+11,79)&&h[510]==0x55&&h[511]==0xaa)
                if(!sx_fs_emit(c,&sx_fs_fat32_boot_sector,(uint64_t)backup*sector,512,1))return false;
        }
    } else if(b[38]==0x29) {
        if(!sx_add(c,&sx_fs_fat16_boot_sector,0,512))return false;
    } else if(!sx_add(c,&sx_fs_fat_bpb,0,36)||!sx_add(c,&sx_fs_boot_signature,510,2))return false;
    if(clusters>=4085)for(uint32_t i=0;i<fats;i++) {
        uint64_t count=fat*sector/(fat32?4:2);if(count>8192)count=8192;
        if(!sx_fs_emit(c,fat32?&sx_fs_fat32_entry:&sx_fs_fat16_entry,(reserved+fat*i)*sector,fat32?4:2,count))return false;
    }
    root=(reserved+fat*fats)*sector;heap=data_start*sector;bool ended=false;
    if(!fat32)return sx_fs_fat_directory(c,root,entries,false,&ended);
    uint32_t flags=xx_data_get_u16(b,sizeof(b),40,false),active=(flags&0x80U)?flags&15U:0;
    if(active>=fats)return false;
    uint32_t cluster=xx_data_get_u32(b,sizeof(b),44,false)&0x0fffffff,visited[64];size_t seen=0;
    while(cluster>=2&&cluster<clusters+2&&seen<SX_COUNT(visited)&&!ended) {
        for(size_t i=0;i<seen;i++)if(visited[i]==cluster)return true;
        visited[seen++]=cluster;uint64_t at=heap+(uint64_t)(cluster-2)*sector*spc;
        if(!sx_fs_fat_directory(c,at,(uint64_t)sector*spc/32,true,&ended))return false;
        if(ended)break;
        uint32_t next;uint64_t link=((uint64_t)reserved+fat*active)*sector+(uint64_t)cluster*4;
        if(!sx_fs_fits(c,link,4)||!sx_u32(c,(int64_t)link,false,&next))return false;
        cluster=next&0x0fffffff;
    }
    return true;
}
bool sx_fat_schema_build(sx_context*c)
{
    return sx_fs_fat(c);
}
