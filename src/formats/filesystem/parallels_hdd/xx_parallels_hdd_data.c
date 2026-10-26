/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * parallels hdd data structures, moved out of the diskmeta schema family. */
#include "../../xx_format_schema_diskmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sx_dm_parallels_header_extended_fields[] = {
    SX_FIELD("magic","byte[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("heads","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("cluster_sectors","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("bat_entries","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("sector_count","uint64",36,8,SX_COUNT_PROP),
    SX_FIELD("in_use","uint32",44,4,SX_ID),
    SX_FIELD("data_sector","uint32",48,4,SX_ID),
    SX_FIELD("flags","uint32",52,4,SX_FLAGS),
    SX_FIELD("extension_sector","uint64",56,8,SX_ID),
};
const sx_layout sx_dm_parallels_header_extended = {0x6029001eU,"parallels_header_extended",sx_dm_parallels_header_extended_fields,SX_COUNT(sx_dm_parallels_header_extended_fields),SX_LE};
static const xx_data_struct_field_desc sx_dm_parallels_header_old_fields[] = {
    SX_FIELD("magic","byte[16]",0,16,SX_SIGNATURE),
    SX_FIELD("version","uint32",16,4,SX_NONE),
    SX_FIELD("heads","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("cylinders","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("cluster_sectors","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("bat_entries","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("sector_count","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("reserved_sector_count_high","uint32",40,4,SX_RESERVED),
    SX_FIELD("in_use","uint32",44,4,SX_ID),
    SX_FIELD("data_sector","uint32",48,4,SX_ID),
    SX_FIELD("flags","uint32",52,4,SX_FLAGS),
    SX_FIELD("extension_sector","uint64",56,8,SX_ID),
};
const sx_layout sx_dm_parallels_header_old = {0x6029001fU,"parallels_header_old",sx_dm_parallels_header_old_fields,SX_COUNT(sx_dm_parallels_header_old_fields),SX_LE};
static bool sx_dm_parallels(sx_context*c){uint8_t h[64];if(!sx_dm_read(c,0,h,64))return false;bool ext=!xx_rt_memcmp(h,"WithouFreSpacExt",16);if(!sx_dm_add(c,ext?&sx_dm_parallels_header_extended:&sx_dm_parallels_header_old,0,64))return false;uint64_t n=sx_dm_u32(h,32,false);return !sx_dm_span(c,64,n*4)||sx_dm_table(c,ext?&sx_dm_parallels_bat_cluster:&sx_dm_parallels_bat_sector,64,4,n);}
bool sx_parallels_hdd_build(sx_context*c)
{
 return sx_dm_parallels(c);
}
