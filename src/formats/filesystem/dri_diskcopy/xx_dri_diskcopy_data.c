/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DRI_DISKCOPY data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_dri_signature_fields[] = {
    SX_FIELD("signature","char[51]",0,51,SX_SIGNATURE),
};
const sx_layout sxst_dri_signature = {0x6037002bU,"dri_signature",sxst_dri_signature_fields,SX_COUNT(sxst_dri_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxst_dri_diskcopy_bpb_fields[] = {
    SX_FIELD("expected_five","uint8",0,1,SX_ID),
    SX_FIELD("drive_code","uint8",1,1,SX_ID),
    SX_FIELD("unknown_02","uint16",2,2,SX_NONE),
    SX_FIELD("cylinders","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("unknown_06","uint8",6,1,SX_NONE),
    SX_FIELD("bytes_per_sector","uint16",7,2,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("reserved_sectors","uint16",10,2,SX_COUNT_PROP),
    SX_FIELD("fat_count","uint8",12,1,SX_COUNT_PROP),
    SX_FIELD("root_entries","uint16",13,2,SX_COUNT_PROP),
    SX_FIELD("total_sectors","uint16",15,2,SX_COUNT_PROP),
    SX_FIELD("media_descriptor","uint8",17,1,SX_ID),
    SX_FIELD("sectors_per_fat","uint16",18,2,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint16",20,2,SX_COUNT_PROP),
    SX_FIELD("heads","uint16",22,2,SX_COUNT_PROP),
    SX_FIELD("hidden_sectors","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("drive_number","uint8",28,1,SX_ID),
    SX_FIELD("unknown_1d","byte[8]",29,8,SX_NONE),
    SX_FIELD("unknown_25","uint8",37,1,SX_NONE),
    SX_FIELD("sectors_per_track_copy","uint16",38,2,SX_COUNT_PROP),
    SX_FIELD("unknown_28","byte[144]",40,144,SX_NONE),
};
const sx_layout sxst_dri_diskcopy_bpb = {0x6037002cU,"dri_diskcopy_bpb",sxst_dri_diskcopy_bpb_fields,SX_COUNT(sxst_dri_diskcopy_bpb_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static bool sxst_dri(sx_context*c){if(c->size<419)return false;uint64_t p=(uint64_t)c->size-419;return SXST_ADD(c,dri_signature,p)&&SXST_TABLE(c,dri_diskcopy_bpb,p+51,2);}
bool sx_dri_diskcopy_build(sx_context*c)
{
 return sxst_dri(c);
}
#undef SXST_ADD
#undef SXST_TABLE
