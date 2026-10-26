/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Fdcopy Cfi data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_fdcopy_track_fields[] = {
    SX_FIELD("compressed_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxdn_fdcopy_track = {0x60780018U,"fdcopy_track",sxdn_fdcopy_track_fields,SX_COUNT(sxdn_fdcopy_track_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_fdcopy_token_fields[] = {
    SX_FIELD("count_and_repeat","uint16",0,2,SX_NONE),
};
const sx_layout sxdn_fdcopy_token = {0x60780019U,"fdcopy_token",sxdn_fdcopy_token_fields,SX_COUNT(sxdn_fdcopy_token_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_fdcopy_repeat_fields[] = {
    SX_FIELD("repeated_byte","uint8",0,1,SX_NONE),
};
const sx_layout sxdn_fdcopy_repeat = {0x6078001aU,"fdcopy_repeat",sxdn_fdcopy_repeat_fields,SX_COUNT(sxdn_fdcopy_repeat_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
static bool sxdn_cfi(sx_context*c){uint8_t h[2];uint64_t p=0;for(unsigned track=0;track<256&&p<(uint64_t)c->size&&c->count<SXDN_LIMIT;track++){if(!sxdn_read(c,p,h,2)||!SXDN_ADD(c,fdcopy_track,p))break;uint64_t z=sxdn16(h,0),q=p+2;if(!sxdn_span(c,q,z))break;uint64_t end=q+z;while(q<end&&c->count<SXDN_LIMIT){if(end-q<2||!sxdn_read(c,q,h,2))break;uint64_t v=sxdn16(h,0),n=v&0x7fff;if(!n||!SXDN_ADD(c,fdcopy_token,q))return true;q+=2;if(v&0x8000){if(q>=end||!SXDN_ADD(c,fdcopy_repeat,q))return true;q++;}else{if(n>end-q)return true;q+=n;}}p=end;}return c->count!=0;}
bool sx_fdcopy_cfi_build(sx_context*c)
{
 return sxdn_cfi(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
