/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Adobe Director CXT data structures, moved out of the videotail schema family. */
#include "../../xx_format_schema_videotail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvt_director_header_le_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form","char[4]",8,4,SX_ID),
};
const sx_layout sxvt_director_header_le = {UINT32_C(0x60390026),"director_header_le",sxvt_director_header_le_fields,SX_COUNT(sxvt_director_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_chunk_le_fields[] = {
 SX_FIELD("type","char[4]",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxvt_director_chunk_le = {UINT32_C(0x60390027),"director_chunk_le",sxvt_director_chunk_le_fields,SX_COUNT(sxvt_director_chunk_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_header_be_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("form","char[4]",8,4,SX_ID),
};
const sx_layout sxvt_director_header_be = {UINT32_C(0x60390028),"director_header_be",sxvt_director_header_be_fields,SX_COUNT(sxvt_director_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_chunk_be_fields[] = {
 SX_FIELD("type","char[4]",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxvt_director_chunk_be = {UINT32_C(0x60390029),"director_chunk_be",sxvt_director_chunk_be_fields,SX_COUNT(sxvt_director_chunk_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_imap_le_fields[] = {
 SX_FIELD("map_version","uint32",0,4,SX_ID),
 SX_FIELD("mmap_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("director_version","uint32",8,4,SX_ID),
};
const sx_layout sxvt_director_imap_le = {UINT32_C(0x60390081),"director_imap_le",sxvt_director_imap_le_fields,SX_COUNT(sxvt_director_imap_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_mmap_le_fields[] = {
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_size","uint16",2,2,SX_SIZE),
 SX_FIELD("allocated_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("used_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint32[2]",12,8,SX_RESERVED),
 SX_FIELD("first_free_resource_id","int32",20,4,SX_ID),
};
const sx_layout sxvt_director_mmap_le = {UINT32_C(0x60390082),"director_mmap_le",sxvt_director_mmap_le_fields,SX_COUNT(sxvt_director_mmap_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_mmap_entry_le_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("chunk_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("flags","uint16",12,2,SX_FLAGS),
 SX_FIELD("unknown","uint16",14,2,SX_NONE),
 SX_FIELD("next_free_resource_id","uint32",16,4,SX_ID),
};
const sx_layout sxvt_director_mmap_entry_le = {UINT32_C(0x60390083),"director_mmap_entry_le",sxvt_director_mmap_entry_le_fields,SX_COUNT(sxvt_director_mmap_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_key_le_fields[] = {
 SX_FIELD("entry_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_size_secondary","uint16",2,2,SX_SIZE),
 SX_FIELD("allocated_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("used_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxvt_director_key_le = {UINT32_C(0x60390084),"director_key_le",sxvt_director_key_le_fields,SX_COUNT(sxvt_director_key_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_key_entry_le_fields[] = {
 SX_FIELD("child_resource_index","uint32",0,4,SX_ID),
 SX_FIELD("parent_resource_index","uint32",4,4,SX_ID),
 SX_FIELD("child_type","uint32",8,4,SX_ID),
};
const sx_layout sxvt_director_key_entry_le = {UINT32_C(0x60390085),"director_key_entry_le",sxvt_director_key_entry_le_fields,SX_COUNT(sxvt_director_key_entry_le_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_director_imap_be_fields[] = {
 SX_FIELD("map_version","uint32",0,4,SX_ID),
 SX_FIELD("mmap_offset","uint32",4,4,SX_OFFSET),
 SX_FIELD("director_version","uint32",8,4,SX_ID),
};
const sx_layout sxvt_director_imap_be = {UINT32_C(0x60390086),"director_imap_be",sxvt_director_imap_be_fields,SX_COUNT(sxvt_director_imap_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_mmap_be_fields[] = {
 SX_FIELD("header_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_size","uint16",2,2,SX_SIZE),
 SX_FIELD("allocated_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("used_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("reserved","uint32[2]",12,8,SX_RESERVED),
 SX_FIELD("first_free_resource_id","int32",20,4,SX_ID),
};
const sx_layout sxvt_director_mmap_be = {UINT32_C(0x60390087),"director_mmap_be",sxvt_director_mmap_be_fields,SX_COUNT(sxvt_director_mmap_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_mmap_entry_be_fields[] = {
 SX_FIELD("type","uint32",0,4,SX_ID),
 SX_FIELD("body_size","uint32",4,4,SX_SIZE),
 SX_FIELD("chunk_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("flags","uint16",12,2,SX_FLAGS),
 SX_FIELD("unknown","uint16",14,2,SX_NONE),
 SX_FIELD("next_free_resource_id","uint32",16,4,SX_ID),
};
const sx_layout sxvt_director_mmap_entry_be = {UINT32_C(0x60390088),"director_mmap_entry_be",sxvt_director_mmap_entry_be_fields,SX_COUNT(sxvt_director_mmap_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_key_be_fields[] = {
 SX_FIELD("entry_size","uint16",0,2,SX_SIZE),
 SX_FIELD("entry_size_secondary","uint16",2,2,SX_SIZE),
 SX_FIELD("allocated_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("used_count","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxvt_director_key_be = {UINT32_C(0x60390089),"director_key_be",sxvt_director_key_be_fields,SX_COUNT(sxvt_director_key_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_key_entry_be_fields[] = {
 SX_FIELD("child_resource_index","uint32",0,4,SX_ID),
 SX_FIELD("parent_resource_index","uint32",4,4,SX_ID),
 SX_FIELD("child_type","uint32",8,4,SX_ID),
};
const sx_layout sxvt_director_key_entry_be = {UINT32_C(0x6039008a),"director_key_entry_be",sxvt_director_key_entry_be_fields,SX_COUNT(sxvt_director_key_entry_be_fields),SX_BE};
static const xx_data_struct_field_desc sxvt_director_cast_index_fields[] = {
 SX_FIELD("cast_resource_index","uint32",0,4,SX_ID),
};
const sx_layout sxvt_director_cast_index = {UINT32_C(0x6039008b),"director_cast_index",sxvt_director_cast_index_fields,SX_COUNT(sxvt_director_cast_index_fields),SX_BE};
static bool sxvt_dtag(const uint8_t*b,const char*t,bool be){if(!xx_rt_memcmp(b,t,4))return true;return !be&&b[0]==(uint8_t)t[3]&&b[1]==(uint8_t)t[2]&&b[2]==(uint8_t)t[1]&&b[3]==(uint8_t)t[0];}
static bool sxvt_director(sx_context*c){uint8_t h[12];if(!sxvt_read(c,0,h,12))return false;bool be=h[0]=='R';uint64_t end=8+sxvt_uint(h+4,4,be);if(end<12||!sxvt_span(c,0,end)||!sxvt_add(c,be?&sxvt_director_header_be:&sxvt_director_header_le,0))return false;bool plain=!xx_rt_memcmp(h+8,be?"MV93":"39VM",4)||!xx_rt_memcmp(h+8,be?"MC95":"59CM",4);
 for(uint64_t p=12;p<end;){uint8_t b[8];if(end-p<8||!sxvt_read(c,p,b,8))return false;uint64_t n=sxvt_uint(b+4,4,be);if(n>end-p-8||!sxvt_add(c,be?&sxvt_director_chunk_be:&sxvt_director_chunk_le,p))return false;uint64_t q=p+8;if(plain){const sx_layout*l=NULL,*e=NULL;uint64_t hs=0,es=0,count=0;
 if(sxvt_dtag(b,"imap",be)&&n>=12)l=be?&sxvt_director_imap_be:&sxvt_director_imap_le;
 else if(sxvt_dtag(b,"mmap",be)&&n>=24){l=be?&sxvt_director_mmap_be:&sxvt_director_mmap_le;e=be?&sxvt_director_mmap_entry_be:&sxvt_director_mmap_entry_le;if(!sxvt_word(c,q,2,be,&hs)||!sxvt_word(c,q+2,2,be,&es)||!sxvt_word(c,q+8,4,be,&count))return false;if(hs<24||es<20||hs>n||count>(n-hs)/es){e=NULL;} }
 else if(sxvt_dtag(b,"KEY*",be)&&n>=12){l=be?&sxvt_director_key_be:&sxvt_director_key_le;e=be?&sxvt_director_key_entry_be:&sxvt_director_key_entry_le;hs=12;if(!sxvt_word(c,q,2,be,&es)||!sxvt_word(c,q+8,4,be,&count))return false;if(es<12||count>(n-hs)/es)e=NULL;}
 else if(sxvt_dtag(b,"CAS*",be)&&!(n%4)){hs=0;es=4;count=n/4;e=&sxvt_director_cast_index;}
 if(l&&!sxvt_add(c,l,q))return false;if(e){for(uint64_t i=0;i<count;i++)if(!sxvt_add(c,e,q+hs+i*es))return false;}}
 p=q+n;if(n&1){if(p==end)return false;p++;}}
 return true;}
bool sx_adobe_director_cxt_build(sx_context*c)
{
 return sxvt_director(c);
}
