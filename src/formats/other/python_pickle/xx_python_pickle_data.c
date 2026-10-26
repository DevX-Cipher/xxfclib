/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * python pickle data structures, moved out of the binarylater schema family. */
#include "../../xx_format_schema_binarylater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxbl_pickle_tag_fields[] = {
 SX_FIELD("type_and_flags","uint8",0,1,SX_FLAGS),
};
const sx_layout sxbl_pickle_tag = {UINT32_C(0x6035003e),"pickle_tag",sxbl_pickle_tag_fields,SX_COUNT(sxbl_pickle_tag_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_pickle_protocol_fields[] = {
 SX_FIELD("opcode","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("protocol","uint8",1,1,SX_ID),
};
const sx_layout sxbl_pickle_protocol = {UINT32_C(0x603500d9),"pickle_protocol",sxbl_pickle_protocol_fields,SX_COUNT(sxbl_pickle_protocol_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_pickle_frame_size_fields[] = {
 SX_FIELD("frame_size","uint64",0,8,SX_SIZE),
};
const sx_layout sxbl_pickle_frame_size = {UINT32_C(0x603500da),"pickle_frame_size",sxbl_pickle_frame_size_fields,SX_COUNT(sxbl_pickle_frame_size_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_pickle_memo1_fields[] = {
 SX_FIELD("memo_index","uint8",0,1,SX_ID),
};
const sx_layout sxbl_pickle_memo1 = {UINT32_C(0x603500db),"pickle_memo1",sxbl_pickle_memo1_fields,SX_COUNT(sxbl_pickle_memo1_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_pickle_memo4_fields[] = {
 SX_FIELD("memo_index","uint32",0,4,SX_ID),
};
const sx_layout sxbl_pickle_memo4 = {UINT32_C(0x603500dc),"pickle_memo4",sxbl_pickle_memo4_fields,SX_COUNT(sxbl_pickle_memo4_fields),SX_LE};
static const xx_data_struct_field_desc sxbl_pickle_signed_length_fields[] = {
 SX_FIELD("byte_size","int32",0,4,SX_SIZE),
};
const sx_layout sxbl_pickle_signed_length = {UINT32_C(0x603500dd),"pickle_signed_length",sxbl_pickle_signed_length_fields,SX_COUNT(sxbl_pickle_signed_length_fields),SX_LE};
#define SXBL_LIMIT 20000U
static bool sxbl_pickle(sx_context*c){uint64_t p=0,end=(uint64_t)c->size,frame=0,n;if(!sxbl_emit(c,&p,end,&sxbl_pickle_protocol))return false;for(unsigned i=0;p<end&&i<SXBL_LIMIT;i++){uint8_t t;if(!sxbl_byte(c,p,&t)||!sxbl_emit(c,&p,end,&sxbl_pickle_tag))return false;uint64_t limit=frame?frame:end;
 if(t==0x95){if(frame&&p-1!=frame)return false;frame=0;if(!sxbl_word(c,p,8,false,&n)||!sxbl_emit(c,&p,end,&sxbl_pickle_frame_size)||n>end-p)return false;frame=p+n;continue;}
 switch(t){case '.':return true;case 'J':if(!sxbl_numeric(c,&p,limit,4,true,false))return false;break;case 'K':case 'M':if(!sxbl_numeric(c,&p,limit,t=='K'?1:2,false,false))return false;break;case 'G':if(!sxbl_float(c,&p,limit,8,true))return false;break;
 case 0x8a:case 'U':case 'C':case 0x8c:if(!sxbl_string(c,&p,limit,1,false))return false;break;
 case 'B':case 'X':if(!sxbl_string(c,&p,limit,4,false))return false;break;
 case 0x8b:case 'T':if(!sxbl_word(c,p,4,false,&n)||!sxbl_emit(c,&p,limit,&sxbl_pickle_signed_length)||!sxbl_skip(c,&p,limit,n))return false;break;
 case 0x8d:case 0x8e:case 0x96:if(!sxbl_string(c,&p,limit,8,false))return false;break;
 case 'q':case 'h':case 'r':case 'j':if(!sxbl_emit(c,&p,limit,t=='q'||t=='h'?&sxbl_pickle_memo1:&sxbl_pickle_memo4))return false;break;
 case 'N':case 0x88:case 0x89:case ']':case '}':case ')':case 0x8f:case '(':case '0':case '1':case '2':case 0x85:case 0x86:case 0x87:case 't':case 'l':case 'd':case 'e':case 'u':case 0x90:case 0x91:case 'a':case 's':case 0x94:break;default:return false;}
 if(frame&&p==frame)frame=0;
 }return false;}
bool sx_python_pickle_build(sx_context*c)
{
 return sxbl_pickle(c);
}
