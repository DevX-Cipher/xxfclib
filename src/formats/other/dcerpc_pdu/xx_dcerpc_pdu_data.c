/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DCERPC PDU data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_dcerpc_bind_le_fields[]={
 SX_FIELD("maximum_transmit_fragment","uint16",0,2,SX_SIZE),
 SX_FIELD("maximum_receive_fragment","uint16",2,2,SX_SIZE),
 SX_FIELD("association_group","uint32",4,4,SX_ID),
 SX_FIELD("context_count","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("reserved","bytes",9,3,SX_RESERVED),
};
const sx_layout sxnm_dcerpc_bind_le={UINT32_C(0x60260065),"dcerpc_bind_le",sxnm_dcerpc_bind_le_fields,SX_COUNT(sxnm_dcerpc_bind_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_context_le_fields[]={
 SX_FIELD("context_id","uint16",0,2,SX_ID),
 SX_FIELD("transfer_syntax_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("abstract_syntax_uuid","bytes",4,16,SX_ID),
 SX_FIELD("abstract_syntax_version","uint32",20,4,SX_ID),
};
const sx_layout sxnm_dcerpc_context_le={UINT32_C(0x60260066),"dcerpc_context_le",sxnm_dcerpc_context_le_fields,SX_COUNT(sxnm_dcerpc_context_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_transfer_syntax_le_fields[]={
 SX_FIELD("transfer_syntax_uuid","bytes",0,16,SX_ID),
 SX_FIELD("transfer_syntax_version","uint32",16,4,SX_ID),
};
const sx_layout sxnm_dcerpc_transfer_syntax_le={UINT32_C(0x60260067),"dcerpc_transfer_syntax_le",sxnm_dcerpc_transfer_syntax_le_fields,SX_COUNT(sxnm_dcerpc_transfer_syntax_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnm_dcerpc_bind_be_fields[]={
 SX_FIELD("maximum_transmit_fragment","uint16",0,2,SX_SIZE),
 SX_FIELD("maximum_receive_fragment","uint16",2,2,SX_SIZE),
 SX_FIELD("association_group","uint32",4,4,SX_ID),
 SX_FIELD("context_count","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("reserved","bytes",9,3,SX_RESERVED),
};
const sx_layout sxnm_dcerpc_bind_be={UINT32_C(0x6026006F),"dcerpc_bind_be",sxnm_dcerpc_bind_be_fields,SX_COUNT(sxnm_dcerpc_bind_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_context_be_fields[]={
 SX_FIELD("context_id","uint16",0,2,SX_ID),
 SX_FIELD("transfer_syntax_count","uint8",2,1,SX_COUNT_PROP),
 SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
 SX_FIELD("abstract_syntax_uuid","bytes",4,16,SX_ID),
 SX_FIELD("abstract_syntax_version","uint32",20,4,SX_ID),
};
const sx_layout sxnm_dcerpc_context_be={UINT32_C(0x60260070),"dcerpc_context_be",sxnm_dcerpc_context_be_fields,SX_COUNT(sxnm_dcerpc_context_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_dcerpc_transfer_syntax_be_fields[]={
 SX_FIELD("transfer_syntax_uuid","bytes",0,16,SX_ID),
 SX_FIELD("transfer_syntax_version","uint32",16,4,SX_ID),
};
const sx_layout sxnm_dcerpc_transfer_syntax_be={UINT32_C(0x60260071),"dcerpc_transfer_syntax_be",sxnm_dcerpc_transfer_syntax_be_fields,SX_COUNT(sxnm_dcerpc_transfer_syntax_be_fields),SX_BE};
static bool sxnm_rpc(sxnm_view *v)
{
 if(!sxnm_need(v,0,16,v->n))return false;bool be=v->p[4]!=16;unsigned type=v->p[2];if(!sxnm_row(v,be?&sxnm_dcerpc_header_be:&sxnm_dcerpc_header_le,0,v->n)||xx_data_get_u16(v->p+8,2,0,be)!=v->n)return false;
 if(type==0||type==2)return sxnm_row(v,type==0?(be?&sxnm_dcerpc_request_be:&sxnm_dcerpc_request_le):(be?&sxnm_dcerpc_response_be:&sxnm_dcerpc_response_le),16,v->n);
 if(type!=11||!sxnm_row(v,be?&sxnm_dcerpc_bind_be:&sxnm_dcerpc_bind_le,16,v->n))return false;unsigned count=v->p[24];size_t at=28;
 for(unsigned i=0;i<count;i++){if(!sxnm_row(v,be?&sxnm_dcerpc_context_be:&sxnm_dcerpc_context_le,at,v->n))return false;unsigned n=v->p[at+2];at+=24;for(unsigned j=0;j<n;j++,at+=20)if(!sxnm_row(v,be?&sxnm_dcerpc_transfer_syntax_be:&sxnm_dcerpc_transfer_syntax_le,at,v->n))return false;}return at==v->n;
}
bool sx_dcerpc_pdu_build(sxnm_view*v)
{
 return sxnm_rpc(v);
}
