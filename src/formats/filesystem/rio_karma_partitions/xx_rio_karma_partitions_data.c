/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Rio Karma partitions data structures, moved out of the volume schema family. */
#include "../../xx_format_schema_volume.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/formats/filesystem/volume/xx_volume.h"
#include "xxfclib/formats/filesystem/gpt/xx_gpt.h"

static const xx_data_struct_field_desc sx_v_rio_karma_partition_entry_fields[] = {
    SX_FIELD("reserved", "uint32", 0, 4, SX_RESERVED),
    SX_FIELD("type", "uint8", 4, 1, SX_ID),
    SX_FIELD("reserved2", "byte[3]", 5, 3, SX_RESERVED),
    SX_FIELD("start_sector", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 12, 4, SX_COUNT_PROP),
};
const sx_layout sx_v_rio_karma_partition_entry = {UINT32_C(0x6005000c), "rio_karma_partition_entry", sx_v_rio_karma_partition_entry_fields, SX_COUNT(sx_v_rio_karma_partition_entry_fields), SX_LE};
static const xx_data_struct_field_desc sx_v_rio_karma_partition_footer_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
};
const sx_layout sx_v_rio_karma_partition_footer = {UINT32_C(0x6005000d), "rio_karma_partition_footer", sx_v_rio_karma_partition_footer_fields, SX_COUNT(sx_v_rio_karma_partition_footer_fields), SX_LE};
bool sx_rio_karma_partitions_build(sx_context*c)
{
        if(!sx_table(c,&sx_v_rio_karma_partition_entry,270,16,2)||!sx_add(c,&sx_v_rio_karma_partition_footer,510,2))return false;return true;
}
