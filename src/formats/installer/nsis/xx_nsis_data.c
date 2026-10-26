/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * NSIS data structures, moved out of the installerremaining schema family. */
#include "../../xx_format_schema_installerremaining.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxir_nsis_common_flags_fields[]={
 SX_FIELD("flags","int32le",0,4,SX_FLAGS),
};
const sx_layout sxir_nsis_common_flags={0x60800002U,"nsis_common_flags",sxir_nsis_common_flags_fields,SX_COUNT(sxir_nsis_common_flags_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_block32_fields[]={
 SX_FIELD("header_relative_offset","uint32le",0,4,SX_OFFSET),
 SX_FIELD("item_count","int32le",4,4,SX_COUNT_PROP),
};
const sx_layout sxir_nsis_block32={0x60800003U,"nsis_block32",sxir_nsis_block32_fields,SX_COUNT(sxir_nsis_block32_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_block64_fields[]={
 SX_FIELD("header_relative_offset","uint64le",0,8,SX_OFFSET),
 SX_FIELD("item_count","int32le",8,4,SX_COUNT_PROP),
};
const sx_layout sxir_nsis_block64={0x60800004U,"nsis_block64",sxir_nsis_block64_fields,SX_COUNT(sxir_nsis_block64_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_instruction_fields[]={
 SX_FIELD("opcode","int32le",0,4,SX_ID),
 SX_FIELD("parameters","int32le[6]",4,24,SX_NONE),
};
const sx_layout sxir_nsis_instruction={0x60800005U,"nsis_instruction",sxir_nsis_instruction_fields,SX_COUNT(sxir_nsis_instruction_fields),SX_LE};
static const xx_data_struct_field_desc sxir_nsis_block_length_fields[]={
 SX_FIELD("encoded_block_size","uint32le",0,4,SX_FLAGS),
};
const sx_layout sxir_nsis_block_length={0x60800006U,"nsis_block_length",sxir_nsis_block_length_fields,SX_COUNT(sxir_nsis_block_length_fields),SX_LE};
static const xx_data_struct_field_desc sxir_installer_crc32_fields[]={
 SX_FIELD("crc32","uint32le",0,4,SX_CHECKSUM),
};
const sx_layout sxir_installer_crc32={0x60800007U,"installer_crc32",sxir_installer_crc32_fields,SX_COUNT(sxir_installer_crc32_fields),SX_LE};
#define IR_ROW(name,at,end) sxir_row(v,&sxir_##name,(at),(end))
#define IR_U(at,z,out,end) sxir_u(v,(at),(z),false,&(out),(end))
static bool sxir_ns_lzma(sxir_view*v,uint64_t at,uint64_t end)
{uint8_t b[7];return sxir_read(v,at,b,7,end)&&b[0]==0x5d&&!b[1]&&!b[2]&&!b[5]&&!(b[6]&128);}
static bool sxir_nsis(sxir_view*v)
{uint64_t end=v->c->size,at=0,flags,header_size,size,packed;bool found=false;
 if(sxir_eq(v,0,"MZ",2,end)){for(at=512;at<=end&&end-at>=28;at+=512){if(sxir_eq(v,at+4,"\xef\xbe\xad\xdeNullsoftInst",16,end)){found=true;break;}}if(!found)return false;}
 if(!sxir_eq(v,at+4,"\xef\xbe\xad\xdeNullsoftInst",16,end)||!IR_U(at,4,flags,end)||flags&~15U||!IR_U(at+20,4,header_size,end)||!header_size||header_size>16777216||!IR_U(at+24,4,size,end)||size<32||!sxir_span(v,at,size,end)||!IR_ROW(nsis_firstheader,at,end))return false;
 uint64_t finish=at+size;if((flags&8)||!(flags&4)){if(!IR_ROW(installer_crc32,finish-4,finish))return false;finish-=4;}
 uint64_t data=at+28;if(!IR_U(data,4,packed,finish))return false;bool solid=packed!=header_size&&(!(packed&0x80000000U)||sxir_ns_lzma(v,data,finish)||sxir_ns_lzma(v,data+1,finish));if(solid)return true;
 if(!IR_ROW(nsis_block_length,data,finish))return false;uint64_t bytes=packed&0x7fffffffU;if(!sxir_span(v,data+4,bytes,finish))return false;if(packed&0x80000000U)return true;if(bytes!=header_size||bytes<68)return false;
 uint64_t h=data+4,he=h+bytes,stride=8;if(bytes>=100){bool wide=true;for(unsigned i=0;i<8;i++){uint64_t upper;if(!IR_U(h+8+i*12,4,upper,he))return false;if(upper)wide=false;}if(wide)stride=12;}
 if(!IR_ROW(nsis_common_flags,h,he)||!sxir_table(v,stride==12?&sxir_nsis_block64:&sxir_nsis_block32,h+4,8,he))return false;
 uint64_t entries,count,strings,lang;if(!IR_U(h+4+stride*2,4,entries,he)||!IR_U(h+stride*3,4,count,he)||!IR_U(h+4+stride*3,4,strings,he)||!IR_U(h+4+stride*4,4,lang,he)||entries>bytes||count>(bytes-entries)/28||strings>=lang||lang>bytes)return false;
 if(!sxir_table(v,&sxir_nsis_instruction,h+entries,count,he)||!sxir_emit(v,&sxir_nsis_string_pool,h+strings,lang-strings,he))return false;
 for(uint64_t i=0;i<count;i++){uint64_t command=h+entries+28*i,op,off,n;if(!IR_U(command,4,op,he))return false;if(op!=20)continue;if(!IR_U(command+12,4,off,he)||off>finish-he||!IR_U(he+off,4,n,finish)||!sxir_span(v,he+off+4,n&0x7fffffffU,finish)||!IR_ROW(nsis_block_length,he+off,finish))return false;}
 return true;}
bool sx_nsis_build(sx_context*c)
{
 sxir_view view={c,0},*v=&view;return sxir_nsis(v);
}
#undef IR_ROW
#undef IR_U
