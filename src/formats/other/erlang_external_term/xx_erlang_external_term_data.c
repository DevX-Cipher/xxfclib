/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * erlang external term data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_etf_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_etf_tag = {UINT32_C(0x60350039),"etf_tag",sxbl_etf_tag_fields,SX_COUNT(sxbl_etf_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_etf_version_fields[] = {
 SX_FIELD("version","uint8",0,1,SX_SIGNATURE),
};
const sx_layout sxbl_etf_version = {UINT32_C(0x60350098),"etf_version",sxbl_etf_version_fields,SX_COUNT(sxbl_etf_version_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_etf_big_sign_fields[] = {
 SX_FIELD("sign","uint8",0,1,SX_NONE),
};
const sx_layout sxbl_etf_big_sign = {UINT32_C(0x60350099),"etf_big_sign",sxbl_etf_big_sign_fields,SX_COUNT(sxbl_etf_big_sign_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_etf_bit_count_fields[] = {
 SX_FIELD("last_byte_bits","uint8",0,1,SX_NONE),
};
const sx_layout sxbl_etf_bit_count = {UINT32_C(0x6035009a),"etf_bit_count",sxbl_etf_bit_count_fields,SX_COUNT(sxbl_etf_bit_count_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_etf_old_float_fields[] = {
 SX_FIELD("decimal_text","char[31]",0,31,SX_STRING),
};
const sx_layout sxbl_etf_old_float = {UINT32_C(0x6035009b),"etf_old_float",sxbl_etf_old_float_fields,SX_COUNT(sxbl_etf_old_float_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_etf_pid_old_fields[] = {
 SX_FIELD("id","uint32",0,4,SX_ID),
 SX_FIELD("serial","uint32",4,4,SX_ID),
 SX_FIELD("creation","uint8",8,1,SX_NONE),
};
const sx_layout sxbl_etf_pid_old = {UINT32_C(0x6035009c),"etf_pid_old",sxbl_etf_pid_old_fields,SX_COUNT(sxbl_etf_pid_old_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_etf_pid_new_fields[] = {
 SX_FIELD("id","uint32",0,4,SX_ID),
 SX_FIELD("serial","uint32",4,4,SX_ID),
 SX_FIELD("creation","uint32",8,4,SX_NONE),
};
const sx_layout sxbl_etf_pid_new = {UINT32_C(0x6035009d),"etf_pid_new",sxbl_etf_pid_new_fields,SX_COUNT(sxbl_etf_pid_new_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_etf_port_old_fields[] = {
 SX_FIELD("id","uint32",0,4,SX_ID),
 SX_FIELD("creation","uint8",4,1,SX_NONE),
};
const sx_layout sxbl_etf_port_old = {UINT32_C(0x6035009e),"etf_port_old",sxbl_etf_port_old_fields,SX_COUNT(sxbl_etf_port_old_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_etf_port_new_fields[] = {
 SX_FIELD("id","uint32",0,4,SX_ID),
 SX_FIELD("creation","uint32",4,4,SX_NONE),
};
const sx_layout sxbl_etf_port_new = {UINT32_C(0x6035009f),"etf_port_new",sxbl_etf_port_new_fields,SX_COUNT(sxbl_etf_port_new_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_etf_port_v4_fields[] = {
 SX_FIELD("id","uint64",0,8,SX_ID),
 SX_FIELD("creation","uint32",8,4,SX_NONE),
};
const sx_layout sxbl_etf_port_v4 = {UINT32_C(0x603500a0),"etf_port_v4",sxbl_etf_port_v4_fields,SX_COUNT(sxbl_etf_port_v4_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_etf_reference_id_fields[] = {
 SX_FIELD("id","uint32",0,4,SX_ID),
};
const sx_layout sxbl_etf_reference_id = {UINT32_C(0x603500a1),"etf_reference_id",sxbl_etf_reference_id_fields,SX_COUNT(sxbl_etf_reference_id_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_etf_creation1_fields[] = {
 SX_FIELD("creation","uint8",0,1,SX_NONE),
};
const sx_layout sxbl_etf_creation1 = {UINT32_C(0x603500a2),"etf_creation1",sxbl_etf_creation1_fields,SX_COUNT(sxbl_etf_creation1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_etf_creation4_fields[] = {
 SX_FIELD("creation","uint32",0,4,SX_NONE),
};
const sx_layout sxbl_etf_creation4 = {UINT32_C(0x603500a3),"etf_creation4",sxbl_etf_creation4_fields,SX_COUNT(sxbl_etf_creation4_fields),SX_BE};
static const xx_data_struct_field_desc sxbl_etf_reference_old_fields[] = {
 SX_FIELD("id","uint32",0,4,SX_ID),
 SX_FIELD("creation","uint8",4,1,SX_NONE),
};
const sx_layout sxbl_etf_reference_old = {UINT32_C(0x60350118),"etf_reference_old",sxbl_etf_reference_old_fields,SX_COUNT(sxbl_etf_reference_old_fields),SX_BE};
#define SXBL_LIMIT 20000U
static bool sxbl_etf(sx_context*c,uint64_t*p,uint64_t end,unsigned depth){uint8_t t;if(depth>32||!sxbl_byte(c,*p,&t)||!sxbl_emit(c,p,end,&sxbl_etf_tag))return false;uint64_t n;unsigned z;
 if(t==106)return true;if(t==97||t==98)return sxbl_numeric(c,p,end,t==97?1:4,t==98,true);if(t==70)return sxbl_float(c,p,end,8,true);if(t==99)return sxbl_emit(c,p,end,&sxbl_etf_old_float);
 if(t==100||t==115||t==118||t==119)return sxbl_string(c,p,end,t==100||t==118?2:1,true);if(t==107)return sxbl_string(c,p,end,2,true);
 if(t==109||t==77){if(!sxbl_length(c,p,end,4,true,false,&n))return false;if(t==77&&!sxbl_emit(c,p,end,&sxbl_etf_bit_count))return false;return sxbl_skip(c,p,end,n);}
 if(t==104||t==105||t==108||t==116){if(!sxbl_length(c,p,end,t==104?1:4,true,true,&n)||n>SXBL_LIMIT)return false;for(uint64_t i=0;i<n*(t==116?2U:1U);i++)if(!sxbl_etf(c,p,end,depth+1))return false;return t!=108||sxbl_etf(c,p,end,depth+1);}
 if(t==110||t==111){if(!sxbl_length(c,p,end,t==110?1:4,true,true,&n)||!sxbl_emit(c,p,end,&sxbl_etf_big_sign))return false;return sxbl_skip(c,p,end,n);}
 if(t==103||t==88||t==102||t==89||t==120||t==101||t==114||t==90){n=1;if((t==114||t==90)&&(!sxbl_length(c,p,end,2,true,true,&n)||n>5))return false;if(!sxbl_etf(c,p,end,depth+1))return false;
  if(t==103||t==88)return sxbl_emit(c,p,end,t==103?&sxbl_etf_pid_old:&sxbl_etf_pid_new);
  if(t==102||t==89||t==120||t==101)return sxbl_emit(c,p,end,t==101?&sxbl_etf_reference_old:t==102?&sxbl_etf_port_old:t==89?&sxbl_etf_port_new:&sxbl_etf_port_v4);
  if(!sxbl_emit(c,p,end,t==90?&sxbl_etf_creation4:&sxbl_etf_creation1))return false;for(uint64_t i=0;i<n;i++)if(!sxbl_emit(c,p,end,&sxbl_etf_reference_id))return false;return true;}
 (void)z;return false;}
bool sx_erlang_external_term_build(sx_context*c)
{
 uint64_t p=0,end=(uint64_t)c->size;return sxbl_emit(c,&p,end,&sxbl_etf_version)&&sxbl_etf(c,&p,end,0);
}
