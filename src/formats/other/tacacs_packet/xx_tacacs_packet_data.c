/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TACACS PACKET data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_tacacs(sxnm_view *v){if(!SN_ROW(tacacs_header,0,v->n)||!SN_ROW(tacacs_authentication_start,12,v->n)||sxnm_u32(v->p+8)!=v->n-12)return false;return (size_t)v->p[16]+v->p[17]+v->p[18]+v->p[19]==v->n-20;}
bool sx_tacacs_packet_build(sxnm_view*v)
{
 return sxnm_tacacs(v);
}
#undef SN_ROW
