/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_resourceextra_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_resourceextra.h"
static const xx_data_struct_field_desc sxre_secondnature_entry_fields[] = {
 SX_FIELD("name","char[13]",0,13,SX_NONE),
 SX_FIELD("payload_offset","uint32",13,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32",17,4,SX_SIZE),
};
const sx_layout sxre_secondnature_entry = {UINT32_C(0x603f0006),"secondnature_entry",sxre_secondnature_entry_fields,SX_COUNT(sxre_secondnature_entry_fields),SX_LE};
static const xx_data_struct_field_desc sxre_secondnature_entry_complemented_fields[] = {
 SX_FIELD("name","ones_char[13]",0,13,SX_NONE),
 SX_FIELD("payload_offset","uint32_ones_le",13,4,SX_OFFSET),
 SX_FIELD("payload_size","uint32_ones_le",17,4,SX_SIZE),
};
const sx_layout sxre_secondnature_entry_complemented = {UINT32_C(0x603f000d),"secondnature_entry_complemented",sxre_secondnature_entry_complemented_fields,SX_COUNT(sxre_secondnature_entry_complemented_fields),SX_LE};
static const sx_layout *const sx_resourceextra_layouts[] = {
 &sxre_secondnature_banner,
 &sxre_secondnature_bmx_count,
 &sxre_secondnature_ref_counts,
 &sxre_secondnature_snx_text,
 &sxre_secondnature_snx_info,
 &sxre_secondnature_entry,
 &sxre_secondnature_ref_entry,
 &sxre_secondnature_banner_complemented,
 &sxre_secondnature_bmx_count_complemented,
 &sxre_secondnature_ref_counts_complemented,
 &sxre_secondnature_snx_text_complemented,
 &sxre_secondnature_snx_info_complemented,
 &sxre_secondnature_entry_complemented,
 &sxre_secondnature_ref_entry_complemented,
 &sxre_skf_short_string_length,
 &sxre_skf_long_string_length,
 &sxre_skf_object_count,
 &sxre_skf_property_count,
 &sxre_skf_property_id,
 &sxre_skf_resource_count,
 &sxre_skf_resource_prefix,
 &sxre_skf_record6_count,
 &sxre_skf_optional_flag,
 &sxre_skf_record14_count,
 &sxre_skf_variable_record_count,
 &sxre_skf_payload_size,
};
static bool sx_resourceextra_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x603f0000U||id>=0x60400000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x603f0005U:
 if(!xx_rt_wcscmp(r->name,L"width"))text=L"Pixels.";
 if(!xx_rt_wcscmp(r->name,L"height"))text=L"Pixels.";
 break;
 case 0x603f0006U:
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"NUL terminated; original stale bytes after terminator remain in raw column.";
 if(!xx_rt_wcscmp(r->name,L"payload_offset"))text=L"File-relative stored value; zero/all-one slots may be reference-only.";
 if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Stored member extent; all-one unused SNX sentinel is not a byte size.";
 break;
 case 0x603f0007U:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"Native preserves the kind word without assigning an enumeration.";
 if(!xx_rt_wcscmp(r->name,L"rectangle_0"))text=L"Screen placement rectangle word0; axis/order not established.";
 break;
 case 0x603f000cU:
 if(!xx_rt_wcscmp(r->name,L"width"))text=L"Pixels.";
 if(!xx_rt_wcscmp(r->name,L"height"))text=L"Pixels.";
 break;
 case 0x603f000dU:
 if(!xx_rt_wcscmp(r->name,L"name"))text=L"NUL terminated; original stale bytes after terminator remain in raw column.";
 if(!xx_rt_wcscmp(r->name,L"payload_offset"))text=L"File-relative stored value; zero/all-one slots may be reference-only.";
 if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Stored member extent; all-one unused SNX sentinel is not a byte size.";
 break;
 case 0x603f000eU:
 if(!xx_rt_wcscmp(r->name,L"kind"))text=L"Native preserves the kind word without assigning an enumeration.";
 if(!xx_rt_wcscmp(r->name,L"rectangle_0"))text=L"Screen placement rectangle word0; axis/order not established.";
 break;
 case 0x603f0013U:
 if(!xx_rt_wcscmp(r->name,L"property_id"))text=L"Observed native branches:2 compound states;13 extra word;44 length-prefixed data. Other nonzero properties use a standard group.";
 break;
 case 0x603f0015U:
 if(!xx_rt_wcscmp(r->name,L"opaque_word"))text=L"Stored resource word; native reader does not assign semantics.";
 break;
 case 0x603f0016U:
 if(!xx_rt_wcscmp(r->name,L"record_count"))text=L"Count of following opaque6-byte records.";
 break;
 case 0x603f0017U:
 if(!xx_rt_wcscmp(r->name,L"present"))text=L"Nonzero introduces27 opaque bytes and a one-byte-length string.";
 break;
 case 0x603f0018U:
 if(!xx_rt_wcscmp(r->name,L"record_count"))text=L"Count of following opaque14-byte records.";
 break;
 case 0x603f0019U:
 if(!xx_rt_wcscmp(r->name,L"record_count"))text=L"Each row has14 opaque bytes, a4-byte size, and that many payload bytes.";
 break;
 default:break;}
 if((id==sxre_secondnature_entry.id||id==sxre_secondnature_entry_complemented.id)&&(!xx_rt_wcscmp(r->name,L"payload_size")||!xx_rt_wcscmp(r->name,L"payload_offset"))&&xx_var_get_u64(&r->value)==UINT32_MAX)text=L"All-one unused SNX slot sentinel, not a byte count or address.";
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXRE_LIMIT 20000U
bool sxre_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxre_read(sx_context*c,uint64_t p,void*b,size_t n){return sxre_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
bool sxre_word(sx_context*c,uint64_t p,unsigned n,bool mask,uint64_t*v){uint8_t b[4];if(!n||n>4||!sxre_read(c,p,b,n))return false;*v=0;for(unsigned i=0;i<n;i++)*v|=(uint64_t)(mask?(uint8_t)~b[i]:b[i])<<(8*i);return true;}
bool sxre_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];int64_t n=f->rel_offset+f->size;return c->count<SXRE_LIMIT&&sxre_span(c,p,(uint64_t)n)&&sx_add(c,l,(int64_t)p,n);}
static int sxre_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxre_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxre_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxre_order);return !c->failed;}
static bool sx_resourceextra_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_SECONDNATURE:case XX_FILE_TYPE_SKF:return true;default:return false;}}
static bool sx_resourceextra_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=c->f->file_type==XX_FILE_TYPE_SECONDNATURE?sx_secondnature_build(c):c->f->file_type==XX_FILE_TYPE_SKF?sx_skf_build(c):false;(void)ok;return c->count&&sxre_finish(c);}
const sx_family sx_resourceextra_family={sx_resourceextra_supports,sx_resourceextra_build,sx_resourceextra_layouts,SX_COUNT(sx_resourceextra_layouts),sx_resourceextra_comment};
