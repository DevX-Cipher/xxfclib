/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NTLM MESSAGE data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_ntlm_version_fields[]={
 SX_FIELD("product_major","uint8",0,1,SX_ID),
 SX_FIELD("product_minor","uint8",1,1,SX_ID),
 SX_FIELD("product_build","uint16",2,2,SX_ID),
 SX_FIELD("reserved","bytes",4,3,SX_RESERVED),
 SX_FIELD("revision","uint8",7,1,SX_ID),
};
const sx_layout sxnm_ntlm_version={UINT32_C(0x6026005E),"ntlm_version",sxnm_ntlm_version_fields,SX_COUNT(sxnm_ntlm_version_fields),SX_LE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_ntlm(sxnm_view *v)
{
 if(!SN_ROW(ntlm_negotiate,0,v->n))return false;uint32_t flags=xx_data_get_u32(v->p+12,4,0,false);if(flags&0x02000000&&!SN_ROW(ntlm_version,32,v->n))return false;
 for(unsigned i=0;i<2;i++){size_t at=16+i*8;uint16_t n=xx_data_get_u16(v->p+at,2,0,false);uint32_t off=xx_data_get_u32(v->p+at+4,4,0,false);if(n&&!sxnm_need(v,off,n,v->n))return false;}return true;
}
bool sx_ntlm_message_build(sxnm_view*v)
{
 return sxnm_ntlm(v);
}
#undef SN_ROW
