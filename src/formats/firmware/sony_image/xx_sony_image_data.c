/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Sony TCJN images data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_sony_image_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("opaque_4","uint8[12]",4,12,SX_NONE),
    SX_FIELD("reserved","uint32",16,4,SX_RESERVED),
    SX_FIELD("payload_size","uint32",20,4,SX_SIZE),
    SX_FIELD("continuation","uint8",24,1,SX_NONE),
    SX_FIELD("field_19","uint8",25,1,SX_NONE),
    SX_FIELD("opaque_1a","uint8[486]",26,486,SX_NONE),
};
const sx_layout sxbrs_sony_image_header = {UINT32_C(0x603e0030),"sony_image_header",sxbrs_sony_image_header_fields,SX_COUNT(sxbrs_sony_image_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_sony_image_zlib_marker_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxbrs_sony_image_zlib_marker = {UINT32_C(0x603e0031),"sony_image_zlib_marker",sxbrs_sony_image_zlib_marker_fields,SX_COUNT(sxbrs_sony_image_zlib_marker_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_resource_zlib_header_fields[] = {
    SX_FIELD("compression_method_flags","uint8",0,1,SX_FLAGS),
    SX_FIELD("flags","uint8",1,1,SX_FLAGS),
};
const sx_layout sxbrs_resource_zlib_header = {UINT32_C(0x603e0032),"resource_zlib_header",sxbrs_resource_zlib_header_fields,SX_COUNT(sxbrs_resource_zlib_header_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_resource_zlib_trailer_fields[] = {
    SX_FIELD("adler32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxbrs_resource_zlib_trailer = {UINT32_C(0x603e0033),"resource_zlib_trailer",sxbrs_resource_zlib_trailer_fields,SX_COUNT(sxbrs_resource_zlib_trailer_fields),SX_BE};
#define N(p,w) sxbrs_num(c,(p),(w),false)
static bool sxbrs_sony(sx_context*c){if(c->size<522||!sxbrs_eq(c,0,"TCJN",4)||N(16,4)||N(20,4)!=(uint64_t)c->size-512||N(24,1)||N(25,1)>1||!sxbrs_eq(c,512,"ZLIB",4))return false;return sxbrs_add(c,&sxbrs_sony_image_header,0)&&sxbrs_add(c,&sxbrs_sony_image_zlib_marker,512)&&sxbrs_add(c,&sxbrs_resource_zlib_header,516)&&sxbrs_add(c,&sxbrs_resource_zlib_trailer,c->size-4);}
bool sx_sony_image_build(sx_context*c)
{
 return sxbrs_sony(c);
}
#undef N
