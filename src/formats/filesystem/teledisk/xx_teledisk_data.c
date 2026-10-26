/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TeleDisk data structures, moved out of the diskimages schema family. */
#include "../../xx_format_schema_diskimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdi_teledisk_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("volume_sequence","uint8",2,1,SX_ID),
    SX_FIELD("volume_id","uint8",3,1,SX_ID),
    SX_FIELD("version","uint8",4,1,SX_NONE),
    SX_FIELD("rate_and_fm","uint8",5,1,SX_FLAGS),
    SX_FIELD("drive_type","uint8",6,1,SX_ID),
    SX_FIELD("stepping_and_comment","uint8",7,1,SX_FLAGS),
    SX_FIELD("dos_allocation_mode","uint8",8,1,SX_FLAGS),
    SX_FIELD("head_count","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("header_crc","uint16",10,2,SX_CHECKSUM),
};
const sx_layout sxdi_teledisk_header = {UINT32_C(0x60150013),"teledisk_header",sxdi_teledisk_header_fields,SX_COUNT(sxdi_teledisk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_comment_fields[] = {
    SX_FIELD("crc","uint16",0,2,SX_CHECKSUM),
    SX_FIELD("text_size","uint16",2,2,SX_SIZE),
    SX_FIELD("year_since_1900","uint8",4,1,SX_NONE),
    SX_FIELD("month_zero_based","uint8",5,1,SX_NONE),
    SX_FIELD("day","uint8",6,1,SX_NONE),
    SX_FIELD("hour","uint8",7,1,SX_NONE),
    SX_FIELD("minute","uint8",8,1,SX_NONE),
    SX_FIELD("second","uint8",9,1,SX_NONE),
};
const sx_layout sxdi_teledisk_comment = {UINT32_C(0x60150014),"teledisk_comment",sxdi_teledisk_comment_fields,SX_COUNT(sxdi_teledisk_comment_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_track_fields[] = {
    SX_FIELD("sector_count","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("cylinder","uint8",1,1,SX_ID),
    SX_FIELD("head_and_fm","uint8",2,1,SX_FLAGS),
    SX_FIELD("header_crc_low","uint8",3,1,SX_CHECKSUM),
};
const sx_layout sxdi_teledisk_track = {UINT32_C(0x60150015),"teledisk_track",sxdi_teledisk_track_fields,SX_COUNT(sxdi_teledisk_track_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_end_fields[] = {
    SX_FIELD("end_marker","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxdi_teledisk_end = {UINT32_C(0x60150016),"teledisk_end",sxdi_teledisk_end_fields,SX_COUNT(sxdi_teledisk_end_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_sector_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("crc_low","uint8",5,1,SX_CHECKSUM),
};
const sx_layout sxdi_teledisk_sector = {UINT32_C(0x60150017),"teledisk_sector",sxdi_teledisk_sector_fields,SX_COUNT(sxdi_teledisk_sector_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_teledisk_data_block_fields[] = {
    SX_FIELD("encoded_size","uint16",0,2,SX_SIZE),
    SX_FIELD("method","uint8",2,1,SX_ID),
};
const sx_layout sxdi_teledisk_data_block = {UINT32_C(0x60150018),"teledisk_data_block",sxdi_teledisk_data_block_fields,SX_COUNT(sxdi_teledisk_data_block_fields),SX_LE};
static bool sxdi_td(sx_context *c)
{
    uint8_t h[12];if(!sxdi_read(c,0,h,12)||(xx_rt_memcmp(h,"TD",2)&&xx_rt_memcmp(h,"td",2))||!sx_add(c,&sxdi_teledisk_header,0,12))return false;
    if(h[0]=='t')return true;uint64_t at=12;unsigned sectors=0;
    if(h[7]&128){uint8_t m[10];if(!sxdi_read(c,at,m,10))return true;if(!sx_add(c,&sxdi_teledisk_comment,(int64_t)at,10))return false;at+=10+sxdi_le16(m+2);if(at>(uint64_t)c->size)return true;}
    for(unsigned i=0;i<4096&&sectors<32768&&at<(uint64_t)c->size;i++){uint8_t t[4];if(!sxdi_read(c,at,t,4))break;
        if(t[0]==255)return sx_add(c,&sxdi_teledisk_end,(int64_t)at,1);
        if(!sx_add(c,&sxdi_teledisk_track,(int64_t)at,4))return false;at+=4;
        for(unsigned j=0;j<t[0]&&sectors<32768;j++){uint8_t s[6];if(!sxdi_read(c,at,s,6)||s[3]>7)return true;
            if(!sx_add(c,&sxdi_teledisk_sector,(int64_t)at,6))return false;at+=6;sectors++;
            if(!(s[4]&0x30)){uint8_t d[3];if(!sxdi_read(c,at,d,3))return true;uint32_t n=sxdi_le16(d);if(!n||!sxdi_span(c,at,2U+n))return true;
                if(!sx_add(c,&sxdi_teledisk_data_block,(int64_t)at,3))return false;at+=2U+n;
            }
        }
    }return true;
}
bool sx_teledisk_build(sx_context*c)
{
    return sxdi_td(c);
}
