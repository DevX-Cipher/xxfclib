/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Shiru's TFM Music Maker tune (.TFD) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmw_tfd_header_fields[]={
 SX_FIELD("magic","bytes",0,4,SX_SIGNATURE),
};
const sx_layout sxmw_tfd_header={UINT32_C(0x60870029),"tfd_header",sxmw_tfd_header_fields,SX_COUNT(sxmw_tfd_header_fields),SX_LE};
static const xx_data_struct_field_desc sxmw_tfd_write_fields[]={
 SX_FIELD("register_index","uint8",0,1,SX_ID),
 SX_FIELD("value","uint8",1,1,SX_NONE),
};
const sx_layout sxmw_tfd_write={UINT32_C(0x6087002C),"tfd_write",sxmw_tfd_write_fields,SX_COUNT(sxmw_tfd_write_fields),SX_LE};
#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
#define MW_TAKE(l,p,n,end) sxmw_take(v,&sxmw_##l,(p),(n),(end))
static bool sxmw_tfd(sxmw_view*v)
{uint64_t end=v->c->size,p=4,cmd;
 if(!sxmw_eq(v,0,"TFMD",4,end)||!MW_ROW(tfd_header,0,end)||!sxmw_cstring(v,&p,end,65)||!sxmw_cstring(v,&p,end,65)||!sxmw_cstring(v,&p,end,385))return false;
 while(p<end){if(!sxmw_u(v,p,1,&cmd,end))return false;if(cmd>=0xfa){if(!sxmw_take(v,cmd==0xfe?&sxmw_tfd_skip:&sxmw_tfd_command,&p,1,end))return false;if(cmd==0xfb)return true;}else if(!MW_TAKE(tfd_write,&p,1,end))return false;}return false;}
bool sx_shiru_tfmd_build(sxmw_view*v)
{
 return sxmw_tfd(v);
}
#undef MW_ROW
#undef MW_TAKE
