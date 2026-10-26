/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TwinTeam TwinTrackPlayer DMO data structures, moved out of the synthtail schema family. */
#include "../../../xx_format_schema_synthtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsynt_dmo_cipher_header_fields[]={
 SX_FIELD("initial_seed","uint32",0,4,SX_NONE),
 SX_FIELD("seed_iteration_limit","uint16",4,2,SX_NONE),
 SX_FIELD("seed_xor","uint32",6,4,SX_NONE),
 SX_FIELD("seed_check","uint16",10,2,SX_NONE),
};
const sx_layout sxsynt_dmo_cipher_header={0x608e0018U,"dmo_cipher_header",sxsynt_dmo_cipher_header_fields,SX_COUNT(sxsynt_dmo_cipher_header_fields),SX_LE};
static bool sxsynt_dmo(sx_context*c)
{uint32_t state,mix,sum=0;uint16_t rounds,check;
 if(!sx_u32(c,0,false,&state)||!sx_u16(c,4,false,&rounds)||!sx_u32(c,6,false,&mix)||!sx_u16(c,10,false,&check))return false;
 for(uint32_t i=0;i<=(uint32_t)rounds;i++){
  if(!(i&255U)&&c->pd&&xx_pd_is_stopped(c->pd))return false;
  state=state*UINT32_C(0x08088405)+1U;sum+=(uint32_t)(((uint64_t)state*65535U)>>32);
 }
 state=(sum^mix)*UINT32_C(0x08088405)+1U;
 if((uint16_t)(((uint64_t)state*65535U)>>32)!=check)return sx_raw(c,0,c->size);
 return sx_add(c,&sxsynt_dmo_cipher_header,0,12)&&sx_raw(c,12,c->size-12);
}
bool sx_twinteam_twintrackplayer_dmo_build(sx_context*c)
{
 return sxsynt_dmo(c);
}
