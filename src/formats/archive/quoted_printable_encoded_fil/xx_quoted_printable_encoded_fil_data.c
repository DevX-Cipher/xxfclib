/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * Quoted-printable data structures, moved out of the archivetransport schema family. */
#include "../../xx_format_schema_archivetransport.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

static const xx_data_struct_field_desc sxatp_transport_line_end_fields[]={
 SX_FIELD("line_ending","uint8",0,0,SX_NONE),
};
const sx_layout sxatp_transport_line_end={UINT32_C(0x60890074),"transport_line_end",sxatp_transport_line_end_fields,SX_COUNT(sxatp_transport_line_end_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_qp_literal_run_fields[]={
 SX_FIELD("literal_bytes","uint8",0,0,SX_NONE),
};
const sx_layout sxatp_qp_literal_run={UINT32_C(0x60890076),"qp_literal_run",sxatp_qp_literal_run_fields,SX_COUNT(sxatp_qp_literal_run_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_qp_hex_escape_fields[]={
 SX_FIELD("escape_marker","char[1]",0,1,SX_NONE),
 SX_FIELD("encoded_octet","ascii_hex[2]",1,2,SX_NONE),
};
const sx_layout sxatp_qp_hex_escape={UINT32_C(0x60890077),"qp_hex_escape",sxatp_qp_hex_escape_fields,SX_COUNT(sxatp_qp_hex_escape_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_qp_soft_break_fields[]={
 SX_FIELD("soft_line_break","uint8",0,0,SX_NONE),
};
const sx_layout sxatp_qp_soft_break={UINT32_C(0x60890078),"qp_soft_break",sxatp_qp_soft_break_fields,SX_COUNT(sxatp_qp_soft_break_fields),SX_LE};
static const xx_data_struct_field_desc sxatp_qp_padding_fields[]={
 SX_FIELD("padding","uint8",0,0,SX_NONE),
};
const sx_layout sxatp_qp_padding={UINT32_C(0x60890079),"qp_padding",sxatp_qp_padding_fields,SX_COUNT(sxatp_qp_padding_fields),SX_LE};
static bool sxatp_hex(uint8_t x){return(x>='0'&&x<='9')||(x>='A'&&x<='F')||(x>='a'&&x<='f');}
static bool sxatp_qp(sx_context*c){uint64_t p=0;while(p<(uint64_t)c->size&&c->count<SXATP_LIMIT){uint8_t b[3];if(!sxatp_read(c,p,b,1))return false;uint64_t q=p+1;const sx_layout*l=&sxatp_qp_literal_run;if(b[0]=='='){if(q==(uint64_t)c->size)l=&sxatp_qp_soft_break;else{if(!sxatp_read(c,q,b+1,1))return false;if(b[1]=='\n')q++,l=&sxatp_qp_soft_break;else if(b[1]=='\r'&&sxatp_read(c,q+1,b+2,1)&&b[2]=='\n')q+=2,l=&sxatp_qp_soft_break;else if(sxatp_hex(b[1])&&sxatp_read(c,q+1,b+2,1)&&sxatp_hex(b[2])){if(!sxatp_add(c,&sxatp_qp_hex_escape,p))return false;p+=3;continue;}else return false;}}
 else if(b[0]=='\r'||b[0]=='\n'){l=&sxatp_transport_line_end;if(b[0]=='\r'&&q<(uint64_t)c->size&&sxatp_read(c,q,b+1,1)&&b[1]=='\n')q++;}
 else if(!b[0]||b[0]==26){l=&sxatp_qp_padding;while(q<(uint64_t)c->size&&q-p<4096){uint8_t x;if(!sxatp_read(c,q,&x,1))return false;if(x&&x!=26)break;q++;}}
 else{while(q<(uint64_t)c->size&&q-p<4096){uint8_t x;if(!sxatp_read(c,q,&x,1))return false;if(x=='='||x=='\r'||x=='\n'||!x||x==26)break;q++;}}
 if(!sxatp_text(c,l,p,q-p,false))return false;p=q;}return true;}
bool sx_quoted_printable_encoded_fil_build(sx_context*c)
{
 return sxatp_qp(c);
}
