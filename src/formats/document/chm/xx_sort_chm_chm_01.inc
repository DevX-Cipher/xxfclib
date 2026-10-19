/* Private sorting implementation from src/formats/document/chm/xx_chm.c. */

/* ---------------------------------------------------------------------- */
/* Records                                                                 */

/* Folders first in directory order, then files by section and offset, so
 * that consecutive members share decoded LZX groups. An xx_sort_callback;
 * context is the chm_context. */
static int chm_record_compare(const void *left, const void *right, void *context)
{
    const chm_context *chm = (const chm_context *)context;
    const chm_record *a = (const chm_record *)left;
    const chm_record *b = (const chm_record *)right;
    const chm_entry *x = &chm->entries[a->entry];
    const chm_entry *y = &chm->entries[b->entry];
    if (a->folder != b->folder) return a->folder ? -1 : 1;
    if (!a->folder) {
        if (x->section != y->section) return x->section < y->section ? -1 : 1;
        if (x->offset != y->offset) return x->offset < y->offset ? -1 : 1;
        if (x->size != y->size) return x->size < y->size ? -1 : 1;
    }
    return a->entry < b->entry ? -1 : (a->entry > b->entry ? 1 : 0);
}

/* Stable, as the merge sort this replaced was, so the order is unchanged. */
static bool chm_sort_records(chm_context *context)
{
    xx_sort_stable_context(context->records, context->record_count, sizeof(*context->records), chm_record_compare, context);
    return true;
}
