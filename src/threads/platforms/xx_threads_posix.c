/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */

/**
 * @file xx_threads_posix.c
 * @brief POSIX threads backend.
 *
 * Semaphores are built from a mutex and a condition variable because macOS
 * does not implement unnamed POSIX semaphores. Timed waits use CLOCK_REALTIME
 * deadlines, the only clock pthread_cond_timedwait accepts on macOS.
 */

#if !defined(_WIN32)

#if !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L
#endif
#if defined(__APPLE__) && !defined(_DARWIN_C_SOURCE)
#define _DARWIN_C_SOURCE 1
#endif

#include "xx_threads_platform.h"
#include "xxfclib/memory/xx_memory.h"
#include <errno.h>
#include <limits.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <unistd.h>

/* ------------------------------------------------------------- threads --- */

static void *xx_threads_posix_start(void *parameter)
{
    xx_threads_run((xx_thread_t *)parameter);

    return NULL;
}

bool xx_threads_platform_start(xx_thread_t *thread, size_t stack_size)
{
    pthread_attr_t attr;
    int result;

    if (pthread_attr_init(&attr) != 0) {
        return false;
    }

    if (stack_size) {
#if defined(PTHREAD_STACK_MIN)
        if (stack_size < (size_t)PTHREAD_STACK_MIN) {
            stack_size = (size_t)PTHREAD_STACK_MIN;
        }
#endif
        if (pthread_attr_setstacksize(&attr, stack_size) != 0) {
            pthread_attr_destroy(&attr);
            return false;
        }
    }

    result = pthread_create(&thread->native, &attr, xx_threads_posix_start, thread);
    pthread_attr_destroy(&attr);

    return result == 0;
}

bool xx_threads_platform_join(xx_thread_t *thread)
{
    return pthread_join(thread->native, NULL) == 0;
}

void xx_threads_platform_detach(xx_thread_t *thread)
{
    pthread_detach(thread->native);
}

uint64_t xx_thread_current_id(void)
{
    /* pthread_t is an integer on Linux and a pointer on macOS and the BSDs. */
    return (uint64_t)(uintptr_t)pthread_self();
}

void xx_thread_yield(void)
{
    sched_yield();
}

void xx_thread_sleep(uint32_t milliseconds)
{
    struct timespec remaining;

    remaining.tv_sec = (time_t)(milliseconds / 1000u);
    remaining.tv_nsec = (long)(milliseconds % 1000u) * 1000000L;

    while ((nanosleep(&remaining, &remaining) != 0) && (errno == EINTR)) {
    }
}

uint32_t xx_thread_cpu_count(void)
{
    long count = sysconf(_SC_NPROCESSORS_ONLN);

    if (count < 1) {
        return 1;
    }

    return (count > (long)UINT32_MAX) ? UINT32_MAX : (uint32_t)count;
}

/* Absolute CLOCK_REALTIME time timeout_ms from now. */
static void xx_threads_posix_deadline(uint32_t timeout_ms, struct timespec *deadline)
{
    clock_gettime(CLOCK_REALTIME, deadline);

    deadline->tv_sec += (time_t)(timeout_ms / 1000u);
    deadline->tv_nsec += (long)(timeout_ms % 1000u) * 1000000L;

    if (deadline->tv_nsec >= 1000000000L) {
        deadline->tv_sec += 1;
        deadline->tv_nsec -= 1000000000L;
    }
}

/* ------------------------------------------------------------- mutexes --- */

struct xx_mutex_s {
    pthread_mutex_t mutex;
};

xx_mutex_t *xx_mutex_create(void)
{
    xx_mutex_t *mutex = (xx_mutex_t *)xx_mem_calloc(1, sizeof(*mutex));
    pthread_mutexattr_t attr;
    bool created = false;

    if (!mutex) {
        return NULL;
    }

    /* Recursive, to match Windows critical sections. */
    if (pthread_mutexattr_init(&attr) == 0) {
        created = (pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE) == 0) && (pthread_mutex_init(&mutex->mutex, &attr) == 0);
        pthread_mutexattr_destroy(&attr);
    }

    if (!created) {
        xx_mem_free(mutex);
        return NULL;
    }

    return mutex;
}

void xx_mutex_destroy(xx_mutex_t *mutex)
{
    if (mutex) {
        pthread_mutex_destroy(&mutex->mutex);
        xx_mem_free(mutex);
    }
}

void xx_mutex_lock(xx_mutex_t *mutex)
{
    if (mutex) {
        pthread_mutex_lock(&mutex->mutex);
    }
}

bool xx_mutex_trylock(xx_mutex_t *mutex)
{
    return mutex && (pthread_mutex_trylock(&mutex->mutex) == 0);
}

void xx_mutex_unlock(xx_mutex_t *mutex)
{
    if (mutex) {
        pthread_mutex_unlock(&mutex->mutex);
    }
}

/* -------------------------------------------------- condition variables --- */

struct xx_cond_s {
    pthread_cond_t cond;
};

xx_cond_t *xx_cond_create(void)
{
    xx_cond_t *cond = (xx_cond_t *)xx_mem_calloc(1, sizeof(*cond));

    if (cond && (pthread_cond_init(&cond->cond, NULL) != 0)) {
        xx_mem_free(cond);
        return NULL;
    }

    return cond;
}

void xx_cond_destroy(xx_cond_t *cond)
{
    if (cond) {
        pthread_cond_destroy(&cond->cond);
        xx_mem_free(cond);
    }
}

static xx_wait_result_t xx_threads_posix_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex, uint32_t timeout_ms)
{
    struct timespec deadline;
    int result;

    if (timeout_ms == XX_WAIT_INFINITE) {
        result = pthread_cond_wait(cond, mutex);
    } else {
        xx_threads_posix_deadline(timeout_ms, &deadline);
        result = pthread_cond_timedwait(cond, mutex, &deadline);
    }

    if (result == 0) {
        return XX_WAIT_OK;
    }

    return (result == ETIMEDOUT) ? XX_WAIT_TIMEOUT : XX_WAIT_ERROR;
}

xx_wait_result_t xx_cond_wait(xx_cond_t *cond, xx_mutex_t *mutex, uint32_t timeout_ms)
{
    if (!cond || !mutex) {
        return XX_WAIT_ERROR;
    }

    return xx_threads_posix_cond_wait(&cond->cond, &mutex->mutex, timeout_ms);
}

void xx_cond_signal(xx_cond_t *cond)
{
    if (cond) {
        pthread_cond_signal(&cond->cond);
    }
}

void xx_cond_broadcast(xx_cond_t *cond)
{
    if (cond) {
        pthread_cond_broadcast(&cond->cond);
    }
}

/* ---------------------------------------------------------- semaphores --- */

struct xx_semaphore_s {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    uint32_t count;
};

xx_semaphore_t *xx_semaphore_create(uint32_t initial_count)
{
    xx_semaphore_t *semaphore;

    if (initial_count > 0x7FFFFFFFu) {
        return NULL;
    }

    semaphore = (xx_semaphore_t *)xx_mem_calloc(1, sizeof(*semaphore));

    if (!semaphore) {
        return NULL;
    }

    if (pthread_mutex_init(&semaphore->mutex, NULL) != 0) {
        xx_mem_free(semaphore);
        return NULL;
    }

    if (pthread_cond_init(&semaphore->cond, NULL) != 0) {
        pthread_mutex_destroy(&semaphore->mutex);
        xx_mem_free(semaphore);
        return NULL;
    }

    semaphore->count = initial_count;

    return semaphore;
}

void xx_semaphore_destroy(xx_semaphore_t *semaphore)
{
    if (semaphore) {
        pthread_cond_destroy(&semaphore->cond);
        pthread_mutex_destroy(&semaphore->mutex);
        xx_mem_free(semaphore);
    }
}

xx_wait_result_t xx_semaphore_wait(xx_semaphore_t *semaphore, uint32_t timeout_ms)
{
    struct timespec deadline;
    xx_wait_result_t result = XX_WAIT_OK;

    if (!semaphore) {
        return XX_WAIT_ERROR;
    }

    /* One deadline for the whole wait, however many spurious wake-ups. */
    if (timeout_ms != XX_WAIT_INFINITE) {
        xx_threads_posix_deadline(timeout_ms, &deadline);
    }

    pthread_mutex_lock(&semaphore->mutex);

    while (semaphore->count == 0) {
        int status;

        if (timeout_ms == XX_WAIT_INFINITE) {
            status = pthread_cond_wait(&semaphore->cond, &semaphore->mutex);
        } else {
            status = pthread_cond_timedwait(&semaphore->cond, &semaphore->mutex, &deadline);
        }

        if (status == ETIMEDOUT) {
            result = XX_WAIT_TIMEOUT;
            break;
        }

        if (status != 0) {
            result = XX_WAIT_ERROR;
            break;
        }
    }

    if (semaphore->count && (result != XX_WAIT_ERROR)) {
        /* A post that raced the timeout still counts as success. */
        semaphore->count--;
        result = XX_WAIT_OK;
    }

    pthread_mutex_unlock(&semaphore->mutex);

    return result;
}

bool xx_semaphore_post(xx_semaphore_t *semaphore, uint32_t count)
{
    bool posted = false;

    if (!semaphore || (count == 0)) {
        return false;
    }

    pthread_mutex_lock(&semaphore->mutex);

    /* Same maximum as the Windows semaphore; refuse rather than wrap. */
    if (count <= 0x7FFFFFFFu - semaphore->count) {
        semaphore->count += count;
        posted = true;
    }

    pthread_mutex_unlock(&semaphore->mutex);

    if (posted) {
        if (count == 1) {
            pthread_cond_signal(&semaphore->cond);
        } else {
            pthread_cond_broadcast(&semaphore->cond);
        }
    }

    return posted;
}

/* ------------------------------------------------------------- atomics --- */

long xx_atomic_load(volatile long *value)
{
    return __atomic_load_n(value, __ATOMIC_SEQ_CST);
}

void xx_atomic_store(volatile long *value, long desired)
{
    __atomic_store_n(value, desired, __ATOMIC_SEQ_CST);
}

long xx_atomic_exchange(volatile long *value, long desired)
{
    return __atomic_exchange_n(value, desired, __ATOMIC_SEQ_CST);
}

long xx_atomic_add(volatile long *value, long delta)
{
    return __atomic_fetch_add(value, delta, __ATOMIC_SEQ_CST);
}

long xx_atomic_compare_exchange(volatile long *value, long expected, long desired)
{
    __atomic_compare_exchange_n(value, &expected, desired, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);

    return expected;
}

void *xx_atomic_load_ptr(void *volatile *value)
{
    return __atomic_load_n(value, __ATOMIC_SEQ_CST);
}

void xx_atomic_store_ptr(void *volatile *value, void *desired)
{
    __atomic_store_n(value, desired, __ATOMIC_SEQ_CST);
}

void *xx_atomic_exchange_ptr(void *volatile *value, void *desired)
{
    return __atomic_exchange_n(value, desired, __ATOMIC_SEQ_CST);
}

void *xx_atomic_compare_exchange_ptr(void *volatile *value, void *expected, void *desired)
{
    __atomic_compare_exchange_n(value, &expected, desired, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);

    return expected;
}

#endif
