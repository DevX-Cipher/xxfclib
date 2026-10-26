/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DeskSoft data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_installer_size_fields[]={
 SX_FIELD("size","uint32le",0,4,SX_SIZE),
};
const sx_layout sxir_installer_size={0x6080000bU,"installer_size",sxir_installer_size_fields,SX_COUNT(sxir_installer_size_fields),SX_LE};
static const xx_data_struct_field_desc sxir_desksoft_header_fields[]={
 SX_FIELD("signature","char[19]",0,19,SX_SIGNATURE),
};
const sx_layout sxir_desksoft_header={0x60800029U,"desksoft_header",sxir_desksoft_header_fields,SX_COUNT(sxir_desksoft_header_fields),SX_LE};
static const xx_data_struct_field_desc sxir_desksoft_end_fields[]={
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
};
const sx_layout sxir_desksoft_end={0x6080002aU,"desksoft_end",sxir_desksoft_end_fields,SX_COUNT(sxir_desksoft_end_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_desksoft(sxir_view*v)
{uint64_t end=v->c->size,at,cert;if(!sxir_pe(v,0,end,&at,&cert)||!sxir_eq(v,at,"<Setup Data Header>",19,end)||!IR_ROW(desksoft_header,at,end))return false;at+=19;
 while(at<end){if(sxir_eq(v,at,"<Setup Data End>",16,end))return at+16==end&&IR_ROW(desksoft_end,at,end);uint64_t len,n;if(!sxir_zstr(v,&at,end,&len)||!len||!IR_U(at,4,n,end)||!IR_ROW(installer_size,at,end)||!sxir_span(v,at+4,n,end))return false;at+=4+n;}return false;}
bool sx_desksoft_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_desksoft(v);
}
#undef IR_ROW
#undef IR_U
