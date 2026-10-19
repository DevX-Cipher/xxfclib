/* Private adaptive Huffman frequency ordering from formats/xx_legacy_huffman.h. */

static void ac_tree_rebuild(ac_tree *t)
{
    unsigned i, j = 0, k;
    for (i = 0; i < t->total; ++i)
        if (t->child[i] >= (int)t->total) {
            t->frequency[j] = (t->frequency[i] + 1) / 2;
            t->child[j++] = t->child[i];
        }
    for (i = 0, k = t->chars; k < t->total; i += 2U, ++k) {
        int weight = t->frequency[i] + t->frequency[i + 1U], at = (int)k - 1;
        while (at >= 0 && weight < t->frequency[at]) {
            --at;
        }
        ++at;
        for (j = k; j > (unsigned)at; --j) {
            t->frequency[j] = t->frequency[j - 1U];
            t->child[j] = t->child[j - 1U];
        }
        t->frequency[at] = weight;
        t->child[at] = (int)i;
    }
    for (i = 0; i < t->total; ++i) {
        int c = t->child[i];
        t->parent[c] = (int)i;
        if (c < (int)t->total) t->parent[c + 1] = (int)i;
    }
}
static void ac_tree_update(ac_tree *t, unsigned symbol, bool freeze)
{
    int node;
    if (t->frequency[t->root] == 0x8000) {
        if (freeze) return;
        ac_tree_rebuild(t);
    }
    node = t->parent[t->total + symbol];
    do {
        int weight = ++t->frequency[node], other = node + 1;
        if (weight > t->frequency[other]) {
            int a, c;
            while (weight > t->frequency[other + 1]) ++other;
            t->frequency[node] = t->frequency[other];
            t->frequency[other] = weight;
            a = t->child[node];
            c = t->child[other];
            t->child[other] = a;
            t->child[node] = c;
            t->parent[a] = other;
            if (a < (int)t->total) t->parent[a + 1] = other;
            t->parent[c] = node;
            if (c < (int)t->total) t->parent[c + 1] = node;
            node = other;
        }
        node = t->parent[node];
    } while (node);
}
