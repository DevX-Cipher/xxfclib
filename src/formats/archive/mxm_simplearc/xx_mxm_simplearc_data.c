/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MXM_SIMPLEARC data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_mxm_simplearc_member_fields[] = {
 SX_FIELD("next_record_delta","uint32",0,4,SX_OFFSET),
 SX_FIELD("stored_size","uint32",4,4,SX_SIZE),
 SX_FIELD("name","char[16]",8,16,SX_NONE),
};
const sx_layout sxaf_mxm_simplearc_member = {UINT32_C(0x603c0028),"mxm_simplearc_member",sxaf_mxm_simplearc_member_fields,SX_COUNT(sxaf_mxm_simplearc_member_fields),SX_BE};
static bool sxaf_mxm(sx_context*c){uint64_t p=0x264;while(sxaf_span(c,p,24)){uint8_t b[24];if(!sxaf_read(c,p,b,24)||!sxaf_add(c,&sxaf_mxm_simplearc_member,p))return false;uint64_t next=sxaf_uint(b,4,true),n=sxaf_uint(b+4,4,true);if(!b[8]||!next)return true;if(next<24||n>next-24||!sxaf_span(c,p,next))return false;p+=next;}return false;}
bool sx_mxm_simplearc_build(sx_context*c)
{
 return sxaf_mxm(c);
}
