/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Blindwrite 5 6 Image data structures, moved out of the disknext schema family. */
#include "../../xx_format_schema_disknext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#if SX_ALIAS_READER_FACTORY
#include "xxfclib/formats/filesystem/psa_disk/xx_psa_disk.h"
#endif

static const xx_data_struct_field_desc sxdn_blindwrite56_signature_fields[] = {
    SX_FIELD("signature","char[16]",0,16,SX_SIGNATURE),
};
const sx_layout sxdn_blindwrite56_signature = {0x6078003bU,"blindwrite56_signature",sxdn_blindwrite56_signature_fields,SX_COUNT(sxdn_blindwrite56_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_disc_fields[] = {
    SX_FIELD("unknown0","uint32[8]",0,32,SX_NONE),
    SX_FIELD("disc_type","uint16",32,2,SX_ID),
    SX_FIELD("session_count","uint16",34,2,SX_COUNT_PROP),
    SX_FIELD("unknown1","uint32[3]",36,12,SX_NONE),
    SX_FIELD("mcn_valid","uint8",48,1,SX_FLAGS),
    SX_FIELD("media_catalog_number","char[13]",49,13,SX_NONE),
    SX_FIELD("unknown2","uint16",62,2,SX_NONE),
    SX_FIELD("unknown3","uint32[4]",64,16,SX_NONE),
    SX_FIELD("pma_size","uint16",80,2,SX_SIZE),
    SX_FIELD("atip_size","uint16",82,2,SX_SIZE),
    SX_FIELD("cd_text_size","uint16",84,2,SX_SIZE),
    SX_FIELD("cd_info_size","uint16",86,2,SX_SIZE),
    SX_FIELD("bca_size","uint32",88,4,SX_SIZE),
    SX_FIELD("unknown4","uint32[3]",92,12,SX_NONE),
    SX_FIELD("dvd_structures_size","uint32",104,4,SX_SIZE),
    SX_FIELD("dvd_info_size","uint32",108,4,SX_SIZE),
};
const sx_layout sxdn_blindwrite56_disc = {0x6078003cU,"blindwrite56_disc",sxdn_blindwrite56_disc_fields,SX_COUNT(sxdn_blindwrite56_disc_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_inquiry_fields[] = {
    SX_FIELD("vendor","char[8]",0,8,SX_NONE),
    SX_FIELD("product","char[16]",8,16,SX_NONE),
    SX_FIELD("revision","char[4]",24,4,SX_ID),
    SX_FIELD("vendor_specific","byte[20]",28,20,SX_NONE),
};
const sx_layout sxdn_blindwrite56_inquiry = {0x6078003dU,"blindwrite56_inquiry",sxdn_blindwrite56_inquiry_fields,SX_COUNT(sxdn_blindwrite56_inquiry_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_volume_name_fields[] = {
    SX_FIELD("volume_identifier","char[32]",0,32,SX_NONE),
};
const sx_layout sxdn_blindwrite56_volume_name = {0x6078003eU,"blindwrite56_volume_name",sxdn_blindwrite56_volume_name_fields,SX_COUNT(sxdn_blindwrite56_volume_name_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_lengths_fields[] = {
    SX_FIELD("mode_page_2a_size","uint32",0,4,SX_SIZE),
    SX_FIELD("unknown_block_size","uint32",4,4,SX_SIZE),
    SX_FIELD("data_blocks_size","uint32",8,4,SX_SIZE),
    SX_FIELD("sessions_size","uint32",12,4,SX_SIZE),
    SX_FIELD("dpm_size","uint32",16,4,SX_SIZE),
};
const sx_layout sxdn_blindwrite56_lengths = {0x6078003fU,"blindwrite56_lengths",sxdn_blindwrite56_lengths_fields,SX_COUNT(sxdn_blindwrite56_lengths_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_data_list_fields[] = {
    SX_FIELD("block_count","uint32",0,4,SX_COUNT_PROP),
    SX_FIELD("drive_path_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxdn_blindwrite56_data_list = {0x60780040U,"blindwrite56_data_list",sxdn_blindwrite56_data_list_fields,SX_COUNT(sxdn_blindwrite56_data_list_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_data_block_fields[] = {
    SX_FIELD("type","uint32",0,4,SX_FLAGS),
    SX_FIELD("payload_size","uint32",4,4,SX_SIZE),
    SX_FIELD("unknown0","uint32[4]",8,16,SX_NONE),
    SX_FIELD("external_file_offset","uint32",24,4,SX_OFFSET),
    SX_FIELD("unknown1","uint32[3]",28,12,SX_NONE),
    SX_FIELD("start_sector","int32",40,4,SX_NONE),
    SX_FIELD("sector_count","int32",44,4,SX_COUNT_PROP),
    SX_FIELD("filename_size","uint32",48,4,SX_SIZE),
};
const sx_layout sxdn_blindwrite56_data_block = {0x60780041U,"blindwrite56_data_block",sxdn_blindwrite56_data_block_fields,SX_COUNT(sxdn_blindwrite56_data_block_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_data_tail_fields[] = {
    SX_FIELD("unknown","uint32",0,4,SX_NONE),
};
const sx_layout sxdn_blindwrite56_data_tail = {0x60780042U,"blindwrite56_data_tail",sxdn_blindwrite56_data_tail_fields,SX_COUNT(sxdn_blindwrite56_data_tail_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_session_fields[] = {
    SX_FIELD("session_number","uint16",0,2,SX_NONE),
    SX_FIELD("entry_count","uint8",2,1,SX_COUNT_PROP),
    SX_FIELD("unknown","uint8",3,1,SX_NONE),
    SX_FIELD("start_sector","int32",4,4,SX_NONE),
    SX_FIELD("end_sector","int32",8,4,SX_NONE),
    SX_FIELD("first_track","uint16",12,2,SX_NONE),
    SX_FIELD("last_track","uint16",14,2,SX_NONE),
};
const sx_layout sxdn_blindwrite56_session = {0x60780043U,"blindwrite56_session",sxdn_blindwrite56_session_fields,SX_COUNT(sxdn_blindwrite56_session_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_entry_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
    SX_FIELD("unknown0","byte[3]",1,3,SX_NONE),
    SX_FIELD("unknown1","uint32",4,4,SX_NONE),
    SX_FIELD("subchannel","uint8",8,1,SX_ID),
    SX_FIELD("unknown2","uint8",9,1,SX_NONE),
    SX_FIELD("control","uint8",10,1,SX_FLAGS),
    SX_FIELD("adr","uint8",11,1,SX_ID),
    SX_FIELD("point","uint8",12,1,SX_ID),
    SX_FIELD("track_number","uint8",13,1,SX_NONE),
    SX_FIELD("minute","uint8",14,1,SX_NONE),
    SX_FIELD("second","uint8",15,1,SX_NONE),
    SX_FIELD("frame","uint8",16,1,SX_NONE),
    SX_FIELD("zero","uint8",17,1,SX_NONE),
    SX_FIELD("pminute","uint8",18,1,SX_NONE),
    SX_FIELD("psecond","uint8",19,1,SX_NONE),
    SX_FIELD("pframe","uint8",20,1,SX_NONE),
    SX_FIELD("unknown3","uint8",21,1,SX_NONE),
    SX_FIELD("pregap_sector_count","uint32",22,4,SX_COUNT_PROP),
    SX_FIELD("unknown4","uint32[4]",26,16,SX_NONE),
    SX_FIELD("first_sector","int32",42,4,SX_NONE),
    SX_FIELD("sector_count","int32",46,4,SX_COUNT_PROP),
    SX_FIELD("unknown5","uint32[2]",50,8,SX_NONE),
    SX_FIELD("session","uint32",58,4,SX_NONE),
    SX_FIELD("unknown6","uint16",62,2,SX_NONE),
};
const sx_layout sxdn_blindwrite56_entry = {0x60780044U,"blindwrite56_entry",sxdn_blindwrite56_entry_fields,SX_COUNT(sxdn_blindwrite56_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_cd_extra_fields[] = {
    SX_FIELD("producer_data","byte[8]",0,8,SX_NONE),
};
const sx_layout sxdn_blindwrite56_cd_extra = {0x60780045U,"blindwrite56_cd_extra",sxdn_blindwrite56_cd_extra_fields,SX_COUNT(sxdn_blindwrite56_cd_extra_fields),SX_LE};
static const xx_data_struct_field_desc sxdn_blindwrite56_footer_fields[] = {
    SX_FIELD("descriptor_size","uint32",0,4,SX_SIZE),
    SX_FIELD("signature","char[16]",4,16,SX_SIGNATURE),
};
const sx_layout sxdn_blindwrite56_footer = {0x60780046U,"blindwrite56_footer",sxdn_blindwrite56_footer_fields,SX_COUNT(sxdn_blindwrite56_footer_fields),SX_LE};
#define SXDN_LIMIT 24000U
#define SXDN_ADD(c,l,p) sxdn_put(c,&sxdn_##l,p,1)
static bool sxdn_bw56(sx_context*c){uint8_t d[112],lengths[20],b[64];uint64_t p=260;if(!sxdn_read(c,16,d,112)||!sxdn_read(c,240,lengths,20)||!SXDN_ADD(c,blindwrite56_signature,0)||!SXDN_ADD(c,blindwrite56_disc,16)||!SXDN_ADD(c,blindwrite56_inquiry,160)||!SXDN_ADD(c,blindwrite56_volume_name,208)||!SXDN_ADD(c,blindwrite56_lengths,240))return false;unsigned type=sxdn16(d+32,0),sessions=sxdn16(d+34,0);uint64_t skips[]={sxdn32(lengths,0),sxdn32(lengths+4,0),sxdn16(d+80,0),sxdn16(d+82,0),sxdn16(d+84,0),sxdn32(d+88,0),sxdn32(d+104,0),type>=8&&type<=10?sxdn16(d+86,0):sxdn32(d+108,0)};for(unsigned i=0;i<SX_COUNT(skips);i++){if(!sxdn_span(c,p,skips[i]))return true;p+=skips[i];}if(!sxdn_read(c,p,b,8)||!SXDN_ADD(c,blindwrite56_data_list,p))return true;uint64_t n=sxdn32(b,0),path=sxdn32(b+4,0);p+=8;if(n>65536||!sxdn_span(c,p,path))return true;p+=path;for(uint64_t i=0;i<n&&c->count<SXDN_LIMIT;i++){if(!sxdn_read(c,p,b,52)||!SXDN_ADD(c,blindwrite56_data_block,p))return true;uint64_t z=sxdn32(b+48,0);p+=52;if(!sxdn_span(c,p,z+4))return true;p+=z;if(!SXDN_ADD(c,blindwrite56_data_tail,p))return false;p+=4;}if(sessions>256)return true;for(unsigned i=0;i<sessions&&c->count<SXDN_LIMIT;i++){if(!sxdn_read(c,p,b,16)||!SXDN_ADD(c,blindwrite56_session,p))return true;n=b[2];p+=16;for(uint64_t j=0;j<n;j++){if(!sxdn_read(c,p,b,64)||!SXDN_ADD(c,blindwrite56_entry,p))return true;p+=64;if(b[0]>=1&&b[0]<=5){if(!SXDN_ADD(c,blindwrite56_cd_extra,p))return true;p+=8;}}}n=sxdn32(lengths+16,0);if(!sxdn_span(c,p,n+20))return true;p+=n;return SXDN_ADD(c,blindwrite56_footer,p);}
bool sx_blindwrite_5_6_image_build(sx_context*c)
{
 return sxdn_bw56(c);
}
#undef SXDN_LIMIT
#undef SXDN_ADD
