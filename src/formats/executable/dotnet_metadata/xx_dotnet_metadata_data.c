/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * .NET metadata data structures, moved out of the vmmeta schema family. */
#include "../../xx_format_schema_vmmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_vm_cli_metadata_root_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("major_version","uint16",4,2,SX_ID),
    SX_FIELD("minor_version","uint16",6,2,SX_ID),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
    SX_FIELD("version_length","uint32",12,4,SX_SIZE),
};
const sx_layout sx_vm_cli_metadata_root = {0x60160034U,"cli_metadata_root",sx_vm_cli_metadata_root_fields,SX_COUNT(sx_vm_cli_metadata_root_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_cli_stream_header_fields[] = {
    SX_FIELD("stream_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("stream_size","uint32",4,4,SX_SIZE),
};
const sx_layout sx_vm_cli_stream_header = {0x60160036U,"cli_stream_header",sx_vm_cli_stream_header_fields,SX_COUNT(sx_vm_cli_stream_header_fields),SX_LE};
static bool sx_vm_dotnet(sx_context *c)
{
    uint32_t len;uint16_t count;uint64_t at;
    if(!sx_u32(c,12,false,&len)||!len||len>256||len%4||!sx_vm_span(c,16,len)||!sx_add(c,&sx_vm_cli_metadata_root,0,16))return false;at=16+len;
    if(!sx_vm_span(c,at,4)||!sx_u16(c,(int64_t)at+2,false,&count)||!count||count>64||!sx_add(c,&sx_vm_cli_storage_header,(int64_t)at,4))return false;at+=4;
    for(uint16_t i=0;i<count;i++){
        if(!sx_add(c,&sx_vm_cli_stream_header,(int64_t)at,8))return false;at+=8;bool ended=false;
        for(unsigned j=0;j<32;j++){uint8_t b;if(!sx_read(c,(int64_t)at++,&b,1))return false;if(!b){ended=true;break;}}
        if(!ended)return false;at=(at+3)&~UINT64_C(3);if(!sx_vm_span(c,at,0))return false;
    }return true;
}
bool sx_dotnet_metadata_build(sx_context*c)
{
    return sx_vm_dotnet(c);
}
