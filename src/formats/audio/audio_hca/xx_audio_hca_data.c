/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * audio_hca data structures, moved out of the audiomore schema family. */
#include "../../xx_format_schema_audiomore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxau_hca_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint16",4,2,SX_ID),
 SX_FIELD("header_size","uint16",6,2,SX_SIZE),
};
const sx_layout sxau_hca_header={UINT32_C(0x602C0010),"hca_header",sxau_hca_header_fields,SX_COUNT(sxau_hca_header_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_format_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("channels","uint8",4,1,SX_COUNT_PROP),
 SX_FIELD("sample_rate","uint24",5,3,SX_NONE),
 SX_FIELD("frame_count","uint32",8,4,SX_COUNT_PROP),
 SX_FIELD("encoder_delay_samples","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("encoder_padding_samples","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxau_hca_format={UINT32_C(0x602C0011),"hca_format",sxau_hca_format_fields,SX_COUNT(sxau_hca_format_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_compression_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("frame_size","uint16",4,2,SX_SIZE),
 SX_FIELD("minimum_resolution","uint8",6,1,SX_NONE),
 SX_FIELD("maximum_resolution","uint8",7,1,SX_NONE),
 SX_FIELD("track_count","uint8",8,1,SX_COUNT_PROP),
 SX_FIELD("channel_configuration","uint8",9,1,SX_ID),
 SX_FIELD("total_bands","uint8",10,1,SX_COUNT_PROP),
 SX_FIELD("base_bands","uint8",11,1,SX_COUNT_PROP),
 SX_FIELD("stereo_bands","uint8",12,1,SX_COUNT_PROP),
 SX_FIELD("bands_per_hfr_group","uint8",13,1,SX_COUNT_PROP),
 SX_FIELD("reserved","bytes",14,2,SX_RESERVED),
};
const sx_layout sxau_hca_compression={UINT32_C(0x602C0012),"hca_compression",sxau_hca_compression_fields,SX_COUNT(sxau_hca_compression_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_ath_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("ath_type","uint16",4,2,SX_ID),
};
const sx_layout sxau_hca_ath={UINT32_C(0x602C0013),"hca_ath",sxau_hca_ath_fields,SX_COUNT(sxau_hca_ath_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_loop_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("start_frame","uint32",4,4,SX_NONE),
 SX_FIELD("end_frame","uint32",8,4,SX_NONE),
 SX_FIELD("pre_loop_samples","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("post_loop_samples","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxau_hca_loop={UINT32_C(0x602C0014),"hca_loop",sxau_hca_loop_fields,SX_COUNT(sxau_hca_loop_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_cipher_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("cipher_type","uint16",4,2,SX_ID),
};
const sx_layout sxau_hca_cipher={UINT32_C(0x602C0015),"hca_cipher",sxau_hca_cipher_fields,SX_COUNT(sxau_hca_cipher_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_relative_volume_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("volume","float",4,4,SX_NONE),
};
const sx_layout sxau_hca_relative_volume={UINT32_C(0x602C0016),"hca_relative_volume",sxau_hca_relative_volume_fields,SX_COUNT(sxau_hca_relative_volume_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_comment_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("comment_length","uint8",4,1,SX_SIZE),
};
const sx_layout sxau_hca_comment={UINT32_C(0x602C0017),"hca_comment",sxau_hca_comment_fields,SX_COUNT(sxau_hca_comment_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_pad_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
};
const sx_layout sxau_hca_pad={UINT32_C(0x602C0018),"hca_pad",sxau_hca_pad_fields,SX_COUNT(sxau_hca_pad_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_checksum_fields[]={
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxau_hca_checksum={UINT32_C(0x602C0019),"hca_checksum",sxau_hca_checksum_fields,SX_COUNT(sxau_hca_checksum_fields),SX_BE};
static const xx_data_struct_field_desc sxau_hca_frame_sync_fields[]={
 SX_FIELD("sync","uint16",0,2,SX_SIGNATURE),
};
const sx_layout sxau_hca_frame_sync={UINT32_C(0x602C001A),"hca_frame_sync",sxau_hca_frame_sync_fields,SX_COUNT(sxau_hca_frame_sync_fields),SX_BE};
#define SA_ROW(l,at,end) sxau_row(v,&sxau_##l,(at),(end))
static bool sxau_hca(sxau_view*v)
{if(!SA_ROW(hca_header,0,v->n))return false;size_t h=sxau_u16(v->p+6,true);if(h<42||!sxau_need(v,0,h,v->n)||!SA_ROW(hca_format,8,h-2)||!SA_ROW(hca_compression,24,h-2)||!SA_ROW(hca_checksum,h-2,h))return false;size_t at=40;
 while(at<h-2){if(!sxau_need(v,at,4,h-2))return false;const uint8_t*p=v->p+at;size_t z=0;const sx_layout*l=NULL;
  if(!xx_rt_memcmp(p,"ath\0",4)){l=&sxau_hca_ath;z=6;}else if(!xx_rt_memcmp(p,"loop",4)){l=&sxau_hca_loop;z=16;}else if(!xx_rt_memcmp(p,"ciph",4)){l=&sxau_hca_cipher;z=6;}else if(!xx_rt_memcmp(p,"rva\0",4)){l=&sxau_hca_relative_volume;z=8;}else if(!xx_rt_memcmp(p,"comm",4)){if(!sxau_need(v,at,5,h-2))return false;l=&sxau_hca_comment;z=5+v->p[at+4];}else if(!xx_rt_memcmp(p,"pad\0",4)){if(!SA_ROW(hca_pad,at,h-2))return false;at=h-2;break;}else return false;
  if(!sxau_need(v,at,z,h-2)||!sxau_row(v,l,at,h-2))return false;at+=z;
 }size_t frames=sxau_u32(v->p+16,true),z=sxau_u16(v->p+28,true);if(z<4||frames>1000000||!sxau_need(v,h,(uint64_t)frames*z,v->n))return false;for(at=h;frames;frames--,at+=z)if(!SA_ROW(hca_frame_sync,at,v->n)||!SA_ROW(hca_checksum,at+z-2,v->n))return false;return at==v->n;}
bool sx_audio_hca_build(sxau_view*v)
{
 return sxau_hca(v);
}
#undef SA_ROW
