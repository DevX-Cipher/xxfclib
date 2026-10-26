/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIE MUSIC VSOFT VORTEXPROJECT data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_vtx(sxmr_view*v)
{uint64_t end=v->c->size,p,mode,x,clock;bool old=sxmr_eq(v,0,"AY",2,end)||sxmr_eq(v,0,"YM",2,end);
 if(!old&&!sxmr_eq(v,0,"ay",2,end)&&!sxmr_eq(v,0,"ym",2,end))return false;
 if(!sxmr_u(v,2,1,&mode,end)||mode>6||!sxmr_u(v,5,4,&clock,end)||clock<800000||clock>4000000)return false;
 if(old){p=14;if(!MR_ROW(vtx_legacy_header,0,end))return false;}else{p=16;if(!MR_ROW(vtx_header,0,end))return false;}
 if(!sxmr_u(v,p-4,4,&x,end)||x<2||x>0xa00000)return false;
 for(unsigned i=0;i<(old?2:5);i++)if(!sxmr_string(v,&p,end))return false;return p<end;}
bool sx_vsoft_vortexproject_build(sxmr_view*v)
{
 return sxmr_vtx(v);
}
#undef MR_ROW
