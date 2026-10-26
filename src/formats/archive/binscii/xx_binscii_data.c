/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * BinSCII data structures, moved out of the archiveremaining schema family. */
#include "../../xx_format_schema_archiveremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxarm_binscii_signature_fields[]={
 SX_FIELD("signature","char[18]",0,18,SX_SIGNATURE),
};
const sx_layout sxarm_binscii_signature={UINT32_C(0x607c0030),"binscii_signature",sxarm_binscii_signature_fields,SX_COUNT(sxarm_binscii_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_binscii_alphabet_fields[]={
 SX_FIELD("alphabet","char[64]",0,64,SX_STRING),
};
const sx_layout sxarm_binscii_alphabet={UINT32_C(0x607c0031),"binscii_alphabet",sxarm_binscii_alphabet_fields,SX_COUNT(sxarm_binscii_alphabet_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_binscii_header_fields[]={
 SX_FIELD("name_length_code","char[1]",0,1,SX_NONE),
 SX_FIELD("prodos_name","char[15]",1,15,SX_STRING),
 SX_FIELD("encoded_metadata","char[36]",16,36,SX_NONE),
};
const sx_layout sxarm_binscii_header={UINT32_C(0x607c0032),"binscii_header",sxarm_binscii_header_fields,SX_COUNT(sxarm_binscii_header_fields),SX_LE};
static const xx_data_struct_field_desc sxarm_binscii_data_crc_fields[]={
 SX_FIELD("encoded_crc_and_padding","char[4]",0,4,SXARM_CHECKSUM),
};
const sx_layout sxarm_binscii_data_crc={UINT32_C(0x607c0033),"binscii_data_crc",sxarm_binscii_data_crc_fields,SX_COUNT(sxarm_binscii_data_crc_fields),SX_LE};
static bool sxarm_binscii(sx_context*c){uint64_t p=0,next;uint8_t b[4096],alphabet[64];size_t n;unsigned state=0;uint64_t lines=0;while(p<(uint64_t)c->size){if(!sxarm_line(c,p,b,sizeof(b),&n,&next))return true;size_t a=0;while(a<n&&b[a]<=32)a++;size_t len=n-a;if(len==18&&!xx_rt_memcmp(b+a,"FiLeStArTfIlEsTaRt",18)){if(!sxarm_add(c,&sxarm_binscii_signature,p+a))return false;state=1;}else if(state==1){if(len<64)return true;if(!sxarm_add(c,&sxarm_binscii_alphabet,p+a))return false;xx_rt_memcpy(alphabet,b+a,64);state=2;}else if(state==2){if(len<52||!sxarm_add(c,&sxarm_binscii_header,p+a))return true;uint8_t raw[27];for(unsigned i=0;i<9;i++){unsigned v[4];for(unsigned j=0;j<4;j++){v[j]=64;for(unsigned k=0;k<64;k++)if(alphabet[k]==b[a+16+4*i+j]){v[j]=k;break;}if(v[j]==64)return true;}raw[3*i]=(uint8_t)(v[3]<<2|v[2]>>4);raw[3*i+1]=(uint8_t)(v[2]<<4|v[1]>>2);raw[3*i+2]=(uint8_t)(v[1]<<6|v[0]);}lines=(sxarm_uint(raw+21,3,false)+47)/48;state=lines?3:4;}else if(state==3){if(lines&&!--lines)state=4;}else if(state==4){if(len>=4&&!sxarm_add(c,&sxarm_binscii_data_crc,p+a))return false;state=0;}p=next;}return true;}
bool sx_binscii_build(sx_context*c)
{
 return sxarm_binscii(c);
}
