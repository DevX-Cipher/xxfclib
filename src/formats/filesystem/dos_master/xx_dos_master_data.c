/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * DOS_MASTER data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

static bool sxdt_master(sx_context*c){/* Only real parent ProDOS metadata is exposed. The native configured profile
 determines embedded DOS sizes; no subclass state is read or guessed here. */sxdt_view v={c,0,(uint64_t)c->size,0};return sxdt_av_prodos(&v);}
bool sx_dos_master_build(sx_context*c)
{
bool ok=false;
ok=sxdt_master(c);
return ok&&c->count&&sxdt_finish(c);
}
