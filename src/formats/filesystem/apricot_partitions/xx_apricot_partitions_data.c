/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Apricot partitions data structures, moved out of the volume schema family. */
#include "../../xx_format_schema_volume.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/formats/filesystem/volume/xx_volume.h"
#include "xxfclib/formats/filesystem/gpt/xx_gpt.h"

static const xx_data_struct_field_desc sx_v_apricot_parameter_block_fields[] = {
    SX_FIELD("bytes_per_sector", "uint16", 0, 2, SX_SIZE),
    SX_FIELD("sectors_per_cluster", "uint8", 2, 1, SX_COUNT_PROP),
    SX_FIELD("reserved_sectors", "uint16", 3, 2, SX_COUNT_PROP),
    SX_FIELD("fat_count", "uint8", 5, 1, SX_COUNT_PROP),
    SX_FIELD("root_entries", "uint16", 6, 2, SX_COUNT_PROP),
    SX_FIELD("sector_count", "uint16", 8, 2, SX_COUNT_PROP),
    SX_FIELD("media", "uint8", 10, 1, SX_ID),
    SX_FIELD("sectors_per_fat", "uint16", 11, 2, SX_COUNT_PROP),
    SX_FIELD("disk_type", "uint8", 13, 1, SX_ID),
    SX_FIELD("start_sector", "uint16", 14, 2, SX_OFFSET),
};
const sx_layout sx_v_apricot_parameter_block = {UINT32_C(0x6005001b), "apricot_parameter_block", sx_v_apricot_parameter_block_fields, SX_COUNT(sx_v_apricot_parameter_block_fields), SX_LE};
static const xx_data_struct_field_desc sx_v_apricot_configuration_fields[] = {
    SX_FIELD("font_name", "char[16]", 0, 16, SX_STRING),
    SX_FIELD("keyboard_name", "char[16]", 16, 16, SX_STRING),
    SX_FIELD("bios_minor_version", "uint8", 32, 1, SX_NONE),
    SX_FIELD("bios_major_version", "uint8", 33, 1, SX_NONE),
    SX_FIELD("diagnostics_flag", "uint8", 34, 1, SX_FLAGS),
    SX_FIELD("printer_device", "uint8", 35, 1, SX_NONE),
    SX_FIELD("bell_volume", "uint8", 36, 1, SX_NONE),
    SX_FIELD("enable_cache", "uint8", 37, 1, SX_FLAGS),
    SX_FIELD("enable_graphics", "uint8", 38, 1, SX_FLAGS),
    SX_FIELD("dos_length", "uint8", 39, 1, SX_NONE),
    SX_FIELD("font_length", "uint8", 40, 1, SX_NONE),
    SX_FIELD("keyboard_length", "uint8", 41, 1, SX_NONE),
    SX_FIELD("dos_start", "uint16", 42, 2, SX_OFFSET),
    SX_FIELD("font_start", "uint16", 44, 2, SX_OFFSET),
    SX_FIELD("keyboard_start", "uint16", 46, 2, SX_OFFSET),
    SX_FIELD("keyboard_volume", "uint8", 48, 1, SX_NONE),
    SX_FIELD("autorepeat", "uint8", 49, 1, SX_NONE),
    SX_FIELD("autorepeat_lead_in", "uint8", 50, 1, SX_NONE),
    SX_FIELD("autorepeat_interval", "uint8", 51, 1, SX_NONE),
    SX_FIELD("microscreen_mode", "uint8", 52, 1, SX_NONE),
    SX_FIELD("spare_keyboard", "byte[11]", 53, 11, SX_RESERVED),
    SX_FIELD("line_mode", "uint8", 64, 1, SX_NONE),
    SX_FIELD("line_width", "uint8", 65, 1, SX_NONE),
    SX_FIELD("image_off", "uint8", 66, 1, SX_FLAGS),
    SX_FIELD("spare_screen", "byte[13]", 67, 13, SX_RESERVED),
    SX_FIELD("tx_baud_rate", "uint8", 80, 1, SX_NONE),
    SX_FIELD("rx_baud_rate", "uint8", 81, 1, SX_NONE),
    SX_FIELD("tx_bits", "uint8", 82, 1, SX_NONE),
    SX_FIELD("rx_bits", "uint8", 83, 1, SX_NONE),
    SX_FIELD("stop_bits", "uint8", 84, 1, SX_NONE),
    SX_FIELD("parity_check", "uint8", 85, 1, SX_NONE),
    SX_FIELD("parity_type", "uint8", 86, 1, SX_NONE),
    SX_FIELD("tx_xon_xoff", "uint8", 87, 1, SX_NONE),
    SX_FIELD("rx_xon_xoff", "uint8", 88, 1, SX_NONE),
    SX_FIELD("xon_character", "uint8", 89, 1, SX_NONE),
    SX_FIELD("xoff_character", "uint8", 90, 1, SX_NONE),
    SX_FIELD("rx_xon_xoff_buffer", "uint16", 91, 2, SX_SIZE),
    SX_FIELD("dtr_dsr", "uint8", 93, 1, SX_NONE),
    SX_FIELD("cts_rts", "uint8", 94, 1, SX_NONE),
    SX_FIELD("nulls_after_cr", "uint8", 95, 1, SX_NONE),
    SX_FIELD("nulls_after_ff", "uint8", 96, 1, SX_NONE),
    SX_FIELD("lf_after_cr_serial", "uint8", 97, 1, SX_NONE),
    SX_FIELD("bios_error_report_serial", "uint8", 98, 1, SX_NONE),
    SX_FIELD("spare_serial", "byte[13]", 99, 13, SX_RESERVED),
    SX_FIELD("lf_after_cr_parallel", "uint8", 112, 1, SX_NONE),
    SX_FIELD("select_line", "uint8", 113, 1, SX_NONE),
    SX_FIELD("paper_empty", "uint8", 114, 1, SX_NONE),
    SX_FIELD("fault_line", "uint8", 115, 1, SX_NONE),
    SX_FIELD("bios_error_report_parallel", "uint8", 116, 1, SX_NONE),
    SX_FIELD("spare_parallel", "byte[11]", 117, 11, SX_RESERVED),
    SX_FIELD("spare_winchester", "byte[14]", 128, 14, SX_RESERVED),
    SX_FIELD("parking_enabled", "uint8", 142, 1, SX_FLAGS),
    SX_FIELD("format_protection", "uint8", 143, 1, SX_FLAGS),
    SX_FIELD("spare_ram_disk", "byte[16]", 144, 16, SX_RESERVED),
};
const sx_layout sx_v_apricot_configuration = {UINT32_C(0x6005001c), "apricot_configuration", sx_v_apricot_configuration_fields, SX_COUNT(sx_v_apricot_configuration_fields), SX_LE};
static const xx_data_struct_field_desc sx_v_apricot_bad_block_entry_fields[] = {
    SX_FIELD("block", "uint16", 0, 2, SX_OFFSET),
};
const sx_layout sx_v_apricot_bad_block_entry = {UINT32_C(0x6005001d), "apricot_bad_block_entry", sx_v_apricot_bad_block_entry_fields, SX_COUNT(sx_v_apricot_bad_block_entry_fields), SX_LE};
static const xx_data_struct_field_desc sx_v_apricot_label_footer_fields[] = {
    SX_FIELD("spare", "byte[63]", 0, 63, SX_RESERVED),
    SX_FIELD("cpm_double_sided", "uint8", 63, 1, SX_FLAGS),
};
const sx_layout sx_v_apricot_label_footer = {UINT32_C(0x6005001e), "apricot_label_footer", sx_v_apricot_label_footer_fields, SX_COUNT(sx_v_apricot_label_footer_fields), SX_LE};
bool sx_apricot_partitions_build(sx_context*c)
{
        if(!sx_add(c,&sx_v_apricot_label_header,0,80)||!sx_add(c,&sx_v_apricot_parameter_block,80,16)||!sx_add(c,&sx_v_apricot_configuration,96,160)||!sx_table(c,&sx_v_apricot_bad_block_entry,256,2,32)||!sx_table(c,&sx_v_apricot_parameter_block,320,16,8)||!sx_add(c,&sx_v_apricot_label_footer,448,64))return false;return true;
}
