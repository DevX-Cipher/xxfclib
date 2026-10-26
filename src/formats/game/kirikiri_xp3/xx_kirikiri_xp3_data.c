/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * kirikiri_xp3 data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_xp3_header_fields[]={
 SX_FIELD("signature","bytes",0,11,SX_SIGNATURE),
 SX_FIELD("index_offset","uint64",11,8,SX_OFFSET),
};
const sx_layout sxgp_xp3_header={UINT32_C(0x6036005D),"xp3_header",sxgp_xp3_header_fields,SX_COUNT(sxgp_xp3_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_index_fields[]={
 SX_FIELD("flags","uint8",0,1,SX_FLAGS),
 SX_FIELD("index_size","uint64",1,8,SX_SIZE),
};
const sx_layout sxgp_xp3_index={UINT32_C(0x6036005E),"xp3_index",sxgp_xp3_index_fields,SX_COUNT(sxgp_xp3_index_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_chunk_fields[]={
 SX_FIELD("chunk_id","bytes",0,4,SX_ID),
 SX_FIELD("data_size","uint64",4,8,SX_SIZE),
};
const sx_layout sxgp_xp3_chunk={UINT32_C(0x6036005F),"xp3_chunk",sxgp_xp3_chunk_fields,SX_COUNT(sxgp_xp3_chunk_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_info_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("original_size","uint64",4,8,SX_SIZE),
 SX_FIELD("archived_size","uint64",12,8,SX_SIZE),
 SX_FIELD("name_utf16_units","uint16",20,2,SX_COUNT_PROP),
};
const sx_layout sxgp_xp3_info={UINT32_C(0x60360060),"xp3_info",sxgp_xp3_info_fields,SX_COUNT(sxgp_xp3_info_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_segment_fields[]={
 SX_FIELD("flags","uint32",0,4,SX_FLAGS),
 SX_FIELD("data_offset","uint64",4,8,SX_OFFSET),
 SX_FIELD("original_size","uint64",12,8,SX_SIZE),
 SX_FIELD("archived_size","uint64",20,8,SX_SIZE),
};
const sx_layout sxgp_xp3_segment={UINT32_C(0x60360061),"xp3_segment",sxgp_xp3_segment_fields,SX_COUNT(sxgp_xp3_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_xp3_checksum_fields[]={
 SX_FIELD("adler32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxgp_xp3_checksum={UINT32_C(0x60360062),"xp3_checksum",sxgp_xp3_checksum_fields,SX_COUNT(sxgp_xp3_checksum_fields),SX_LE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_xp3(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,p,z,stop;uint8_t tag[4];if(!SG_ROW(xp3_header,0,end)||!sxgp_word(v,11,8,false,&p,end)||!SG_ROW(xp3_index,p,end)||!sxgp_word(v,p+1,8,false,&z,end)||!sxgp_span(v,p+9,z,end))return false;p+=9;stop=p+z;
 while(p<stop){uint64_t fend;if(!SG_ROW(xp3_chunk,p,stop)||!sxgp_word(v,p+4,8,false,&z,stop)||!sxgp_span(v,p+12,z,stop))return false;p+=12;fend=p+z;
  while(p<fend){if(!SG_ROW(xp3_chunk,p,fend)||!sxgp_read(v,p,tag,4,fend)||!sxgp_word(v,p+4,8,false,&z,fend)||!sxgp_span(v,p+12,z,fend))return false;p+=12;
   const sx_layout*l=!xx_rt_memcmp(tag,"info",4)?&sxgp_xp3_info:!xx_rt_memcmp(tag,"segm",4)?&sxgp_xp3_segment:!xx_rt_memcmp(tag,"adlr",4)?&sxgp_xp3_checksum:NULL;if(l&&!sxgp_row(v,l,p,p+z))return false;p+=z;
  }
 }return p==stop;}
bool sx_kirikiri_xp3_build(sxgp_view*v)
{
 return sxgp_xp3(v);
}
#undef SG_ROW
