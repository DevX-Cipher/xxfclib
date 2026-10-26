/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SQ data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_sq_magic_fields[] = {
 SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxaf_sq_magic = {UINT32_C(0x603c000f),"sq_magic",sxaf_sq_magic_fields,SX_COUNT(sxaf_sq_magic_fields),SX_LE};
static const xx_data_struct_field_desc sxaf_sq_calendar_fields[] = {
 SX_FIELD("month","uint8",0,1,SX_NONE),
 SX_FIELD("day","uint8",1,1,SX_NONE),
 SX_FIELD("year_since_1980","uint8",2,1,SX_NONE),
 SX_FIELD("hour","uint8",3,1,SX_NONE),
 SX_FIELD("minute","uint8",4,1,SX_NONE),
 SX_FIELD("two_second_count","uint8",5,1,SX_NONE),
};
const sx_layout sxaf_sq_calendar = {UINT32_C(0x603c0010),"sq_calendar",sxaf_sq_calendar_fields,SX_COUNT(sxaf_sq_calendar_fields),SX_LE};
static bool sxaf_sq(sx_context*c){uint64_t p=4;return sxaf_add(c,&sxaf_sq_magic,0)&&sxaf_zstr(c,&p,(uint64_t)c->size,256,0)&&sxaf_add(c,&sxaf_sq_calendar,p);}
bool sx_sq_build(sx_context*c)
{
 return sxaf_sq(c);
}
