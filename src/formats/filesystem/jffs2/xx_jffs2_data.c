/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JFFS2 data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_jffs2_common_header_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_common_header_le = {0x60290040U,"jffs2_common_header_le",sx_dm_jffs2_common_header_le_fields,SX_COUNT(sx_dm_jffs2_common_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_jffs2_directory_entry_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("parent_inode","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("inode","uint32",20,4,SX_ID),
    SX_FIELD("modification_time","uint32",24,4,SX_TIME),
    SX_FIELD("name_size","uint8",28,1,SX_SIZE),
    SX_FIELD("type","uint8",29,1,SX_ID),
    SX_FIELD("unused","byte[2]",30,2,SX_RESERVED),
    SX_FIELD("node_crc","uint32",32,4,SX_CHECKSUM),
    SX_FIELD("name_crc","uint32",36,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_directory_entry_le = {0x60290041U,"jffs2_directory_entry_le",sx_dm_jffs2_directory_entry_le_fields,SX_COUNT(sx_dm_jffs2_directory_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_jffs2_inode_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("mode","uint32",20,4,SX_FLAGS),
    SX_FIELD("uid","uint16",24,2,SX_ID),
    SX_FIELD("gid","uint16",26,2,SX_ID),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
    SX_FIELD("access_time","uint32",32,4,SX_TIME),
    SX_FIELD("modification_time","uint32",36,4,SX_TIME),
    SX_FIELD("change_time","uint32",40,4,SX_TIME),
    SX_FIELD("file_offset","uint32",44,4,SX_OFFSET),
    SX_FIELD("compressed_size","uint32",48,4,SX_SIZE),
    SX_FIELD("decompressed_size","uint32",52,4,SX_SIZE),
    SX_FIELD("compression","uint8",56,1,SX_ID),
    SX_FIELD("user_compression","uint8",57,1,SX_ID),
    SX_FIELD("flags","uint16",58,2,SX_FLAGS),
    SX_FIELD("data_crc","uint32",60,4,SX_CHECKSUM),
    SX_FIELD("node_crc","uint32",64,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_inode_le = {0x60290042U,"jffs2_inode_le",sx_dm_jffs2_inode_le_fields,SX_COUNT(sx_dm_jffs2_inode_le_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_jffs2_xattr_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("xid","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("prefix","uint8",20,1,SX_ID),
    SX_FIELD("name_length","uint8",21,1,SX_SIZE),
    SX_FIELD("value_length","uint16",22,2,SX_SIZE),
    SX_FIELD("data_crc","uint32",24,4,SX_CHECKSUM),
    SX_FIELD("node_crc","uint32",28,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_xattr_le = {0x60290043U,"jffs2_xattr_le",sx_dm_jffs2_xattr_le_fields,SX_COUNT(sx_dm_jffs2_xattr_le_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_jffs2_xref_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("xid","uint32",16,4,SX_ID),
    SX_FIELD("sequence_number","uint32",20,4,SX_NONE),
    SX_FIELD("node_crc","uint32",24,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_xref_le = {0x60290044U,"jffs2_xref_le",sx_dm_jffs2_xref_le_fields,SX_COUNT(sx_dm_jffs2_xref_le_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_jffs2_common_header_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_common_header_be = {0x60290048U,"jffs2_common_header_be",sx_dm_jffs2_common_header_be_fields,SX_COUNT(sx_dm_jffs2_common_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_jffs2_directory_entry_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("parent_inode","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("inode","uint32",20,4,SX_ID),
    SX_FIELD("modification_time","uint32",24,4,SX_TIME),
    SX_FIELD("name_size","uint8",28,1,SX_SIZE),
    SX_FIELD("type","uint8",29,1,SX_ID),
    SX_FIELD("unused","byte[2]",30,2,SX_RESERVED),
    SX_FIELD("node_crc","uint32",32,4,SX_CHECKSUM),
    SX_FIELD("name_crc","uint32",36,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_directory_entry_be = {0x60290049U,"jffs2_directory_entry_be",sx_dm_jffs2_directory_entry_be_fields,SX_COUNT(sx_dm_jffs2_directory_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_jffs2_inode_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("mode","uint32",20,4,SX_FLAGS),
    SX_FIELD("uid","uint16",24,2,SX_ID),
    SX_FIELD("gid","uint16",26,2,SX_ID),
    SX_FIELD("file_size","uint32",28,4,SX_SIZE),
    SX_FIELD("access_time","uint32",32,4,SX_TIME),
    SX_FIELD("modification_time","uint32",36,4,SX_TIME),
    SX_FIELD("change_time","uint32",40,4,SX_TIME),
    SX_FIELD("file_offset","uint32",44,4,SX_OFFSET),
    SX_FIELD("compressed_size","uint32",48,4,SX_SIZE),
    SX_FIELD("decompressed_size","uint32",52,4,SX_SIZE),
    SX_FIELD("compression","uint8",56,1,SX_ID),
    SX_FIELD("user_compression","uint8",57,1,SX_ID),
    SX_FIELD("flags","uint16",58,2,SX_FLAGS),
    SX_FIELD("data_crc","uint32",60,4,SX_CHECKSUM),
    SX_FIELD("node_crc","uint32",64,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_inode_be = {0x6029004aU,"jffs2_inode_be",sx_dm_jffs2_inode_be_fields,SX_COUNT(sx_dm_jffs2_inode_be_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_jffs2_xattr_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("xid","uint32",12,4,SX_ID),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("prefix","uint8",20,1,SX_ID),
    SX_FIELD("name_length","uint8",21,1,SX_SIZE),
    SX_FIELD("value_length","uint16",22,2,SX_SIZE),
    SX_FIELD("data_crc","uint32",24,4,SX_CHECKSUM),
    SX_FIELD("node_crc","uint32",28,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_xattr_be = {0x6029004bU,"jffs2_xattr_be",sx_dm_jffs2_xattr_be_fields,SX_COUNT(sx_dm_jffs2_xattr_be_fields),SX_BE};
static const xx_data_struct_field_desc sx_dm_jffs2_xref_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("xid","uint32",16,4,SX_ID),
    SX_FIELD("sequence_number","uint32",20,4,SX_NONE),
    SX_FIELD("node_crc","uint32",24,4,SX_CHECKSUM),
};
const sx_layout sx_dm_jffs2_xref_be = {0x6029004cU,"jffs2_xref_be",sx_dm_jffs2_xref_be_fields,SX_COUNT(sx_dm_jffs2_xref_be_fields),SX_BE};
static bool sx_dm_jffs(sx_context*c){uint8_t h[12];uint64_t limit=(uint64_t)c->size;if(limit>67108864)limit=67108864;for(uint64_t p=0;p+12<=limit&&c->count<24000;){if(!sx_dm_read(c,p,h,12))return false;bool be=sx_dm_u16(h,0,true)==0x1985;uint64_t z=sx_dm_u32(h,4,be);if(sx_dm_u16(h,0,be)!=0x1985||z<12||!sx_dm_span(c,p,z)||sx_dm_u32(h,8,be)!=(xx_crc32_calc(UINT32_MAX,h,8)^UINT32_MAX)){p+=4;continue;}uint32_t t=sx_dm_u16(h,2,be);const sx_layout*l=be?&sx_dm_jffs2_common_header_be:&sx_dm_jffs2_common_header_le;uint64_t n=12;switch(t|0x2000){case 0xe001:l=be?&sx_dm_jffs2_directory_entry_be:&sx_dm_jffs2_directory_entry_le;n=40;break;case 0xe002:l=be?&sx_dm_jffs2_inode_be:&sx_dm_jffs2_inode_le;n=68;break;case 0xe008:l=be?&sx_dm_jffs2_xattr_be:&sx_dm_jffs2_xattr_le;n=32;break;case 0xe009:l=be?&sx_dm_jffs2_xref_be:&sx_dm_jffs2_xref_le;n=28;break;}if(n>z){l=be?&sx_dm_jffs2_common_header_be:&sx_dm_jffs2_common_header_le;n=12;}if(!sx_dm_add(c,l,p,n))return false;p+=(z+3)&~UINT64_C(3);}return c->count!=0;}
bool sx_jffs2_build(sx_context*c)
{
 return sx_dm_jffs(c);
}
