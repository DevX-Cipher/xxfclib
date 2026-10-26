/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MSDOS data structures, moved out of the executable schema family. */
#include "../../xx_format_schema_executable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_mz_extended_header_fields[] = {
    SX_FIELD("e_res","uint16[4]",0,8,SX_RESERVED),
    SX_FIELD("e_oemid","uint16",8,2,SX_ID),
    SX_FIELD("e_oeminfo","uint16",10,2,SX_NONE),
    SX_FIELD("e_res2","uint16[10]",12,20,SX_RESERVED),
    SX_FIELD("e_lfanew","uint32",32,4,SX_OFFSET),
};
const sx_layout sx_mz_extended_header = {0x60030101U,"mz_extended_header",sx_mz_extended_header_fields,SX_COUNT(sx_mz_extended_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_mz_relocation_fields[] = {
    SX_FIELD("offset","uint16",0,2,SX_OFFSET),
    SX_FIELD("segment","uint16",2,2,SX_ADDRESS),
};
const sx_layout sx_mz_relocation = {0x60030102U,"mz_relocation",sx_mz_relocation_fields,SX_COUNT(sx_mz_relocation_fields),SX_LE};
static bool sx_mz_build(sx_context *c)
{
    uint8_t h[28];
    uint32_t header_size,reloc_offset,reloc_count,at=28;
    if(!sx_read(c,0,h,sizeof(h))||xx_data_get_u16(h,28,0,false)!=0x5a4d)return false;
    header_size=(uint32_t)xx_data_get_u16(h,28,8,false)*16;
    reloc_offset=xx_data_get_u16(h,28,24,false);
    reloc_count=xx_data_get_u16(h,28,6,false);
    if(header_size<28||header_size>(uint64_t)c->size||
       (reloc_count&&(reloc_offset<28||reloc_offset>header_size||reloc_count>(header_size-reloc_offset)/4)))return false;
    if(!sx_add(c,&sx_mz_header,0,28))return false;
    if(header_size>=64&&(!reloc_count||reloc_offset>=64)) {
        uint32_t secondary;uint16_t signature=0;
        sx_context probe=*c;
        /* A recognized PE/NE/LE/LX header can reside in the DOS overlay. */
        probe.size=xx_io_total_size(c->f->device)-c->f->base_address;
        if(!sx_u32(c,60,false,&secondary))return false;
        /* A late relocation table alone can also be classic DOS padding.
         * Match the native reader's known secondary-header signatures before
         * naming those bytes as the Windows extended header. */
        if(secondary>=64&&secondary<=(uint64_t)probe.size-2&&!sx_u16(&probe,secondary,false,&signature))return false;
        bool known=signature==0x454e||signature==0x454c||signature==0x584c;
        if(signature==0x4550&&secondary<=(uint64_t)probe.size-4) {
            uint32_t pe;if(!sx_u32(&probe,secondary,false,&pe))return false;known=pe==0x4550;
        }
        if(known) {
            if(!sx_add(c,&sx_mz_extended_header,28,36))return false;
            at=64;
        }
    }
    if(reloc_count) {
        if(!sx_raw(c,at,reloc_offset-at)||!sx_table(c,&sx_mz_relocation,reloc_offset,4,reloc_count))return false;
        at=reloc_offset+reloc_count*4;
    }
    return sx_raw(c,at,header_size-at)&&sx_raw(c,header_size,c->size-header_size);
}
bool sx_msdos_build(sx_context*c)
{
    return sx_mz_build(c);
}
