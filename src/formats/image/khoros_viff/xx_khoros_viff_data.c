/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * KHOROS VIFF data structures, moved out of the nextmedia schema family. */
#include "../../xx_format_schema_nextmedia.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnx_viff_header_le_fields[]={
 SX_FIELD("identifier","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("file_type","uint8",1,1,SX_ID),
 SX_FIELD("release","uint8",2,1,SX_ID),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("machine_dependency","uint8",4,1,SX_ID),
 SX_FIELD("reserved","bytes",5,3,SX_RESERVED),
 SX_FIELD("comment","char[512]",8,512,SX_STRING),
 SX_FIELD("rows","uint32",520,4,SX_COUNT_PROP),
 SX_FIELD("columns","uint32",524,4,SX_COUNT_PROP),
 SX_FIELD("subrows","uint32",528,4,SX_COUNT_PROP),
 SX_FIELD("x_offset","int32",532,4,SX_NONE),
 SX_FIELD("y_offset","int32",536,4,SX_NONE),
 SX_FIELD("x_bits_per_pixel","float",540,4,SX_NONE),
 SX_FIELD("y_bits_per_pixel","float",544,4,SX_NONE),
 SX_FIELD("location_type","uint32",548,4,SX_ID),
 SX_FIELD("location_dimension","uint32",552,4,SX_COUNT_PROP),
 SX_FIELD("image_count","uint32",556,4,SX_COUNT_PROP),
 SX_FIELD("band_count","uint32",560,4,SX_COUNT_PROP),
 SX_FIELD("storage_type","uint32",564,4,SX_ID),
 SX_FIELD("encoding","uint32",568,4,SX_ID),
 SX_FIELD("map_scheme","uint32",572,4,SX_ID),
 SX_FIELD("map_storage_type","uint32",576,4,SX_ID),
 SX_FIELD("map_rows","uint32",580,4,SX_COUNT_PROP),
 SX_FIELD("map_columns","uint32",584,4,SX_COUNT_PROP),
 SX_FIELD("map_subrows","uint32",588,4,SX_COUNT_PROP),
 SX_FIELD("map_enable","uint32",592,4,SX_FLAGS),
 SX_FIELD("maps_per_cycle","uint32",596,4,SX_COUNT_PROP),
 SX_FIELD("color_space","uint32",600,4,SX_ID),
 SX_FIELD("reserved_tail","bytes",604,420,SX_RESERVED),
};
const sx_layout sxnx_viff_header_le={UINT32_C(0x60320024),"viff_header_le",sxnx_viff_header_le_fields,SX_COUNT(sxnx_viff_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxnx_viff_header_be_fields[]={
 SX_FIELD("identifier","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("file_type","uint8",1,1,SX_ID),
 SX_FIELD("release","uint8",2,1,SX_ID),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("machine_dependency","uint8",4,1,SX_ID),
 SX_FIELD("reserved","bytes",5,3,SX_RESERVED),
 SX_FIELD("comment","char[512]",8,512,SX_STRING),
 SX_FIELD("rows","uint32",520,4,SX_COUNT_PROP),
 SX_FIELD("columns","uint32",524,4,SX_COUNT_PROP),
 SX_FIELD("subrows","uint32",528,4,SX_COUNT_PROP),
 SX_FIELD("x_offset","int32",532,4,SX_NONE),
 SX_FIELD("y_offset","int32",536,4,SX_NONE),
 SX_FIELD("x_bits_per_pixel","float",540,4,SX_NONE),
 SX_FIELD("y_bits_per_pixel","float",544,4,SX_NONE),
 SX_FIELD("location_type","uint32",548,4,SX_ID),
 SX_FIELD("location_dimension","uint32",552,4,SX_COUNT_PROP),
 SX_FIELD("image_count","uint32",556,4,SX_COUNT_PROP),
 SX_FIELD("band_count","uint32",560,4,SX_COUNT_PROP),
 SX_FIELD("storage_type","uint32",564,4,SX_ID),
 SX_FIELD("encoding","uint32",568,4,SX_ID),
 SX_FIELD("map_scheme","uint32",572,4,SX_ID),
 SX_FIELD("map_storage_type","uint32",576,4,SX_ID),
 SX_FIELD("map_rows","uint32",580,4,SX_COUNT_PROP),
 SX_FIELD("map_columns","uint32",584,4,SX_COUNT_PROP),
 SX_FIELD("map_subrows","uint32",588,4,SX_COUNT_PROP),
 SX_FIELD("map_enable","uint32",592,4,SX_FLAGS),
 SX_FIELD("maps_per_cycle","uint32",596,4,SX_COUNT_PROP),
 SX_FIELD("color_space","uint32",600,4,SX_ID),
 SX_FIELD("reserved_tail","bytes",604,420,SX_RESERVED),
};
const sx_layout sxnx_viff_header_be={UINT32_C(0x60320025),"viff_header_be",sxnx_viff_header_be_fields,SX_COUNT(sxnx_viff_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxnx_viff_header_dec_fields[]={
 SX_FIELD("identifier","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("file_type","uint8",1,1,SX_ID),
 SX_FIELD("release","uint8",2,1,SX_ID),
 SX_FIELD("version","uint8",3,1,SX_ID),
 SX_FIELD("machine_dependency","uint8",4,1,SX_ID),
 SX_FIELD("reserved","bytes",5,3,SX_RESERVED),
 SX_FIELD("comment","char[512]",8,512,SX_STRING),
 SX_FIELD("rows","uint32",520,4,SX_COUNT_PROP),
 SX_FIELD("columns","uint32",524,4,SX_COUNT_PROP),
 SX_FIELD("subrows","uint32",528,4,SX_COUNT_PROP),
 SX_FIELD("x_offset","int32",532,4,SX_NONE),
 SX_FIELD("y_offset","int32",536,4,SX_NONE),
 SX_FIELD("x_bits_per_pixel_vax","bytes",540,4,SX_NONE),
 SX_FIELD("y_bits_per_pixel_vax","bytes",544,4,SX_NONE),
 SX_FIELD("location_type","uint32",548,4,SX_ID),
 SX_FIELD("location_dimension","uint32",552,4,SX_COUNT_PROP),
 SX_FIELD("image_count","uint32",556,4,SX_COUNT_PROP),
 SX_FIELD("band_count","uint32",560,4,SX_COUNT_PROP),
 SX_FIELD("storage_type","uint32",564,4,SX_ID),
 SX_FIELD("encoding","uint32",568,4,SX_ID),
 SX_FIELD("map_scheme","uint32",572,4,SX_ID),
 SX_FIELD("map_storage_type","uint32",576,4,SX_ID),
 SX_FIELD("map_rows","uint32",580,4,SX_COUNT_PROP),
 SX_FIELD("map_columns","uint32",584,4,SX_COUNT_PROP),
 SX_FIELD("map_subrows","uint32",588,4,SX_COUNT_PROP),
 SX_FIELD("map_enable","uint32",592,4,SX_FLAGS),
 SX_FIELD("maps_per_cycle","uint32",596,4,SX_COUNT_PROP),
 SX_FIELD("color_space","uint32",600,4,SX_ID),
 SX_FIELD("reserved_tail","bytes",604,420,SX_RESERVED),
};
const sx_layout sxnx_viff_header_dec={UINT32_C(0x60320026),"viff_header_dec",sxnx_viff_header_dec_fields,SX_COUNT(sxnx_viff_header_dec_fields),SX_LE};
static bool sxnx_viff(sxnx_view*v)
{return sxnx_need(v,0,5,v->n)&&sxnx_row(v,v->p[4]==2?&sxnx_viff_header_be:v->p[4]==4?&sxnx_viff_header_dec:&sxnx_viff_header_le,0,v->n);}
bool sx_khoros_viff_build(sxnx_view*v)
{
 return sxnx_viff(v);
}
