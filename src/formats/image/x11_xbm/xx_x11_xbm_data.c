/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * x11_xbm data structures, moved out of the textimages schema family. */
#include "../../xx_format_schema_textimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxti_declaration_name_fields[]={
 SX_FIELD("declaration_name","char",0,0,SX_STRING),
};
const sx_layout sxti_declaration_name={0x6041000dU,"textimage_declaration_name",sxti_declaration_name_fields,SX_COUNT(sxti_declaration_name_fields),SX_LE};
static const xx_data_struct_field_desc sxti_declared_bytes_fields[]={
 SX_FIELD("declared_bytes","ascii_signed",0,0,SX_SIZE),
};
const sx_layout sxti_declared_bytes={0x60410033U,"textimage_declared_bytes",sxti_declared_bytes_fields,SX_COUNT(sxti_declared_bytes_fields),SX_LE};
#define TI_EMIT(n,a,z) do{if(!sxti_emit(q,&sxti_##n,(a),(z)))return false;}while(0)
static bool sxti_cword(sxti_cursor*q,int64_t*a,int64_t*z)
{
 if(!sxti_cskip(q)||q->p==q->n)return false;*a=q->p;while(q->p<q->n){uint8_t c=q->b[q->p];if(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')||c=='_'||((c=='+'||c=='-')&&q->p==*a)))break;q->p++;}*z=q->p-*a;return *z>0;
}
static bool sxti_xbm(sxti_cursor*q)
{
 unsigned defines=0;while(sxti_cskip(q)&&q->p<q->n&&q->b[q->p]=='#'){q->p++;int64_t a,z;if(!sxti_cword(q,&a,&z)||!sxti_eq(q,a,z,"define")||!sxti_cword(q,&a,&z))return false;TI_EMIT(define_name,a,z);const sx_layout*l=z>=6&&sxti_eq(q,a+z-6,6,"_width")?&sxti_width:z>=7&&sxti_eq(q,a+z-7,7,"_height")?&sxti_height:z>=6&&sxti_eq(q,a+z-6,6,"_x_hot")?&sxti_hotspot_x:z>=6&&sxti_eq(q,a+z-6,6,"_y_hot")?&sxti_hotspot_y:NULL;if(!l||!sxti_cword(q,&a,&z)||!sxti_emit(q,l,a,z))return false;defines++;}
 if(!defines)return false;int64_t a=0,z=0;while(sxti_cword(q,&a,&z)){if(sxti_eq(q,a,z,"static")||sxti_eq(q,a,z,"const")||sxti_eq(q,a,z,"unsigned")||sxti_eq(q,a,z,"char"))continue;TI_EMIT(declaration_name,a,z);break;}
 if(!sxti_cskip(q)||q->p==q->n||q->b[q->p++]!='['||!sxti_cskip(q))return false;
 if(q->p<q->n&&q->b[q->p]!=']'){if(!sxti_cword(q,&a,&z))return false;TI_EMIT(declared_bytes,a,z);}
 const char*symbols="]={";for(unsigned i=0;i<3;i++)if(!sxti_cskip(q)||q->p==q->n||q->b[q->p++]!=(uint8_t)symbols[i])return false;
 while(sxti_cskip(q)&&q->p<q->n&&q->b[q->p]!='}'){if(q->c->count>=32000)return true;if(!sxti_cword(q,&a,&z)||z<3||z>4||q->b[a]!='0'||(q->b[a+1]!='x'&&q->b[a+1]!='X'))return false;TI_EMIT(bitmap_byte,a+2,z-2);if(!sxti_cskip(q))return false;if(q->p<q->n&&q->b[q->p]==',')q->p++;else break;}
 return q->p<q->n&&q->b[q->p]=='}';
}
bool sx_x11_xbm_build(sxti_cursor*q)
{
 return sxti_xbm(q);
}
#undef TI_EMIT
