/* Private sorting implementation from src/formats/game/infogramesft/xx_infogramesft.c. */

/* By (offset, id) ascending.  Both keys matter: the walk takes the FIRST
 * entry for an offset, which has to be the lowest id naming it.  Ids are
 * unique, so this is a total order and any sort gives the same result. */
static int ipak_slot_compare(const void *left, const void *right, void *context)
{
    const ipak_slot *a = (const ipak_slot *)left;
    const ipak_slot *b = (const ipak_slot *)right;
    (void)context;
    if (a->offset != b->offset) return a->offset < b->offset ? -1 : 1;
    return a->id < b->id ? -1 : (a->id > b->id ? 1 : 0);
}

static void ipak_sort_slots(ipak_slot *slots, size_t count)
{
    xx_sort_context(slots, count, sizeof(*slots), ipak_slot_compare, NULL);
}
