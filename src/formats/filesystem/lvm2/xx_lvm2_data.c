/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Lvm2 data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_lvm2_label_header_fields[] = {
    SX_FIELD("signature","char[8]",0,8,SX_SIGNATURE),
    SX_FIELD("sector_number","uint64",8,8,SX_NONE),
    SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("pv_header_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("type","char[8]",24,8,SX_STRING),
};
const sx_layout sxvi_lvm2_label_header = {0x60530001U,"lvm2_label_header",sxvi_lvm2_label_header_fields,SX_COUNT(sxvi_lvm2_label_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_lvm2_pv_header_fields[] = {
    SX_FIELD("pv_uuid","char[32]",0,32,SX_ID),
    SX_FIELD("device_size","uint64",32,8,SX_SIZE),
};
const sx_layout sxvi_lvm2_pv_header = {0x60530002U,"lvm2_pv_header",sxvi_lvm2_pv_header_fields,SX_COUNT(sxvi_lvm2_pv_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_lvm2_disk_location_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("size","uint64",8,8,SX_SIZE),
};
const sx_layout sxvi_lvm2_disk_location = {0x60530003U,"lvm2_disk_location",sxvi_lvm2_disk_location_fields,SX_COUNT(sxvi_lvm2_disk_location_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_lvm2_pv_extension_fields[] = {
    SX_FIELD("version","uint32",0,4,SX_ID),
    SX_FIELD("flags","uint32",4,4,SX_FLAGS),
};
const sx_layout sxvi_lvm2_pv_extension = {0x60530004U,"lvm2_pv_extension",sxvi_lvm2_pv_extension_fields,SX_COUNT(sxvi_lvm2_pv_extension_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_lvm2_mda_header_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("magic","char[16]",4,16,SX_SIGNATURE),
    SX_FIELD("version","uint32",20,4,SX_ID),
    SX_FIELD("start","uint64",24,8,SX_OFFSET),
    SX_FIELD("size","uint64",32,8,SX_SIZE),
};
const sx_layout sxvi_lvm2_mda_header = {0x60530005U,"lvm2_mda_header",sxvi_lvm2_mda_header_fields,SX_COUNT(sxvi_lvm2_mda_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_lvm2_raw_location_fields[] = {
    SX_FIELD("offset","uint64",0,8,SX_OFFSET),
    SX_FIELD("size","uint64",8,8,SX_SIZE),
    SX_FIELD("crc32","uint32",16,4,SX_CHECKSUM),
    SX_FIELD("flags","uint32",20,4,SX_FLAGS),
};
const sx_layout sxvi_lvm2_raw_location = {0x60530006U,"lvm2_raw_location",sxvi_lvm2_raw_location_fields,SX_COUNT(sxvi_lvm2_raw_location_fields),SX_LE};
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
static bool sxvi_lvm(sx_context*c){uint8_t h[512],b[512];uint64_t label=UINT64_MAX,pv=0;
 for(unsigned i=0;i<4;i++)if(sxvi_read(c,i*512,h,512)&&!xx_rt_memcmp(h,"LABELONE",8)&&!xx_rt_memcmp(h+24,"LVM2 001",8)&&sxvi64(h+8,0)==i){label=i*512;pv=sxvi32(h+20,0);break;}
 if(label==UINT64_MAX||pv<32||pv>440||!SXVI_ADD(c,lvm2_label_header,label)||!SXVI_ADD(c,lvm2_pv_header,label+pv))return false;
 uint64_t pos=pv+40,metas[28];size_t count=0;for(unsigned list=0;list<2;list++){bool end=false;while(pos+16<=512){uint64_t off=sxvi64(h+pos,0),z=sxvi64(h+pos+8,0);if(!SXVI_ADD(c,lvm2_disk_location,label+pos))return false;pos+=16;if(!off&&!z){end=true;break;}if(list&&count<SX_COUNT(metas)&&z>=512&&sxvi_span(c,off,z))metas[count++]=off;}if(!end)return true;}
 if(pos+8<=512&&sxvi32(h+pos,0)&&sxvi32(h+pos,0)<=2){if(!SXVI_ADD(c,lvm2_pv_extension,label+pos))return false;pos+=8;/* Version1 introduces the bootloader-area list; version2 adds PV_EXT_USED. */while(pos+16<=512){uint64_t off=sxvi64(h+pos,0),z=sxvi64(h+pos+8,0);if(!SXVI_ADD(c,lvm2_disk_location,label+pos))return false;pos+=16;if(!off&&!z)break;}}
 for(size_t i=0;i<count;i++){uint64_t p=metas[i];if(!sxvi_read(c,p,b,512)||xx_rt_memcmp(b+4," LVM2 x[5A%r0N*>",16)||sxvi32(b+20,0)!=1)continue;if(!SXVI_ADD(c,lvm2_mda_header,p))return false;for(unsigned q=40;q+24<=512;q+=24){if(!SXVI_ADD(c,lvm2_raw_location,p+q))return false;if(!sxvi64(b+q,0))break;}}
 return true;
}
bool sx_lvm2_build(sx_context*c)
{
 return sxvi_lvm(c);
}
#undef SXVI_ADD
