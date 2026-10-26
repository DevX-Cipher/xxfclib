/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * exFAT data structures, moved out of the filesystems schema family. */
#include "../../xx_format_schema_filesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fs_exfat_boot_sector_fields[] = {
    SX_FIELD("jump_boot","byte[3]",0,3,SX_NONE),
    SX_FIELD("filesystem_name","char[8]",3,8,SX_SIGNATURE),
    SX_FIELD("must_be_zero","byte[53]",11,53,SX_RESERVED),
    SX_FIELD("partition_sector_offset","uint64",64,8,SX_OFFSET),
    SX_FIELD("volume_sector_count","uint64",72,8,SX_COUNT_PROP),
    SX_FIELD("fat_sector_offset","uint32",80,4,SX_OFFSET),
    SX_FIELD("fat_sector_count","uint32",84,4,SX_COUNT_PROP),
    SX_FIELD("cluster_heap_sector_offset","uint32",88,4,SX_OFFSET),
    SX_FIELD("cluster_count","uint32",92,4,SX_COUNT_PROP),
    SX_FIELD("root_cluster","uint32",96,4,SX_ID),
    SX_FIELD("volume_serial","uint32",100,4,SX_ID),
    SX_FIELD("filesystem_revision","uint16",104,2,SX_ID),
    SX_FIELD("volume_flags","uint16",106,2,SX_FLAGS),
    SX_FIELD("bytes_per_sector_shift","uint8",108,1,SX_NONE),
    SX_FIELD("sectors_per_cluster_shift","uint8",109,1,SX_NONE),
    SX_FIELD("fat_count","uint8",110,1,SX_COUNT_PROP),
    SX_FIELD("drive_select","uint8",111,1,SX_ID),
    SX_FIELD("percent_in_use","uint8",112,1,SX_NONE),
    SX_FIELD("reserved","byte[7]",113,7,SX_RESERVED),
    SX_FIELD("boot_code","byte[390]",120,390,SX_NONE),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
const sx_layout sx_fs_exfat_boot_sector = {0x6010000bU,"exfat_boot_sector",sx_fs_exfat_boot_sector_fields,SX_COUNT(sx_fs_exfat_boot_sector_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_exfat_extended_boot_signature_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sx_fs_exfat_extended_boot_signature = {0x6010000cU,"exfat_extended_boot_signature",sx_fs_exfat_extended_boot_signature_fields,SX_COUNT(sx_fs_exfat_extended_boot_signature_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_exfat_boot_checksum_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sx_fs_exfat_boot_checksum = {0x6010000dU,"exfat_boot_checksum",sx_fs_exfat_boot_checksum_fields,SX_COUNT(sx_fs_exfat_boot_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_exfat_bitmap_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("bitmap_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("reserved","byte[18]",2,18,SX_RESERVED),
    SX_FIELD("first_cluster","uint32",20,4,SX_ID),
    SX_FIELD("data_length","uint64",24,8,SX_SIZE),
};
const sx_layout sx_fs_exfat_bitmap_entry = {0x6010000eU,"exfat_bitmap_entry",sx_fs_exfat_bitmap_entry_fields,SX_COUNT(sx_fs_exfat_bitmap_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_exfat_upcase_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("reserved1","byte[3]",1,3,SX_RESERVED),
    SX_FIELD("table_checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("reserved2","byte[12]",8,12,SX_RESERVED),
    SX_FIELD("first_cluster","uint32",20,4,SX_ID),
    SX_FIELD("data_length","uint64",24,8,SX_SIZE),
};
const sx_layout sx_fs_exfat_upcase_entry = {0x6010000fU,"exfat_upcase_entry",sx_fs_exfat_upcase_entry_fields,SX_COUNT(sx_fs_exfat_upcase_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_exfat_volume_label_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("character_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("volume_label","uint16[11]",2,22,SX_STRING),
    SX_FIELD("reserved","byte[8]",24,8,SX_RESERVED),
};
const sx_layout sx_fs_exfat_volume_label_entry = {0x60100010U,"exfat_volume_label_entry",sx_fs_exfat_volume_label_entry_fields,SX_COUNT(sx_fs_exfat_volume_label_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_exfat_stream_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("general_secondary_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("reserved1","uint8",2,1,SX_RESERVED),
    SX_FIELD("name_length","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("name_hash","uint16",4,2,SX_ID),
    SX_FIELD("reserved2","uint16",6,2,SX_RESERVED),
    SX_FIELD("valid_data_length","uint64",8,8,SX_SIZE),
    SX_FIELD("reserved3","uint32",16,4,SX_RESERVED),
    SX_FIELD("first_cluster","uint32",20,4,SX_ID),
    SX_FIELD("data_length","uint64",24,8,SX_SIZE),
};
const sx_layout sx_fs_exfat_stream_entry = {0x60100012U,"exfat_stream_entry",sx_fs_exfat_stream_entry_fields,SX_COUNT(sx_fs_exfat_stream_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_exfat_name_entry_fields[] = {
    SX_FIELD("entry_type","uint8",0,1,SX_ID),
    SX_FIELD("general_secondary_flags","uint8",1,1,SX_FLAGS),
    SX_FIELD("filename","uint16[15]",2,30,SX_STRING),
};
const sx_layout sx_fs_exfat_name_entry = {0x60100013U,"exfat_name_entry",sx_fs_exfat_name_entry_fields,SX_COUNT(sx_fs_exfat_name_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_fs_exfat_fat_entry_fields[] = {
    SX_FIELD("cluster_link","uint32",0,4,SX_ID),
};
const sx_layout sx_fs_exfat_fat_entry = {0x60100014U,"exfat_fat_entry",sx_fs_exfat_fat_entry_fields,SX_COUNT(sx_fs_exfat_fat_entry_fields),SX_LE};
static bool sx_fs_exfat_boot_valid(sx_context *c,uint64_t at,uint32_t sector,uint8_t *b)
{
    if(!sx_fs_fits(c,at,(uint64_t)sector*12)||!sx_read(c,(int64_t)at,b,512))return false;
    if(xx_rt_memcmp(b+3,"EXFAT   ",8)||b[108]<9||b[108]>12||(1U<<b[108])!=sector||b[109]>25-b[108]||b[510]!=0x55||b[511]!=0xaa)return false;
    uint32_t sum=0;uint8_t buffer[4096];
    for(uint32_t i=0;i<12;i++) {
        if(!sx_read(c,(int64_t)(at+(uint64_t)i*sector),buffer,sector))return false;
        if(i<11)for(uint32_t j=0;j<sector;j++) {
            if(i==0&&(j==106||j==107||j==112))continue;
            sum=((sum>>1)|(sum<<31))+buffer[j];
        }
        else for(uint32_t j=0;j<sector;j+=4)if(xx_data_get_u32(buffer,sector,j,false)!=sum)return false;
        if(i>=1&&i<=8&&xx_data_get_u32(buffer,sector,sector-4,false)!=0xaa550000)return false;
    }
    return true;
}
static bool sx_fs_exfat_directory(sx_context *c,uint64_t at,uint64_t slots,bool *ended)
{
    if(slots>8192)slots=8192;
    for(uint64_t j=0;j<slots;j++) {
        uint8_t type;if(!sx_fs_fits(c,at+j*32,32)||!sx_read(c,(int64_t)(at+j*32),&type,1))return false;
        if(!type){*ended=true;break;}
        const sx_layout *l=NULL;
        switch(type) {
        case 0x81:l=&sx_fs_exfat_bitmap_entry;break;case 0x82:l=&sx_fs_exfat_upcase_entry;break;
        case 0x83:l=&sx_fs_exfat_volume_label_entry;break;case 0x85:l=&sx_fs_exfat_file_entry;break;
        case 0xc0:l=&sx_fs_exfat_stream_entry;break;case 0xc1:l=&sx_fs_exfat_name_entry;break;default:break;
        }
        if(l&&!sx_fs_emit(c,l,at+j*32,32,1))return false;
    }
    return true;
}
static bool sx_fs_exfat(sx_context *c)
{
    uint8_t b[512],h[512];uint32_t sector=0;bool primary=false;
    for(uint32_t s=512;s<=4096;s*=2)if(sx_fs_exfat_boot_valid(c,0,s,b)){sector=s;primary=true;break;}
    if(!sector)for(uint32_t s=512;s<=4096;s*=2)if(sx_fs_exfat_boot_valid(c,(uint64_t)s*12,s,b)&&b[110]==1){sector=s;break;}
    if(!sector)return false;
    for(unsigned copy=0;copy<2;copy++) {
        uint64_t at=(uint64_t)copy*12*sector;
        if(!sx_fs_exfat_boot_valid(c,at,sector,h))continue;
        if(!sx_fs_emit(c,&sx_fs_exfat_boot_sector,at,512,1))return false;
        for(unsigned i=1;i<=8;i++)if(!sx_fs_emit(c,&sx_fs_exfat_extended_boot_signature,at+(uint64_t)(i+1)*sector-4,4,1))return false;
        if(!sx_fs_emit(c,&sx_fs_exfat_boot_checksum,at+(uint64_t)11*sector,4,sector/4))return false;
    }
    uint32_t fat=xx_data_get_u32(b,512,80,false),fatlen=xx_data_get_u32(b,512,84,false),heap=xx_data_get_u32(b,512,88,false),clusters=xx_data_get_u32(b,512,92,false),cluster=xx_data_get_u32(b,512,96,false);
    uint64_t cluster_bytes=(uint64_t)sector<<b[109];uint32_t active=primary?(xx_data_get_u16(b,512,106,false)&1):0;
    if(!fatlen||!clusters||b[110]<1||b[110]>2||active>=b[110])return false;
    for(unsigned i=0;i<b[110];i++) {
        uint64_t count=(uint64_t)fatlen*sector/4;if(count>8192)count=8192;
        if(!sx_fs_emit(c,&sx_fs_exfat_fat_entry,((uint64_t)fat+(uint64_t)fatlen*i)*sector,4,count))return false;
    }
    uint32_t visited[64];size_t seen=0;bool ended=false;
    while(cluster>=2&&cluster-2<clusters&&seen<SX_COUNT(visited)&&!ended) {
        for(size_t i=0;i<seen;i++)if(visited[i]==cluster)return true;
        visited[seen++]=cluster;uint64_t at=(uint64_t)heap*sector+(uint64_t)(cluster-2)*cluster_bytes;
        if(!sx_fs_exfat_directory(c,at,cluster_bytes/32,&ended))return false;
        if(ended)break;
        uint64_t link=((uint64_t)fat+(uint64_t)fatlen*active)*sector+(uint64_t)cluster*4;
        if(!sx_fs_fits(c,link,4)||!sx_u32(c,(int64_t)link,false,&cluster))return false;
    }
    return true;
}
bool sx_exfat_build(sx_context*c)
{
    return sx_fs_exfat(c);
}
