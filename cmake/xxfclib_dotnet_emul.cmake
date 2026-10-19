# Explicit PE/CLI reader sources for managed assembly consumers.
set(XXFC_EMUL_DEFINITIONS XXFC_PROFILE_DOTNET_EMUL)
set(XXFC_EMUL_FORMAT_SOURCES
    src/formats/executable/pe/xx_pe.c src/formats/executable/pe/xx_pe_data.c
    src/formats/executable/pe/xx_pe_inspect.c
    src/formats/executable/pe/xx_pe_stream_common.c src/formats/executable/pe/xx_pe_stream_coff.c
    src/formats/executable/pe/xx_pe_stream_metadata.c src/formats/executable/pe/xx_pe_stream_symbols.c
    src/formats/executable/dotnet/xx_dotnet.c src/formats/executable/dotnet/xx_dotnet_data.c
    src/formats/executable/dotnet/platforms/xx_dotnet_us_simd.h
    src/formats/executable/dotnet/platforms/xx_dotnet_us_sse2.c
    src/formats/executable/dotnet/platforms/xx_dotnet_us_avx2.c
    src/formats/executable/dotnet/xx_dotnet_inspect.c src/formats/executable/dotnet/xx_dotnet_reader.c)
include("${CMAKE_CURRENT_LIST_DIR}/xxfclib_emul_common.cmake")
