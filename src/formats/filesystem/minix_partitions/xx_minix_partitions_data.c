/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Minix partitions data structures, moved out of the volume schema family. */
#include "../../xx_format_schema_volume.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/formats/filesystem/volume/xx_volume.h"
#include "xxfclib/formats/filesystem/gpt/xx_gpt.h"

static const xx_data_struct_field_desc sx_v_minix_mbr_signature_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
};
const sx_layout sx_v_minix_mbr_signature = {UINT32_C(0x60050011), "minix_mbr_signature", sx_v_minix_mbr_signature_fields, SX_COUNT(sx_v_minix_mbr_signature_fields), SX_LE};
bool sx_minix_partitions_build(sx_context*c)
{
        if(!sx_table(c,&sx_v_minix_mbr_partition_entry,446,16,4)||!sx_add(c,&sx_v_minix_mbr_signature,510,2))return false;return true;
}
