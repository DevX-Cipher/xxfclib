/* SPDX-License-Identifier: MIT
 * Binary resource and firmware metadata. Scope: docs/data_struct_binaryresources_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_binaryresources.h"
static const sx_layout *const sx_binaryresources_layouts[] = {
    &sxbrs_ota_bitmap_short,
    &sxbrs_ota_bitmap_extended,
    &sxbrs_lp_geometry,
    &sxbrs_lp_header,
    &sxbrs_lp_header_extended,
    &sxbrs_lp_partition,
    &sxbrs_lp_extent,
    &sxbrs_lp_group,
    &sxbrs_lp_block_device,
    &sxbrs_dts_header,
    &sxbrs_dts_counts,
    &sxbrs_dts_bounds,
    &sxbrs_dts_node,
    &sxbrs_dts_subshape_first,
    &sxbrs_dts_subshape_count,
    &sxbrs_dts_rotation,
    &sxbrs_dts_translation,
    &sxbrs_dts_guard32,
    &sxbrs_dts_guard16,
    &sxbrs_dts_guard8,
    &sxbrs_dts_name_byte,
    &sxbrs_dts_footer,
    &sxbrs_vxworks_symbol_le,
    &sxbrs_vxworks_symbol_be,
    &sxbrs_mwave_header,
    &sxbrs_pcxlib_header,
    &sxbrs_pcxlib_member,
    &sxbrs_qnx_startup_prefix,
    &sxbrs_qnx_startup_header,
    &sxbrs_qnx_block,
    &sxbrs_uboot_env_le,
    &sxbrs_uboot_redundant_env_le,
    &sxbrs_uboot_env_be,
    &sxbrs_uboot_redundant_env_be,
    &sxbrs_uboot_key_byte,
    &sxbrs_uboot_value_byte,
    &sxbrs_uboot_separator,
    &sxbrs_uboot_terminator,
    &sxbrs_fss_header,
    &sxbrs_fss_record,
    &sxbrs_fss_end,
    &sxbrs_px_header,
    &sxbrs_px_block,
    &sxbrs_px_count,
    &sxbrs_px_record,
    &sxbrs_evd_header,
    &sxbrs_evd_record,
    &sxbrs_sony_image_header,
    &sxbrs_sony_image_zlib_marker,
    &sxbrs_resource_zlib_header,
    &sxbrs_resource_zlib_trailer,
};
static bool sx_binaryresources_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x603e0000U||id>=0x603f0000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x603e0001U:
        if(!xx_rt_wcscmp(r->name,L"infofield"))text=L"Bit4 selects16-bit dimensions; extension fields are unsupported by the native reader.";
        if(!xx_rt_wcscmp(r->name,L"depth"))text=L"Native monochrome images store1 bit per pixel.";
        break;
    case 0x603e0002U:
        if(!xx_rt_wcscmp(r->name,L"infofield"))text=L"Bit4 selects16-bit big-endian dimensions.";
        if(!xx_rt_wcscmp(r->name,L"depth"))text=L"Native monochrome images store1 bit per pixel.";
        break;
    case 0x603e0003U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"LP_METADATA_GEOMETRY_MAGIC";
        if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"SHA-256 of the geometry with this field zeroed.";
        if(!xx_rt_wcscmp(r->name,L"logical_block_size"))text=L"Alignment in bytes; multiple of512.";
        break;
    case 0x603e0004U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"LP_METADATA_HEADER_MAGIC";
        if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"SHA-256 of header_size bytes with this checksum zeroed.";
        if(!xx_rt_wcscmp(r->name,L"tables_checksum"))text=L"SHA-256 of all table bytes.";
        if(!xx_rt_wcscmp(r->name,L"partitions_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"extents_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"groups_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"block_devices_offset"))text=L"Byte offset from the end of the metadata header.";
        break;
    case 0x603e0005U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"LP_METADATA_HEADER_MAGIC";
        if(!xx_rt_wcscmp(r->name,L"header_checksum"))text=L"SHA-256 of header_size bytes with this checksum zeroed.";
        if(!xx_rt_wcscmp(r->name,L"tables_checksum"))text=L"SHA-256 of all table bytes.";
        if(!xx_rt_wcscmp(r->name,L"partitions_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"extents_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"groups_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"block_devices_offset"))text=L"Byte offset from the end of the metadata header.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"LP_HEADER_FLAG_VIRTUAL_AB_DEVICE=1; LP_HEADER_FLAG_OVERLAYS_ACTIVE=2.";
        break;
    case 0x603e0006U:
        if(!xx_rt_wcscmp(r->name,L"attributes"))text=L"LP_PARTITION_ATTR_READONLY=1; SLOT_SUFFIXED=2; UPDATED=4; DISABLED=8.";
        if(!xx_rt_wcscmp(r->name,L"first_extent_index"))text=L"Index in the extent table; not a byte offset.";
        if(!xx_rt_wcscmp(r->name,L"group_index"))text=L"Index in the partition-group table.";
        break;
    case 0x603e0007U:
        if(!xx_rt_wcscmp(r->name,L"num_sectors"))text=L"Length in512-byte sectors.";
        if(!xx_rt_wcscmp(r->name,L"target_type"))text=L"LP_TARGET_TYPE_LINEAR=0; LP_TARGET_TYPE_ZERO=1.";
        if(!xx_rt_wcscmp(r->name,L"target_data"))text=L"LINEAR: physical sector number in512-byte units; ZERO: reserved zero.";
        if(!xx_rt_wcscmp(r->name,L"target_source"))text=L"LINEAR: block-device table index; ZERO: reserved zero.";
        break;
    case 0x603e0008U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"LP_GROUP_SLOT_SUFFIXED=1.";
        if(!xx_rt_wcscmp(r->name,L"maximum_size"))text=L"Byte limit; zero means unlimited.";
        break;
    case 0x603e0009U:
        if(!xx_rt_wcscmp(r->name,L"first_logical_sector"))text=L"First usable512-byte sector number.";
        if(!xx_rt_wcscmp(r->name,L"alignment"))text=L"Partition alignment in bytes.";
        if(!xx_rt_wcscmp(r->name,L"alignment_offset"))text=L"Byte alignment adjustment within the parent block device.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"LP_BLOCK_DEVICE_SLOT_SUFFIXED=1.";
        break;
    case 0x603e000aU:
        if(!xx_rt_wcscmp(r->name,L"version"))text=L"Low16 bits are DTS version; high16 bits are exporter version.";
        if(!xx_rt_wcscmp(r->name,L"buffer_size_words"))text=L"Total buffer length in32-bit words.";
        if(!xx_rt_wcscmp(r->name,L"start16_words"))text=L"Start of16-bit buffer, measured in32-bit words from the end of this header.";
        if(!xx_rt_wcscmp(r->name,L"start8_words"))text=L"Start of8-bit buffer, measured in32-bit words from the end of this header.";
        break;
    case 0x603e000dU:
        if(!xx_rt_wcscmp(r->name,L"parent_index"))text=L"-1 means no parent.";
        if(!xx_rt_wcscmp(r->name,L"first_object_index"))text=L"-1 means no object.";
        if(!xx_rt_wcscmp(r->name,L"first_child_index"))text=L"-1 means no child.";
        if(!xx_rt_wcscmp(r->name,L"next_sibling_index"))text=L"-1 means no sibling.";
        break;
    case 0x603e0010U:
        if(!xx_rt_wcscmp(r->name,L"x"))text=L"Quantized quaternion component; original signed16-bit encoding.";
        break;
    case 0x603e0017U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Runtime symbol value; not a physical file offset.";
        if(!xx_rt_wcscmp(r->name,L"type"))text=L"Native recognized symbol classes:0x500 function,0x700 initialized data,0x900 uninitialized data.";
        break;
    case 0x603e0018U:
        if(!xx_rt_wcscmp(r->name,L"value"))text=L"Runtime symbol value; not a physical file offset.";
        if(!xx_rt_wcscmp(r->name,L"type"))text=L"Native recognized symbol classes:0x500 function,0x700 initialized data,0x900 uninitialized data.";
        break;
    case 0x603e0019U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"Unix compress signature1F9D.";
        if(!xx_rt_wcscmp(r->name,L"dos_time"))text=L"Packed DOS time: bits0..4 seconds/2, bits5..10 minutes, bits11..15 hours.";
        if(!xx_rt_wcscmp(r->name,L"dos_date"))text=L"Packed DOS date: bits0..4 day, bits5..8 month, bits9..15 years since1980.";
        if(!xx_rt_wcscmp(r->name,L"constant"))text=L"MWave wrapper constant0x0020.";
        if(!xx_rt_wcscmp(r->name,L"compress_flags"))text=L"Low5 bits:max LZW code width; bit7:block mode; bits5..6 reserved.";
        break;
    case 0x603e001bU:
        if(!xx_rt_wcscmp(r->name,L"method"))text=L"Native defined method0:stored.";
        break;
    case 0x603e001cU:
        if(!xx_rt_wcscmp(r->name,L"signature"))text=L"QNX startup signature0x00FF7EEB.";
        if(!xx_rt_wcscmp(r->name,L"flags1"))text=L"Includes byte order and compression method encoding.";
        if(!xx_rt_wcscmp(r->name,L"machine"))text=L"ELF machine identifier.";
        if(!xx_rt_wcscmp(r->name,L"paddr_bias"))text=L"Bias added to physical addresses to form accessible pointers.";
        if(!xx_rt_wcscmp(r->name,L"imagefs_size"))text=L"Decoded image-filesystem size.";
        if(!xx_rt_wcscmp(r->name,L"preboot_size"))text=L"Bytes from image start to this startup header.";
        break;
    case 0x603e001dU:
        if(!xx_rt_wcscmp(r->name,L"signature"))text=L"QNX startup signature0x00FF7EEB.";
        if(!xx_rt_wcscmp(r->name,L"flags1"))text=L"Includes byte order and compression method encoding.";
        if(!xx_rt_wcscmp(r->name,L"machine"))text=L"ELF machine identifier.";
        if(!xx_rt_wcscmp(r->name,L"paddr_bias"))text=L"Bias added to physical addresses to form accessible pointers.";
        if(!xx_rt_wcscmp(r->name,L"imagefs_size"))text=L"Decoded image-filesystem size.";
        if(!xx_rt_wcscmp(r->name,L"preboot_size"))text=L"Bytes from image start to this startup header.";
        if(!xx_rt_wcscmp(r->name,L"info"))text=L"Startup-info records; their individual grammar remains undecoded.";
        break;
    case 0x603e001eU:
        if(!xx_rt_wcscmp(r->name,L"packed_size"))text=L"Length of the following NRV2B block; zero terminates the chain.";
        break;
    case 0x603e001fU:
        if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the complete data area, including padding.";
        break;
    case 0x603e0020U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the complete data area after flags, including padding.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Redundant-environment active/obsolete flag or serial counter, depending on storage backend.";
        break;
    case 0x603e0021U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the complete data area, including padding.";
        break;
    case 0x603e0022U:
        if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 of the complete data area after flags, including padding.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Redundant-environment active/obsolete flag or serial counter, depending on storage backend.";
        break;
    case 0x603e0025U:
        if(!xx_rt_wcscmp(r->name,L"separator"))text=L"ASCII equals sign separates key and value.";
        break;
    case 0x603e0026U:
        if(!xx_rt_wcscmp(r->name,L"terminator"))text=L"NUL terminates the variable; a second NUL ends the list.";
        break;
    case 0x603e0027U:
        if(!xx_rt_wcscmp(r->name,L"marker_05"))text=L"Native signature requires1.";
        if(!xx_rt_wcscmp(r->name,L"marker_07"))text=L"Native signature requires1.";
        if(!xx_rt_wcscmp(r->name,L"descriptor_count"))text=L"Includes one implicit descriptor before the stored12-byte descriptor records.";
        if(!xx_rt_wcscmp(r->name,L"marker_0e"))text=L"Native signature requires0xFFFF.";
        break;
    case 0x603e0028U:
        if(!xx_rt_wcscmp(r->name,L"data_offset"))text=L"Data extent is associated with the preceding record name.";
        if(!xx_rt_wcscmp(r->name,L"kind"))text=L"0x10 marks a named resource descriptor.";
        break;
    case 0x603e002bU:
        if(!xx_rt_wcscmp(r->name,L"kind"))text=L"Native named-resource block type1.";
        break;
    case 0x603e002dU:
        if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Native resource record marker1.";
        break;
    case 0x603e002eU:
        if(!xx_rt_wcscmp(r->name,L"marker"))text=L"Native header marker12.";
        if(!xx_rt_wcscmp(r->name,L"field_10"))text=L"Meaning unconfirmed; native reader requires nonzero.";
        if(!xx_rt_wcscmp(r->name,L"field_14"))text=L"Meaning unconfirmed; native reader requires nonzero.";
        break;
    case 0x603e002fU:
        if(!xx_rt_wcscmp(r->name,L"image_type"))text=L"JPEG=1;PNG=2.";
        break;
    case 0x603e0030U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"TCJN";
        if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Bytes following this512-byte header.";
        if(!xx_rt_wcscmp(r->name,L"continuation"))text=L"Zero selects the initial volume; continuations need the initial volume.";
        if(!xx_rt_wcscmp(r->name,L"field_19"))text=L"Meaning unconfirmed; native reader accepts0 or1.";
        break;
    case 0x603e0031U:
        if(!xx_rt_wcscmp(r->name,L"magic"))text=L"ZLIB marker before the physical zlib stream.";
        break;
    case 0x603e0032U:
        if(!xx_rt_wcscmp(r->name,L"compression_method_flags"))text=L"CM bits0..3=8:DEFLATE; CINFO bits4..7=window log2 minus8.";
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"FCHECK bits0..4; FDICT bit5; compression level bits6..7.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
#include "xxfclib/algo/crc/xx_crc.h"
/* Bounded physical metadata; byte coordinates are always those of the input. */
uint64_t sxbrs_num(sx_context*c,int64_t at,unsigned width,bool be){uint8_t b[8];if(!width||width>8||!sx_read(c,at,b,width)){c->failed=true;return 0;}uint64_t v=0;for(unsigned i=0;i<width;i++)v|=(uint64_t)b[i]<<(8*(be?width-1-i:i));return v;}
uint64_t sxbrs_width(const sx_layout*l){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];return(uint64_t)(f->rel_offset+f->size);}
bool sxbrs_take(sx_context*c,const sx_layout*l,int64_t*at,int64_t end,uint64_t count){uint64_t width=sxbrs_width(l);if(*at<0||end<*at||!width||count>(uint64_t)(end-*at)/width)return false;if(count&&c->count<32000&&!sx_table(c,l,*at,(int64_t)width,count>65536?65536:count))return false;*at+=(int64_t)(count*width);return !c->failed&&!xx_pd_is_stopped(c->pd);}
bool sxbrs_add(sx_context*c,const sx_layout*l,int64_t at){return sxbrs_take(c,l,&at,c->size,1);}
bool sxbrs_skip(int64_t*at,int64_t end,uint64_t n){if(*at<0||end<*at||n>(uint64_t)(end-*at))return false;*at+=(int64_t)n;return true;}
bool sxbrs_eq(sx_context*c,int64_t at,const char*text,size_t n){uint8_t buf[64];return n<=sizeof(buf)&&sx_read(c,at,buf,n)&&!xx_rt_memcmp(buf,text,n);}
static int sxbrs_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxbrs_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxbrs_order);
 /* Resources can share physical extents. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxbrs_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_binaryresources_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_PCXLIB:case XX_FILE_TYPE_TORQUE_DTS:case XX_FILE_TYPE_NOKIA_OTA_BITMAP:case XX_FILE_TYPE_FSS:case XX_FILE_TYPE_PX:case XX_FILE_TYPE_EVD:case XX_FILE_TYPE_QNXBASE:case XX_FILE_TYPE_VXWORKS:case XX_FILE_TYPE_MWAVE:case XX_FILE_TYPE_UBOOT_ENV:case XX_FILE_TYPE_ANDROID_LP:case XX_FILE_TYPE_SONY_IMAGE:return true;default:return false;}}
static bool sx_binaryresources_build(sx_context*c){if(!c||c->size<1||c->size>268435456||xx_pd_is_stopped(c->pd))return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_PCXLIB:ok=sx_pcxlib_build(c);break;case XX_FILE_TYPE_TORQUE_DTS:ok=sx_torque_dts_build(c);break;case XX_FILE_TYPE_NOKIA_OTA_BITMAP:ok=sx_nokia_ota_bitmap_build(c);break;case XX_FILE_TYPE_FSS:ok=sx_fss_build(c);break;case XX_FILE_TYPE_PX:ok=sx_px_build(c);break;case XX_FILE_TYPE_EVD:ok=sx_evd_build(c);break;case XX_FILE_TYPE_QNXBASE:ok=sx_qnxbase_build(c);break;case XX_FILE_TYPE_VXWORKS:ok=sx_vxworks_build(c);break;case XX_FILE_TYPE_MWAVE:ok=sx_mwave_build(c);break;case XX_FILE_TYPE_UBOOT_ENV:ok=sx_uboot_build(c);break;case XX_FILE_TYPE_ANDROID_LP:ok=sx_android_lp_build(c);break;case XX_FILE_TYPE_SONY_IMAGE:ok=sx_sony_image_build(c);break;default:return false;}return ok&&sxbrs_finish(c);}
const sx_family sx_binaryresources_family={sx_binaryresources_supports,sx_binaryresources_build,sx_binaryresources_layouts,SX_COUNT(sx_binaryresources_layouts),sx_binaryresources_comment};
