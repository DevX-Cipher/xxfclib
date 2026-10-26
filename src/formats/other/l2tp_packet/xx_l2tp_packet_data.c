/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * L2TP PACKET data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_l2tp_protocol_version_fields[]={
 SX_FIELD("protocol_version","uint16",0,2,SX_ID),
};
const sx_layout sxnm_l2tp_protocol_version={UINT32_C(0x60260055),"l2tp_protocol_version",sxnm_l2tp_protocol_version_fields,SX_COUNT(sxnm_l2tp_protocol_version_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_firmware_revision_fields[]={
 SX_FIELD("firmware_revision","uint16",0,2,SX_ID),
};
const sx_layout sxnm_l2tp_firmware_revision={UINT32_C(0x60260056),"l2tp_firmware_revision",sxnm_l2tp_firmware_revision_fields,SX_COUNT(sxnm_l2tp_firmware_revision_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_assigned_tunnel_fields[]={
 SX_FIELD("tunnel_id","uint16",0,2,SX_ID),
};
const sx_layout sxnm_l2tp_assigned_tunnel={UINT32_C(0x60260057),"l2tp_assigned_tunnel",sxnm_l2tp_assigned_tunnel_fields,SX_COUNT(sxnm_l2tp_assigned_tunnel_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_receive_window_fields[]={
 SX_FIELD("window_packets","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxnm_l2tp_receive_window={UINT32_C(0x60260058),"l2tp_receive_window",sxnm_l2tp_receive_window_fields,SX_COUNT(sxnm_l2tp_receive_window_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_framing_capabilities_fields[]={
 SX_FIELD("framing_capabilities","uint32",0,4,SX_FLAGS),
};
const sx_layout sxnm_l2tp_framing_capabilities={UINT32_C(0x60260059),"l2tp_framing_capabilities",sxnm_l2tp_framing_capabilities_fields,SX_COUNT(sxnm_l2tp_framing_capabilities_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_l2tp_bearer_capabilities_fields[]={
 SX_FIELD("bearer_capabilities","uint32",0,4,SX_FLAGS),
};
const sx_layout sxnm_l2tp_bearer_capabilities={UINT32_C(0x6026005A),"l2tp_bearer_capabilities",sxnm_l2tp_bearer_capabilities_fields,SX_COUNT(sxnm_l2tp_bearer_capabilities_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_l2tp(sxnm_view *v)
{
 if(!SN_ROW(l2tp_control_header,0,v->n)||sxnm_u16(v->p+2)!=v->n)return false;size_t at=12;
 while(at<v->n){if(!SN_ROW(l2tp_avp_header,at,v->n))return false;unsigned n=sxnm_u16(v->p+at)&1023,type=sxnm_u16(v->p+at+4);if(n<6||!sxnm_need(v,at,n,v->n))return false;const sx_layout *l=NULL;
  switch(type){case 0:l=&sxnm_l2tp_message_type;break;case 2:l=&sxnm_l2tp_protocol_version;break;case 3:l=&sxnm_l2tp_framing_capabilities;break;case 4:l=&sxnm_l2tp_bearer_capabilities;break;case 6:l=&sxnm_l2tp_firmware_revision;break;case 9:l=&sxnm_l2tp_assigned_tunnel;break;case 10:l=&sxnm_l2tp_receive_window;break;default:break;}if(l&&!sxnm_row(v,l,at+6,at+n))return false;at+=n;
 }return true;
}
bool sx_l2tp_packet_build(sxnm_view*v)
{
 return sxnm_l2tp(v);
}
#undef SN_ROW
