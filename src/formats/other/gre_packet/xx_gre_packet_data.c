/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GRE PACKET data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_gre_checksum_fields[]={
 SX_FIELD("checksum","uint16",0,2,SX_CHECKSUM),
 SX_FIELD("reserved","uint16",2,2,SX_RESERVED),
};
const sx_layout sxnm_gre_checksum={UINT32_C(0x6026004F),"gre_checksum",sxnm_gre_checksum_fields,SX_COUNT(sxnm_gre_checksum_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_gre_key_fields[]={
 SX_FIELD("key","uint32",0,4,SX_ID),
};
const sx_layout sxnm_gre_key={UINT32_C(0x60260050),"gre_key",sxnm_gre_key_fields,SX_COUNT(sxnm_gre_key_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_gre_sequence_fields[]={
 SX_FIELD("sequence_number","uint32",0,4,SX_ID),
};
const sx_layout sxnm_gre_sequence={UINT32_C(0x60260051),"gre_sequence",sxnm_gre_sequence_fields,SX_COUNT(sxnm_gre_sequence_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_gre(sxnm_view *v)
{
 if(!SN_ROW(gre_header,0,v->n))return false;unsigned f=sxnm_u16(v->p);size_t at=4;if(f&0x8000){if(!SN_ROW(gre_checksum,at,v->n))return false;at+=4;}if(f&0x2000){if(!SN_ROW(gre_key,at,v->n))return false;at+=4;}if(f&0x1000){if(!SN_ROW(gre_sequence,at,v->n))return false;at+=4;}return sxnm_ip(v,at,v->n);
}
bool sx_gre_packet_build(sxnm_view*v)
{
 return sxnm_gre(v);
}
#undef SN_ROW
