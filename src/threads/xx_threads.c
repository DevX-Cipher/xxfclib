/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/**
 * @file xx_threads.c
 * @brief Platform-independent thread lifetime and one-time initialisation.
 */

#include "platforms/xx_threads_platform.h"
#include "xxfclib/memory/xx_memory.h"

/* xx_once states. */
#define XX_ONCE_NEW 0L
#define XX_ONCE_RUNNING 1L
#define XX_ONCE_DONE 2L

static void xx_thread_release_ref(xx_thread_t *thread)
{
    if (xx_atomic_add(&thread->refs, -1) == 1) {
        xx_mem_free(thread);
    }
}

void xx_threads_run(xx_thread_t *thread)
{
    thread->exit_code = thread->fn(thread->arg);
    xx_thread_release_ref(thread);
}

xx_thread_t *xx_thread_create(xx_thread_fn fn, void *arg)
{
    return xx_thread_create_ex(fn, arg, 0);
}

xx_thread_t *xx_thread_create_ex(xx_thread_fn fn, void *arg, size_t stack_size)
{
    xx_thread_t *thread;

    if (!fn) {
        return NULL;
    }

    thread = (xx_thread_t *)xx_mem_calloc(1, sizeof(*thread));

    if (!thread) {
        return NULL;
    }

    thread->fn = fn;
    thread->arg = arg;
    thread->refs = 2;

    if (!xx_threads_platform_start(thread, stack_size)) {
        xx_mem_free(thread);
        return NULL;
    }

    return thread;
}

bool xx_thread_join(xx_thread_t *thread, int *exit_code)
{
    if (!thread || !xx_threads_platform_join(thread)) {
        return false;
    }

    /* The thread has ended, so its reference is gone and exit_code is final. */
    if (exit_code) {
        *exit_code = thread->exit_code;
    }

    xx_thread_release_ref(thread);

    return true;
}

void xx_thread_detach(xx_thread_t *thread)
{
    if (!thread) {
        return;
    }

    xx_threads_platform_detach(thread);
    xx_thread_release_ref(thread);
}

void xx_once(xx_once_t *once, xx_once_fn fn, void *arg)
{
    long state;

    if (!once || !fn) {
        return;
    }

    state = xx_atomic_load(&once->state);

    if (state == XX_ONCE_DONE) {
        return;
    }

    if ((state == XX_ONCE_NEW) && (xx_atomic_compare_exchange(&once->state, XX_ONCE_NEW, XX_ONCE_RUNNING) == XX_ONCE_NEW)) {
        fn(arg);
        xx_atomic_store(&once->state, XX_ONCE_DONE);
        return;
    }

    /* Another thread is running fn; initialisers are short, so spin politely. */
    while (xx_atomic_load(&once->state) != XX_ONCE_DONE) {
        xx_thread_yield();
    }
}
