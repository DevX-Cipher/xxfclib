/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Supercard Scp data structures, moved out of the systemextra schema family. */
#include "../../xx_format_schema_systemextra.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxse_scp_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("version_bcd","uint8",3,1,SX_NONE),
    SX_FIELD("disk_type","uint8",4,1,SX_ID),
    SX_FIELD("revolution_count","uint8",5,1,SX_COUNT_PROP),
    SX_FIELD("first_track","uint8",6,1,SX_ID),
    SX_FIELD("last_track","uint8",7,1,SX_ID),
    SX_FIELD("flags","uint8",8,1,SX_FLAGS),
    SX_FIELD("bitcell_width","uint8",9,1,SX_NONE),
    SX_FIELD("heads","uint8",10,1,SX_ID),
    SX_FIELD("resolution_multiplier","uint8",11,1,SX_NONE),
    SX_FIELD("checksum","uint32",12,4,SX_CHECKSUM),
};
const sx_layout sxse_scp_header = {0x602f0023U,"scp_header",sxse_scp_header_fields,SX_COUNT(sxse_scp_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_scp_track_offset_fields[] = {
    SX_FIELD("track_offset","uint32",0,4,SX_OFFSET),
};
const sx_layout sxse_scp_track_offset = {0x602f0024U,"scp_track_offset",sxse_scp_track_offset_fields,SX_COUNT(sxse_scp_track_offset_fields),SX_LE};
static const xx_data_struct_field_desc sxse_scp_track_header_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("track_number","uint8",3,1,SX_ID),
};
const sx_layout sxse_scp_track_header = {0x602f0025U,"scp_track_header",sxse_scp_track_header_fields,SX_COUNT(sxse_scp_track_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_scp_revolution_fields[] = {
    SX_FIELD("index_duration","uint32",0,4,SX_NONE),
    SX_FIELD("sample_count","uint32",4,4,SX_COUNT_PROP),
    SX_FIELD("data_offset","uint32",8,4,SX_OFFSET),
};
const sx_layout sxse_scp_revolution = {0x602f0026U,"scp_revolution",sxse_scp_revolution_fields,SX_COUNT(sxse_scp_revolution_fields),SX_LE};
static const xx_data_struct_field_desc sxse_scp_extension_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxse_scp_extension_header = {0x602f0027U,"scp_extension_header",sxse_scp_extension_header_fields,SX_COUNT(sxse_scp_extension_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_scp_write_splices_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",4,4,SX_SIZE),
    SX_FIELD("reserved","uint32",8,4,SX_RESERVED),
};
const sx_layout sxse_scp_write_splices_header = {0x602f0028U,"scp_write_splices_header",sxse_scp_write_splices_header_fields,SX_COUNT(sxse_scp_write_splices_header_fields),SX_LE};
static const xx_data_struct_field_desc sxse_scp_write_splice_fields[] = {
    SX_FIELD("write_splice","uint32",0,4,SX_NONE),
};
const sx_layout sxse_scp_write_splice = {0x602f0029U,"scp_write_splice",sxse_scp_write_splice_fields,SX_COUNT(sxse_scp_write_splice_fields),SX_LE};
static const xx_data_struct_field_desc sxse_scp_footer_fields[] = {
    SX_FIELD("drive_manufacturer_offset","uint32",0,4,SX_OFFSET),
    SX_FIELD("drive_model_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("drive_serial_offset","uint32",8,4,SX_OFFSET),
    SX_FIELD("creator_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("application_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("comments_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("creation_time","int64",24,8,SX_TIME),
    SX_FIELD("modification_time","int64",32,8,SX_TIME),
    SX_FIELD("application_version_bcd","uint8",40,1,SX_NONE),
    SX_FIELD("hardware_version_bcd","uint8",41,1,SX_NONE),
    SX_FIELD("firmware_version_bcd","uint8",42,1,SX_NONE),
    SX_FIELD("footer_version_bcd","uint8",43,1,SX_NONE),
    SX_FIELD("signature","char[4]",44,4,SX_SIGNATURE),
};
const sx_layout sxse_scp_footer = {0x602f002aU,"scp_footer",sxse_scp_footer_fields,SX_COUNT(sxse_scp_footer_fields),SX_LE};
static const xx_data_struct_field_desc sxse_scp_string_header_fields[] = {
    SX_FIELD("string_size","uint16",0,2,SX_SIZE),
};
const sx_layout sxse_scp_string_header = {0x602f002bU,"scp_string_header",sxse_scp_string_header_fields,SX_COUNT(sxse_scp_string_header_fields),SX_LE};
#define SXSE_ADD(c,l,p,z) sxse_put(c,&sxse_##l,p,z,1)
#define SXSE_TABLE(c,l,p,z,n) sxse_put(c,&sxse_##l,p,z,n)
static bool sxse_scp(sx_context*c){uint8_t h[16],b[48];uint64_t first=(uint64_t)c->size;if(!sxse_read(c,0,h,16)||xx_rt_memcmp(h,"SCP",3)||h[5]<1||h[5]>5||!SXSE_ADD(c,scp_header,0,16)||!SXSE_TABLE(c,scp_track_offset,16,4,168))return false;
 for(unsigned i=0;i<168;i++){uint32_t p;if(!sx_u32(c,16+4*i,false,&p))return false;if(!p)continue;if(p<688||!sxse_read(c,p,b,4)||xx_rt_memcmp(b,"TRK",3)||!SXSE_ADD(c,scp_track_header,p,4)||!SXSE_TABLE(c,scp_revolution,(uint64_t)p+4,12,h[5]))return false;if(p<first)first=p;}
 if(first>688&&sxse_read(c,688,b,8)&&!xx_rt_memcmp(b,"EXTS",4)){uint64_t z=sxse_u32(b,4,false),end=696+z;if(end>first||!sxse_span(c,696,z)||!SXSE_ADD(c,scp_extension_header,688,8))return false;uint64_t p=696;for(unsigned i=0;p<end&&i<4096;i++){if(end-p<8||!sxse_read(c,p,b,8))return false;z=sxse_u32(b,4,false);if(z>end-p-8)return false;if(!xx_rt_memcmp(b,"WRSP",4)&&z==676){if(!SXSE_ADD(c,scp_write_splices_header,p,12)||!SXSE_TABLE(c,scp_write_splice,p+12,4,168))return false;}else if(!SXSE_ADD(c,scp_extension_header,p,8))return false;p+=8+z;}if(p!=end)return false;}
 if(h[8]&32){if(c->size<48)return false;uint64_t p=(uint64_t)c->size-48;if(!sxse_read(c,p,b,48)||xx_rt_memcmp(b+44,"FPCS",4)||!SXSE_ADD(c,scp_footer,p,48))return false;for(unsigned i=0;i<6;i++){uint32_t q=sxse_u32(b,4*i,false);if(q){uint16_t z;if(q>=p||!sx_u16(c,q,false,&z)||z>p-q-2||!sxse_span(c,q,3+(uint64_t)z)||!SXSE_ADD(c,scp_string_header,q,2))return false;}}}return true;}
bool sx_supercard_scp_build(sx_context*c)
{
 return sxse_scp(c);
}
#undef SXSE_ADD
#undef SXSE_TABLE
