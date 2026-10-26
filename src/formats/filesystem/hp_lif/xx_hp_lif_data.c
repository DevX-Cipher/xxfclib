/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HP_LIF data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_hp_lif_volume_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("label","char[6]",2,6,SX_NONE),
    SX_FIELD("directory_block","uint32",8,4,SX_NONE),
    SX_FIELD("lif_identifier","uint16",12,2,SX_ID),
    SX_FIELD("reserved0","uint16",14,2,SX_RESERVED),
    SX_FIELD("directory_blocks","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("version","uint16",20,2,SX_ID),
    SX_FIELD("reserved1","uint16",22,2,SX_RESERVED),
    SX_FIELD("tracks","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("heads","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("sectors_per_track","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("creation_date_bcd","byte[6]",36,6,SX_NONE),
};
const sx_layout sxcf_hp_lif_volume_header = {0x603d003aU,"hp_lif_volume_header",sxcf_hp_lif_volume_header_fields,SX_COUNT(sxcf_hp_lif_volume_header_fields),SX_BE};
static const xx_data_struct_field_desc sxcf_hp_lif_directory_entry_fields[] = {
    SX_FIELD("name","char[10]",0,10,SX_NONE),
    SX_FIELD("type","uint16",10,2,SX_ID),
    SX_FIELD("first_block","uint32",12,4,SX_NONE),
    SX_FIELD("block_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("creation_date_bcd","byte[6]",20,6,SX_NONE),
    SX_FIELD("volume_number","uint16",26,2,SX_FLAGS),
    SX_FIELD("implementation_defined","uint32",28,4,SX_NONE),
};
const sx_layout sxcf_hp_lif_directory_entry = {0x603d003bU,"hp_lif_directory_entry",sxcf_hp_lif_directory_entry_fields,SX_COUNT(sxcf_hp_lif_directory_entry_fields),SX_BE};
#define SXCF_LIMIT 24000U
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
static bool sxcf_lif(sx_context*c){uint8_t h[42],b[32];if(!sxcf_read(c,0,h,42)||sxcf16(h,1)!=0x8000)return false;uint64_t p=(uint64_t)sxcf32(h+8,1)*256,n=(uint64_t)sxcf32(h+16,1)*256;if(!p||!n||!sxcf_span(c,p,n)||!SXCF_ADD(c,hp_lif_volume_header,0))return false;for(uint64_t q=0;q+32<=n&&c->count<SXCF_LIMIT;q+=32){if(!sxcf_read(c,p+q,b,32)||!SXCF_ADD(c,hp_lif_directory_entry,p+q))return false;if(sxcf16(b+10,1)==65535)break;}return true;}
bool sx_hp_lif_build(sx_context*c)
{
 return sxcf_lif(c);
}
