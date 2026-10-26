/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BinHex 4.0 data structures, moved out of the archivetransport schema family. */
#include "../../xx_format_schema_archivetransport.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxatp_binhex_banner_fields[]={
 SX_FIELD("banner","char[45]",0,45,SX_SIGNATURE),
};
const sx_layout sxatp_binhex_banner={UINT32_C(0x60890071),"binhex_banner",sxatp_binhex_banner_fields,SX_COUNT(sxatp_binhex_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_binhex_delimiter_fields[]={
 SX_FIELD("delimiter","char[1]",0,1,SX_NONE),
};
const sx_layout sxatp_binhex_delimiter={UINT32_C(0x60890072),"binhex_delimiter",sxatp_binhex_delimiter_fields,SX_COUNT(sxatp_binhex_delimiter_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_binhex_encoded_run_fields[]={
 SX_FIELD("encoded_six_bit_characters","char",0,0,SX_NONE),
};
const sx_layout sxatp_binhex_encoded_run={UINT32_C(0x60890073),"binhex_encoded_run",sxatp_binhex_encoded_run_fields,SX_COUNT(sxatp_binhex_encoded_run_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_transport_whitespace_fields[]={
 SX_FIELD("whitespace","uint8",0,0,SX_NONE),
};
const sx_layout sxatp_transport_whitespace={UINT32_C(0x60890075),"transport_whitespace",sxatp_transport_whitespace_fields,SX_COUNT(sxatp_transport_whitespace_fields),SX_LE};
static bool sxatp_hqxchar(uint8_t x){const char*a="!\"#$%&'()*+,-012345689@ABCDEFGHIJKLMNPQRSTUVXYZ[`abcdefhijklmpqr";return x&&xx_rt_strchr(a,x)!=NULL;}
static bool sxatp_binhex(sx_context*c){if(!sxatp_add(c,&sxatp_binhex_banner,0))return false;uint64_t p=45;unsigned colons=0;while(p<(uint64_t)c->size&&c->count<SXATP_LIMIT){uint8_t x;if(!sxatp_read(c,p,&x,1))return false;if(x==':'){if(!sxatp_add(c,&sxatp_binhex_delimiter,p++))return false;if(++colons==2)return true;continue;}const sx_layout*l=sxatp_space(x)?&sxatp_transport_whitespace:colons==1&&sxatp_hqxchar(x)?&sxatp_binhex_encoded_run:NULL;if(!l)return false;uint64_t q=p+1;while(q<(uint64_t)c->size&&q-p<4096){uint8_t y;if(!sxatp_read(c,q,&y,1))return false;if(l==&sxatp_transport_whitespace?!sxatp_space(y):!sxatp_hqxchar(y))break;q++;}if(!sxatp_text(c,l,p,q-p,false))return false;p=q;}return true;}
bool sx_binhex_build(sx_context*c)
{
 return sxatp_binhex(c);
}
