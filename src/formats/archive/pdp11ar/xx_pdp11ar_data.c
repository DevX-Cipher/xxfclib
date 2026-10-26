/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PDP-11 ar archives data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_pdp11ar_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxar_pdp11ar_header = {UINT32_C(0x601c0032),"pdp11ar_header",sxar_pdp11ar_header_fields,SX_COUNT(sxar_pdp11ar_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_pdp11ar_member_fields[] = {
    SX_FIELD("name","char[14]",0,14,SX_STRING),
    SX_FIELD("modified","uint32_pdp",14,4,SX_TIME),
    SX_FIELD("uid","uint8",18,1,SX_ID),
    SX_FIELD("gid","uint8",19,1,SX_ID),
    SX_FIELD("mode","uint16",20,2,SX_FLAGS),
    SX_FIELD("data_size","uint32_pdp",22,4,SX_SIZE),
};
const sx_layout sxar_pdp11ar_member = {UINT32_C(0x601c0033),"pdp11ar_member",sxar_pdp11ar_member_fields,SX_COUNT(sxar_pdp11ar_member_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_pdp11ar(sx_context *c){if(!sxar_span(c,0,2)||!sxar_add(c,&sxar_pdp11ar_header,0))return false;uint64_t p=2;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){uint8_t b[26];if(!sxar_read(c,p,b,26)||!b[0])break;uint64_t n=((uint32_t)sxar16(b+22,false)<<16)|sxar16(b+24,false);if(!sxar_span(c,p+26,n))break;if(!sxar_add(c,&sxar_pdp11ar_member,p))return false;p=(p+26+n+1)&~UINT64_C(1);}return true;}
bool sx_pdp11ar_build(sx_context*c)
{
 return sxar_pdp11ar(c);
}
