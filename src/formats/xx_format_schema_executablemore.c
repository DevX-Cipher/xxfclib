/* SPDX-License-Identifier: MIT. Physical executable metadata. Scope: docs/data_struct_executablemore_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_executablemore.h"
static const sx_layout *const sx_executablemore_layouts[] = {
 &sxexm_vz_header,
 &sxexm_xalz_header,
 &sxexm_pyc_header8,
 &sxexm_pyc_header12,
 &sxexm_pyc_header16_timestamp,
 &sxexm_pyc_header16_hash,
 &sxexm_msf7_superblock,
 &sxexm_msf7_directory_block,
 &sxexm_msf7_stream_count,
 &sxexm_msf7_stream_size,
 &sxexm_msf7_stream_block,
 &sxexm_mub_header_le,
 &sxexm_mub_arch32_le,
 &sxexm_mub_header_be,
 &sxexm_mub_arch32_be,
 &sxexm_mub_arch64_be,
 &sxexm_resource_fork_header,
 &sxexm_resource_map_header,
 &sxexm_resource_type_count,
 &sxexm_resource_type_entry,
 &sxexm_resource_reference,
 &sxexm_resource_data_length,
 &sxexm_resource_name_length,
 &sxexm_pebble_header,
 &sxexm_pebble_relocation,
 &sxexm_nro_start,
 &sxexm_nro_header,
 &sxexm_nro_asset_header,
 &sxexm_nso_header,
 &sxexm_xbe_header,
 &sxexm_xbe_section,
 &sxexm_xbe_certificate,
 &sxexm_dmp64_prefix,
 &sxexm_dmp64_type,
 &sxexm_dmp64_required_space,
 &sxexm_dmp64_product,
 &sxexm_dmp64_bitmap_header,
 &sxexm_cgc_header_le,
 &sxexm_cgc_header_be,
 &sxexm_cgc_program_header_le,
 &sxexm_cgc_program_header_be,
 &sxexm_cgc_section_header_le,
 &sxexm_cgc_section_header_be,
 &sxexm_rel_header,
 &sxexm_rel_v2_extension,
 &sxexm_rel_v3_extension,
 &sxexm_rel_section,
 &sxexm_rel_import,
 &sxexm_rel_relocation,
 &sxexm_xtac_header,
 &sxexm_xtac_address_pair,
 &sxexm_xtac_block_stub,
 &sxexm_xtac_linked_entry0,
 &sxexm_xtac_linked_entry1,
 &sxexm_xtac_linked_entry2,
 &sxexm_xtac_linked_entry3,
 &sxexm_qnx_record_header,
 &sxexm_qnx_module_header,
 &sxexm_qnx_segment,
 &sxexm_qnx_load_header,
 &sxexm_qnx_resource_header,
 &sxexm_qnx_read_write_end,
 &sxexm_qnx_image_end,
 &sxexm_omf_record_header,
 &sxexm_omf_checksum,
 &sxexm_omf_name_length,
 &sxexm_dos_extender_mz,
 &sxexm_dos16m_bw_header,
 &sxexm_dos16m_mf_header,
 &sxexm_amiga_hunk_tag,
 &sxexm_amiga_hunk_length,
 &sxexm_amiga_hunk_table,
 &sxexm_amiga_hunk_allocation,
 &sxexm_amiga_memory_flags,
 &sxexm_amiga_relocation_count16,
 &sxexm_amiga_relocation_target16,
 &sxexm_amiga_relocation_offset16,
 &sxexm_amiga_relocation_count32,
 &sxexm_amiga_relocation_target32,
 &sxexm_amiga_relocation_offset32,
 &sxexm_amiga_symbol_value,
 &sxexm_amiga_ext_name,
 &sxexm_amiga_common_size,
 &sxexm_som_header,
 &sxexm_som_space,
 &sxexm_som_subspace_initialized,
 &sxexm_som_subspace_pattern,
 &sxexm_som_symbol,
 &sxexm_xcoff32_file_header,
 &sxexm_xcoff32_optional_header,
 &sxexm_xcoff32_section,
 &sxexm_xcoff32_loader,
 &sxexm_xcoff32_loader_symbol_inline,
 &sxexm_xcoff32_loader_symbol_external,
};
static bool sx_executablemore_comment(xx_data_struct_record *r,uint32_t id){
 if(!r||!r->name||id<0x602b0000U||id>=0x602c0000U)return true;
 const wchar_t *text=NULL;switch(id){
 case 0x602b0001U:
 if(!xx_rt_wcscmp(r->name,L"file_type"))text=L"0xF0=BASIC, 0xF1=machine code.";
 break;
 case 0x602b0005U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"PEP 552: bit 0 selects hash-based header; bit 1 requests source checking.";
 break;
 case 0x602b0006U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"PEP 552: bit 0 selects hash-based header; bit 1 requests source checking.";
 break;
 case 0x602b0007U:
 if(!xx_rt_wcscmp(r->name,L"free_block_map_block"))text=L"File block index, in block_size-byte units.";
 if(!xx_rt_wcscmp(r->name,L"block_map_block"))text=L"File block index of the directory-block index array.";
 break;
 case 0x602b0008U:
 if(!xx_rt_wcscmp(r->name,L"directory_block_index"))text=L"Physical file block index containing one page of the logical stream directory.";
 break;
 case 0x602b000aU:
 if(!xx_rt_wcscmp(r->name,L"stream_size"))text=L"0xFFFFFFFF denotes an absent stream; other values are byte sizes.";
 break;
 case 0x602b000bU:
 if(!xx_rt_wcscmp(r->name,L"stream_block_index"))text=L"Physical file block index in block_size-byte units.";
 break;
 case 0x602b000dU:
 if(!xx_rt_wcscmp(r->name,L"alignment_shift"))text=L"Slice alignment is 1 << alignment_shift bytes.";
 break;
 case 0x602b000fU:
 if(!xx_rt_wcscmp(r->name,L"alignment_shift"))text=L"Slice alignment is 1 << alignment_shift bytes.";
 break;
 case 0x602b0010U:
 if(!xx_rt_wcscmp(r->name,L"alignment_shift"))text=L"Slice alignment is 1 << alignment_shift bytes.";
 break;
 case 0x602b0012U:
 if(!xx_rt_wcscmp(r->name,L"type_list_offset"))text=L"Relative to the resource map start.";
 if(!xx_rt_wcscmp(r->name,L"name_list_offset"))text=L"Relative to the resource map start.";
 break;
 case 0x602b0013U:
 if(!xx_rt_wcscmp(r->name,L"type_count_minus_one"))text=L"Encoded count minus one; 0xFFFF denotes no types.";
 break;
 case 0x602b0014U:
 if(!xx_rt_wcscmp(r->name,L"resource_count_minus_one"))text=L"Number of references minus one.";
 if(!xx_rt_wcscmp(r->name,L"references_offset"))text=L"Relative to the beginning of the type list, including its count word.";
 break;
 case 0x602b0015U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the name list; 0xFFFF means unnamed.";
 if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Relative to the data area; points to the resource length word.";
 break;
 case 0x602b0018U:
 if(!xx_rt_wcscmp(r->name,L"entry_point"))text=L"Byte offset in the loaded application image.";
 if(!xx_rt_wcscmp(r->name,L"symbol_table_address"))text=L"Application-image address retained as stored; zero means absent.";
 break;
 case 0x602b0019U:
 if(!xx_rt_wcscmp(r->name,L"relocation_offset"))text=L"Byte offset of the location to relocate in the application image.";
 break;
 case 0x602b001aU:
 if(!xx_rt_wcscmp(r->name,L"version_or_instruction"))text=L"Module-header-location version on firmware 17 or later; padding or an entry instruction in older/homebrew images.";
 if(!xx_rt_wcscmp(r->name,L"version_offset"))text=L"Module-version byte offset on firmware 17 or later; reserved on older NRO images.";
 break;
 case 0x602b001bU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 requests aligned header; bit 1 marks compression on firmware 23 or later.";
 if(!xx_rt_wcscmp(r->name,L"additional_header_offset"))text=L"Additional NRA0 header offset on firmware 23 or later; reserved in older images.";
 if(!xx_rt_wcscmp(r->name,L"dso_handle_offset"))text=L"Image-relative DSO handle offset.";
 if(!xx_rt_wcscmp(r->name,L"embedded_offset"))text=L"Image-relative embedded metadata offset; older tooling names this API-info offset.";
 break;
 case 0x602b001cU:
 if(!xx_rt_wcscmp(r->name,L"icon_offset"))text=L"Relative to this ASET header.";
 if(!xx_rt_wcscmp(r->name,L"nacp_offset"))text=L"Relative to this ASET header.";
 if(!xx_rt_wcscmp(r->name,L"romfs_offset"))text=L"Relative to this ASET header.";
 break;
 case 0x602b001dU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bits 0..2 select section compression; bits 3..5 select decompressed-section SHA-256 checks. Bit 6 selects execute-only memory; bit 7 selects Zstandard instead of LZ4 on newer runtimes.";
 if(!xx_rt_wcscmp(r->name,L"text_address"))text=L"Image-relative virtual address.";
 if(!xx_rt_wcscmp(r->name,L"ro_address"))text=L"Image-relative virtual address.";
 if(!xx_rt_wcscmp(r->name,L"data_address"))text=L"Image-relative virtual address.";
 if(!xx_rt_wcscmp(r->name,L"embedded_offset"))text=L"Offset within decompressed rodata; older tooling names this API-info offset.";
 if(!xx_rt_wcscmp(r->name,L"dynstr_offset"))text=L"Offset within decompressed rodata.";
 if(!xx_rt_wcscmp(r->name,L"dynsym_offset"))text=L"Offset within decompressed rodata.";
 break;
 case 0x602b001eU:
 if(!xx_rt_wcscmp(r->name,L"encoded_entry_point"))text=L"XOR-encoded entry-point word; encoding key depends on retail/debug variant.";
 if(!xx_rt_wcscmp(r->name,L"encoded_kernel_thunk_address"))text=L"XOR-encoded kernel-thunk address word; not a direct virtual address.";
 break;
 case 0x602b0025U:
 if(!xx_rt_wcscmp(r->name,L"present_page_count"))text=L"Number of stored 4096-byte physical memory pages.";
 if(!xx_rt_wcscmp(r->name,L"addressable_page_count"))text=L"Number of bits in the page-presence bitmap.";
 break;
 case 0x602b002aU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the section-name string table.";
 break;
 case 0x602b002bU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the section-name string table.";
 break;
 case 0x602b002cU:
 if(!xx_rt_wcscmp(r->name,L"module_name_offset"))text=L"Offset in the external module-name string table, not a byte offset in this REL image.";
 if(!xx_rt_wcscmp(r->name,L"prolog_offset"))text=L"Byte offset within the corresponding section.";
 if(!xx_rt_wcscmp(r->name,L"epilog_offset"))text=L"Byte offset within the corresponding section.";
 if(!xx_rt_wcscmp(r->name,L"unresolved_offset"))text=L"Byte offset within the corresponding section.";
 break;
 case 0x602b002fU:
 if(!xx_rt_wcscmp(r->name,L"offset_and_executable"))text=L"Low bit marks executable; bits 2..31 are the aligned file byte offset (bit 1 is excluded). Zero offset with nonzero size is BSS.";
 break;
 case 0x602b0031U:
 if(!xx_rt_wcscmp(r->name,L"offset_delta"))text=L"Byte delta from the preceding patch position in the current section.";
 if(!xx_rt_wcscmp(r->name,L"relocation_type"))text=L"201=NOP, 202=section selection, 203=end of table; other values are PowerPC relocations.";
 break;
 case 0x602b0033U:
 if(!xx_rt_wcscmp(r->name,L"x86_rva"))text=L"Relative virtual address in the original x86 image.";
 if(!xx_rt_wcscmp(r->name,L"arm64_rva"))text=L"Relative virtual address in the translated ARM64 image.";
 break;
 case 0x602b0034U:
 if(!xx_rt_wcscmp(r->name,L"offset_to_next_entry"))text=L"Byte extent of the code regions following this 16-byte stub.";
 if(!xx_rt_wcscmp(r->name,L"next_entry_offset"))text=L"File-relative byte offset of the next BLCK stub; zero terminates.";
 break;
 case 0x602b0035U:
 if(!xx_rt_wcscmp(r->name,L"metadata_and_step"))text=L"High nibble selects edge fields; low 28 bits encode forward distance in four-byte words, 0x0FFFFFFF terminates.";
 break;
 case 0x602b0036U:
 if(!xx_rt_wcscmp(r->name,L"metadata_and_step"))text=L"High nibble selects edge fields; low 28 bits encode forward distance in four-byte words, 0x0FFFFFFF terminates.";
 break;
 case 0x602b0037U:
 if(!xx_rt_wcscmp(r->name,L"metadata_and_step"))text=L"High nibble selects edge fields; low 28 bits encode forward distance in four-byte words, 0x0FFFFFFF terminates.";
 break;
 case 0x602b0038U:
 if(!xx_rt_wcscmp(r->name,L"metadata_and_step"))text=L"High nibble selects edge fields; low 28 bits encode forward distance in four-byte words, 0x0FFFFFFF terminates.";
 break;
 case 0x602b0039U:
 if(!xx_rt_wcscmp(r->name,L"record_type"))text=L"0=module header, 1=comment, 2=load, 3=fixup, 4=8087 fixup, 5=image end, 6=resource, 7=read/write end, 8=linear fixup.";
 break;
 case 0x602b003bU:
 if(!xx_rt_wcscmp(r->name,L"size_and_flags"))text=L"Low 28 bits encode segment byte size; high nibble carries segment attributes.";
 break;
 case 0x602b003cU:
 if(!xx_rt_wcscmp(r->name,L"segment_offset"))text=L"Offset within the selected load segment.";
 break;
 case 0x602b0040U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Payload bytes plus the trailing one-byte checksum; excludes this three-byte record header.";
 break;
 case 0x602b0041U:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Byte sum of the complete record is zero; zero also denotes an omitted checksum in legacy tools.";
 break;
 case 0x602b0043U:
 if(!xx_rt_wcscmp(r->name,L"pages_in_file"))text=L"Number of 512-byte pages; extender chain location follows the native reader convention.";
 if(!xx_rt_wcscmp(r->name,L"header_paragraphs"))text=L"Number of 16-byte paragraphs in the MZ header.";
 if(!xx_rt_wcscmp(r->name,L"min_alloc_paragraphs"))text=L"Allocation count in 16-byte paragraphs.";
 if(!xx_rt_wcscmp(r->name,L"max_alloc_paragraphs"))text=L"Allocation count in 16-byte paragraphs.";
 break;
 case 0x602b0044U:
 if(!xx_rt_wcscmp(r->name,L"makepm_version"))text=L"Encoded version multiplied by 100.";
 if(!xx_rt_wcscmp(r->name,L"next_header_offset"))text=L"Byte offset relative to the containing DOS executable.";
 if(!xx_rt_wcscmp(r->name,L"program_paragraphs"))text=L"Number of 16-byte paragraphs in the program.";
 if(!xx_rt_wcscmp(r->name,L"transfer_buffer_size"))text=L"Byte size; zero encodes the default 8192-byte buffer.";
 break;
 case 0x602b0046U:
 if(!xx_rt_wcscmp(r->name,L"type_and_memory_flags"))text=L"Low 30 bits are the HUNK type; top two bits encode memory attributes.";
 break;
 case 0x602b0047U:
 if(!xx_rt_wcscmp(r->name,L"longword_count"))text=L"Count in four-byte longwords.";
 break;
 case 0x602b0049U:
 if(!xx_rt_wcscmp(r->name,L"size_and_memory_flags"))text=L"Low 30 bits encode allocation size in longwords; top bits are memory flags. Both top bits set add an explicit memory-attribute word.";
 break;
 case 0x602b004dU:
 if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Byte offset of the relocation in its source hunk.";
 break;
 case 0x602b0050U:
 if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Byte offset of the relocation in its source hunk.";
 break;
 case 0x602b0052U:
 if(!xx_rt_wcscmp(r->name,L"name_longwords"))text=L"Name length in four-byte longwords.";
 break;
 case 0x602b0054U:
 if(!xx_rt_wcscmp(r->name,L"entry_offset"))text=L"Byte offset within the entry subspace.";
 break;
 case 0x602b0055U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset in the space string table.";
 break;
 case 0x602b0056U:
 if(!xx_rt_wcscmp(r->name,L"space_index"))text=L"Signed space index; negative values retain their sentinel meaning.";
 if(!xx_rt_wcscmp(r->name,L"file_offset"))text=L"SOM-relative byte offset of the initialization image; used only when initialization_size is nonzero.";
 if(!xx_rt_wcscmp(r->name,L"subspace_start"))text=L"Virtual byte address relative to the start of the owning space.";
 if(!xx_rt_wcscmp(r->name,L"alignment_and_reserved"))text=L"Packed alignment/reserved word retained without splitting: HP structure diagram specifies 5/27 bits while descriptive text gives 16/16.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset in the space string table.";
 if(!xx_rt_wcscmp(r->name,L"fixup_request_index"))text=L"Signed index of the first fixup; negative values denote no index.";
 break;
 case 0x602b0057U:
 if(!xx_rt_wcscmp(r->name,L"space_index"))text=L"Signed space index; negative values retain their sentinel meaning.";
 if(!xx_rt_wcscmp(r->name,L"initialization_pattern"))text=L"Repeated 32-bit initialization bit pattern for the subspace; not a file offset.";
 if(!xx_rt_wcscmp(r->name,L"subspace_start"))text=L"Virtual byte address relative to the start of the owning space.";
 if(!xx_rt_wcscmp(r->name,L"alignment_and_reserved"))text=L"Packed alignment/reserved word retained without splitting: HP structure diagram specifies 5/27 bits while descriptive text gives 16/16.";
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset in the space string table.";
 if(!xx_rt_wcscmp(r->name,L"fixup_request_index"))text=L"Signed index of the first fixup; negative values denote no index.";
 break;
 case 0x602b0058U:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Byte offset in the symbol string table.";
 if(!xx_rt_wcscmp(r->name,L"qualifier_name_offset"))text=L"Byte offset in the symbol string table.";
 break;
 case 0x602b005aU:
 if(!xx_rt_wcscmp(r->name,L"text_alignment_shift"))text=L"Power-of-two alignment exponent.";
 if(!xx_rt_wcscmp(r->name,L"data_alignment_shift"))text=L"Power-of-two alignment exponent.";
 if(!xx_rt_wcscmp(r->name,L"text_page_size"))text=L"Encoded page-size request; preserved without conversion.";
 if(!xx_rt_wcscmp(r->name,L"data_page_size"))text=L"Encoded page-size request; preserved without conversion.";
 if(!xx_rt_wcscmp(r->name,L"stack_page_size"))text=L"Encoded page-size request; preserved without conversion.";
 break;
 case 0x602b005cU:
 if(!xx_rt_wcscmp(r->name,L"import_files_offset"))text=L"Relative to the loader section.";
 if(!xx_rt_wcscmp(r->name,L"strings_offset"))text=L"Relative to the loader section.";
 break;
 case 0x602b005dU:
 case 0x602b005eU:
 if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Relative to the loader string table.";
 if(!xx_rt_wcscmp(r->name,L"parameter_type_offset"))text=L"Byte offset from the loader string table to the parameter type-check string (after its length field); zero means absent.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXEXM_LIMIT 20000U
bool sxexm_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxexm_read(sx_context *c,uint64_t p,void *b,size_t n){return sxexm_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxexm_uint(const uint8_t *b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
uint16_t sxexm16(const uint8_t *b,bool be){return (uint16_t)sxexm_uint(b,2,be);}
uint32_t sxexm32(const uint8_t *b,bool be){return (uint32_t)sxexm_uint(b,4,be);}
/* Native readers can authenticate aliases and damaged optional records. Keep
 * earlier bounded physical metadata, and leave conflicting later interpretations
 * opaque instead of discarding the entire useful header view. */
bool sxexm_free(sx_context *c,uint64_t p,uint64_t n){for(size_t i=0;i<c->count;i++){uint64_t at=(uint64_t)(c->items[i].offset-c->f->base_address),z=(uint64_t)c->items[i].total_size;if(p<at+z&&at<p+n)return false;}return true;}
bool sxexm_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(!sxexm_span(c,p,n))return false;if(!sxexm_free(c,p,n))return true;return c->count>=SXEXM_LIMIT||sx_add(c,l,(int64_t)p,(int64_t)n);}
bool sxexm_table(sx_context *c,const sx_layout *l,uint64_t p,uint64_t n){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n||n>SXEXM_LIMIT||!sxexm_span(c,p,n*z))return true;if(!sxexm_free(c,p,n*z))return true;return c->count>=SXEXM_LIMIT||sx_table(c,l,(int64_t)p,(int64_t)z,n);}
bool sxexm_word(sx_context *c,uint64_t p,unsigned n,bool be,uint64_t *v){uint8_t b[8];if(n>8||!sxexm_read(c,p,b,n))return false;*v=sxexm_uint(b,n,be);return true;}
static int sxexm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
bool sxexm_finish(sx_context *c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxexm_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxexm_order);return !c->failed;}
static bool sx_executablemore_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_AMIGAHUNK:case XX_FILE_TYPE_DOS16M:case XX_FILE_TYPE_DOS4G:case XX_FILE_TYPE_RESOURCEFORK:case XX_FILE_TYPE_XBOX_XBE:case XX_FILE_TYPE_MICROSOFT_MSF:case XX_FILE_TYPE_PYC:case XX_FILE_TYPE_VTECH_VZ:case XX_FILE_TYPE_XAMARIN_COMPRESSED_ASSEMBLY:case XX_FILE_TYPE_MUB:case XX_FILE_TYPE_CGC:case XX_FILE_TYPE_NINTENDO_NRO:case XX_FILE_TYPE_NINTENDO_NSO:case XX_FILE_TYPE_WINDOWS_DMP64:case XX_FILE_TYPE_OMF:case XX_FILE_TYPE_XTAC:case XX_FILE_TYPE_PEBBLE:case XX_FILE_TYPE_HP_SOM:case XX_FILE_TYPE_QNX_LMF:case XX_FILE_TYPE_NINTENDO_REL:case XX_FILE_TYPE_XCOFF:return true;default:return false;}}
static bool sx_executablemore_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
if(c->f->file_type==XX_FILE_TYPE_AMIGAHUNK)return sx_amigahunk_build(c);
if(c->f->file_type==XX_FILE_TYPE_DOS16M)return sx_dos16m_build(c);
if(c->f->file_type==XX_FILE_TYPE_DOS4G)return sx_dos16m_build(c);
if(c->f->file_type==XX_FILE_TYPE_RESOURCEFORK)return sx_resourcefork_build(c);
if(c->f->file_type==XX_FILE_TYPE_XBOX_XBE)return sx_xbox_xbe_build(c);
if(c->f->file_type==XX_FILE_TYPE_MICROSOFT_MSF)return sx_microsoft_msf_build(c);
if(c->f->file_type==XX_FILE_TYPE_PYC)return sx_pyc_build(c);
if(c->f->file_type==XX_FILE_TYPE_VTECH_VZ)return sx_vtech_vz_build(c);
if(c->f->file_type==XX_FILE_TYPE_XAMARIN_COMPRESSED_ASSEMBLY)return sx_xamarin_compressed_assembly_build(c);
if(c->f->file_type==XX_FILE_TYPE_MUB)return sx_mub_build(c);
if(c->f->file_type==XX_FILE_TYPE_CGC)return sx_cgc_build(c);
if(c->f->file_type==XX_FILE_TYPE_NINTENDO_NRO)return sx_nintendo_nro_build(c);
if(c->f->file_type==XX_FILE_TYPE_NINTENDO_NSO)return sx_nintendo_nso_build(c);
if(c->f->file_type==XX_FILE_TYPE_WINDOWS_DMP64)return sx_windows_dmp64_build(c);
if(c->f->file_type==XX_FILE_TYPE_OMF)return sx_omf_build(c);
if(c->f->file_type==XX_FILE_TYPE_XTAC)return sx_xtac_build(c);
if(c->f->file_type==XX_FILE_TYPE_PEBBLE)return sx_pebble_build(c);
if(c->f->file_type==XX_FILE_TYPE_HP_SOM)return sx_hp_som_build(c);
if(c->f->file_type==XX_FILE_TYPE_QNX_LMF)return sx_qnx_lmf_build(c);
if(c->f->file_type==XX_FILE_TYPE_NINTENDO_REL)return sx_nintendo_rel_build(c);
if(c->f->file_type==XX_FILE_TYPE_XCOFF)return sx_xcoff_build(c);
return false;}
const sx_family sx_executablemore_family={sx_executablemore_supports,sx_executablemore_build,sx_executablemore_layouts,SX_COUNT(sx_executablemore_layouts),sx_executablemore_comment};
