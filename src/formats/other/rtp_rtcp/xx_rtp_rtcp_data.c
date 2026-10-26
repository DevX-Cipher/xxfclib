/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RTP RTCP data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_rtp_csrc_fields[]={
 SX_FIELD("contributing_source","uint32",0,4,SX_ID),
};
const sx_layout sxnm_rtp_csrc={UINT32_C(0x60260018),"rtp_csrc",sxnm_rtp_csrc_fields,SX_COUNT(sxnm_rtp_csrc_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_receiver_info_fields[]={
 SX_FIELD("synchronization_source","uint32",0,4,SX_ID),
};
const sx_layout sxnm_rtcp_receiver_info={UINT32_C(0x6026001D),"rtcp_receiver_info",sxnm_rtcp_receiver_info_fields,SX_COUNT(sxnm_rtcp_receiver_info_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_source_fields[]={
 SX_FIELD("source_identifier","uint32",0,4,SX_ID),
};
const sx_layout sxnm_rtcp_source={UINT32_C(0x6026001F),"rtcp_source",sxnm_rtcp_source_fields,SX_COUNT(sxnm_rtcp_source_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_sdes_end_fields[]={
 SX_FIELD("zero","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxnm_rtcp_sdes_end={UINT32_C(0x60260021),"rtcp_sdes_end",sxnm_rtcp_sdes_end_fields,SX_COUNT(sxnm_rtcp_sdes_end_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_bye_reason_fields[]={
 SX_FIELD("reason_length","uint8",0,1,SX_SIZE),
};
const sx_layout sxnm_rtcp_bye_reason={UINT32_C(0x60260022),"rtcp_bye_reason",sxnm_rtcp_bye_reason_fields,SX_COUNT(sxnm_rtcp_bye_reason_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_rtcp_app_header_fields[]={
 SX_FIELD("source_identifier","uint32",0,4,SX_ID),
 SX_FIELD("name","char[4]",4,4,SX_ID),
};
const sx_layout sxnm_rtcp_app_header={UINT32_C(0x60260023),"rtcp_app_header",sxnm_rtcp_app_header_fields,SX_COUNT(sxnm_rtcp_app_header_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_rtcp(sxnm_view *v)
{
 size_t at=0;
 while(at<v->n){if(!SN_ROW(rtcp_header,at,v->n))return false;unsigned flags=v->p[at],type=v->p[at+1],count=flags&31;size_t n=((size_t)sxnm_u16(v->p+at+2)+1)*4;if(n<4||!sxnm_need(v,at,n,v->n))return false;size_t end=at+n,body=end,p=at+4;
  if(flags&32){unsigned pad=v->p[end-1];if(!pad||pad>n-4||!SN_ROW(rtp_padding_count,end-1,end))return false;body-=pad;}
  if(type==200||type==201){size_t fixed=type==200?24:4;if(!sxnm_row(v,type==200?&sxnm_rtcp_sender_info:&sxnm_rtcp_receiver_info,p,body))return false;p+=fixed;for(unsigned i=0;i<count;i++,p+=24)if(!SN_ROW(rtcp_report_block,p,body))return false;if(p!=body)return false;}
  else if(type==202){for(unsigned i=0;i<count;i++){if(!SN_ROW(rtcp_source,p,body))return false;p+=4;bool ended=false;while(p<body){if(!v->p[p]){if(!SN_ROW(rtcp_sdes_end,p,body))return false;p++;size_t pad=(4-(p-at)%4)%4;if(!sxnm_need(v,p,pad,body))return false;p+=pad;ended=true;break;}if(!SN_ROW(rtcp_sdes_item,p,body))return false;size_t bytes=v->p[p+1];p+=2;if(!sxnm_need(v,p,bytes,body))return false;p+=bytes;}if(!ended)return false;}if(p!=body)return false;}
  else if(type==203){for(unsigned i=0;i<count;i++,p+=4)if(!SN_ROW(rtcp_source,p,body))return false;if(p<body){if(!SN_ROW(rtcp_bye_reason,p,body)||!sxnm_need(v,p+1,v->p[p],body))return false;}}
  else if(type==204){if(!SN_ROW(rtcp_app_header,p,body))return false;}else return false;at=end;
 }return true;
}
static bool sxnm_rtp(sxnm_view *v)
{
 if(!sxnm_need(v,0,2,v->n))return false;if(v->p[1]>=192&&v->p[1]<=223)return sxnm_rtcp(v);
 if(!SN_ROW(rtp_header,0,v->n))return false;unsigned flags=v->p[0],count=flags&15;size_t at=12,end=v->n;
 for(unsigned i=0;i<count;i++,at+=4)if(!SN_ROW(rtp_csrc,at,end))return false;
 if(flags&16){if(!SN_ROW(rtp_extension_header,at,end))return false;size_t n=(size_t)sxnm_u16(v->p+at+2)*4;at+=4;if(!sxnm_need(v,at,n,end))return false;at+=n;}
 if(flags&32){unsigned n=v->p[end-1];if(!n||n>end-at||!SN_ROW(rtp_padding_count,end-1,end))return false;end-=n;}return at<end;
}
bool sx_rtp_rtcp_build(sxnm_view*v)
{
 return sxnm_rtp(v);
}
#undef SN_ROW
