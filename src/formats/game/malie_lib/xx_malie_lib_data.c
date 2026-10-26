/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * malie_lib data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_malie_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","bytes",4,4,SX_NONE),
 SX_FIELD("entries","int16",8,2,SX_COUNT_PROP),
 SX_FIELD("unknown0a","bytes",10,6,SX_NONE),
};
const sx_layout sxgco_malie_header={UINT32_C(0x6040003B),"malie_header",sxgco_malie_header_fields,SX_COUNT(sxgco_malie_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_malieu_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
 SX_FIELD("unknown04","bytes",4,4,SX_NONE),
 SX_FIELD("entries","int32",8,4,SX_COUNT_PROP),
 SX_FIELD("unknown0c","bytes",12,4,SX_NONE),
};
const sx_layout sxgco_malieu_header={UINT32_C(0x6040003C),"malieu_header",sxgco_malieu_header_fields,SX_COUNT(sxgco_malieu_header_fields),SX_LE};
static bool sxgco_malie_dir(sxgco_view*v,uint64_t p,uint64_t end,unsigned depth)
{uint8_t magic[4];uint64_t n,stride,namez,at,off,z;bool u;if(depth>=64||!sxgco_read(v,p,magic,4,end))return false;u=!xx_rt_memcmp(magic,"LIBU",4);if(!u&&xx_rt_memcmp(magic,"LIB\0",4))return true;
 if(!sxgco_word(v,p+8,u?4:2,false,&n,end)||!n||n>UINT32_C(0xfffff)||(!u&&n>=0x8000)||n>INT32_MAX)return true;stride=u?80:48;namez=u?68:36;if(!sxgco_span(v,p,16+n*stride,end))return true;
 /* Check the entire immediate index before interpreting a possible nested
  * resource as a directory; native LIB keeps malformed children opaque. */
 for(uint64_t i=0;i<n;i++){at=p+16+i*stride;if(!sxgco_word(v,at+namez,4,false,&z,end)||!sxgco_word(v,at+namez+4,u?8:4,false,&off,end)||off<16+n*stride||off>end-p||z>end-p-off)return true;}
 if(!sxgco_row(v,u?&sxgco_malieu_header:&sxgco_malie_header,p,end)||!sxgco_table(v,u?&sxgco_malieu_entry:&sxgco_malie_entry,p+16,n,end))return false;
 for(uint64_t i=0;i<n;i++){at=p+16+i*stride;uint8_t name[68];if(!sxgco_read(v,at,name,(size_t)namez,end)||!sxgco_word(v,at+namez,4,false,&z,end)||!sxgco_word(v,at+namez+4,u?8:4,false,&off,end))return false;bool dot=false;for(unsigned j=0;j<namez;j+=u?2:1){unsigned c=name[j]|(u?(unsigned)name[j+1]<<8:0);if(!c)break;if(c=='.')dot=true;}if(!dot&&z>=4&&!sxgco_malie_dir(v,p+off,p+off+z,depth+1))return false;}return true;}
static bool sxgco_malie(sxgco_view*v){return sxgco_malie_dir(v,0,v->c->size,0);}
bool sx_malie_lib_build(sxgco_view*v)
{
 return sxgco_malie(v);
}
