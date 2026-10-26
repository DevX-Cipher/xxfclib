/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * msgpack data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_msgpack_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_msgpack_tag = {UINT32_C(0x60350037),"msgpack_tag",sxbl_msgpack_tag_fields,SX_COUNT(sxbl_msgpack_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_msgpack_extension_type_fields[] = {
 SX_FIELD("extension_type","int8",0,1,SX_ID),
};
const sx_layout sxbl_msgpack_extension_type = {UINT32_C(0x60350094),"msgpack_extension_type",sxbl_msgpack_extension_type_fields,SX_COUNT(sxbl_msgpack_extension_type_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_msgpack_timestamp64_fields[] = {
 SX_FIELD("nanoseconds_and_seconds","uint64",0,8,SX_NONE),
};
const sx_layout sxbl_msgpack_timestamp64 = {UINT32_C(0x60350095),"msgpack_timestamp64",sxbl_msgpack_timestamp64_fields,SX_COUNT(sxbl_msgpack_timestamp64_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_msgpack_timestamp96_fields[] = {
 SX_FIELD("nanoseconds","uint32",0,4,SX_NONE),
 SX_FIELD("seconds","int64",4,8,SX_NONE),
};
const sx_layout sxbl_msgpack_timestamp96 = {UINT32_C(0x60350096),"msgpack_timestamp96",sxbl_msgpack_timestamp96_fields,SX_COUNT(sxbl_msgpack_timestamp96_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_msgpack_timestamp32_fields[] = {
 SX_FIELD("seconds_since_unix_epoch","uint32",0,4,SX_NONE),
};
const sx_layout sxbl_msgpack_timestamp32 = {UINT32_C(0x603500fb),"msgpack_timestamp32",sxbl_msgpack_timestamp32_fields,SX_COUNT(sxbl_msgpack_timestamp32_fields),SX_BE};
#define SXBL_LIMIT 20000U
static bool sxbl_msgpack(sx_context*c,uint64_t*p,uint64_t end,unsigned depth){uint8_t t;if(depth>32||!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_msgpack_tag))return false;if(t<=127||t>=224||t==192||t==194||t==195)return true;uint64_t n=0;unsigned kind=0,z=0;if((t&224)==160){n=t&31;kind=1;}else if((t&240)==144||(t&240)==128){n=t&15;kind=(t&240)==144?3:4;}else if(t>=196&&t<=198){kind=2;z=1U<<(t-196);}else if(t>=199&&t<=201){kind=5;z=1U<<(t-199);}else if(t==202||t==203)return sxbl_float(c,p,end,t==202?4:8,true);else if(t>=204&&t<=211)return sxbl_numeric(c,p,end,1U<<((t-204)&3),t>=208,true);else if(t>=212&&t<=216){kind=5;n=1U<<(t-212);}else if(t>=217&&t<=219){kind=1;z=1U<<(t-217);}else if(t>=220&&t<=223){kind=t<222?3:4;z=(t&1)?4:2;}else return false;
 if(z&&!sxbl_length(c,p,end,z,true,kind==3||kind==4,&n))return false;if(kind==3||kind==4){if(n>SXBL_LIMIT)return false;for(uint64_t i=0;i<n*(kind==4?2U:1U);i++)if(!sxbl_msgpack(c,p,end,depth+1))return false;return true;}if(kind==5){uint8_t ext;if(!sxbl_byte(c,*p,&ext)||!sxbl_emit(c,p,end,&sxbl_msgpack_extension_type))return false;if(ext==255){if(n==4)return sxbl_emit(c,p,end,&sxbl_msgpack_timestamp32);if(n==8)return sxbl_emit(c,p,end,&sxbl_msgpack_timestamp64);if(n==12)return sxbl_emit(c,p,end,&sxbl_msgpack_timestamp96);}}return sxbl_skip(c,p,end,n);}
bool sx_msgpack_build(sx_context*c)
{
 uint64_t p=0,end=(uint64_t)c->size;return sxbl_msgpack(c,&p,end,0);
}
