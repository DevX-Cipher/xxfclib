/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * PYZ data structures, moved out of the binaryextra schema family. */
#include "../../xx_format_schema_binaryextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbx_pyz_header_le_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("python_magic","uint8[4]",4,4,SX_SIGNATURE),
 SX_FIELD("toc_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxbx_pyz_header_le = {UINT32_C(0x603000a7),"pyz_header_le",sxbx_pyz_header_le_fields,SX_COUNT(sxbx_pyz_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_header_be_fields[] = {
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("python_magic","uint8[4]",4,4,SX_SIGNATURE),
 SX_FIELD("toc_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxbx_pyz_header_be = {UINT32_C(0x603000a8),"pyz_header_be",sxbx_pyz_header_be_fields,SX_COUNT(sxbx_pyz_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_tag_fields[] = {
 SX_FIELD("type_and_reference","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbx_pyz_marshal_tag = {UINT32_C(0x603000a9),"pyz_marshal_tag",sxbx_pyz_marshal_tag_fields,SX_COUNT(sxbx_pyz_marshal_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_int32_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxbx_pyz_marshal_int32 = {UINT32_C(0x603000aa),"pyz_marshal_int32",sxbx_pyz_marshal_int32_fields,SX_COUNT(sxbx_pyz_marshal_int32_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_int64_fields[] = {
 SX_FIELD("value","int64",0,8,SX_NONE),
};
const sx_layout sxbx_pyz_marshal_int64 = {UINT32_C(0x603000ab),"pyz_marshal_int64",sxbx_pyz_marshal_int64_fields,SX_COUNT(sxbx_pyz_marshal_int64_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_length_fields[] = {
 SX_FIELD("value","int32",0,4,SX_SIZE),
};
const sx_layout sxbx_pyz_marshal_length = {UINT32_C(0x603000ac),"pyz_marshal_length",sxbx_pyz_marshal_length_fields,SX_COUNT(sxbx_pyz_marshal_length_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_count_fields[] = {
 SX_FIELD("value","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbx_pyz_marshal_count = {UINT32_C(0x603000ad),"pyz_marshal_count",sxbx_pyz_marshal_count_fields,SX_COUNT(sxbx_pyz_marshal_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_short_count_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_COUNT_PROP),
};
const sx_layout sxbx_pyz_marshal_short_count = {UINT32_C(0x603000ae),"pyz_marshal_short_count",sxbx_pyz_marshal_short_count_fields,SX_COUNT(sxbx_pyz_marshal_short_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_short_length_fields[] = {
 SX_FIELD("value","uint8",0,1,SX_SIZE),
};
const sx_layout sxbx_pyz_marshal_short_length = {UINT32_C(0x603000af),"pyz_marshal_short_length",sxbx_pyz_marshal_short_length_fields,SX_COUNT(sxbx_pyz_marshal_short_length_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_reference_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxbx_pyz_marshal_reference = {UINT32_C(0x603000b0),"pyz_marshal_reference",sxbx_pyz_marshal_reference_fields,SX_COUNT(sxbx_pyz_marshal_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_long_digits_fields[] = {
 SX_FIELD("value","int32",0,4,SX_NONE),
};
const sx_layout sxbx_pyz_marshal_long_digits = {UINT32_C(0x603000b1),"pyz_marshal_long_digits",sxbx_pyz_marshal_long_digits_fields,SX_COUNT(sxbx_pyz_marshal_long_digits_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_digit_fields[] = {
 SX_FIELD("value","uint16",0,2,SX_NONE),
};
const sx_layout sxbx_pyz_marshal_digit = {UINT32_C(0x603000b2),"pyz_marshal_digit",sxbx_pyz_marshal_digit_fields,SX_COUNT(sxbx_pyz_marshal_digit_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_offset32_fields[] = {
 SX_FIELD("file_offset","int32",0,4,SX_OFFSET),
};
const sx_layout sxbx_pyz_marshal_offset32 = {UINT32_C(0x603000f4),"pyz_marshal_offset32",sxbx_pyz_marshal_offset32_fields,SX_COUNT(sxbx_pyz_marshal_offset32_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_size32_fields[] = {
 SX_FIELD("packed_size","int32",0,4,SX_SIZE),
};
const sx_layout sxbx_pyz_marshal_size32 = {UINT32_C(0x603000f5),"pyz_marshal_size32",sxbx_pyz_marshal_size32_fields,SX_COUNT(sxbx_pyz_marshal_size32_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_offset64_fields[] = {
 SX_FIELD("file_offset","int64",0,8,SX_OFFSET),
};
const sx_layout sxbx_pyz_marshal_offset64 = {UINT32_C(0x603000f6),"pyz_marshal_offset64",sxbx_pyz_marshal_offset64_fields,SX_COUNT(sxbx_pyz_marshal_offset64_fields),SX_LE};
static const xx_data_struct_field_desc sxbx_pyz_marshal_size64_fields[] = {
 SX_FIELD("packed_size","int64",0,8,SX_SIZE),
};
const sx_layout sxbx_pyz_marshal_size64 = {UINT32_C(0x603000f7),"pyz_marshal_size64",sxbx_pyz_marshal_size64_fields,SX_COUNT(sxbx_pyz_marshal_size64_fields),SX_LE};
#define SXBX_LIMIT 20000U
static bool sxbx_marshal(sx_context*c,uint64_t*p,uint64_t end,unsigned depth,unsigned*work,unsigned role){if(depth>32||++*work>SXBX_LIMIT||c->count>=SXBX_LIMIT||*p>=end)return false;uint64_t code,n;if(!sxbx_word(c,*p,1,false,&code)||!sxbx_add(c,&sxbx_pyz_marshal_tag,(*p)++))return false;code&=127;const sx_layout*l=NULL;unsigned width=0;if(code=='i'){l=role==1?&sxbx_pyz_marshal_offset32:role==2?&sxbx_pyz_marshal_size32:&sxbx_pyz_marshal_int32;width=4;}else if(code=='I'){l=role==1?&sxbx_pyz_marshal_offset64:role==2?&sxbx_pyz_marshal_size64:&sxbx_pyz_marshal_int64;width=8;}else if(code=='r'){l=&sxbx_pyz_marshal_reference;width=4;}else if(code=='N'||code=='0'||code=='F'||code=='T')return true;
 if(l){if(width>end-*p||!sxbx_add(c,l,*p))return false;*p+=width;return true;}if(code=='s'||code=='t'||code=='u'||code=='a'||code=='A')return sxbx_counted(c,p,end,&sxbx_pyz_marshal_length,4,false,1);if(code=='z'||code=='Z')return sxbx_counted(c,p,end,&sxbx_pyz_marshal_short_length,1,false,1);
 if(code=='l'){if(end-*p<4||!sxbx_word(c,*p,4,false,&n)||!sxbx_add(c,&sxbx_pyz_marshal_long_digits,*p))return false;*p+=4;int64_t z=(int32_t)(uint32_t)n;n=z<0?(uint64_t)-z:(uint64_t)z;if(n>5||n>(end-*p)/2||!sxbx_table(c,&sxbx_pyz_marshal_digit,*p,n))return false;*p+=n*2;return true;}
 if(code=='['||code=='('||code==')'){width=code==')'?1:4;if(width>end-*p||!sxbx_word(c,*p,width,false,&n)||n>SXBX_LIMIT||!sxbx_add(c,width==1?&sxbx_pyz_marshal_short_count:&sxbx_pyz_marshal_count,*p))return false;*p+=width;for(uint64_t i=0;i<n;i++)if(!sxbx_marshal(c,p,end,depth+1,work,(code!='['&&n==3&&i)?(unsigned)i:0))return false;return true;}if(code=='{'){for(unsigned i=0;i<SXBX_LIMIT;i++){if(*p>=end||!sxbx_word(c,*p,1,false,&n))return false;if((n&127)=='0')return sxbx_marshal(c,p,end,depth+1,work,0);if(!sxbx_marshal(c,p,end,depth+1,work,0)||!sxbx_marshal(c,p,end,depth+1,work,0))return false;}return false;}return false;}
static bool sxbx_pyz(sx_context*c){uint8_t b[12];if(!sxbx_read(c,0,b,12))return false;uint64_t p=sxbx32(b+8,true),end=(uint64_t)c->size;bool be=true;if(p<12||p>=end){p=sxbx32(b+8,false);be=false;}if(p<12||p>=end||!sxbx_add(c,be?&sxbx_pyz_header_be:&sxbx_pyz_header_le,0))return false;size_t keep=c->count;unsigned work=0;if(!sxbx_marshal(c,&p,end,0,&work,0)||p!=end)c->count=keep;return true;}
bool sx_pyz_build(sx_context*c)
{
 return sxbx_pyz(c);
}
