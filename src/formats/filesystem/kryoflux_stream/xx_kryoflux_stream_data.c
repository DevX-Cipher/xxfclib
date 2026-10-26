/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Kryoflux Stream data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_kryoflux_oob_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("block_type","uint8",1,1,SX_ID),
    SX_FIELD("payload_size","uint16",2,2,SX_SIZE),
};
const sx_layout sxdn_kryoflux_oob = {0x60780027U,"kryoflux_oob",sxdn_kryoflux_oob_fields,SX_COUNT(sxdn_kryoflux_oob_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_kryoflux_eof_fields[] = {
    SX_FIELD("marker","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("block_type","uint8",1,1,SX_ID),
    SX_FIELD("eof_sentinel","uint16",2,2,SX_SIGNATURE),
};
const sx_layout sxdn_kryoflux_eof = {0x60780028U,"kryoflux_eof",sxdn_kryoflux_eof_fields,SX_COUNT(sxdn_kryoflux_eof_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_kryoflux_stream_info_fields[] = {
    SX_FIELD("stream_position","uint32",0,4,SX_NONE),
    SX_FIELD("transfer_time","uint32",4,4,SX_NONE),
};
const sx_layout sxdn_kryoflux_stream_info = {0x60780029U,"kryoflux_stream_info",sxdn_kryoflux_stream_info_fields,SX_COUNT(sxdn_kryoflux_stream_info_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_kryoflux_stream_end_fields[] = {
    SX_FIELD("stream_position","uint32",0,4,SX_NONE),
    SX_FIELD("result","uint32",4,4,SX_ID),
};
const sx_layout sxdn_kryoflux_stream_end = {0x6078002aU,"kryoflux_stream_end",sxdn_kryoflux_stream_end_fields,SX_COUNT(sxdn_kryoflux_stream_end_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_kryoflux_index_fields[] = {
    SX_FIELD("stream_position","uint32",0,4,SX_NONE),
    SX_FIELD("timer","uint32",4,4,SX_NONE),
    SX_FIELD("system_clock","uint32",8,4,SX_NONE),
};
const sx_layout sxdn_kryoflux_index = {0x6078002bU,"kryoflux_index",sxdn_kryoflux_index_fields,SX_COUNT(sxdn_kryoflux_index_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_kryoflux_info_text_fields[] = {
    SX_FIELD("value","utf8",0,0,SX_STRING),
};
const sx_layout sxdn_kryoflux_info_text = {0x60780035U,"kryoflux_info_text",sxdn_kryoflux_info_text_fields,SX_COUNT(sxdn_kryoflux_info_text_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
static bool sxdn_kryo(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size&&c->count<SXDN_LIMIT){uint8_t b[4];if(!sxdn_read(c,p,b,1))break;if(b[0]!=13){uint64_t n=b[0]<8||b[0]==9?2:b[0]==10||b[0]==12?3:1;if(!sxdn_span(c,p,n))break;p+=n;continue;}if(!sxdn_read(c,p,b,4))break;uint64_t z=sxdn16(b+2,0);if(b[1]==13)return SXDN_ADD(c,kryoflux_eof,p);if(!sxdn_span(c,p+4,z)||!SXDN_ADD(c,kryoflux_oob,p))break;p+=4;if(b[1]==1&&z>=8){if(!SXDN_ADD(c,kryoflux_stream_info,p))return false;}else if(b[1]==2&&z>=12){if(!SXDN_ADD(c,kryoflux_index,p))return false;}else if(b[1]==3&&z>=8){if(!SXDN_ADD(c,kryoflux_stream_end,p))return false;}else if(b[1]==4&&!sxdn_value(c,&sxdn_kryoflux_info_text,p,z))return false;p+=z;}return c->count!=0;}
bool sx_kryoflux_stream_build(sx_context*c)
{
 return sxdn_kryo(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
