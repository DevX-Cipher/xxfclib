/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical VM container metadata. Encoded payloads remain raw. */

#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_vmmeta.h"

static const xx_data_struct_field_desc sx_vm_java_class_identity_fields[] = {
    SX_FIELD("access_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("this_class","uint16",2,2,SX_ID),
    SX_FIELD("super_class","uint16",4,2,SX_ID),
    SX_FIELD("interfaces_count","uint16",6,2,SX_COUNT_PROP),
};
const sx_layout sx_vm_java_class_identity = {0x60160013U,"java_class_identity",sx_vm_java_class_identity_fields,SX_COUNT(sx_vm_java_class_identity_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_field_info_fields[] = {
    SX_FIELD("access_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("name_index","uint16",2,2,SX_ID),
    SX_FIELD("descriptor_index","uint16",4,2,SX_ID),
    SX_FIELD("attributes_count","uint16",6,2,SX_COUNT_PROP),
};
const sx_layout sx_vm_java_field_info = {0x60160018U,"java_field_info",sx_vm_java_field_info_fields,SX_COUNT(sx_vm_java_field_info_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_java_method_info_fields[] = {
    SX_FIELD("access_flags","uint16",0,2,SX_FLAGS),
    SX_FIELD("name_index","uint16",2,2,SX_ID),
    SX_FIELD("descriptor_index","uint16",4,2,SX_ID),
    SX_FIELD("attributes_count","uint16",6,2,SX_COUNT_PROP),
};
const sx_layout sx_vm_java_method_info = {0x60160019U,"java_method_info",sx_vm_java_method_info_fields,SX_COUNT(sx_vm_java_method_info_fields),SX_BE};
static const xx_data_struct_field_desc sx_vm_lua51_prototype_fields[] = {
    SX_FIELD("first_line","int32",0,4,SX_NONE),
    SX_FIELD("last_line","int32",4,4,SX_NONE),
    SX_FIELD("upvalue_count","uint8",8,1,SX_COUNT_PROP),
    SX_FIELD("parameter_count","uint8",9,1,SX_COUNT_PROP),
    SX_FIELD("vararg_flags","uint8",10,1,SX_FLAGS),
    SX_FIELD("maximum_stack_size","uint8",11,1,SX_COUNT_PROP),
};
const sx_layout sx_vm_lua51_prototype = {0x6016001cU,"lua51_prototype",sx_vm_lua51_prototype_fields,SX_COUNT(sx_vm_lua51_prototype_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_string32_fields[] = {
    SX_FIELD("byte_length","uint32",0,4,SX_SIZE),
};
const sx_layout sx_vm_lua51_string32 = {0x60160023U,"lua51_string32",sx_vm_lua51_string32_fields,SX_COUNT(sx_vm_lua51_string32_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_string64_fields[] = {
    SX_FIELD("byte_length","uint64",0,8,SX_SIZE),
};
const sx_layout sx_vm_lua51_string64 = {0x60160024U,"lua51_string64",sx_vm_lua51_string64_fields,SX_COUNT(sx_vm_lua51_string64_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_constant_tag_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
};
const sx_layout sx_vm_lua51_constant_tag = {0x60160025U,"lua51_constant_tag",sx_vm_lua51_constant_tag_fields,SX_COUNT(sx_vm_lua51_constant_tag_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_lua51_setlist_extra_fields[] = {
    SX_FIELD("block_index","uint32",0,4,SX_NONE),
};
const sx_layout sx_vm_lua51_setlist_extra = {0x60160029U,"lua51_setlist_extra",sx_vm_lua51_setlist_extra_fields,SX_COUNT(sx_vm_lua51_setlist_extra_fields),SX_LE};
static const xx_data_struct_field_desc sx_vm_cli_storage_header_fields[] = {
    SX_FIELD("flags","uint16",0,2,SX_RESERVED),
    SX_FIELD("stream_count","uint16",2,2,SX_COUNT_PROP),
};
const sx_layout sx_vm_cli_storage_header = {0x60160035U,"cli_storage_header",sx_vm_cli_storage_header_fields,SX_COUNT(sx_vm_cli_storage_header_fields),SX_LE};
static const sx_layout *const sx_vmmeta_layouts[] = {
    &sx_vm_java_class_header,
    &sx_vm_java_constant_utf8,
    &sx_vm_java_constant_integer,
    &sx_vm_java_constant_float,
    &sx_vm_java_constant_long,
    &sx_vm_java_constant_double,
    &sx_vm_java_constant_class,
    &sx_vm_java_constant_string,
    &sx_vm_java_constant_method_type,
    &sx_vm_java_constant_module,
    &sx_vm_java_constant_package,
    &sx_vm_java_constant_fieldref,
    &sx_vm_java_constant_methodref,
    &sx_vm_java_constant_interface_methodref,
    &sx_vm_java_constant_name_and_type,
    &sx_vm_java_constant_dynamic,
    &sx_vm_java_constant_invoke_dynamic,
    &sx_vm_java_constant_method_handle,
    &sx_vm_java_class_identity,
    &sx_vm_java_interface,
    &sx_vm_java_fields_count,
    &sx_vm_java_methods_count,
    &sx_vm_java_attributes_count,
    &sx_vm_java_field_info,
    &sx_vm_java_method_info,
    &sx_vm_java_attribute_info,
    &sx_vm_lua51_header,
    &sx_vm_lua51_prototype,
    &sx_vm_lua51_code_count,
    &sx_vm_lua51_constants_count,
    &sx_vm_lua51_prototypes_count,
    &sx_vm_lua51_lineinfo_count,
    &sx_vm_lua51_locals_count,
    &sx_vm_lua51_upvalues_count,
    &sx_vm_lua51_string32,
    &sx_vm_lua51_string64,
    &sx_vm_lua51_constant_tag,
    &sx_vm_lua51_boolean,
    &sx_vm_lua51_number_bits,
    &sx_vm_lua51_instruction,
    &sx_vm_lua51_setlist_extra,
    &sx_vm_lua51_lineinfo,
    &sx_vm_lua51_local_range,
    &sx_vm_beam_header,
    &sx_vm_beam_chunk_header,
    &sx_vm_beam_code_header,
    &sx_vm_beam_atom_count,
    &sx_vm_beam_atom_length,
    &sx_vm_beam_table_count,
    &sx_vm_beam_import,
    &sx_vm_beam_export,
    &sx_vm_cli_metadata_root,
    &sx_vm_cli_storage_header,
    &sx_vm_cli_stream_header,
};
static bool sx_vmmeta_supports(xx_file_type_t type)
{
    return type==XX_FILE_TYPE_JAVA_CLASS||type==XX_FILE_TYPE_LUA_BYTECODE51||type==XX_FILE_TYPE_ERLANG_BEAM||type==XX_FILE_TYPE_DOTNET_METADATA;
}
bool sx_vm_span(sx_context *c,uint64_t at,uint64_t n){return at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
static void sx_vm_sort(sx_context *c)
{
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++){
        xx_data_struct d=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>d.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=d;
    }
}
static bool sx_vm_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;sx_vm_sort(c);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end||(at>end&&!sx_raw(c,end,at-end)))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;sx_vm_sort(c);return !c->failed;
}
static bool sx_vmmeta_build(sx_context *c)
{
    if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;
    switch(c->f->file_type){case XX_FILE_TYPE_JAVA_CLASS:ok=sx_java_class_build(c);break;case XX_FILE_TYPE_LUA_BYTECODE51:ok=sx_lua_bytecode51_build(c);break;case XX_FILE_TYPE_ERLANG_BEAM:ok=sx_erlang_beam_build(c);break;case XX_FILE_TYPE_DOTNET_METADATA:ok=sx_dotnet_metadata_build(c);break;default:break;}
    return ok&&sx_vm_finish(c);
}
typedef struct sx_vm_flag {uint64_t mask;const wchar_t *name;} sx_vm_flag;
static bool sx_vm_flags(xx_data_struct_record *r,const sx_vm_flag *flags,size_t count)
{
    wchar_t out[256];size_t used=0;uint64_t value=xx_var_get_u64(&r->value),known=0;
    for(size_t i=0;i<count;i++) {
        known|=flags[i].mask;if(!(value&flags[i].mask))continue;
        if(used+32>=SX_COUNT(out))return false;
        if(used)out[used++]=L'|';
        const wchar_t *p=flags[i].name;while(*p&&used+24<SX_COUNT(out))out[used++]=*p++;
        if(*p)return false;
    }
    uint64_t unknown=value&~known;
    if(unknown) {
        if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';
        bool started=false;
        for(int shift=60;shift>=0;shift-=4) {unsigned digit=(unsigned)((unknown>>shift)&15);if(digit||started||!shift){out[used++]=L"0123456789ABCDEF"[digit];started=true;}}
    }
    if(!used)out[used++]=L'0';out[used]=0;
    return xx_data_struct_record_set_comment(r,out);
}
static bool sx_vmmeta_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60160000U||id>=0x60170000U)return true;
    const wchar_t *text=NULL;
    if(!xx_rt_wcscmp(r->name,L"access_flags")) {
        static const sx_vm_flag cls[]={{1,L"ACC_PUBLIC"},{16,L"ACC_FINAL"},{32,L"ACC_SUPER"},{512,L"ACC_INTERFACE"},{1024,L"ACC_ABSTRACT"},{4096,L"ACC_SYNTHETIC"},{8192,L"ACC_ANNOTATION"},{16384,L"ACC_ENUM"},{32768,L"ACC_MODULE"}};
        static const sx_vm_flag fld[]={{1,L"ACC_PUBLIC"},{2,L"ACC_PRIVATE"},{4,L"ACC_PROTECTED"},{8,L"ACC_STATIC"},{16,L"ACC_FINAL"},{64,L"ACC_VOLATILE"},{128,L"ACC_TRANSIENT"},{4096,L"ACC_SYNTHETIC"},{16384,L"ACC_ENUM"}};
        static const sx_vm_flag met[]={{1,L"ACC_PUBLIC"},{2,L"ACC_PRIVATE"},{4,L"ACC_PROTECTED"},{8,L"ACC_STATIC"},{16,L"ACC_FINAL"},{32,L"ACC_SYNCHRONIZED"},{64,L"ACC_BRIDGE"},{128,L"ACC_VARARGS"},{256,L"ACC_NATIVE"},{1024,L"ACC_ABSTRACT"},{2048,L"ACC_STRICT (major versions46-60)"},{4096,L"ACC_SYNTHETIC"}};
        if(id==sx_vm_java_class_identity.id)return sx_vm_flags(r,cls,SX_COUNT(cls));
        if(id==sx_vm_java_field_info.id)return sx_vm_flags(r,fld,SX_COUNT(fld));
        if(id==sx_vm_java_method_info.id)return sx_vm_flags(r,met,SX_COUNT(met));
    }
    if(id==sx_vm_lua51_prototype.id&&!xx_rt_wcscmp(r->name,L"vararg_flags")) {
        static const sx_vm_flag flags[]={{1,L"VARARG_HASARG"},{2,L"VARARG_ISVARARG"},{4,L"VARARG_NEEDSARG"}};return sx_vm_flags(r,flags,SX_COUNT(flags));
    }
    if(!xx_rt_wcscmp(r->name,L"reference_kind")) {
        static const wchar_t *const kinds[]={L"",L"REF_getField",L"REF_getStatic",L"REF_putField",L"REF_putStatic",L"REF_invokeVirtual",L"REF_invokeStatic",L"REF_invokeSpecial",L"REF_newInvokeSpecial",L"REF_invokeInterface"};
        uint64_t v=xx_var_get_u64(&r->value);if(v&&v<SX_COUNT(kinds))text=kinds[v];
    }
    if(!xx_rt_wcscmp(r->name,L"tag")){
        switch(xx_var_get_u64(&r->value)){
        case 1:text=L"CONSTANT_Utf8";break;case 3:text=L"CONSTANT_Integer";break;case 4:text=L"CONSTANT_Float";break;case 5:text=L"CONSTANT_Long";break;case 6:text=L"CONSTANT_Double";break;case 7:text=L"CONSTANT_Class";break;case 8:text=L"CONSTANT_String";break;case 9:text=L"CONSTANT_Fieldref";break;case 10:text=L"CONSTANT_Methodref";break;case 11:text=L"CONSTANT_InterfaceMethodref";break;case 12:text=L"CONSTANT_NameAndType";break;case 15:text=L"CONSTANT_MethodHandle";break;case 16:text=L"CONSTANT_MethodType";break;case 17:text=L"CONSTANT_Dynamic";break;case 18:text=L"CONSTANT_InvokeDynamic";break;case 19:text=L"CONSTANT_Module";break;case 20:text=L"CONSTANT_Package";break;default:break;}
    }else if(id==sx_vm_lua51_constant_tag.id){switch(xx_var_get_u64(&r->value)){case 0:text=L"LUA_TNIL";break;case 1:text=L"LUA_TBOOLEAN";break;case 3:text=L"LUA_TNUMBER";break;case 4:text=L"LUA_TSTRING";break;default:break;}}
    else if(id==sx_vm_cli_storage_header.id&&!xx_rt_wcscmp(r->name,L"flags"))text=L"Reserved; must be zero";
    else if(!xx_rt_wcscmp(r->name,L"ieee754_bits"))text=L"Stored IEEE754 bit pattern";
    else if(!xx_rt_wcscmp(r->name,L"stream_offset"))text=L"Byte offset from the CLI metadata root";
    else if(!xx_rt_wcscmp(r->name,L"byte_length")&&(id==sx_vm_lua51_string32.id||id==sx_vm_lua51_string64.id))text=L"Stored string length including terminating zero; zero means no string";
    else if(!xx_rt_wcscmp(r->name,L"constant_pool_count"))text=L"Constant-pool index limit; long and double entries consume two indexes";
    else if(id==sx_vm_lua51_setlist_extra.id)text=L"SETLIST auxiliary block index; not an opcode or byte offset";
    else if(!xx_rt_wcscmp(r->name,L"encoded_instruction")){
        static const wchar_t *const ops[]={L"MOVE",L"LOADK",L"LOADBOOL",L"LOADNIL",L"GETUPVAL",L"GETGLOBAL",L"GETTABLE",L"SETGLOBAL",L"SETUPVAL",L"SETTABLE",L"NEWTABLE",L"SELF",L"ADD",L"SUB",L"MUL",L"DIV",L"MOD",L"POW",L"UNM",L"NOT",L"LEN",L"CONCAT",L"JMP",L"EQ",L"LT",L"LE",L"TEST",L"TESTSET",L"CALL",L"TAILCALL",L"RETURN",L"FORLOOP",L"FORPREP",L"TFORLOOP",L"SETLIST",L"CLOSE",L"CLOSURE",L"VARARG"};
        uint64_t v=xx_var_get_u64(&r->value)&63;if(v<SX_COUNT(ops))text=ops[v];
    }
    return !text||xx_data_struct_record_set_comment(r,text);
}
const sx_family sx_vmmeta_family={sx_vmmeta_supports,sx_vmmeta_build,sx_vmmeta_layouts,SX_COUNT(sx_vmmeta_layouts),sx_vmmeta_comment};
