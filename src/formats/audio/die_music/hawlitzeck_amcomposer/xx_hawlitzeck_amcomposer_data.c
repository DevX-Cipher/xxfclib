/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Marc Hawlitzeck's A.M. Composer module (.AMC) data structures, moved out of the amigaplayers schema family. */
#include "../../../xx_format_schema_amigaplayers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define AP_ROW(l,at,end) sxamip_row(v,&sxamip_##l,(at),(end))
static bool sxamip_amc(sxamip_view*v)
{
 uint64_t e=(uint64_t)v->c->size,stop,p=72,n,off,z;
 if(!sxamip_eq(v,0,"AMC V1.2 REPLAY!",16,e)||!AP_ROW(amc_header,0,e)||!sxamip_be(v,24,4,&stop,e)||stop<88||(stop-72)%16||!sxamip_span(v,72,stop-72,e))return false;
 n=(stop-72)/16;
 for(uint64_t i=0;i<n;i++,p+=16){if(!sxamip_be(v,p,4,&off,e)||!sxamip_be(v,p+4,2,&z,e)||!sxamip_span(v,off,z*2,e)||!AP_ROW(amc_sample,p,e))return false;}
 return true;
}
bool sx_hawlitzeck_amcomposer_build(sxamip_view*v)
{
 return sxamip_amc(v);
}
#undef AP_ROW
