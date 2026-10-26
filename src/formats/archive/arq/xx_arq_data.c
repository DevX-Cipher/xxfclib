/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ARQ data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_arq_container_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("total_unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
const sx_layout sxae_arq_container = {UINT32_C(0x60170008),"arq_container",sxae_arq_container_fields,SX_COUNT(sxae_arq_container_fields),SX_LE};
static const xx_data_struct_field_desc sxae_arq_member_prefix_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("signature","uint16",4,2,SX_SIGNATURE),
    SX_FIELD("name_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxae_arq_member_prefix = {UINT32_C(0x60170009),"arq_member_prefix",sxae_arq_member_prefix_fields,SX_COUNT(sxae_arq_member_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxae_arq_member_tail_fields[] = {
    SX_FIELD("modified","uint32",0,4,SX_NONE),
    SX_FIELD("attributes","uint16",4,2,SX_FLAGS),
    SX_FIELD("reserved","uint32",6,4,SX_RESERVED),
    SX_FIELD("packed_size","uint32",10,4,SX_SIZE),
    SX_FIELD("unpacked_size","uint32",14,4,SX_SIZE),
    SX_FIELD("packed_crc32","uint32",18,4,SX_CHECKSUM),
    SX_FIELD("method","uint16",22,2,SX_ID),
    SX_FIELD("flags","uint8",24,1,SX_FLAGS),
    SX_FIELD("reserved_tail","uint8[8]",25,8,SX_RESERVED),
};
const sx_layout sxae_arq_member_tail = {UINT32_C(0x6017000a),"arq_member_tail",sxae_arq_member_tail_fields,SX_COUNT(sxae_arq_member_tail_fields),SX_LE};
static bool sxae_arq(sx_context *c)
{
 int64_t p=0;uint8_t b[12];if(!sx_read(c,0,b,4))return false;if(sxae32(b)==UINT32_C(0x02045767)){if(!sxae_add(c,&sxae_arq_container,0))return false;p=12;}
 for(unsigned k=0;k<20000;k++){if(!sx_read(c,p,b,8)||sxae32(b)!=UINT32_C(0x01045767))return false;uint16_t n=sxae16(b+6);int64_t t=p+8+n;uint32_t z;
 if(!sxae_bound(c,p,41+n)||!sxae_add(c,&sxae_arq_member_prefix,p)||!sxae_add(c,&sxae_arq_member_tail,t))return false;
 if(!n)return true;if(!sx_u32(c,t+10,false,&z)||!sxae_data(c,t+33,z))return false;p=t+33+z;}return false;
}
bool sx_arq_build(sx_context*c)
{
 return sxae_arq(c);
}
