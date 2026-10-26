/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Mds data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_mds_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("major_version","uint8",16,1,SX_ID),
    SX_FIELD("minor_version","uint8",17,1,SX_ID),
    SX_FIELD("media_type","uint16",18,2,SX_ID),
    SX_FIELD("sessions","uint16",20,2,SX_COUNT_PROP),
    SX_FIELD("session_count_copy","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("unknown0","uint16",24,2,SX_NONE),
    SX_FIELD("bca_size","uint16",26,2,SX_SIZE),
    SX_FIELD("unknown1","byte[8]",28,8,SX_NONE),
    SX_FIELD("bca_offset","uint32",36,4,SX_OFFSET),
    SX_FIELD("unknown2","byte[24]",40,24,SX_NONE),
    SX_FIELD("structures_offset","uint32",64,4,SX_OFFSET),
    SX_FIELD("unknown3","byte[12]",68,12,SX_NONE),
    SX_FIELD("sessions_offset","uint32",80,4,SX_OFFSET),
    SX_FIELD("disc_metadata_offset","uint32",84,4,SX_OFFSET),
};
const sx_layout sxvi_mds_header = {0x60530047U,"mds_header",sxvi_mds_header_fields,SX_COUNT(sxvi_mds_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_mds_session_fields[] = {
    SX_FIELD("start_lba","int32",0,4,SX_NONE),
    SX_FIELD("end_lba","int32",4,4,SX_NONE),
    SX_FIELD("sequence","uint16",8,2,SX_ID),
    SX_FIELD("block_count","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("non_track_blocks","uint8",11,1,SX_COUNT_PROP),
    SX_FIELD("first_track","uint16",12,2,SX_ID),
    SX_FIELD("last_track","uint16",14,2,SX_ID),
    SX_FIELD("unknown","uint32",16,4,SX_NONE),
    SX_FIELD("tracks_offset","uint32",20,4,SX_OFFSET),
};
const sx_layout sxvi_mds_session = {0x60530048U,"mds_session",sxvi_mds_session_fields,SX_COUNT(sxvi_mds_session_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_mds_track_fields[] = {
    SX_FIELD("mode","uint8",0,1,SX_ID),
    SX_FIELD("subchannel_mode","uint8",1,1,SX_ID),
    SX_FIELD("adr_control","uint8",2,1,SX_FLAGS),
    SX_FIELD("track_number","uint8",3,1,SX_ID),
    SX_FIELD("point","uint8",4,1,SX_ID),
    SX_FIELD("minute","uint8",5,1,SX_NONE),
    SX_FIELD("second","uint8",6,1,SX_NONE),
    SX_FIELD("frame","uint8",7,1,SX_NONE),
    SX_FIELD("zero","uint8",8,1,SX_RESERVED),
    SX_FIELD("pminute","uint8",9,1,SX_NONE),
    SX_FIELD("psecond","uint8",10,1,SX_NONE),
    SX_FIELD("pframe","uint8",11,1,SX_NONE),
    SX_FIELD("extra_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("sector_size","uint16",16,2,SX_SIZE),
    SX_FIELD("unknown0","byte[18]",18,18,SX_NONE),
    SX_FIELD("start_lba","uint32",36,4,SX_NONE),
    SX_FIELD("mdf_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("file_count","uint32",48,4,SX_COUNT_PROP),
    SX_FIELD("footer_offset","uint32",52,4,SX_OFFSET),
    SX_FIELD("unknown1","byte[24]",56,24,SX_NONE),
};
const sx_layout sxvi_mds_track = {0x60530049U,"mds_track",sxvi_mds_track_fields,SX_COUNT(sxvi_mds_track_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_mds_track_extra_fields[] = {
    SX_FIELD("pregap_sectors","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("sector_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxvi_mds_track_extra = {0x6053004aU,"mds_track_extra",sxvi_mds_track_extra_fields,SX_COUNT(sxvi_mds_track_extra_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_mds_footer_fields[] = {
    SX_FIELD("filename_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("wide_character","uint32",4,4,SX_FLAGS),
    SX_FIELD("unknown0","uint32",8,4,SX_NONE),
    SX_FIELD("unknown1","uint32",12,4,SX_NONE),
};
const sx_layout sxvi_mds_footer = {0x6053004bU,"mds_footer",sxvi_mds_footer_fields,SX_COUNT(sxvi_mds_footer_fields),SX_LE};
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
#define SXVI_TABLE(c,l,p,n) sxvi_put(c,&sxvi_##l,p,n)
static bool sxvi_mds(sx_context*c){uint8_t h[88],b[24];if(!sxvi_read(c,0,h,88)||xx_rt_memcmp(h,"MEDIA DESCRIPTOR",16)||h[16]!=1||h[17]!=4||!SXVI_ADD(c,mds_header,0))return false;uint64_t sessions=sxvi16(h+20,0),base=sxvi32(h+80,0),blocks=0;if(!sessions||sessions>32||!sxvi_span(c,base,sessions*24))return true;if(!SXVI_TABLE(c,mds_session,base,sessions))return false;for(uint64_t i=0;i<sessions;i++){if(!sxvi_read(c,base+i*24,b,24))return false;uint64_t p=sxvi32(b+20,0),n=b[10];if(!sxvi_span(c,p,n*80))continue;if(!SXVI_TABLE(c,mds_track,p,n))return false;blocks+=n;for(uint64_t j=0;j<n;j++){uint8_t t[56];if(!sxvi_read(c,p+j*80,t,56))return false;uint64_t footer=sxvi32(t+52,0);if(footer&&sxvi_span(c,footer,16)&&!SXVI_ADD(c,mds_footer,footer))return false;}}
 /* Native-supported producer stores an extra descriptor for every block,
  * including TOC lead-in/out blocks whose pointer is zero. */
 uint64_t extra=base+sessions*24+blocks*80;if(sxvi_span(c,extra,blocks*8)&&!SXVI_TABLE(c,mds_track_extra,extra,blocks))return false;return true;
}
bool sx_mds_build(sx_context*c)
{
 return sxvi_mds(c);
}
#undef SXVI_ADD
#undef SXVI_TABLE
