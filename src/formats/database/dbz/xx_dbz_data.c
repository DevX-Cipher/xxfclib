/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * dbz data structures, moved out of the databases schema family. */
#include "../../xx_format_schema_databases.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxd_dbz_header_fields[] = {
    SX_FIELD("magic", "char[27]", 0, 27, SX_SIGNATURE),
};
const sx_layout sxd_dbz_header = {UINT32_C(0x601A003B),"dbz_header",sxd_dbz_header_fields,SX_COUNT(sxd_dbz_header_fields),SX_LE};
static bool sxd_decimal(const uint8_t *p,unsigned n,uint64_t *v)
{
    unsigned i=0;*v=0;while(i<n&&p[i]==' ')i++;if(i==n)return false;for(;i<n;i++){if(p[i]<'0'||p[i]>'9'||*v>(UINT64_MAX-(p[i]-'0'))/10)return false;*v=*v*10+(p[i]-'0');}return true;
}
static bool sxd_dbz(sx_context *c,const uint8_t *b)
{
    uint64_t first;if(!sxd_can(c,0,59)||!sxd_decimal(b+27+14,9,&first)||first<59||(first-27)%32||first>(uint64_t)c->size)return false;
    if(!sxd_add(c,&sxd_dbz_header,0,27))return false;for(uint64_t at=27;at<first;at+=32){uint64_t offset,size;if(sxd_decimal(b+at+14,9,&offset)&&sxd_decimal(b+at+23,9,&size)&&!sxd_add(c,&sxd_dbz_index_record,at,32))return false;}return true;
}
bool sx_dbz_build(sx_context *c,uint8_t *b)
{
 return sxd_dbz(c,b);
}
