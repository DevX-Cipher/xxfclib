/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MBR partition table data structures, moved out of the volume schema family. */
#include "../../xx_format_schema_volume.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/formats/filesystem/volume/xx_volume.h"
#include "xxfclib/formats/filesystem/gpt/xx_gpt.h"

static const xx_data_struct_field_desc sx_v_mbr_disk_signature_fields[] = {
    SX_FIELD("disk_signature", "uint32", 0, 4, SX_ID),
    SX_FIELD("reserved", "uint16", 4, 2, SX_RESERVED),
};
const sx_layout sx_v_mbr_disk_signature = {UINT32_C(0x60050026), "mbr_disk_signature", sx_v_mbr_disk_signature_fields, SX_COUNT(sx_v_mbr_disk_signature_fields), SX_LE};
static const xx_data_struct_field_desc sx_v_mbr_boot_signature_fields[] = {
    SX_FIELD("magic", "uint16", 0, 2, SX_SIGNATURE),
};
const sx_layout sx_v_mbr_boot_signature = {UINT32_C(0x60050028), "mbr_boot_signature", sx_v_mbr_boot_signature_fields, SX_COUNT(sx_v_mbr_boot_signature_fields), SX_LE};
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
bool sx_mbr_build(sx_context*c)
{
    if(!sx_v_mbr(c))return false;return true;
}
