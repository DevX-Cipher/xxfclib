/* SPDX-License-Identifier: MIT. Physical serialization metadata. Scope: docs/data_struct_videotail_scope.txt. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xx_format_schema_videotail.h"
static const sx_layout *const sx_videotail_layouts[] = {
 &sxvt_grasp_header,
 &sxvt_grasp_entry,
 &sxvt_grasp_member_size,
 &sxvt_swf_header,
 &sxvt_swf_lzma_header,
 &sxvt_swf_rect1,
 &sxvt_swf_rect2,
 &sxvt_swf_rect3,
 &sxvt_swf_rect4,
 &sxvt_swf_rect5,
 &sxvt_swf_rect6,
 &sxvt_swf_rect7,
 &sxvt_swf_rect8,
 &sxvt_swf_rect9,
 &sxvt_swf_rect10,
 &sxvt_swf_rect11,
 &sxvt_swf_rect12,
 &sxvt_swf_rect13,
 &sxvt_swf_rect14,
 &sxvt_swf_rect15,
 &sxvt_swf_rect16,
 &sxvt_swf_rect17,
 &sxvt_swf_movie,
 &sxvt_swf_tag_short,
 &sxvt_swf_tag_long,
 &sxvt_swf_sprite,
 &sxvt_swf_background,
 &sxvt_swf_character_id,
 &sxvt_swf_jpeg3,
 &sxvt_swf_jpeg4,
 &sxvt_swf_lossless,
 &sxvt_swf_palette_count,
 &sxvt_swf_sound,
 &sxvt_swf_mp3_seek,
 &sxvt_swf_stream_sound,
 &sxvt_swf_binary,
 &sxvt_swf_file_attributes,
 &sxvt_director_header_le,
 &sxvt_director_chunk_le,
 &sxvt_director_header_be,
 &sxvt_director_chunk_be,
 &sxvt_mp4_box,
 &sxvt_mp4_box64,
 &sxvt_mp4_uuid,
 &sxvt_mp4_ftyp,
 &sxvt_mp4_brand,
 &sxvt_mp4_mvhd_v0,
 &sxvt_mp4_tkhd_v0,
 &sxvt_mp4_mdhd_v0,
 &sxvt_mp4_elst_entry_v0,
 &sxvt_mp4_mvhd_v1,
 &sxvt_mp4_tkhd_v1,
 &sxvt_mp4_mdhd_v1,
 &sxvt_mp4_elst_entry_v1,
 &sxvt_mp4_hdlr,
 &sxvt_mp4_table,
 &sxvt_mp4_stsz,
 &sxvt_mp4_stco,
 &sxvt_mp4_co64,
 &sxvt_mp4_stts,
 &sxvt_mp4_ctts_v0,
 &sxvt_mp4_ctts_v1,
 &sxvt_mp4_stsc,
 &sxvt_mp4_stss,
 &sxvt_mp4_sample_size,
 &sxvt_mp4_sample_entry,
 &sxvt_mp4_vmhd,
 &sxvt_mp4_smhd,
 &sxvt_mp4_fullbox,
 &sxvt_ebml_id1,
 &sxvt_ebml_id2,
 &sxvt_ebml_id3,
 &sxvt_ebml_id4,
 &sxvt_ebml_size1,
 &sxvt_matroska_track1,
 &sxvt_matroska_lace_size1,
 &sxvt_matroska_lace_delta1,
 &sxvt_matroska_uint1,
 &sxvt_matroska_offset1,
 &sxvt_ebml_size2,
 &sxvt_matroska_track2,
 &sxvt_matroska_lace_size2,
 &sxvt_matroska_lace_delta2,
 &sxvt_matroska_uint2,
 &sxvt_matroska_offset2,
 &sxvt_ebml_size3,
 &sxvt_matroska_track3,
 &sxvt_matroska_lace_size3,
 &sxvt_matroska_lace_delta3,
 &sxvt_matroska_uint3,
 &sxvt_matroska_offset3,
 &sxvt_ebml_size4,
 &sxvt_matroska_track4,
 &sxvt_matroska_lace_size4,
 &sxvt_matroska_lace_delta4,
 &sxvt_matroska_uint4,
 &sxvt_matroska_offset4,
 &sxvt_ebml_size5,
 &sxvt_matroska_track5,
 &sxvt_matroska_lace_size5,
 &sxvt_matroska_lace_delta5,
 &sxvt_matroska_uint5,
 &sxvt_matroska_offset5,
 &sxvt_ebml_size6,
 &sxvt_matroska_track6,
 &sxvt_matroska_lace_size6,
 &sxvt_matroska_lace_delta6,
 &sxvt_matroska_uint6,
 &sxvt_matroska_offset6,
 &sxvt_ebml_size7,
 &sxvt_matroska_track7,
 &sxvt_matroska_lace_size7,
 &sxvt_matroska_lace_delta7,
 &sxvt_matroska_uint7,
 &sxvt_matroska_offset7,
 &sxvt_ebml_size8,
 &sxvt_matroska_track8,
 &sxvt_matroska_lace_size8,
 &sxvt_matroska_lace_delta8,
 &sxvt_matroska_uint8,
 &sxvt_matroska_offset8,
 &sxvt_matroska_date,
 &sxvt_matroska_float4,
 &sxvt_matroska_float8,
 &sxvt_matroska_crc32,
 &sxvt_matroska_block,
 &sxvt_matroska_lace_count,
 &sxvt_matroska_xiph_size,
 &sxvt_director_imap_le,
 &sxvt_director_mmap_le,
 &sxvt_director_mmap_entry_le,
 &sxvt_director_key_le,
 &sxvt_director_key_entry_le,
 &sxvt_director_imap_be,
 &sxvt_director_mmap_be,
 &sxvt_director_mmap_entry_be,
 &sxvt_director_key_be,
 &sxvt_director_key_entry_be,
 &sxvt_director_cast_index,
};
static bool sx_videotail_comment(xx_data_struct_record*r,uint32_t id){
 if(!r||!r->name||id<0x60390000U||id>=0x603a0000U)return true;
 const wchar_t*text=NULL;switch(id){
 case 0x60390001U:
 if(!xx_rt_wcscmp(r->name,L"index_size"))text=L"Byte length of the following17-byte-entry index.";
 break;
 case 0x60390002U:
 if(!xx_rt_wcscmp(r->name,L"member_offset"))text=L"File-relative offset of the member length word; zero ends the index.";
 break;
 case 0x60390004U:
 if(!xx_rt_wcscmp(r->name,L"uncompressed_file_size"))text=L"Complete uncompressed movie length including this8-byte header; compressed storage extent can differ.";
 break;
 case 0x60390005U:
 if(!xx_rt_wcscmp(r->name,L"compressed_size"))text=L"Length of LZMA compressed data, excluding the five property bytes.";
 if(!xx_rt_wcscmp(r->name,L"lc_lp_pb"))text=L"LZMA property byte encodes lc,lp,pb.";
 break;
 case 0x60390006U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390007U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390008U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390009U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000aU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000bU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000cU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000dU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000eU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x6039000fU:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390010U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390011U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390012U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390013U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390014U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390015U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390016U:
 if(!xx_rt_wcscmp(r->name,L"encoded_rect"))text=L"Bit-packed RECT: first5bits give signed coordinate width, followed by Xmin,Xmax,Ymin,Ymax in twips and byte-alignment padding.";
 break;
 case 0x60390017U:
 if(!xx_rt_wcscmp(r->name,L"frame_rate_fixed8"))text=L"Adobe SWF19 physical UI16 field; unsigned8.8 frames per second.";
 break;
 case 0x60390018U: if(!xx_rt_wcscmp(r->name,L"code_and_length")){switch(xx_var_get_u64(&r->value)>>6){
 case 0:text=L"End; low6bits encode body length or63 for long header";break;
 case 1:text=L"ShowFrame; low6bits encode body length or63 for long header";break;
 case 6:text=L"DefineBits; low6bits encode body length or63 for long header";break;
 case 8:text=L"JPEGTables; low6bits encode body length or63 for long header";break;
 case 9:text=L"SetBackgroundColor; low6bits encode body length or63 for long header";break;
 case 14:text=L"DefineSound; low6bits encode body length or63 for long header";break;
 case 18:text=L"SoundStreamHead; low6bits encode body length or63 for long header";break;
 case 19:text=L"SoundStreamBlock; low6bits encode body length or63 for long header";break;
 case 20:text=L"DefineBitsLossless; low6bits encode body length or63 for long header";break;
 case 21:text=L"DefineBitsJPEG2; low6bits encode body length or63 for long header";break;
 case 35:text=L"DefineBitsJPEG3; low6bits encode body length or63 for long header";break;
 case 36:text=L"DefineBitsLossless2; low6bits encode body length or63 for long header";break;
 case 39:text=L"DefineSprite; low6bits encode body length or63 for long header";break;
 case 45:text=L"SoundStreamHead2; low6bits encode body length or63 for long header";break;
 case 69:text=L"FileAttributes; low6bits encode body length or63 for long header";break;
 case 87:text=L"DefineBinaryData; low6bits encode body length or63 for long header";break;
 case 90:text=L"DefineBitsJPEG4; low6bits encode body length or63 for long header";break;
 default:text=L"Upper10bits tag code; low6bits body length or63 for long header";break;}}break;
 case 0x60390019U: if(!xx_rt_wcscmp(r->name,L"code_and_length")){switch(xx_var_get_u64(&r->value)>>6){
 case 0:text=L"End; low6bits encode body length or63 for long header";break;
 case 1:text=L"ShowFrame; low6bits encode body length or63 for long header";break;
 case 6:text=L"DefineBits; low6bits encode body length or63 for long header";break;
 case 8:text=L"JPEGTables; low6bits encode body length or63 for long header";break;
 case 9:text=L"SetBackgroundColor; low6bits encode body length or63 for long header";break;
 case 14:text=L"DefineSound; low6bits encode body length or63 for long header";break;
 case 18:text=L"SoundStreamHead; low6bits encode body length or63 for long header";break;
 case 19:text=L"SoundStreamBlock; low6bits encode body length or63 for long header";break;
 case 20:text=L"DefineBitsLossless; low6bits encode body length or63 for long header";break;
 case 21:text=L"DefineBitsJPEG2; low6bits encode body length or63 for long header";break;
 case 35:text=L"DefineBitsJPEG3; low6bits encode body length or63 for long header";break;
 case 36:text=L"DefineBitsLossless2; low6bits encode body length or63 for long header";break;
 case 39:text=L"DefineSprite; low6bits encode body length or63 for long header";break;
 case 45:text=L"SoundStreamHead2; low6bits encode body length or63 for long header";break;
 case 69:text=L"FileAttributes; low6bits encode body length or63 for long header";break;
 case 87:text=L"DefineBinaryData; low6bits encode body length or63 for long header";break;
 case 90:text=L"DefineBitsJPEG4; low6bits encode body length or63 for long header";break;
 default:text=L"Upper10bits tag code; low6bits body length or63 for long header";break;}}break;
 case 0x6039001dU:
 if(!xx_rt_wcscmp(r->name,L"alpha_data_offset"))text=L"Relative to the end of this fixed header, where JPEG bytes begin.";
 break;
 case 0x6039001eU:
 if(!xx_rt_wcscmp(r->name,L"alpha_data_offset"))text=L"Byte count of ImageData; alpha bytes begin this many bytes after the8-byte fixed header.";
 if(!xx_rt_wcscmp(r->name,L"deblock_fixed8"))text=L"Unsigned8.8 normalized deblocking strength; Adobe SWF19 declares UI16.";
 break;
 case 0x60390020U:
 if(!xx_rt_wcscmp(r->name,L"palette_count_minus_one"))text=L"Encoded number of colour-table entries minus1.";
 break;
 case 0x60390021U:
 if(!xx_rt_wcscmp(r->name,L"sound_format_flags"))text=L"High4bits codec, next2bits sample-rate selector, bit1 sample width, bit0 stereo.";
 break;
 case 0x60390026U:
 if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Container length minus8.";
 break;
 case 0x60390028U:
 if(!xx_rt_wcscmp(r->name,L"payload_size"))text=L"Container length minus8.";
 break;
 case 0x6039002aU:
 if(!xx_rt_wcscmp(r->name,L"box_size"))text=L"Includes this header;1 selects64-bit extended size;0 extends to parent end.";
 break;
 case 0x6039002bU:
 if(!xx_rt_wcscmp(r->name,L"box_size"))text=L"Value1 selects the following64-bit size.";
 break;
 case 0x6039002fU:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"timescale"))text=L"Ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"rate_fixed16"))text=L"Signed16.16 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"volume_fixed8"))text=L"Signed8.8 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"matrix"))text=L"Signed16.16 values except u,v,w use2.30.";
 break;
 case 0x60390030U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"TrackEnabled=1,TrackInMovie=2,TrackInPreview=4,TrackSizeIsAspectRatio=8.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"volume_fixed8"))text=L"Signed8.8 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"matrix"))text=L"Signed16.16 values except u,v,w use2.30.";
 if(!xx_rt_wcscmp(r->name,L"width_fixed16"))text=L"Unsigned16.16 pixels.";
 if(!xx_rt_wcscmp(r->name,L"height_fixed16"))text=L"Unsigned16.16 pixels.";
 break;
 case 0x60390031U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"timescale"))text=L"Ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Media timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"language"))text=L"Low15bits encode three5-bit ISO639-2 letters, each plus0x60.";
 break;
 case 0x60390032U:
 if(!xx_rt_wcscmp(r->name,L"segment_duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"media_time"))text=L"Media timescale ticks;-1 means empty edit.";
 break;
 case 0x60390033U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"timescale"))text=L"Ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"rate_fixed16"))text=L"Signed16.16 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"volume_fixed8"))text=L"Signed8.8 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"matrix"))text=L"Signed16.16 values except u,v,w use2.30.";
 break;
 case 0x60390034U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"TrackEnabled=1,TrackInMovie=2,TrackInPreview=4,TrackSizeIsAspectRatio=8.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"volume_fixed8"))text=L"Signed8.8 fixed point.";
 if(!xx_rt_wcscmp(r->name,L"matrix"))text=L"Signed16.16 values except u,v,w use2.30.";
 if(!xx_rt_wcscmp(r->name,L"width_fixed16"))text=L"Unsigned16.16 pixels.";
 if(!xx_rt_wcscmp(r->name,L"height_fixed16"))text=L"Unsigned16.16 pixels.";
 break;
 case 0x60390035U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"creation_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"modification_time"))text=L"Seconds since1904-01-01UTC.";
 if(!xx_rt_wcscmp(r->name,L"timescale"))text=L"Ticks per second.";
 if(!xx_rt_wcscmp(r->name,L"duration"))text=L"Media timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"language"))text=L"Low15bits encode three5-bit ISO639-2 letters, each plus0x60.";
 break;
 case 0x60390036U:
 if(!xx_rt_wcscmp(r->name,L"segment_duration"))text=L"Movie timescale ticks.";
 if(!xx_rt_wcscmp(r->name,L"media_time"))text=L"Media timescale ticks;-1 means empty edit.";
 break;
 case 0x60390037U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 break;
 case 0x60390038U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 break;
 case 0x60390039U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"sample_size"))text=L"Zero selects one size per sample.";
 break;
 case 0x6039003aU:
 if(!xx_rt_wcscmp(r->name,L"chunk_offset"))text=L"File-relative byte offset of the media chunk.";
 break;
 case 0x6039003bU:
 if(!xx_rt_wcscmp(r->name,L"chunk_offset"))text=L"File-relative byte offset of the media chunk.";
 break;
 case 0x6039003cU:
 if(!xx_rt_wcscmp(r->name,L"sample_delta"))text=L"Decode duration in media timescale ticks.";
 break;
 case 0x6039003dU:
 if(!xx_rt_wcscmp(r->name,L"sample_offset"))text=L"Composition offset in media timescale ticks.";
 break;
 case 0x6039003eU:
 if(!xx_rt_wcscmp(r->name,L"sample_offset"))text=L"Signed composition offset in media timescale ticks.";
 break;
 case 0x6039003fU:
 if(!xx_rt_wcscmp(r->name,L"first_chunk"))text=L"One-based chunk index.";
 if(!xx_rt_wcscmp(r->name,L"sample_description_index"))text=L"One-based sample description index.";
 break;
 case 0x60390040U:
 if(!xx_rt_wcscmp(r->name,L"sample_number"))text=L"One-based sync sample index.";
 break;
 case 0x60390043U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 break;
 case 0x60390044U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 if(!xx_rt_wcscmp(r->name,L"balance_fixed8"))text=L"Signed8.8 fixed point.";
 break;
 case 0x60390045U:
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Box-specific24-bit flags.";
 break;
 case 0x60390046U: switch(xx_var_get_u64(&r->value)) {
 case 440786851:text=L"EBML";break;
 case 408125543:text=L"Segment";break;
 case 357149030:text=L"Info";break;
 case 374648427:text=L"Tracks";break;
 case 174:text=L"TrackEntry";break;
 case 524531317:text=L"Cluster";break;
 case 160:text=L"BlockGroup";break;
 case 163:text=L"SimpleBlock";break;
 case 161:text=L"Block";break;
 case 236:text=L"Void";break;
 case 191:text=L"CRC32";break;
 case 17026:text=L"DocType";break;
 case 17030:text=L"EBMLVersion";break;
 case 17143:text=L"EBMLReadVersion";break;
 case 17138:text=L"EBMLMaxIDLength";break;
 case 17139:text=L"EBMLMaxSizeLength";break;
 case 17031:text=L"DocTypeVersion";break;
 case 17029:text=L"DocTypeReadVersion";break;
 case 2807729:text=L"TimestampScale";break;
 case 17545:text=L"Duration";break;
 case 17505:text=L"DateUTC";break;
 case 19840:text=L"MuxingApp";break;
 case 22337:text=L"WritingApp";break;
 case 215:text=L"TrackNumber";break;
 case 29637:text=L"TrackUID";break;
 case 131:text=L"TrackType";break;
 case 134:text=L"CodecID";break;
 case 224:text=L"Video";break;
 case 225:text=L"Audio";break;
 case 176:text=L"PixelWidth";break;
 case 186:text=L"PixelHeight";break;
 case 181:text=L"SamplingFrequency";break;
 case 159:text=L"Channels";break;
 case 231:text=L"Timestamp";break;
 case 21420:text=L"SeekPosition";break;
 case 290298740:text=L"SeekHead";break;
 case 19899:text=L"Seek";break;
 case 241:text=L"CueClusterPosition";break;
 case 240:text=L"CueRelativePosition";break;
 default:text=L"EBML element ID including its marker bit";break;}break;
 case 0x60390047U: switch(xx_var_get_u64(&r->value)) {
 case 440786851:text=L"EBML";break;
 case 408125543:text=L"Segment";break;
 case 357149030:text=L"Info";break;
 case 374648427:text=L"Tracks";break;
 case 174:text=L"TrackEntry";break;
 case 524531317:text=L"Cluster";break;
 case 160:text=L"BlockGroup";break;
 case 163:text=L"SimpleBlock";break;
 case 161:text=L"Block";break;
 case 236:text=L"Void";break;
 case 191:text=L"CRC32";break;
 case 17026:text=L"DocType";break;
 case 17030:text=L"EBMLVersion";break;
 case 17143:text=L"EBMLReadVersion";break;
 case 17138:text=L"EBMLMaxIDLength";break;
 case 17139:text=L"EBMLMaxSizeLength";break;
 case 17031:text=L"DocTypeVersion";break;
 case 17029:text=L"DocTypeReadVersion";break;
 case 2807729:text=L"TimestampScale";break;
 case 17545:text=L"Duration";break;
 case 17505:text=L"DateUTC";break;
 case 19840:text=L"MuxingApp";break;
 case 22337:text=L"WritingApp";break;
 case 215:text=L"TrackNumber";break;
 case 29637:text=L"TrackUID";break;
 case 131:text=L"TrackType";break;
 case 134:text=L"CodecID";break;
 case 224:text=L"Video";break;
 case 225:text=L"Audio";break;
 case 176:text=L"PixelWidth";break;
 case 186:text=L"PixelHeight";break;
 case 181:text=L"SamplingFrequency";break;
 case 159:text=L"Channels";break;
 case 231:text=L"Timestamp";break;
 case 21420:text=L"SeekPosition";break;
 case 290298740:text=L"SeekHead";break;
 case 19899:text=L"Seek";break;
 case 241:text=L"CueClusterPosition";break;
 case 240:text=L"CueRelativePosition";break;
 default:text=L"EBML element ID including its marker bit";break;}break;
 case 0x60390048U: switch(xx_var_get_u64(&r->value)) {
 case 440786851:text=L"EBML";break;
 case 408125543:text=L"Segment";break;
 case 357149030:text=L"Info";break;
 case 374648427:text=L"Tracks";break;
 case 174:text=L"TrackEntry";break;
 case 524531317:text=L"Cluster";break;
 case 160:text=L"BlockGroup";break;
 case 163:text=L"SimpleBlock";break;
 case 161:text=L"Block";break;
 case 236:text=L"Void";break;
 case 191:text=L"CRC32";break;
 case 17026:text=L"DocType";break;
 case 17030:text=L"EBMLVersion";break;
 case 17143:text=L"EBMLReadVersion";break;
 case 17138:text=L"EBMLMaxIDLength";break;
 case 17139:text=L"EBMLMaxSizeLength";break;
 case 17031:text=L"DocTypeVersion";break;
 case 17029:text=L"DocTypeReadVersion";break;
 case 2807729:text=L"TimestampScale";break;
 case 17545:text=L"Duration";break;
 case 17505:text=L"DateUTC";break;
 case 19840:text=L"MuxingApp";break;
 case 22337:text=L"WritingApp";break;
 case 215:text=L"TrackNumber";break;
 case 29637:text=L"TrackUID";break;
 case 131:text=L"TrackType";break;
 case 134:text=L"CodecID";break;
 case 224:text=L"Video";break;
 case 225:text=L"Audio";break;
 case 176:text=L"PixelWidth";break;
 case 186:text=L"PixelHeight";break;
 case 181:text=L"SamplingFrequency";break;
 case 159:text=L"Channels";break;
 case 231:text=L"Timestamp";break;
 case 21420:text=L"SeekPosition";break;
 case 290298740:text=L"SeekHead";break;
 case 19899:text=L"Seek";break;
 case 241:text=L"CueClusterPosition";break;
 case 240:text=L"CueRelativePosition";break;
 default:text=L"EBML element ID including its marker bit";break;}break;
 case 0x60390049U: switch(xx_var_get_u64(&r->value)) {
 case 440786851:text=L"EBML";break;
 case 408125543:text=L"Segment";break;
 case 357149030:text=L"Info";break;
 case 374648427:text=L"Tracks";break;
 case 174:text=L"TrackEntry";break;
 case 524531317:text=L"Cluster";break;
 case 160:text=L"BlockGroup";break;
 case 163:text=L"SimpleBlock";break;
 case 161:text=L"Block";break;
 case 236:text=L"Void";break;
 case 191:text=L"CRC32";break;
 case 17026:text=L"DocType";break;
 case 17030:text=L"EBMLVersion";break;
 case 17143:text=L"EBMLReadVersion";break;
 case 17138:text=L"EBMLMaxIDLength";break;
 case 17139:text=L"EBMLMaxSizeLength";break;
 case 17031:text=L"DocTypeVersion";break;
 case 17029:text=L"DocTypeReadVersion";break;
 case 2807729:text=L"TimestampScale";break;
 case 17545:text=L"Duration";break;
 case 17505:text=L"DateUTC";break;
 case 19840:text=L"MuxingApp";break;
 case 22337:text=L"WritingApp";break;
 case 215:text=L"TrackNumber";break;
 case 29637:text=L"TrackUID";break;
 case 131:text=L"TrackType";break;
 case 134:text=L"CodecID";break;
 case 224:text=L"Video";break;
 case 225:text=L"Audio";break;
 case 176:text=L"PixelWidth";break;
 case 186:text=L"PixelHeight";break;
 case 181:text=L"SamplingFrequency";break;
 case 159:text=L"Channels";break;
 case 231:text=L"Timestamp";break;
 case 21420:text=L"SeekPosition";break;
 case 290298740:text=L"SeekHead";break;
 case 19899:text=L"Seek";break;
 case 241:text=L"CueClusterPosition";break;
 case 240:text=L"CueRelativePosition";break;
 default:text=L"EBML element ID including its marker bit";break;}break;
 case 0x6039004aU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(127);char b[160];wchar_t wide[160];
 if((raw>>7)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(127))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039004bU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(127);char b[160];wchar_t wide[160];
 if((raw>>7)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039004cU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(127);char b[160];wchar_t wide[160];
 if((raw>>7)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039004dU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(127);char b[160];wchar_t wide[160];
 if((raw>>7)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(63)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039004fU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390050U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(16383);char b[160];wchar_t wide[160];
 if((raw>>14)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(16383))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390051U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(16383);char b[160];wchar_t wide[160];
 if((raw>>14)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390052U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(16383);char b[160];wchar_t wide[160];
 if((raw>>14)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390053U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(16383);char b[160];wchar_t wide[160];
 if((raw>>14)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(8191)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390055U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390056U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(2097151);char b[160];wchar_t wide[160];
 if((raw>>21)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(2097151))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390057U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(2097151);char b[160];wchar_t wide[160];
 if((raw>>21)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390058U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(2097151);char b[160];wchar_t wide[160];
 if((raw>>21)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390059U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(2097151);char b[160];wchar_t wide[160];
 if((raw>>21)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(1048575)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039005bU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x6039005cU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(268435455);char b[160];wchar_t wide[160];
 if((raw>>28)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(268435455))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039005dU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(268435455);char b[160];wchar_t wide[160];
 if((raw>>28)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039005eU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(268435455);char b[160];wchar_t wide[160];
 if((raw>>28)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039005fU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(268435455);char b[160];wchar_t wide[160];
 if((raw>>28)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(134217727)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390061U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390062U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(34359738367);char b[160];wchar_t wide[160];
 if((raw>>35)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(34359738367))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390063U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(34359738367);char b[160];wchar_t wide[160];
 if((raw>>35)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390064U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(34359738367);char b[160];wchar_t wide[160];
 if((raw>>35)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390065U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(34359738367);char b[160];wchar_t wide[160];
 if((raw>>35)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(17179869183)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390067U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390068U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(4398046511103);char b[160];wchar_t wide[160];
 if((raw>>42)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(4398046511103))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390069U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(4398046511103);char b[160];wchar_t wide[160];
 if((raw>>42)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039006aU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(4398046511103);char b[160];wchar_t wide[160];
 if((raw>>42)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039006bU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(4398046511103);char b[160];wchar_t wide[160];
 if((raw>>42)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(2199023255551)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039006dU:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x6039006eU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(562949953421311);char b[160];wchar_t wide[160];
 if((raw>>49)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(562949953421311))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x6039006fU: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(562949953421311);char b[160];wchar_t wide[160];
 if((raw>>49)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390070U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(562949953421311);char b[160];wchar_t wide[160];
 if((raw>>49)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390071U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(562949953421311);char b[160];wchar_t wide[160];
 if((raw>>49)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(281474976710655)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390073U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x60390074U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(72057594037927935);char b[160];wchar_t wide[160];
 if((raw>>56)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 if(v==UINT64_C(72057594037927935))return xx_data_struct_record_set_comment(r,L"EBML unknown-size sentinel; enclosing boundary determines extent.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT: decoded payload length %llu bytes; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390075U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(72057594037927935);char b[160];wchar_t wide[160];
 if((raw>>56)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390076U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(72057594037927935);char b[160];wchar_t wide[160];
 if((raw>>56)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML VINT decoded value %llu; physical marker retained.",(unsigned long long)v);
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390077U: {uint64_t raw=xx_var_get_u64(&r->value),v=raw&UINT64_C(72057594037927935);char b[160];wchar_t wide[160];
 if((raw>>56)!=1)return xx_data_struct_record_set_comment(r,L"Invalid EBML VINT width marker; physical encoded word retained.");
 xx_rt_snprintf(b,SX_COUNT(b),"EBML lacing: signed frame-size difference %lld bytes.",(long long)((int64_t)v-INT64_C(36028797018963967)));
 for(size_t i=0;i<SX_COUNT(wide);i++){wide[i]=(unsigned char)b[i];if(!b[i])break;}return xx_data_struct_record_set_comment(r,wide);}
 case 0x60390079U:
 if(!xx_rt_wcscmp(r->name,L"relative_offset"))text=L"Relative to Segment data start, except CueRelativePosition relative to its Cluster data start; element ID determines origin.";
 break;
 case 0x6039007dU:
 if(!xx_rt_wcscmp(r->name,L"crc32"))text=L"CRC32 over parent contents except this complete CRC element.";
 break;
 case 0x6039007eU:
 if(!xx_rt_wcscmp(r->name,L"relative_timestamp"))text=L"Signed offset from Cluster timestamp in track ticks.";
 if(!xx_rt_wcscmp(r->name,L"flags"))text=L"Lacing bits1..2:0none,1Xiph,2fixed,3EBML; SimpleBlock bit7keyframe,bit0discardable.";
 break;
 case 0x6039007fU:
 if(!xx_rt_wcscmp(r->name,L"frame_count_minus_one"))text=L"Number of frames minus1; lacing requires at least2frames.";
 break;
 case 0x60390080U:
 if(!xx_rt_wcscmp(r->name,L"size_part"))text=L"Add255 continuations and a terminating byte below255 to obtain one frame size.";
 break;
 case 0x60390081U:
 if(!xx_rt_wcscmp(r->name,L"mmap_offset"))text=L"File-relative offset of the memory-map chunk.";
 break;
 case 0x60390082U:
 if(!xx_rt_wcscmp(r->name,L"first_free_resource_id"))text=L"Minus1 means no free resource.";
 break;
 case 0x60390083U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"Packed four-character resource type.";
 if(!xx_rt_wcscmp(r->name,L"chunk_offset"))text=L"File-relative chunk-header offset.";
 if(!xx_rt_wcscmp(r->name,L"next_free_resource_id"))text=L"Resource index for free entries, flags for special resources.";
 break;
 case 0x60390085U:
 if(!xx_rt_wcscmp(r->name,L"child_type"))text=L"Packed four-character type.";
 break;
 case 0x60390086U:
 if(!xx_rt_wcscmp(r->name,L"mmap_offset"))text=L"File-relative offset of the memory-map chunk.";
 break;
 case 0x60390087U:
 if(!xx_rt_wcscmp(r->name,L"first_free_resource_id"))text=L"Minus1 means no free resource.";
 break;
 case 0x60390088U:
 if(!xx_rt_wcscmp(r->name,L"type"))text=L"Packed four-character resource type.";
 if(!xx_rt_wcscmp(r->name,L"chunk_offset"))text=L"File-relative chunk-header offset.";
 if(!xx_rt_wcscmp(r->name,L"next_free_resource_id"))text=L"Resource index for free entries, flags for special resources.";
 break;
 case 0x6039008aU:
 if(!xx_rt_wcscmp(r->name,L"child_type"))text=L"Packed four-character type.";
 break;
 case 0x6039008bU:
 if(!xx_rt_wcscmp(r->name,L"cast_resource_index"))text=L"Cast-list indices are stored big-endian independently of container byte order.";
 break;
 default:break;}
 return !text||xx_data_struct_record_set_comment(r,text);
}
#define SXVT_LIMIT 20000U
bool sxvt_span(sx_context*c,uint64_t p,uint64_t n){return c->size>=0&&p<=(uint64_t)c->size&&n<=(uint64_t)c->size-p;}
bool sxvt_read(sx_context*c,uint64_t p,void*b,size_t n){return sxvt_span(c,p,n)&&sx_read(c,(int64_t)p,b,n);}
uint64_t sxvt_uint(const uint8_t*b,unsigned n,bool be){uint64_t v=0;for(unsigned i=0;i<n;i++)v|=(uint64_t)b[i]<<(8*(be?n-1-i:i));return v;}
bool sxvt_word(sx_context*c,uint64_t p,unsigned n,bool be,uint64_t*v){uint8_t b[8];if(!n||n>8||!sxvt_read(c,p,b,n))return false;*v=sxvt_uint(b,n,be);return true;}
bool sxvt_add(sx_context*c,const sx_layout*l,uint64_t p){const xx_data_struct_field_desc*f=&l->fields[l->field_count-1];int64_t n=f->rel_offset+f->size;return c->count<SXVT_LIMIT&&sxvt_span(c,p,(uint64_t)n)&&sx_add(c,l,(int64_t)p,n);}
bool sxvt_byte(sx_context*c,uint64_t p,uint8_t*v){return sxvt_read(c,p,v,1);}
static int sxvt_order(const void*a,const void*b){const xx_data_struct*x=a,*y=b;return x->offset<y->offset?-1:x->offset>y->offset?1:0;}
static bool sxvt_finish(sx_context*c){size_t n=c->count;int64_t end=0;xx_rt_qsort(c->items,n,sizeof(*c->items),sxvt_order);for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+c->items[i].total_size;}if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxvt_order);return !c->failed;}
static bool sx_videotail_supports(xx_file_type_t type){switch(type){case XX_FILE_TYPE_GRASP:case XX_FILE_TYPE_SWF:case XX_FILE_TYPE_MP4:case XX_FILE_TYPE_MATROSKA:case XX_FILE_TYPE_ADOBE_DIRECTOR_CXT:return true;default:return false;}}
static bool sx_videotail_build(sx_context*c){if(!c||!c->f||c->size<0||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;bool ok=false;switch(c->f->file_type){case XX_FILE_TYPE_GRASP:ok=sx_grasp_build(c);break;case XX_FILE_TYPE_SWF:ok=sx_swf_build(c);break;case XX_FILE_TYPE_MP4:ok=sx_mp4_build(c);break;case XX_FILE_TYPE_MATROSKA:ok=sx_matroska_build(c);break;case XX_FILE_TYPE_ADOBE_DIRECTOR_CXT:ok=sx_adobe_director_cxt_build(c);break;default:break;}/* Optional damaged/capped metadata remains raw; keep already framed records. */(void)ok;return c->count&&sxvt_finish(c);}
const sx_family sx_videotail_family={sx_videotail_supports,sx_videotail_build,sx_videotail_layouts,SX_COUNT(sx_videotail_layouts),sx_videotail_comment};
