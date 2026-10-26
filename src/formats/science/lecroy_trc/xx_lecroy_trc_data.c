/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LeCroy TRC data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_lecroy_trigger_time_le_fields[] = {
    SX_FIELD("trigger_time","float64",0,8,SX_NONE),
    SX_FIELD("time_offset","float64",8,8,SX_NONE),
};
const sx_layout sxsw_lecroy_trigger_time_le = {UINT32_C(0x602d0025),"lecroy_trigger_time_le",sxsw_lecroy_trigger_time_le_fields,SX_COUNT(sxsw_lecroy_trigger_time_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_lecroy_ris_time_le_fields[] = {
    SX_FIELD("ris_time","float64",0,8,SX_NONE),
};
const sx_layout sxsw_lecroy_ris_time_le = {UINT32_C(0x602d0026),"lecroy_ris_time_le",sxsw_lecroy_ris_time_le_fields,SX_COUNT(sxsw_lecroy_ris_time_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_lecroy_trigger_time_be_fields[] = {
    SX_FIELD("trigger_time","float64",0,8,SX_NONE),
    SX_FIELD("time_offset","float64",8,8,SX_NONE),
};
const sx_layout sxsw_lecroy_trigger_time_be = {UINT32_C(0x602d0029),"lecroy_trigger_time_be",sxsw_lecroy_trigger_time_be_fields,SX_COUNT(sxsw_lecroy_trigger_time_be_fields),SX_BE};
static const xx_data_struct_field_desc sxsw_lecroy_ris_time_be_fields[] = {
    SX_FIELD("ris_time","float64",0,8,SX_NONE),
};
const sx_layout sxsw_lecroy_ris_time_be = {UINT32_C(0x602d002a),"lecroy_ris_time_be",sxsw_lecroy_ris_time_be_fields,SX_COUNT(sxsw_lecroy_ris_time_be_fields),SX_BE};
static bool sxsw_lecroy(sx_context *c)
{
 uint8_t b[346];if(!sx_read(c,0,b,346))return false;bool be=sxsw16(b+34,false)==0;uint32_t desc=sxsw32(b+36,be),user=sxsw32(b+40,be),trigger=sxsw32(b+48,be),ris=sxsw32(b+52,be);int64_t at=(int64_t)desc+user;
 return sxsw_add(c,be?&sxsw_lecroy_descriptor_be:&sxsw_lecroy_descriptor_le,0,346)&&sxsw_table(c,be?&sxsw_lecroy_trigger_time_be:&sxsw_lecroy_trigger_time_le,at,16,trigger/16)&&sxsw_table(c,be?&sxsw_lecroy_ris_time_be:&sxsw_lecroy_ris_time_le,at+trigger,8,ris/8);
}
bool sx_lecroy_trc_build(sx_context*c)
{
 return sxsw_lecroy(c);
}
