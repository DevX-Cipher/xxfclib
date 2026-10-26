/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * stos_memory_bank data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_stos_palette_header_fields[]={
 SX_FIELD("magic","char[4]",0,4,SX_SIGNATURE),
};
const sx_layout sxgco_stos_palette_header={UINT32_C(0x60400034),"stos_palette_header",sxgco_stos_palette_header_fields,SX_COUNT(sxgco_stos_palette_header_fields),SX_LE};
static const xx_data_struct_field_desc sxgco_stos_icon_header_fields[]={
 SX_FIELD("bank_id","uint32",0,4,SX_ID),
 SX_FIELD("icons","uint16",4,2,SX_COUNT_PROP),
};
const sx_layout sxgco_stos_icon_header={UINT32_C(0x60400036),"stos_icon_header",sxgco_stos_icon_header_fields,SX_COUNT(sxgco_stos_icon_header_fields),SX_BE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_stos(sxgco_view*v)
{uint64_t e=v->c->size,p=0,id,n,total=0,off;uint8_t magic[10];if(!sxgco_read(v,0,magic,10,e))return false;
 if(!xx_rt_memcmp(magic,"Lionpoubnk",10)){if(!GC_ROW(stos_header,0,e))return false;p=18;uint64_t type;if(!sxgco_word(v,14,1,false,&type,e))return false;if(type!=0x81)return true;}
 if(!sxgco_word(v,p,4,true,&id,e))return false;
 if(id==UINT32_C(0x19861987)){if(!GC_ROW(stos_sprite,p,e))return false;
 for(unsigned i=0;i<3;i++){if(!sxgco_word(v,p+16+2*i,2,true,&n,e)||!sxgco_word(v,p+4+4*i,4,true,&off,e))return false;total+=n;off+=p+4;if(sxgco_span(v,off,n*8,e)&&!sxgco_table(v,&sxgco_stos_sprite_param,off,n,e))return false;}
 uint64_t pal=p+22+total*8;if(sxgco_word(v,pal,4,true,&id,e)&&id==UINT32_C(0x50414c54))return GC_ROW(stos_palette_header,pal,e)&&sxgco_table(v,&sxgco_stos_color,pal+4,16,e);return true;}
 if(id==UINT32_C(0x28091960)){if(!GC_ROW(stos_icon_header,p,e)||!sxgco_word(v,p+4,2,true,&n,e)||!sxgco_span(v,p+6,n*84,e))return false;for(uint64_t i=0;i<n;i++)if(!GC_ROW(stos_icon,p+6+i*84,e))return false;}return true;}
bool sx_stos_memory_bank_build(sxgco_view*v)
{
 return sxgco_stos(v);
}
#undef GC_ROW
