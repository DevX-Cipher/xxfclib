/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IMD data structures, moved out of the diskimages schema family. */
#include "../../xx_format_schema_diskimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdi_imd_track_header_fields[] = {
    SX_FIELD("mode","uint8",0,1,SX_ID),
    SX_FIELD("cylinder","uint8",1,1,SX_ID),
    SX_FIELD("head_and_maps","uint8",2,1,SX_FLAGS),
    SX_FIELD("sector_count","uint8",3,1,SX_COUNT_PROP),
    SX_FIELD("sector_size_code","uint8",4,1,SX_NONE),
};
const sx_layout sxdi_imd_track_header = {UINT32_C(0x60150009),"imd_track_header",sxdi_imd_track_header_fields,SX_COUNT(sxdi_imd_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_sector_id_fields[] = {
    SX_FIELD("sector_id","uint8",0,1,SX_ID),
};
const sx_layout sxdi_imd_sector_id = {UINT32_C(0x6015000a),"imd_sector_id",sxdi_imd_sector_id_fields,SX_COUNT(sxdi_imd_sector_id_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_cylinder_map_fields[] = {
    SX_FIELD("cylinder_id","uint8",0,1,SX_ID),
};
const sx_layout sxdi_imd_cylinder_map = {UINT32_C(0x6015000b),"imd_cylinder_map",sxdi_imd_cylinder_map_fields,SX_COUNT(sxdi_imd_cylinder_map_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_head_map_fields[] = {
    SX_FIELD("head_id","uint8",0,1,SX_ID),
};
const sx_layout sxdi_imd_head_map = {UINT32_C(0x6015000c),"imd_head_map",sxdi_imd_head_map_fields,SX_COUNT(sxdi_imd_head_map_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_size_map_fields[] = {
    SX_FIELD("sector_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxdi_imd_size_map = {UINT32_C(0x6015000d),"imd_size_map",sxdi_imd_size_map_fields,SX_COUNT(sxdi_imd_size_map_fields),SX_LE};
static const xx_data_struct_field_desc sxdi_imd_sector_status_fields[] = {
    SX_FIELD("status","uint8",0,1,SX_ID),
};
const sx_layout sxdi_imd_sector_status = {UINT32_C(0x6015000e),"imd_sector_status",sxdi_imd_sector_status_fields,SX_COUNT(sxdi_imd_sector_status_fields),SX_LE};
static bool sxdi_imd(sx_context *c)
{
    uint8_t b[1024];size_t n=c->size<1024?(size_t)c->size:1024;uint64_t at=0;unsigned tracks=0,sectors=0;
    if(n<4||!sxdi_read(c,0,b,n)||xx_rt_memcmp(b,"IMD ",4))return false;
    while(at<n&&b[at]!=0x1a)at++;if(at==n)return false;at++;
    while(at<(uint64_t)c->size&&tracks<4096&&sectors<32768){uint8_t h[5];uint64_t sizes=0;uint32_t fixed=0;
        if(!sxdi_read(c,at,h,5)||(h[0]>6&&h[0]!=9)||!h[3]||(h[2]&0x3e)||(h[4]>6&&h[4]!=255))return tracks!=0;
        uint64_t prefix=5+(uint64_t)h[3]*(1+((h[2]&128)!=0)+((h[2]&64)!=0)+(h[4]==255?2:0));
        if(!sxdi_span(c,at,prefix))return tracks!=0;
        if(!sx_add(c,&sxdi_imd_track_header,(int64_t)at,5))return false;tracks++;at+=5;
        if(!sx_table(c,&sxdi_imd_sector_id,(int64_t)at,1,h[3]))return false;at+=h[3];
        if(h[2]&128){if(!sx_table(c,&sxdi_imd_cylinder_map,(int64_t)at,1,h[3]))return false;at+=h[3];}
        if(h[2]&64){if(!sx_table(c,&sxdi_imd_head_map,(int64_t)at,1,h[3]))return false;at+=h[3];}
        if(h[4]==255){sizes=at;if(!sx_table(c,&sxdi_imd_size_map,(int64_t)at,2,h[3]))return false;at+=(uint64_t)h[3]*2;}else fixed=128U<<h[4];
        for(unsigned j=0;j<h[3]&&sectors<32768;j++){uint8_t status;uint16_t z=0;uint32_t len=fixed;
            if(sizes){if(!sx_u16(c,(int64_t)(sizes+j*2),false,&z))return false;len=z;}
            if(!len||len>8192||!sxdi_read(c,at,&status,1)||status>8)return true;
            if(!sx_add(c,&sxdi_imd_sector_status,(int64_t)at,1))return false;at++;sectors++;
            if(!status)continue;
            if(!(status&1)){if(!sxdi_span(c,at,1))return true;if(!sx_add(c,&sxdi_disk_fill_byte,(int64_t)at,1))return false;at++;}
            else {if(!sxdi_span(c,at,len))return true;at+=len;}
        }
    }return tracks!=0;
}
bool sx_imd_build(sx_context*c)
{
    return sxdi_imd(c);
}
