/* SPDX-License-Identifier: MIT
 * Stored binary model metadata. Scope: docs/data_struct_modelmeta_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_modelmeta.h"
static const sx_layout *const sx_modelmeta_layouts[] = {
    &sxmo_b3d_header,
    &sxmo_b3d_chunk,
    &sxmo_b3d_texture,
    &sxmo_b3d_brush_count,
    &sxmo_b3d_texture_index,
    &sxmo_b3d_brush,
    &sxmo_b3d_node,
    &sxmo_b3d_brush_index,
    &sxmo_b3d_vertices,
    &sxmo_b3d_position,
    &sxmo_b3d_normal,
    &sxmo_b3d_color,
    &sxmo_b3d_texture_coordinate,
    &sxmo_b3d_triangle,
    &sxmo_ms3d_header,
    &sxmo_ms3d_vertex_count,
    &sxmo_ms3d_triangle_count,
    &sxmo_ms3d_group_count,
    &sxmo_ms3d_material_count,
    &sxmo_ms3d_vertex,
    &sxmo_ms3d_triangle,
    &sxmo_ms3d_group,
    &sxmo_ms3d_triangle_index,
    &sxmo_ms3d_material_index,
    &sxmo_ms3d_material,
    &sxmo_ms3d_animation,
    &sxmo_bch21_header,
    &sxmo_bch_relocation,
    &sxmo_ogre_mesh_header,
    &sxmo_ogre_mesh_chunk,
    &sxmo_ogre_mesh_animation,
    &sxmo_ogre_submesh,
    &sxmo_ogre_index16,
    &sxmo_ogre_vertex_count,
    &sxmo_ogre_vertex_element,
    &sxmo_ogre_vertex_buffer,
    &sxmo_ogre_position,
    &sxmo_ogre_operation,
    &sxmo_ogre_bounds,
    &sxmo_blend_header,
    &sxmo_blend_block32_le,
    &sxmo_blend_block64_le,
    &sxmo_blend_dna_names_le,
    &sxmo_blend_dna_types_le,
    &sxmo_blend_dna_structures_le,
    &sxmo_blend_dna_lengths_tag_le,
    &sxmo_blend_dna_type_size_le,
    &sxmo_blend_dna_structure_le,
    &sxmo_blend_dna_field_le,
    &sxmo_blend_block32_be,
    &sxmo_blend_block64_be,
    &sxmo_blend_dna_names_be,
    &sxmo_blend_dna_types_be,
    &sxmo_blend_dna_structures_be,
    &sxmo_blend_dna_lengths_tag_be,
    &sxmo_blend_dna_type_size_be,
    &sxmo_blend_dna_structure_be,
    &sxmo_blend_dna_field_be,
    &sxmo_fbx_header,
    &sxmo_fbx_node32,
    &sxmo_fbx_node64,
    &sxmo_fbx_scalar_y,
    &sxmo_fbx_scalar_c,
    &sxmo_fbx_scalar_i,
    &sxmo_fbx_scalar_f,
    &sxmo_fbx_scalar_l,
    &sxmo_fbx_scalar_d,
    &sxmo_fbx_blob,
    &sxmo_fbx_array,
    &sxmo_fbx_footer_prefix,
    &sxmo_fbx_footer_tail,
    &sxmo_3ds_chunk,
    &sxmo_3ds_version,
    &sxmo_3ds_vertex_count,
    &sxmo_3ds_face_count,
    &sxmo_3ds_uv_count,
    &sxmo_3ds_vertex,
    &sxmo_3ds_uv,
    &sxmo_3ds_face,
    &sxmo_3ds_local_matrix,
    &sxmo_lwo2_form,
    &sxmo_lwo2_chunk,
    &sxmo_lwo2_layer,
    &sxmo_lwo2_point,
    &sxmo_lwo2_polygon_type,
    &sxmo_lwo2_tag_type,
    &sxmo_lwo2_polygon,
    &sxmo_lwo2_index16,
    &sxmo_lwo2_index24,
    &sxmo_lwo2_tag_index,
    &sxmo_s3o_header,
    &sxmo_s3o_piece,
    &sxmo_s3o_vertex,
    &sxmo_s3o_child,
    &sxmo_s3o_index,
    &sxmo_stl_binary_header,
    &sxmo_stl_binary_facet,
    &sxmo_openctm_header,
    &sxmo_openctm_string_length,
    &sxmo_openctm_tag,
    &sxmo_openctm_triangle,
    &sxmo_openctm_vertex,
    &sxmo_openctm_normal,
    &sxmo_openctm_uv,
    &sxmo_openctm_attribute,
    &sxmo_qb_header,
    &sxmo_qb_name_length,
    &sxmo_qb_matrix,
    &sxmo_qb_voxel,
    &sxmo_qb_rle_marker,
    &sxmo_qb_rle_run,
    &sxmo_ter_header,
    &sxmo_ter_end,
    &sxmo_ter_size,
    &sxmo_ter_point_count,
    &sxmo_ter_scale,
    &sxmo_ter_radius,
    &sxmo_ter_curvature,
    &sxmo_ter_altitude,
    &sxmo_ter_height,
    &sxmo_pmx20_header,
    &sxmo_pmx_text_length,
    &sxmo_pmx_vertex_count,
    &sxmo_pmx_face_index_count,
    &sxmo_pmx_texture_count,
    &sxmo_pmx_vertex,
    &sxmo_pmx_additional_uv,
    &sxmo_pmx_skinning,
    &sxmo_pmx_bone_index1,
    &sxmo_pmx_vertex_index1,
    &sxmo_pmx_bone_index2,
    &sxmo_pmx_vertex_index2,
    &sxmo_pmx_bone_index4,
    &sxmo_pmx_vertex_index4,
    &sxmo_pmx_weight,
    &sxmo_pmx_edge_scale,
    &sxmo_pmx_sdef,
    &sxmo_pmx_material_count,
    &sxmo_ogre_skeleton_header,
    &sxmo_ogre_skeleton_chunk,
    &sxmo_ogre_skeleton_bone_chunk,
    &sxmo_ogre_skeleton_bone,
    &sxmo_ogre_skeleton_scale,
    &sxmo_ogre_skeleton_parent,
    &sxmo_ogre_skeleton_blend,
    &sxmo_ogre_skeleton_duration,
    &sxmo_ogre_skeleton_track,
    &sxmo_ogre_skeleton_keyframe,
    &sxmo_cal3d_skeleton_header,
    &sxmo_cal3d_bone_name,
    &sxmo_cal3d_bone,
    &sxmo_cal3d_child,
};
static bool sx_modelmeta_comment(xx_data_struct_record *r,uint32_t id)
{
    if(!r||!r->name||id<0x60210000U||id>=0x60220000U)return true;
    const wchar_t *text=NULL;switch(id){
    case 0x60210002U:
        if(!xx_rt_wcscmp(r->name,L"data_size"))text=L"Payload bytes excluding the eight-byte chunk header.";
        break;
    case 0x60210005U:
        if(!xx_rt_wcscmp(r->name,L"texture_index"))text=L"-1 means no texture.";
        break;
    case 0x60210007U:
        if(!xx_rt_wcscmp(r->name,L"rotation_wxyz"))text=L"Quaternion stored as W, X, Y, Z.";
        break;
    case 0x60210008U:
        if(!xx_rt_wcscmp(r->name,L"brush_index"))text=L"-1 means no brush.";
        break;
    case 0x60210009U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 adds normals; bit 1 adds vertex colors.";
        break;
    case 0x60210014U:
        if(!xx_rt_wcscmp(r->name,L"bone_index"))text=L"-1 means no bone.";
        break;
    case 0x60210018U:
        if(!xx_rt_wcscmp(r->name,L"material_index"))text=L"-1 means no material.";
        break;
    case 0x6021001aU:
        if(!xx_rt_wcscmp(r->name,L"current_time"))text=L"Animation time in seconds.";
        break;
    case 0x6021001cU:
        if(!xx_rt_wcscmp(r->name,L"encoded_relocation"))text=L"Bits 29..31 select source section, 25..28 target section; low 25 bits are a source byte offset for target 1, otherwise a word offset.";
        break;
    case 0x6021001eU:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Includes the six-byte chunk header.";
        break;
    case 0x60210023U:
        if(!xx_rt_wcscmp(r->name,L"offset"))text=L"Byte offset within the vertex.";
        break;
    case 0x60210026U:
        if(!xx_rt_wcscmp(r->name,L"operation_type"))text=L"4 means triangle list.";
        break;
    case 0x60210028U:
        if(!xx_rt_wcscmp(r->name,L"pointer_size"))text=L"Underscore means 32-bit pointers; hyphen means 64-bit pointers.";
        if(!xx_rt_wcscmp(r->name,L"byte_order"))text=L"v means little-endian; V means big-endian.";
        break;
    case 0x60210029U:
        if(!xx_rt_wcscmp(r->name,L"old_pointer"))text=L"Original in-memory address before relocation.";
        break;
    case 0x6021002aU:
        if(!xx_rt_wcscmp(r->name,L"old_pointer"))text=L"Original in-memory address before relocation.";
        break;
    case 0x60210032U:
        if(!xx_rt_wcscmp(r->name,L"old_pointer"))text=L"Original in-memory address before relocation.";
        break;
    case 0x60210033U:
        if(!xx_rt_wcscmp(r->name,L"old_pointer"))text=L"Original in-memory address before relocation.";
        break;
    case 0x60210045U:
        if(!xx_rt_wcscmp(r->name,L"encoding"))text=L"0 means raw values; 1 means zlib compressed.";
        break;
    case 0x60210046U:
        if(!xx_rt_wcscmp(r->name,L"identifier"))text=L"Writer-generated footer identifier.";
        break;
    case 0x60210048U:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Includes this six-byte chunk header.";
        break;
    case 0x60210057U:
        if(!xx_rt_wcscmp(r->name,L"count_and_flags"))text=L"Low 10 bits are vertex count; upper 6 bits are polygon flags.";
        break;
    case 0x60210060U:
        if(!xx_rt_wcscmp(r->name,L"header"))text=L"Application-defined binary header bytes.";
        break;
    case 0x60210061U:
        if(!xx_rt_wcscmp(r->name,L"attribute_byte_count"))text=L"Native reader accepts zero; nonzero vendor color encodings are outside this provider.";
        break;
    case 0x60210062U:
        if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Bit 0 indicates vertex normals.";
        break;
    case 0x6021006aU:
        if(!xx_rt_wcscmp(r->name,L"color_format"))text=L"0=RGBA, 1=BGRA.";
        break;
    case 0x6021006dU:
        if(!xx_rt_wcscmp(r->name,L"encoded_color"))text=L"Color byte order and alpha/visibility-mask meaning are selected by the file header.";
        break;
    case 0x6021006eU:
        if(!xx_rt_wcscmp(r->name,L"marker"))text=L"2=run; 6=end of slice.";
        break;
    case 0x60210072U:
        if(!xx_rt_wcscmp(r->name,L"size_minus_one"))text=L"Shorter terrain side is this value plus one samples.";
        break;
    case 0x60210078U:
        if(!xx_rt_wcscmp(r->name,L"height_sample"))text=L"Encoded height; convert using base_height and height_scale, then vertical scale.";
        break;
    case 0x60210079U:
        if(!xx_rt_wcscmp(r->name,L"encoding"))text=L"0=UTF-16LE, 1=UTF-8.";
        break;
    case 0x60210080U:
        if(!xx_rt_wcscmp(r->name,L"deform_type"))text=L"0=BDEF1, 1=BDEF2, 2=BDEF4, 3=SDEF.";
        break;
    case 0x60210081U:
        if(!xx_rt_wcscmp(r->name,L"bone_index"))text=L"-1 means no bone.";
        break;
    case 0x60210083U:
        if(!xx_rt_wcscmp(r->name,L"bone_index"))text=L"-1 means no bone.";
        break;
    case 0x60210085U:
        if(!xx_rt_wcscmp(r->name,L"bone_index"))text=L"-1 means no bone.";
        break;
    case 0x6021008cU:
        if(!xx_rt_wcscmp(r->name,L"chunk_size"))text=L"Includes this six-byte header.";
        break;
    case 0x6021008dU:
        if(!xx_rt_wcscmp(r->name,L"fixed_size"))text=L"Historical bone length excludes the newline-terminated bone name; includes the six-byte header.";
        break;
    case 0x60210092U:
        if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Animation duration in seconds.";
        break;
    case 0x60210094U:
        if(!xx_rt_wcscmp(r->name,L"time"))text=L"Animation time in seconds.";
        break;
    case 0x60210096U:
        if(!xx_rt_wcscmp(r->name,L"name_size"))text=L"Includes the terminating NUL byte.";
        break;
    case 0x60210097U:
        if(!xx_rt_wcscmp(r->name,L"parent_index"))text=L"-1 means no parent.";
        break;
    default:break;}return !text||xx_data_struct_record_set_comment(r,text);
}
/* Physical metadata only; unimplemented and compressed bodies stay raw. */
bool sxmo_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxmo_read(sx_context*c,uint64_t p,void*b,size_t n){return sxmo_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxmo_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
uint32_t sxmo32(const uint8_t*b,bool be){return(uint32_t)sxmo_uint(b,4,be);}
uint16_t sxmo16(const uint8_t*b,bool be){return(uint16_t)sxmo_uint(b,2,be);}
/* Alias pointers are emitted once. Partial overlaps retain the first bounded physical record. */
bool sxmo_table(sx_context*c,const sx_layout*l,uint64_t p,uint64_t n){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(!n)return true;if(n>1000000||!sxmo_span(c,p,z*n))return false;if(c->count>=20000)return true;for(size_t i=0;i<c->count;i++){uint64_t a=(uint64_t)(c->items[i].offset-c->f->base_address),b=a+(uint64_t)c->items[i].total_size;if(p<b&&a<p+z*n)return true;}return sx_table(c,l,(int64_t)p,(int64_t)z,n);}
bool sxmo_add(sx_context*c,const sx_layout*l,uint64_t p){return sxmo_table(c,l,p,1);}
bool sxmo_string(sx_context*c,uint64_t*p,uint64_t end,uint8_t terminal){for(unsigned i=0;i<4096;i++){uint8_t b;if(*p>=end||!sxmo_read(c,(*p)++,&b,1))return false;if(b==terminal)return true;}return false;}
bool sxmo_take(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];uint64_t z=(uint64_t)(f->rel_offset+f->size);if(*p>end||z>end-*p||!sxmo_add(c,l,*p))return false;*p+=z;return true;}
bool sxmo_text(sx_context*c,const sx_layout*l,uint64_t*p,uint64_t end){uint8_t b[4];if(*p>end||end-*p<4||!sxmo_read(c,*p,b,4))return false;uint32_t n=sxmo32(b,false);if(n>1048576||n>end-*p-4||!sxmo_add(c,l,*p))return false;*p+=4+n;return true;}
static int sxmo_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
bool sxmo_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxmo_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxmo_order);return !c->failed;}
static bool sx_modelmeta_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_BLITZ3D_B3D:case XX_FILE_TYPE_MILKSHAPE_MS3D:case XX_FILE_TYPE_NINTENDO_BCH:case XX_FILE_TYPE_OGRE_MESH:case XX_FILE_TYPE_BLENDER_BLEND:case XX_FILE_TYPE_AUTODESK_FBX:case XX_FILE_TYPE_AUTODESK_3DS:case XX_FILE_TYPE_LIGHTWAVE_LWO2:case XX_FILE_TYPE_SPRING_S3O:case XX_FILE_TYPE_STEREOLITHOGRAPHY_STL:case XX_FILE_TYPE_OPENCTM_MESH:case XX_FILE_TYPE_QUBICLE_QB:case XX_FILE_TYPE_TERRAGEN_TER:case XX_FILE_TYPE_MMD_PMX:case XX_FILE_TYPE_OGRE_SKELETON:case XX_FILE_TYPE_CAL3D_SKELETON:return true;default:return false;}}
static bool sx_modelmeta_build(sx_context*c){
if(c->f->file_type==XX_FILE_TYPE_BLITZ3D_B3D)return sx_blitz3d_b3d_build(c);
if(c->f->file_type==XX_FILE_TYPE_MILKSHAPE_MS3D)return sx_milkshape_ms3d_build(c);
if(c->f->file_type==XX_FILE_TYPE_NINTENDO_BCH)return sx_nintendo_bch_build(c);
if(c->f->file_type==XX_FILE_TYPE_OGRE_MESH)return sx_ogre_mesh_build(c);
if(c->f->file_type==XX_FILE_TYPE_BLENDER_BLEND)return sx_blender_blend_build(c);
if(c->f->file_type==XX_FILE_TYPE_AUTODESK_FBX)return sx_autodesk_fbx_build(c);
if(c->f->file_type==XX_FILE_TYPE_AUTODESK_3DS)return sx_autodesk_3ds_build(c);
if(c->f->file_type==XX_FILE_TYPE_LIGHTWAVE_LWO2)return sx_lightwave_lwo2_build(c);
if(c->f->file_type==XX_FILE_TYPE_SPRING_S3O)return sx_spring_s3o_build(c);
if(c->f->file_type==XX_FILE_TYPE_STEREOLITHOGRAPHY_STL)return sx_stereolithography_stl_build(c);
if(c->f->file_type==XX_FILE_TYPE_OPENCTM_MESH)return sx_openctm_mesh_build(c);
if(c->f->file_type==XX_FILE_TYPE_QUBICLE_QB)return sx_qubicle_qb_build(c);
if(c->f->file_type==XX_FILE_TYPE_TERRAGEN_TER)return sx_terragen_ter_build(c);
if(c->f->file_type==XX_FILE_TYPE_MMD_PMX)return sx_mmd_pmx_build(c);
if(c->f->file_type==XX_FILE_TYPE_OGRE_SKELETON)return sx_ogre_skeleton_build(c);
if(c->f->file_type==XX_FILE_TYPE_CAL3D_SKELETON)return sx_cal3d_skeleton_build(c);
return false;}
const sx_family sx_modelmeta_family={sx_modelmeta_supports,sx_modelmeta_build,sx_modelmeta_layouts,SX_COUNT(sx_modelmeta_layouts),sx_modelmeta_comment};
