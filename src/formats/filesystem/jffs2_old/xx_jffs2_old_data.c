/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Jffs2 Old data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_old_jffs2_common_header_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
const sx_layout sxdn_old_jffs2_common_header_le = {0x6078004aU,"old_jffs2_common_header_le",sxdn_old_jffs2_common_header_le_fields,SX_COUNT(sxdn_old_jffs2_common_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_old_jffs2_directory_entry_le_fields[] = {
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
const sx_layout sxdn_old_jffs2_directory_entry_le = {0x6078004bU,"old_jffs2_directory_entry_le",sxdn_old_jffs2_directory_entry_le_fields,SX_COUNT(sxdn_old_jffs2_directory_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_old_jffs2_inode_le_fields[] = {
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
const sx_layout sxdn_old_jffs2_inode_le = {0x6078004cU,"old_jffs2_inode_le",sxdn_old_jffs2_inode_le_fields,SX_COUNT(sxdn_old_jffs2_inode_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_old_jffs2_xattr_le_fields[] = {
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
const sx_layout sxdn_old_jffs2_xattr_le = {0x6078004dU,"old_jffs2_xattr_le",sxdn_old_jffs2_xattr_le_fields,SX_COUNT(sxdn_old_jffs2_xattr_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_old_jffs2_xref_le_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("xid","uint32",16,4,SX_ID),
    SX_FIELD("sequence_number","uint32",20,4,SX_NONE),
    SX_FIELD("node_crc","uint32",24,4,SX_CHECKSUM),
};
const sx_layout sxdn_old_jffs2_xref_le = {0x6078004eU,"old_jffs2_xref_le",sxdn_old_jffs2_xref_le_fields,SX_COUNT(sxdn_old_jffs2_xref_le_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_old_jffs2_common_header_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
const sx_layout sxdn_old_jffs2_common_header_be = {0x6078004fU,"old_jffs2_common_header_be",sxdn_old_jffs2_common_header_be_fields,SX_COUNT(sxdn_old_jffs2_common_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_old_jffs2_directory_entry_be_fields[] = {
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
const sx_layout sxdn_old_jffs2_directory_entry_be = {0x60780050U,"old_jffs2_directory_entry_be",sxdn_old_jffs2_directory_entry_be_fields,SX_COUNT(sxdn_old_jffs2_directory_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_old_jffs2_inode_be_fields[] = {
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
const sx_layout sxdn_old_jffs2_inode_be = {0x60780051U,"old_jffs2_inode_be",sxdn_old_jffs2_inode_be_fields,SX_COUNT(sxdn_old_jffs2_inode_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_old_jffs2_xattr_be_fields[] = {
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
const sx_layout sxdn_old_jffs2_xattr_be = {0x60780052U,"old_jffs2_xattr_be",sxdn_old_jffs2_xattr_be_fields,SX_COUNT(sxdn_old_jffs2_xattr_be_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_old_jffs2_xref_be_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("node_type","uint16",2,2,SX_ID),
    SX_FIELD("total_length","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("inode","uint32",12,4,SX_ID),
    SX_FIELD("xid","uint32",16,4,SX_ID),
    SX_FIELD("sequence_number","uint32",20,4,SX_NONE),
    SX_FIELD("node_crc","uint32",24,4,SX_CHECKSUM),
};
const sx_layout sxdn_old_jffs2_xref_be = {0x60780053U,"old_jffs2_xref_be",sxdn_old_jffs2_xref_be_fields,SX_COUNT(sxdn_old_jffs2_xref_be_fields),SX_BE};
#define SXDN_LIMIT 24000U
#define DN_PAIR(n,be) ((be)?&sxdn_##n##_be:&sxdn_##n##_le)
static bool sxdn_oldjffs(sx_context*c){uint8_t h[12];uint64_t end=(uint64_t)c->size;if(end>67108864)end=67108864;for(uint64_t p=0;p+12<=end&&c->count<SXDN_LIMIT;){if(!sxdn_read(c,p,h,12))return false;bool be=sxdn16(h,1)==0x1984;uint64_t n=sxdn32(h+4,be);if(sxdn16(h,be)!=0x1984||n<12||!sxdn_span(c,p,n)||sxdn32(h+8,be)!=(xx_crc32_calc(UINT32_MAX,h,8)^UINT32_MAX)){p+=4;continue;}const sx_layout*l=DN_PAIR(old_jffs2_common_header,be);unsigned z=12;switch(sxdn16(h+2,be)|0x2000){case 0xe001:l=DN_PAIR(old_jffs2_directory_entry,be);z=40;break;case 0xe002:l=DN_PAIR(old_jffs2_inode,be);z=68;break;case 0xe008:l=DN_PAIR(old_jffs2_xattr,be);z=32;break;case 0xe009:l=DN_PAIR(old_jffs2_xref,be);z=28;break;}if(z>n)l=DN_PAIR(old_jffs2_common_header,be);if(!sxdn_put(c,l,p,1))return false;p+=(n+3)&~UINT64_C(3);}return c->count!=0;}
bool sx_jffs2_old_build(sx_context*c)
{
 return sxdn_oldjffs(c);
}
#undef SXDN_LIMIT
#undef DN_PAIR
