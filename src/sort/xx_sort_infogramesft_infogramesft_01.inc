/* Private sorting implementation from src/formats/infogramesft/xx_infogramesft.c. */

/* Heapsort by (offset, id) ascending.  Both keys matter: the walk takes the
 * FIRST entry for an offset, which has to be the lowest id naming it. */
static bool ipak_slot_less(const ipak_slot *a, const ipak_slot *b)
{
    return a->offset != b->offset ? a->offset < b->offset : a->id < b->id;
}

static void ipak_sift(ipak_slot *slots, size_t start, size_t count)
{
    size_t root = start;
    while (root * 2U + 1U < count) {
        size_t child = root * 2U + 1U;
        ipak_slot swap;
        if (child + 1U < count && ipak_slot_less(&slots[child], &slots[child + 1U])) ++child;
        if (!ipak_slot_less(&slots[root], &slots[child])) return;
        swap = slots[root];
        slots[root] = slots[child];
        slots[child] = swap;
        root = child;
    }
}

static void ipak_sort_slots(ipak_slot *slots, size_t count)
{
    size_t index;
    if (count < 2U) return;
    index = count / 2U;
    while (index != 0U) {
        --index;
        ipak_sift(slots, index, count);
    }
    index = count;
    while (index > 1U) {
        ipak_slot swap = slots[0];
        --index;
        slots[0] = slots[index];
        slots[index] = swap;
        ipak_sift(slots, 0U, index);
    }
}
