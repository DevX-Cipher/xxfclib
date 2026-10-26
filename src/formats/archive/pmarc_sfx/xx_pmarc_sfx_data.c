/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * pmarc sfx data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_pmarc_member_fields[]={
 SX_FIELD("header_size_minus_two","uint8",0,1,SX_NONE),
 SX_FIELD("header_checksum","uint8",1,1,SX_CHECKSUM),
 SX_FIELD("method","char[5]",2,5,SX_ID),
 SX_FIELD("packed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",11,4,SX_SIZE),
 SX_FIELD("dos_date_time","uint32",15,4,SX_NONE),
 SX_FIELD("attributes","uint8",19,1,SX_FLAGS),
 SX_FIELD("header_level","uint8",20,1,SX_NONE),
 SX_FIELD("name_size","uint8",21,1,SX_SIZE),
};
const sx_layout sxaend_pmarc_member={UINT32_C(0x60840027),"pmarc_member",sxaend_pmarc_member_fields,SX_COUNT(sxaend_pmarc_member_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_pmarc_crc_fields[]={
 SX_FIELD("data_crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxaend_pmarc_crc={UINT32_C(0x60840028),"pmarc_crc",sxaend_pmarc_crc_fields,SX_COUNT(sxaend_pmarc_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_pmarc_end_fields[]={
 SX_FIELD("end_marker","uint8",0,1,SX_ID),
};
const sx_layout sxaend_pmarc_end={UINT32_C(0x60840029),"pmarc_end",sxaend_pmarc_end_fields,SX_COUNT(sxaend_pmarc_end_fields),SX_LE};
#define SXAEND_LIMIT 20000U
static bool sxaend_pmarc(sx_context*c){uint64_t p,n;if(!sxaend_first_source(c,&p,&n))return false;uint64_t end=p+n;for(unsigned i=0;p<end&&i<SXAEND_LIMIT;i++){uint8_t h[22];if(!sxaend_read(c,p,h,1))return false;if(!h[0])return sxaend_add(c,&sxaend_pmarc_end,p);uint64_t z=h[0]+2;if(z<24||z>end-p||!sxaend_read(c,p,h,22)||z<24+h[21]||xx_rt_memcmp(h+2,"-pm",3)||!sxaend_add(c,&sxaend_pmarc_member,p)||!sxaend_name(c,p+22,h[21])||!sxaend_add(c,&sxaend_pmarc_crc,p+22+h[21]))return false;uint64_t packed=sxaend_uint(h+7,4,false);if(packed>end-p-z)return false;p+=z+packed;}return true;}
bool sx_pmarc_sfx_build(sx_context*c)
{
 return sxaend_pmarc(c);
}
