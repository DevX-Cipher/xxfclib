/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * qemu enhanced disk data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_qed_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("cluster_size","uint32",4,4,SX_SIZE),
    SX_FIELD("table_size_clusters","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("header_size_clusters","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("features","uint64",16,8,SX_FLAGS),
    SX_FIELD("compatible_features","uint64",24,8,SX_FLAGS),
    SX_FIELD("autoclear_features","uint64",32,8,SX_FLAGS),
    SX_FIELD("l1_table_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("image_size","uint64",48,8,SX_SIZE),
    SX_FIELD("backing_filename_offset","uint32",56,4,SX_OFFSET),
    SX_FIELD("backing_filename_size","uint32",60,4,SX_SIZE),
};
const sx_layout sx_dm_qed_header = {0x6029001bU,"qed_header",sx_dm_qed_header_fields,SX_COUNT(sx_dm_qed_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_qed_l1_entry_fields[] = {
    SX_FIELD("l2_table_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sx_dm_qed_l1_entry = {0x6029001cU,"qed_l1_entry",sx_dm_qed_l1_entry_fields,SX_COUNT(sx_dm_qed_l1_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_qed_l2_entry_fields[] = {
    SX_FIELD("data_cluster_offset","uint64",0,8,SX_OFFSET),
};
const sx_layout sx_dm_qed_l2_entry = {0x6029001dU,"qed_l2_entry",sx_dm_qed_l2_entry_fields,SX_COUNT(sx_dm_qed_l2_entry_fields),SX_LE};
static bool sx_dm_qed(sx_context*c){uint8_t h[64];if(!sx_dm_read(c,0,h,64)||xx_rt_memcmp(h,"QED\0",4)||!sx_dm_add(c,&sx_dm_qed_header,0,64))return false;uint64_t cs=sx_dm_u32(h,4,false),ts=sx_dm_u32(h,8,false),p=sx_dm_u64(h,40,false);if(cs<4096||cs>67108864||!ts||ts>16)return true;uint64_t n=cs*ts/8;if(n>65536)n=65536;if(!sx_dm_span(c,p,n*8))return true;if(!sx_dm_table(c,&sx_dm_qed_l1_entry,p,8,n))return false;for(uint64_t i=0;i<n&&c->count<24000;i++){uint64_t q;if(!sx_u64(c,(int64_t)(p+i*8),false,&q))return false;if(q>=cs&&q%cs==0&&sx_dm_span(c,q,n*8)&&!sx_dm_table(c,&sx_dm_qed_l2_entry,q,8,n))return false;}return true;}
bool sx_qemu_enhanced_disk_build(sx_context*c)
{
 return sx_dm_qed(c);
}
