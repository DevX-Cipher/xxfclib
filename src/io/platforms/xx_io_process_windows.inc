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
 * @file xx_io_process_windows.c
 * @brief Native Windows process-memory I/O without CRT allocation.
 *
 * Included by the portable process device after its internal declarations.
 */
#if defined(_WIN32)

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "xx_io_platform.h"
#include <windows.h>
#include <errno.h>
#include <stdint.h>

/* Only error constants are used: assigning errno would import _errno in a
 * CRT-free consumer. Native operation failures retain their Win32 error. */
void xx_io_platform_process_set_error(int error)
{
    DWORD code;
    switch (error) {
        case 0: code = ERROR_SUCCESS; break;
        case EINVAL: code = ERROR_INVALID_PARAMETER; break;
        case EACCES: code = ERROR_ACCESS_DENIED; break;
        case EOVERFLOW: code = ERROR_ARITHMETIC_OVERFLOW; break;
        case ENOMEM: code = ERROR_NOT_ENOUGH_MEMORY; break;
        default: code = ERROR_GEN_FAILURE; break;
    }
    SetLastError(code);
}

void *xx_io_platform_process_alloc(size_t size)
{
    HANDLE heap;
    void *memory;
    if (!size) {
        xx_io_platform_process_set_error(EINVAL);
        return NULL;
    }
    heap = GetProcessHeap();
    if (!heap) return NULL;
    memory = HeapAlloc(heap, HEAP_ZERO_MEMORY, (SIZE_T)size);
    /* HeapAlloc does not provide a defined GetLastError value on failure. */
    if (!memory) xx_io_platform_process_set_error(ENOMEM);
    return memory;
}

void xx_io_platform_process_free(void *memory)
{
    if (memory) {
        DWORD error = GetLastError();
        (void)HeapFree(GetProcessHeap(), 0, memory);
        SetLastError(error);
    }
}

void *xx_io_platform_process_open_ex(uint64_t pid, unsigned access)
{
    DWORD rights = 0;
    if (!access || (access & ~3U) || pid > UINT32_MAX) {
        xx_io_platform_process_set_error(EINVAL);
        return NULL;
    }
    if (!pid) pid = (uint64_t)GetCurrentProcessId();
    if (access & 1U) rights |= PROCESS_VM_READ;
    if (access & 2U) rights |= PROCESS_VM_WRITE | PROCESS_VM_OPERATION;
    /* Request the VM rights required for these operations without query
     * rights or changes to the caller's privileges. */
    return (void *)OpenProcess(rights, FALSE, (DWORD)pid);
}

void *xx_io_platform_process_open(uint64_t pid)
{
    void *handle = xx_io_platform_process_open_ex(pid, 3U);
    /* Preserve the legacy read/write attempt while allowing inspection of a
     * process that grants VM_READ but refuses mutation rights. */
    return handle ? handle : xx_io_platform_process_open_ex(pid, 1U);
}

static int xx_io_win_process_range(void *handle, uint64_t address, const void *buffer, size_t size)
{
    if (!handle || (HANDLE)handle == INVALID_HANDLE_VALUE) {
        SetLastError(ERROR_INVALID_HANDLE);
        return 0;
    }
    if (size && !buffer) {
        xx_io_platform_process_set_error(EINVAL);
        return 0;
    }
    /* Windows ssize_t is SSIZE_T, with the same signed pointer-sized limit as
     * PTRDIFF_MAX. Validate the final addressed byte for both address widths. */
    if (size > (size_t)PTRDIFF_MAX || address > (uint64_t)UINTPTR_MAX ||
        (size && ((uint64_t)(size - 1U) > UINT64_MAX - address ||
                  (uint64_t)(size - 1U) > (uint64_t)UINTPTR_MAX - address))) {
        xx_io_platform_process_set_error(EOVERFLOW);
        return 0;
    }
    return 1;
}

ssize_t xx_io_platform_process_read(void *handle, uint64_t address, void *buffer, size_t size)
{
    SIZE_T done = 0;
    BOOL success;
    if (!xx_io_win_process_range(handle, address, buffer, size)) return -1;
    if (!size) return 0;
    success = ReadProcessMemory((HANDLE)handle, (LPCVOID)(uintptr_t)address, buffer, (SIZE_T)size, &done);
    /* ERROR_PARTIAL_COPY can still report useful bytes. Keep the OS error for
     * callers that inspect it, and let the device advance by the actual count. */
    return success || done ? (ssize_t)done : -1;
}

ssize_t xx_io_platform_process_write(void *handle, uint64_t address, const void *buffer, size_t size)
{
    SIZE_T done = 0;
    BOOL success;
    DWORD write_error = ERROR_SUCCESS;
    if (!xx_io_win_process_range(handle, address, buffer, size)) return -1;
    if (!size) return 0;
    success = WriteProcessMemory((HANDLE)handle, (LPVOID)(uintptr_t)address, buffer, (SIZE_T)size, &done);
    if (!success) write_error = GetLastError();
    if (done) {
        /* Flush every byte actually changed, including a partial failed write.
         * Cache-flush failure cannot undo or conceal committed memory bytes. */
        (void)FlushInstructionCache((HANDLE)handle, (LPCVOID)(uintptr_t)address, done);
        if (!success) SetLastError(write_error);
        return (ssize_t)done;
    }
    return success ? 0 : -1;
}

int xx_io_platform_process_close(void *handle)
{
    if (!handle || (HANDLE)handle == INVALID_HANDLE_VALUE) {
        SetLastError(ERROR_INVALID_HANDLE);
        return -1;
    }
    return CloseHandle((HANDLE)handle) ? 0 : -1;
}

void *xx_io_platform_process_adopt(void *native)
{
    if (!native || (HANDLE)native == INVALID_HANDLE_VALUE) {
        SetLastError(ERROR_INVALID_HANDLE);
        return NULL;
    }
    /* Read/write hooks use this HANDLE directly. Ownership stays with the
     * caller; portable device cleanup must not call close for an adopted one. */
    return native;
}

#endif /* _WIN32 */
