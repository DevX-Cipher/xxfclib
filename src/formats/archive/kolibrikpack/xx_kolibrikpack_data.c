/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * KolibriOS kpack ("KPCK") containers data structures, moved out of the archiveframes schema family. */
#include "../../xx_format_schema_archiveframes.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxafr_kpack_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint32",8,4,SX_FLAGS),
};
const sx_layout sxafr_kpack_header = {UINT32_C(0x60540019),"kpack_header",sxafr_kpack_header_fields,SX_COUNT(sxafr_kpack_header_fields),SX_LE};
static const xx_data_struct_field_desc sxafr_kpack_filter_fields[] = {
 SX_FIELD("conversion_count","uint32",0,4,SX_COUNT_PROP),
 SX_FIELD("marker","uint8",4,1,SX_NONE),
};
const sx_layout sxafr_kpack_filter = {UINT32_C(0x6054001a),"kpack_filter",sxafr_kpack_filter_fields,SX_COUNT(sxafr_kpack_filter_fields),SX_LE};
static bool sxafr_kpack(sx_context*c){uint64_t flags;if(!sxafr_word(c,8,4,false,&flags)||!sxafr_add(c,&sxafr_kpack_header,0))return false;return !(flags&0xc0)||(c->size>=17&&sxafr_add(c,&sxafr_kpack_filter,(uint64_t)c->size-5));}
bool sx_kolibrikpack_build(sx_context*c)
{
 return sxafr_kpack(c);
}
