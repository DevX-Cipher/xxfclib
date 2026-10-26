/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Gentee installer data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_gentee_locator_fields[] = {
    SX_FIELD("payload_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("first_block_size","uint32",4,4,SX_SIZE),
    SX_FIELD("first_unpacked_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxil_gentee_locator = {0x60850038U,"gentee_locator",sxil_gentee_locator_fields,SX_COUNT(sxil_gentee_locator_fields),SX_LE};
static const xx_data_struct_field_desc sxil_gentee_block_size_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxil_gentee_block_size = {0x60850039U,"gentee_block_size",sxil_gentee_block_size_fields,SX_COUNT(sxil_gentee_block_size_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
/* Gentee uses the largest nonempty section end, without SizeOfHeaders. */
static bool sxil_gentee_overlay(sx_context*c,uint64_t*out){uint8_t d[64],h[24],row[40];if(!sxil_span(c,0,0x3fc)||!sxil_read(c,0,d,64)||d[0]!='M'||d[1]!='Z')return false;uint64_t lf=sxil32(d+60,false);if(lf<64||lf>0x10000||!sxil_read(c,lf,h,24)||xx_rt_memcmp(h,"PE\0\0",4))return false;unsigned n=sxil16(h+6,false),opt=sxil16(h+20,false);uint64_t tab=lf+24+opt,end=0;if(!n||n>96||!sxil_span(c,tab,40U*n))return false;for(unsigned i=0;i<n;i++){if(!sxil_read(c,tab+40U*i,row,40))return false;uint64_t z=sxil32(row+16,false),p=sxil32(row+20,false);if(z&&p+z>end)end=p+z;}if(!end||!sxil_span(c,end,12))return false;*out=end;return true;}
static bool sxil_gentee_header(sx_context*c,uint64_t p){uint32_t z;return sxil_u32(c,p,&z)&&z>0&&z<0x100000&&sxil_eq(c,p+4,"\xab\x67\xa7\x36\xff\x4d\xfb\x6f",8);}
static bool sxil_gentee(sx_context*c,sxil_records*r){uint64_t overlay,p;uint32_t off;if(!sxil_gentee_overlay(c,&overlay))return true;p=overlay;
 if(sxil_u32(c,0x3f0,&off)&&off>=overlay&&sxil_gentee_header(c,off)){p=off;if(!SXIL_ADD(c,gentee_locator,0x3f0))return false;}
 else if(!sxil_gentee_header(c,p))return true;
 if(!SXIL_ADD(c,gentee_block_size,p))return false;
 for(size_t i=0;i<r->count;i++){sxil_member*m=r->items+i;if(m->header_size>=4&&m->header!=p&&!SXIL_ADD(c,gentee_block_size,m->header))return false;}return true;}
bool sx_gentee_installer_build(sx_context*c,sxil_records records)
{
 return sxil_gentee(c,&records);
}
#undef SXIL_ADD
