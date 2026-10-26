/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_cia data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_cia_header_fields[]={
 SX_FIELD("header_size","uint32",0,4,SX_SIZE),
 SX_FIELD("type","uint16",4,2,SX_ID),
 SX_FIELD("version","uint16",6,2,SX_ID),
 SX_FIELD("certificates_size","uint32",8,4,SX_SIZE),
 SX_FIELD("ticket_size","uint32",12,4,SX_SIZE),
 SX_FIELD("tmd_size","uint32",16,4,SX_SIZE),
 SX_FIELD("metadata_size","uint32",20,4,SX_SIZE),
 SX_FIELD("content_size","uint64",24,8,SX_SIZE),
 SX_FIELD("content_index_bitmap","bytes",32,8192,SX_FLAGS),
};
const sx_layout sxgp_cia_header={UINT32_C(0x6036008A),"cia_header",sxgp_cia_header_fields,SX_COUNT(sxgp_cia_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_cia_signature_fields[]={
 SX_FIELD("signature_type","uint32",0,4,SX_ID),
 SX_FIELD("signature","bytes",4,256,SX_SIGNATURE),
 SX_FIELD("padding","bytes",260,60,SX_RESERVED),
};
const sx_layout sxgp_cia_signature={UINT32_C(0x6036008B),"cia_signature",sxgp_cia_signature_fields,SX_COUNT(sxgp_cia_signature_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_cia_tmd_fields[]={
 SX_FIELD("issuer","char[64]",0,64,SX_STRING),
 SX_FIELD("version","uint8",64,1,SX_ID),
 SX_FIELD("ca_crl_version","uint8",65,1,SX_ID),
 SX_FIELD("signer_crl_version","uint8",66,1,SX_ID),
 SX_FIELD("reserved","uint8",67,1,SX_RESERVED),
 SX_FIELD("system_version","uint64",68,8,SX_ID),
 SX_FIELD("title_id","uint64",76,8,SX_ID),
 SX_FIELD("title_type","uint32",84,4,SX_FLAGS),
 SX_FIELD("group_id","uint16",88,2,SX_ID),
 SX_FIELD("save_data_size","uint32le",90,4,SX_SIZE),
 SX_FIELD("private_save_data_size","uint32le",94,4,SX_SIZE),
 SX_FIELD("reserved2","bytes",98,4,SX_RESERVED),
 SX_FIELD("twl_flag","uint8",102,1,SX_FLAGS),
 SX_FIELD("reserved3","bytes",103,49,SX_RESERVED),
 SX_FIELD("access_rights","uint32",152,4,SX_FLAGS),
 SX_FIELD("title_version","uint16",156,2,SX_ID),
 SX_FIELD("content_count","uint16",158,2,SX_COUNT_PROP),
 SX_FIELD("boot_content","uint16",160,2,SX_ID),
 SX_FIELD("reserved4","uint16",162,2,SX_RESERVED),
 SX_FIELD("content_info_sha256","bytes",164,32,SX_CHECKSUM),
};
const sx_layout sxgp_cia_tmd={UINT32_C(0x6036008C),"cia_tmd",sxgp_cia_tmd_fields,SX_COUNT(sxgp_cia_tmd_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_cia_content_info_fields[]={
 SX_FIELD("index_offset","uint16",0,2,SX_ID),
 SX_FIELD("content_count","uint16",2,2,SX_COUNT_PROP),
 SX_FIELD("sha256","bytes",4,32,SX_CHECKSUM),
};
const sx_layout sxgp_cia_content_info={UINT32_C(0x6036008D),"cia_content_info",sxgp_cia_content_info_fields,SX_COUNT(sxgp_cia_content_info_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_cia_content_fields[]={
 SX_FIELD("content_id","uint32",0,4,SX_ID),
 SX_FIELD("content_index","uint16",4,2,SX_ID),
 SX_FIELD("type","uint16",6,2,SX_FLAGS),
 SX_FIELD("content_size","uint64",8,8,SX_SIZE),
 SX_FIELD("sha256","bytes",16,32,SX_CHECKSUM),
};
const sx_layout sxgp_cia_content={UINT32_C(0x6036008E),"cia_content",sxgp_cia_content_fields,SX_COUNT(sxgp_cia_content_fields),SX_BE};
static const xx_data_struct_field_desc sxgp_cia_metadata_fields[]={
 SX_FIELD("dependencies","bytes",0,384,SX_ID),
 SX_FIELD("reserved","bytes",384,384,SX_RESERVED),
 SX_FIELD("core_version","uint32",768,4,SX_ID),
 SX_FIELD("reserved2","bytes",772,252,SX_RESERVED),
};
const sx_layout sxgp_cia_metadata={UINT32_C(0x6036008F),"cia_metadata",sxgp_cia_metadata_fields,SX_COUNT(sxgp_cia_metadata_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_cia(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,tmd=0x2dc0,ts,ms,cs,n,meta;if(!SG_ROW(cia_header,0,end)||!sxgp_word(v,16,4,false,&ts,end)||!sxgp_word(v,20,4,false,&ms,end)||!sxgp_word(v,24,8,false,&cs,end)||!sxgp_span(v,tmd,ts,end))return false;
 uint64_t stop=tmd+ts;if(!SG_ROW(cia_signature,tmd,stop)||!SG_ROW(cia_tmd,tmd+0x140,stop)||!sxgp_table(v,&sxgp_cia_content_info,tmd+0x204,64,stop)||!sxgp_word(v,tmd+0x1de,2,true,&n,stop)||n>1024||!sxgp_table(v,&sxgp_cia_content,tmd+0xb04,n,stop))return false;
 uint64_t content=(stop+63)&~UINT64_C(63);if(!sxgp_span(v,content,cs,end))return false;meta=(content+cs+63)&~UINT64_C(63);return !ms||(sxgp_span(v,meta,ms,end)&&SG_ROW(cia_metadata,meta,meta+ms));}
bool sx_nintendo_cia_build(sxgp_view*v)
{
 return sxgp_cia(v);
}
#undef SG_ROW
