/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Humongous TLKB data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_he_tlkb_chunk_fields[]={
 SX_FIELD("encoded_tag","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_total_size","uint8[4]",4,4,SX_NONE),
};
const sx_layout sxarm_he_tlkb_chunk={UINT32_C(0x607c001d),"he_tlkb_chunk",sxarm_he_tlkb_chunk_fields,SX_COUNT(sxarm_he_tlkb_chunk_fields),SX_LE};
static bool sxarm_he(sx_context*c){uint8_t h[8];if(!sxarm_read(c,0,h,8)||h[0]!=('T'^0x69)||h[1]!=('L'^0x69)||h[2]!=('K'^0x69)||h[3]!=('B'^0x69))return false;uint64_t p=0,end=(uint64_t)c->size;for(unsigned i=0;p<end&&i<SXARM_LIMIT;i++){if(!sxarm_read(c,p,h,8)||!sxarm_add(c,&sxarm_he_tlkb_chunk,p))return false;for(unsigned j=0;j<8;j++)h[j]^=0x69;uint64_t z=sxarm_uint(h+4,4,true);if(z<8||z>end-p)return false;if(!p){end=z;p=8;}else p+=z;}return true;}
bool sx_he_tlkb_build(sx_context*c)
{
 return sxarm_he(c);
}
