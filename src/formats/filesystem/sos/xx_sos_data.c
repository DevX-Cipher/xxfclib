/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SOS data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_sos_boot_prefix_fields[] = {
    SX_FIELD("signature","char[3]",0,3,SX_SIGNATURE),
    SX_FIELD("filesystem_flags","uint8",3,1,SX_FLAGS),
    SX_FIELD("boot_checksum","uint32",4,4,SX_CHECKSUM),
    SX_FIELD("root_block","uint32",8,4,SX_NONE),
    SX_FIELD("loader_code","byte[4]",12,4,SX_NONE),
    SX_FIELD("loader_signature","char[4]",16,4,SX_SIGNATURE),
};
const sx_layout sxst_sos_boot_prefix = {0x60370003U,"sos_boot_prefix",sxst_sos_boot_prefix_fields,SX_COUNT(sxst_sos_boot_prefix_fields),SX_BE};
static const xx_data_struct_field_desc sxst_sos_directory_entry_fields[] = {
    SX_FIELD("data_offset","int32",0,4,SX_OFFSET),
    SX_FIELD("data_size","int32",4,4,SX_SIZE),
    SX_FIELD("name","char[24]",8,24,SX_NONE),
};
const sx_layout sxst_sos_directory_entry = {0x60370004U,"sos_directory_entry",sxst_sos_directory_entry_fields,SX_COUNT(sxst_sos_directory_entry_fields),SX_BE};
#define SXST_LIMIT 24000U
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
static bool sxst_sos(sx_context*c){uint8_t b[32];if(!SXST_ADD(c,sos_boot_prefix,0))return false;uint64_t p=0;for(unsigned i=1;i<=30;i++){if(!sxst_read(c,i*512,b,32))break;if(!xx_rt_memcmp(b+8,"loader",6)&&(b[14]==0)){p=i*512;break;}}if(!p)return true;for(unsigned i=0;i<SXST_LIMIT&&c->count<SXST_LIMIT;i++,p+=32){if(!sxst_read(c,p,b,32))break;if(!SXST_ADD(c,sos_directory_entry,p))return false;if(!sxst_uint(b,4,true)||!b[8])break;}return true;}
bool sx_sos_build(sx_context*c)
{
 return sxst_sos(c);
}
#undef SXST_LIMIT
#undef SXST_ADD
