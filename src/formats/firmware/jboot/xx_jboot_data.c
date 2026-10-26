/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * JBOOT data structures, moved out of the firmwaremeta schema family. */
#include "../../xx_format_schema_firmwaremeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fw_jboot_stag_header_fields[] = {
    SX_FIELD("cmark","uint8",0,1,SX_ID),
    SX_FIELD("id","uint8",1,1,SX_ID),
    SX_FIELD("magic","uint16",2,2,SX_SIGNATURE),
    SX_FIELD("timestamp_ticks","uint32",4,4,SX_NONE),
    SX_FIELD("image_size","uint32",8,4,SX_SIZE),
    SX_FIELD("image_checksum","uint16",12,2,SX_CHECKSUM),
    SX_FIELD("header_checksum","uint16",14,2,SX_CHECKSUM),
};
const sx_layout sx_fw_jboot_stag_header = {0x601e0011U,"jboot_stag_header",sx_fw_jboot_stag_header_fields,SX_COUNT(sx_fw_jboot_stag_header_fields),SX_LE};
bool sx_jboot_build(sx_context*c)
{
    bool ok=false;
    int64_t n=sx_fw_native_header_size(c);const sx_layout *l=n==40?&sx_fw_jboot_sch2_header:n==80?&sx_fw_jboot_arm_header:n==16?&sx_fw_jboot_stag_header:NULL;ok=l&&sx_add(c,l,0,n);
    return ok&&sx_fw_finish(c);
}
