/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Atari AHDI partitions data structures, moved out of the volume schema family. */
#include "../../xx_format_schema_volume.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/formats/filesystem/volume/xx_volume.h"
#include "xxfclib/formats/filesystem/gpt/xx_gpt.h"

static const xx_data_struct_field_desc sx_v_atari_partition_entry_fields[] = {
    SX_FIELD("flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("id", "char[3]", 1, 3, SX_STRING),
    SX_FIELD("start_sector", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 8, 4, SX_COUNT_PROP),
};
const sx_layout sx_v_atari_partition_entry = {UINT32_C(0x60050012), "atari_partition_entry", sx_v_atari_partition_entry_fields, SX_COUNT(sx_v_atari_partition_entry_fields), SX_BE};
static const xx_data_struct_field_desc sx_v_atari_disk_size_fields[] = {
    SX_FIELD("sector_count", "uint32", 0, 4, SX_COUNT_PROP),
};
const sx_layout sx_v_atari_disk_size = {UINT32_C(0x60050013), "atari_disk_size", sx_v_atari_disk_size_fields, SX_COUNT(sx_v_atari_disk_size_fields), SX_BE};
static const xx_data_struct_field_desc sx_v_atari_bad_sector_list_fields[] = {
    SX_FIELD("start_sector", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("checksum", "uint16", 8, 2, SX_CHECKSUM),
};
const sx_layout sx_v_atari_bad_sector_list = {UINT32_C(0x60050014), "atari_bad_sector_list", sx_v_atari_bad_sector_list_fields, SX_COUNT(sx_v_atari_bad_sector_list_fields), SX_BE};
static bool sx_v_atari_entries(sx_context *c,int64_t table,unsigned count,uint64_t root,uint64_t *seen,size_t *ns)
{
    if(!sx_table(c,&sx_v_atari_partition_entry,table,12,count))return false;
    for(unsigned i=0;i<count;i++) {
        uint8_t e[12];if(!sx_read(c,table+(int64_t)i*12,e,12))return false;
        uint32_t len=xx_data_get_u32(e,12,8,true),rel=xx_data_get_u32(e,12,4,true);
        if(!(e[0]&1)||!len||e[1]!='X'||e[2]!='G'||e[3]!='M')continue;
        uint64_t at=root+rel;
        if(*ns>=64||at>INT64_MAX/512||!sx_v_fits(c,at*512,512))return false;
        for(size_t j=0;j<*ns;j++)if(seen[j]==at)return false;
        seen[(*ns)++]=at;
        if(!sx_v_atari_entries(c,(int64_t)(at*512)+454,4,root?root:at,seen,ns))return false;
    }
    return true;
}
bool sx_atari_ahdi_build(sx_context*c)
{
        uint64_t seen[64];size_t ns=0;
        if(!sx_add(c,&sx_v_atari_disk_size,450,4)||!sx_add(c,&sx_v_atari_bad_sector_list,502,10)||!sx_v_atari_entries(c,454,4,0,seen,&ns)||!sx_v_atari_entries(c,342,8,0,seen,&ns))return false;return true;
}
