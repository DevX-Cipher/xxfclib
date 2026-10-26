/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ti99 pc99 data structures, moved out of the diskremaining schema family. */
#include "../../xx_format_schema_diskremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdr_pc99_id_fm_fields[] = {
    SX_FIELD("address_mark","uint8",0,1,SX_ID),
    SX_FIELD("cylinder","uint8",1,1,SX_NONE),
    SX_FIELD("head","uint8",2,1,SX_NONE),
    SX_FIELD("sector","uint8",3,1,SX_NONE),
    SX_FIELD("size_code","uint8",4,1,SX_NONE),
    SX_FIELD("crc16_or_token","uint16be",5,2,SX_CHECKSUM),
};
const sx_layout sxdr_pc99_id_fm = {0x607f000fU,"pc99_id_fm",sxdr_pc99_id_fm_fields,SX_COUNT(sxdr_pc99_id_fm_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_pc99_id_mfm_fields[] = {
    SX_FIELD("sync","byte[3]",0,3,SX_SIGNATURE),
    SX_FIELD("address_mark","uint8",3,1,SX_ID),
    SX_FIELD("cylinder","uint8",4,1,SX_NONE),
    SX_FIELD("head","uint8",5,1,SX_NONE),
    SX_FIELD("sector","uint8",6,1,SX_NONE),
    SX_FIELD("size_code","uint8",7,1,SX_NONE),
    SX_FIELD("crc16_or_token","uint16be",8,2,SX_CHECKSUM),
};
const sx_layout sxdr_pc99_id_mfm = {0x607f0010U,"pc99_id_mfm",sxdr_pc99_id_mfm_fields,SX_COUNT(sxdr_pc99_id_mfm_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_pc99_data_fm_fields[] = {
    SX_FIELD("data_mark","uint8",0,1,SX_ID),
};
const sx_layout sxdr_pc99_data_fm = {0x607f0011U,"pc99_data_fm",sxdr_pc99_data_fm_fields,SX_COUNT(sxdr_pc99_data_fm_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_pc99_data_mfm_fields[] = {
    SX_FIELD("sync","byte[3]",0,3,SX_SIGNATURE),
    SX_FIELD("data_mark","uint8",3,1,SX_ID),
};
const sx_layout sxdr_pc99_data_mfm = {0x607f0012U,"pc99_data_mfm",sxdr_pc99_data_mfm_fields,SX_COUNT(sxdr_pc99_data_mfm_fields),SX_LE};
static const xx_data_struct_field_desc sxdr_pc99_data_crc_fields[] = {
    SX_FIELD("crc16_or_token","uint16be",0,2,SX_CHECKSUM),
};
const sx_layout sxdr_pc99_data_crc = {0x607f0013U,"pc99_data_crc",sxdr_pc99_data_crc_fields,SX_COUNT(sxdr_pc99_data_crc_fields),SX_LE};
#define SXDR_ADD(c,n,p) sxdr_put(c,&sxdr_##n,p,1)
static bool sxdr_pc_crc(const uint8_t*b,size_t n,const uint8_t*crc){return (crc[0]==0xf7&&crc[1]==0xf7)||sxdr_ccitt(b,n)==sxdr16(crc,true);}
static bool sxdr_pc99(sx_context*c){uint32_t n=0;bool fm=false;if(c->size==40*3253||c->size==80*3253){n=3253;fm=true;}else if(c->size==40*6872||c->size==80*6872)n=6872;else return false;uint8_t*b=xx_mem_alloc(n);if(!b)return false;bool ok=true;
 for(uint32_t tr=0;tr<(uint64_t)c->size/n&&ok;tr++){uint64_t base=(uint64_t)tr*n;if(!sxdr_read(c,base,b,n)){ok=false;break;}uint32_t wanted=fm?9:18,seen=0;for(uint32_t i=0;i+7<n;){if(!(i&255)&&xx_pd_is_stopped(c->pd)){ok=false;break;}if(b[i]!=0xfe||(!fm&&(i<3||b[i-3]!=0xa1||b[i-2]!=0xa1||b[i-1]!=0xa1))){i++;continue;}uint32_t a=fm?i:i-3;if(b[i+1]!=tr%40||b[i+2]!=tr/40||b[i+3]>=wanted||b[i+4]!=1||!sxdr_pc_crc(b+a,i+5-a,b+i+5)){i++;continue;}uint32_t j=i+7;for(;j<n&&j-i<96;j++){if((b[j]==0xfb||b[j]==0xf8)&&(fm||(j>=3&&b[j-3]==0xa1&&b[j-2]==0xa1&&b[j-1]==0xa1)))break;if(b[j]==0xfe)break;}
 if(j>=n||j-i>=96||n-j<259||(b[j]!=0xfb&&b[j]!=0xf8)||(seen&(1U<<b[i+3]))){ok=false;break;}uint32_t data=fm?j:j-3;if(!sxdr_pc_crc(b+data,j+257-data,b+j+257)){ok=false;break;}seen|=1U<<b[i+3];if(!sxdr_put(c,fm?&sxdr_pc99_id_fm:&sxdr_pc99_id_mfm,base+a,1)||!sxdr_put(c,fm?&sxdr_pc99_data_fm:&sxdr_pc99_data_mfm,base+data,1)||!SXDR_ADD(c,pc99_data_crc,base+j+257)){ok=false;break;}i=j+259;}
 if(seen!=(1U<<wanted)-1)ok=false;}
 xx_mem_free(b);return ok;}
#undef SXDR_ADD
bool sx_ti99_pc99_build(sx_context*c)
{
 return sxdr_pc99(c);
}
