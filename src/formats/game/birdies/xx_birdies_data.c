/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BIRDIES data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_birdies_header_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("member_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxan_birdies_header = {UINT32_C(0x60770039),"birdies_header",sxan_birdies_header_fields,SX_COUNT(sxan_birdies_header_fields),SX_LE};
static const xx_data_struct_field_desc sxan_birdies_member_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxan_birdies_member = {UINT32_C(0x6077003a),"birdies_member",sxan_birdies_member_fields,SX_COUNT(sxan_birdies_member_fields),SX_LE};
static bool sxan_birdies(sx_context*c){uint64_t n,p=8,len;if(!sxan_add(c,&sxan_birdies_header,0)||!sxan_word(c,4,4,false,&n))return false;for(uint64_t i=0;i<n;i++){if(!sxan_zlen(c,p,(uint64_t)c->size,&len)||!sxan_named(c,p,len)||!sxan_add(c,&sxan_birdies_member,p+len))return false;p+=len+8;}return true;}
bool sx_birdies_build(sx_context*c)
{
bool ok=false;
ok=sxan_birdies(c);
(void)ok;return c->count&&sxan_finish(c);
}
