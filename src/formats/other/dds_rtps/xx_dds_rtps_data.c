/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DDS RTPS data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_rtps_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("protocol_major","uint8",4,1,SX_ID),
 SX_FIELD("protocol_minor","uint8",5,1,SX_ID),
 SX_FIELD("vendor_id","bytes",6,2,SX_ID),
 SX_FIELD("guid_prefix","bytes",8,12,SX_ID),
};
const sx_layout sxnm_rtps_header={UINT32_C(0x6026005F),"rtps_header",sxnm_rtps_header_fields,SX_COUNT(sxnm_rtps_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtps_destination_fields[]={
 SX_FIELD("guid_prefix","bytes",0,12,SX_ID),
};
const sx_layout sxnm_rtps_destination={UINT32_C(0x60260074),"rtps_destination",sxnm_rtps_destination_fields,SX_COUNT(sxnm_rtps_destination_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_rtps(sxnm_view *v)
{
 if(!SN_ROW(rtps_header,0,v->n))return false;size_t at=20;
 while(at<v->n){if(!sxnm_need(v,at,4,v->n))return false;unsigned type=v->p[at],f=v->p[at+1];bool be=!(f&1);size_t n=xx_data_get_u16(v->p+at+2,2,0,be);if(!sxnm_row(v,be?&sxnm_rtps_submessage_be:&sxnm_rtps_submessage_le,at,v->n))return false;at+=4;if(!n&&!(type==9&&(f&2)))n=v->n-at;if(!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;const sx_layout *l=NULL;
  if(type==9&&!(f&2))l=be?&sxnm_rtps_timestamp_be:&sxnm_rtps_timestamp_le;else if(type==14)l=&sxnm_rtps_destination;else if(type==7)l=be?&sxnm_rtps_heartbeat_be:&sxnm_rtps_heartbeat_le;else if(type==21){l=be?&sxnm_rtps_data_be:&sxnm_rtps_data_le;if(!SN_ROW(rtps_cdr_encapsulation,at+20,end))return false;}
  if(l&&!sxnm_row(v,l,at,end))return false;at=end;
 }return true;
}
bool sx_dds_rtps_build(sxnm_view*v)
{
 return sxnm_rtps(v);
}
#undef SN_ROW
