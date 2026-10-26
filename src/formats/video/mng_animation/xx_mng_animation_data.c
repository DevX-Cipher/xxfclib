/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MNG ANIMATION data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_mng_signature_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
};
const sx_layout sxnx_mng_signature={UINT32_C(0x603200C7),"mng_signature",sxnx_mng_signature_fields,SX_COUNT(sxnx_mng_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_chunk_fields[]={
 SX_FIELD("data_size","uint32",0,4,SX_SIZE),
 SX_FIELD("chunk_type","bytes",4,4,SX_ID),
};
const sx_layout sxnx_mng_chunk={UINT32_C(0x603200C8),"mng_chunk",sxnx_mng_chunk_fields,SX_COUNT(sxnx_mng_chunk_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_crc_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxnx_mng_crc={UINT32_C(0x603200C9),"mng_crc",sxnx_mng_crc_fields,SX_COUNT(sxnx_mng_crc_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_header_fields[]={
 SX_FIELD("width","uint32",0,4,SX_NONE),
 SX_FIELD("height","uint32",4,4,SX_NONE),
 SX_FIELD("ticks_per_second","uint32",8,4,SX_NONE),
 SX_FIELD("nominal_layer_count","uint32",12,4,SX_COUNT_PROP),
 SX_FIELD("nominal_frame_count","uint32",16,4,SX_COUNT_PROP),
 SX_FIELD("nominal_play_time_ticks","uint32",20,4,SX_NONE),
 SX_FIELD("simplicity_profile","uint32",24,4,SX_FLAGS),
};
const sx_layout sxnx_mng_header={UINT32_C(0x603200CA),"mng_header",sxnx_mng_header_fields,SX_COUNT(sxnx_mng_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_png_header_fields[]={
 SX_FIELD("width","uint32",0,4,SX_NONE),
 SX_FIELD("height","uint32",4,4,SX_NONE),
 SX_FIELD("depth","uint8",8,1,SX_NONE),
 SX_FIELD("color_type","uint8",9,1,SX_ID),
 SX_FIELD("compression","uint8",10,1,SX_ID),
 SX_FIELD("filter","uint8",11,1,SX_ID),
 SX_FIELD("interlace","uint8",12,1,SX_ID),
};
const sx_layout sxnx_mng_png_header={UINT32_C(0x603200CB),"mng_png_header",sxnx_mng_png_header_fields,SX_COUNT(sxnx_mng_png_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_gray_fields[]={
 SX_FIELD("gray","uint16",0,2,SX_NONE),
};
const sx_layout sxnx_mng_gray={UINT32_C(0x603200CC),"mng_gray",sxnx_mng_gray_fields,SX_COUNT(sxnx_mng_gray_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_rgb_fields[]={
 SX_FIELD("red","uint16",0,2,SX_NONE),
 SX_FIELD("green","uint16",2,2,SX_NONE),
 SX_FIELD("blue","uint16",4,2,SX_NONE),
};
const sx_layout sxnx_mng_rgb={UINT32_C(0x603200CD),"mng_rgb",sxnx_mng_rgb_fields,SX_COUNT(sxnx_mng_rgb_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_palette_index_fields[]={
 SX_FIELD("index","uint8",0,1,SX_ID),
};
const sx_layout sxnx_mng_palette_index={UINT32_C(0x603200CE),"mng_palette_index",sxnx_mng_palette_index_fields,SX_COUNT(sxnx_mng_palette_index_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_alpha_fields[]={
 SX_FIELD("alpha","uint8",0,1,SX_NONE),
};
const sx_layout sxnx_mng_alpha={UINT32_C(0x603200CF),"mng_alpha",sxnx_mng_alpha_fields,SX_COUNT(sxnx_mng_alpha_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_gamma_fields[]={
 SX_FIELD("gamma_100000","uint32",0,4,SX_NONE),
};
const sx_layout sxnx_mng_gamma={UINT32_C(0x603200D0),"mng_gamma",sxnx_mng_gamma_fields,SX_COUNT(sxnx_mng_gamma_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_chromaticity_fields[]={
 SX_FIELD("white_x_100000","uint32",0,4,SX_NONE),
 SX_FIELD("white_y_100000","uint32",4,4,SX_NONE),
 SX_FIELD("red_x_100000","uint32",8,4,SX_NONE),
 SX_FIELD("red_y_100000","uint32",12,4,SX_NONE),
 SX_FIELD("green_x_100000","uint32",16,4,SX_NONE),
 SX_FIELD("green_y_100000","uint32",20,4,SX_NONE),
 SX_FIELD("blue_x_100000","uint32",24,4,SX_NONE),
 SX_FIELD("blue_y_100000","uint32",28,4,SX_NONE),
};
const sx_layout sxnx_mng_chromaticity={UINT32_C(0x603200D1),"mng_chromaticity",sxnx_mng_chromaticity_fields,SX_COUNT(sxnx_mng_chromaticity_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_srgb_fields[]={
 SX_FIELD("rendering_intent","uint8",0,1,SX_ID),
};
const sx_layout sxnx_mng_srgb={UINT32_C(0x603200D2),"mng_srgb",sxnx_mng_srgb_fields,SX_COUNT(sxnx_mng_srgb_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_physical_fields[]={
 SX_FIELD("horizontal_pixels","uint32",0,4,SX_NONE),
 SX_FIELD("vertical_pixels","uint32",4,4,SX_NONE),
 SX_FIELD("unit","uint8",8,1,SX_ID),
};
const sx_layout sxnx_mng_physical={UINT32_C(0x603200D3),"mng_physical",sxnx_mng_physical_fields,SX_COUNT(sxnx_mng_physical_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_term_fields[]={
 SX_FIELD("termination_action","uint8",0,1,SX_ID),
};
const sx_layout sxnx_mng_term={UINT32_C(0x603200D4),"mng_term",sxnx_mng_term_fields,SX_COUNT(sxnx_mng_term_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_fram_fields[]={
 SX_FIELD("framing_mode","uint8",0,1,SX_ID),
};
const sx_layout sxnx_mng_fram={UINT32_C(0x603200D5),"mng_fram",sxnx_mng_fram_fields,SX_COUNT(sxnx_mng_fram_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_mng_defi_fields[]={
 SX_FIELD("object_id","uint16",0,2,SX_ID),
};
const sx_layout sxnx_mng_defi={UINT32_C(0x603200D6),"mng_defi",sxnx_mng_defi_fields,SX_COUNT(sxnx_mng_defi_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_mng_back_flag_fields[]={
 SX_FIELD("mandatory","uint8",0,1,SX_FLAGS),
};
const sx_layout sxnx_mng_back_flag={UINT32_C(0x603200D7),"mng_back_flag",sxnx_mng_back_flag_fields,SX_COUNT(sxnx_mng_back_flag_fields),SX_LE};
#define SN_ROW(l,at,end) sxnx_row(v,&sxnx_##l,(at),(end))
static bool sxnx_mng(sxnx_view*v)
{if(!SN_ROW(mng_signature,0,v->n))return false;size_t p=8;unsigned color=0;while(p<v->n){if(!SN_ROW(mng_chunk,p,v->n))return false;unsigned z=sxnx_u32(v->p+p,true),id=sxnx_u32(v->p+p+4,true);p+=8;if(!sxnx_need(v,p,(uint64_t)z+4,v->n)||!SN_ROW(mng_crc,p+z,v->n))return false;const sx_layout*l=NULL;
 switch(id){case 0x4d484452:l=&sxnx_mng_header;break;case 0x49484452:l=&sxnx_mng_png_header;if(!sxnx_need(v,p,13,p+z))return false;color=v->p[p+9];break;case 0x504c5445:if(z%3||!sxnx_table(v,&sxnx_rgb_palette_entry,p,z/3,p+z))return false;break;case 0x74524e53:if(color==3){if(!sxnx_table(v,&sxnx_mng_alpha,p,z,p+z))return false;}else l=color==0?&sxnx_mng_gray:&sxnx_mng_rgb;break;case 0x624b4744:l=color==3?&sxnx_mng_palette_index:color==0||color==4?&sxnx_mng_gray:&sxnx_mng_rgb;break;case 0x67414d41:l=&sxnx_mng_gamma;break;case 0x6348524d:l=&sxnx_mng_chromaticity;break;case 0x73524742:l=&sxnx_mng_srgb;break;case 0x70485973:l=&sxnx_mng_physical;break;case 0x5445524d:l=&sxnx_mng_term;break;case 0x4652414d:l=&sxnx_mng_fram;break;case 0x44454649:l=&sxnx_mng_defi;break;case 0x4241434b:l=&sxnx_mng_rgb;if(z==7&&!SN_ROW(mng_back_flag,p+6,p+z))return false;break;default:break;}
 if(l&&!sxnx_row(v,l,p,p+z))return false;p+=z+4;}return true;}
bool sx_mng_animation_build(sxnx_view*v)
{
 return sxnx_mng(v);
}
#undef SN_ROW
