/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "../../xx_format_extractor_engine.h"
#include "xxfclib/formats/executable/pef/xx_pef.h"

static const xx_file_type_t k_types[] = {XX_FILE_TYPE_PEF};
static const uint8_t k_magic[] = {'J', 'o', 'y', '!', 'p', 'e', 'f', 'f'};
static const xx_format_search_anchor k_anchors[] = {{k_magic, sizeof(k_magic), 0}};

static Abstractformat *open_reader(xx_io_device *device)
{
    xx_pef *reader = xx_pef_create(device, 0);
    return reader ? &reader->format : NULL;
}

static void close_reader(Abstractformat *format)
{
    xx_pef_free((xx_pef *)format);
}

static const xx_format_search_desc k_desc = {k_types, 1U, k_anchors, 1U, open_reader, close_reader, false};

static xx_format_search_state *create_search(xx_format_extractor *self, xx_io_device *device, const xx_list_s *options, xx_pd_struct *pd)
{
    (void)self;
    return xx_format_search_create(&k_desc, device, options, pd);
}

static const xx_format_search_info *current_search(xx_format_extractor *self, xx_format_search_state *state)
{
    (void)self;
    return xx_format_search_current(state);
}

static bool next_search(xx_format_extractor *self, xx_format_search_state *state, xx_pd_struct *pd)
{
    (void)self;
    return xx_format_search_find_next(state, pd);
}

static void free_search(xx_format_extractor *self, xx_format_search_state *state)
{
    (void)self;
    xx_format_search_free(state);
}

xx_format_extractor xx_pef_extractor = {create_search, current_search, next_search, free_search};

/* BEGIN GENERATED ABSTRACT EXTRACTOR */
#include "../../xx_format_abstract_extractor_adapter.h"
XX_FORMAT_DEFINE_ABSTRACT_EXTRACTOR(pef, k_desc)
/* END GENERATED ABSTRACT EXTRACTOR */
