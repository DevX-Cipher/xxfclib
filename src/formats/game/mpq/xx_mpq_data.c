/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Blizzard MoPaQ (MPQ) game archive data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_mpq_header_v0_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("archive_size_32","uint32",8,4,SX_SIZE),
    SX_FIELD("format_version","uint16",12,2,SX_ID),
    SX_FIELD("sector_shift","uint16",14,2,SX_NONE),
    SX_FIELD("hash_table_offset_low","uint32",16,4,SX_OFFSET),
    SX_FIELD("block_table_offset_low","uint32",20,4,SX_OFFSET),
    SX_FIELD("hash_entry_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("block_entry_count","uint32",28,4,SX_COUNT_PROP),
};
const sx_layout sxar_mpq_header_v0 = {UINT32_C(0x601c0007),"mpq_header_v0",sxar_mpq_header_v0_fields,SX_COUNT(sxar_mpq_header_v0_fields),SX_LE};
static const xx_data_struct_field_desc sxar_mpq_header_v1_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("archive_size_32","uint32",8,4,SX_SIZE),
    SX_FIELD("format_version","uint16",12,2,SX_ID),
    SX_FIELD("sector_shift","uint16",14,2,SX_NONE),
    SX_FIELD("hash_table_offset_low","uint32",16,4,SX_OFFSET),
    SX_FIELD("block_table_offset_low","uint32",20,4,SX_OFFSET),
    SX_FIELD("hash_entry_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("block_entry_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("high_block_table_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("hash_table_offset_high","uint16",40,2,SX_NONE),
    SX_FIELD("block_table_offset_high","uint16",42,2,SX_NONE),
};
const sx_layout sxar_mpq_header_v1 = {UINT32_C(0x601c0008),"mpq_header_v1",sxar_mpq_header_v1_fields,SX_COUNT(sxar_mpq_header_v1_fields),SX_LE};
static const xx_data_struct_field_desc sxar_mpq_header_v2_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("archive_size_32","uint32",8,4,SX_SIZE),
    SX_FIELD("format_version","uint16",12,2,SX_ID),
    SX_FIELD("sector_shift","uint16",14,2,SX_NONE),
    SX_FIELD("hash_table_offset_low","uint32",16,4,SX_OFFSET),
    SX_FIELD("block_table_offset_low","uint32",20,4,SX_OFFSET),
    SX_FIELD("hash_entry_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("block_entry_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("high_block_table_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("hash_table_offset_high","uint16",40,2,SX_NONE),
    SX_FIELD("block_table_offset_high","uint16",42,2,SX_NONE),
    SX_FIELD("archive_size_64","uint64",44,8,SX_SIZE),
    SX_FIELD("bet_table_offset","uint64",52,8,SX_OFFSET),
    SX_FIELD("het_table_offset","uint64",60,8,SX_OFFSET),
};
const sx_layout sxar_mpq_header_v2 = {UINT32_C(0x601c0009),"mpq_header_v2",sxar_mpq_header_v2_fields,SX_COUNT(sxar_mpq_header_v2_fields),SX_LE};
static const xx_data_struct_field_desc sxar_mpq_header_v3_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",4,4,SX_SIZE),
    SX_FIELD("archive_size_32","uint32",8,4,SX_SIZE),
    SX_FIELD("format_version","uint16",12,2,SX_ID),
    SX_FIELD("sector_shift","uint16",14,2,SX_NONE),
    SX_FIELD("hash_table_offset_low","uint32",16,4,SX_OFFSET),
    SX_FIELD("block_table_offset_low","uint32",20,4,SX_OFFSET),
    SX_FIELD("hash_entry_count","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("block_entry_count","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("high_block_table_offset","uint64",32,8,SX_OFFSET),
    SX_FIELD("hash_table_offset_high","uint16",40,2,SX_NONE),
    SX_FIELD("block_table_offset_high","uint16",42,2,SX_NONE),
    SX_FIELD("archive_size_64","uint64",44,8,SX_SIZE),
    SX_FIELD("bet_table_offset","uint64",52,8,SX_OFFSET),
    SX_FIELD("het_table_offset","uint64",60,8,SX_OFFSET),
    SX_FIELD("hash_table_size","uint64",68,8,SX_SIZE),
    SX_FIELD("block_table_size","uint64",76,8,SX_SIZE),
    SX_FIELD("high_block_table_size","uint64",84,8,SX_SIZE),
    SX_FIELD("het_table_size","uint64",92,8,SX_SIZE),
    SX_FIELD("bet_table_size","uint64",100,8,SX_SIZE),
    SX_FIELD("raw_chunk_size","uint32",108,4,SX_SIZE),
    SX_FIELD("block_table_md5","uint8[16]",112,16,SX_CHECKSUM),
    SX_FIELD("hash_table_md5","uint8[16]",128,16,SX_CHECKSUM),
    SX_FIELD("high_block_table_md5","uint8[16]",144,16,SX_CHECKSUM),
    SX_FIELD("bet_table_md5","uint8[16]",160,16,SX_CHECKSUM),
    SX_FIELD("het_table_md5","uint8[16]",176,16,SX_CHECKSUM),
    SX_FIELD("header_md5","uint8[16]",192,16,SX_CHECKSUM),
};
const sx_layout sxar_mpq_header_v3 = {UINT32_C(0x601c000a),"mpq_header_v3",sxar_mpq_header_v3_fields,SX_COUNT(sxar_mpq_header_v3_fields),SX_LE};
static const xx_data_struct_field_desc sxar_mpq_high_block_entry_fields[] = {
    SX_FIELD("file_offset_high","uint16",0,2,SX_NONE),
};
const sx_layout sxar_mpq_high_block_entry = {UINT32_C(0x601c000b),"mpq_high_block_entry",sxar_mpq_high_block_entry_fields,SX_COUNT(sxar_mpq_high_block_entry_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_mpq(sx_context *c){uint8_t b[208];if(!sxar_read(c,0,b,32))return false;unsigned v=sxar16(b+12,false);const sx_layout *a[]={&sxar_mpq_header_v0,&sxar_mpq_header_v1,&sxar_mpq_header_v2,&sxar_mpq_header_v3};unsigned widths[]={32,44,68,208};if(v>3||!sxar_read(c,0,b,widths[v])||!sxar_add(c,a[v],0))return false;
 if(v==1){uint64_t p=sxar64(b+32),n=sxar32(b+28,false);if(p>=sxar32(b+4,false)&&p&&n<=SXAR_LIMIT&&sxar_span(c,p,n*2)&&!sx_table(c,&sxar_mpq_high_block_entry,(int64_t)p,2,n))return false;}return true;}
bool sx_mpq_build(sx_context*c)
{
 return sxar_mpq(c);
}
