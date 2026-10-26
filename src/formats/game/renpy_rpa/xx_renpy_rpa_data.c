/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * renpy_rpa data structures, moved out of the gameplatforms schema family. */
#include "../../xx_format_schema_gameplatforms.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgp_rpa_header_fields[]={
 SX_FIELD("signature","bytes",0,8,SX_SIGNATURE),
 SX_FIELD("index_offset","ascii_hex[16]",8,16,SX_OFFSET),
 SX_FIELD("separator","uint8",24,1,SX_NONE),
 SX_FIELD("xor_key","ascii_hex[8]",25,8,SX_FLAGS),
 SX_FIELD("newline","uint8",33,1,SX_NONE),
};
const sx_layout sxgp_rpa_header={UINT32_C(0x6036006B),"rpa_header",sxgp_rpa_header_fields,SX_COUNT(sxgp_rpa_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_rpa_zlib_fields[]={
 SX_FIELD("compression_method_window","uint8",0,1,SX_FLAGS),
 SX_FIELD("compression_flags","uint8",1,1,SX_FLAGS),
};
const sx_layout sxgp_rpa_zlib={UINT32_C(0x6036006C),"rpa_zlib",sxgp_rpa_zlib_fields,SX_COUNT(sxgp_rpa_zlib_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_rpa_adler_fields[]={
 SX_FIELD("adler32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxgp_rpa_adler={UINT32_C(0x6036006D),"rpa_adler",sxgp_rpa_adler_fields,SX_COUNT(sxgp_rpa_adler_fields),SX_BE};
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
static bool sxgp_rpa(sxgp_view*v)
{uint64_t end=(uint64_t)v->c->size,index=0;uint8_t text[16];if(!SG_ROW(rpa_header,0,end)||!sxgp_read(v,8,text,16,end))return false;for(unsigned i=0;i<16;i++){unsigned d=text[i]>='0'&&text[i]<='9'?text[i]-'0':text[i]>='a'&&text[i]<='f'?text[i]-'a'+10:text[i]>='A'&&text[i]<='F'?text[i]-'A'+10:16;if(d==16)return false;index=(index<<4)|d;}return end>=4&&SG_ROW(rpa_zlib,index,end)&&SG_ROW(rpa_adler,end-4,end);}
bool sx_renpy_rpa_build(sxgp_view*v)
{
 return sxgp_rpa(v);
}
#undef SG_ROW
