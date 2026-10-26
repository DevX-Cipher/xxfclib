/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DISKDUPE data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_diskdupe_header_fields[] = {
    SX_FIELD("signature","char[21]",0,21,SX_SIGNATURE),
    SX_FIELD("unknown_15","byte[46]",21,46,SX_NONE),
    SX_FIELD("track_count","uint8",67,1,SX_COUNT_PROP),
    SX_FIELD("block_size","uint16",68,2,SX_SIZE),
    SX_FIELD("unknown_46","byte[2]",70,2,SX_NONE),
};
const sx_layout sxsl_diskdupe_header = {0x60330006U,"diskdupe_header",sxsl_diskdupe_header_fields,SX_COUNT(sxsl_diskdupe_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_diskdupe_track_fields[] = {
    SX_FIELD("block_offset","uint24",0,3,SX_NONE),
    SX_FIELD("status","uint8",3,1,SX_ID),
    SX_FIELD("unknown","uint8",4,1,SX_NONE),
};
const sx_layout sxsl_diskdupe_track = {0x60330007U,"diskdupe_track",sxsl_diskdupe_track_fields,SX_COUNT(sxsl_diskdupe_track_fields),SX_LE};
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
#define SXSL_TABLE(c,l,p,n) sxsl_put(c,&sxsl_##l,p,n)
static bool sxsl_diskdupe(sx_context*c){uint8_t b[72];return sxsl_read(c,0,b,72)&&SXSL_ADD(c,diskdupe_header,0)&&SXSL_TABLE(c,diskdupe_track,72,b[67]);}
bool sx_diskdupe_build(sx_context*c)
{
bool ok=false;
ok=sxsl_diskdupe(c);
return ok&&sxsl_finish(c);
}
