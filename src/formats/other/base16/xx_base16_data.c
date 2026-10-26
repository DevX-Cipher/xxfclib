/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * base16 data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_base16(sxtw_cursor*q)
{
 while(q->p<q->n){if(q->c->count>=32000)return true;while(q->p<q->n&&sxtw_space(q->b[q->p]))q->p++;uint64_t value;if(q->n-q->p<2||!sxtw_number(q,q->p,2,16,&value))break;TW_EMIT(hex_byte,q->p,2);q->p+=2;}return true;
}
bool sx_base16_build(sxtw_cursor*q)
{
 return sxtw_base16(q);
}
#undef TW_EMIT
