/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * capnproto message data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_capnp_segment_table_fields[] = {
 SX_FIELD("segment_count_minus_one","uint32",0,4,SX_NONE),
 SX_FIELD("segment_words","uint32",4,4,SX_NONE),
};
const sx_layout sxbx_capnp_segment_table = {UINT32_C(0x60300068),"capnp_segment_table",sxbx_capnp_segment_table_fields,SX_COUNT(sxbx_capnp_segment_table_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_capnp_struct_pointer_fields[] = {
 SX_FIELD("offset_and_kind","uint32",0,4,SX_FLAGS),
 SX_FIELD("data_word_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("pointer_count","uint16",6,2,SX_COUNT_PROP),
};
const sx_layout sxbx_capnp_struct_pointer = {UINT32_C(0x60300069),"capnp_struct_pointer",sxbx_capnp_struct_pointer_fields,SX_COUNT(sxbx_capnp_struct_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_capnp_list_pointer_fields[] = {
 SX_FIELD("offset_and_kind","uint32",0,4,SX_FLAGS),
 SX_FIELD("count_and_element_size","uint32",4,4,SX_FLAGS),
};
const sx_layout sxbx_capnp_list_pointer = {UINT32_C(0x6030006a),"capnp_list_pointer",sxbx_capnp_list_pointer_fields,SX_COUNT(sxbx_capnp_list_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_capnp_composite_tag_fields[] = {
 SX_FIELD("element_count_and_kind","uint32",0,4,SX_FLAGS),
 SX_FIELD("data_word_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("pointer_count","uint16",6,2,SX_COUNT_PROP),
};
const sx_layout sxbx_capnp_composite_tag = {UINT32_C(0x6030006b),"capnp_composite_tag",sxbx_capnp_composite_tag_fields,SX_COUNT(sxbx_capnp_composite_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_capnp_null_pointer_fields[] = {
 SX_FIELD("null_pointer","uint64",0,8,SX_NONE),
};
const sx_layout sxbx_capnp_null_pointer = {UINT32_C(0x6030006c),"capnp_null_pointer",sxbx_capnp_null_pointer_fields,SX_COUNT(sxbx_capnp_null_pointer_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_cap_pointer(sx_context*c,uint64_t word,uint64_t words,unsigned depth,unsigned*work){if(depth>32||++*work>65536||c->count>=SXBX_LIMIT||word>=words)return true;uint64_t p=8+word*8,v;if(!sxbx_word(c,p,8,false,&v))return false;if(!sxbx_free(c,p,8))return true;if(!v)return sxbx_add(c,&sxbx_capnp_null_pointer,p);unsigned type=(unsigned)v&3;if(type>1)return true;if(!sxbx_add(c,type?&sxbx_capnp_list_pointer:&sxbx_capnp_struct_pointer,p))return false;int64_t disp=(int32_t)(uint32_t)v/4;/* arithmetic shift for negative 30-bit word offsets, without implementation-defined shifts */if((uint32_t)v&0x80000000U)disp=((int64_t)(int32_t)(uint32_t)v-3)/4;int64_t target=(int64_t)word+1+disp;if(target<0||(uint64_t)target>words)return true;uint64_t at=(uint64_t)target;if(!type){uint64_t data=(v>>32)&65535,ptrs=v>>48;if(data+ptrs>words-at)return true;for(uint64_t i=0;i<ptrs&&c->count<SXBX_LIMIT;i++)if(!sxbx_cap_pointer(c,at+data+i,words,depth+1,work))return false;}else{unsigned size=(unsigned)(v>>32)&7;uint64_t n=v>>35;if(size==6){if(n>words-at)return true;for(uint64_t i=0;i<n&&c->count<SXBX_LIMIT;i++)if(!sxbx_cap_pointer(c,at+i,words,depth+1,work))return false;}else if(size==7){uint64_t tag;if(at>=words||n>words-at-1||!sxbx_word(c,8+at*8,8,false,&tag)||(tag&3))return true;uint64_t elems=(uint32_t)tag>>2,data=(tag>>32)&65535,ptrs=tag>>48;if(elems>1048576||elems*(data+ptrs)!=n)return true;if(!sxbx_add(c,&sxbx_capnp_composite_tag,8+at*8))return false;for(uint64_t i=0;i<elems&&c->count<SXBX_LIMIT;i++)for(uint64_t j=0;j<ptrs&&c->count<SXBX_LIMIT;j++)if(!sxbx_cap_pointer(c,at+1+i*(data+ptrs)+data+j,words,depth+1,work))return false;}}return true;}
static bool sxbx_capnp(sx_context*c){uint64_t n;if(!sxbx_add(c,&sxbx_capnp_segment_table,0)||!sxbx_word(c,4,4,false,&n)||n>1048576||!sxbx_span(c,8,n*8))return false;unsigned work=0;return sxbx_cap_pointer(c,0,n,0,&work);}
bool sx_capnproto_message_build(sx_context*c)
{
 return sxbx_capnp(c);
}
