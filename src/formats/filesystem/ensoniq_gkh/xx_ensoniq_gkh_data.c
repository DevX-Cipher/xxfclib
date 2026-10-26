/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ensoniq gkh data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_gkh_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("number_type","uint8",4,1,SX_ID),
    SX_FIELD("version","uint8",5,1,SX_ID),
    SX_FIELD("tag_count","uint16",6,2,SX_COUNT_PROP),
};
const sx_layout sxdleg_gkh_header = {0x60750031U,"gkh_header",sxdleg_gkh_header_fields,SX_COUNT(sxdleg_gkh_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_gkh_format_tag_fields[] = {
    SX_FIELD("tag_type","uint8",0,1,SX_ID),
    SX_FIELD("data_type","uint8",1,1,SX_ID),
    SX_FIELD("disk_format","uint32",2,4,SX_ID),
    SX_FIELD("dump_type","uint32",6,4,SX_ID),
};
const sx_layout sxdleg_gkh_format_tag = {0x60750032U,"gkh_format_tag",sxdleg_gkh_format_tag_fields,SX_COUNT(sxdleg_gkh_format_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_gkh_geometry_tag_fields[] = {
    SX_FIELD("tag_type","uint8",0,1,SX_ID),
    SX_FIELD("data_type","uint8",1,1,SX_ID),
    SX_FIELD("track_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("head_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("sector_size","uint16",8,2,SX_SIZE),
};
const sx_layout sxdleg_gkh_geometry_tag = {0x60750033U,"gkh_geometry_tag",sxdleg_gkh_geometry_tag_fields,SX_COUNT(sxdleg_gkh_geometry_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_gkh_location_tag_fields[] = {
    SX_FIELD("tag_type","uint8",0,1,SX_ID),
    SX_FIELD("data_type","uint8",1,1,SX_ID),
    SX_FIELD("data_size","uint32",2,4,SX_SIZE),
    SX_FIELD("data_offset","uint32",6,4,SX_OFFSET),
};
const sx_layout sxdleg_gkh_location_tag = {0x60750034U,"gkh_location_tag",sxdleg_gkh_location_tag_fields,SX_COUNT(sxdleg_gkh_location_tag_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
static bool sxdleg_gkh(sx_context*c){uint8_t h[10];if(!sxdleg_read(c,0,h,8)||xx_rt_memcmp(h,"TDDFI\1",6))return false;unsigned n=sxdleg16(h+6,0);if(n<3||n>5||!sxdleg_span(c,8,n*10)||!SXDLEG_ADD(c,gkh_header,0))return false;for(unsigned i=0;i<n;i++){uint64_t p=8+i*10;if(!sxdleg_read(c,p,h,10))return false;const sx_layout*l=h[0]==1?&sxdleg_gkh_format_tag:h[0]==10?&sxdleg_gkh_geometry_tag:(h[0]==11||h[0]==20||h[0]==21)?&sxdleg_gkh_location_tag:NULL;if(l&&!sxdleg_put(c,l,p,1))return false;}return true;}
#undef SXDLEG_ADD
bool sx_ensoniq_gkh_build(sx_context*c)
{
 return sxdleg_gkh(c);
}
