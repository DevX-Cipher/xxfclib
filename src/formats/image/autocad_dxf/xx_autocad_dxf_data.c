/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * autocad_dxf data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_dxf_signature_fields[]={
 SX_FIELD("signature","char[22]",0,22,SX_SIGNATURE),
};
const sx_layout sxmt_dxf_signature={0x60520077U,"modeltext_dxf_signature",sxmt_dxf_signature_fields,SX_COUNT(sxmt_dxf_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_group_code_fields[]={
 SX_FIELD("group_code","uint16",0,2,SX_ID),
};
const sx_layout sxmt_dxf_group_code={0x60520078U,"modeltext_dxf_group_code",sxmt_dxf_group_code_fields,SX_COUNT(sxmt_dxf_group_code_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_int8_fields[]={
 SX_FIELD("value","int8",0,1,SX_NONE),
};
const sx_layout sxmt_dxf_int8={0x60520079U,"modeltext_dxf_int8",sxmt_dxf_int8_fields,SX_COUNT(sxmt_dxf_int8_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_int16_fields[]={
 SX_FIELD("value","int16",0,2,SX_NONE),
};
const sx_layout sxmt_dxf_int16={0x6052007aU,"modeltext_dxf_int16",sxmt_dxf_int16_fields,SX_COUNT(sxmt_dxf_int16_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_int32_fields[]={
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxmt_dxf_int32={0x6052007bU,"modeltext_dxf_int32",sxmt_dxf_int32_fields,SX_COUNT(sxmt_dxf_int32_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_int64_fields[]={
 SX_FIELD("value","int64",0,8,SX_NONE),
};
const sx_layout sxmt_dxf_int64={0x6052007cU,"modeltext_dxf_int64",sxmt_dxf_int64_fields,SX_COUNT(sxmt_dxf_int64_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_double_fields[]={
 SX_FIELD("value","double",0,8,SX_NONE),
};
const sx_layout sxmt_dxf_double={0x6052007dU,"modeltext_dxf_double",sxmt_dxf_double_fields,SX_COUNT(sxmt_dxf_double_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_dxf_chunk_length_fields[]={
 SX_FIELD("binary_chunk_length","uint8",0,1,SX_SIZE),
};
const sx_layout sxmt_dxf_chunk_length={0x6052007eU,"modeltext_dxf_chunk_length",sxmt_dxf_chunk_length_fields,SX_COUNT(sxmt_dxf_chunk_length_fields),SX_LE};
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)
static bool sxmt_dxf(sxmt_cursor*q){if(q->n<22)return false;MT_EMIT(dxf_signature,0,22);q->p=22;while(q->p<q->n){if(q->c->count>=32000)return true;if(q->n-q->p<2)return false;unsigned code=xx_data_get_u16(q->b+q->p,2,0,false),kind=255;MT_EMIT(dxf_group_code,q->p,2);q->p+=2;
 if((code>=10&&code<=59)||(code>=110&&code<=149)||(code>=210&&code<=239)||(code>=460&&code<=469)||(code>=1010&&code<=1059))kind=8;
 else if((code>=60&&code<=79)||(code>=170&&code<=179)||(code>=270&&code<=289)||(code>=370&&code<=389)||(code>=400&&code<=409)||code==1060||code==1070)kind=2;
 else if((code>=90&&code<=99)||(code>=420&&code<=429)||(code>=440&&code<=459)||code==1071)kind=4;
 else if(code>=160&&code<=169)kind=9;else if(code>=290&&code<=299)kind=1;else if((code>=310&&code<=319)||code==1004)kind=3;
 else if(code<=9||(code>=100&&code<=102)||code==105||(code>=300&&code<=309)||(code>=320&&code<=369)||(code>=390&&code<=399)||(code>=410&&code<=419)||(code>=430&&code<=439)||(code>=470&&code<=481)||code==999||(code>=1000&&code<=1009))kind=0;
 if(kind==255)return false;if(!kind){int64_t a=q->p;while(q->p<q->n&&q->b[q->p])q->p++;if(q->p==q->n)return false;MT_EMIT(string_value,a,q->p-a);q->p++;}
 else if(kind==3){if(q->p==q->n)return false;unsigned n=q->b[q->p];MT_EMIT(dxf_chunk_length,q->p,1);q->p++;if(n>(uint64_t)(q->n-q->p))return false;q->p+=n;}
 else {const sx_layout*l=kind==1?&sxmt_dxf_int8:kind==2?&sxmt_dxf_int16:kind==4?&sxmt_dxf_int32:kind==9?&sxmt_dxf_int64:&sxmt_dxf_double;unsigned w=kind==9?8:kind;if(!sxmt_emit(q,l,q->p,w))return false;q->p+=w;}}
 return true;}
bool sx_autocad_dxf_build(sxmt_cursor*q)
{
 return sxmt_dxf(q);
}
#undef MT_EMIT
