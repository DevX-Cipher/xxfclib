/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * FidoNet mail packets data structures, moved out of the docmeta schema family. */
#include "../../xx_format_schema_docmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdm_pkt_type2_header_fields[]={
 SX_FIELD("origin_node","uint16",0,2,SX_ID),
 SX_FIELD("destination_node","uint16",2,2,SX_ID),
 SX_FIELD("year","uint16",4,2,SX_NONE),
 SX_FIELD("month_zero_based","uint16",6,2,SX_NONE),
 SX_FIELD("day","uint16",8,2,SX_NONE),
 SX_FIELD("hour","uint16",10,2,SX_NONE),
 SX_FIELD("minute","uint16",12,2,SX_NONE),
 SX_FIELD("second","uint16",14,2,SX_NONE),
 SX_FIELD("baud_rate","uint16",16,2,SX_NONE),
 SX_FIELD("packet_type","uint16",18,2,SX_ID),
 SX_FIELD("origin_net","uint16",20,2,SX_ID),
 SX_FIELD("destination_net","uint16",22,2,SX_ID),
 SX_FIELD("product_code","uint8",24,1,SX_ID),
 SX_FIELD("serial_number","uint8",25,1,SX_NONE),
 SX_FIELD("password","char[8]",26,8,SX_NONE),
 SX_FIELD("origin_zone","uint16",34,2,SX_ID),
 SX_FIELD("destination_zone","uint16",36,2,SX_ID),
 SX_FIELD("reserved_or_extension","bytes",38,20,SX_NONE),
};
const sx_layout sxdm_pkt_type2_header={UINT32_C(0x6023000E),"pkt_type2_header",sxdm_pkt_type2_header_fields,SX_COUNT(sxdm_pkt_type2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxdm_pkt_message_header_fields[]={
 SX_FIELD("message_type","uint16",0,2,SX_ID),
 SX_FIELD("origin_node","uint16",2,2,SX_ID),
 SX_FIELD("destination_node","uint16",4,2,SX_ID),
 SX_FIELD("origin_net","uint16",6,2,SX_ID),
 SX_FIELD("destination_net","uint16",8,2,SX_ID),
 SX_FIELD("attributes","uint16",10,2,SX_FLAGS),
 SX_FIELD("cost","uint16",12,2,SX_NONE),
};
const sx_layout sxdm_pkt_message_header={UINT32_C(0x6023000F),"pkt_message_header",sxdm_pkt_message_header_fields,SX_COUNT(sxdm_pkt_message_header_fields),SX_LE};
static bool sxdm_pkt(sx_context *c)
{
 int64_t at=58;uint16_t type;if(!sxdm_add(c,&sxdm_pkt_type2_header,0,58))return false;
 for(unsigned i=0;at<c->size;i++){
  if(i>=65536)return false;if(c->size-at<2)return true;if(!sx_u16(c,at,false,&type))return false;
  if(!type)return true;if(c->size-at<3)return true;
  if(type!=2||!sxdm_add(c,&sxdm_pkt_message_header,at,14))return false;at+=14;
  for(unsigned j=0;j<5;j++)if(!sxdm_zero(c,&at,c->size,16*1024*1024))return false;
 }return true;
}
bool sx_pkt_build(sx_context*c)
{
 return sxdm_pkt(c);
}
