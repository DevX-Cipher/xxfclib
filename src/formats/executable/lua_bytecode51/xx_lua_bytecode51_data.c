/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Lua 5.1 bytecode data structures, moved out of the vmmeta schema family. */
#include "../../xx_format_schema_vmmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_vm_lua51_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint8",4,1,SX_ID),
    SX_FIELD("format","uint8",5,1,SX_ID),
    SX_FIELD("little_endian","uint8",6,1,SX_ID),
    SX_FIELD("integer_size","uint8",7,1,SX_SIZE),
    SX_FIELD("size_t_size","uint8",8,1,SX_SIZE),
    SX_FIELD("instruction_size","uint8",9,1,SX_SIZE),
    SX_FIELD("number_size","uint8",10,1,SX_SIZE),
    SX_FIELD("integral_numbers","uint8",11,1,SX_ID),
};
const sx_layout sx_vm_lua51_header = {0x6016001bU,"lua51_header",sx_vm_lua51_header_fields,SX_COUNT(sx_vm_lua51_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_code_count_fields[] = {
    SX_FIELD("code_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_lua51_code_count = {0x6016001dU,"lua51_code_count",sx_vm_lua51_code_count_fields,SX_COUNT(sx_vm_lua51_code_count_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_constants_count_fields[] = {
    SX_FIELD("constants_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_lua51_constants_count = {0x6016001eU,"lua51_constants_count",sx_vm_lua51_constants_count_fields,SX_COUNT(sx_vm_lua51_constants_count_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_prototypes_count_fields[] = {
    SX_FIELD("prototypes_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_lua51_prototypes_count = {0x6016001fU,"lua51_prototypes_count",sx_vm_lua51_prototypes_count_fields,SX_COUNT(sx_vm_lua51_prototypes_count_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_lineinfo_count_fields[] = {
    SX_FIELD("lineinfo_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_lua51_lineinfo_count = {0x60160020U,"lua51_lineinfo_count",sx_vm_lua51_lineinfo_count_fields,SX_COUNT(sx_vm_lua51_lineinfo_count_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_locals_count_fields[] = {
    SX_FIELD("locals_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_lua51_locals_count = {0x60160021U,"lua51_locals_count",sx_vm_lua51_locals_count_fields,SX_COUNT(sx_vm_lua51_locals_count_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_upvalues_count_fields[] = {
    SX_FIELD("upvalues_count","int32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_lua51_upvalues_count = {0x60160022U,"lua51_upvalues_count",sx_vm_lua51_upvalues_count_fields,SX_COUNT(sx_vm_lua51_upvalues_count_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_boolean_fields[] = {
    SX_FIELD("value","uint8",0,1,SX_NONE),
};
const sx_layout sx_vm_lua51_boolean = {0x60160026U,"lua51_boolean",sx_vm_lua51_boolean_fields,SX_COUNT(sx_vm_lua51_boolean_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_number_bits_fields[] = {
    SX_FIELD("ieee754_bits","uint64",0,8,SX_NONE),
};
const sx_layout sx_vm_lua51_number_bits = {0x60160027U,"lua51_number_bits",sx_vm_lua51_number_bits_fields,SX_COUNT(sx_vm_lua51_number_bits_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_instruction_fields[] = {
    SX_FIELD("encoded_instruction","uint32",0,4,SX_NONE),
};
const sx_layout sx_vm_lua51_instruction = {0x60160028U,"lua51_instruction",sx_vm_lua51_instruction_fields,SX_COUNT(sx_vm_lua51_instruction_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_lineinfo_fields[] = {
    SX_FIELD("source_line","int32",0,4,SX_NONE),
};
const sx_layout sx_vm_lua51_lineinfo = {0x6016002aU,"lua51_lineinfo",sx_vm_lua51_lineinfo_fields,SX_COUNT(sx_vm_lua51_lineinfo_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_local_range_fields[] = {
    SX_FIELD("start_instruction_index","int32",0,4,SX_NONE),
    SX_FIELD("end_instruction_index","int32",4,4,SX_NONE),
};
const sx_layout sx_vm_lua51_local_range = {0x6016002bU,"lua51_local_range",sx_vm_lua51_local_range_fields,SX_COUNT(sx_vm_lua51_local_range_fields),SX_LE};
static bool sx_vm_count(sx_context *c,uint64_t *at,const sx_layout *l,uint32_t *v)
{
    if(!sx_vm_span(c,*at,4)||!sx_u32(c,(int64_t)*at,false,v)||!sx_add(c,l,(int64_t)*at,4))return false;*at+=4;return true;
}
typedef struct sx_vm_lua_state{sx_context *c;uint64_t at,instructions;unsigned width,prototypes;}sx_vm_lua_state;
static bool sx_vm_lua_string(sx_vm_lua_state *s)
{
    uint64_t size=0;
    if(!sx_vm_span(s->c,s->at,s->width))return false;
    if(s->width==4){uint32_t n;if(!sx_u32(s->c,(int64_t)s->at,false,&n))return false;size=n;}
    else if(!sx_u64(s->c,(int64_t)s->at,false,&size))return false;
    if(size>16777216||!sx_vm_span(s->c,s->at+s->width,size)||!sx_add(s->c,s->width==4?&sx_vm_lua51_string32:&sx_vm_lua51_string64,(int64_t)s->at,s->width))return false;
    s->at+=s->width+size;return true;
}
static bool sx_vm_lua_proto(sx_vm_lua_state *s,unsigned depth)
{
    sx_context *c=s->c;uint32_t count;
    if(depth>32||++s->prototypes>1024||!sx_vm_lua_string(s)||!sx_add(c,&sx_vm_lua51_prototype,(int64_t)s->at,12))return false;s->at+=12;
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_code_count,&count)||!count||count>65536||s->instructions+count>1000000||!sx_vm_span(c,s->at,(uint64_t)count*4))return false;
    uint32_t run=0;
    for(uint32_t i=0;i<count;i++){
        uint32_t word;if(!sx_u32(c,(int64_t)(s->at+(uint64_t)i*4),false,&word))return false;
        if((word&63)>37)return false;
        if((word&63)==34&&((word>>14)&511)==0){
            /* SETLIST C=0 consumes a full data word, not another opcode. */
            if(i+1>=count||!sx_table(c,&sx_vm_lua51_instruction,(int64_t)(s->at+(uint64_t)run*4),4,i-run+1)||!sx_add(c,&sx_vm_lua51_setlist_extra,(int64_t)(s->at+(uint64_t)(i+1)*4),4))return false;
            i++;run=i+1;
        }
    }
    if(run<count&&!sx_table(c,&sx_vm_lua51_instruction,(int64_t)(s->at+(uint64_t)run*4),4,count-run))return false;
    s->at+=(uint64_t)count*4;s->instructions+=count;
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_constants_count,&count)||count>65536)return false;
    for(uint32_t i=0;i<count;i++){
        uint8_t t;if(!sx_read(c,(int64_t)s->at,&t,1)||!sx_add(c,&sx_vm_lua51_constant_tag,(int64_t)s->at,1))return false;s->at++;
        if(t==0)continue;
        if(t==1){if(!sx_add(c,&sx_vm_lua51_boolean,(int64_t)s->at,1))return false;s->at++;}
        else if(t==3){if(!sx_add(c,&sx_vm_lua51_number_bits,(int64_t)s->at,8))return false;s->at+=8;}
        else if(t==4){if(!sx_vm_lua_string(s))return false;}
        else return false;
    }
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_prototypes_count,&count)||count>1024)return false;
    for(uint32_t i=0;i<count;i++)if(!sx_vm_lua_proto(s,depth+1))return false;
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_lineinfo_count,&count)||count>65536||!sx_table(c,&sx_vm_lua51_lineinfo,(int64_t)s->at,4,count))return false;s->at+=(uint64_t)count*4;
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_locals_count,&count)||count>65536)return false;
    for(uint32_t i=0;i<count;i++){if(!sx_vm_lua_string(s)||!sx_add(c,&sx_vm_lua51_local_range,(int64_t)s->at,8))return false;s->at+=8;}
    if(!sx_vm_count(c,&s->at,&sx_vm_lua51_upvalues_count,&count)||count>60)return false;
    for(uint32_t i=0;i<count;i++)if(!sx_vm_lua_string(s))return false;
    return true;
}
static bool sx_vm_lua(sx_context *c)
{
    uint8_t h[12];if(!sx_read(c,0,h,12)||h[6]!=1||h[7]!=4||(h[8]!=4&&h[8]!=8)||h[9]!=4||h[10]!=8||h[11]||!sx_add(c,&sx_vm_lua51_header,0,12))return false;
    sx_vm_lua_state s={c,12,0,h[8],0};return sx_vm_lua_proto(&s,0)&&s.at==(uint64_t)c->size;
}
bool sx_lua_bytecode51_build(sx_context*c)
{
    return sx_vm_lua(c);
}
