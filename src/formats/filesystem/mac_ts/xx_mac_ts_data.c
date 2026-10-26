/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MAC_TS data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static const xx_data_struct_field_desc sxdt_mac_ts_driver_descriptor_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("block_size","uint16",2,2,SX_SIZE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("device_type","uint16",8,2,SX_ID),
    SX_FIELD("device_id","uint16",10,2,SX_ID),
    SX_FIELD("driver_data","uint32",12,4,SX_NONE),
    SX_FIELD("driver_count","uint16",16,2,SX_COUNT_PROP),
    SX_FIELD("driver_start_block","uint32",18,4,SX_NONE),
    SX_FIELD("driver_size_blocks","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("driver_os_type","uint16",24,2,SX_ID),
};
const sx_layout sxdt_mac_ts_driver_descriptor = {0x607a0002U,"mac_ts_driver_descriptor",sxdt_mac_ts_driver_descriptor_fields,SX_COUNT(sxdt_mac_ts_driver_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_mac_ts_map_header_fields[] = {
    SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
};
const sx_layout sxdt_mac_ts_map_header = {0x607a0003U,"mac_ts_map_header",sxdt_mac_ts_map_header_fields,SX_COUNT(sxdt_mac_ts_map_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdt_mac_ts_partition_fields[] = {
    SX_FIELD("start_block","uint32",0,4,SX_NONE),
    SX_FIELD("block_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("filesystem_id","char[4]",8,4,SX_ID),
};
const sx_layout sxdt_mac_ts_partition = {0x607a0004U,"mac_ts_partition",sxdt_mac_ts_partition_fields,SX_COUNT(sxdt_mac_ts_partition_fields),SX_BE};
#define SXDT_ADD(c,l,p) sxdt_put(c,&sxdt_##l,p,1)
static bool sxdt_ts(sx_context*c){uint8_t h[26];if(!sxdt_read(c,0,h,26)||sxdt16(h,1)!=0x4552||sxdt16(h+2,1)!=512||!SXDT_ADD(c,mac_ts_driver_descriptor,0)||!sxdt_read(c,512,h,2)||sxdt16(h,1)!=0x5453||!SXDT_ADD(c,mac_ts_map_header,512))return false;for(unsigned i=0;i<42;i++){uint64_t p=514+i*12;if(!sxdt_read(c,p,h,12)||!SXDT_ADD(c,mac_ts_partition,p))return false;if(!sxdt32(h,1))break;}return true;}
static bool sxdt_ts_children(sx_context*c){uint8_t h[12];if(!sxdt_ts(c))return false;for(unsigned i=0;i<42;i++){if(!sxdt_read(c,514+i*12,h,12))return false;uint64_t p=(uint64_t)sxdt32(h,1)*512,n=(uint64_t)sxdt32(h+4,1)*512;if(!p)break;if(n&&sxdt_span(c,p,n)&&!sxdt_child(c,p,n))return false;}return true;}
bool sx_mac_ts_build(sx_context*c)
{
bool ok=false;
ok=sxdt_ts_children(c);
return ok&&c->count&&sxdt_finish(c);
}
