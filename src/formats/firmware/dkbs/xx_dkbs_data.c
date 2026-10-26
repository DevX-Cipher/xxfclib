/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DKBS data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_fm_dkbs_header_fields[] = {
    SX_FIELD("board_id","char[32]",0,32,SX_NONE),
    SX_FIELD("unknown1","byte[8]",32,8,SX_NONE),
    SX_FIELD("firmware_version","char[32]",40,32,SX_NONE),
    SX_FIELD("unknown2","byte[32]",72,32,SX_NONE),
    SX_FIELD("payload_size","uint32",104,4,SX_SIZE),
    SX_FIELD("unknown3","byte[4]",108,4,SX_NONE),
    SX_FIELD("boot_device","char[32]",112,32,SX_NONE),
    SX_FIELD("unknown4","byte[16]",144,16,SX_NONE),
};
const sx_layout sx_fm_dkbs_header = {0x60220003U,"dkbs_header",sx_fm_dkbs_header_fields,SX_COUNT(sx_fm_dkbs_header_fields),SX_FILE};
bool sx_dkbs_build(sx_context*c)
{
    return sx_fm_add(c,&sx_fm_dkbs_header,0,160);
}
