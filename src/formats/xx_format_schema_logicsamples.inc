/* SPDX-License-Identifier: MIT. Original physical filesystem metadata. */
static const xx_data_struct_field_desc sxlogic_logic_signal_sample_fields[]={
 SX_FIELD("channel_levels","uint8",0,1,SX_FLAGS),
};
static const sx_layout sxlogic_logic_signal_sample={0x60a00001U,"logic_signal_sample",sxlogic_logic_signal_sample_fields,SX_COUNT(sxlogic_logic_signal_sample_fields),SX_LE};
static const sx_layout*const sx_logicsamples_layouts[]={&sxlogic_logic_signal_sample};
static bool sx_logicsamples_supports(xx_file_type_t type)
{return type==XX_FILE_TYPE_HXC_LOGIC_ANALYZER;}
static bool sx_logicsamples_build(sx_context*c)
{
 if(!c||!c->f||!sx_logicsamples_supports(c->f->file_type)||c->size<=0||c->size>64*1024*1024)return false;
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 return sx_table(c,&sxlogic_logic_signal_sample,0,1,(uint64_t)c->size);
}
static bool sx_logicsamples_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id!=0x60a00001U||r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
 if(xx_rt_wcscmp(r->name,L"channel_levels"))return true;
 uint64_t value=xx_var_get_u64(&r->value);wchar_t text[192];size_t n=0;
 if(!value)return xx_data_struct_record_set_comment(r,L"ALL_CHANNELS_LOW. Sample rate and signal assignments are external settings.");
 for(unsigned bit=0;bit<8;bit++)if(value&(UINT64_C(1)<<bit)){
  if(n)text[n++]=L'|';
  const wchar_t*prefix=L"CH";while(*prefix)text[n++]=*prefix++;
  text[n++]=(wchar_t)(L'0'+bit);const wchar_t*suffix=L"_HIGH";while(*suffix)text[n++]=*suffix++;
 }
 const wchar_t*tail=L". Sample rate and signal assignments are external settings.";
 while(*tail&&n<SX_COUNT(text)-1)text[n++]=*tail++;text[n]=0;
 return xx_data_struct_record_set_comment(r,text);
}
