/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * jose_jws data structures, moved out of the textwire schema family. */
#include "../../xx_format_schema_textwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxtw_base64url_header_fields[]={
 SX_FIELD("base64url_header","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_base64url_header={0x60710011U,"textwire_base64url_header",sxtw_base64url_header_fields,SX_COUNT(sxtw_base64url_header_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_base64url_payload_fields[]={
 SX_FIELD("base64url_payload","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_base64url_payload={0x60710012U,"textwire_base64url_payload",sxtw_base64url_payload_fields,SX_COUNT(sxtw_base64url_payload_fields),SX_LE};
static const xx_data_struct_field_desc sxtw_base64url_signature_fields[]={
 SX_FIELD("base64url_signature","utf8",0,0,SX_STRING),
};
const sx_layout sxtw_base64url_signature={0x60710013U,"textwire_base64url_signature",sxtw_base64url_signature_fields,SX_COUNT(sxtw_base64url_signature_fields),SX_LE};
static bool sxtw_jws(sxtw_cursor*q)
{
 const sx_layout*l[]={&sxtw_base64url_header,&sxtw_base64url_payload,&sxtw_base64url_signature};for(unsigned i=0;i<3;i++){int64_t a=q->p;while(q->p<q->n&&q->b[q->p]!='.')q->p++;if(!sxtw_emit(q,l[i],a,q->p-a))return false;if(i<2){if(q->p==q->n)return false;q->p++;}}return q->p==q->n;
}
bool sx_jose_jws_build(sxtw_cursor*q)
{
 return sxtw_jws(q);
}
