/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SAF data structures, moved out of the archivetails schema family. */
#include "../../xx_format_schema_archivetails.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxat_saf_banner29_fields[] = {
 SX_FIELD("banner","char[29]",0,29,SX_SIGNATURE),
};
const sx_layout sxat_saf_banner29 = {UINT32_C(0x60640003),"saf_banner29",sxat_saf_banner29_fields,SX_COUNT(sxat_saf_banner29_fields),SX_LE};
static const xx_data_struct_field_desc sxat_saf_banner47_fields[] = {
 SX_FIELD("banner","char[47]",0,47,SX_SIGNATURE),
};
const sx_layout sxat_saf_banner47 = {UINT32_C(0x60640004),"saf_banner47",sxat_saf_banner47_fields,SX_COUNT(sxat_saf_banner47_fields),SX_LE};
static const xx_data_struct_field_desc sxat_saf_member_fields[] = {
 SX_FIELD("name","char[14]",0,14,SX_NONE),
 SX_FIELD("uncompressed_size","int32",14,4,SX_SIZE),
 SX_FIELD("compressed_size","int32",18,4,SX_SIZE),
 SX_FIELD("dos_date","uint16",22,2,SX_NONE),
 SX_FIELD("dos_time","uint16",24,2,SX_NONE),
 SX_FIELD("unknown","uint8",26,1,SX_NONE),
 SX_FIELD("method","uint8",27,1,SX_NONE),
 SX_FIELD("opaque","uint8[7]",28,7,SX_NONE),
};
const sx_layout sxat_saf_member = {UINT32_C(0x60640005),"saf_member",sxat_saf_member_fields,SX_COUNT(sxat_saf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxat_saf_chunk_fields[] = {
 SX_FIELD("compressed_size","int32",0,4,SX_SIZE),
};
const sx_layout sxat_saf_chunk = {UINT32_C(0x60640006),"saf_chunk",sxat_saf_chunk_fields,SX_COUNT(sxat_saf_chunk_fields),SX_LE};
static bool sxat_saf(sx_context*c){uint8_t b[47];if(!sxat_read(c,0,b,47))return false;uint64_t p=b[27]==0x1a&&b[28]==0?29:47;if(!sxat_add(c,p==29?&sxat_saf_banner29:&sxat_saf_banner47,0))return false;while(sxat_span(c,p,35)){uint8_t h[35];if(!sxat_read(c,p,h,35))return false;uint64_t z=sxat_uint(h+18,4,false);if(z>INT32_MAX||!sxat_add(c,&sxat_saf_member,p))return false;p+=35;if(!sxat_span(c,p,z))return true;if(h[27]!=3){uint64_t q=p,end=p+z;while(q<end){uint64_t n;if(end-q<4||!sxat_word(c,q,4,false,&n)||n>INT32_MAX||!sxat_add(c,&sxat_saf_chunk,q))break;q+=4;if(n>end-q)break;q+=n;}}p+=z;}return true;}
bool sx_saf_build(sx_context*c)
{
 return sxat_saf(c);
}
