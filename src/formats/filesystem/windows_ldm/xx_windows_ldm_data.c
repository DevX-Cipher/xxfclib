/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Windows Ldm data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_ldm_private_header_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("unknown0","byte[4]",8,4,SX_NONE),
    SX_FIELD("major_version","uint16",12,2,SX_ID),
    SX_FIELD("minor_version","uint16",14,2,SX_ID),
    SX_FIELD("unknown1","byte[32]",16,32,SX_NONE),
    SX_FIELD("disk_uuid","char[36]",48,36,SX_ID),
    SX_FIELD("unknown2","byte[199]",84,199,SX_NONE),
    SX_FIELD("logical_disk_start","uint64",283,8,SX_NONE),
    SX_FIELD("logical_disk_sectors","uint64",291,8,SX_COUNT_PROP),
    SX_FIELD("configuration_start","uint64",299,8,SX_NONE),
    SX_FIELD("configuration_sectors","uint64",307,8,SX_COUNT_PROP),
    SX_FIELD("unknown3","byte[197]",315,197,SX_NONE),
};
const sx_layout sxvi_ldm_private_header = {0x6053004cU,"ldm_private_header",sxvi_ldm_private_header_fields,SX_COUNT(sxvi_ldm_private_header_fields),SX_BE};
static const xx_data_struct_field_desc sxvi_ldm_tocblock_fields[] = {
    SX_FIELD("magic","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("unknown0","byte[28]",8,28,SX_NONE),
    SX_FIELD("configuration_name","char[10]",36,10,SX_STRING),
    SX_FIELD("configuration_start","uint64",46,8,SX_NONE),
    SX_FIELD("configuration_sectors","uint64",54,8,SX_COUNT_PROP),
    SX_FIELD("unknown1","byte[8]",62,8,SX_NONE),
    SX_FIELD("log_name","char[10]",70,10,SX_STRING),
    SX_FIELD("log_start","uint64",80,8,SX_NONE),
    SX_FIELD("log_sectors","uint64",88,8,SX_COUNT_PROP),
    SX_FIELD("unknown2","byte[416]",96,416,SX_NONE),
};
const sx_layout sxvi_ldm_tocblock = {0x6053004dU,"ldm_tocblock",sxvi_ldm_tocblock_fields,SX_COUNT(sxvi_ldm_tocblock_fields),SX_BE};
static const xx_data_struct_field_desc sxvi_ldm_vmdb_header_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("last_vblk_sequence","uint32",4,4,SX_NONE),
    SX_FIELD("vblk_size","uint32",8,4,SX_SIZE),
    SX_FIELD("vblk_offset","uint32",12,4,SX_OFFSET),
    SX_FIELD("update_state","uint16",16,2,SX_ID),
    SX_FIELD("major_version","uint16",18,2,SX_ID),
    SX_FIELD("minor_version","uint16",20,2,SX_ID),
};
const sx_layout sxvi_ldm_vmdb_header = {0x6053004eU,"ldm_vmdb_header",sxvi_ldm_vmdb_header_fields,SX_COUNT(sxvi_ldm_vmdb_header_fields),SX_BE};
static const xx_data_struct_field_desc sxvi_ldm_vblk_fragment_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("sequence","uint32",4,4,SX_ID),
    SX_FIELD("group","uint32",8,4,SX_ID),
    SX_FIELD("fragment_number","uint16",12,2,SX_NONE),
    SX_FIELD("fragment_count","uint16",14,2,SX_COUNT_PROP),
};
const sx_layout sxvi_ldm_vblk_fragment = {0x6053004fU,"ldm_vblk_fragment",sxvi_ldm_vblk_fragment_fields,SX_COUNT(sxvi_ldm_vblk_fragment_fields),SX_BE};
static const xx_data_struct_field_desc sxvi_ldm_vblk_record_header_fields[] = {
    SX_FIELD("unknown","byte[2]",0,2,SX_NONE),
    SX_FIELD("flags","uint8",2,1,SX_FLAGS),
    SX_FIELD("type","uint8",3,1,SX_ID),
    SX_FIELD("declared_length","uint32",4,4,SX_SIZE),
};
const sx_layout sxvi_ldm_vblk_record_header = {0x60530050U,"ldm_vblk_record_header",sxvi_ldm_vblk_record_header_fields,SX_COUNT(sxvi_ldm_vblk_record_header_fields),SX_BE};
static const xx_data_struct_field_desc sxvi_ldm_variable_length_fields[] = {
    SX_FIELD("length","uint8",0,1,SX_SIZE),
};
const sx_layout sxvi_ldm_variable_length = {0x60530051U,"ldm_variable_length",sxvi_ldm_variable_length_fields,SX_COUNT(sxvi_ldm_variable_length_fields),SX_LE};
#define SXVI_LIMIT 24000U
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
static bool sxvi_ldm(sx_context*c){uint8_t h[512],b[32];if(!sxvi_read(c,3072,h,512)||xx_rt_memcmp(h,"PRIVHEAD",8)||sxvi16(h+12,1)!=2||!SXVI_ADD(c,ldm_private_header,3072))return false;uint64_t config=sxvi64(h+299,1),n=sxvi64(h+307,1);if(config>(uint64_t)c->size/512||n<32||n>32768||n>(uint64_t)c->size/512-config)return true;uint64_t base=config*512;
 const unsigned toc[]={1,2,2045,2046},ph[]={1856,2047};for(unsigned i=0;i<SX_COUNT(ph);i++)if(ph[i]<n&&sxvi_magic(c,base+ph[i]*512,"PRIVHEAD",8)&&!SXVI_ADD(c,ldm_private_header,base+ph[i]*512))return false;
 for(unsigned i=0;i<SX_COUNT(toc);i++)if(toc[i]<n&&sxvi_magic(c,base+toc[i]*512,"TOCBLOCK",8)&&!SXVI_ADD(c,ldm_tocblock,base+toc[i]*512))return false;
 uint64_t p=base+17*512;if(!sxvi_read(c,p,b,22)||xx_rt_memcmp(b,"VMDB",4)||!SXVI_ADD(c,ldm_vmdb_header,p))return true;uint64_t last=sxvi32(b+4,1),z=sxvi32(b+8,1),start=sxvi32(b+12,1);if(z<32||z>4096||!sxvi_pow(z)||start<512||start%z||last>(n-17)*512/z||start>last*z)return true;
 for(uint64_t q=start;q<last*z&&c->count<SXVI_LIMIT;q+=z){if(!sxvi_read(c,p+q,b,24)||xx_rt_memcmp(b,"VBLK",4))break;if(!SXVI_ADD(c,ldm_vblk_fragment,p+q))return false;if(sxvi16(b+12,1)==0&&sxvi16(b+14,1)){if(!SXVI_ADD(c,ldm_vblk_record_header,p+q+16))return false;/* Only unfragmented common ID/name length bytes have direct coordinates. */if(sxvi16(b+14,1)==1){uint64_t v=24;for(unsigned k=0;k<2;k++){uint8_t len;if(v>=z||!sxvi_read(c,p+q+v,&len,1)||len>z-v-1)break;if(!SXVI_ADD(c,ldm_variable_length,p+q+v))return false;v+=1+len;}}}}
 return true;
}
bool sx_windows_ldm_build(sx_context*c)
{
 return sxvi_ldm(c);
}
#undef SXVI_LIMIT
#undef SXVI_ADD
