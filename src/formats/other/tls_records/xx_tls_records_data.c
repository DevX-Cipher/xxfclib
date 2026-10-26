/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TLS RECORDS data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_tls_hello_prefix_fields[]={
 SX_FIELD("legacy_version","uint16",0,2,SX_ID),
 SX_FIELD("random","bytes",2,32,SX_NONE),
};
const sx_layout sxnm_tls_hello_prefix={UINT32_C(0x60260026),"tls_hello_prefix",sxnm_tls_hello_prefix_fields,SX_COUNT(sxnm_tls_hello_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_session_id_length_fields[]={
 SX_FIELD("session_id_length","uint8",0,1,SX_SIZE),
};
const sx_layout sxnm_tls_session_id_length={UINT32_C(0x60260027),"tls_session_id_length",sxnm_tls_session_id_length_fields,SX_COUNT(sxnm_tls_session_id_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_cipher_suites_length_fields[]={
 SX_FIELD("cipher_suites_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxnm_tls_cipher_suites_length={UINT32_C(0x60260028),"tls_cipher_suites_length",sxnm_tls_cipher_suites_length_fields,SX_COUNT(sxnm_tls_cipher_suites_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_compression_methods_length_fields[]={
 SX_FIELD("compression_methods_length","uint8",0,1,SX_SIZE),
};
const sx_layout sxnm_tls_compression_methods_length={UINT32_C(0x6026002A),"tls_compression_methods_length",sxnm_tls_compression_methods_length_fields,SX_COUNT(sxnm_tls_compression_methods_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_extensions_length_fields[]={
 SX_FIELD("extensions_length","uint16",0,2,SX_SIZE),
};
const sx_layout sxnm_tls_extensions_length={UINT32_C(0x6026002C),"tls_extensions_length",sxnm_tls_extensions_length_fields,SX_COUNT(sxnm_tls_extensions_length_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_tls_change_cipher_spec_fields[]={
 SX_FIELD("compatibility_value","uint8",0,1,SX_ID),
};
const sx_layout sxnm_tls_change_cipher_spec={UINT32_C(0x6026002E),"tls_change_cipher_spec",sxnm_tls_change_cipher_spec_fields,SX_COUNT(sxnm_tls_change_cipher_spec_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_tls_hello(sxnm_view *v,size_t at,size_t end,unsigned type)
{
 if(!SN_ROW(tls_hello_prefix,at,end))return false;at+=34;if(!SN_ROW(tls_session_id_length,at,end))return false;size_t n=v->p[at++];if(!sxnm_need(v,at,n,end))return false;at+=n;
 if(type==1){if(!SN_ROW(tls_cipher_suites_length,at,end))return false;n=sxnm_u16(v->p+at);at+=2;if(n%2||!sxnm_need(v,at,n,end))return false;size_t ce=at+n;for(;at<ce;at+=2)if(!SN_ROW(tls_cipher_suite,at,ce))return false;
  if(!SN_ROW(tls_compression_methods_length,at,end))return false;n=v->p[at++];if(!sxnm_need(v,at,n,end))return false;size_t ce2=at+n;for(;at<ce2;at++)if(!SN_ROW(tls_compression_method,at,ce2))return false;
 }else if(type==2){if(!SN_ROW(tls_cipher_suite,at,end)||!SN_ROW(tls_compression_method,at+2,end))return false;at+=3;}else return false;
 if(!SN_ROW(tls_extensions_length,at,end))return false;n=sxnm_u16(v->p+at);at+=2;if(n!=end-at)return false;
 while(at<end){if(!SN_ROW(tls_extension_header,at,end))return false;n=sxnm_u16(v->p+at+2);at+=4;if(!sxnm_need(v,at,n,end))return false;at+=n;}return true;
}
static bool sxnm_tls(sxnm_view *v)
{
 size_t at=0;
 while(at<v->n){if(!SN_ROW(tls_record_header,at,v->n))return false;unsigned type=v->p[at];size_t n=sxnm_u16(v->p+at+3);at+=5;if(!sxnm_need(v,at,n,v->n))return false;size_t end=at+n;
  if(type==22){size_t p=at;while(p<end){if(!SN_ROW(tls_handshake_header,p,end))return false;unsigned ht=v->p[p];size_t hn=sxnm_u24(v->p+p+1);p+=4;if(!sxnm_need(v,p,hn,end)||!sxnm_tls_hello(v,p,p+hn,ht))return false;p+=hn;}}
  else if(type==20){if(n!=1||!SN_ROW(tls_change_cipher_spec,at,end))return false;}else if(type!=23)return false;at=end;
 }return true;
}
bool sx_tls_records_build(sxnm_view*v)
{
 return sxnm_tls(v);
}
#undef SN_ROW
