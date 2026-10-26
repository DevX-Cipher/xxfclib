/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MoleBox data structures, moved out of the executabletail schema family. */
#include "../../xx_format_schema_executabletail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/executable/molebox/xx_molebox.h"
#endif

static const xx_data_struct_field_desc sxexo_molebox_package_prefix_fields[]={
SX_FIELD("encrypted_signature","uint8[8]",0,8,SX_NONE),
SX_FIELD("stored_package_base","uint32",8,4,SX_OFFSET),
};
const sx_layout sxexo_molebox_package_prefix={0x60880001U,"molebox_package_prefix",sxexo_molebox_package_prefix_fields,SX_COUNT(sxexo_molebox_package_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_molebox_encrypted_tree_fields[]={
SX_FIELD("ciphertext","uint8",0,0,SX_NONE),
};
const sx_layout sxexo_molebox_encrypted_tree={0x60880002U,"molebox_encrypted_tree",sxexo_molebox_encrypted_tree_fields,SX_COUNT(sxexo_molebox_encrypted_tree_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_molebox_encrypted_header_fields[]={
SX_FIELD("ciphertext","uint8[48]",0,48,SX_NONE),
};
const sx_layout sxexo_molebox_encrypted_header={0x60880003U,"molebox_encrypted_header",sxexo_molebox_encrypted_header_fields,SX_COUNT(sxexo_molebox_encrypted_header_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_molebox_encrypted_catalog_fields[]={
SX_FIELD("ciphertext","uint8",0,0,SX_NONE),
};
const sx_layout sxexo_molebox_encrypted_catalog={0x60880004U,"molebox_encrypted_catalog",sxexo_molebox_encrypted_catalog_fields,SX_COUNT(sxexo_molebox_encrypted_catalog_fields),SX_LE};
static const xx_data_struct_field_desc sxexo_molebox_encrypted_catalog_footer_fields[]={
SX_FIELD("ciphertext","uint8[8]",0,8,SX_NONE),
};
const sx_layout sxexo_molebox_encrypted_catalog_footer={0x60880005U,"molebox_encrypted_catalog_footer",sxexo_molebox_encrypted_catalog_footer_fields,SX_COUNT(sxexo_molebox_encrypted_catalog_footer_fields),SX_LE};
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
#endif
bool sx_molebox_build(sx_context*c)
{
#if SX_ALIAS_READER_FACTORY
    return sxexo_molebox(c);
#else
    (void)c;return false;
#endif
}
