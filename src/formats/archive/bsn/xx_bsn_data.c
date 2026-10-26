/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BSN data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_bsn_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint16",4,2,SX_NONE),
};
const sx_layout sxae_bsn_header = {UINT32_C(0x60170004),"bsn_header",sxae_bsn_header_fields,SX_COUNT(sxae_bsn_header_fields),SX_BE};
static const xx_data_struct_field_desc sxae_bsn_member_prefix_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("body_size","uint16",4,2,SX_SIZE),
    SX_FIELD("attributes","uint32",6,4,SX_FLAGS),
    SX_FIELD("date_time","uint32",10,4,SX_NONE),
};
const sx_layout sxae_bsn_member_prefix = {UINT32_C(0x60170005),"bsn_member_prefix",sxae_bsn_member_prefix_fields,SX_COUNT(sxae_bsn_member_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxae_bsn_member_sizes_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("header_crc32","uint32",12,4,SX_CHECKSUM),
};
const sx_layout sxae_bsn_member_sizes = {UINT32_C(0x60170006),"bsn_member_sizes",sxae_bsn_member_sizes_fields,SX_COUNT(sxae_bsn_member_sizes_fields),SX_BE};
static const xx_data_struct_field_desc sxae_bsn_end_fields[] = {
    SX_FIELD("marker","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxae_bsn_end = {UINT32_C(0x60170007),"bsn_end",sxae_bsn_end_fields,SX_COUNT(sxae_bsn_end_fields),SX_BE};
static bool sxae_bsn(sx_context *c)
{
 uint8_t b[14];int64_t p=6;if(!sx_read(c,0,b,6)||xx_rt_memcmp(b,"\xff" "BSG",4)||!sxae_add(c,&sxae_bsn_header,0))return false;
 for(unsigned k=0;k<20000;k++){if(!sx_read(c,p,b,2))return false;if(!b[0]&&!b[1])return sxae_add(c,&sxae_bsn_end,p);
 if(!sx_read(c,p,b,14)||xx_rt_memcmp(b,"\xff" "BSA",4))return false;uint16_t z=xx_data_get_u16(b+4,2,0,true);if(z<22||z>281||!sxae_bound(c,p,10+z))return false;
 int64_t tail=p+6+z-12;uint32_t packed;if(!sx_u32(c,tail+4,true,&packed)||!sxae_add(c,&sxae_bsn_member_prefix,p)||!sxae_add(c,&sxae_bsn_member_sizes,tail)||!sxae_data(c,p+10+z,packed))return false;p+=10+z+packed;}return false;
}
bool sx_bsn_build(sx_context*c)
{
 return sxae_bsn(c);
}
