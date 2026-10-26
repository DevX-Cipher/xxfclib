/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SFX embedded archive data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_localzip_softpaq_table_fields[]={
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown_4","uint8[4]",4,4,SX_NONE),
 SX_FIELD("first_size","uint32",8,4,SX_SIZE),
 SX_FIELD("first_offset","uint32",12,4,SX_OFFSET),
 SX_FIELD("unknown_16","uint8[8]",16,8,SX_NONE),
 SX_FIELD("second_size","uint32",24,4,SX_SIZE),
 SX_FIELD("second_offset","uint32",28,4,SX_OFFSET),
 SX_FIELD("third_size","uint32",32,4,SX_SIZE),
 SX_FIELD("third_offset","uint32",36,4,SX_OFFSET),
};
const sx_layout sxaend_localzip_softpaq_table={UINT32_C(0x60840044),"localzip_softpaq_table",sxaend_localzip_softpaq_table_fields,SX_COUNT(sxaend_localzip_softpaq_table_fields),SX_LE};
static bool sxaend_localzip(sx_context*c){uint64_t cap=(uint64_t)c->size<131072?(uint64_t)c->size:131072;for(uint64_t p=0;p+40<=cap;p++){uint8_t h[40];if((p&4095)==0&&xx_pd_is_stopped(c->pd))return false;if(!sxaend_read(c,p,h,1))return false;if(h[0]!='!')continue;if(!sxaend_read(c,p,h,40)||xx_rt_memcmp(h,"!3PS",4))continue;uint64_t a=sxaend_uint(h+12,4,false),az=sxaend_uint(h+8,4,false),b=sxaend_uint(h+28,4,false),bz=sxaend_uint(h+24,4,false),d=sxaend_uint(h+36,4,false),dz=sxaend_uint(h+32,4,false);if(a>=p+40&&sxaend_span(c,a,az)&&b==a+az&&sxaend_span(c,b,bz)&&d==b+bz&&sxaend_span(c,d,dz)&&d+dz==(uint64_t)c->size&&!sxaend_add(c,&sxaend_localzip_softpaq_table,p))return false;break;}return sxaend_carrier_records(c);}
bool sx_sfx_localzip_build(sx_context*c)
{
 return sxaend_localzip(c);
}
