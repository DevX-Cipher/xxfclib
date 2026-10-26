/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Erlang BEAM data structures, moved out of the vmmeta schema family. */
#include "../../xx_format_schema_vmmeta.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_vm_beam_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("form_size","uint32",4,4,SX_SIZE),
    SX_FIELD("form_type","char[4]",8,4,SX_ID),
};
const sx_layout sx_vm_beam_header = {0x6016002cU,"beam_header",sx_vm_beam_header_fields,SX_COUNT(sx_vm_beam_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_beam_chunk_header_fields[] = {
    SX_FIELD("chunk_id","char[4]",0,4,SX_ID),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
};
const sx_layout sx_vm_beam_chunk_header = {0x6016002dU,"beam_chunk_header",sx_vm_beam_chunk_header_fields,SX_COUNT(sx_vm_beam_chunk_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_beam_code_header_fields[] = {
    SX_FIELD("subheader_size","uint32",0,4,SX_SIZE),
    SX_FIELD("instruction_set","uint32",4,4,SX_ID),
    SX_FIELD("opcode_maximum","uint32",8,4,SX_ID),
    SX_FIELD("label_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("function_count","uint32",16,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_beam_code_header = {0x6016002eU,"beam_code_header",sx_vm_beam_code_header_fields,SX_COUNT(sx_vm_beam_code_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_beam_atom_count_fields[] = {
    SX_FIELD("atom_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_beam_atom_count = {0x6016002fU,"beam_atom_count",sx_vm_beam_atom_count_fields,SX_COUNT(sx_vm_beam_atom_count_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_beam_atom_length_fields[] = {
    SX_FIELD("byte_length","uint8",0,1,SX_SIZE),
};
const sx_layout sx_vm_beam_atom_length = {0x60160030U,"beam_atom_length",sx_vm_beam_atom_length_fields,SX_COUNT(sx_vm_beam_atom_length_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_beam_table_count_fields[] = {
    SX_FIELD("entry_count","uint32",0,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_beam_table_count = {0x60160031U,"beam_table_count",sx_vm_beam_table_count_fields,SX_COUNT(sx_vm_beam_table_count_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_beam_import_fields[] = {
    SX_FIELD("module_atom_index","uint32",0,4,SX_ID),
    SX_FIELD("function_atom_index","uint32",4,4,SX_ID),
    SX_FIELD("arity","uint32",8,4,SX_COUNT_PROP),
};
const sx_layout sx_vm_beam_import = {0x60160032U,"beam_import",sx_vm_beam_import_fields,SX_COUNT(sx_vm_beam_import_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_beam_export_fields[] = {
    SX_FIELD("function_atom_index","uint32",0,4,SX_ID),
    SX_FIELD("arity","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("label_index","uint32",8,4,SX_ID),
};
const sx_layout sx_vm_beam_export = {0x60160033U,"beam_export",sx_vm_beam_export_fields,SX_COUNT(sx_vm_beam_export_fields),SX_BE};
static bool sx_vm_beam(sx_context *c)
{
    uint32_t form_size;if(!sx_u32(c,4,true,&form_size)||form_size<4||!sx_vm_span(c,8,form_size)||!sx_add(c,&sx_vm_beam_header,0,12))return false;
    uint64_t at=12,end=8+(uint64_t)form_size;
    for(unsigned i=0;at<end&&i<128;i++){
        uint8_t b[8];if(end-at<8||!sx_read(c,(int64_t)at,b,8))return false;
        uint32_t n=xx_data_get_u32(b,8,4,true);uint64_t padded=((uint64_t)n+3)&~UINT64_C(3),q=at+8;
        if(padded>end-q||!sx_add(c,&sx_vm_beam_chunk_header,(int64_t)at,8))return false;
        if(!xx_rt_memcmp(b,"Code",4)){if(n<20||!sx_add(c,&sx_vm_beam_code_header,(int64_t)q,20))return false;}
        else if(!xx_rt_memcmp(b,"Atom",4)||!xx_rt_memcmp(b,"AtU8",4)){
            uint32_t count;if(n<4||!sx_u32(c,(int64_t)q,true,&count)||count>65536||!sx_add(c,&sx_vm_beam_atom_count,(int64_t)q,4))return false;uint64_t p=q+4;
            for(uint32_t k=0;k<count;k++){uint8_t len;if(p>=q+n||!sx_read(c,(int64_t)p,&len,1)||len>q+n-p-1||!sx_add(c,&sx_vm_beam_atom_length,(int64_t)p,1))return false;p+=1+(uint64_t)len;}
            if(p!=q+n)return false;
        }else if(!xx_rt_memcmp(b,"ImpT",4)||!xx_rt_memcmp(b,"ExpT",4)||!xx_rt_memcmp(b,"LocT",4)){
            uint32_t count=0;bool optional=!xx_rt_memcmp(b,"LocT",4);
            /* Native validation authenticates ImpT/ExpT. LocT is optional and
             * not validated there, so malformed optional content stays raw. */
            if(n>=4&&sx_u32(c,(int64_t)q,true,&count)&&count<=65536&&n==4+(uint64_t)count*12){
                if(!sx_add(c,&sx_vm_beam_table_count,(int64_t)q,4)||!sx_table(c,!xx_rt_memcmp(b,"ImpT",4)?&sx_vm_beam_import:&sx_vm_beam_export,(int64_t)q+4,12,count))return false;
            }else if(!optional)return false;
        }
        at=q+padded;
    }return at==end;
}
bool sx_erlang_beam_build(sx_context*c)
{
    return sx_vm_beam(c);
}
