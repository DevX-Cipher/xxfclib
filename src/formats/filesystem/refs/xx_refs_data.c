/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * REFS data structures, moved out of the modernfs schema family. */
#include "../../xx_format_schema_modernfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmf_refs_volume_header_fields[] = {
    SX_FIELD("jump","byte[3]",0,3,SX_NONE),
    SX_FIELD("signature","char[8]",3,8,SX_SIGNATURE),
    SX_FIELD("zero","byte[5]",11,5,SX_RESERVED),
    SX_FIELD("identifier","uint32",16,4,SX_SIGNATURE),
    SX_FIELD("header_length","uint16",20,2,SX_SIZE),
    SX_FIELD("checksum","uint16",22,2,SX_NONE),
    SX_FIELD("sector_count","uint64",24,8,SX_COUNT_PROP),
    SX_FIELD("bytes_per_sector","uint32",32,4,SX_SIZE),
    SX_FIELD("sectors_per_cluster","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("major_version","uint8",40,1,SX_ID),
    SX_FIELD("minor_version","uint8",41,1,SX_ID),
    SX_FIELD("unknown_flags","uint16",42,2,SX_NONE),
    SX_FIELD("unknown1","uint32",44,4,SX_NONE),
    SX_FIELD("unknown2","uint64",48,8,SX_NONE),
    SX_FIELD("volume_serial","uint64",56,8,SX_ID),
    SX_FIELD("container_size","uint64",64,8,SX_NONE),
    SX_FIELD("unknown3","byte[440]",72,440,SX_NONE),
};
const sx_layout sxmf_refs_volume_header = {0x60420001U,"refs_volume_header",sxmf_refs_volume_header_fields,SX_COUNT(sxmf_refs_volume_header_fields),SX_LE};
#define SXMF_ADD(c,l,p) sxmf_put(c,&sxmf_##l,p,1)
static bool sxmf_refs(sx_context*c){uint8_t h[64];if(!sxmf_read(c,0,h,64)||xx_rt_memcmp(h+3,"ReFS\0\0\0\0",8)||xx_rt_memcmp(h+16,"FSRS",4)||!SXMF_ADD(c,refs_volume_header,0))return false;uint64_t bs=sxmf32(h+32,0),n=sxmf64(h+24,0);if(bs>=512&&bs<=65536&&sxmf_pow(bs)&&n&&n<=(uint64_t)c->size/bs){uint64_t p=(n-1)*bs;if(p&&sxmf_read(c,p,h,64)&&!xx_rt_memcmp(h+3,"ReFS\0\0\0\0",8)&&!xx_rt_memcmp(h+16,"FSRS",4)&&!SXMF_ADD(c,refs_volume_header,p))return false;}return true;}
bool sx_refs_build(sx_context*c)
{
 return sxmf_refs(c);
}
#undef SXMF_ADD
