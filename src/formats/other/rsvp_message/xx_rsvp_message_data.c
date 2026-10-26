/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * RSVP MESSAGE data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_rsvp_hello_instances_fields[]={
 SX_FIELD("source_instance","uint32",0,4,SX_ID),
 SX_FIELD("destination_instance","uint32",4,4,SX_ID),
};
const sx_layout sxnm_rsvp_hello_instances={UINT32_C(0x60260041),"rsvp_hello_instances",sxnm_rsvp_hello_instances_fields,SX_COUNT(sxnm_rsvp_hello_instances_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
bool sx_rsvp_message_build(sxnm_view*v)
{
 return SN_ROW(rsvp_header,0,v->n)&&SN_ROW(rsvp_object_header,8,v->n)&&SN_ROW(rsvp_hello_instances,12,v->n);
}
#undef SN_ROW
