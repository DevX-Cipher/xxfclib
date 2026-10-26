/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * swf data structures, moved out of the videotail schema family. */
#include "../../xx_format_schema_videotail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvt_swf_header_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("uncompressed_file_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxvt_swf_header = {UINT32_C(0x60390004),"swf_header",sxvt_swf_header_fields,SX_COUNT(sxvt_swf_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_lzma_header_fields[] = {
 SX_FIELD("compressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("lc_lp_pb","uint8",4,1,SX_FLAGS),
 SX_FIELD("dictionary_size","uint32",5,4,SX_SIZE),
};
const sx_layout sxvt_swf_lzma_header = {UINT32_C(0x60390005),"swf_lzma_header",sxvt_swf_lzma_header_fields,SX_COUNT(sxvt_swf_lzma_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect1_fields[] = {
 SX_FIELD("encoded_rect","uint8[1]",0,1,SX_NONE),
};
const sx_layout sxvt_swf_rect1 = {UINT32_C(0x60390006),"swf_rect1",sxvt_swf_rect1_fields,SX_COUNT(sxvt_swf_rect1_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect2_fields[] = {
 SX_FIELD("encoded_rect","uint8[2]",0,2,SX_NONE),
};
const sx_layout sxvt_swf_rect2 = {UINT32_C(0x60390007),"swf_rect2",sxvt_swf_rect2_fields,SX_COUNT(sxvt_swf_rect2_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect3_fields[] = {
 SX_FIELD("encoded_rect","uint8[3]",0,3,SX_NONE),
};
const sx_layout sxvt_swf_rect3 = {UINT32_C(0x60390008),"swf_rect3",sxvt_swf_rect3_fields,SX_COUNT(sxvt_swf_rect3_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect4_fields[] = {
 SX_FIELD("encoded_rect","uint8[4]",0,4,SX_NONE),
};
const sx_layout sxvt_swf_rect4 = {UINT32_C(0x60390009),"swf_rect4",sxvt_swf_rect4_fields,SX_COUNT(sxvt_swf_rect4_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect5_fields[] = {
 SX_FIELD("encoded_rect","uint8[5]",0,5,SX_NONE),
};
const sx_layout sxvt_swf_rect5 = {UINT32_C(0x6039000a),"swf_rect5",sxvt_swf_rect5_fields,SX_COUNT(sxvt_swf_rect5_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect6_fields[] = {
 SX_FIELD("encoded_rect","uint8[6]",0,6,SX_NONE),
};
const sx_layout sxvt_swf_rect6 = {UINT32_C(0x6039000b),"swf_rect6",sxvt_swf_rect6_fields,SX_COUNT(sxvt_swf_rect6_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect7_fields[] = {
 SX_FIELD("encoded_rect","uint8[7]",0,7,SX_NONE),
};
const sx_layout sxvt_swf_rect7 = {UINT32_C(0x6039000c),"swf_rect7",sxvt_swf_rect7_fields,SX_COUNT(sxvt_swf_rect7_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect8_fields[] = {
 SX_FIELD("encoded_rect","uint8[8]",0,8,SX_NONE),
};
const sx_layout sxvt_swf_rect8 = {UINT32_C(0x6039000d),"swf_rect8",sxvt_swf_rect8_fields,SX_COUNT(sxvt_swf_rect8_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect9_fields[] = {
 SX_FIELD("encoded_rect","uint8[9]",0,9,SX_NONE),
};
const sx_layout sxvt_swf_rect9 = {UINT32_C(0x6039000e),"swf_rect9",sxvt_swf_rect9_fields,SX_COUNT(sxvt_swf_rect9_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect10_fields[] = {
 SX_FIELD("encoded_rect","uint8[10]",0,10,SX_NONE),
};
const sx_layout sxvt_swf_rect10 = {UINT32_C(0x6039000f),"swf_rect10",sxvt_swf_rect10_fields,SX_COUNT(sxvt_swf_rect10_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect11_fields[] = {
 SX_FIELD("encoded_rect","uint8[11]",0,11,SX_NONE),
};
const sx_layout sxvt_swf_rect11 = {UINT32_C(0x60390010),"swf_rect11",sxvt_swf_rect11_fields,SX_COUNT(sxvt_swf_rect11_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect12_fields[] = {
 SX_FIELD("encoded_rect","uint8[12]",0,12,SX_NONE),
};
const sx_layout sxvt_swf_rect12 = {UINT32_C(0x60390011),"swf_rect12",sxvt_swf_rect12_fields,SX_COUNT(sxvt_swf_rect12_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect13_fields[] = {
 SX_FIELD("encoded_rect","uint8[13]",0,13,SX_NONE),
};
const sx_layout sxvt_swf_rect13 = {UINT32_C(0x60390012),"swf_rect13",sxvt_swf_rect13_fields,SX_COUNT(sxvt_swf_rect13_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect14_fields[] = {
 SX_FIELD("encoded_rect","uint8[14]",0,14,SX_NONE),
};
const sx_layout sxvt_swf_rect14 = {UINT32_C(0x60390013),"swf_rect14",sxvt_swf_rect14_fields,SX_COUNT(sxvt_swf_rect14_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect15_fields[] = {
 SX_FIELD("encoded_rect","uint8[15]",0,15,SX_NONE),
};
const sx_layout sxvt_swf_rect15 = {UINT32_C(0x60390014),"swf_rect15",sxvt_swf_rect15_fields,SX_COUNT(sxvt_swf_rect15_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect16_fields[] = {
 SX_FIELD("encoded_rect","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxvt_swf_rect16 = {UINT32_C(0x60390015),"swf_rect16",sxvt_swf_rect16_fields,SX_COUNT(sxvt_swf_rect16_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_rect17_fields[] = {
 SX_FIELD("encoded_rect","uint8[17]",0,17,SX_NONE),
};
const sx_layout sxvt_swf_rect17 = {UINT32_C(0x60390016),"swf_rect17",sxvt_swf_rect17_fields,SX_COUNT(sxvt_swf_rect17_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_movie_fields[] = {
 SX_FIELD("frame_rate_fixed8","uint16",0,2,SX_NONE),
 SX_FIELD("frame_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxvt_swf_movie = {UINT32_C(0x60390017),"swf_movie",sxvt_swf_movie_fields,SX_COUNT(sxvt_swf_movie_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_tag_short_fields[] = {
 SX_FIELD("code_and_length","uint16",0,2,SX_FLAGS),
};
const sx_layout sxvt_swf_tag_short = {UINT32_C(0x60390018),"swf_tag_short",sxvt_swf_tag_short_fields,SX_COUNT(sxvt_swf_tag_short_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_tag_long_fields[] = {
 SX_FIELD("code_and_length","uint16",0,2,SX_FLAGS),
 SX_FIELD("body_size","uint32",2,4,SX_SIZE),
};
const sx_layout sxvt_swf_tag_long = {UINT32_C(0x60390019),"swf_tag_long",sxvt_swf_tag_long_fields,SX_COUNT(sxvt_swf_tag_long_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_sprite_fields[] = {
 SX_FIELD("sprite_id","uint16",0,2,SX_ID),
 SX_FIELD("frame_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxvt_swf_sprite = {UINT32_C(0x6039001a),"swf_sprite",sxvt_swf_sprite_fields,SX_COUNT(sxvt_swf_sprite_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_background_fields[] = {
 SX_FIELD("red","uint8",0,1,SX_NONE),
 SX_FIELD("green","uint8",1,1,SX_NONE),
 SX_FIELD("blue","uint8",2,1,SX_NONE),
};
const sx_layout sxvt_swf_background = {UINT32_C(0x6039001b),"swf_background",sxvt_swf_background_fields,SX_COUNT(sxvt_swf_background_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_character_id_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
};
const sx_layout sxvt_swf_character_id = {UINT32_C(0x6039001c),"swf_character_id",sxvt_swf_character_id_fields,SX_COUNT(sxvt_swf_character_id_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_jpeg3_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
 SX_FIELD("alpha_data_offset","uint32",2,4,SX_OFFSET),
};
const sx_layout sxvt_swf_jpeg3 = {UINT32_C(0x6039001d),"swf_jpeg3",sxvt_swf_jpeg3_fields,SX_COUNT(sxvt_swf_jpeg3_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_jpeg4_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
 SX_FIELD("alpha_data_offset","uint32",2,4,SX_OFFSET),
 SX_FIELD("deblock_fixed8","uint16",6,2,SX_NONE),
};
const sx_layout sxvt_swf_jpeg4 = {UINT32_C(0x6039001e),"swf_jpeg4",sxvt_swf_jpeg4_fields,SX_COUNT(sxvt_swf_jpeg4_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_lossless_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
 SX_FIELD("bitmap_format","uint8",2,1,SX_ID),
 SX_FIELD("width","uint16",3,2,SX_NONE),
 SX_FIELD("height","uint16",5,2,SX_NONE),
};
const sx_layout sxvt_swf_lossless = {UINT32_C(0x6039001f),"swf_lossless",sxvt_swf_lossless_fields,SX_COUNT(sxvt_swf_lossless_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_palette_count_fields[] = {
 SX_FIELD("palette_count_minus_one","uint8",0,1,SX_NONE),
};
const sx_layout sxvt_swf_palette_count = {UINT32_C(0x60390020),"swf_palette_count",sxvt_swf_palette_count_fields,SX_COUNT(sxvt_swf_palette_count_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_sound_fields[] = {
 SX_FIELD("sound_id","uint16",0,2,SX_ID),
 SX_FIELD("sound_format_flags","uint8",2,1,SX_FLAGS),
 SX_FIELD("sample_count","uint32",3,4,SX_COUNT_PROP),
};
const sx_layout sxvt_swf_sound = {UINT32_C(0x60390021),"swf_sound",sxvt_swf_sound_fields,SX_COUNT(sxvt_swf_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_mp3_seek_fields[] = {
 SX_FIELD("seek_samples","int16",0,2,SX_NONE),
};
const sx_layout sxvt_swf_mp3_seek = {UINT32_C(0x60390022),"swf_mp3_seek",sxvt_swf_mp3_seek_fields,SX_COUNT(sxvt_swf_mp3_seek_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_stream_sound_fields[] = {
 SX_FIELD("playback_flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("stream_flags","uint8",1,1,SX_FLAGS),
 SX_FIELD("sample_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sxvt_swf_stream_sound = {UINT32_C(0x60390023),"swf_stream_sound",sxvt_swf_stream_sound_fields,SX_COUNT(sxvt_swf_stream_sound_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_binary_fields[] = {
 SX_FIELD("character_id","uint16",0,2,SX_ID),
 SX_FIELD("reserved","uint32",2,4,SX_RESERVED),
};
const sx_layout sxvt_swf_binary = {UINT32_C(0x60390024),"swf_binary",sxvt_swf_binary_fields,SX_COUNT(sxvt_swf_binary_fields),SX_LE};
static const xx_data_struct_field_desc sxvt_swf_file_attributes_fields[] = {
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
};
const sx_layout sxvt_swf_file_attributes = {UINT32_C(0x60390025),"swf_file_attributes",sxvt_swf_file_attributes_fields,SX_COUNT(sxvt_swf_file_attributes_fields),SX_LE};
#define SXVT_LIMIT 20000U
static bool sxvt_swftags(sx_context*c,uint64_t p,uint64_t end,unsigned depth){if(depth>16)return false;while(p<end&&c->count<SXVT_LIMIT){uint64_t h,n;unsigned z=2;if(end-p<2||!sxvt_word(c,p,2,false,&h))return false;n=h&63;if(n==63){z=6;if(end-p<6||!sxvt_word(c,p+2,4,false,&n))return false;}if(n>end-p-z)return false;if(!sxvt_add(c,z==2?&sxvt_swf_tag_short:&sxvt_swf_tag_long,p))return false;unsigned code=(unsigned)(h>>6);p+=z;uint64_t stop=p+n;const sx_layout*l=NULL;if(!code)return true;
 switch(code){case 39:if(n>=4){if(!sxvt_add(c,&sxvt_swf_sprite,p))return false;(void)sxvt_swftags(c,p+4,stop,depth+1);}break;case 9:if(n==3)l=&sxvt_swf_background;break;case 6:case 21:if(n>=2)l=&sxvt_swf_character_id;break;case 35:if(n>=6)l=&sxvt_swf_jpeg3;break;case 90:if(n>=8)l=&sxvt_swf_jpeg4;break;case 20:case 36:if(n>=7){uint8_t f;if(!sxvt_add(c,&sxvt_swf_lossless,p)||!sxvt_byte(c,p+2,&f))return false;if(f==3&&n>=8&&!sxvt_add(c,&sxvt_swf_palette_count,p+7))return false;}break;
 case 14:if(n>=7){uint8_t f;if(!sxvt_add(c,&sxvt_swf_sound,p)||!sxvt_byte(c,p+2,&f))return false;if((f>>4)==2&&n>=9&&!sxvt_add(c,&sxvt_swf_mp3_seek,p+7))return false;}break;
 case 18:case 45:if(n>=4){uint8_t f;if(!sxvt_add(c,&sxvt_swf_stream_sound,p)||!sxvt_byte(c,p+1,&f))return false;if((f>>4)==2&&n>=6&&!sxvt_add(c,&sxvt_swf_mp3_seek,p+4))return false;}break;case 69:if(n==4)l=&sxvt_swf_file_attributes;break;case 87:if(n>=6)l=&sxvt_swf_binary;break;default:break;}
 if(l&&!sxvt_add(c,l,p))return false;p=stop;}return p==end;}
static bool sxvt_swf(sx_context*c){uint8_t h[9];if(!sxvt_read(c,0,h,8)||!sxvt_add(c,&sxvt_swf_header,0))return false;if(h[0]=='Z')return sxvt_add(c,&sxvt_swf_lzma_header,8);if(h[0]!='F')return h[0]=='C';if(!sxvt_byte(c,8,h+8))return false;unsigned z=(5+4*(h[8]>>3)+7)/8;const sx_layout*const a[]={&sxvt_swf_rect1,&sxvt_swf_rect2,&sxvt_swf_rect3,&sxvt_swf_rect4,&sxvt_swf_rect5,&sxvt_swf_rect6,&sxvt_swf_rect7,&sxvt_swf_rect8,&sxvt_swf_rect9,&sxvt_swf_rect10,&sxvt_swf_rect11,&sxvt_swf_rect12,&sxvt_swf_rect13,&sxvt_swf_rect14,&sxvt_swf_rect15,&sxvt_swf_rect16,&sxvt_swf_rect17};if(!z||z>17||!sxvt_add(c,a[z-1],8)||!sxvt_add(c,&sxvt_swf_movie,8+z))return false;uint64_t end=sxvt_uint(h+4,4,false);if(end>(uint64_t)c->size)end=(uint64_t)c->size;return sxvt_swftags(c,12+z,end,0);}
bool sx_swf_build(sx_context*c)
{
 return sxvt_swf(c);
}
