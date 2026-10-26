/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ASCENDBACKUP data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_ascendbackup_name_size_fields[] = {
 SX_FIELD("name_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxacl_ascendbackup_name_size = {UINT32_C(0x6050001b),"ascendbackup_name_size",sxacl_ascendbackup_name_size_fields,SX_COUNT(sxacl_ascendbackup_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_ascendbackup_size_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxacl_ascendbackup_size = {UINT32_C(0x6050001c),"ascendbackup_size",sxacl_ascendbackup_size_fields,SX_COUNT(sxacl_ascendbackup_size_fields),SX_LE};
#define SXACL_LIMIT 20000U
static bool sxacl_ascend(sx_context*c){uint64_t p=0;for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint64_t n,z;if(!sxacl_word(c,p,2,false,&n)||!n||n>12||!sxacl_word(c,p+2+n,4,false,&z)||!sxacl_span(c,p+6+n,z)||!sxacl_add(c,&sxacl_ascendbackup_name_size,p)||!sxacl_add(c,&sxacl_ascendbackup_size,p+2+n)||!sxacl_dcl(c,p+6+n,z))return false;p+=6+n+z;}return true;}
bool sx_ascendbackup_build(sx_context*c)
{
 return sxacl_ascend(c);
}
