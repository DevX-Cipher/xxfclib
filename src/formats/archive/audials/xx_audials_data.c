/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * AUDIALS data structures, moved out of the archivenext schema family. */
#include "../../xx_format_schema_archivenext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxan_audials_count_fields[] = {
 SX_FIELD("member_count","ascii_decimal",0,0,SX_COUNT_PROP),
};
const sx_layout sxan_audials_count = {UINT32_C(0x60770040),"audials_count",sxan_audials_count_fields,SX_COUNT(sxan_audials_count_fields),SX_LE};
static const xx_data_struct_field_desc sxan_audials_offset_fields[] = {
 SX_FIELD("data_offset","ascii_decimal",0,0,SX_OFFSET),
};
const sx_layout sxan_audials_offset = {UINT32_C(0x60770041),"audials_offset",sxan_audials_offset_fields,SX_COUNT(sxan_audials_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxan_audials_size_fields[] = {
 SX_FIELD("payload_size","ascii_decimal",0,0,SX_SIZE),
};
const sx_layout sxan_audials_size = {UINT32_C(0x60770042),"audials_size",sxan_audials_size_fields,SX_COUNT(sxan_audials_size_fields),SX_LE};
static bool sxan_line(sx_context*c,uint64_t p,uint64_t*end){uint8_t b;*end=p;for(unsigned i=0;i<8192;i++){if(!sxan_read(c,*end,&b,1))return false;if(b==13){uint8_t next;if(!sxan_read(c,*end+1,&next,1)||next!=10)return false;return true;}if(b<32&&b!=9)return false;(*end)++;}return false;}
static bool sxan_audials(sx_context*c){uint64_t p=0,end,n=0;if(!sxan_line(c,p,&end)||end<=12||end-12>20)return false;uint8_t digits[20];if(!sxan_read(c,12,digits,(size_t)(end-12)))return false;for(uint64_t i=0;i<end-12;i++){if(digits[i]==' ')continue;if(digits[i]<'0'||digits[i]>'9'||n>65536)return false;n=n*10+digits[i]-'0';}if(!sxan_text(c,&sxan_audials_count,12,end-12,false))return false;p=end+2;for(uint64_t i=0;i<n;i++){uint64_t tab1=p,tab2;uint8_t b;if(!sxan_line(c,p,&end))return false;while(tab1<end){if(!sxan_read(c,tab1,&b,1))return false;if(b==9)break;tab1++;}tab2=tab1+1;while(tab2<end){if(!sxan_read(c,tab2,&b,1))return false;if(b==9)break;tab2++;}if(tab1>=end||tab2>=end||!sxan_named(c,p,tab1-p)||!sxan_text(c,&sxan_audials_offset,tab1+1,tab2-tab1-1,false)||!sxan_text(c,&sxan_audials_size,tab2+1,end-tab2-1,false))return false;p=end+2;}return true;}
bool sx_audials_build(sx_context*c)
{
bool ok=false;
ok=sxan_audials(c);
(void)ok;return c->count&&sxan_finish(c);
}
