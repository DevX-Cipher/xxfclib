/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * CFFA data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static bool sxdt_cffa(sx_context*c){const uint64_t slot=33554432;uint64_t slots=(uint64_t)c->size/slot;if((uint64_t)c->size%slot==slot-512)slots++;/* Profile6 has two 1GiB tails; infer only this exact authenticated size. */bool six=(uint64_t)c->size==4*slot+2*UINT64_C(1073741824)||(uint64_t)c->size==4*slot+2*UINT64_C(1073741824)-512;if(six)slots=6;if(slots!=4&&slots!=8&&!six)return false;uint64_t p=0;for(uint64_t i=0;i<slots;i++){uint64_t n=six&&i>=4?UINT64_C(1073741824):slot;if(n>(uint64_t)c->size-p)n=(uint64_t)c->size-p;uint8_t b[512];if(!sxdt_read(c,p+1024,b,512))return false;if(sxdt_av_pd_header(b)||(b[0]=='B'&&b[1]=='D')){if(!sxdt_child(c,p,n))return false;}p+=n;}return c->count!=0;}
bool sx_cffa_build(sx_context*c)
{
bool ok=false;
ok=sxdt_cffa(c);
return ok&&c->count&&sxdt_finish(c);
}
