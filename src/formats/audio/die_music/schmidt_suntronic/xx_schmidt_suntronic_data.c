/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * schmidt_suntronic data structures, moved out of the amigamore schema family. */
#include "../../../xx_format_schema_amigamore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxamore_sun_end_fields[]={
 SX_FIELD("end_marker","uint32",0,4,SX_ID),
};
const sx_layout sxamore_sun_end={UINT32_C(0x6095002A),"sun_end",sxamore_sun_end_fields,SX_COUNT(sxamore_sun_end_fields),SX_BE};
#define AM_ROW(l,at,end) sxamore_row(v,&sxamore_##l,(at),(end))
static bool sxamore_sun(sxamore_view*v)
{
 uint64_t e=(uint64_t)v->c->size,x,base,p=0,a,b,c,operands[4];
 if(!sxamore_eq(v,0,"\x48\xe7\xff\xfe\x4d\xfa",6,e)||!sxamore_be(v,8,4,&x,e)||(x!=0x4a2e0018&&x!=0x4a2e0010)||!sxamore_signed16(v,6,6,&base,e)||base<14)return false;
 bool four_channels=x==0x4a2e0018;uint64_t bound=base<e?base:e;
 if(!sxamore_find(v,&p,bound,0x43ee,2,2))return false;operands[0]=p+2;
 if(!sxamore_signed16(v,p+2,base,&a,e)||!sxamore_span(v,a,four_channels?20:4,e))return false;
 p=0;for(unsigned i=1;i<4;i++){if(!sxamore_find(v,&p,bound,0x45ee,2,2))return false;operands[i]=p+2;p+=2;}
 if(!sxamore_signed16(v,operands[2],base,&b,e)||!sxamore_signed16(v,operands[3],base,&c,e)||b>c)return false;
 if(!AM_ROW(signed_displacement,6,e))return false;
 if(four_channels){if(!AM_ROW(sun_initial_channels,a,e))return false;}
 else{bool done=false;for(unsigned i=0;i<4096;i++,a+=4){if(!sxamore_be(v,a,4,&x,e))return false;if(!x){if(!AM_ROW(sun_end,a,e))return false;done=true;break;}if(!AM_ROW(original_address,a,e))return false;}if(!done)return false;}
 for(unsigned i=0;i<4;i++)if(!AM_ROW(signed_displacement,operands[i],e))return false;
 /* b..c mixes original pointers with control words in the two dialects.
    Their physical extent remains raw instead of pretending it is a u32 array. */
 return true;
}
bool sx_schmidt_suntronic_build(sxamore_view*v)
{
 return sxamore_sun(v);
}
#undef AM_ROW
