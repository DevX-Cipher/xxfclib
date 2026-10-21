# Hosted static library containing xxfclib's format readers, archive algorithms
# and settings support. This profile intentionally stops before the full DIE
# engine and its sibling cdisasm project are evaluated.
include(GNUInstallDirs)

if(BUILD_SHARED_LIBS OR XXFC_STATIC_NO_CRT OR XXFC_BUILD_BOTH)
    message(FATAL_ERROR
        "The formats profile supports one hosted static library; use full for CRT-free or dual builds")
endif()

include("${CMAKE_CURRENT_SOURCE_DIR}/xxformats.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/xxsettings.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/xxterminal.cmake")

set(XXFC_FORMATS_PROFILE_SOURCES
    src/history/xx_history.c
    ${XXFORMATS_SOURCES}
    ${XXSETTINGS_SOURCES}
    ${XXTERMINAL_SOURCES})
list(REMOVE_DUPLICATES XXFC_FORMATS_PROFILE_SOURCES)

add_library(xxfclib STATIC ${XXFC_FORMATS_PROFILE_SOURCES})
add_library(xxfclib::xxfclib ALIAS xxfclib)
target_compile_features(xxfclib PUBLIC c_std_11)
target_compile_definitions(xxfclib
    PUBLIC XXFC_STATIC XXFC_FORMATS_ONLY=1
    PRIVATE XXFC_NO_EXTERNAL_HELPERS=1)
target_include_directories(xxfclib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE ${XXFORMATS_INCLUDE_DIRS})

set(_xxfc_formats_profile_libraries
    ${XXFORMATS_LIBRARIES}
    ${XXSETTINGS_LIBRARIES})
list(REMOVE_DUPLICATES _xxfc_formats_profile_libraries)
target_link_libraries(xxfclib PUBLIC ${_xxfc_formats_profile_libraries})

set_target_properties(xxfclib PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS OFF
    POSITION_INDEPENDENT_CODE ON)
if(MSVC)
    target_compile_options(xxfclib PRIVATE /W4 /utf-8)
    target_compile_definitions(xxfclib PRIVATE _CRT_SECURE_NO_WARNINGS)
else()
    target_compile_options(xxfclib PRIVATE -Wall -Wextra -Wpedantic)
endif()

list(LENGTH XXFC_FORMATS_PROFILE_SOURCES _xxfc_formats_profile_source_count)
message(STATUS
    "xxfclib formats profile: ${_xxfc_formats_profile_source_count} C sources; external helpers disabled")

install(TARGETS xxfclib EXPORT xxfclibTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/xxfclib"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT xxfclibTargets
    FILE xxfclibTargets.cmake
    NAMESPACE xxfclib::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/xxfclib)

unset(_xxfc_formats_profile_libraries)
unset(_xxfc_formats_profile_source_count)
