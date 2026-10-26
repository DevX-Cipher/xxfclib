/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SCF data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_scf_header_fields[] = {
 SX_FIELD("constant","uint32",0,4,SX_NONE),
};
const sx_layout sxao_scf_header = {UINT32_C(0x60700024),"scf_header",sxao_scf_header_fields,SX_COUNT(sxao_scf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_scf_member_fields[] = {
 SX_FIELD("name","char[14]",0,14,SX_NONE),
 SX_FIELD("compressed_size","uint32",14,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",18,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",22,2,SX_NONE),
 SX_FIELD("dos_time","uint16",24,2,SX_NONE),
};
const sx_layout sxao_scf_member = {UINT32_C(0x60700025),"scf_member",sxao_scf_member_fields,SX_COUNT(sxao_scf_member_fields),SX_LE};
static bool sxao_scf(sx_context*c){uint64_t p=4;if(!sxao_add(c,&sxao_scf_header,0))return false;while(sxao_span(c,p,26)){uint64_t z;if(!sxao_word(c,p+14,4,false,&z)||!sxao_add(c,&sxao_scf_member,p))return false;p+=26;if(!sxao_span(c,p,z)||!sxao_dcl(c,p,z))return true;p+=z;}return true;}
bool sx_scf_build(sx_context*c)
{
 return sxao_scf(c);
}
