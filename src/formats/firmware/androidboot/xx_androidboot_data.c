/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ANDROIDBOOT data structures, moved out of the firmwaremeta schema family. */
#include "../../xx_format_schema_firmwaremeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

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
const sx_layout sx_fw_android_boot_v0 = {0x601e0001U,"android_boot_v0",sx_fw_android_boot_v0_fields,SX_COUNT(sx_fw_android_boot_v0_fields),SX_LE};
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
const sx_layout sx_fw_android_boot_qcom = {0x601e0002U,"android_boot_qcom",sx_fw_android_boot_qcom_fields,SX_COUNT(sx_fw_android_boot_qcom_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_android_boot_v1_extra_fields[] = {
    SX_FIELD("recovery_dtbo_size","uint32",0,4,SX_SIZE),
    SX_FIELD("recovery_dtbo_offset","uint64",4,8,SX_OFFSET),
    SX_FIELD("header_size","uint32",12,4,SX_SIZE),
};
const sx_layout sx_fw_android_boot_v1_extra = {0x601e0003U,"android_boot_v1_extra",sx_fw_android_boot_v1_extra_fields,SX_COUNT(sx_fw_android_boot_v1_extra_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_android_boot_v2_extra_fields[] = {
    SX_FIELD("dtb_size","uint32",0,4,SX_SIZE),
    SX_FIELD("dtb_addr","uint64",4,8,SX_ADDRESS),
};
const sx_layout sx_fw_android_boot_v2_extra = {0x601e0004U,"android_boot_v2_extra",sx_fw_android_boot_v2_extra_fields,SX_COUNT(sx_fw_android_boot_v2_extra_fields),SX_LE};
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
const sx_layout sx_fw_android_boot_v3 = {0x601e0005U,"android_boot_v3",sx_fw_android_boot_v3_fields,SX_COUNT(sx_fw_android_boot_v3_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_android_boot_v4_extra_fields[] = {
    SX_FIELD("signature_size","uint32",0,4,SX_SIZE),
};
const sx_layout sx_fw_android_boot_v4_extra = {0x601e0006U,"android_boot_v4_extra",sx_fw_android_boot_v4_extra_fields,SX_COUNT(sx_fw_android_boot_v4_extra_fields),SX_LE};
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
bool sx_androidboot_build(sx_context*c)
{
    bool ok=false;
    ok=sx_fw_boot(c);
    return ok&&sx_fw_finish(c);
}
