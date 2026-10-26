/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Physical Android resource metadata. Unimplemented payloads remain raw. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_androidmeta.h"
static const xx_data_struct_field_desc sx_am_android_string_pool_header_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("string_count","uint32",8,4,SX_COUNT_PROP),
    SX_FIELD("style_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("flags","uint32",16,4,SX_FLAGS),
    SX_FIELD("strings_start","uint32",20,4,SX_OFFSET),
    SX_FIELD("styles_start","uint32",24,4,SX_OFFSET),
};
static const sx_layout sx_am_android_string_pool_header = {0x601b0002U,"android_string_pool_header",sx_am_android_string_pool_header_fields,SX_COUNT(sx_am_android_string_pool_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_string_offset_fields[] = {
    SX_FIELD("string_offset","uint32",0,4,SX_OFFSET),
};
static const sx_layout sx_am_android_string_offset = {0x601b0003U,"android_string_offset",sx_am_android_string_offset_fields,SX_COUNT(sx_am_android_string_offset_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_type_header_fields[] = {
    SX_FIELD("type","uint16",0,2,SX_ID),
    SX_FIELD("header_size","uint16",2,2,SX_SIZE),
    SX_FIELD("chunk_size","uint32",4,4,SX_SIZE),
    SX_FIELD("type_id","uint8",8,1,SX_ID),
    SX_FIELD("flags","uint8",9,1,SX_FLAGS),
    SX_FIELD("reserved","uint16",10,2,SX_RESERVED),
    SX_FIELD("entry_count","uint32",12,4,SX_COUNT_PROP),
    SX_FIELD("entries_start","uint32",16,4,SX_OFFSET),
};
const sx_layout sx_am_android_type_header = {0x601b0010U,"android_type_header",sx_am_android_type_header_fields,SX_COUNT(sx_am_android_type_header_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_table_entry_fields[] = {
    SX_FIELD("entry_size","uint16",0,2,SX_SIZE),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("key_index","uint32",4,4,SX_ID),
};
const sx_layout sx_am_android_table_entry = {0x601b0018U,"android_table_entry",sx_am_android_table_entry_fields,SX_COUNT(sx_am_android_table_entry_fields),SX_LE};
static const xx_data_struct_field_desc sx_am_android_table_map_entry_fields[] = {
    SX_FIELD("entry_size","uint16",0,2,SX_SIZE),
    SX_FIELD("flags","uint16",2,2,SX_FLAGS),
    SX_FIELD("key_index","uint32",4,4,SX_ID),
    SX_FIELD("parent_resource_id","uint32",8,4,SX_ID),
    SX_FIELD("value_count","uint32",12,4,SX_COUNT_PROP),
};
const sx_layout sx_am_android_table_map_entry = {0x601b0019U,"android_table_map_entry",sx_am_android_table_map_entry_fields,SX_COUNT(sx_am_android_table_map_entry_fields),SX_LE};
static const sx_layout *const sx_androidmeta_layouts[] = {
    &sx_am_android_chunk_header,
    &sx_am_android_string_pool_header,
    &sx_am_android_string_offset,
    &sx_am_android_xml_node,
    &sx_am_android_xml_namespace,
    &sx_am_android_xml_start_element,
    &sx_am_android_xml_end_element,
    &sx_am_android_xml_attribute,
    &sx_am_android_xml_cdata,
    &sx_am_android_resource_id,
    &sx_am_android_table_header,
    &sx_am_android_package_header,
    &sx_am_android_package_header_extended,
    &sx_am_android_type_spec,
    &sx_am_android_type_spec_flags,
    &sx_am_android_type_header,
    &sx_am_android_config_size,
    &sx_am_android_config_base,
    &sx_am_android_config_screen,
    &sx_am_android_config_size_dp,
    &sx_am_android_config_locale,
    &sx_am_android_config_color,
    &sx_am_android_entry_offset,
    &sx_am_android_table_entry,
    &sx_am_android_table_map_entry,
    &sx_am_android_value,
    &sx_am_android_table_map,
};
static bool sx_androidmeta_supports(xx_file_type_t t){return t==XX_FILE_TYPE_ANDROID_BINARY_XML||t==XX_FILE_TYPE_ANDROID_RESOURCES_ARSC;}
bool sx_am_chunk(sx_context *c,uint64_t at,uint64_t end,sx_am_chunk_info *q)
{
    uint8_t b[8];if(at>end||end-at<8||!sx_read(c,(int64_t)at,b,8))return false;
    uint32_t n=xx_data_get_u32(b,8,4,false);q->at=at;q->type=xx_data_get_u16(b,8,0,false);q->header=xx_data_get_u16(b,8,2,false);
    if(q->header<8||n<q->header||n>end-at)return false;q->end=at+n;return true;
}
bool sx_am_pool(sx_context *c,const sx_am_chunk_info *q)
{
    uint32_t n;if(q->header<28||!sx_u32(c,(int64_t)q->at+8,false,&n)||n>4096||(uint64_t)n*4>q->end-q->at-q->header)return false;
    return sx_add(c,&sx_am_android_string_pool_header,(int64_t)q->at,28)&&sx_table(c,&sx_am_android_string_offset,(int64_t)(q->at+q->header),4,n);
}
static void sx_am_sort(sx_context *c)
{
    for(size_t gap=c->count/2;gap;gap/=2)for(size_t i=gap;i<c->count;i++){
        xx_data_struct d=c->items[i];size_t j=i;while(j>=gap&&c->items[j-gap].offset>d.offset){c->items[j]=c->items[j-gap];j-=gap;}c->items[j]=d;
    }
}
static bool sx_am_finish(sx_context *c)
{
    size_t n=c->count;int64_t end=0;sx_am_sort(c);
    for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address;if(at<end||(at>end&&!sx_raw(c,end,at-end)))return false;end=at+c->items[i].total_size;}
    if(end<c->size&&!sx_raw(c,end,c->size-end))return false;sx_am_sort(c);return !c->failed;
}
static bool sx_androidmeta_build(sx_context *c)
{
    if(!c||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
    sx_am_chunk_info root;if(!sx_am_chunk(c,0,(uint64_t)c->size,&root)||root.end!=(uint64_t)c->size)return false;
    bool ok=c->f->file_type==XX_FILE_TYPE_ANDROID_BINARY_XML?sx_android_binary_xml_build(c,root):c->f->file_type==XX_FILE_TYPE_ANDROID_RESOURCES_ARSC?sx_android_resources_arsc_build(c,root):false;
    return ok&&sx_am_finish(c);
}
typedef struct sx_am_flag {uint64_t mask;const wchar_t *name;} sx_am_flag;
static bool sx_am_flags(xx_data_struct_record *r,const sx_am_flag *flags,size_t count)
{
    wchar_t out[1024];size_t used=0;uint64_t value=xx_var_get_u64(&r->value),known=0;
    for(size_t i=0;i<count;i++) {
        known|=flags[i].mask;if(!(value&flags[i].mask))continue;
        if(used+32>=SX_COUNT(out))return false;
        if(used)out[used++]=L'|';
        const wchar_t *p=flags[i].name;while(*p&&used+24<SX_COUNT(out))out[used++]=*p++;
        if(*p)return false;
    }
    uint64_t unknown=value&~known;
    if(unknown) {
        if(used)out[used++]=L'|';out[used++]=L'0';out[used++]=L'x';
        bool started=false;
        for(int shift=60;shift>=0;shift-=4) {unsigned digit=(unsigned)((unknown>>shift)&15);if(digit||started||!shift){out[used++]=L"0123456789ABCDEF"[digit];started=true;}}
    }
    if(!used)out[used++]=L'0';out[used]=0;
    return xx_data_struct_record_set_comment(r,out);
}
static bool sx_androidmeta_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x601b0000U||id>=0x601c0000U)return true;
    const wchar_t *text=NULL;
    if(!xx_rt_wcscmp(r->name,L"type")){
        switch(xx_var_get_u64(&r->value)){
        case 1:text=L"RES_STRING_POOL_TYPE";break;case 2:text=L"RES_TABLE_TYPE";break;case 3:text=L"RES_XML_TYPE";break;
        case 256:text=L"RES_XML_START_NAMESPACE_TYPE";break;case 257:text=L"RES_XML_END_NAMESPACE_TYPE";break;case 258:text=L"RES_XML_START_ELEMENT_TYPE";break;case 259:text=L"RES_XML_END_ELEMENT_TYPE";break;case 260:text=L"RES_XML_CDATA_TYPE";break;
        case 384:text=L"RES_XML_RESOURCE_MAP_TYPE";break;case 512:text=L"RES_TABLE_PACKAGE_TYPE";break;case 513:text=L"RES_TABLE_TYPE_TYPE";break;case 514:text=L"RES_TABLE_TYPE_SPEC_TYPE";break;default:break;}
    }else if(!xx_rt_wcscmp(r->name,L"data_type")){
        switch(xx_var_get_u64(&r->value)){
        case 0:text=L"TYPE_NULL";break;case 1:text=L"TYPE_REFERENCE";break;case 2:text=L"TYPE_ATTRIBUTE";break;case 3:text=L"TYPE_STRING";break;case 4:text=L"TYPE_FLOAT";break;case 5:text=L"TYPE_DIMENSION";break;case 6:text=L"TYPE_FRACTION";break;case 7:text=L"TYPE_DYNAMIC_REFERENCE";break;case 8:text=L"TYPE_DYNAMIC_ATTRIBUTE";break;case 16:text=L"TYPE_INT_DEC";break;case 17:text=L"TYPE_INT_HEX";break;case 18:text=L"TYPE_INT_BOOLEAN";break;case 28:text=L"TYPE_INT_COLOR_ARGB8";break;case 29:text=L"TYPE_INT_COLOR_RGB8";break;case 30:text=L"TYPE_INT_COLOR_ARGB4";break;case 31:text=L"TYPE_INT_COLOR_RGB4";break;default:break;}
    }else if(!xx_rt_wcscmp(r->name,L"flags")){
        if(id==sx_am_android_string_pool_header.id){static const sx_am_flag a[]={{1,L"SORTED_FLAG"},{256,L"UTF8_FLAG"}};return sx_am_flags(r,a,SX_COUNT(a));}
        if(id==sx_am_android_type_header.id){static const sx_am_flag a[]={{1,L"FLAG_SPARSE"},{2,L"FLAG_OFFSET16"}};return sx_am_flags(r,a,SX_COUNT(a));}
        if(id==sx_am_android_table_entry.id||id==sx_am_android_table_map_entry.id){static const sx_am_flag a[]={{1,L"FLAG_COMPLEX"},{2,L"FLAG_PUBLIC"},{4,L"FLAG_WEAK"},{8,L"FLAG_COMPACT"}};return sx_am_flags(r,a,SX_COUNT(a));}
    }else if(!xx_rt_wcscmp(r->name,L"input_flags")||!xx_rt_wcscmp(r->name,L"screen_layout")||!xx_rt_wcscmp(r->name,L"ui_mode")||!xx_rt_wcscmp(r->name,L"screen_layout2")||!xx_rt_wcscmp(r->name,L"color_mode")){
        uint64_t v=xx_var_get_u64(&r->value);sx_am_flag a[3];size_t n=0;
#define SX_AM_GROUP(mask,shift,names) do {size_t sel=(size_t)((v&(mask))>>(shift));if(sel&&sel<SX_COUNT(names)){a[n++]=(sx_am_flag){mask,names[sel]};}}while(0)
        if(!xx_rt_wcscmp(r->name,L"input_flags")){
            static const wchar_t *const k[]={L"",L"KEYSHIDDEN_NO",L"KEYSHIDDEN_YES",L"KEYSHIDDEN_SOFT"},*const nav[]={L"",L"NAVHIDDEN_NO",L"NAVHIDDEN_YES"};
            SX_AM_GROUP(3,0,k);SX_AM_GROUP(12,2,nav);
        }else if(!xx_rt_wcscmp(r->name,L"screen_layout")){
            static const wchar_t *const size[]={L"",L"SCREENSIZE_SMALL",L"SCREENSIZE_NORMAL",L"SCREENSIZE_LARGE",L"SCREENSIZE_XLARGE"},*const lng[]={L"",L"SCREENLONG_NO",L"SCREENLONG_YES"},*const dir[]={L"",L"LAYOUTDIR_LTR",L"LAYOUTDIR_RTL"};
            SX_AM_GROUP(15,0,size);SX_AM_GROUP(48,4,lng);SX_AM_GROUP(192,6,dir);
        }else if(!xx_rt_wcscmp(r->name,L"ui_mode")){
            static const wchar_t *const mode[]={L"",L"UI_MODE_TYPE_NORMAL",L"UI_MODE_TYPE_DESK",L"UI_MODE_TYPE_CAR",L"UI_MODE_TYPE_TELEVISION",L"UI_MODE_TYPE_APPLIANCE",L"UI_MODE_TYPE_WATCH",L"UI_MODE_TYPE_VR_HEADSET"},*const night[]={L"",L"UI_MODE_NIGHT_NO",L"UI_MODE_NIGHT_YES"};
            SX_AM_GROUP(15,0,mode);SX_AM_GROUP(48,4,night);
        }else if(!xx_rt_wcscmp(r->name,L"screen_layout2")){
            static const wchar_t *const round[]={L"",L"SCREENROUND_NO",L"SCREENROUND_YES"};SX_AM_GROUP(3,0,round);
        }else{
            static const wchar_t *const wide[]={L"",L"WIDE_COLOR_GAMUT_NO",L"WIDE_COLOR_GAMUT_YES"},*const hdr[]={L"",L"HDR_NO",L"HDR_YES"};SX_AM_GROUP(3,0,wide);SX_AM_GROUP(12,2,hdr);
        }
#undef SX_AM_GROUP
        return sx_am_flags(r,a,n);
    }else if(!xx_rt_wcscmp(r->name,L"configuration_flags")){
        static const sx_am_flag a[]={{1,L"CONFIG_MCC"},{2,L"CONFIG_MNC"},{4,L"CONFIG_LOCALE"},{8,L"CONFIG_TOUCHSCREEN"},{16,L"CONFIG_KEYBOARD"},{32,L"CONFIG_KEYBOARD_HIDDEN"},{64,L"CONFIG_NAVIGATION"},{128,L"CONFIG_ORIENTATION"},{256,L"CONFIG_DENSITY"},{512,L"CONFIG_SCREEN_SIZE"},{1024,L"CONFIG_VERSION"},{2048,L"CONFIG_SCREEN_LAYOUT"},{4096,L"CONFIG_UI_MODE"},{8192,L"CONFIG_SMALLEST_SCREEN_SIZE"},{16384,L"CONFIG_LAYOUTDIR"},{32768,L"CONFIG_SCREEN_ROUND"},{65536,L"CONFIG_COLOR_MODE"},{131072,L"CONFIG_GRAMMATICAL_GENDER"},{0x20000000,L"SPEC_STAGED_API"},{0x40000000,L"SPEC_PUBLIC"}};return sx_am_flags(r,a,SX_COUNT(a));
    }else if(!xx_rt_wcscmp(r->name,L"strings_start"))text=L"Byte offset from the start of this string-pool chunk";
    else if(!xx_rt_wcscmp(r->name,L"styles_start"))text=L"Byte offset from the start of this string-pool chunk; zero means no style data";
    else if(!xx_rt_wcscmp(r->name,L"string_offset"))text=L"Byte offset from the string-data area at strings_start";
    else if(!xx_rt_wcscmp(r->name,L"type_strings")||!xx_rt_wcscmp(r->name,L"key_strings"))text=L"Byte offset from the start of this package chunk";
    else if(!xx_rt_wcscmp(r->name,L"type_id_offset"))text=L"Type-identifier adjustment, not a byte offset";
    else if(!xx_rt_wcscmp(r->name,L"entries_start"))text=L"Byte offset from the start of this resource-type chunk";
    else if(!xx_rt_wcscmp(r->name,L"entry_offset"))text=xx_var_get_u64(&r->value)==UINT32_MAX?L"NO_ENTRY":L"Byte offset from the entry-data area at entries_start";
    else if(!xx_rt_wcscmp(r->name,L"attribute_start"))text=L"Byte offset from the start-element extension, after the XML node header";
    else if(!xx_rt_wcscmp(r->name,L"id_index")||!xx_rt_wcscmp(r->name,L"class_index")||!xx_rt_wcscmp(r->name,L"style_index"))text=L"One-based attribute index; zero means absent";
    else if(!xx_rt_wcscmp(r->name,L"comment_index")||!xx_rt_wcscmp(r->name,L"namespace_index")||!xx_rt_wcscmp(r->name,L"raw_value_index")||!xx_rt_wcscmp(r->name,L"prefix_index"))text=xx_var_get_u64(&r->value)==UINT32_MAX?L"No string reference (0xFFFFFFFF)":L"String-pool index";
    else if(!xx_rt_wcscmp(r->name,L"orientation")){static const wchar_t *const names[]={L"ORIENTATION_ANY",L"ORIENTATION_PORT",L"ORIENTATION_LAND",L"ORIENTATION_SQUARE"};uint64_t v=xx_var_get_u64(&r->value);if(v<SX_COUNT(names))text=names[v];}
    else if(!xx_rt_wcscmp(r->name,L"touchscreen")){static const wchar_t *const names[]={L"TOUCHSCREEN_ANY",L"TOUCHSCREEN_NOTOUCH",L"TOUCHSCREEN_STYLUS",L"TOUCHSCREEN_FINGER"};uint64_t v=xx_var_get_u64(&r->value);if(v<SX_COUNT(names))text=names[v];}
    else if(!xx_rt_wcscmp(r->name,L"keyboard")){static const wchar_t *const names[]={L"KEYBOARD_ANY",L"KEYBOARD_NOKEYS",L"KEYBOARD_QWERTY",L"KEYBOARD_12KEY"};uint64_t v=xx_var_get_u64(&r->value);if(v<SX_COUNT(names))text=names[v];}
    else if(!xx_rt_wcscmp(r->name,L"navigation")){static const wchar_t *const names[]={L"NAVIGATION_ANY",L"NAVIGATION_NONAV",L"NAVIGATION_DPAD",L"NAVIGATION_TRACKBALL",L"NAVIGATION_WHEEL"};uint64_t v=xx_var_get_u64(&r->value);if(v<SX_COUNT(names))text=names[v];}
    else if(!xx_rt_wcscmp(r->name,L"density")){uint64_t v=xx_var_get_u64(&r->value);text=v==0?L"DENSITY_DEFAULT":v==65534?L"DENSITY_ANY":v==65535?L"DENSITY_NONE":L"Dots per inch";}
    else if(!xx_rt_wcscmp(r->name,L"grammatical_inflection"))text=L"Grammatical-gender qualifier in newer Android resources; reserved padding in older versions";
    else if(!xx_rt_wcscmp(r->name,L"screen_width")||!xx_rt_wcscmp(r->name,L"screen_height"))text=L"Pixels; zero selects any size";
    else if(!xx_rt_wcscmp(r->name,L"screen_width_dp")||!xx_rt_wcscmp(r->name,L"screen_height_dp")||!xx_rt_wcscmp(r->name,L"smallest_screen_width_dp"))text=L"Density-independent pixels; zero selects any size";
    else if(!xx_rt_wcscmp(r->name,L"language")||!xx_rt_wcscmp(r->name,L"country"))text=L"Two stored locale bytes; may use the packed three-character encoding";
    else if(!xx_rt_wcscmp(r->name,L"data"))text=L"Encoded value interpreted according to data_type; references are resource IDs, not byte addresses";
    else if(!xx_rt_wcscmp(r->name,L"reserved")||!xx_rt_wcscmp(r->name,L"minor_version"))text=L"Reserved; expected zero";
    return !text||xx_data_struct_record_set_comment(r,text);
}
const sx_family sx_androidmeta_family={sx_androidmeta_supports,sx_androidmeta_build,sx_androidmeta_layouts,SX_COUNT(sx_androidmeta_layouts),sx_androidmeta_comment};
