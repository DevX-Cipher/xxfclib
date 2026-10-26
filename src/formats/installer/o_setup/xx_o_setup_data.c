/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * O_SETUP data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_osetup_member_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
 SX_FIELD("modification_time","uint32",8,4,SX_TIME),
 SX_FIELD("name","char[13]",12,13,SX_NONE),
 SX_FIELD("writer_memory","uint8[19]",25,19,SX_NONE),
};
const sx_layout sxan_osetup_member = {UINT32_C(0x60770019),"osetup_member",sxan_osetup_member_fields,SX_COUNT(sxan_osetup_member_fields),SX_LE};
static const xx_data_struct_field_desc sxan_osetup_trailer_6_fields[] = {
 SX_FIELD("signature","char[6]",0,6,SX_SIGNATURE),
 SX_FIELD("first_record_offset","uint32",6,4,SX_OFFSET),
 SX_FIELD("member_count","uint16",10,2,SX_COUNT_PROP),
};
const sx_layout sxan_osetup_trailer_6 = {UINT32_C(0x6077001a),"osetup_trailer_6",sxan_osetup_trailer_6_fields,SX_COUNT(sxan_osetup_trailer_6_fields),SX_LE};
static const xx_data_struct_field_desc sxan_osetup_trailer_8_fields[] = {
 SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
 SX_FIELD("first_record_offset","uint32",8,4,SX_OFFSET),
 SX_FIELD("member_count","uint16",12,2,SX_COUNT_PROP),
};
const sx_layout sxan_osetup_trailer_8 = {UINT32_C(0x6077001b),"osetup_trailer_8",sxan_osetup_trailer_8_fields,SX_COUNT(sxan_osetup_trailer_8_fields),SX_LE};
static bool sxan_osetup(sx_context*c){uint8_t h[8];uint64_t trailer,p,n,z;unsigned tag=8;if(c->size<14)return false;trailer=(uint64_t)c->size-14;if(!sxan_read(c,trailer,h,8))return false;if(xx_rt_memcmp(h,"OSETUPS\0",8)&&xx_rt_memcmp(h,"OSETUPA\0",8)){tag=6;trailer=(uint64_t)c->size-12;if(!sxan_read(c,trailer,h,6)||xx_rt_memcmp(h,"OSETUP",6))return false;}if(!sxan_add(c,tag==8?&sxan_osetup_trailer_8:&sxan_osetup_trailer_6,trailer)||!sxan_word(c,trailer+tag,4,false,&p)||!sxan_word(c,trailer+tag+4,2,false,&n))return false;for(uint64_t i=0;i<n;i++){if(p>trailer||trailer-p<44||!sxan_word(c,p+4,4,false,&z)||!sxan_add(c,&sxan_osetup_member,p))return false;p+=44;if(z>trailer-p)return true;p+=z;}return true;}
bool sx_o_setup_build(sx_context*c)
{
bool ok=false;
ok=sxan_osetup(c);
(void)ok;return c->count&&sxan_finish(c);
}
