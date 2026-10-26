/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Delrina WinFax LSZ libraries data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_lsz_header_fields[]={
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
};
const sx_layout sxdm_lsz_header={UINT32_C(0x60230005),"lsz_header",sxdm_lsz_header_fields,SX_COUNT(sxdm_lsz_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_lsz_member_header_fields[]={
 SX_FIELD("tag","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("filename","char[13]",4,13,SX_STRING),
 SX_FIELD("reserved","uint16",17,2,SX_RESERVED),
 SX_FIELD("unpacked_size","int32",19,4,SX_SIZE),
 SX_FIELD("packed_size","int32",23,4,SX_SIZE),
 SX_FIELD("checksum","uint32",27,4,SX_CHECKSUM),
 SX_FIELD("dos_time","uint16",31,2,SX_TIME),
 SX_FIELD("dos_date","uint16",33,2,SX_TIME),
 SX_FIELD("attributes","uint16",35,2,SX_FLAGS),
 SX_FIELD("method","uint16",37,2,SX_ID),
 SX_FIELD("reserved_tail","bytes",39,12,SX_RESERVED),
};
const sx_layout sxdm_lsz_member_header={UINT32_C(0x60230006),"lsz_member_header",sxdm_lsz_member_header_fields,SX_COUNT(sxdm_lsz_member_header_fields),SX_LE};
static bool sxdm_lsz(sx_context *c)
{
 uint8_t b[51];int64_t at=6;if(!sxdm_add(c,&sxdm_lsz_header,0,6))return false;
 for(unsigned i=0;at<c->size;i++){if(i>=65536||!sx_read(c,at,b,51))return false;int32_t n=(int32_t)sxdm_u32(b+23);if(n<0||!sxdm_span(c,at+51,(uint32_t)n)||!sxdm_add(c,&sxdm_lsz_member_header,at,51))return false;at+=51+(int64_t)n;}return true;
}
bool sx_lsz_build(sx_context*c)
{
 return sxdm_lsz(c);
}
