/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MountainSort MDA arrays data structures, moved out of the sciencemeta schema family. */
#include "../../xx_format_schema_sciencemeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsc_mda_dimension32_fields[] = {
    SX_FIELD("dimension","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsc_mda_dimension32 = {UINT32_C(0x60280023),"mda_dimension32",sxsc_mda_dimension32_fields,SX_COUNT(sxsc_mda_dimension32_fields),SX_LE};
static const xx_data_struct_field_desc sxsc_mda_dimension64_fields[] = {
    SX_FIELD("dimension","int64",0,8,SX_COUNT_PROP),
};
const sx_layout sxsc_mda_dimension64 = {UINT32_C(0x60280024),"mda_dimension64",sxsc_mda_dimension64_fields,SX_COUNT(sxsc_mda_dimension64_fields),SX_LE};
static bool sxsc_mda(sx_context *c)
{
 uint32_t raw;if(!sx_u32(c,8,false,&raw)||!sxsc_add(c,&sxsc_mda_header,0,12))return false;bool wide=(raw&0x80000000U)!=0;uint32_t count=wide?0U-raw:raw;
 return count>=2&&count<=6&&sxsc_table(c,wide?&sxsc_mda_dimension64:&sxsc_mda_dimension32,12,wide?8:4,count);
}
bool sx_mountainsort_mda_build(sx_context*c)
{
 return sxsc_mda(c);
}
