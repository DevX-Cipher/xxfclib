/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Dragon Cas data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_dragon_cas_block_header_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("block_type","uint8",1,1,SX_ID),
    SX_FIELD("payload_size","uint8",2,1,SX_SIZE),
};
const sx_layout sxdn_dragon_cas_block_header = {0x60780003U,"dragon_cas_block_header",sxdn_dragon_cas_block_header_fields,SX_COUNT(sxdn_dragon_cas_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_dragon_cas_file_header_fields[] = {
    SX_FIELD("filename","char[8]",0,8,SX_NONE),
    SX_FIELD("file_type","uint8",8,1,SX_ID),
    SX_FIELD("ascii_flag","uint8",9,1,SX_FLAGS),
    SX_FIELD("gap_flag","uint8",10,1,SX_FLAGS),
    SX_FIELD("execution_address","uint16",11,2,SX_ADDRESS),
    SX_FIELD("load_address","uint16",13,2,SX_ADDRESS),
};
const sx_layout sxdn_dragon_cas_file_header = {0x60780004U,"dragon_cas_file_header",sxdn_dragon_cas_file_header_fields,SX_COUNT(sxdn_dragon_cas_file_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdn_dragon_cas_block_checksum_fields[] = {
    SX_FIELD("checksum","uint8",0,1,SX_CHECKSUM),
};
const sx_layout sxdn_dragon_cas_block_checksum = {0x60780005U,"dragon_cas_block_checksum",sxdn_dragon_cas_block_checksum_fields,SX_COUNT(sxdn_dragon_cas_block_checksum_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
static bool sxdn_dragon(sx_context*c){uint64_t p=0;for(unsigned i=0;i<4096&&p<(uint64_t)c->size&&c->count<SXDN_LIMIT;i++){uint8_t h[3];while(p<(uint64_t)c->size&&sxdn_read(c,p,h,1)&&h[0]==0x55)p++;if(!sxdn_read(c,p,h,3)||h[0]!=0x3c||!sxdn_span(c,p,4+(uint64_t)h[2]))break;if(!SXDN_ADD(c,dragon_cas_block_header,p)||!SXDN_ADD(c,dragon_cas_block_checksum,p+3+h[2]))return false;if(!h[1]&&h[2]==15&&!SXDN_ADD(c,dragon_cas_file_header,p+3))return false;p+=4+h[2];}return c->count!=0;}
bool sx_dragon_cas_build(sx_context*c)
{
 return sxdn_dragon(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
