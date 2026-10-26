/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * COMPDISK data structures, moved out of the systemtail schema family. */
#include "../../xx_format_schema_systemtail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxst_compdisk_header_fields[] = {
    SX_FIELD("signature","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version","uint32",4,4,SX_ID),
    SX_FIELD("reserved1","uint32",8,4,SX_RESERVED),
    SX_FIELD("reserved2","uint32",12,4,SX_RESERVED),
};
const sx_layout sxst_compdisk_header = {0x6037001cU,"compdisk_header",sxst_compdisk_header_fields,SX_COUNT(sxst_compdisk_header_fields),SX_BE};
static const xx_data_struct_field_desc sxst_compdisk_cylinder_fields[] = {
    SX_FIELD("packed_size","uint32",0,4,SX_SIZE),
    SX_FIELD("olaf_checksum","uint16",4,2,SX_CHECKSUM),
};
const sx_layout sxst_compdisk_cylinder = {0x6037001dU,"compdisk_cylinder",sxst_compdisk_cylinder_fields,SX_COUNT(sxst_compdisk_cylinder_fields),SX_BE};
#define SXST_ADD(c,l,p) sxst_put(c,&sxst_##l,p,1)
static bool sxst_compdisk(sx_context*c){if(!SXST_ADD(c,compdisk_header,0))return false;uint64_t p=16,z;for(unsigned i=0;i<80;i++){if(!sxst_word(c,p,4,true,&z))break;if(!z)z=11264;if(!sxst_span(c,p+6,z)||!SXST_ADD(c,compdisk_cylinder,p))break;p+=6+z;}return true;}
bool sx_compdisk_build(sx_context*c)
{
 return sxst_compdisk(c);
}
#undef SXST_ADD
