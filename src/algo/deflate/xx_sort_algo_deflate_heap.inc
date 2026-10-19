/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Private Deflate Huffman priority ordering. Index ties retain the original
 * encoder output and the helpers remain local to the encoder translation unit.
 */

static bool xx_huff_node_less(const xx_huff_node *nodes, int a, int b)
{
    return nodes[a].freq < nodes[b].freq || (nodes[a].freq == nodes[b].freq && a < b);
}

static void xx_huff_heap_push(const xx_huff_node *nodes, int *heap, int *count, int node)
{
    int at = (*count)++;
    while (at != 0) {
        int parent = (at - 1) / 2;
        if (!xx_huff_node_less(nodes, node, heap[parent])) break;
        heap[at] = heap[parent];
        at = parent;
    }
    heap[at] = node;
}

static int xx_huff_heap_pop(const xx_huff_node *nodes, int *heap, int *count)
{
    int result = heap[0];
    int node = heap[--*count];
    int at = 0;
    while (at * 2 + 1 < *count) {
        int child = at * 2 + 1;
        if (child + 1 < *count && xx_huff_node_less(nodes, heap[child + 1], heap[child])) ++child;
        if (!xx_huff_node_less(nodes, heap[child], node)) break;
        heap[at] = heap[child];
        at = child;
    }
    if (*count != 0) heap[at] = node;
    return result;
}

