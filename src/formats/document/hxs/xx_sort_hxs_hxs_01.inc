/* Private sorting implementation from src/formats/document/hxs/xx_hxs.c. */

/* ---------------------------------------------------------------------- */
/* Records                                                                 */

/* Folders first in directory order, then files by section and offset, so
 * that consecutive members share decoded LZX groups. An xx_sort_callback;
 * context is the hxs_context. */
static int hxs_record_compare(const void *left, const void *right, void *context)
{
    const hxs_context *hxs = (const hxs_context *)context;
    const hxs_record *a = (const hxs_record *)left;
    const hxs_record *b = (const hxs_record *)right;
    const hxs_entry *x = &hxs->entries[a->entry];
    const hxs_entry *y = &hxs->entries[b->entry];
    if (a->folder != b->folder) return a->folder ? -1 : 1;
    if (!a->folder) {
        if (x->section != y->section) return x->section < y->section ? -1 : 1;
        if (x->offset != y->offset) return x->offset < y->offset ? -1 : 1;
        if (x->size != y->size) return x->size < y->size ? -1 : 1;
    }
    return a->entry < b->entry ? -1 : (a->entry > b->entry ? 1 : 0);
}

/* Stable, as the merge sort this replaced was, so the order is unchanged. */
static bool hxs_sort_records(hxs_context *context)
{
    xx_sort_stable_context(context->records, context->record_count, sizeof(*context->records), hxs_record_compare, context);
    return true;
}
