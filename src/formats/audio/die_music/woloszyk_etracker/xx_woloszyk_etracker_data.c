/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Woloszyk Etracker data structures, moved out of the zxmusic schema family. */
#include "../../../xx_format_schema_zxmusic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static bool sxzxm_etracker(sx_context*c){
 uint64_t base=0;if((sxzxm_eq(c,0,"\x21\xb3\x84",3)||sxzxm_eq(c,0,"\x21\xb3\x04",3))&&sxzxm_eq(c,0x4bd,"ETracker (C) BY ESI.",19))base=0x4b3;
 uint8_t h[30],v;if(!sxzxm_read(c,base,h,30)||!sxzxm_put(c,&sxzxm_etracker_header,base,1))return false;
 unsigned pos=sxzxm16(h),pt=sxzxm16(h+2),sp=sxzxm16(h+4),op=sxzxm16(h+6),vol=sxzxm16(h+8),patterns=0,n=0;
 for(;n<1024&&sxzxm_u8(c,base+pos+n,&v);n++){if(v==255){n++;break;}if(v<96){if(v%3)break;if(v/3U+1>patterns)patterns=v/3U+1;}}
 if(!sxzxm_opt(c,&sxzxm_etracker_position,base+pos,n)||!sxzxm_opt(c,&sxzxm_etracker_pattern,base+pt,patterns))return false;
 unsigned sc=op>=sp?(op-sp)/2:0,oc=vol>=op?(vol-op)/2:0;if(sc>32)sc=32;if(oc>32)oc=32;
 return sxzxm_opt(c,&sxzxm_etracker_sample_offset,base+sp,sc)&&sxzxm_opt(c,&sxzxm_etracker_ornament_offset,base+op,oc);
}
bool sx_woloszyk_etracker_build(sx_context*c)
{
 return sxzxm_etracker(c);
}
