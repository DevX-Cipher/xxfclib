/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * sfx_clickteam_multimedia_fusion data structures, moved out of the installerextras schema family. */
#include "../../xx_format_schema_installerextras.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxiex_installer_utf16_name_fields[] = {
    SX_FIELD("name","uint16",0,0,SX_NONE),
};
const sx_layout sxiex_installer_utf16_name = {0x60820004U,"installer_utf16_name",sxiex_installer_utf16_name_fields,SX_COUNT(sxiex_installer_utf16_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_clickteam_pack_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("secondary_signature","uint32",4,4,SX_SIGNATURE),
    SX_FIELD("header_size","uint32",8,4,SX_SIZE),
    SX_FIELD("pack_size","uint32",12,4,SX_SIZE),
    SX_FIELD("unknown","uint32",16,4,SX_NONE),
    SX_FIELD("reserved1","uint32",20,4,SX_RESERVED),
    SX_FIELD("reserved2","uint32",24,4,SX_RESERVED),
    SX_FIELD("file_count","uint32",28,4,SX_COUNT_PROP),
};
const sx_layout sxiex_clickteam_pack = {0x6082003bU,"clickteam_pack",sxiex_clickteam_pack_fields,SX_COUNT(sxiex_clickteam_pack_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_clickteam_name_fields[] = {
    SX_FIELD("name_length","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxiex_clickteam_name = {0x6082003cU,"clickteam_name",sxiex_clickteam_name_fields,SX_COUNT(sxiex_clickteam_name_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_clickteam_size_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
};
const sx_layout sxiex_clickteam_size = {0x6082003dU,"clickteam_size",sxiex_clickteam_size_fields,SX_COUNT(sxiex_clickteam_size_fields),SX_LE};
static const xx_data_struct_field_desc sxiex_clickteam_checksum_size_fields[] = {
    SX_FIELD("checksum","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("packed_size","uint32",4,4,SX_SIZE),
};
const sx_layout sxiex_clickteam_checksum_size = {0x6082003eU,"clickteam_checksum_size",sxiex_clickteam_checksum_size_fields,SX_COUNT(sxiex_clickteam_checksum_size_fields),SX_LE};
#define SXIEX_ADD(c,n,p) sxiex_put(c,&sxiex_##n,p,1)
static bool sxiex_clickteam(sx_context*c,const sxiex_records*r){
 uint64_t p=0;if(!sxiex_pe(c,&p)||!sxiex_eq(c,p,"wwww",4))return true;if(!SXIEX_ADD(c,clickteam_pack,p))return false;
 bool known=false,unicode=false,two=false;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint16_t n;if(m->header!=p+32||!sxiex_u16(c,m->header,&n)||!n)continue;unsigned choices=0;
 for(unsigned u=0;u<2;u++)for(unsigned t=0;t<2;t++){uint64_t nb=(uint64_t)n*(u+1);uint32_t z,crc;if(m->header_size!=2+nb+(t?8:4)||!sxiex_u32(c,m->header+2+nb+(t?4:0),&z)||z!=m->packed)continue;if(t&&(!sxiex_u32(c,m->header+2+nb,&crc)||crc))continue;unicode=u!=0;two=t!=0;choices++;}known=choices==1;break;}
 if(!known)return true;
 for(size_t i=0;i<r->count;i++){const sxiex_member*m=r->items+i;uint16_t n;if(!m->header_size||!sxiex_u16(c,m->header,&n))continue;uint64_t nb=(uint64_t)n*(unicode?2:1);if(m->header_size!=2+nb+(two?8:4))continue;
 if(!SXIEX_ADD(c,clickteam_name,m->header)||!sxiex_text(c,unicode?&sxiex_installer_utf16_name:&sxiex_installer_name,m->header+2,nb)||!sxiex_put(c,two?&sxiex_clickteam_checksum_size:&sxiex_clickteam_size,m->header+2+nb,1))return false;}
 return true;
}
bool sx_sfx_clickteam_multimedia_fusion_build(sx_context*c,const sxiex_records*records)
{
 return sxiex_clickteam(c,records);
}
#undef SXIEX_ADD
