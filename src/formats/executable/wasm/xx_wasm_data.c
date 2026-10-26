/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * wasm data structures, moved out of the executable schema family. */
#include "../../xx_format_schema_executable.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_wasm_header_fields[] = {
    SX_FIELD("magic","uint8[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
};
const sx_layout sx_wasm_header = {0x60030028U,"wasm_header",sx_wasm_header_fields,SX_COUNT(sx_wasm_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_2_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,2,SX_SIZE),
};
const sx_layout sx_wasm_section_header_2 = {0x6003002AU,"wasm_section_header_2",sx_wasm_section_header_2_fields,SX_COUNT(sx_wasm_section_header_2_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_3_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,3,SX_SIZE),
};
const sx_layout sx_wasm_section_header_3 = {0x6003002BU,"wasm_section_header_3",sx_wasm_section_header_3_fields,SX_COUNT(sx_wasm_section_header_3_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_4_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,4,SX_SIZE),
};
const sx_layout sx_wasm_section_header_4 = {0x6003002CU,"wasm_section_header_4",sx_wasm_section_header_4_fields,SX_COUNT(sx_wasm_section_header_4_fields),SX_LE};
static bool sx_wasm_build(sx_context *c)
{
    static const sx_layout *const layouts[]={&sx_wasm_section_header_1,&sx_wasm_section_header_2,&sx_wasm_section_header_3,&sx_wasm_section_header_4,&sx_wasm_section_header_5};
    uint8_t h[8];int64_t at=8;
    if(!sx_read(c,0,h,8)||xx_rt_memcmp(h,"\0asm\1\0\0\0",8)||!sx_add(c,&sx_wasm_header,0,8))return false;
    while(at<c->size) {
        uint8_t id,b=0;uint32_t value=0;unsigned w;
        if(!sx_read(c,at,&id,1)||id>12)return false;
        for(w=0;w<5;w++) {
            if(!sx_read(c,at+1+w,&b,1)||(w==4&&(b&0xf0)))return false;
            value|=(uint32_t)(b&127)<<(7*w);if(!(b&128))break;
        }
        if(w==5||!sx_add(c,layouts[w],at,2+w))return false;
        at+=2+w;if(!sx_raw(c,at,value))return false;at+=value;
    }return true;
}
bool sx_wasm_schema_build(sx_context*c)
{
    return sx_wasm_build(c);
}
