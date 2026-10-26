/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * cineon data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_cineon_file_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("generic_header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("industry_header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("user_header_size","uint32",16,4,SX_SIZE),
    SX_FIELD("file_size","uint32",20,4,SX_SIZE),
    SX_FIELD("version","char[8]",24,8,SX_STRING),
    SX_FIELD("filename","char[100]",32,100,SX_STRING),
    SX_FIELD("creation_date","char[12]",132,12,SX_STRING),
    SX_FIELD("creation_time","char[12]",144,12,SX_STRING),
    SX_FIELD("reserved","uint8[36]",156,36,SX_RESERVED),
};
const sx_layout sxrm_cineon_file_header_be = {UINT32_C(0x601d0036),"cineon_file_header_be",sxrm_cineon_file_header_be_fields,SX_COUNT(sxrm_cineon_file_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_image_header_be_fields[] = {
    SX_FIELD("orientation","uint8",0,1,SX_ID),
    SX_FIELD("channel_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("reserved","uint8[2]",2,2,SX_RESERVED),
};
const sx_layout sxrm_cineon_image_header_be = {UINT32_C(0x601d0037),"cineon_image_header_be",sxrm_cineon_image_header_be_fields,SX_COUNT(sxrm_cineon_image_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_channel_be_fields[] = {
    SX_FIELD("designator0","uint8",0,1,SX_ID),
    SX_FIELD("designator1","uint8",1,1,SX_ID),
    SX_FIELD("bit_depth","uint8",2,1,SX_NONE),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("width","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("minimum_data","float32",12,4,SX_NONE),
    SX_FIELD("minimum_quantity","float32",16,4,SX_NONE),
    SX_FIELD("maximum_data","float32",20,4,SX_NONE),
    SX_FIELD("maximum_quantity","float32",24,4,SX_NONE),
};
const sx_layout sxrm_cineon_channel_be = {UINT32_C(0x601d0038),"cineon_channel_be",sxrm_cineon_channel_be_fields,SX_COUNT(sxrm_cineon_channel_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_color_be_fields[] = {
    SX_FIELD("white_x","float32",0,4,SX_NONE),
    SX_FIELD("white_y","float32",4,4,SX_NONE),
    SX_FIELD("red_x","float32",8,4,SX_NONE),
    SX_FIELD("red_y","float32",12,4,SX_NONE),
    SX_FIELD("green_x","float32",16,4,SX_NONE),
    SX_FIELD("green_y","float32",20,4,SX_NONE),
    SX_FIELD("blue_x","float32",24,4,SX_NONE),
    SX_FIELD("blue_y","float32",28,4,SX_NONE),
    SX_FIELD("label","char[200]",32,200,SX_STRING),
    SX_FIELD("reserved","uint8[28]",232,28,SX_RESERVED),
};
const sx_layout sxrm_cineon_color_be = {UINT32_C(0x601d0039),"cineon_color_be",sxrm_cineon_color_be_fields,SX_COUNT(sxrm_cineon_color_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_data_format_be_fields[] = {
    SX_FIELD("interleave","uint8",0,1,SX_ID),
    SX_FIELD("packing","uint8",1,1,SX_ID),
    SX_FIELD("data_sign","uint8",2,1,SX_ID),
    SX_FIELD("image_sense","uint8",3,1,SX_ID),
    SX_FIELD("line_padding","uint32",4,4,SX_SIZE),
    SX_FIELD("channel_padding","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint8[20]",12,20,SX_RESERVED),
};
const sx_layout sxrm_cineon_data_format_be = {UINT32_C(0x601d003a),"cineon_data_format_be",sxrm_cineon_data_format_be_fields,SX_COUNT(sxrm_cineon_data_format_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_origin_be_fields[] = {
    SX_FIELD("x_offset","int32",0,4,SX_NONE),
    SX_FIELD("y_offset","int32",4,4,SX_NONE),
    SX_FIELD("source_filename","char[100]",8,100,SX_STRING),
    SX_FIELD("source_date","char[12]",108,12,SX_STRING),
    SX_FIELD("source_time","char[12]",120,12,SX_STRING),
    SX_FIELD("input_device","char[64]",132,64,SX_STRING),
    SX_FIELD("input_model","char[32]",196,32,SX_STRING),
    SX_FIELD("input_serial","char[32]",228,32,SX_STRING),
    SX_FIELD("x_pitch","float32",260,4,SX_NONE),
    SX_FIELD("y_pitch","float32",264,4,SX_NONE),
    SX_FIELD("gamma","float32",268,4,SX_NONE),
    SX_FIELD("reserved","uint8[40]",272,40,SX_RESERVED),
};
const sx_layout sxrm_cineon_origin_be = {UINT32_C(0x601d003b),"cineon_origin_be",sxrm_cineon_origin_be_fields,SX_COUNT(sxrm_cineon_origin_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_film_be_fields[] = {
    SX_FIELD("manufacturer_id","uint8",0,1,SX_ID),
    SX_FIELD("film_type","uint8",1,1,SX_ID),
    SX_FIELD("perforation_offset","uint8",2,1,SX_NONE),
    SX_FIELD("reserved0","uint8",3,1,SX_RESERVED),
    SX_FIELD("prefix","uint32",4,4,SX_ID),
    SX_FIELD("count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("format","char[32]",12,32,SX_STRING),
    SX_FIELD("frame_position","uint32",44,4,SX_NONE),
    SX_FIELD("frame_rate","float32",48,4,SX_NONE),
    SX_FIELD("frame_id","char[32]",52,32,SX_STRING),
    SX_FIELD("slate","char[200]",84,200,SX_STRING),
    SX_FIELD("reserved1","uint8[740]",284,740,SX_RESERVED),
};
const sx_layout sxrm_cineon_film_be = {UINT32_C(0x601d003c),"cineon_film_be",sxrm_cineon_film_be_fields,SX_COUNT(sxrm_cineon_film_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_cineon_file_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("generic_header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("industry_header_size","uint32",12,4,SX_SIZE),
    SX_FIELD("user_header_size","uint32",16,4,SX_SIZE),
    SX_FIELD("file_size","uint32",20,4,SX_SIZE),
    SX_FIELD("version","char[8]",24,8,SX_STRING),
    SX_FIELD("filename","char[100]",32,100,SX_STRING),
    SX_FIELD("creation_date","char[12]",132,12,SX_STRING),
    SX_FIELD("creation_time","char[12]",144,12,SX_STRING),
    SX_FIELD("reserved","uint8[36]",156,36,SX_RESERVED),
};
const sx_layout sxrm_cineon_file_header_le = {UINT32_C(0x601d0044),"cineon_file_header_le",sxrm_cineon_file_header_le_fields,SX_COUNT(sxrm_cineon_file_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_image_header_le_fields[] = {
    SX_FIELD("orientation","uint8",0,1,SX_ID),
    SX_FIELD("channel_count","uint8",1,1,SX_COUNT_PROP),
    SX_FIELD("reserved","uint8[2]",2,2,SX_RESERVED),
};
const sx_layout sxrm_cineon_image_header_le = {UINT32_C(0x601d0045),"cineon_image_header_le",sxrm_cineon_image_header_le_fields,SX_COUNT(sxrm_cineon_image_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_channel_le_fields[] = {
    SX_FIELD("designator0","uint8",0,1,SX_ID),
    SX_FIELD("designator1","uint8",1,1,SX_ID),
    SX_FIELD("bit_depth","uint8",2,1,SX_NONE),
    SX_FIELD("reserved","uint8",3,1,SX_RESERVED),
    SX_FIELD("width","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("minimum_data","float32",12,4,SX_NONE),
    SX_FIELD("minimum_quantity","float32",16,4,SX_NONE),
    SX_FIELD("maximum_data","float32",20,4,SX_NONE),
    SX_FIELD("maximum_quantity","float32",24,4,SX_NONE),
};
const sx_layout sxrm_cineon_channel_le = {UINT32_C(0x601d0046),"cineon_channel_le",sxrm_cineon_channel_le_fields,SX_COUNT(sxrm_cineon_channel_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_color_le_fields[] = {
    SX_FIELD("white_x","float32",0,4,SX_NONE),
    SX_FIELD("white_y","float32",4,4,SX_NONE),
    SX_FIELD("red_x","float32",8,4,SX_NONE),
    SX_FIELD("red_y","float32",12,4,SX_NONE),
    SX_FIELD("green_x","float32",16,4,SX_NONE),
    SX_FIELD("green_y","float32",20,4,SX_NONE),
    SX_FIELD("blue_x","float32",24,4,SX_NONE),
    SX_FIELD("blue_y","float32",28,4,SX_NONE),
    SX_FIELD("label","char[200]",32,200,SX_STRING),
    SX_FIELD("reserved","uint8[28]",232,28,SX_RESERVED),
};
const sx_layout sxrm_cineon_color_le = {UINT32_C(0x601d0047),"cineon_color_le",sxrm_cineon_color_le_fields,SX_COUNT(sxrm_cineon_color_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_data_format_le_fields[] = {
    SX_FIELD("interleave","uint8",0,1,SX_ID),
    SX_FIELD("packing","uint8",1,1,SX_ID),
    SX_FIELD("data_sign","uint8",2,1,SX_ID),
    SX_FIELD("image_sense","uint8",3,1,SX_ID),
    SX_FIELD("line_padding","uint32",4,4,SX_SIZE),
    SX_FIELD("channel_padding","uint32",8,4,SX_SIZE),
    SX_FIELD("reserved","uint8[20]",12,20,SX_RESERVED),
};
const sx_layout sxrm_cineon_data_format_le = {UINT32_C(0x601d0048),"cineon_data_format_le",sxrm_cineon_data_format_le_fields,SX_COUNT(sxrm_cineon_data_format_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_origin_le_fields[] = {
    SX_FIELD("x_offset","int32",0,4,SX_NONE),
    SX_FIELD("y_offset","int32",4,4,SX_NONE),
    SX_FIELD("source_filename","char[100]",8,100,SX_STRING),
    SX_FIELD("source_date","char[12]",108,12,SX_STRING),
    SX_FIELD("source_time","char[12]",120,12,SX_STRING),
    SX_FIELD("input_device","char[64]",132,64,SX_STRING),
    SX_FIELD("input_model","char[32]",196,32,SX_STRING),
    SX_FIELD("input_serial","char[32]",228,32,SX_STRING),
    SX_FIELD("x_pitch","float32",260,4,SX_NONE),
    SX_FIELD("y_pitch","float32",264,4,SX_NONE),
    SX_FIELD("gamma","float32",268,4,SX_NONE),
    SX_FIELD("reserved","uint8[40]",272,40,SX_RESERVED),
};
const sx_layout sxrm_cineon_origin_le = {UINT32_C(0x601d0049),"cineon_origin_le",sxrm_cineon_origin_le_fields,SX_COUNT(sxrm_cineon_origin_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_cineon_film_le_fields[] = {
    SX_FIELD("manufacturer_id","uint8",0,1,SX_ID),
    SX_FIELD("film_type","uint8",1,1,SX_ID),
    SX_FIELD("perforation_offset","uint8",2,1,SX_NONE),
    SX_FIELD("reserved0","uint8",3,1,SX_RESERVED),
    SX_FIELD("prefix","uint32",4,4,SX_ID),
    SX_FIELD("count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("format","char[32]",12,32,SX_STRING),
    SX_FIELD("frame_position","uint32",44,4,SX_NONE),
    SX_FIELD("frame_rate","float32",48,4,SX_NONE),
    SX_FIELD("frame_id","char[32]",52,32,SX_STRING),
    SX_FIELD("slate","char[200]",84,200,SX_STRING),
    SX_FIELD("reserved1","uint8[740]",284,740,SX_RESERVED),
};
const sx_layout sxrm_cineon_film_le = {UINT32_C(0x601d004a),"cineon_film_le",sxrm_cineon_film_le_fields,SX_COUNT(sxrm_cineon_film_le_fields),SX_LE};
static bool sxrm_cineon(sx_context *c)
{
 uint8_t h[24];if(!sxrm_read(c,0,h,24))return false;bool be=sxrm32(h,true)==0x802a5fd7U;if(!be&&sxrm32(h,false)!=0x802a5fd7U)return false;
 if(!sxrm_add(c,be?&sxrm_cineon_file_header_be:&sxrm_cineon_file_header_le,0))return false;
 if(sxrm_span(c,192,4)&&!sxrm_add(c,be?&sxrm_cineon_image_header_be:&sxrm_cineon_image_header_le,192))return false;
 if(sxrm_span(c,196,224)&&!sxrm_table(c,be?&sxrm_cineon_channel_be:&sxrm_cineon_channel_le,196,8))return false;
 if(sxrm_span(c,420,260)&&!sxrm_add(c,be?&sxrm_cineon_color_be:&sxrm_cineon_color_le,420))return false;
 if(sxrm_span(c,680,32)&&!sxrm_add(c,be?&sxrm_cineon_data_format_be:&sxrm_cineon_data_format_le,680))return false;
 if(sxrm_span(c,712,312)&&!sxrm_add(c,be?&sxrm_cineon_origin_be:&sxrm_cineon_origin_le,712))return false;
 if(sxrm32(h+12,be)>=1024&&sxrm_span(c,1024,1024)&&!sxrm_add(c,be?&sxrm_cineon_film_be:&sxrm_cineon_film_le,1024))return false;return !c->failed;
}
bool sx_cineon_build(sx_context*c)
{
 return sxrm_cineon(c);
}
