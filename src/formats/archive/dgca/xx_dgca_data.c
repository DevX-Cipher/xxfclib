/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DGCA data structures, moved out of the archivetransport schema family. */
#include "../../xx_format_schema_archivetransport.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxatp_dgca_chunk_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",4,4,SX_SIZE),
 SX_FIELD("payload_size","uint64",8,8,SX_SIZE),
 SX_FIELD("flags","uint32",16,4,SX_FLAGS),
 SX_FIELD("alignment","uint32",20,4,SX_NONE),
 SX_FIELD("payload_crc32","uint32",24,4,SX_CHECKSUM),
 SX_FIELD("header_crc32","uint32",28,4,SX_CHECKSUM),
};
const sx_layout sxatp_dgca_chunk={UINT32_C(0x60890001),"dgca_chunk",sxatp_dgca_chunk_fields,SX_COUNT(sxatp_dgca_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_iarc_prefix_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("version","char[4]",4,4,SX_NONE),
 SX_FIELD("unknown_08","uint8[24]",8,24,SX_NONE),
};
const sx_layout sxatp_dgca_iarc_prefix={UINT32_C(0x60890002),"dgca_iarc_prefix",sxatp_dgca_iarc_prefix_fields,SX_COUNT(sxatp_dgca_iarc_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_iarc_clear_tail_fields[]={
 SX_FIELD("password_verifier","uint64",0,8,SX_NONE),
 SX_FIELD("member_count","uint64",8,8,SX_COUNT_PROP),
 SX_FIELD("uncompressed_size","uint64",16,8,SX_SIZE),
 SX_FIELD("directory_size","uint64",24,8,SX_SIZE),
 SX_FIELD("names_size","uint64",32,8,SX_SIZE),
 SX_FIELD("unknown_72","uint8[8]",40,8,SX_NONE),
};
const sx_layout sxatp_dgca_iarc_clear_tail={UINT32_C(0x60890003),"dgca_iarc_clear_tail",sxatp_dgca_iarc_clear_tail_fields,SX_COUNT(sxatp_dgca_iarc_clear_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_stored_unit_fields[]={
 SX_FIELD("method","uint32",0,4,SX_ID),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxatp_dgca_stored_unit={UINT32_C(0x60890004),"dgca_stored_unit",sxatp_dgca_stored_unit_fields,SX_COUNT(sxatp_dgca_stored_unit_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_compressed_unit_fields[]={
 SX_FIELD("method","uint32",0,4,SX_ID),
 SX_FIELD("uncompressed_size","uint32",4,4,SX_SIZE),
 SX_FIELD("flags","uint32",8,4,SX_FLAGS),
 SX_FIELD("parameter_nibbles","uint32",12,4,SX_FLAGS),
 SX_FIELD("bwt_primary_index","uint32",16,4,SX_NONE),
 SX_FIELD("literal_count","uint32",20,4,SX_COUNT_PROP),
 SX_FIELD("first_stream_size","uint32",24,4,SX_SIZE),
 SX_FIELD("second_stream_size","uint32",28,4,SX_SIZE),
};
const sx_layout sxatp_dgca_compressed_unit={UINT32_C(0x60890005),"dgca_compressed_unit",sxatp_dgca_compressed_unit_fields,SX_COUNT(sxatp_dgca_compressed_unit_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_dgca_plane_unit_fields[]={
 SX_FIELD("method","uint32",0,4,SX_ID),
 SX_FIELD("plane_count","uint32",4,4,SX_COUNT_PROP),
};
const sx_layout sxatp_dgca_plane_unit={UINT32_C(0x60890006),"dgca_plane_unit",sxatp_dgca_plane_unit_fields,SX_COUNT(sxatp_dgca_plane_unit_fields),SX_LE};
static uint64_t sxatp_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
static bool sxatp_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxatp_read(c,p,b,n))return false;*v=sxatp_uint(b,n,be);return true;}
static bool sxatp_dg_unit(sx_context*c,uint64_t p,uint64_t end,unsigned depth,uint64_t*next){uint8_t b[32];if(depth>2||p>end||end-p<8||!sxatp_read(c,p,b,8))return false;uint64_t m=sxatp_uint(b,4,false),n=sxatp_uint(b+4,4,false),z=8;if(m==0){if(n>end-p-8||!sxatp_add(c,&sxatp_dgca_stored_unit,p))return false;z+=n;}else if(m==1){if(end-p<32||!sxatp_read(c,p,b,32))return false;z=32+sxatp_uint(b+24,4,false)+sxatp_uint(b+28,4,false);if(z>end-p||!sxatp_add(c,&sxatp_dgca_compressed_unit,p))return false;}else if(m==2&&depth==0){if(!n||n>(end-p-8)/8||!sxatp_add(c,&sxatp_dgca_plane_unit,p))return false;uint64_t at=p+8;for(uint64_t i=0;i<n;i++)if(!sxatp_dg_unit(c,at,end,depth+1,&at))return false;z=at-p;}else return false;*next=p+z;return true;}
static bool sxatp_dg_chunks(sx_context*c,uint64_t p,uint64_t end,unsigned depth,bool encrypted){if(depth>4)return false;while(p<end){uint8_t h[32];if(end-p<32||!sxatp_read(c,p,h,32))return false;uint64_t z=sxatp_uint(h+8,8,false);if(sxatp_uint(h+4,4,false)!=32||sxatp_uint(h+20,4,false)!=16||z>end-p-32||z>UINT64_MAX-15)return false;uint64_t body=p+32,next=body+((z+15)&~UINT64_C(15));if(next>end||!sxatp_add(c,&sxatp_dgca_chunk,p))return false;
 if(!xx_rt_memcmp(h,"IARC",4)&&z==80){uint64_t flags;if(!sxatp_word(c,body,4,false,&flags)||!sxatp_add(c,&sxatp_dgca_iarc_prefix,body))return false;if(!(flags&1)&&!sxatp_add(c,&sxatp_dgca_iarc_clear_tail,body+32))return false;}
 else if(!xx_rt_memcmp(h,"DGCC",4)&&!encrypted){uint64_t q;if(!sxatp_dg_unit(c,body,body+z,0,&q))return false;}
 else if(!xx_rt_memcmp(h,"DGCA",4)||!xx_rt_memcmp(h,"INFO",4)||(!encrypted&&(!xx_rt_memcmp(h,"DATA",4)||!xx_rt_memcmp(h,"IFDT",4)||!xx_rt_memcmp(h,"IFNM",4)))){if(!sxatp_dg_chunks(c,body,body+z,depth+1,encrypted))return false;}
 p=next;}return true;}
/* Locate the clear IARC flag before interpreting any possibly encrypted DGCC. */
static bool sxatp_dgca(sx_context*c){uint8_t h[32];if(!sxatp_read(c,0,h,32)||xx_rt_memcmp(h,"DGCA",4))return false;uint64_t root=sxatp_uint(h+8,8,false);if(root>(uint64_t)c->size-32)return false;bool encrypted=false;uint64_t p=32;while(p<root+32){if(root+32-p<32||!sxatp_read(c,p,h,32))return false;uint64_t z=sxatp_uint(h+8,8,false);if(z>root+32-p-32||z>UINT64_MAX-15)return false;if(!xx_rt_memcmp(h,"INFO",4)){uint64_t q=p+32,e=q+z;while(q<e){uint8_t a[32];if(e-q<32||!sxatp_read(c,q,a,32))return false;uint64_t n=sxatp_uint(a+8,8,false);if(n>e-q-32||n>UINT64_MAX-15)return false;if(!xx_rt_memcmp(a,"IARC",4)){uint64_t f;if(n<4||!sxatp_word(c,q+32,4,false,&f))return false;encrypted=(f&1)!=0;}uint64_t step=32+((n+15)&~UINT64_C(15));if(step>e-q)return false;q+=step;}}
 uint64_t step=32+((z+15)&~UINT64_C(15));if(step>root+32-p)return false;p+=step;}return sxatp_dg_chunks(c,0,root+32,0,encrypted);}
bool sx_dgca_build(sx_context*c)
{
 return sxatp_dgca(c);
}
