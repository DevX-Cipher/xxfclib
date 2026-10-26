/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PFCP MESSAGE data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_pfcp_node_ipv4_fields[]={
 SX_FIELD("node_ipv4","bytes",0,4,SX_NONE),
};
const sx_layout sxnm_pfcp_node_ipv4={UINT32_C(0x60260039),"pfcp_node_ipv4",sxnm_pfcp_node_ipv4_fields,SX_COUNT(sxnm_pfcp_node_ipv4_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_node_ipv6_fields[]={
 SX_FIELD("node_ipv6","bytes",0,16,SX_NONE),
};
const sx_layout sxnm_pfcp_node_ipv6={UINT32_C(0x6026003A),"pfcp_node_ipv6",sxnm_pfcp_node_ipv6_fields,SX_COUNT(sxnm_pfcp_node_ipv6_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pfcp_dns_label_fields[]={
 SX_FIELD("label_length","uint8",0,1,SX_SIZE),
};
const sx_layout sxnm_pfcp_dns_label={UINT32_C(0x6026003B),"pfcp_dns_label",sxnm_pfcp_dns_label_fields,SX_COUNT(sxnm_pfcp_dns_label_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_pfcp(sxnm_view *v)
{
 if(!SN_ROW(pfcp_node_header,0,v->n)||sxnm_u16(v->p+2)!=v->n-4)return false;size_t at=8;
 while(at<v->n){if(!SN_ROW(pfcp_information_element,at,v->n))return false;unsigned type=sxnm_u16(v->p+at),n=sxnm_u16(v->p+at+2);at+=4;if(!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;
  if(type==60){if(!SN_ROW(pfcp_node_id_type,at,end))return false;unsigned kind=v->p[at++];if(kind<2){if(!sxnm_row(v,kind?&sxnm_pfcp_node_ipv6:&sxnm_pfcp_node_ipv4,at,end))return false;}else if(kind==2){while(at<end){if(!SN_ROW(pfcp_dns_label,at,end))return false;unsigned len=v->p[at++];if(!len||!sxnm_need(v,at,len,end))return false;at+=len;}}else return false;}
  else if(type==96&&!SN_ROW(pfcp_recovery_time,at,end))return false;at=end;
 }return true;
}
bool sx_pfcp_message_build(sxnm_view*v)
{
 return sxnm_pfcp(v);
}
#undef SN_ROW
