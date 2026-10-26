/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ESP archive data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_esp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint8",4,1,SX_ID),
 SX_FIELD("flags","uint8",5,1,SX_FLAGS),
 SX_FIELD("directory_offset","uint32",6,4,SX_OFFSET),
};
const sx_layout sxal_esp_header = {UINT32_C(0x6020004c),"esp_header",sxal_esp_header_fields,SX_COUNT(sxal_esp_header_fields),SX_LE};
bool sx_esp_archive_build(sx_context*c)
{
 uint8_t b[4];return sxal_read(c,0,b,4)&&!xx_rt_memcmp(b,"ESP>",4)&&sxal_add(c,&sxal_esp_header,0);
}
