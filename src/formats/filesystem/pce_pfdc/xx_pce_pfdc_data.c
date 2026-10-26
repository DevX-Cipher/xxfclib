/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PCE PFDC (v0, v1, v2) data structures, moved out of the pcedisks schema family. */
#include "../../xx_format_schema_pcedisks.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_pc_pfdc_legacy_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint16",4,2,SX_ID),
    SX_FIELD("version_minor","uint16",6,2,SX_ID),
    SX_FIELD("sector_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("sector_records_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sx_pc_pfdc_legacy_header = {0x60140001U,"pfdc_legacy_header",sx_pc_pfdc_legacy_header_fields,SX_COUNT(sx_pc_pfdc_legacy_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_pc_pfdc_v2_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_major","uint16",4,2,SX_ID),
    SX_FIELD("version_minor","uint16",6,2,SX_ID),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
    SX_FIELD("chunks_offset","uint32",12,4,SX_OFFSET),
};
const sx_layout sx_pc_pfdc_v2_header = {0x60140002U,"pfdc_v2_header",sx_pc_pfdc_v2_header_fields,SX_COUNT(sx_pc_pfdc_v2_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_pc_pfdc_v2_chunk_fields[] = {
    SX_FIELD("chunk_id","char[2]",0,2,SX_ID),
    SX_FIELD("payload_size","uint16",2,2,SX_SIZE),
};
const sx_layout sx_pc_pfdc_v2_chunk = {0x60140007U,"pfdc_v2_chunk",sx_pc_pfdc_v2_chunk_fields,SX_COUNT(sx_pc_pfdc_v2_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sx_pc_pfdc_file_crc_fields[] = {
    SX_FIELD("file_crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sx_pc_pfdc_file_crc = {0x6014000aU,"pfdc_file_crc",sx_pc_pfdc_file_crc_fields,SX_COUNT(sx_pc_pfdc_file_crc_fields),SX_BE};
static const xx_data_struct_field_desc sx_pc_pce_fill_byte_fields[] = {
    SX_FIELD("filler","uint8",0,1,SX_ID),
};
const sx_layout sx_pc_pce_fill_byte = {0x6014000dU,"pce_fill_byte",sx_pc_pce_fill_byte_fields,SX_COUNT(sx_pc_pce_fill_byte_fields),SX_BE};
static bool sx_pc_legacy(sx_context *c,unsigned version)
{
    uint32_t count,offset;
    if(!sx_u32(c,8,true,&count)||!sx_u32(c,12,true,&offset)||!count||count>4096||offset<16||!sx_add(c,&sx_pc_pfdc_legacy_header,0,16))return false;
    uint64_t at=offset;
    for(uint32_t i=0;i<count;i++) {
        uint8_t b[16];uint32_t h=version?16:12;
        if(!sx_pc_span(c,at,h)||!sx_read(c,(int64_t)at,b,h))return false;
        uint32_t flags=version?xx_data_get_u32(b,h,12,true):b[5],size=xx_data_get_u16(b,h,6,true),stored=(flags&0x80U)?1:size;
        if(!sx_pc_span(c,at+h,stored)||!sx_add(c,version?&sx_pc_pfdc_v1_sector:&sx_pc_pfdc_v0_sector,(int64_t)at,h))return false;
        if((flags&0x80U)&&!sx_add(c,&sx_pc_pce_fill_byte,(int64_t)(at+h),1))return false;
        at+=h+stored;
    }
    return at==(uint64_t)c->size;
}
static bool sx_pc_v2(sx_context *c)
{
    uint32_t offset;if(c->size<28||!sx_u32(c,12,true,&offset)||offset<16||!sx_add(c,&sx_pc_pfdc_v2_header,0,16))return false;
    uint64_t at=offset,end=(uint64_t)c->size-4;
    for(unsigned n=0;n<8192&&at<end;n++) {
        uint8_t b[4];if(at>end||end-at<8||!sx_read(c,(int64_t)at,b,4))return false;
        uint32_t size=xx_data_get_u16(b,4,2,true);if(size>end-at-8)return false;
        if(!sx_add(c,&sx_pc_pfdc_v2_chunk,(int64_t)at,4)||!sx_add(c,&sx_pc_pce_chunk_crc,(int64_t)(at+4+size),4))return false;
        if(b[0]=='S'&&b[1]=='C') {
            uint8_t h[12];if(size<12||!sx_read(c,(int64_t)at+4,h,12)||!sx_add(c,&sx_pc_pfdc_v2_sector,(int64_t)at+4,12))return false;
            if(h[0]&0x80U)if(size<13||!sx_add(c,&sx_pc_pce_fill_byte,(int64_t)at+16,1))return false;
        }
        at+=size+8;
    }
    return at==end&&sx_add(c,&sx_pc_pfdc_file_crc,(int64_t)end,4);
}
bool sx_pce_pfdc_build(sx_context*c)
{
    bool ok=false;
    switch(c->f->file_type) {
    case XX_FILE_TYPE_PCE_PFDC_V0:ok=sx_pc_legacy(c,0);break;
    case XX_FILE_TYPE_PCE_PFDC_V1:ok=sx_pc_legacy(c,1);break;
    case XX_FILE_TYPE_PCE_PFDC_V2:ok=sx_pc_v2(c);break;
    }
    return ok;
}
