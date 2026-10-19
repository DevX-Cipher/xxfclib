/* Private sorting implementation from src/formats/chm/xx_chm.c. */

/* ---------------------------------------------------------------------- */
/* Records                                                                 */

/* Folders first in directory order, then files by section and offset, so
 * that consecutive members share decoded LZX groups. */
static bool chm_record_before(const chm_context *context, const chm_record *a, const chm_record *b)
{
    const chm_entry *x = &context->entries[a->entry];
    const chm_entry *y = &context->entries[b->entry];
    if (a->folder != b->folder) return a->folder;
    if (!a->folder) {
        if (x->section != y->section) return x->section < y->section;
        if (x->offset != y->offset) return x->offset < y->offset;
        if (x->size != y->size) return x->size < y->size;
    }
    return a->entry < b->entry;
}

static bool chm_sort_records(chm_context *context)
{
    size_t count = context->record_count, width, left;
    chm_record *temp, *source = context->records, *target;
    if (count < 2U) return true;
    temp = (chm_record *)xx_mem_alloc(count * sizeof(*temp));
    if (!temp) return false;
    target = temp;
    for (width = 1U; width < count; width *= 2U) {
        for (left = 0U; left < count; left += 2U * width) {
            size_t middle = left + width < count ? left + width : count;
            size_t right = middle + width < count ? middle + width : count;
            size_t i = left, j = middle, k = left;
            while (i < middle && j < right) target[k++] = chm_record_before(context, &source[j], &source[i]) ? source[j++] : source[i++];
            while (i < middle) target[k++] = source[i++];
            while (j < right) target[k++] = source[j++];
        }
        {
            chm_record *swap = source;
            source = target;
            target = swap;
        }
    }
    if (source != context->records) xx_rt_memcpy(context->records, source, count * sizeof(*source));
    xx_mem_free(temp);
    return true;
}
