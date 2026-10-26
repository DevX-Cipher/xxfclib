/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * amiga ipf data structures, moved out of the diskimages schema family. */
#include "../../xx_format_schema_diskimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxdi_ipf_chunk_header_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("header_crc","uint32",8,4,SX_CHECKSUM),
};
const sx_layout sxdi_ipf_chunk_header = {UINT32_C(0x6015001c),"ipf_chunk_header",sxdi_ipf_chunk_header_fields,SX_COUNT(sxdi_ipf_chunk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_info_fields[] = {
    SX_FIELD("image_type","uint32",0,4,SX_ID),
    SX_FIELD("encoder","uint32",4,4,SX_ID),
    SX_FIELD("encoder_revision","uint32",8,4,SX_ID),
    SX_FIELD("release","uint32",12,4,SX_ID),
    SX_FIELD("revision","uint32",16,4,SX_ID),
    SX_FIELD("origin","uint32",20,4,SX_ID),
    SX_FIELD("min_cylinder","uint32",24,4,SX_ID),
    SX_FIELD("max_cylinder","uint32",28,4,SX_ID),
    SX_FIELD("min_head","uint32",32,4,SX_ID),
    SX_FIELD("max_head","uint32",36,4,SX_ID),
    SX_FIELD("creation_date","uint32",40,4,SX_NONE),
    SX_FIELD("creation_time","uint32",44,4,SX_NONE),
    SX_FIELD("platforms","uint32[4]",48,16,SX_ID),
    SX_FIELD("disk_number","uint32",64,4,SX_ID),
    SX_FIELD("user_id","uint32",68,4,SX_ID),
    SX_FIELD("reserved","uint32[3]",72,12,SX_RESERVED),
};
const sx_layout sxdi_ipf_info = {UINT32_C(0x6015001d),"ipf_info",sxdi_ipf_info_fields,SX_COUNT(sxdi_ipf_info_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_image_fields[] = {
    SX_FIELD("cylinder","uint32",0,4,SX_ID),
    SX_FIELD("head","uint32",4,4,SX_ID),
    SX_FIELD("density_type","uint32",8,4,SX_ID),
    SX_FIELD("signal_type","uint32",12,4,SX_ID),
    SX_FIELD("track_size_rounded","uint32",16,4,SX_NONE),
    SX_FIELD("start_position_rounded","uint32",20,4,SX_NONE),
    SX_FIELD("start_bit","uint32",24,4,SX_NONE),
    SX_FIELD("data_bits","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("gap_bits","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("track_bits","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("block_count","uint32",40,4,SX_COUNT_PROP),
    SX_FIELD("process","uint32",44,4,SX_ID),
    SX_FIELD("flags","uint32",48,4,SX_FLAGS),
    SX_FIELD("data_key","uint32",52,4,SX_ID),
    SX_FIELD("reserved","uint32[3]",56,12,SX_RESERVED),
};
const sx_layout sxdi_ipf_image = {UINT32_C(0x6015001e),"ipf_image",sxdi_ipf_image_fields,SX_COUNT(sxdi_ipf_image_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_data_fields[] = {
    SX_FIELD("payload_size","uint32",0,4,SX_SIZE),
    SX_FIELD("payload_bits","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("payload_crc","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("data_key","uint32",12,4,SX_ID),
};
const sx_layout sxdi_ipf_data = {UINT32_C(0x6015001f),"ipf_data",sxdi_ipf_data_fields,SX_COUNT(sxdi_ipf_data_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_block_encoder1_fields[] = {
    SX_FIELD("data_bits","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("gap_bits","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("decoded_block_size_rounded","uint32",8,4,SX_NONE),
    SX_FIELD("decoded_gap_size_rounded","uint32",12,4,SX_NONE),
    SX_FIELD("encoding_type","uint32",16,4,SX_ID),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("gap_value","uint32",24,4,SX_ID),
    SX_FIELD("data_offset","uint32",28,4,SX_OFFSET),
};
const sx_layout sxdi_ipf_block_encoder1 = {UINT32_C(0x60150020),"ipf_block_encoder1",sxdi_ipf_block_encoder1_fields,SX_COUNT(sxdi_ipf_block_encoder1_fields),SX_BE};
static const xx_data_struct_field_desc sxdi_ipf_block_encoder2_fields[] = {
    SX_FIELD("data_bits","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("gap_bits","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("gap_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("cell_type","uint32",12,4,SX_ID),
    SX_FIELD("encoding_type","uint32",16,4,SX_ID),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
    SX_FIELD("gap_value","uint32",24,4,SX_ID),
    SX_FIELD("data_offset","uint32",28,4,SX_OFFSET),
};
const sx_layout sxdi_ipf_block_encoder2 = {UINT32_C(0x60150021),"ipf_block_encoder2",sxdi_ipf_block_encoder2_fields,SX_COUNT(sxdi_ipf_block_encoder2_fields),SX_BE};
static uint32_t sxdi_be32(const uint8_t *p){return xx_data_get_u32(p,4,0,true);}
static bool sxdi_ipf(sx_context *c)
{
    uint64_t at=0;uint32_t encoder=0,keys[170],counts[170];size_t tracks=0;
    while(at<(uint64_t)c->size&&c->count+3<=32768){uint8_t h[12];if(!sxdi_read(c,at,h,12))return at!=0;uint32_t n=sxdi_be32(h+4);if(n<12||!sxdi_span(c,at,n)||(!at&&xx_rt_memcmp(h,"CAPS",4)))return at!=0;
        if(!sx_add(c,&sxdi_ipf_chunk_header,(int64_t)at,12))return false;uint64_t q=at+12,end=at+n;
        if(!xx_rt_memcmp(h,"INFO",4)&&n>=96){if(!sx_add(c,&sxdi_ipf_info,(int64_t)q,84)||!sx_u32(c,(int64_t)q+4,true,&encoder))return false;}
        else if(!xx_rt_memcmp(h,"IMGE",4)&&n>=80){if(!sx_add(c,&sxdi_ipf_image,(int64_t)q,68))return false;
            if(tracks<170){if(!sx_u32(c,(int64_t)q+52,true,&keys[tracks])||!sx_u32(c,(int64_t)q+40,true,&counts[tracks]))return false;tracks++;}
        }else if(!xx_rt_memcmp(h,"DATA",4)&&n>=28){uint8_t d[16];if(!sxdi_read(c,q,d,16)||!sx_add(c,&sxdi_ipf_data,(int64_t)q,16))return false;uint32_t bytes=sxdi_be32(d),key=sxdi_be32(d+12);if(!sxdi_span(c,end,bytes))return true;
            if(encoder==1||encoder==2)for(size_t j=0;j<tracks;j++)if(keys[j]==key){uint32_t blocks=counts[j];if(blocks&&blocks<=256&&(uint64_t)blocks*32<=bytes&&!sx_table(c,encoder==1?&sxdi_ipf_block_encoder1:&sxdi_ipf_block_encoder2,(int64_t)end,32,blocks))return false;break;}
            end+=bytes;
        }
        at=end;if(c->count>=32768)break;
    }return at!=0;
}
bool sx_amiga_ipf_build(sx_context*c)
{
    return sxdi_ipf(c);
}
