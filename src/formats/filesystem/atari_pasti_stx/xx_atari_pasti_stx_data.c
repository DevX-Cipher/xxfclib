/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Atari Pasti Stx data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_stx_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
    SX_FIELD("tool_id","uint16",6,2,SX_ID),
    SX_FIELD("reserved1","uint16",8,2,SX_RESERVED),
    SX_FIELD("track_count","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("revision","uint8",11,1,SX_NONE),
    SX_FIELD("reserved2","byte[4]",12,4,SX_RESERVED),
};
const sx_layout sxse_stx_header = {0x602f0051U,"stx_header",sxse_stx_header_fields,SX_COUNT(sxse_stx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_stx_track_fields[] = {
    SX_FIELD("record_size","uint32",0,4,SX_SIZE),
    SX_FIELD("fuzzy_mask_size","uint32",4,4,SX_SIZE),
    SX_FIELD("sector_count","uint16",8,2,SX_COUNT_PROP),
    SX_FIELD("flags","uint16",10,2,SX_FLAGS),
    SX_FIELD("track_length","uint16",12,2,SX_NONE),
    SX_FIELD("track_and_side","uint8",14,1,SX_FLAGS),
    SX_FIELD("track_type","uint8",15,1,SX_ID),
};
const sx_layout sxse_stx_track = {0x602f0052U,"stx_track",sxse_stx_track_fields,SX_COUNT(sxse_stx_track_fields),SX_LE};
static const xx_data_struct_field_desc sxse_stx_sector_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("bit_position","uint16",4,2,SX_NONE),
    SX_FIELD("read_time","uint16",6,2,SX_NONE),
    SX_FIELD("cylinder","uint8",8,1,SX_ID),
    SX_FIELD("head","uint8",9,1,SX_ID),
    SX_FIELD("sector_id","uint8",10,1,SX_ID),
    SX_FIELD("size_code","uint8",11,1,SX_NONE),
    SX_FIELD("id_crc","uint16be",12,2,SX_CHECKSUM),
    SX_FIELD("fdc_status","uint8",14,1,SX_FLAGS),
    SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
};
const sx_layout sxse_stx_sector = {0x602f0053U,"stx_sector",sxse_stx_sector_fields,SX_COUNT(sxse_stx_sector_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
#define SXSE_TABLE(c,l,p,z,n) sxse_put(c,&sxse_##l,p,z,n)
static bool sxse_stx(sx_context*c){uint8_t b[16];if(!sxse_read(c,0,b,16)||xx_rt_memcmp(b,"RSY\0",4)||!SXSE_ADD(c,stx_header,0,16))return false;unsigned n=b[10];uint64_t p=16;for(unsigned i=0;i<n;i++){if(!sxse_read(c,p,b,16))return false;uint64_t z=sxse_u32(b,0,false),fuzzy=sxse_u32(b,4,false);unsigned ns=sxse_u16(b,8,false),flags=sxse_u16(b,10,false);if(z<16||!sxse_span(c,p,z)||!SXSE_ADD(c,stx_track,p,16))return false;if(flags&1){if(ns>64||16+(uint64_t)ns*16+fuzzy>z||!SXSE_TABLE(c,stx_sector,p+16,16,ns))return false;}p+=z;}return true;}
bool sx_atari_pasti_stx_build(sx_context*c)
{
 return sxse_stx(c);
}
#undef SXSE_ADD
#undef SXSE_TABLE
