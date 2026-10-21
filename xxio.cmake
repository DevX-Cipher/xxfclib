# Standalone generic I/O: buffered, file, memory, subdevice, multivolume and
# process streams with native Windows/POSIX backends. Add XXIO_SOURCES to a
# static C11 target, define XXFC_STATIC publicly, add XXIO_INCLUDE_DIR, apply
# XXIO_COMPILE_DEFINITIONS privately, and link XXIO_LIBRARIES. The process
# backend is included by xx_io_process.c, as in xxprocessio.cmake.
set(XXIO_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(XXIO_INCLUDE_DIRS "${XXIO_INCLUDE_DIR}")
set(XXIO_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/src/io/xx_io.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/io/xx_io_buffer.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/io/xx_io_file.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/io/xx_io_mem.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/io/xx_io_memory_only.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/io/xx_io_sub.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/io/xx_io_process.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/memory/xx_memory.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/memory/xx_memory_rt.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/memory/platforms/xx_memory_sse2.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/memory/platforms/xx_memory_avx2.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/memory/platforms/xx_memory_neon.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/global/xx_global.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/global/platforms/xx_global_cpu.c"
)
set(XXIO_COMPILE_DEFINITIONS)
set(XXIO_LIBRARIES)
if(WIN32)
    list(APPEND XXIO_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/src/io/platforms/xx_io_windows.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/memory/platforms/xx_memory_windows.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/strings/platforms/xx_string_windows.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/global/platforms/xx_global_windows.c"
    )
    list(APPEND XXIO_LIBRARIES kernel32)
elseif(UNIX)
    list(APPEND XXIO_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/src/io/platforms/xx_io_posix.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/memory/platforms/xx_memory_posix.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/strings/platforms/xx_string_posix.c"
        "${CMAKE_CURRENT_LIST_DIR}/src/global/platforms/xx_global_posix.c"
        # Native I/O entropy fallback uses these libc-backed stream functions.
        "${CMAKE_CURRENT_LIST_DIR}/src/rt/platforms/xx_rt_posix.c"
    )
    list(APPEND XXIO_COMPILE_DEFINITIONS _POSIX_C_SOURCE=200809L _FILE_OFFSET_BITS=64)
    if(APPLE)
        list(APPEND XXIO_COMPILE_DEFINITIONS _DARWIN_C_SOURCE)
    endif()
else()
    message(FATAL_ERROR "xxio.cmake requires Windows or a POSIX platform")
endif()

# The memory dispatcher selects these kernels at runtime. GCC/Clang use the
# existing per-function target attributes; MSVC needs an AVX2 source flag only.
if(MSVC AND CMAKE_C_COMPILER_ARCHITECTURE_ID MATCHES "^(X86|x86|x64|AMD64)$")
    set_property(SOURCE "${CMAKE_CURRENT_LIST_DIR}/src/memory/platforms/xx_memory_avx2.c"
        APPEND PROPERTY COMPILE_OPTIONS "/arch:AVX2")
endif()
