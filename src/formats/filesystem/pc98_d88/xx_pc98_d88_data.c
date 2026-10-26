/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pc98 d88 data structures, moved out of the diskimages schema family. */
#include "../../xx_format_schema_diskimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdi_d88_disk_header_fields[] = {
    SX_FIELD("disk_name","char[17]",0,17,SX_STRING),
    SX_FIELD("reserved","uint8[9]",17,9,SX_RESERVED),
    SX_FIELD("write_protect","uint8",26,1,SX_FLAGS),
    SX_FIELD("media_type","uint8",27,1,SX_ID),
    SX_FIELD("disk_size","uint32",28,4,SX_SIZE),
};
const sx_layout sxdi_d88_disk_header = {UINT32_C(0x60150019),"d88_disk_header",sxdi_d88_disk_header_fields,SX_COUNT(sxdi_d88_disk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_d88_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxdi_d88_track_offset = {UINT32_C(0x6015001a),"d88_track_offset",sxdi_d88_track_offset_fields,SX_COUNT(sxdi_d88_track_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_d88_sector_header_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("sector_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("density","uint8",6,1,SX_ID),
    SX_FIELD("deleted_mark","uint8",7,1,SX_FLAGS),
    SX_FIELD("status","uint8",8,1,SX_ID),
    SX_FIELD("reserved","uint8[5]",9,5,SX_RESERVED),
    SX_FIELD("stored_size","uint16",14,2,SX_SIZE),
};
const sx_layout sxdi_d88_sector_header = {UINT32_C(0x6015001b),"d88_sector_header",sxdi_d88_sector_header_fields,SX_COUNT(sxdi_d88_sector_header_fields),SX_LE};
static bool sxdi_d88(sx_context *c)
{
    uint64_t base=0;unsigned disks=0,sectors=0;
    while(base<(uint64_t)c->size&&disks<256&&sectors<32768){uint8_t h[32];uint32_t offsets[164],first=0;unsigned count=160;
        if(!sxdi_read(c,base,h,32))return disks!=0;uint32_t size=sxdi_le32(h+28);
        if(size<672||!sxdi_span(c,base,size))return disks!=0;
        for(unsigned i=0;i<160;i++){if(!sx_u32(c,(int64_t)(base+32+i*4),false,&offsets[i]))return false;if(offsets[i]&&!first)first=offsets[i];}
        if(first==688)count=164;else if(first!=672)return disks!=0;
        if(size<first)return disks!=0;for(unsigned i=160;i<count;i++)if(!sx_u32(c,(int64_t)(base+32+i*4),false,&offsets[i]))return false;
        uint32_t prev=0;for(unsigned i=0;i<count;i++)if(offsets[i]){if(offsets[i]<first||offsets[i]>size||(prev&&offsets[i]<prev))return disks!=0;prev=offsets[i];}
        if(!sx_add(c,&sxdi_d88_disk_header,(int64_t)base,32)||!sx_table(c,&sxdi_d88_track_offset,(int64_t)base+32,4,count))return false;disks++;
        for(unsigned i=0;i<count&&sectors<32768;i++){uint64_t at=offsets[i],end=size;if(!at||at==size)continue;
            for(unsigned j=i+1;j<count;j++)if(offsets[j]){end=offsets[j];break;}if(at>=end)continue;
            uint8_t s[16];if(end-at<16||!sxdi_read(c,base+at,s,16))continue;unsigned n=sxdi_le16(s+4);if(!n||n>128)continue;
            for(unsigned j=0;j<n&&sectors<32768;j++){if(end-at<16||!sxdi_read(c,base+at,s,16))break;uint32_t z=sxdi_le16(s+14);if(z>end-at-16)break;
                if(!sx_add(c,&sxdi_d88_sector_header,(int64_t)(base+at),16))return false;at+=16+z;sectors++;
            }
        }base+=size;
    }return disks!=0;
}
bool sx_pc98_d88_build(sx_context*c)
{
    return sxdi_d88(c);
}
