/* SPDX-License-Identifier: MIT. Physical CMD FD filesystem metadata. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_cmdfilesystems.h"

static const sx_layout*const sx_cmdfilesystems_layouts[]={&sxcmdfs_cmd_fd_system_header,&sxcmdfs_cmd_fd_partition_sector_link,&sxcmdfs_cmd_fd_first_partition,&sxcmdfs_cmd_fd_partition,&sxcmdfs_cmd_native_header,&sxcmdfs_cmd_native_bam_header};
static bool sx_cmdfilesystems_supports(xx_file_type_t type)
{switch(type){case XX_FILE_TYPE_CMD_D1M:case XX_FILE_TYPE_CMD_D2M:case XX_FILE_TYPE_CMD_D4M:return true;default:return false;}}
static bool sx_cmdfilesystems_build(sx_context*c)
{
 if(!c||!c->f||!sx_cmdfilesystems_supports(c->f->file_type))return false;
 if((!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 return sx_cmd_fd_build(c);
}
static bool sx_cmdfilesystems_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<0x609a0001U||id>0x609a0006U)return true;
 if(!xx_rt_wcscmp(r->name,L"starting_lba"))return xx_data_struct_record_set_comment(r,L"Stored big-endian 24-bit start in 512-byte logical blocks. System partition entry stores zero; its computed physical origin is not substituted here.");
 if(!xx_rt_wcscmp(r->name,L"length_lba"))return xx_data_struct_record_set_comment(r,L"Stored big-endian 24-bit length in 512-byte logical blocks.");
 if(!xx_rt_wcscmp(r->name,L"name_petscii"))return xx_data_struct_record_set_comment(r,L"Original 16-byte PETSCII name, including A0 padding; retained as bytes without a lossy text conversion.");
 if(!xx_rt_wcscmp(r->name,L"default_partition")||!xx_rt_wcscmp(r->name,L"default_partition_copy"))return xx_data_struct_record_set_comment(r,L"Stored default partition number; VICE reads byte E2 and preserves its E3 copy.");
 if(r->value.type==XX_VAR_TYPE_FLOAT||r->value.type==XX_VAR_TYPE_DOUBLE)return true;
 if(!xx_rt_wcscmp(r->name,L"partition_type")){
  const wchar_t*t=L"Unknown or unavailable partition type";
  switch(xx_var_get_u64(&r->value)){case 0:t=L"Unused partition";break;case 1:t=L"CMD native partition";break;case 2:t=L"1541 emulation partition";break;case 3:t=L"1571 emulation partition";break;case 4:t=L"1581 emulation partition";break;case 255:t=L"System partition";break;}
  return xx_data_struct_record_set_comment(r,t);
 }
 return xx_data_struct_record_set_comment(r,L"Stored CMD FD filesystem metadata byte range. Geometry-derived values and decoded head-order positions are not inserted as members; unknown bytes remain opaque.");
}
const sx_family sx_cmdfilesystems_family={sx_cmdfilesystems_supports,sx_cmdfilesystems_build,sx_cmdfilesystems_layouts,SX_COUNT(sx_cmdfilesystems_layouts),sx_cmdfilesystems_comment};
