/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SCUMM SOU data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_sou_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("reserved","uint32",4,4,SX_RESERVED),
};
const sx_layout sxarm_sou_header={UINT32_C(0x607c001e),"sou_header",sxarm_sou_header_fields,SX_COUNT(sxarm_sou_header_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_sou_chunk_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("total_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxarm_sou_chunk={UINT32_C(0x607c001f),"sou_chunk",sxarm_sou_chunk_fields,SX_COUNT(sxarm_sou_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_sou_mouth_sync_fields[]={
 SX_FIELD("mouth_sync_time","uint16",0,2,SX_NONE),
};
const sx_layout sxarm_sou_mouth_sync={UINT32_C(0x607c0020),"sou_mouth_sync",sxarm_sou_mouth_sync_fields,SX_COUNT(sxarm_sou_mouth_sync_fields),SX_BE};
static const xx_data_struct_field_desc sxarm_sou_voc_header_fields[]={
 SX_FIELD("signature","char[20]",0,20,SX_SIGNATURE),
 SX_FIELD("header_size","uint16",20,2,SX_SIZE),
 SX_FIELD("version","uint16",22,2,SX_NONE),
 SX_FIELD("version_checksum","uint16",24,2,SXARM_CHECKSUM),
};
const sx_layout sxarm_sou_voc_header={UINT32_C(0x607c0021),"sou_voc_header",sxarm_sou_voc_header_fields,SX_COUNT(sxarm_sou_voc_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_end_fields[]={
 SX_FIELD("block_type","uint8",0,1,SX_ID),
};
const sx_layout sxarm_sou_voc_end={UINT32_C(0x607c0023),"sou_voc_end",sxarm_sou_voc_end_fields,SX_COUNT(sxarm_sou_voc_end_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_sound_fields[]={
 SX_FIELD("time_constant","uint8",0,1,SX_NONE),
 SX_FIELD("codec","uint8",1,1,SX_ID),
};
const sx_layout sxarm_sou_voc_sound={UINT32_C(0x607c0024),"sou_voc_sound",sxarm_sou_voc_sound_fields,SX_COUNT(sxarm_sou_voc_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_silence_fields[]={
 SX_FIELD("duration_minus_one","uint16",0,2,SX_NONE),
 SX_FIELD("time_constant","uint8",2,1,SX_NONE),
};
const sx_layout sxarm_sou_voc_silence={UINT32_C(0x607c0025),"sou_voc_silence",sxarm_sou_voc_silence_fields,SX_COUNT(sxarm_sou_voc_silence_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_marker_fields[]={
 SX_FIELD("marker","uint16",0,2,SX_ID),
};
const sx_layout sxarm_sou_voc_marker={UINT32_C(0x607c0026),"sou_voc_marker",sxarm_sou_voc_marker_fields,SX_COUNT(sxarm_sou_voc_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_repeat_fields[]={
 SX_FIELD("repeat_count","uint16",0,2,SX_NONE),
};
const sx_layout sxarm_sou_voc_repeat={UINT32_C(0x607c0027),"sou_voc_repeat",sxarm_sou_voc_repeat_fields,SX_COUNT(sxarm_sou_voc_repeat_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_extended_fields[]={
 SX_FIELD("time_constant","uint16",0,2,SX_NONE),
 SX_FIELD("codec","uint8",2,1,SX_ID),
 SX_FIELD("channel_mode","uint8",3,1,SX_NONE),
};
const sx_layout sxarm_sou_voc_extended={UINT32_C(0x607c0028),"sou_voc_extended",sxarm_sou_voc_extended_fields,SX_COUNT(sxarm_sou_voc_extended_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_sou_voc_new_sound_fields[]={
 SX_FIELD("sample_rate","uint32",0,4,SX_NONE),
 SX_FIELD("bits_per_sample","uint8",4,1,SX_NONE),
 SX_FIELD("channels","uint8",5,1,SX_COUNT_PROP),
 SX_FIELD("codec","uint16",6,2,SX_ID),
 SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
const sx_layout sxarm_sou_voc_new_sound={UINT32_C(0x607c0029),"sou_voc_new_sound",sxarm_sou_voc_new_sound_fields,SX_COUNT(sxarm_sou_voc_new_sound_fields),SX_LE};
static bool sxarm_voc(sx_context*c,uint64_t p,uint64_t end,uint64_t*next){uint64_t z,t;if(p>end||end-p<26||!sxarm_add(c,&sxarm_sou_voc_header,p)||!sxarm_word(c,p+20,2,false,&z)||z<26||z>end-p)return false;p+=z;for(unsigned i=0;p<end&&i<4096;i++){if(!sxarm_word(c,p,1,false,&t))return false;if(!t){if(!sxarm_add(c,&sxarm_sou_voc_end,p))return false;*next=p+1;return true;}if(end-p<4||!sxarm_word(c,p+1,3,false,&z)||z>end-p-4||!sxarm_add(c,&sxarm_sou_voc_block,p))return false;p+=4;const sx_layout*l=NULL;unsigned min=0;switch(t){case 1:l=&sxarm_sou_voc_sound;min=2;break;case 3:l=&sxarm_sou_voc_silence;min=3;break;case 4:l=&sxarm_sou_voc_marker;min=2;break;case 6:l=&sxarm_sou_voc_repeat;min=2;break;case 8:l=&sxarm_sou_voc_extended;min=4;break;case 9:l=&sxarm_sou_voc_new_sound;min=12;break;default:break;}if(l&&z>=min&&!sxarm_add(c,l,p))return false;p+=z;}return false;}
static bool sxarm_sou(sx_context*c){uint8_t root[8];if(!sxarm_read(c,0,root,8)||xx_rt_memcmp(root,"SOU \0\0\0\0",8))return false;if(!sxarm_add(c,&sxarm_sou_header,0))return false;uint64_t p=8,end=(uint64_t)c->size,z,next;uint8_t tag[4];while(p<end){if(!sxarm_add(c,&sxarm_sou_chunk,p)||!sxarm_word(c,p+4,4,true,&z)||z<8||z>end-p)return false;if(!sxarm_table(c,&sxarm_sou_mouth_sync,p+8,2,(z-8)/2))return false;p+=z;if(p==end)return true;if(!sxarm_read(c,p,tag,4))return false;if(!xx_rt_memcmp(tag,"VTLK",4)){if(!sxarm_add(c,&sxarm_sou_chunk,p)||!sxarm_word(c,p+4,4,true,&z)||z<8||z>end-p||!sxarm_voc(c,p+8,p+z,&next))return false;p+=z;}else{if(!sxarm_voc(c,p,end,&next))return false;p=next;}}return true;}
bool sx_audio_scumm_sou_build(sx_context*c)
{
 return sxarm_sou(c);
}
