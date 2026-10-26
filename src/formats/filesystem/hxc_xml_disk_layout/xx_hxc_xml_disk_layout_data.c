/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 * HXC_XML_DISK_LAYOUT data structures, moved out of the disktail schema family. */
#include "../../xx_format_schema_disktail.h"
#include "xxfclib/memory/xx_memory.h"
#include "xxfclib/rt/xx_rt.h"
#include <stdio.h>
#include "xxfclib/strings/xx_string.h"
#if SX_ALIAS_READER_FACTORY && defined(CPM)
#include "xxfclib/formats/filesystem/cpm/xx_cpm.h"
#endif

bool sx_hxc_xml_disk_layout_build(sx_context*c)
{
bool ok=false;
ok=sxdt_xml(c,0,(uint64_t)c->size,true);
return ok&&c->count&&sxdt_finish(c);
}
