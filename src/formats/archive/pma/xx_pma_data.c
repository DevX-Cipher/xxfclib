/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PMA data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_pma_header_fields[] = {
 SX_FIELD("header_payload_size","uint8",0,1,SX_SIZE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_NONE),
 SX_FIELD("compressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_timestamp","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
 SX_FIELD("header_level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
const sx_layout sxas_pma_header = {UINT32_C(0x60430018),"pma_header",sxas_pma_header_fields,SX_COUNT(sxas_pma_header_fields),SX_LE};
static const xx_data_struct_field_desc sxas_pma_crc16_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxas_pma_crc16 = {UINT32_C(0x60430019),"pma_crc16",sxas_pma_crc16_fields,SX_COUNT(sxas_pma_crc16_fields),SX_LE};
static bool sxas_pma(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint8_t b[22];if(!sxas_read(c,p,b,1))return false;if(!b[0])return true;if(!sxas_read(c,p,b,22))return false;uint64_t hs=b[0]+2,n=b[21],packed=sxas_uint(b+7,4,false);if(hs<24+n||!sxas_span(c,p,hs)||!sxas_span(c,p+hs,packed)||!sxas_add(c,&sxas_pma_header,p)||!sxas_add(c,&sxas_pma_crc16,p+22+n))return false;p+=hs+packed;}return true;}
bool sx_pma_build(sx_context*c)
{
 return sxas_pma(c);
}
