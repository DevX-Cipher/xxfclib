/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * EDI LZSS data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_edi_header_fields[] = {
 SX_FIELD("signature","char[7]",0,7,SX_SIGNATURE),
 SX_FIELD("version","char[1]",7,1,SX_NONE),
};
const sx_layout sxat_edi_header = {UINT32_C(0x60640015),"edi_header",sxat_edi_header_fields,SX_COUNT(sxat_edi_header_fields),SX_LE};
static const xx_data_struct_field_desc sxat_edi_name_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
};
const sx_layout sxat_edi_name = {UINT32_C(0x60640016),"edi_name",sxat_edi_name_fields,SX_COUNT(sxat_edi_name_fields),SX_LE};
static const xx_data_struct_field_desc sxat_edi_size_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxat_edi_size = {UINT32_C(0x60640017),"edi_size",sxat_edi_size_fields,SX_COUNT(sxat_edi_size_fields),SX_LE};
static bool sxat_edi(sx_context*c){uint8_t h[21];if(!sxat_add(c,&sxat_edi_header,0))return false;bool named=false;if(sxat_read(c,0,h,21)){for(unsigned i=8;i<21;i++){if(!h[i]){named=i!=8;break;}if(h[i]<32||h[i]>=127)break;}}if(named&&!sxat_add(c,&sxat_edi_name,8))return false;uint64_t version;if(!sxat_word(c,7,1,false,&version))return false;return version!='2'||(named&&sxat_add(c,&sxat_edi_size,21));}
bool sx_edilzss_build(sx_context*c)
{
 return sxat_edi(c);
}
