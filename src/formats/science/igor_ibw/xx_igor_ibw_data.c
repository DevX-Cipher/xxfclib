/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Igor binary wave data structures, moved out of the sciencewire schema family. */
#include "../../xx_format_schema_sciencewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsw_igor_binary5_le_fields[] = {
    SX_FIELD("version","int16",0,2,SX_ID),
    SX_FIELD("checksum","int16",2,2,SX_CHECKSUM),
    SX_FIELD("wfmSize","int32",4,4,SX_SIZE),
    SX_FIELD("formulaSize","int32",8,4,SX_SIZE),
    SX_FIELD("noteSize","int32",12,4,SX_SIZE),
    SX_FIELD("dataEUnitsSize","int32",16,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize0","int32",20,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize1","int32",24,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize2","int32",28,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize3","int32",32,4,SX_SIZE),
    SX_FIELD("dimLabelsSize0","int32",36,4,SX_SIZE),
    SX_FIELD("dimLabelsSize1","int32",40,4,SX_SIZE),
    SX_FIELD("dimLabelsSize2","int32",44,4,SX_SIZE),
    SX_FIELD("dimLabelsSize3","int32",48,4,SX_SIZE),
    SX_FIELD("sIndicesSize","int32",52,4,SX_SIZE),
    SX_FIELD("optionsSize1","int32",56,4,SX_RESERVED),
    SX_FIELD("optionsSize2","int32",60,4,SX_RESERVED),
};
const sx_layout sxsw_igor_binary5_le = {UINT32_C(0x602d001f),"igor_binary5_le",sxsw_igor_binary5_le_fields,SX_COUNT(sxsw_igor_binary5_le_fields),SX_LE};
static const xx_data_struct_field_desc sxsw_igor_binary5_be_fields[] = {
    SX_FIELD("version","int16",0,2,SX_ID),
    SX_FIELD("checksum","int16",2,2,SX_CHECKSUM),
    SX_FIELD("wfmSize","int32",4,4,SX_SIZE),
    SX_FIELD("formulaSize","int32",8,4,SX_SIZE),
    SX_FIELD("noteSize","int32",12,4,SX_SIZE),
    SX_FIELD("dataEUnitsSize","int32",16,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize0","int32",20,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize1","int32",24,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize2","int32",28,4,SX_SIZE),
    SX_FIELD("dimEUnitsSize3","int32",32,4,SX_SIZE),
    SX_FIELD("dimLabelsSize0","int32",36,4,SX_SIZE),
    SX_FIELD("dimLabelsSize1","int32",40,4,SX_SIZE),
    SX_FIELD("dimLabelsSize2","int32",44,4,SX_SIZE),
    SX_FIELD("dimLabelsSize3","int32",48,4,SX_SIZE),
    SX_FIELD("sIndicesSize","int32",52,4,SX_SIZE),
    SX_FIELD("optionsSize1","int32",56,4,SX_RESERVED),
    SX_FIELD("optionsSize2","int32",60,4,SX_RESERVED),
};
const sx_layout sxsw_igor_binary5_be = {UINT32_C(0x602d0021),"igor_binary5_be",sxsw_igor_binary5_be_fields,SX_COUNT(sxsw_igor_binary5_be_fields),SX_BE};
static bool sxsw_igor(sx_context *c)
{
 uint16_t version;if(!sx_u16(c,0,false,&version))return false;bool be=version!=5;
 return sxsw_add(c,be?&sxsw_igor_binary5_be:&sxsw_igor_binary5_le,0,64)&&sxsw_add(c,be?&sxsw_igor_wave5_be:&sxsw_igor_wave5_le,64,320);
}
bool sx_igor_ibw_build(sx_context*c)
{
 return sxsw_igor(c);
}
