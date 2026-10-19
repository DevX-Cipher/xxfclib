/* Copyright (c) 2026 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @file xx_memory.h
 * @brief Memory management subsystem and utilities.
 */

#ifndef XX_MEMORY_H
#define XX_MEMORY_H

#include "xxfclib/xxfc_defs.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- Core Memory Allocation Functions --- */

/**
 * @brief Allocate a block of memory of specified size.
 * @param size Number of bytes to allocate.
 * @return Pointer to allocated block, or NULL on failure or if size == 0.
 */
XXFC_API void *xx_mem_alloc(size_t size);

/**
 * @brief Allocate zero-initialized memory for an array of elements.
 * @param count Number of elements.
 * @param size Size of each element in bytes.
 * @return Pointer to zeroed allocated block, or NULL on failure or if count*size == 0.
 */
XXFC_API void *xx_mem_calloc(size_t count, size_t size);

/**
 * @brief Reallocate a block of memory to a new size.
 * @param ptr Pointer to previously allocated block, or NULL to allocate anew.
 * @param new_size New size in bytes. If 0 and ptr != NULL, frees memory and returns NULL.
 * @return Pointer to reallocated block, or NULL on failure.
 */
XXFC_API void *xx_mem_realloc(void *ptr, size_t new_size);

/**
 * @brief Free a block of memory previously allocated by xx_mem_* functions.
 * @param ptr Pointer to block to free (safe to pass NULL).
 */
XXFC_API void xx_mem_free(void *ptr);

/**
 * @brief Allocate aligned memory block.
 * @param alignment Alignment boundary in bytes (must be power of two and multiple of sizeof(void*)).
 * @param size Number of bytes to allocate.
 * @return Pointer to aligned block, or NULL on failure.
 */
XXFC_API void *xx_mem_aligned_alloc(size_t alignment, size_t size);

/**
 * @brief Free memory block allocated by xx_mem_aligned_alloc.
 * @param ptr Pointer to aligned block to free (safe to pass NULL).
 */
XXFC_API void xx_mem_aligned_free(void *ptr);

/**
 * @brief Query usable size of an allocated memory block.
 * @param ptr Pointer to allocated block.
 * @return Usable size in bytes, or 0 if unknown / unsupported.
 */
XXFC_API size_t xx_mem_usable_size(void *ptr);

/* --- Memory Utility Functions --- */

/**
 * @brief Zero out a region of memory securely.
 * @param ptr Pointer to memory.
 * @param size Number of bytes to zero.
 * @return Pointer to memory (ptr).
 */
XXFC_API void *xx_mem_zero(void *ptr, size_t size);

/**
 * @brief Fill a region of memory with a given byte value.
 * @param dst Pointer to memory block.
 * @param value Byte value to set.
 * @param size Number of bytes to set.
 * @return Pointer to destination (dst).
 */
XXFC_API void *xx_mem_set(void *dst, int value, size_t size);

/**
 * @brief Copy non-overlapping memory from src to dst.
 * @param dst Destination pointer.
 * @param src Source pointer.
 * @param size Number of bytes to copy.
 * @return Pointer to destination (dst).
 */
XXFC_API void *xx_mem_copy(void *dst, const void *src, size_t size);

/**
 * @brief Copy potentially overlapping memory from src to dst.
 * @param dst Destination pointer.
 * @param src Source pointer.
 * @param size Number of bytes to move.
 * @return Pointer to destination (dst).
 */
XXFC_API void *xx_mem_move(void *dst, const void *src, size_t size);

/**
 * @brief Compare two memory blocks byte-by-byte.
 * @param a First block.
 * @param b Second block.
 * @param size Number of bytes to compare.
 * @return < 0 if a < b, 0 if a == b, > 0 if a > b.
 */
XXFC_API int xx_mem_compare(const void *a, const void *b, size_t size);

/**
 * @brief Find the first occurrence of a byte value in a memory block (memchr).
 * @param ptr Block to search; may be NULL only when size is 0.
 * @param value Byte to find, converted to unsigned char.
 * @param size Number of bytes to search.
 * @return Pointer to the first matching byte, or NULL if it does not occur.
 */
XXFC_API void *xx_mem_find_byte(const void *ptr, int value, size_t size);

/* --- Inline Convenience Aliases --- */

static inline void *xx_alloc(size_t size)
{
    return xx_mem_alloc(size);
}

static inline void *xx_zalloc(size_t count, size_t size)
{
    return xx_mem_calloc(count, size);
}

static inline void *xx_realloc(void *ptr, size_t new_size)
{
    return xx_mem_realloc(ptr, new_size);
}

static inline void xx_free(void *ptr)
{
    xx_mem_free(ptr);
}

static inline void *xx_aligned_alloc(size_t alignment, size_t size)
{
    return xx_mem_aligned_alloc(alignment, size);
}

static inline void xx_aligned_free(void *ptr)
{
    xx_mem_aligned_free(ptr);
}

static inline void *mem_alloc(size_t size)
{
    return xx_mem_alloc(size);
}

static inline void *mem_calloc(size_t count, size_t size)
{
    return xx_mem_calloc(count, size);
}

static inline void *mem_realloc(void *ptr, size_t new_size)
{
    return xx_mem_realloc(ptr, new_size);
}

static inline void mem_free(void *ptr)
{
    xx_mem_free(ptr);
}

static inline void *mem_set(void *dst, int value, size_t size)
{
    return xx_mem_set(dst, value, size);
}

/* --- Unaligned Word Access Helpers --- */

#if defined(__GNUC__) || defined(__clang__)
typedef struct __attribute__((packed, may_alias)) xx_mem_word32_s {
    uint32_t value;
} xx_mem_word32;
typedef struct __attribute__((packed, may_alias)) xx_mem_word64_s {
    uint64_t value;
} xx_mem_word64;
#elif defined(_MSC_VER)
#pragma pack(push, 1)
typedef struct xx_mem_word32_s {
    uint32_t value;
} xx_mem_word32;
typedef struct xx_mem_word64_s {
    uint64_t value;
} xx_mem_word64;
#pragma pack(pop)
#endif

static inline uint32_t xx_mem_load32(const void *source)
{
#if defined(_MSC_VER) || defined(__GNUC__) || defined(__clang__)
    return ((const xx_mem_word32 *)source)->value;
#else
    uint32_t val;
    xx_mem_copy(&val, source, sizeof(val));
    return val;
#endif
}

static inline void xx_mem_store32(void *destination, uint32_t value)
{
#if defined(_MSC_VER) || defined(__GNUC__) || defined(__clang__)
    ((xx_mem_word32 *)destination)->value = value;
#else
    xx_mem_copy(destination, &value, sizeof(value));
#endif
}

static inline uint64_t xx_mem_load64(const void *source)
{
#if defined(_MSC_VER) || defined(__GNUC__) || defined(__clang__)
    return ((const xx_mem_word64 *)source)->value;
#else
    uint64_t val;
    xx_mem_copy(&val, source, sizeof(val));
    return val;
#endif
}

static inline void xx_mem_store64(void *destination, uint64_t value)
{
#if defined(_MSC_VER) || defined(__GNUC__) || defined(__clang__)
    ((xx_mem_word64 *)destination)->value = value;
#else
    xx_mem_copy(destination, &value, sizeof(value));
#endif
}

static inline void xx_mem_copy64(void *destination, const void *source)
{
#if defined(_MSC_VER) || defined(__GNUC__) || defined(__clang__)
    ((xx_mem_word64 *)destination)->value = ((const xx_mem_word64 *)source)->value;
#else
    xx_mem_copy(destination, source, 8);
#endif
}

#ifdef __cplusplus
}
#endif

#endif /* XX_MEMORY_H */
