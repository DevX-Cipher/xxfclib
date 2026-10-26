/* Original Broadcom cfe_flashimage.h, mkflashimage.c and ui_flash.c. */
#include "xx_format_schema.h"
#include "xx_format_schema_internal.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#include "xxfclib/algo/crc/xx_crc.h"
#include "xx_format_schema_cfefirmware.h"

static const sx_layout*const sx_cfefirmware_layouts[]={&sxcfefw_header};
static bool sx_cfefirmware_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_CFE:return true;default:return false;}}
/* The pre-existing native ROM identity has no authenticated update-envelope
   members. Preserve its physical bytes as the ordinary raw view. */
static bool sx_cfefirmware_build(sx_context*c){
 return sx_cfe_build(c);
}
static bool sx_cfefirmware_comment(xx_data_struct_record*r,uint32_t id){
 if(id!=UINT32_C(0x609f0001)||!r||!r->name)return true;
 const wchar_t*n=r->name;
 if(!xx_rt_wcscmp(n,L"seal"))return xx_data_struct_record_set_comment(r,L"Original Broadcom flash-update envelope marker CFE1; distinct from the opaque ROM entry-point seal.");
 if(!xx_rt_wcscmp(n,L"flags"))return xx_data_struct_record_set_comment(r,L"Payload CPU flags: bit0 big-endian image, bit1 little-endian image, bit2 64-bit-long build. Both endian bits mark the concatenated bi-endian payload; these header words always use big-endian byte order.");
 if(!xx_rt_wcscmp(n,L"payload_size"))return xx_data_struct_record_set_comment(r,L"Firmware payload bytes following the 64-byte update envelope; excludes this header and any trailing overlay.");
 if(!xx_rt_wcscmp(n,L"payload_crc32"))return xx_data_struct_record_set_comment(r,L"Stored CRC of payload bytes only: reflected polynomial 0xEDB88320, initial 0xFFFFFFFF, no final complement. The header bytes are not covered.");
 if(!xx_rt_wcscmp(n,L"board_name"))return xx_data_struct_record_set_comment(r,L"Target board identifier in a fixed 32-byte ASCIIZ slot. Parsing does not establish compatibility with the current hardware.");
 if(!xx_rt_wcscmp(n,L"major_version")||!xx_rt_wcscmp(n,L"minor_version")||!xx_rt_wcscmp(n,L"eco_version"))return xx_data_struct_record_set_comment(r,L"One stored firmware version component, written from mkflashimage's major.minor.eco option.");
 if(!xx_rt_wcscmp(n,L"misc_version"))return xx_data_struct_record_set_comment(r,L"Fourth stored firmware-version byte; original mkflashimage writes zero.");
 if(!xx_rt_wcscmp(n,L"reserved"))return xx_data_struct_record_set_comment(r,L"Twelve bytes reserved by the original Broadcom update-header declaration; the original writer clears them.");
 return true;
}
const sx_family sx_cfefirmware_family={sx_cfefirmware_supports,sx_cfefirmware_build,sx_cfefirmware_layouts,SX_COUNT(sx_cfefirmware_layouts),sx_cfefirmware_comment};
