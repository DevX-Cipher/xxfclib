/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TPLINK data structures, moved out of the firmwaremeta schema family. */
#include "../../xx_format_schema_firmwaremeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_tplink_build(sx_context*c)
{
    bool ok=false;
    int64_t n=sx_fw_native_header_size(c);ok=n==512?sx_add(c,&sx_fw_tplink_linux_header,0,512):n==148?sx_add(c,&sx_fw_tplink_rtos_header_prefix,0,32):false;
    return ok&&sx_fw_finish(c);
}
