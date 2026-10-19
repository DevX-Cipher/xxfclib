/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/**
 * @file xx_threads.h
 * @brief Threads, mutexes, condition variables, semaphores, one-time
 *        initialisation and atomics.
 *
 * Every object is an opaque handle created and destroyed by the library, so
 * the ABI does not depend on the size of CRITICAL_SECTION or pthread_mutex_t.
 * Windows uses KERNEL32 only (CreateThread, critical sections, semaphores)
 * and works without the CRT; elsewhere the backend is POSIX threads.
 *
 * Condition variables need Windows Vista or later. They are resolved at run
 * time, so the library still loads on Windows XP, where xx_cond_create
 * returns NULL.
 *
 * Destroying an object that another thread is still using is undefined, as
 * is destroying a mutex that is locked.
 */

#ifndef XX_THREADS_H
#define XX_THREADS_H

#include "xxfclib/xxfc_defs.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Timeout value meaning "wait until signalled". */
#define XX_WAIT_INFINITE 0xFFFFFFFFu

typedef enum xx_wait_result_e {
    XX_WAIT_OK = 0,      /**< The wait succeeded. */
    XX_WAIT_TIMEOUT = 1, /**< The timeout expired first. */
    XX_WAIT_ERROR = 2    /**< Invalid argument or system failure. */
} xx_wait_result_t;

/* ------------------------------------------------------------- threads --- */

typedef struct xx_thread_s xx_thread_t;

/** Thread entry point; the return value is reported by xx_thread_join. */
typedef int (*xx_thread_fn)(void *arg);

/**
 * Start a thread running fn(arg). Returns NULL on failure. The handle must be
 * released exactly once, by xx_thread_join or xx_thread_detach.
 */
XXFC_API xx_thread_t *xx_thread_create(xx_thread_fn fn, void *arg);

/** As xx_thread_create; stack_size 0 selects the platform default. */
XXFC_API xx_thread_t *xx_thread_create_ex(xx_thread_fn fn, void *arg, size_t stack_size);

/**
 * Wait for the thread to finish, store its return value in exit_code when
 * that is not NULL, and release the handle. A thread must not join itself.
 */
XXFC_API bool xx_thread_join(xx_thread_t *thread, int *exit_code);

/** Release the handle without waiting; the thread cleans up when it ends. */
XXFC_API void xx_thread_detach(xx_thread_t *thread);

/** Identifies the calling thread while it runs; ids may be reused later. */
XXFC_API uint64_t xx_thread_current_id(void);

/** Give the rest of the time slice to another ready thread. */
XXFC_API void xx_thread_yield(void);

/** Suspend the calling thread for at least milliseconds. */
XXFC_API void xx_thread_sleep(uint32_t milliseconds);

/** Number of logical processors available to the process, at least 1. */
XXFC_API uint32_t xx_thread_cpu_count(void);

/* ------------------------------------------------------------- mutexes --- */

/* Mutexes are recursive: the owning thread may lock one again, and must
 * unlock it as many times as it locked it. */
typedef struct xx_mutex_s xx_mutex_t;

XXFC_API xx_mutex_t *xx_mutex_create(void);
XXFC_API void xx_mutex_destroy(xx_mutex_t *mutex);
XXFC_API void xx_mutex_lock(xx_mutex_t *mutex);
/** Lock without blocking; false when another thread owns the mutex. */
XXFC_API bool xx_mutex_trylock(xx_mutex_t *mutex);
XXFC_API void xx_mutex_unlock(xx_mutex_t *mutex);

/* -------------------------------------------------- condition variables --- */

typedef struct xx_cond_s xx_cond_t;

/** NULL on failure, or on Windows versions before Vista. */
XXFC_API xx_cond_t *xx_cond_create(void);
XXFC_API void xx_cond_destroy(xx_cond_t *cond);

/**
 * Atomically unlock mutex, which the caller must have locked exactly once,
 * and wait; the mutex is locked again before this returns. Wake-ups may be
 * spurious, so wait in a loop that re-checks the predicate.
 */
XXFC_API xx_wait_result_t xx_cond_wait(xx_cond_t *cond, xx_mutex_t *mutex, uint32_t timeout_ms);
XXFC_API void xx_cond_signal(xx_cond_t *cond);
XXFC_API void xx_cond_broadcast(xx_cond_t *cond);

/* ---------------------------------------------------------- semaphores --- */

typedef struct xx_semaphore_s xx_semaphore_t;

/** Counting semaphore; initial_count must not exceed INT32_MAX. */
XXFC_API xx_semaphore_t *xx_semaphore_create(uint32_t initial_count);
XXFC_API void xx_semaphore_destroy(xx_semaphore_t *semaphore);
/** Decrement the count, waiting while it is zero. */
XXFC_API xx_wait_result_t xx_semaphore_wait(xx_semaphore_t *semaphore, uint32_t timeout_ms);
/** Increment the count by count, waking up to that many waiters. */
XXFC_API bool xx_semaphore_post(xx_semaphore_t *semaphore, uint32_t count);

/* ------------------------------------------------- one-time initialising --- */

/** Zero-initialise a static xx_once_t: `static xx_once_t once = XX_ONCE_INIT;` */
typedef struct xx_once_s {
    volatile long state;
} xx_once_t;

#define XX_ONCE_INIT {0}

typedef void (*xx_once_fn)(void *arg);

/**
 * Run fn(arg) exactly once per once object. Other callers wait until it has
 * returned, so its effects are visible to every caller afterwards. fn must
 * not call xx_once on the same object.
 */
XXFC_API void xx_once(xx_once_t *once, xx_once_fn fn, void *arg);

/* ------------------------------------------------------------- atomics --- */

/* Sequentially consistent operations on naturally aligned values. Each
 * returns the value held before the operation, except xx_atomic_load. */
XXFC_API long xx_atomic_load(volatile long *value);
XXFC_API void xx_atomic_store(volatile long *value, long desired);
XXFC_API long xx_atomic_exchange(volatile long *value, long desired);
XXFC_API long xx_atomic_add(volatile long *value, long delta);
/** Store desired when *value equals expected; returns the previous value. */
XXFC_API long xx_atomic_compare_exchange(volatile long *value, long expected, long desired);

XXFC_API void *xx_atomic_load_ptr(void *volatile *value);
XXFC_API void xx_atomic_store_ptr(void *volatile *value, void *desired);
XXFC_API void *xx_atomic_exchange_ptr(void *volatile *value, void *desired);
XXFC_API void *xx_atomic_compare_exchange_ptr(void *volatile *value, void *expected, void *desired);

#ifdef __cplusplus
}
#endif

#endif /* XX_THREADS_H */
