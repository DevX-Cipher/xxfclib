/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_ncsd data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_ncsd_header_fields[]={
 SX_FIELD("signature","bytes",0,256,SX_SIGNATURE),
 SX_FIELD("magic","bytes",256,4,SX_SIGNATURE),
 SX_FIELD("content_media_units","uint32",260,4,SX_NONE),
 SX_FIELD("media_id","uint64",264,8,SX_ID),
 SX_FIELD("filesystem_types","bytes",272,8,SX_ID),
 SX_FIELD("crypto_types","bytes",280,8,SX_ID),
};
const sx_layout sxgp_ncsd_header={UINT32_C(0x60360027),"ncsd_header",sxgp_ncsd_header_fields,SX_COUNT(sxgp_ncsd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncsd_partition_fields[]={
 SX_FIELD("offset_media_units","uint32",0,4,SX_NONE),
 SX_FIELD("size_media_units","uint32",4,4,SX_NONE),
};
const sx_layout sxgp_ncsd_partition={UINT32_C(0x60360028),"ncsd_partition",sxgp_ncsd_partition_fields,SX_COUNT(sxgp_ncsd_partition_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncsd_tail_fields[]={
 SX_FIELD("extended_header_sha256","bytes",0,32,SX_CHECKSUM),
 SX_FIELD("additional_header_size","uint32",32,4,SX_SIZE),
 SX_FIELD("sector_zero_offset_encoded","uint32",36,4,SX_NONE),
 SX_FIELD("partition_flags","bytes",40,8,SX_FLAGS),
 SX_FIELD("partition_id_0","uint64",48,8,SX_ID),
 SX_FIELD("partition_id_1","uint64",56,8,SX_ID),
 SX_FIELD("partition_id_2","uint64",64,8,SX_ID),
 SX_FIELD("partition_id_3","uint64",72,8,SX_ID),
 SX_FIELD("partition_id_4","uint64",80,8,SX_ID),
 SX_FIELD("partition_id_5","uint64",88,8,SX_ID),
 SX_FIELD("partition_id_6","uint64",96,8,SX_ID),
 SX_FIELD("partition_id_7","uint64",104,8,SX_ID),
 SX_FIELD("reserved","bytes",112,47,SX_RESERVED),
 SX_FIELD("extra_save_key_selector","uint8",159,1,SX_ID),
};
const sx_layout sxgp_ncsd_tail={UINT32_C(0x60360029),"ncsd_tail",sxgp_ncsd_tail_fields,SX_COUNT(sxgp_ncsd_tail_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_ncsd(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size;if(!SG_ROW(ncsd_header,0,end)||!sxgp_table(v,&sxgp_ncsd_partition,0x120,8,end)||!SG_ROW(ncsd_tail,0x160,end))return false;for(unsigned i=0;i<8;i++){uint64_t at,z;if(!sxgp_word(v,0x120+i*8,4,false,&at,end)||!sxgp_word(v,0x124+i*8,4,false,&z,end))return false;if(z){at*=512;z*=512;if(!sxgp_span(v,at,z,end)||!sxgp_ncch_at(v,at,at+z,false))return false;}}return true;}
bool sx_nintendo_ncsd_build(sxgp_view*v)
{
 return sxgp_ncsd(v);
}
#undef SG_ROW
