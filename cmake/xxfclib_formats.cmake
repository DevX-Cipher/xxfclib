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
xxfclib_configure_streams(xxfclib)
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

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_apple_diags_tests.cmake")

unset(_xxfc_formats_profile_libraries)
unset(_xxfc_formats_profile_source_count)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_eid_crypto_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_eid_reader_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_natata_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_fox_sqz_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_stor_resource_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_lyme_sfx_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_installshield_obl_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_pftw_pkg_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_autoplay_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_sod_installer_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_starforce_ovl_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_stuffit5_sfx_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_self_unstuffer_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_secura_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_patchwise_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_installjammer_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_tarma_legacy_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_kirikiri_xp3_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_ar_legacy_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_aixbff_volume_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_bigf_nameless_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_binhex_name_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_cfl_lzo_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_lz4_overlay_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_amigalzx_crlf_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_cramfs_page_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_gob_terminal_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_gst_prefix_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_ibmzpak_short_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_insa_empty_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_isskin_overlay_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_ivt_empty_key_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_ivt_index_only_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_asymetrix_empty_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_instalit_footer_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_jgpak_banner_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_kboom_short_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_lofi_memory_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_macbinary_paint_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_macbinary_secondary_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_makeself_nvidia_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_mi10_padding_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_mpq_hash_count_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_mva_volume_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_pdb_empty_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_pyz_namespace_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_refpack_alignment_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_rnca_order_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_rtpatch_metadata_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_sfx7zip_resource_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_lzma_context_tests.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_sfxarj_resource_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_arq_advisory_tests.cmake")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/xxfclib_sfxcab_bss_tests.cmake")
