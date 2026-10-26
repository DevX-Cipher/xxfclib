/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SDI data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_sdi_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("type","uint64",8,8,SX_ID),
    SX_FIELD("boot_offset","uint64",16,8,SX_OFFSET),
    SX_FIELD("boot_size","uint64",24,8,SX_SIZE),
    SX_FIELD("vendor_id","uint64",32,8,SX_ID),
    SX_FIELD("device_id","uint64",40,8,SX_ID),
    SX_FIELD("device_model","byte[16]",48,16,SX_NONE),
    SX_FIELD("device_role","uint64",64,8,SX_ID),
    SX_FIELD("reserved1","uint64",72,8,SX_RESERVED),
    SX_FIELD("runtime_guid","byte[16]",80,16,SX_NONE),
    SX_FIELD("runtime_oem_revision","uint64",96,8,SX_NONE),
    SX_FIELD("reserved2","uint64",104,8,SX_RESERVED),
    SX_FIELD("page_alignment","int64",112,8,SX_NONE),
    SX_FIELD("reserved3","byte[384]",120,384,SX_RESERVED),
    SX_FIELD("checksum","uint64",504,8,SX_CHECKSUM),
};
const sx_layout sxsl_sdi_header = {0x6033001bU,"sdi_header",sxsl_sdi_header_fields,SX_COUNT(sxsl_sdi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_sdi_section_fields[] = {
    SX_FIELD("section_type","char[8]",0,8,SX_ID),
    SX_FIELD("attributes","uint64",8,8,SX_FLAGS),
    SX_FIELD("data_offset","int64",16,8,SX_OFFSET),
    SX_FIELD("data_size","int64",24,8,SX_SIZE),
    SX_FIELD("partition_type","uint64",32,8,SX_ID),
    SX_FIELD("reserved","byte[24]",40,24,SX_RESERVED),
};
const sx_layout sxsl_sdi_section = {0x6033001cU,"sdi_section",sxsl_sdi_section_fields,SX_COUNT(sxsl_sdi_section_fields),SX_LE};
#define SXSL_LIMIT 24000U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
static bool sxsl_sdi(sx_context*c){uint64_t page;uint8_t b[8];if(!SXSL_ADD(c,sdi_header,0)||!sxsl_word(c,112,8,false,&page))return false;if(!page||page>2048)return true;page*=512;for(uint64_t p=page;p+64<=2*page&&c->count<SXSL_LIMIT;p+=64){if(!sxsl_read(c,p,b,8))break;uint64_t tag=sxsl_uint(b,8,false);if(!tag)break;if(!SXSL_ADD(c,sdi_section,p))return false;}return true;}
bool sx_sdi_build(sx_context*c)
{
bool ok=false;
ok=sxsl_sdi(c);
return ok&&sxsl_finish(c);
}
