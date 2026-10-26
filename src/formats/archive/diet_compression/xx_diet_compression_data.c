/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * diet_compression data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_diet_data_v100_fields[]={
 SX_FIELD("exit_instructions","uint8[4]",0,4,SX_NONE),
 SX_FIELD("signature","uint8[2]",4,2,SX_SIGNATURE),
 SX_FIELD("compressed_crc16","uint16",6,2,SX_CHECKSUM),
};
const sx_layout sxaend_diet_data_v100={UINT32_C(0x6084000f),"diet_data_v100",sxaend_diet_data_v100_fields,SX_COUNT(sxaend_diet_data_v100_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_diet_data_v102_fields[]={
 SX_FIELD("signature","uint8[5]",0,5,SX_SIGNATURE),
};
const sx_layout sxaend_diet_data_v102={UINT32_C(0x60840010),"diet_data_v102",sxaend_diet_data_v102_fields,SX_COUNT(sxaend_diet_data_v102_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_diet_data_v144_fields[]={
 SX_FIELD("exit_instructions","uint8[4]",0,4,SX_NONE),
 SX_FIELD("signature","uint8[5]",4,5,SX_SIGNATURE),
};
const sx_layout sxaend_diet_data_v144={UINT32_C(0x60840011),"diet_data_v144",sxaend_diet_data_v144_fields,SX_COUNT(sxaend_diet_data_v144_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_diet_data_lengths_fields[]={
 SX_FIELD("flags_and_packed_size_high","uint8",0,1,SX_NONE),
 SX_FIELD("packed_size_low","uint16",1,2,SX_NONE),
 SX_FIELD("compressed_crc16","uint16",3,2,SX_CHECKSUM),
 SX_FIELD("uncompressed_size_high","uint8",5,1,SX_NONE),
 SX_FIELD("uncompressed_size_low","uint16",6,2,SX_NONE),
};
const sx_layout sxaend_diet_data_lengths={UINT32_C(0x60840012),"diet_data_lengths",sxaend_diet_data_lengths_fields,SX_COUNT(sxaend_diet_data_lengths_fields),SX_LE};
static bool sxaend_diet(sx_context*c){uint8_t h[9];if(!sxaend_read(c,0,h,8))return false;uint64_t p=0;if(!xx_rt_memcmp(h,"\x9d\x89" "dlz",5)){if(!sxaend_add(c,&sxaend_diet_data_v102,0))return false;p=5;}else if(!xx_rt_memcmp(h,"\xb4\x4c\xcd\x21\x9d\x89",6)){if(sxaend_read(c,6,h,3)&&!xx_rt_memcmp(h,"dlz",3)){if(!sxaend_add(c,&sxaend_diet_data_v144,0))return false;p=9;}else return sxaend_add(c,&sxaend_diet_data_v100,0);}else return false;return sxaend_add(c,&sxaend_diet_data_lengths,p);}
bool sx_diet_compression_build(sx_context*c)
{
 return sxaend_diet(c);
}
