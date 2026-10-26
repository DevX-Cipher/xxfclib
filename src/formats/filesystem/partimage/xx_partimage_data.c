/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Partimage data structures, moved out of the volumeimages schema family. */
#include "../../xx_format_schema_volumeimages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxvi_partimage_volume_header_fields[] = {
    SX_FIELD("magic","char[32]",0,32,SX_SIGNATURE),
    SX_FIELD("version","char[64]",32,64,SX_STRING),
    SX_FIELD("volume_number","uint32",96,4,SX_NONE),
    SX_FIELD("identifier","uint64",100,8,SX_ID),
    SX_FIELD("reserved","byte[404]",108,404,SX_RESERVED),
};
const sx_layout sxvi_partimage_volume_header = {0x6053005eU,"partimage_volume_header",sxvi_partimage_volume_header_fields,SX_COUNT(sxvi_partimage_volume_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_partimage_main_header_fields[] = {
    SX_FIELD("filesystem","char[512]",0,512,SX_STRING),
    SX_FIELD("description","char[4096]",512,4096,SX_STRING),
    SX_FIELD("original_device","char[512]",4608,512,SX_STRING),
    SX_FIELD("first_image_filepath","char[4095]",5120,4095,SX_STRING),
    SX_FIELD("uname_system","char[65]",9215,65,SX_STRING),
    SX_FIELD("uname_node","char[65]",9280,65,SX_STRING),
    SX_FIELD("uname_release","char[65]",9345,65,SX_STRING),
    SX_FIELD("uname_version","char[65]",9410,65,SX_STRING),
    SX_FIELD("uname_machine","char[65]",9475,65,SX_STRING),
    SX_FIELD("compression","uint32",9540,4,SX_ID),
    SX_FIELD("flags","uint32",9544,4,SX_FLAGS),
    SX_FIELD("second","uint32",9548,4,SX_NONE),
    SX_FIELD("minute","uint32",9552,4,SX_NONE),
    SX_FIELD("hour","uint32",9556,4,SX_NONE),
    SX_FIELD("day","uint32",9560,4,SX_NONE),
    SX_FIELD("month","uint32",9564,4,SX_NONE),
    SX_FIELD("year","uint32",9568,4,SX_NONE),
    SX_FIELD("weekday","uint32",9572,4,SX_NONE),
    SX_FIELD("yearday","uint32",9576,4,SX_NONE),
    SX_FIELD("daylight_saving","uint32",9580,4,SX_NONE),
    SX_FIELD("timezone_offset","uint32",9584,4,SX_NONE),
    SX_FIELD("timezone_word","uint32",9588,4,SX_NONE),
    SX_FIELD("partition_size","uint64",9592,8,SX_SIZE),
    SX_FIELD("hostname","char[128]",9600,128,SX_STRING),
    SX_FIELD("version","char[64]",9728,64,SX_STRING),
    SX_FIELD("mbr_count","uint32",9792,4,SX_COUNT_PROP),
    SX_FIELD("mbr_record_size","uint32",9796,4,SX_SIZE),
    SX_FIELD("encryption_algorithm","uint32",9800,4,SX_ID),
    SX_FIELD("test_key_hash","byte[16]",9804,16,SX_CHECKSUM),
    SX_FIELD("future_extensions","uint32[10]",9820,40,SX_RESERVED),
    SX_FIELD("reserved","byte[6524]",9860,6524,SX_RESERVED),
};
const sx_layout sxvi_partimage_main_header = {0x6053005fU,"partimage_main_header",sxvi_partimage_main_header_fields,SX_COUNT(sxvi_partimage_main_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_partimage_local_header_fields[] = {
    SX_FIELD("block_size","uint64",0,8,SX_SIZE),
    SX_FIELD("used_blocks","uint64",8,8,SX_COUNT_PROP),
    SX_FIELD("block_count","uint64",16,8,SX_COUNT_PROP),
    SX_FIELD("bitmap_size","uint64",24,8,SX_SIZE),
    SX_FIELD("bad_blocks","uint64",32,8,SX_COUNT_PROP),
    SX_FIELD("label","char[64]",40,64,SX_STRING),
    SX_FIELD("reserved","byte[16280]",104,16280,SX_RESERVED),
};
const sx_layout sxvi_partimage_local_header = {0x60530060U,"partimage_local_header",sxvi_partimage_local_header_fields,SX_COUNT(sxvi_partimage_local_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_partimage_header_checksum_fields[] = {
    SX_FIELD("additive_checksum","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxvi_partimage_header_checksum = {0x60530061U,"partimage_header_checksum",sxvi_partimage_header_checksum_fields,SX_COUNT(sxvi_partimage_header_checksum_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_partimage_extension_header_fields[] = {
    SX_FIELD("magic","char[18]",0,18,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",18,4,SX_SIZE),
};
const sx_layout sxvi_partimage_extension_header = {0x60530062U,"partimage_extension_header",sxvi_partimage_extension_header_fields,SX_COUNT(sxvi_partimage_extension_header_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_partimage_data_check_fields[] = {
    SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("crc32","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("block_position","uint64",8,8,SX_NONE),
};
const sx_layout sxvi_partimage_data_check = {0x60530063U,"partimage_data_check",sxvi_partimage_data_check_fields,SX_COUNT(sxvi_partimage_data_check_fields),SX_LE};
static const xx_data_struct_field_desc sxvi_partimage_tail_fields[] = {
    SX_FIELD("additive_checksum","uint64",0,8,SX_CHECKSUM),
    SX_FIELD("volume_number","uint32",8,4,SX_NONE),
    SX_FIELD("reserved","byte[16372]",12,16372,SX_RESERVED),
};
const sx_layout sxvi_partimage_tail = {0x60530064U,"partimage_tail",sxvi_partimage_tail_fields,SX_COUNT(sxvi_partimage_tail_fields),SX_LE};
#define SXVI_LIMIT 24000U
#define SXVI_ADD(c,l,p) sxvi_put(c,&sxvi_##l,p,1)
static bool sxvi_pi_marker(sx_context*c,uint64_t*p,const char*str){size_t n=xx_rt_strlen(str);if(!sxvi_magic(c,*p,str,n))return false;*p+=n;return true;}
static bool sxvi_partimage(sx_context*c){uint8_t b[40];uint64_t p=512;if(!sxvi_magic(c,0,"PaRtImAgE-VoLuMe\0",16)||!sxvi_magic(c,32,"0.6.1\0",6)||!sxvi_magic(c,512+9728,"0.6.1\0",6)||!SXVI_ADD(c,partimage_volume_header,0)||!SXVI_ADD(c,partimage_main_header,p)||!SXVI_ADD(c,partimage_header_checksum,p+16384))return false;p+=16388;
 if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-MBRBACKUP"))return true;for(unsigned i=0;i<10;i++){char magic[32];xx_rt_snprintf(magic,sizeof(magic),"MAGIC-BEGIN-EXT%03u",i);if(!sxvi_magic(c,p,magic,18)||!sxvi_read(c,p+18,b,4))return true;uint64_t n=sxvi32(b,0);if(!SXVI_ADD(c,partimage_extension_header,p)||!sxvi_span(c,p+22,n))return false;p+=22+n;}
 if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-LOCALHEADER")||!sxvi_read(c,p,b,40))return true;uint64_t bs=sxvi64(b,0),used=sxvi64(b+8,0),blocks=sxvi64(b+16,0),bitmap=sxvi64(b+24,0);if(!SXVI_ADD(c,partimage_local_header,p)||!SXVI_ADD(c,partimage_header_checksum,p+16384))return false;p+=16388;
 if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-BITMAP")||!sxvi_span(c,p,bitmap))return true;p+=bitmap;if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-INFO")||!sxvi_span(c,p,16388))return true;if(!SXVI_ADD(c,partimage_header_checksum,p+16384))return false;p+=16388;if(!sxvi_pi_marker(c,&p,"MAGIC-BEGIN-DATABLOCKS"))return true;
 if(!bs||bs>65536||used>blocks||used>UINT64_MAX/bs)return true;uint64_t bytes=used*bs,checks=bytes/65536;if(bytes>UINT64_MAX-checks*16||!sxvi_span(c,p,bytes+checks*16))return true;uint64_t end=p+bytes+checks*16;
 for(uint64_t i=0;i<checks&&c->count<SXVI_LIMIT;i++){uint64_t at=p+(i+1)*65536+i*16;if(!sxvi_magic(c,at,"CHK\0",4))break;if(!SXVI_ADD(c,partimage_data_check,at))return false;}
 if(!sxvi_pi_marker(c,&end,"MAGIC-BEGIN-TAIL")||!sxvi_span(c,end,16384))return true;return SXVI_ADD(c,partimage_tail,end);
}
bool sx_partimage_build(sx_context*c)
{
 return sxvi_partimage(c);
}
#undef SXVI_LIMIT
#undef SXVI_ADD
