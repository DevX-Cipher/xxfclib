/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Blindwrite4 data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_blindwrite4_header_fields[] = {
    SX_FIELD("signature","char[19]",0,19,SX_SIGNATURE),
    SX_FIELD("unknown","uint32",19,4,SX_NONE),
    SX_FIELD("timestamp_encoded","uint64",23,8,SX_NONE),
};
const sx_layout sxdn_blindwrite4_header = {0x60780036U,"blindwrite4_header",sxdn_blindwrite4_header_fields,SX_COUNT(sxdn_blindwrite4_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite4_string_size_fields[] = {
    SX_FIELD("string_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxdn_blindwrite4_string_size = {0x60780037U,"blindwrite4_string_size",sxdn_blindwrite4_string_size_fields,SX_COUNT(sxdn_blindwrite4_string_size_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite4_track_count_fields[] = {
    SX_FIELD("track_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxdn_blindwrite4_track_count = {0x60780038U,"blindwrite4_track_count",sxdn_blindwrite4_track_count_fields,SX_COUNT(sxdn_blindwrite4_track_count_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite4_extra_prefix_fields[] = {
    SX_FIELD("unknown","byte[4]",0,4,SX_NONE),
    SX_FIELD("payload_size","uint8",4,1,SX_SIZE),
};
const sx_layout sxdn_blindwrite4_extra_prefix = {0x60780039U,"blindwrite4_extra_prefix",sxdn_blindwrite4_extra_prefix_fields,SX_COUNT(sxdn_blindwrite4_extra_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite4_track_fields[] = {
    SX_FIELD("external_file_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("subchannel","uint8",4,1,SX_FLAGS),
    SX_FIELD("unknown0","byte[3]",5,3,SX_NONE),
    SX_FIELD("unknown1","uint32",8,4,SX_NONE),
    SX_FIELD("unknown2","uint8",12,1,SX_NONE),
    SX_FIELD("session_number","uint8",13,1,SX_NONE),
    SX_FIELD("unknown3","uint8",14,1,SX_NONE),
    SX_FIELD("adr_control","uint8",15,1,SX_FLAGS),
    SX_FIELD("unknown4","uint8",16,1,SX_NONE),
    SX_FIELD("mode","uint8",17,1,SX_ID),
    SX_FIELD("unknown5","uint8",18,1,SX_NONE),
    SX_FIELD("point","uint8",19,1,SX_ID),
    SX_FIELD("unknown6","uint32[2]",20,8,SX_NONE),
    SX_FIELD("sector_adjustment","uint32",28,4,SX_NONE),
    SX_FIELD("unknown7","uint32",32,4,SX_NONE),
    SX_FIELD("unknown8","uint16",36,2,SX_NONE),
    SX_FIELD("end_sector","uint32",38,4,SX_NONE),
    SX_FIELD("unknown9","uint8",42,1,SX_NONE),
    SX_FIELD("pregap_sector","int32",43,4,SX_NONE),
    SX_FIELD("start_sector","int32",47,4,SX_NONE),
    SX_FIELD("unknown10","uint32[2]",51,8,SX_NONE),
};
const sx_layout sxdn_blindwrite4_track = {0x6078003aU,"blindwrite4_track",sxdn_blindwrite4_track_fields,SX_COUNT(sxdn_blindwrite4_track_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
static bool sxdn_bw4_string(sx_context*c,uint64_t*p){uint64_t n;if(!sxdn_word(c,*p,4,false,&n)||!sxdn_span(c,*p+4,n)||!SXDN_ADD(c,blindwrite4_string_size,*p))return false;*p+=4;if(!sxdn_value(c,&sxdn_disk_descriptor_string,*p,n))return false;*p+=n;return true;}
static bool sxdn_bw4(sx_context*c){uint64_t p=31,n;uint8_t b[5];if(!SXDN_ADD(c,blindwrite4_header,0))return false;for(unsigned i=0;i<3;i++)if(!sxdn_bw4_string(c,&p))return true;if(!sxdn_word(c,p,4,false,&n)||!SXDN_ADD(c,blindwrite4_track_count,p)||n>256)return true;p+=4;for(unsigned i=0;i<2;i++)if(!sxdn_bw4_string(c,&p))return true;if(!sxdn_read(c,p,b,5)||!SXDN_ADD(c,blindwrite4_extra_prefix,p)||!sxdn_span(c,p+5,b[4]))return true;p+=5+b[4];for(uint64_t i=0;i<n&&c->count<SXDN_LIMIT;i++){if(!sxdn_bw4_string(c,&p)||!SXDN_ADD(c,blindwrite4_track,p))return true;p+=59;for(unsigned j=0;j<15;j++)if(!sxdn_bw4_string(c,&p))return true;}return true;}
bool sx_blindwrite4_build(sx_context*c)
{
 return sxdn_bw4(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
