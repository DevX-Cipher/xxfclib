/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PowerArc data structures, moved out of the archivetransport schema family. */
#include "../../xx_format_schema_archivetransport.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxatp_powerarc_header_fields[]={
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
};
const sx_layout sxatp_powerarc_header={UINT32_C(0x6089006d),"powerarc_header",sxatp_powerarc_header_fields,SX_COUNT(sxatp_powerarc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_powerarc_bzip2_stream_fields[]={
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("block_size_digit","char[1]",3,1,SX_NONE),
};
const sx_layout sxatp_powerarc_bzip2_stream={UINT32_C(0x6089006e),"powerarc_bzip2_stream",sxatp_powerarc_bzip2_stream_fields,SX_COUNT(sxatp_powerarc_bzip2_stream_fields),SX_BE};
static const xx_data_struct_field_desc sxatp_powerarc_bzip2_first_block_fields[]={
 SX_FIELD("block_magic","uint48",0,6,SX_SIGNATURE),
 SX_FIELD("block_crc32","uint32",6,4,SX_CHECKSUM),
 SX_FIELD("randomized","msb_bits[0,1]",10,1,SX_FLAGS),
 SX_FIELD("bwt_original_pointer","msb_bits[1,24]",10,4,SX_NONE),
};
const sx_layout sxatp_powerarc_bzip2_first_block={UINT32_C(0x6089006f),"powerarc_bzip2_first_block",sxatp_powerarc_bzip2_first_block_fields,SX_COUNT(sxatp_powerarc_bzip2_first_block_fields),SX_BE};
static const xx_data_struct_field_desc sxatp_powerarc_bzip2_empty_end_fields[]={
 SX_FIELD("end_magic","uint48",0,6,SX_SIGNATURE),
 SX_FIELD("combined_crc32","uint32",6,4,SX_CHECKSUM),
};
const sx_layout sxatp_powerarc_bzip2_empty_end={UINT32_C(0x60890070),"powerarc_bzip2_empty_end",sxatp_powerarc_bzip2_empty_end_fields,SX_COUNT(sxatp_powerarc_bzip2_empty_end_fields),SX_BE};
static bool sxatp_powerarc(sx_context*c){uint8_t h[18];if(!sxatp_read(c,0,h,18)||xx_rt_memcmp(h,"BZIP0001BZh",11)||h[11]<'1'||h[11]>'9'||!sxatp_add(c,&sxatp_powerarc_header,0)||!sxatp_add(c,&sxatp_powerarc_bzip2_stream,8))return false;static const uint8_t block[6]={0x31,0x41,0x59,0x26,0x53,0x59},end[6]={0x17,0x72,0x45,0x38,0x50,0x90};if(!xx_rt_memcmp(h+12,block,6))return sxatp_add(c,&sxatp_powerarc_bzip2_first_block,12);if(!xx_rt_memcmp(h+12,end,6))return sxatp_add(c,&sxatp_powerarc_bzip2_empty_end,12);return false;}
bool sx_powerarc_build(sx_context*c)
{
 return sxatp_powerarc(c);
}
