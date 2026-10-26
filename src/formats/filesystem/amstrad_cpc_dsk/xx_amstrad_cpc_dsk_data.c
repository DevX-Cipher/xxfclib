/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Amstrad Cpc Dsk data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_cpc_disk_header_fields[] = {
    SX_FIELD("signature","char[34]",0,34,SX_SIGNATURE),
    SX_FIELD("creator","char[14]",34,14,SX_STRING),
    SX_FIELD("cylinder_count","uint8",48,1,SX_COUNT_PROP),
    SX_FIELD("side_count","uint8",49,1,SX_COUNT_PROP),
    SX_FIELD("track_size","uint16",50,2,SX_SIZE),
};
const sx_layout sxse_cpc_disk_header = {0x602f0018U,"cpc_disk_header",sxse_cpc_disk_header_fields,SX_COUNT(sxse_cpc_disk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_cpc_extended_disk_header_fields[] = {
    SX_FIELD("signature","char[34]",0,34,SX_SIGNATURE),
    SX_FIELD("creator","char[14]",34,14,SX_STRING),
    SX_FIELD("cylinder_count","uint8",48,1,SX_COUNT_PROP),
    SX_FIELD("side_count","uint8",49,1,SX_COUNT_PROP),
    SX_FIELD("unused","uint16",50,2,SX_RESERVED),
};
const sx_layout sxse_cpc_extended_disk_header = {0x602f0019U,"cpc_extended_disk_header",sxse_cpc_extended_disk_header_fields,SX_COUNT(sxse_cpc_extended_disk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_cpc_track_size_fields[] = {
    SX_FIELD("size_units","uint8",0,1,SX_NONE),
};
const sx_layout sxse_cpc_track_size = {0x602f001aU,"cpc_track_size",sxse_cpc_track_size_fields,SX_COUNT(sxse_cpc_track_size_fields),SX_LE};
static const xx_data_struct_field_desc sxse_cpc_track_header_fields[] = {
    SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
    SX_FIELD("reserved","byte[4]",12,4,SX_RESERVED),
    SX_FIELD("cylinder","uint8",16,1,SX_ID),
    SX_FIELD("side","uint8",17,1,SX_ID),
    SX_FIELD("data_rate","uint8",18,1,SX_ID),
    SX_FIELD("recording_mode","uint8",19,1,SX_ID),
    SX_FIELD("sector_size_code","uint8",20,1,SX_NONE),
    SX_FIELD("sector_count","uint8",21,1,SX_COUNT_PROP),
    SX_FIELD("gap3_length","uint8",22,1,SX_SIZE),
    SX_FIELD("filler_byte","uint8",23,1,SX_NONE),
};
const sx_layout sxse_cpc_track_header = {0x602f001bU,"cpc_track_header",sxse_cpc_track_header_fields,SX_COUNT(sxse_cpc_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_cpc_sector_standard_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("fdc_status1","uint8",4,1,SX_FLAGS),
    SX_FIELD("fdc_status2","uint8",5,1,SX_FLAGS),
    SX_FIELD("unused","uint16",6,2,SX_RESERVED),
};
const sx_layout sxse_cpc_sector_standard = {0x602f001cU,"cpc_sector_standard",sxse_cpc_sector_standard_fields,SX_COUNT(sxse_cpc_sector_standard_fields),SX_LE};
static const xx_data_struct_field_desc sxse_cpc_sector_extended_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("fdc_status1","uint8",4,1,SX_FLAGS),
    SX_FIELD("fdc_status2","uint8",5,1,SX_FLAGS),
    SX_FIELD("data_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxse_cpc_sector_extended = {0x602f001dU,"cpc_sector_extended",sxse_cpc_sector_extended_fields,SX_COUNT(sxse_cpc_sector_extended_fields),SX_LE};
static const xx_data_struct_field_desc sxse_cpc_offset_info_fields[] = {
    SX_FIELD("signature","char[13]",0,13,SX_SIGNATURE),
    SX_FIELD("reserved","byte[2]",13,2,SX_RESERVED),
};
const sx_layout sxse_cpc_offset_info = {0x602f001eU,"cpc_offset_info",sxse_cpc_offset_info_fields,SX_COUNT(sxse_cpc_offset_info_fields),SX_LE};
static const xx_data_struct_field_desc sxse_cpc_track_length_fields[] = {
    SX_FIELD("track_length","uint16",0,2,SX_NONE),
};
const sx_layout sxse_cpc_track_length = {0x602f001fU,"cpc_track_length",sxse_cpc_track_length_fields,SX_COUNT(sxse_cpc_track_length_fields),SX_LE};
static const xx_data_struct_field_desc sxse_cpc_sector_timing_fields[] = {
    SX_FIELD("sector_position","uint16",0,2,SX_NONE),
};
const sx_layout sxse_cpc_sector_timing = {0x602f0020U,"cpc_sector_timing",sxse_cpc_sector_timing_fields,SX_COUNT(sxse_cpc_sector_timing_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
#define SXSE_TABLE(c,l,p,z,n) sxse_put(c,&sxse_##l,p,z,n)
static bool sxse_cpc(sx_context*c){uint8_t h[256],b[24];uint64_t p=256;uint8_t counts[168];unsigned formatted=0;if(!sxse_read(c,0,h,256))return false;bool ext=!xx_rt_memcmp(h,"EXTENDED CPC DSK File\r\nDisk-Info\r\n",34);unsigned n=(unsigned)h[48]*h[49];if(!n||n>168||!sxse_put(c,ext?&sxse_cpc_extended_disk_header:&sxse_cpc_disk_header,0,52,1)||(ext&&!SXSE_TABLE(c,cpc_track_size,52,1,n)))return false;
 for(unsigned i=0;i<n;i++){uint64_t z=ext?(uint64_t)h[52+i]*256:sxse_u16(h,50,false);if(!z)continue;if(z<256||!sxse_span(c,p,z)||!sxse_read(c,p,b,24)||xx_rt_memcmp(b,"Track-Info\r\n",12)||b[21]>29)return false;counts[formatted++]=b[21];if(!SXSE_ADD(c,cpc_track_header,p,24)||!sxse_put(c,ext?&sxse_cpc_sector_extended:&sxse_cpc_sector_standard,p+24,8,b[21]))return false;p+=z;}
 if(sxse_span(c,p,15)&&sxse_read(c,p,b,15)&&!xx_rt_memcmp(b,"Offset-Info\r\n",13)){if(!SXSE_ADD(c,cpc_offset_info,p,15))return false;p+=15;for(unsigned i=0;i<formatted;i++){if(!SXSE_ADD(c,cpc_track_length,p,2)||!SXSE_TABLE(c,cpc_sector_timing,p+2,2,counts[i]))return false;p+=2+2*counts[i];}}
 return true;}
bool sx_amstrad_cpc_dsk_build(sx_context*c)
{
 return sxse_cpc(c);
}
#undef SXSE_ADD
#undef SXSE_TABLE
