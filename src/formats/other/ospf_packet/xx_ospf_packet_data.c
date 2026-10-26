/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * OSPF PACKET data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_ospfv2_neighbor_fields[]={
 SX_FIELD("neighbor_router_id","bytes",0,4,SX_NONE),
};
const sx_layout sxnm_ospfv2_neighbor={UINT32_C(0x6026000E),"ospfv2_neighbor",sxnm_ospfv2_neighbor_fields,SX_COUNT(sxnm_ospfv2_neighbor_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_ospf(sxnm_view *v){if(!SN_ROW(ospfv2_header,0,v->n)||!SN_ROW(ospfv2_hello,24,v->n)||sxnm_u16(v->p+2)!=v->n)return false;for(size_t at=44;at<v->n;at+=4)if(!SN_ROW(ospfv2_neighbor,at,v->n))return false;return true;}
bool sx_ospf_packet_build(sxnm_view*v)
{
 return sxnm_ospf(v);
}
#undef SN_ROW
