/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Acorn Uef data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_uef_header_fields[] = {
    SX_FIELD("signature","char[10]",0,10,SX_SIGNATURE),
    SX_FIELD("version_minor","uint8",10,1,SX_NONE),
    SX_FIELD("version_major","uint8",11,1,SX_NONE),
};
const sx_layout sxse_uef_header = {0x602f0039U,"uef_header",sxse_uef_header_fields,SX_COUNT(sxse_uef_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_uef_chunk_fields[] = {
    SX_FIELD("chunk_id","uint16",0,2,SX_ID),
    SX_FIELD("data_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxse_uef_chunk = {0x602f003aU,"uef_chunk",sxse_uef_chunk_fields,SX_COUNT(sxse_uef_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxse_uef_carrier_fields[] = {
    SX_FIELD("cycles","uint16",0,2,SX_NONE),
};
const sx_layout sxse_uef_carrier = {0x602f003bU,"uef_carrier",sxse_uef_carrier_fields,SX_COUNT(sxse_uef_carrier_fields),SX_LE};
static const xx_data_struct_field_desc sxse_uef_carrier_dummy_fields[] = {
    SX_FIELD("leading_cycles","uint16",0,2,SX_NONE),
    SX_FIELD("trailing_cycles","uint16",2,2,SX_NONE),
};
const sx_layout sxse_uef_carrier_dummy = {0x602f003cU,"uef_carrier_dummy",sxse_uef_carrier_dummy_fields,SX_COUNT(sxse_uef_carrier_dummy_fields),SX_LE};
static const xx_data_struct_field_desc sxse_uef_gap_fields[] = {
    SX_FIELD("duration_cycles","uint16",0,2,SX_NONE),
};
const sx_layout sxse_uef_gap = {0x602f003dU,"uef_gap",sxse_uef_gap_fields,SX_COUNT(sxse_uef_gap_fields),SX_LE};
static const xx_data_struct_field_desc sxse_uef_phase_fields[] = {
    SX_FIELD("degrees","uint16",0,2,SX_NONE),
};
const sx_layout sxse_uef_phase = {0x602f003eU,"uef_phase",sxse_uef_phase_fields,SX_COUNT(sxse_uef_phase_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
static bool sxse_uef(sx_context*c){uint8_t b[12];if(!sxse_read(c,0,b,12)||xx_rt_memcmp(b,"UEF File!\0",10)||!SXSE_ADD(c,uef_header,0,12))return false;uint64_t p=12;for(unsigned k=0;p<(uint64_t)c->size&&k<65536;k++){if(!sxse_read(c,p,b,6))return false;uint64_t z=sxse_u32(b,2,false);unsigned type=sxse_u16(b,0,false);if(!sxse_span(c,p+6,z)||!SXSE_ADD(c,uef_chunk,p,6))return false;const sx_layout*l=type==0x110?&sxse_uef_carrier:type==0x111?&sxse_uef_carrier_dummy:type==0x112?&sxse_uef_gap:type==0x115?&sxse_uef_phase:NULL;if(l&&(z!=(type==0x111?4U:2U)||!sxse_put(c,l,p+6,z,1)))return false;p+=6+z;}return p==(uint64_t)c->size;}
bool sx_acorn_uef_build(sx_context*c)
{
 return sxse_uef(c);
}
#undef SXSE_ADD
