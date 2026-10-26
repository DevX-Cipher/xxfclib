/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * southern_magneticfieldspacker data structures, moved out of the modvariants schema family. */
#include "../../../xx_format_schema_modvariants.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define SMV_ROW(n,p) sxmodv_row(v,&sxmodv_##n,p)
static bool sxmodv_mfp(sxmodv_view*v){
 uint64_t count,copy;if(!sxmodv_span(v,0,382))return false;
 for(unsigned i=0;i<31;i++)if(!SMV_ROW(mod_compact_sample,i*8))return false;
 if(!SMV_ROW(mfp_controls,248))return false;
 for(unsigned i=0;i<128;i++)if(!SMV_ROW(mod_order,250+i))return false;
 if(!SMV_ROW(mfp_counts,378)||!sxmodv_word(v,378,2,&count)||!sxmodv_word(v,380,2,&copy)||count!=copy||!count||count>127||!sxmodv_span(v,382,count*8))return false;
 for(uint64_t i=0;i<count;i++)if(!SMV_ROW(mfp_channels,382+i*8))return false;
 /* Original ADDA.W uses signed displacements from382+8*count. Packed channel
  * bodies and the separate .smp companion have no invented physical members. */
 return true;
}
bool sx_southern_magneticfieldspacker_build(sxmodv_view*v)
{
 return sxmodv_mfp(v);
}
#undef SMV_ROW
