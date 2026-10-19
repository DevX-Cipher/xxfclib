/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/**
 * @file xx_threads_platform.h
 * @brief Internal interface between xx_threads.c and the OS thread backends.
 *
 * xx_threads.c owns the thread object and its lifetime; the backends start,
 * join and detach the native thread. Mutexes, condition variables,
 * semaphores and atomics are implemented by the backends directly.
 */

#ifndef XX_THREADS_PLATFORM_H
#define XX_THREADS_PLATFORM_H

#include "xxfclib/threads/xx_threads.h"

#if !defined(_WIN32)
#include <pthread.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Two references: the handle and the running thread. Whichever drops the
 * last one frees the object, so a detached thread needs no one to wait. */
struct xx_thread_s {
    xx_thread_fn fn;
    void *arg;
    int exit_code;
    volatile long refs;
#if defined(_WIN32)
    void *native; /* HANDLE */
#else
    pthread_t native;
#endif
};

/** Body of every new thread: runs fn(arg) and drops the thread's reference. */
void xx_threads_run(xx_thread_t *thread);

/** Start a native thread that calls xx_threads_run(thread). */
bool xx_threads_platform_start(xx_thread_t *thread, size_t stack_size);

/** Wait for the native thread to end and release its native handle. */
bool xx_threads_platform_join(xx_thread_t *thread);

/** Release the native handle without waiting. */
void xx_threads_platform_detach(xx_thread_t *thread);

#ifdef __cplusplus
}
#endif

#endif /* XX_THREADS_PLATFORM_H */
