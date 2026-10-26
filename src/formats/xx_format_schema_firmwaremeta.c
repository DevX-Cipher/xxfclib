/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical firmware container metadata. Unimplemented payloads remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_firmwaremeta.h"
static const xx_data_struct_field_desc sx_fw_android_vendor_ramdisk_entry_fields[] = {
    SX_FIELD("ramdisk_size","uint32",0,4,SX_SIZE),
    SX_FIELD("ramdisk_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("ramdisk_type","uint32",8,4,SX_ID),
    SX_FIELD("ramdisk_name","char[32]",12,32,SX_NONE),
    SX_FIELD("board_id","uint32[16]",44,64,SX_ID),
};
const sx_layout sx_fw_android_vendor_ramdisk_entry = {0x601e0009U,"android_vendor_ramdisk_entry",sx_fw_android_vendor_ramdisk_entry_fields,SX_COUNT(sx_fw_android_vendor_ramdisk_entry_fields),SX_LE};
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
const sx_layout sx_fw_esp32_image_header = {0x601e000aU,"esp32_image_header",sx_fw_esp32_image_header_fields,SX_COUNT(sx_fw_esp32_image_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_esp32_checksum_fields[] = {
    SX_FIELD("xor_checksum","uint8",0,1,SX_CHECKSUM),
};
const sx_layout sx_fw_esp32_checksum = {0x601e000cU,"esp32_checksum",sx_fw_esp32_checksum_fields,SX_COUNT(sx_fw_esp32_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_dlink_tlv_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("model_name","char[32]",4,32,SX_NONE),
    SX_FIELD("board_id","char[32]",36,32,SX_NONE),
    SX_FIELD("unknown","byte[8]",68,8,SX_NONE),
    SX_FIELD("md5","char[32]",76,32,SX_CHECKSUM),
    SX_FIELD("data_type","uint32",108,4,SX_ID),
    SX_FIELD("data_length","uint32",112,4,SX_SIZE),
};
const sx_layout sx_fw_dlink_tlv_header = {0x601e000dU,"dlink_tlv_header",sx_fw_dlink_tlv_header_fields,SX_COUNT(sx_fw_dlink_tlv_header_fields),SX_LE};
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
const sx_layout sx_fw_tplink_linux_header = {0x601e000eU,"tplink_linux_header",sx_fw_tplink_linux_header_fields,SX_COUNT(sx_fw_tplink_linux_header_fields),SX_FILE};
static const xx_data_struct_field_desc sx_fw_tplink_rtos_header_prefix_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("unknown","byte[16]",4,16,SX_NONE),
    SX_FIELD("magic2","uint32",20,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",24,4,SX_SIZE),
    SX_FIELD("model_number","uint16",28,2,SX_ID),
    SX_FIELD("hardware_revision_major","uint8",30,1,SX_ID),
    SX_FIELD("hardware_revision_minor","uint8",31,1,SX_ID),
};
const sx_layout sx_fw_tplink_rtos_header_prefix = {0x601e000fU,"tplink_rtos_header_prefix",sx_fw_tplink_rtos_header_prefix_fields,SX_COUNT(sx_fw_tplink_rtos_header_prefix_fields),SX_BE};
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
const sx_layout sx_fw_jboot_sch2_header = {0x601e0010U,"jboot_sch2_header",sx_fw_jboot_sch2_header_fields,SX_COUNT(sx_fw_jboot_sch2_header_fields),SX_LE};
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
const sx_layout sx_fw_jboot_arm_header = {0x601e0012U,"jboot_arm_header",sx_fw_jboot_arm_header_fields,SX_COUNT(sx_fw_jboot_arm_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_intel_flash_region_fields[] = {
    SX_FIELD("flreg","uint32",0,4,SX_FLAGS),
};
const sx_layout sx_fw_intel_flash_region = {0x601e0016U,"intel_flash_region",sx_fw_intel_flash_region_fields,SX_COUNT(sx_fw_intel_flash_region_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_syssize16_fields[] = {
    SX_FIELD("syssize_paragraphs","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("legacy_swap_dev","uint16",2,2,SX_ID),
};
const sx_layout sx_fw_linux_boot_syssize16 = {0x601e0018U,"linux_boot_syssize16",sx_fw_linux_boot_syssize16_fields,SX_COUNT(sx_fw_linux_boot_syssize16_fields),SX_LE};
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
const sx_layout sx_fw_linux_boot_header_200 = {0x601e001aU,"linux_boot_header_200",sx_fw_linux_boot_header_200_fields,SX_COUNT(sx_fw_linux_boot_header_200_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_212_fields[] = {
    SX_FIELD("xloadflags","uint16",0,2,SX_FLAGS),
};
const sx_layout sx_fw_linux_boot_header_212 = {0x601e0026U,"linux_boot_header_212",sx_fw_linux_boot_header_212_fields,SX_COUNT(sx_fw_linux_boot_header_212_fields),SX_LE};
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
static int sx_fw_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
bool sx_fw_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sx_fw_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end||(at>end&&!sx_raw(c,end,at-end)))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sx_fw_order);return !c->failed;
}
/* Select ambiguous vendor variants using the native reader's validated header span. */
int64_t sx_fw_native_header_size(sx_context *c)
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
    if(c->f->file_type==XX_FILE_TYPE_ANDROIDBOOT)return sx_androidboot_build(c);
    if(c->f->file_type==XX_FILE_TYPE_ANDROID_VENDOR_BOOT)return sx_android_vendor_boot_build(c);
    if(c->f->file_type==XX_FILE_TYPE_ESPRESSIF_IMAGE)return sx_espressif_image_build(c);
    if(c->f->file_type==XX_FILE_TYPE_DLINK_TLV)return sx_dlink_tlv_build(c);
    if(c->f->file_type==XX_FILE_TYPE_TPLINK)return sx_tplink_build(c);
    if(c->f->file_type==XX_FILE_TYPE_JBOOT)return sx_jboot_build(c);
    if(c->f->file_type==XX_FILE_TYPE_QNAP_NAS_FIRMWARE)return sx_qnap_nas_firmware_build(c);
    if(c->f->file_type==XX_FILE_TYPE_PCHROM)return sx_pchrom_build(c);
    if(c->f->file_type==XX_FILE_TYPE_LINUXBOOT)return sx_linuxboot_build(c);
    return false;
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
const sx_family sx_firmwaremeta_family={sx_firmwaremeta_supports,sx_firmwaremeta_build,sx_firmwaremeta_layouts,SX_COUNT(sx_firmwaremeta_layouts),sx_firmwaremeta_comment};
