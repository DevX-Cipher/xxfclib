/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Nokia OTA bitmap data structures, moved out of the binaryresources schema family. */
#include "../../xx_format_schema_binaryresources.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"

static const xx_data_struct_field_desc sxbrs_ota_bitmap_short_fields[] = {
    SX_FIELD("infofield","uint8",0,1,SX_FLAGS),
    SX_FIELD("width","uint8",1,1,SX_NONE),
    SX_FIELD("height","uint8",2,1,SX_NONE),
    SX_FIELD("depth","uint8",3,1,SX_NONE),
};
const sx_layout sxbrs_ota_bitmap_short = {UINT32_C(0x603e0001),"ota_bitmap_short",sxbrs_ota_bitmap_short_fields,SX_COUNT(sxbrs_ota_bitmap_short_fields),SX_LE};
static const xx_data_struct_field_desc sxbrs_ota_bitmap_extended_fields[] = {
    SX_FIELD("infofield","uint8",0,1,SX_FLAGS),
    SX_FIELD("width","uint16",1,2,SX_NONE),
    SX_FIELD("height","uint16",3,2,SX_NONE),
    SX_FIELD("depth","uint8",5,1,SX_NONE),
};
const sx_layout sxbrs_ota_bitmap_extended = {UINT32_C(0x603e0002),"ota_bitmap_extended",sxbrs_ota_bitmap_extended_fields,SX_COUNT(sxbrs_ota_bitmap_extended_fields),SX_BE};
#define N(p,w) sxbrs_num(c,(p),(w),false)
#define B(p,w) sxbrs_num(c,(p),(w),true)
static bool sxbrs_ota(sx_context*c){uint64_t flags=N(0,1),n=(flags&16)?6:4;if(flags&~16U||c->size<(int64_t)n)return false;uint64_t w=N(1,1),h=N(2,1);if(flags&16){w=B(1,2);h=B(3,2);}if(!w||w>8192||!h||h>4095||N(n-1,1)!=1||(w+7)/8*h!=(uint64_t)c->size-n)return false;return sxbrs_add(c,flags&16?&sxbrs_ota_bitmap_extended:&sxbrs_ota_bitmap_short,0);}
bool sx_nokia_ota_bitmap_build(sx_context*c)
{
 return sxbrs_ota(c);
}
#undef N
#undef B
