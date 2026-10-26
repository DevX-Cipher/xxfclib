/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ESPRESSIF_IMAGE data structures, moved out of the firmwaremeta schema family. */
#include "../../xx_format_schema_firmwaremeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fw_esp32_segment_header_fields[] = {
    SX_FIELD("load_addr","uint32",0,4,SX_ADDRESS),
    SX_FIELD("data_length","uint32",4,4,SX_SIZE),
};
const sx_layout sx_fw_esp32_segment_header = {0x601e000bU,"esp32_segment_header",sx_fw_esp32_segment_header_fields,SX_COUNT(sx_fw_esp32_segment_header_fields),SX_LE};
static bool sx_fw_esp(sx_context *c)
{
    uint8_t h[24];if(!sx_read(c,0,h,24)||h[0]!=0xe9||!h[1]||h[1]>16||!sx_add(c,&sx_fw_esp32_image_header,0,24))return false;
    uint64_t at=24;
    for(unsigned i=0;i<h[1];i++){uint32_t n;if(!sx_u32(c,(int64_t)at+4,false,&n)||!sx_add(c,&sx_fw_esp32_segment_header,(int64_t)at,8)||!sx_range(c,(int64_t)at+8,n))return false;at+=8+(uint64_t)n;}
    uint64_t checksum=((at+16)&~UINT64_C(15))-1;
    return checksum<=(uint64_t)INT64_MAX&&sx_add(c,&sx_fw_esp32_checksum,(int64_t)checksum,1);
}
bool sx_espressif_image_build(sx_context*c)
{
    bool ok=false;
    ok=sx_fw_esp(c);
    return ok&&sx_fw_finish(c);
}
