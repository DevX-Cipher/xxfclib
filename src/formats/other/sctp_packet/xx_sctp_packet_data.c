/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SCTP PACKET data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_sctp(sxnm_view *v)
{
 if(!SN_ROW(sctp_common_header,0,v->n))return false;size_t at=12;
 while(at<v->n){if(!SN_ROW(sctp_data_chunk,at,v->n)||v->p[at])return false;size_t n=sxnm_u16(v->p+at+2);if(n<16||!sxnm_need(v,at,n+(4-n%4)%4,v->n))return false;at+=n+(4-n%4)%4;}return true;
}
bool sx_sctp_packet_build(sxnm_view*v)
{
 return sxnm_sctp(v);
}
#undef SN_ROW
