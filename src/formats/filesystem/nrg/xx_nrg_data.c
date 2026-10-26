/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NRG data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_nrg_footer32_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("chunk_list_offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sxsl_nrg_footer32 = {0x6033003dU,"nrg_footer32",sxsl_nrg_footer32_fields,SX_COUNT(sxsl_nrg_footer32_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_dao_track32_fields[] = {
    SX_FIELD("isrc","char[12]",0,12,SX_NONE),
    SX_FIELD("sector_size","uint16",12,2,SX_SIZE),
    SX_FIELD("mode","uint8",14,1,SX_ID),
    SX_FIELD("unknown","byte[3]",15,3,SX_NONE),
    SX_FIELD("pregap_offset","uint32",18,4,SX_OFFSET),
    SX_FIELD("track_offset","uint32",22,4,SX_OFFSET),
    SX_FIELD("end_offset","uint32",26,4,SX_OFFSET),
};
const sx_layout sxsl_nrg_dao_track32 = {0x6033003eU,"nrg_dao_track32",sxsl_nrg_dao_track32_fields,SX_COUNT(sxsl_nrg_dao_track32_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_etn_track32_fields[] = {
    SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("unknown1","byte[3]",8,3,SX_NONE),
    SX_FIELD("mode","uint8",11,1,SX_ID),
    SX_FIELD("start_lba","int32",12,4,SX_NONE),
    SX_FIELD("unknown2","byte[4]",16,4,SX_NONE),
};
const sx_layout sxsl_nrg_etn_track32 = {0x6033003fU,"nrg_etn_track32",sxsl_nrg_etn_track32_fields,SX_COUNT(sxsl_nrg_etn_track32_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_footer64_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("chunk_list_offset","uint64",4,8,SX_OFFSET),
};
const sx_layout sxsl_nrg_footer64 = {0x60330040U,"nrg_footer64",sxsl_nrg_footer64_fields,SX_COUNT(sxsl_nrg_footer64_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_dao_track64_fields[] = {
    SX_FIELD("isrc","char[12]",0,12,SX_NONE),
    SX_FIELD("sector_size","uint16",12,2,SX_SIZE),
    SX_FIELD("mode","uint8",14,1,SX_ID),
    SX_FIELD("unknown","byte[3]",15,3,SX_NONE),
    SX_FIELD("pregap_offset","uint64",18,8,SX_OFFSET),
    SX_FIELD("track_offset","uint64",26,8,SX_OFFSET),
    SX_FIELD("end_offset","uint64",34,8,SX_OFFSET),
};
const sx_layout sxsl_nrg_dao_track64 = {0x60330041U,"nrg_dao_track64",sxsl_nrg_dao_track64_fields,SX_COUNT(sxsl_nrg_dao_track64_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_etn_track64_fields[] = {
    SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("data_size","uint64",8,8,SX_SIZE),
    SX_FIELD("unknown1","byte[3]",16,3,SX_NONE),
    SX_FIELD("mode","uint8",19,1,SX_ID),
    SX_FIELD("start_lba","int32",20,4,SX_NONE),
    SX_FIELD("unknown2","byte[8]",24,8,SX_NONE),
};
const sx_layout sxsl_nrg_etn_track64 = {0x60330042U,"nrg_etn_track64",sxsl_nrg_etn_track64_fields,SX_COUNT(sxsl_nrg_etn_track64_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_chunk_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxsl_nrg_chunk = {0x60330043U,"nrg_chunk",sxsl_nrg_chunk_fields,SX_COUNT(sxsl_nrg_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_dao_header_fields[] = {
    SX_FIELD("size_word","byte[4]",0,4,SX_NONE),
    SX_FIELD("media_catalog_number","char[13]",4,13,SX_NONE),
    SX_FIELD("unknown1","uint8",17,1,SX_NONE),
    SX_FIELD("session_type","uint8",18,1,SX_ID),
    SX_FIELD("unknown2","uint8",19,1,SX_NONE),
    SX_FIELD("first_track","uint8",20,1,SX_NONE),
    SX_FIELD("last_track","uint8",21,1,SX_NONE),
};
const sx_layout sxsl_nrg_dao_header = {0x60330044U,"nrg_dao_header",sxsl_nrg_dao_header_fields,SX_COUNT(sxsl_nrg_dao_header_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_cuex_fields[] = {
    SX_FIELD("adr_control","uint8",0,1,SX_FLAGS),
    SX_FIELD("track_bcd","uint8",1,1,SX_NONE),
    SX_FIELD("index_bcd","uint8",2,1,SX_NONE),
    SX_FIELD("unknown","uint8",3,1,SX_NONE),
    SX_FIELD("start_lba","int32",4,4,SX_NONE),
};
const sx_layout sxsl_nrg_cuex = {0x60330045U,"nrg_cuex",sxsl_nrg_cuex_fields,SX_COUNT(sxsl_nrg_cuex_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_cues_fields[] = {
    SX_FIELD("adr_control","uint8",0,1,SX_FLAGS),
    SX_FIELD("track_bcd","uint8",1,1,SX_NONE),
    SX_FIELD("index_bcd","uint8",2,1,SX_NONE),
    SX_FIELD("unknown","uint8",3,1,SX_NONE),
    SX_FIELD("hour","uint8",4,1,SX_NONE),
    SX_FIELD("minute","uint8",5,1,SX_NONE),
    SX_FIELD("second","uint8",6,1,SX_NONE),
    SX_FIELD("frame","uint8",7,1,SX_NONE),
};
const sx_layout sxsl_nrg_cues = {0x60330046U,"nrg_cues",sxsl_nrg_cues_fields,SX_COUNT(sxsl_nrg_cues_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_session_fields[] = {
    SX_FIELD("track_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sxsl_nrg_session = {0x60330047U,"nrg_session",sxsl_nrg_session_fields,SX_COUNT(sxsl_nrg_session_fields),SX_BE};
static const xx_data_struct_field_desc sxsl_nrg_media_fields[] = {
    SX_FIELD("media_type","uint32",0,4,SX_FLAGS),
};
const sx_layout sxsl_nrg_media = {0x60330048U,"nrg_media",sxsl_nrg_media_fields,SX_COUNT(sxsl_nrg_media_fields),SX_BE};
#define SXSL_LIMIT 24000U
#define SXSL_ROWS 1048576U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
static bool sxsl_nrg(sx_context*c){uint8_t b[12];uint64_t end=(uint64_t)c->size,p;if(end>=12&&sxsl_read(c,end-12,b,12)&&!xx_rt_memcmp(b,"NER5",4)){p=sxsl_uint(b+4,8,true);if(!SXSL_ADD(c,nrg_footer64,end-12))return false;end-=12;}else if(end>=8&&sxsl_read(c,end-8,b,8)&&!xx_rt_memcmp(b,"NERO",4)){p=sxsl_uint(b+4,4,true);if(!SXSL_ADD(c,nrg_footer32,end-8))return false;end-=8;}else return false;for(unsigned i=0;i<SXSL_LIMIT&&p<end&&c->count<SXSL_LIMIT;i++){if(end-p<8||!sxsl_read(c,p,b,8))break;uint64_t n=sxsl_uint(b+4,4,true),q=p+8;if(n>end-q||!SXSL_ADD(c,nrg_chunk,p))break;const sx_layout*l=NULL;uint64_t z=0,skip=0;if(!xx_rt_memcmp(b,"DAOX",4)||!xx_rt_memcmp(b,"DAOI",4)){z=b[3]=='X'?42:30;skip=22;l=b[3]=='X'?&sxsl_nrg_dao_track64:&sxsl_nrg_dao_track32;if(n>=22&&!SXSL_ADD(c,nrg_dao_header,q))return false;}else if(!xx_rt_memcmp(b,"ETN2",4)||!xx_rt_memcmp(b,"ETNF",4)){z=b[3]=='2'?32:20;l=b[3]=='2'?&sxsl_nrg_etn_track64:&sxsl_nrg_etn_track32;}else if(!xx_rt_memcmp(b,"CUEX",4)||!xx_rt_memcmp(b,"CUES",4)){z=8;l=b[3]=='X'?&sxsl_nrg_cuex:&sxsl_nrg_cues;}else if(!xx_rt_memcmp(b,"SINF",4)&&n==4){z=4;l=&sxsl_nrg_session;}else if(!xx_rt_memcmp(b,"MTYP",4)&&n==4){z=4;l=&sxsl_nrg_media;}if(l&&n>=skip&&(n-skip)%z==0&&(n-skip)/z<=SXSL_ROWS&&!sxsl_put(c,l,q+skip,(n-skip)/z))return false;p=q+n;if(!xx_rt_memcmp(b,"END!",4))break;}return true;}
bool sx_nrg_build(sx_context*c)
{
bool ok=false;
ok=sxsl_nrg(c);
return ok&&sxsl_finish(c);
}
