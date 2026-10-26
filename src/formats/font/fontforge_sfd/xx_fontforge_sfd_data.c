/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * fontforge_sfd data structures, moved out of the modeltext schema family. */
#include "../../xx_format_schema_modeltext.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxmt_glyph_index_fields[]={
 SX_FIELD("glyph_index","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_glyph_index={0x60520029U,"modeltext_glyph_index",sxmt_glyph_index_fields,SX_COUNT(sxmt_glyph_index_fields),SX_LE};
static const xx_data_struct_field_desc sxmt_curve_flags_fields[]={
 SX_FIELD("curve_flags","ascii_signed",0,0,SX_NONE),
};
const sx_layout sxmt_curve_flags={0x60520038U,"modeltext_curve_flags",sxmt_curve_flags_fields,SX_COUNT(sxmt_curve_flags_fields),SX_LE};
#define MT_VALUE(n,e,v) do{if(!sxmt_value(q,&sxmt_##n,(e),(v)))return false;}while(0)
#define MT_EMIT(n,a,z) do{if(!sxmt_emit(q,&sxmt_##n,(a),(z)))return false;}while(0)
static bool sxmt_sfd(sxmt_cursor*q){int64_t a,e,k,z;bool glyph=false,curve=false;while(sxmt_line(q,&a,&e,false)){if(q->c->count>=32000)return true;int64_t next=q->p;q->p=a;if(!sxmt_token(q,e,&k,&z,false))return false;bool numeric=(q->b[k]>='0'&&q->b[k]<='9')||q->b[k]=='-'||q->b[k]=='+'||q->b[k]=='.';
 if(curve&&numeric){q->p=a;unsigned i=0;while(sxmt_token(q,e,&a,&z,false)){bool command=z==1&&(q->b[a]=='m'||q->b[a]=='l'||q->b[a]=='c');if(command){MT_EMIT(keyword,a,z);MT_VALUE(curve_flags,e,NULL);break;}if(i++>=6||!sxmt_emit(q,(i%2)?&sxmt_x:&sxmt_y,a,z))return false;}}
 else{MT_EMIT(keyword,k,z);
#define MT_SFDKEY(s) (sxmt_eq(q,k,z,s ":"))
 if(MT_SFDKEY("StartChar")){glyph=true;if(!sxmt_remainder(q,&sxmt_glyph_name,e))return false;}
 else if(sxmt_eq(q,k,z,"EndChar")){glyph=false;curve=false;}else if(sxmt_eq(q,k,z,"Fore"))curve=true;else if(sxmt_eq(q,k,z,"EndSplineSet"))curve=false;
 else if(MT_SFDKEY("BeginChars")){MT_VALUE(property_total,e,NULL);MT_VALUE(glyph_count,e,NULL);}
 else if(glyph&&MT_SFDKEY("Encoding")){MT_VALUE(glyph_index,e,NULL);MT_VALUE(codepoint,e,NULL);}
 else if(MT_SFDKEY("SplineFontDB")){MT_VALUE(version,e,NULL);}
 else if(MT_SFDKEY("Ascent")||MT_SFDKEY("Descent")||MT_SFDKEY("DisplaySize")||MT_SFDKEY("Width")||MT_SFDKEY("VWidth")||MT_SFDKEY("NeedsXUIDChange")||MT_SFDKEY("AntiAlias")){MT_VALUE(integer_value,e,NULL);}
 else if(MT_SFDKEY("ItalicAngle")||MT_SFDKEY("UnderlinePosition")||MT_SFDKEY("UnderlineWidth")){MT_VALUE(font_metric,e,NULL);}
 else if(!sxmt_remainder(q,&sxmt_string_value,e))return false;
#undef MT_SFDKEY
 }q->p=next;}return true;}
bool sx_fontforge_sfd_build(sxmt_cursor*q)
{
 return sxmt_sfd(q);
}
#undef MT_VALUE
#undef MT_EMIT
