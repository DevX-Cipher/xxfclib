/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Microsoft CHM data structures, moved out of the package schema family. */
#include "../../xx_format_schema_package.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sx_p_chm_itsp_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("version", "uint32", 4, 4, SX_NONE),
    SX_FIELD("header_size", "uint32", 8, 4, SX_SIZE),
    SX_FIELD("unknown_0", "uint32", 12, 4, SX_NONE),
    SX_FIELD("chunk_size", "uint32", 16, 4, SX_SIZE),
    SX_FIELD("density", "uint32", 20, 4, SX_NONE),
    SX_FIELD("tree_depth", "uint32", 24, 4, SX_COUNT_PROP),
    SX_FIELD("root_index", "int32", 28, 4, SX_ID),
    SX_FIELD("first_pmgl", "int32", 32, 4, SX_ID),
    SX_FIELD("last_pmgl", "int32", 36, 4, SX_ID),
    SX_FIELD("unknown_1", "int32", 40, 4, SX_NONE),
    SX_FIELD("chunk_count", "uint32", 44, 4, SX_COUNT_PROP),
    SX_FIELD("language_id", "uint32", 48, 4, SX_ID),
    SX_FIELD("guid", "bytes", 52, 16, SX_ID),
    SX_FIELD("header_size_again", "uint32", 68, 4, SX_SIZE),
    SX_FIELD("unknown_2", "bytes", 72, 12, SX_NONE),
};
const sx_layout sx_p_chm_itsp = { UINT32_C(0x60070031), "chm_itsp", sx_p_chm_itsp_fields, SX_COUNT(sx_p_chm_itsp_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_chm_pmgl_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("free_space", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("unknown", "uint32", 8, 4, SX_NONE),
    SX_FIELD("previous", "int32", 12, 4, SX_ID),
    SX_FIELD("next", "int32", 16, 4, SX_ID),
};
const sx_layout sx_p_chm_pmgl = { UINT32_C(0x60070032), "chm_pmgl", sx_p_chm_pmgl_fields, SX_COUNT(sx_p_chm_pmgl_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_chm_pmgi_fields[] = {
    SX_FIELD("signature", "char[4]", 0, 4, SX_SIGNATURE),
    SX_FIELD("free_space", "uint32", 4, 4, SX_SIZE),
};
const sx_layout sx_p_chm_pmgi = { UINT32_C(0x60070033), "chm_pmgi", sx_p_chm_pmgi_fields, SX_COUNT(sx_p_chm_pmgi_fields), SX_LE };
static const xx_data_struct_field_desc sx_p_chm_section0_fields[] = {
    SX_FIELD("magic", "uint32", 0, 4, SX_SIGNATURE),
    SX_FIELD("unknown", "uint32", 4, 4, SX_NONE),
    SX_FIELD("file_size", "uint64", 8, 8, SX_SIZE),
    SX_FIELD("unknown_tail", "bytes", 16, 8, SX_NONE),
};
const sx_layout sx_p_chm_section0 = { UINT32_C(0x60070034), "chm_section0", sx_p_chm_section0_fields, SX_COUNT(sx_p_chm_section0_fields), SX_LE };
static bool sx_p_chm(sx_context *c)
{
    uint32_t v,hs,chunk,count;uint64_t section,section_size,dir,dir_size;
    if(!sx_p_sig(c,0,"ITSF",4)||!sx_u32(c,4,false,&v)||(v!=2&&v!=3)||!sx_u32(c,8,false,&hs)||hs!=(v==3?96:88)||!sx_add(c,v==3?&sx_p_chm_itsf3:&sx_p_chm_itsf2,0,hs)||!sx_u64(c,56,false,&section)||!sx_u64(c,64,false,&section_size)||section_size<24||!sx_p_span(c,section,section_size)||!sx_add(c,&sx_p_chm_section0,(int64_t)section,24)||!sx_u64(c,72,false,&dir)||!sx_u64(c,80,false,&dir_size)||dir_size<84||!sx_p_span(c,dir,dir_size)||!sx_p_sig(c,dir,"ITSP",4)||!sx_u32(c,dir+16,false,&chunk)||chunk<20||!sx_u32(c,dir+44,false,&count)||(uint64_t)count*chunk>dir_size-84||!sx_add(c,&sx_p_chm_itsp,dir,84))return false;
    int64_t off=(int64_t)dir+84;for(uint32_t i=0;i<count;i++,off+=chunk){uint32_t free;if(!sx_u32(c,off+4,false,&free)||free>chunk)return false;if(sx_p_sig(c,off,"PMGL",4)){if(free>chunk-20||!sx_add(c,&sx_p_chm_pmgl,off,20))return false;}else if(sx_p_sig(c,off,"PMGI",4)){if(free>chunk-8||!sx_add(c,&sx_p_chm_pmgi,off,8))return false;}else return false;}return true;
}
bool sx_chm_build(sx_context*c)
{
    return sx_p_chm(c);
}
