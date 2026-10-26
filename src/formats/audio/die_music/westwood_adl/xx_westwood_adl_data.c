/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Westwood ADL module (.ADL) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_adl_program8_fields[]={
 SX_FIELD("program","uint8",0,1,SX_ID),
};
const sx_layout sxmw_adl_program8={UINT32_C(0x6087003D),"adl_program8",sxmw_adl_program8_fields,SX_COUNT(sxmw_adl_program8_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_adl_program16_fields[]={
 SX_FIELD("program","uint16",0,2,SX_ID),
};
const sx_layout sxmw_adl_program16={UINT32_C(0x6087003E),"adl_program16",sxmw_adl_program16_fields,SX_COUNT(sxmw_adl_program16_fields),SX_LE};
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_adl(sxmw_view*v)
{uint64_t end=v->c->size,base=500,n=500,p=0,x;bool old=false;
 if(end<720)return false;for(unsigned i=0;i<500;i+=2){if(!sxmw_u(v,i,2,&x,end))return false;if(x>=500&&x<65535){old=true;break;}}
 if(old){base=sxmw_eq(v,120,"lwm\xff\xff\xffno",8,end)?250:120;n=250;for(unsigned i=0;i<150;i++){if(!sxmw_u(v,base+2*i,2,&x,end))return false;if(x&&x<1000){n=150;break;}}}
 if(!sxmw_span(v,base,n*4,end)||!sxmw_take(v,old?&sxmw_adl_program8:&sxmw_adl_program16,&p,old?base:250,end))return false;
 if(!MW_TAKE(adl_program_offset,&p,n,end)||!MW_TAKE(adl_instrument_offset,&p,n,end))return false;
 for(uint64_t i=0;i<n*2;i++){if(!sxmw_u(v,base+i*2,2,&x,end))return false;if(x&&x!=65535&&!sxmw_span(v,base,x,end))return false;}return true;}
bool sx_westwood_adl_build(sxmw_view*v)
{
 return sxmw_adl(v);
}
#undef MW_TAKE
