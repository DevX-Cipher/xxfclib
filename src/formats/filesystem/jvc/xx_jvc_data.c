/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Jvc data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_dragon_dos_geometry_fields[] = {
    SX_FIELD("cylinders","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_cylinder","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("cylinders_complement","uint8",2,1,SX_NONE),
    SX_FIELD("sectors_complement","uint8",3,1,SX_NONE),
};
const sx_layout sxdn_dragon_dos_geometry = {0x60780010U,"dragon_dos_geometry",sxdn_dragon_dos_geometry_fields,SX_COUNT(sxdn_dragon_dos_geometry_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_dragon_dos_file_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("filename","char[8]",1,8,SX_NONE),
    SX_FIELD("extension","char[3]",9,3,SX_NONE),
    SX_FIELD("extent_1_sector","uint16be",12,2,SX_NONE),
    SX_FIELD("extent_1_sectors","uint8",14,1,SX_COUNT_PROP),
    SX_FIELD("extent_2_sector","uint16be",15,2,SX_NONE),
    SX_FIELD("extent_2_sectors","uint8",17,1,SX_COUNT_PROP),
    SX_FIELD("extent_3_sector","uint16be",18,2,SX_NONE),
    SX_FIELD("extent_3_sectors","uint8",20,1,SX_COUNT_PROP),
    SX_FIELD("extent_4_sector","uint16be",21,2,SX_NONE),
    SX_FIELD("extent_4_sectors","uint8",23,1,SX_COUNT_PROP),
    SX_FIELD("next_or_last_bytes","uint8",24,1,SX_NONE),
};
const sx_layout sxdn_dragon_dos_file = {0x60780011U,"dragon_dos_file",sxdn_dragon_dos_file_fields,SX_COUNT(sxdn_dragon_dos_file_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_dragon_dos_continuation_fields[] = {
    SX_FIELD("flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("extent_1_sector","uint16be",1,2,SX_NONE),
    SX_FIELD("extent_1_sectors","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("extent_2_sector","uint16be",4,2,SX_NONE),
    SX_FIELD("extent_2_sectors","uint8",6,1,SX_COUNT_PROP),
    SX_FIELD("extent_3_sector","uint16be",7,2,SX_NONE),
    SX_FIELD("extent_3_sectors","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("extent_4_sector","uint16be",10,2,SX_NONE),
    SX_FIELD("extent_4_sectors","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("extent_5_sector","uint16be",13,2,SX_NONE),
    SX_FIELD("extent_5_sectors","uint8",15,1,SX_COUNT_PROP),
    SX_FIELD("extent_6_sector","uint16be",16,2,SX_NONE),
    SX_FIELD("extent_6_sectors","uint8",18,1,SX_COUNT_PROP),
    SX_FIELD("extent_7_sector","uint16be",19,2,SX_NONE),
    SX_FIELD("extent_7_sectors","uint8",21,1,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[2]",22,2,SX_NONE),
    SX_FIELD("next_or_last_bytes","uint8",24,1,SX_NONE),
};
const sx_layout sxdn_dragon_dos_continuation = {0x60780012U,"dragon_dos_continuation",sxdn_dragon_dos_continuation_fields,SX_COUNT(sxdn_dragon_dos_continuation_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_jvc_os9_disk_descriptor_fields[] = {
    SX_FIELD("total_sectors","uint24",0,3,SX_COUNT_PROP),
    SX_FIELD("track_sector_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("bitmap_bytes","uint16",4,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("root_fd_sector","uint24",8,3,SX_NONE),
    SX_FIELD("owner","uint16",11,2,SX_ID),
    SX_FIELD("attributes","uint8",13,1,SX_FLAGS),
    SX_FIELD("disk_id","uint16",14,2,SX_ID),
    SX_FIELD("format","uint8",16,1,SX_FLAGS),
    SX_FIELD("sectors_per_track","uint16",17,2,SX_COUNT_PROP),
    SX_FIELD("reserved19","byte[2]",19,2,SX_RESERVED),
    SX_FIELD("bootstrap_sector","uint24",21,3,SX_NONE),
    SX_FIELD("bootstrap_bytes","uint16",24,2,SX_SIZE),
    SX_FIELD("creation_ymdhm","byte[5]",26,5,SX_NONE),
    SX_FIELD("volume_name","byte[32]",31,32,SX_NONE),
};
const sx_layout sxdn_jvc_os9_disk_descriptor = {0x60780060U,"jvc_os9_disk_descriptor",sxdn_jvc_os9_disk_descriptor_fields,SX_COUNT(sxdn_jvc_os9_disk_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_jvc_os9_path_options_fields[] = {
    SX_FIELD("device_class","uint8",0,1,SX_ID),
    SX_FIELD("drive","uint8",1,1,SX_NONE),
    SX_FIELD("step_rate","uint8",2,1,SX_NONE),
    SX_FIELD("device_type","uint8",3,1,SX_FLAGS),
    SX_FIELD("density","uint8",4,1,SX_FLAGS),
    SX_FIELD("cylinders","uint16",5,2,SX_COUNT_PROP),
    SX_FIELD("sides","uint8",7,1,SX_COUNT_PROP),
    SX_FIELD("verify_disable","uint8",8,1,SX_FLAGS),
    SX_FIELD("sectors_per_track","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("track0_sectors","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("interleave","uint8",13,1,SX_NONE),
    SX_FIELD("segment_allocation_size","uint8",14,1,SX_NONE),
    SX_FIELD("dma_mode","uint8",15,1,SX_FLAGS),
    SX_FIELD("record_extension","uint16",16,2,SX_NONE),
    SX_FIELD("sector_track_offsets","uint8",18,1,SX_NONE),
    SX_FIELD("file_attributes","uint8",19,1,SX_FLAGS),
    SX_FIELD("file_descriptor_sector","uint24",20,3,SX_NONE),
    SX_FIELD("directory_descriptor_sector","uint24",23,3,SX_NONE),
    SX_FIELD("directory_entry_offset","uint32",26,4,SX_OFFSET),
    SX_FIELD("device_table_address","uint16",30,2,SX_ADDRESS),
};
const sx_layout sxdn_jvc_os9_path_options = {0x60780061U,"jvc_os9_path_options",sxdn_jvc_os9_path_options_fields,SX_COUNT(sxdn_jvc_os9_path_options_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_jvc_os9_file_descriptor_fields[] = {
    SX_FIELD("attributes","uint8",0,1,SX_FLAGS),
    SX_FIELD("owner","uint16",1,2,SX_ID),
    SX_FIELD("modification_ymdhm","byte[5]",3,5,SX_NONE),
    SX_FIELD("link_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("byte_size","uint32",9,4,SX_SIZE),
    SX_FIELD("creation_ymd","byte[3]",13,3,SX_NONE),
};
const sx_layout sxdn_jvc_os9_file_descriptor = {0x60780062U,"jvc_os9_file_descriptor",sxdn_jvc_os9_file_descriptor_fields,SX_COUNT(sxdn_jvc_os9_file_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_jvc_os9_segment_fields[] = {
    SX_FIELD("first_sector","uint24",0,3,SX_NONE),
    SX_FIELD("sector_count","uint16",3,2,SX_COUNT_PROP),
};
const sx_layout sxdn_jvc_os9_segment = {0x60780063U,"jvc_os9_segment",sxdn_jvc_os9_segment_fields,SX_COUNT(sxdn_jvc_os9_segment_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_jvc_os9_directory_entry_fields[] = {
    SX_FIELD("name","byte[29]",0,29,SX_NONE),
    SX_FIELD("file_descriptor_sector","uint24",29,3,SX_NONE),
};
const sx_layout sxdn_jvc_os9_directory_entry = {0x60780064U,"jvc_os9_directory_entry",sxdn_jvc_os9_directory_entry_fields,SX_COUNT(sxdn_jvc_os9_directory_entry_fields),SX_BE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
#define SXDN_TABLE(c,l,p,n) sxdn_put(c,&sxdn_##l,p,n)
static uint32_t sxdn24(const uint8_t*b){return (uint32_t)b[0]<<16|(uint32_t)b[1]<<8|b[2];}
static bool sxdn_os9(sx_context*c,uint64_t base){uint8_t b[256];if(!sxdn_read(c,base,b,256))return false;uint64_t total=sxdn24(b),root=sxdn24(b+8);if(!total||root>=total||!sxdn_span(c,base,total*256)||!SXDN_ADD(c,jvc_os9_disk_descriptor,base)||!SXDN_ADD(c,jvc_os9_path_options,base+63))return false;uint32_t queue[1024];size_t n=1;queue[0]=(uint32_t)root;for(size_t i=0;i<n&&c->count<SXDN_LIMIT;i++){uint64_t p=base+(uint64_t)queue[i]*256;if(!sxdn_read(c,p,b,256)||!SXDN_ADD(c,jvc_os9_file_descriptor,p))return false;unsigned segments=0;for(unsigned j=0;j<48;j++){uint64_t lsn=sxdn24(b+16+j*5),cnt=sxdn16(b+19+j*5,1);if(!lsn||!cnt)break;if(lsn>=total||cnt>total-lsn)break;segments++;}if(!SXDN_TABLE(c,jvc_os9_segment,p+16,segments))return false;if(!(b[0]&128))continue;uint64_t remaining=sxdn32(b+9,1);if(remaining>4*1024*1024)continue;for(unsigned j=0;j<segments&&remaining&&c->count<SXDN_LIMIT;j++){uint64_t lsn=sxdn24(b+16+j*5),cnt=sxdn16(b+19+j*5,1),bytes=cnt*256;if(bytes>remaining)bytes=remaining;uint64_t at=base+lsn*256;if(!SXDN_TABLE(c,jvc_os9_directory_entry,at,bytes/32))return false;for(uint64_t off=0;off+32<=bytes&&n<1024;off+=32){uint8_t e[32];if(!sxdn_read(c,at+off,e,32))return false;uint32_t fd=sxdn24(e+29);if(!e[0]||!fd||fd>=total)continue;bool seen=false;for(size_t k=0;k<n;k++)if(queue[k]==fd){seen=true;break;}if(!seen)queue[n++]=fd;}remaining-=bytes;}}return true;}
static bool sxdn_jvc(sx_context*c){uint64_t h=(uint64_t)c->size%256;if(h>5||!sxdn_jvc_header(c,h))return false;uint8_t b[256];uint64_t total,root;if(sxdn_read(c,h,b,256)&&(total=sxdn24(b))&&total<=((uint64_t)c->size-h)/256&&(root=sxdn24(b+8))&&root<total){uint8_t fd[16];if(sxdn_read(c,h+root*256,fd,16)&&(fd[0]&128))return sxdn_os9(c,h);}for(unsigned heads=1;heads<=2;heads++){uint64_t p=h+20*18*heads*256;if(!sxdn_read(c,p,b,256)||b[253]!=18*heads||(uint8_t)~b[252]!=b[254]||(uint8_t)~b[253]!=b[255]||!b[252])continue;if(!SXDN_ADD(c,dragon_dos_geometry,p+252))return false;for(unsigned s=2;s<18;s++){for(unsigned i=0;i<10;i++){uint64_t at=p+(uint64_t)s*256+i*25;uint8_t flag;if(!sxdn_read(c,at,&flag,1))return false;if(flag&8)return true;if(!sxdn_put(c,flag&1?&sxdn_dragon_dos_continuation:&sxdn_dragon_dos_file,at,1))return false;}}return true;}return c->count!=0;}
bool sx_jvc_build(sx_context*c)
{
 return sxdn_jvc(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
#undef SXDN_TABLE
