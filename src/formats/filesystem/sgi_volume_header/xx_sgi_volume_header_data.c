/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SGI volume header data structures, moved out of the volume schema family. */
#include "../../xx_format_schema_volume.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/formats/filesystem/volume/xx_volume.h"
#include "xxfclib/formats/filesystem/gpt/xx_gpt.h"

static const xx_data_struct_field_desc sx_v_sgi_volume_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("root_partition", "int16", 4, 2, SX_ID),
    SX_FIELD("swap_partition", "int16", 6, 2, SX_ID),
    SX_FIELD("boot_file", "char[16]", 8, 16, SX_STRING),
};
const sx_layout sx_v_sgi_volume_header = {UINT32_C(0x60050005), "sgi_volume_header", sx_v_sgi_volume_header_fields, SX_COUNT(sx_v_sgi_volume_header_fields), SX_BE};
static const xx_data_struct_field_desc sx_v_sgi_device_parameters_fields[] = {
    SX_FIELD("skew", "uint8", 0, 1, SX_NONE),
    SX_FIELD("gap1", "uint8", 1, 1, SX_NONE),
    SX_FIELD("gap2", "uint8", 2, 1, SX_NONE),
    SX_FIELD("spares_per_cylinder", "uint8", 3, 1, SX_COUNT_PROP),
    SX_FIELD("cylinders_low", "uint16", 4, 2, SX_COUNT_PROP),
    SX_FIELD("starting_head", "uint16", 6, 2, SX_NONE),
    SX_FIELD("tracks", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("command_tag_queue_depth", "uint8", 10, 1, SX_COUNT_PROP),
    SX_FIELD("cylinders_high", "uint8", 11, 1, SX_COUNT_PROP),
    SX_FIELD("unused", "uint16", 12, 2, SX_RESERVED),
    SX_FIELD("sectors_per_track", "uint16", 14, 2, SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector", "uint16", 16, 2, SX_SIZE),
    SX_FIELD("interleave", "uint16", 18, 2, SX_NONE),
    SX_FIELD("flags", "uint32", 20, 4, SX_FLAGS),
    SX_FIELD("data_rate", "uint32", 24, 4, SX_NONE),
    SX_FIELD("retry_count", "uint32", 28, 4, SX_COUNT_PROP),
    SX_FIELD("milliseconds_per_word", "uint32", 32, 4, SX_NONE),
    SX_FIELD("extended_gap1", "uint16", 36, 2, SX_NONE),
    SX_FIELD("extended_sync", "uint16", 38, 2, SX_NONE),
    SX_FIELD("extended_read_delay", "uint16", 40, 2, SX_NONE),
    SX_FIELD("extended_gap2", "uint16", 42, 2, SX_NONE),
    SX_FIELD("extended_read_gate", "uint16", 44, 2, SX_NONE),
    SX_FIELD("extended_write_continuation", "uint16", 46, 2, SX_NONE),
};
const sx_layout sx_v_sgi_device_parameters = {UINT32_C(0x60050006), "sgi_device_parameters", sx_v_sgi_device_parameters_fields, SX_COUNT(sx_v_sgi_device_parameters_fields), SX_BE};
static const xx_data_struct_field_desc sx_v_sgi_volume_directory_entry_fields[] = {
    SX_FIELD("name", "char[8]", 0, 8, SX_STRING),
    SX_FIELD("start_block", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("byte_size", "uint32", 12, 4, SX_SIZE),
};
const sx_layout sx_v_sgi_volume_directory_entry = {UINT32_C(0x60050007), "sgi_volume_directory_entry", sx_v_sgi_volume_directory_entry_fields, SX_COUNT(sx_v_sgi_volume_directory_entry_fields), SX_BE};
static const xx_data_struct_field_desc sx_v_sgi_partition_entry_fields[] = {
    SX_FIELD("block_count", "uint32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("start_block", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("type", "uint32", 8, 4, SX_ID),
};
const sx_layout sx_v_sgi_partition_entry = {UINT32_C(0x60050008), "sgi_partition_entry", sx_v_sgi_partition_entry_fields, SX_COUNT(sx_v_sgi_partition_entry_fields), SX_BE};
static const xx_data_struct_field_desc sx_v_sgi_volume_header_footer_fields[] = {
    SX_FIELD("checksum", "uint32", 0, 4, SX_CHECKSUM),
    SX_FIELD("padding", "uint32", 4, 4, SX_RESERVED),
};
const sx_layout sx_v_sgi_volume_header_footer = {UINT32_C(0x60050009), "sgi_volume_header_footer", sx_v_sgi_volume_header_footer_fields, SX_COUNT(sx_v_sgi_volume_header_footer_fields), SX_BE};
bool sx_sgi_volume_header_build(sx_context*c)
{
        if(!sx_add(c,&sx_v_sgi_volume_header,0,24)||!sx_add(c,&sx_v_sgi_device_parameters,24,48)||!sx_table(c,&sx_v_sgi_volume_directory_entry,72,16,15)||!sx_table(c,&sx_v_sgi_partition_entry,312,12,16)||!sx_add(c,&sx_v_sgi_volume_header_footer,504,8))return false;return true;
}
