/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * THOMSON_SAP data structures, moved out of the systemlater schema family. */
#include "../../xx_format_schema_systemlater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxsl_sap_header_fields[] = {
    SX_FIELD("version","uint8",0,1,SX_ID),
    SX_FIELD("signature","char[65]",1,65,SX_SIGNATURE),
};
const sx_layout sxsl_sap_header = {0x60330020U,"sap_header",sxsl_sap_header_fields,SX_COUNT(sxsl_sap_header_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_sap_sector_fields[] = {
    SX_FIELD("format","uint8",0,1,SX_ID),
    SX_FIELD("protection","uint8",1,1,SX_FLAGS),
    SX_FIELD("cylinder","uint8",2,1,SX_NONE),
    SX_FIELD("sector","uint8",3,1,SX_NONE),
};
const sx_layout sxsl_sap_sector = {0x60330021U,"sap_sector",sxsl_sap_sector_fields,SX_COUNT(sxsl_sap_sector_fields),SX_LE};
static const xx_data_struct_field_desc sxsl_sap_checksum_fields[] = {
    SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxsl_sap_checksum = {0x60330022U,"sap_checksum",sxsl_sap_checksum_fields,SX_COUNT(sxsl_sap_checksum_fields),SX_BE};
#define SXSL_LIMIT 24000U
#define SXSL_ADD(c,l,p) sxsl_put(c,&sxsl_##l,p,1)
static bool sxsl_sap(sx_context*c){uint8_t version;if(!sxsl_read(c,0,&version,1)||!SXSL_ADD(c,sap_header,0))return false;uint64_t z=version==1?256:version==2?128:0,n=version==1?1280:640;if(!z)return true;for(uint64_t i=0;i<n&&c->count<SXSL_LIMIT;i++){uint64_t p=66+i*(z+6);if(!sxsl_span(c,p,z+6))break;if(!SXSL_ADD(c,sap_sector,p)||!SXSL_ADD(c,sap_checksum,p+4+z))return false;}return true;}
bool sx_thomson_sap_build(sx_context*c)
{
bool ok=false;
ok=sxsl_sap(c);
return ok&&sxsl_finish(c);
}
