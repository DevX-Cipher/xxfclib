/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NETFLOW DATAGRAM data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_netflow(sxnm_view *v){if(!SN_ROW(netflow_v5_header,0,v->n))return false;unsigned count=sxnm_u16(v->p+2);if((uint64_t)count*48!=v->n-24)return false;for(unsigned i=0;i<count;i++)if(!SN_ROW(netflow_v5_record,24+(size_t)i*48,v->n))return false;return true;}
bool sx_netflow_datagram_build(sxnm_view*v)
{
 return sxnm_netflow(v);
}
#undef SN_ROW
