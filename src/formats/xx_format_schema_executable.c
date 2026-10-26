/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical executable layouts: xxfclib DEX definitions, Apple fat.h,
 * Microsoft PE/COFF and UEFI TE headers; WebAssembly core section framing.
 */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_executable.h"
static const xx_data_struct_field_desc sx_dex_code_item_fields[] = {
    SX_FIELD("registers_size","uint16",0,2,SX_COUNT_PROP),
    SX_FIELD("ins_size","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("outs_size","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("tries_size","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("debug_info_off","uint32",8,4,SX_OFFSET),
    SX_FIELD("insns_size","uint32",12,4,SX_COUNT_PROP),
};
static const sx_layout sx_dex_code_item_le = {0x60030017U,"dex_code_item_le",sx_dex_code_item_fields,SX_COUNT(sx_dex_code_item_fields),SX_LE};
static const sx_layout sx_dex_code_item_be = {0x60030018U,"dex_code_item_be",sx_dex_code_item_fields,SX_COUNT(sx_dex_code_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_try_item_fields[] = {
    SX_FIELD("start_addr","uint32",0,4,SX_OFFSET),
    SX_FIELD("insn_count","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("handler_off","uint16",6,2,SX_OFFSET),
};
static const sx_layout sx_dex_try_item_le = {0x60030019U,"dex_try_item_le",sx_dex_try_item_fields,SX_COUNT(sx_dex_try_item_fields),SX_LE};
static const sx_layout sx_dex_try_item_be = {0x6003001AU,"dex_try_item_be",sx_dex_try_item_fields,SX_COUNT(sx_dex_try_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_coff_file_header_fields[] = {
    SX_FIELD("Machine","uint16",0,2,SX_ID),
    SX_FIELD("NumberOfSections","uint16",2,2,SX_COUNT_PROP),
    SX_FIELD("TimeDateStamp","uint32",4,4,SX_TIME),
    SX_FIELD("PointerToSymbolTable","uint32",8,4,SX_OFFSET),
    SX_FIELD("NumberOfSymbols","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("SizeOfOptionalHeader","uint16",16,2,SX_SIZE),
    SX_FIELD("Characteristics","uint16",18,2,SX_FLAGS),
};
static const sx_layout sx_coff_file_header = {0x60030021U,"coff_file_header",sx_coff_file_header_fields,SX_COUNT(sx_coff_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_te_header_fields[] = {
    SX_FIELD("Signature","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("Machine","uint16",2,2,SX_ID),
    SX_FIELD("NumberOfSections","uint8",4,1,SX_COUNT_PROP),
    SX_FIELD("Subsystem","uint8",5,1,SX_ID),
    SX_FIELD("StrippedSize","uint16",6,2,SX_SIZE),
    SX_FIELD("AddressOfEntryPoint","uint32",8,4,SX_ADDRESS),
    SX_FIELD("BaseOfCode","uint32",12,4,SX_ADDRESS),
    SX_FIELD("ImageBase","uint64",16,8,SX_ADDRESS),
    SX_FIELD("BaseReloc.VirtualAddress","uint32",24,4,SX_ADDRESS),
    SX_FIELD("BaseReloc.Size","uint32",28,4,SX_SIZE),
    SX_FIELD("Debug.VirtualAddress","uint32",32,4,SX_ADDRESS),
    SX_FIELD("Debug.Size","uint32",36,4,SX_SIZE),
};
static const sx_layout sx_te_header = {0x60030022U,"te_header",sx_te_header_fields,SX_COUNT(sx_te_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_coff_section_header_fields[] = {
    SX_FIELD("Name","char[8]",0,8,SX_STRING),
    SX_FIELD("VirtualSize","uint32",8,4,SX_SIZE),
    SX_FIELD("VirtualAddress","uint32",12,4,SX_ADDRESS),
    SX_FIELD("SizeOfRawData","uint32",16,4,SX_SIZE),
    SX_FIELD("PointerToRawData","uint32",20,4,SX_OFFSET),
    SX_FIELD("PointerToRelocations","uint32",24,4,SX_OFFSET),
    SX_FIELD("PointerToLinenumbers","uint32",28,4,SX_OFFSET),
    SX_FIELD("NumberOfRelocations","uint16",32,2,SX_COUNT_PROP),
    SX_FIELD("NumberOfLinenumbers","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("Characteristics","uint32",36,4,SX_FLAGS),
};
static const sx_layout sx_coff_section_header = {0x60030023U,"coff_section_header",sx_coff_section_header_fields,SX_COUNT(sx_coff_section_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_coff_relocation_fields[] = {
    SX_FIELD("VirtualAddress","uint32",0,4,SX_ADDRESS),
    SX_FIELD("SymbolTableIndex","uint32",4,4,SX_ID),
    SX_FIELD("Type","uint16",8,2,SX_ID),
};
static const sx_layout sx_coff_relocation = {0x60030024U,"coff_relocation",sx_coff_relocation_fields,SX_COUNT(sx_coff_relocation_fields),SX_LE};
static const xx_data_struct_field_desc sx_coff_line_number_fields[] = {
    SX_FIELD("SymbolTableIndex_or_VirtualAddress","uint32",0,4,SX_NONE),
    SX_FIELD("Linenumber","uint16",4,2,SX_NONE),
};
static const sx_layout sx_coff_line_number = {0x60030025U,"coff_line_number",sx_coff_line_number_fields,SX_COUNT(sx_coff_line_number_fields),SX_LE};
static const xx_data_struct_field_desc sx_coff_symbol_fields[] = {
    SX_FIELD("Name","uint8[8]",0,8,SX_NONE),
    SX_FIELD("Value","uint32",8,4,SX_NONE),
    SX_FIELD("SectionNumber","int16",12,2,SX_ID),
    SX_FIELD("Type","uint16",14,2,SX_ID),
    SX_FIELD("StorageClass","uint8",16,1,SX_ID),
    SX_FIELD("NumberOfAuxSymbols","uint8",17,1,SX_COUNT_PROP),
};
static const sx_layout sx_coff_symbol = {0x60030026U,"coff_symbol",sx_coff_symbol_fields,SX_COUNT(sx_coff_symbol_fields),SX_LE};
static const xx_data_struct_field_desc sx_coff_string_table_fields[] = {
    SX_FIELD("Length","uint32",0,4,SX_SIZE),
};
static const sx_layout sx_coff_string_table = {0x60030027U,"coff_string_table",sx_coff_string_table_fields,SX_COUNT(sx_coff_string_table_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_1_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,1,SX_SIZE),
};
const sx_layout sx_wasm_section_header_1 = {0x60030029U,"wasm_section_header_1",sx_wasm_section_header_1_fields,SX_COUNT(sx_wasm_section_header_1_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_5_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,5,SX_SIZE),
};
const sx_layout sx_wasm_section_header_5 = {0x6003002DU,"wasm_section_header_5",sx_wasm_section_header_5_fields,SX_COUNT(sx_wasm_section_header_5_fields),SX_LE};
/* The original DOS header is 28 bytes. The Windows extension is separate:
 * never interpret a classic relocation table at byte 28 as reserved words. */
static const xx_data_struct_field_desc sx_mz_header_fields[] = {
    SX_FIELD("e_magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("e_cblp","uint16",2,2,SX_NONE),
    SX_FIELD("e_cp","uint16",4,2,SX_COUNT_PROP),
    SX_FIELD("e_crlc","uint16",6,2,SX_COUNT_PROP),
    SX_FIELD("e_cparhdr","uint16",8,2,SX_NONE),
    SX_FIELD("e_minalloc","uint16",10,2,SX_NONE),
    SX_FIELD("e_maxalloc","uint16",12,2,SX_NONE),
    SX_FIELD("e_ss","uint16",14,2,SX_ADDRESS),
    SX_FIELD("e_sp","uint16",16,2,SX_ADDRESS),
    SX_FIELD("e_csum","uint16",18,2,SX_CHECKSUM),
    SX_FIELD("e_ip","uint16",20,2,SX_ADDRESS),
    SX_FIELD("e_cs","uint16",22,2,SX_ADDRESS),
    SX_FIELD("e_lfarlc","uint16",24,2,SX_OFFSET),
    SX_FIELD("e_ovno","uint16",26,2,SX_ID),
};
const sx_layout sx_mz_header = {0x60030100U,"mz_header",sx_mz_header_fields,SX_COUNT(sx_mz_header_fields),SX_LE};
static const sx_layout *const sx_executable_layouts[] = { &sx_mz_header, &sx_mz_extended_header, &sx_mz_relocation, &sx_dex_header_le, &sx_dex_header_be, &sx_dex_map_list_le, &sx_dex_map_list_be, &sx_dex_map_item_le, &sx_dex_map_item_be, &sx_dex_string_id_item_le, &sx_dex_string_id_item_be, &sx_dex_type_id_item_le, &sx_dex_type_id_item_be, &sx_dex_proto_id_item_le, &sx_dex_proto_id_item_be, &sx_dex_field_id_item_le, &sx_dex_field_id_item_be, &sx_dex_method_id_item_le, &sx_dex_method_id_item_be, &sx_dex_class_def_item_le, &sx_dex_class_def_item_be, &sx_dex_call_site_id_item_le, &sx_dex_call_site_id_item_be, &sx_dex_method_handle_item_le, &sx_dex_method_handle_item_be, &sx_dex_code_item_le, &sx_dex_code_item_be, &sx_dex_try_item_le, &sx_dex_try_item_be, &sx_fat_header_le, &sx_fat_header_be, &sx_fat_arch_le, &sx_fat_arch_be, &sx_fat_arch_64_le, &sx_fat_arch_64_be, &sx_coff_file_header, &sx_te_header, &sx_coff_section_header, &sx_coff_relocation, &sx_coff_line_number, &sx_coff_symbol, &sx_coff_string_table, &sx_wasm_header, &sx_wasm_section_header_1, &sx_wasm_section_header_2, &sx_wasm_section_header_3, &sx_wasm_section_header_4, &sx_wasm_section_header_5 };
static bool sx_executable_supports(xx_file_type_t t)
{
    return t==XX_FILE_TYPE_MSDOS||t==XX_FILE_TYPE_DEX||t==XX_FILE_TYPE_MACHOFAT||t==XX_FILE_TYPE_COFF_OBJECT||t==XX_FILE_TYPE_TE_EXECUTABLE||t==XX_FILE_TYPE_WASM;
}
bool sx_coff_build(sx_context *c,bool te)
{
    uint8_t h[40];uint32_t n,sym=0,symbols=0;int64_t table,adjust=0;
    if(!sx_read(c,0,h,te?40:20))return false;
    if(te){if(xx_data_get_u16(h,40,0,false)!=0x5a56)return false;n=h[4];table=40;adjust=40-(int64_t)xx_data_get_u16(h,40,6,false);}
    else{n=xx_data_get_u16(h,20,2,false);table=20+xx_data_get_u16(h,20,16,false);sym=xx_data_get_u32(h,20,8,false);symbols=xx_data_get_u32(h,20,12,false);}
    if(!n||n>65535||!sx_add(c,te?&sx_te_header:&sx_coff_file_header,0,te?40:20)||!sx_table(c,&sx_coff_section_header,table,40,n))return false;
    for(uint32_t i=0;i<n;i++) {
        uint8_t s[40];uint32_t size,off,rel,line;uint16_t nr,nl;
        if(!sx_read(c,table+(int64_t)i*40,s,40))return false;
        size=xx_data_get_u32(s,40,16,false);off=xx_data_get_u32(s,40,20,false);
        rel=xx_data_get_u32(s,40,24,false);line=xx_data_get_u32(s,40,28,false);
        nr=xx_data_get_u16(s,40,32,false);nl=xx_data_get_u16(s,40,34,false);
        if(size&&off&&!sx_raw(c,(int64_t)off+adjust,size))return false;
        if(!te&&nr) {
            uint32_t count=nr;
            if(nr==65535&&(xx_data_get_u32(s,40,36,false)&0x01000000U)) {
                if(!sx_u32(c,rel,false,&count)||count==0)return false;
                /* Overflow marker has the same physical 10-byte layout. */
            }
            if(!rel||!sx_table(c,&sx_coff_relocation,rel,10,count))return false;
        }
        if(!te&&nl&&(!line||!sx_table(c,&sx_coff_line_number,line,6,nl)))return false;
    }
    if(!te&&sym) {
        uint32_t string_size;
        if(symbols>(uint64_t)c->size/18)return false;
        for(uint32_t i=0;i<symbols;) {
            uint8_t aux;int64_t off=(int64_t)sym+(int64_t)i*18;
            if(!sx_add(c,&sx_coff_symbol,off,18)||!sx_read(c,off+17,&aux,1)||aux>symbols-i-1)return false;
            if(aux&&!sx_raw(c,off+18,(int64_t)aux*18))return false;
            i+=1+aux;
        }
        int64_t strings=(int64_t)sym+(int64_t)symbols*18;
        if(!sx_u32(c,strings,false,&string_size)||string_size<4||!sx_add(c,&sx_coff_string_table,strings,4)||!sx_raw(c,strings+4,string_size-4))return false;
    }return true;
}
static bool sx_executable_build(sx_context *c)
{
    switch(c->f->file_type) {
        case XX_FILE_TYPE_MSDOS:return sx_msdos_build(c);
        case XX_FILE_TYPE_DEX:return sx_dex_schema_build(c);
        case XX_FILE_TYPE_MACHOFAT:return sx_machofat_build(c);
        case XX_FILE_TYPE_COFF_OBJECT:return sx_coff_object_build(c);
        case XX_FILE_TYPE_TE_EXECUTABLE:return sx_te_executable_build(c);
        case XX_FILE_TYPE_WASM:return sx_wasm_schema_build(c);
        default:return false;
    }
}
static bool sx_executable_comment(xx_data_struct_record *r,uint32_t id)
{
    const char *comment=NULL;uint64_t v;
    if(!r||id<0x60030000U||id>=0x60040000U)return true;
    v=xx_var_get_u64(&r->value);
    if(id==sx_mz_header.id&&r->name) {
        if(!xx_rt_wcscmp(r->name,L"e_magic")&&v==0x5a4d)comment="MZ";
        else if(!xx_rt_wcscmp(r->name,L"e_cblp"))comment="Bytes in final 512-byte page (0 means 512)";
        else if(!xx_rt_wcscmp(r->name,L"e_cp"))comment="512-byte pages in file";
        else if(!xx_rt_wcscmp(r->name,L"e_cparhdr")||!xx_rt_wcscmp(r->name,L"e_minalloc")||!xx_rt_wcscmp(r->name,L"e_maxalloc"))comment="16-byte paragraphs";
    }else if(r->name&&!xx_rt_wcscmp(r->name,L"Machine")) {
        switch(v){case 0x14c:comment="IMAGE_FILE_MACHINE_I386";break;case 0x8664:comment="IMAGE_FILE_MACHINE_AMD64";break;case 0xaa64:comment="IMAGE_FILE_MACHINE_ARM64";break;case 0x1c4:comment="IMAGE_FILE_MACHINE_ARMNT";break;}
    }else if(r->name&&!xx_rt_wcscmp(r->name,L"cputype")) {
        switch(v){case 7:comment="CPU_TYPE_X86";break;case 12:comment="CPU_TYPE_ARM";break;case 0x1000007:comment="CPU_TYPE_X86_64";break;case 0x100000c:comment="CPU_TYPE_ARM64";break;case 18:comment="CPU_TYPE_POWERPC";break;}
    }else if(id>=sx_wasm_section_header_1.id&&id<=sx_wasm_section_header_5.id&&r->offset==0) {
        static const char *const names[]={"custom","type","import","function","table","memory","global","export","start","element","code","data","data_count"};
        if(v<SX_COUNT(names))comment=names[v];
    }
    if(comment){wchar_t w[80];size_t i=0;for(;comment[i]&&i<79;i++)w[i]=(unsigned char)comment[i];w[i]=0;return xx_data_struct_record_set_comment(r,w);}return true;
}
const sx_family sx_executable_family={sx_executable_supports,sx_executable_build,sx_executable_layouts,SX_COUNT(sx_executable_layouts),sx_executable_comment};
