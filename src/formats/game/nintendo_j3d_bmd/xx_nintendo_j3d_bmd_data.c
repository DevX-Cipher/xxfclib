/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo j3d bmd data structures, moved out of the mediaextra schema family. */
#include "../../xx_format_schema_mediaextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SM_ROW(l,at,end) sxmx_row(v,&sxmx_##l,(at),(end))
static bool sxmx_j3d(sxmx_view*v)
{if(!SM_ROW(j3d_header,0,v->n))return false;uint32_t n=sxmx_u32(v->p+12,true);if(n>4096)return false;size_t at=32;for(uint32_t i=0;i<n;i++){if(!SM_ROW(section_be,at,v->n))return false;size_t size=sxmx_u32(v->p+at+4,true);if(size<8||!sxmx_need(v,at,size,v->n))return false;at+=size;}return at==v->n;}
bool sx_nintendo_j3d_bmd_build(sxmx_view*v)
{
 return sxmx_j3d(v);
}
#undef SM_ROW
