/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ECMA67_FS data structures, moved out of the classicfs schema family. */
#include "../../xx_format_schema_classicfs.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxcf_ecma67_volume_label_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("label_number","uint8",3,1,SX_ID),
    SX_FIELD("volume_identifier","char[6]",4,6,SX_NONE),
    SX_FIELD("accessibility","uint8",10,1,SX_ID),
    SX_FIELD("reserved0","byte[26]",11,26,SX_RESERVED),
    SX_FIELD("owner","char[14]",37,14,SX_NONE),
    SX_FIELD("reserved1","byte[20]",51,20,SX_RESERVED),
    SX_FIELD("surface","uint8",71,1,SX_ID),
    SX_FIELD("reserved2","byte[3]",72,3,SX_RESERVED),
    SX_FIELD("record_length_code","uint8",75,1,SX_ID),
    SX_FIELD("reserved3","byte[2]",76,2,SX_RESERVED),
    SX_FIELD("file_label_allocation","uint8",78,1,SX_ID),
    SX_FIELD("standard_version","uint8",79,1,SX_ID),
    SX_FIELD("reserved4","byte[48]",80,48,SX_RESERVED),
};
const sx_layout sxcf_ecma67_volume_label = {0x603d003cU,"ecma67_volume_label",sxcf_ecma67_volume_label_fields,SX_COUNT(sxcf_ecma67_volume_label_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ecma67_error_map_label_fields[] = {
    SX_FIELD("identifier","char[5]",0,5,SX_SIGNATURE),
    SX_FIELD("reserved0","uint8",5,1,SX_RESERVED),
    SX_FIELD("defective_cylinder_1","char[3]",6,3,SX_NONE),
    SX_FIELD("reserved1","uint8",9,1,SX_RESERVED),
    SX_FIELD("defective_cylinder_2","char[3]",10,3,SX_NONE),
    SX_FIELD("reserved2","byte[115]",13,115,SX_RESERVED),
};
const sx_layout sxcf_ecma67_error_map_label = {0x603d003dU,"ecma67_error_map_label",sxcf_ecma67_error_map_label_fields,SX_COUNT(sxcf_ecma67_error_map_label_fields),SX_LE};
static const xx_data_struct_field_desc sxcf_ecma67_file_label_fields[] = {
    SX_FIELD("identifier","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("label_number","uint8",3,1,SX_ID),
    SX_FIELD("reserved0","uint8",4,1,SX_RESERVED),
    SX_FIELD("filename","char[17]",5,17,SX_NONE),
    SX_FIELD("block_length_decimal","char[5]",22,5,SX_NONE),
    SX_FIELD("reserved1","uint8",27,1,SX_RESERVED),
    SX_FIELD("first_extent_chs","char[5]",28,5,SX_NONE),
    SX_FIELD("reserved2","uint8",33,1,SX_RESERVED),
    SX_FIELD("last_extent_chs","char[5]",34,5,SX_NONE),
    SX_FIELD("record_format","uint8",39,1,SX_ID),
    SX_FIELD("bypass_indicator","uint8",40,1,SX_ID),
    SX_FIELD("accessibility","uint8",41,1,SX_ID),
    SX_FIELD("write_protect","uint8",42,1,SX_ID),
    SX_FIELD("interchange_type","uint8",43,1,SX_ID),
    SX_FIELD("multi_volume","uint8",44,1,SX_ID),
    SX_FIELD("section_number_decimal","char[2]",45,2,SX_NONE),
    SX_FIELD("creation_date","char[6]",47,6,SX_NONE),
    SX_FIELD("record_length_decimal","char[4]",53,4,SX_NONE),
    SX_FIELD("unused_tail_decimal","char[5]",57,5,SX_NONE),
    SX_FIELD("record_attribute","uint8",62,1,SX_ID),
    SX_FIELD("file_organization","uint8",63,1,SX_ID),
    SX_FIELD("reserved3","byte[2]",64,2,SX_RESERVED),
    SX_FIELD("expiration_date","char[6]",66,6,SX_NONE),
    SX_FIELD("verify_copy","uint8",72,1,SX_ID),
    SX_FIELD("reserved4","uint8",73,1,SX_RESERVED),
    SX_FIELD("end_of_data_chs","char[5]",74,5,SX_NONE),
    SX_FIELD("reserved5","byte[49]",79,49,SX_RESERVED),
};
const sx_layout sxcf_ecma67_file_label = {0x603d003eU,"ecma67_file_label",sxcf_ecma67_file_label_fields,SX_COUNT(sxcf_ecma67_file_label_fields),SX_LE};
#define SXCF_ADD(c,l,p) sxcf_put(c,&sxcf_##l,p,1)
static bool sxcf_ecma(sx_context*c){uint8_t h[128],b[128];if(!sxcf_read(c,768,h,128)||xx_rt_memcmp(h,"VOL",3)||h[75]!='1'||!SXCF_ADD(c,ecma67_volume_label,768))return false;if(sxcf_read(c,512,b,128)&&!xx_rt_memcmp(b,"ERMAP",5)&&!SXCF_ADD(c,ecma67_error_map_label,512))return false;unsigned end=h[71]=='M'&&h[78]=='1'?32:16;for(unsigned n=7;n<end;n++){uint64_t p=n<16?(uint64_t)n*128:2048+(uint64_t)(n-16)*256;if(!sxcf_read(c,p,b,128))break;if(!xx_rt_memcmp(b,"HDR",3)&&(b[3]==1||b[3]=='1')&&!SXCF_ADD(c,ecma67_file_label,p))return false;}return true;}
bool sx_ecma67_fs_build(sx_context*c)
{
 return sxcf_ecma(c);
}
