/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HA data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_ha_header_fields[] = {
    SX_FIELD("signature", "char[2]", 0, 2, SX_SIGNATURE),
    SX_FIELD("member_count", "uint16", 2, 2, SX_COUNT_PROP),
};
const sx_layout sx_p_ha_header = { UINT32_C(0x60070015), "ha_header", sx_p_ha_header_fields, SX_COUNT(sx_p_ha_header_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_ha_machine_fields[] = {
    SX_FIELD("machine_data_size", "uint8", 0, 1, SX_SIZE),
};
const sx_layout sx_p_ha_machine = { UINT32_C(0x60070017), "ha_machine", sx_p_ha_machine_fields, SX_COUNT(sx_p_ha_machine_fields), SX_LE };
static bool sx_p_ha(sx_context *c)
{
    uint16_t count;if(!sx_p_sig(c,0,"HA",2)||!sx_u16(c,2,false,&count)||!sx_add(c,&sx_p_ha_header,0,4))return false;int64_t off=4;
    for(unsigned i=0;i<count;i++){uint32_t packed;uint8_t machine;if(!sx_u32(c,off+1,false,&packed)||!sx_add(c,&sx_p_ha_file,off,17))return false;off+=17;if(!sx_p_zstring(c,&off,c->size)||!sx_p_zstring(c,&off,c->size)||!sx_p_byte(c,off,&machine)||!sx_add(c,&sx_p_ha_machine,off,1))return false;off++;if(!sx_p_span(c,off,(uint64_t)machine+packed))return false;off+=(int64_t)machine+packed;}
    return off==c->size;
}
bool sx_ha_build(sx_context*c)
{
    return sx_p_ha(c);
}
