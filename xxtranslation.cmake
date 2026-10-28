# Memory-only PO reader. The consumer supplies xx_mem_* and xx_rt_* primitives
# (xxio.cmake provides them for hosted targets). No gettext/libintl dependency.
set(XXTRANSLATION_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set(XXTRANSLATION_SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/translation/xx_translation.c")
# Add this separately when file loading is wanted, with xxio.cmake's sources.
set(XXTRANSLATION_IO_SOURCES "${CMAKE_CURRENT_LIST_DIR}/src/translation/xx_translation_io.c")
