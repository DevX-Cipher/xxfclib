/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * python marshal data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_marshal_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_marshal_tag = {UINT32_C(0x6035003f),"marshal_tag",sxbl_marshal_tag_fields,SX_COUNT(sxbl_marshal_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_marshal_signed_count_fields[] = {
 SX_FIELD("signed_digit_count","int32",0,4,SX_NONE),
};
const sx_layout sxbl_marshal_signed_count = {UINT32_C(0x603500de),"marshal_signed_count",sxbl_marshal_signed_count_fields,SX_COUNT(sxbl_marshal_signed_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_marshal_long_digit_fields[] = {
 SX_FIELD("magnitude_digit","uint16",0,2,SX_NONE),
};
const sx_layout sxbl_marshal_long_digit = {UINT32_C(0x603500df),"marshal_long_digit",sxbl_marshal_long_digit_fields,SX_COUNT(sxbl_marshal_long_digit_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_marshal_reference_fields[] = {
 SX_FIELD("reference_index","int32",0,4,SX_ID),
};
const sx_layout sxbl_marshal_reference = {UINT32_C(0x603500e0),"marshal_reference",sxbl_marshal_reference_fields,SX_COUNT(sxbl_marshal_reference_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_marshal_count_fields[] = {
 SX_FIELD("item_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sxbl_marshal_count = {UINT32_C(0x603500e1),"marshal_count",sxbl_marshal_count_fields,SX_COUNT(sxbl_marshal_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_marshal_string_size_fields[] = {
 SX_FIELD("byte_size","int32",0,4,SX_SIZE),
};
const sx_layout sxbl_marshal_string_size = {UINT32_C(0x603500e2),"marshal_string_size",sxbl_marshal_string_size_fields,SX_COUNT(sxbl_marshal_string_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_marshal_complex_fields[] = {
 SX_FIELD("real","float64",0,8,SX_NONE),
 SX_FIELD("imaginary","float64",8,8,SX_NONE),
};
const sx_layout sxbl_marshal_complex = {UINT32_C(0x603500e3),"marshal_complex",sxbl_marshal_complex_fields,SX_COUNT(sxbl_marshal_complex_fields),SX_LE};
static bool sxbl_marshal(sx_context*c,uint64_t*p,uint64_t end,unsigned depth){uint8_t t;if(depth>64||!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_marshal_tag))return false;t&=127;uint64_t n;
 if(t=='N'||t=='F'||t=='T'||t=='.'||t=='0')return true;if(t=='i'||t=='I')return sxbl_numeric(c,p,end,t=='i'?4:8,true,false);if(t=='g')return sxbl_float(c,p,end,8,false);if(t=='y')return sxbl_emit(c,p,end,&sxbl_marshal_complex);if(t=='r')return sxbl_emit(c,p,end,&sxbl_marshal_reference);
 if(t=='l'){if(!sxbl_word(c,*p,4,false,&n)||!sxbl_emit(c,p,end,&sxbl_marshal_signed_count))return false;int64_t v=(int32_t)n;n=(uint64_t)(v<0?-v:v);if(n>4096)return false;for(uint64_t i=0;i<n;i++)if(!sxbl_emit(c,p,end,&sxbl_marshal_long_digit))return false;return true;}
 if(t=='z'||t=='Z')return sxbl_string(c,p,end,1,false);if(t=='s'||t=='t'||t=='u'||t=='a'||t=='A'){if(!sxbl_word(c,*p,4,false,&n)||!sxbl_emit(c,p,end,&sxbl_marshal_string_size))return false;return sxbl_skip(c,p,end,n);}
 if(t=='{' ){for(unsigned i=0;i<4090;i++){if(!sxbl_byte(c,*p,&t))return false;if((t&127)=='0')return sxbl_emit(c,p,end,&sxbl_marshal_tag);if(!sxbl_marshal(c,p,end,depth+1)||!sxbl_marshal(c,p,end,depth+1))return false;}return false;}
 if(t=='('||t==')'||t=='['||t=='<'||t=='>'){if(t==')'){if(!sxbl_length(c,p,end,1,false,true,&n))return false;}else if(!sxbl_word(c,*p,4,false,&n)||!sxbl_emit(c,p,end,&sxbl_marshal_count))return false;if(n>4090)return false;for(uint64_t i=0;i<n;i++)if(!sxbl_marshal(c,p,end,depth+1))return false;return true;}return false;}
bool sx_python_marshal_build(sx_context*c)
{
 uint64_t p=0,end=(uint64_t)c->size;return sxbl_marshal(c,&p,end,0);
}
