/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * fei data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_fei_id_phase0_fields[] = {
    SX_FIELD("sync_bitcells","byte[6]",0,6,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[2]",6,2,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[2]",8,2,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[2]",10,2,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[2]",12,2,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[2]",14,2,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[2]",16,2,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[2]",18,2,SX_CHECKSUM),
};
const sx_layout sxdr_fei_id_phase0 = {0x607f0029U,"fei_id_phase0",sxdr_fei_id_phase0_fields,SX_COUNT(sxdr_fei_id_phase0_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_fei_id_phase1_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
const sx_layout sxdr_fei_id_phase1 = {0x607f002aU,"fei_id_phase1",sxdr_fei_id_phase1_fields,SX_COUNT(sxdr_fei_id_phase1_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_fei_id_phase2_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
const sx_layout sxdr_fei_id_phase2 = {0x607f002bU,"fei_id_phase2",sxdr_fei_id_phase2_fields,SX_COUNT(sxdr_fei_id_phase2_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_fei_id_phase3_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
const sx_layout sxdr_fei_id_phase3 = {0x607f002cU,"fei_id_phase3",sxdr_fei_id_phase3_fields,SX_COUNT(sxdr_fei_id_phase3_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_fei_id_phase4_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
const sx_layout sxdr_fei_id_phase4 = {0x607f002dU,"fei_id_phase4",sxdr_fei_id_phase4_fields,SX_COUNT(sxdr_fei_id_phase4_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_fei_id_phase5_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
const sx_layout sxdr_fei_id_phase5 = {0x607f002eU,"fei_id_phase5",sxdr_fei_id_phase5_fields,SX_COUNT(sxdr_fei_id_phase5_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_fei_id_phase6_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
const sx_layout sxdr_fei_id_phase6 = {0x607f002fU,"fei_id_phase6",sxdr_fei_id_phase6_fields,SX_COUNT(sxdr_fei_id_phase6_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_fei_id_phase7_fields[] = {
    SX_FIELD("sync_bitcells","byte[7]",0,7,SX_SIGNATURE),
    SX_FIELD("address_mark_mfm_bitcells","byte[3]",6,3,SX_ID),
    SX_FIELD("cylinder_mfm_bitcells","byte[3]",8,3,SX_NONE),
    SX_FIELD("head_mfm_bitcells","byte[3]",10,3,SX_NONE),
    SX_FIELD("sector_mfm_bitcells","byte[3]",12,3,SX_NONE),
    SX_FIELD("size_code_mfm_bitcells","byte[3]",14,3,SX_NONE),
    SX_FIELD("crc_high_mfm_bitcells","byte[3]",16,3,SX_CHECKSUM),
    SX_FIELD("crc_low_mfm_bitcells","byte[3]",18,3,SX_CHECKSUM),
};
const sx_layout sxdr_fei_id_phase7 = {0x607f0030U,"fei_id_phase7",sxdr_fei_id_phase7_fields,SX_COUNT(sxdr_fei_id_phase7_fields),SX_LE};
#define SXDR_LIMIT 24000U
static uint16_t sxdr_mfmword(const uint8_t*b,uint32_t bit){uint16_t v=0;for(unsigned k=0;k<16;k++)v=(uint16_t)((v<<1)|((b[(bit+k)/8]>>((bit+k)%8))&1));return v;}
static uint8_t sxdr_mfmdata(uint16_t v){uint8_t x=0;for(unsigned k=0;k<8;k++)x=(uint8_t)((x<<1)|((v>>(14-k*2))&1));return x;}
static bool sxdr_fei_track(sx_context*c,uint8_t*b,uint64_t p,uint32_t n,uint32_t cyl,uint32_t head,bool emit){
 if(!sxdr_read(c,p,b,n))return false;bool found=false;const sx_layout*phases[]={&sxdr_fei_id_phase0,&sxdr_fei_id_phase1,&sxdr_fei_id_phase2,&sxdr_fei_id_phase3,&sxdr_fei_id_phase4,&sxdr_fei_id_phase5,&sxdr_fei_id_phase6,&sxdr_fei_id_phase7};
 for(uint32_t bit=0;bit+160<=n*8;bit++){if(!(bit&4095)&&xx_pd_is_stopped(c->pd))return false;if(sxdr_mfmword(b,bit)!=0x4489||sxdr_mfmword(b,bit+16)!=0x4489||sxdr_mfmword(b,bit+32)!=0x4489)continue;uint8_t id[10]={0xa1,0xa1,0xa1};for(unsigned j=0;j<7;j++)id[j+3]=sxdr_mfmdata(sxdr_mfmword(b,bit+48+j*16));if(id[3]!=0xfe||!id[6]||id[7]>6||sxdr_ccitt(id,10))continue;if(id[4]!=cyl||id[5]!=head)return false;found=true;if(emit&&!sxdr_put(c,phases[bit%8],p+bit/8,1))return false;}
 return found;}
static bool sxdr_fei(sx_context*c){uint8_t*b=xx_mem_alloc(25000);if(!b)return false;uint32_t bytes=0,tracks=0;bool ok=false;
 for(unsigned pass=0;pass<2;pass++){uint32_t n=pass?12500:25000;if(c->size<=0||c->size%(n*2))continue;uint64_t t=c->size/(n*2);if(t>170||!t)continue;if(sxdr_fei_track(c,b,0,n,0,0,false)&&sxdr_fei_track(c,b,t*n,n,0,1,false)&&sxdr_fei_track(c,b,(t-1)*n,n,(uint32_t)t-1,0,false)&&sxdr_fei_track(c,b,(t*2-1)*n,n,(uint32_t)t-1,1,false)){bytes=n;tracks=(uint32_t)t;break;}}
 if(bytes){ok=true;for(uint32_t i=0;i<tracks*2&&c->count<SXDR_LIMIT;i++){/* Interior tracks need not have decodable sector IDs. */size_t start=c->count;bool z=sxdr_fei_track(c,b,(uint64_t)i*bytes,bytes,i%tracks,i/tracks,true);if(!z&&xx_pd_is_stopped(c->pd)){ok=false;break;}if(!z)c->count=start;}}
 xx_mem_free(b);return ok;}
#undef SXDR_LIMIT
bool sx_fei_build(sx_context*c)
{
 return sxdr_fei(c);
}
