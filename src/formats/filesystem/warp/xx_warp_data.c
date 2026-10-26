/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * WARP data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_warp_track_fields[] = {
    SX_FIELD("signature","char[10]",0,10,SX_SIGNATURE),
    SX_FIELD("cylinder","uint16",10,2,SX_NONE),
    SX_FIELD("side","char[4]",12,4,SX_ID),
    SX_FIELD("version","uint16",16,2,SX_ID),
    SX_FIELD("compression","uint16",18,2,SX_ID),
    SX_FIELD("data_crc","uint16",20,2,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",22,4,SX_SIZE),
};
const sx_layout sxst_warp_track = {0x60370017U,"warp_track",sxst_warp_track_fields,SX_COUNT(sxst_warp_track_fields),SX_BE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
static bool sxst_warp(sx_context*c){uint64_t p=0;uint8_t b[26];for(unsigned i=0;i<160;i++){if(!sxst_read(c,p,b,26)||xx_rt_memcmp(b,"Warp v1.1",10))break;uint64_t z=sxst_uint(b+22,4,true);if(!sxst_span(c,p+26,z)||!SXST_ADD(c,warp_track,p))break;p+=26+z;}return c->count>0;}
bool sx_warp_build(sx_context*c)
{
 return sxst_warp(c);
}
#undef SXST_ADD
