/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Inno Setup data structures, moved out of the installerlast schema family. */
#include "../../xx_format_schema_installerlast.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxil_inno_loader_pointer_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("table_offset","uint32",4,4,SX_OFFSET),
    SX_FIELD("complemented_table_offset","uint32",8,4,SX_NONE),
};
const sx_layout sxil_inno_loader_pointer = {0x60850059U,"inno_loader_pointer",sxil_inno_loader_pointer_fields,SX_COUNT(sxil_inno_loader_pointer_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_loader2_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("legacy_word","uint32",32,4,SX_NONE),
    SX_FIELD("setup_header_offset","uint32",36,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",40,4,SX_OFFSET),
};
const sx_layout sxil_inno_loader2 = {0x6085005aU,"inno_loader2",sxil_inno_loader2_fields,SX_COUNT(sxil_inno_loader2_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_loader4_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",36,4,SX_OFFSET),
};
const sx_layout sxil_inno_loader4 = {0x6085005bU,"inno_loader4",sxil_inno_loader4_fields,SX_COUNT(sxil_inno_loader4_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_loader5_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",36,4,SX_OFFSET),
};
const sx_layout sxil_inno_loader5 = {0x6085005cU,"inno_loader5",sxil_inno_loader5_fields,SX_COUNT(sxil_inno_loader5_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_loader6_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_packed_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",36,4,SX_OFFSET),
    SX_FIELD("table_crc32","uint32",40,4,SX_CHECKSUM),
};
const sx_layout sxil_inno_loader6 = {0x6085005dU,"inno_loader6",sxil_inno_loader6_fields,SX_COUNT(sxil_inno_loader6_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_loader7_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("total_size","uint32",12,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",16,4,SX_OFFSET),
    SX_FIELD("exe_unpacked_size","uint32",20,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",24,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",28,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("table_crc32","uint32",36,4,SX_CHECKSUM),
};
const sx_layout sxil_inno_loader7 = {0x6085005eU,"inno_loader7",sxil_inno_loader7_fields,SX_COUNT(sxil_inno_loader7_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_loader_revision1_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("revision","uint32",12,4,SX_ID),
    SX_FIELD("total_size","uint32",16,4,SX_SIZE),
    SX_FIELD("exe_offset","uint32",20,4,SX_OFFSET),
    SX_FIELD("exe_unpacked_size","uint32",24,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",28,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint32",32,4,SX_OFFSET),
    SX_FIELD("data_offset","uint32",36,4,SX_OFFSET),
    SX_FIELD("table_crc32","uint32",40,4,SX_CHECKSUM),
};
const sx_layout sxil_inno_loader_revision1 = {0x6085005fU,"inno_loader_revision1",sxil_inno_loader_revision1_fields,SX_COUNT(sxil_inno_loader_revision1_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_loader_revision2_fields[] = {
    SX_FIELD("signature","byte[12]",0,12,SX_SIGNATURE),
    SX_FIELD("revision","uint32",12,4,SX_ID),
    SX_FIELD("total_size","uint64",16,8,SX_SIZE),
    SX_FIELD("exe_offset","uint64",24,8,SX_OFFSET),
    SX_FIELD("exe_unpacked_size","uint32",32,4,SX_SIZE),
    SX_FIELD("exe_checksum","uint32",36,4,SX_CHECKSUM),
    SX_FIELD("setup_header_offset","uint64",40,8,SX_OFFSET),
    SX_FIELD("data_offset","uint64",48,8,SX_OFFSET),
    SX_FIELD("reserved","uint32",56,4,SX_RESERVED),
    SX_FIELD("table_crc32","uint32",60,4,SX_CHECKSUM),
};
const sx_layout sxil_inno_loader_revision2 = {0x60850060U,"inno_loader_revision2",sxil_inno_loader_revision2_fields,SX_COUNT(sxil_inno_loader_revision2_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_setup_version_fields[] = {
    SX_FIELD("version","char[64]",0,64,SX_NONE),
};
const sx_layout sxil_inno_setup_version = {0x60850061U,"inno_setup_version",sxil_inno_setup_version_fields,SX_COUNT(sxil_inno_setup_version_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_encryption_envelope_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("encryption_kind","uint8",4,1,SX_ID),
    SX_FIELD("encryption_parameters","byte[48]",5,48,SX_NONE),
};
const sx_layout sxil_inno_encryption_envelope = {0x60850062U,"inno_encryption_envelope",sxil_inno_encryption_envelope_fields,SX_COUNT(sxil_inno_encryption_envelope_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_block_legacy_fields[] = {
    SX_FIELD("header_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("compressed_size","int32",4,4,SX_NONE),
    SX_FIELD("uncompressed_size","uint32",8,4,SX_SIZE),
};
const sx_layout sxil_inno_block_legacy = {0x60850063U,"inno_block_legacy",sxil_inno_block_legacy_fields,SX_COUNT(sxil_inno_block_legacy_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_block32_fields[] = {
    SX_FIELD("header_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("stored_extent","uint32",4,4,SX_SIZE),
    SX_FIELD("compressed","uint8",8,1,SX_FLAGS),
};
const sx_layout sxil_inno_block32 = {0x60850064U,"inno_block32",sxil_inno_block32_fields,SX_COUNT(sxil_inno_block32_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_block64_fields[] = {
    SX_FIELD("header_crc32","uint32",0,4,SX_CHECKSUM),
    SX_FIELD("stored_extent","uint64",4,8,SX_SIZE),
    SX_FIELD("compressed","uint8",12,1,SX_FLAGS),
};
const sx_layout sxil_inno_block64 = {0x60850065U,"inno_block64",sxil_inno_block64_fields,SX_COUNT(sxil_inno_block64_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_block_crc32_fields[] = {
    SX_FIELD("crc32","uint32",0,4,SX_CHECKSUM),
};
const sx_layout sxil_inno_block_crc32 = {0x60850066U,"inno_block_crc32",sxil_inno_block_crc32_fields,SX_COUNT(sxil_inno_block_crc32_fields),SX_LE};
static const xx_data_struct_field_desc sxil_inno_data_marker_fields[] = {
    SX_FIELD("signature","byte[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxil_inno_data_marker = {0x60850067U,"inno_data_marker",sxil_inno_data_marker_fields,SX_COUNT(sxil_inno_data_marker_fields),SX_LE};
#define SXIL_ADD(c,n,p) sxil_put(c,&sxil_##n,p,1)
static uint64_t sxil64(const uint8_t*p){return (uint64_t)sxil32(p,false)|((uint64_t)sxil32(p+4,false)<<32);}
static bool sxil_inno(sx_context*c){uint8_t b[64];uint64_t table=0,header=0,data=0;unsigned generation=0;uint32_t resource_size=0;const sx_layout*row=NULL;
 if(sxil_eq(c,48,"Inno",4)){uint32_t p,np;if(!sxil_u32(c,52,&p)||!sxil_u32(c,56,&np)||p!=~np||!sxil_read(c,p,b,12))return true;table=p;if(!SXIL_ADD(c,inno_loader_pointer,48))return false;
  if(xx_rt_memcmp(b,"rDlPtS",6)||b[6]!='0'||b[7]<'2'||b[7]>'7'||xx_rt_memcmp(b+8,"\x87\x65\x56\x78",4))return true;generation=b[7]-'0';unsigned n=generation==2||generation==6?44:40;if(!sxil_read(c,table,b,n))return true;
  switch(generation){case 2:row=&sxil_inno_loader2;break;case 4:row=&sxil_inno_loader4;break;case 5:row=&sxil_inno_loader5;break;case 6:row=&sxil_inno_loader6;break;case 7:row=&sxil_inno_loader7;break;default:return true;}
  header=sxil32(b+(generation==2?36:generation==7?28:32),false);data=sxil32(b+(generation==2?40:generation==7?32:36),false);
 }else if(sxil_resource(c,10,11111,NULL,&table,&resource_size)&&resource_size>=44&&sxil_read(c,table,b,44)){
  if(xx_rt_memcmp(b,"rDlPtS\xcd\xe6\xd7\x7b\x0b\x2a",12))return true;generation=sxil32(b+12,false);
  if(generation==1){row=&sxil_inno_loader_revision1;header=sxil32(b+32,false);data=sxil32(b+36,false);}
  else if(generation==2&&resource_size>=64&&sxil_read(c,table,b,64)){row=&sxil_inno_loader_revision2;header=sxil64(b+40);data=sxil64(b+48);}else return true;
  generation+=100;
 }else return true;
 if(!sxil_put(c,row,table,1))return false;if(!sxil_read(c,header,b,64))return true;
 unsigned version[3]={0};size_t pos=0;while(pos<64&&b[pos]!='(')pos++;if(pos==64)return true;pos++;
 for(unsigned k=0;k<3;k++){unsigned digits=0;while(pos<64&&b[pos]>='0'&&b[pos]<='9'&&digits<3){version[k]=version[k]*10+b[pos++]-'0';digits++;}if(!digits)return true;if(k<2){if(pos>=64||b[pos++]!='.')return true;}}
 if(!SXIL_ADD(c,inno_setup_version,header))return false;uint64_t p=header+64;bool legacy=version[0]<4||(version[0]==4&&version[1]==0&&version[2]<9),wide=version[0]>6||(version[0]==6&&version[1]>=7);
 if(generation==102){if(!SXIL_ADD(c,inno_encryption_envelope,p))return false;p+=53;}
 for(unsigned block=0;block<2;block++){uint64_t extent;unsigned hs=legacy?12:wide?13:9;if(!sxil_read(c,p,b,hs))return true;
  if(legacy){int32_t packed=(int32_t)sxil32(b+4,false);uint64_t n=packed==-1?sxil32(b+8,false):packed<0?0:(uint32_t)packed;extent=n+4*((n+4095)/4096);}
  else extent=wide?sxil64(b+4):sxil32(b+4,false);
  if(!sxil_put(c,legacy?&sxil_inno_block_legacy:wide?&sxil_inno_block64:&sxil_inno_block32,p,1))return false;p+=hs;if(!sxil_span(c,p,extent))return true;uint64_t end=p+extent;
  for(size_t k=0;k<20000&&p<end;k++){if(end-p<4)return true;if(!SXIL_ADD(c,inno_block_crc32,p))return false;p+=4;uint64_t n=end-p<4096?end-p:4096;p+=n;}
  p=end;
 }
 if(data&&sxil_eq(c,data,"zlb\x1a",4)&&!SXIL_ADD(c,inno_data_marker,data))return false;return true;
}
bool sx_inno_setup_build(sx_context*c)
{
 return sxil_inno(c);
}
#undef SXIL_ADD
