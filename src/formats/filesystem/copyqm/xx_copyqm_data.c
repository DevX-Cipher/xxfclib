/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CopyQM data structures, moved out of the diskimages schema family. */
#include "../../xx_format_schema_diskimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdi_copyqm_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("format_marker","uint8",2,1,SX_ID),
    SX_FIELD("sector_size","uint16",3,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sectors","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("root_entries","uint16",9,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors16","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("media_type","uint8",13,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sector_count","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("total_sectors32","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("description","char[60]",28,60,SX_STRING),
    SX_FIELD("blind_mode","uint8",88,1,SX_ID),
    SX_FIELD("density","uint8",89,1,SX_ID),
    SX_FIELD("used_cylinders","uint8",90,1,SX_COUNT_PROP),
    SX_FIELD("total_cylinders","uint8",91,1,SX_COUNT_PROP),
    SX_FIELD("decoded_data_crc","uint32",92,4,SX_CHECKSUM),
    SX_FIELD("volume_label","char[11]",96,11,SX_STRING),
    SX_FIELD("dos_time","uint16",107,2,SX_NONE),
    SX_FIELD("dos_date","uint16",109,2,SX_NONE),
    SX_FIELD("comment_size","uint16",111,2,SX_SIZE),
    SX_FIELD("first_sector_minus_one","uint8",113,1,SX_NONE),
    SX_FIELD("unknown_72","uint8[2]",114,2,SX_NONE),
    SX_FIELD("interleave","uint8",116,1,SX_NONE),
    SX_FIELD("skew","int8",117,1,SX_NONE),
    SX_FIELD("source_drive_type","uint8",118,1,SX_ID),
    SX_FIELD("unknown_77","uint8[13]",119,13,SX_NONE),
    SX_FIELD("header_checksum","uint8",132,1,SX_CHECKSUM),
};
const sx_layout sxdi_copyqm_header = {UINT32_C(0x60150006),"copyqm_header",sxdi_copyqm_header_fields,SX_COUNT(sxdi_copyqm_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_copyqm_rle_token_fields[] = {
    SX_FIELD("signed_run_length","int16",0,2,SX_NONE),
};
const sx_layout sxdi_copyqm_rle_token = {UINT32_C(0x60150007),"copyqm_rle_token",sxdi_copyqm_rle_token_fields,SX_COUNT(sxdi_copyqm_rle_token_fields),SX_LE};
static bool sxdi_cqm(sx_context *c)
{
    uint8_t h[133];if(!sxdi_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"CQ\024",3)||!sx_add(c,&sxdi_copyqm_header,0,133))return false;
    uint64_t at=133U+sxdi_le16(h+111);if(at>(uint64_t)c->size)return true;
    for(unsigned i=0;i<8192&&at<(uint64_t)c->size;i++){uint8_t b[2];if(!sxdi_read(c,at,b,2))break;
        int32_t n=(int16_t)sxdi_le16(b);if(!sx_add(c,&sxdi_copyqm_rle_token,(int64_t)at,2))return false;at+=2;if(!n)break;
        if(n<0){if(!sxdi_span(c,at,1))break;if(!sx_add(c,&sxdi_disk_fill_byte,(int64_t)at,1))return false;at++;}
        else {if(!sxdi_span(c,at,(unsigned)n))break;at+=(unsigned)n;}
    }return true;
}
bool sx_copyqm_build(sx_context*c)
{
    return sxdi_cqm(c);
}
