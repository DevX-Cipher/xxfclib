/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * TAR NEXTSTEP data structures, moved out of the archivepackages schema family. */
#include "../../xx_format_schema_archivepackages.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxap_tar_nextstep_header_fields[] = {
 SX_FIELD("name","char[225]",0,225,SX_NONE),
 SX_FIELD("mode","ascii_octal_padded[8]",225,8,SX_FLAGS),
 SX_FIELD("uid","ascii_octal_padded[8]",233,8,SX_NONE),
 SX_FIELD("gid","ascii_octal_padded[8]",241,8,SX_NONE),
 SX_FIELD("payload_size","ascii_octal_padded[12]",249,12,SX_SIZE),
 SX_FIELD("modification_time","ascii_octal_padded[12]",261,12,SX_TIME),
 SX_FIELD("checksum","ascii_octal_padded[8]",273,8,SX_CHECKSUM),
 SX_FIELD("typeflag","char[1]",281,1,SX_NONE),
 SX_FIELD("unknown_tail","uint8[230]",282,230,SX_NONE),
};
const sx_layout sxap_tar_nextstep_header = {UINT32_C(0x60720032),"tar_nextstep_header",sxap_tar_nextstep_header_fields,SX_COUNT(sxap_tar_nextstep_header_fields),SX_LE};
static bool sxap_octal(const uint8_t*b,size_t n,uint64_t*v){*v=0;size_t i=0;while(i<n&&(b[i]==' '||!b[i]))i++;bool digit=false;for(;i<n;i++){if(b[i]==' '||!b[i]){for(;i<n;i++)if(b[i]!=' '&&b[i])return false;break;}if(b[i]<'0'||b[i]>'7'||*v>(UINT64_MAX-(b[i]-'0'))/8)return false;*v=*v*8+b[i]-'0';digit=true;}return digit;}
static bool sxap_tar(sx_context*c){uint64_t p=0;uint8_t h[512];while(sxap_read(c,p,h,512)){bool zero=true;for(unsigned i=0;i<512;i++)if(h[i])zero=false;if(zero)break;uint64_t stored,z,checksum=8*32;if(!sxap_octal(h+0x111,8,&stored))return true;for(unsigned i=0;i<512;i++)if(i<0x111||i>=0x119)checksum+=h[i];if(stored!=checksum||!sxap_add(c,&sxap_tar_nextstep_header,p)||!sxap_octal(h+0xf9,12,&z))return true;if(h[0x119]=='1'||h[0x119]=='2')z=0;if(z>UINT64_MAX-511)return false;z=(z+511)&~UINT64_C(511);p+=512;if(!sxap_span(c,p,z))return true;p+=z;}return true;}
bool sx_tar_nextstep_build(sx_context*c)
{
 return sxap_tar(c);
}
