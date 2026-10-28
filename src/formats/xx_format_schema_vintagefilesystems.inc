/* SPDX-License-Identifier: MIT. Original physical filesystem metadata. */
static const xx_data_struct_field_desc sxvintage_thomson_volume_header_fields[]={
 SX_FIELD("volume_name","char[8]",0,8,SX_NONE),
 SX_FIELD("unknown_volume_bytes","uint8[248]",8,248,SX_NONE),
};
static const sx_layout sxvintage_thomson_volume_header={0x609d0001U,"thomson_volume_header",sxvintage_thomson_volume_header_fields,SX_COUNT(sxvintage_thomson_volume_header_fields),SX_BE};
static const xx_data_struct_field_desc sxvintage_thomson_fat_prefix_fields[]={
 SX_FIELD("reserved_zero","uint8",0,1,SX_NONE),
};
static const sx_layout sxvintage_thomson_fat_prefix={0x609d0002U,"thomson_fat_prefix",sxvintage_thomson_fat_prefix_fields,SX_COUNT(sxvintage_thomson_fat_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxvintage_thomson_fat_entry_fields[]={
 SX_FIELD("allocation_value","uint8",0,1,SX_NONE),
};
static const sx_layout sxvintage_thomson_fat_entry={0x609d0003U,"thomson_fat_entry",sxvintage_thomson_fat_entry_fields,SX_COUNT(sxvintage_thomson_fat_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxvintage_thomson_directory_entry_fields[]={
 SX_FIELD("filename","char[8]",0,8,SX_NONE),
 SX_FIELD("extension","char[3]",8,3,SX_NONE),
 SX_FIELD("file_type","uint8",11,1,SX_ID),
 SX_FIELD("format_flag","uint8",12,1,SX_FLAGS),
 SX_FIELD("first_block","uint8",13,1,SX_ID),
 SX_FIELD("last_sector_bytes","uint16",14,2,SX_SIZE),
 SX_FIELD("comment","char[8]",16,8,SX_NONE),
 SX_FIELD("day","uint8",24,1,SX_NONE),
 SX_FIELD("month","uint8",25,1,SX_NONE),
 SX_FIELD("year","uint8",26,1,SX_NONE),
 SX_FIELD("unknown_tail","uint8[5]",27,5,SX_NONE),
};
static const sx_layout sxvintage_thomson_directory_entry={0x609d0004U,"thomson_directory_entry",sxvintage_thomson_directory_entry_fields,SX_COUNT(sxvintage_thomson_directory_entry_fields),SX_BE};
static const xx_data_struct_field_desc sxvintage_thomson_directory_state_fields[]={
 SX_FIELD("entry_state","uint8",0,1,SX_NONE),
};
static const sx_layout sxvintage_thomson_directory_state={0x609d0005U,"thomson_directory_state",sxvintage_thomson_directory_state_fields,SX_COUNT(sxvintage_thomson_directory_state_fields),SX_BE};
static const xx_data_struct_field_desc sxvintage_northstar_directory_entry_fields[]={
 SX_FIELD("filename","char[8]",0,8,SX_NONE),
 SX_FIELD("disk_address","uint16",8,2,SX_ID),
 SX_FIELD("stored_length","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("type_density","uint8",12,1,SX_FLAGS),
 SX_FIELD("opaque_type_data","uint8[3]",13,3,SX_NONE),
};
static const sx_layout sxvintage_northstar_directory_entry={0x609d0006U,"northstar_directory_entry",sxvintage_northstar_directory_entry_fields,SX_COUNT(sxvintage_northstar_directory_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxvintage_northstar_executable_entry_fields[]={
 SX_FIELD("filename","char[8]",0,8,SX_NONE),
 SX_FIELD("disk_address","uint16",8,2,SX_ID),
 SX_FIELD("stored_length","uint16",10,2,SX_COUNT_PROP),
 SX_FIELD("type_density","uint8",12,1,SX_FLAGS),
 SX_FIELD("go_address","uint16",13,2,SX_ADDRESS),
 SX_FIELD("unknown_tail","uint8",15,1,SX_NONE),
};
static const sx_layout sxvintage_northstar_executable_entry={0x609d0007U,"northstar_executable_entry",sxvintage_northstar_executable_entry_fields,SX_COUNT(sxvintage_northstar_executable_entry_fields),SX_LE};
static const sx_layout*const sx_vintagefilesystems_layouts[]={&sxvintage_thomson_volume_header,&sxvintage_thomson_fat_prefix,&sxvintage_thomson_fat_entry,&sxvintage_thomson_directory_entry,&sxvintage_thomson_directory_state,&sxvintage_northstar_directory_entry,&sxvintage_northstar_executable_entry};
static bool sx_vintagefilesystems_supports(xx_file_type_t type)
{return type==XX_FILE_TYPE_THOMSON_FD||type==XX_FILE_TYPE_NORTHSTAR_NSI;}
static bool sxvintage_span(sx_context*c,uint64_t at,uint64_t size)
{return c&&c->size>=0&&at<=(uint64_t)c->size&&size<=(uint64_t)c->size-at&&!xx_pd_is_stopped(c->pd);}
static bool sxvintage_thomson_side(sx_context*c,uint64_t origin,bool*accepted)
{
 uint8_t volume[256],fat[256],directory[3584];uint64_t at=origin+20*4096;unsigned blocks=80,entries=0;
 *accepted=false;
 if(!sxvintage_span(c,at,4096))return true;
 if(!sx_read(c,(int64_t)at,volume,256)||!sx_read(c,(int64_t)at+256,fat,256)||!sx_read(c,(int64_t)at+512,directory,sizeof(directory)))return false;
 for(unsigned i=0;i<8;i++)if(volume[i]<32||volume[i]>127)return true;
 if(fat[0]||!(fat[41]==254||fat[41]==251)||!(fat[42]==254||fat[42]==251))return true;
 for(unsigned i=81;i<256;i++)if(fat[i]){blocks=160;break;}
 if(!sxvintage_span(c,origin,(uint64_t)blocks*2048))return true;
 for(unsigned i=blocks+1;i<256;i++)if(fat[i])return true;
 for(unsigned i=1;i<=blocks;i++)if(!(fat[i]<blocks||(fat[i]>=193&&fat[i]<=200)||fat[i]==251||fat[i]==254||fat[i]==255))return true;
 for(;entries<112;entries++){
  const uint8_t*d=directory+entries*32;
  if(d[0]==255){entries++;break;}
  if(!d[0])continue;
  for(unsigned i=0;i<11;i++)if(d[i]<32||d[i]>127)return true;
  if(d[11]>3||(d[12]!=0&&d[12]!=255)||d[13]>=blocks||d[14])return true;
 }
 if(!sx_add(c,&sxvintage_thomson_volume_header,(int64_t)at,256)||
    !sx_add(c,&sxvintage_thomson_fat_prefix,(int64_t)at+256,1)||
    !sx_table(c,&sxvintage_thomson_fat_entry,(int64_t)at+257,1,blocks))return false;
 for(unsigned i=0;i<entries;i++){
  const uint8_t*d=directory+i*32;
  const sx_layout*l=(d[0]==0||d[0]==255)?&sxvintage_thomson_directory_state:&sxvintage_thomson_directory_entry;
  if(!sx_add(c,l,(int64_t)at+512+i*32,l==&sxvintage_thomson_directory_state?1:32))return false;
 }
 *accepted=true;return true;
}
static bool sxvintage_northstar(sx_context*c)
{
 uint8_t directory[2048];unsigned used=0;uint64_t sectors;
 if(c->size!=179200&&c->size!=358400)return false;
 sectors=(uint64_t)c->size/512;
 if(!sx_read(c,0,directory,sizeof(directory)))return false;
 for(unsigned i=0;i<128;i++){
  const uint8_t*d=directory+i*16;
  if(d[0]==' ')continue;
  for(unsigned j=0;j<8;j++)if(d[j]<32||d[j]>=127||d[j]==',')return false;
  uint64_t at=(uint64_t)d[8]+((uint64_t)d[9]<<8),length=(uint64_t)d[10]+((uint64_t)d[11]<<8);
  if(!(d[12]&128)||at>=sectors||length>sectors-at)return false;
  used++;
 }
 if(!used)return false;
 for(unsigned i=0;i<128;i++){
  const uint8_t*d=directory+i*16;
  if(d[0]==' ')continue;
  const sx_layout*l=(d[12]&127)==1?&sxvintage_northstar_executable_entry:&sxvintage_northstar_directory_entry;
  if(!sx_add(c,l,i*16,16))return false;
 }
 return true;
}
static int sxvintage_compare(const void*a,const void*b)
{const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxvintage_finish(sx_context*c)
{
 size_t count=c->count;int64_t end=0;xx_rt_qsort(c->items,count,sizeof(*c->items),sxvintage_compare);
 for(size_t i=0;i<count;i++){
  int64_t at=c->items[i].offset-c->f->base_address,size=c->items[i].total_size;
  if(at<end||size<=0||at>c->size||size>c->size-at)return false;
  if(at>end&&!sx_raw(c,end,at-end))return false;
  end=at+size;
 }
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;
 xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxvintage_compare);
 return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_vintagefilesystems_build(sx_context*c)
{
 if(!c||!c->f||!sx_vintagefilesystems_supports(c->f->file_type))return false;
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 if(c->f->file_type==XX_FILE_TYPE_NORTHSTAR_NSI){
  if(c->size!=89600&&c->size!=179200&&c->size!=358400)return false;
  if(sxvintage_northstar(c))return sxvintage_finish(c);
  if(c->failed||c->count||xx_pd_is_stopped(c->pd))return false;
  return sx_raw(c,0,c->size);
 }
 if(c->size!=327680&&c->size!=655360)return false;
 bool first=false,second=false;
 if(!sxvintage_thomson_side(c,0,&first)||!sxvintage_thomson_side(c,(uint64_t)c->size/2,&second))return false;
 if(!first&&!second)return sx_raw(c,0,c->size);
 return sxvintage_finish(c);
}
static bool sx_vintagefilesystems_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<0x609d0001U||id>0x609d0007U)return true;
 if(r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
 if(id>=0x609d0006U){
  if(!xx_rt_wcscmp(r->name,L"disk_address"))return xx_data_struct_record_set_comment(r,L"Stored logical disk-sector address. This profile uses 512-byte sectors; no transformed sector order or synthesized byte offset is inserted.");
  if(!xx_rt_wcscmp(r->name,L"stored_length"))return xx_data_struct_record_set_comment(r,L"Original directory length word, preserved without conversion. The supported double-density producer and release-5 disk count 512-byte sectors; older manuals describe different block units.");
  if(!xx_rt_wcscmp(r->name,L"go_address"))return xx_data_struct_record_set_comment(r,L"Stored 16-bit load/start address for a North Star type-1 executable.");
  if(!xx_rt_wcscmp(r->name,L"type_density")){
   uint64_t v=xx_var_get_u64(&r->value);const wchar_t*names[]={L"DOUBLE_DENSITY | Data",L"DOUBLE_DENSITY | Executable",L"DOUBLE_DENSITY | BASIC"};
   return xx_data_struct_record_set_comment(r,(v&127)<3?names[v&127]:L"DOUBLE_DENSITY | User/unknown stored file type");
  }
  return xx_data_struct_record_set_comment(r,L"Original North Star double-density directory bytes. Unspecified type data and unused entries stay opaque.");
 }
 if(!xx_rt_wcscmp(r->name,L"first_block"))return xx_data_struct_record_set_comment(r,L"Stored allocation-block index, not a byte offset. Each block holds eight sectors; the original on-disk value is preserved.");
 if(!xx_rt_wcscmp(r->name,L"last_sector_bytes"))return xx_data_struct_record_set_comment(r,L"Stored big-endian byte count used in the last data sector. Double-density file payload uses at most 255 bytes per physical 256-byte sector.");
 if(!xx_rt_wcscmp(r->name,L"year"))return xx_data_struct_record_set_comment(r,L"Stored two-digit year; no century is inserted as a physical member.");
 if(!xx_rt_wcscmp(r->name,L"file_type")){
  const wchar_t*names[]={L"BASIC program",L"BASIC data",L"Machine code",L"ASCII assembler"};uint64_t v=xx_var_get_u64(&r->value);
  return xx_data_struct_record_set_comment(r,v<4?names[v]:L"Unknown stored file type");
 }
 if(!xx_rt_wcscmp(r->name,L"format_flag"))return xx_data_struct_record_set_comment(r,xx_var_get_u64(&r->value)==0?L"Binary/tokenized":xx_var_get_u64(&r->value)==255?L"ASCII":L"Unknown stored format flag");
 if(!xx_rt_wcscmp(r->name,L"allocation_value")){
  uint64_t v=xx_var_get_u64(&r->value);const wchar_t*text=v==255?L"Free block":v==254?L"Reserved metadata block (formatter value FE)":v==251?L"Reserved block (documented value FB)":v>=193&&v<=200?L"Final block: low nibble is the number of used sectors":L"Next allocation-block index";
  return xx_data_struct_record_set_comment(r,text);
 }
 if(!xx_rt_wcscmp(r->name,L"entry_state"))return xx_data_struct_record_set_comment(r,xx_var_get_u64(&r->value)==255?L"End of directory":xx_var_get_u64(&r->value)==0?L"Free directory entry":L"Stored directory marker");
 return xx_data_struct_record_set_comment(r,L"Original Thomson BASIC-DOS filesystem bytes. Unknown spans stay opaque; geometry and transformed sector-order values are not inserted as stored fields.");
}
