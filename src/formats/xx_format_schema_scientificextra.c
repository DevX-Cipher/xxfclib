/* SPDX-License-Identifier: MIT
 * Scientific file metadata. Scope: docs/data_struct_scientificextra_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_scientificextra.h"
static const xx_data_struct_field_desc sxscx_iplab_header_le_fields[] = {
    SX_FIELD("byte_order","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_size","uint32",4,4,SX_SIZE),
    SX_FIELD("version","char[4]",8,4,SX_ID),
    SX_FIELD("data_tag","char[4]",12,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",16,4,SX_SIZE),
    SX_FIELD("width","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("channels","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("z_planes","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("time_points","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("sample_type","uint32",40,4,SX_ID),
};
const sx_layout sxscx_iplab_header_le = {UINT32_C(0x60310004),"iplab_header_le",sxscx_iplab_header_le_fields,SX_COUNT(sxscx_iplab_header_le_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_iplab_header_be_fields[] = {
    SX_FIELD("byte_order","char[4]",0,4,SX_SIGNATURE),
    SX_FIELD("version_size","uint32",4,4,SX_SIZE),
    SX_FIELD("version","char[4]",8,4,SX_ID),
    SX_FIELD("data_tag","char[4]",12,4,SX_SIGNATURE),
    SX_FIELD("data_size","uint32",16,4,SX_SIZE),
    SX_FIELD("width","uint32",20,4,SX_COUNT_PROP),
    SX_FIELD("height","uint32",24,4,SX_COUNT_PROP),
    SX_FIELD("channels","uint32",28,4,SX_COUNT_PROP),
    SX_FIELD("z_planes","uint32",32,4,SX_COUNT_PROP),
    SX_FIELD("time_points","uint32",36,4,SX_COUNT_PROP),
    SX_FIELD("sample_type","uint32",40,4,SX_ID),
};
const sx_layout sxscx_iplab_header_be = {UINT32_C(0x60310007),"iplab_header_be",sxscx_iplab_header_be_fields,SX_COUNT(sxscx_iplab_header_be_fields),SX_BE};
static const xx_data_struct_field_desc sxscx_fgb_header_geometry_type_fields[] = {
    SX_FIELD("geometry_type","uint8",0,1,SX_ID),
};
const sx_layout sxscx_fgb_header_geometry_type = {UINT32_C(0x60310028),"fgb_header_geometry_type",sxscx_fgb_header_geometry_type_fields,SX_COUNT(sxscx_fgb_header_geometry_type_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_column_type_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
};
const sx_layout sxscx_fgb_column_type = {UINT32_C(0x60310035),"fgb_column_type",sxscx_fgb_column_type_fields,SX_COUNT(sxscx_fgb_column_type_fields),SX_LE};
static const xx_data_struct_field_desc sxscx_fgb_geometry_type_fields[] = {
    SX_FIELD("type","uint8",0,1,SX_ID),
};
const sx_layout sxscx_fgb_geometry_type = {UINT32_C(0x6031004b),"fgb_geometry_type",sxscx_fgb_geometry_type_fields,SX_COUNT(sxscx_fgb_geometry_type_fields),SX_LE};
static const sx_layout *const sx_scientificextra_layouts[] = {
    &sxscx_aedat2_event,
    &sxscx_axona_timestamp,
    &sxscx_axona_end,
    &sxscx_iplab_header_le,
    &sxscx_iplab_terminator_le,
    &sxscx_dsn6_header_le,
    &sxscx_iplab_header_be,
    &sxscx_iplab_terminator_be,
    &sxscx_dsn6_header_be,
    &sxscx_brix_header,
    &sxscx_mtz_prefix,
    &sxscx_mtz_header_record,
    &sxscx_ensight_header,
    &sxscx_ensight_part,
    &sxscx_ensight_elements,
    &sxscx_ensight_given_id,
    &sxscx_ensight_coordinate,
    &sxscx_ensight_connectivity,
    &sxscx_dted_uhl,
    &sxscx_dted_dsi,
    &sxscx_dted_acc,
    &sxscx_dted_column_header,
    &sxscx_dted_column_checksum,
    &sxscx_fgb_prefix,
    &sxscx_fgb_root,
    &sxscx_fgb_feature_size,
    &sxscx_fgb_table_header,
    &sxscx_fgb_vtable_header,
    &sxscx_fgb_vtable_entry,
    &sxscx_fgb_vector_header,
    &sxscx_fgb_string_header,
    &sxscx_fgb_vector_reference,
    &sxscx_fgb_geometry_end,
    &sxscx_fgb_coordinate,
    &sxscx_fgb_geometry_time,
    &sxscx_fgb_index_internal,
    &sxscx_fgb_index_leaf,
    &sxscx_fgb_header_name,
    &sxscx_fgb_header_envelope,
    &sxscx_fgb_header_geometry_type,
    &sxscx_fgb_header_has_z,
    &sxscx_fgb_header_has_m,
    &sxscx_fgb_header_has_t,
    &sxscx_fgb_header_has_tm,
    &sxscx_fgb_header_columns,
    &sxscx_fgb_header_features_count,
    &sxscx_fgb_header_index_node_size,
    &sxscx_fgb_header_crs,
    &sxscx_fgb_header_title,
    &sxscx_fgb_header_description,
    &sxscx_fgb_header_metadata,
    &sxscx_fgb_column_name,
    &sxscx_fgb_column_type,
    &sxscx_fgb_column_title,
    &sxscx_fgb_column_description,
    &sxscx_fgb_column_width,
    &sxscx_fgb_column_precision,
    &sxscx_fgb_column_scale,
    &sxscx_fgb_column_nullable,
    &sxscx_fgb_column_unique,
    &sxscx_fgb_column_primary_key,
    &sxscx_fgb_column_metadata,
    &sxscx_fgb_crs_org,
    &sxscx_fgb_crs_code,
    &sxscx_fgb_crs_name,
    &sxscx_fgb_crs_description,
    &sxscx_fgb_crs_wkt,
    &sxscx_fgb_crs_code_string,
    &sxscx_fgb_geometry_ends,
    &sxscx_fgb_geometry_xy,
    &sxscx_fgb_geometry_z,
    &sxscx_fgb_geometry_m,
    &sxscx_fgb_geometry_t,
    &sxscx_fgb_geometry_tm,
    &sxscx_fgb_geometry_type,
    &sxscx_fgb_geometry_parts,
    &sxscx_fgb_feature_geometry,
    &sxscx_fgb_feature_properties,
    &sxscx_fgb_property_0,
    &sxscx_fgb_property_1,
    &sxscx_fgb_property_2,
    &sxscx_fgb_property_3,
    &sxscx_fgb_property_4,
    &sxscx_fgb_property_5,
    &sxscx_fgb_property_6,
    &sxscx_fgb_property_7,
    &sxscx_fgb_property_8,
    &sxscx_fgb_property_9,
    &sxscx_fgb_property_10,
    &sxscx_fgb_property_11,
    &sxscx_fgb_property_12,
    &sxscx_fgb_property_13,
    &sxscx_fgb_property_14,
};
static bool sx_scientificextra_static_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60310000U||id>=0x60320000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60310001U:
        if(!xx_rt_wcscmp(r->name,L"event_address"))text=L"Signed packed sensor address; its bits depend on the AEChip. This is not a memory address.";
        if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Microseconds; native reader supports nonnegative monotonic timestamps.";
        break;
    case 0x60310002U:
        if(!xx_rt_wcscmp(r->name,L"timestamp"))text=L"Signed sample-clock count; divide by the text header timebase to obtain seconds.";
        break;
    case 0x60310004U:
        if(!xx_rt_wcscmp(r->name,L"data_size"))text=L"Size of the data block after its tag, including its size word and the six dimension/type words.";
        break;
    case 0x60310006U:
        if(!xx_rt_wcscmp(r->name,L"origin_x"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"origin_y"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"origin_z"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"cell_a"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_b"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_c"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_alpha"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_beta"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_gamma"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"density_multiplier"))text=L"Stored density scale multiplied by100.";
        break;
    case 0x60310007U:
        if(!xx_rt_wcscmp(r->name,L"data_size"))text=L"Size of the data block after its tag, including its size word and the six dimension/type words.";
        break;
    case 0x60310009U:
        if(!xx_rt_wcscmp(r->name,L"origin_x"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"origin_y"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"origin_z"))text=L"Spatial grid coordinate, not a file offset.";
        if(!xx_rt_wcscmp(r->name,L"cell_a"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_b"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_c"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_alpha"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_beta"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"cell_gamma"))text=L"Divide this stored value by cell_multiplier to obtain the cell parameter.";
        if(!xx_rt_wcscmp(r->name,L"density_multiplier"))text=L"Stored density scale multiplied by100.";
        break;
    case 0x6031000aU:
        if(!xx_rt_wcscmp(r->name,L"descriptor_text"))text=L"BRIX ASCII descriptor: origin, extent, grid, cell, prod, plus and sigma. Numeric text is preserved as stored.";
        break;
    case 0x6031000bU:
        if(!xx_rt_wcscmp(r->name,L"header_word_index"))text=L"One-based four-byte word index; byte position is four times(value-1).";
        break;
    case 0x6031000cU:
        if(!xx_rt_wcscmp(r->name,L"record_text"))text=L"Fixed80-byte metadata record. Space-delimited numeric/text fields are preserved verbatim.";
        break;
    case 0x60310010U:
        if(!xx_rt_wcscmp(r->name,L"identifier"))text=L"Stored node or element identifier; not a file offset.";
        break;
    case 0x60310011U:
        if(!xx_rt_wcscmp(r->name,L"coordinate"))text=L"Cartesian coordinate; not a file offset.";
        break;
    case 0x60310012U:
        if(!xx_rt_wcscmp(r->name,L"local_node_index"))text=L"One-based local node index, independent of given node IDs.";
        break;
    case 0x60310013U:
        if(!xx_rt_wcscmp(r->name,L"longitude_interval"))text=L"Tenths of arc-seconds.";
        if(!xx_rt_wcscmp(r->name,L"latitude_interval"))text=L"Tenths of arc-seconds.";
        if(!xx_rt_wcscmp(r->name,L"absolute_vertical_accuracy"))text=L"Metres or NA.";
        break;
    case 0x60310017U:
        if(!xx_rt_wcscmp(r->name,L"checksum"))text=L"Unsigned sum of all bytes in this elevation column, excluding this four-byte checksum.";
        break;
    case 0x60310019U:
        if(!xx_rt_wcscmp(r->name,L"root_offset"))text=L"Forward displacement from this four-byte word to the root table.";
        break;
    case 0x6031001bU:
        if(!xx_rt_wcscmp(r->name,L"vtable_displacement"))text=L"Subtract this signed displacement from the table address to locate its vtable.";
        break;
    case 0x6031001dU:
        if(!xx_rt_wcscmp(r->name,L"member_offset"))text=L"Displacement from the containing table; zero means absent.";
        break;
    case 0x60310020U:
        if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Forward displacement from this word to a table.";
        break;
    case 0x60310021U:
        if(!xx_rt_wcscmp(r->name,L"point_end_index"))text=L"End index in the coordinate array, not a byte offset.";
        break;
    case 0x60310022U:
        if(!xx_rt_wcscmp(r->name,L"coordinate"))text=L"Geometry/envelope floating point value, not a memory address.";
        break;
    case 0x60310024U:
        if(!xx_rt_wcscmp(r->name,L"child_node_index"))text=L"Index of first child node; not a file byte offset.";
        break;
    case 0x60310025U:
        if(!xx_rt_wcscmp(r->name,L"feature_offset"))text=L"Byte displacement from the start of the feature section.";
        break;
    case 0x60310026U:
        if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310027U:
        if(!xx_rt_wcscmp(r->name,L"envelope_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031002dU:
        if(!xx_rt_wcscmp(r->name,L"columns_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310030U:
        if(!xx_rt_wcscmp(r->name,L"crs_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310031U:
        if(!xx_rt_wcscmp(r->name,L"title_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310032U:
        if(!xx_rt_wcscmp(r->name,L"description_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310033U:
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310034U:
        if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310036U:
        if(!xx_rt_wcscmp(r->name,L"title_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310037U:
        if(!xx_rt_wcscmp(r->name,L"description_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031003eU:
        if(!xx_rt_wcscmp(r->name,L"metadata_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031003fU:
        if(!xx_rt_wcscmp(r->name,L"org_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310041U:
        if(!xx_rt_wcscmp(r->name,L"name_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310042U:
        if(!xx_rt_wcscmp(r->name,L"description_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310043U:
        if(!xx_rt_wcscmp(r->name,L"wkt_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310044U:
        if(!xx_rt_wcscmp(r->name,L"code_string_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310045U:
        if(!xx_rt_wcscmp(r->name,L"ends_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310046U:
        if(!xx_rt_wcscmp(r->name,L"xy_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310047U:
        if(!xx_rt_wcscmp(r->name,L"z_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310048U:
        if(!xx_rt_wcscmp(r->name,L"m_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x60310049U:
        if(!xx_rt_wcscmp(r->name,L"t_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031004aU:
        if(!xx_rt_wcscmp(r->name,L"tm_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031004cU:
        if(!xx_rt_wcscmp(r->name,L"parts_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031004dU:
        if(!xx_rt_wcscmp(r->name,L"geometry_offset"))text=L"Forward displacement from this physical word.";
        break;
    case 0x6031004eU:
        if(!xx_rt_wcscmp(r->name,L"properties_offset"))text=L"Forward displacement from this physical word.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
static bool sx_scientificextra_comment(xx_data_struct_record *r,uint32_t id)
{
 if(!sx_scientificextra_static_comment(r,id))return false;
 if(!r||!r->name||id<0x60310000U||id>=0x60320000U)return true;
 xx_var_type_t type=xx_var_get_type(&r->value);
 if(type==XX_VAR_TYPE_FLOAT||type==XX_VAR_TYPE_DOUBLE||type==XX_VAR_TYPE_STRING||type==XX_VAR_TYPE_BYTES)return true;
 uint64_t v=xx_var_get_u64(&r->value);const wchar_t *text=NULL;
 if((id==sxscx_iplab_header_le.id||id==sxscx_iplab_header_be.id)&&!xx_rt_wcscmp(r->name,L"sample_type")){
  switch(v){case 0:text=L"Unsigned8-bit intensity";break;case 1:text=L"Signed16-bit intensity";break;case 2:text=L"Unsigned16-bit intensity";break;case 3:text=L"Signed32-bit intensity";break;case 4:text=L"IEEE754 float32";break;case 5:text=L"Unsigned8-bit data";break;case 6:text=L"Unsigned16-bit data";break;case 10:text=L"IEEE754 float64";break;default:break;}
 }
 if(id==sxscx_fgb_header_geometry_type.id||id==sxscx_fgb_geometry_type.id){
  static const wchar_t *const names[]={L"Unknown",L"Point",L"LineString",L"Polygon",L"MultiPoint",L"MultiLineString",L"MultiPolygon",L"GeometryCollection",L"CircularString",L"CompoundCurve",L"CurvePolygon",L"MultiCurve",L"MultiSurface",L"Curve",L"Surface",L"PolyhedralSurface",L"TIN",L"Triangle"};if(v<SX_COUNT(names))text=names[v];
 }
 if(id==sxscx_fgb_column_type.id){
  static const wchar_t *const names[]={L"Byte",L"UByte",L"Bool",L"Short",L"UShort",L"Int",L"UInt",L"Long",L"ULong",L"Float",L"Double",L"String",L"Json",L"DateTime",L"Binary"};if(v<SX_COUNT(names))text=names[v];
 }
 return !text||xx_data_struct_record_set_comment(r,text);
}
/* Physical coordinates only; bounded output leaves unexpanded data raw. */
bool sxscx_span(sx_context *c,uint64_t at,uint64_t n){return c&&!xx_pd_is_stopped(c->pd)&&c->size>=0&&at<=(uint64_t)c->size&&n<=(uint64_t)c->size-at;}
uint16_t sxscx16(const uint8_t *p,bool be){return xx_data_get_u16(p,2,0,be);}
uint32_t sxscx32(const uint8_t *p,bool be){return xx_data_get_u32(p,4,0,be);}
uint64_t sxscx_extent(const sx_layout *l){const xx_data_struct_field_desc *f=&l->fields[l->field_count-1];return (uint64_t)(f->rel_offset+f->size);}
bool sxscx_add(sx_context *c,const sx_layout *l,uint64_t at){uint64_t n=sxscx_extent(l);return sxscx_span(c,at,n)&&(c->count>=32000||sx_add(c,l,(int64_t)at,(int64_t)n));}
bool sxscx_table(sx_context *c,const sx_layout *l,uint64_t at,uint64_t count){uint64_t n=sxscx_extent(l);return !count||(count<=INT64_MAX/n&&sxscx_span(c,at,n*count)&&(c->count>=32000||sx_table(c,l,(int64_t)at,(int64_t)n,count)));}
static int sxscx_order(const void *a,const void *b){const xx_data_struct *x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:x->total_size<y->total_size?-1:x->total_size>y->total_size?1:x->id<y->id?-1:x->id>y->id?1:0;}
static bool sxscx_finish(sx_context *c)
{
 size_t n=c->count,keep=0;if(!n)return false;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxscx_order);
 /* FlatBuffers can share vtables/vectors. Keep one identical physical view,
  * preserve distinct aliased interpretations and fill only uncovered gaps. */
 for(size_t i=0;i<n;i++){
  xx_data_struct d=c->items[i];if(keep){const xx_data_struct *p=&c->items[keep-1];if(d.offset==p->offset&&d.total_size==p->total_size&&d.entry_size==p->entry_size&&d.count==p->count&&d.id==p->id)continue;}
  c->items[keep++]=d;
 }c->count=n=keep;
 for(size_t i=0;i<n;i++){int64_t at=c->items[i].offset-c->f->base_address,bytes=c->items[i].total_size;if(at>end&&!sx_raw(c,end,at-end))return false;if(at+bytes>end)end=at+bytes;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxscx_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
bool sxscx_decimal(const uint8_t *p,size_t n,uint64_t *value)
{
 uint64_t v=0;size_t i=0;while(i<n&&(p[i]==' '||p[i]=='\t'))i++;bool digit=false;
 for(;i<n&&p[i]>='0'&&p[i]<='9';i++){if(v>(UINT64_MAX-(p[i]-'0'))/10)return false;v=v*10+p[i]-'0';digit=true;}
 while(i<n&&(p[i]==' '||p[i]=='\t'||p[i]=='\r'))i++;*value=v;return digit&&i==n;
}
static bool sx_scientificextra_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_FLATGEOBUF:case XX_FILE_TYPE_AXONA_TETRODE:case XX_FILE_TYPE_INIVATION_AEDAT:case XX_FILE_TYPE_ENSIGHT_GOLD_GEOMETRY:case XX_FILE_TYPE_DTED_ELEVATION:case XX_FILE_TYPE_SCANALYTICS_IPLAB:case XX_FILE_TYPE_DSN6_DENSITY:case XX_FILE_TYPE_CRYSTALLOGRAPHY_MTZ:return true;default:return false;}}
static bool sx_scientificextra_build(sx_context *c)
{
 if(!c||c->size<=0||c->size>134217728||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 uint8_t *b=xx_mem_alloc((size_t)c->size);if(!b)return false;bool ok=sx_read(c,0,b,(size_t)c->size);
 if(ok)switch(c->f->file_type){case XX_FILE_TYPE_FLATGEOBUF:ok=sx_flatgeobuf_build(c,b);break;case XX_FILE_TYPE_AXONA_TETRODE:ok=sx_axona_tetrode_build(c,b);break;case XX_FILE_TYPE_INIVATION_AEDAT:ok=sx_inivation_aedat_build(c,b);break;case XX_FILE_TYPE_ENSIGHT_GOLD_GEOMETRY:ok=sx_ensight_gold_geometry_build(c,b);break;case XX_FILE_TYPE_DTED_ELEVATION:ok=sx_dted_elevation_build(c,b);break;case XX_FILE_TYPE_SCANALYTICS_IPLAB:ok=sx_scanalytics_iplab_build(c,b);break;case XX_FILE_TYPE_DSN6_DENSITY:ok=sx_dsn6_density_build(c,b);break;case XX_FILE_TYPE_CRYSTALLOGRAPHY_MTZ:ok=sx_crystallography_mtz_build(c,b);break;default:ok=false;break;}
 xx_mem_free(b);return ok&&sxscx_finish(c);
}
const sx_family sx_scientificextra_family={sx_scientificextra_supports,sx_scientificextra_build,sx_scientificextra_layouts,SX_COUNT(sx_scientificextra_layouts),sx_scientificextra_comment};
