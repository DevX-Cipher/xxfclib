/* Copyright (c) 2026 hors<horsicq@gmail.com>
 * SPDX-License-Identifier: MIT
 */
#ifndef XX_FORMAT_STREAM_FEATURES_H
#define XX_FORMAT_STREAM_FEATURES_H

/* CMake publishes explicit values. Manual full-library builds keep historical
 * availability unless they select a smaller set of source files and flags. */
#ifndef XXFC_ENABLE_STREAM_DATASTRUCTS
#define XXFC_ENABLE_STREAM_DATASTRUCTS 1
#endif
#ifndef XXFC_ENABLE_STREAM_IMPORT
#define XXFC_ENABLE_STREAM_IMPORT 1
#endif
#ifndef XXFC_ENABLE_STREAM_EXPORT
#define XXFC_ENABLE_STREAM_EXPORT 1
#endif
#ifndef XXFC_ENABLE_STREAM_RESOURCES
#define XXFC_ENABLE_STREAM_RESOURCES 1
#endif
#ifndef XXFC_ENABLE_STREAM_METADATA
#define XXFC_ENABLE_STREAM_METADATA 1
#endif
#ifndef XXFC_ENABLE_STREAM_SYMBOLS
#define XXFC_ENABLE_STREAM_SYMBOLS 1
#endif

#endif
