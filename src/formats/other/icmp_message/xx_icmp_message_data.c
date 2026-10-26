/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ICMP MESSAGE data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
bool sx_icmp_message_build(sxnm_view*v)
{
 return SN_ROW(icmp_echo_header,0,v->n);
}
#undef SN_ROW
