/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * cpk data structures, moved out of the gamecontainers schema family. */
#include "../../xx_format_schema_gamecontainers.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxgco_cpk_packet_fields[]={
 SX_FIELD("tag","char[4]",0,4,SX_ID),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("table_bytes","uint64",8,8,SX_SIZE),
};
const sx_layout sxgco_cpk_packet={UINT32_C(0x6040004A),"cpk_packet",sxgco_cpk_packet_fields,SX_COUNT(sxgco_cpk_packet_fields),SX_LE};
#define GC_ROW(l,at,end) sxgco_row(v,&sxgco_##l,(at),(end))
static bool sxgco_cpk_utf(sxgco_view*v,uint64_t at,uint64_t size,uint64_t packets[2],unsigned depth)
{uint64_t end=at+size,declared,rows,strings,data,cols,width,count,p,rowpos=0;uint8_t sig[4];if(depth>4||!sxgco_span(v,at,size,v->c->size)||size<32||!sxgco_read(v,at,sig,4,end))return false;
 /* XOR-obfuscated table bytes are retained verbatim. There are no physical
  * clear columns or offsets to display inside that byte stream. */
 if(xx_rt_memcmp(sig,"@UTF",4))return true;
 if(!GC_ROW(cpk_utf_header,at,end)||!sxgco_word(v,at+4,4,true,&declared,end)||declared+8>size||!sxgco_word(v,at+10,2,true,&rows,end)||!sxgco_word(v,at+12,4,true,&strings,end)||!sxgco_word(v,at+16,4,true,&data,end)||!sxgco_word(v,at+24,2,true,&cols,end)||!sxgco_word(v,at+26,2,true,&width,end)||!sxgco_word(v,at+28,4,true,&count,end)||!cols||cols>256||count>UINT32_C(0x100000))return false;
 end=at+8+declared;rows+=at+8;strings+=at+8;data+=at+8;if(rows<at+32||strings<rows||data<strings||data>end||(count&&(width>(strings-rows)/count)))return false;p=at+32;
 for(uint64_t i=0;i<cols;i++){uint64_t flags,no,value=0,cell=0,z;char name[32];if(!GC_ROW(cpk_utf_column,p,rows)||!sxgco_word(v,p,1,false,&flags,rows)||!sxgco_word(v,p+1,4,true,&no,rows))return false;unsigned type=(unsigned)flags&15,storage=(unsigned)flags&0xf0;static const uint8_t sizes[12]={1,1,2,2,4,4,8,8,4,8,4,8};if(type>11||no>=data-strings)return false;z=sizes[type];p+=5;
 if(storage==0x30){cell=p;if(!sxgco_span(v,p,z,rows))return false;p+=z;}else if(storage==0x50){if(z>width-rowpos)return false;cell=rows+rowpos;rowpos+=z;}else if(storage!=0x10&&storage!=0)return false;
 uint64_t q=strings+no;unsigned j=0;for(;j<sizeof(name)-1&&q+j<data;j++){uint64_t c;if(!sxgco_word(v,q+j,1,false,&c,data))return false;name[j]=(char)c;if(!c)break;}name[j]=0;
 if(cell&&count&&type<8&&!sxgco_word(v,cell,(unsigned)z,true,&value,end))return false;
 if(packets&&count&&type<8){if(!xx_rt_strcmp(name,"TocOffset"))packets[0]=value;else if(!xx_rt_strcmp(name,"ItocOffset"))packets[1]=value;}
 if(cell&&count&&type==11&&(!xx_rt_strcmp(name,"DataL")||!xx_rt_strcmp(name,"DataH"))){uint64_t off,len;if(!sxgco_word(v,cell,4,true,&off,end)||!sxgco_word(v,cell+4,4,true,&len,end)||off>end-data||len>end-data-off)return false;if(len&&!sxgco_cpk_utf(v,data+off,len,NULL,depth+1))return false;}}
 return sxgco_table(v,&sxgco_filename_byte,strings,data-strings,end);}
static bool sxgco_cpk_parse_packet(sxgco_view*v,uint64_t at,uint64_t pointers[2])
{uint64_t z,e=v->c->size;return GC_ROW(cpk_packet,at,e)&&sxgco_word(v,at+8,8,false,&z,e)&&sxgco_span(v,at+16,z,e)&&sxgco_cpk_utf(v,at+16,z,pointers,0);}
static bool sxgco_cpk(sxgco_view*v)
{uint64_t refs[2]={0,0},e=v->c->size;if(!sxgco_cpk_parse_packet(v,0,refs))return false;for(unsigned i=0;i<2;i++)if(refs[i]&&refs[i]!=UINT64_MAX){uint8_t tag[4];if(!sxgco_read(v,refs[i],tag,4,e)||xx_rt_memcmp(tag,i?"ITOC":"TOC ",4)||!sxgco_cpk_parse_packet(v,refs[i],NULL))return false;}
 Abstractformat*f=v->c->f;xx_archive_record_state*s=xx_format_create_archive_records_reading(f,NULL,v->c->pd);if(!s)return true;bool ok=true;unsigned count=0;
 do{const xx_archive_record*r=xx_format_get_current_archive_record(f,s);if(!r)break;if(++count>UINT32_C(0x100000)){ok=false;break;}if(r->data_offset<f->base_address||r->compressed_size<16)continue;uint64_t at=(uint64_t)(r->data_offset-f->base_address);uint8_t h[8];if(sxgco_read(v,at,h,8,e)&&!xx_rt_memcmp(h,"CRILAYLA",8)&&!GC_ROW(cpk_crilayla,at,e)){ok=false;break;}
 }while(xx_format_archive_record_move_to_next(f,s,v->c->pd));xx_format_free_archive_records_reading(f,s);return ok&&!xx_pd_is_stopped(v->c->pd);}
bool sx_cpk_build(sxgco_view*v)
{
 return sxgco_cpk(v);
}
#undef GC_ROW
