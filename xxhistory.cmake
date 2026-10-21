# Reusable command history. Include these sources in a C11 target which already
# supplies xxfclib's memory and runtime primitives (xx_mem_*, xx_rt_strlen and
# xx_rt_memcpy). There are no I/O, platform, UI or thread dependencies here.
# For a self-contained hosted target, xxio.cmake supplies those primitives;
# combine the source lists with list(REMOVE_DUPLICATES ...) when appropriate.
set(XXHISTORY_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(XXHISTORY_INCLUDE_DIRS "${XXHISTORY_INCLUDE_DIR}")
set(XXHISTORY_SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/history/xx_history.c")
set(XXHISTORY_COMPILE_DEFINITIONS)
set(XXHISTORY_LIBRARIES)
