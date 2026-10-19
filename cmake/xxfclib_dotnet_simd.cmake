# Keep instruction-set flags local to the runtime-dispatched #US backends.
# Call from the directory that owns the consumer target, including focused
# consumers that compile a source subset instead of adding xxfclib itself.
include_guard(GLOBAL)

function(xxfclib_configure_dotnet_simd_sources source_dir)
    get_filename_component(_xxfc_dotnet_root "${source_dir}" ABSOLUTE)
    get_property(_xxfc_dotnet_configured DIRECTORY PROPERTY XXFC_DOTNET_SIMD_ROOTS)
    if(_xxfc_dotnet_root IN_LIST _xxfc_dotnet_configured)
        return()
    endif()
    set_property(DIRECTORY APPEND PROPERTY XXFC_DOTNET_SIMD_ROOTS "${_xxfc_dotnet_root}")

    set_source_files_properties(
        "${_xxfc_dotnet_root}/src/formats/executable/dotnet/platforms/xx_dotnet_us_simd.h"
        PROPERTIES HEADER_FILE_ONLY TRUE)

    if(MSVC)
        if(CMAKE_C_COMPILER_ARCHITECTURE_ID MATCHES "^(X86|x86)$")
            set_property(SOURCE "${_xxfc_dotnet_root}/src/formats/executable/dotnet/platforms/xx_dotnet_us_sse2.c"
                APPEND PROPERTY COMPILE_OPTIONS /arch:SSE2)
        endif()
        if(CMAKE_C_COMPILER_ARCHITECTURE_ID MATCHES "^(x64|X64|AMD64|amd64|X86|x86)$")
            set_property(SOURCE "${_xxfc_dotnet_root}/src/formats/executable/dotnet/platforms/xx_dotnet_us_avx2.c"
                APPEND PROPERTY COMPILE_OPTIONS /arch:AVX2)
        endif()
    elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang" AND
           CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|amd64|AMD64|[iI][3-6]86|[xX]86)$")
        set_property(SOURCE "${_xxfc_dotnet_root}/src/formats/executable/dotnet/platforms/xx_dotnet_us_sse2.c"
            APPEND PROPERTY COMPILE_OPTIONS -msse2)
        set_property(SOURCE "${_xxfc_dotnet_root}/src/formats/executable/dotnet/platforms/xx_dotnet_us_avx2.c"
            APPEND PROPERTY COMPILE_OPTIONS -mavx2)
    endif()
endfunction()
