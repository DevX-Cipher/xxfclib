/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PFPK archive data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_pfpk_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxbx_pfpk_header = {UINT32_C(0x603000f1),"pfpk_header",sxbx_pfpk_header_fields,SX_COUNT(sxbx_pfpk_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pfpk_name_size_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxbx_pfpk_name_size = {UINT32_C(0x603000f2),"pfpk_name_size",sxbx_pfpk_name_size_fields,SX_COUNT(sxbx_pfpk_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pfpk_member_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxbx_pfpk_member = {UINT32_C(0x603000f3),"pfpk_member",sxbx_pfpk_member_fields,SX_COUNT(sxbx_pfpk_member_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_pfpk(sx_context*c){uint64_t n,p=8,end=(uint64_t)c->size;if(!sxbx_add(c,&sxbx_pfpk_header,0)||!sxbx_word(c,4,4,false,&n)||n>SXBX_LIMIT)return false;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++){if(!sxbx_counted(c,&p,end,&sxbx_pfpk_name_size,1,false,1)||end-p<8||!sxbx_add(c,&sxbx_pfpk_member,p))break;p+=8;}return true;}
bool sx_pfpk_build(sx_context*c)
{
 return sxbx_pfpk(c);
}
