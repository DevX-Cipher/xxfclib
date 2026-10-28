/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical volume metadata layouts; independent declarations from wire facts.
 * Primary references and per-format limits: docs/data_struct_volume_scope.txt.
 */
#include "xxfclib/formats/filesystem/volume/xx_volume.h"

static const xx_data_struct_field_desc sx_v_dec_partition_table_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("valid", "uint32", 4, 4, SX_FLAGS),
};
static const sx_layout sx_v_dec_partition_table_header = {UINT32_C(0x60050001), "dec_partition_table_header", sx_v_dec_partition_table_header_fields, SX_COUNT(sx_v_dec_partition_table_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_dec_partition_entry_fields[] = {
    SX_FIELD("block_count", "int32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("start_block", "uint32", 4, 4, SX_OFFSET),
};
static const sx_layout sx_v_dec_partition_entry = {UINT32_C(0x60050002), "dec_partition_entry", sx_v_dec_partition_entry_fields, SX_COUNT(sx_v_dec_partition_entry_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_dragonfly_disklabel64_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("crc32", "uint32", 4, 4, SX_CHECKSUM),
    SX_FIELD("alignment", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("partition_count", "uint32", 12, 4, SX_COUNT_PROP),
    SX_FIELD("storage_uuid", "byte[16]", 16, 16, SX_ID),
    SX_FIELD("total_size", "uint64", 32, 8, SX_SIZE),
    SX_FIELD("boot_area_offset", "uint64", 40, 8, SX_OFFSET),
    SX_FIELD("partition_area_offset", "uint64", 48, 8, SX_OFFSET),
    SX_FIELD("partition_area_end", "uint64", 56, 8, SX_OFFSET),
    SX_FIELD("backup_label_offset", "uint64", 64, 8, SX_OFFSET),
    SX_FIELD("pack_name", "char[64]", 72, 64, SX_STRING),
    SX_FIELD("reserved", "byte[64]", 136, 64, SX_RESERVED),
};
static const sx_layout sx_v_dragonfly_disklabel64_header = {UINT32_C(0x60050003), "dragonfly_disklabel64_header", sx_v_dragonfly_disklabel64_header_fields, SX_COUNT(sx_v_dragonfly_disklabel64_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_dragonfly_partition64_fields[] = {
    SX_FIELD("byte_offset", "uint64", 0, 8, SX_OFFSET),
    SX_FIELD("byte_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("filesystem_type", "uint8", 16, 1, SX_ID),
    SX_FIELD("reserved_bytes", "byte[3]", 17, 3, SX_RESERVED),
    SX_FIELD("reserved_word1", "uint32", 20, 4, SX_RESERVED),
    SX_FIELD("reserved_word2", "uint32", 24, 4, SX_RESERVED),
    SX_FIELD("reserved_word3", "uint32", 28, 4, SX_RESERVED),
    SX_FIELD("type_uuid", "byte[16]", 32, 16, SX_ID),
    SX_FIELD("storage_uuid", "byte[16]", 48, 16, SX_ID),
};
static const sx_layout sx_v_dragonfly_partition64 = {UINT32_C(0x60050004), "dragonfly_partition64", sx_v_dragonfly_partition64_fields, SX_COUNT(sx_v_dragonfly_partition64_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_sgi_volume_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("root_partition", "int16", 4, 2, SX_ID),
    SX_FIELD("swap_partition", "int16", 6, 2, SX_ID),
    SX_FIELD("boot_file", "char[16]", 8, 16, SX_STRING),
};
static const sx_layout sx_v_sgi_volume_header = {UINT32_C(0x60050005), "sgi_volume_header", sx_v_sgi_volume_header_fields, SX_COUNT(sx_v_sgi_volume_header_fields), SX_BE};

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
static const sx_layout sx_v_sgi_device_parameters = {UINT32_C(0x60050006), "sgi_device_parameters", sx_v_sgi_device_parameters_fields, SX_COUNT(sx_v_sgi_device_parameters_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_sgi_volume_directory_entry_fields[] = {
    SX_FIELD("name", "char[8]", 0, 8, SX_STRING),
    SX_FIELD("start_block", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("byte_size", "uint32", 12, 4, SX_SIZE),
};
static const sx_layout sx_v_sgi_volume_directory_entry = {UINT32_C(0x60050007), "sgi_volume_directory_entry", sx_v_sgi_volume_directory_entry_fields, SX_COUNT(sx_v_sgi_volume_directory_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_sgi_partition_entry_fields[] = {
    SX_FIELD("block_count", "uint32", 0, 4, SX_COUNT_PROP),
    SX_FIELD("start_block", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("type", "uint32", 8, 4, SX_ID),
};
static const sx_layout sx_v_sgi_partition_entry = {UINT32_C(0x60050008), "sgi_partition_entry", sx_v_sgi_partition_entry_fields, SX_COUNT(sx_v_sgi_partition_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_sgi_volume_header_footer_fields[] = {
    SX_FIELD("checksum", "uint32", 0, 4, SX_CHECKSUM),
    SX_FIELD("padding", "uint32", 4, 4, SX_RESERVED),
};
static const sx_layout sx_v_sgi_volume_header_footer = {UINT32_C(0x60050009), "sgi_volume_header_footer", sx_v_sgi_volume_header_footer_fields, SX_COUNT(sx_v_sgi_volume_header_footer_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_human68k_partition_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("size", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("size2", "uint32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("unknown", "uint32", 12, 4, SX_NONE),
};
static const sx_layout sx_v_human68k_partition_header = {UINT32_C(0x6005000a), "human68k_partition_header", sx_v_human68k_partition_header_fields, SX_COUNT(sx_v_human68k_partition_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_human68k_partition_entry_fields[] = {
    SX_FIELD("name", "char[8]", 0, 8, SX_STRING),
    SX_FIELD("state_and_start_block", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("block_count", "uint32", 12, 4, SX_COUNT_PROP),
};
static const sx_layout sx_v_human68k_partition_entry = {UINT32_C(0x6005000b), "human68k_partition_entry", sx_v_human68k_partition_entry_fields, SX_COUNT(sx_v_human68k_partition_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_rio_karma_partition_entry_fields[] = {
    SX_FIELD("reserved", "uint32", 0, 4, SX_RESERVED),
    SX_FIELD("type", "uint8", 4, 1, SX_ID),
    SX_FIELD("reserved2", "byte[3]", 5, 3, SX_RESERVED),
    SX_FIELD("start_sector", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 12, 4, SX_COUNT_PROP),
};
static const sx_layout sx_v_rio_karma_partition_entry = {UINT32_C(0x6005000c), "rio_karma_partition_entry", sx_v_rio_karma_partition_entry_fields, SX_COUNT(sx_v_rio_karma_partition_entry_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_rio_karma_partition_footer_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
};
static const sx_layout sx_v_rio_karma_partition_footer = {UINT32_C(0x6005000d), "rio_karma_partition_footer", sx_v_rio_karma_partition_footer_fields, SX_COUNT(sx_v_rio_karma_partition_footer_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_xenix_partition_header_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
};
static const sx_layout sx_v_xenix_partition_header = {UINT32_C(0x6005000e), "xenix_partition_header", sx_v_xenix_partition_header_fields, SX_COUNT(sx_v_xenix_partition_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_xenix_partition_entry_fields[] = {
    SX_FIELD("start_1k_block", "int32", 0, 4, SX_OFFSET),
    SX_FIELD("block_count", "int32", 4, 4, SX_COUNT_PROP),
};
static const sx_layout sx_v_xenix_partition_entry = {UINT32_C(0x6005000f), "xenix_partition_entry", sx_v_xenix_partition_entry_fields, SX_COUNT(sx_v_xenix_partition_entry_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_minix_mbr_partition_entry_fields[] = {
    SX_FIELD("boot_indicator", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("start_head", "uint8", 1, 1, SX_NONE),
    SX_FIELD("start_sector_and_cylinder_high", "uint8", 2, 1, SX_NONE),
    SX_FIELD("start_cylinder_low", "uint8", 3, 1, SX_NONE),
    SX_FIELD("type", "uint8", 4, 1, SX_ID),
    SX_FIELD("end_head", "uint8", 5, 1, SX_NONE),
    SX_FIELD("end_sector_and_cylinder_high", "uint8", 6, 1, SX_NONE),
    SX_FIELD("end_cylinder_low", "uint8", 7, 1, SX_NONE),
    SX_FIELD("start_lba", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 12, 4, SX_COUNT_PROP),
};
static const sx_layout sx_v_minix_mbr_partition_entry = {UINT32_C(0x60050010), "minix_mbr_partition_entry", sx_v_minix_mbr_partition_entry_fields, SX_COUNT(sx_v_minix_mbr_partition_entry_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_minix_mbr_signature_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
};
static const sx_layout sx_v_minix_mbr_signature = {UINT32_C(0x60050011), "minix_mbr_signature", sx_v_minix_mbr_signature_fields, SX_COUNT(sx_v_minix_mbr_signature_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_atari_partition_entry_fields[] = {
    SX_FIELD("flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("id", "char[3]", 1, 3, SX_STRING),
    SX_FIELD("start_sector", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 8, 4, SX_COUNT_PROP),
};
static const sx_layout sx_v_atari_partition_entry = {UINT32_C(0x60050012), "atari_partition_entry", sx_v_atari_partition_entry_fields, SX_COUNT(sx_v_atari_partition_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_atari_disk_size_fields[] = {
    SX_FIELD("sector_count", "uint32", 0, 4, SX_COUNT_PROP),
};
static const sx_layout sx_v_atari_disk_size = {UINT32_C(0x60050013), "atari_disk_size", sx_v_atari_disk_size_fields, SX_COUNT(sx_v_atari_disk_size_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_atari_bad_sector_list_fields[] = {
    SX_FIELD("start_sector", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("checksum", "uint16", 8, 2, SX_CHECKSUM),
};
static const sx_layout sx_v_atari_bad_sector_list = {UINT32_C(0x60050014), "atari_bad_sector_list", sx_v_atari_bad_sector_list_fields, SX_COUNT(sx_v_atari_bad_sector_list_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_next_disklabel_header_fields[] = {
    SX_FIELD("version", "uint32", 0, 4, SX_ID),
    SX_FIELD("label_block", "int32", 4, 4, SX_OFFSET),
    SX_FIELD("size", "int32", 8, 4, SX_COUNT_PROP),
    SX_FIELD("label", "char[24]", 12, 24, SX_STRING),
    SX_FIELD("flags", "uint32", 36, 4, SX_FLAGS),
    SX_FIELD("tag", "uint32", 40, 4, SX_ID),
};
static const sx_layout sx_v_next_disklabel_header = {UINT32_C(0x60050015), "next_disklabel_header", sx_v_next_disklabel_header_fields, SX_COUNT(sx_v_next_disklabel_header_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_next_disktab_fields[] = {
    SX_FIELD("drive_name", "char[24]", 0, 24, SX_STRING),
    SX_FIELD("drive_type", "char[24]", 24, 24, SX_STRING),
    SX_FIELD("sector_size", "int32", 48, 4, SX_SIZE),
    SX_FIELD("tracks", "int32", 52, 4, SX_COUNT_PROP),
    SX_FIELD("sectors_per_track", "int32", 56, 4, SX_COUNT_PROP),
    SX_FIELD("cylinders", "int32", 60, 4, SX_COUNT_PROP),
    SX_FIELD("rpm", "int32", 64, 4, SX_NONE),
    SX_FIELD("front_porch", "int16", 68, 2, SX_COUNT_PROP),
    SX_FIELD("back_porch", "int16", 70, 2, SX_COUNT_PROP),
    SX_FIELD("alternate_groups", "int16", 72, 2, SX_COUNT_PROP),
    SX_FIELD("alternate_group_size", "int16", 74, 2, SX_COUNT_PROP),
    SX_FIELD("alternates_per_group", "int16", 76, 2, SX_COUNT_PROP),
    SX_FIELD("alternate_group_offset", "int16", 78, 2, SX_OFFSET),
    SX_FIELD("boot_block0", "int32", 80, 4, SX_OFFSET),
    SX_FIELD("boot_block1", "int32", 84, 4, SX_OFFSET),
    SX_FIELD("boot_file", "char[24]", 88, 24, SX_STRING),
    SX_FIELD("host_name", "char[32]", 112, 32, SX_STRING),
    SX_FIELD("root_partition", "uint8", 144, 1, SX_ID),
    SX_FIELD("read_write_partition", "uint8", 145, 1, SX_ID),
};
static const sx_layout sx_v_next_disktab = {UINT32_C(0x60050016), "next_disktab", sx_v_next_disktab_fields, SX_COUNT(sx_v_next_disktab_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_next_partition_entry_fields[] = {
    SX_FIELD("start_sector", "int32", 0, 4, SX_OFFSET),
    SX_FIELD("sector_count", "int32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("block_size", "int16", 8, 2, SX_SIZE),
    SX_FIELD("fragment_size", "int16", 10, 2, SX_SIZE),
    SX_FIELD("optimization", "uint8", 12, 1, SX_ID),
    SX_FIELD("cylinders_per_group", "int16", 13, 2, SX_COUNT_PROP),
    SX_FIELD("density", "int16", 15, 2, SX_NONE),
    SX_FIELD("minimum_free_percent", "uint8", 17, 1, SX_NONE),
    SX_FIELD("newfs", "uint8", 18, 1, SX_FLAGS),
    SX_FIELD("mount_point", "char[16]", 19, 16, SX_STRING),
    SX_FIELD("automount", "uint8", 35, 1, SX_FLAGS),
    SX_FIELD("filesystem_type", "char[8]", 36, 8, SX_STRING),
};
static const sx_layout sx_v_next_partition_entry = {UINT32_C(0x60050017), "next_partition_entry", sx_v_next_partition_entry_fields, SX_COUNT(sx_v_next_partition_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_next_bad_block_entry_fields[] = {
    SX_FIELD("block", "int32", 0, 4, SX_OFFSET),
};
static const sx_layout sx_v_next_bad_block_entry = {UINT32_C(0x60050018), "next_bad_block_entry", sx_v_next_bad_block_entry_fields, SX_COUNT(sx_v_next_bad_block_entry_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_next_disklabel_checksum_fields[] = {
    SX_FIELD("checksum", "uint16", 0, 2, SX_CHECKSUM),
};
static const sx_layout sx_v_next_disklabel_checksum = {UINT32_C(0x60050019), "next_disklabel_checksum", sx_v_next_disklabel_checksum_fields, SX_COUNT(sx_v_next_disklabel_checksum_fields), SX_BE};

static const xx_data_struct_field_desc sx_v_apricot_label_header_fields[] = {
    SX_FIELD("version", "char[8]", 0, 8, SX_STRING),
    SX_FIELD("operating_system", "uint8", 8, 1, SX_ID),
    SX_FIELD("write_protected", "uint8", 9, 1, SX_FLAGS),
    SX_FIELD("copy_protected", "uint8", 10, 1, SX_FLAGS),
    SX_FIELD("boot_type", "uint8", 11, 1, SX_ID),
    SX_FIELD("partition_count", "uint8", 12, 1, SX_COUNT_PROP),
    SX_FIELD("winchester", "uint8", 13, 1, SX_FLAGS),
    SX_FIELD("sector_size", "uint16", 14, 2, SX_SIZE),
    SX_FIELD("sectors_per_track", "uint16", 16, 2, SX_COUNT_PROP),
    SX_FIELD("cylinders", "uint32", 18, 4, SX_COUNT_PROP),
    SX_FIELD("heads", "uint8", 22, 1, SX_COUNT_PROP),
    SX_FIELD("interleave", "uint8", 23, 1, SX_NONE),
    SX_FIELD("skew", "uint16", 24, 2, SX_NONE),
    SX_FIELD("boot_location", "uint32", 26, 4, SX_OFFSET),
    SX_FIELD("boot_size", "uint16", 30, 2, SX_COUNT_PROP),
    SX_FIELD("boot_address", "uint32", 32, 4, SX_ADDRESS),
    SX_FIELD("boot_offset", "uint16", 36, 2, SX_OFFSET),
    SX_FIELD("boot_segment", "uint16", 38, 2, SX_ADDRESS),
    SX_FIELD("first_data_block", "uint32", 40, 4, SX_OFFSET),
    SX_FIELD("generation", "uint16", 44, 2, SX_NONE),
    SX_FIELD("copy_count", "uint16", 46, 2, SX_COUNT_PROP),
    SX_FIELD("maximum_copies", "uint16", 48, 2, SX_COUNT_PROP),
    SX_FIELD("serial_number", "char[8]", 50, 8, SX_STRING),
    SX_FIELD("part_number", "char[8]", 58, 8, SX_STRING),
    SX_FIELD("copyright", "char[14]", 66, 14, SX_STRING),
};
static const sx_layout sx_v_apricot_label_header = {UINT32_C(0x6005001a), "apricot_label_header", sx_v_apricot_label_header_fields, SX_COUNT(sx_v_apricot_label_header_fields), SX_LE};

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
static const sx_layout sx_v_apricot_parameter_block = {UINT32_C(0x6005001b), "apricot_parameter_block", sx_v_apricot_parameter_block_fields, SX_COUNT(sx_v_apricot_parameter_block_fields), SX_LE};

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
static const sx_layout sx_v_apricot_configuration = {UINT32_C(0x6005001c), "apricot_configuration", sx_v_apricot_configuration_fields, SX_COUNT(sx_v_apricot_configuration_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_apricot_bad_block_entry_fields[] = {
    SX_FIELD("block", "uint16", 0, 2, SX_OFFSET),
};
static const sx_layout sx_v_apricot_bad_block_entry = {UINT32_C(0x6005001d), "apricot_bad_block_entry", sx_v_apricot_bad_block_entry_fields, SX_COUNT(sx_v_apricot_bad_block_entry_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_apricot_label_footer_fields[] = {
    SX_FIELD("spare", "byte[63]", 0, 63, SX_RESERVED),
    SX_FIELD("cpm_double_sided", "uint8", 63, 1, SX_FLAGS),
};
static const sx_layout sx_v_apricot_label_footer = {UINT32_C(0x6005001e), "apricot_label_footer", sx_v_apricot_label_footer_fields, SX_COUNT(sx_v_apricot_label_footer_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_acorn_disc_record_fields[] = {
    SX_FIELD("log2_sector_size", "uint8", 0, 1, SX_NONE),
    SX_FIELD("sectors_per_track", "uint8", 1, 1, SX_COUNT_PROP),
    SX_FIELD("heads", "uint8", 2, 1, SX_COUNT_PROP),
    SX_FIELD("density", "uint8", 3, 1, SX_NONE),
    SX_FIELD("id_length", "uint8", 4, 1, SX_COUNT_PROP),
    SX_FIELD("log2_bytes_per_map_bit", "uint8", 5, 1, SX_NONE),
    SX_FIELD("skew", "uint8", 6, 1, SX_NONE),
    SX_FIELD("boot_option", "uint8", 7, 1, SX_ID),
    SX_FIELD("low_sector", "uint8", 8, 1, SX_NONE),
    SX_FIELD("zone_count_low", "uint8", 9, 1, SX_COUNT_PROP),
    SX_FIELD("zone_spare", "uint16", 10, 2, SX_NONE),
    SX_FIELD("root", "uint32", 12, 4, SX_OFFSET),
    SX_FIELD("disc_size_low", "uint32", 16, 4, SX_NONE),
    SX_FIELD("disc_id", "uint16", 20, 2, SX_ID),
    SX_FIELD("disc_name", "char[10]", 22, 10, SX_STRING),
    SX_FIELD("disc_type", "uint32", 32, 4, SX_ID),
    SX_FIELD("disc_size_high", "uint32", 36, 4, SX_NONE),
    SX_FIELD("flags", "uint8", 40, 1, SX_FLAGS),
    SX_FIELD("zone_count_high", "uint8", 41, 1, SX_COUNT_PROP),
    SX_FIELD("alignment_padding", "byte[2]", 42, 2, SX_RESERVED),
    SX_FIELD("format_version", "uint32", 44, 4, SX_NONE),
    SX_FIELD("root_size", "uint32", 48, 4, SX_SIZE),
    SX_FIELD("reserved", "byte[8]", 52, 8, SX_RESERVED),
};
static const sx_layout sx_v_acorn_disc_record = {UINT32_C(0x6005001f), "acorn_disc_record", sx_v_acorn_disc_record_fields, SX_COUNT(sx_v_acorn_disc_record_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_acorn_boot_footer_fields[] = {
    SX_FIELD("flags", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("start_cylinder", "uint16", 1, 2, SX_OFFSET),
    SX_FIELD("checksum", "uint8", 3, 1, SX_CHECKSUM),
};
static const sx_layout sx_v_acorn_boot_footer = {UINT32_C(0x60050020), "acorn_boot_footer", sx_v_acorn_boot_footer_fields, SX_COUNT(sx_v_acorn_boot_footer_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_acorn_linux_partition_entry_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("start_sector", "uint32", 4, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 8, 4, SX_COUNT_PROP),
};
static const sx_layout sx_v_acorn_linux_partition_entry = {UINT32_C(0x60050021), "acorn_linux_partition_entry", sx_v_acorn_linux_partition_entry_fields, SX_COUNT(sx_v_acorn_linux_partition_entry_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_acorn_riscix_table_header_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("date", "uint32", 4, 4, SX_TIME),
};
static const sx_layout sx_v_acorn_riscix_table_header = {UINT32_C(0x60050022), "acorn_riscix_table_header", sx_v_acorn_riscix_table_header_fields, SX_COUNT(sx_v_acorn_riscix_table_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_acorn_riscix_partition_entry_fields[] = {
    SX_FIELD("start_sector", "uint32", 0, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 4, 4, SX_COUNT_PROP),
    SX_FIELD("one", "uint32", 8, 4, SX_NONE),
    SX_FIELD("name", "char[16]", 12, 16, SX_STRING),
};
static const sx_layout sx_v_acorn_riscix_partition_entry = {UINT32_C(0x60050023), "acorn_riscix_partition_entry", sx_v_acorn_riscix_partition_entry_fields, SX_COUNT(sx_v_acorn_riscix_partition_entry_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_pc98_partition_entry_fields[] = {
    SX_FIELD("mid", "uint8", 0, 1, SX_ID),
    SX_FIELD("sid", "uint8", 1, 1, SX_ID),
    SX_FIELD("reserved", "byte[2]", 2, 2, SX_RESERVED),
    SX_FIELD("ipl_sector", "uint8", 4, 1, SX_NONE),
    SX_FIELD("ipl_head", "uint8", 5, 1, SX_NONE),
    SX_FIELD("ipl_cylinder", "uint16", 6, 2, SX_NONE),
    SX_FIELD("start_sector", "uint8", 8, 1, SX_OFFSET),
    SX_FIELD("start_head", "uint8", 9, 1, SX_NONE),
    SX_FIELD("start_cylinder", "uint16", 10, 2, SX_NONE),
    SX_FIELD("end_sector", "uint8", 12, 1, SX_OFFSET),
    SX_FIELD("end_head", "uint8", 13, 1, SX_NONE),
    SX_FIELD("end_cylinder", "uint16", 14, 2, SX_NONE),
    SX_FIELD("name", "char[16]", 16, 16, SX_STRING),
};
static const sx_layout sx_v_pc98_partition_entry = {UINT32_C(0x60050024), "pc98_partition_entry", sx_v_pc98_partition_entry_fields, SX_COUNT(sx_v_pc98_partition_entry_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_pc98_boot_signature_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
};
static const sx_layout sx_v_pc98_boot_signature = {UINT32_C(0x60050025), "pc98_boot_signature", sx_v_pc98_boot_signature_fields, SX_COUNT(sx_v_pc98_boot_signature_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_mbr_disk_signature_fields[] = {
    SX_FIELD("disk_signature", "uint32", 0, 4, SX_ID),
    SX_FIELD("reserved", "uint16", 4, 2, SX_RESERVED),
};
static const sx_layout sx_v_mbr_disk_signature = {UINT32_C(0x60050026), "mbr_disk_signature", sx_v_mbr_disk_signature_fields, SX_COUNT(sx_v_mbr_disk_signature_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_mbr_partition_entry_fields[] = {
    SX_FIELD("boot_indicator", "uint8", 0, 1, SX_FLAGS),
    SX_FIELD("start_head", "uint8", 1, 1, SX_NONE),
    SX_FIELD("start_sector_and_cylinder_high", "uint8", 2, 1, SX_NONE),
    SX_FIELD("start_cylinder_low", "uint8", 3, 1, SX_NONE),
    SX_FIELD("type", "uint8", 4, 1, SX_ID),
    SX_FIELD("end_head", "uint8", 5, 1, SX_NONE),
    SX_FIELD("end_sector_and_cylinder_high", "uint8", 6, 1, SX_NONE),
    SX_FIELD("end_cylinder_low", "uint8", 7, 1, SX_NONE),
    SX_FIELD("start_lba", "uint32", 8, 4, SX_OFFSET),
    SX_FIELD("sector_count", "uint32", 12, 4, SX_COUNT_PROP),
};
static const sx_layout sx_v_mbr_partition_entry = {UINT32_C(0x60050027), "mbr_partition_entry", sx_v_mbr_partition_entry_fields, SX_COUNT(sx_v_mbr_partition_entry_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_mbr_boot_signature_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
};
static const sx_layout sx_v_mbr_boot_signature = {UINT32_C(0x60050028), "mbr_boot_signature", sx_v_mbr_boot_signature_fields, SX_COUNT(sx_v_mbr_boot_signature_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_gpt_header_fields[] = {
    SX_FIELD("signature", "byte[8]", 0, 8, SX_SIGNATURE),
    SX_FIELD("revision", "uint32", 8, 4, SX_ID),
    SX_FIELD("header_size", "uint32", 12, 4, SX_SIZE),
    SX_FIELD("header_crc32", "uint32", 16, 4, SX_CHECKSUM),
    SX_FIELD("reserved", "uint32", 20, 4, SX_RESERVED),
    SX_FIELD("my_lba", "uint64", 24, 8, SX_OFFSET),
    SX_FIELD("alternate_lba", "uint64", 32, 8, SX_OFFSET),
    SX_FIELD("first_usable_lba", "uint64", 40, 8, SX_OFFSET),
    SX_FIELD("last_usable_lba", "uint64", 48, 8, SX_OFFSET),
    SX_FIELD("disk_guid", "byte[16]", 56, 16, SX_ID),
    SX_FIELD("partition_entry_lba", "uint64", 72, 8, SX_OFFSET),
    SX_FIELD("partition_entry_count", "uint32", 80, 4, SX_COUNT_PROP),
    SX_FIELD("partition_entry_size", "uint32", 84, 4, SX_SIZE),
    SX_FIELD("partition_entry_array_crc32", "uint32", 88, 4, SX_CHECKSUM),
};
static const sx_layout sx_v_gpt_header = {UINT32_C(0x60050029), "gpt_header", sx_v_gpt_header_fields, SX_COUNT(sx_v_gpt_header_fields), SX_LE};

static const xx_data_struct_field_desc sx_v_gpt_partition_entry_fields[] = {
    SX_FIELD("type_guid", "byte[16]", 0, 16, SX_ID),
    SX_FIELD("unique_guid", "byte[16]", 16, 16, SX_ID),
    SX_FIELD("starting_lba", "uint64", 32, 8, SX_OFFSET),
    SX_FIELD("ending_lba", "uint64", 40, 8, SX_OFFSET),
    SX_FIELD("attributes", "uint64", 48, 8, SX_FLAGS),
    SX_FIELD("name_utf16le", "byte[72]", 56, 72, SX_STRING),
};
static const sx_layout sx_v_gpt_partition_entry = {UINT32_C(0x6005002a), "gpt_partition_entry", sx_v_gpt_partition_entry_fields, SX_COUNT(sx_v_gpt_partition_entry_fields), SX_LE};

static const sx_layout *const sx_volume_layouts[] = {
    &sx_v_dec_partition_table_header,
    &sx_v_dec_partition_entry,
    &sx_v_dragonfly_disklabel64_header,
    &sx_v_dragonfly_partition64,
    &sx_v_sgi_volume_header,
    &sx_v_sgi_device_parameters,
    &sx_v_sgi_volume_directory_entry,
    &sx_v_sgi_partition_entry,
    &sx_v_sgi_volume_header_footer,
    &sx_v_human68k_partition_header,
    &sx_v_human68k_partition_entry,
    &sx_v_rio_karma_partition_entry,
    &sx_v_rio_karma_partition_footer,
    &sx_v_xenix_partition_header,
    &sx_v_xenix_partition_entry,
    &sx_v_minix_mbr_partition_entry,
    &sx_v_minix_mbr_signature,
    &sx_v_atari_partition_entry,
    &sx_v_atari_disk_size,
    &sx_v_atari_bad_sector_list,
    &sx_v_next_disklabel_header,
    &sx_v_next_disktab,
    &sx_v_next_partition_entry,
    &sx_v_next_bad_block_entry,
    &sx_v_next_disklabel_checksum,
    &sx_v_apricot_label_header,
    &sx_v_apricot_parameter_block,
    &sx_v_apricot_configuration,
    &sx_v_apricot_bad_block_entry,
    &sx_v_apricot_label_footer,
    &sx_v_acorn_disc_record,
    &sx_v_acorn_boot_footer,
    &sx_v_acorn_linux_partition_entry,
    &sx_v_acorn_riscix_table_header,
    &sx_v_acorn_riscix_partition_entry,
    &sx_v_pc98_partition_entry,
    &sx_v_pc98_boot_signature,
    &sx_v_mbr_disk_signature,
    &sx_v_mbr_partition_entry,
    &sx_v_mbr_boot_signature,
    &sx_v_gpt_header,
    &sx_v_gpt_partition_entry,
};
/* Walk only physical metadata. Native reader validation supplies each format's
 * integrity rules; all schema offsets still receive independent range checks.
 * Partition payloads and unspecified boot code remain RAW_DATA. */
#include "xxfclib/formats/filesystem/gpt/xx_gpt.h"
static bool sx_volume_supports(xx_file_type_t t)
{
    switch(t) {
    case XX_FILE_TYPE_MBR: case XX_FILE_TYPE_GPT:
    case XX_FILE_TYPE_DEC_DISKLABEL: case XX_FILE_TYPE_DRAGONFLY_DISKLABEL:
    case XX_FILE_TYPE_SGI_VOLUME_HEADER: case XX_FILE_TYPE_HUMAN68K_PARTITIONS:
    case XX_FILE_TYPE_RIO_KARMA_PARTITIONS: case XX_FILE_TYPE_XENIX_PARTITIONS:
    case XX_FILE_TYPE_MINIX_PARTITIONS: case XX_FILE_TYPE_ATARI_AHDI:
    case XX_FILE_TYPE_NEXT_DISKLABEL: case XX_FILE_TYPE_APRICOT_PARTITIONS:
    case XX_FILE_TYPE_ACORN_PARTITIONS: case XX_FILE_TYPE_PC98_PARTITIONS:return true;
    default:return false;
    }
}
static bool sx_v_fits(const sx_context *c,uint64_t o,uint64_t n)
{
    return c && c->size>=0 && o<=(uint64_t)c->size && n<=(uint64_t)c->size-o;
}
/* Shell sort needs no CRT qsort and no auxiliary allocation. */
static void sx_v_sort(sx_context *c)
{
    for(size_t gap=c->count/2;gap;gap/=2) for(size_t i=gap;i<c->count;i++) {
        xx_data_struct item=c->items[i];size_t j=i;
        while(j>=gap&&c->items[j-gap].offset>item.offset){c->items[j]=c->items[j-gap];j-=gap;}
        c->items[j]=item;
    }
}
static bool sx_v_finish(sx_context *c)
{
    int64_t end=0;sx_v_sort(c);size_t n=c->count;
    for(size_t i=0;i<n;i++) {
        int64_t off=c->items[i].offset-c->f->base_address,stop=off+c->items[i].total_size;
        if(off>end&&!sx_raw(c,end,off-end))return false;
        if(stop>end)end=stop;
    }
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    sx_v_sort(c);return !c->failed;
}
static bool sx_v_mbr_extended(uint8_t t){return t==5||t==15||t==0x85;}
static bool sx_v_mbr_sector(sx_context *c,int64_t at,bool primary)
{
    return (!primary||sx_add(c,&sx_v_mbr_disk_signature,at+440,6)) &&
        sx_table(c,&sx_v_mbr_partition_entry,at+446,16,4) && sx_add(c,&sx_v_mbr_boot_signature,at+510,2);
}
static bool sx_v_mbr(sx_context *c)
{
    uint8_t b[512];uint64_t seen[256];size_t ns=0;
    if(!sx_read(c,0,b,512)||!sx_v_mbr_sector(c,0,true))return false;
    for(size_t i=0;i<4;i++) {
        const uint8_t *e=b+446+i*16;uint64_t root=xx_data_get_u32(e,16,8,false),length=xx_data_get_u32(e,16,12,false),cur=root;
        if(!sx_v_mbr_extended(e[4])||!root||!length)continue;
        for(unsigned steps=0;steps<256;steps++) {
            uint8_t sector[512];bool duplicate=false;
            if(cur<root||cur-root>=length||cur>INT64_MAX/512||!sx_v_fits(c,cur*512,512))break;
            for(size_t j=0;j<ns;j++)if(seen[j]==cur){duplicate=true;break;}
            if(duplicate||ns==SX_COUNT(seen))break;
            if(!sx_read(c,(int64_t)(cur*512),sector,512))return false;
            if(sector[510]!=0x55||sector[511]!=0xaa)break;
            seen[ns++]=cur;
            if(!sx_v_mbr_sector(c,(int64_t)(cur*512),false))return false;
            const uint8_t *link=sector+462;uint32_t rel=xx_data_get_u32(link,16,8,false);
            if(!sx_v_mbr_extended(link[4])||!rel||rel>=length)break;
            cur=root+rel;
        }
    }
    return true;
}
/* Header CRC failures do not erase a recognizable physical header. The native
 * selected copy establishes validity; alternate copies need independently safe
 * framing before their physical members may be displayed. */
typedef struct sx_v_gpt_copy_info {
    uint64_t header,header_end,entries;
    uint32_t count,stride;
    bool framed,array;
} sx_v_gpt_copy_info;
static bool sx_v_gpt_read_header(sx_context *c,uint64_t at,uint64_t bs,bool selected,sx_v_gpt_copy_info *copy)
{
    uint8_t h[92];uint64_t entries;uint32_t count,stride,header_size;
    xx_mem_zero(copy,sizeof(*copy));
    if(!sx_v_fits(c,at,92))return !selected;
    if(!sx_read(c,(int64_t)at,h,92))return false;
    header_size=xx_data_get_u32(h,92,12,false);
    if(xx_rt_memcmp(h,"EFI PART",8)||header_size<92||header_size>bs||!sx_v_fits(c,at,header_size)||xx_data_get_u64(h,92,24,false)!=at/bs)return !selected;
    copy->framed=true;copy->header=at;copy->header_end=at+header_size;
    if(!sx_add(c,&sx_v_gpt_header,(int64_t)at,92))return false;
    entries=xx_data_get_u64(h,92,72,false);count=xx_data_get_u32(h,92,80,false);stride=xx_data_get_u32(h,92,84,false);
    if(!entries||entries>(uint64_t)INT64_MAX/bs||!count||count>4096||stride<128||stride>4096||stride%8)return !selected;
    entries*=bs;
    if(!sx_v_fits(c,entries,((uint64_t)count-1)*stride+128))return !selected;
    copy->array=true;copy->entries=entries;copy->count=count;copy->stride=stride;return true;
}
static bool sx_v_gpt_entries(sx_context *c,const sx_v_gpt_copy_info *copy,const sx_v_gpt_copy_info *headers,size_t nh)
{
    if(!copy->array)return true;
    uint64_t entries=copy->entries,end=entries+((uint64_t)copy->count-1)*copy->stride+128;
    bool overlap=false;
    /* Both safely framed headers are reserved first, including unknown header
     * extensions. A corrupt cross-copy array must not reinterpret those bytes
     * as partition entries. Their extension bytes remain RAW_DATA. */
    for(size_t j=0;j<nh;j++)if(headers[j].framed&&headers[j].header<end&&entries<headers[j].header_end)overlap=true;
    for(size_t j=0;j<c->count&&!overlap;j++) {
        uint64_t start=(uint64_t)(c->items[j].offset-c->f->base_address);
        if(start<end&&entries<start+(uint64_t)c->items[j].total_size)overlap=true;
    }
    if(!overlap&&copy->stride==128)return sx_table(c,&sx_v_gpt_partition_entry,(int64_t)entries,128,copy->count);
    for(uint32_t i=0;i<copy->count;i++) {
        uint64_t off=entries+(uint64_t)i*copy->stride;bool covered=false;
        for(size_t j=0;j<nh;j++)if(headers[j].framed&&headers[j].header<off+128&&off<headers[j].header_end)covered=true;
        for(size_t j=0;j<c->count&&!covered;j++) {
            uint64_t start=(uint64_t)(c->items[j].offset-c->f->base_address);
            if(start<off+128&&off<start+(uint64_t)c->items[j].total_size)covered=true;
        }
        if(!covered&&!sx_add(c,&sx_v_gpt_partition_entry,(int64_t)off,128))return false;
    }
    return true;
}
static bool sx_v_gpt(sx_context *c)
{
    const xx_gpt *g=(const xx_gpt *)c->f;uint64_t bs=g->block_size,backup;sx_v_gpt_copy_info copies[2];
    if((bs!=512&&bs!=4096)||c->size<(int64_t)(bs*2))return false;
    backup=((uint64_t)c->size/bs-1)*bs;
    if(!sx_v_gpt_read_header(c,g->used_backup?backup:bs,bs,true,&copies[0]))return false;
    xx_mem_zero(&copies[1],sizeof(copies[1]));
    if(backup!=bs&&!sx_v_gpt_read_header(c,g->used_backup?bs:backup,bs,false,&copies[1]))return false;
    return sx_v_gpt_entries(c,&copies[0],copies,2)&&sx_v_gpt_entries(c,&copies[1],copies,2);
}
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
static bool sx_volume_build(sx_context *c)
{
    uint32_t v=0;int64_t at=0;
    if(!c||!c->f||!sx_volume_supports(c->f->file_type))return false;
    /* Through callbacks only: this source also links in profiles where GPT,
     * MBR, or shared-volume native readers were not compiled. */
    if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    switch(c->f->file_type) {
    case XX_FILE_TYPE_MBR:if(!sx_v_mbr(c))return false;break;
    case XX_FILE_TYPE_GPT:if(!sx_v_gpt(c))return false;break;
    case XX_FILE_TYPE_DEC_DISKLABEL:
        at=31*512;if(!sx_add(c,&sx_v_dec_partition_table_header,at+440,8)||!sx_table(c,&sx_v_dec_partition_entry,at+448,8,8))return false;break;
    case XX_FILE_TYPE_DRAGONFLY_DISKLABEL:
        if(!sx_u32(c,524,false,&v)||v<1||v>16||!sx_add(c,&sx_v_dragonfly_disklabel64_header,512,200)||!sx_table(c,&sx_v_dragonfly_partition64,712,64,v))return false;break;
    case XX_FILE_TYPE_SGI_VOLUME_HEADER:
        if(!sx_add(c,&sx_v_sgi_volume_header,0,24)||!sx_add(c,&sx_v_sgi_device_parameters,24,48)||!sx_table(c,&sx_v_sgi_volume_directory_entry,72,16,15)||!sx_table(c,&sx_v_sgi_partition_entry,312,12,16)||!sx_add(c,&sx_v_sgi_volume_header_footer,504,8))return false;break;
    case XX_FILE_TYPE_HUMAN68K_PARTITIONS:
        at=1024;
        if(sx_v_fits(c,2048,512)){if(!sx_u32(c,2048,true,&v))return false;if(v==UINT32_C(0x5836384b))at=2048;}
        if(!sx_add(c,&sx_v_human68k_partition_header,at,16)||!sx_table(c,&sx_v_human68k_partition_entry,at+16,16,8))return false;break;
    case XX_FILE_TYPE_RIO_KARMA_PARTITIONS:
        if(!sx_table(c,&sx_v_rio_karma_partition_entry,270,16,2)||!sx_add(c,&sx_v_rio_karma_partition_footer,510,2))return false;break;
    case XX_FILE_TYPE_XENIX_PARTITIONS:
        at=42*512;if(!sx_add(c,&sx_v_xenix_partition_header,at,2)||!sx_table(c,&sx_v_xenix_partition_entry,at+2,8,16))return false;break;
    case XX_FILE_TYPE_MINIX_PARTITIONS:
        if(!sx_table(c,&sx_v_minix_mbr_partition_entry,446,16,4)||!sx_add(c,&sx_v_minix_mbr_signature,510,2))return false;break;
    case XX_FILE_TYPE_ATARI_AHDI: {
        uint64_t seen[64];size_t ns=0;
        if(!sx_add(c,&sx_v_atari_disk_size,450,4)||!sx_add(c,&sx_v_atari_bad_sector_list,502,10)||!sx_v_atari_entries(c,454,4,0,seen,&ns)||!sx_v_atari_entries(c,342,8,0,seen,&ns))return false;break;
    }
    case XX_FILE_TYPE_NEXT_DISKLABEL: {
        static const int offsets[]={0,2048,7680,8192};bool found=false;
        for(size_t i=0;i<SX_COUNT(offsets);i++)if(sx_v_fits(c,offsets[i],1024)) {
            if(!sx_u32(c,offsets[i],true,&v))return false;
            if(v==UINT32_C(0x4e655854)||v==UINT32_C(0x646c5632)||v==UINT32_C(0x646c5633)){at=offsets[i];found=true;break;}
        }
        if(!found||!sx_add(c,&sx_v_next_disklabel_header,at,44)||!sx_add(c,&sx_v_next_disktab,at+44,146)||!sx_table(c,&sx_v_next_partition_entry,at+190,44,8))return false;
        if(v==UINT32_C(0x646c5633)){if(!sx_add(c,&sx_v_next_disklabel_checksum,at+542,2))return false;}
        else if(sx_v_fits(c,(uint64_t)at,7224)) {
            if(!sx_table(c,&sx_v_next_bad_block_entry,at+542,4,1670)||!sx_add(c,&sx_v_next_disklabel_checksum,at+7222,2))return false;
        }
        /* Native readers permit short old labels: do not invent a checksum at
         * the v3 offset. Incomplete old bad-block tails stay explicitly raw. */
        break;
    }
    case XX_FILE_TYPE_APRICOT_PARTITIONS:
        if(!sx_add(c,&sx_v_apricot_label_header,0,80)||!sx_add(c,&sx_v_apricot_parameter_block,80,16)||!sx_add(c,&sx_v_apricot_configuration,96,160)||!sx_table(c,&sx_v_apricot_bad_block_entry,256,2,32)||!sx_table(c,&sx_v_apricot_parameter_block,320,16,8)||!sx_add(c,&sx_v_apricot_label_footer,448,64))return false;break;
    case XX_FILE_TYPE_ACORN_PARTITIONS: {
        uint8_t b[64];uint64_t map;
        if(!sx_read(c,3072+448,b,64)||!sx_add(c,&sx_v_acorn_disc_record,3072+448,60)||!sx_add(c,&sx_v_acorn_boot_footer,3072+508,4))return false;
        if(b[0]<7||b[0]>13)return false;
        map=(uint64_t)xx_data_get_u16(b,64,61,false)*(b[2]+((b[8]>>6)&1))*b[1]*(UINT64_C(1)<<b[0]);
        if(map>INT64_MAX||!sx_v_fits(c,map,512))return false;at=(int64_t)map;
        if((b[60]&15)==9){if(!sx_table(c,&sx_v_acorn_linux_partition_entry,at,12,42))return false;}
        else if((b[60]&15)==1||(b[60]&15)==2){if(!sx_add(c,&sx_v_acorn_riscix_table_header,at,8)||!sx_table(c,&sx_v_acorn_riscix_partition_entry,at+8,28,8))return false;}
        else return false;break;
    }
    case XX_FILE_TYPE_PC98_PARTITIONS:
        at=((const xx_volume *)c->f)->logical_sector_size;
        if(at<128||at>8192||!sx_add(c,&sx_v_pc98_boot_signature,at-2,2)||!sx_table(c,&sx_v_pc98_partition_entry,at,32,8))return false;break;
    default:return false;
    }
    return sx_v_finish(c);
}
static bool sx_volume_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<UINT32_C(0x60050001)||id>UINT32_C(0x6005ffff))return true;
    const wchar_t *comment=NULL;uint64_t v=xx_var_get_u64(&r->value);
    if(id==sx_v_human68k_partition_entry.id&&!xx_rt_wcscmp(r->name,L"state_and_start_block"))comment=L"High 8 bits: state; low 24 bits: starting block";
    else if(id==sx_v_xenix_partition_entry.id&&!xx_rt_wcscmp(r->name,L"start_1k_block"))comment=L"1024-byte blocks relative to block 977";
    else if((id==sx_v_mbr_partition_entry.id||id==sx_v_minix_mbr_partition_entry.id)&&!xx_rt_wcscmp(r->name,L"boot_indicator"))comment=v==0x80?L"Active (bootable)":v==0?L"Inactive":L"Unrecognized boot indicator";
    else if(id==sx_v_gpt_partition_entry.id&&!xx_rt_wcscmp(r->name,L"name_utf16le"))comment=L"36 UTF-16LE code units; zero-terminated partition name";
    else if(id==sx_v_gpt_partition_entry.id&&!xx_rt_wcscmp(r->name,L"ending_lba"))comment=L"Inclusive ending LBA";
    else if(id==sx_v_gpt_header.id&&!xx_rt_wcscmp(r->name,L"revision")&&v==0x10000)comment=L"GPT revision 1.0";
    else if((id==sx_v_mbr_partition_entry.id||id==sx_v_minix_mbr_partition_entry.id)&&!xx_rt_wcscmp(r->name,L"type")) {
        switch(v) {
        case 0:comment=L"Empty";break;case 1:comment=L"FAT12";break;case 4:comment=L"FAT16 (<32 MiB)";break;
        case 5:comment=L"Extended (CHS)";break;case 6:comment=L"FAT16";break;case 7:comment=L"NTFS/exFAT/HPFS";break;
        case 11:comment=L"FAT32 (CHS)";break;case 12:comment=L"FAT32 (LBA)";break;case 14:comment=L"FAT16 (LBA)";break;
        case 15:comment=L"Extended (LBA)";break;case 0x81:comment=L"Minix";break;case 0x82:comment=L"Linux swap";break;
        case 0x83:comment=L"Linux";break;case 0x85:comment=L"Extended (Linux)";break;case 0x8e:comment=L"Linux LVM";break;
        case 0xee:comment=L"GPT protective";break;case 0xef:comment=L"EFI System";break;case 0xfd:comment=L"Linux RAID auto";break;
        default:break;
        }
    }else if(id==sx_v_gpt_partition_entry.id&&!xx_rt_wcscmp(r->name,L"attributes")) {
        static const wchar_t *const names[]={L"0",L"PLATFORM_REQUIRED",L"NO_BLOCK_IO_PROTOCOL",L"PLATFORM_REQUIRED|NO_BLOCK_IO_PROTOCOL",L"LEGACY_BIOS_BOOTABLE",L"PLATFORM_REQUIRED|LEGACY_BIOS_BOOTABLE",L"NO_BLOCK_IO_PROTOCOL|LEGACY_BIOS_BOOTABLE",L"PLATFORM_REQUIRED|NO_BLOCK_IO_PROTOCOL|LEGACY_BIOS_BOOTABLE"};
        if(v<8)comment=names[v];
    }
    else if(id==sx_v_acorn_disc_record.id) {
        if(!xx_rt_wcscmp(r->name,L"log2_sector_size"))comment=L"Base-2 exponent: sector size is 1 << value bytes";
        else if(!xx_rt_wcscmp(r->name,L"log2_bytes_per_map_bit"))comment=L"Base-2 exponent: bytes per map bit is 1 << value";
        else if(!xx_rt_wcscmp(r->name,L"id_length"))comment=L"Fragment identifier length in bits";
        else if(!xx_rt_wcscmp(r->name,L"disc_size_low"))comment=L"Lower 32 bits of the 64-bit byte size";
        else if(!xx_rt_wcscmp(r->name,L"disc_size_high"))comment=L"Upper 32 bits of the 64-bit byte size";
    }else if(id==sx_v_next_disklabel_header.id&&!xx_rt_wcscmp(r->name,L"size"))comment=L"Block count";
    else if(id==sx_v_next_disktab.id&&!xx_rt_wcscmp(r->name,L"alternate_group_size"))comment=L"Sector count";
    else if(id==sx_v_apricot_label_header.id&&!xx_rt_wcscmp(r->name,L"boot_size"))comment=L"Sector count";
    if(comment)return xx_data_struct_record_set_comment(r,comment);
    return true;
}
