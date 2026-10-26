/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * QUAD data structures, moved out of the archivequad schema family. */
#include "../../xx_format_schema_archivequad.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

bool sx_quad_build(sx_context*c)
{
 uint32_t size;
 if(c->size<9||!sx_u32(c,0,false,&size)||size>UINT32_C(67108864))return false;
 return sx_add(c,&sxquad_header,0,4)&&sx_raw(c,4,c->size-4);
}
