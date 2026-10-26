/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QNAP_NAS_FIRMWARE data structures, moved out of the firmwaremeta schema family. */
#include "../../xx_format_schema_firmwaremeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fw_qnap_footer_fields[] = {
    SX_FIELD("magic","byte[6]",0,6,SX_SIGNATURE),
    SX_FIELD("encrypted_length","uint32",6,4,SX_SIZE),
    SX_FIELD("device_id","char[16]",10,16,SX_NONE),
    SX_FIELD("file_version","char[16]",26,16,SX_NONE),
    SX_FIELD("firmware_date","char[16]",42,16,SX_NONE),
    SX_FIELD("revision","char[16]",58,16,SX_NONE),
};
const sx_layout sx_fw_qnap_footer = {0x601e0013U,"qnap_footer",sx_fw_qnap_footer_fields,SX_COUNT(sx_fw_qnap_footer_fields),SX_LE};
bool sx_qnap_nas_firmware_build(sx_context*c)
{
    bool ok=false;
    ok=c->size>=78&&sx_add(c,&sx_fw_qnap_footer,c->size-74,74);
    return ok&&sx_fw_finish(c);
}
