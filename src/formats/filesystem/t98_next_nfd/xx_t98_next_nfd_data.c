/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * T98 Next Nfd data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_nfd_header_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
    SX_FIELD("comment","char[256]",16,256,SX_STRING),
    SX_FIELD("data_offset","uint32",272,4,SX_OFFSET),
    SX_FIELD("write_protected","uint8",276,1,SX_FLAGS),
    SX_FIELD("head_count","uint8",277,1,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[10]",278,10,SX_RESERVED),
};
const sx_layout sxse_nfd_header = {0x602f0057U,"nfd_header",sxse_nfd_header_fields,SX_COUNT(sxse_nfd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_nfd_sector_r0_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("mfm","uint8",4,1,SX_FLAGS),
    SX_FIELD("deleted_data_mark","uint8",5,1,SX_FLAGS),
    SX_FIELD("status","uint8",6,1,SX_FLAGS),
    SX_FIELD("fdc_st0","uint8",7,1,SX_FLAGS),
    SX_FIELD("fdc_st1","uint8",8,1,SX_FLAGS),
    SX_FIELD("fdc_st2","uint8",9,1,SX_FLAGS),
    SX_FIELD("pda","uint8",10,1,SX_NONE),
    SX_FIELD("reserved","byte[5]",11,5,SX_RESERVED),
};
const sx_layout sxse_nfd_sector_r0 = {0x602f0058U,"nfd_sector_r0",sxse_nfd_sector_r0_fields,SX_COUNT(sxse_nfd_sector_r0_fields),SX_LE};
static const xx_data_struct_field_desc sxse_nfd_sector_r1_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_ID),
    SX_FIELD("head","uint8",1,1,SX_ID),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("mfm","uint8",4,1,SX_FLAGS),
    SX_FIELD("deleted_data_mark","uint8",5,1,SX_FLAGS),
    SX_FIELD("status","uint8",6,1,SX_FLAGS),
    SX_FIELD("fdc_st0","uint8",7,1,SX_FLAGS),
    SX_FIELD("fdc_st1","uint8",8,1,SX_FLAGS),
    SX_FIELD("fdc_st2","uint8",9,1,SX_FLAGS),
    SX_FIELD("retry_count","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("pda","uint8",11,1,SX_NONE),
    SX_FIELD("reserved","byte[4]",12,4,SX_RESERVED),
};
const sx_layout sxse_nfd_sector_r1 = {0x602f0059U,"nfd_sector_r1",sxse_nfd_sector_r1_fields,SX_COUNT(sxse_nfd_sector_r1_fields),SX_LE};
static const xx_data_struct_field_desc sxse_nfd_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxse_nfd_track_offset = {0x602f005aU,"nfd_track_offset",sxse_nfd_track_offset_fields,SX_COUNT(sxse_nfd_track_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxse_nfd_additional_info_fields[] = {
    SX_FIELD("additional_info","uint32",0,4,SX_NONE),
    SX_FIELD("reserved","byte[12]",4,12,SX_RESERVED),
};
const sx_layout sxse_nfd_additional_info = {0x602f005bU,"nfd_additional_info",sxse_nfd_additional_info_fields,SX_COUNT(sxse_nfd_additional_info_fields),SX_LE};
static const xx_data_struct_field_desc sxse_nfd_track_header_fields[] = {
    SX_FIELD("sector_count","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("diagnostic_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[12]",4,12,SX_RESERVED),
};
const sx_layout sxse_nfd_track_header = {0x602f005cU,"nfd_track_header",sxse_nfd_track_header_fields,SX_COUNT(sxse_nfd_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_nfd_diagnostic_fields[] = {
    SX_FIELD("command","uint8",0,1,SX_ID),
    SX_FIELD("cylinder","uint8",1,1,SX_ID),
    SX_FIELD("head","uint8",2,1,SX_ID),
    SX_FIELD("sector_id","uint8",3,1,SX_ID),
    SX_FIELD("size_code","uint8",4,1,SX_NONE),
    SX_FIELD("status","uint8",5,1,SX_FLAGS),
    SX_FIELD("fdc_st0","uint8",6,1,SX_FLAGS),
    SX_FIELD("fdc_st1","uint8",7,1,SX_FLAGS),
    SX_FIELD("fdc_st2","uint8",8,1,SX_FLAGS),
    SX_FIELD("retry_count","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("data_size","uint32",10,4,SX_SIZE),
    SX_FIELD("pda","uint8",14,1,SX_NONE),
    SX_FIELD("reserved","uint8",15,1,SX_RESERVED),
};
const sx_layout sxse_nfd_diagnostic = {0x602f005dU,"nfd_diagnostic",sxse_nfd_diagnostic_fields,SX_COUNT(sxse_nfd_diagnostic_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
#define SXSE_TABLE(c,l,p,z,n) sxse_put(c,&sxse_##l,p,z,n)
static bool sxse_nfd(sx_context*c){uint8_t b[288];if(!sxse_read(c,0,b,288)||xx_rt_memcmp(b,"T98FDDIMAGE.R",13)||!SXSE_ADD(c,nfd_header,0,288))return false;uint64_t limit=sxse_u32(b,272,false);if(!sxse_span(c,0,limit))return false;if(b[13]=='0')return limit>=288+163U*26U*16U&&SXSE_TABLE(c,nfd_sector_r0,288,16,163*26);
 if(b[13]!='1'||limit<960||!SXSE_TABLE(c,nfd_track_offset,288,4,164)||!SXSE_ADD(c,nfd_additional_info,944,16))return false;
 for(unsigned i=0;i<164;i++){uint32_t p;if(!sx_u32(c,288+4*i,false,&p))return false;if(!p)continue;if(p<960||p>limit||limit-p<16||!sxse_read(c,p,b,16))return false;unsigned n=sxse_u16(b,0,false),d=sxse_u16(b,2,false);if(n>255||d>255||16*(1+(uint64_t)n+d)>limit-p||!SXSE_ADD(c,nfd_track_header,p,16)||!SXSE_TABLE(c,nfd_sector_r1,(uint64_t)p+16,16,n)||!SXSE_TABLE(c,nfd_diagnostic,(uint64_t)p+16+16*n,16,d))return false;}return true;}
bool sx_t98_next_nfd_build(sx_context*c)
{
 return sxse_nfd(c);
}
#undef SXSE_ADD
#undef SXSE_TABLE
