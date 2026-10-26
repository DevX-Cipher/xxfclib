/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * VMDK data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_vmdk_sparse_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_NONE),
    SX_FIELD("flags","uint32",8,4,SX_FLAGS),
    SX_FIELD("capacity_sectors","uint64",12,8,SX_COUNT_PROP),
    SX_FIELD("grain_size_sectors","uint64",20,8,SX_COUNT_PROP),
    SX_FIELD("descriptor_sector","uint64",28,8,SX_ID),
    SX_FIELD("descriptor_size_sectors","uint64",36,8,SX_COUNT_PROP),
    SX_FIELD("grain_table_entry_count","uint32",44,4,SX_COUNT_PROP),
    SX_FIELD("redundant_grain_directory_sector","uint64",48,8,SX_ID),
    SX_FIELD("grain_directory_sector","uint64",56,8,SX_ID),
    SX_FIELD("overhead_sectors","uint64",64,8,SX_COUNT_PROP),
    SX_FIELD("unclean_shutdown","uint8",72,1,SX_FLAGS),
    SX_FIELD("single_end_line_char","uint8",73,1,SX_NONE),
    SX_FIELD("non_end_line_char","uint8",74,1,SX_NONE),
    SX_FIELD("double_end_line_char1","uint8",75,1,SX_NONE),
    SX_FIELD("double_end_line_char2","uint8",76,1,SX_NONE),
    SX_FIELD("compression_algorithm","uint16",77,2,SX_ID),
    SX_FIELD("padding","byte[433]",79,433,SX_RESERVED),
};
const sx_layout sx_dm_vmdk_sparse_header = {0x60290014U,"vmdk_sparse_header",sx_dm_vmdk_sparse_header_fields,SX_COUNT(sx_dm_vmdk_sparse_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_vmdk_metadata_marker_fields[] = {
    SX_FIELD("sector_count","uint64",0,8,SX_COUNT_PROP),
    SX_FIELD("size","uint32",8,4,SX_SIZE),
    SX_FIELD("type","uint32",12,4,SX_ID),
};
const sx_layout sx_dm_vmdk_metadata_marker = {0x60290017U,"vmdk_metadata_marker",sx_dm_vmdk_metadata_marker_fields,SX_COUNT(sx_dm_vmdk_metadata_marker_fields),SX_LE};
static bool sx_dm_vmdk(sx_context*c){uint8_t h[512];uint64_t header=0;if(!sx_dm_read(c,0,h,512)||xx_rt_memcmp(h,"KDMV",4))return false;if(!sx_dm_add(c,&sx_dm_vmdk_sparse_header,0,512))return false;if(sx_dm_u64(h,56,false)==UINT64_MAX){if(c->size<2048||!sx_dm_read(c,(uint64_t)c->size-1024,h,512)||xx_rt_memcmp(h,"KDMV",4))return true;header=(uint64_t)c->size-1024;if(!sx_dm_add(c,&sx_dm_vmdk_sparse_header,header,512)||!sx_dm_add(c,&sx_dm_vmdk_metadata_marker,header-512,16)||!sx_dm_add(c,&sx_dm_vmdk_metadata_marker,header+512,16))return false;}
 uint64_t cap=sx_dm_u64(h,12,false),grain=sx_dm_u64(h,20,false),gtes=sx_dm_u32(h,44,false);if(!grain||!gtes||cap>UINT64_C(1)<<40)return true;uint64_t grains=cap/grain+(cap%grain!=0),n=grains/gtes+(grains%gtes!=0);if(n>65536)n=65536;
 for(unsigned copy=0;copy<2;copy++){uint64_t sector=sx_dm_u64(h,copy?48:56,false);if(!sector||sector>INT64_MAX/512)continue;uint64_t p=sector*512;if(!sx_dm_span(c,p,n*4))continue;if(!sx_dm_table(c,&sx_dm_vmdk_grain_directory_entry,p,4,n))return false;for(uint64_t i=0;i<n&&c->count<24000;i++){uint32_t v;if(!sx_u32(c,(int64_t)(p+i*4),false,&v))return false;uint64_t q=(uint64_t)v*512,k=gtes;if(k>65536)k=65536;if(v&&q>=512&&sx_dm_span(c,q,k*4)&&!sx_dm_table(c,&sx_dm_vmdk_grain_table_entry,q,4,k))return false;}}return true;}
bool sx_vmdk_build(sx_context*c)
{
 return sx_dm_vmdk(c);
}
