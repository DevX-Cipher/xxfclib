/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PARTCLONE_IMAGE data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_partclone_header_le_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("creator_version","char[14]",16,14,SX_NONE),
    SX_FIELD("image_version","char[4]",30,4,SX_NONE),
    SX_FIELD("byte_order_marker","uint16",34,2,SX_ID),
    SX_FIELD("filesystem","char[16]",36,16,SX_NONE),
    SX_FIELD("device_size","uint64",52,8,SX_SIZE),
    SX_FIELD("total_blocks","uint64",60,8,SX_COUNT_PROP),
    SX_FIELD("superblock_used_blocks","uint64",68,8,SX_COUNT_PROP),
    SX_FIELD("bitmap_used_blocks","uint64",76,8,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",84,4,SX_SIZE),
    SX_FIELD("feature_size","uint32",88,4,SX_SIZE),
    SX_FIELD("options_image_version","uint16",92,2,SX_NONE),
    SX_FIELD("cpu_bits","uint16",94,2,SX_NONE),
    SX_FIELD("checksum_mode","uint16",96,2,SX_ID),
    SX_FIELD("checksum_size","uint16",98,2,SX_SIZE),
    SX_FIELD("blocks_per_checksum","uint32",100,4,SX_COUNT_PROP),
    SX_FIELD("reseed_checksum","uint8",104,1,SX_FLAGS),
    SX_FIELD("bitmap_mode","uint8",105,1,SX_ID),
    SX_FIELD("header_crc","uint32",106,4,SX_CHECKSUM),
};
const sx_layout sxsl_partclone_header_le = {0x60330037U,"partclone_header_le",sxsl_partclone_header_le_fields,SX_COUNT(sxsl_partclone_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_partclone_bitmap_crc_le_fields[] = {
    SX_FIELD("bitmap_crc","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxsl_partclone_bitmap_crc_le = {0x60330038U,"partclone_bitmap_crc_le",sxsl_partclone_bitmap_crc_le_fields,SX_COUNT(sxsl_partclone_bitmap_crc_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_partclone_header_be_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("creator_version","char[14]",16,14,SX_NONE),
    SX_FIELD("image_version","char[4]",30,4,SX_NONE),
    SX_FIELD("byte_order_marker","uint16",34,2,SX_ID),
    SX_FIELD("filesystem","char[16]",36,16,SX_NONE),
    SX_FIELD("device_size","uint64",52,8,SX_SIZE),
    SX_FIELD("total_blocks","uint64",60,8,SX_COUNT_PROP),
    SX_FIELD("superblock_used_blocks","uint64",68,8,SX_COUNT_PROP),
    SX_FIELD("bitmap_used_blocks","uint64",76,8,SX_COUNT_PROP),
    SX_FIELD("block_size","uint32",84,4,SX_SIZE),
    SX_FIELD("feature_size","uint32",88,4,SX_SIZE),
    SX_FIELD("options_image_version","uint16",92,2,SX_NONE),
    SX_FIELD("cpu_bits","uint16",94,2,SX_NONE),
    SX_FIELD("checksum_mode","uint16",96,2,SX_ID),
    SX_FIELD("checksum_size","uint16",98,2,SX_SIZE),
    SX_FIELD("blocks_per_checksum","uint32",100,4,SX_COUNT_PROP),
    SX_FIELD("reseed_checksum","uint8",104,1,SX_FLAGS),
    SX_FIELD("bitmap_mode","uint8",105,1,SX_ID),
    SX_FIELD("header_crc","uint32",106,4,SX_CHECKSUM),
};
const sx_layout sxsl_partclone_header_be = {0x60330039U,"partclone_header_be",sxsl_partclone_header_be_fields,SX_COUNT(sxsl_partclone_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_partclone_bitmap_crc_be_fields[] = {
    SX_FIELD("bitmap_crc","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxsl_partclone_bitmap_crc_be = {0x6033003aU,"partclone_bitmap_crc_be",sxsl_partclone_bitmap_crc_be_fields,SX_COUNT(sxsl_partclone_bitmap_crc_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_partclone_bitmap_byte_fields[] = {
    SX_FIELD("allocated_bits","uint8",0,1,SX_FLAGS),
};
const sx_layout sxsl_partclone_bitmap_byte = {0x60330054U,"partclone_bitmap_byte",sxsl_partclone_bitmap_byte_fields,SX_COUNT(sxsl_partclone_bitmap_byte_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_partclone_data_checksum4_fields[] = {
    SX_FIELD("checksum","byte[4]",0,4,SX_CHECKSUM),
};
const sx_layout sxsl_partclone_data_checksum4 = {0x60330055U,"partclone_data_checksum4",sxsl_partclone_data_checksum4_fields,SX_COUNT(sxsl_partclone_data_checksum4_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_partclone_data_checksum16_fields[] = {
    SX_FIELD("checksum","byte[16]",0,16,SX_CHECKSUM),
};
const sx_layout sxsl_partclone_data_checksum16 = {0x60330056U,"partclone_data_checksum16",sxsl_partclone_data_checksum16_fields,SX_COUNT(sxsl_partclone_data_checksum16_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ROWS 1048576U
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_partclone(sx_context*c){uint8_t h[110];if(!sxsl_read(c,0,h,110))return false;bool be=h[34]==0xc0&&h[35]==0xde;if(!sxsl_put(c,be?&sxsl_partclone_header_be:&sxsl_partclone_header_le,0,1))return false;uint64_t total=sxsl_uint(h+60,8,be),used=sxsl_uint(h+76,8,be),block=sxsl_uint(h+84,4,be),per=sxsl_uint(h+100,4,be),cs=sxsl_uint(h+98,2,be),map=total/8+(total%8!=0);if(!sxsl_span(c,110,map)||!sxsl_span(c,110+map,4))return true;if(map<=SXSL_ROWS&&!SXSL_TABLE(c,partclone_bitmap_byte,110,map))return false;if(!sxsl_put(c,be?&sxsl_partclone_bitmap_crc_be:&sxsl_partclone_bitmap_crc_le,110+map,1))return false;if(!per||!block||(cs!=4&&cs!=16))return true;uint64_t p=114+map;for(unsigned i=0;used&&i<SXSL_LIMIT&&c->count<SXSL_LIMIT;i++){uint64_t n=used<per?used:per;if(n>UINT64_MAX/block||!sxsl_span(c,p,n*block)||!sxsl_span(c,p+n*block,cs))break;p+=n*block;if(!sxsl_put(c,cs==4?&sxsl_partclone_data_checksum4:&sxsl_partclone_data_checksum16,p,1))return false;p+=cs;used-=n;}return true;}
bool sx_partclone_image_build(sx_context*c)
{
bool ok=false;
ok=sxsl_partclone(c);
return ok&&sxsl_finish(c);
}
