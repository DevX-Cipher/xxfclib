/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IRIXSA data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_irixsa_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("reserved","byte[24]",8,24,SX_RESERVED),
};
const sx_layout sxst_irixsa_header = {0x60370001U,"irixsa_header",sxst_irixsa_header_fields,SX_COUNT(sxst_irixsa_header_fields),SX_BE};
static const xx_data_struct_field_desc sxst_irixsa_directory_entry_fields[] = {
    SX_FIELD("name","char[16]",0,16,SX_NONE),
    SX_FIELD("first_block","uint32",16,4,SX_NONE),
    SX_FIELD("byte_size","uint32",20,4,SX_SIZE),
};
const sx_layout sxst_irixsa_directory_entry = {0x60370002U,"irixsa_directory_entry",sxst_irixsa_directory_entry_fields,SX_COUNT(sxst_irixsa_directory_entry_fields),SX_BE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
bool sx_irixsa_build(sx_context*c)
{
 return SXST_ADD(c,irixsa_header,0)&&SXST_TABLE(c,irixsa_directory_entry,32,20);
}
#undef SXST_ADD
#undef SXST_TABLE
