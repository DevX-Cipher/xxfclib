/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * bleubleu_famistudio data structures, moved out of the musicprojects schema family. */
#include "../../../xx_format_schema_musicprojects.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmp_famistudio_file_header_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("format_version","int32",4,4,SX_NONE),
 SX_FIELD("uncompressed_size","int32",8,4,SX_SIZE),
};
const sx_layout sxmp_famistudio_file_header={0x607b0001U,"famistudio_file_header",sxmp_famistudio_file_header_fields,SX_COUNT(sxmp_famistudio_file_header_fields),SX_LE};
#define MP_ROW(name,at,end) sxmp_row(v,&sxmp_##name,(at),(end))
static bool sxmp_famistudio(sxmp_view*v)
{uint64_t e=v->c->size,version,z;return MP_ROW(famistudio_file_header,0,e)&&sxmp_u(v,4,4,&version,e)&&version>0&&version<=INT32_MAX&&sxmp_u(v,8,4,&z,e)&&z<=INT32_MAX;}
bool sx_bleubleu_famistudio_build(sxmp_view*v)
{
 return sxmp_famistudio(v);
}
#undef MP_ROW
