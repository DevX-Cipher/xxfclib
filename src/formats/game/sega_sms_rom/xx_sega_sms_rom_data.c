/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sega_sms_rom data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_sms_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("reserved","bytes",8,2,SX_RESERVED),
 SX_FIELD("checksum","uint16",10,2,SX_CHECKSUM),
 SX_FIELD("product_code_low","uint16",12,2,SX_ID),
 SX_FIELD("product_high_version","uint8",14,1,SX_FLAGS),
 SX_FIELD("region_size","uint8",15,1,SX_FLAGS),
};
const sx_layout sxgp_sms_header={UINT32_C(0x60360003),"sms_header",sxgp_sms_header_fields,SX_COUNT(sxgp_sms_header_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_sms(sxgp_view*v){const uint64_t offsets[]={0x1ff0,0x3ff0,0x7ff0,0x8ff0};uint64_t end=(uint64_t)v->c->size;uint8_t tag[8];for(unsigned i=0;i<4;i++)if(sxgp_span(v,offsets[i],16,end)&&sxgp_read(v,offsets[i],tag,8,end)&&!xx_rt_memcmp(tag,"TMR SEGA",8))return SG_ROW(sms_header,offsets[i],end);return false;}
bool sx_sega_sms_rom_build(sxgp_view*v)
{
 return sxgp_sms(v);
}
#undef SG_ROW
