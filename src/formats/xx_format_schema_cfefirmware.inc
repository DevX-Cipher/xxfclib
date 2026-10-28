/* Original Broadcom cfe_flashimage.h, mkflashimage.c and ui_flash.c. */
static const xx_data_struct_field_desc sxcfefw_header_fields[]={
 SX_FIELD("seal","uint8[4]",0,4,SX_SIGNATURE),
 SX_FIELD("flags","uint32",4,4,SX_FLAGS),
 SX_FIELD("payload_size","uint32",8,4,SX_SIZE),
 SX_FIELD("payload_crc32","uint32",12,4,SX_CHECKSUM),
 SX_FIELD("board_name","char[32]",16,32,SX_STRING),
 SX_FIELD("major_version","uint8",48,1,SX_NONE),
 SX_FIELD("minor_version","uint8",49,1,SX_NONE),
 SX_FIELD("eco_version","uint8",50,1,SX_NONE),
 SX_FIELD("misc_version","uint8",51,1,SX_NONE),
 SX_FIELD("reserved","uint8[12]",52,12,SX_RESERVED),
};
static const sx_layout sxcfefw_header={UINT32_C(0x609f0001),"cfe_flash_update_header",sxcfefw_header_fields,SX_COUNT(sxcfefw_header_fields),SX_BE};
static const sx_layout*const sx_cfefirmware_layouts[]={&sxcfefw_header};
static uint32_t sxcfefw_be32(const uint8_t*p){return((uint32_t)p[0]<<24)|((uint32_t)p[1]<<16)|((uint32_t)p[2]<<8)|p[3];}
static bool sx_cfefirmware_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_CFE:return true;default:return false;}}
static bool sxcfefw_update(sx_context*c){
 uint8_t h[64],b[8192];uint32_t crc=0;uint64_t done=0;bool terminated=false;
 if(c->size<64||!sx_read(c,0,h,64)||xx_rt_memcmp(h,"CFE1",4))return false;
 uint32_t n=sxcfefw_be32(h+8);if(!n||n>UINT32_C(67108864)||(uint64_t)n>(uint64_t)c->size-64)return false;
 for(unsigned i=16;i<48;i++)if(!h[i])terminated=true;if(!terminated)return false;
 while(done<n){size_t z=(uint64_t)n-done>sizeof(b)?sizeof(b):(size_t)((uint64_t)n-done);if(xx_pd_is_stopped(c->pd)||!sx_read(c,64+(int64_t)done,b,z))return false;crc=xx_crc32_calc(crc,b,z);done+=z;}
 if(~crc!=sxcfefw_be32(h+12))return false;
 return sx_add(c,&sxcfefw_header,0,64)&&sx_raw(c,64,c->size-64);
}
/* The pre-existing native ROM identity has no authenticated update-envelope
   members. Preserve its physical bytes as the ordinary raw view. */
static bool sx_cfefirmware_build(sx_context*c){
 if(sxcfefw_update(c))return true;
 if(c->failed||xx_pd_is_stopped(c->pd))return false;
 uint8_t seal[8];
 return c->size>=36&&sx_read(c,28,seal,8)&&!xx_rt_memcmp(seal,"CFE1CFE1",8)&&sx_raw(c,0,c->size);
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
