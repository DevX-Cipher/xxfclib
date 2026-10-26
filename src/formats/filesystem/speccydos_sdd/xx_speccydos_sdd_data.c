/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * speccydos sdd data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_speccydos_boot_header_fields[] = {
    SX_FIELD("magic","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("unknown_05","byte[8]",5,8,SX_NONE),
    SX_FIELD("density","uint8",13,1,SX_ID),
    SX_FIELD("cylinders_and_sides","uint8",14,1,SX_FLAGS),
    SX_FIELD("sectors_per_track","uint8",15,1,SX_COUNT_PROP),
};
const sx_layout sxdr_speccydos_boot_header = {0x607f0032U,"speccydos_boot_header",sxdr_speccydos_boot_header_fields,SX_COUNT(sxdr_speccydos_boot_header_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static bool sxdr_sdd(sx_context*c){uint8_t h[16];if(!sxdr_read(c,0,h,16)||xx_rt_memcmp(h,"TRKY2",5)||h[13]>1||!(h[14]&127)||!h[15])return false;uint64_t bytes=(uint64_t)(h[14]&127)*((h[14]&128)?2:1)*h[15]*256;if(bytes!=(uint64_t)c->size)return false;return SXDR_ADD(c,speccydos_boot_header,0);}
#undef SXDR_ADD
bool sx_speccydos_sdd_build(sx_context*c)
{
 return sxdr_sdd(c);
}
