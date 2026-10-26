/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Amaya 'Pixel' Daisuke's pxtone Noise instrument (.PTNOISE) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_pxt_noise_header_fields[]={
 SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("version","uint32",8,4,SX_ID),
};
const sx_layout sxmn_pxt_noise_header={UINT32_C(0x60760023),"pxt_noise_header",sxmn_pxt_noise_header_fields,SX_COUNT(sxmn_pxt_noise_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples1_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,1,SX_COUNT_PROP),
};
const sx_layout sxmn_pxt_noise_samples1={UINT32_C(0x60760024),"pxt_noise_samples1",sxmn_pxt_noise_samples1_fields,SX_COUNT(sxmn_pxt_noise_samples1_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples2_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,2,SX_COUNT_PROP),
};
const sx_layout sxmn_pxt_noise_samples2={UINT32_C(0x60760025),"pxt_noise_samples2",sxmn_pxt_noise_samples2_fields,SX_COUNT(sxmn_pxt_noise_samples2_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples3_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,3,SX_COUNT_PROP),
};
const sx_layout sxmn_pxt_noise_samples3={UINT32_C(0x60760026),"pxt_noise_samples3",sxmn_pxt_noise_samples3_fields,SX_COUNT(sxmn_pxt_noise_samples3_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples4_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,4,SX_COUNT_PROP),
};
const sx_layout sxmn_pxt_noise_samples4={UINT32_C(0x60760027),"pxt_noise_samples4",sxmn_pxt_noise_samples4_fields,SX_COUNT(sxmn_pxt_noise_samples4_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_samples5_fields[]={
 SX_FIELD("samples_44100hz","uleb128_64",0,5,SX_COUNT_PROP),
};
const sx_layout sxmn_pxt_noise_samples5={UINT32_C(0x60760028),"pxt_noise_samples5",sxmn_pxt_noise_samples5_fields,SX_COUNT(sxmn_pxt_noise_samples5_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_pxt_noise_units_fields[]={
 SX_FIELD("units","int8",0,1,SX_COUNT_PROP),
};
const sx_layout sxmn_pxt_noise_units={UINT32_C(0x60760029),"pxt_noise_units",sxmn_pxt_noise_units_fields,SX_COUNT(sxmn_pxt_noise_units_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_noise(sxmn_view*v)
{uint64_t end=v->c->size,at=12,b=0,value=0;if(!MN_ROW(pxt_noise_header,0,end))return false;unsigned width=0;do{if(width==5||!sxmn_word(v,at+width,1,false,&b,end)||(width==4&&(b&240)))return false;value|=(b&127)<<(7*width);width++;}while(b&128);if(value>INT32_MAX)return false;const sx_layout*ls[]={&sxmn_pxt_noise_samples1,&sxmn_pxt_noise_samples2,&sxmn_pxt_noise_samples3,&sxmn_pxt_noise_samples4,&sxmn_pxt_noise_samples5};if(!sxmn_row(v,ls[width-1],at,end)||!MN_ROW(pxt_noise_units,at+width,end)||!sxmn_word(v,at+width,1,false,&b,end)||b>4)return false;return true;}
bool sx_pixel_pxtone_ptnoise_build(sxmn_view*v)
{
 return sxmn_noise(v);
}
#undef MN_ROW
