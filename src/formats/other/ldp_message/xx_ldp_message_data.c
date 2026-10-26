/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LDP MESSAGE data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_ldp_ipv4_transport_fields[]={
 SX_FIELD("transport_ipv4","bytes",0,4,SX_NONE),
};
const sx_layout sxnm_ldp_ipv4_transport={UINT32_C(0x6026004C),"ldp_ipv4_transport",sxnm_ldp_ipv4_transport_fields,SX_COUNT(sxnm_ldp_ipv4_transport_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_ldp_configuration_sequence_fields[]={
 SX_FIELD("configuration_sequence","uint32",0,4,SX_ID),
};
const sx_layout sxnm_ldp_configuration_sequence={UINT32_C(0x6026004D),"ldp_configuration_sequence",sxnm_ldp_configuration_sequence_fields,SX_COUNT(sxnm_ldp_configuration_sequence_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_ldp(sxnm_view *v)
{
 if(!SN_ROW(ldp_pdu_header,0,v->n)||sxnm_u16(v->p+2)!=v->n-4)return false;size_t at=10;
 while(at<v->n){if(!SN_ROW(ldp_message_header,at,v->n))return false;size_t n=(size_t)sxnm_u16(v->p+at+2)+4;if(n<8||!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;at+=8;
  while(at<end){if(!SN_ROW(ldp_tlv_header,at,end))return false;unsigned type=sxnm_u16(v->p+at)&0x3fff,nv=sxnm_u16(v->p+at+2);at+=4;if(!sxnm_need(v,at,nv,end))return false;const sx_layout *l=type==0x400?&sxnm_ldp_common_hello:type==0x401?&sxnm_ldp_ipv4_transport:type==0x402?&sxnm_ldp_configuration_sequence:NULL;if(l&&!sxnm_row(v,l,at,at+nv))return false;at+=nv;}
 }return true;
}
bool sx_ldp_message_build(sxnm_view*v)
{
 return sxnm_ldp(v);
}
#undef SN_ROW
