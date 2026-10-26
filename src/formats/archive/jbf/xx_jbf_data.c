/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JBF archives (headerless DOS LZHUF archiver) data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_jbf_member_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("uncompressed_size","int32",17,4,SX_SIZE),
 SX_FIELD("payload_offset","int32",21,4,SX_OFFSET),
 SX_FIELD("checksum","uint16",25,2,SX_CHECKSUM),
 SX_FIELD("dos_time","uint16",27,2,SX_NONE),
 SX_FIELD("dos_date","uint16",29,2,SX_NONE),
};
const sx_layout sxafr_jbf_member = {UINT32_C(0x60540013),"jbf_member",sxafr_jbf_member_fields,SX_COUNT(sxafr_jbf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_jbf_count_fields[] = {
 SX_FIELD("member_count","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxafr_jbf_count = {UINT32_C(0x60540014),"jbf_count",sxafr_jbf_count_fields,SX_COUNT(sxafr_jbf_count_fields),SX_LE};
static bool sxafr_jbf(sx_context*c){uint64_t n;if(c->size<1||!sxafr_word(c,(uint64_t)c->size-1,1,false,&n)||!n||n>((uint64_t)c->size-1)/31)return false;uint64_t p=(uint64_t)c->size-1-n*31;for(uint64_t i=0;i<n;i++)if(!sxafr_add(c,&sxafr_jbf_member,p+i*31))return false;return sxafr_add(c,&sxafr_jbf_count,(uint64_t)c->size-1);}
bool sx_jbf_build(sx_context*c)
{
 return sxafr_jbf(c);
}
