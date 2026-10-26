/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MACHOFAT data structures, moved out of the executable schema family. */
#include "../../xx_format_schema_executable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fat_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("nfat_arch","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sx_fat_header_le = {0x6003001BU,"fat_header_le",sx_fat_header_fields,SX_COUNT(sx_fat_header_fields),SX_LE};
const sx_layout sx_fat_header_be = {0x6003001CU,"fat_header_be",sx_fat_header_fields,SX_COUNT(sx_fat_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_fat_arch_fields[] = {
    SX_FIELD("cputype","uint32",0,4,SX_ID),
    SX_FIELD("cpusubtype","uint32",4,4,SX_ID),
    SX_FIELD("offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("size","uint32",12,4,SX_SIZE),
    SX_FIELD("align","uint32",16,4,SX_NONE),
};
const sx_layout sx_fat_arch_le = {0x6003001DU,"fat_arch_le",sx_fat_arch_fields,SX_COUNT(sx_fat_arch_fields),SX_LE};
const sx_layout sx_fat_arch_be = {0x6003001EU,"fat_arch_be",sx_fat_arch_fields,SX_COUNT(sx_fat_arch_fields),SX_BE};
static const xx_data_struct_field_desc sx_fat_arch_64_fields[] = {
    SX_FIELD("cputype","uint32",0,4,SX_ID),
    SX_FIELD("cpusubtype","uint32",4,4,SX_ID),
    SX_FIELD("offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("size","uint64",16,8,SX_SIZE),
    SX_FIELD("align","uint32",24,4,SX_NONE),
    SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
const sx_layout sx_fat_arch_64_le = {0x6003001FU,"fat_arch_64_le",sx_fat_arch_64_fields,SX_COUNT(sx_fat_arch_64_fields),SX_LE};
const sx_layout sx_fat_arch_64_be = {0x60030020U,"fat_arch_64_be",sx_fat_arch_64_fields,SX_COUNT(sx_fat_arch_64_fields),SX_BE};
static bool sx_fat_build(sx_context *c)
{
    uint8_t h[8];uint32_t magic,n;bool be,wide;
    if(!sx_read(c,0,h,8))return false;
    magic=xx_data_get_u32(h,8,0,true);
    be=magic==0xcafebabeU||magic==0xcafebabfU;wide=magic==0xcafebabfU||magic==0xbfbafecaU;
    if(!be&&magic!=0xbebafecaU&&magic!=0xbfbafecaU)return false;
    n=xx_data_get_u32(h,8,4,be);if(!n||n>4096)return false;
    if(!sx_add(c,be?&sx_fat_header_be:&sx_fat_header_le,0,8)||!sx_table(c,wide?(be?&sx_fat_arch_64_be:&sx_fat_arch_64_le):(be?&sx_fat_arch_be:&sx_fat_arch_le),8,wide?32:20,n))return false;
    for(uint32_t i=0;i<n;i++) {
        uint8_t a[32];uint64_t off,size;int stride=wide?32:20;
        if(!sx_read(c,8+(int64_t)i*stride,a,stride))return false;
        off=wide?xx_data_get_u64(a,stride,8,be):xx_data_get_u32(a,stride,8,be);
        size=wide?xx_data_get_u64(a,stride,16,be):xx_data_get_u32(a,stride,12,be);
        if(off>INT64_MAX||size>INT64_MAX||!sx_raw(c,(int64_t)off,(int64_t)size))return false;
    }return true;
}
bool sx_machofat_build(sx_context*c)
{
    return sx_fat_build(c);
}
