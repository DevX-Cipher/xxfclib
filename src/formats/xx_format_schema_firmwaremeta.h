/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The firmwaremeta schema family: what its family unit (xx_format_schema_firmwaremeta.c)
 * and its formats' data files share. Formats: ANDROIDBOOT; ANDROID_VENDOR_BOOT; ESPRESSIF_IMAGE; DLINK_TLV; TPLINK; JBOOT; QNAP_NAS_FIRMWARE; PCHROM; LINUXBOOT. */
#ifndef XX_FORMAT_SCHEMA_FIRMWAREMETA_H
#define XX_FORMAT_SCHEMA_FIRMWAREMETA_H
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"

/* Defined in the family unit or in a format's data file. */
extern const sx_layout sx_fw_android_boot_v0;
extern const sx_layout sx_fw_android_boot_qcom;
extern const sx_layout sx_fw_android_boot_v1_extra;
extern const sx_layout sx_fw_android_boot_v2_extra;
extern const sx_layout sx_fw_android_boot_v3;
extern const sx_layout sx_fw_android_boot_v4_extra;
extern const sx_layout sx_fw_android_vendor_boot_v3;
extern const sx_layout sx_fw_android_vendor_boot_v4_extra;
extern const sx_layout sx_fw_android_vendor_ramdisk_entry;
extern const sx_layout sx_fw_esp32_image_header;
extern const sx_layout sx_fw_esp32_segment_header;
extern const sx_layout sx_fw_esp32_checksum;
extern const sx_layout sx_fw_dlink_tlv_header;
extern const sx_layout sx_fw_tplink_linux_header;
extern const sx_layout sx_fw_tplink_rtos_header_prefix;
extern const sx_layout sx_fw_jboot_sch2_header;
extern const sx_layout sx_fw_jboot_stag_header;
extern const sx_layout sx_fw_jboot_arm_header;
extern const sx_layout sx_fw_qnap_footer;
extern const sx_layout sx_fw_intel_flash_descriptor_map;
extern const sx_layout sx_fw_intel_flash_component;
extern const sx_layout sx_fw_intel_flash_region;
extern const sx_layout sx_fw_linux_boot_setup_count;
extern const sx_layout sx_fw_linux_boot_syssize16;
extern const sx_layout sx_fw_linux_boot_syssize32;
extern const sx_layout sx_fw_linux_boot_header_200;
extern const sx_layout sx_fw_linux_boot_header_201;
extern const sx_layout sx_fw_linux_boot_header_202;
extern const sx_layout sx_fw_linux_boot_header_203;
extern const sx_layout sx_fw_linux_boot_header_205;
extern const sx_layout sx_fw_linux_boot_header_206;
extern const sx_layout sx_fw_linux_boot_header_207;
extern const sx_layout sx_fw_linux_boot_header_208;
extern const sx_layout sx_fw_linux_boot_header_209;
extern const sx_layout sx_fw_linux_boot_min_alignment_210;
extern const sx_layout sx_fw_linux_boot_header_210;
extern const sx_layout sx_fw_linux_boot_header_211;
extern const sx_layout sx_fw_linux_boot_header_212;
extern const sx_layout sx_fw_linux_boot_header_215;
bool sx_fw_finish(sx_context *c);
int64_t sx_fw_native_header_size(sx_context *c);

/* Per-format walkers, called by the family's build. */
bool sx_androidboot_build(sx_context *c);  /* firmware/androidboot/xx_androidboot_data.c */
bool sx_android_vendor_boot_build(sx_context *c);  /* firmware/android_vendor_boot/xx_android_vendor_boot_data.c */
bool sx_espressif_image_build(sx_context *c);  /* firmware/espressif_image/xx_espressif_image_data.c */
bool sx_dlink_tlv_build(sx_context *c);  /* firmware/dlink_tlv/xx_dlink_tlv_data.c */
bool sx_tplink_build(sx_context *c);  /* firmware/tplink/xx_tplink_data.c */
bool sx_jboot_build(sx_context *c);  /* firmware/jboot/xx_jboot_data.c */
bool sx_qnap_nas_firmware_build(sx_context *c);  /* firmware/qnap_nas_firmware/xx_qnap_nas_firmware_data.c */
bool sx_pchrom_build(sx_context *c);  /* firmware/pchrom/xx_pchrom_data.c */
bool sx_linuxboot_build(sx_context *c);  /* firmware/linuxboot/xx_linuxboot_data.c */

#endif
