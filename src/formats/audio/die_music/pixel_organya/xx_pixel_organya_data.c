/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Amaya 'Pixel' Daisuke's Organya/ORG Maker module (.ORG) data structures, moved out of the musicnext schema family. */
#include "../../../xx_format_schema_musicnext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmn_org_note_fields[]={
 SX_FIELD("note","uint8",0,1,SX_ID),
};
const sx_layout sxmn_org_note={UINT32_C(0x6076001A),"org_note",sxmn_org_note_fields,SX_COUNT(sxmn_org_note_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_length_fields[]={
 SX_FIELD("length","uint8",0,1,SX_NONE),
};
const sx_layout sxmn_org_length={UINT32_C(0x6076001B),"org_length",sxmn_org_length_fields,SX_COUNT(sxmn_org_length_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_volume_fields[]={
 SX_FIELD("volume","uint8",0,1,SX_NONE),
};
const sx_layout sxmn_org_volume={UINT32_C(0x6076001C),"org_volume",sxmn_org_volume_fields,SX_COUNT(sxmn_org_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxmn_org_pan_fields[]={
 SX_FIELD("pan","uint8",0,1,SX_NONE),
};
const sx_layout sxmn_org_pan={UINT32_C(0x6076001D),"org_pan",sxmn_org_pan_fields,SX_COUNT(sxmn_org_pan_fields),SX_LE};
#define MN_ROW(l,at,end) sxmn_row(v,&sxmn_##l,(at),(end))
static bool sxmn_org(sxmn_view*v)
{uint64_t end=v->c->size,at=114;if(!MN_ROW(org_header,0,end)||!sxmn_table(v,&sxmn_org_instrument,18,16,end))return false;for(unsigned i=0;i<16;i++){uint64_t n;if(!sxmn_word(v,22+6*i,2,false,&n,end)||!sxmn_table(v,&sxmn_org_position,at,n,end))return false;at+=n*4;const sx_layout*fields[]={&sxmn_org_note,&sxmn_org_length,&sxmn_org_volume,&sxmn_org_pan};for(unsigned j=0;j<4;j++){if(!sxmn_table(v,fields[j],at,n,end))return false;at+=n;}}return true;}
bool sx_pixel_organya_build(sxmn_view*v)
{
 return sxmn_org(v);
}
#undef MN_ROW
