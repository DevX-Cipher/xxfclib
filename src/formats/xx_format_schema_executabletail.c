/* SPDX-License-Identifier: MIT
 * Partial physical executable metadata; encrypted regions stay ciphertext. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_executabletail.h"
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
const sx_layout sxexo_overlay_dos_header={0x60880006U,"overlay_dos_header",sxexo_overlay_dos_header_fields,SX_COUNT(sxexo_overlay_dos_header_fields),SX_LE};
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
const sx_layout sxexo_overlay_ne_header={0x60880014U,"overlay_ne_header",sxexo_overlay_ne_header_fields,SX_COUNT(sxexo_overlay_ne_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_overlay_ne_segment_fields[]={
SX_FIELD("FileOffset","uint16",0,2,SX_OFFSET),
SX_FIELD("FileSize","uint16",2,2,SX_SIZE),
SX_FIELD("Flags","uint16",4,2,SX_FLAGS),
SX_FIELD("MinimumAllocation","uint16",6,2,SX_SIZE),
};
const sx_layout sxexo_overlay_ne_segment={0x60880015U,"overlay_ne_segment",sxexo_overlay_ne_segment_fields,SX_COUNT(sxexo_overlay_ne_segment_fields),SX_LE};
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
static bool sx_executabletail_build(sx_context*c)
{
#if SX_ALIAS_READER_FACTORY
    if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    bool ok=c->f->file_type==XX_FILE_TYPE_MOLEBOX?sx_molebox_build(c):c->f->file_type==XX_FILE_TYPE_EXECUTABLE_OVERLAY?sx_executable_overlay_build(c):false;
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
const sx_family sx_executabletail_family={sx_executabletail_supports,sx_executabletail_build,sx_executabletail_layouts,SX_COUNT(sx_executabletail_layouts),sx_executabletail_comment};
