/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BIOS firmware data structures, moved out of the firmwaremore schema family. */
#include "../../xx_format_schema_firmwaremore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_bios_firmware_build(sx_context*c)
{
    uint8_t op;if(c->size<16||!sx_fm_read(c,c->size-16,&op,1))return false;return op==0xea?sx_fm_add(c,&sx_fm_bios_far_reset_jump,c->size-16,5):op==0xe9?sx_fm_add(c,&sx_fm_bios_near_reset_jump,c->size-16,3):false;
}
