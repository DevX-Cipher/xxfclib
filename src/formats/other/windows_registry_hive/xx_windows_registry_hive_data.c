/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * windows registry hive data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_regf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("primary_sequence","uint32",4,4,SX_NONE),
 SX_FIELD("secondary_sequence","uint32",8,4,SX_NONE),
 SX_FIELD("last_written","uint64",12,8,SX_NONE),
 SX_FIELD("major","uint32",20,4,SX_NONE),
 SX_FIELD("minor","uint32",24,4,SX_NONE),
 SX_FIELD("file_type","uint32",28,4,SX_ID),
 SX_FIELD("file_format","uint32",32,4,SX_ID),
 SX_FIELD("root_cell_offset","uint32",36,4,SX_OFFSET),
 SX_FIELD("hive_bins_size","uint32",40,4,SX_SIZE),
 SX_FIELD("clustering_factor","uint32",44,4,SX_NONE),
 SX_FIELD("filename","uint8[64]",48,64,SX_NONE),
};
const sx_layout sxbx_regf_header = {UINT32_C(0x60300019),"regf_header",sxbx_regf_header_fields,SX_COUNT(sxbx_regf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_checksum_fields[] = {
 SX_FIELD("xor32","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxbx_regf_checksum = {UINT32_C(0x6030001a),"regf_checksum",sxbx_regf_checksum_fields,SX_COUNT(sxbx_regf_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_hbin_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("bin_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("bin_size","uint32",8,4,SX_SIZE),
 SX_FIELD("reserved1","uint32",12,4,SX_NONE),
 SX_FIELD("reserved2","uint32",16,4,SX_NONE),
 SX_FIELD("timestamp","uint64",20,8,SX_NONE),
 SX_FIELD("spare","uint32",28,4,SX_NONE),
};
const sx_layout sxbx_regf_hbin = {UINT32_C(0x6030001b),"regf_hbin",sxbx_regf_hbin_fields,SX_COUNT(sxbx_regf_hbin_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_cell_fields[] = {
 SX_FIELD("signed_cell_size","int32",0,4,SX_NONE),
};
const sx_layout sxbx_regf_cell = {UINT32_C(0x6030001c),"regf_cell",sxbx_regf_cell_fields,SX_COUNT(sxbx_regf_cell_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_nk_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("flags","uint16",2,2,SX_FLAGS),
 SX_FIELD("last_written","uint64",4,8,SX_NONE),
 SX_FIELD("access_bits","uint32",12,4,SX_NONE),
 SX_FIELD("parent_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("subkey_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("volatile_subkey_count","uint32",24,4,SX_COUNT_PROP),
 SX_FIELD("subkey_list_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("volatile_list_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("value_count","uint32",36,4,SX_COUNT_PROP),
 SX_FIELD("values_offset","uint32",40,4,SX_OFFSET),
 SX_FIELD("security_offset","uint32",44,4,SX_OFFSET),
 SX_FIELD("class_offset","uint32",48,4,SX_OFFSET),
 SX_FIELD("max_subkey_name_size","uint32",52,4,SX_SIZE),
 SX_FIELD("max_subkey_class_size","uint32",56,4,SX_SIZE),
 SX_FIELD("max_value_name_size","uint32",60,4,SX_SIZE),
 SX_FIELD("max_value_data_size","uint32",64,4,SX_SIZE),
 SX_FIELD("work_variable","uint32",68,4,SX_NONE),
 SX_FIELD("name_size","uint16",72,2,SX_SIZE),
 SX_FIELD("class_size","uint16",74,2,SX_SIZE),
};
const sx_layout sxbx_regf_nk = {UINT32_C(0x6030001d),"regf_nk",sxbx_regf_nk_fields,SX_COUNT(sxbx_regf_nk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_sk_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("reserved","uint16",2,2,SX_NONE),
 SX_FIELD("previous_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("next_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("reference_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("descriptor_size","uint32",16,4,SX_SIZE),
};
const sx_layout sxbx_regf_sk = {UINT32_C(0x6030001e),"regf_sk",sxbx_regf_sk_fields,SX_COUNT(sxbx_regf_sk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_list_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("entry_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxbx_regf_list = {UINT32_C(0x6030001f),"regf_list",sxbx_regf_list_fields,SX_COUNT(sxbx_regf_list_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_list_offset_fields[] = {
 SX_FIELD("cell_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxbx_regf_list_offset = {UINT32_C(0x60300020),"regf_list_offset",sxbx_regf_list_offset_fields,SX_COUNT(sxbx_regf_list_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_list_hash_fields[] = {
 SX_FIELD("cell_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("name_hash_or_hint","uint32",4,4,SX_NONE),
};
const sx_layout sxbx_regf_list_hash = {UINT32_C(0x60300021),"regf_list_hash",sxbx_regf_list_hash_fields,SX_COUNT(sxbx_regf_list_hash_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_vk_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("name_size","uint16",2,2,SX_SIZE),
 SX_FIELD("data_size_flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("data_offset_or_inline","uint32",8,4,SX_NONE),
 SX_FIELD("value_type","uint32",12,4,SX_ID),
 SX_FIELD("flags","uint16",16,2,SX_FLAGS),
 SX_FIELD("spare","uint16",18,2,SX_NONE),
};
const sx_layout sxbx_regf_vk = {UINT32_C(0x60300022),"regf_vk",sxbx_regf_vk_fields,SX_COUNT(sxbx_regf_vk_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_regf_db_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("segment_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("segment_list_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxbx_regf_db = {UINT32_C(0x60300023),"regf_db",sxbx_regf_db_fields,SX_COUNT(sxbx_regf_db_fields),SX_LE};
#define SXBX_LIMIT 20000U
static uint16_t sxbx16(const uint8_t *b,bool be){return (uint16_t)sxbx_uint(b,2,be);}
static bool sxbx_regf(sx_context*c){uint8_t b[80];if(!sxbx_add(c,&sxbx_regf_header,0)||!sxbx_add(c,&sxbx_regf_checksum,508))return false;uint64_t p=4096;for(unsigned bins=0;bins<SXBX_LIMIT&&c->count<SXBX_LIMIT;bins++){if(!sxbx_read(c,p,b,32)||xx_rt_memcmp(b,"hbin",4))break;uint64_t size=sxbx32(b+8,false);if(size<4096||size%4096||!sxbx_span(c,p,size))break;if(!sxbx_add(c,&sxbx_regf_hbin,p))return false;uint64_t q=p+32,end=p+size;while(q<end&&c->count<SXBX_LIMIT){if(!sxbx_read(c,q,b,4))break;int64_t signedsize=(int32_t)sxbx32(b,false);uint64_t z=signedsize<0?(uint64_t)-signedsize:(uint64_t)signedsize;if(z<8||z%8||z>end-q)break;if(!sxbx_add(c,&sxbx_regf_cell,q))return false;if(signedsize<0&&sxbx_read(c,q+4,b,(size_t)(z-4<76?z-4:76))){const sx_layout*l=NULL;uint64_t n=0;if(!xx_rt_memcmp(b,"nk",2)&&z>=80&&sxbx16(b+72,false)<=z-80)l=&sxbx_regf_nk;else if(!xx_rt_memcmp(b,"sk",2)&&z>=24&&sxbx32(b+16,false)<=z-24)l=&sxbx_regf_sk;else if(!xx_rt_memcmp(b,"vk",2)&&z>=24&&sxbx16(b+2,false)<=z-24)l=&sxbx_regf_vk;else if(!xx_rt_memcmp(b,"db",2)&&z>=12)l=&sxbx_regf_db;else if((!xx_rt_memcmp(b,"lf",2)||!xx_rt_memcmp(b,"lh",2)||!xx_rt_memcmp(b,"li",2)||!xx_rt_memcmp(b,"ri",2))&&z>=8){n=sxbx16(b+2,false);unsigned stride=(b[1]=='f'||b[1]=='h')?8:4;if(n<=(z-8)/stride){l=&sxbx_regf_list;if(!sxbx_table(c,stride==8?&sxbx_regf_list_hash:&sxbx_regf_list_offset,q+8,n))return false;}}if(l&&!sxbx_add(c,l,q+4))return false;}q+=z;}p=end;}return true;}
bool sx_windows_registry_hive_build(sx_context*c)
{
 return sxbx_regf(c);
}
