/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PPTP MESSAGE data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_pptp_start_control_connection_fields[]={
 SX_FIELD("protocol_version","uint16",0,2,SX_ID),
 SX_FIELD("reserved","uint16",2,2,SX_RESERVED),
 SX_FIELD("framing_capabilities","uint32",4,4,SX_FLAGS),
 SX_FIELD("bearer_capabilities","uint32",8,4,SX_FLAGS),
 SX_FIELD("maximum_channels","uint16",12,2,SX_COUNT_PROP),
 SX_FIELD("firmware_revision","uint16",14,2,SX_ID),
 SX_FIELD("host_name","char[64]",16,64,SX_STRING),
 SX_FIELD("vendor_string","char[64]",80,64,SX_STRING),
};
const sx_layout sxnm_pptp_start_control_connection={UINT32_C(0x6026003E),"pptp_start_control_connection",sxnm_pptp_start_control_connection_fields,SX_COUNT(sxnm_pptp_start_control_connection_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
bool sx_pptp_message_build(sxnm_view*v)
{
 return SN_ROW(pptp_control_header,0,v->n)&&SN_ROW(pptp_start_control_connection,12,v->n);
}
#undef SN_ROW
