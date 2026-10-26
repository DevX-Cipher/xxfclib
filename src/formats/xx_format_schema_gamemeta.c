/* SPDX-License-Identifier: MIT. Physical game metadata. Scope: docs/data_struct_gamemeta_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_gamemeta.h"
static const xx_data_struct_field_desc sxgm_crt_header_fields[] = {
 SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
 SX_FIELD("header_size","uint32",16,4,SX_SIZE),
 SX_FIELD("version","uint16",20,2,SX_ID),
 SX_FIELD("hardware_type","uint16",22,2,SX_ID),
 SX_FIELD("exrom","uint8",24,1,SX_FLAGS),
 SX_FIELD("game","uint8",25,1,SX_FLAGS),
 SX_FIELD("hardware_subtype","uint8",26,1,SX_ID),
 SX_FIELD("reserved","uint8[5]",27,5,SX_RESERVED),
 SX_FIELD("name","char[32]",32,32,SX_STRING),
};
static const sx_layout sxgm_crt_header = {UINT32_C(0x60270004),"crt_header",sxgm_crt_header_fields,SX_COUNT(sxgm_crt_header_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_crt_chip_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("packet_size","uint32",4,4,SX_SIZE),
 SX_FIELD("chip_type","uint16",8,2,SX_ID),
 SX_FIELD("bank","uint16",10,2,SX_ID),
 SX_FIELD("load_address","uint16",12,2,SX_ADDRESS),
 SX_FIELD("image_size","uint16",14,2,SX_SIZE),
};
static const sx_layout sxgm_crt_chip = {UINT32_C(0x60270005),"crt_chip",sxgm_crt_chip_fields,SX_COUNT(sxgm_crt_chip_fields),SX_BE};
static const xx_data_struct_field_desc sxgm_pfs_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("entry_count","uint32",4,4,SX_COUNT_PROP),
 SX_FIELD("strings_size","uint32",8,4,SX_SIZE),
 SX_FIELD("reserved","uint32",12,4,SX_RESERVED),
};
static const sx_layout sxgm_pfs_header = {UINT32_C(0x6027002b),"pfs_header",sxgm_pfs_header_fields,SX_COUNT(sxgm_pfs_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_pfs_entry_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("data_size","uint64",8,8,SX_SIZE),
 SX_FIELD("name_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("reserved","uint32",20,4,SX_RESERVED),
};
static const sx_layout sxgm_pfs_entry = {UINT32_C(0x6027002c),"pfs_entry",sxgm_pfs_entry_fields,SX_COUNT(sxgm_pfs_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_hfs_entry_fields[] = {
 SX_FIELD("data_offset","uint64",0,8,SX_OFFSET),
 SX_FIELD("data_size","uint64",8,8,SX_SIZE),
 SX_FIELD("name_offset","uint32",16,4,SX_OFFSET),
 SX_FIELD("hashed_size","uint32",20,4,SX_SIZE),
 SX_FIELD("reserved","uint64",24,8,SX_RESERVED),
 SX_FIELD("sha256","uint8[32]",32,32,SX_CHECKSUM),
};
static const sx_layout sxgm_hfs_entry = {UINT32_C(0x6027002d),"hfs_entry",sxgm_hfs_entry_fields,SX_COUNT(sxgm_hfs_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_idtech_bsp_header_fields[] = {
 SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("version","int32",4,4,SX_ID),
};
const sx_layout sxgm_idtech_bsp_header = {UINT32_C(0x60270045),"idtech_bsp_header",sxgm_idtech_bsp_header_fields,SX_COUNT(sxgm_idtech_bsp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_vertex_fields[] = {
 SX_FIELD("x","uint8",0,1,SX_NONE),
 SX_FIELD("y","uint8",1,1,SX_NONE),
 SX_FIELD("z","uint8",2,1,SX_NONE),
 SX_FIELD("normal_index","uint8",3,1,SX_ID),
};
const sx_layout sxgm_quake_vertex = {UINT32_C(0x6027004e),"quake_vertex",sxgm_quake_vertex_fields,SX_COUNT(sxgm_quake_vertex_fields),SX_LE};
static const xx_data_struct_field_desc sxgm_quake_frame_type_fields[] = {
 SX_FIELD("frame_type","int32",0,4,SX_ID),
};
const sx_layout sxgm_quake_frame_type = {UINT32_C(0x6027005b),"quake_frame_type",sxgm_quake_frame_type_fields,SX_COUNT(sxgm_quake_frame_type_fields),SX_LE};
static const sx_layout *const sx_gamemeta_layouts[] = {
 &sxgm_ines_header,
 &sxgm_nes2_header,
 &sxgm_lynx_header,
 &sxgm_crt_header,
 &sxgm_crt_chip,
 &sxgm_godot_pck_v1,
 &sxgm_godot_pck_v2,
 &sxgm_godot_pck_v3,
 &sxgm_godot_pck_v4_salted,
 &sxgm_godot_file_count,
 &sxgm_godot_path_length,
 &sxgm_godot_entry_v1,
 &sxgm_godot_entry_v2,
 &sxgm_godot_encrypted_block,
 &sxgm_godot_trailer,
 &sxgm_vpk_header,
 &sxgm_vpk_v2_sections,
 &sxgm_vpk_entry,
 &sxgm_vpk_archive_md5,
 &sxgm_vpk_other_md5,
 &sxgm_vpk_public_key_length,
 &sxgm_vpk_signature_length,
 &sxgm_rarc_header_le,
 &sxgm_rarc_header_be,
 &sxgm_rarc_node_le,
 &sxgm_rarc_node_be,
 &sxgm_rarc_file_le,
 &sxgm_rarc_directory_le,
 &sxgm_rarc_file_be,
 &sxgm_rarc_directory_be,
 &sxgm_narc_header,
 &sxgm_narc_fat,
 &sxgm_narc_entry,
 &sxgm_narc_block,
 &sxgm_sarc_header_le,
 &sxgm_sarc_header_be,
 &sxgm_sarc_fat_le,
 &sxgm_sarc_fat_be,
 &sxgm_sarc_entry_le,
 &sxgm_sarc_entry_be,
 &sxgm_sarc_names_le,
 &sxgm_sarc_names_be,
 &sxgm_pfs_header,
 &sxgm_pfs_entry,
 &sxgm_hfs_entry,
 &sxgm_psarc_header,
 &sxgm_psarc_entry,
 &sxgm_psarc_block_length,
 &sxgm_biff_header,
 &sxgm_biff_entry_v1,
 &sxgm_biff_entry_v2,
 &sxgm_erf_header,
 &sxgm_erf_key16,
 &sxgm_erf_key32,
 &sxgm_erf_resource,
 &sxgm_erf_localized,
 &sxgm_rim_header,
 &sxgm_rim_entry,
 &sxgm_bsa_header,
 &sxgm_bsa_folder,
 &sxgm_bsa_folder105,
 &sxgm_bsa_file,
 &sxgm_game_name_length8,
 &sxgm_game_name_length16,
 &sxgm_ba2_header,
 &sxgm_ba2_v2_extension,
 &sxgm_ba2_v3_compression,
 &sxgm_ba2_general_entry,
 &sxgm_idtech_bsp_header,
 &sxgm_idtech_bsp_lump,
 &sxgm_valve_bsp_lump,
 &sxgm_valve_bsp_revision,
 &sxgm_md2_header,
 &sxgm_game_skin_name,
 &sxgm_md2_texcoord,
 &sxgm_md2_triangle,
 &sxgm_md2_frame,
 &sxgm_quake_vertex,
 &sxgm_md2_gl_command,
 &sxgm_md2_gl_vertex,
 &sxgm_md3_header,
 &sxgm_md3_frame,
 &sxgm_md3_tag,
 &sxgm_md3_surface,
 &sxgm_md3_triangle,
 &sxgm_md3_shader,
 &sxgm_md3_texcoord,
 &sxgm_md3_vertex,
 &sxgm_qvm_header,
 &sxgm_quake_sprite_header,
 &sxgm_quake_frame_type,
 &sxgm_quake_group_count,
 &sxgm_quake_interval,
 &sxgm_quake_sprite_frame,
 &sxgm_quake_mdl_header,
 &sxgm_quake_skin_type,
 &sxgm_quake_stvert,
 &sxgm_quake_triangle,
 &sxgm_quake_mdl_frame,
 &sxgm_studio_v10_header,
 &sxgm_studio_texture,
 &sxgm_studio_skinref,
};
static bool sx_gamemeta_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x60270000U||id>=0x60280000U)return true;
 const wchar_t *text=NULL;switch(id){
 case 0x60270001U:
 if(!xx_rt_wcscmp(r->name,L"prg_rom_units"))text=L"Number of 16 KiB PRG ROM units.";
 if(!xx_rt_wcscmp(r->name,L"chr_rom_units"))text=L"Number of 8 KiB CHR ROM units; zero uses CHR RAM.";
 if(!xx_rt_wcscmp(r->name,L"flags6"))text=L"Low bits: mirroring, battery, trainer, four-screen; high nibble: mapper low bits.";
 if(!xx_rt_wcscmp(r->name,L"flags7"))text=L"High nibble: mapper high bits; low bits: console and header format.";
 if(!xx_rt_wcscmp(r->name,L"prg_ram_units"))text=L"Number of 8 KiB PRG RAM units; zero conventionally means one unit.";
 break;
 case 0x60270002U:
 if(!xx_rt_wcscmp(r->name,L"prg_rom_units_low"))text=L"Low eight bits of the linear 16 KiB PRG ROM unit count; extended by rom_size_high.";
 if(!xx_rt_wcscmp(r->name,L"chr_rom_units_low"))text=L"Low eight bits of the linear 8 KiB CHR ROM unit count; extended by rom_size_high.";
 if(!xx_rt_wcscmp(r->name,L"rom_size_high"))text=L"Low/high nibbles extend PRG/CHR counts; value 15 selects exponent encoding, outside the native reader scope.";
 if(!xx_rt_wcscmp(r->name,L"prg_ram_shifts"))text=L"Low/high nibbles encode volatile/nonvolatile RAM: zero means absent, otherwise 64 << nibble bytes.";
 if(!xx_rt_wcscmp(r->name,L"chr_ram_shifts"))text=L"Low/high nibbles encode volatile/nonvolatile CHR RAM: zero means absent, otherwise 64 << nibble bytes.";
 if(!xx_rt_wcscmp(r->name,L"misc_rom_count"))text=L"Low two bits are the miscellaneous ROM count; these variants are excluded by the native reader.";
 break;
 case 0x60270003U:
 if(!xx_rt_wcscmp(r->name,L"bank0_page_size"))text=L"Bank 0 consists of 256 pages of this byte size.";
 if(!xx_rt_wcscmp(r->name,L"bank1_page_size"))text=L"Bank 1 consists of 256 pages; zero means absent.";
 if(!xx_rt_wcscmp(r->name,L"rotation"))text=L"0=none, 1=left, 2=right.";
 if(!xx_rt_wcscmp(r->name,L"audin"))text=L"Bit 0 enables additional AUDIN-addressed banks; excluded by the native reader.";
 if(!xx_rt_wcscmp(r->name,L"eeprom"))text=L"Low bits select 93C46/56/66/76/86; bit 6=SD support, bit 7=eight-bit EEPROM mode.";
 break;
 case 0x60270005U:
 if(!xx_rt_wcscmp(r->name,L"packet_size"))text=L"Includes this 16-byte CHIP header and any packet padding; RAM chips may omit image bytes.";
 if(!xx_rt_wcscmp(r->name,L"chip_type"))text=L"0=ROM, 1=RAM, 2=flash ROM, 3=EEPROM (broader CRT reader).";
 break;
 case 0x60270007U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=encrypted directory; bit 1=file_base relative to pack header.";
 if(!xx_rt_wcscmp(r->name,L"file_base"))text=L"Payload offset origin; pack-relative when flag 1 is set, otherwise relative to the enclosing file.";
 break;
 case 0x60270008U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=encrypted directory; bit 1=relative base; bit 2=sparse bundle.";
 if(!xx_rt_wcscmp(r->name,L"file_base"))text=L"Payload origin relative to this pack header.";
 if(!xx_rt_wcscmp(r->name,L"directory_offset"))text=L"Directory count word offset relative to this pack header.";
 break;
 case 0x60270009U:
 if(!xx_rt_wcscmp(r->name,L"file_base"))text=L"Payload origin relative to this pack header.";
 if(!xx_rt_wcscmp(r->name,L"directory_offset"))text=L"Directory count word offset relative to this pack header.";
 if(!xx_rt_wcscmp(r->name,L"salt"))text=L"Version 4 encrypted sparse-bundle key derivation salt.";
 break;
 case 0x6027000bU:
 if(!xx_rt_wcscmp(r->name,L"path_size"))text=L"Padded UTF-8 path byte count, including its terminating NUL.";
 break;
 case 0x6027000cU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Payload byte offset relative to the pack version-specific file_base.";
 break;
 case 0x6027000dU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Payload byte offset relative to the pack version-specific file_base.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0=encrypted, bit 1=removal, bit 2=delta.";
 break;
 case 0x6027000eU:
 if(!xx_rt_wcscmp(r->name,L"plain_size"))text=L"Decoded plaintext length; ciphertext occupies the length rounded up to 16 bytes.";
 break;
 case 0x6027000fU:
 if(!xx_rt_wcscmp(r->name,L"pack_size"))text=L"Pack bytes preceding this 12-byte embedded-pack trailer.";
 break;
 case 0x60270012U:
 if(!xx_rt_wcscmp(r->name,L"archive_index"))text=L"0x7FFF means the directory file data section; other values name an external numbered archive.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset in the selected archive data section, not necessarily this file.";
 break;
 case 0x60270013U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Offset in the selected external archive.";
 break;
 case 0x60270017U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"nodes_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"entries_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"strings_offset"))text=L"Relative to byte 0x20 in this archive.";
 break;
 case 0x60270018U:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"nodes_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"entries_offset"))text=L"Relative to byte 0x20 in this archive.";
 if(!xx_rt_wcscmp(r->name,L"strings_offset"))text=L"Relative to byte 0x20 in this archive.";
 break;
 case 0x60270019U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string pool.";
 break;
 case 0x6027001aU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string pool.";
 break;
 case 0x6027001bU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"Bit 0=file, bit 1=directory, bit 2=compressed, bit 7=Yaz0.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to the archive data section.";
 break;
 case 0x6027001cU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"Bit 0=file, bit 1=directory, bit 2=compressed, bit 7=Yaz0.";
 if(!xx_rt_wcscmp(r->name,L"node_index"))text=L"Directory node index; 0xFFFFFFFF is the root parent sentinel.";
 break;
 case 0x6027001dU:
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"Bit 0=file, bit 1=directory, bit 2=compressed, bit 7=Yaz0.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Byte offset relative to the archive data section.";
 break;
 case 0x6027001eU:
 if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"Bit 0=file, bit 1=directory, bit 2=compressed, bit 7=Yaz0.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"node_index"))text=L"Directory node index; 0xFFFFFFFF is the root parent sentinel.";
 break;
 case 0x60270021U:
 if(!xx_rt_wcscmp(r->name,L"start_offset"))text=L"Relative to the GMIF image payload.";
 if(!xx_rt_wcscmp(r->name,L"end_offset"))text=L"Exclusive endpoint relative to the GMIF image payload.";
 break;
 case 0x60270027U:
 if(!xx_rt_wcscmp(r->name,L"name_attributes"))text=L"High byte=has name; low 24 bits=string-pool offset in four-byte units.";
 if(!xx_rt_wcscmp(r->name,L"start_offset"))text=L"Relative to the data section.";
 if(!xx_rt_wcscmp(r->name,L"end_offset"))text=L"Exclusive endpoint relative to the data section.";
 break;
 case 0x60270028U:
 if(!xx_rt_wcscmp(r->name,L"name_attributes"))text=L"High byte=has name; low 24 bits=string-pool offset in four-byte units.";
 if(!xx_rt_wcscmp(r->name,L"start_offset"))text=L"Relative to the data section.";
 if(!xx_rt_wcscmp(r->name,L"end_offset"))text=L"Exclusive endpoint relative to the data section.";
 break;
 case 0x6027002cU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the payload area after the directory and string pool.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string pool.";
 break;
 case 0x6027002dU:
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the payload area after the directory and string pool.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the string pool.";
 if(!xx_rt_wcscmp(r->name,L"hashed_size"))text=L"Length of the initial member region covered by sha256.";
 break;
 case 0x60270030U:
 if(!xx_rt_wcscmp(r->name,L"stored_length"))text=L"Zero encodes a full 65536-byte stored block; nonzero is the physical block byte length.";
 break;
 case 0x60270034U:
 if(!xx_rt_wcscmp(r->name,L"build_year"))text=L"Years since 1900.";
 if(!xx_rt_wcscmp(r->name,L"build_day"))text=L"Zero-based day of the year.";
 if(!xx_rt_wcscmp(r->name,L"description_strref"))text=L"String-reference index; 0xFFFFFFFF means absent.";
 break;
 case 0x6027003bU:
 if(!xx_rt_wcscmp(r->name,L"archive_flags"))text=L"Bit 0=folder names, bit 1=file names, bit 2=default compression; bit 8=embedded file names for v104/105.";
 break;
 case 0x6027003cU:
 if(!xx_rt_wcscmp(r->name,L"block_offset"))text=L"Encoded folder block offset includes the file-name-pool byte length.";
 break;
 case 0x6027003dU:
 if(!xx_rt_wcscmp(r->name,L"block_offset"))text=L"Encoded folder block offset includes the file-name-pool byte length.";
 break;
 case 0x6027003eU:
 if(!xx_rt_wcscmp(r->name,L"size_flags"))text=L"Low 30 bits=stored byte length; bit 30 toggles archive default compression; bit 31 is reserved.";
 break;
 case 0x60270043U:
 if(!xx_rt_wcscmp(r->name,L"compression"))text=L"0=zlib, 3=LZ4.";
 break;
 case 0x60270044U:
 if(!xx_rt_wcscmp(r->name,L"packed_size"))text=L"Zero denotes a stored member of unpacked_size bytes.";
 if(!xx_rt_wcscmp(r->name,L"alignment"))text=L"Native general-file record marker 0xBAADF00D.";
 break;
 case 0x60270047U:
 if(!xx_rt_wcscmp(r->name,L"fourcc"))text=L"Compression identifier/uncompressed-length slot; the native reader supports zero, uncompressed records.";
 break;
 case 0x60270049U:
 if(!xx_rt_wcscmp(r->name,L"gl_command_words"))text=L"Number of four-byte command-stream words; not the number of commands.";
 break;
 case 0x6027004eU:
 if(!xx_rt_wcscmp(r->name,L"x"))text=L"Compressed coordinate; multiply by frame/model scale and add translation.";
 if(!xx_rt_wcscmp(r->name,L"y"))text=L"Compressed coordinate; multiply by frame/model scale and add translation.";
 if(!xx_rt_wcscmp(r->name,L"z"))text=L"Compressed coordinate; multiply by frame/model scale and add translation.";
 break;
 case 0x6027004fU:
 if(!xx_rt_wcscmp(r->name,L"vertex_count_signed"))text=L"Positive=triangle strip, negative=triangle fan, zero=terminator; absolute value is vertex count.";
 break;
 case 0x60270054U:
 if(!xx_rt_wcscmp(r->name,L"triangles_offset"))text=L"Byte offset relative to this surface header.";
 if(!xx_rt_wcscmp(r->name,L"shaders_offset"))text=L"Byte offset relative to this surface header.";
 if(!xx_rt_wcscmp(r->name,L"texcoords_offset"))text=L"Byte offset relative to this surface header.";
 if(!xx_rt_wcscmp(r->name,L"vertices_offset"))text=L"Byte offset relative to this surface header.";
 if(!xx_rt_wcscmp(r->name,L"end_offset"))text=L"Byte offset relative to this surface header.";
 break;
 case 0x60270058U:
 if(!xx_rt_wcscmp(r->name,L"x"))text=L"Signed fixed point coordinate, scale 1/64.";
 if(!xx_rt_wcscmp(r->name,L"y"))text=L"Signed fixed point coordinate, scale 1/64.";
 if(!xx_rt_wcscmp(r->name,L"z"))text=L"Signed fixed point coordinate, scale 1/64.";
 if(!xx_rt_wcscmp(r->name,L"normal"))text=L"Two encoded eight-bit spherical angles retained as their physical signed short word.";
 break;
 case 0x6027005bU:
 if(!xx_rt_wcscmp(r->name,L"frame_type"))text=L"0=single frame, 1=frame group.";
 break;
 case 0x6027005dU:
 if(!xx_rt_wcscmp(r->name,L"interval"))text=L"Cumulative group frame interval in seconds.";
 break;
 case 0x60270064U:
 if(!xx_rt_wcscmp(r->name,L"sound_table"))text=L"Unused legacy sound-table slot; retained as encoded integer.";
 if(!xx_rt_wcscmp(r->name,L"sound_index"))text=L"Unused legacy sound-index slot.";
 if(!xx_rt_wcscmp(r->name,L"sound_groups"))text=L"Unused legacy sound-group slot.";
 if(!xx_rt_wcscmp(r->name,L"sound_group_index"))text=L"Unused legacy sound-group-index slot.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXGM_LIMIT 20000U
bool sxgm_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxgm_read(sx_context *c,uint64_t p,void *b,size_t n){return sxgm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxgm_uint(const uint8_t *b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
uint16_t sxgm16(const uint8_t *b,bool be){return (uint16_t)sxgm_uint(b,2,be);}
uint32_t sxgm32(const uint8_t *b,bool be){return (uint32_t)sxgm_uint(b,4,be);}
/* Native readers can authenticate aliases and damaged optional records. Keep
 * earlier bounded physical metadata, and leave conflicting later interpretations
 * opaque instead of discarding the entire useful header view. */
static bool sxgm_free(sx_context *c,uint64_t p,uint64_t n){for(size_t i=0;i<c->count;i++){uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<at+z&&at<p+n)return false;}return true;}
bool sxgm_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(!sxgm_span(c,p,n))return false;if(!sxgm_free(c,p,n))return true;return c->count>=SXGM_LIMIT||sx_add(c,l,(int64_t)p,(int64_t)n);}
bool sxgm_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n||n>SXGM_LIMIT||!sxgm_span(c,p,n*z))return true;if(!sxgm_free(c,p,n*z))return true;return c->count>=SXGM_LIMIT||sx_table(c,l,(int64_t)p,(int64_t)z,n);}
bool sxgm_word(sx_context *c,uint64_t p,unsigned n,bool be,uint64_t *v){uint8_t b[8];if(n>8||!sxgm_read(c,p,b,n))return false;*v=sxgm_uint(b,n,be);return true;}
static bool sxgm_crt(sx_context *c){uint8_t b[64];if(!sxgm_read(c,0,b,64)||!sxgm_add(c,&sxgm_crt_header,0))return false;uint64_t p=sxgm32(b+16,true);if(p<64)p=64;for(unsigned i=0;i<SXGM_LIMIT&&p<(uint64_t)c->size;i++){if(!sxgm_read(c,p,b,16)||xx_rt_memcmp(b,"CHIP",4))break;uint64_t n=sxgm32(b+4,true);if(n<16||!sxgm_span(c,p,n))break;if(!sxgm_add(c,&sxgm_crt_chip,p))return false;p+=n;}return true;}
bool sxgm_fixed(sx_context *c,const sx_layout *h,const sx_layout *e,unsigned off,unsigned size,unsigned noff,unsigned nwidth,unsigned poff,unsigned pwidth,bool be){uint8_t b[160];if(size>sizeof(b)||!sxgm_read(c,off,b,size)||!sxgm_add(c,h,off))return false;uint64_t n=sxgm_uint(b+noff,nwidth,be),p=pwidth?sxgm_uint(b+poff,pwidth,be):off+size;return sxgm_table(c,e,p,n);}
static int sxgm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxgm_finish(sx_context *c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxgm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxgm_order);return !c->failed;}
static bool sx_gamemeta_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_NES_ROM:case XX_FILE_TYPE_LYNX_LNX:case XX_FILE_TYPE_CRT:case XX_FILE_TYPE_COMMODORE_CRT:case XX_FILE_TYPE_GODOT_ENGINE_PCK:case XX_FILE_TYPE_VALVE_VPK:case XX_FILE_TYPE_NINTENDO_RARC:case XX_FILE_TYPE_NINTENDO_NARC:case XX_FILE_TYPE_NINTENDO_SARC:case XX_FILE_TYPE_NINTENDO_PFS0:case XX_FILE_TYPE_NINTENDO_HFS0:case XX_FILE_TYPE_SONY_PSARC:case XX_FILE_TYPE_BIOWARE_BIFF:case XX_FILE_TYPE_BIOWARE_ERF:case XX_FILE_TYPE_BIOWARE_RIM:case XX_FILE_TYPE_BETHESDA_BSA:case XX_FILE_TYPE_BETHESDA_BA2:case XX_FILE_TYPE_IDTECH_BSP:case XX_FILE_TYPE_VALVE_BSP:case XX_FILE_TYPE_IDTECH_MD2:case XX_FILE_TYPE_IDTECH_MD3:case XX_FILE_TYPE_IDTECH_QVM:case XX_FILE_TYPE_QUAKE_SPRITE:case XX_FILE_TYPE_IDTECH_MDL:case XX_FILE_TYPE_VALVE_STUDIO_MDL:return true;default:return false;}}
static bool sx_gamemeta_build(sx_context *c){if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;uint8_t b[16];switch(c->f->file_type){
 case XX_FILE_TYPE_NES_ROM:ok=sx_nes_rom_build(c,b);break;
 case XX_FILE_TYPE_LYNX_LNX:ok=sx_lynx_lnx_build(c);break;
 case XX_FILE_TYPE_CRT:case XX_FILE_TYPE_COMMODORE_CRT:ok=sxgm_crt(c);break;
 case XX_FILE_TYPE_GODOT_ENGINE_PCK:ok=sx_godot_engine_pck_build(c);break;
 case XX_FILE_TYPE_VALVE_VPK:ok=sx_valve_vpk_build(c);break;
 case XX_FILE_TYPE_NINTENDO_RARC:ok=sx_nintendo_rarc_build(c);break;
 case XX_FILE_TYPE_NINTENDO_NARC:ok=sx_nintendo_narc_build(c);break;
 case XX_FILE_TYPE_NINTENDO_SARC:ok=sx_nintendo_sarc_build(c);break;
 case XX_FILE_TYPE_NINTENDO_PFS0:case XX_FILE_TYPE_NINTENDO_HFS0:ok=sxgm_fixed(c,&sxgm_pfs_header,c->f->file_type==XX_FILE_TYPE_NINTENDO_PFS0?&sxgm_pfs_entry:&sxgm_hfs_entry,0,16,4,4,0,0,false);break;
 case XX_FILE_TYPE_SONY_PSARC:ok=sx_sony_psarc_build(c);break;
 case XX_FILE_TYPE_BIOWARE_BIFF:ok=sx_bioware_biff_build(c);break;
 case XX_FILE_TYPE_BIOWARE_ERF:ok=sx_bioware_erf_build(c);break;
 case XX_FILE_TYPE_BIOWARE_RIM:ok=sx_bioware_rim_build(c);break;
 case XX_FILE_TYPE_BETHESDA_BSA:ok=sx_bethesda_bsa_build(c);break;
 case XX_FILE_TYPE_BETHESDA_BA2:ok=sx_bethesda_ba2_build(c);break;
 case XX_FILE_TYPE_IDTECH_BSP:ok=sx_idtech_bsp_build(c,b);break;
 case XX_FILE_TYPE_VALVE_BSP:ok=sx_valve_bsp_build(c);break;
 case XX_FILE_TYPE_IDTECH_MD2:ok=sx_idtech_md2_build(c);break;
 case XX_FILE_TYPE_IDTECH_MD3:ok=sx_idtech_md3_build(c);break;
 case XX_FILE_TYPE_IDTECH_QVM:ok=sx_idtech_qvm_build(c);break;
 case XX_FILE_TYPE_QUAKE_SPRITE:ok=sx_quake_sprite_build(c);break;
 case XX_FILE_TYPE_IDTECH_MDL:ok=sx_idtech_mdl_build(c);break;
 case XX_FILE_TYPE_VALVE_STUDIO_MDL:ok=sx_valve_studio_mdl_build(c);break;
 default:break;}return ok&&sxgm_finish(c);}
const sx_family sx_gamemeta_family={sx_gamemeta_supports,sx_gamemeta_build,sx_gamemeta_layouts,SX_COUNT(sx_gamemeta_layouts),sx_gamemeta_comment};
