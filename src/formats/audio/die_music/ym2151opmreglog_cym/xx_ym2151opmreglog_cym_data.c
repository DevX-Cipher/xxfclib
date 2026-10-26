/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * YM2151 register log (CYM) data structures, moved out of the musiclogs schema family. */
#include "../../../xx_format_schema_musiclogs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxlog_cym_register_write_fields[]={
 SX_FIELD("register","uint8",0,1,SX_FLAGS),
 SX_FIELD("value","uint8",1,1,SX_NONE),
};
const sx_layout sxlog_cym_register_write={0x608c0018U,"cym_register_write",sxlog_cym_register_write_fields,SX_COUNT(sxlog_cym_register_write_fields),SX_LE};
static const xx_data_struct_field_desc sxlog_cym_frame_wait_fields[]={
 SX_FIELD("wait_marker","uint8",0,1,SX_FLAGS),
};
const sx_layout sxlog_cym_frame_wait={0x608c0019U,"cym_frame_wait",sxlog_cym_frame_wait_fields,SX_COUNT(sxlog_cym_frame_wait_fields),SX_LE};
static bool sxlog_cym(sx_context*c)
{int64_t at=0;unsigned work=0;uint8_t r;while(at<c->size&&work++<16000){if(!sx_read(c,at,&r,1))return false;unsigned size=r?2:1;if(size>(uint64_t)(c->size-at))break;if(!sx_add(c,r?&sxlog_cym_register_write:&sxlog_cym_frame_wait,at,size))return false;at+=size;}return sx_raw(c,at,c->size-at);}
bool sx_ym2151opmreglog_cym_build(sx_context*c)
{
 return sxlog_cym(c);
}
