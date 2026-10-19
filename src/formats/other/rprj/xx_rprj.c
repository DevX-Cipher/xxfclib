/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#include "xxfclib/formats/other/rprj/xx_rprj.h"
#include "../../common/xx_memory_blob.h"

static bool pm_parse(Abstractformat *format, pm_stream *stream, xx_pd_struct *pd)
{
    memory_blob blob;
    xx_rprj *reader = (xx_rprj *)format;
    uint32_t version;
    bool ok = false;

    if (!blob_load(format, &blob, pd)) return false;
    BLOB_NEED(blob_span(&blob, 0, 8) && !xx_rt_memcmp(blob.p, "RPRJ", 4));
    /* Radare projects only reserve the trailing dword as version metadata.
     * Requiring the current value here would make older and newer projects
     * indistinguishable from truncated input. */
    version = xx_data_get_u32(blob.p + 4, 4, 0, false);
    BLOB_NEED(blob_add(format, stream, &blob, "project-header", 0, 8));
    if (blob.n > 8) BLOB_NEED(blob_add(format, stream, &blob, "project-data", 8, blob.n - 8));
    reader->version = version;
    stream->size = (int64_t)blob.n;
    ok = true;
done:
    xx_mem_free(blob.p);
    return ok;
}

void xx_rprj_init(xx_rprj *reader, xx_io_device *device, int64_t base_address)
{
    if (reader) {
        xx_mem_zero(reader, sizeof(*reader));
        pm_init(&reader->format, device, base_address, XX_FILE_TYPE_RPRJ, "rprj");
    }
}

xx_rprj *xx_rprj_create(xx_io_device *device, int64_t base_address)
{
    xx_rprj *reader = (xx_rprj *)xx_mem_alloc(sizeof(*reader));
    if (reader) xx_rprj_init(reader, device, base_address);
    return reader;
}

void xx_rprj_destroy(xx_rprj *reader)
{
    if (reader) xx_format_cleanup_extra_parameters(&reader->format);
}

void xx_rprj_free(xx_rprj *reader)
{
    if (reader) {
        xx_rprj_destroy(reader);
        xx_mem_free(reader);
    }
}

bool xx_rprj_check_is_valid(Abstractformat *self, xx_pd_struct *pd)
{
    return pm_valid(self, pd);
}

bool xx_rprj_handle_base_info(Abstractformat *self, xx_pd_struct *pd)
{
    return pm_handle(self, pd);
}
