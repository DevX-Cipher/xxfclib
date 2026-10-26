/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OSL2000 data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_osl_encoded_record_fields[] = {
 SX_FIELD("encoded_header","uint8[16]",0,16,SX_NONE),
};
const sx_layout sxan_osl_encoded_record = {UINT32_C(0x60770065),"osl_encoded_record",sxan_osl_encoded_record_fields,SX_COUNT(sxan_osl_encoded_record_fields),SX_LE};
static const xx_data_struct_field_desc sxan_osl_payload_checksum_fields[] = {
 SX_FIELD("rolling_checksum","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxan_osl_payload_checksum = {UINT32_C(0x60770066),"osl_payload_checksum",sxan_osl_payload_checksum_fields,SX_COUNT(sxan_osl_payload_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxan_osl_signature_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
};
const sx_layout sxan_osl_signature = {UINT32_C(0x60770067),"osl_signature",sxan_osl_signature_fields,SX_COUNT(sxan_osl_signature_fields),SX_LE};
static uint8_t sxan_rol8(uint8_t b){return (uint8_t)((b<<1)|(b>>7));}
static uint8_t sxan_ror8(uint8_t b){return (uint8_t)((b>>1)|(b<<7));}
static bool sxan_osl(sx_context*c){uint64_t p=3;if(!sxan_add(c,&sxan_osl_signature,0))return false;while(sxan_span(c,p,16)){uint8_t b[16];if(!sxan_read(c,p,b,16))return false;for(unsigned i=16;i--;){uint8_t v=b[i];if(i)v=b[i-1]^(uint8_t)(sxan_rol8(v)+i);b[i]=(uint8_t)(sxan_ror8(v)-i)^90;}if(sxan_uint(b,2,false)!=0x4948)return true;uint64_t z=sxan_uint(b+2,4,false);if(!sxan_add(c,&sxan_osl_encoded_record,p))return false;p+=16;if(!sxan_span(c,p,z+2))return true;if(!sxan_add(c,&sxan_osl_payload_checksum,p+z))return false;p+=z+2;}return true;}
bool sx_osl2000_build(sx_context*c)
{
bool ok=false;
ok=sxan_osl(c);
(void)ok;return c->count&&sxan_finish(c);
}
