/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * The Bat! MSB mailbox data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_thebat_msb_header_fields[]={
 SX_FIELD("header_value1","uint32",0,4,SX_NONE),
 SX_FIELD("header_value2","uint32",4,4,SX_NONE),
 SX_FIELD("sentinel","uint32",8,4,SX_SIGNATURE),
 SX_FIELD("metadata","bytes",12,68,SX_NONE),
};
const sx_layout sxdm_thebat_msb_header={UINT32_C(0x6023000A),"thebat_msb_header",sxdm_thebat_msb_header_fields,SX_COUNT(sxdm_thebat_msb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_thebat_msb_record_fields[]={
 SX_FIELD("record_body_size","uint32",0,4,SX_SIZE),
 SX_FIELD("metadata_size","uint32",4,4,SX_SIZE),
 SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
 SX_FIELD("flags","uint8",12,1,SX_FLAGS),
};
const sx_layout sxdm_thebat_msb_record={UINT32_C(0x6023000B),"thebat_msb_record",sxdm_thebat_msb_record_fields,SX_COUNT(sxdm_thebat_msb_record_fields),SX_LE};
static bool sxdm_msb(sx_context *c)
{
 uint8_t b[13];int64_t at=80;if(!sxdm_add(c,&sxdm_thebat_msb_header,0,80))return false;
 for(unsigned i=0;at<c->size;i++){if(i>=65536||!sx_read(c,at,b,13))return false;uint32_t n=sxdm_u32(b),meta=sxdm_u32(b+4);if(n<=meta||!sxdm_span(c,at+13,n)||!sxdm_add(c,&sxdm_thebat_msb_record,at,13))return false;at+=13+(int64_t)n;}return true;
}
bool sx_thebat_msb_build(sx_context*c)
{
 return sxdm_msb(c);
}
