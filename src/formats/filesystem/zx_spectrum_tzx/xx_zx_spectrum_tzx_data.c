/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Zx Spectrum Tzx data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_tzx_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("version_major","uint8",8,1,SX_NONE),
    SX_FIELD("version_minor","uint8",9,1,SX_NONE),
};
const sx_layout sxse_tzx_header = {0x602f000bU,"tzx_header",sxse_tzx_header_fields,SX_COUNT(sxse_tzx_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_standard_data_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
    SX_FIELD("pause_milliseconds","uint16",1,2,SX_NONE),
    SX_FIELD("data_size","uint16",3,2,SX_SIZE),
};
const sx_layout sxse_tzx_standard_data = {0x602f000cU,"tzx_standard_data",sxse_tzx_standard_data_fields,SX_COUNT(sxse_tzx_standard_data_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_turbo_data_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
    SX_FIELD("pilot_pulse_ticks","uint16",1,2,SX_NONE),
    SX_FIELD("sync_first_ticks","uint16",3,2,SX_NONE),
    SX_FIELD("sync_second_ticks","uint16",5,2,SX_NONE),
    SX_FIELD("zero_bit_ticks","uint16",7,2,SX_NONE),
    SX_FIELD("one_bit_ticks","uint16",9,2,SX_NONE),
    SX_FIELD("pilot_pulse_count","uint16",11,2,SX_COUNT_PROP),
    SX_FIELD("last_byte_used_bits","uint8",13,1,SX_NONE),
    SX_FIELD("pause_milliseconds","uint16",14,2,SX_NONE),
    SX_FIELD("data_size","uint24",16,3,SX_SIZE),
};
const sx_layout sxse_tzx_turbo_data = {0x602f000dU,"tzx_turbo_data",sxse_tzx_turbo_data_fields,SX_COUNT(sxse_tzx_turbo_data_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_pure_tone_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
    SX_FIELD("pulse_ticks","uint16",1,2,SX_NONE),
    SX_FIELD("pulse_count","uint16",3,2,SX_COUNT_PROP),
};
const sx_layout sxse_tzx_pure_tone = {0x602f000eU,"tzx_pure_tone",sxse_tzx_pure_tone_fields,SX_COUNT(sxse_tzx_pure_tone_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_pulse_sequence_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
    SX_FIELD("pulse_count","uint8",1,1,SX_COUNT_PROP),
};
const sx_layout sxse_tzx_pulse_sequence = {0x602f000fU,"tzx_pulse_sequence",sxse_tzx_pulse_sequence_fields,SX_COUNT(sxse_tzx_pulse_sequence_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_pulse_fields[] = {
    SX_FIELD("duration_ticks","uint16",0,2,SX_NONE),
};
const sx_layout sxse_tzx_pulse = {0x602f0010U,"tzx_pulse",sxse_tzx_pulse_fields,SX_COUNT(sxse_tzx_pulse_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_pure_data_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
    SX_FIELD("zero_bit_ticks","uint16",1,2,SX_NONE),
    SX_FIELD("one_bit_ticks","uint16",3,2,SX_NONE),
    SX_FIELD("last_byte_used_bits","uint8",5,1,SX_NONE),
    SX_FIELD("pause_milliseconds","uint16",6,2,SX_NONE),
    SX_FIELD("data_size","uint24",8,3,SX_SIZE),
};
const sx_layout sxse_tzx_pure_data = {0x602f0011U,"tzx_pure_data",sxse_tzx_pure_data_fields,SX_COUNT(sxse_tzx_pure_data_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_pause_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
    SX_FIELD("pause_milliseconds","uint16",1,2,SX_NONE),
};
const sx_layout sxse_tzx_pause = {0x602f0012U,"tzx_pause",sxse_tzx_pause_fields,SX_COUNT(sxse_tzx_pause_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_text_header_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
    SX_FIELD("text_size","uint8",1,1,SX_SIZE),
};
const sx_layout sxse_tzx_text_header = {0x602f0013U,"tzx_text_header",sxse_tzx_text_header_fields,SX_COUNT(sxse_tzx_text_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_group_end_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
};
const sx_layout sxse_tzx_group_end = {0x602f0014U,"tzx_group_end",sxse_tzx_group_end_fields,SX_COUNT(sxse_tzx_group_end_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_archive_info_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
    SX_FIELD("data_size","uint16",1,2,SX_SIZE),
    SX_FIELD("string_count","uint8",3,1,SX_COUNT_PROP),
};
const sx_layout sxse_tzx_archive_info = {0x602f0015U,"tzx_archive_info",sxse_tzx_archive_info_fields,SX_COUNT(sxse_tzx_archive_info_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_archive_string_fields[] = {
    SX_FIELD("text_id","uint8",0,1,SX_ID),
    SX_FIELD("text_size","uint8",1,1,SX_SIZE),
};
const sx_layout sxse_tzx_archive_string = {0x602f0016U,"tzx_archive_string",sxse_tzx_archive_string_fields,SX_COUNT(sxse_tzx_archive_string_fields),SX_LE};
static const xx_data_struct_field_desc sxse_tzx_custom_info_fields[] = {
    SX_FIELD("block_id","uint8",0,1,SX_ID),
    SX_FIELD("identifier","char[16]",1,16,SX_STRING),
    SX_FIELD("data_size","uint32",17,4,SX_SIZE),
};
const sx_layout sxse_tzx_custom_info = {0x602f0017U,"tzx_custom_info",sxse_tzx_custom_info_fields,SX_COUNT(sxse_tzx_custom_info_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
#define SXSE_TABLE(c,l,p,z,n) sxse_put(c,&sxse_##l,p,z,n)
static bool sxse_tzx(sx_context*c){uint8_t b[21];uint64_t p=10,end=(uint64_t)c->size;unsigned group=0;if(!sxse_read(c,0,b,10)||xx_rt_memcmp(b,"ZXTape!\x1a",8)||!SXSE_ADD(c,tzx_header,0,10))return false;
 for(unsigned visit=0;p<end&&visit<4095;visit++){if(!sxse_read(c,p,b,1))return false;const sx_layout*l=NULL;uint64_t z=0,data=0;switch(b[0]){
 case 0x10:l=&sxse_tzx_standard_data;z=5;break;case 0x11:l=&sxse_tzx_turbo_data;z=19;break;case 0x12:l=&sxse_tzx_pure_tone;z=5;break;case 0x13:l=&sxse_tzx_pulse_sequence;z=2;break;case 0x14:l=&sxse_tzx_pure_data;z=11;break;case 0x20:l=&sxse_tzx_pause;z=3;break;case 0x21:if(++group>16)return false;/* fallthrough */case 0x30:l=&sxse_tzx_text_header;z=2;break;case 0x22:if(!group)return false;group--;l=&sxse_tzx_group_end;z=1;break;case 0x32:l=&sxse_tzx_archive_info;z=4;break;case 0x35:l=&sxse_tzx_custom_info;z=21;break;default:return false;}
 if(!sxse_read(c,p,b,(size_t)z)||!sxse_put(c,l,p,z,1))return false;
 switch(b[0]){case 0x10:data=sxse_u16(b,3,false);break;case 0x11:data=(uint32_t)b[16]|((uint32_t)b[17]<<8)|((uint32_t)b[18]<<16);break;case 0x13:data=2*(uint64_t)b[1];if(!SXSE_TABLE(c,tzx_pulse,p+z,2,b[1]))return false;break;case 0x14:data=(uint32_t)b[8]|((uint32_t)b[9]<<8)|((uint32_t)b[10]<<16);break;case 0x21:case 0x30:data=b[1];break;case 0x35:data=sxse_u32(b,17,false);break;case 0x32:{uint64_t len=sxse_u16(b,1,false);unsigned n=b[3];if(!len||!sxse_span(c,p+3,len))return false;uint64_t q=p+4,limit=p+3+len;for(unsigned i=0;i<n;i++){if(limit-q<2||!sxse_read(c,q,b,2)||!SXSE_ADD(c,tzx_archive_string,q,2)||b[1]>limit-q-2)return false;q+=2+b[1];}if(q!=limit)return false;data=len-1;break;}default:break;}
 if(!sxse_span(c,p+z,data))return false;p+=z+data;
 }return p==end&&!group&&p>10;}
bool sx_zx_spectrum_tzx_build(sx_context*c)
{
 return sxse_tzx(c);
}
#undef SXSE_ADD
#undef SXSE_TABLE
