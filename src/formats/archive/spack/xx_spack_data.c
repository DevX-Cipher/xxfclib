/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SPACK data structures, moved out of the archivefinal schema family. */
#include "../../xx_format_schema_archivefinal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxaf_spack_magic_fields[] = {
 SX_FIELD("signature","uint32",0,4,SX_SIGNATURE),
};
const sx_layout sxaf_spack_magic = {UINT32_C(0x603c0021),"spack_magic",sxaf_spack_magic_fields,SX_COUNT(sxaf_spack_magic_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_spack_stored_member_fields[] = {
 SX_FIELD("tag","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("id_and_flags","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxaf_spack_stored_member = {UINT32_C(0x603c0022),"spack_stored_member",sxaf_spack_stored_member_fields,SX_COUNT(sxaf_spack_stored_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_spack_compressed_member_fields[] = {
 SX_FIELD("tag","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("id_and_flags","uint16",2,2,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("compressed_size","uint32",8,4,SX_SIZE),
 SX_FIELD("crc16","uint16",12,2,SX_CHECKSUM),
};
const sx_layout sxaf_spack_compressed_member = {UINT32_C(0x603c0023),"spack_compressed_member",sxaf_spack_compressed_member_fields,SX_COUNT(sxaf_spack_compressed_member_fields),SX_BE};
static const xx_data_struct_field_desc sxaf_spack_footer_fields[] = {
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("index_record_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxaf_spack_footer = {UINT32_C(0x603c0024),"spack_footer",sxaf_spack_footer_fields,SX_COUNT(sxaf_spack_footer_fields),SX_BE};
static bool sxaf_spack(sx_context*c){uint64_t start=0,footer,n,index;uint8_t b[14];if(!sxaf_read(c,0,b,4))return false;if(sxaf_uint(b,4,true)==0x3f3){uint8_t x;if(!sxaf_read(c,47,&x,1))return false;start=x==0xf4?6624:6616;}if(c->size<12||!sxaf_read(c,(uint64_t)c->size-12,b,4))return false;footer=(uint64_t)c->size-12;if(xx_rt_memcmp(b,"INDX",4)){footer=(uint64_t)c->size-8;if(!sxaf_read(c,footer,b,4)||xx_rt_memcmp(b,"INDX",4))return false;}if(!sxaf_word(c,footer+4,4,true,&n)||n<14||n>footer||footer-n<start+4||!sxaf_add(c,&sxaf_spack_magic,start)||!sxaf_add(c,&sxaf_spack_footer,footer))return false;index=footer-n;if(!sxaf_add(c,&sxaf_spack_compressed_member,index))return false;for(uint64_t p=start+4;p<index;){if(index-p<8||!sxaf_read(c,p,b,8))return false;uint64_t flag=sxaf_uint(b+2,2,true),size=sxaf_uint(b+4,4,true),hs=8;const sx_layout*l=&sxaf_spack_stored_member;if(!(flag&0x8000)){hs=14;l=&sxaf_spack_compressed_member;if(index-p<14||!sxaf_word(c,p+8,4,true,&size))return false;}if(size>index-p-hs||!sxaf_add(c,l,p))return false;p+=hs+size;}return true;}
bool sx_spack_build(sx_context*c)
{
 return sxaf_spack(c);
}
