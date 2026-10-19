/* Private sorting implementation from src/formats/dart/xx_dart.c. */

/* Halve every leaf weight and rebuild the internal nodes in sorted order. */
static void lz_tree_rebuild(dart_lzh *z)
{
    uint32_t from, to = 0U, pair, node, slot, move;
    for (from = 0U; from < LZ_T; ++from) {
        if (z->child[from] >= LZ_T) {
            z->freq[to] = (uint16_t)((z->freq[from] + 1U) / 2U);
            z->child[to] = z->child[from];
            ++to;
        }
    }
    pair = 0U;
    for (node = LZ_NCHAR; node < LZ_T; ++node) {
        uint16_t weight = (uint16_t)(z->freq[pair] + z->freq[pair + 1U]);
        slot = node;
        while (slot > 0U && weight < z->freq[slot - 1U]) --slot;
        for (move = node; move > slot; --move) {
            z->freq[move] = z->freq[move - 1U];
            z->child[move] = z->child[move - 1U];
        }
        z->freq[slot] = weight;
        z->child[slot] = (uint16_t)pair;
        pair += 2U;
    }
    for (node = 0U; node < LZ_T; ++node) {
        uint32_t c = z->child[node];
        if (c >= LZ_T) {
            z->parent[c] = (uint16_t)node;
        } else {
            z->parent[c] = (uint16_t)node;
            z->parent[c + 1U] = (uint16_t)node;
        }
    }
}

/* Count one occurrence of @p symbol, keeping the weights sorted. */
static void lz_tree_count(dart_lzh *z, uint32_t symbol)
{
    uint32_t node, guard = 0U;
    if (z->freq[LZ_ROOT] == LZ_MAX_FREQ) lz_tree_rebuild(z);
    node = z->parent[symbol + LZ_T];
    do {
        uint32_t weight = (uint32_t)z->freq[node] + 1U, swap;
        z->freq[node] = (uint16_t)weight;
        swap = node + 1U;
        if (weight > z->freq[swap]) {
            uint32_t a, b;
            while (swap < LZ_T && weight > z->freq[swap + 1U]) ++swap;
            z->freq[node] = z->freq[swap];
            z->freq[swap] = (uint16_t)weight;
            a = z->child[node];
            z->parent[a] = (uint16_t)swap;
            if (a < LZ_T) z->parent[a + 1U] = (uint16_t)swap;
            b = z->child[swap];
            z->child[swap] = (uint16_t)a;
            z->parent[b] = (uint16_t)node;
            if (b < LZ_T) z->parent[b + 1U] = (uint16_t)node;
            z->child[node] = (uint16_t)b;
            node = swap;
        }
        node = z->parent[node];
    } while (node != 0U && ++guard < LZ_T);
}
