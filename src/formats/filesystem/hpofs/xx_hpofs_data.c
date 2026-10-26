/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HPOFS data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_hpofs_boot_sector_fields[] = {
    SX_FIELD("jump","byte[3]",0,3,SX_NONE),
    SX_FIELD("oem_name","char[8]",3,8,SX_NONE),
    SX_FIELD("bytes_per_sector","uint16",11,2,SX_SIZE),
    SX_FIELD("sectors_per_allocation_unit","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sectors","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",16,1,SX_COUNT_PROP),
    SX_FIELD("root_entry_compatibility","uint16",17,2,SX_NONE),
    SX_FIELD("sector_count_16","uint16",19,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",21,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",24,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",26,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sectors","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("sector_count_32","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("drive_number","uint8",36,1,SX_ID),
    SX_FIELD("reserved0","uint8",37,1,SX_RESERVED),
    SX_FIELD("extended_signature","uint8",38,1,SX_SIGNATURE),
    SX_FIELD("serial_number","uint32",39,4,SX_ID),
    SX_FIELD("volume_label","char[11]",43,11,SX_NONE),
    SX_FIELD("filesystem_identifier","char[8]",54,8,SX_SIGNATURE),
    SX_FIELD("boot_code","byte[442]",62,442,SX_NONE),
    SX_FIELD("marker","uint16",504,2,SX_SIGNATURE),
    SX_FIELD("reserved1","uint16",506,2,SX_RESERVED),
    SX_FIELD("version","uint16",508,2,SX_ID),
    SX_FIELD("boot_signature","uint16",510,2,SX_SIGNATURE),
};
const sx_layout sxcf_hpofs_boot_sector = {0x603d0050U,"hpofs_boot_sector",sxcf_hpofs_boot_sector_fields,SX_COUNT(sxcf_hpofs_boot_sector_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_hpofs_media_information_fields[] = {
    SX_FIELD("identifier","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("volume_label","char[32]",8,32,SX_NONE),
    SX_FIELD("comment_codepage_data","byte[160]",40,160,SX_NONE),
    SX_FIELD("serial_number","uint32",200,4,SX_ID),
    SX_FIELD("format_major","uint16",204,2,SX_ID),
    SX_FIELD("format_minor","uint16",206,2,SX_ID),
    SX_FIELD("codepage_type","uint16",208,2,SX_ID),
    SX_FIELD("codepage","uint16",210,2,SX_ID),
    SX_FIELD("sector_count","uint32",212,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint16",216,2,SX_SIZE),
    SX_FIELD("bytes_per_sector_copy","uint16",218,2,SX_SIZE),
    SX_FIELD("reserved0","uint32",220,4,SX_RESERVED),
    SX_FIELD("sectors_per_band","uint32",224,4,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector_32","uint32",228,4,SX_SIZE),
    SX_FIELD("opaque_e8","byte[8]",232,8,SX_NONE),
    SX_FIELD("revision_high","uint16",240,2,SX_NONE),
    SX_FIELD("revision_low","uint16",242,2,SX_NONE),
    SX_FIELD("opaque_f4","byte[8]",244,8,SX_NONE),
};
const sx_layout sxcf_hpofs_media_information = {0x603d0051U,"hpofs_media_information",sxcf_hpofs_media_information_fields,SX_COUNT(sxcf_hpofs_media_information_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_hpofs_subfile_header_fields[] = {
    SX_FIELD("identifier","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("opaque_04","byte[12]",4,12,SX_NONE),
    SX_FIELD("extent_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("opaque_12","byte[14]",18,14,SX_NONE),
};
const sx_layout sxcf_hpofs_subfile_header = {0x603d0052U,"hpofs_subfile_header",sxcf_hpofs_subfile_header_fields,SX_COUNT(sxcf_hpofs_subfile_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_hpofs_extent_fields[] = {
    SX_FIELD("sector_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("opaque_02","uint16",2,2,SX_NONE),
    SX_FIELD("first_sector","uint32",4,4,SX_NONE),
};
const sx_layout sxcf_hpofs_extent = {0x603d0053U,"hpofs_extent",sxcf_hpofs_extent_fields,SX_COUNT(sxcf_hpofs_extent_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_hpofs_directory_node_fields[] = {
    SX_FIELD("identifier","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("opaque_04","byte[16]",4,16,SX_NONE),
    SX_FIELD("level","uint16",20,2,SX_NONE),
    SX_FIELD("codepage_type","uint16",22,2,SX_ID),
    SX_FIELD("separator","uint16",24,2,SX_NONE),
    SX_FIELD("reserved0","uint16",26,2,SX_RESERVED),
    SX_FIELD("opaque_1c","byte[8]",28,8,SX_NONE),
};
const sx_layout sxcf_hpofs_directory_node = {0x603d0054U,"hpofs_directory_node",sxcf_hpofs_directory_node_fields,SX_COUNT(sxcf_hpofs_directory_node_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_hpofs_directory_record_prefix_fields[] = {
    SX_FIELD("key_size","uint16",0,2,SX_SIZE),
    SX_FIELD("record_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxcf_hpofs_directory_record_prefix = {0x603d0055U,"hpofs_directory_record_prefix",sxcf_hpofs_directory_record_prefix_fields,SX_COUNT(sxcf_hpofs_directory_record_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_hpofs_directory_record_fields[] = {
    SX_FIELD("record_identifier","uint32",0,4,SX_ID),
    SX_FIELD("record_identifier_copy","uint32",4,4,SX_ID),
    SX_FIELD("opaque_08","byte[4]",8,4,SX_NONE),
    SX_FIELD("record_type","uint8",12,1,SX_ID),
    SX_FIELD("opaque_0d","uint8",13,1,SX_NONE),
    SX_FIELD("attributes","uint8",14,1,SX_FLAGS),
    SX_FIELD("opaque_0f","byte[49]",15,49,SX_NONE),
    SX_FIELD("inline_extent_sectors","uint16",64,2,SX_COUNT_PROP),
    SX_FIELD("opaque_42","uint16",66,2,SX_NONE),
    SX_FIELD("inline_extent_first_sector","uint32",68,4,SX_NONE),
    SX_FIELD("opaque_48","byte[4]",72,4,SX_NONE),
    SX_FIELD("extent_list_sector","uint32",76,4,SX_NONE),
    SX_FIELD("opaque_50","byte[8]",80,8,SX_NONE),
    SX_FIELD("file_size","uint32",88,4,SX_SIZE),
};
const sx_layout sxcf_hpofs_directory_record = {0x603d0056U,"hpofs_directory_record",sxcf_hpofs_directory_record_fields,SX_COUNT(sxcf_hpofs_directory_record_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_hpofs_volume_information_fields[] = {
    SX_FIELD("identifier","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("record_version1","uint32",8,4,SX_ID),
    SX_FIELD("record_version2","uint32",12,4,SX_ID),
    SX_FIELD("directory_intent_counter","uint32",16,4,SX_NONE),
    SX_FIELD("directory_update_counter","uint32",20,4,SX_NONE),
};
const sx_layout sxcf_hpofs_volume_information = {0x603d007fU,"hpofs_volume_information",sxcf_hpofs_volume_information_fields,SX_COUNT(sxcf_hpofs_volume_information_fields),SX_BE};
#define SXCF_LIMIT 24000U
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
#define SXCF_TABLE(c,l,p,n) sxcf_put(c,&sxcf_##l,p,n)
static bool sxcf_hpofs_node(sx_context*c,uint64_t p,uint64_t n){
 uint8_t h[92];if(n<36||!sxcf_read(c,p,h,36)||(xx_rt_memcmp(h,"INDX",4)&&xx_rt_memcmp(h,"DATA",4)))return true;if(!SXCF_ADD(c,hpofs_directory_node,p))return false;if(sxcf16(h+20,1))return true;
 for(uint64_t q=36;q+4<=n&&c->count<SXCF_LIMIT;){if(!sxcf_read(c,p+q,h,4))return false;unsigned key=sxcf16(h,1),rec=sxcf16(h+2,1);if(!key)break;if(key<5||key>1028||rec<92||(uint64_t)key+rec+4>n-q)break;if(!SXCF_ADD(c,hpofs_directory_record_prefix,p+q)||!SXCF_ADD(c,hpofs_directory_record,p+q+4+key))return false;q+=4+key+rec;}return true;
}
static bool sxcf_hpofs(sx_context*c){
 uint8_t b[4096],r[8];if(!sxcf_read(c,0,b,512)||(xx_rt_memcmp(b+54,"HPOFS\0\0\0",8)&&xx_rt_memcmp(b+54,"HPOFS   ",8)))return false;uint64_t bs=sxcf16(b+11,0),blocks=sxcf32(b+32,0);if(!blocks)blocks=sxcf16(b+19,0);if(bs<512||bs>4096||!sxcf_pow(bs)||!sxcf_span(c,0,blocks*bs)||!SXCF_ADD(c,hpofs_boot_sector,0))return false;
 if(sxcf_read(c,13*bs,b,252)&&!xx_rt_memcmp(b,"MEDINFO ",8)&&!SXCF_ADD(c,hpofs_media_information,13*bs))return false;
 if(sxcf_read(c,14*bs,b,24)&&!xx_rt_memcmp(b,"VOLINFO ",8)&&!SXCF_ADD(c,hpofs_volume_information,14*bs))return false;
 if(!sxcf_read(c,6*bs,b,92)||sxcf32(b,1)!=3)return true;uint32_t nr=sxcf32(b+76,1);if(!nr||nr>=blocks||!sxcf_read(c,(uint64_t)nr*bs,b,(size_t)bs)||xx_rt_memcmp(b,"SUBF",4))return true;unsigned count=sxcf16(b+16,1);if(count>(bs-32)/8)return true;
 if(!SXCF_ADD(c,hpofs_subfile_header,(uint64_t)nr*bs)||!SXCF_TABLE(c,hpofs_extent,(uint64_t)nr*bs+32,count))return false;
 /* Native directory runs can include gaps; only the declared extents are
  * traversed here. Optional gap leaves and file SUBF chains remain raw. */
 for(unsigned i=0;i<count&&c->count<SXCF_LIMIT;i++){xx_rt_memcpy(r,b+32+8*i,8);uint64_t first=sxcf32(r+4,1),n=sxcf16(r,1);if(first==UINT32_MAX)break;if(!n||first>=blocks||n>blocks-first||n>262144)continue;for(uint64_t j=0;j+4<=n&&c->count<SXCF_LIMIT;j+=4)if(!sxcf_hpofs_node(c,(first+j)*bs,bs*4))return false;}return true;
}
bool sx_hpofs_build(sx_context*c)
{
 return sxcf_hpofs(c);
}
