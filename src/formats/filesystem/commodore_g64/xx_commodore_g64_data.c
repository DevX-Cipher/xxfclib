/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Commodore G64 data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_g64_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("version","uint8",8,1,SX_NONE),
    SX_FIELD("halftrack_count","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("maximum_track_size","uint16",10,2,SX_SIZE),
};
const sx_layout sxse_g64_header = {0x602f0002U,"g64_header",sxse_g64_header_fields,SX_COUNT(sxse_g64_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_g64_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxse_g64_track_offset = {0x602f0003U,"g64_track_offset",sxse_g64_track_offset_fields,SX_COUNT(sxse_g64_track_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxse_g64_constant_speed_fields[] = {
    SX_FIELD("speed_zone","uint32",0,4,SX_NONE),
};
const sx_layout sxse_g64_constant_speed = {0x602f0004U,"g64_constant_speed",sxse_g64_constant_speed_fields,SX_COUNT(sxse_g64_constant_speed_fields),SX_LE};
static const xx_data_struct_field_desc sxse_g64_speed_offset_fields[] = {
    SX_FIELD("speed_map_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxse_g64_speed_offset = {0x602f0005U,"g64_speed_offset",sxse_g64_speed_offset_fields,SX_COUNT(sxse_g64_speed_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxse_g64_track_header_fields[] = {
    SX_FIELD("track_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxse_g64_track_header = {0x602f0006U,"g64_track_header",sxse_g64_track_header_fields,SX_COUNT(sxse_g64_track_header_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
#define SXSE_TABLE(c,l,p,z,n) sxse_put(c,&sxse_##l,p,z,n)
static bool sxse_g64(sx_context*c){uint8_t h[12],b[4];if(!sxse_read(c,0,h,12)||xx_rt_memcmp(h,"GCR-1541",8)||!h[9]||h[9]>84||!SXSE_ADD(c,g64_header,0,12))return false;unsigned n=h[9];uint64_t end=12+8*n;if(!SXSE_TABLE(c,g64_track_offset,12,4,n)||!sxse_span(c,12,8*n))return false;for(unsigned i=0;i<n;i++){if(!sxse_read(c,12+4*i,b,4))return false;uint64_t p=sxse_u32(b,0,false);if(p){uint16_t z;if(p<end||!sx_u16(c,(int64_t)p,false,&z)||!z||!sxse_span(c,p,2+(uint64_t)z)||!SXSE_ADD(c,g64_track_header,p,2))return false;}uint64_t q=12+4*n+4*i;if(!sxse_read(c,q,b,4))return false;uint32_t v=sxse_u32(b,0,false);if(!sxse_put(c,v<=3?&sxse_g64_constant_speed:&sxse_g64_speed_offset,q,4,1))return false;}return true;}
bool sx_commodore_g64_build(sx_context*c)
{
 return sxse_g64(c);
}
#undef SXSE_ADD
#undef SXSE_TABLE
