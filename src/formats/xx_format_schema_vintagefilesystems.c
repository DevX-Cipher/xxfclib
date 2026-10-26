/* SPDX-License-Identifier: MIT. Original physical filesystem metadata. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_vintagefilesystems.h"

static const sx_layout*const sx_vintagefilesystems_layouts[]={&sxvintage_thomson_volume_header,&sxvintage_thomson_fat_prefix,&sxvintage_thomson_fat_entry,&sxvintage_thomson_directory_entry,&sxvintage_thomson_directory_state,&sxvintage_northstar_directory_entry,&sxvintage_northstar_executable_entry};
static bool sx_vintagefilesystems_supports(xx_file_type_t type)
{return type==XX_FILE_TYPE_THOMSON_FD||type==XX_FILE_TYPE_NORTHSTAR_NSI;}
static int sxvintage_compare(const void*a,const void*b)
{const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
bool sxvintage_finish(sx_context*c)
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
 if(c->f->file_type==XX_FILE_TYPE_NORTHSTAR_NSI)return sx_northstar_nsi_build(c);
 return sx_thomson_fd_build(c);
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
const sx_family sx_vintagefilesystems_family={sx_vintagefilesystems_supports,sx_vintagefilesystems_build,sx_vintagefilesystems_layouts,SX_COUNT(sx_vintagefilesystems_layouts),sx_vintagefilesystems_comment};
