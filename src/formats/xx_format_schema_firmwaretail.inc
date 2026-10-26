/* SPDX-License-Identifier: MIT
 * Authenticated physical firmware prefixes. These formats have no generic
 * length-bearing header; unclassified image bodies remain raw. */
static const xx_data_struct_field_desc sxftl_ecos_exception_prefix_le_fields[]={
 SX_FIELD("cause_instruction","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("mask_instruction","uint32",4,4,SX_SIGNATURE),
};
static const sx_layout sxftl_ecos_exception_prefix_le={0x60860001U,"ecos_exception_prefix_le",sxftl_ecos_exception_prefix_le_fields,SX_COUNT(sxftl_ecos_exception_prefix_le_fields),SX_LE};
static const xx_data_struct_field_desc sxftl_ecos_exception_prefix_le_nop_fields[]={
 SX_FIELD("cause_instruction","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("nop_instruction","uint32",4,4,SX_NONE),
 SX_FIELD("mask_instruction","uint32",8,4,SX_SIGNATURE),
};
static const sx_layout sxftl_ecos_exception_prefix_le_nop={0x60860002U,"ecos_exception_prefix_le_nop",sxftl_ecos_exception_prefix_le_nop_fields,SX_COUNT(sxftl_ecos_exception_prefix_le_nop_fields),SX_LE};
static const xx_data_struct_field_desc sxftl_ecos_exception_prefix_be_fields[]={
 SX_FIELD("cause_instruction","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("mask_instruction","uint32",4,4,SX_SIGNATURE),
};
static const sx_layout sxftl_ecos_exception_prefix_be={0x60860003U,"ecos_exception_prefix_be",sxftl_ecos_exception_prefix_be_fields,SX_COUNT(sxftl_ecos_exception_prefix_be_fields),SX_BE};
static const xx_data_struct_field_desc sxftl_ecos_exception_prefix_be_nop_fields[]={
 SX_FIELD("cause_instruction","uint32",0,4,SX_SIGNATURE),
 SX_FIELD("nop_instruction","uint32",4,4,SX_NONE),
 SX_FIELD("mask_instruction","uint32",8,4,SX_SIGNATURE),
};
static const sx_layout sxftl_ecos_exception_prefix_be_nop={0x60860004U,"ecos_exception_prefix_be_nop",sxftl_ecos_exception_prefix_be_nop_fields,SX_COUNT(sxftl_ecos_exception_prefix_be_nop_fields),SX_BE};
static const sx_layout*const sx_firmwaretail_layouts[]={&sxftl_ecos_exception_prefix_le,&sxftl_ecos_exception_prefix_le_nop,&sxftl_ecos_exception_prefix_be,&sxftl_ecos_exception_prefix_be_nop};
static bool sx_firmwaretail_supports(xx_file_type_t type)
{return type==XX_FILE_TYPE_ECOS;}
static bool sx_firmwaretail_build(sx_context*c)
{
    uint8_t h[12];const sx_layout*l=NULL;int64_t size=0;
    if(!c||!c->f||!sx_firmwaretail_supports(c->f->file_type)||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    if(c->f->file_type==XX_FILE_TYPE_ECOS){
        static const uint8_t prefixes[4][12]={
            {0x00,0x68,0x1a,0x40,0x00,0x00,0x00,0x00,0x7f,0x00,0x5a,0x33},
            {0x40,0x1a,0x68,0x00,0x00,0x00,0x00,0x00,0x33,0x5a,0x00,0x7f},
            {0x00,0x68,0x1a,0x40,0x7f,0x00,0x5a,0x33},
            {0x40,0x1a,0x68,0x00,0x33,0x5a,0x00,0x7f}};
        const sx_layout*layouts[]={&sxftl_ecos_exception_prefix_le_nop,&sxftl_ecos_exception_prefix_be_nop,&sxftl_ecos_exception_prefix_le,&sxftl_ecos_exception_prefix_be};
        for(size_t i=0;i<4;i++){size=i<2?12:8;if(c->size>=size&&sx_read(c,0,h,(size_t)size)&&!xx_rt_memcmp(h,prefixes[i],(size_t)size)){l=layouts[i];break;}}
    }

    return l&&sx_add(c,l,0,size)&&sx_raw(c,size,c->size-size);
}
static bool sx_firmwaretail_comment(xx_data_struct_record*r,uint32_t id)
{
    if(!r||!r->name||id<0x60860001U||id>0x60860004U)return true;
    if(!xx_rt_wcscmp(r->name,L"cause_instruction"))return xx_data_struct_record_set_comment(r,L"MIPS mfc0 $k0, Cause instruction word; not an address or image length.");
    if(!xx_rt_wcscmp(r->name,L"nop_instruction"))return xx_data_struct_record_set_comment(r,L"Optional MIPS nop instruction.");
    if(!xx_rt_wcscmp(r->name,L"mask_instruction"))return xx_data_struct_record_set_comment(r,L"MIPS andi $k0, $k0, 0x7F instruction word.");

    return true;
}
