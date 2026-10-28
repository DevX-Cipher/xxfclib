/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical firmware container metadata. Unimplemented payloads remain raw. */

static const xx_data_struct_field_desc sx_fw_android_boot_v0_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("kernel_size","uint32",8,4,SX_SIZE),
    SX_FIELD("kernel_addr","uint32",12,4,SX_ADDRESS),
    SX_FIELD("ramdisk_size","uint32",16,4,SX_SIZE),
    SX_FIELD("ramdisk_addr","uint32",20,4,SX_ADDRESS),
    SX_FIELD("second_size","uint32",24,4,SX_SIZE),
    SX_FIELD("second_addr","uint32",28,4,SX_ADDRESS),
    SX_FIELD("tags_addr","uint32",32,4,SX_ADDRESS),
    SX_FIELD("page_size","uint32",36,4,SX_SIZE),
    SX_FIELD("header_version","uint32",40,4,SX_ID),
    SX_FIELD("os_version","uint32",44,4,SX_ID),
    SX_FIELD("name","char[16]",48,16,SX_NONE),
    SX_FIELD("cmdline","char[512]",64,512,SX_NONE),
    SX_FIELD("id","byte[32]",576,32,SX_NONE),
    SX_FIELD("extra_cmdline","char[1024]",608,1024,SX_NONE),
};
static const sx_layout sx_fw_android_boot_v0 = {0x601e0001U,"android_boot_v0",sx_fw_android_boot_v0_fields,SX_COUNT(sx_fw_android_boot_v0_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_android_boot_qcom_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("kernel_size","uint32",8,4,SX_SIZE),
    SX_FIELD("kernel_addr","uint32",12,4,SX_ADDRESS),
    SX_FIELD("ramdisk_size","uint32",16,4,SX_SIZE),
    SX_FIELD("ramdisk_addr","uint32",20,4,SX_ADDRESS),
    SX_FIELD("second_size","uint32",24,4,SX_SIZE),
    SX_FIELD("second_addr","uint32",28,4,SX_ADDRESS),
    SX_FIELD("tags_addr","uint32",32,4,SX_ADDRESS),
    SX_FIELD("page_size","uint32",36,4,SX_SIZE),
    SX_FIELD("dt_size","uint32",40,4,SX_SIZE),
    SX_FIELD("unused","uint32",44,4,SX_RESERVED),
    SX_FIELD("name","char[16]",48,16,SX_NONE),
    SX_FIELD("cmdline","char[512]",64,512,SX_NONE),
    SX_FIELD("id","byte[32]",576,32,SX_NONE),
    SX_FIELD("extra_cmdline","char[1024]",608,1024,SX_NONE),
};
static const sx_layout sx_fw_android_boot_qcom = {0x601e0002U,"android_boot_qcom",sx_fw_android_boot_qcom_fields,SX_COUNT(sx_fw_android_boot_qcom_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_android_boot_v1_extra_fields[] = {
    SX_FIELD("recovery_dtbo_size","uint32",0,4,SX_SIZE),
    SX_FIELD("recovery_dtbo_offset","uint64",4,8,SX_OFFSET),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sx_fw_android_boot_v1_extra = {0x601e0003U,"android_boot_v1_extra",sx_fw_android_boot_v1_extra_fields,SX_COUNT(sx_fw_android_boot_v1_extra_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_android_boot_v2_extra_fields[] = {
    SX_FIELD("dtb_size","uint32",0,4,SX_SIZE),
    SX_FIELD("dtb_addr","uint64",4,8,SX_ADDRESS),
};
static const sx_layout sx_fw_android_boot_v2_extra = {0x601e0004U,"android_boot_v2_extra",sx_fw_android_boot_v2_extra_fields,SX_COUNT(sx_fw_android_boot_v2_extra_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_android_boot_v3_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("kernel_size","uint32",8,4,SX_SIZE),
    SX_FIELD("ramdisk_size","uint32",12,4,SX_SIZE),
    SX_FIELD("os_version","uint32",16,4,SX_ID),
    SX_FIELD("header_size","uint32",20,4,SX_SIZE),
    SX_FIELD("reserved","uint32[4]",24,16,SX_RESERVED),
    SX_FIELD("header_version","uint32",40,4,SX_ID),
    SX_FIELD("cmdline","char[1536]",44,1536,SX_NONE),
};
static const sx_layout sx_fw_android_boot_v3 = {0x601e0005U,"android_boot_v3",sx_fw_android_boot_v3_fields,SX_COUNT(sx_fw_android_boot_v3_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_android_boot_v4_extra_fields[] = {
    SX_FIELD("signature_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sx_fw_android_boot_v4_extra = {0x601e0006U,"android_boot_v4_extra",sx_fw_android_boot_v4_extra_fields,SX_COUNT(sx_fw_android_boot_v4_extra_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_android_vendor_boot_v3_fields[] = {
    SX_FIELD("magic","byte[8]",0,8,SX_SIGNATURE),
    SX_FIELD("header_version","uint32",8,4,SX_ID),
    SX_FIELD("page_size","uint32",12,4,SX_SIZE),
    SX_FIELD("kernel_addr","uint32",16,4,SX_ADDRESS),
    SX_FIELD("ramdisk_addr","uint32",20,4,SX_ADDRESS),
    SX_FIELD("vendor_ramdisk_size","uint32",24,4,SX_SIZE),
    SX_FIELD("cmdline","char[2048]",28,2048,SX_NONE),
    SX_FIELD("tags_addr","uint32",2076,4,SX_ADDRESS),
    SX_FIELD("name","char[16]",2080,16,SX_NONE),
    SX_FIELD("header_size","uint32",2096,4,SX_SIZE),
    SX_FIELD("dtb_size","uint32",2100,4,SX_SIZE),
    SX_FIELD("dtb_addr","uint64",2104,8,SX_ADDRESS),
};
static const sx_layout sx_fw_android_vendor_boot_v3 = {0x601e0007U,"android_vendor_boot_v3",sx_fw_android_vendor_boot_v3_fields,SX_COUNT(sx_fw_android_vendor_boot_v3_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_android_vendor_boot_v4_extra_fields[] = {
    SX_FIELD("vendor_ramdisk_table_size","uint32",0,4,SX_SIZE),
    SX_FIELD("vendor_ramdisk_table_entry_num","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("vendor_ramdisk_table_entry_size","uint32",8,4,SX_SIZE),
    SX_FIELD("bootconfig_size","uint32",12,4,SX_SIZE),
};
static const sx_layout sx_fw_android_vendor_boot_v4_extra = {0x601e0008U,"android_vendor_boot_v4_extra",sx_fw_android_vendor_boot_v4_extra_fields,SX_COUNT(sx_fw_android_vendor_boot_v4_extra_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_android_vendor_ramdisk_entry_fields[] = {
    SX_FIELD("ramdisk_size","uint32",0,4,SX_SIZE),
    SX_FIELD("ramdisk_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("ramdisk_type","uint32",8,4,SX_ID),
    SX_FIELD("ramdisk_name","char[32]",12,32,SX_NONE),
    SX_FIELD("board_id","uint32[16]",44,64,SX_ID),
};
static const sx_layout sx_fw_android_vendor_ramdisk_entry = {0x601e0009U,"android_vendor_ramdisk_entry",sx_fw_android_vendor_ramdisk_entry_fields,SX_COUNT(sx_fw_android_vendor_ramdisk_entry_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_esp32_image_header_fields[] = {
    SX_FIELD("magic","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("segment_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("flash_mode","uint8",2,1,SX_ID),
    SX_FIELD("flash_size_frequency","uint8",3,1,SX_FLAGS),
    SX_FIELD("entry_addr","uint32",4,4,SX_ADDRESS),
    SX_FIELD("wp_pin","uint8",8,1,SX_ID),
    SX_FIELD("spi_pin_drive_settings","byte[3]",9,3,SX_FLAGS),
    SX_FIELD("chip_id","uint16",12,2,SX_ID),
    SX_FIELD("min_chip_rev","uint8",14,1,SX_ID),
    SX_FIELD("min_chip_rev_full","uint16",15,2,SX_ID),
    SX_FIELD("max_chip_rev_full","uint16",17,2,SX_ID),
    SX_FIELD("reserved","byte[4]",19,4,SX_RESERVED),
    SX_FIELD("hash_appended","uint8",23,1,SX_FLAGS),
};
static const sx_layout sx_fw_esp32_image_header = {0x601e000aU,"esp32_image_header",sx_fw_esp32_image_header_fields,SX_COUNT(sx_fw_esp32_image_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_esp32_segment_header_fields[] = {
    SX_FIELD("load_addr","uint32",0,4,SX_ADDRESS),
    SX_FIELD("data_length","uint32",4,4,SX_SIZE),
};
static const sx_layout sx_fw_esp32_segment_header = {0x601e000bU,"esp32_segment_header",sx_fw_esp32_segment_header_fields,SX_COUNT(sx_fw_esp32_segment_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_esp32_checksum_fields[] = {
    SX_FIELD("xor_checksum","uint8",0,1,SX_CHECKSUM),
};
static const sx_layout sx_fw_esp32_checksum = {0x601e000cU,"esp32_checksum",sx_fw_esp32_checksum_fields,SX_COUNT(sx_fw_esp32_checksum_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_dlink_tlv_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("model_name","char[32]",4,32,SX_NONE),
    SX_FIELD("board_id","char[32]",36,32,SX_NONE),
    SX_FIELD("unknown","byte[8]",68,8,SX_NONE),
    SX_FIELD("md5","char[32]",76,32,SX_CHECKSUM),
    SX_FIELD("data_type","uint32",108,4,SX_ID),
    SX_FIELD("data_length","uint32",112,4,SX_SIZE),
};
static const sx_layout sx_fw_dlink_tlv_header = {0x601e000dU,"dlink_tlv_header",sx_fw_dlink_tlv_header_fields,SX_COUNT(sx_fw_dlink_tlv_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_tplink_linux_header_fields[] = {
    SX_FIELD("version","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("vendor_name","char[24]",4,24,SX_NONE),
    SX_FIELD("fw_version","char[36]",28,36,SX_NONE),
    SX_FIELD("hw_id","uint32",64,4,SX_ID),
    SX_FIELD("hw_rev","uint32",68,4,SX_ID),
    SX_FIELD("region_code","uint32",72,4,SX_ID),
    SX_FIELD("md5sum1","byte[16]",76,16,SX_CHECKSUM),
    SX_FIELD("unknown2","uint32",92,4,SX_NONE),
    SX_FIELD("md5sum2","byte[16]",96,16,SX_CHECKSUM),
    SX_FIELD("unknown3","uint32",112,4,SX_NONE),
    SX_FIELD("kernel_load_addr","uint32",116,4,SX_ADDRESS),
    SX_FIELD("kernel_entry_addr","uint32",120,4,SX_ADDRESS),
    SX_FIELD("firmware_length","uint32",124,4,SX_SIZE),
    SX_FIELD("kernel_offset","uint32",128,4,SX_OFFSET),
    SX_FIELD("kernel_length","uint32",132,4,SX_SIZE),
    SX_FIELD("rootfs_offset","uint32",136,4,SX_OFFSET),
    SX_FIELD("rootfs_length","uint32",140,4,SX_SIZE),
    SX_FIELD("boot_offset","uint32",144,4,SX_OFFSET),
    SX_FIELD("boot_length","uint32",148,4,SX_SIZE),
    SX_FIELD("version_major","uint16",152,2,SX_ID),
    SX_FIELD("version_minor","uint16",154,2,SX_ID),
    SX_FIELD("version_patch","uint16",156,2,SX_ID),
    SX_FIELD("padding","byte[130]",158,130,SX_RESERVED),
    SX_FIELD("region_str1","char[32]",288,32,SX_NONE),
    SX_FIELD("region_str2","char[32]",320,32,SX_NONE),
    SX_FIELD("padding2","byte[160]",352,160,SX_RESERVED),
};
static const sx_layout sx_fw_tplink_linux_header = {0x601e000eU,"tplink_linux_header",sx_fw_tplink_linux_header_fields,SX_COUNT(sx_fw_tplink_linux_header_fields),SX_FILE};

static const xx_data_struct_field_desc sx_fw_tplink_rtos_header_prefix_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("unknown","byte[16]",4,16,SX_NONE),
    SX_FIELD("magic2","uint32",20,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",24,4,SX_SIZE),
    SX_FIELD("model_number","uint16",28,2,SX_ID),
    SX_FIELD("hardware_revision_major","uint8",30,1,SX_ID),
    SX_FIELD("hardware_revision_minor","uint8",31,1,SX_ID),
};
static const sx_layout sx_fw_tplink_rtos_header_prefix = {0x601e000fU,"tplink_rtos_header_prefix",sx_fw_tplink_rtos_header_prefix_fields,SX_COUNT(sx_fw_tplink_rtos_header_prefix_fields),SX_BE};

static const xx_data_struct_field_desc sx_fw_jboot_sch2_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("compression_type","uint8",2,1,SX_ID),
    SX_FIELD("version","uint8",3,1,SX_ID),
    SX_FIELD("ram_entry_addr","uint32",4,4,SX_ADDRESS),
    SX_FIELD("kernel_image_size","uint32",8,4,SX_SIZE),
    SX_FIELD("kernel_crc","uint32",12,4,SX_CHECKSUM),
    SX_FIELD("ram_start_addr","uint32",16,4,SX_ADDRESS),
    SX_FIELD("rootfs_flash_addr","uint32",20,4,SX_ADDRESS),
    SX_FIELD("rootfs_size","uint32",24,4,SX_SIZE),
    SX_FIELD("rootfs_crc","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("header_crc","uint32",32,4,SX_CHECKSUM),
    SX_FIELD("header_size","uint16",36,2,SX_SIZE),
    SX_FIELD("cmdline_size","uint16",38,2,SX_SIZE),
};
static const sx_layout sx_fw_jboot_sch2_header = {0x601e0010U,"jboot_sch2_header",sx_fw_jboot_sch2_header_fields,SX_COUNT(sx_fw_jboot_sch2_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_jboot_stag_header_fields[] = {
    SX_FIELD("cmark","uint8",0,1,SX_ID),
    SX_FIELD("id","uint8",1,1,SX_ID),
    SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
    SX_FIELD("timestamp_ticks","uint32",4,4,SX_NONE),
    SX_FIELD("image_size","uint32",8,4,SX_SIZE),
    SX_FIELD("image_checksum","uint16",12,2,SX_CHECKSUM),
    SX_FIELD("header_checksum","uint16",14,2,SX_CHECKSUM),
};
static const sx_layout sx_fw_jboot_stag_header = {0x601e0011U,"jboot_stag_header",sx_fw_jboot_stag_header_fields,SX_COUNT(sx_fw_jboot_stag_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_jboot_arm_header_fields[] = {
    SX_FIELD("rom_id","char[12]",0,12,SX_NONE),
    SX_FIELD("drange","uint16",12,2,SX_NONE),
    SX_FIELD("image_checksum","uint16",14,2,SX_CHECKSUM),
    SX_FIELD("block_size","uint32",16,4,SX_SIZE),
    SX_FIELD("reserved2","uint32",20,4,SX_RESERVED),
    SX_FIELD("reserved3","uint16",24,2,SX_RESERVED),
    SX_FIELD("lpvs","uint8",26,1,SX_ID),
    SX_FIELD("mbz","uint8",27,1,SX_RESERVED),
    SX_FIELD("timestamp_ticks","uint32",28,4,SX_NONE),
    SX_FIELD("erase_start","uint32",32,4,SX_ADDRESS),
    SX_FIELD("erase_size","uint32",36,4,SX_SIZE),
    SX_FIELD("data_start","uint32",40,4,SX_ADDRESS),
    SX_FIELD("data_size","uint32",44,4,SX_SIZE),
    SX_FIELD("reserved4","uint32",48,4,SX_RESERVED),
    SX_FIELD("reserved5","uint32",52,4,SX_RESERVED),
    SX_FIELD("reserved6","uint32",56,4,SX_RESERVED),
    SX_FIELD("reserved7","uint32",60,4,SX_RESERVED),
    SX_FIELD("header_id","uint16",64,2,SX_SIGNATURE),
    SX_FIELD("header_version","uint16",66,2,SX_ID),
    SX_FIELD("reserved8","uint16",68,2,SX_RESERVED),
    SX_FIELD("section_id","uint8",70,1,SX_ID),
    SX_FIELD("image_info_type","uint8",71,1,SX_ID),
    SX_FIELD("image_info_offset","uint32",72,4,SX_OFFSET),
    SX_FIELD("family","uint16",76,2,SX_ID),
    SX_FIELD("header_checksum","uint16",78,2,SX_CHECKSUM),
};
static const sx_layout sx_fw_jboot_arm_header = {0x601e0012U,"jboot_arm_header",sx_fw_jboot_arm_header_fields,SX_COUNT(sx_fw_jboot_arm_header_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_qnap_footer_fields[] = {
    SX_FIELD("magic","byte[6]",0,6,SX_SIGNATURE),
    SX_FIELD("encrypted_length","uint32",6,4,SX_SIZE),
    SX_FIELD("device_id","char[16]",10,16,SX_NONE),
    SX_FIELD("file_version","char[16]",26,16,SX_NONE),
    SX_FIELD("firmware_date","char[16]",42,16,SX_NONE),
    SX_FIELD("revision","char[16]",58,16,SX_NONE),
};
static const sx_layout sx_fw_qnap_footer = {0x601e0013U,"qnap_footer",sx_fw_qnap_footer_fields,SX_COUNT(sx_fw_qnap_footer_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_intel_flash_descriptor_map_fields[] = {
    SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("flmap0","uint32",4,4,SX_FLAGS),
    SX_FIELD("flmap1","uint32",8,4,SX_FLAGS),
    SX_FIELD("flmap2","uint32",12,4,SX_FLAGS),
};
static const sx_layout sx_fw_intel_flash_descriptor_map = {0x601e0014U,"intel_flash_descriptor_map",sx_fw_intel_flash_descriptor_map_fields,SX_COUNT(sx_fw_intel_flash_descriptor_map_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_intel_flash_component_fields[] = {
    SX_FIELD("flcomp","uint32",0,4,SX_FLAGS),
    SX_FIELD("flill","uint32",4,4,SX_FLAGS),
    SX_FIELD("flpb","uint32",8,4,SX_NONE),
};
static const sx_layout sx_fw_intel_flash_component = {0x601e0015U,"intel_flash_component",sx_fw_intel_flash_component_fields,SX_COUNT(sx_fw_intel_flash_component_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_intel_flash_region_fields[] = {
    SX_FIELD("flreg","uint32",0,4,SX_FLAGS),
};
static const sx_layout sx_fw_intel_flash_region = {0x601e0016U,"intel_flash_region",sx_fw_intel_flash_region_fields,SX_COUNT(sx_fw_intel_flash_region_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_setup_count_fields[] = {
    SX_FIELD("setup_sects","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("root_flags","uint16",1,2,SX_FLAGS),
};
static const sx_layout sx_fw_linux_boot_setup_count = {0x601e0017U,"linux_boot_setup_count",sx_fw_linux_boot_setup_count_fields,SX_COUNT(sx_fw_linux_boot_setup_count_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_syssize16_fields[] = {
    SX_FIELD("syssize_paragraphs","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("legacy_swap_dev","uint16",2,2,SX_ID),
};
static const sx_layout sx_fw_linux_boot_syssize16 = {0x601e0018U,"linux_boot_syssize16",sx_fw_linux_boot_syssize16_fields,SX_COUNT(sx_fw_linux_boot_syssize16_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_syssize32_fields[] = {
    SX_FIELD("syssize_paragraphs","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_fw_linux_boot_syssize32 = {0x601e0019U,"linux_boot_syssize32",sx_fw_linux_boot_syssize32_fields,SX_COUNT(sx_fw_linux_boot_syssize32_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_200_fields[] = {
    SX_FIELD("ram_size","uint16",0,2,SX_NONE),
    SX_FIELD("vid_mode","uint16",2,2,SX_ID),
    SX_FIELD("root_dev","uint16",4,2,SX_ID),
    SX_FIELD("boot_flag","uint16",6,2,SX_SIGNATURE),
    SX_FIELD("jump","byte[2]",8,2,SX_NONE),
    SX_FIELD("header","byte[4]",10,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",14,2,SX_ID),
    SX_FIELD("realmode_swtch","uint32",16,4,SX_POINTER),
    SX_FIELD("start_sys_seg","uint16",20,2,SX_ADDRESS),
    SX_FIELD("kernel_version","uint16",22,2,SX_OFFSET),
    SX_FIELD("type_of_loader","uint8",24,1,SX_ID),
    SX_FIELD("loadflags","uint8",25,1,SX_FLAGS),
    SX_FIELD("setup_move_size","uint16",26,2,SX_SIZE),
    SX_FIELD("code32_start","uint32",28,4,SX_ADDRESS),
    SX_FIELD("ramdisk_image","uint32",32,4,SX_ADDRESS),
    SX_FIELD("ramdisk_size","uint32",36,4,SX_SIZE),
    SX_FIELD("bootsect_kludge","uint32",40,4,SX_POINTER),
};
static const sx_layout sx_fw_linux_boot_header_200 = {0x601e001aU,"linux_boot_header_200",sx_fw_linux_boot_header_200_fields,SX_COUNT(sx_fw_linux_boot_header_200_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_201_fields[] = {
    SX_FIELD("heap_end_ptr","uint16",0,2,SX_OFFSET),
};
static const sx_layout sx_fw_linux_boot_header_201 = {0x601e001bU,"linux_boot_header_201",sx_fw_linux_boot_header_201_fields,SX_COUNT(sx_fw_linux_boot_header_201_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_202_fields[] = {
    SX_FIELD("ext_loader_ver","uint8",0,1,SX_ID),
    SX_FIELD("ext_loader_type","uint8",1,1,SX_ID),
    SX_FIELD("cmd_line_ptr","uint32",2,4,SX_POINTER),
};
static const sx_layout sx_fw_linux_boot_header_202 = {0x601e001cU,"linux_boot_header_202",sx_fw_linux_boot_header_202_fields,SX_COUNT(sx_fw_linux_boot_header_202_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_203_fields[] = {
    SX_FIELD("initrd_addr_max","uint32",0,4,SX_ADDRESS),
};
static const sx_layout sx_fw_linux_boot_header_203 = {0x601e001dU,"linux_boot_header_203",sx_fw_linux_boot_header_203_fields,SX_COUNT(sx_fw_linux_boot_header_203_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_205_fields[] = {
    SX_FIELD("kernel_alignment","uint32",0,4,SX_SIZE),
    SX_FIELD("relocatable_kernel","uint8",4,1,SX_FLAGS),
};
static const sx_layout sx_fw_linux_boot_header_205 = {0x601e001eU,"linux_boot_header_205",sx_fw_linux_boot_header_205_fields,SX_COUNT(sx_fw_linux_boot_header_205_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_206_fields[] = {
    SX_FIELD("cmdline_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sx_fw_linux_boot_header_206 = {0x601e001fU,"linux_boot_header_206",sx_fw_linux_boot_header_206_fields,SX_COUNT(sx_fw_linux_boot_header_206_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_207_fields[] = {
    SX_FIELD("hardware_subarch","uint32",0,4,SX_ID),
    SX_FIELD("hardware_subarch_data","uint64",4,8,SX_POINTER),
};
static const sx_layout sx_fw_linux_boot_header_207 = {0x601e0020U,"linux_boot_header_207",sx_fw_linux_boot_header_207_fields,SX_COUNT(sx_fw_linux_boot_header_207_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_208_fields[] = {
    SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("payload_length","uint32",4,4,SX_SIZE),
};
static const sx_layout sx_fw_linux_boot_header_208 = {0x601e0021U,"linux_boot_header_208",sx_fw_linux_boot_header_208_fields,SX_COUNT(sx_fw_linux_boot_header_208_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_209_fields[] = {
    SX_FIELD("setup_data","uint64",0,8,SX_POINTER),
};
static const sx_layout sx_fw_linux_boot_header_209 = {0x601e0022U,"linux_boot_header_209",sx_fw_linux_boot_header_209_fields,SX_COUNT(sx_fw_linux_boot_header_209_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_min_alignment_210_fields[] = {
    SX_FIELD("min_alignment","uint8",0,1,SX_NONE),
};
static const sx_layout sx_fw_linux_boot_min_alignment_210 = {0x601e0023U,"linux_boot_min_alignment_210",sx_fw_linux_boot_min_alignment_210_fields,SX_COUNT(sx_fw_linux_boot_min_alignment_210_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_210_fields[] = {
    SX_FIELD("pref_address","uint64",0,8,SX_ADDRESS),
    SX_FIELD("init_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sx_fw_linux_boot_header_210 = {0x601e0024U,"linux_boot_header_210",sx_fw_linux_boot_header_210_fields,SX_COUNT(sx_fw_linux_boot_header_210_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_211_fields[] = {
    SX_FIELD("handover_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sx_fw_linux_boot_header_211 = {0x601e0025U,"linux_boot_header_211",sx_fw_linux_boot_header_211_fields,SX_COUNT(sx_fw_linux_boot_header_211_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_212_fields[] = {
    SX_FIELD("xloadflags","uint16",0,2,SX_FLAGS),
};
static const sx_layout sx_fw_linux_boot_header_212 = {0x601e0026U,"linux_boot_header_212",sx_fw_linux_boot_header_212_fields,SX_COUNT(sx_fw_linux_boot_header_212_fields),SX_LE};

static const xx_data_struct_field_desc sx_fw_linux_boot_header_215_fields[] = {
    SX_FIELD("kernel_info_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sx_fw_linux_boot_header_215 = {0x601e0027U,"linux_boot_header_215",sx_fw_linux_boot_header_215_fields,SX_COUNT(sx_fw_linux_boot_header_215_fields),SX_LE};

static const sx_layout *const sx_firmwaremeta_layouts[] = {
    &sx_fw_android_boot_v0,
    &sx_fw_android_boot_qcom,
    &sx_fw_android_boot_v1_extra,
    &sx_fw_android_boot_v2_extra,
    &sx_fw_android_boot_v3,
    &sx_fw_android_boot_v4_extra,
    &sx_fw_android_vendor_boot_v3,
    &sx_fw_android_vendor_boot_v4_extra,
    &sx_fw_android_vendor_ramdisk_entry,
    &sx_fw_esp32_image_header,
    &sx_fw_esp32_segment_header,
    &sx_fw_esp32_checksum,
    &sx_fw_dlink_tlv_header,
    &sx_fw_tplink_linux_header,
    &sx_fw_tplink_rtos_header_prefix,
    &sx_fw_jboot_sch2_header,
    &sx_fw_jboot_stag_header,
    &sx_fw_jboot_arm_header,
    &sx_fw_qnap_footer,
    &sx_fw_intel_flash_descriptor_map,
    &sx_fw_intel_flash_component,
    &sx_fw_intel_flash_region,
    &sx_fw_linux_boot_setup_count,
    &sx_fw_linux_boot_syssize16,
    &sx_fw_linux_boot_syssize32,
    &sx_fw_linux_boot_header_200,
    &sx_fw_linux_boot_header_201,
    &sx_fw_linux_boot_header_202,
    &sx_fw_linux_boot_header_203,
    &sx_fw_linux_boot_header_205,
    &sx_fw_linux_boot_header_206,
    &sx_fw_linux_boot_header_207,
    &sx_fw_linux_boot_header_208,
    &sx_fw_linux_boot_header_209,
    &sx_fw_linux_boot_min_alignment_210,
    &sx_fw_linux_boot_header_210,
    &sx_fw_linux_boot_header_211,
    &sx_fw_linux_boot_header_212,
    &sx_fw_linux_boot_header_215,
};

static bool sx_firmwaremeta_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_ANDROIDBOOT:case XX_FILE_TYPE_ANDROID_VENDOR_BOOT:case XX_FILE_TYPE_ESPRESSIF_IMAGE:case XX_FILE_TYPE_DLINK_TLV:case XX_FILE_TYPE_TPLINK:case XX_FILE_TYPE_JBOOT:case XX_FILE_TYPE_QNAP_NAS_FIRMWARE:case XX_FILE_TYPE_PCHROM:case XX_FILE_TYPE_LINUXBOOT:return true;default:return false;}
}
static bool sx_fw_boot(sx_context *c)
{
    uint32_t v;if(!sx_u32(c,40,false,&v))return false;
    if(v>4)return sx_add(c,&sx_fw_android_boot_qcom,0,1632);
    if(v<=2){if(!sx_add(c,&sx_fw_android_boot_v0,0,1632))return false;
        if(v>=1&&!sx_add(c,&sx_fw_android_boot_v1_extra,1632,16))return false;
        return v<2||sx_add(c,&sx_fw_android_boot_v2_extra,1648,12);
    }
    if(v>4||!sx_add(c,&sx_fw_android_boot_v3,0,1580))return false;
    return v<4||sx_add(c,&sx_fw_android_boot_v4_extra,1580,4);
}
static bool sx_fw_vendor(sx_context *c)
{
    uint8_t h[2128];if(!sx_read(c,0,h,2112))return false;
    uint32_t v=xx_data_get_u32(h,2112,8,false),page=xx_data_get_u32(h,2112,12,false);
    if((v!=3&&v!=4)||page<512||page>65536||(page&(page-1))||!sx_add(c,&sx_fw_android_vendor_boot_v3,0,2112))return false;
    if(v==3)return true;
    if(!sx_read(c,2112,h+2112,16)||!sx_add(c,&sx_fw_android_vendor_boot_v4_extra,2112,16))return false;
    uint32_t n=xx_data_get_u32(h,2128,2116,false),width=xx_data_get_u32(h,2128,2120,false);
    uint64_t at=(2128U+page-1)&~((uint64_t)page-1);
    at+=((uint64_t)xx_data_get_u32(h,2128,24,false)+page-1)&~((uint64_t)page-1);
    at+=((uint64_t)xx_data_get_u32(h,2128,2100,false)+page-1)&~((uint64_t)page-1);
    return n<=65533&&(!n||width==108)&&sx_table(c,&sx_fw_android_vendor_ramdisk_entry,(int64_t)at,108,n);
}
static bool sx_fw_esp(sx_context *c)
{
    uint8_t h[24];if(!sx_read(c,0,h,24)||h[0]!=0xe9||!h[1]||h[1]>16||!sx_add(c,&sx_fw_esp32_image_header,0,24))return false;
    uint64_t at=24;
    for(unsigned i=0;i<h[1];i++){uint32_t n;if(!sx_u32(c,(int64_t)at+4,false,&n)||!sx_add(c,&sx_fw_esp32_segment_header,(int64_t)at,8)||!sx_range(c,(int64_t)at+8,n))return false;at+=8+(uint64_t)n;}
    uint64_t checksum=((at+16)&~UINT64_C(15))-1;
    return checksum<=(uint64_t)INT64_MAX&&sx_add(c,&sx_fw_esp32_checksum,(int64_t)checksum,1);
}
static bool sx_fw_pch(sx_context *c)
{
    uint32_t map1,comp;if(!sx_u32(c,0x18,false,&map1)||!sx_u32(c,0x30,false,&comp))return false;
    uint32_t master=(map1&255)*16,n=((comp>>17)&7)?16:7;
    if(master<0x40||master>0xe00)return false;if(n>(master-0x40)/4)n=(master-0x40)/4;
    return n>=5&&sx_add(c,&sx_fw_intel_flash_descriptor_map,0x10,16)&&sx_add(c,&sx_fw_intel_flash_component,0x30,12)&&sx_table(c,&sx_fw_intel_flash_region,0x40,4,n);
}
static bool sx_fw_linux(sx_context *c)
{
    uint16_t v;uint8_t jump[2];if(!sx_u16(c,0x206,false,&v)||!sx_read(c,0x200,jump,2)||(v>>8)!=2||jump[0]!=0xeb||jump[1]>=128)return false;
    uint32_t end=0x202+((uint32_t)jump[1]);
    if(!sx_add(c,&sx_fw_linux_boot_setup_count,0x1f1,3)||!sx_add(c,v<0x204?&sx_fw_linux_boot_syssize16:&sx_fw_linux_boot_syssize32,0x1f4,4)||!sx_add(c,&sx_fw_linux_boot_header_200,0x1f8,44))return false;
    const struct{uint16_t v;uint32_t at,n;const sx_layout *l;} ext[]={
        {0x201,0x224,2,&sx_fw_linux_boot_header_201},{0x202,0x226,6,&sx_fw_linux_boot_header_202},{0x203,0x22c,4,&sx_fw_linux_boot_header_203},
        {0x205,0x230,5,&sx_fw_linux_boot_header_205},{0x206,0x238,4,&sx_fw_linux_boot_header_206},{0x207,0x23c,12,&sx_fw_linux_boot_header_207},
        {0x208,0x248,8,&sx_fw_linux_boot_header_208},{0x209,0x250,8,&sx_fw_linux_boot_header_209},{0x20a,0x235,1,&sx_fw_linux_boot_min_alignment_210},
        {0x20a,0x258,12,&sx_fw_linux_boot_header_210},{0x20b,0x264,4,&sx_fw_linux_boot_header_211},{0x20c,0x236,2,&sx_fw_linux_boot_header_212},
        {0x20f,0x268,4,&sx_fw_linux_boot_header_215}};
    for(size_t i=0;i<SX_COUNT(ext);i++)if(v>=ext[i].v&&ext[i].at+ext[i].n<=end&&!sx_add(c,ext[i].l,ext[i].at,ext[i].n))return false;
    return true;
}
static int sx_fw_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sx_fw_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sx_fw_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end||(at>end&&!sx_raw(c,end,at-end)))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sx_fw_order);return !c->failed;
}
/* Select ambiguous vendor variants using the native reader's validated header span. */
static int64_t sx_fw_native_header_size(sx_context *c)
{
    Abstractformat *f=c->f;int64_t width=-1;
    if(!f->create_archive_records_reading||!f->get_current_archive_record||!f->free_archive_records_reading)return -1;
    xx_archive_record_state *st=(f->create_archive_records_reading)(f,NULL,c->pd);
    if(!st)return -1;
    const xx_archive_record *r=(f->get_current_archive_record)(f,st);
    if(r&&r->header_offset==f->base_address&&r->header_size>0&&r->header_size<=c->size)width=r->header_size;
    (f->free_archive_records_reading)(f,st);return width;
}
static bool sx_firmwaremeta_build(sx_context *c)
{
    if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    bool ok=false;switch(c->f->file_type){
    case XX_FILE_TYPE_ANDROIDBOOT:ok=sx_fw_boot(c);break;
    case XX_FILE_TYPE_ANDROID_VENDOR_BOOT:ok=sx_fw_vendor(c);break;
    case XX_FILE_TYPE_ESPRESSIF_IMAGE:ok=sx_fw_esp(c);break;
    case XX_FILE_TYPE_DLINK_TLV:ok=sx_add(c,&sx_fw_dlink_tlv_header,0,116);break;
    case XX_FILE_TYPE_TPLINK:{int64_t n=sx_fw_native_header_size(c);ok=n==512?sx_add(c,&sx_fw_tplink_linux_header,0,512):n==148?sx_add(c,&sx_fw_tplink_rtos_header_prefix,0,32):false;break;}
    case XX_FILE_TYPE_JBOOT:{int64_t n=sx_fw_native_header_size(c);const sx_layout *l=n==40?&sx_fw_jboot_sch2_header:n==80?&sx_fw_jboot_arm_header:n==16?&sx_fw_jboot_stag_header:NULL;ok=l&&sx_add(c,l,0,n);break;}
    case XX_FILE_TYPE_QNAP_NAS_FIRMWARE:ok=c->size>=78&&sx_add(c,&sx_fw_qnap_footer,c->size-74,74);break;
    case XX_FILE_TYPE_PCHROM:ok=sx_fw_pch(c);break;
    case XX_FILE_TYPE_LINUXBOOT:ok=sx_fw_linux(c);break;
    default:break;}return ok&&sx_fw_finish(c);
}
static bool sx_fw_text(xx_data_struct_record *r,const char *s)
{
    wchar_t b[512];size_t i=0;while(s[i]&&i+1<SX_COUNT(b)){b[i]=(unsigned char)s[i];i++;}if(s[i])return false;b[i]=0;return xx_data_struct_record_set_comment(r,b);
}
static bool sx_fw_flags(xx_data_struct_record *r,const char *const *names,size_t count)
{
    char out[512];size_t used=0;uint64_t value=xx_var_get_u64(&r->value),known=0;
    for(size_t i=0;i<count;i++)if(names[i]){known|=UINT64_C(1)<<i;if(value&(UINT64_C(1)<<i)){int n=xx_rt_snprintf(out+used,sizeof(out)-used,"%s%s",used?"|":"",names[i]);if(n<0||(size_t)n>=sizeof(out)-used)return false;used+=(size_t)n;}}
    uint64_t unknown=value&~known;if(unknown){int n=xx_rt_snprintf(out+used,sizeof(out)-used,"%s0x%llX",used?"|":"",(unsigned long long)unknown);if(n<0||(size_t)n>=sizeof(out)-used)return false;used+=(size_t)n;}
    if(!used)out[used++]='0';out[used]=0;return sx_fw_text(r,out);
}
static bool sx_firmwaremeta_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x601e0001U||id>=0x601e0001U+SX_COUNT(sx_firmwaremeta_layouts))return true;
    uint64_t v=xx_var_get_u64(&r->value);char b[400];const char *s=NULL;
    if(id==sx_fw_linux_boot_header_200.id&&!xx_rt_wcscmp(r->name,L"loadflags")){static const char *const flags[]={"LOADED_HIGH","KASLR_FLAG",NULL,NULL,NULL,"QUIET_FLAG","KEEP_SEGMENTS","CAN_USE_HEAP"};return sx_fw_flags(r,flags,SX_COUNT(flags));}
    if(id==sx_fw_linux_boot_header_212.id&&!xx_rt_wcscmp(r->name,L"xloadflags")){static const char *const flags[]={"XLF_KERNEL_64","XLF_CAN_BE_LOADED_ABOVE_4G","XLF_EFI_HANDOVER_32","XLF_EFI_HANDOVER_64","XLF_EFI_KEXEC","XLF_5LEVEL","XLF_5LEVEL_ENABLED","XLF_MEM_ENCRYPTION"};return sx_fw_flags(r,flags,SX_COUNT(flags));}
    if(!xx_rt_wcscmp(r->name,L"os_version")){
        if(!v)s="Unspecified OS version and security patch level";
        else{xx_rt_snprintf(b,sizeof(b),"Android %llu.%llu.%llu; security patch %llu-%02llu",(unsigned long long)((v>>25)&127),(unsigned long long)((v>>18)&127),(unsigned long long)((v>>11)&127),(unsigned long long)(2000+((v>>4)&127)),(unsigned long long)(v&15));s=b;}
    }else if(id==sx_fw_android_vendor_ramdisk_entry.id&&!xx_rt_wcscmp(r->name,L"ramdisk_type")){
        const char *types[]={"VENDOR_RAMDISK_TYPE_NONE","VENDOR_RAMDISK_TYPE_PLATFORM","VENDOR_RAMDISK_TYPE_RECOVERY","VENDOR_RAMDISK_TYPE_DLKM"};if(v<SX_COUNT(types))s=types[v];
    }else if(id==sx_fw_android_vendor_ramdisk_entry.id&&!xx_rt_wcscmp(r->name,L"ramdisk_offset"))s="Byte offset within the vendor ramdisk section";
    else if(id==sx_fw_esp32_image_header.id){
        if(!xx_rt_wcscmp(r->name,L"flash_mode")){const char *names[]={"QIO","QOUT","DIO","DOUT"};if(v<4)s=names[v];}
        else if(!xx_rt_wcscmp(r->name,L"flash_size_frequency")){const char *freq=(v&15)==0?"40 MHz":(v&15)==1?"26 MHz":(v&15)==2?"20 MHz":(v&15)==15?"80 MHz":"unknown frequency";unsigned size=(unsigned)(v>>4);if(size<=4)xx_rt_snprintf(b,sizeof(b),"%u MiB; %s",1U<<size,freq);else xx_rt_snprintf(b,sizeof(b),"Flash-size code %u; %s",size,freq);s=b;}
        else if(!xx_rt_wcscmp(r->name,L"chip_id")&&!v)s="ESP32";
        else if(!xx_rt_wcscmp(r->name,L"hash_appended"))s=v==0?"No appended SHA-256 digest":v==1?"SHA-256 digest appended":NULL;
        else if(!xx_rt_wcscmp(r->name,L"min_chip_rev"))s="Deprecated minimum chip revision";
        else if(!xx_rt_wcscmp(r->name,L"min_chip_rev_full")||!xx_rt_wcscmp(r->name,L"max_chip_rev_full")){xx_rt_snprintf(b,sizeof(b),"Chip revision %llu.%llu (major * 100 + minor)",(unsigned long long)(v/100),(unsigned long long)(v%100));s=b;}
    }else if(id==sx_fw_esp32_checksum.id)s="XOR of all segment payload bytes, initialized to 0xEF";
    else if(id==sx_fw_dlink_tlv_header.id&&!xx_rt_wcscmp(r->name,L"data_type")&&v==1)s="Firmware payload";
    else if(id==sx_fw_tplink_linux_header.id&&(!xx_rt_wcscmp(r->name,L"kernel_load_addr")||!xx_rt_wcscmp(r->name,L"kernel_entry_addr")))s="Encoded address word in the native-selected header byte order; mktplinkfw -e images byte-swap these two words without an identifying flag";
    else if(id==sx_fw_tplink_rtos_header_prefix.id&&!xx_rt_wcscmp(r->name,L"data_size"))s="Bytes following the first 20 bytes of the image";
    else if(id==sx_fw_jboot_sch2_header.id&&!xx_rt_wcscmp(r->name,L"compression_type")){const char *names[]={"Stored","JZ","gzip","LZMA"};if(v<4)s=names[v];}
    else if(!xx_rt_wcscmp(r->name,L"timestamp_ticks"))s="4-second ticks since 1998-03-07 16:00:00 UTC; stored value retained";
    else if(id==sx_fw_jboot_arm_header.id&&(!xx_rt_wcscmp(r->name,L"erase_start")||!xx_rt_wcscmp(r->name,L"data_start")))s="Flash coordinate; not a file offset";
    else if(id==sx_fw_intel_flash_region.id){uint64_t base=v&0x7fff,limit=(v>>16)&0x7fff;if(v==UINT32_MAX||base>limit)s="Disabled/unprogrammed flash region";else{xx_rt_snprintf(b,sizeof(b),"Flash base 0x%llX; inclusive limit 0x%llX (4 KiB units); reserved bits 0x%llX",(unsigned long long)(base<<12),(unsigned long long)((limit<<12)|4095),(unsigned long long)(v&UINT64_C(0x80008000)));s=b;}}
    else if(!xx_rt_wcscmp(r->name,L"setup_sects"))s="512-byte setup sectors; stored zero means 4";
    else if(!xx_rt_wcscmp(r->name,L"syssize_paragraphs"))s=id==sx_fw_linux_boot_syssize16.id?"16-byte paragraphs, low 16 bits; old bzImage size may wrap":"16-byte paragraphs";
    else if(!xx_rt_wcscmp(r->name,L"start_sys_seg"))s="Legacy load segment; linear address is the stored segment times 16";
    else if(!xx_rt_wcscmp(r->name,L"hardware_subarch_data"))s="Physical pointer to subarchitecture-specific data";
    else if(!xx_rt_wcscmp(r->name,L"kernel_version"))s="Byte offset relative to the setup header at image offset 0x200";
    else if(!xx_rt_wcscmp(r->name,L"payload_offset"))s="Byte offset relative to the protected-mode code";
    else if(!xx_rt_wcscmp(r->name,L"min_alignment"))s="Minimum alignment as a power of two; value is an exponent";
    else if(!xx_rt_wcscmp(r->name,L"kernel_info_offset")||!xx_rt_wcscmp(r->name,L"handover_offset"))s="Byte offset relative to the protected-mode code";
    return !s||sx_fw_text(r,s);
}
