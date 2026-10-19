/* Private sorting implementation from src/formats/filesystem/dms/xx_dms.c. */

static uint32_t *xx_dms_deep_parent_leaf(xx_dms_deep *deep, uint32_t code)
{
    xx_dms_deep_node *parent = &deep->nodes[deep->nodes[code].parent];
    return (parent->left_leaf == code) ? &parent->left_leaf : &parent->right_leaf;
}

static void xx_dms_deep_swap(uint32_t *left, uint32_t *right)
{
    uint32_t temporary = *left;
    *left = *right;
    *right = temporary;
}

static void xx_dms_deep_update(xx_dms_deep *deep, uint32_t code)
{
    if (!deep || code >= XX_DMS_DEEP_SYMBOLS) return;
    while (code != XX_DMS_DEEP_ROOT) {
        uint32_t index;
        uint32_t dest_index;
        uint32_t frequency;
        ++deep->nodes[code].frequency;
        index = deep->nodes[code].index;
        dest_index = index;
        frequency = deep->nodes[code].frequency;
        while (dest_index != XX_DMS_DEEP_ROOT && frequency > deep->nodes[deep->code_map[dest_index + 1U]].frequency) {
            ++dest_index;
        }
        if (index != dest_index) {
            uint32_t dest_code = deep->code_map[dest_index];
            xx_dms_deep_swap(&deep->nodes[code].index, &deep->nodes[dest_code].index);
            xx_dms_deep_swap(&deep->code_map[index], &deep->code_map[dest_index]);
            /* The parent links must be swapped before the parents are, so
             * that each lookup still resolves against the old parent. */
            xx_dms_deep_swap(xx_dms_deep_parent_leaf(deep, code), xx_dms_deep_parent_leaf(deep, dest_code));
            xx_dms_deep_swap(&deep->nodes[code].parent, &deep->nodes[dest_code].parent);
        }
        code = deep->nodes[code].parent;
        if (code >= XX_DMS_DEEP_NODES) return;
    }
    ++deep->nodes[code].frequency;
}

/* Halve every frequency, rounding up, and rebuild the tree around the new
 * ordering. Called when the root frequency saturates. */
static void xx_dms_deep_halve(xx_dms_deep *deep)
{
    uint32_t index;
    uint32_t slot;
    uint32_t inner;
    uint32_t leaf;
    if (!deep) return;
    for (index = 0U, slot = 0U; index < XX_DMS_DEEP_NODES - 1U && slot < XX_DMS_DEEP_SYMBOLS; ++index) {
        if (deep->code_map[index] < XX_DMS_DEEP_SYMBOLS) {
            deep->nodes[deep->code_map[index]].index = slot++;
        }
    }
    for (index = 0U; index < XX_DMS_DEEP_SYMBOLS; ++index) {
        deep->nodes[index].frequency = (deep->nodes[index].frequency + 1U) >> 1U;
        deep->nodes[index].parent = XX_DMS_DEEP_SYMBOLS + (deep->nodes[index].index >> 1U);
        deep->code_map[deep->nodes[index].index] = index;
    }
    for (inner = XX_DMS_DEEP_SYMBOLS, leaf = 0U; inner < XX_DMS_DEEP_NODES; ++inner, leaf += 2U) {
        uint32_t left = deep->code_map[leaf];
        uint32_t right = deep->code_map[leaf + 1U];
        uint32_t frequency;
        uint32_t position;
        if (left >= XX_DMS_DEEP_NODES || right >= XX_DMS_DEEP_NODES) return;
        frequency = deep->nodes[left].frequency + deep->nodes[right].frequency;
        deep->nodes[inner].frequency = frequency;
        deep->nodes[inner].index = inner;
        deep->nodes[inner].parent = XX_DMS_DEEP_SYMBOLS + (inner >> 1U);
        deep->nodes[inner].left_leaf = left;
        deep->nodes[inner].right_leaf = right;
        deep->code_map[inner] = inner;
        /* Bubble the new internal node down to its place. The "position > 0"
         * guard is not in the reference; the invariant makes it unreachable,
         * but without it a broken state would index code_map[-1]. */
        for (position = inner; position > 0U && frequency < deep->nodes[deep->code_map[position - 1U]].frequency; --position) {
            uint32_t code = deep->code_map[position];
            uint32_t dest_code = deep->code_map[position - 1U];
            xx_dms_deep_swap(&deep->nodes[code].index, &deep->nodes[dest_code].index);
            xx_dms_deep_swap(&deep->nodes[code].parent, &deep->nodes[dest_code].parent);
            xx_dms_deep_swap(&deep->code_map[position], &deep->code_map[position - 1U]);
        }
    }
}
