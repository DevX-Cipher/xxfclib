/* Panorama byte-preserving XOR fields. Every value is stored ciphertext, not a decoded numeric value. */
static const xx_data_struct_field_desc sxpano_signature_fields[]={
 SX_FIELD("encoded_rar4_signature","uint8[7]",0,7,SX_NONE),
};
static const sx_layout sxpano_signature={UINT32_C(0x60970001),"panorama_rar4_signature",sxpano_signature_fields,SX_COUNT(sxpano_signature_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_base_header_fields[]={
 SX_FIELD("encoded_header_crc","uint8[2]",0,2,SX_NONE),
 SX_FIELD("encoded_header_type","uint8[1]",2,1,SX_NONE),
 SX_FIELD("encoded_header_flags","uint8[2]",3,2,SX_NONE),
 SX_FIELD("encoded_header_size","uint8[2]",5,2,SX_NONE),
};
static const sx_layout sxpano_base_header={UINT32_C(0x60970002),"panorama_rar4_base_header",sxpano_base_header_fields,SX_COUNT(sxpano_base_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_main_header_fields[]={
 SX_FIELD("encoded_header_crc","uint8[2]",0,2,SX_NONE),
 SX_FIELD("encoded_header_type","uint8[1]",2,1,SX_NONE),
 SX_FIELD("encoded_header_flags","uint8[2]",3,2,SX_NONE),
 SX_FIELD("encoded_header_size","uint8[2]",5,2,SX_NONE),
 SX_FIELD("encoded_authenticity_offset_high","uint8[2]",7,2,SX_NONE),
 SX_FIELD("encoded_authenticity_offset_low","uint8[4]",9,4,SX_NONE),
};
static const sx_layout sxpano_main_header={UINT32_C(0x60970003),"panorama_rar4_main_header",sxpano_main_header_fields,SX_COUNT(sxpano_main_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_file_header_fields[]={
 SX_FIELD("encoded_header_crc","uint8[2]",0,2,SX_NONE),
 SX_FIELD("encoded_header_type","uint8[1]",2,1,SX_NONE),
 SX_FIELD("encoded_header_flags","uint8[2]",3,2,SX_NONE),
 SX_FIELD("encoded_header_size","uint8[2]",5,2,SX_NONE),
 SX_FIELD("encoded_packed_size_low","uint8[4]",7,4,SX_NONE),
 SX_FIELD("encoded_unpacked_size_low","uint8[4]",11,4,SX_NONE),
 SX_FIELD("encoded_host_os","uint8[1]",15,1,SX_NONE),
 SX_FIELD("encoded_file_crc","uint8[4]",16,4,SX_NONE),
 SX_FIELD("encoded_dos_file_time","uint8[4]",20,4,SX_NONE),
 SX_FIELD("encoded_unpack_version","uint8[1]",24,1,SX_NONE),
 SX_FIELD("encoded_compression_method","uint8[1]",25,1,SX_NONE),
 SX_FIELD("encoded_name_size","uint8[2]",26,2,SX_NONE),
 SX_FIELD("encoded_attributes","uint8[4]",28,4,SX_NONE),
};
static const sx_layout sxpano_file_header={UINT32_C(0x60970004),"panorama_rar4_file_header",sxpano_file_header_fields,SX_COUNT(sxpano_file_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_large_sizes_fields[]={
 SX_FIELD("encoded_packed_size_high","uint8[4]",0,4,SX_NONE),
 SX_FIELD("encoded_unpacked_size_high","uint8[4]",4,4,SX_NONE),
};
static const sx_layout sxpano_large_sizes={UINT32_C(0x60970005),"panorama_rar4_large_sizes",sxpano_large_sizes_fields,SX_COUNT(sxpano_large_sizes_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_file_name_fields[]={
 SX_FIELD("encoded_file_name","uint8",0,0,SX_NONE),
};
static const sx_layout sxpano_file_name={UINT32_C(0x60970006),"panorama_rar4_file_name",sxpano_file_name_fields,SX_COUNT(sxpano_file_name_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_salt_fields[]={
 SX_FIELD("encoded_salt","uint8[8]",0,8,SX_NONE),
};
static const sx_layout sxpano_salt={UINT32_C(0x60970007),"panorama_rar4_salt",sxpano_salt_fields,SX_COUNT(sxpano_salt_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_long_block_size_fields[]={
 SX_FIELD("encoded_data_size","uint8[4]",0,4,SX_NONE),
};
static const sx_layout sxpano_long_block_size={UINT32_C(0x60970008),"panorama_rar4_long_block_size",sxpano_long_block_size_fields,SX_COUNT(sxpano_long_block_size_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_end_data_crc_fields[]={
 SX_FIELD("encoded_archive_data_crc","uint8[4]",0,4,SX_NONE),
};
static const sx_layout sxpano_end_data_crc={UINT32_C(0x60970009),"panorama_rar4_end_data_crc",sxpano_end_data_crc_fields,SX_COUNT(sxpano_end_data_crc_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_end_volume_fields[]={
 SX_FIELD("encoded_volume_number","uint8[2]",0,2,SX_NONE),
};
static const sx_layout sxpano_end_volume={UINT32_C(0x6097000a),"panorama_rar4_end_volume",sxpano_end_volume_fields,SX_COUNT(sxpano_end_volume_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_comment_header_fields[]={
 SX_FIELD("encoded_header_crc","uint8[2]",0,2,SX_NONE),
 SX_FIELD("encoded_header_type","uint8[1]",2,1,SX_NONE),
 SX_FIELD("encoded_header_flags","uint8[2]",3,2,SX_NONE),
 SX_FIELD("encoded_header_size","uint8[2]",5,2,SX_NONE),
 SX_FIELD("encoded_unpacked_size","uint8[2]",7,2,SX_NONE),
 SX_FIELD("encoded_unpack_version","uint8[1]",9,1,SX_NONE),
 SX_FIELD("encoded_compression_method","uint8[1]",10,1,SX_NONE),
 SX_FIELD("encoded_comment_crc","uint8[2]",11,2,SX_NONE),
};
static const sx_layout sxpano_comment_header={UINT32_C(0x6097000b),"panorama_rar4_comment_header",sxpano_comment_header_fields,SX_COUNT(sxpano_comment_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_old_service_header_fields[]={
 SX_FIELD("encoded_header_crc","uint8[2]",0,2,SX_NONE),
 SX_FIELD("encoded_header_type","uint8[1]",2,1,SX_NONE),
 SX_FIELD("encoded_header_flags","uint8[2]",3,2,SX_NONE),
 SX_FIELD("encoded_header_size","uint8[2]",5,2,SX_NONE),
 SX_FIELD("encoded_data_size","uint8[4]",7,4,SX_NONE),
 SX_FIELD("encoded_subtype","uint8[2]",11,2,SX_NONE),
 SX_FIELD("encoded_level","uint8[1]",13,1,SX_NONE),
};
static const sx_layout sxpano_old_service_header={UINT32_C(0x6097000c),"panorama_rar4_old_service_header",sxpano_old_service_header_fields,SX_COUNT(sxpano_old_service_header_fields),SX_LE};
static const xx_data_struct_field_desc sxpano_recovery_header_fields[]={
 SX_FIELD("encoded_header_crc","uint8[2]",0,2,SX_NONE),
 SX_FIELD("encoded_header_type","uint8[1]",2,1,SX_NONE),
 SX_FIELD("encoded_header_flags","uint8[2]",3,2,SX_NONE),
 SX_FIELD("encoded_header_size","uint8[2]",5,2,SX_NONE),
 SX_FIELD("encoded_data_size","uint8[4]",7,4,SX_NONE),
 SX_FIELD("encoded_version","uint8[1]",11,1,SX_NONE),
 SX_FIELD("encoded_recovery_sectors","uint8[2]",12,2,SX_NONE),
 SX_FIELD("encoded_total_blocks","uint8[4]",14,4,SX_NONE),
 SX_FIELD("encoded_mark","uint8[8]",18,8,SX_NONE),
};
static const sx_layout sxpano_recovery_header={UINT32_C(0x6097000d),"panorama_rar4_recovery_header",sxpano_recovery_header_fields,SX_COUNT(sxpano_recovery_header_fields),SX_LE};
static const sx_layout*const sx_panorama_layouts[]={&sxpano_signature,&sxpano_base_header,&sxpano_main_header,&sxpano_file_header,&sxpano_large_sizes,&sxpano_file_name,&sxpano_salt,&sxpano_long_block_size,&sxpano_end_data_crc,&sxpano_end_volume,&sxpano_comment_header,&sxpano_old_service_header,&sxpano_recovery_header};
typedef struct sxpano_view{sx_context*c;uint8_t pad[1024];uint64_t work;}sxpano_view;
static bool sxpano_read(sxpano_view*v,uint64_t p,void*out,size_t n){
 if(v->work>UINT64_C(16777216)||n>UINT64_C(16777216)-v->work||p>(uint64_t)v->c->size||n>(uint64_t)v->c->size-p||!sx_read(v->c,(int64_t)p,out,n))return false;
 v->work+=n;uint8_t*b=out;for(size_t i=0;i<n;i++)b[i]^=v->pad[(p+i)&1023];return true;
}
static uint16_t sxpano_u16(const uint8_t*b){return(uint16_t)((uint16_t)b[0]|((uint16_t)b[1]<<8));}
static uint32_t sxpano_u32(const uint8_t*b){return(uint32_t)b[0]|((uint32_t)b[1]<<8)|((uint32_t)b[2]<<16)|((uint32_t)b[3]<<24);}
static bool sxpano_crc(sxpano_view*v,uint64_t p,uint64_t n,uint16_t expected){
 uint8_t b[512];uint32_t crc=UINT32_MAX;
 while(n){size_t z=n<sizeof(b)?(size_t)n:sizeof(b);if(!sxpano_read(v,p,b,z))return false;for(size_t i=0;i<z;i++){crc^=b[i];for(unsigned j=0;j<8;j++)crc=(crc>>1)^((0-(crc&1))&UINT32_C(0xedb88320));}p+=z;n-=z;}
 return(uint16_t)(crc^UINT32_MAX)==expected;
}
/* ReadHeader15's consumed file prefix excludes an embedded legacy comment.
 * Service subdata precedes salt; it is not a filename or a salt byte range. */
static bool sxpano_file_prefix(sxpano_view*v,uint64_t p,const uint8_t*h,unsigned type,uint16_t flags,uint16_t hs,uint64_t*salt,uint64_t*used){
 uint64_t q=32+((flags&0x100)?8:0),name=sxpano_u16(h+26);*salt=0;
 if(q>hs||name>hs-q)return false;q+=name;
 if(type==0x7a){uint64_t extra=hs-32-name;if(flags&0x400){if(extra<8)return false;extra-=8;}if(extra>hs-q)return false;q+=extra;}
 if(flags&0x400){if(8>hs-q)return false;*salt=q;q+=8;}
 if(flags&0x1000){uint8_t b[2];if(2>hs-q||!sxpano_read(v,p+q,b,2))return false;q+=2;unsigned timeflags=sxpano_u16(b);
  /* UnRAR does not consume the fourth/archive-time nibble. */
  for(unsigned i=0;i<3;i++){unsigned mode=timeflags>>((3-i)*4);if(mode&8){unsigned z=(i?4:0)+(mode&3);if(z>hs-q)return false;q+=z;}}
 }
 *used=q;return true;
}
static bool sxpano_put(sxpano_view*v,const sx_layout*l,uint64_t p,uint64_t n){return v->c->count<20000&&p<=(uint64_t)v->c->size&&n<=(uint64_t)v->c->size-p&&sx_add(v->c,l,(int64_t)p,(int64_t)n);}
static int sxpano_order(const void*aa,const void*bb){const xx_data_struct*a=aa,*b=bb;return a->offset<b->offset?-1:a->offset>b->offset?1:0;}
static bool sxpano_finish(sx_context*c){size_t n=c->count;int64_t end=0;if(!n)return false;
 for(size_t i=0;i<n;i++){int64_t p=c->items[i].offset-c->f->base_address,z=c->items[i].total_size;if(p<end)return false;if(p>end&&!sx_raw(c,end,p-end))return false;end=p+z;}
 if(end<c->size&&!sx_raw(c,end,c->size-end))return false;xx_rt_qsort(c->items,c->count,sizeof(*c->items),sxpano_order);return !c->failed&&!xx_pd_is_stopped(c->pd);
}
static bool sx_panorama_supports(xx_file_type_t t){switch(t){case XX_FILE_TYPE_PANORAMA:return true;default:return false;}}
static bool sx_panorama_build(sx_context*c){
 if(!c||!c->f||c->f->file_type!=XX_FILE_TYPE_PANORAMA||c->size<32||(!c->f->base_info_handled&&!xx_format_handle_base_info(c->f,c->pd))||!c->f->is_valid)return false;
 uint8_t h[40];if(!sx_read(c,0,h,8))return false;uint32_t seed=sxpano_u32(h)^UINT32_C(0x21726152);if(!seed||((sxpano_u32(h+4)^(seed*UINT32_C(0x08088405)))&UINT32_C(0xffffff))!=UINT32_C(0x071a))return false;
 sxpano_view v={0};v.c=c;uint32_t x=seed;for(unsigned i=0;i<256;i++){for(unsigned j=0;j<4;j++)v.pad[i*4+j]=(uint8_t)(x>>(j*8));x*=UINT32_C(0x08088405);}
 uint64_t p=7;bool first=true;
 while(p<(uint64_t)c->size&&c->count<20000&&!xx_pd_is_stopped(c->pd)){
  if(!sxpano_read(&v,p,h,7))break;unsigned type=h[2];uint16_t flags=sxpano_u16(h+3),hs=sxpano_u16(h+5);uint64_t data=0;
  if(type<0x73||type>0x7b||hs<7||hs>(uint64_t)c->size-p||(first&&(type!=0x73||hs<13)))break;
  unsigned fixed=(type==0x73)?13:(type==0x74||type==0x7a)?32:(type==0x75)?13:(type==0x77)?14:(type==0x78)?26:7;
  if(hs<fixed||!sxpano_read(&v,p,h,fixed))break;
  if(flags&0x8000){uint8_t b[4];if(hs<11||!sxpano_read(&v,p+7,b,4))break;data=sxpano_u32(b);}
  if((type==0x74||type==0x7a)&&(flags&0x100)){uint8_t b[8];if(hs<40||!sxpano_read(&v,p+32,b,8))break;data|=(uint64_t)sxpano_u32(b)<<32;}
  if(data>(uint64_t)c->size-p-hs)break;
  /* Legacy embedded comment headers cover their fixed prefix, as UnRAR's
     ReadHeader15 reads only13 bytes for these specific forms. */
  uint64_t crc_size=(type==0x75||(type==0x73&&(flags&2)))?13:hs,salt=0,prefix=0;
  bool fileprefix=(type==0x74||type==0x7a)&&sxpano_file_prefix(&v,p,h,type,flags,hs,&salt,&prefix);
  if((type==0x74||type==0x7a)&&(flags&8)){if(!fileprefix)break;crc_size=prefix;}
  if(!sxpano_crc(&v,p+2,crc_size-2,sxpano_u16(h)))break;
  if(first){if(!sxpano_put(&v,&sxpano_signature,0,7))break;first=false;}
  const sx_layout*l=type==0x73?&sxpano_main_header:(type==0x74||type==0x7a)?&sxpano_file_header:type==0x75?&sxpano_comment_header:type==0x77?&sxpano_old_service_header:type==0x78?&sxpano_recovery_header:&sxpano_base_header;
  if(!sxpano_put(&v,l,p,fixed))break;
  if(type==0x74||type==0x7a){
   uint64_t q=p+32;if(flags&0x100){if(!sxpano_put(&v,&sxpano_large_sizes,q,8))break;q+=8;}
   uint16_t name=sxpano_u16(h+26);if(name<=(p+hs)-q){if(name&&name<=4096&&!sxpano_put(&v,&sxpano_file_name,q,name))break;if(fileprefix&&salt&&!sxpano_put(&v,&sxpano_salt,p+salt,8))break;}
  }else if(type==0x7b){uint64_t q=p+7;if(flags&2){if(4>(p+hs)-q)break;if(!sxpano_put(&v,&sxpano_end_data_crc,q,4))break;q+=4;}if(flags&8){if(2>(p+hs)-q)break;if(!sxpano_put(&v,&sxpano_end_volume,q,2))break;}}
  else if(fixed==7&&(flags&0x8000)&&!sxpano_put(&v,&sxpano_long_block_size,p+7,4))break;
  p+=hs+data;if(type==0x7b||(type==0x73&&(flags&0x80)))break;
 }
 return sxpano_finish(c);
}
static bool sx_panorama_comment(xx_data_struct_record*r,uint32_t id){
 if((id&UINT32_C(0xffff0000))!=UINT32_C(0x60970000))return true;
 if(!r)return false;
 return xx_data_struct_record_set_comment(r,L"Physical Panorama XOR ciphertext bytes for the named RAR4 field. These are encoded bytes, not the decoded numeric/string value. The byte-preserving stream transform identifies the span; no decompressed-member coordinates are used.");
}
