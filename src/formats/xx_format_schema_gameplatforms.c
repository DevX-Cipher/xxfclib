/* Copyright (c)2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical game cartridge and resource metadata; compressed and unknown bodies stay raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_gameplatforms.h"
static const xx_data_struct_field_desc sxgp_ncch_header_fields[]={
 SX_FIELD("signature","bytes",0,256,SX_SIGNATURE),
 SX_FIELD("magic","bytes",256,4,SX_SIGNATURE),
 SX_FIELD("content_media_units","uint32",260,4,SX_NONE),
 SX_FIELD("partition_id","uint64",264,8,SX_ID),
 SX_FIELD("maker_code","char[2]",272,2,SX_ID),
 SX_FIELD("version","uint16",274,2,SX_ID),
 SX_FIELD("seed_hash","uint32",276,4,SX_CHECKSUM),
 SX_FIELD("program_id","uint64",280,8,SX_ID),
 SX_FIELD("reserved","bytes",288,16,SX_RESERVED),
 SX_FIELD("logo_sha256","bytes",304,32,SX_CHECKSUM),
 SX_FIELD("product_code","char[16]",336,16,SX_ID),
 SX_FIELD("extended_header_sha256","bytes",352,32,SX_CHECKSUM),
 SX_FIELD("extended_header_size","uint32",384,4,SX_SIZE),
 SX_FIELD("reserved2","bytes",388,4,SX_RESERVED),
 SX_FIELD("flags","bytes",392,8,SX_FLAGS),
 SX_FIELD("plain_offset_media_units","uint32",400,4,SX_NONE),
 SX_FIELD("plain_size_media_units","uint32",404,4,SX_NONE),
 SX_FIELD("logo_offset_media_units","uint32",408,4,SX_NONE),
 SX_FIELD("logo_size_media_units","uint32",412,4,SX_NONE),
 SX_FIELD("exefs_offset_media_units","uint32",416,4,SX_NONE),
 SX_FIELD("exefs_size_media_units","uint32",420,4,SX_NONE),
 SX_FIELD("exefs_hash_media_units","uint32",424,4,SX_NONE),
 SX_FIELD("reserved3","bytes",428,4,SX_RESERVED),
 SX_FIELD("romfs_offset_media_units","uint32",432,4,SX_NONE),
 SX_FIELD("romfs_size_media_units","uint32",436,4,SX_NONE),
 SX_FIELD("romfs_hash_media_units","uint32",440,4,SX_NONE),
 SX_FIELD("reserved4","bytes",444,4,SX_RESERVED),
 SX_FIELD("exefs_sha256","bytes",448,32,SX_CHECKSUM),
 SX_FIELD("romfs_sha256","bytes",480,32,SX_CHECKSUM),
};
static const sx_layout sxgp_ncch_header={UINT32_C(0x60360026),"ncch_header",sxgp_ncch_header_fields,SX_COUNT(sxgp_ncch_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_sci_prefix_fields[]={
 SX_FIELD("name","char[8]",0,8,SX_STRING),
 SX_FIELD("reserved","bytes",8,5,SX_RESERVED),
 SX_FIELD("flags","uint8",13,1,SX_FLAGS),
 SX_FIELD("remaster_version","uint16",14,2,SX_ID),
};
static const sx_layout sxgp_ncch_sci_prefix={UINT32_C(0x6036002A),"ncch_sci_prefix",sxgp_ncch_sci_prefix_fields,SX_COUNT(sxgp_ncch_sci_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_code_segment_fields[]={
 SX_FIELD("address","uint32",0,4,SX_ADDRESS),
 SX_FIELD("page_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("code_size","uint32",8,4,SX_SIZE),
};
static const sx_layout sxgp_ncch_code_segment={UINT32_C(0x6036002B),"ncch_code_segment",sxgp_ncch_code_segment_fields,SX_COUNT(sxgp_ncch_code_segment_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_stack_fields[]={
 SX_FIELD("stack_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgp_ncch_stack={UINT32_C(0x6036002C),"ncch_stack",sxgp_ncch_stack_fields,SX_COUNT(sxgp_ncch_stack_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_reserved_word_fields[]={
 SX_FIELD("reserved","uint32",0,4,SX_RESERVED),
};
static const sx_layout sxgp_ncch_reserved_word={UINT32_C(0x6036002D),"ncch_reserved_word",sxgp_ncch_reserved_word_fields,SX_COUNT(sxgp_ncch_reserved_word_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_bss_fields[]={
 SX_FIELD("bss_size","uint32",0,4,SX_SIZE),
};
static const sx_layout sxgp_ncch_bss={UINT32_C(0x6036002E),"ncch_bss",sxgp_ncch_bss_fields,SX_COUNT(sxgp_ncch_bss_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_dependency_fields[]={
 SX_FIELD("program_id","uint64",0,8,SX_ID),
};
static const sx_layout sxgp_ncch_dependency={UINT32_C(0x6036002F),"ncch_dependency",sxgp_ncch_dependency_fields,SX_COUNT(sxgp_ncch_dependency_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_ncch_sci_tail_fields[]={
 SX_FIELD("savedata_size","uint64",0,8,SX_SIZE),
 SX_FIELD("jump_id","uint64",8,8,SX_ID),
 SX_FIELD("reserved","bytes",16,48,SX_RESERVED),
};
static const sx_layout sxgp_ncch_sci_tail={UINT32_C(0x60360030),"ncch_sci_tail",sxgp_ncch_sci_tail_fields,SX_COUNT(sxgp_ncch_sci_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxgp_gcm_id_fields[]={
 SX_FIELD("game_code","char[4]",0,4,SX_ID),
 SX_FIELD("maker_code","char[2]",4,2,SX_ID),
 SX_FIELD("disc_number","uint8",6,1,SX_ID),
 SX_FIELD("version","uint8",7,1,SX_ID),
 SX_FIELD("audio_streaming","uint8",8,1,SX_FLAGS),
 SX_FIELD("stream_buffer_size","uint8",9,1,SX_NONE),
 SX_FIELD("reserved","bytes",10,14,SX_RESERVED),
 SX_FIELD("wii_magic","uint32",24,4,SX_SIGNATURE),
 SX_FIELD("gamecube_magic","uint32",28,4,SX_SIGNATURE),
};
const sx_layout sxgp_gcm_id={UINT32_C(0x60360090),"gcm_id",sxgp_gcm_id_fields,SX_COUNT(sxgp_gcm_id_fields),SX_BE};
static const sx_layout *const sx_gameplatforms_layouts[]={
 &sxgp_msx_rom_header,
 &sxgp_msx_binary_header,
 &sxgp_sms_header,
 &sxgp_tic_chunk,
 &sxgp_gb_common,
 &sxgp_gb_title,
 &sxgp_cgb_title,
 &sxgp_gb_cartridge,
 &sxgp_gba_header,
 &sxgp_megadrive_boot,
 &sxgp_megadrive_vector,
 &sxgp_megadrive_header,
 &sxgp_n64_header,
 &sxgp_a78_header,
 &sxgp_unif_header,
 &sxgp_unif_chunk,
 &sxgp_unif_crc,
 &sxgp_unif_mirroring,
 &sxgp_fds_header,
 &sxgp_fds_file_count,
 &sxgp_fds_file,
 &sxgp_pbp_header,
 &sxgp_sfo_header,
 &sxgp_sfo_entry,
 &sxgp_xnb_header,
 &sxgp_xnb_count,
 &sxgp_xnb_reader_id,
 &sxgp_xnb_length_1,
 &sxgp_xnb_length_2,
 &sxgp_xnb_length_3,
 &sxgp_xnb_length_4,
 &sxgp_xnb_reader_version,
 &sxgp_xnb_texture,
 &sxgp_xnb_mip,
 &sxgp_xnb_int32,
 &sxgp_xnb_float32,
 &sxgp_xnb_byte,
 &sxgp_ncch_header,
 &sxgp_ncsd_header,
 &sxgp_ncsd_partition,
 &sxgp_ncsd_tail,
 &sxgp_ncch_sci_prefix,
 &sxgp_ncch_code_segment,
 &sxgp_ncch_stack,
 &sxgp_ncch_reserved_word,
 &sxgp_ncch_bss,
 &sxgp_ncch_dependency,
 &sxgp_ncch_sci_tail,
 &sxgp_nds_header,
 &sxgp_nds_fat,
 &sxgp_nds_overlay,
 &sxgp_nds_directory,
 &sxgp_nds_name,
 &sxgp_nds_subdirectory,
 &sxgp_sfo_int32,
 &sxgp_nds_root_directory,
 &sxgp_unity_header,
 &sxgp_unity_sizes,
 &sxgp_unity_info,
 &sxgp_unity_block,
 &sxgp_unity_node_count,
 &sxgp_unity_node,
 &sxgp_hpi_header,
 &sxgp_hpi_directory,
 &sxgp_hpi_entry,
 &sxgp_hpi_file,
 &sxgp_rff_header,
 &sxgp_rff_entry,
 &sxgp_bnd3_header_le,
 &sxgp_bnd4_header_le,
 &sxgp_bnd3_entry_le,
 &sxgp_bnd4_entry_le,
 &sxgp_bnd_offset32_le,
 &sxgp_bnd_offset64_le,
 &sxgp_bnd_id_le,
 &sxgp_bnd3_name_le,
 &sxgp_bnd4_name_le,
 &sxgp_bnd_raw32_le,
 &sxgp_bnd_raw64_le,
 &sxgp_bnd4_names_extra_le,
 &sxgp_bnd3_header_be,
 &sxgp_bnd4_header_be,
 &sxgp_bnd3_entry_be,
 &sxgp_bnd4_entry_be,
 &sxgp_bnd_offset32_be,
 &sxgp_bnd_offset64_be,
 &sxgp_bnd_id_be,
 &sxgp_bnd3_name_be,
 &sxgp_bnd4_name_be,
 &sxgp_bnd_raw32_be,
 &sxgp_bnd_raw64_be,
 &sxgp_bnd4_names_extra_be,
 &sxgp_xp3_header,
 &sxgp_xp3_index,
 &sxgp_xp3_chunk,
 &sxgp_xp3_info,
 &sxgp_xp3_segment,
 &sxgp_xp3_checksum,
 &sxgp_lspk_header,
 &sxgp_lspk_file,
 &sxgp_lsf_header,
 &sxgp_lsf_string_table,
 &sxgp_lsf_bucket,
 &sxgp_lsf_string,
 &sxgp_lsf_node,
 &sxgp_lsf_attribute,
 &sxgp_rpa_header,
 &sxgp_rpa_zlib,
 &sxgp_rpa_adler,
 &sxgp_nbt_tag,
 &sxgp_nbt_string,
 &sxgp_nbt_array,
 &sxgp_nbt_list,
 &sxgp_nbt_byte,
 &sxgp_nbt_short,
 &sxgp_nbt_int,
 &sxgp_nbt_long,
 &sxgp_nbt_float,
 &sxgp_nbt_double,
 &sxgp_szx_header,
 &sxgp_szx_chunk,
 &sxgp_szx_z80,
 &sxgp_szx_z80_v0_tail,
 &sxgp_szx_z80_v1_tail,
 &sxgp_szx_z80_v4_tail,
 &sxgp_szx_spectrum,
 &sxgp_szx_ram,
 &sxgp_szx_creator,
 &sxgp_szx_joystick,
 &sxgp_szx_keyboard,
 &sxgp_szx_keyboard_joystick,
 &sxgp_szx_printer,
 &sxgp_szx_ay,
 &sxgp_cpc_header,
 &sxgp_cpc_v1_tail,
 &sxgp_cpc_model,
 &sxgp_fds_side,
 &sxgp_cia_header,
 &sxgp_cia_signature,
 &sxgp_cia_tmd,
 &sxgp_cia_content_info,
 &sxgp_cia_content,
 &sxgp_cia_metadata,
 &sxgp_gcm_id,
 &sxgp_gcm_title,
 &sxgp_gcm_debug,
 &sxgp_gcm_boot,
 &sxgp_gcm_apploader,
 &sxgp_gcm_fst_file,
 &sxgp_gcm_fst_directory,
 &sxgp_gcm_fst_root,
 &sxgp_gcm_dol_offset,
 &sxgp_gcm_dol_address,
 &sxgp_gcm_dol_size,
 &sxgp_gcm_dol_tail,
 &sxgp_wbfs_header,
 &sxgp_wbfs_disc_title,
 &sxgp_wbfs_block,
 &sxgp_wbfs_md5,
};
bool sxgp_span(sxgp_view*v,uint64_t at,uint64_t n,uint64_t end)
{return !xx_pd_is_stopped(v->c->pd)&&v->c->size>=0&&end<=(uint64_t)v->c->size&&at<=end&&n<=end-at;}
bool sxgp_read(sxgp_view*v,uint64_t at,void*p,size_t n,uint64_t end)
{return sxgp_span(v,at,n,end)&&sx_read(v->c,(int64_t)at,p,n);}
bool sxgp_word(sxgp_view*v,uint64_t at,unsigned n,bool be,uint64_t*out,uint64_t end)
{uint8_t b[8];if(!n||n>8||!sxgp_read(v,at,b,n,end))return false;uint64_t x=0;for(unsigned i=0;i<n;i++)x|=(uint64_t)b[be?n-i-1:i]<<(8*i);*out=x;return true;}
bool sxgp_row(sxgp_view*v,const sx_layout*l,uint64_t at,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(++v->work>4000000||!sxgp_span(v,at,z,end))return false;return v->c->count>=24000||sx_add(v->c,l,(int64_t)at,(int64_t)z);}
#define SG_ROW(l,at,end) sxgp_row(v,&sxgp_##l,(at),(end))
bool sxgp_table(sxgp_view*v,const sx_layout*l,uint64_t at,uint64_t count,uint64_t end)
{const xx_data_struct_field_desc*f=l->fields+l->field_count-1;uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!z||count>4000000||count>UINT64_MAX/z||!sxgp_span(v,at,count*z,end))return false;for(uint64_t i=0;i<count&&v->c->count<24000;i++,at+=z)if(!sxgp_row(v,l,at,end))return false;return true;}
static int sxgp_order(const void*aa,const void*bb)
{const xx_data_struct*a=aa,*b=bb;if(a->offset!=b->offset)return a->offset<b->offset?-1:1;return a->total_size<b->total_size?-1:a->total_size>b->total_size?1:0;}
static bool sxgp_finish(sx_context*c)
{size_t n=c->count,keep=0;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxgp_order);
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at<end)continue;c->items[keep++]=c->items[i];end=at+z;}c->count=keep;n=keep;end=0;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;end=at+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxgp_order);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxgp_ncch_at(sxgp_view*v,uint64_t at,uint64_t end,bool extended)
{uint64_t ex;if(!SG_ROW(ncch_header,at,end)||!sxgp_word(v,at+0x180,4,false,&ex,end))return false;if(extended&&ex){uint64_t p=at+512;if(!sxgp_span(v,p,0x800,end)||!SG_ROW(ncch_sci_prefix,p,end)||!SG_ROW(ncch_code_segment,p+16,end)||!SG_ROW(ncch_stack,p+28,end)||!SG_ROW(ncch_code_segment,p+32,end)||!SG_ROW(ncch_reserved_word,p+44,end)||!SG_ROW(ncch_code_segment,p+48,end)||!SG_ROW(ncch_bss,p+60,end)||!sxgp_table(v,&sxgp_ncch_dependency,p+64,48,end)||!SG_ROW(ncch_sci_tail,p+448,end))return false;}return true;}
static bool sx_gameplatforms_supports(xx_file_type_t t)
{switch(t){
case XX_FILE_TYPE_UNITYFS:
case XX_FILE_TYPE_TOTALANNIHILATION_HPI:
case XX_FILE_TYPE_RAVENSOFT_RFF:
case XX_FILE_TYPE_KIRIKIRI_XP3:
case XX_FILE_TYPE_FROMSOFTWARE_BINDER:
case XX_FILE_TYPE_NINTENDO_NCCH:
case XX_FILE_TYPE_NINTENDO_NCSD:
case XX_FILE_TYPE_NINTENDO_CIA:
case XX_FILE_TYPE_NINTENDO_NDS:
case XX_FILE_TYPE_NINTENDO_GCM:
case XX_FILE_TYPE_LARIAN_LSPK:
case XX_FILE_TYPE_LARIAN_LSF:
case XX_FILE_TYPE_RENPY_RPA:
case XX_FILE_TYPE_NINTENDO_WBFS:
case XX_FILE_TYPE_SONY_PSP_PBP:
case XX_FILE_TYPE_NINTENDO_N64_ROM:
case XX_FILE_TYPE_NINTENDO_GB_ROM:
case XX_FILE_TYPE_NINTENDO_GBA_ROM:
case XX_FILE_TYPE_SEGA_MEGADRIVE_ROM:
case XX_FILE_TYPE_XNA_XNB:
case XX_FILE_TYPE_ZX_SPECTRUM_SZX:
case XX_FILE_TYPE_NINTENDO_UNIF:
case XX_FILE_TYPE_NINTENDO_FDS:
case XX_FILE_TYPE_ATARI_7800_A78:
case XX_FILE_TYPE_AMSTRAD_CPC_SNA:
case XX_FILE_TYPE_MINECRAFT_NBT:
case XX_FILE_TYPE_MSX_ROM:
case XX_FILE_TYPE_SEGA_SMS_ROM:
case XX_FILE_TYPE_TIC80:
return true;default:return false;}}
static bool sx_gameplatforms_build(sx_context*c)
{if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid||c->size<=0)return false;sxgp_view view={c,0},*v=&view;bool ok=false;
 switch(c->f->file_type){
case XX_FILE_TYPE_UNITYFS:ok=sx_unityfs_build(v);break;
case XX_FILE_TYPE_TOTALANNIHILATION_HPI:ok=sx_totalannihilation_hpi_build(v);break;
case XX_FILE_TYPE_RAVENSOFT_RFF:ok=sx_ravensoft_rff_build(v);break;
case XX_FILE_TYPE_KIRIKIRI_XP3:ok=sx_kirikiri_xp3_build(v);break;
case XX_FILE_TYPE_FROMSOFTWARE_BINDER:ok=sx_fromsoftware_binder_build(v);break;
case XX_FILE_TYPE_NINTENDO_NCCH:ok=sx_nintendo_ncch_build(v);break;
case XX_FILE_TYPE_NINTENDO_NCSD:ok=sx_nintendo_ncsd_build(v);break;
case XX_FILE_TYPE_NINTENDO_CIA:ok=sx_nintendo_cia_build(v);break;
case XX_FILE_TYPE_NINTENDO_NDS:ok=sx_nintendo_nds_build(v);break;
case XX_FILE_TYPE_NINTENDO_GCM:ok=sx_nintendo_gcm_build(v);break;
case XX_FILE_TYPE_LARIAN_LSPK:ok=sx_larian_lspk_build(v);break;
case XX_FILE_TYPE_LARIAN_LSF:ok=sx_larian_lsf_build(v);break;
case XX_FILE_TYPE_RENPY_RPA:ok=sx_renpy_rpa_build(v);break;
case XX_FILE_TYPE_NINTENDO_WBFS:ok=sx_nintendo_wbfs_build(v);break;
case XX_FILE_TYPE_SONY_PSP_PBP:ok=sx_sony_psp_pbp_build(v);break;
case XX_FILE_TYPE_NINTENDO_N64_ROM:ok=sx_nintendo_n64_rom_build(v);break;
case XX_FILE_TYPE_NINTENDO_GB_ROM:ok=sx_nintendo_gb_rom_build(v);break;
case XX_FILE_TYPE_NINTENDO_GBA_ROM:ok=sx_nintendo_gba_rom_build(v);break;
case XX_FILE_TYPE_SEGA_MEGADRIVE_ROM:ok=sx_sega_megadrive_rom_build(v);break;
case XX_FILE_TYPE_XNA_XNB:ok=sx_xna_xnb_build(v);break;
case XX_FILE_TYPE_ZX_SPECTRUM_SZX:ok=sx_zx_spectrum_szx_build(v);break;
case XX_FILE_TYPE_NINTENDO_UNIF:ok=sx_nintendo_unif_build(v);break;
case XX_FILE_TYPE_NINTENDO_FDS:ok=sx_nintendo_fds_build(v);break;
case XX_FILE_TYPE_ATARI_7800_A78:ok=sx_atari_7800_a78_build(v);break;
case XX_FILE_TYPE_AMSTRAD_CPC_SNA:ok=sx_amstrad_cpc_sna_build(v);break;
case XX_FILE_TYPE_MINECRAFT_NBT:ok=sx_minecraft_nbt_build(v);break;
case XX_FILE_TYPE_MSX_ROM:ok=sx_msx_rom_build(v);break;
case XX_FILE_TYPE_SEGA_SMS_ROM:ok=sx_sega_sms_rom_build(v);break;
case XX_FILE_TYPE_TIC80:ok=sx_tic80_build(v);break;
default:break;}
 return ok&&sxgp_finish(c);}
#undef SG_ROW
static bool sx_gameplatforms_comment(xx_data_struct_record*r,uint32_t id)
{
 if(!r||!r->name||id<UINT32_C(0x60360001)||id>=UINT32_C(0x60370000))return true;
 if(r->type&&!xx_rt_wcsncmp(r->type,L"ascii_",6)&&xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;
 if(id==1614151688u&&!xx_rt_wcscmp(r->name,L"cartridge_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"ROM_ONLY");
 case 1u:return xx_data_struct_record_set_comment(r,L"MBC1");
 case 2u:return xx_data_struct_record_set_comment(r,L"MBC1_RAM");
 case 3u:return xx_data_struct_record_set_comment(r,L"MBC1_RAM_BATTERY");
 case 5u:return xx_data_struct_record_set_comment(r,L"MBC2");
 case 6u:return xx_data_struct_record_set_comment(r,L"MBC2_BATTERY");
 case 8u:return xx_data_struct_record_set_comment(r,L"ROM_RAM");
 case 9u:return xx_data_struct_record_set_comment(r,L"ROM_RAM_BATTERY");
 case 15u:return xx_data_struct_record_set_comment(r,L"MBC3_TIMER_BATTERY");
 case 16u:return xx_data_struct_record_set_comment(r,L"MBC3_TIMER_RAM_BATTERY");
 case 17u:return xx_data_struct_record_set_comment(r,L"MBC3");
 case 18u:return xx_data_struct_record_set_comment(r,L"MBC3_RAM");
 case 19u:return xx_data_struct_record_set_comment(r,L"MBC3_RAM_BATTERY");
 case 25u:return xx_data_struct_record_set_comment(r,L"MBC5");
 case 26u:return xx_data_struct_record_set_comment(r,L"MBC5_RAM");
 case 27u:return xx_data_struct_record_set_comment(r,L"MBC5_RAM_BATTERY");
 default:break;}}
 if(id==1614151688u&&!xx_rt_wcscmp(r->name,L"destination_code")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"JAPAN");
 case 1u:return xx_data_struct_record_set_comment(r,L"OVERSEAS");
 default:break;}}
 if(id==1614151687u&&!xx_rt_wcscmp(r->name,L"cgb_flag")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 128u:return xx_data_struct_record_set_comment(r,L"CGB_COMPATIBLE");
 case 192u:return xx_data_struct_record_set_comment(r,L"CGB_ONLY");
 default:break;}}
 if(id==1614151688u&&!xx_rt_wcscmp(r->name,L"rom_size_code")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"32 KiB");
 case 1u:return xx_data_struct_record_set_comment(r,L"64 KiB");
 case 2u:return xx_data_struct_record_set_comment(r,L"128 KiB");
 case 3u:return xx_data_struct_record_set_comment(r,L"256 KiB");
 case 4u:return xx_data_struct_record_set_comment(r,L"512 KiB");
 case 5u:return xx_data_struct_record_set_comment(r,L"1024 KiB");
 case 6u:return xx_data_struct_record_set_comment(r,L"2048 KiB");
 case 7u:return xx_data_struct_record_set_comment(r,L"4096 KiB");
 case 8u:return xx_data_struct_record_set_comment(r,L"8192 KiB");
 default:break;}}
 if(id==1614151688u&&!xx_rt_wcscmp(r->name,L"ram_size_code")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"NONE");
 case 1u:return xx_data_struct_record_set_comment(r,L"2 KiB");
 case 2u:return xx_data_struct_record_set_comment(r,L"8 KiB");
 case 3u:return xx_data_struct_record_set_comment(r,L"32 KiB");
 case 4u:return xx_data_struct_record_set_comment(r,L"128 KiB");
 case 5u:return xx_data_struct_record_set_comment(r,L"64 KiB");
 default:break;}}
 if(id==1614151698u&&!xx_rt_wcscmp(r->name,L"mirroring")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"HORIZONTAL");
 case 1u:return xx_data_struct_record_set_comment(r,L"VERTICAL");
 case 2u:return xx_data_struct_record_set_comment(r,L"SINGLE_SCREEN_0");
 case 3u:return xx_data_struct_record_set_comment(r,L"SINGLE_SCREEN_1");
 case 4u:return xx_data_struct_record_set_comment(r,L"FOUR_SCREEN");
 case 5u:return xx_data_struct_record_set_comment(r,L"MAPPER_CONTROLLED");
 default:break;}}
 if(id==1614151701u&&!xx_rt_wcscmp(r->name,L"file_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"PRG_RAM");
 case 1u:return xx_data_struct_record_set_comment(r,L"CHR_RAM");
 case 2u:return xx_data_struct_record_set_comment(r,L"NAMETABLE");
 default:break;}}
 if(id==1614151704u&&!xx_rt_wcscmp(r->name,L"data_format")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 4u:return xx_data_struct_record_set_comment(r,L"BINARY");
 case 516u:return xx_data_struct_record_set_comment(r,L"UTF8_STRING");
 case 1028u:return xx_data_struct_record_set_comment(r,L"INT32");
 default:break;}}
 if(id==1614151705u&&!xx_rt_wcscmp(r->name,L"target_platform")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 119u:return xx_data_struct_record_set_comment(r,L"WINDOWS");
 case 120u:return xx_data_struct_record_set_comment(r,L"XBOX360");
 case 109u:return xx_data_struct_record_set_comment(r,L"WINDOWS_PHONE");
 default:break;}}
 if(id==1614151705u&&!xx_rt_wcscmp(r->name,L"flags")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"UNCOMPRESSED_REACH");
 case 1u:return xx_data_struct_record_set_comment(r,L"UNCOMPRESSED_HIDEF");
 case 128u:return xx_data_struct_record_set_comment(r,L"LZX_COMPRESSED");
 case 64u:return xx_data_struct_record_set_comment(r,L"LZ4_COMPRESSED");
 default:break;}}
 if(id==1614151713u&&!xx_rt_wcscmp(r->name,L"surface_format")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"COLOR");
 case 1u:return xx_data_struct_record_set_comment(r,L"BGR565");
 case 2u:return xx_data_struct_record_set_comment(r,L"BGRA5551");
 case 3u:return xx_data_struct_record_set_comment(r,L"BGRA4444");
 case 4u:return xx_data_struct_record_set_comment(r,L"DXT1");
 case 5u:return xx_data_struct_record_set_comment(r,L"DXT3");
 case 6u:return xx_data_struct_record_set_comment(r,L"DXT5");
 case 7u:return xx_data_struct_record_set_comment(r,L"NORMALIZED_BYTE2");
 case 8u:return xx_data_struct_record_set_comment(r,L"NORMALIZED_BYTE4");
 case 9u:return xx_data_struct_record_set_comment(r,L"RGBA1010102");
 case 10u:return xx_data_struct_record_set_comment(r,L"RG32");
 case 11u:return xx_data_struct_record_set_comment(r,L"RGBA64");
 case 12u:return xx_data_struct_record_set_comment(r,L"ALPHA8");
 case 13u:return xx_data_struct_record_set_comment(r,L"SINGLE");
 case 14u:return xx_data_struct_record_set_comment(r,L"VECTOR2");
 case 15u:return xx_data_struct_record_set_comment(r,L"VECTOR4");
 case 16u:return xx_data_struct_record_set_comment(r,L"HALF_SINGLE");
 case 17u:return xx_data_struct_record_set_comment(r,L"HALF_VECTOR2");
 case 18u:return xx_data_struct_record_set_comment(r,L"HALF_VECTOR4");
 case 19u:return xx_data_struct_record_set_comment(r,L"HDR_BLENDABLE");
 default:break;}}
 if(id==1614151746u&&!xx_rt_wcscmp(r->name,L"compression")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"STORED");
 case 1u:return xx_data_struct_record_set_comment(r,L"LZ77");
 case 2u:return xx_data_struct_record_set_comment(r,L"ZLIB");
 default:break;}}
 if(id==1614151819u&&!xx_rt_wcscmp(r->name,L"signature_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 65540u:return xx_data_struct_record_set_comment(r,L"RSA2048_SHA256");
 default:break;}}
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"version")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"NCCH_VERSION_0");
 case 1u:return xx_data_struct_record_set_comment(r,L"NCCH_VERSION_1");
 case 2u:return xx_data_struct_record_set_comment(r,L"NCCH_VERSION_2");
 default:break;}}
 if(id==1614151790u&&!xx_rt_wcscmp(r->name,L"tag_id")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"TAG_End");
 case 1u:return xx_data_struct_record_set_comment(r,L"TAG_Byte");
 case 2u:return xx_data_struct_record_set_comment(r,L"TAG_Short");
 case 3u:return xx_data_struct_record_set_comment(r,L"TAG_Int");
 case 4u:return xx_data_struct_record_set_comment(r,L"TAG_Long");
 case 5u:return xx_data_struct_record_set_comment(r,L"TAG_Float");
 case 6u:return xx_data_struct_record_set_comment(r,L"TAG_Double");
 case 7u:return xx_data_struct_record_set_comment(r,L"TAG_Byte_Array");
 case 8u:return xx_data_struct_record_set_comment(r,L"TAG_String");
 case 9u:return xx_data_struct_record_set_comment(r,L"TAG_List");
 case 10u:return xx_data_struct_record_set_comment(r,L"TAG_Compound");
 case 11u:return xx_data_struct_record_set_comment(r,L"TAG_Int_Array");
 case 12u:return xx_data_struct_record_set_comment(r,L"TAG_Long_Array");
 default:break;}}
 if(id==1614151793u&&!xx_rt_wcscmp(r->name,L"element_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"TAG_End");
 case 1u:return xx_data_struct_record_set_comment(r,L"TAG_Byte");
 case 2u:return xx_data_struct_record_set_comment(r,L"TAG_Short");
 case 3u:return xx_data_struct_record_set_comment(r,L"TAG_Int");
 case 4u:return xx_data_struct_record_set_comment(r,L"TAG_Long");
 case 5u:return xx_data_struct_record_set_comment(r,L"TAG_Float");
 case 6u:return xx_data_struct_record_set_comment(r,L"TAG_Double");
 case 7u:return xx_data_struct_record_set_comment(r,L"TAG_Byte_Array");
 case 8u:return xx_data_struct_record_set_comment(r,L"TAG_String");
 case 9u:return xx_data_struct_record_set_comment(r,L"TAG_List");
 case 10u:return xx_data_struct_record_set_comment(r,L"TAG_Compound");
 case 11u:return xx_data_struct_record_set_comment(r,L"TAG_Int_Array");
 case 12u:return xx_data_struct_record_set_comment(r,L"TAG_Long_Array");
 default:break;}}
 if(id==1614151800u&&!xx_rt_wcscmp(r->name,L"machine")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_16K");
 case 1u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_48K");
 case 2u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_128K");
 case 3u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_PLUS2");
 case 4u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_PLUS2A");
 case 5u:return xx_data_struct_record_set_comment(r,L"ZX_SPECTRUM_PLUS3");
 default:break;}}
 if(id==1614151816u&&!xx_rt_wcscmp(r->name,L"machine_type")&&xx_var_get_type(&r->value)>=XX_VAR_TYPE_INT8&&xx_var_get_type(&r->value)<=XX_VAR_TYPE_UINT64){switch(xx_var_get_u64(&r->value)){
 case 0u:return xx_data_struct_record_set_comment(r,L"CPC464");
 case 1u:return xx_data_struct_record_set_comment(r,L"CPC664");
 case 2u:return xx_data_struct_record_set_comment(r,L"CPC6128");
 default:break;}}
 if(id==1614151681u&&!xx_rt_wcscmp(r->name,L"init_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151681u&&!xx_rt_wcscmp(r->name,L"runtime_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151681u&&!xx_rt_wcscmp(r->name,L"device_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151681u&&!xx_rt_wcscmp(r->name,L"text_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151682u&&!xx_rt_wcscmp(r->name,L"start_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151682u&&!xx_rt_wcscmp(r->name,L"end_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151682u&&!xx_rt_wcscmp(r->name,L"init_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151690u&&!xx_rt_wcscmp(r->name,L"stack_pointer"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151690u&&!xx_rt_wcscmp(r->name,L"reset_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151691u&&!xx_rt_wcscmp(r->name,L"handler_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"rom_start"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"rom_end"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"ram_start"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"ram_end"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"sram_start"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151692u&&!xx_rt_wcscmp(r->name,L"sram_end"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151693u&&!xx_rt_wcscmp(r->name,L"entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151701u&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"param_sfo_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"icon0_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"icon1_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"pic0_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"pic1_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"snd0_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"data_psp_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151702u&&!xx_rt_wcscmp(r->name,L"data_psar_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151703u&&!xx_rt_wcscmp(r->name,L"key_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded PARAM.SFO header");
 if(id==1614151703u&&!xx_rt_wcscmp(r->name,L"data_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded PARAM.SFO header");
 if(id==1614151704u&&!xx_rt_wcscmp(r->name,L"key_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the SFO key table");
 if(id==1614151704u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the SFO data table");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"content_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"plain_offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"plain_size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"logo_offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"logo_size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"exefs_offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"exefs_size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"exefs_hash_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"romfs_offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"romfs_size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151718u&&!xx_rt_wcscmp(r->name,L"romfs_hash_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151719u&&!xx_rt_wcscmp(r->name,L"content_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151720u&&!xx_rt_wcscmp(r->name,L"offset_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151720u&&!xx_rt_wcscmp(r->name,L"size_media_units"))return xx_data_struct_record_set_comment(r,L"Encoded position or length in 512-byte media units; multiply by 512 for bytes");
 if(id==1614151723u&&!xx_rt_wcscmp(r->name,L"address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_rom_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_rom_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"fnt_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"fat_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_overlay_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_overlay_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"banner_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm9_autoload_list_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"arm7_autoload_list_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"debug_rom_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"debug_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151730u&&!xx_rt_wcscmp(r->name,L"start_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151730u&&!xx_rt_wcscmp(r->name,L"end_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151731u&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151731u&&!xx_rt_wcscmp(r->name,L"static_init_start"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151731u&&!xx_rt_wcscmp(r->name,L"static_init_end"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151732u&&!xx_rt_wcscmp(r->name,L"subtable_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the file-name table");
 if(id==1614151736u&&!xx_rt_wcscmp(r->name,L"subtable_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the file-name table");
 if(id==1614151742u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the uncompressed block stream; supported blocks are stored");
 if(id==1614151743u&&!xx_rt_wcscmp(r->name,L"directory_end_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151743u&&!xx_rt_wcscmp(r->name,L"root_directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151744u&&!xx_rt_wcscmp(r->name,L"entries_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151745u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151745u&&!xx_rt_wcscmp(r->name,L"record_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151746u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151747u&&!xx_rt_wcscmp(r->name,L"directory_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151748u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151749u&&!xx_rt_wcscmp(r->name,L"format_bits"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151749u&&!xx_rt_wcscmp(r->name,L"bit_big_endian"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151749u&&!xx_rt_wcscmp(r->name,L"headers_end"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151750u&&!xx_rt_wcscmp(r->name,L"reversed_bit_order"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151750u&&!xx_rt_wcscmp(r->name,L"headers_end"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151750u&&!xx_rt_wcscmp(r->name,L"format_bits"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151750u&&!xx_rt_wcscmp(r->name,L"hash_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151751u&&!xx_rt_wcscmp(r->name,L"file_flags"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151752u&&!xx_rt_wcscmp(r->name,L"file_flags"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151753u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151754u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151756u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151757u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151761u&&!xx_rt_wcscmp(r->name,L"format_bits"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151761u&&!xx_rt_wcscmp(r->name,L"bit_big_endian"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151761u&&!xx_rt_wcscmp(r->name,L"headers_end"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151762u&&!xx_rt_wcscmp(r->name,L"reversed_bit_order"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151762u&&!xx_rt_wcscmp(r->name,L"headers_end"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151762u&&!xx_rt_wcscmp(r->name,L"format_bits"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151762u&&!xx_rt_wcscmp(r->name,L"hash_table_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151763u&&!xx_rt_wcscmp(r->name,L"file_flags"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151764u&&!xx_rt_wcscmp(r->name,L"file_flags"))return xx_data_struct_record_set_comment(r,L"Binder bit-field encoding; bit order follows this binder header");
 if(id==1614151765u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151766u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151768u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151769u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151773u&&!xx_rt_wcscmp(r->name,L"index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151777u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151779u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151780u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151787u&&!xx_rt_wcscmp(r->name,L"index_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151802u&&!xx_rt_wcscmp(r->name,L"sp"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151802u&&!xx_rt_wcscmp(r->name,L"pc"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151805u&&!xx_rt_wcscmp(r->name,L"memptr"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151814u&&!xx_rt_wcscmp(r->name,L"sp"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151814u&&!xx_rt_wcscmp(r->name,L"pc"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151817u&&!xx_rt_wcscmp(r->name,L"manufacture_date_bcd"))return xx_data_struct_record_set_comment(r,L"Packed binary-coded decimal; original digits are preserved");
 if(id==1614151817u&&!xx_rt_wcscmp(r->name,L"rewrite_date_bcd"))return xx_data_struct_record_set_comment(r,L"Packed binary-coded decimal; original digits are preserved");
 if(id==1614151817u&&!xx_rt_wcscmp(r->name,L"rewrite_count_bcd"))return xx_data_struct_record_set_comment(r,L"Packed binary-coded decimal; original digits are preserved");
 if(id==1614151826u&&!xx_rt_wcscmp(r->name,L"debug_monitor_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151826u&&!xx_rt_wcscmp(r->name,L"debug_monitor_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151827u&&!xx_rt_wcscmp(r->name,L"dol_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151827u&&!xx_rt_wcscmp(r->name,L"fst_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151827u&&!xx_rt_wcscmp(r->name,L"fst_load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151827u&&!xx_rt_wcscmp(r->name,L"user_data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151828u&&!xx_rt_wcscmp(r->name,L"entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151829u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the FST string table");
 if(id==1614151829u&&!xx_rt_wcscmp(r->name,L"data_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the beginning of this file");
 if(id==1614151830u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the FST string table");
 if(id==1614151831u&&!xx_rt_wcscmp(r->name,L"name_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the FST string table");
 if(id==1614151832u&&!xx_rt_wcscmp(r->name,L"section_offset"))return xx_data_struct_record_set_comment(r,L"Byte offset relative to the embedded DOL header");
 if(id==1614151833u&&!xx_rt_wcscmp(r->name,L"load_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151835u&&!xx_rt_wcscmp(r->name,L"bss_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151835u&&!xx_rt_wcscmp(r->name,L"entry_address"))return xx_data_struct_record_set_comment(r,L"Target CPU memory address; not a file offset");
 if(id==1614151732u&&!xx_rt_wcscmp(r->name,L"parent_id_or_directory_count"))return xx_data_struct_record_set_comment(r,L"Parent directory ID; the root uses a separate count layout");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"capacity_exponent"))return xx_data_struct_record_set_comment(r,L"ROM capacity exponent: 128 KiB multiplied by 2 to this power");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"secure_transfer_timeout"))return xx_data_struct_record_set_comment(r,L"Secure-area delay in 1/131000-second units");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"secure_area_disable"))return xx_data_struct_record_set_comment(r,L"Encrypted eight-byte secure-area-disable token");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"nand_rom_end_units"))return xx_data_struct_record_set_comment(r,L"NDS NAND position in 0x20000-byte units; zero means absent");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"nand_rw_start_units"))return xx_data_struct_record_set_comment(r,L"NDS NAND position in 0x20000-byte units; zero means absent");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"unknown_88"))return xx_data_struct_record_set_comment(r,L"Undocumented NDS word; retained without inferring an offset");
 if(id==1614151729u&&!xx_rt_wcscmp(r->name,L"reserved_or_fastboot"))return xx_data_struct_record_set_comment(r,L"Reserved bytes or homebrew fast-boot marker");
 if(id==1614151731u&&!xx_rt_wcscmp(r->name,L"compressed_size_flags"))return xx_data_struct_record_set_comment(r,L"Low 24 bits: compressed size in bytes; high 8 bits: flags");
 if(id==1614151723u&&!xx_rt_wcscmp(r->name,L"page_count"))return xx_data_struct_record_set_comment(r,L"Count of 4096-byte virtual-memory pages");
 if(id==1614151721u&&!xx_rt_wcscmp(r->name,L"sector_zero_offset_encoded"))return xx_data_struct_record_set_comment(r,L"Encoded sector-zero offset; retained in its on-disk units");
 if(id==1614151836u&&!xx_rt_wcscmp(r->name,L"host_sector_shift"))return xx_data_struct_record_set_comment(r,L"Base-2 logarithm of the host-sector size in bytes");
 if(id==1614151836u&&!xx_rt_wcscmp(r->name,L"wbfs_sector_shift"))return xx_data_struct_record_set_comment(r,L"Base-2 logarithm of the WBFS cluster size in bytes");
 if(id==1614151836u&&!xx_rt_wcscmp(r->name,L"host_sector_count"))return xx_data_struct_record_set_comment(r,L"Count of host sectors; size is 2 to host_sector_shift bytes");
 if(id==1614151838u&&!xx_rt_wcscmp(r->name,L"physical_cluster"))return xx_data_struct_record_set_comment(r,L"Physical WBFS cluster index; zero means unallocated; multiply by cluster size for bytes");
 if(id==1614151824u&&!xx_rt_wcscmp(r->name,L"stream_buffer_size"))return xx_data_struct_record_set_comment(r,L"Encoded audio streaming buffer-size selector");
 if(id==1614151821u&&!xx_rt_wcscmp(r->name,L"index_offset"))return xx_data_struct_record_set_comment(r,L"Index of the first covered content record; not a byte offset");
 if(id==1614151823u&&!xx_rt_wcscmp(r->name,L"dependencies"))return xx_data_struct_record_set_comment(r,L"48 little-endian program IDs, each 64 bits");
 if(id==1614151814u&&!xx_rt_wcscmp(r->name,L"memory_dump_kib"))return xx_data_struct_record_set_comment(r,L"Memory dump length in 1024-byte units");
 if(id==1614151802u&&!xx_rt_wcscmp(r->name,L"tstates"))return xx_data_struct_record_set_comment(r,L"CPU T-state count within the current frame; not a wall-clock timestamp");
 if(id==1614151804u&&!xx_rt_wcscmp(r->name,L"hold_interrupt_cycles"))return xx_data_struct_record_set_comment(r,L"Remaining CPU cycles for the interrupt hold");
 if(id==1614151805u&&!xx_rt_wcscmp(r->name,L"hold_interrupt_cycles"))return xx_data_struct_record_set_comment(r,L"Remaining CPU cycles for the interrupt hold");
 if(id==1614151748u&&!xx_rt_wcscmp(r->name,L"runtime_state"))return xx_data_struct_record_set_comment(r,L"Serialized runtime/cache words; no pointer interpretation assumed");
 if(id==1614151748u&&!xx_rt_wcscmp(r->name,L"unknown_time_word"))return xx_data_struct_record_set_comment(r,L"Opaque on-disk word; epoch and interpretation not established by the native reader");
 if(id==1614151693u&&!xx_rt_wcscmp(r->name,L"pi_boot_config"))return xx_data_struct_record_set_comment(r,L"Packed initial peripheral-interface configuration bytes");
 if(id==1614151693u&&!xx_rt_wcscmp(r->name,L"clock_rate"))return xx_data_struct_record_set_comment(r,L"Encoded clock rate; boot code clears its low four bits");
 if(id==1614151693u&&!xx_rt_wcscmp(r->name,L"manufacturer"))return xx_data_struct_record_set_comment(r,L"32-bit manufacturer identifier, commonly ASCII N in its low byte");
 if(id==1614151683u&&!xx_rt_wcscmp(r->name,L"product_high_version"))return xx_data_struct_record_set_comment(r,L"High nibble: high product-code digit; low nibble: version");
 if(id==1614151683u&&!xx_rt_wcscmp(r->name,L"region_size"))return xx_data_struct_record_set_comment(r,L"High nibble: region/platform selector; low nibble: encoded ROM size");
 if(id==1614151684u&&!xx_rt_wcscmp(r->name,L"bank_type"))return xx_data_struct_record_set_comment(r,L"Bits 0..4: chunk type; bits 5..7: cartridge bank");
 if(id==1614151785u&&!xx_rt_wcscmp(r->name,L"name_reference"))return xx_data_struct_record_set_comment(r,L"Packed string-table bucket/index reference");
 if(id==1614151786u&&!xx_rt_wcscmp(r->name,L"name_reference"))return xx_data_struct_record_set_comment(r,L"Packed string-table bucket/index reference");
 if(id==1614151786u&&!xx_rt_wcscmp(r->name,L"type_length"))return xx_data_struct_record_set_comment(r,L"Low 6 bits: value type; upper 26 bits: stored value byte size");
 if(id==1614151786u&&!xx_rt_wcscmp(r->name,L"node_index"))return xx_data_struct_record_set_comment(r,L"Owning node index; signed sentinel values remain signed");
 if(id==1614151776u&&!xx_rt_wcscmp(r->name,L"name_utf16_units"))return xx_data_struct_record_set_comment(r,L"Count of UTF-16 code units in the following file name");
 return true;
}
const sx_family sx_gameplatforms_family={sx_gameplatforms_supports,sx_gameplatforms_build,sx_gameplatforms_layouts,SX_COUNT(sx_gameplatforms_layouts),sx_gameplatforms_comment};
