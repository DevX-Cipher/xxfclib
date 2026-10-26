/* SPDX-License-Identifier: MIT
 * Partial physical executable metadata; encrypted regions stay ciphertext. */
static const xx_data_struct_field_desc sxexo_molebox_package_prefix_fields[]={
SX_FIELD("encrypted_signature","uint8[8]",0,8,SX_NONE),
SX_FIELD("stored_package_base","uint32",8,4,SX_OFFSET),
};
static const sx_layout sxexo_molebox_package_prefix={0x60880001U,"molebox_package_prefix",sxexo_molebox_package_prefix_fields,SX_COUNT(sxexo_molebox_package_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_molebox_encrypted_tree_fields[]={
SX_FIELD("ciphertext","uint8",0,0,SX_NONE),
};
static const sx_layout sxexo_molebox_encrypted_tree={0x60880002U,"molebox_encrypted_tree",sxexo_molebox_encrypted_tree_fields,SX_COUNT(sxexo_molebox_encrypted_tree_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_molebox_encrypted_header_fields[]={
SX_FIELD("ciphertext","uint8[48]",0,48,SX_NONE),
};
static const sx_layout sxexo_molebox_encrypted_header={0x60880003U,"molebox_encrypted_header",sxexo_molebox_encrypted_header_fields,SX_COUNT(sxexo_molebox_encrypted_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_molebox_encrypted_catalog_fields[]={
SX_FIELD("ciphertext","uint8",0,0,SX_NONE),
};
static const sx_layout sxexo_molebox_encrypted_catalog={0x60880004U,"molebox_encrypted_catalog",sxexo_molebox_encrypted_catalog_fields,SX_COUNT(sxexo_molebox_encrypted_catalog_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_molebox_encrypted_catalog_footer_fields[]={
SX_FIELD("ciphertext","uint8[8]",0,8,SX_NONE),
};
static const sx_layout sxexo_molebox_encrypted_catalog_footer={0x60880005U,"molebox_encrypted_catalog_footer",sxexo_molebox_encrypted_catalog_footer_fields,SX_COUNT(sxexo_molebox_encrypted_catalog_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_dos_header_fields[]={
SX_FIELD("e_magic","uint16",0,2,SX_SIGNATURE),
SX_FIELD("e_cblp","uint16",2,2,SX_NONE),
SX_FIELD("e_cp","uint16",4,2,SX_COUNT_PROP),
SX_FIELD("e_crlc","uint16",6,2,SX_COUNT_PROP),
SX_FIELD("e_cparhdr","uint16",8,2,SX_COUNT_PROP),
SX_FIELD("e_minalloc","uint16",10,2,SX_COUNT_PROP),
SX_FIELD("e_maxalloc","uint16",12,2,SX_COUNT_PROP),
SX_FIELD("e_ss","uint16",14,2,SX_ADDRESS),
SX_FIELD("e_sp","uint16",16,2,SX_ADDRESS),
SX_FIELD("e_csum","uint16",18,2,SX_CHECKSUM),
SX_FIELD("e_ip","uint16",20,2,SX_ADDRESS),
SX_FIELD("e_cs","uint16",22,2,SX_ADDRESS),
SX_FIELD("e_lfarlc","uint16",24,2,SX_OFFSET),
SX_FIELD("e_ovno","uint16",26,2,SX_ID),
};
static const sx_layout sxexo_overlay_dos_header={0x60880006U,"overlay_dos_header",sxexo_overlay_dos_header_fields,SX_COUNT(sxexo_overlay_dos_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_dos_e_res_fields[]={
SX_FIELD("e_res","uint16le[4]",0,8,SX_RESERVED),
};
static const sx_layout sxexo_overlay_dos_e_res={0x60880007U,"overlay_dos_e_res",sxexo_overlay_dos_e_res_fields,SX_COUNT(sxexo_overlay_dos_e_res_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_dos_e_oemid_fields[]={
SX_FIELD("e_oemid","uint16",0,2,SX_ID),
};
static const sx_layout sxexo_overlay_dos_e_oemid={0x60880008U,"overlay_dos_e_oemid",sxexo_overlay_dos_e_oemid_fields,SX_COUNT(sxexo_overlay_dos_e_oemid_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_dos_e_oeminfo_fields[]={
SX_FIELD("e_oeminfo","uint16",0,2,SX_NONE),
};
static const sx_layout sxexo_overlay_dos_e_oeminfo={0x60880009U,"overlay_dos_e_oeminfo",sxexo_overlay_dos_e_oeminfo_fields,SX_COUNT(sxexo_overlay_dos_e_oeminfo_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_dos_e_res2_fields[]={
SX_FIELD("e_res2","uint16le[10]",0,20,SX_RESERVED),
};
static const sx_layout sxexo_overlay_dos_e_res2={0x6088000aU,"overlay_dos_e_res2",sxexo_overlay_dos_e_res2_fields,SX_COUNT(sxexo_overlay_dos_e_res2_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_dos_e_lfanew_fields[]={
SX_FIELD("e_lfanew","uint32",0,4,SX_OFFSET),
};
static const sx_layout sxexo_overlay_dos_e_lfanew={0x6088000bU,"overlay_dos_e_lfanew",sxexo_overlay_dos_e_lfanew_fields,SX_COUNT(sxexo_overlay_dos_e_lfanew_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_dos_relocation_fields[]={
SX_FIELD("offset","uint16",0,2,SX_ADDRESS),
SX_FIELD("segment","uint16",2,2,SX_ADDRESS),
};
static const sx_layout sxexo_overlay_dos_relocation={0x6088000cU,"overlay_dos_relocation",sxexo_overlay_dos_relocation_fields,SX_COUNT(sxexo_overlay_dos_relocation_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_pe_signature_fields[]={
SX_FIELD("Signature","uint32",0,4,SX_ID),
};
static const sx_layout sxexo_overlay_pe_signature={0x6088000dU,"overlay_pe_signature",sxexo_overlay_pe_signature_fields,SX_COUNT(sxexo_overlay_pe_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_coff_header_fields[]={
SX_FIELD("Machine","uint16",0,2,SX_ID),
SX_FIELD("NumberOfSections","uint16",2,2,SX_COUNT_PROP),
SX_FIELD("TimeDateStamp","uint32",4,4,SX_TIME),
SX_FIELD("PointerToSymbolTable","uint32",8,4,SX_OFFSET),
SX_FIELD("NumberOfSymbols","uint32",12,4,SX_COUNT_PROP),
SX_FIELD("SizeOfOptionalHeader","uint16",16,2,SX_SIZE),
SX_FIELD("Characteristics","uint16",18,2,SX_FLAGS),
};
static const sx_layout sxexo_overlay_coff_header={0x6088000eU,"overlay_coff_header",sxexo_overlay_coff_header_fields,SX_COUNT(sxexo_overlay_coff_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_pe_optional32_fields[]={
SX_FIELD("Magic","uint16",0,2,SX_ID),
SX_FIELD("MajorLinkerVersion","uint8",2,1,SX_NONE),
SX_FIELD("MinorLinkerVersion","uint8",3,1,SX_NONE),
SX_FIELD("SizeOfCode","uint32",4,4,SX_SIZE),
SX_FIELD("SizeOfInitializedData","uint32",8,4,SX_SIZE),
SX_FIELD("SizeOfUninitializedData","uint32",12,4,SX_SIZE),
SX_FIELD("AddressOfEntryPoint","uint32",16,4,SX_ADDRESS),
SX_FIELD("BaseOfCode","uint32",20,4,SX_ADDRESS),
SX_FIELD("BaseOfData","uint32",24,4,SX_ADDRESS),
SX_FIELD("ImageBase","uint32",28,4,SX_ADDRESS),
SX_FIELD("SectionAlignment","uint32",32,4,SX_SIZE),
SX_FIELD("FileAlignment","uint32",36,4,SX_SIZE),
SX_FIELD("MajorOperatingSystemVersion","uint16",40,2,SX_NONE),
SX_FIELD("MinorOperatingSystemVersion","uint16",42,2,SX_NONE),
SX_FIELD("MajorImageVersion","uint16",44,2,SX_NONE),
SX_FIELD("MinorImageVersion","uint16",46,2,SX_NONE),
SX_FIELD("MajorSubsystemVersion","uint16",48,2,SX_NONE),
SX_FIELD("MinorSubsystemVersion","uint16",50,2,SX_NONE),
SX_FIELD("Win32VersionValue","uint32",52,4,SX_RESERVED),
SX_FIELD("SizeOfImage","uint32",56,4,SX_SIZE),
SX_FIELD("SizeOfHeaders","uint32",60,4,SX_SIZE),
SX_FIELD("CheckSum","uint32",64,4,SX_CHECKSUM),
SX_FIELD("Subsystem","uint16",68,2,SX_ID),
SX_FIELD("DllCharacteristics","uint16",70,2,SX_FLAGS),
SX_FIELD("SizeOfStackReserve","uint32",72,4,SX_SIZE),
SX_FIELD("SizeOfStackCommit","uint32",76,4,SX_SIZE),
SX_FIELD("SizeOfHeapReserve","uint32",80,4,SX_SIZE),
SX_FIELD("SizeOfHeapCommit","uint32",84,4,SX_SIZE),
SX_FIELD("LoaderFlags","uint32",88,4,SX_FLAGS),
SX_FIELD("NumberOfRvaAndSizes","uint32",92,4,SX_COUNT_PROP),
};
static const sx_layout sxexo_overlay_pe_optional32={0x6088000fU,"overlay_pe_optional32",sxexo_overlay_pe_optional32_fields,SX_COUNT(sxexo_overlay_pe_optional32_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_pe_optional64_fields[]={
SX_FIELD("Magic","uint16",0,2,SX_ID),
SX_FIELD("MajorLinkerVersion","uint8",2,1,SX_NONE),
SX_FIELD("MinorLinkerVersion","uint8",3,1,SX_NONE),
SX_FIELD("SizeOfCode","uint32",4,4,SX_SIZE),
SX_FIELD("SizeOfInitializedData","uint32",8,4,SX_SIZE),
SX_FIELD("SizeOfUninitializedData","uint32",12,4,SX_SIZE),
SX_FIELD("AddressOfEntryPoint","uint32",16,4,SX_ADDRESS),
SX_FIELD("BaseOfCode","uint32",20,4,SX_ADDRESS),
SX_FIELD("ImageBase","uint64",24,8,SX_ADDRESS),
SX_FIELD("SectionAlignment","uint32",32,4,SX_SIZE),
SX_FIELD("FileAlignment","uint32",36,4,SX_SIZE),
SX_FIELD("MajorOperatingSystemVersion","uint16",40,2,SX_NONE),
SX_FIELD("MinorOperatingSystemVersion","uint16",42,2,SX_NONE),
SX_FIELD("MajorImageVersion","uint16",44,2,SX_NONE),
SX_FIELD("MinorImageVersion","uint16",46,2,SX_NONE),
SX_FIELD("MajorSubsystemVersion","uint16",48,2,SX_NONE),
SX_FIELD("MinorSubsystemVersion","uint16",50,2,SX_NONE),
SX_FIELD("Win32VersionValue","uint32",52,4,SX_RESERVED),
SX_FIELD("SizeOfImage","uint32",56,4,SX_SIZE),
SX_FIELD("SizeOfHeaders","uint32",60,4,SX_SIZE),
SX_FIELD("CheckSum","uint32",64,4,SX_CHECKSUM),
SX_FIELD("Subsystem","uint16",68,2,SX_ID),
SX_FIELD("DllCharacteristics","uint16",70,2,SX_FLAGS),
SX_FIELD("SizeOfStackReserve","uint64",72,8,SX_SIZE),
SX_FIELD("SizeOfStackCommit","uint64",80,8,SX_SIZE),
SX_FIELD("SizeOfHeapReserve","uint64",88,8,SX_SIZE),
SX_FIELD("SizeOfHeapCommit","uint64",96,8,SX_SIZE),
SX_FIELD("LoaderFlags","uint32",104,4,SX_FLAGS),
SX_FIELD("NumberOfRvaAndSizes","uint32",108,4,SX_COUNT_PROP),
};
static const sx_layout sxexo_overlay_pe_optional64={0x60880010U,"overlay_pe_optional64",sxexo_overlay_pe_optional64_fields,SX_COUNT(sxexo_overlay_pe_optional64_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_pe_directory_fields[]={
SX_FIELD("VirtualAddress","uint32",0,4,SX_ADDRESS),
SX_FIELD("Size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxexo_overlay_pe_directory={0x60880011U,"overlay_pe_directory",sxexo_overlay_pe_directory_fields,SX_COUNT(sxexo_overlay_pe_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_pe_security_directory_fields[]={
SX_FIELD("FileOffset","uint32",0,4,SX_OFFSET),
SX_FIELD("Size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxexo_overlay_pe_security_directory={0x60880012U,"overlay_pe_security_directory",sxexo_overlay_pe_security_directory_fields,SX_COUNT(sxexo_overlay_pe_security_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_pe_section_fields[]={
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
static const sx_layout sxexo_overlay_pe_section={0x60880013U,"overlay_pe_section",sxexo_overlay_pe_section_fields,SX_COUNT(sxexo_overlay_pe_section_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_ne_header_fields[]={
SX_FIELD("ne_magic","uint16",0,2,SX_ID),
SX_FIELD("ne_ver","uint8",2,1,SX_NONE),
SX_FIELD("ne_rev","uint8",3,1,SX_NONE),
SX_FIELD("ne_enttab","uint16",4,2,SX_OFFSET),
SX_FIELD("ne_cbenttab","uint16",6,2,SX_SIZE),
SX_FIELD("ne_crc","uint32",8,4,SX_CHECKSUM),
SX_FIELD("ne_flags","uint16",12,2,SX_FLAGS),
SX_FIELD("ne_autodata","uint16",14,2,SX_ID),
SX_FIELD("ne_heap","uint16",16,2,SX_SIZE),
SX_FIELD("ne_stack","uint16",18,2,SX_SIZE),
SX_FIELD("ne_csip","uint32",20,4,SX_ADDRESS),
SX_FIELD("ne_sssp","uint32",24,4,SX_ADDRESS),
SX_FIELD("ne_cseg","uint16",28,2,SX_COUNT_PROP),
SX_FIELD("ne_cmod","uint16",30,2,SX_COUNT_PROP),
SX_FIELD("ne_cbnrestab","uint16",32,2,SX_SIZE),
SX_FIELD("ne_segtab","uint16",34,2,SX_OFFSET),
SX_FIELD("ne_rsrctab","uint16",36,2,SX_OFFSET),
SX_FIELD("ne_restab","uint16",38,2,SX_OFFSET),
SX_FIELD("ne_modtab","uint16",40,2,SX_OFFSET),
SX_FIELD("ne_imptab","uint16",42,2,SX_OFFSET),
SX_FIELD("ne_nrestab","uint32",44,4,SX_OFFSET),
SX_FIELD("ne_cmovent","uint16",48,2,SX_COUNT_PROP),
SX_FIELD("ne_align","uint16",50,2,SX_NONE),
SX_FIELD("ne_cres","uint16",52,2,SX_COUNT_PROP),
SX_FIELD("ne_exetyp","uint8",54,1,SX_ID),
SX_FIELD("ne_flagsothers","uint8",55,1,SX_FLAGS),
SX_FIELD("ne_pretthunks","uint16",56,2,SX_OFFSET),
SX_FIELD("ne_psegrefbytes","uint16",58,2,SX_OFFSET),
SX_FIELD("ne_swaparea","uint16",60,2,SX_NONE),
SX_FIELD("ne_expver","uint16",62,2,SX_NONE),
};
static const sx_layout sxexo_overlay_ne_header={0x60880014U,"overlay_ne_header",sxexo_overlay_ne_header_fields,SX_COUNT(sxexo_overlay_ne_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_ne_segment_fields[]={
SX_FIELD("FileOffset","uint16",0,2,SX_OFFSET),
SX_FIELD("FileSize","uint16",2,2,SX_SIZE),
SX_FIELD("Flags","uint16",4,2,SX_FLAGS),
SX_FIELD("MinimumAllocation","uint16",6,2,SX_SIZE),
};
static const sx_layout sxexo_overlay_ne_segment={0x60880015U,"overlay_ne_segment",sxexo_overlay_ne_segment_fields,SX_COUNT(sxexo_overlay_ne_segment_fields),SX_LE};
static const sx_layout*const sx_executabletail_layouts[]={&sxexo_molebox_package_prefix,&sxexo_molebox_encrypted_tree,&sxexo_molebox_encrypted_header,&sxexo_molebox_encrypted_catalog,&sxexo_molebox_encrypted_catalog_footer,&sxexo_overlay_dos_header,&sxexo_overlay_dos_e_res,&sxexo_overlay_dos_e_oemid,&sxexo_overlay_dos_e_oeminfo,&sxexo_overlay_dos_e_res2,&sxexo_overlay_dos_e_lfanew,&sxexo_overlay_dos_relocation,&sxexo_overlay_pe_signature,&sxexo_overlay_coff_header,&sxexo_overlay_pe_optional32,&sxexo_overlay_pe_optional64,&sxexo_overlay_pe_directory,&sxexo_overlay_pe_security_directory,&sxexo_overlay_pe_section,&sxexo_overlay_ne_header,&sxexo_overlay_ne_segment};
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/molebox/xx_molebox.h"
#endif
static bool sx_executabletail_supports(xx_file_type_t type)
{
#if SX_ALIAS_READER_FACTORY
    return type==XX_FILE_TYPE_MOLEBOX||type==XX_FILE_TYPE_EXECUTABLE_OVERLAY;
#else
    (void)type;return false;
#endif
}
static int sxexo_order(const void*a,const void*b)
{const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxexo_finish(sx_context*c)
{
    size_t n=c->count;int64_t end=0;
    xx_rt_qsort(c->items,n,sizeof(*c->items),sxexo_order);
    for(size_t i=0;i<n;i++){
        int64_t off=c->items[i].offset-c->f->base_address,size=c->items[i].total_size;
        if(off<end||size<0||off>c->size||size>c->size-off)return false;
        if(off>end&&!sx_raw(c,end,off-end))return false;
        end=off+size;
    }
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
    xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxexo_order);
    return !c->failed;
}
#if SX_ALIAS_READER_FACTORY
static bool sxexo_cipher(sx_context*c,const sx_layout*l,int64_t absolute,int64_t size)
{
    if(absolute<c->f->base_address||size<=0)return false;
    /* Bound displayed byte arrays; remainder preserves its physical span raw. */
    return sx_add(c,l,absolute-c->f->base_address,size>4096?4096:size);
}
static bool sxexo_molebox(sx_context*c)
{
    xx_molebox_physical_metadata m;
    if(!xx_molebox_get_physical_metadata(c->f,0,&m,c->pd)||!m.package_count||m.package_count>64)return false;
    uint32_t count=m.package_count;
    if(m.catalog_offset>=0&&(!sxexo_cipher(c,&sxexo_molebox_encrypted_catalog,m.catalog_offset,m.catalog_size)||
       !sxexo_cipher(c,&sxexo_molebox_encrypted_catalog_footer,m.catalog_offset+m.catalog_size,8)))return false;
    for(uint32_t i=0;i<count;i++){
        if(!xx_molebox_get_physical_metadata(c->f,i,&m,c->pd)||m.package_count!=count)return false;
        if(m.has_verified_prefix&&!sx_add(c,&sxexo_molebox_package_prefix,m.package_offset-c->f->base_address,12))return false;
        if(!sxexo_cipher(c,&sxexo_molebox_encrypted_tree,m.tree_offset,m.tree_size)||
           !sxexo_cipher(c,&sxexo_molebox_encrypted_header,m.header_offset,48))return false;
    }
    return true;
}
static bool sxexo_within(int64_t size,int64_t at,uint64_t bytes)
{return at>=0&&at<=size&&bytes<=(uint64_t)(size-at);}
static bool sxexo_image(sx_context*c,int64_t at,int64_t size)
{
    uint8_t h[64],sig[4];uint32_t extended=0;bool windows=false;
    if(c->count>23000)return true;
    if(!sxexo_within(c->size,at,(uint64_t)size)||size<28||!sx_read(c,at,h,28)||
       !((h[0]=='M'&&h[1]=='Z')||(h[0]=='Z'&&h[1]=='M')))return false;
    if(size>=64){
        if(!sx_read(c,at+28,h+28,36))return false;
        extended=xx_data_get_u32(h,64,60,false);
        if(extended>=64&&sxexo_within(size,extended,4)){
            if(!sx_read(c,at+extended,sig,4))return false;
            windows=!xx_rt_memcmp(sig,"PE\0\0",4)||!xx_rt_memcmp(sig,"NE",2);
        }
    }
    if(!sx_add(c,&sxexo_overlay_dos_header,at,28))return false;
    uint16_t reloc=xx_data_get_u16(h,28,6,false),relat=xx_data_get_u16(h,28,24,false);
    bool reloc_valid=reloc&&relat>=28&&sxexo_within(size,relat,(uint64_t)reloc*4);
    uint64_t reloc_end=(uint64_t)relat+(uint64_t)reloc*4;
    if(windows){
        const sx_layout*fields[]={&sxexo_overlay_dos_e_res,&sxexo_overlay_dos_e_oemid,&sxexo_overlay_dos_e_oeminfo,&sxexo_overlay_dos_e_res2,&sxexo_overlay_dos_e_lfanew};
        const uint8_t offsets[]={28,36,38,40,60},sizes[]={8,2,2,20,4};
        for(size_t i=0;i<SX_COUNT(fields);i++){
            bool overlaps=reloc_valid&&relat<(unsigned)offsets[i]+sizes[i]&&reloc_end>offsets[i];
            if(!overlaps&&!sx_add(c,fields[i],at+offsets[i],sizes[i]))return false;
        }
    }
    /* Actual early DOS relocation slots take precedence over the extended
     * DOS reserved/OEM interpretation. If a table reaches a Windows header,
     * preserve that primary header view and leave the conflicting prefix raw. */
    if(reloc_valid&&(!windows||reloc_end<=extended)&&!sx_table(c,&sxexo_overlay_dos_relocation,at+relat,4,reloc))return false;
    if(!windows)return true;
    if(!xx_rt_memcmp(sig,"NE",2)){
        uint8_t ne[64];if(!sxexo_within(size,extended,64)||!sx_read(c,at+extended,ne,64)||!sx_add(c,&sxexo_overlay_ne_header,at+extended,64))return false;
        uint16_t count=xx_data_get_u16(ne,64,28,false),offset=xx_data_get_u16(ne,64,34,false);
        if(count&&offset>=64&&sxexo_within(size,(int64_t)extended+offset,(uint64_t)count*8))return sx_table(c,&sxexo_overlay_ne_segment,at+extended+offset,8,count);
        return true;
    }
    uint8_t pe[24],op[112];if(!sxexo_within(size,extended,24)||!sx_read(c,at+extended,pe,24))return false;
    uint16_t count=xx_data_get_u16(pe,24,6,false),optional=xx_data_get_u16(pe,24,20,false);int64_t opt=(int64_t)extended+24;
    if(optional<96||!sxexo_within(size,opt,optional)||!sx_read(c,at+opt,op,96))return false;
    uint16_t magic=xx_data_get_u16(op,96,0,false);int64_t prefix=magic==0x20b?112:96;
    if((magic!=0x10b&&magic!=0x20b)||optional<prefix||(prefix==112&&!sx_read(c,at+opt,op,112)))return false;
    uint32_t dirs=xx_data_get_u32(op,(size_t)prefix,(size_t)prefix-4,false);
    if(dirs>16||(uint64_t)dirs*8>(uint64_t)(optional-prefix)||!sxexo_within(size,opt+optional,(uint64_t)count*40))return false;
    if(!sx_add(c,&sxexo_overlay_pe_signature,at+extended,4)||!sx_add(c,&sxexo_overlay_coff_header,at+extended+4,20)||
       !sx_add(c,magic==0x20b?&sxexo_overlay_pe_optional64:&sxexo_overlay_pe_optional32,at+opt,prefix))return false;
    for(uint32_t i=0;i<dirs;i++)if(!sx_add(c,i==4?&sxexo_overlay_pe_security_directory:&sxexo_overlay_pe_directory,at+opt+prefix+(int64_t)i*8,8))return false;
    return !count||sx_table(c,&sxexo_overlay_pe_section,at+opt+optional,40,count);
}
static bool sxexo_overlay(sx_context*c)
{
    xx_archive_record_state*s=xx_format_create_archive_records_reading(c->f,NULL,c->pd);bool ok=true,first=true;
    if(!s)return false;
    do{
        const xx_archive_record*r=xx_format_get_current_archive_record(c->f,s);
        if(!r)break;
        int64_t off=r->data_offset-c->f->base_address,size=r->compressed_size;
        const char*name=xx_archive_record_get_original_name(r);
        if(off<0||size<0||!sxexo_within(c->size,off,(uint64_t)size)){ok=false;break;}
        if(first){first=false;if(!sxexo_image(c,0,off)){ok=false;break;}}
        /* The stored native iterator supplies authenticated image extents.
         * Padding and opaque terminal overlays have no invented headers. */
        if(name&&(xx_rt_strstr(name,"-dos-image.exe")||xx_rt_strstr(name,"-pe-image.exe")||xx_rt_strstr(name,"-ne-image.exe")))
            if(!sxexo_image(c,off,size)){ok=false;break;}
    }while(xx_format_archive_record_move_to_next(c->f,s,c->pd));
    xx_format_free_archive_records_reading(c->f,s);return ok&&!first;
}
#endif
static bool sx_executabletail_build(sx_context*c)
{
#if SX_ALIAS_READER_FACTORY
    if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    bool ok=c->f->file_type==XX_FILE_TYPE_MOLEBOX?sxexo_molebox(c):c->f->file_type==XX_FILE_TYPE_EXECUTABLE_OVERLAY?sxexo_overlay(c):false;
    return ok&&c->count&&sxexo_finish(c);
#else
    (void)c;return false;
#endif
}
static bool sx_executabletail_comment(xx_data_struct_record*r,uint32_t id)
{
    if(!r||!r->name||id<0x60880001U||id>0x6088ffffU)return true;
    if(!xx_rt_wcscmp(r->name,L"ciphertext"))return xx_data_struct_record_set_comment(r,L"Encrypted physical metadata bytes; plaintext fields have no source-file offsets here. At most 4096 bytes are displayed; any remaining ciphertext stays raw.");
    if(!xx_rt_wcscmp(r->name,L"encrypted_signature"))return xx_data_struct_record_set_comment(r,L"Blowfish-encrypted QUICKBOX signature, verified using the native package key.");
    if(!xx_rt_wcscmp(r->name,L"stored_package_base"))return xx_data_struct_record_set_comment(r,L"Package base as stored by the original writer, relative to the input file start.");
    if(id==sxexo_overlay_dos_header.id){
        if(!xx_rt_wcscmp(r->name,L"e_cblp"))return xx_data_struct_record_set_comment(r,L"Bytes in final 512-byte page; 0 means 512.");
        if(!xx_rt_wcscmp(r->name,L"e_cp"))return xx_data_struct_record_set_comment(r,L"512-byte pages.");
        if(!xx_rt_wcscmp(r->name,L"e_cparhdr")||!xx_rt_wcscmp(r->name,L"e_minalloc")||!xx_rt_wcscmp(r->name,L"e_maxalloc"))return xx_data_struct_record_set_comment(r,L"16-byte paragraphs.");
    }
    if(id==sxexo_overlay_ne_segment.id){
        if(!xx_rt_wcscmp(r->name,L"FileOffset"))return xx_data_struct_record_set_comment(r,L"Logical sectors; scale by 2^ne_align. Zero means no physical segment data.");
        if(!xx_rt_wcscmp(r->name,L"FileSize")||!xx_rt_wcscmp(r->name,L"MinimumAllocation"))return xx_data_struct_record_set_comment(r,L"Size in bytes; encoded zero means 65536 bytes.");
    }
    if(id==sxexo_overlay_ne_header.id&&!xx_rt_wcscmp(r->name,L"ne_align"))return xx_data_struct_record_set_comment(r,L"Logical-sector alignment shift count.");
    if(r->property&(SX_OFFSET|SX_ADDRESS))return xx_data_struct_record_set_comment(r,L"Encoded address or offset within this executable image; source byte position is shown separately.");
    return true;
}

