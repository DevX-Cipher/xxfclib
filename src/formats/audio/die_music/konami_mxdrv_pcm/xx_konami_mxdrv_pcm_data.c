/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Konami's MXDRV external PCM resource (.PDX) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_pdx(sxmn_view*v)
{uint64_t end=v->c->size,at=0,data=end;while(at<data){uint64_t off,z;if(!MN_ROW(pdx_entry,at,data)||!sxmn_word(v,at,4,true,&off,end)||!sxmn_word(v,at+4,4,true,&z,end))return false;if(off){if(off<at+8||!sxmn_span(v,off,z,end))return false;if(off<data)data=off;}at+=8;if(++v->work>4000000)return false;}return at==data;}
bool sx_konami_mxdrv_pcm_build(sxmn_view*v)
{
 return sxmn_pdx(v);
}
#undef MN_ROW
