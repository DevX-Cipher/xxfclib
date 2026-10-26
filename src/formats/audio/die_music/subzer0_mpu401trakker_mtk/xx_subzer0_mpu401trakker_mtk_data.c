/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * SuBZeR0's MPU-401 Trakker Adlib module (.MTK) data structures, moved out of the musicwire schema family. */
#include "../../../xx_format_schema_musicwire.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"

#define MW_ROW(l,at,end) sxmw_row(v,&sxmw_##l,(at),(end))
static bool sxmw_mtk(sxmw_view*v)
{uint64_t end=v->c->size,n;return sxmw_eq(v,0,"mpu401tr\x92kk\xeer@data",18,end)&&sxmw_u(v,20,2,&n,end)&&n>=6085&&MW_ROW(mtk_header,0,end);}
bool sx_subzer0_mpu401trakker_mtk_build(sxmw_view*v)
{
 return sxmw_mtk(v);
}
#undef MW_ROW
