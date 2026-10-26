/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * GKSETUP data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_gksetup_banner_fields[] = {
 SX_FIELD("banner","char[39]",0,39,SX_SIGNATURE),
};
const sx_layout sxan_gksetup_banner = {UINT32_C(0x6077000f),"gksetup_banner",sxan_gksetup_banner_fields,SX_COUNT(sxan_gksetup_banner_fields),SX_LE};
static const xx_data_struct_field_desc sxan_gksetup_signature_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
};
const sx_layout sxan_gksetup_signature = {UINT32_C(0x60770010),"gksetup_signature",sxan_gksetup_signature_fields,SX_COUNT(sxan_gksetup_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxan_gksetup_data_offset_fields[] = {
 SX_FIELD("data_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxan_gksetup_data_offset = {UINT32_C(0x60770011),"gksetup_data_offset",sxan_gksetup_data_offset_fields,SX_COUNT(sxan_gksetup_data_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxan_gksetup_member_fields[] = {
 SX_FIELD("name","char[260]",0,260,SX_NONE),
 SX_FIELD("attributes","uint32",260,4,SX_FLAGS),
 SX_FIELD("creation_time","uint64",264,8,SX_NONE),
 SX_FIELD("access_time","uint64",272,8,SX_NONE),
 SX_FIELD("modification_time","uint64",280,8,SX_NONE),
 SX_FIELD("payload_size","int32",288,4,SX_SIZE),
};
const sx_layout sxan_gksetup_member = {UINT32_C(0x60770012),"gksetup_member",sxan_gksetup_member_fields,SX_COUNT(sxan_gksetup_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_archivenext_padding32_fields[] = {
 SX_FIELD("padding","uint32",0,4,SX_NONE),
};
const sx_layout sxan_archivenext_padding32 = {UINT32_C(0x60770047),"archivenext_padding32",sxan_archivenext_padding32_fields,SX_COUNT(sxan_archivenext_padding32_fields),SX_LE};
static bool sxan_gk_header(sx_context*c,uint64_t p,uint64_t*z,uint64_t*attrs,bool*pop){uint8_t h[292];if(!sxan_read(c,p,h,sizeof(h)))return false;unsigned len=0;while(len<259&&h[len]){if(h[len]<32)return false;len++;}if(!len)return false;*z=sxan_uint(h+288,4,false);*attrs=sxan_uint(h+260,4,false);*pop=len==2&&h[0]=='.'&&h[1]=='.';return *z<=INT32_MAX;}
static bool sxan_gk(sx_context*c){uint64_t p,z,attrs;bool pop,padded=true;if(!sxan_add(c,&sxan_gksetup_banner,0)||!sxan_add(c,&sxan_gksetup_signature,80)||!sxan_add(c,&sxan_gksetup_data_offset,296)||!sxan_word(c,296,4,false,&p))return false;uint64_t q=p;for(unsigned i=0;i<2;i++){uint64_t zero;if(!sxan_gk_header(c,q,&z,&attrs,&pop)||!sxan_span(c,q+292,z)||!sxan_word(c,q+292,4,false,&zero)||zero){padded=false;break;}q+=296+z;}while(sxan_gk_header(c,p,&z,&attrs,&pop)){if(!sxan_add(c,&sxan_gksetup_member,p))return false;p+=292;if(padded){uint64_t zero;if(!sxan_word(c,p,4,false,&zero)||zero)return true;if(!sxan_add(c,&sxan_archivenext_padding32,p))return false;p+=4;}if(pop)continue;if(attrs&16){if(z)return true;continue;}if(!sxan_span(c,p,z))return true;p+=z;}return true;}
bool sx_gksetup_build(sx_context*c)
{
bool ok=false;
ok=sxan_gk(c);
(void)ok;return c->count&&sxan_finish(c);
}
