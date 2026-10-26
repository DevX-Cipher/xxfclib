/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * MS DOS BACKUP2 data structures, moved out of the archivelater schema family. */
#include "../../xx_format_schema_archivelater.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxal_dos_backup2_header_fields[] = {
 SX_FIELD("header_size","uint8",0,1,SX_SIZE),
 SX_FIELD("signature","char[8]",1,8,SX_SIGNATURE),
 SX_FIELD("volume_number","uint8",9,1,SX_ID),
 SX_FIELD("reserved","uint8[128]",10,128,SX_RESERVED),
 SX_FIELD("last_volume","uint8",138,1,SX_FLAGS),
};
const sx_layout sxal_dos_backup2_header = {UINT32_C(0x60200049),"dos_backup2_header",sxal_dos_backup2_header_fields,SX_COUNT(sxal_dos_backup2_header_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_backup2_directory_fields[] = {
 SX_FIELD("record_size","uint8",0,1,SX_SIZE),
 SX_FIELD("path","char[63]",1,63,SX_STRING),
 SX_FIELD("file_count","uint16",64,2,SX_COUNT_PROP),
 SX_FIELD("next_directory_offset","uint32",66,4,SX_OFFSET),
};
const sx_layout sxal_dos_backup2_directory = {UINT32_C(0x6020004a),"dos_backup2_directory",sxal_dos_backup2_directory_fields,SX_COUNT(sxal_dos_backup2_directory_fields),SX_LE};
static const xx_data_struct_field_desc sxal_dos_backup2_file_fields[] = {
 SX_FIELD("record_size","uint8",0,1,SX_SIZE),
 SX_FIELD("name","char[12]",1,12,SX_STRING),
 SX_FIELD("flags","uint8",13,1,SX_FLAGS),
 SX_FIELD("total_size","uint32",14,4,SX_SIZE),
 SX_FIELD("fragment_number","uint16",18,2,SX_ID),
 SX_FIELD("data_offset","uint32",20,4,SX_OFFSET),
 SX_FIELD("fragment_size","uint32",24,4,SX_SIZE),
 SX_FIELD("attributes","uint16",28,2,SX_FLAGS),
 SX_FIELD("time","uint16",30,2,SX_NONE),
 SX_FIELD("date","uint16",32,2,SX_NONE),
};
const sx_layout sxal_dos_backup2_file = {UINT32_C(0x6020004b),"dos_backup2_file",sxal_dos_backup2_file_fields,SX_COUNT(sxal_dos_backup2_file_fields),SX_LE};
static bool sxal_backup2(sx_context *c){uint8_t b[70];if(!sxal_add(c,&sxal_dos_backup2_header,0))return false;uint64_t p=139;for(unsigned i=0;i<SXAL_LIMIT&&p<(uint64_t)c->size;i++){if(!sxal_read(c,p,b,70)||b[0]!=70)break;unsigned n=sxal16(b+64,false);bool last=sxal32(b+66,false)==UINT32_MAX;if(!sxal_add(c,&sxal_dos_backup2_directory,p))return false;p+=70;for(unsigned j=0;j<n;j++){if(!sxal_read(c,p,b,34)||b[0]!=34)return true;if(!sxal_add(c,&sxal_dos_backup2_file,p))return false;p+=34;}if(last)break;}return true;}
bool sx_ms_dos_backup2_build(sx_context*c)
{
 return sxal_backup2(c);
}
