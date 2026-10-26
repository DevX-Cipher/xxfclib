/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * InstallShield Developer 7 data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_installshield_developer_header_fields[] = {
    SX_FIELD("signature","char[14]",0,14,SX_SIGNATURE),
    SX_FIELD("file_count","uint32",14,4,SX_COUNT_PROP),
    SX_FIELD("reserved","byte[28]",18,28,SX_RESERVED),
};
const sx_layout sxil_installshield_developer_header = {0x60850029U,"installshield_developer_header",sxil_installshield_developer_header_fields,SX_COUNT(sxil_installshield_developer_header_fields),SX_LE};
static const xx_data_struct_field_desc sxil_installshield_developer_record_fields[] = {
    SX_FIELD("name_storage","char[268]",0,268,SX_NONE),
    SX_FIELD("file_size","uint32",268,4,SX_SIZE),
    SX_FIELD("reserved","byte[40]",272,40,SX_RESERVED),
};
const sx_layout sxil_installshield_developer_record = {0x6085002aU,"installshield_developer_record",sxil_installshield_developer_record_fields,SX_COUNT(sxil_installshield_developer_record_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static bool sxil_isd(sx_context*c){uint64_t p;uint32_t n;if(!sxil_pe(c,&p)||!sxil_eq(c,p,"InstallShield\0",14)||!sxil_u32(c,p+14,&n)||!n||n>65535)return true;if(!SXIL_ADD(c,installshield_developer_header,p))return false;p+=46;for(uint32_t i=0;i<n;i++){uint32_t z;if(!sxil_u32(c,p+268,&z)||!sxil_span(c,p,312)||!sxil_span(c,p+312,z))return true;if(!SXIL_ADD(c,installshield_developer_record,p))return false;p+=312+(uint64_t)z;}return true;}
bool sx_installshield_developer_build(sx_context*c)
{
 return sxil_isd(c);
}
#undef SXIL_ADD
