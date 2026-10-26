/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * atari stt data structures, moved out of the disklegacy schema family. */
#include "../../xx_format_schema_disklegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdleg_stt_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_ID),
    SX_FIELD("flags","uint16",6,2,SX_FLAGS),
    SX_FIELD("all_track_flags","uint16",8,2,SX_FLAGS),
    SX_FIELD("track_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("side_count","uint16",12,2,SX_COUNT_PROP),
};
const sx_layout sxdleg_stt_header = {0x60750013U,"stt_header",sxdleg_stt_header_fields,SX_COUNT(sxdleg_stt_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_stt_track_entry_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("track_size","uint16",4,2,SX_SIZE),
};
const sx_layout sxdleg_stt_track_entry = {0x60750014U,"stt_track_entry",sxdleg_stt_track_entry_fields,SX_COUNT(sxdleg_stt_track_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_stt_track_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_flags","uint16",4,2,SX_FLAGS),
};
const sx_layout sxdleg_stt_track_header = {0x60750015U,"stt_track_header",sxdleg_stt_track_header_fields,SX_COUNT(sxdleg_stt_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_stt_sector_section_fields[] = {
    SX_FIELD("end_offset","uint16",0,2,SX_OFFSET),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("sector_count","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxdleg_stt_sector_section = {0x60750016U,"stt_sector_section",sxdleg_stt_sector_section_fields,SX_COUNT(sxdleg_stt_sector_section_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_stt_sector_descriptor_fields[] = {
    SX_FIELD("cylinder","uint8",0,1,SX_NONE),
    SX_FIELD("side","uint8",1,1,SX_NONE),
    SX_FIELD("sector_id","uint8",2,1,SX_ID),
    SX_FIELD("size_code","uint8",3,1,SX_NONE),
    SX_FIELD("address_crc","byte[2]",4,2,SX_CHECKSUM),
    SX_FIELD("data_offset","uint16",6,2,SX_OFFSET),
    SX_FIELD("data_size","uint16",8,2,SX_SIZE),
};
const sx_layout sxdleg_stt_sector_descriptor = {0x60750017U,"stt_sector_descriptor",sxdleg_stt_sector_descriptor_fields,SX_COUNT(sxdleg_stt_sector_descriptor_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_stt_raw_section_fields[] = {
    SX_FIELD("end_offset","uint16",0,2,SX_OFFSET),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("data_offset","uint16",4,2,SX_OFFSET),
    SX_FIELD("data_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxdleg_stt_raw_section = {0x60750018U,"stt_raw_section",sxdleg_stt_raw_section_fields,SX_COUNT(sxdleg_stt_raw_section_fields),SX_LE};
static const xx_data_struct_field_desc sxdleg_stt_unknown_section_fields[] = {
    SX_FIELD("end_offset","uint16",0,2,SX_OFFSET),
};
const sx_layout sxdleg_stt_unknown_section = {0x60750019U,"stt_unknown_section",sxdleg_stt_unknown_section_fields,SX_COUNT(sxdleg_stt_unknown_section_fields),SX_LE};
#define SXDLEG_ADD(c,l,p) sxdleg_put(c,&sxdleg_##l,p,1)
#define SXDLEG_TABLE(c,l,p,n) sxdleg_put(c,&sxdleg_##l,p,n)
static bool sxdleg_stt(sx_context*c){uint8_t h[14],e[10];if(!sxdleg_read(c,0,h,14)||xx_rt_memcmp(h,"STEM",4))return false;unsigned tracks=sxdleg16(h+10,0),sides=sxdleg16(h+12,0);if(!tracks||tracks>86||!sides||sides>2||!sxdleg_span(c,14,tracks*sides*6)||!SXDLEG_ADD(c,stt_header,0)||!SXDLEG_TABLE(c,stt_track_entry,14,tracks*sides))return false;
 for(unsigned i=0;i<tracks*sides;i++){if(!sxdleg_read(c,14+i*6,e,6))return false;uint64_t p=sxdleg32(e,0),z=sxdleg16(e+4,0);if(z<6||!sxdleg_span(c,p,z)||!sxdleg_read(c,p,e,6)||xx_rt_memcmp(e,"TRCK",4))continue;if(!SXDLEG_ADD(c,stt_track_header,p))return false;unsigned flags=sxdleg16(e+4,0);uint64_t q=6;
 for(unsigned bit=0;bit<16;bit++){if(!(flags&(1U<<bit)))continue;unsigned head=bit==0?6:bit==1?8:2;if(head>z-q||!sxdleg_read(c,p+q,e,head))break;unsigned end=sxdleg16(e,0);if(end<q+head||end>z)break;const sx_layout*l=bit==0?&sxdleg_stt_sector_section:bit==1?&sxdleg_stt_raw_section:&sxdleg_stt_unknown_section;if(!sxdleg_put(c,l,p+q,1))return false;if(bit==0){unsigned n=sxdleg16(e+4,0);if(n>256||n>(end-q-6)/10)break;if(!SXDLEG_TABLE(c,stt_sector_descriptor,p+q+6,n))return false;}q=end;}
 }return true;}
#undef SXDLEG_ADD
#undef SXDLEG_TABLE
bool sx_atari_stt_build(sx_context*c)
{
 return sxdleg_stt(c);
}
