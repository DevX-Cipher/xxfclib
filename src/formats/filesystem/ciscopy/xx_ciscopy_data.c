/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CISCOPY data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_ciscopy_header_fields[] = {
    SX_FIELD("disk_type","uint8",0,1,SX_ID),
};
const sx_layout sxst_ciscopy_header = {0x60370021U,"ciscopy_header",sxst_ciscopy_header_fields,SX_COUNT(sxst_ciscopy_header_fields),SX_LE};
static const xx_data_struct_field_desc sxst_ciscopy_track_state_fields[] = {
    SX_FIELD("state","uint8",0,1,SX_ID),
};
const sx_layout sxst_ciscopy_track_state = {0x60370022U,"ciscopy_track_state",sxst_ciscopy_track_state_fields,SX_COUNT(sxst_ciscopy_track_state_fields),SX_LE};
static const xx_data_struct_field_desc sxst_ciscopy_compression_fields[] = {
    SX_FIELD("compression","uint8",0,1,SX_ID),
};
const sx_layout sxst_ciscopy_compression = {0x60370023U,"ciscopy_compression",sxst_ciscopy_compression_fields,SX_COUNT(sxst_ciscopy_compression_fields),SX_LE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
#define SXST_TABLE(c,l,p,n) sxst_put(c,&sxst_##l,p,n)
static bool sxst_ciscopy(sx_context*c){uint8_t type;if(!sxst_read(c,0,&type,1)||!SXST_ADD(c,ciscopy_header,0))return false;uint64_t n=type<=4?80:160;if(type<1||type>7||!sxst_span(c,1,n+1))return true;return SXST_TABLE(c,ciscopy_track_state,1,n)&&SXST_ADD(c,ciscopy_compression,n+1);}
bool sx_ciscopy_build(sx_context*c)
{
 return sxst_ciscopy(c);
}
#undef SXST_ADD
#undef SXST_TABLE
