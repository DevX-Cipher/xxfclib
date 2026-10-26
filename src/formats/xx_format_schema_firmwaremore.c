/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical firmware container metadata. Unimplemented payloads remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_firmwaremore.h"
static const xx_data_struct_field_desc sx_fm_rompaq_header_fields[] = {
    SX_FIELD("image_size","int32",0,4,SX_SIZE),
    SX_FIELD("checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("rom_id","uint16",8,2,SX_ID),
    SX_FIELD("version","uint16",10,2,SX_ID),
    SX_FIELD("image_name","char[7]",12,7,SX_NONE),
    SX_FIELD("name_terminator","uint8",19,1,SX_RESERVED),
    SX_FIELD("date","char[39]",20,39,SX_NONE),
    SX_FIELD("date_terminator","uint8",59,1,SX_RESERVED),
    SX_FIELD("method","uint8",60,1,SX_ID),
    SX_FIELD("part_count","uint16",61,2,SX_COUNT_PROP),
    SX_FIELD("packed_part_size","int32",63,4,SX_SIZE),
    SX_FIELD("reserved","uint32",67,4,SX_RESERVED),
    SX_FIELD("reserved2","uint8",71,1,SX_RESERVED),
};
const sx_layout sx_fm_rompaq_header = {0x60220001U,"rompaq_header",sx_fm_rompaq_header_fields,SX_COUNT(sx_fm_rompaq_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_dms_swapped_header_fields[] = {
    SX_FIELD("tag","byte[2]",0,2,SX_SIGNATURE),
    SX_FIELD("unknown16","uint16",2,2,SX_NONE),
    SX_FIELD("magic","uint32_halfword_be",4,4,SX_SIGNATURE),
    SX_FIELD("unknown32","uint32_halfword_be",8,4,SX_NONE),
    SX_FIELD("image_size","uint32_halfword_be",12,4,SX_SIZE),
};
const sx_layout sx_fm_dms_swapped_header = {0x60220002U,"dms_swapped_header",sx_fm_dms_swapped_header_fields,SX_COUNT(sx_fm_dms_swapped_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_fm_mh01_signature_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("signature_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("signature_size","uint32",8,4,SX_SIZE),
    SX_FIELD("unknown","uint32",12,4,SX_NONE),
};
const sx_layout sx_fm_mh01_signature_header = {0x60220005U,"mh01_signature_header",sx_fm_mh01_signature_header_fields,SX_COUNT(sx_fm_mh01_signature_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_dlke_arm_header_fields[] = {
    SX_FIELD("rom_id","char[12]",0,12,SX_NONE),
    SX_FIELD("drange","uint16",12,2,SX_NONE),
    SX_FIELD("image_checksum","uint16",14,2,SX_CHECKSUM),
    SX_FIELD("block_size","uint32",16,4,SX_SIZE),
    SX_FIELD("reserved2","uint32",20,4,SX_RESERVED),
    SX_FIELD("reserved3","uint16",24,2,SX_RESERVED),
    SX_FIELD("lpvs","uint8",26,1,SX_ID),
    SX_FIELD("mbz","uint8",27,1,SX_RESERVED),
    SX_FIELD("timestamp_ticks","uint32",28,4,SX_NONE),
    SX_FIELD("erase_start","uint32",32,4,SX_ADDRESS),
    SX_FIELD("erase_size","uint32",36,4,SX_SIZE),
    SX_FIELD("data_start","uint32",40,4,SX_ADDRESS),
    SX_FIELD("data_size","uint32",44,4,SX_SIZE),
    SX_FIELD("reserved4","uint32",48,4,SX_RESERVED),
    SX_FIELD("reserved5","uint32",52,4,SX_RESERVED),
    SX_FIELD("reserved6","uint32",56,4,SX_RESERVED),
    SX_FIELD("reserved7","uint32",60,4,SX_RESERVED),
    SX_FIELD("header_id","uint16",64,2,SX_SIGNATURE),
    SX_FIELD("header_version","uint16",66,2,SX_ID),
    SX_FIELD("reserved8","uint16",68,2,SX_RESERVED),
    SX_FIELD("section_id","uint8",70,1,SX_ID),
    SX_FIELD("image_info_type","uint8",71,1,SX_ID),
    SX_FIELD("image_info_offset","uint32",72,4,SX_OFFSET),
    SX_FIELD("family","uint16",76,2,SX_ID),
    SX_FIELD("header_checksum","uint16",78,2,SX_CHECKSUM),
};
const sx_layout sx_fm_dlke_arm_header = {0x60220008U,"dlke_arm_header",sx_fm_dlke_arm_header_fields,SX_COUNT(sx_fm_dlke_arm_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_alpha_encimg_payload_le_fields[] = {
    SX_FIELD("encrypted_size","uint32",0,4,SX_SIZE),
    SX_FIELD("offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sx_fm_alpha_encimg_payload_le = {0x6022000bU,"alpha_encimg_payload_le",sx_fm_alpha_encimg_payload_le_fields,SX_COUNT(sx_fm_alpha_encimg_payload_le_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_alpha_encimg_payload_be_fields[] = {
    SX_FIELD("encrypted_size","uint32",0,4,SX_SIZE),
    SX_FIELD("offset","uint32",4,4,SX_OFFSET),
};
const sx_layout sx_fm_alpha_encimg_payload_be = {0x6022000cU,"alpha_encimg_payload_be",sx_fm_alpha_encimg_payload_be_fields,SX_COUNT(sx_fm_alpha_encimg_payload_be_fields),SX_BE};
static const xx_data_struct_field_desc sx_fm_dlink_package_header_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("unknown","uint32",4,4,SX_NONE),
    SX_FIELD("first_entry_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sx_fm_dlink_package_header = {0x6022000eU,"dlink_package_header",sx_fm_dlink_package_header_fields,SX_COUNT(sx_fm_dlink_package_header_fields),SX_BE};
static const xx_data_struct_field_desc sx_fm_dlink_package_entry_fields[] = {
    SX_FIELD("header_length","uint32",0,4,SX_SIZE),
    SX_FIELD("type","uint16",4,2,SX_ID),
    SX_FIELD("unknown","uint16",6,2,SX_NONE),
    SX_FIELD("file_size","uint32",8,4,SX_SIZE),
    SX_FIELD("name","char[16]",12,16,SX_NONE),
};
const sx_layout sx_fm_dlink_package_entry = {0x60220010U,"dlink_package_entry",sx_fm_dlink_package_entry_fields,SX_COUNT(sx_fm_dlink_package_entry_fields),SX_BE};
static const xx_data_struct_field_desc sx_fm_htc_nbh_block_header_fields[] = {
    SX_FIELD("data_length","uint32",0,4,SX_SIZE),
    SX_FIELD("signature_length","uint32",4,4,SX_SIZE),
    SX_FIELD("flag","uint8",8,1,SX_FLAGS),
};
const sx_layout sx_fm_htc_nbh_block_header = {0x60220012U,"htc_nbh_block_header",sx_fm_htc_nbh_block_header_fields,SX_COUNT(sx_fm_htc_nbh_block_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_htc_dbh_section_type_fields[] = {
    SX_FIELD("section_type","uint32",0,4,SX_ID),
};
const sx_layout sx_fm_htc_dbh_section_type = {0x60220014U,"htc_dbh_section_type",sx_fm_htc_dbh_section_type_fields,SX_COUNT(sx_fm_htc_dbh_section_type_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_htc_dbh_section_offset_fields[] = {
    SX_FIELD("section_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sx_fm_htc_dbh_section_offset = {0x60220015U,"htc_dbh_section_offset",sx_fm_htc_dbh_section_offset_fields,SX_COUNT(sx_fm_htc_dbh_section_offset_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_xiaomi_hdr1_prefix_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("signature_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("unused","uint16",12,2,SX_RESERVED),
    SX_FIELD("device_id","uint16",14,2,SX_ID),
};
static const sx_layout sx_fm_xiaomi_hdr1_prefix = {0x60220018U,"xiaomi_hdr1_prefix",sx_fm_xiaomi_hdr1_prefix_fields,SX_COUNT(sx_fm_xiaomi_hdr1_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_xiaomi_hdr2_prefix_fields[] = {
    SX_FIELD("magic","byte[4]",0,4,SX_SIGNATURE),
    SX_FIELD("signature_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("crc32","uint32",8,4,SX_CHECKSUM),
    SX_FIELD("unused","uint32",12,4,SX_RESERVED),
    SX_FIELD("device_id","char[8]",16,8,SX_NONE),
    SX_FIELD("region","char[8]",24,8,SX_NONE),
    SX_FIELD("unused2","uint64[2]",32,16,SX_RESERVED),
};
static const sx_layout sx_fm_xiaomi_hdr2_prefix = {0x60220019U,"xiaomi_hdr2_prefix",sx_fm_xiaomi_hdr2_prefix_fields,SX_COUNT(sx_fm_xiaomi_hdr2_prefix_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_xiaomi_blob_offset_fields[] = {
    SX_FIELD("blob_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sx_fm_xiaomi_blob_offset = {0x6022001aU,"xiaomi_blob_offset",sx_fm_xiaomi_blob_offset_fields,SX_COUNT(sx_fm_xiaomi_blob_offset_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_xiaomi_blob_header_fields[] = {
    SX_FIELD("magic","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("flash_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("data_size","uint32",8,4,SX_SIZE),
    SX_FIELD("type","uint16",12,2,SX_ID),
    SX_FIELD("unused","uint16",14,2,SX_RESERVED),
    SX_FIELD("name","char[32]",16,32,SX_NONE),
};
static const sx_layout sx_fm_xiaomi_blob_header = {0x6022001bU,"xiaomi_blob_header",sx_fm_xiaomi_blob_header_fields,SX_COUNT(sx_fm_xiaomi_blob_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_xiaomi_signature_fields[] = {
    SX_FIELD("signature_size","uint32",0,4,SX_SIZE),
    SX_FIELD("padding","uint32[3]",4,12,SX_RESERVED),
    SX_FIELD("signature","byte[256]",16,256,SX_NONE),
};
static const sx_layout sx_fm_xiaomi_signature = {0x6022001cU,"xiaomi_signature",sx_fm_xiaomi_signature_fields,SX_COUNT(sx_fm_xiaomi_signature_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_bios_far_reset_jump_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("target_offset","uint16",1,2,SX_OFFSET),
    SX_FIELD("target_segment","uint16",3,2,SX_ADDRESS),
};
const sx_layout sx_fm_bios_far_reset_jump = {0x6022001dU,"bios_far_reset_jump",sx_fm_bios_far_reset_jump_fields,SX_COUNT(sx_fm_bios_far_reset_jump_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_bios_near_reset_jump_fields[] = {
    SX_FIELD("opcode","uint8",0,1,SX_ID),
    SX_FIELD("displacement","int16",1,2,SX_OFFSET),
};
const sx_layout sx_fm_bios_near_reset_jump = {0x6022001eU,"bios_near_reset_jump",sx_fm_bios_near_reset_jump_fields,SX_COUNT(sx_fm_bios_near_reset_jump_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_gns1_segment_fields[] = {
    SX_FIELD("size","uint32",0,4,SX_SIZE),
    SX_FIELD("physical_address","uint32",4,4,SX_ADDRESS),
    SX_FIELD("image_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sx_fm_gns1_segment = {0x60220021U,"gns1_segment",sx_fm_gns1_segment_fields,SX_COUNT(sx_fm_gns1_segment_fields),SX_LE};
static const xx_data_struct_field_desc sx_fm_gns1_terminator_fields[] = {
    SX_FIELD("size_sentinel","uint32",0,4,SX_SIGNATURE),
    SX_FIELD("address_sentinel","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("offset_sentinel","uint32",8,4,SX_SIGNATURE),
};
const sx_layout sx_fm_gns1_terminator = {0x60220022U,"gns1_terminator",sx_fm_gns1_terminator_fields,SX_COUNT(sx_fm_gns1_terminator_fields),SX_LE};
static const sx_layout *const sx_firmwaremore_layouts[] = {
    &sx_fm_rompaq_header,
    &sx_fm_dms_swapped_header,
    &sx_fm_dkbs_header,
    &sx_fm_shrs_header_prefix,
    &sx_fm_mh01_signature_header,
    &sx_fm_mh01_payload_header,
    &sx_fm_autel_header,
    &sx_fm_dlke_arm_header,
    &sx_fm_encrpted_img_header,
    &sx_fm_alpha_encimg_header_prefix,
    &sx_fm_alpha_encimg_payload_le,
    &sx_fm_alpha_encimg_payload_be,
    &sx_fm_alpha_encimg_header_suffix,
    &sx_fm_dlink_package_header,
    &sx_fm_dlink_fpkg_extra,
    &sx_fm_dlink_package_entry,
    &sx_fm_htc_nbh_header,
    &sx_fm_htc_nbh_block_header,
    &sx_fm_htc_dbh_prefix,
    &sx_fm_htc_dbh_section_type,
    &sx_fm_htc_dbh_section_offset,
    &sx_fm_htc_dbh_section_size,
    &sx_fm_htc_dbh_identity,
    &sx_fm_xiaomi_hdr1_prefix,
    &sx_fm_xiaomi_hdr2_prefix,
    &sx_fm_xiaomi_blob_offset,
    &sx_fm_xiaomi_blob_header,
    &sx_fm_xiaomi_signature,
    &sx_fm_bios_far_reset_jump,
    &sx_fm_bios_near_reset_jump,
    &sx_fm_gns1_ftab_header,
    &sx_fm_gns1_ftab_entry,
    &sx_fm_gns1_segment,
    &sx_fm_gns1_terminator,
};
/* Optional metadata ranges are bounded before shared helpers are called. */
bool sx_fm_span(sx_context*c,int64_t p,uint64_t n){return p>=0&&p<=c->size&&n<=(uint64_t)(c->size-p);}
bool sx_fm_read(sx_context*c,int64_t p,void*b,size_t n){return sx_fm_span(c,p,n)&&sx_read(c,p,b,n);}
bool sx_fm_u32(sx_context*c,int64_t p,bool be,uint32_t*v){uint8_t b[4];if(!sx_fm_read(c,p,b,4))return false;*v=xx_data_get_u32(b,4,0,be);return true;}
/* Keep the first physical interpretation of ambiguous overlapping ranges. */
bool sx_fm_table(sx_context*c,const sx_layout*l,int64_t p,int64_t z,uint64_t n){if(!n)return true;if(z<=0||n>1000000||(uint64_t)z>INT64_MAX/n||!sx_fm_span(c,p,(uint64_t)z*n))return false;if(c->count>=32000)return true;for(size_t i=0;i<c->count;i++){int64_t a=c->items[i].offset-c->f->base_address,b=a+c->items[i].total_size;if(p<b&&a<p+z*(int64_t)n)return true;}return sx_table(c,l,p,z,n);}
bool sx_fm_add(sx_context*c,const sx_layout*l,int64_t p,int64_t z){return sx_fm_table(c,l,p,z,1);}
static bool sx_firmwaremore_supports(xx_file_type_t t)
{
    switch(t){case XX_FILE_TYPE_ROMPAQ:case XX_FILE_TYPE_DMSFW:case XX_FILE_TYPE_DKBS:case XX_FILE_TYPE_SHRS:case XX_FILE_TYPE_MH01:case XX_FILE_TYPE_AUTEL:case XX_FILE_TYPE_DLKE:case XX_FILE_TYPE_ENCRPTED_IMG:case XX_FILE_TYPE_D_LINK_ALPHA_ENCIMG_V2:case XX_FILE_TYPE_D_LINK_FPKG_CPKG:case XX_FILE_TYPE_HTC_NBH_ROM_IMAGE:case XX_FILE_TYPE_XIAOMI_HDR1:case XX_FILE_TYPE_XIAOMI_HDR2:case XX_FILE_TYPE_BIOS_FIRMWARE:case XX_FILE_TYPE_GNS1:return true;default:return false;}
}
bool sx_fm_xiaomi(sx_context *c,bool hdr2)
{
    uint32_t signature;int64_t prefix=hdr2?48:16;if(!sx_fm_u32(c,4,false,&signature)||!sx_fm_add(c,hdr2?&sx_fm_xiaomi_hdr2_prefix:&sx_fm_xiaomi_hdr1_prefix,0,prefix)||!sx_fm_table(c,&sx_fm_xiaomi_blob_offset,prefix,4,8)||!sx_fm_add(c,&sx_fm_xiaomi_signature,signature,272))return false;
    for(unsigned i=0;i<8;i++){uint32_t off;if(!sx_fm_u32(c,prefix+4*i,false,&off))return false;if(!off)break;if(!sx_fm_add(c,&sx_fm_xiaomi_blob_header,off,48))return false;}
    return true;
}
static int sx_fm_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sx_fm_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sx_fm_order);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end||(at>end&&!sx_raw(c,end,at-end)))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sx_fm_order);return !c->failed;
}
static bool sx_firmwaremore_build(sx_context *c)
{
    if(!c||!c->f||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;
    switch(c->f->file_type){
    case XX_FILE_TYPE_ROMPAQ:ok=sx_rompaq_build(c);break;
    case XX_FILE_TYPE_DMSFW:ok=sx_dmsfw_build(c);break;
    case XX_FILE_TYPE_DKBS:ok=sx_dkbs_build(c);break;
    case XX_FILE_TYPE_SHRS:ok=sx_shrs_build(c);break;
    case XX_FILE_TYPE_MH01:ok=sx_mh01_build(c);break;
    case XX_FILE_TYPE_AUTEL:ok=sx_autel_build(c);break;
    case XX_FILE_TYPE_DLKE:ok=sx_dlke_build(c);break;
    case XX_FILE_TYPE_ENCRPTED_IMG:ok=sx_encrpted_img_build(c);break;
    case XX_FILE_TYPE_D_LINK_ALPHA_ENCIMG_V2:ok=sx_d_link_alpha_encimg_v2_build(c);break;
    case XX_FILE_TYPE_D_LINK_FPKG_CPKG:ok=sx_d_link_fpkg_cpkg_build(c);break;
    case XX_FILE_TYPE_HTC_NBH_ROM_IMAGE:ok=sx_htc_nbh_rom_image_build(c);break;
    case XX_FILE_TYPE_XIAOMI_HDR1:ok=sx_xiaomi_hdr1_build(c);break;
    case XX_FILE_TYPE_XIAOMI_HDR2:ok=sx_xiaomi_hdr2_build(c);break;
    case XX_FILE_TYPE_BIOS_FIRMWARE:ok=sx_bios_firmware_build(c);break;
    case XX_FILE_TYPE_GNS1:ok=sx_gns1_build(c);break;
    default:break;}return ok&&sx_fm_finish(c);
}
static bool sx_firmwaremore_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60220001U||id>=0x60220001U+SX_COUNT(sx_firmwaremore_layouts))return true;
    uint64_t v=xx_var_get_u64(&r->value);const wchar_t *s=NULL;
    if(id==sx_fm_dlink_package_header.id&&!xx_rt_wcscmp(r->name,L"unknown"))s=L"Stored constant 0x01000000; its meaning is not established";
    else if(id==sx_fm_dms_swapped_header.id&&(!xx_rt_wcscmp(r->name,L"magic")||!xx_rt_wcscmp(r->name,L"unknown32")||!xx_rt_wcscmp(r->name,L"image_size")))s=L"Physical bytes ABCD decode as big-endian CDAB after swapping the two 16-bit halves";
    else if(id==sx_fm_rompaq_header.id&&!xx_rt_wcscmp(r->name,L"method"))s=v==1?L"Stored":v==2?L"PKWARE DCL implode":NULL;
    else if(id==sx_fm_mh01_signature_header.id&&!xx_rt_wcscmp(r->name,L"signature_offset"))s=L"Byte offset relative to the second MH01 header at file offset 0x10";
    else if(id==sx_fm_dlke_arm_header.id&&!xx_rt_wcscmp(r->name,L"timestamp_ticks"))s=L"4-second ticks since 1998-03-07 16:00:00 UTC; stored value retained";
    else if((id==sx_fm_alpha_encimg_payload_le.id||id==sx_fm_alpha_encimg_payload_be.id))s=L"Native payload byte order chooses the smaller size interpretation, independently of the header magic byte order";
    else if(id==sx_fm_dlink_package_entry.id&&!xx_rt_wcscmp(r->name,L"type"))s=v==0x100?L"FILE":v==0x101?L"UNKNOWN_TYPE_0x101":v==0x102?L"CHECKSUM":v==0x103?L"SIGNATURE":NULL;
    else if(id==sx_fm_htc_nbh_block_header.id&&!xx_rt_wcscmp(r->name,L"flag"))s=v==1?L"MORE_BLOCKS":v==2?L"LAST_BLOCK":v==0?L"Legacy zero flag":NULL;
    else if(id==sx_fm_htc_dbh_section_type.id){switch(v){case 0:s=L"Unused section";break;case 0x100:s=L"IPL";break;case 0x101:s=L"G3IPL";break;case 0x102:s=L"G4IPL";break;case 0x200:s=L"SPL";break;case 0x201:s=L"G3SPL";break;case 0x202:s=L"G4SPL";break;case 0x300:s=L"GSM";break;case 0x400:s=L"OS";break;case 0x600:s=L"MainSplash";break;case 0x601:s=L"SubSplash";break;case 0x700:case 0x900:s=L"ExtROM";break;}}
    else if(id==sx_fm_htc_dbh_section_offset.id)s=L"Byte offset in the logical reassembled DBH image, not in the signed NBH wrapper";
    else if(id==sx_fm_xiaomi_blob_header.id&&!xx_rt_wcscmp(r->name,L"flash_offset"))s=L"Flash destination coordinate; not an offset in the container file";
    else if((id==sx_fm_xiaomi_hdr1_prefix.id||id==sx_fm_xiaomi_hdr2_prefix.id)&&!xx_rt_wcscmp(r->name,L"crc32"))s=L"CRC-32/JAMCRC from file offset 0x0C through the fixed signature block";
    else if(id==sx_fm_bios_far_reset_jump.id&&!xx_rt_wcscmp(r->name,L"target_segment"))s=L"Real-mode segment; physical target is segment * 16 + target_offset";
    else if(id==sx_fm_bios_near_reset_jump.id&&!xx_rt_wcscmp(r->name,L"displacement"))s=L"Signed 16-bit relative displacement from the end of the three-byte reset jump";
    else if(id==sx_fm_gns1_terminator.id)s=L"Physical table terminator: all three words are zero or all are 0xFFFFFFFF; not a segment size, address or offset";
    else if(id==sx_fm_gns1_segment.id&&!xx_rt_wcscmp(r->name,L"image_offset"))s=L"Byte offset relative to the GNS1 image, which can be embedded inside FTAB";
    return !s||xx_data_struct_record_set_comment(r,s);
}
const sx_family sx_firmwaremore_family={sx_firmwaremore_supports,sx_firmwaremore_build,sx_firmwaremore_layouts,SX_COUNT(sx_firmwaremore_layouts),sx_firmwaremore_comment};
