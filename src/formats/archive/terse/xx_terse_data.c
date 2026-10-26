/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IBM TERSE containers data structures, moved out of the archivewire schema family. */
#include "../../xx_format_schema_archivewire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarwire_terse_spack_signature_fields[]={
 SX_FIELD("signature","uint8[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxarwire_terse_spack_signature={UINT32_C(0x608d0004),"terse_spack_signature",sxarwire_terse_spack_signature_fields,SX_COUNT(sxarwire_terse_spack_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_terse_profile_fields[]={
 SX_FIELD("profile_selector","uint8",0,1,SX_ID),
 SX_FIELD("profile_variant","uint8",1,1,SX_NONE),
 SX_FIELD("opaque_profile","uint8[10]",2,10,SX_NONE),
};
const sx_layout sxarwire_terse_profile={UINT32_C(0x608d0005),"terse_profile",sxarwire_terse_profile_fields,SX_COUNT(sxarwire_terse_profile_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_terse_code_bit0_fields[]={
 SX_FIELD("pair_code","msb_bits[0,12]",0,2,SX_ID),
};
const sx_layout sxarwire_terse_code_bit0={UINT32_C(0x608d007e),"terse_code_bit0",sxarwire_terse_code_bit0_fields,SX_COUNT(sxarwire_terse_code_bit0_fields),SX_LE};
static const xx_data_struct_field_desc sxarwire_terse_code_bit4_fields[]={
 SX_FIELD("pair_code","msb_bits[4,12]",0,2,SX_ID),
};
const sx_layout sxarwire_terse_code_bit4={UINT32_C(0x608d007f),"terse_code_bit4",sxarwire_terse_code_bit4_fields,SX_COUNT(sxarwire_terse_code_bit4_fields),SX_LE};
static const sx_layout *const sxarwire_set_terse_code[]={&sxarwire_terse_code_bit0,&sxarwire_terse_code_bit4};
#define SXARWIRE_LIMIT 20000U
static bool sxarwire_terse(sx_context*c){uint8_t h[12];if(!sxarwire_read(c,0,h,4))return false;unsigned prefix;
 if(h[0]==1&&h[1]==0x89&&h[2]==0x69&&h[3]==0xa5){prefix=4;if(!sxarwire_put(c,&sxarwire_terse_spack_signature,0))return false;}
 else{if(!sxarwire_read(c,0,h,12)||(h[0]!=2&&h[0]!=5&&h[0]!=9)||h[1]>1)return false;prefix=12;if(!sxarwire_put(c,&sxarwire_terse_profile,0))return false;}
 sxarwire_bits b={c,(uint64_t)prefix*8,false,0,0,false};while(c->count<SXARWIRE_LIMIT){uint64_t p=b.bit,v;if(!sxarwire_take(&b,12,&v)||!sxarwire_put(c,sxarwire_set_terse_code[(p&7)/4],p/8))return false;if(!v)return true;}return true;}
bool sx_terse_build(sx_context*c)
{
 return sxarwire_terse(c);
}
