/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BONDWELL_2_DISK data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static bool sxdt_bw_name(const uint8_t*b,unsigned n,bool required){bool padding=false;for(unsigned i=0;i<n;i++){unsigned x=b[i]&127;if(x==32){if(!i&&required)return false;padding=true;}else if(padding||x<33||x>126||x=='.'||x==','||x==';'||x==':'||x=='='||x=='?'||x=='*'||x=='<'||x=='>'||x=='['||x==']')return false;}return true;}
static bool sxdt_bw_entries(const uint8_t*b,unsigned first,unsigned end,unsigned minimum,unsigned blocks,uint8_t*used){for(unsigned i=first;i<end;i++){const uint8_t*e=b+i*32;if(e[0]==229)continue;if(e[0]>15||!sxdt_bw_name(e+1,8,true)||!sxdt_bw_name(e+9,3,false)||e[12]>31||e[13]>128||e[14]>15||e[15]>128)return false;unsigned need=(((e[12]&1)*128+e[15])+15)/16;for(unsigned j=0;j<16;j++){unsigned k=e[16+j];if(!k)continue;if(j>=need||k<minimum||k>=blocks||(used[k/8]&(1U<<(k%8))))return false;used[k/8]|=(uint8_t)(1U<<(k%8));}}return true;}
static bool sxdt_bondwell(sx_context*c){unsigned spt=c->size==348160?17:c->size==368640?18:0;if(!spt)return false;uint64_t p=2U*spt*256;uint8_t dir[4096],used[32]={0};unsigned blocks=78*spt*256/2048,n=64;if(!sxdt_read(c,p,dir,sizeof(dir))||!sxdt_bw_entries(dir,0,64,1,blocks,used))return false;if(!(used[0]&2)&&sxdt_bw_entries(dir,64,128,2,blocks,used))n=128;for(unsigned i=0;i<n;i++)if(!sxdt_put(c,dir[i*32]==229?&sxdt_cpm_deleted_entry:&sxdt_cpm_extent8,p+i*32,1))return false;return true;}
bool sx_bondwell_2_disk_build(sx_context*c)
{
bool ok=false;
ok=sxdt_bondwell(c);
return ok&&c->count&&sxdt_finish(c);
}
