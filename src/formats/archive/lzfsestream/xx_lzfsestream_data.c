/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LZFSE stream data structures, moved out of the archivemore schema family. */
#include "../../xx_format_schema_archivemore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxar_lzfse_raw_block_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxar_lzfse_raw_block = {UINT32_C(0x601c0026),"lzfse_raw_block",sxar_lzfse_raw_block_fields,SX_COUNT(sxar_lzfse_raw_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzfse_lzvn_block_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxar_lzfse_lzvn_block = {UINT32_C(0x601c0027),"lzfse_lzvn_block",sxar_lzfse_lzvn_block_fields,SX_COUNT(sxar_lzfse_lzvn_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzfse_v1_block_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",8,4,SX_SIZE),
    SX_FIELD("literal_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("match_count","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("literal_payload_size","uint32",20,4,SX_SIZE),
    SX_FIELD("lmd_payload_size","uint32",24,4,SX_SIZE),
    SX_FIELD("literal_bits","int32",28,4,SX_NONE),
    SX_FIELD("literal_states","uint16[4]",32,8,SX_NONE),
    SX_FIELD("lmd_bits","int32",40,4,SX_NONE),
    SX_FIELD("l_state","uint16",44,2,SX_NONE),
    SX_FIELD("m_state","uint16",46,2,SX_NONE),
    SX_FIELD("d_state","uint16",48,2,SX_NONE),
    SX_FIELD("l_frequencies","uint16[20]",50,40,SX_NONE),
    SX_FIELD("m_frequencies","uint16[20]",90,40,SX_NONE),
    SX_FIELD("d_frequencies","uint16[64]",130,128,SX_NONE),
    SX_FIELD("literal_frequencies","uint16[256]",258,512,SX_NONE),
    SX_FIELD("alignment_padding","uint16",770,2,SX_RESERVED),
};
const sx_layout sxar_lzfse_v1_block = {UINT32_C(0x601c0028),"lzfse_v1_block",sxar_lzfse_v1_block_fields,SX_COUNT(sxar_lzfse_v1_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzfse_v2_block_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unpacked_size","uint32",4,4,SX_SIZE),
    SX_FIELD("packed_fields0","uint64",8,8,SX_NONE),
    SX_FIELD("packed_fields1","uint64",16,8,SX_NONE),
    SX_FIELD("packed_fields2","uint64",24,8,SX_NONE),
};
const sx_layout sxar_lzfse_v2_block = {UINT32_C(0x601c0029),"lzfse_v2_block",sxar_lzfse_v2_block_fields,SX_COUNT(sxar_lzfse_v2_block_fields),SX_LE};
static const xx_data_struct_field_desc sxar_lzfse_end_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxar_lzfse_end = {UINT32_C(0x601c002a),"lzfse_end",sxar_lzfse_end_fields,SX_COUNT(sxar_lzfse_end_fields),SX_LE};
#define SXAR_LIMIT 20000U
static bool sxar_lzfse(sx_context *c){uint64_t p=0;for(unsigned i=0;i<SXAR_LIMIT&&p<(uint64_t)c->size;i++){uint8_t b[32];if(!sxar_read(c,p,b,4))break;const sx_layout *l=NULL;uint64_t head=0,payload=0;
 if(!xx_rt_memcmp(b,"bvx$",4)){if(!sxar_add(c,&sxar_lzfse_end,p))return false;break;}
 if(!xx_rt_memcmp(b,"bvx-",4)){head=8;if(!sxar_read(c,p,b,8))break;payload=sxar32(b+4,false);l=&sxar_lzfse_raw_block;}
 else if(!xx_rt_memcmp(b,"bvxn",4)){head=12;if(!sxar_read(c,p,b,12))break;payload=sxar32(b+8,false);l=&sxar_lzfse_lzvn_block;}
 else if(!xx_rt_memcmp(b,"bvx1",4)){head=772;if(!sxar_read(c,p,b,28))break;payload=(uint64_t)sxar32(b+20,false)+sxar32(b+24,false);l=&sxar_lzfse_v1_block;}
 else if(!xx_rt_memcmp(b,"bvx2",4)){if(!sxar_read(c,p,b,32))break;head=sxar32(b+24,false);if(head<32||head>752)break;payload=((sxar64(b+8)>>20)&0xfffff)+((sxar64(b+16)>>40)&0xfffff);l=&sxar_lzfse_v2_block;}else break;
 if(!sxar_span(c,p,head+payload))break;if(!sxar_add(c,l,p))return false;p+=head+payload;}return c->count!=0;}
bool sx_lzfsestream_build(sx_context*c)
{
 return sxar_lzfse(c);
}
