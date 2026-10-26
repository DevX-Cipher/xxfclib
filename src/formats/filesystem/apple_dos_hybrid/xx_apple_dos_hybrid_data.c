/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * APPLE_DOS_HYBRID data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static bool sxdt_hybrid(sx_context*c){sxdt_view v={c,0,(uint64_t)c->size,0};if(c->size!=143360||!sxdt_av_apple_dos(&v,16))return false;uint8_t h[512];for(unsigned i=0;i<2;i++){if(!sxdt_read(c,i?2816:1024,h,512))return false;if(sxdt_av_pd_header(h))return sxdt_av_prodos(&v);if(!sxdt16(h,0)&&sxdt16(h+2,0)==6&&h[6]>=1&&h[6]<=7)return sxdt_av_pascal(&v);if(!i&&h[0]=='B'&&h[1]=='D')return sxdt_av_hfs(&v);}/* The alternate CP/M view has caller-selected skew; its virtual directory is not guessed here. */return true;}
bool sx_apple_dos_hybrid_build(sx_context*c)
{
bool ok=false;
ok=sxdt_hybrid(c);
return ok&&c->count&&sxdt_finish(c);
}
