/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * EDC data structures, moved out of the archivestreams schema family. */
#include "../../xx_format_schema_archivestreams.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxas_edc_header_fields[] = {
 SX_FIELD("signature","char[12]",0,12,SX_SIGNATURE),
 SX_FIELD("name","char[12]",12,12,SX_NONE),
 SX_FIELD("eof_marker","uint8",24,1,SX_SIGNATURE),
 SX_FIELD("version","uint8",25,1,SX_NONE),
 SX_FIELD("method","uint8",26,1,SX_NONE),
 SX_FIELD("uncompressed_size","uint32",27,4,SX_SIZE),
 SX_FIELD("member_size","uint32",31,4,SX_SIZE),
 SX_FIELD("reserved","uint16",35,2,SX_NONE),
 SX_FIELD("dos_time","uint16",37,2,SX_NONE),
 SX_FIELD("dos_date","uint16",39,2,SX_NONE),
};
const sx_layout sxas_edc_header = {UINT32_C(0x60430026),"edc_header",sxas_edc_header_fields,SX_COUNT(sxas_edc_header_fields),SX_LE};
static bool sxas_edc(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size){uint64_t n;if(!sxas_word(c,p+31,4,false,&n)||n<41||!sxas_span(c,p,n)||!sxas_add(c,&sxas_edc_header,p))return false;p+=n;}return true;}
bool sx_edc_build(sx_context*c)
{
 return sxas_edc(c);
}
