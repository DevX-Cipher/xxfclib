/* Private sorting implementation from src/formats/game/cpk/xx_cpk.c. */

static int cpk_compare_itoc(const void *left, const void *right, void *context)
{
    const cpk_itoc_entry *a = (const cpk_itoc_entry *)left;
    const cpk_itoc_entry *b = (const cpk_itoc_entry *)right;
    (void)context;
    if (a->id != b->id) return a->id < b->id ? -1 : 1;
    return a->order < b->order ? -1 : (a->order > b->order ? 1 : 0);
}
