/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * apple nib data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_apple_gcr_address_fields[] = {
    SX_FIELD("prologue","byte[3]",0,3,SX_SIGNATURE),
    SX_FIELD("volume_4and4","byte[2]",3,2,SX_NONE),
    SX_FIELD("track_4and4","byte[2]",5,2,SX_NONE),
    SX_FIELD("sector_4and4","byte[2]",7,2,SX_NONE),
    SX_FIELD("xor_checksum_4and4","byte[2]",9,2,SX_CHECKSUM),
    SX_FIELD("epilogue","byte[3]",11,3,SX_SIGNATURE),
};
const sx_layout sxdr_apple_gcr_address = {0x607f0014U,"apple_gcr_address",sxdr_apple_gcr_address_fields,SX_COUNT(sxdr_apple_gcr_address_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_apple_gcr_data_prefix_fields[] = {
    SX_FIELD("prologue","byte[3]",0,3,SX_SIGNATURE),
};
const sx_layout sxdr_apple_gcr_data_prefix = {0x607f0015U,"apple_gcr_data_prefix",sxdr_apple_gcr_data_prefix_fields,SX_COUNT(sxdr_apple_gcr_data_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_apple_gcr_data_suffix_fields[] = {
    SX_FIELD("translated_xor_checksum","uint8",0,1,SX_CHECKSUM),
    SX_FIELD("epilogue","byte[3]",1,3,SX_SIGNATURE),
};
const sx_layout sxdr_apple_gcr_data_suffix = {0x607f0016U,"apple_gcr_data_suffix",sxdr_apple_gcr_data_suffix_fields,SX_COUNT(sxdr_apple_gcr_data_suffix_fields),SX_LE};
#define SXDR_LIMIT 24000U
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static uint8_t sxdr_ring(const uint8_t*b,uint32_t n,uint32_t p){return b[p%n];}
static bool sxdr_four(const uint8_t*b,uint32_t n,uint32_t p,uint8_t*v){uint8_t a=sxdr_ring(b,n,p),z=sxdr_ring(b,n,p+1);if((a&0xaa)!=0xaa||(z&0xaa)!=0xaa)return false;*v=(uint8_t)(((a<<1)|1)&z);return true;}
static bool sxdr_gcrcheck(const uint8_t*b,uint32_t n,uint32_t p,unsigned sectors){
 static const uint8_t codes62[64]={0x96,0x97,0x9a,0x9b,0x9d,0x9e,0x9f,0xa6,0xa7,0xab,0xac,0xad,0xae,0xaf,0xb2,0xb3,0xb4,0xb5,0xb6,0xb7,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,0xcb,0xcd,0xce,0xcf,0xd3,0xd6,0xd7,0xd9,0xda,0xdb,0xdc,0xdd,0xde,0xdf,0xe5,0xe6,0xe7,0xe9,0xea,0xeb,0xec,0xed,0xee,0xef,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff};
 static const uint8_t codes53[32]={0xab,0xad,0xae,0xaf,0xb5,0xb6,0xb7,0xba,0xbb,0xbd,0xbe,0xbf,0xd6,0xd7,0xda,0xdb,0xdd,0xde,0xdf,0xea,0xeb,0xed,0xee,0xef,0xf5,0xf6,0xf7,0xfa,0xfb,0xfd,0xfe,0xff};
 uint8_t inv[256],sum=0;xx_rt_memset(inv,255,sizeof(inv));for(unsigned i=0;i<(sectors==13?32:64);i++)inv[sectors==13?codes53[i]:codes62[i]]=(uint8_t)i;uint32_t z=sectors==13?410:342;
 for(uint32_t i=0;i<z;i++){uint8_t v=inv[sxdr_ring(b,n,p+i)];if(v==255)return false;sum^=v;}return inv[sxdr_ring(b,n,p+z)]==sum&&sxdr_ring(b,n,p+z+1)==0xde&&sxdr_ring(b,n,p+z+2)==0xaa;}
static bool sxdr_nib(sx_context*c){uint32_t n=0;if(c->size>=35*6656&&c->size<=50*6656&&c->size%6656==0)n=6656;else if(c->size>=35*6384&&c->size<=40*6384&&c->size%6384==0)n=6384;else return false;uint8_t*b=xx_mem_alloc(n);if(!b)return false;bool ok=true;
 for(uint32_t tr=0;tr<(uint64_t)c->size/n&&ok&&c->count<SXDR_LIMIT;tr++){uint64_t base=(uint64_t)tr*n;if(!sxdr_read(c,base,b,n)){ok=false;break;}for(uint32_t i=0;i<n;i++){if(!(i&255)&&xx_pd_is_stopped(c->pd)){ok=false;break;}if(b[i]!=0xd5||sxdr_ring(b,n,i+1)!=0xaa)continue;uint8_t mark=sxdr_ring(b,n,i+2);unsigned sectors=mark==0x96?16:mark==0xb5?13:0;if(!sectors)continue;uint8_t v,t,s,x;if(!sxdr_four(b,n,i+3,&v)||!sxdr_four(b,n,i+5,&t)||!sxdr_four(b,n,i+7,&s)||!sxdr_four(b,n,i+9,&x)||t!=tr||s>=sectors||(uint8_t)(v^t^s)!=x||sxdr_ring(b,n,i+11)!=0xde||sxdr_ring(b,n,i+12)!=0xaa)continue;
 for(uint32_t gap=14;gap<270;gap++){uint32_t p=i+gap;if(sxdr_ring(b,n,p)!=0xd5||sxdr_ring(b,n,p+1)!=0xaa)continue;mark=sxdr_ring(b,n,p+2);if(mark==0x96||mark==0xb5)break;if(mark!=0xad)continue;if(sxdr_gcrcheck(b,n,p+3,sectors)){/* Each emitted structure must itself be contiguous in the source track. */if(i+14<=n&&!SXDR_ADD(c,apple_gcr_address,base+i)){ok=false;break;}uint32_t d=p%n,z=sectors==13?410:342,end=(p+3+z)%n;if(d+3<=n&&!SXDR_ADD(c,apple_gcr_data_prefix,base+d)){ok=false;break;}if(end+4<=n&&!SXDR_ADD(c,apple_gcr_data_suffix,base+end)){ok=false;break;}}break;}
 }}xx_mem_free(b);return ok&&c->count!=0;}
#undef SXDR_LIMIT
#undef SXDR_ADD
bool sx_apple_nib_build(sx_context*c)
{
 return sxdr_nib(c);
}
