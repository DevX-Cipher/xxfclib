/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * IBM ZPAK archives data structures, moved out of the archivelegacy schema family. */
#include "../../xx_format_schema_archivelegacy.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxag_ibmzpak_header_fields[] = {
 SX_FIELD("signature","char[5]",0,5,SX_SIGNATURE),
 SX_FIELD("reserved","uint8",5,1,SX_RESERVED),
 SX_FIELD("version","uint16",6,2,SX_ID),
};
const sx_layout sxag_ibmzpak_header = {UINT32_C(0x6025001d),"ibmzpak_header",sxag_ibmzpak_header_fields,SX_COUNT(sxag_ibmzpak_header_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ibmzpak_entry_fields[] = {
 SX_FIELD("name","char[80]",0,80,SX_STRING),
 SX_FIELD("packed_size","uint32",80,4,SX_SIZE),
 SX_FIELD("date","uint16",84,2,SX_NONE),
 SX_FIELD("time","uint16",86,2,SX_NONE),
};
const sx_layout sxag_ibmzpak_entry = {UINT32_C(0x6025001e),"ibmzpak_entry",sxag_ibmzpak_entry_fields,SX_COUNT(sxag_ibmzpak_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxag_ibmzpak_count_fields[] = {
 SX_FIELD("entry_count","uint16",0,2,SX_COUNT_PROP),
};
const sx_layout sxag_ibmzpak_count = {UINT32_C(0x6025001f),"ibmzpak_count",sxag_ibmzpak_count_fields,SX_COUNT(sxag_ibmzpak_count_fields),SX_LE};
#define SXAG_LIMIT 20000U
static bool sxag_ibm(sx_context *c){uint8_t b[88];if(!sxag_add(c,&sxag_ibmzpak_header,0)||(uint64_t)c->size<10||!sxag_read(c,(uint64_t)c->size-2,b,2))return false;uint64_t n=sxag16(b,false);if(!n||n>SXAG_LIMIT||n*88>(uint64_t)c->size-10)return true;uint64_t table=(uint64_t)c->size-2-n*88,p=8;if(!sxag_table(c,&sxag_ibmzpak_entry,table,n)||!sxag_add(c,&sxag_ibmzpak_count,(uint64_t)c->size-2))return false;for(uint64_t i=0;i<n;i++){if(!sxag_read(c,table+i*88,b,88))break;uint64_t z=sxag32(b+80,false);if(z<2||p>table||z>table-p)break;if(!sxag_add(c,&sxag_archivelegacy_dcl,p))return false;p+=z;}return true;}
bool sx_ibmzpak_build(sx_context*c)
{
 return sxag_ibm(c);
}
