/* SPDX-License-Identifier: MIT
 * Physical archive metadata. See docs/data_struct_archivemore_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_archivemore.h"
static const xx_data_struct_field_desc sxar_rtpatch_header_fields[] = {
    SX_FIELD("magic","char[2]",0,2,SX_SIGNATURE),
    SX_FIELD("generation","uint16",2,2,SX_ID),
    SX_FIELD("builder_metadata","uint8[22]",4,22,SX_NONE),
};
static const sx_layout sxar_rtpatch_header = {UINT32_C(0x601c0001),"rtpatch_header",sxar_rtpatch_header_fields,SX_COUNT(sxar_rtpatch_header_fields),SX_LE};
static const xx_data_struct_field_desc sxar_rtpatch_destination_count_fields[] = {
    SX_FIELD("destination_count","uint8",0,1,SX_COUNT_PROP),
};
static const sx_layout sxar_rtpatch_destination_count = {UINT32_C(0x601c0002),"rtpatch_destination_count",sxar_rtpatch_destination_count_fields,SX_COUNT(sxar_rtpatch_destination_count_fields),SX_LE};
static const xx_data_struct_field_desc sxar_rtpatch_stream_sizes_fields[] = {
    SX_FIELD("unpacked_size","uint32",0,4,SX_SIZE),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
};
static const sx_layout sxar_rtpatch_stream_sizes = {UINT32_C(0x601c0003),"rtpatch_stream_sizes",sxar_rtpatch_stream_sizes_fields,SX_COUNT(sxar_rtpatch_stream_sizes_fields),SX_LE};
static const xx_data_struct_field_desc sxar_rtpatch_destination_fields[] = {
    SX_FIELD("name","char[14]",0,14,SX_STRING),
    SX_FIELD("attributes","uint16",14,2,SX_FLAGS),
    SX_FIELD("unpacked_size","uint32",16,4,SX_SIZE),
    SX_FIELD("date","uint16",20,2,SX_NONE),
    SX_FIELD("time","uint16",22,2,SX_NONE),
    SX_FIELD("builder_metadata","uint8[10]",24,10,SX_NONE),
};
static const sx_layout sxar_rtpatch_destination = {UINT32_C(0x601c0004),"rtpatch_destination",sxar_rtpatch_destination_fields,SX_COUNT(sxar_rtpatch_destination_fields),SX_LE};
static const xx_data_struct_field_desc sxar_rtpatch_codec_header_fields[] = {
    SX_FIELD("magic","uint16",0,2,SX_SIGNATURE),
    SX_FIELD("raw_literal_flag","uint8",2,1,SX_FLAGS),
    SX_FIELD("marker","uint8",3,1,SX_SIGNATURE),
    SX_FIELD("rescale_periods","uint24",4,3,SX_NONE),
    SX_FIELD("window_and_first_bits","uint8",7,1,SX_NONE),
};
static const sx_layout sxar_rtpatch_codec_header = {UINT32_C(0x601c0005),"rtpatch_codec_header",sxar_rtpatch_codec_header_fields,SX_COUNT(sxar_rtpatch_codec_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_rtpatch_name_size_fields[] = {
    SX_FIELD("name_size","uint8",0,1,SX_SIZE),
};
static const sx_layout sxar_rtpatch_name_size = {UINT32_C(0x601c0006),"rtpatch_name_size",sxar_rtpatch_name_size_fields,SX_COUNT(sxar_rtpatch_name_size_fields),SX_LE};
static const xx_data_struct_field_desc sxar_packit_marker_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
static const sx_layout sxar_packit_marker = {UINT32_C(0x601c0017),"packit_marker",sxar_packit_marker_fields,SX_COUNT(sxar_packit_marker_fields),SX_BE};
static const xx_data_struct_field_desc sxar_packit_stored_header_fields[] = {
    SX_FIELD("name_size","uint8",0,1,SX_SIZE),
    SX_FIELD("name","char[63]",1,63,SX_STRING),
    SX_FIELD("file_type","char[4]",64,4,SX_ID),
    SX_FIELD("creator","char[4]",68,4,SX_ID),
    SX_FIELD("finder_flags","uint16",72,2,SX_FLAGS),
    SX_FIELD("locked","uint16",74,2,SX_FLAGS),
    SX_FIELD("data_fork_size","uint32",76,4,SX_SIZE),
    SX_FIELD("resource_fork_size","uint32",80,4,SX_SIZE),
    SX_FIELD("created","uint32",84,4,SX_NONE),
    SX_FIELD("modified","uint32",88,4,SX_NONE),
    SX_FIELD("header_crc16","uint16",92,2,SX_CHECKSUM),
};
static const sx_layout sxar_packit_stored_header = {UINT32_C(0x601c0018),"packit_stored_header",sxar_packit_stored_header_fields,SX_COUNT(sxar_packit_stored_header_fields),SX_BE};
static const xx_data_struct_field_desc sxar_packit_forks_crc_fields[] = {
    SX_FIELD("forks_crc16","uint16",0,2,SX_CHECKSUM),
};
static const sx_layout sxar_packit_forks_crc = {UINT32_C(0x601c0019),"packit_forks_crc",sxar_packit_forks_crc_fields,SX_COUNT(sxar_packit_forks_crc_fields),SX_BE};
static const sx_layout *const sx_archivemore_layouts[] = {
    &sxar_rtpatch_header,
    &sxar_rtpatch_destination_count,
    &sxar_rtpatch_stream_sizes,
    &sxar_rtpatch_destination,
    &sxar_rtpatch_codec_header,
    &sxar_rtpatch_name_size,
    &sxar_mpq_header_v0,
    &sxar_mpq_header_v1,
    &sxar_mpq_header_v2,
    &sxar_mpq_header_v3,
    &sxar_mpq_high_block_entry,
    &sxar_applesingle_header,
    &sxar_applesingle_entry,
    &sxar_macbinary1_header,
    &sxar_macbinary2_header,
    &sxar_macbinary3_header,
    &sxar_binaryii_header,
    &sxar_nufx_master,
    &sxar_nufx_record,
    &sxar_nufx_option_size,
    &sxar_nufx_name_size,
    &sxar_nufx_thread,
    &sxar_packit_marker,
    &sxar_packit_stored_header,
    &sxar_packit_forks_crc,
    &sxar_stuffit_header,
    &sxar_stuffit_member,
    &sxar_compactpro_header,
    &sxar_compactpro_catalogue,
    &sxar_compactpro_name_size,
    &sxar_compactpro_directory,
    &sxar_compactpro_file,
    &sxar_egg_header,
    &sxar_egg_file,
    &sxar_egg_extra,
    &sxar_egg_block,
    &sxar_egg_end,
    &sxar_lzfse_raw_block,
    &sxar_lzfse_lzvn_block,
    &sxar_lzfse_v1_block,
    &sxar_lzfse_v2_block,
    &sxar_lzfse_end,
    &sxar_lzf_stored_block,
    &sxar_lzf_compressed_block,
    &sxar_lzf_end,
    &sxar_sixpack_header,
    &sxar_sixpack_chunk,
    &sxar_sixpack_file,
    &sxar_lbr_directory_entry,
    &sxar_pdp11ar_header,
    &sxar_pdp11ar_member,
    &sxar_bigaf_header,
    &sxar_bigaf_member,
    &sxar_bigaf_name_end,
};
static bool sx_archivemore_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x601c0000U||id>=0x601d0000U)return true;
    if(r->type&&!xx_rt_wcsncmp(r->type,L"ascii_",6)&&xx_var_get_type(&r->value)==XX_VAR_TYPE_BYTES)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x601c0004U:
        if(!xx_rt_wcscmp(r->name,L"date"))text=L"Packed DOS date/time bits.";
        if(!xx_rt_wcscmp(r->name,L"time"))text=L"Packed DOS date/time bits.";
        break;
    case 0x601c0005U:
        if(!xx_rt_wcscmp(r->name,L"rescale_periods"))text=L"Two packed 12-bit rescale periods; first in the high 12 bits.";
        if(!xx_rt_wcscmp(r->name,L"window_and_first_bits"))text=L"High nibble is the window selector; low nibble starts the compressed payload.";
        break;
    case 0x601c0007U:
        if(!xx_rt_wcscmp(r->name,L"sector_shift"))text=L"File sectors contain 512 multiplied by 2 raised to sector_shift bytes.";
        break;
    case 0x601c0008U:
        if(!xx_rt_wcscmp(r->name,L"sector_shift"))text=L"File sectors contain 512 multiplied by 2 raised to sector_shift bytes.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_low"))text=L"Low 32 bits of the byte offset; combine hash_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_low"))text=L"Low 32 bits of the byte offset; combine block_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        break;
    case 0x601c0009U:
        if(!xx_rt_wcscmp(r->name,L"sector_shift"))text=L"File sectors contain 512 multiplied by 2 raised to sector_shift bytes.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_low"))text=L"Low 32 bits of the byte offset; combine hash_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_low"))text=L"Low 32 bits of the byte offset; combine block_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        break;
    case 0x601c000aU:
        if(!xx_rt_wcscmp(r->name,L"sector_shift"))text=L"File sectors contain 512 multiplied by 2 raised to sector_shift bytes.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_low"))text=L"Low 32 bits of the byte offset; combine hash_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_low"))text=L"Low 32 bits of the byte offset; combine block_table_offset_high.";
        if(!xx_rt_wcscmp(r->name,L"hash_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        if(!xx_rt_wcscmp(r->name,L"block_table_offset_high"))text=L"Upper 16 bits of the byte offset.";
        break;
    case 0x601c000bU:
        if(!xx_rt_wcscmp(r->name,L"file_offset_high"))text=L"Upper 16 bits of a file offset; encrypted block-table entry contains the low word.";
        break;
    case 0x601c000eU:
        if(!xx_rt_wcscmp(r->name,L"window_vertical"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"window_horizontal"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        break;
    case 0x601c000fU:
        if(!xx_rt_wcscmp(r->name,L"window_vertical"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"window_horizontal"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"total_unpacked_size"))text=L"Reserved for compressed MacBinary files; not used by the plain native reader.";
        break;
    case 0x601c0010U:
        if(!xx_rt_wcscmp(r->name,L"window_vertical"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"window_horizontal"))text=L"Window pixel coordinate.";
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"total_unpacked_size"))text=L"Reserved for compressed MacBinary files; not used by the plain native reader.";
        break;
    case 0x601c0011U:
        if(!xx_rt_wcscmp(r->name,L"block_count_low"))text=L"Low 16 bits of the ProDOS block count, not a byte size.";
        if(!xx_rt_wcscmp(r->name,L"modified_date"))text=L"Packed ProDOS date.";
        if(!xx_rt_wcscmp(r->name,L"modified_time"))text=L"Packed ProDOS time.";
        if(!xx_rt_wcscmp(r->name,L"created_date"))text=L"Packed ProDOS date.";
        if(!xx_rt_wcscmp(r->name,L"created_time"))text=L"Packed ProDOS time.";
        if(!xx_rt_wcscmp(r->name,L"eof_low"))text=L"Low 24 bits of the declared byte size; combine eof_high. Directories store no payload.";
        if(!xx_rt_wcscmp(r->name,L"block_count_high"))text=L"High 16 bits of the ProDOS block count.";
        if(!xx_rt_wcscmp(r->name,L"eof_high"))text=L"High 8 bits of the declared byte size.";
        break;
    case 0x601c0013U:
        if(!xx_rt_wcscmp(r->name,L"filesystem_info"))text=L"Low byte is the native pathname separator; high byte is reserved.";
        if(!xx_rt_wcscmp(r->name,L"auxiliary_type_or_block_count"))text=L"File auxiliary type, or disk block count for disk-image threads.";
        if(!xx_rt_wcscmp(r->name,L"storage_type_or_block_size"))text=L"File storage type, or disk block size in bytes for disk-image threads.";
        break;
    case 0x601c0016U:
        if(!xx_rt_wcscmp(r->name,L"thread_crc16"))text=L"Version 2 checks compressed bytes; version 3 checks uncompressed bytes, seeded 0xFFFF.";
        if(!xx_rt_wcscmp(r->name,L"unpacked_size"))text=L"Disk-image threads may instead derive their byte size from the record block count.";
        break;
    case 0x601c0018U:
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        break;
    case 0x601c001bU:
        if(!xx_rt_wcscmp(r->name,L"resource_method"))text=L"Method bits plus folder/encryption markers; 32 starts a folder and 33 ends one.";
        if(!xx_rt_wcscmp(r->name,L"data_method"))text=L"Fork compression method and password flag; 0 is stored.";
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        break;
    case 0x601c001eU:
        if(!xx_rt_wcscmp(r->name,L"name_size_and_folder"))text=L"Low 7 bits are name length; bit 7 marks a directory.";
        break;
    case 0x601c0020U:
        if(!xx_rt_wcscmp(r->name,L"created"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"modified"))text=L"Seconds since 1904-01-01, not Unix epoch.";
        if(!xx_rt_wcscmp(r->name,L"crc32_register"))text=L"Uncomplemented CRC32 over resource then data fork.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 encrypted; bit 1 resource LZH; bit 2 data LZH.";
        break;
    case 0x601c0029U:
        if(!xx_rt_wcscmp(r->name,L"packed_fields0"))text=L"Bits 0..19 literals; 20..39 literal bytes; 40..59 matches; 60..62 literal bit accumulator.";
        if(!xx_rt_wcscmp(r->name,L"packed_fields1"))text=L"Four 10-bit literal states; bits 40..59 LMD payload bytes; 60..62 LMD bit accumulator.";
        if(!xx_rt_wcscmp(r->name,L"packed_fields2"))text=L"Bits 0..31 header byte size; 32..41 L state; 42..51 M state; 52..61 D state.";
        break;
    case 0x601c0031U:
        if(!xx_rt_wcscmp(r->name,L"status"))text=L"0 active, 0xFE deleted, 0xFF unused; stale fields in inactive entries are not live references.";
        if(!xx_rt_wcscmp(r->name,L"first_sector"))text=L"File-relative sector number; multiply by 128 for a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"sector_count"))text=L"Count of 128-byte sectors.";
        if(!xx_rt_wcscmp(r->name,L"created_date"))text=L"Days since 1977-12-31; zero means unset.";
        if(!xx_rt_wcscmp(r->name,L"modified_date"))text=L"Days since 1977-12-31; zero means unset.";
        if(!xx_rt_wcscmp(r->name,L"created_time"))text=L"Packed DOS date/time bits.";
        if(!xx_rt_wcscmp(r->name,L"modified_time"))text=L"Packed DOS date/time bits.";
        break;
    case 0x601c0035U:
        if(!xx_rt_wcscmp(r->name,L"mode"))text=L"Octal permission bits stored as a blank-padded digit string.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
/* Every offset is relative to the selected reader's original physical base. */
#define SXAR_LIMIT 20000U
bool sxar_span(sx_context *c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxar_read(sx_context *c,uint64_t p,void *b,size_t n){return sxar_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint16_t sxar16(const uint8_t *b,bool be){return xx_data_get_u16(b,2,0,be);}
uint32_t sxar32(const uint8_t *b,bool be){return xx_data_get_u32(b,4,0,be);}
uint64_t sxar64(const uint8_t *b){return xx_data_get_u64(b,8,0,false);}
bool sxar_add(sx_context *c,const sx_layout *l,uint64_t p){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];return c->count<SXAR_LIMIT&&p<=INT64_MAX&&sx_add(c,l,(int64_t)p,f->rel_offset+f->size);}
/* Reuse validated native archive-record boundaries for formats whose compressed
 * stream must be decoded merely to find the next physical record. No constructors. */
bool sxar_native_records(sx_context *c,bool pit){uint8_t b[128];uint16_t generation=0;uint64_t end=0;bool ok=true;
 if(!pit){if(!sxar_read(c,0,b,26)||!sxar_add(c,&sxar_rtpatch_header,0))return false;generation=sxar16(b+2,false);}
 if(!c->f->create_archive_records_reading||!c->f->get_current_archive_record||!c->f->archive_record_move_to_next||!c->f->free_archive_records_reading)return c->count!=0;
 xx_archive_record_state *state=(c->f->create_archive_records_reading)(c->f,NULL,c->pd);if(!state)return c->count!=0;
 for(unsigned i=0;i<SXAR_LIMIT;i++){const xx_archive_record *r=(c->f->get_current_archive_record)(c->f,state);if(!r)break;
  int64_t absolute=r->header_offset;
  if(pit&&absolute<c->f->base_address&&(r->header_size==4||r->header_size==98)&&r->data_offset>=c->f->base_address+r->header_size)absolute=r->data_offset-r->header_size;
  if(absolute>=c->f->base_address){uint64_t p=(uint64_t)(absolute-c->f->base_address),data=r->data_offset>=c->f->base_address?(uint64_t)(r->data_offset-c->f->base_address):UINT64_MAX;
   if(pit){if(p>=end&&sxar_read(c,p,b,4)&&!xx_rt_memcmp(b,"PMa",3)){if(!sxar_add(c,&sxar_packit_marker,p)){ok=false;break;}
    if(b[3]=='g'&&sxar_read(c,p+4,b,94)){uint64_t z=(uint64_t)sxar32(b+76,true)+sxar32(b+80,true);if(sxar_span(c,p+98,z+2)){if(!sxar_add(c,&sxar_packit_stored_header,p+4)||!sxar_add(c,&sxar_packit_forks_crc,p+98+z)){ok=false;break;}end=p+100+z;}}
    else if(data<=INT64_MAX&&r->compressed_size>=0&&sxar_span(c,data,(uint64_t)r->compressed_size))end=data+(uint64_t)r->compressed_size;
   }}else if(p>=26&&p>=end&&r->header_size>=42&&data==p+(uint64_t)r->header_size&&sxar_read(c,p,b,42)){
    /* Fixed and augmented whole-file forms start with the two size words.
     * Delta/inline forms remain raw unless this independent shape agrees. */
    uint32_t n=sxar32(b,false);bool whole=p>0&&sxar_read(c,p-1,b+42,1)&&b[42]==1&&n==sxar32(b+24,false)&&r->compressed_size>=0&&sxar32(b+4,false)==(uint64_t)r->compressed_size;
    if(whole&&((generation<=320&&r->header_size==42)||(generation>=400&&r->header_size>=53))){
     uint64_t name=p+50;bool valid=true;if(generation>=400){uint8_t z;valid=sxar_read(c,name,&z,1)&&z>=2&&name+1+z==data;}
     if(valid){if(!sxar_add(c,&sxar_rtpatch_destination_count,p-1)||!sxar_add(c,&sxar_rtpatch_stream_sizes,p)||!sxar_add(c,&sxar_rtpatch_destination,p+8)||(generation>=400&&!sxar_add(c,&sxar_rtpatch_name_size,name))){ok=false;break;}if(sxar_read(c,data,b,8)&&b[0]==0xb5&&b[1]==0x9c&&!sxar_add(c,&sxar_rtpatch_codec_header,data)){ok=false;break;}end=data+(uint64_t)r->compressed_size;}
    }
   }
  }
  if(!(c->f->archive_record_move_to_next)(c->f,state,c->pd))break;
 }
 (c->f->free_archive_records_reading)(c->f,state);
 if(pit&&end&&sxar_read(c,end,b,4)&&!xx_rt_memcmp(b,"PEnd",4)&&!sxar_add(c,&sxar_packit_marker,end))ok=false;
 return ok&&c->count!=0;}
static int sxar_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxar_finish(sx_context *c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxar_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxar_order);return !c->failed;}
static bool sx_archivemore_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_RTPATCH:case XX_FILE_TYPE_MPQ:case XX_FILE_TYPE_APPLESINGLE:case XX_FILE_TYPE_MACBINARY:case XX_FILE_TYPE_BINARYII:case XX_FILE_TYPE_NUFX:case XX_FILE_TYPE_PACKIT_MAC:case XX_FILE_TYPE_STUFFIT:case XX_FILE_TYPE_COMPACTPRO:case XX_FILE_TYPE_EGG:case XX_FILE_TYPE_LZFSE:case XX_FILE_TYPE_LZF_STREAM:case XX_FILE_TYPE_FASTLZ_SIXPACK:case XX_FILE_TYPE_LBR:case XX_FILE_TYPE_PDP11AR:case XX_FILE_TYPE_BIGAF:return true;default:return false;}}
static bool sx_archivemore_build(sx_context *c){if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_RTPATCH:ok=sx_rtpatch_build(c);break;case XX_FILE_TYPE_MPQ:ok=sx_mpq_build(c);break;case XX_FILE_TYPE_APPLESINGLE:ok=sx_applesingle_build(c);break;case XX_FILE_TYPE_MACBINARY:ok=sx_macbinary_build(c);break;case XX_FILE_TYPE_BINARYII:ok=sx_binaryii_build(c);break;case XX_FILE_TYPE_NUFX:ok=sx_nufx_build(c);break;case XX_FILE_TYPE_PACKIT_MAC:ok=sx_packit_mac_build(c);break;case XX_FILE_TYPE_STUFFIT:ok=sx_stuffit_build(c);break;case XX_FILE_TYPE_COMPACTPRO:ok=sx_compactpro_build(c);break;case XX_FILE_TYPE_EGG:ok=sx_egg_build(c);break;case XX_FILE_TYPE_LZFSE:ok=sx_lzfsestream_build(c);break;case XX_FILE_TYPE_LZF_STREAM:ok=sx_lzf_stream_build(c);break;case XX_FILE_TYPE_FASTLZ_SIXPACK:ok=sx_fastlz_sixpack_build(c);break;case XX_FILE_TYPE_LBR:ok=sx_lbr_build(c);break;case XX_FILE_TYPE_PDP11AR:ok=sx_pdp11ar_build(c);break;case XX_FILE_TYPE_BIGAF:ok=sx_bigaf_build(c);break;default:break;}return ok&&sxar_finish(c);}
const sx_family sx_archivemore_family={sx_archivemore_supports,sx_archivemore_build,sx_archivemore_layouts,SX_COUNT(sx_archivemore_layouts),sx_archivemore_comment};
