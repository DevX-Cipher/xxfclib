/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PSX Alternative!'s Eternal SPU Plugin chiptune (.SPU) data structures, moved out of the musicremaining schema family. */
#include "../../../xx_format_schema_musicremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmr_spu_metadata_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("game","char[64]",4,64,SX_NONE),
 SX_FIELD("title","char[64]",68,64,SX_NONE),
 SX_FIELD("artist","char[32]",132,32,SX_NONE),
 SX_FIELD("comment","char[3840]",164,3840,SX_NONE),
};
const sx_layout sxmr_spu_metadata={UINT32_C(0x607D003D),"spu_metadata",sxmr_spu_metadata_fields,SX_COUNT(sxmr_spu_metadata_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_register_fields[]={
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
const sx_layout sxmr_spu_register={UINT32_C(0x607D003E),"spu_register",sxmr_spu_register_fields,SX_COUNT(sxmr_spu_register_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_transfer_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("payload_bytes","uint32",1,4,SX_SIZE),
};
const sx_layout sxmr_spu_transfer={UINT32_C(0x607D0044),"spu_transfer",sxmr_spu_transfer_fields,SX_COUNT(sxmr_spu_transfer_fields),SX_LE};
static const xx_data_struct_field_desc sxmr_spu_xa_fields[]={
 SX_FIELD("opcode","uint8",0,1,SX_ID),
 SX_FIELD("xa_metadata","bytes",1,32,SX_NONE),
};
const sx_layout sxmr_spu_xa={UINT32_C(0x607D0046),"spu_xa",sxmr_spu_xa_fields,SX_COUNT(sxmr_spu_xa_fields),SX_LE};
#define MR_ROW(l,at,end) sxmr_row(v,&sxmr_##l,(at),(end))
static bool sxmr_spu(sxmr_view*v)
{uint64_t end=v->c->size,n,x,p=0x80208,ticks;if(!sxmr_eq(v,0,"SPU",3,end)||!sxmr_u(v,3,1,&x,end)||(x!=0&&x!='1')||!MR_ROW(spu_metadata,0,end)||!sxmr_table(v,&sxmr_spu_register,0x80000,256,end)||!sxmr_u(v,0x80200,4,&ticks,end)||!sxmr_u(v,0x80204,4,&n,end))return false;
 if(ticks==44100&&n<=(end-p)/12){return MR_ROW(spu_old_timing,0x80200,end)&&sxmr_table(v,&sxmr_spu_old_event,p,n,end);}
 if(!MR_ROW(spu_new_timing,0x80200,end))return false;
 while(p<end&&n<ticks){if(!sxmr_u(v,p,1,&x,end))return false;
  if(x==0){if(!MR_ROW(spu_write,p,end)||!sxmr_u(v,p+7,4,&n,end))return false;p+=11;}
  else if(x==1){if(!MR_ROW(spu_read,p,end)||!sxmr_u(v,p+5,4,&n,end))return false;p+=9;}
  else if(x==2||x==5){if(!sxmr_u(v,p+1,4,&x,end)||!MR_ROW(spu_transfer,p,end))return false;p+=5;if(!sxmr_span(v,p,x,end))return false;p+=x;if(!MR_ROW(spu_tick,p,end)||!sxmr_u(v,p,4,&n,end))return false;p+=4;}
  else if(x==3){if(!MR_ROW(spu_dma_read,p,end)||!sxmr_u(v,p+5,4,&n,end))return false;p+=9;}
  else if(x==4){if(!MR_ROW(spu_xa,p,end)||!sxmr_span(v,p+33,16384,end))return false;p+=33+16384;if(!MR_ROW(spu_tick,p,end)||!sxmr_u(v,p,4,&n,end))return false;p+=4;}
  else return false;
 }
 return n>=ticks;}
bool sx_psxalt_eternalspuplugin_build(sxmr_view*v)
{
 return sxmr_spu(v);
}
#undef MR_ROW
