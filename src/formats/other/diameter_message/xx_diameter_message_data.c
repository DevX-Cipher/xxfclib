/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DIAMETER MESSAGE data structures, moved out of the networkmeta schema family. */
#include "../../xx_format_schema_networkmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxnm_diameter_vendor_id_fields[]={
 SX_FIELD("vendor_id","uint32",0,4,SX_ID),
};
const sx_layout sxnm_diameter_vendor_id={UINT32_C(0x60260032),"diameter_vendor_id",sxnm_diameter_vendor_id_fields,SX_COUNT(sxnm_diameter_vendor_id_fields),SX_BE};
#define SN_ROW(l,at,end) sxnm_row(v,&sxnm_##l,(at),(end))
static bool sxnm_diameter(sxnm_view *v)
{
 if(!SN_ROW(diameter_header,0,v->n)||sxnm_u24(v->p+1)!=v->n)return false;size_t at=20;
 while(at<v->n){if(!SN_ROW(diameter_avp_header,at,v->n))return false;uint32_t code=sxnm_u32(v->p+at);size_t n=sxnm_u24(v->p+at+5);if(n<8||!sxnm_need(v,at,n+(4-n%4)%4,v->n))return false;
  if(code==257&&!SN_ROW(diameter_address_family,at+8,at+n))return false;if(code==266&&!SN_ROW(diameter_vendor_id,at+8,at+n))return false;at+=n+(4-n%4)%4;
 }return true;
}
bool sx_diameter_message_build(sxnm_view*v)
{
 return sxnm_diameter(v);
}
#undef SN_ROW
