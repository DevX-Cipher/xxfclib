/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * relic sga data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmx_sga6_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("major_version","uint16",8,2,SX_ID),
 SX_FIELD("minor_version","uint16",10,2,SX_ID),
 SX_FIELD("archive_name_utf16le","bytes",12,128,SX_NONE),
 SX_FIELD("table_size","uint32",140,4,SX_SIZE),
 SX_FIELD("data_offset","uint32",144,4,SX_OFFSET),
 SX_FIELD("platform","uint32",148,4,SX_ID),
};
const sx_layout sxmx_sga6_header={UINT32_C(0x602E0059),"sga6_header",sxmx_sga6_header_fields,SX_COUNT(sxmx_sga6_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_sga6_table_slot_fields[]={
 SX_FIELD("table_relative","uint32",0,4,SX_OFFSET),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxmx_sga6_table_slot={UINT32_C(0x602E005A),"sga6_table_slot",sxmx_sga6_table_slot_fields,SX_COUNT(sxmx_sga6_table_slot_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_sga6_drive_fields[]={
 SX_FIELD("alias","char[64]",0,64,SX_STRING),
 SX_FIELD("name","char[64]",64,64,SX_STRING),
 SX_FIELD("first_folder","uint32",128,4,SX_ID),
 SX_FIELD("end_folder","uint32",132,4,SX_ID),
 SX_FIELD("first_file","uint32",136,4,SX_ID),
 SX_FIELD("end_file","uint32",140,4,SX_ID),
 SX_FIELD("root_folder","uint32",144,4,SX_ID),
};
const sx_layout sxmx_sga6_drive={UINT32_C(0x602E005B),"sga6_drive",sxmx_sga6_drive_fields,SX_COUNT(sxmx_sga6_drive_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_sga6_folder_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("first_folder","uint32",4,4,SX_ID),
 SX_FIELD("end_folder","uint32",8,4,SX_ID),
 SX_FIELD("first_file","uint32",12,4,SX_ID),
 SX_FIELD("end_file","uint32",16,4,SX_ID),
};
const sx_layout sxmx_sga6_folder={UINT32_C(0x602E005C),"sga6_folder",sxmx_sga6_folder_fields,SX_COUNT(sxmx_sga6_folder_fields),SX_LE};
static const xx_data_struct_field_desc sxmx_sga6_file_fields[]={
 SX_FIELD("name_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_relative","uint32",4,4,SX_OFFSET),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",12,4,SX_SIZE),
 SX_FIELD("timestamp","uint32",16,4,SX_TIME),
 SX_FIELD("verification","uint8",20,1,SX_ID),
 SX_FIELD("storage_type","uint8",21,1,SX_ID),
 SX_FIELD("crc32","uint32",22,4,SX_CHECKSUM),
};
const sx_layout sxmx_sga6_file={UINT32_C(0x602E005D),"sga6_file",sxmx_sga6_file_fields,SX_COUNT(sxmx_sga6_file_fields),SX_LE};
#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_sga(sxmx_view*v)
{if(!SM_ROW(sga6_header,0,v->n)||!sxmx_table(v,&sxmx_sga6_table_slot,152,4,v->n))return false;size_t end=152+(size_t)sxmx_u32(v->p+140,false);if(end>v->n)return false;const sx_layout*ls[]={&sxmx_sga6_drive,&sxmx_sga6_folder,&sxmx_sga6_file};for(unsigned i=0;i<3;i++){const uint8_t*p=v->p+152+i*8;if(!sxmx_table(v,ls[i],152+(size_t)sxmx_u32(p,false),sxmx_u32(p+4,false),end))return false;}return true;}
bool sx_relic_sga_build(sxmx_view*v)
{
 return sxmx_sga(v);
}
#undef SM_ROW
