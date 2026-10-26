/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PIM MESSAGE data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_pim_header_fields[]={
 SX_FIELD("version_and_type","uint8",0,1,SX_FLAGS),
 SX_FIELD("reserved","uint8",1,1,SX_RESERVED),
 SX_FIELD("checksum","uint16",2,2,SX_CHECKSUM),
};
const sx_layout sxnm_pim_header={UINT32_C(0x60260042),"pim_header",sxnm_pim_header_fields,SX_COUNT(sxnm_pim_header_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_dr_priority_fields[]={
 SX_FIELD("designated_router_priority","uint32",0,4,SX_NONE),
};
const sx_layout sxnm_pim_dr_priority={UINT32_C(0x60260046),"pim_dr_priority",sxnm_pim_dr_priority_fields,SX_COUNT(sxnm_pim_dr_priority_fields),SX_BE};
static const xx_data_struct_field_desc sxnm_pim_generation_id_fields[]={
 SX_FIELD("generation_identifier","uint32",0,4,SX_ID),
};
const sx_layout sxnm_pim_generation_id={UINT32_C(0x60260047),"pim_generation_id",sxnm_pim_generation_id_fields,SX_COUNT(sxnm_pim_generation_id_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_pim(sxnm_view *v)
{
 if(!SN_ROW(pim_header,0,v->n))return false;size_t at=4;while(at<v->n){if(!SN_ROW(pim_option_header,at,v->n))return false;unsigned t=sxnm_u16(v->p+at),n=sxnm_u16(v->p+at+2);at+=4;if(!sxnm_need(v,at,n,v->n))return false;const sx_layout *l=t==1?&sxnm_pim_holdtime:t==2?&sxnm_pim_lan_prune_delay:t==19?&sxnm_pim_dr_priority:t==20?&sxnm_pim_generation_id:NULL;if(l&&!sxnm_row(v,l,at,at+n))return false;at+=n;}return true;
}
bool sx_pim_message_build(sxnm_view*v)
{
 return sxnm_pim(v);
}
#undef SN_ROW
