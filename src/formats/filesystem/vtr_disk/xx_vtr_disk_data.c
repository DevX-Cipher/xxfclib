/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * vtr disk data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_vtr_header_fields[] = {
    SX_FIELD("magic","char[7]",0,7,SX_SIGNATURE),
    SX_FIELD("write_protected","uint8",7,1,SX_FLAGS),
    SX_FIELD("rpm","uint16",8,2,SX_NONE),
    SX_FIELD("cylinders","uint8",10,1,SX_COUNT_PROP),
    SX_FIELD("interface_mode","uint8",11,1,SX_ID),
    SX_FIELD("heads","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("track_encoding","uint8",13,1,SX_ID),
    SX_FIELD("bitrate_kbps","uint16",14,2,SX_NONE),
    SX_FIELD("track_list_block","uint16",16,2,SX_NONE),
    SX_FIELD("revision","uint8",18,1,SX_ID),
    SX_FIELD("reserved1","byte[100]",19,100,SX_RESERVED),
    SX_FIELD("input_filename","char[128]",119,128,SX_NONE),
    SX_FIELD("reserved2","byte[50]",247,50,SX_RESERVED),
    SX_FIELD("credits","char[73]",297,73,SX_NONE),
};
const sx_layout sxdr_vtr_header = {0x607f000dU,"vtr_header",sxdr_vtr_header_fields,SX_COUNT(sxdr_vtr_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_vtr_track_entry_fields[] = {
    SX_FIELD("track_block","uint16",0,2,SX_NONE),
    SX_FIELD("combined_track_bytes","uint16",2,2,SX_SIZE),
};
const sx_layout sxdr_vtr_track_entry = {0x607f000eU,"vtr_track_entry",sxdr_vtr_track_entry_fields,SX_COUNT(sxdr_vtr_track_entry_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static bool sxdr_vtr(sx_context*c){uint8_t h[370];if(!sxdr_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"VTrucco",7)||!h[10]||!h[12]||h[12]>2||h[18]||!SXDR_ADD(c,vtr_header,0))return false;uint64_t table=(uint64_t)sxdr16(h+16,false)*512;if(table<512||!sxdr_span(c,table,(uint64_t)h[10]*4))return true;return sxdr_put(c,&sxdr_vtr_track_entry,table,h[10]);}
#undef SXDR_ADD
bool sx_vtr_disk_build(sx_context*c)
{
 return sxdr_vtr(c);
}
