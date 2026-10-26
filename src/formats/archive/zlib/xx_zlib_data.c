/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * zlib data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_zlib_dictionary_fields[] = {
    SX_FIELD("dictionary_adler32", "uint32", 0, 4, SX_CHECKSUM),
};
const sx_layout sx_p_zlib_dictionary = { UINT32_C(0x60070024), "zlib_dictionary", sx_p_zlib_dictionary_fields, SX_COUNT(sx_p_zlib_dictionary_fields), SX_BE };
static const xx_data_struct_field_desc sx_p_zlib_trailer_fields[] = {
    SX_FIELD("adler32", "uint32", 0, 4, SX_CHECKSUM),
};
const sx_layout sx_p_zlib_trailer = { UINT32_C(0x60070025), "zlib_trailer", sx_p_zlib_trailer_fields, SX_COUNT(sx_p_zlib_trailer_fields), SX_BE };
bool sx_zlib_build(sx_context*c)
{
    uint8_t b[16];bool ok=false;
    if(sx_read(c,0,b,2)&&(b[0]&15)==8&&(b[0]>>4)<=7&&(((unsigned)b[0]<<8)|b[1])%31==0&&c->size>=6+(b[1]&32?4:0)){ok=sx_add(c,&sx_p_zlib_header,0,2)&&(!(b[1]&32)||sx_add(c,&sx_p_zlib_dictionary,2,4))&&sx_add(c,&sx_p_zlib_trailer,c->size-4,4);}
    return ok;
}
