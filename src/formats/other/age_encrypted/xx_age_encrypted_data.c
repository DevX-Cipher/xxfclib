/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * age_encrypted data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_recipient_type_fields[]={
 SX_FIELD("recipient_type","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_recipient_type={0x6071001dU,"textwire_recipient_type",sxtw_recipient_type_fields,SX_COUNT(sxtw_recipient_type_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_encoded_public_key_fields[]={
 SX_FIELD("encoded_public_key","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_encoded_public_key={0x6071001eU,"textwire_encoded_public_key",sxtw_encoded_public_key_fields,SX_COUNT(sxtw_encoded_public_key_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_encoded_wrapped_key_fields[]={
 SX_FIELD("encoded_wrapped_key","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_encoded_wrapped_key={0x6071001fU,"textwire_encoded_wrapped_key",sxtw_encoded_wrapped_key_fields,SX_COUNT(sxtw_encoded_wrapped_key_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_encoded_header_mac_fields[]={
 SX_FIELD("encoded_header_mac","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_encoded_header_mac={0x60710020U,"textwire_encoded_header_mac",sxtw_encoded_header_mac_fields,SX_COUNT(sxtw_encoded_header_mac_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_binary_nonce_fields[]={
 SX_FIELD("nonce","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxtw_binary_nonce={0x60710046U,"textwire_binary_nonce",sxtw_binary_nonce_fields,SX_COUNT(sxtw_binary_nonce_fields),SX_LE};
#define TW_EMIT(n,a,z) do{if(!sxtw_emit(q,&sxtw_##n,(a),(z)))return false;}while(0)
static bool sxtw_age(sxtw_cursor*q)
{
 int64_t a,end;if(!sxtw_line(q,&a,&end))return false;TW_EMIT(signature,a,end-a);
 while(sxtw_line(q,&a,&end)){
  if(q->c->count>=32000)return true;
  if(end-a>=4&&sxtw_eq(q,a,4,"--- ")){TW_EMIT(encoded_header_mac,a+4,end-a-4);if(q->n-q->p<16)return false;TW_EMIT(binary_nonce,q->p,16);return true;}
  if(end-a<10||!sxtw_eq(q,a,3,"-> "))return false;int64_t p=a+3;while(p<end&&q->b[p]!=' ')p++;TW_EMIT(recipient_type,a+3,p-a-3);if(p==end)return false;TW_EMIT(encoded_public_key,p+1,end-p-1);if(!sxtw_line(q,&a,&end))return false;TW_EMIT(encoded_wrapped_key,a,end-a);
 }return false;
}
bool sx_age_encrypted_build(sxtw_cursor*q)
{
 return sxtw_age(q);
}
#undef TW_EMIT
