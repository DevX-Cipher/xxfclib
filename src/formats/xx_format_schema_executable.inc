/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical executable layouts: xxfclib DEX definitions, Apple fat.h,
 * Microsoft PE/COFF and UEFI TE headers; WebAssembly core section framing.
 */
static const xx_data_struct_field_desc sx_dex_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("checksum","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("signature","uint8[20]",12,20,SX_NONE),
    SX_FIELD("file_size","uint32",32,4,SX_SIZE),
    SX_FIELD("header_size","uint32",36,4,SX_SIZE),
    SX_FIELD("endian_tag","uint32",40,4,SX_ID),
    SX_FIELD("link_size","uint32",44,4,SX_SIZE),
    SX_FIELD("link_off","uint32",48,4,SX_OFFSET),
    SX_FIELD("map_off","uint32",52,4,SX_OFFSET),
    SX_FIELD("string_ids_size","uint32",56,4,SX_COUNT_PROP),
    SX_FIELD("string_ids_off","uint32",60,4,SX_OFFSET),
    SX_FIELD("type_ids_size","uint32",64,4,SX_COUNT_PROP),
    SX_FIELD("type_ids_off","uint32",68,4,SX_OFFSET),
    SX_FIELD("proto_ids_size","uint32",72,4,SX_COUNT_PROP),
    SX_FIELD("proto_ids_off","uint32",76,4,SX_OFFSET),
    SX_FIELD("field_ids_size","uint32",80,4,SX_COUNT_PROP),
    SX_FIELD("field_ids_off","uint32",84,4,SX_OFFSET),
    SX_FIELD("method_ids_size","uint32",88,4,SX_COUNT_PROP),
    SX_FIELD("method_ids_off","uint32",92,4,SX_OFFSET),
    SX_FIELD("class_defs_size","uint32",96,4,SX_COUNT_PROP),
    SX_FIELD("class_defs_off","uint32",100,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",104,4,SX_SIZE),
    SX_FIELD("data_off","uint32",108,4,SX_OFFSET),
};
static const sx_layout sx_dex_header_le = {0x60030001U,"dex_header_le",sx_dex_header_fields,SX_COUNT(sx_dex_header_fields),SX_LE};
static const sx_layout sx_dex_header_be = {0x60030002U,"dex_header_be",sx_dex_header_fields,SX_COUNT(sx_dex_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_map_list_fields[] = {
    SX_FIELD("size","uint32",0,4,SX_COUNT_PROP),
};
static const sx_layout sx_dex_map_list_le = {0x60030003U,"dex_map_list_le",sx_dex_map_list_fields,SX_COUNT(sx_dex_map_list_fields),SX_LE};
static const sx_layout sx_dex_map_list_be = {0x60030004U,"dex_map_list_be",sx_dex_map_list_fields,SX_COUNT(sx_dex_map_list_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_map_item_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("unused","uint16",2,2,SX_RESERVED),
    SX_FIELD("size","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("offset","uint32",8,4,SX_OFFSET),
};
static const sx_layout sx_dex_map_item_le = {0x60030005U,"dex_map_item_le",sx_dex_map_item_fields,SX_COUNT(sx_dex_map_item_fields),SX_LE};
static const sx_layout sx_dex_map_item_be = {0x60030006U,"dex_map_item_be",sx_dex_map_item_fields,SX_COUNT(sx_dex_map_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_string_id_item_fields[] = {
    SX_FIELD("string_data_off","uint32",0,4,SX_OFFSET),
};
static const sx_layout sx_dex_string_id_item_le = {0x60030007U,"dex_string_id_item_le",sx_dex_string_id_item_fields,SX_COUNT(sx_dex_string_id_item_fields),SX_LE};
static const sx_layout sx_dex_string_id_item_be = {0x60030008U,"dex_string_id_item_be",sx_dex_string_id_item_fields,SX_COUNT(sx_dex_string_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_type_id_item_fields[] = {
    SX_FIELD("descriptor_idx","uint32",0,4,SX_ID),
};
static const sx_layout sx_dex_type_id_item_le = {0x60030009U,"dex_type_id_item_le",sx_dex_type_id_item_fields,SX_COUNT(sx_dex_type_id_item_fields),SX_LE};
static const sx_layout sx_dex_type_id_item_be = {0x6003000AU,"dex_type_id_item_be",sx_dex_type_id_item_fields,SX_COUNT(sx_dex_type_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_proto_id_item_fields[] = {
    SX_FIELD("shorty_idx","uint32",0,4,SX_ID),
    SX_FIELD("return_type_idx","uint32",4,4,SX_ID),
    SX_FIELD("parameters_off","uint32",8,4,SX_OFFSET),
};
static const sx_layout sx_dex_proto_id_item_le = {0x6003000BU,"dex_proto_id_item_le",sx_dex_proto_id_item_fields,SX_COUNT(sx_dex_proto_id_item_fields),SX_LE};
static const sx_layout sx_dex_proto_id_item_be = {0x6003000CU,"dex_proto_id_item_be",sx_dex_proto_id_item_fields,SX_COUNT(sx_dex_proto_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_field_id_item_fields[] = {
    SX_FIELD("class_idx","uint16",0,2,SX_ID),
    SX_FIELD("type_idx","uint16",2,2,SX_ID),
    SX_FIELD("name_idx","uint32",4,4,SX_ID),
};
static const sx_layout sx_dex_field_id_item_le = {0x6003000DU,"dex_field_id_item_le",sx_dex_field_id_item_fields,SX_COUNT(sx_dex_field_id_item_fields),SX_LE};
static const sx_layout sx_dex_field_id_item_be = {0x6003000EU,"dex_field_id_item_be",sx_dex_field_id_item_fields,SX_COUNT(sx_dex_field_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_method_id_item_fields[] = {
    SX_FIELD("class_idx","uint16",0,2,SX_ID),
    SX_FIELD("proto_idx","uint16",2,2,SX_ID),
    SX_FIELD("name_idx","uint32",4,4,SX_ID),
};
static const sx_layout sx_dex_method_id_item_le = {0x6003000FU,"dex_method_id_item_le",sx_dex_method_id_item_fields,SX_COUNT(sx_dex_method_id_item_fields),SX_LE};
static const sx_layout sx_dex_method_id_item_be = {0x60030010U,"dex_method_id_item_be",sx_dex_method_id_item_fields,SX_COUNT(sx_dex_method_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_class_def_item_fields[] = {
    SX_FIELD("class_idx","uint32",0,4,SX_ID),
    SX_FIELD("access_flags","uint32",4,4,SX_FLAGS),
    SX_FIELD("superclass_idx","uint32",8,4,SX_ID),
    SX_FIELD("interfaces_off","uint32",12,4,SX_OFFSET),
    SX_FIELD("source_file_idx","uint32",16,4,SX_ID),
    SX_FIELD("annotations_off","uint32",20,4,SX_OFFSET),
    SX_FIELD("class_data_off","uint32",24,4,SX_OFFSET),
    SX_FIELD("static_values_off","uint32",28,4,SX_OFFSET),
};
static const sx_layout sx_dex_class_def_item_le = {0x60030011U,"dex_class_def_item_le",sx_dex_class_def_item_fields,SX_COUNT(sx_dex_class_def_item_fields),SX_LE};
static const sx_layout sx_dex_class_def_item_be = {0x60030012U,"dex_class_def_item_be",sx_dex_class_def_item_fields,SX_COUNT(sx_dex_class_def_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_call_site_id_item_fields[] = {
    SX_FIELD("call_site_off","uint32",0,4,SX_OFFSET),
};
static const sx_layout sx_dex_call_site_id_item_le = {0x60030013U,"dex_call_site_id_item_le",sx_dex_call_site_id_item_fields,SX_COUNT(sx_dex_call_site_id_item_fields),SX_LE};
static const sx_layout sx_dex_call_site_id_item_be = {0x60030014U,"dex_call_site_id_item_be",sx_dex_call_site_id_item_fields,SX_COUNT(sx_dex_call_site_id_item_fields),SX_BE};
static const xx_data_struct_field_desc sx_dex_method_handle_item_fields[] = {
    SX_FIELD("method_handle_type","uint16",0,2,SX_ID),
    SX_FIELD("unused1","uint16",2,2,SX_RESERVED),
    SX_FIELD("field_or_method_id","uint16",4,2,SX_ID),
    SX_FIELD("unused2","uint16",6,2,SX_RESERVED),
};
static const sx_layout sx_dex_method_handle_item_le = {0x60030015U,"dex_method_handle_item_le",sx_dex_method_handle_item_fields,SX_COUNT(sx_dex_method_handle_item_fields),SX_LE};
static const sx_layout sx_dex_method_handle_item_be = {0x60030016U,"dex_method_handle_item_be",sx_dex_method_handle_item_fields,SX_COUNT(sx_dex_method_handle_item_fields),SX_BE};
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
static const xx_data_struct_field_desc sx_fat_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("nfat_arch","uint32",4,4,SX_COUNT_PROP),
};
static const sx_layout sx_fat_header_le = {0x6003001BU,"fat_header_le",sx_fat_header_fields,SX_COUNT(sx_fat_header_fields),SX_LE};
static const sx_layout sx_fat_header_be = {0x6003001CU,"fat_header_be",sx_fat_header_fields,SX_COUNT(sx_fat_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_fat_arch_fields[] = {
    SX_FIELD("cputype","uint32",0,4,SX_ID),
    SX_FIELD("cpusubtype","uint32",4,4,SX_ID),
    SX_FIELD("offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("size","uint32",12,4,SX_SIZE),
    SX_FIELD("align","uint32",16,4,SX_NONE),
};
static const sx_layout sx_fat_arch_le = {0x6003001DU,"fat_arch_le",sx_fat_arch_fields,SX_COUNT(sx_fat_arch_fields),SX_LE};
static const sx_layout sx_fat_arch_be = {0x6003001EU,"fat_arch_be",sx_fat_arch_fields,SX_COUNT(sx_fat_arch_fields),SX_BE};
static const xx_data_struct_field_desc sx_fat_arch_64_fields[] = {
    SX_FIELD("cputype","uint32",0,4,SX_ID),
    SX_FIELD("cpusubtype","uint32",4,4,SX_ID),
    SX_FIELD("offset","uint64",8,8,SX_OFFSET),
    SX_FIELD("size","uint64",16,8,SX_SIZE),
    SX_FIELD("align","uint32",24,4,SX_NONE),
    SX_FIELD("reserved","uint32",28,4,SX_RESERVED),
};
static const sx_layout sx_fat_arch_64_le = {0x6003001FU,"fat_arch_64_le",sx_fat_arch_64_fields,SX_COUNT(sx_fat_arch_64_fields),SX_LE};
static const sx_layout sx_fat_arch_64_be = {0x60030020U,"fat_arch_64_be",sx_fat_arch_64_fields,SX_COUNT(sx_fat_arch_64_fields),SX_BE};
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
static const xx_data_struct_field_desc sx_wasm_header_fields[] = {
    SX_FIELD("magic","uint8[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
};
static const sx_layout sx_wasm_header = {0x60030028U,"wasm_header",sx_wasm_header_fields,SX_COUNT(sx_wasm_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_1_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,1,SX_SIZE),
};
static const sx_layout sx_wasm_section_header_1 = {0x60030029U,"wasm_section_header_1",sx_wasm_section_header_1_fields,SX_COUNT(sx_wasm_section_header_1_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_2_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,2,SX_SIZE),
};
static const sx_layout sx_wasm_section_header_2 = {0x6003002AU,"wasm_section_header_2",sx_wasm_section_header_2_fields,SX_COUNT(sx_wasm_section_header_2_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_3_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,3,SX_SIZE),
};
static const sx_layout sx_wasm_section_header_3 = {0x6003002BU,"wasm_section_header_3",sx_wasm_section_header_3_fields,SX_COUNT(sx_wasm_section_header_3_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_4_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,4,SX_SIZE),
};
static const sx_layout sx_wasm_section_header_4 = {0x6003002CU,"wasm_section_header_4",sx_wasm_section_header_4_fields,SX_COUNT(sx_wasm_section_header_4_fields),SX_LE};
static const xx_data_struct_field_desc sx_wasm_section_header_5_fields[] = {
    SX_FIELD("id","uint8",0,1,SX_ID),
    SX_FIELD("payload_len","uleb128",1,5,SX_SIZE),
};
static const sx_layout sx_wasm_section_header_5 = {0x6003002DU,"wasm_section_header_5",sx_wasm_section_header_5_fields,SX_COUNT(sx_wasm_section_header_5_fields),SX_LE};
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
static const sx_layout sx_mz_header = {0x60030100U,"mz_header",sx_mz_header_fields,SX_COUNT(sx_mz_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_mz_extended_header_fields[] = {
    SX_FIELD("e_res","uint16[4]",0,8,SX_RESERVED),
    SX_FIELD("e_oemid","uint16",8,2,SX_ID),
    SX_FIELD("e_oeminfo","uint16",10,2,SX_NONE),
    SX_FIELD("e_res2","uint16[10]",12,20,SX_RESERVED),
    SX_FIELD("e_lfanew","uint32",32,4,SX_OFFSET),
};
static const sx_layout sx_mz_extended_header = {0x60030101U,"mz_extended_header",sx_mz_extended_header_fields,SX_COUNT(sx_mz_extended_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_mz_relocation_fields[] = {
    SX_FIELD("offset","uint16",0,2,SX_OFFSET),
    SX_FIELD("segment","uint16",2,2,SX_ADDRESS),
};
static const sx_layout sx_mz_relocation = {0x60030102U,"mz_relocation",sx_mz_relocation_fields,SX_COUNT(sx_mz_relocation_fields),SX_LE};
static bool sx_mz_build(sx_context *c)
{
    uint8_t h[28];
    uint32_t header_size,reloc_offset,reloc_count,at=28;
    if(!sx_read(c,0,h,sizeof(h))||xx_data_get_u16(h,28,0,false)!=0x5a4d)return false;
    header_size=(uint32_t)xx_data_get_u16(h,28,8,false)*16;
    reloc_offset=xx_data_get_u16(h,28,24,false);
    reloc_count=xx_data_get_u16(h,28,6,false);
    if(header_size<28||header_size>(uint64_t)c->size||
       (reloc_count&&(reloc_offset<28||reloc_offset>header_size||reloc_count>(header_size-reloc_offset)/4)))return false;
    if(!sx_add(c,&sx_mz_header,0,28))return false;
    if(header_size>=64&&(!reloc_count||reloc_offset>=64)) {
        uint32_t secondary;uint16_t signature=0;
        sx_context probe=*c;
        /* A recognized PE/NE/LE/LX header can reside in the DOS overlay. */
        probe.size=xx_io_total_size(c->f->device)-c->f->base_address;
        if(!sx_u32(c,60,false,&secondary))return false;
        /* A late relocation table alone can also be classic DOS padding.
         * Match the native reader's known secondary-header signatures before
         * naming those bytes as the Windows extended header. */
        if(secondary>=64&&secondary<=(uint64_t)probe.size-2&&!sx_u16(&probe,secondary,false,&signature))return false;
        bool known=signature==0x454e||signature==0x454c||signature==0x584c;
        if(signature==0x4550&&secondary<=(uint64_t)probe.size-4) {
            uint32_t pe;if(!sx_u32(&probe,secondary,false,&pe))return false;known=pe==0x4550;
        }
        if(known) {
            if(!sx_add(c,&sx_mz_extended_header,28,36))return false;
            at=64;
        }
    }
    if(reloc_count) {
        if(!sx_raw(c,at,reloc_offset-at)||!sx_table(c,&sx_mz_relocation,reloc_offset,4,reloc_count))return false;
        at=reloc_offset+reloc_count*4;
    }
    return sx_raw(c,at,header_size-at)&&sx_raw(c,header_size,c->size-header_size);
}

static const sx_layout *const sx_executable_layouts[] = { &sx_mz_header, &sx_mz_extended_header, &sx_mz_relocation, &sx_dex_header_le, &sx_dex_header_be, &sx_dex_map_list_le, &sx_dex_map_list_be, &sx_dex_map_item_le, &sx_dex_map_item_be, &sx_dex_string_id_item_le, &sx_dex_string_id_item_be, &sx_dex_type_id_item_le, &sx_dex_type_id_item_be, &sx_dex_proto_id_item_le, &sx_dex_proto_id_item_be, &sx_dex_field_id_item_le, &sx_dex_field_id_item_be, &sx_dex_method_id_item_le, &sx_dex_method_id_item_be, &sx_dex_class_def_item_le, &sx_dex_class_def_item_be, &sx_dex_call_site_id_item_le, &sx_dex_call_site_id_item_be, &sx_dex_method_handle_item_le, &sx_dex_method_handle_item_be, &sx_dex_code_item_le, &sx_dex_code_item_be, &sx_dex_try_item_le, &sx_dex_try_item_be, &sx_fat_header_le, &sx_fat_header_be, &sx_fat_arch_le, &sx_fat_arch_be, &sx_fat_arch_64_le, &sx_fat_arch_64_be, &sx_coff_file_header, &sx_te_header, &sx_coff_section_header, &sx_coff_relocation, &sx_coff_line_number, &sx_coff_symbol, &sx_coff_string_table, &sx_wasm_header, &sx_wasm_section_header_1, &sx_wasm_section_header_2, &sx_wasm_section_header_3, &sx_wasm_section_header_4, &sx_wasm_section_header_5 };
static bool sx_executable_supports(xx_file_type_t t)
{
    return t==XX_FILE_TYPE_MSDOS||t==XX_FILE_TYPE_DEX||t==XX_FILE_TYPE_MACHOFAT||t==XX_FILE_TYPE_COFF_OBJECT||t==XX_FILE_TYPE_TE_EXECUTABLE||t==XX_FILE_TYPE_WASM;
}
#define SX_DEX_LAYOUT(n) (be?&sx_##n##_be:&sx_##n##_le)
static bool sx_dex_build(sx_context *c)
{
    uint8_t h[112]; uint32_t map,filesize,header,n;
    bool be;
    const sx_layout *fixed[6];
    const unsigned widths[]={4,4,12,8,8,32};
    if(!sx_read(c,0,h,sizeof(h))||xx_rt_memcmp(h,"dex\n",4))return false;
    if(xx_data_get_u32(h,112,40,false)==0x12345678U)be=false;
    else if(xx_data_get_u32(h,112,40,false)==0x78563412U)be=true;else return false;
    filesize=xx_data_get_u32(h,112,32,be);header=xx_data_get_u32(h,112,36,be);
    if(header!=112||filesize<112||filesize>(uint64_t)c->size)return false;
    c->size=filesize;
    if(!sx_add(c,SX_DEX_LAYOUT(dex_header),0,112))return false;
    fixed[0]=SX_DEX_LAYOUT(dex_string_id_item);fixed[1]=SX_DEX_LAYOUT(dex_type_id_item);fixed[2]=SX_DEX_LAYOUT(dex_proto_id_item);
    fixed[3]=SX_DEX_LAYOUT(dex_field_id_item);fixed[4]=SX_DEX_LAYOUT(dex_method_id_item);fixed[5]=SX_DEX_LAYOUT(dex_class_def_item);
    for(unsigned i=0;i<6;i++) {
        n=xx_data_get_u32(h,112,56+i*8,be);
        uint32_t off=xx_data_get_u32(h,112,60+i*8,be);
        if(n&&(!off||!sx_table(c,fixed[i],off,widths[i],n)))return false;
    }
    map=xx_data_get_u32(h,112,52,be);
    if(map) {
        if(!sx_u32(c,map,be,&n)||n>65536||!sx_add(c,SX_DEX_LAYOUT(dex_map_list),map,4)||!sx_table(c,SX_DEX_LAYOUT(dex_map_item),(int64_t)map+4,12,n))return false;
        for(uint32_t i=0;i<n;i++) {
            uint8_t entry[12];uint16_t type;uint32_t count,off;
            if(!sx_read(c,(int64_t)map+4+(int64_t)i*12,entry,12))return false;
            type=xx_data_get_u16(entry,12,0,be);count=xx_data_get_u32(entry,12,4,be);off=xx_data_get_u32(entry,12,8,be);
            if(type==7&&!sx_table(c,SX_DEX_LAYOUT(dex_call_site_id_item),off,4,count))return false;
            if(type==8&&!sx_table(c,SX_DEX_LAYOUT(dex_method_handle_item),off,8,count))return false;
        }
    }
    /* Variable DEX items remain explicit raw data until their individual
     * encoded-value, debug-info and instruction grammars have schemas. */
    n=xx_data_get_u32(h,112,104,be);
    if(n&&!sx_raw(c,xx_data_get_u32(h,112,108,be),n))return false;
    return true;
}
#undef SX_DEX_LAYOUT
static bool sx_fat_build(sx_context *c)
{
    uint8_t h[8];uint32_t magic,n;bool be,wide;
    if(!sx_read(c,0,h,8))return false;
    magic=xx_data_get_u32(h,8,0,true);
    be=magic==0xcafebabeU||magic==0xcafebabfU;wide=magic==0xcafebabfU||magic==0xbfbafecaU;
    if(!be&&magic!=0xbebafecaU&&magic!=0xbfbafecaU)return false;
    n=xx_data_get_u32(h,8,4,be);if(!n||n>4096)return false;
    if(!sx_add(c,be?&sx_fat_header_be:&sx_fat_header_le,0,8)||!sx_table(c,wide?(be?&sx_fat_arch_64_be:&sx_fat_arch_64_le):(be?&sx_fat_arch_be:&sx_fat_arch_le),8,wide?32:20,n))return false;
    for(uint32_t i=0;i<n;i++) {
        uint8_t a[32];uint64_t off,size;int stride=wide?32:20;
        if(!sx_read(c,8+(int64_t)i*stride,a,stride))return false;
        off=wide?xx_data_get_u64(a,stride,8,be):xx_data_get_u32(a,stride,8,be);
        size=wide?xx_data_get_u64(a,stride,16,be):xx_data_get_u32(a,stride,12,be);
        if(off>INT64_MAX||size>INT64_MAX||!sx_raw(c,(int64_t)off,(int64_t)size))return false;
    }return true;
}
static bool sx_coff_build(sx_context *c,bool te)
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
static bool sx_wasm_build(sx_context *c)
{
    static const sx_layout *const layouts[]={&sx_wasm_section_header_1,&sx_wasm_section_header_2,&sx_wasm_section_header_3,&sx_wasm_section_header_4,&sx_wasm_section_header_5};
    uint8_t h[8];int64_t at=8;
    if(!sx_read(c,0,h,8)||xx_rt_memcmp(h,"\0asm\1\0\0\0",8)||!sx_add(c,&sx_wasm_header,0,8))return false;
    while(at<c->size) {
        uint8_t id,b=0;uint32_t value=0;unsigned w;
        if(!sx_read(c,at,&id,1)||id>12)return false;
        for(w=0;w<5;w++) {
            if(!sx_read(c,at+1+w,&b,1)||(w==4&&(b&0xf0)))return false;
            value|=(uint32_t)(b&127)<<(7*w);if(!(b&128))break;
        }
        if(w==5||!sx_add(c,layouts[w],at,2+w))return false;
        at+=2+w;if(!sx_raw(c,at,value))return false;at+=value;
    }return true;
}
static bool sx_executable_build(sx_context *c)
{
    switch(c->f->file_type) {
        case XX_FILE_TYPE_MSDOS:return sx_mz_build(c);
        case XX_FILE_TYPE_DEX:return sx_dex_build(c);
        case XX_FILE_TYPE_MACHOFAT:return sx_fat_build(c);
        case XX_FILE_TYPE_COFF_OBJECT:return sx_coff_build(c,false);
        case XX_FILE_TYPE_TE_EXECUTABLE:return sx_coff_build(c,true);
        case XX_FILE_TYPE_WASM:return sx_wasm_build(c);
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
