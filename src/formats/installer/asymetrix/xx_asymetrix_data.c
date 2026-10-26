/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ASYMETRIX data structures, moved out of the archiveextras schema family. */
#include "../../xx_format_schema_archiveextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxae_asymetrix_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("record_stride","uint32",4,4,SX_SIZE),
    SX_FIELD("set_name","char[9]",8,9,SX_STRING),
    SX_FIELD("opaque_metadata","uint8[23]",17,23,SX_NONE),
    SX_FIELD("volume_number","uint16",40,2,SX_ID),
    SX_FIELD("member_count","uint16",42,2,SX_COUNT_PROP),
};
const sx_layout sxae_asymetrix_header = {UINT32_C(0x6017002e),"asymetrix_header",sxae_asymetrix_header_fields,SX_COUNT(sxae_asymetrix_header_fields),SX_LE};
static const xx_data_struct_field_desc sxae_asymetrix_member_fields[] = {
    SX_FIELD("name","char[13]",0,13,SX_STRING),
    SX_FIELD("writer_bytes","uint8[17]",13,17,SX_NONE),
    SX_FIELD("volume_word","uint32",30,4,SX_NONE),
    SX_FIELD("data_offset","uint32",34,4,SX_OFFSET),
    SX_FIELD("unpacked_size","uint32",38,4,SX_SIZE),
    SX_FIELD("writer_bytes2","uint8[56]",42,56,SX_NONE),
    SX_FIELD("date","uint16",98,2,SX_NONE),
    SX_FIELD("time","uint16",100,2,SX_NONE),
    SX_FIELD("attributes","uint16",102,2,SX_FLAGS),
    SX_FIELD("crc32","uint32",104,4,SX_CHECKSUM),
};
const sx_layout sxae_asymetrix_member = {UINT32_C(0x6017002f),"asymetrix_member",sxae_asymetrix_member_fields,SX_COUNT(sxae_asymetrix_member_fields),SX_LE};
static const xx_data_struct_field_desc sxae_asymetrix_block_fields[] = {
    SX_FIELD("method","uint16",0,2,SX_ID),
    SX_FIELD("packed_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxae_asymetrix_block = {UINT32_C(0x60170030),"asymetrix_block",sxae_asymetrix_block_fields,SX_COUNT(sxae_asymetrix_block_fields),SX_LE};
static bool sxae_asymetrix(sx_context *c)
{
 uint8_t h[44];if(!sx_read(c,0,h,44)||sxae32(h)!=UINT32_C(0x63132260)||sxae32(h+4)!=108||!sxae_add(c,&sxae_asymetrix_header,0))return false;uint16_t vol=sxae16(h+40),n=sxae16(h+42);if(vol!=1)return true;int64_t end=44+(int64_t)n*108;
 if(n>20000||!sxae_bound(c,0,end)||!sx_table(c,&sxae_asymetrix_member,44,108,n))return false;
 for(unsigned i=0;i<n;i++){uint8_t b[108];if(!sx_read(c,44+(int64_t)i*108,b,108))return false;if((sxae32(b+30)>>16)!=1)continue;int64_t p=sxae32(b+34),limit=c->size;uint32_t left=sxae32(b+38);if(p<end||p>c->size)continue;
 /* The native reader bounds each chain by the next current-volume offset. */
 for(unsigned j=i+1;j<n;j++){uint8_t next[12];if(!sx_read(c,44+(int64_t)j*108+30,next,12))return false;if((sxae32(next)>>16)==1){limit=sxae32(next+4);break;}}
 if(limit<p||limit>c->size)continue;size_t saved=c->count;bool complete=true;
 for(unsigned k=0;left&&k<20000;k++){uint8_t q[6];if(limit-p<6){complete=false;break;}if(!sx_read(c,p,q,6))return false;uint16_t method=sxae16(q);uint32_t z=sxae32(q+2),decoded=left>4096?4096:left;
 if(method>1||z>(uint64_t)(limit-p-6)||(method==0&&z!=decoded)){complete=false;break;}
 if(!sxae_add(c,&sxae_asymetrix_block,p)||!sxae_data(c,p+6,z))return false;p+=6+z;left-=decoded;}
 if(left||!complete)c->count=saved;
 }return true;
}
bool sx_asymetrix_build(sx_context*c)
{
 return sxae_asymetrix(c);
}
