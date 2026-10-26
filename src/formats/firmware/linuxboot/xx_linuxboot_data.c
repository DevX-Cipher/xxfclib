/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LINUXBOOT data structures, moved out of the firmwaremeta schema family. */
#include "../../xx_format_schema_firmwaremeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fw_linux_boot_setup_count_fields[] = {
    SX_FIELD("setup_sects","uint8",0,1,SX_COUNT_PROP),
    SX_FIELD("root_flags","uint16",1,2,SX_FLAGS),
};
const sx_layout sx_fw_linux_boot_setup_count = {0x601e0017U,"linux_boot_setup_count",sx_fw_linux_boot_setup_count_fields,SX_COUNT(sx_fw_linux_boot_setup_count_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_syssize32_fields[] = {
    SX_FIELD("syssize_paragraphs","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_fw_linux_boot_syssize32 = {0x601e0019U,"linux_boot_syssize32",sx_fw_linux_boot_syssize32_fields,SX_COUNT(sx_fw_linux_boot_syssize32_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_201_fields[] = {
    SX_FIELD("heap_end_ptr","uint16",0,2,SX_OFFSET),
};
const sx_layout sx_fw_linux_boot_header_201 = {0x601e001bU,"linux_boot_header_201",sx_fw_linux_boot_header_201_fields,SX_COUNT(sx_fw_linux_boot_header_201_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_202_fields[] = {
    SX_FIELD("ext_loader_ver","uint8",0,1,SX_ID),
    SX_FIELD("ext_loader_type","uint8",1,1,SX_ID),
    SX_FIELD("cmd_line_ptr","uint32",2,4,SX_POINTER),
};
const sx_layout sx_fw_linux_boot_header_202 = {0x601e001cU,"linux_boot_header_202",sx_fw_linux_boot_header_202_fields,SX_COUNT(sx_fw_linux_boot_header_202_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_203_fields[] = {
    SX_FIELD("initrd_addr_max","uint32",0,4,SX_ADDRESS),
};
const sx_layout sx_fw_linux_boot_header_203 = {0x601e001dU,"linux_boot_header_203",sx_fw_linux_boot_header_203_fields,SX_COUNT(sx_fw_linux_boot_header_203_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_205_fields[] = {
    SX_FIELD("kernel_alignment","uint32",0,4,SX_SIZE),
    SX_FIELD("relocatable_kernel","uint8",4,1,SX_FLAGS),
};
const sx_layout sx_fw_linux_boot_header_205 = {0x601e001eU,"linux_boot_header_205",sx_fw_linux_boot_header_205_fields,SX_COUNT(sx_fw_linux_boot_header_205_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_206_fields[] = {
    SX_FIELD("cmdline_size","uint32",0,4,SX_SIZE),
};
const sx_layout sx_fw_linux_boot_header_206 = {0x601e001fU,"linux_boot_header_206",sx_fw_linux_boot_header_206_fields,SX_COUNT(sx_fw_linux_boot_header_206_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_207_fields[] = {
    SX_FIELD("hardware_subarch","uint32",0,4,SX_ID),
    SX_FIELD("hardware_subarch_data","uint64",4,8,SX_POINTER),
};
const sx_layout sx_fw_linux_boot_header_207 = {0x601e0020U,"linux_boot_header_207",sx_fw_linux_boot_header_207_fields,SX_COUNT(sx_fw_linux_boot_header_207_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_208_fields[] = {
    SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("payload_length","uint32",4,4,SX_SIZE),
};
const sx_layout sx_fw_linux_boot_header_208 = {0x601e0021U,"linux_boot_header_208",sx_fw_linux_boot_header_208_fields,SX_COUNT(sx_fw_linux_boot_header_208_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_209_fields[] = {
    SX_FIELD("setup_data","uint64",0,8,SX_POINTER),
};
const sx_layout sx_fw_linux_boot_header_209 = {0x601e0022U,"linux_boot_header_209",sx_fw_linux_boot_header_209_fields,SX_COUNT(sx_fw_linux_boot_header_209_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_min_alignment_210_fields[] = {
    SX_FIELD("min_alignment","uint8",0,1,SX_NONE),
};
const sx_layout sx_fw_linux_boot_min_alignment_210 = {0x601e0023U,"linux_boot_min_alignment_210",sx_fw_linux_boot_min_alignment_210_fields,SX_COUNT(sx_fw_linux_boot_min_alignment_210_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_210_fields[] = {
    SX_FIELD("pref_address","uint64",0,8,SX_ADDRESS),
    SX_FIELD("init_size","uint32",8,4,SX_SIZE),
};
const sx_layout sx_fw_linux_boot_header_210 = {0x601e0024U,"linux_boot_header_210",sx_fw_linux_boot_header_210_fields,SX_COUNT(sx_fw_linux_boot_header_210_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_211_fields[] = {
    SX_FIELD("handover_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sx_fw_linux_boot_header_211 = {0x601e0025U,"linux_boot_header_211",sx_fw_linux_boot_header_211_fields,SX_COUNT(sx_fw_linux_boot_header_211_fields),SX_LE};
static const xx_data_struct_field_desc sx_fw_linux_boot_header_215_fields[] = {
    SX_FIELD("kernel_info_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sx_fw_linux_boot_header_215 = {0x601e0027U,"linux_boot_header_215",sx_fw_linux_boot_header_215_fields,SX_COUNT(sx_fw_linux_boot_header_215_fields),SX_LE};
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
bool sx_linuxboot_build(sx_context*c)
{
    bool ok=false;
    ok=sx_fw_linux(c);
    return ok&&sx_fw_finish(c);
}
