/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE_MUSIC_SAHARASURFERS_IXALANCE_CO data structures, moved out of the pcmusicmore schema family. */
#include "../../../xx_format_schema_pcmusicmore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxpcmore_eq(sx_context*c,uint64_t p,const char*s,size_t n){uint8_t b[64];return n<=sizeof(b)&&sxpcmore_read(c,p,b,n)&&!xx_rt_memcmp(b,s,n);}
#define SXPCMORE_ADD(c,n,p) sxpcmore_put(c,&sxpcmore_##n,p,1)
static bool sxpcmore_ixs(sx_context*c){return sxpcmore_eq(c,0,"IXS!",4)&&sxpcmore_span(c,0,56)&&SXPCMORE_ADD(c,ixs_compressed_header,0);}
bool sx_saharasurfers_ixalance_co_build(sx_context*c)
{
bool ok=false;
ok=sxpcmore_ixs(c);
(void)ok;return c->count&&sxpcmore_finish(c);
}
