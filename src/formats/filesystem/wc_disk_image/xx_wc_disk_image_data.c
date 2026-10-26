/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WC_DISK_IMAGE data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_wcdisk_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint8",16,1,SX_ID),
    SX_FIELD("heads","uint8",17,1,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",18,1,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint8",19,1,SX_COUNT_PROP),
    SX_FIELD("extra_tracks","uint8[4]",20,4,SX_FLAGS),
    SX_FIELD("extra_flags","uint8",24,1,SX_FLAGS),
    SX_FIELD("reserved","byte[7]",25,7,SX_RESERVED),
};
const sx_layout sxst_wcdisk_header = {0x60370027U,"wcdisk_header",sxst_wcdisk_header_fields,SX_COUNT(sxst_wcdisk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxst_wcdisk_sector_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector","uint8",2,1,SX_NONE),
    SX_FIELD("cylinder","uint8",3,1,SX_NONE),
    SX_FIELD("data_crc","uint16",4,2,SX_CHECKSUM),
};
const sx_layout sxst_wcdisk_sector = {0x60370028U,"wcdisk_sector",sxst_wcdisk_sector_fields,SX_COUNT(sxst_wcdisk_sector_fields),SX_LE};
static const xx_data_struct_field_desc sxst_wcdisk_fill_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector","uint8",2,1,SX_NONE),
    SX_FIELD("cylinder","uint8",3,1,SX_NONE),
    SX_FIELD("fill_value","uint8",4,1,SX_ID),
    SX_FIELD("unused","uint8",5,1,SX_NONE),
};
const sx_layout sxst_wcdisk_fill = {0x60370029U,"wcdisk_fill",sxst_wcdisk_fill_fields,SX_COUNT(sxst_wcdisk_fill_fields),SX_LE};
static const xx_data_struct_field_desc sxst_wcdisk_extra_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_NONE),
    SX_FIELD("sector","uint8",2,1,SX_NONE),
    SX_FIELD("cylinder","uint8",3,1,SX_NONE),
    SX_FIELD("text_size","uint16",4,2,SX_SIZE),
};
const sx_layout sxst_wcdisk_extra = {0x6037002aU,"wcdisk_extra",sxst_wcdisk_extra_fields,SX_COUNT(sxst_wcdisk_extra_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
static bool sxst_wcdisk(sx_context*c){uint8_t h[32],b[6];if(!sxst_read(c,0,h,32)||!SXST_ADD(c,wcdisk_header,0))return false;if(!h[17]||h[17]>2||!h[18]||h[18]>18||!h[19]||h[19]>80)return true;uint64_t tracks=(uint64_t)h[17]*h[19],p=32;for(unsigned i=20;i<24;i++)tracks+=h[i]!=0;for(uint64_t i=0;i<tracks*h[18];i++){if(!sxst_read(c,p,b,6)||b[0]>2)return true;uint64_t z=b[0]==0?512:0;if(!sxst_span(c,p+6,z)||!sxst_put(c,b[0]==2?&sxst_wcdisk_fill:&sxst_wcdisk_sector,p,1))return true;p+=6+z;}for(unsigned i=0;i<2;i++)if(h[24]&(1U<<i)){if(!sxst_read(c,p,b,6)||b[0]!=3+i)return true;uint64_t z=sxst16(b+4);if(!sxst_span(c,p+6,z)||!SXST_ADD(c,wcdisk_extra,p))return true;p+=6+z;}return true;}
bool sx_wc_disk_image_build(sx_context*c)
{
 return sxst_wcdisk(c);
}
#undef SXST_ADD
