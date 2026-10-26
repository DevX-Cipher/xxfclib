/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IGF2 data structures, moved out of the archivesystems schema family. */
#include "../../xx_format_schema_archivesystems.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxasy_igf2_header_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("opaque1","uint8[6]",2,6,SX_NONE),
 SX_FIELD("container_size","int32",8,4,SX_SIZE),
 SX_FIELD("positive_count_word","int32",12,4,SX_NONE),
 SX_FIELD("opaque2","uint8[16]",16,16,SX_NONE),
 SX_FIELD("first_record_offset","uint32",32,4,SX_OFFSET),
 SX_FIELD("complemented_record_offset","uint32_ones_le",36,4,SX_OFFSET),
};
const sx_layout sxasy_igf2_header = {UINT32_C(0x60440012),"igf2_header",sxasy_igf2_header_fields,SX_COUNT(sxasy_igf2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_igf2_member56_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("tag","uint16",2,2,SX_NONE),
 SX_FIELD("opaque1","uint8[16]",4,16,SX_NONE),
 SX_FIELD("file_time","uint32",20,4,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",24,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",28,4,SX_SIZE),
 SX_FIELD("opaque3","uint8[4]",32,4,SX_NONE),
 SX_FIELD("compressed_size","int32",36,4,SX_SIZE),
 SX_FIELD("opaque4","uint8[16]",40,16,SX_NONE),
};
const sx_layout sxasy_igf2_member56 = {UINT32_C(0x60440013),"igf2_member56",sxasy_igf2_member56_fields,SX_COUNT(sxasy_igf2_member56_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_igf2_member44_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("tag","uint16",2,2,SX_NONE),
 SX_FIELD("opaque1","uint8[12]",4,12,SX_NONE),
 SX_FIELD("file_time","uint32",16,4,SX_NONE),
 SX_FIELD("opaque2","uint8[4]",20,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",24,4,SX_SIZE),
 SX_FIELD("opaque3","uint8[4]",28,4,SX_NONE),
 SX_FIELD("compressed_size","int32",32,4,SX_SIZE),
 SX_FIELD("opaque4","uint8[8]",36,8,SX_NONE),
};
const sx_layout sxasy_igf2_member44 = {UINT32_C(0x60440014),"igf2_member44",sxasy_igf2_member44_fields,SX_COUNT(sxasy_igf2_member44_fields),SX_LE};
static const xx_data_struct_field_desc sxasy_igf2_end_fields[] = {
 SX_FIELD("signature","uint16",0,2,SX_SIGNATURE),
 SX_FIELD("end_tag","uint16",2,2,SX_SIGNATURE),
};
const sx_layout sxasy_igf2_end = {UINT32_C(0x60440015),"igf2_end",sxasy_igf2_end_fields,SX_COUNT(sxasy_igf2_end_fields),SX_LE};
static bool sxasy_igf2_scan(sx_context*c,uint64_t start,unsigned hs,bool emit,uint64_t*count,bool*ended){uint64_t p=start;*count=0;*ended=false;for(unsigned i=0;i<65537;i++){uint8_t b[56];if(!sxasy_read(c,p,b,4))return false;if(sxasy_uint(b+2,2,false)==65535){*ended=true;return !emit||sxasy_add(c,&sxasy_igf2_end,p);}if(!sxasy_read(c,p,b,56)||sxasy_uint(b,2,false)!=0xecdb)return false;unsigned packedoff=hs==56?36:32,plainoff=hs==56?28:24;uint64_t z=sxasy_uint(b+packedoff,4,false),plain=sxasy_uint(b+plainoff,4,false),q=p+hs;if(z>INT32_MAX||plain>INT32_MAX||!sxasy_zstr(c,&q,(uint64_t)c->size,1024)||q==p+hs+1)return false;uint64_t relative=(q-p+4)&~UINT64_C(3);if(!sxasy_span(c,p,relative)||!sxasy_span(c,p+relative,z))return false;if(emit&&!sxasy_add(c,hs==56?&sxasy_igf2_member56:&sxasy_igf2_member44,p))return false;(*count)++;p+=relative+z;}return false;}
static bool sxasy_igf2(sx_context*c){uint64_t p,a,b;bool ae,be;if(!sxasy_word(c,32,4,false,&p)||p<40||!sxasy_add(c,&sxasy_igf2_header,0))return false;(void)sxasy_igf2_scan(c,p,56,false,&a,&ae);unsigned hs=56;if(!ae){(void)sxasy_igf2_scan(c,p,44,false,&b,&be);if(be||b>a)hs=44;}return sxasy_igf2_scan(c,p,hs,true,&a,&ae);}
bool sx_igf2_build(sx_context*c)
{
 return sxasy_igf2(c);
}
