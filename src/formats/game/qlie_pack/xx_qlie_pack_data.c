/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * qlie_pack data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_qlie(sxgco_view*v)
{uint64_t e=v->c->size,p,n,z,major,minor;if(e<28||!GC_ROW(qlie_footer,e-28,e)||!sxgco_word(v,e-12,4,false,&n,e)||!sxgco_word(v,e-8,8,false,&p,e)||!sxgco_word(v,e-17,1,false,&major,e)||!sxgco_word(v,e-15,1,false,&minor,e)||n>UINT32_C(0xfffff))return false;
 uint64_t bound=e-28;bool unicode=major=='3'&&minor=='1';if(major=='3'){if(e<0x440)return false;bound=e-0x440;}if(major=='1')return true;
 for(uint64_t i=0;i<n;i++){if(!GC_ROW(qlie_name_units,p,bound)||!sxgco_word(v,p,2,false,&z,bound)||!z||z>256)return false;if(unicode)z*=2;if(!sxgco_table(v,&sxgco_encoded_byte,p+2,z,bound)||!GC_ROW(qlie_entry,p+2+z,bound))return false;p+=30+z;}return true;}
bool sx_qlie_pack_build(sxgco_view*v)
{
 return sxgco_qlie(v);
}
#undef GC_ROW
