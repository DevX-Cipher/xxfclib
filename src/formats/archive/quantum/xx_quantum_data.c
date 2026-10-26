/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QUANTUM data structures, moved out of the archiveobsolete schema family. */
#include "../../xx_format_schema_archiveobsolete.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxao_quantum_header_fields[] = {
 SX_FIELD("signature","char[2]",0,2,SX_SIGNATURE),
 SX_FIELD("zero","uint8",2,1,SX_NONE),
 SX_FIELD("version","uint8",3,1,SX_NONE),
 SX_FIELD("member_count","uint16",4,2,SX_COUNT_PROP),
 SX_FIELD("window_bits","uint8",6,1,SX_NONE),
 SX_FIELD("level","uint8",7,1,SX_NONE),
};
const sx_layout sxao_quantum_header = {UINT32_C(0x6070000f),"quantum_header",sxao_quantum_header_fields,SX_COUNT(sxao_quantum_header_fields),SX_LE};
static const xx_data_struct_field_desc sxao_quantum_length1_fields[] = {
 SX_FIELD("string_size","uint8",0,1,SX_SIZE),
};
const sx_layout sxao_quantum_length1 = {UINT32_C(0x60700010),"quantum_length1",sxao_quantum_length1_fields,SX_COUNT(sxao_quantum_length1_fields),SX_LE};
static const xx_data_struct_field_desc sxao_quantum_length2_fields[] = {
 SX_FIELD("length_high","uint8",0,1,SX_NONE),
 SX_FIELD("length_low","uint8",1,1,SX_NONE),
};
const sx_layout sxao_quantum_length2 = {UINT32_C(0x60700011),"quantum_length2",sxao_quantum_length2_fields,SX_COUNT(sxao_quantum_length2_fields),SX_BE};
static const xx_data_struct_field_desc sxao_quantum_member_fields[] = {
 SX_FIELD("uncompressed_size","uint32",0,4,SX_SIZE),
 SX_FIELD("dos_time","uint16",4,2,SX_NONE),
 SX_FIELD("dos_date","uint16",6,2,SX_NONE),
};
const sx_layout sxao_quantum_member = {UINT32_C(0x60700012),"quantum_member",sxao_quantum_member_fields,SX_COUNT(sxao_quantum_member_fields),SX_LE};
static const xx_data_struct_field_desc sxao_quantum_crc16_fields[] = {
 SX_FIELD("crc16","uint16",0,2,SX_CHECKSUM),
};
const sx_layout sxao_quantum_crc16 = {UINT32_C(0x60700013),"quantum_crc16",sxao_quantum_crc16_fields,SX_COUNT(sxao_quantum_crc16_fields),SX_LE};
static bool sxao_qlength(sx_context*c,uint64_t*p,uint64_t*z){uint8_t b[2];if(!sxao_read(c,*p,b,1))return false;if(b[0]&128){if(!sxao_read(c,*p,b,2)||!sxao_add(c,&sxao_quantum_length2,*p))return false;*z=((b[0]&127U)<<8)|b[1];*p+=2;}else{if(!sxao_add(c,&sxao_quantum_length1,*p))return false;*z=b[0];(*p)++;}return sxao_span(c,*p,*z);}
static bool sxao_quantum(sx_context*c){uint64_t p=8,n,ver;if(!sxao_word(c,4,2,false,&n)||!sxao_word(c,3,1,false,&ver)||!sxao_add(c,&sxao_quantum_header,0))return false;for(uint64_t i=0;i<n;i++){uint64_t z;if(!sxao_qlength(c,&p,&z)||!sxao_text(c,&sxao_archiveobsolete_name,p,z,false))return false;p+=z;if(!sxao_qlength(c,&p,&z))return false;p+=z;if(!sxao_add(c,&sxao_quantum_member,p))return false;p+=8;if(ver<0x17){if(!sxao_add(c,&sxao_quantum_crc16,p))return false;p+=2;}}return true;}
bool sx_quantum_build(sx_context*c)
{
 return sxao_quantum(c);
}
