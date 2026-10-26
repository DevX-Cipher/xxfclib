/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * dpx data structures, moved out of the rastermore schema family. */
#include "../../xx_format_schema_rastermore.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxrm_dpx_file_header_be_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("version","char[8]",8,8,SX_STRING),
    SX_FIELD("file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("ditto_key","uint32",20,4,SX_ID),
    SX_FIELD("generic_header_size","uint32",24,4,SX_SIZE),
    SX_FIELD("industry_header_size","uint32",28,4,SX_SIZE),
    SX_FIELD("user_header_size","uint32",32,4,SX_SIZE),
    SX_FIELD("filename","char[100]",36,100,SX_STRING),
    SX_FIELD("creation_time","char[24]",136,24,SX_STRING),
    SX_FIELD("creator","char[100]",160,100,SX_STRING),
    SX_FIELD("project","char[200]",260,200,SX_STRING),
    SX_FIELD("copyright","char[200]",460,200,SX_STRING),
    SX_FIELD("encryption_key","uint32",660,4,SX_ID),
    SX_FIELD("reserved","uint8[104]",664,104,SX_RESERVED),
};
const sx_layout sxrm_dpx_file_header_be = {UINT32_C(0x601d002f),"dpx_file_header_be",sxrm_dpx_file_header_be_fields,SX_COUNT(sxrm_dpx_file_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_image_header_be_fields[] = {
    SX_FIELD("orientation","uint16",0,2,SX_ID),
    SX_FIELD("element_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("pixels_per_line","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("lines_per_element","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxrm_dpx_image_header_be = {UINT32_C(0x601d0030),"dpx_image_header_be",sxrm_dpx_image_header_be_fields,SX_COUNT(sxrm_dpx_image_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_element_be_fields[] = {
    SX_FIELD("data_sign","uint32",0,4,SX_ID),
    SX_FIELD("reference_low_data","uint32",4,4,SX_NONE),
    SX_FIELD("reference_low_quantity","float32",8,4,SX_NONE),
    SX_FIELD("reference_high_data","uint32",12,4,SX_NONE),
    SX_FIELD("reference_high_quantity","float32",16,4,SX_NONE),
    SX_FIELD("descriptor","uint8",20,1,SX_ID),
    SX_FIELD("transfer_characteristic","uint8",21,1,SX_ID),
    SX_FIELD("colorimetric","uint8",22,1,SX_ID),
    SX_FIELD("bit_depth","uint8",23,1,SX_NONE),
    SX_FIELD("packing","uint16",24,2,SX_ID),
    SX_FIELD("encoding","uint16",26,2,SX_ID),
    SX_FIELD("data_offset","uint32",28,4,SX_OFFSET),
    SX_FIELD("end_of_line_padding","uint32",32,4,SX_SIZE),
    SX_FIELD("end_of_image_padding","uint32",36,4,SX_SIZE),
    SX_FIELD("description","char[32]",40,32,SX_STRING),
};
const sx_layout sxrm_dpx_element_be = {UINT32_C(0x601d0031),"dpx_element_be",sxrm_dpx_element_be_fields,SX_COUNT(sxrm_dpx_element_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_image_reserved_be_fields[] = {
    SX_FIELD("reserved","uint8[52]",0,52,SX_RESERVED),
};
const sx_layout sxrm_dpx_image_reserved_be = {UINT32_C(0x601d0032),"dpx_image_reserved_be",sxrm_dpx_image_reserved_be_fields,SX_COUNT(sxrm_dpx_image_reserved_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_orientation_be_fields[] = {
    SX_FIELD("x_offset","uint32",0,4,SX_NONE),
    SX_FIELD("y_offset","uint32",4,4,SX_NONE),
    SX_FIELD("x_center","float32",8,4,SX_NONE),
    SX_FIELD("y_center","float32",12,4,SX_NONE),
    SX_FIELD("original_width","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("original_height","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("source_filename","char[100]",24,100,SX_STRING),
    SX_FIELD("source_creation_time","char[24]",124,24,SX_STRING),
    SX_FIELD("input_device","char[32]",148,32,SX_STRING),
    SX_FIELD("input_serial","char[32]",180,32,SX_STRING),
    SX_FIELD("border_validity","uint16[4]",212,8,SX_NONE),
    SX_FIELD("pixel_aspect_horizontal","uint32",220,4,SX_NONE),
    SX_FIELD("pixel_aspect_vertical","uint32",224,4,SX_NONE),
    SX_FIELD("reserved","uint8[28]",228,28,SX_RESERVED),
};
const sx_layout sxrm_dpx_orientation_be = {UINT32_C(0x601d0033),"dpx_orientation_be",sxrm_dpx_orientation_be_fields,SX_COUNT(sxrm_dpx_orientation_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_film_be_fields[] = {
    SX_FIELD("manufacturer_id","char[2]",0,2,SX_STRING),
    SX_FIELD("film_type","char[2]",2,2,SX_STRING),
    SX_FIELD("perforation_offset","char[2]",4,2,SX_STRING),
    SX_FIELD("prefix","char[6]",6,6,SX_STRING),
    SX_FIELD("count","char[4]",12,4,SX_STRING),
    SX_FIELD("format","char[32]",16,32,SX_STRING),
    SX_FIELD("frame_position","uint32",48,4,SX_NONE),
    SX_FIELD("sequence_extent","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("held_count","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("frame_rate","float32",60,4,SX_NONE),
    SX_FIELD("shutter_angle","float32",64,4,SX_NONE),
    SX_FIELD("frame_id","char[32]",68,32,SX_STRING),
    SX_FIELD("slate","char[100]",100,100,SX_STRING),
    SX_FIELD("reserved","uint8[56]",200,56,SX_RESERVED),
};
const sx_layout sxrm_dpx_film_be = {UINT32_C(0x601d0034),"dpx_film_be",sxrm_dpx_film_be_fields,SX_COUNT(sxrm_dpx_film_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_television_be_fields[] = {
    SX_FIELD("time_code","uint32",0,4,SX_NONE),
    SX_FIELD("user_bits","uint32",4,4,SX_FLAGS),
    SX_FIELD("interlace","uint8",8,1,SX_ID),
    SX_FIELD("field_number","uint8",9,1,SX_ID),
    SX_FIELD("video_signal","uint8",10,1,SX_ID),
    SX_FIELD("padding","uint8",11,1,SX_RESERVED),
    SX_FIELD("horizontal_sample_rate","float32",12,4,SX_NONE),
    SX_FIELD("vertical_sample_rate","float32",16,4,SX_NONE),
    SX_FIELD("frame_rate","float32",20,4,SX_NONE),
    SX_FIELD("time_offset","float32",24,4,SX_NONE),
    SX_FIELD("gamma","float32",28,4,SX_NONE),
    SX_FIELD("black_level","float32",32,4,SX_NONE),
    SX_FIELD("black_gain","float32",36,4,SX_NONE),
    SX_FIELD("break_point","float32",40,4,SX_NONE),
    SX_FIELD("white_level","float32",44,4,SX_NONE),
    SX_FIELD("integration_time","float32",48,4,SX_NONE),
    SX_FIELD("reserved","uint8[76]",52,76,SX_RESERVED),
};
const sx_layout sxrm_dpx_television_be = {UINT32_C(0x601d0035),"dpx_television_be",sxrm_dpx_television_be_fields,SX_COUNT(sxrm_dpx_television_be_fields),SX_BE};
static const xx_data_struct_field_desc sxrm_dpx_file_header_le_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("image_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("version","char[8]",8,8,SX_STRING),
    SX_FIELD("file_size","uint32",16,4,SX_SIZE),
    SX_FIELD("ditto_key","uint32",20,4,SX_ID),
    SX_FIELD("generic_header_size","uint32",24,4,SX_SIZE),
    SX_FIELD("industry_header_size","uint32",28,4,SX_SIZE),
    SX_FIELD("user_header_size","uint32",32,4,SX_SIZE),
    SX_FIELD("filename","char[100]",36,100,SX_STRING),
    SX_FIELD("creation_time","char[24]",136,24,SX_STRING),
    SX_FIELD("creator","char[100]",160,100,SX_STRING),
    SX_FIELD("project","char[200]",260,200,SX_STRING),
    SX_FIELD("copyright","char[200]",460,200,SX_STRING),
    SX_FIELD("encryption_key","uint32",660,4,SX_ID),
    SX_FIELD("reserved","uint8[104]",664,104,SX_RESERVED),
};
const sx_layout sxrm_dpx_file_header_le = {UINT32_C(0x601d003d),"dpx_file_header_le",sxrm_dpx_file_header_le_fields,SX_COUNT(sxrm_dpx_file_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_image_header_le_fields[] = {
    SX_FIELD("orientation","uint16",0,2,SX_ID),
    SX_FIELD("element_count","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("pixels_per_line","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("lines_per_element","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sxrm_dpx_image_header_le = {UINT32_C(0x601d003e),"dpx_image_header_le",sxrm_dpx_image_header_le_fields,SX_COUNT(sxrm_dpx_image_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_element_le_fields[] = {
    SX_FIELD("data_sign","uint32",0,4,SX_ID),
    SX_FIELD("reference_low_data","uint32",4,4,SX_NONE),
    SX_FIELD("reference_low_quantity","float32",8,4,SX_NONE),
    SX_FIELD("reference_high_data","uint32",12,4,SX_NONE),
    SX_FIELD("reference_high_quantity","float32",16,4,SX_NONE),
    SX_FIELD("descriptor","uint8",20,1,SX_ID),
    SX_FIELD("transfer_characteristic","uint8",21,1,SX_ID),
    SX_FIELD("colorimetric","uint8",22,1,SX_ID),
    SX_FIELD("bit_depth","uint8",23,1,SX_NONE),
    SX_FIELD("packing","uint16",24,2,SX_ID),
    SX_FIELD("encoding","uint16",26,2,SX_ID),
    SX_FIELD("data_offset","uint32",28,4,SX_OFFSET),
    SX_FIELD("end_of_line_padding","uint32",32,4,SX_SIZE),
    SX_FIELD("end_of_image_padding","uint32",36,4,SX_SIZE),
    SX_FIELD("description","char[32]",40,32,SX_STRING),
};
const sx_layout sxrm_dpx_element_le = {UINT32_C(0x601d003f),"dpx_element_le",sxrm_dpx_element_le_fields,SX_COUNT(sxrm_dpx_element_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_image_reserved_le_fields[] = {
    SX_FIELD("reserved","uint8[52]",0,52,SX_RESERVED),
};
const sx_layout sxrm_dpx_image_reserved_le = {UINT32_C(0x601d0040),"dpx_image_reserved_le",sxrm_dpx_image_reserved_le_fields,SX_COUNT(sxrm_dpx_image_reserved_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_orientation_le_fields[] = {
    SX_FIELD("x_offset","uint32",0,4,SX_NONE),
    SX_FIELD("y_offset","uint32",4,4,SX_NONE),
    SX_FIELD("x_center","float32",8,4,SX_NONE),
    SX_FIELD("y_center","float32",12,4,SX_NONE),
    SX_FIELD("original_width","uint32",16,4,SX_COUNT_PROP),
    SX_FIELD("original_height","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("source_filename","char[100]",24,100,SX_STRING),
    SX_FIELD("source_creation_time","char[24]",124,24,SX_STRING),
    SX_FIELD("input_device","char[32]",148,32,SX_STRING),
    SX_FIELD("input_serial","char[32]",180,32,SX_STRING),
    SX_FIELD("border_validity","uint16[4]",212,8,SX_NONE),
    SX_FIELD("pixel_aspect_horizontal","uint32",220,4,SX_NONE),
    SX_FIELD("pixel_aspect_vertical","uint32",224,4,SX_NONE),
    SX_FIELD("reserved","uint8[28]",228,28,SX_RESERVED),
};
const sx_layout sxrm_dpx_orientation_le = {UINT32_C(0x601d0041),"dpx_orientation_le",sxrm_dpx_orientation_le_fields,SX_COUNT(sxrm_dpx_orientation_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_film_le_fields[] = {
    SX_FIELD("manufacturer_id","char[2]",0,2,SX_STRING),
    SX_FIELD("film_type","char[2]",2,2,SX_STRING),
    SX_FIELD("perforation_offset","char[2]",4,2,SX_STRING),
    SX_FIELD("prefix","char[6]",6,6,SX_STRING),
    SX_FIELD("count","char[4]",12,4,SX_STRING),
    SX_FIELD("format","char[32]",16,32,SX_STRING),
    SX_FIELD("frame_position","uint32",48,4,SX_NONE),
    SX_FIELD("sequence_extent","uint32",52,4,SX_COUNT_PROP),
    SX_FIELD("held_count","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("frame_rate","float32",60,4,SX_NONE),
    SX_FIELD("shutter_angle","float32",64,4,SX_NONE),
    SX_FIELD("frame_id","char[32]",68,32,SX_STRING),
    SX_FIELD("slate","char[100]",100,100,SX_STRING),
    SX_FIELD("reserved","uint8[56]",200,56,SX_RESERVED),
};
const sx_layout sxrm_dpx_film_le = {UINT32_C(0x601d0042),"dpx_film_le",sxrm_dpx_film_le_fields,SX_COUNT(sxrm_dpx_film_le_fields),SX_LE};
static const xx_data_struct_field_desc sxrm_dpx_television_le_fields[] = {
    SX_FIELD("time_code","uint32",0,4,SX_NONE),
    SX_FIELD("user_bits","uint32",4,4,SX_FLAGS),
    SX_FIELD("interlace","uint8",8,1,SX_ID),
    SX_FIELD("field_number","uint8",9,1,SX_ID),
    SX_FIELD("video_signal","uint8",10,1,SX_ID),
    SX_FIELD("padding","uint8",11,1,SX_RESERVED),
    SX_FIELD("horizontal_sample_rate","float32",12,4,SX_NONE),
    SX_FIELD("vertical_sample_rate","float32",16,4,SX_NONE),
    SX_FIELD("frame_rate","float32",20,4,SX_NONE),
    SX_FIELD("time_offset","float32",24,4,SX_NONE),
    SX_FIELD("gamma","float32",28,4,SX_NONE),
    SX_FIELD("black_level","float32",32,4,SX_NONE),
    SX_FIELD("black_gain","float32",36,4,SX_NONE),
    SX_FIELD("break_point","float32",40,4,SX_NONE),
    SX_FIELD("white_level","float32",44,4,SX_NONE),
    SX_FIELD("integration_time","float32",48,4,SX_NONE),
    SX_FIELD("reserved","uint8[76]",52,76,SX_RESERVED),
};
const sx_layout sxrm_dpx_television_le = {UINT32_C(0x601d0043),"dpx_television_le",sxrm_dpx_television_le_fields,SX_COUNT(sxrm_dpx_television_le_fields),SX_LE};
static bool sxrm_dpx(sx_context *c)
{
 uint8_t h[36];if(!sxrm_read(c,0,h,36))return false;bool be=!xx_rt_memcmp(h,"SDPX",4);if(!be&&xx_rt_memcmp(h,"XPDS",4))return false;
 if(!sxrm_add(c,be?&sxrm_dpx_file_header_be:&sxrm_dpx_file_header_le,0))return false;
 if(sxrm_span(c,768,12)&&!sxrm_add(c,be?&sxrm_dpx_image_header_be:&sxrm_dpx_image_header_le,768))return false;
 if(sxrm_span(c,780,576)&&!sxrm_table(c,be?&sxrm_dpx_element_be:&sxrm_dpx_element_le,780,8))return false;
 if(sxrm_span(c,1356,52)&&!sxrm_add(c,be?&sxrm_dpx_image_reserved_be:&sxrm_dpx_image_reserved_le,1356))return false;
 if(sxrm_span(c,1408,256)&&!sxrm_add(c,be?&sxrm_dpx_orientation_be:&sxrm_dpx_orientation_le,1408))return false;
 if(sxrm32(h+28,be)>=384&&sxrm_span(c,1664,384)){if(!sxrm_add(c,be?&sxrm_dpx_film_be:&sxrm_dpx_film_le,1664)||!sxrm_add(c,be?&sxrm_dpx_television_be:&sxrm_dpx_television_le,1920))return false;}return !c->failed;
}
bool sx_dpx_build(sx_context*c)
{
 return sxrm_dpx(c);
}
