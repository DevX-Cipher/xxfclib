/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BOO data structures, moved out of the archiveend schema family. */
#include "../../xx_format_schema_archiveend.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/archive/sfx_tgcf/xx_sfx_tgcf.h"
#endif

static const xx_data_struct_field_desc sxaend_boo_name_fields[]={
 SX_FIELD("boo_name","char",0,0,SX_STRING),
};
const sx_layout sxaend_boo_name={UINT32_C(0x6084002a),"boo_name",sxaend_boo_name_fields,SX_COUNT(sxaend_boo_name_fields),SX_LE};
static const xx_data_struct_field_desc sxaend_boo_encoded_line_fields[]={
 SX_FIELD("boo_encoded_line","char",0,0,SX_NONE),
};
const sx_layout sxaend_boo_encoded_line={UINT32_C(0x6084002b),"boo_encoded_line",sxaend_boo_encoded_line_fields,SX_COUNT(sxaend_boo_encoded_line_fields),SX_LE};
#define SXAEND_LIMIT 20000U
static bool sxaend_line(sx_context*c,uint64_t p,uint8_t*b,size_t cap,size_t*n,uint64_t*next){*n=0;uint64_t q=p;while(q<(uint64_t)c->size){uint8_t x;if(!sxaend_read(c,q,&x,1))return false;q++;if(x=='\r'||x=='\n'){if(x=='\r'&&q<(uint64_t)c->size){uint8_t y;if(!sxaend_read(c,q,&y,1))return false;if(y=='\n')q++;}*next=q;return true;}if(*n>=cap)return false;b[(*n)++]=x;}*next=q;return q>p;}
static bool sxaend_boo(sx_context*c){uint8_t b[4096];size_t n;uint64_t p=0,next;if(!sxaend_line(c,0,b,sizeof(b),&n,&next)||n<3||n>12||!sxaend_text(c,&sxaend_boo_name,0,n,false))return false;p=next;for(unsigned i=0;p<(uint64_t)c->size&&i<SXAEND_LIMIT;i++){if(!sxaend_line(c,p,b,sizeof(b),&n,&next)||next<=p)return false;if(n&&!sxaend_text(c,&sxaend_boo_encoded_line,p,n,false))return false;p=next;}return true;}
bool sx_boo_build(sx_context*c)
{
 return sxaend_boo(c);
}
