/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SHRINK_CDAF data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_cdaf_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("form_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form_type","char[4]",8,4,SX_SIGNATURE),
 SX_FIELD("name_chunk","char[4]",12,4,SX_SIGNATURE),
 SX_FIELD("name_size","uint32",16,4,SX_SIZE),
 SX_FIELD("name","char[6]",20,6,SX_NONE),
};
const sx_layout sxaf_cdaf_header = {UINT32_C(0x603c001e),"cdaf_header",sxaf_cdaf_header_fields,SX_COUNT(sxaf_cdaf_header_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_cdaf_member_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("opaque0","uint8",8,1,SX_NONE),
 SX_FIELD("method","uint8",9,1,SX_NONE),
 SX_FIELD("opaque1","uint8[4]",10,4,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",14,4,SX_SIZE),
 SX_FIELD("opaque2","uint8[6]",18,6,SX_NONE),
 SX_FIELD("crc16","uint16",24,2,SX_CHECKSUM),
 SX_FIELD("opaque3","uint8[2]",26,2,SX_NONE),
};
const sx_layout sxaf_cdaf_member = {UINT32_C(0x603c001f),"cdaf_member",sxaf_cdaf_member_fields,SX_COUNT(sxaf_cdaf_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_cdaf_chunk_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxaf_cdaf_chunk = {UINT32_C(0x603c0020),"cdaf_chunk",sxaf_cdaf_chunk_fields,SX_COUNT(sxaf_cdaf_chunk_fields),SX_BE};
static bool sxaf_cdaf(sx_context*c){uint64_t p=26;if(!sxaf_add(c,&sxaf_cdaf_header,0))return false;while(p<(uint64_t)c->size){uint64_t hs,n;uint8_t b[4];if(!sxaf_word(c,p+4,4,true,&hs)||hs<20||hs>65535||!sxaf_add(c,&sxaf_cdaf_member,p))return false;hs-=20;p+=28;if(!sxaf_span(c,p,hs+(hs&1)))return false;p+=hs+(hs&1);if(!sxaf_read(c,p,b,4))return false;if(!xx_rt_memcmp(b,"NOTE",4)){if(!sxaf_word(c,p+4,4,true,&n)||!sxaf_span(c,p+8,n+(n&1))||!sxaf_add(c,&sxaf_cdaf_chunk,p))return false;p+=8+n+(n&1);}if(!sxaf_read(c,p,b,4)||xx_rt_memcmp(b,"BODY",4)||!sxaf_word(c,p+4,4,true,&n)||!sxaf_span(c,p+8,n+(n&1))||!sxaf_add(c,&sxaf_cdaf_chunk,p))return false;p+=8+n+(n&1);}return true;}
bool sx_shrink_cdaf_build(sx_context*c)
{
 return sxaf_cdaf(c);
}
