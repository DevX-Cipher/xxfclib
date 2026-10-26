/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * ZLWB data structures, moved out of the archiveclassic schema family. */
#include "../../xx_format_schema_archiveclassic.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxacl_zlwb_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("marker","uint8",4,1,SX_SIGNATURE),
 SX_FIELD("version","uint32",5,4,SX_NONE),
 SX_FIELD("opaque1","uint8[9]",9,9,SX_NONE),
 SX_FIELD("member_count","int32",18,4,SX_COUNT_PROP),
 SX_FIELD("directory_offset","int32",22,4,SX_OFFSET),
 SX_FIELD("opaque2","uint8[4]",26,4,SX_NONE),
};
const sx_layout sxacl_zlwb_header = {UINT32_C(0x60500002),"zlwb_header",sxacl_zlwb_header_fields,SX_COUNT(sxacl_zlwb_header_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_zlwb_blob_fields[] = {
 SX_FIELD("unused1","uint32",0,4,SX_NONE),
 SX_FIELD("compressed_size","int32",4,4,SX_SIZE),
 SX_FIELD("record_size","int32",8,4,SX_SIZE),
 SX_FIELD("unused2","uint32",12,4,SX_NONE),
};
const sx_layout sxacl_zlwb_blob = {UINT32_C(0x60500003),"zlwb_blob",sxacl_zlwb_blob_fields,SX_COUNT(sxacl_zlwb_blob_fields),SX_LE};
static bool sxacl_zlwb(sx_context*c){uint64_t n,p;if(!sxacl_word(c,18,4,false,&n)||n>INT32_MAX||!sxacl_word(c,22,4,false,&p)||p<30||p>INT32_MAX||!sxacl_add(c,&sxacl_zlwb_header,0))return false;for(uint64_t i=0;i<n;i++){uint8_t b[16];if(!sxacl_read(c,p,b,16))return false;uint64_t z=sxacl_uint(b+4,4,false),plain=sxacl_uint(b+8,4,false);if(z>INT32_MAX||(plain!=272&&plain!=552)||!sxacl_span(c,p+16,z)||!sxacl_add(c,&sxacl_zlwb_blob,p))return false;p+=16+z;}return true;}
bool sx_zlwb_build(sx_context*c)
{
 return sxacl_zlwb(c);
}
