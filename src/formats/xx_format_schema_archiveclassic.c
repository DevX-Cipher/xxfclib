/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_archiveclassic_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archiveclassic.h"
static const xx_data_struct_field_desc sxacl_zzz_member_fields[] = {
 SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
 SX_FIELD("compressed_size","uint32",3,4,SX_SIZE),
 SX_FIELD("uncompressed_size","uint32",7,4,SX_SIZE),
 SX_FIELD("name","char[12]",11,12,SX_NONE),
 SX_FIELD("reserved","uint8",23,1,SX_NONE),
};
const sx_layout sxacl_zzz_member = {UINT32_C(0x60500005),"zzz_member",sxacl_zzz_member_fields,SX_COUNT(sxacl_zzz_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_bwf_member_fields[] = {
 SX_FIELD("tag","uint8",0,1,SX_SIGNATURE),
 SX_FIELD("name","char[13]",1,13,SX_NONE),
 SX_FIELD("dos_timestamp","uint32",14,4,SX_NONE),
 SX_FIELD("compressed_size","int32",18,4,SX_SIZE),
};
const sx_layout sxacl_bwf_member = {UINT32_C(0x60500018),"bwf_member",sxacl_bwf_member_fields,SX_COUNT(sxacl_bwf_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_zap_member_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("dos_time","uint16",13,2,SX_NONE),
 SX_FIELD("dos_date","uint16",15,2,SX_NONE),
 SX_FIELD("compressed_size","int32",17,4,SX_SIZE),
};
const sx_layout sxacl_zap_member = {UINT32_C(0x60500019),"zap_member",sxacl_zap_member_fields,SX_COUNT(sxacl_zap_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_stork_member_fields[] = {
 SX_FIELD("name_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_NONE),
 SX_FIELD("compressed_size","int32",13,4,SX_SIZE),
 SX_FIELD("terminator","char[1]",17,1,SX_SIGNATURE),
};
const sx_layout sxacl_stork_member = {UINT32_C(0x6050001a),"stork_member",sxacl_stork_member_fields,SX_COUNT(sxacl_stork_member_fields),SX_LE};
static const xx_data_struct_field_desc sxacl_archiveclassic_dcl_fields[] = {
 SX_FIELD("literal_mode","uint8",0,1,SX_NONE),
 SX_FIELD("dictionary_bits","uint8",1,1,SX_NONE),
};
static const sx_layout sxacl_archiveclassic_dcl = {UINT32_C(0x60500034),"archiveclassic_dcl",sxacl_archiveclassic_dcl_fields,SX_COUNT(sxacl_archiveclassic_dcl_fields),SX_LE};
static const sx_layout *const sx_archiveclassic_layouts[] = {
 &sxacl_dtpacked_header,
 &sxacl_zlwb_header,
 &sxacl_zlwb_blob,
 &sxacl_zz_header,
 &sxacl_zzz_member,
 &sxacl_jgpak_header,
 &sxacl_jgpak_version_size,
 &sxacl_jgpak_count,
 &sxacl_jgpak_name_size,
 &sxacl_jgpak_member,
 &sxacl_borlandpack_header,
 &sxacl_borlandpack_attributes,
 &sxacl_borlandpack_size,
 &sxacl_borlandpack_lzw_flags,
 &sxacl_jetbbs_member,
 &sxacl_jetbbs_crc16,
 &sxacl_jetbbs_os,
 &sxacl_jetbbs_extension_size,
 &sxacl_jetbbs_extension_type,
 &sxacl_jetbbs_sizes64,
 &sxacl_qualitas_header,
 &sxacl_qualitas_member,
 &sxacl_qualitas_crc32,
 &sxacl_bwf_member,
 &sxacl_zap_member,
 &sxacl_stork_member,
 &sxacl_ascendbackup_name_size,
 &sxacl_ascendbackup_size,
 &sxacl_fmc1_header,
 &sxacl_fmc1_member,
 &sxacl_spis_header,
 &sxacl_spis_member,
 &sxacl_bwcf_header,
 &sxacl_bwcf_name_v1,
 &sxacl_bwcf_name_v2,
 &sxacl_bwcf_directory_size,
 &sxacl_bwcf_member,
 &sxacl_bwcf_block_size,
 &sxacl_cmp_header,
 &sxacl_fls_count,
 &sxacl_fls_header_record,
 &sxacl_fls_member,
 &sxacl_fls_name_header,
 &sxacl_fls_component_offset,
 &sxacl_fls_component_size,
 &sxacl_genius_header,
 &sxacl_genius_member,
 &sxacl_genius_block_size,
 &sxacl_genius_footer,
 &sxacl_hzl_header,
 &sxacl_kboom_header,
 &sxacl_archiveclassic_dcl,
};
static bool sx_archiveclassic_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60500000U||id>=0x60510000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60500001U:
 if(!xx_rt_wcscmp(r->name,L"uninitialized1"))text=L"Uninitialized writer memory, not a filename or checksum";
 if(!xx_rt_wcscmp(r->name,L"uninitialized2"))text=L"Uninitialized writer memory";
 break;
 case 0x60500003U:
 if(!xx_rt_wcscmp(r->name,L"record_size"))text=L"Decoded record width, 272 or 552";
 break;
 case 0x6050000bU:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"Archive-wide method";
 if(!xx_rt_wcscmp(r->name,L"version"))text=L"100 denotes version 1.00";
 break;
 case 0x6050000cU:
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Unidentified checksum algorithm";
 break;
 case 0x6050000eU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Unix compress flags: 0x80 block mode, low five bits maximum code width; the 1F9D magic is not stored";
 break;
 case 0x6050000fU:
 if(!xx_rt_wcscmp(r->name,L"header_payload_size"))text=L"Excludes size and checksum bytes";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"-mg0- stored, -mg4- lh4, -mg5- lh5";
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Level 1 includes extended-header bytes";
 break;
 case 0x60500012U:
 if(!xx_rt_wcscmp(r->name,L"next_header_size"))text=L"Zero ends the extension chain; nonzero counts the physical extension bytes following the current length word";
 break;
 case 0x60500013U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"0 header CRC, 1 replacement filename, 2 directory, 0x42 64-bit size copies";
 break;
 case 0x60500015U:
 if(!xx_rt_wcscmp(r->name,L"directory_size"))text=L"Excludes the 14-byte archive header";
 break;
 case 0x60500016U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Includes the four-byte checksum preceding DCL data";
 if(!xx_rt_wcscmp(r->name,L"disk_number"))text=L"1 means current volume";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"Observed 0 and 1 both carry DCL; not a codec selector";
 break;
 case 0x60500018U:
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"Native name stops before the last slot, which may contain stale memory";
 break;
 case 0x6050001fU:
 if(!xx_rt_wcscmp(r->name,L"method_tag"))text=L"NON, RLE, LZH, CUS or LH5";
 if(!xx_rt_wcscmp(r->name,L"uncompressed_size"))text=L"Total plaintext size of this segment";
 if(!xx_rt_wcscmp(r->name,L"archive_type"))text=L"0 single stream, 1 named members";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Byte sum, used only by type 0";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"0..2; 2 means XOR-masked data";
 break;
 case 0x60500020U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 NON, 1 RLE, 2 LZH, 3 CUS, 4 LH5";
 if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Sum of uncompressed bytes";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"0..2; 2 means XOR-masked data";
 break;
 case 0x60500025U:
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"Includes the four-byte repeated plain length";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 LZHUF, 3 stored";
 break;
 case 0x60500027U:
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"1 framed LZW/stored; 2 LZSS or DCL selected by payload preamble";
 if(!xx_rt_wcscmp(r->name,L"variant"))text=L"9 old, 11 newer";
 if(!xx_rt_wcscmp(r->name,L"block_size"))text=L"LZW framing width, 0x1000 bytes";
 break;
 case 0x60500028U:
 if(!xx_rt_wcscmp(r->name,L"record_count"))text=L"Includes the leading header record; member count is one less";
 break;
 case 0x6050002aU:
 if(!xx_rt_wcscmp(r->name,L"compressed"))text=L"0 stored, 1 FLS-LZ";
 if(!xx_rt_wcscmp(r->name,L"name_reference"))text=L"Relative to the start of the name block";
 if(!xx_rt_wcscmp(r->name,L"tail_size"))text=L"Padding following this member payload";
 break;
 case 0x6050002cU:
 if(!xx_rt_wcscmp(r->name,L"component_offset"))text=L"Relative to the start of the name block";
 break;
 case 0x6050002eU:
 if(!xx_rt_wcscmp(r->name,L"uninitialized"))text=L"Uninitialized writer memory, not a version";
 break;
 case 0x6050002fU:
 if(!xx_rt_wcscmp(r->name,L"write_time"))text=L"Stored timestamp; epoch unspecified";
 if(!xx_rt_wcscmp(r->name,L"method"))text=L"0 stored, 1 separately framed DCL blocks";
 if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Includes the stored NUL";
 break;
 case 0x60500031U:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"Unfinalized reflected EDB88320 accumulator seeded with 0xFFFFFFFF, equivalent to CRC-32/JAMCRC";
 break;
 case 0x60500034U:
 if(!xx_rt_wcscmp(r->name,L"literal_mode"))text=L"0 binary or 1 coded literals";
 if(!xx_rt_wcscmp(r->name,L"dictionary_bits"))text=L"4, 5 or 6; PKWARE DCL dictionary parameter";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXACL_LIMIT 20000U
bool sxacl_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxacl_read(sx_context*c,uint64_t p,void*b,size_t n){return sxacl_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxacl_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxacl_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxacl_read(c,p,b,n))return false;*v=sxacl_uint(b,n,be);return true;}
/* Keep physical descriptors sorted; aliases share the first bounded metadata span. */
bool sxacl_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t n=(uint64_t)(f->rel_offset+f->size);if(c->count>=SXACL_LIMIT||!sxacl_span(c,p,n))return false;int64_t absolute=c->f->base_address+(int64_t)p;size_t lo=0,hi=c->count;while(lo<hi){size_t m=lo+(hi-lo)/2;if(c->items[m].offset<absolute)lo=m+1;else hi=m;}if((lo<c->count&&c->items[lo].offset<absolute+(int64_t)n)||(lo&&c->items[lo-1].offset+c->items[lo-1].total_size>absolute))return true;size_t old=c->count;if(!sx_add(c,l,(int64_t)p,(int64_t)n))return false;xx_data_struct row=c->items[old];xx_rt_memmove(c->items+lo+1,c->items+lo,(old-lo)*sizeof(row));c->items[lo]=row;return true;}
bool sxacl_dcl(sx_context*c,uint64_t p,uint64_t n){uint8_t h[2];return n<2||!sxacl_read(c,p,h,2)||h[0]>1||h[1]<4||h[1]>6?true:sxacl_add(c,&sxacl_archiveclassic_dcl,p);}
bool sxacl_chain(sx_context*c,const sx_layout*l,uint64_t p,unsigned hs,unsigned sizeoff,bool sign,bool dcl){for(unsigned i=0;i<SXACL_LIMIT&&p<(uint64_t)c->size;i++){uint8_t h[24];if(hs>sizeof(h)||sizeoff>hs||hs-sizeoff<4||!sxacl_read(c,p,h,hs))return false;if((l==&sxacl_zzz_member&&xx_rt_memcmp(h,"ZZZ",3))||(l==&sxacl_bwf_member&&h[0]!=1)||((l==&sxacl_zap_member||l==&sxacl_stork_member)&&(!h[0]||h[0]>12))||(l==&sxacl_stork_member&&h[17]!='$'))return false;uint64_t z=sxacl_uint(h+sizeoff,4,false);if((sign&&z>INT32_MAX)||!sxacl_span(c,p+hs,z)||!sxacl_add(c,l,p))return false;if(dcl&&!sxacl_dcl(c,p+hs,z))return false;p+=hs+z;}return true;}
static int sxacl_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxacl_finish(sx_context*c){size_t n=c->count;int64_t end=0;for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxacl_order);return !c->failed;}
static bool sx_archiveclassic_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_DTPACKED:case XX_FILE_TYPE_ZLWB:case XX_FILE_TYPE_ZZ:case XX_FILE_TYPE_ZZZ:case XX_FILE_TYPE_JGPAK:case XX_FILE_TYPE_BORLANDPACK:case XX_FILE_TYPE_JETBBS:case XX_FILE_TYPE_QUALITAS:case XX_FILE_TYPE_BWF:case XX_FILE_TYPE_ZAP:case XX_FILE_TYPE_STORK:case XX_FILE_TYPE_ASCENDBACKUP:case XX_FILE_TYPE_FMC1:case XX_FILE_TYPE_SPIS:case XX_FILE_TYPE_BWCF:case XX_FILE_TYPE_CMP:case XX_FILE_TYPE_FLS:case XX_FILE_TYPE_GENIUS:case XX_FILE_TYPE_HZL:case XX_FILE_TYPE_KBOOM:return true;default:return false;}}
static bool sx_archiveclassic_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_DTPACKED:ok=sx_dtpacked_build(c);break;case XX_FILE_TYPE_ZLWB:ok=sx_zlwb_build(c);break;case XX_FILE_TYPE_ZZ:ok=sx_zz_build(c);break;case XX_FILE_TYPE_ZZZ:ok=sx_zzz_build(c);break;case XX_FILE_TYPE_JGPAK:ok=sx_jgpak_build(c);break;case XX_FILE_TYPE_BORLANDPACK:ok=sx_borlandpack_build(c);break;case XX_FILE_TYPE_JETBBS:ok=sx_jetbbs_build(c);break;case XX_FILE_TYPE_QUALITAS:ok=sx_qualitas_build(c);break;case XX_FILE_TYPE_BWF:ok=sx_bwf_build(c);break;case XX_FILE_TYPE_ZAP:ok=sx_zap_build(c);break;case XX_FILE_TYPE_STORK:ok=sx_stork_build(c);break;case XX_FILE_TYPE_ASCENDBACKUP:ok=sx_ascendbackup_build(c);break;case XX_FILE_TYPE_FMC1:ok=sx_fmc1_build(c);break;case XX_FILE_TYPE_SPIS:ok=sx_spis_build(c);break;case XX_FILE_TYPE_BWCF:ok=sx_bwcf_build(c);break;case XX_FILE_TYPE_CMP:ok=sx_cmp_build(c);break;case XX_FILE_TYPE_FLS:ok=sx_fls_build(c);break;case XX_FILE_TYPE_GENIUS:ok=sx_genius_build(c);break;case XX_FILE_TYPE_HZL:ok=sx_hzl_build(c);break;case XX_FILE_TYPE_KBOOM:ok=sx_kboom_build(c);break;default:break;}(void)ok;return c->count&&sxacl_finish(c);}
const sx_family sx_archiveclassic_family={sx_archiveclassic_supports,sx_archiveclassic_build,sx_archiveclassic_layouts,SX_COUNT(sx_archiveclassic_layouts),sx_archiveclassic_comment};
