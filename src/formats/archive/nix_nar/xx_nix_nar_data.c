/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nix nar data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_nar_string_length_fields[] = {
 SX_FIELD("byte_length","uint64",0,8,SX_SIZE),
};
const sx_layout sxaf_nar_string_length = {UINT32_C(0x603c0001),"nar_string_length",sxaf_nar_string_length_fields,SX_COUNT(sxaf_nar_string_length_fields),SX_LE};
static bool sxaf_nar(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint64_t n;if(!sxaf_word(c,p,8,false,&n)||!sxaf_span(c,p+8,n)||!sxaf_add(c,&sxaf_nar_string_length,p))return false;p+=8+n;uint64_t pad=(8-(n&7))&7;if(!sxaf_span(c,p,pad))return false;p+=pad;}return true;}
bool sx_nix_nar_build(sx_context*c)
{
 return sxaf_nar(c);
}
