/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TI99 DSK data structures, moved out of the retrofs schema family. */
#include "../../xx_format_schema_retrofs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrfs_ti99_vib_fields[] = {
    SX_FIELD("volume_name","char[10]",0,10,SX_NONE),
    SX_FIELD("sector_count","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("signature","char[3]",13,3,SX_SIGNATURE),
    SX_FIELD("protection","uint8",16,1,SX_FLAGS),
    SX_FIELD("tracks_per_side","uint8",17,1,SX_COUNT_PROP),
    SX_FIELD("side_count","uint8",18,1,SX_COUNT_PROP),
    SX_FIELD("density","uint8",19,1,SX_ID),
    SX_FIELD("reserved","byte[36]",20,36,SX_RESERVED),
    SX_FIELD("allocation_bitmap","byte[200]",56,200,SX_FLAGS),
};
const sx_layout sxrfs_ti99_vib = {0x60650020U,"ti99_vib",sxrfs_ti99_vib_fields,SX_COUNT(sxrfs_ti99_vib_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_ti99_directory_pointer_fields[] = {
    SX_FIELD("file_descriptor_sector","uint16",0,2,SX_NONE),
};
const sx_layout sxrfs_ti99_directory_pointer = {0x60650021U,"ti99_directory_pointer",sxrfs_ti99_directory_pointer_fields,SX_COUNT(sxrfs_ti99_directory_pointer_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_ti99_file_descriptor_fields[] = {
    SX_FIELD("name","char[10]",0,10,SX_NONE),
    SX_FIELD("reserved10","byte[2]",10,2,SX_RESERVED),
    SX_FIELD("flags","uint8",12,1,SX_FLAGS),
    SX_FIELD("records_per_sector","uint8",13,1,SX_COUNT_PROP),
    SX_FIELD("sector_count","uint16",14,2,SX_COUNT_PROP),
    SX_FIELD("last_sector_bytes","uint8",16,1,SX_NONE),
    SX_FIELD("record_length","uint8",17,1,SX_SIZE),
    SX_FIELD("record_count","uint16le",18,2,SX_COUNT_PROP),
    SX_FIELD("reserved20","byte[8]",20,8,SX_RESERVED),
};
const sx_layout sxrfs_ti99_file_descriptor = {0x60650022U,"ti99_file_descriptor",sxrfs_ti99_file_descriptor_fields,SX_COUNT(sxrfs_ti99_file_descriptor_fields),SX_BE};
static const xx_data_struct_field_desc sxrfs_ti99_cluster_fields[] = {
    SX_FIELD("packed_sector_and_end","byte[3]",0,3,SX_NONE),
};
const sx_layout sxrfs_ti99_cluster = {0x60650023U,"ti99_cluster",sxrfs_ti99_cluster_fields,SX_COUNT(sxrfs_ti99_cluster_fields),SX_LE};
#define SXRFS_LIMIT 24000U
#define SXRFS_ADD(c,l,p) sxrfs_put(c,&sxrfs_##l,p,1)
#define SXRFS_TABLE(c,l,p,n) sxrfs_put(c,&sxrfs_##l,p,n)
static bool sxrfs_ti(sx_context*c){uint8_t b[256];if(!sxrfs_read(c,0,b,256)||xx_rt_memcmp(b+13,"DSK",3)||!SXRFS_ADD(c,ti99_vib,0)||!SXRFS_TABLE(c,ti99_directory_pointer,256,128)||!sxrfs_read(c,256,b,256))return false;unsigned sectors=(unsigned)((uint64_t)c->size/256);for(unsigned i=0;i<128&&c->count<SXRFS_LIMIT;i++){unsigned n=sxrfs16(b+i*2,1);if(!n)break;if(n<2||n>=sectors)continue;if(!SXRFS_ADD(c,ti99_file_descriptor,(uint64_t)n*256)||!SXRFS_TABLE(c,ti99_cluster,(uint64_t)n*256+28,76))return false;}return true;}
bool sx_ti99_dsk_build(sx_context*c)
{
 return sxrfs_ti(c);
}
#undef SXRFS_LIMIT
#undef SXRFS_ADD
#undef SXRFS_TABLE
