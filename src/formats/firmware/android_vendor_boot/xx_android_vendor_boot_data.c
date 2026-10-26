/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ANDROID_VENDOR_BOOT data structures, moved out of the firmwaremeta schema family. */
#include "../../xx_format_schema_firmwaremeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

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
const sx_layout sx_fw_android_vendor_boot_v3 = {0x601e0007U,"android_vendor_boot_v3",sx_fw_android_vendor_boot_v3_fields,SX_COUNT(sx_fw_android_vendor_boot_v3_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_android_vendor_boot_v4_extra_fields[] = {
    SX_FIELD("vendor_ramdisk_table_size","uint32",0,4,SX_SIZE),
    SX_FIELD("vendor_ramdisk_table_entry_num","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("vendor_ramdisk_table_entry_size","uint32",8,4,SX_SIZE),
    SX_FIELD("bootconfig_size","uint32",12,4,SX_SIZE),
};
const sx_layout sx_fw_android_vendor_boot_v4_extra = {0x601e0008U,"android_vendor_boot_v4_extra",sx_fw_android_vendor_boot_v4_extra_fields,SX_COUNT(sx_fw_android_vendor_boot_v4_extra_fields),SX_LE};
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
bool sx_android_vendor_boot_build(sx_context*c)
{
    bool ok=false;
    ok=sx_fw_vendor(c);
    return ok&&sx_fw_finish(c);
}
