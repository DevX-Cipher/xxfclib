/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * dted_elevation data structures, moved out of the scientificextra schema family. */
#include "../../xx_format_schema_scientificextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxscx_dted_uhl_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("version","char[1]",3,1,SX_ID),
    SX_FIELD("longitude_origin","char[8]",4,8,SX_STRING),
    SX_FIELD("latitude_origin","char[8]",12,8,SX_STRING),
    SX_FIELD("longitude_interval","ascii_decimal[4]",20,4,SX_NONE),
    SX_FIELD("latitude_interval","ascii_decimal[4]",24,4,SX_NONE),
    SX_FIELD("absolute_vertical_accuracy","char[4]",28,4,SX_STRING),
    SX_FIELD("security_code","char[3]",32,3,SX_STRING),
    SX_FIELD("unique_reference","char[12]",35,12,SX_STRING),
    SX_FIELD("longitude_lines","ascii_decimal[4]",47,4,SX_COUNT_PROP),
    SX_FIELD("latitude_points","ascii_decimal[4]",51,4,SX_COUNT_PROP),
    SX_FIELD("multiple_accuracy","char[1]",55,1,SX_ID),
    SX_FIELD("reserved","char[24]",56,24,SX_RESERVED),
};
const sx_layout sxscx_dted_uhl = {UINT32_C(0x60310013),"dted_uhl",sxscx_dted_uhl_fields,SX_COUNT(sxscx_dted_uhl_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_dted_dsi_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("security_code","char[1]",3,1,SX_STRING),
    SX_FIELD("security_control","char[2]",4,2,SX_STRING),
    SX_FIELD("security_handling","char[27]",6,27,SX_STRING),
    SX_FIELD("opaque_21","uint8[26]",33,26,SX_NONE),
    SX_FIELD("series_designator","char[5]",59,5,SX_STRING),
    SX_FIELD("unique_reference","char[15]",64,15,SX_STRING),
    SX_FIELD("opaque_4f","uint8[8]",79,8,SX_NONE),
    SX_FIELD("data_edition","char[2]",87,2,SX_STRING),
    SX_FIELD("merge_version","char[1]",89,1,SX_STRING),
    SX_FIELD("maintenance_date","char[4]",90,4,SX_STRING),
    SX_FIELD("merge_date","char[4]",94,4,SX_STRING),
    SX_FIELD("maintenance_description","char[4]",98,4,SX_STRING),
    SX_FIELD("producer","char[8]",102,8,SX_STRING),
    SX_FIELD("opaque_6e","uint8[16]",110,16,SX_NONE),
    SX_FIELD("product_specification","char[9]",126,9,SX_STRING),
    SX_FIELD("specification_amendment","char[2]",135,2,SX_STRING),
    SX_FIELD("specification_date","char[4]",137,4,SX_STRING),
    SX_FIELD("vertical_datum","char[3]",141,3,SX_STRING),
    SX_FIELD("horizontal_datum","char[5]",144,5,SX_STRING),
    SX_FIELD("digitizing_system","char[10]",149,10,SX_STRING),
    SX_FIELD("compilation_date","char[4]",159,4,SX_STRING),
    SX_FIELD("opaque_a3","uint8[22]",163,22,SX_NONE),
    SX_FIELD("origin_latitude","char[9]",185,9,SX_STRING),
    SX_FIELD("origin_longitude","char[10]",194,10,SX_STRING),
    SX_FIELD("southwest_latitude","char[7]",204,7,SX_STRING),
    SX_FIELD("southwest_longitude","char[8]",211,8,SX_STRING),
    SX_FIELD("northwest_latitude","char[7]",219,7,SX_STRING),
    SX_FIELD("northwest_longitude","char[8]",226,8,SX_STRING),
    SX_FIELD("northeast_latitude","char[7]",234,7,SX_STRING),
    SX_FIELD("northeast_longitude","char[8]",241,8,SX_STRING),
    SX_FIELD("southeast_latitude","char[7]",249,7,SX_STRING),
    SX_FIELD("southeast_longitude","char[8]",256,8,SX_STRING),
    SX_FIELD("orientation","char[9]",264,9,SX_STRING),
    SX_FIELD("latitude_interval","char[4]",273,4,SX_STRING),
    SX_FIELD("longitude_interval","char[4]",277,4,SX_STRING),
    SX_FIELD("latitude_points","char[4]",281,4,SX_STRING),
    SX_FIELD("longitude_lines","char[4]",285,4,SX_STRING),
    SX_FIELD("partial_cell","char[2]",289,2,SX_STRING),
    SX_FIELD("opaque_123","uint8[357]",291,357,SX_NONE),
};
const sx_layout sxscx_dted_dsi = {UINT32_C(0x60310014),"dted_dsi",sxscx_dted_dsi_fields,SX_COUNT(sxscx_dted_dsi_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_dted_acc_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("absolute_horizontal_accuracy","char[4]",3,4,SX_STRING),
    SX_FIELD("absolute_vertical_accuracy","char[4]",7,4,SX_STRING),
    SX_FIELD("relative_horizontal_accuracy","char[4]",11,4,SX_STRING),
    SX_FIELD("relative_vertical_accuracy","char[4]",15,4,SX_STRING),
    SX_FIELD("opaque_13","uint8[36]",19,36,SX_NONE),
    SX_FIELD("accuracy_subregions","char[2]",55,2,SX_STRING),
    SX_FIELD("opaque_39","uint8[2643]",57,2643,SX_NONE),
};
const sx_layout sxscx_dted_acc = {UINT32_C(0x60310015),"dted_acc",sxscx_dted_acc_fields,SX_COUNT(sxscx_dted_acc_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_dted_column_header_fields[] = {
    SX_FIELD("sentinel","uint8",0,1,SX_SIGNATURE),
    SX_FIELD("block_count","uint24",1,3,SX_COUNT_PROP),
    SX_FIELD("longitude_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("latitude_count","uint16",6,2,SX_COUNT_PROP),
};
const sx_layout sxscx_dted_column_header = {UINT32_C(0x60310016),"dted_column_header",sxscx_dted_column_header_fields,SX_COUNT(sxscx_dted_column_header_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_dted_column_checksum_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxscx_dted_column_checksum = {UINT32_C(0x60310017),"dted_column_checksum",sxscx_dted_column_checksum_fields,SX_COUNT(sxscx_dted_column_checksum_fields),SX_BE};
static bool sxscx_dted(sx_context *c,const uint8_t *b,size_t n)
{
 uint64_t nx,ny,at=3428;if(n<3428||!sxscx_decimal(b+47,4,&nx)||!sxscx_decimal(b+51,4,&ny)||!nx||!ny||nx>3601||ny>3601)return false;
 if(!sxscx_add(c,&sxscx_dted_uhl,0)||!sxscx_add(c,&sxscx_dted_dsi,80)||!sxscx_add(c,&sxscx_dted_acc,728))return false;
 uint64_t size=12+ny*2;for(uint64_t i=0;i<nx;i++,at+=size)if(!sxscx_span(c,at,size)||!sxscx_add(c,&sxscx_dted_column_header,at)||!sxscx_add(c,&sxscx_dted_column_checksum,at+size-4))return false;
 return at==n;
}
bool sx_dted_elevation_build(sx_context *c,uint8_t *b)
{
 return sxscx_dted(c,b,(size_t)c->size);
}
