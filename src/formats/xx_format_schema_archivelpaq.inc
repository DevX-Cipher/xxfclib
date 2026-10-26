/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * LPAQ serialized headers. The independent optional GPL codec executable is
 * required by the native readers; no codec code is linked into this schema.
 * Wire source: Matt Mahoney lpaq1.cpp and Alexander Ratushnyak lpaq5/lpaq8.cpp,
 * original compression header writers. Entropy-coded data remains raw.
 */
static const xx_data_struct_field_desc sxlpaq_header_fields[] = {
    SX_FIELD("magic", "uint8[2]", 0, 2, SX_SIGNATURE),
    SX_FIELD("revision", "uint8", 2, 1, SX_ID),
    SX_FIELD("memory_level", "ascii_decimal[1]", 3, 1, SX_NONE),
    SX_FIELD("uncompressed_size", "uint32", 4, 4, SX_SIZE)
};
static const xx_data_struct_field_desc sxlpaq_header8_fields[] = {
    SX_FIELD("magic", "uint8[2]", 0, 2, SX_SIGNATURE),
    SX_FIELD("revision", "uint8", 2, 1, SX_ID),
    SX_FIELD("memory_level", "ascii_decimal[1]", 3, 1, SX_NONE),
    SX_FIELD("uncompressed_size", "uint32", 4, 4, SX_SIZE),
    SX_FIELD("data_mode", "uint8", 8, 1, SX_ID)
};
static const sx_layout sxlpaq_header = {0x60830001u, "lpaq_header", sxlpaq_header_fields, SX_COUNT(sxlpaq_header_fields), SX_BE};
static const sx_layout sxlpaq_header8 = {0x60830002u, "lpaq8_header", sxlpaq_header8_fields, SX_COUNT(sxlpaq_header8_fields), SX_BE};
static const sx_layout *const sx_archivelpaq_layouts[] = {&sxlpaq_header, &sxlpaq_header8};

static bool sx_archivelpaq_supports(xx_file_type_t type)
{
    switch(type) {
    case XX_FILE_TYPE_LPAQ1: case XX_FILE_TYPE_LPAQ5: case XX_FILE_TYPE_LPAQ8: return true;
    default: return false;
    }
}
static bool sx_archivelpaq_build(sx_context *c)
{
    uint8_t h[9]; unsigned revision, width;
    if(!c || !c->f || !sx_archivelpaq_supports(c->f->file_type))return false;
    revision=c->f->file_type==XX_FILE_TYPE_LPAQ1?1:c->f->file_type==XX_FILE_TYPE_LPAQ5?5:8;
    width=revision==8?9:8;
    if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    if(c->size<(int64_t)width+1 || !sx_read(c,0,h,width) || h[0]!='p' || h[1]!='Q' || h[2]!=revision || h[3]<'0' || h[3]>'9' || (revision==8&&h[8]>2))return false;
    return sx_add(c,revision==8?&sxlpaq_header8:&sxlpaq_header,0,width) && sx_raw(c,width,c->size-width);
}
static bool sx_archivelpaq_comment(xx_data_struct_record *r,uint32_t id)
{
    const wchar_t *comment=NULL; uint64_t value;
    if(id!=sxlpaq_header.id&&id!=sxlpaq_header8.id)return true;
    if(!r||!r->name)return false;
    if(r->value.type<XX_VAR_TYPE_INT8||r->value.type>XX_VAR_TYPE_UINT64)return true;
    if(!xx_rt_wcscmp(r->name,L"memory_level")) {
        /* Keep the shared decoder diagnostic for manually requested corrupt fields. */
        if(r->value.type!=XX_VAR_TYPE_UINT64)return true;
        comment=L"ASCII memory option 0..9; model memory scales as 2^level. This is an option, not a byte count.";
    }
    else if(!xx_rt_wcscmp(r->name,L"revision")) {
        value=xx_var_get_u64(&r->value);
        comment=value==1?L"LPAQ1":value==5?L"LPAQ5":value==8?L"LPAQ8":L"Unknown LPAQ revision";
    } else if(!xx_rt_wcscmp(r->name,L"data_mode")) {
        value=xx_var_get_u64(&r->value);
        comment=value==0?L"DEFAULT (binary model)":value==1?L"TEXT (text model)":value==2?L"EXE (executable transform)":L"Unknown data mode";
    }
    return !comment||xx_data_struct_record_set_comment(r,comment);
}
