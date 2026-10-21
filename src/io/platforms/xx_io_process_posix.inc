/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 *
 * Included by xx_io_process.c after the portable device implementation. Its
 * feature-test macros must precede all headers in that translation unit:
 * _POSIX_C_SOURCE=200809L, _FILE_OFFSET_BITS=64, and _DARWIN_C_SOURCE on macOS.
 */
#ifndef _WIN32
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#if defined(__APPLE__)
#include <mach/mach.h>
#include <mach/mach_vm.h>
#endif

#define XX_PROCESS_POSIX_READ 1U
#define XX_PROCESS_POSIX_WRITE 2U
#define XX_PROCESS_POSIX_READ_WRITE (XX_PROCESS_POSIX_READ | XX_PROCESS_POSIX_WRITE)
#define XX_PROCESS_POSIX_CHUNK ((size_t)65536)

void xx_io_platform_process_set_error(int error)
{
    errno = error;
}

void *xx_io_platform_process_alloc(size_t size)
{
    void *result = calloc(1, size ? size : 1);
    if (!result) errno = ENOMEM;
    return result;
}

void xx_io_platform_process_free(void *pointer)
{
    int saved = errno;
    free(pointer);
    errno = saved;
}

static int xx_process_posix_access(unsigned access)
{
    if (access != XX_PROCESS_POSIX_READ && access != XX_PROCESS_POSIX_WRITE && access != XX_PROCESS_POSIX_READ_WRITE) {
        errno = EINVAL;
        return 0;
    }
    return 1;
}

static int xx_process_posix_pid(uint64_t requested, pid_t *pid)
{
    if (requested > INT_MAX) { errno = EINVAL; return 0; }
    *pid = requested ? (pid_t)requested : getpid();
    return 1;
}

#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
static int xx_process_posix_request(uint64_t address, const void *buffer, size_t *size)
{
    if (!*size) return 1;
    if (!buffer) { errno = EINVAL; return 0; }
    if (*size && (uint64_t)(*size - 1U) > UINT64_MAX - address) { errno = EOVERFLOW; return 0; }
    if (*size > (size_t)SSIZE_MAX) *size = (size_t)SSIZE_MAX;
    return 1;
}
#endif

#if defined(__linux__) || defined(__FreeBSD__)
/* FreeBSD uses its native procfs mem node when procfs is mounted. Kernel
 * sysctl structure queries remain usable without procfs; memory open then
 * reports ENOENT/EACCES and the inspector leaves remote fields unavailable.
 * No debugger attachment or process suspension is performed. */
/* fd+1 encoding preserves a valid descriptor zero as a non-NULL handle.
 * Unsigned arithmetic also handles fd==INT_MAX without signed overflow. */
static void *xx_process_posix_encode_fd(int fd)
{
    return (void *)((uintptr_t)(unsigned)fd + 1U);
}

static int xx_process_posix_decode_fd(void *handle, int *fd)
{
    uintptr_t encoded = (uintptr_t)handle;
    if (!encoded || encoded - 1U > INT_MAX) { errno = EBADF; return 0; }
    *fd = (int)(encoded - 1U);
    return 1;
}

static int xx_process_posix_offset_range(uint64_t address, size_t size)
{
    unsigned bits = (unsigned)(sizeof(off_t) * CHAR_BIT);
    uint64_t maximum = bits >= 64 ? (uint64_t)INT64_MAX : (UINT64_C(1) << (bits - 1U)) - 1U;
    if (address > maximum || (size && (uint64_t)(size - 1U) > maximum - address)) {
        errno = EOVERFLOW;
        return 0;
    }
    return 1;
}

void *xx_io_platform_process_open_ex(uint64_t requested, unsigned access)
{
    char path[64];
    pid_t pid;
    int fd, flags;
    if (!xx_process_posix_access(access) || !xx_process_posix_pid(requested, &pid)) return NULL;
    flags = access == XX_PROCESS_POSIX_READ ? O_RDONLY : (access == XX_PROCESS_POSIX_WRITE ? O_WRONLY : O_RDWR);
    (void)snprintf(path, sizeof(path), "/proc/%ld/mem", (long)pid);
    do { fd = open(path, flags | O_CLOEXEC); } while (fd < 0 && errno == EINTR);
    return fd < 0 ? NULL : xx_process_posix_encode_fd(fd);
}

void *xx_io_platform_process_open(uint64_t pid)
{
    void *handle;
    if (pid > INT_MAX) { errno = EINVAL; return NULL; }
    handle = xx_io_platform_process_open_ex(pid, XX_PROCESS_POSIX_READ_WRITE);
    return handle ? handle : xx_io_platform_process_open_ex(pid, XX_PROCESS_POSIX_READ);
}

ssize_t xx_io_platform_process_read(void *handle, uint64_t address, void *buffer, size_t size)
{
    int fd;
    size_t total = 0;
    if (!xx_process_posix_decode_fd(handle, &fd)) return -1;
    if (!size) return 0;
    if (!xx_process_posix_offset_range(address, size) || !xx_process_posix_request(address, buffer, &size)) return -1;
    while (total < size) {
        size_t amount = size - total < XX_PROCESS_POSIX_CHUNK ? size - total : XX_PROCESS_POSIX_CHUNK;
        ssize_t got = pread(fd, (unsigned char *)buffer + total, amount, (off_t)(address + total));
        if (got < 0 && errno == EINTR) continue;
        if (got < 0) return total ? (ssize_t)total : -1;
        if (!got) break;
        total += (size_t)got;
    }
    return (ssize_t)total;
}

ssize_t xx_io_platform_process_write(void *handle, uint64_t address, const void *buffer, size_t size)
{
    int fd;
    size_t total = 0;
    if (!xx_process_posix_decode_fd(handle, &fd)) return -1;
    if (!size) return 0;
    if (!xx_process_posix_offset_range(address, size) || !xx_process_posix_request(address, buffer, &size)) return -1;
    while (total < size) {
        size_t amount = size - total < XX_PROCESS_POSIX_CHUNK ? size - total : XX_PROCESS_POSIX_CHUNK;
        ssize_t put = pwrite(fd, (const unsigned char *)buffer + total, amount, (off_t)(address + total));
        if (put < 0 && errno == EINTR) continue;
        if (put < 0) return total ? (ssize_t)total : -1;
        if (!put) { errno = EIO; break; }
        total += (size_t)put;
    }
    return (ssize_t)total;
}

int xx_io_platform_process_close(void *handle)
{
    int fd;
    if (!xx_process_posix_decode_fd(handle, &fd)) return -1;
    /* Retrying close after EINTR can close an unrelated, reused descriptor. */
    return close(fd);
}

void *xx_io_platform_process_adopt(void *native)
{
    uintptr_t raw = (uintptr_t)native;
    int flags;
    if (raw > INT_MAX) { errno = EBADF; return NULL; }
    do { flags = fcntl((int)raw, F_GETFL); } while (flags < 0 && errno == EINTR);
    if (flags < 0) return NULL;
    /* This borrows the caller's descriptor, including fd 0 / native==NULL. */
    return xx_process_posix_encode_fd((int)raw);
}

#elif defined(__APPLE__)
static int xx_process_posix_mach_error(kern_return_t error, int opening)
{
    switch (error) {
        case KERN_INVALID_ADDRESS:
        case KERN_MEMORY_FAILURE:
        case KERN_MEMORY_ERROR: errno = EFAULT; break;
        case KERN_PROTECTION_FAILURE:
        case KERN_NO_ACCESS: errno = EACCES; break;
        case KERN_NO_SPACE:
        case KERN_RESOURCE_SHORTAGE: errno = ENOMEM; break;
        case KERN_INVALID_ARGUMENT: errno = EINVAL; break;
        case KERN_INVALID_NAME:
        case KERN_INVALID_TASK:
        case KERN_TERMINATED:
        case MACH_SEND_INVALID_DEST:
        case MACH_RCV_PORT_DIED: errno = ESRCH; break;
        default: errno = opening ? EPERM : EIO; break;
    }
    return -1;
}

static int xx_process_posix_decode_task(void *handle, task_t *task)
{
    uintptr_t encoded = (uintptr_t)handle;
    if (encoded > UINT32_MAX || !MACH_PORT_VALID((mach_port_t)encoded)) { errno = EBADF; return 0; }
    *task = (task_t)encoded;
    return 1;
}

void *xx_io_platform_process_open_ex(uint64_t requested, unsigned access)
{
    task_t task = MACH_PORT_NULL;
    pid_t pid;
    kern_return_t result;
    if (!xx_process_posix_access(access) || !xx_process_posix_pid(requested, &pid)) return NULL;
    if (pid == getpid()) {
        task = mach_task_self();
        /* Retain one independent send uref; close must not consume the
         * process-global reference owned by mach_task_self(). */
        result = mach_port_mod_refs(mach_task_self(), task, MACH_PORT_RIGHT_SEND, 1);
    } else result = task_for_pid(mach_task_self(), pid, &task);
    if (result != KERN_SUCCESS) { xx_process_posix_mach_error(result, 1); return NULL; }
    if (!MACH_PORT_VALID(task)) { errno = ESRCH; return NULL; }
    return (void *)(uintptr_t)task;
}

void *xx_io_platform_process_open(uint64_t pid)
{
    /* Mach grants a task port, not separate O_RDONLY/O_RDWR descriptors.
     * The portable device enforces the requested read/write access flags. */
    return xx_io_platform_process_open_ex(pid, XX_PROCESS_POSIX_READ_WRITE);
}

ssize_t xx_io_platform_process_read(void *handle, uint64_t address, void *buffer, size_t size)
{
    task_t task;
    size_t total = 0;
    if (!xx_process_posix_decode_task(handle, &task)) return -1;
    if (!size) return 0;
    if (!xx_process_posix_request(address, buffer, &size)) return -1;
    while (total < size) {
        size_t amount = size - total < XX_PROCESS_POSIX_CHUNK ? size - total : XX_PROCESS_POSIX_CHUNK;
        mach_vm_size_t got = 0;
        kern_return_t result = mach_vm_read_overwrite(task, (mach_vm_address_t)(address + total), (mach_vm_size_t)amount,
                                                     (mach_vm_address_t)(uintptr_t)((unsigned char *)buffer + total), &got);
        if (got > amount) { errno = EIO; return total ? (ssize_t)total : -1; }
        total += (size_t)got;
        if (result != KERN_SUCCESS) { xx_process_posix_mach_error(result, 0); return total ? (ssize_t)total : -1; }
        if (!got) { errno = EIO; return total ? (ssize_t)total : -1; }
    }
    return (ssize_t)total;
}

ssize_t xx_io_platform_process_write(void *handle, uint64_t address, const void *buffer, size_t size)
{
    task_t task;
    size_t total = 0;
    if (!xx_process_posix_decode_task(handle, &task)) return -1;
    if (!size) return 0;
    if (!xx_process_posix_request(address, buffer, &size)) return -1;
    while (total < size) {
        /* mach_vm_write's data count is 32-bit even for a 64-bit task. */
        size_t amount = size - total < XX_PROCESS_POSIX_CHUNK ? size - total : XX_PROCESS_POSIX_CHUNK;
        kern_return_t result = mach_vm_write(task, (mach_vm_address_t)(address + total),
                                            (vm_offset_t)(uintptr_t)((const unsigned char *)buffer + total),
                                            (mach_msg_type_number_t)amount);
        if (result != KERN_SUCCESS) { xx_process_posix_mach_error(result, 0); return total ? (ssize_t)total : -1; }
        total += amount;
    }
    return (ssize_t)total;
}

int xx_io_platform_process_close(void *handle)
{
    task_t task;
    kern_return_t result;
    if (!xx_process_posix_decode_task(handle, &task)) return -1;
    result = mach_port_deallocate(mach_task_self(), task);
    return result == KERN_SUCCESS ? 0 : xx_process_posix_mach_error(result, 0);
}

void *xx_io_platform_process_adopt(void *native)
{
    task_t task;
    mach_port_type_t type = 0;
    kern_return_t result;
    if (!xx_process_posix_decode_task(native, &task)) return NULL;
    result = mach_port_type(mach_task_self(), task, &type);
    if (result != KERN_SUCCESS) { xx_process_posix_mach_error(result, 0); return NULL; }
    if (!(type & MACH_PORT_TYPE_SEND)) { errno = type & MACH_PORT_TYPE_DEAD_NAME ? ESRCH : EBADF; return NULL; }
    /* No retain here: the portable device borrows this exact send right and
     * does not call the close hook when that device is destroyed. */
    return native;
}

#else
void *xx_io_platform_process_open_ex(uint64_t pid, unsigned access)
{
    pid_t checked;
    if (!xx_process_posix_access(access) || !xx_process_posix_pid(pid, &checked)) return NULL;
    errno = ENOTSUP;
    return NULL;
}

void *xx_io_platform_process_open(uint64_t pid)
{
    return xx_io_platform_process_open_ex(pid, XX_PROCESS_POSIX_READ_WRITE);
}

ssize_t xx_io_platform_process_read(void *handle, uint64_t address, void *buffer, size_t size)
{
    (void)handle; (void)address; (void)buffer; (void)size;
    errno = ENOTSUP;
    return -1;
}

ssize_t xx_io_platform_process_write(void *handle, uint64_t address, const void *buffer, size_t size)
{
    (void)handle; (void)address; (void)buffer; (void)size;
    errno = ENOTSUP;
    return -1;
}

int xx_io_platform_process_close(void *handle)
{
    (void)handle;
    errno = ENOTSUP;
    return -1;
}

void *xx_io_platform_process_adopt(void *native)
{
    (void)native;
    errno = ENOTSUP;
    return NULL;
}
#endif
#undef XX_PROCESS_POSIX_READ
#undef XX_PROCESS_POSIX_WRITE
#undef XX_PROCESS_POSIX_READ_WRITE
#undef XX_PROCESS_POSIX_CHUNK
#endif
