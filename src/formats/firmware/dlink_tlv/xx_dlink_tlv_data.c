/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DLINK_TLV data structures, moved out of the firmwaremeta schema family. */
#include "../../xx_format_schema_firmwaremeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_dlink_tlv_build(sx_context*c)
{
    bool ok=false;
    ok=sx_add(c,&sx_fw_dlink_tlv_header,0,116);
    return ok&&sx_fw_finish(c);
}
