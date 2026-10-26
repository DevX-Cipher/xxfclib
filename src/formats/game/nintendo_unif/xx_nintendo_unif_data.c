/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * nintendo_unif data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_unif_header_fields[]={
 SX_FIELD("signature","bytes",0,4,SX_SIGNATURE),
 SX_FIELD("version","uint32",4,4,SX_ID),
 SX_FIELD("reserved","bytes",8,24,SX_RESERVED),
};
const sx_layout sxgp_unif_header={UINT32_C(0x6036000F),"unif_header",sxgp_unif_header_fields,SX_COUNT(sxgp_unif_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_unif_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxgp_unif_chunk={UINT32_C(0x60360010),"unif_chunk",sxgp_unif_chunk_fields,SX_COUNT(sxgp_unif_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_unif_crc_fields[]={
 SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxgp_unif_crc={UINT32_C(0x60360011),"unif_crc",sxgp_unif_crc_fields,SX_COUNT(sxgp_unif_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_unif_mirroring_fields[]={
 SX_FIELD("mirroring","uint8",0,1,SX_ID),
};
const sx_layout sxgp_unif_mirroring={UINT32_C(0x60360012),"unif_mirroring",sxgp_unif_mirroring_fields,SX_COUNT(sxgp_unif_mirroring_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_unif(sxgp_view*v){uint64_t end=(uint64_t)v->c->size,p=32,z;uint8_t tag[4];if(!SG_ROW(unif_header,0,end))return false;while(p<end){if(!SG_ROW(unif_chunk,p,end)||!sxgp_read(v,p,tag,4,end)||!sxgp_word(v,p+4,4,false,&z,end)||!sxgp_span(v,p+8,z,end))return false;p+=8;if((!xx_rt_memcmp(tag,"PCK",3)||!xx_rt_memcmp(tag,"CCK",3))&&z==4){if(!SG_ROW(unif_crc,p,p+z))return false;}else if(!xx_rt_memcmp(tag,"MIRR",4)&&z==1&&!SG_ROW(unif_mirroring,p,p+z))return false;p+=z;}return p==end;}
bool sx_nintendo_unif_build(sxgp_view*v)
{
 return sxgp_unif(v);
}
#undef SG_ROW
