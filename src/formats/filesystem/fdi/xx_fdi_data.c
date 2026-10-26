/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FDI data structures, moved out of the diskimages schema family. */
#include "../../xx_format_schema_diskimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdi_fdi_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("write_protected","uint8",3,1,SX_FLAGS),
    SX_FIELD("cylinders","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("text_offset","uint16",8,2,SX_OFFSET),
    SX_FIELD("data_offset","uint16",10,2,SX_OFFSET),
    SX_FIELD("extra_header_size","uint16",12,2,SX_SIZE),
};
const sx_layout sxdi_fdi_header = {UINT32_C(0x6015000f),"fdi_header",sxdi_fdi_header_fields,SX_COUNT(sxdi_fdi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_fdi_track_header_fields[] = {
    SX_FIELD("track_data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("reserved","uint16",4,2,SX_RESERVED),
    SX_FIELD("sector_count","uint8",6,1,SX_COUNT_PROP),
};
const sx_layout sxdi_fdi_track_header = {UINT32_C(0x60150010),"fdi_track_header",sxdi_fdi_track_header_fields,SX_COUNT(sxdi_fdi_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_fdi_sector_header_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("flags","uint8",4,1,SX_FLAGS),
    SX_FIELD("data_offset","uint16",5,2,SX_OFFSET),
};
const sx_layout sxdi_fdi_sector_header = {UINT32_C(0x60150011),"fdi_sector_header",sxdi_fdi_sector_header_fields,SX_COUNT(sxdi_fdi_sector_header_fields),SX_LE};
static bool sxdi_fdi(sx_context *c)
{
    uint8_t h[14];if(!sxdi_read(c,0,h,14)||xx_rt_memcmp(h,"FDI",3)||!sx_add(c,&sxdi_fdi_header,0,14))return false;
    uint32_t cyl=sxdi_le16(h+4),heads=sxdi_le16(h+6);uint64_t at=14U+sxdi_le16(h+12),limit=sxdi_le16(h+10),text=sxdi_le16(h+8);
    if(!cyl||cyl>256||!heads||heads>2||at>limit||limit>(uint64_t)c->size)return true;if(text>=at&&text<limit)limit=text;
    for(uint32_t i=0;i<cyl*heads;i++){uint8_t t[7];if(at>limit||limit-at<7||!sxdi_read(c,at,t,7))break;uint64_t bytes=7U+(uint64_t)t[6]*7;
        if(bytes>limit-at)break;if(!sx_add(c,&sxdi_fdi_track_header,(int64_t)at,7))return false;
        if(t[6]&&!sx_table(c,&sxdi_fdi_sector_header,(int64_t)at+7,7,t[6]))return false;at+=bytes;
    }return true;
}
bool sx_fdi_build(sx_context*c)
{
    return sxdi_fdi(c);
}
