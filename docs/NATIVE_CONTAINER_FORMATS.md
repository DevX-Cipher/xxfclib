# Native container readers

Each file format owns its implementation in `src/formats/<format>/xx_<format>.c`
and its public interface in `include/xxfclib/formats/<format>/xx_<format>.h`.
For example, PBO uses `src/formats/game/pbo/xx_pbo.c` and
`include/xxfclib/formats/game/pbo/xx_pbo.h`. Public constructors and abstract
extractors/detectors are defined by each module. Reader entries use the ordinary
`samples/unpack/xxfc_readers.c` registry; stable type values are declared directly
in `include/xxfclib/xxfc_defs.h`, with detection and labels in
`src/formats/xx_format.c`.
These readers enumerate and decode member data. They never execute the input,
launch an installer or require external extraction executables.
TEST reads and decompresses into memory through the ordinary archive API.
Extraction writes only when an output path is supplied.
FAT and Starkit extraction now honors the overwrite option; the default uses
an exclusive file open so an existing destination is preserved.

## Implemented layouts

| Family | Formats | Decoding and integrity |
| --- | --- | --- |
| Streams | ZXML, ZISOFS, NVP, SQZE, ZIP PSC, CRX | Bounded zlib/deflate chunks, typed NVP resources, SQZE LZSS/XOR, transformed ZIP device, CRX2/3 header and protobuf framing; existing ZIP payload CRC and password handling |
| Compressed | DCS, MSKN1/2/3, CSQ, Zoot1, RDFZ, ZBEOS, Solaris compressed packages | LZMS, skin pixel/theme data, native bounded stream decoding, CPIO package members; declared sizes and available checksums |
| Games/resources | GTA IMG v2, PBO, PIRS/LIVE/CON STFS, PAM PAK, PFPK, PX, SBPAK, Titan Quest ARC, CGJP, Birdies, XUIZ | Actual stored/compressed resource bytes; PBO additive checksum, STFS SHA1 tree and block hashes, Titan Quest Adler32, bounded tables and normalized paths |
| Vendor containers | Shell-prefixed Starkit, EVD, DeskSoft, MetaProducts, VisualWare, Lyme SFX, Audials CMP, PSA diagnostic disk, WebExe | Embedded native Starkit/FAT, image slices, installer file tables, LH1, legacy and transformed gzip containers, zlib and ZIP local-record payloads; available CRC32/Adler32 and strict framing |
| Legacy compression | ASD, CFD, RDC, Fox SQZ, SKF, OSL2000, LDS | Native decoding, framing/length validation and available checksums; Fox SQZ embedded keys retained as password metadata |
| Disk wrappers | DCP, Sony TCJN images | Geometry/header validation, complete stored or RDC-decoded floppy images, Sony zlib payload and Adler32 validation |

## Individual module folders

The source and public-header folder names are:

| Family | Folders beneath `src/formats/` and `include/xxfclib/formats/` |
| --- | --- |
| Streams | `zxml`, `zisofs`, `nvp`, `sqze`, `zip_psc`, `crx_native` |
| Compressed data | `dcs`, `mskn1`, `mskn2`, `mskn3`, `csq`, `zoot1`, `rdfz`, `zbeos`, `solarispkg_zip` |
| Games/resources | `gta_img`, `pbo`, `pirs`, `pam_pak`, `pfpk`, `px`, `sbpak`, `titan_quest`, `cgjp`, `birdies`, `xuiz` |
| Vendor containers | `binsh_starkit`, `evd`, `desksoft`, `metaproducts`, `visualware`, `lyme_sfx`, `audials`, `psa_disk`, `webexe` |
| Legacy compression | `asd`, `cfd`, `rdc`, `fox_sqz`, `skf`, `osl2000`, `lds` |
| Disk wrappers | `dcp_disk`, `sony_image` |

The stream readers' grammar provenance and corpus results are recorded in
[STREAM_READERS_PROVENANCE.md](STREAM_READERS_PROVENANCE.md).

DCS uses the Windows system Cabinet decompression API with raw LZMS. It has no
external executable dependency; DCS decoding is currently Windows-specific.
Other readers use the library's native codecs.

RDC has no magic signature. Generic automatic detection requires the original
`.??_` source-name hint and a successful structural probe. An unnamed memory
device can be opened with the explicit RDC reader.

Fox SQZ credential metadata uses `embedded-key:HEX` for its recovered binary
XOR key. This does not claim recovery of the original user-entered password.
The reader uses the embedded binary key automatically, regardless of whether
the caller supplies a password option.

WebExe contains successive ZIP local records followed by an opaque vendor
index. Opening its final embedded ZIP alone can report success for only a tiny
placeholder. The WebExe reader instead consumes the complete declared local
record region and verifies every payload CRC. Repeated placeholder names become
unique numbered portable leaves. Original website/document names from the
vendor index are not recovered.

PX exports every named resource value, including thumbnail/icon/style data and
intact resource envelopes. EVD exports its actual JPEG/PNG slices. DCP exports
the complete logical disk image; filesystem interpretation remains a separate
operation on that image. These are data-bearing results, not metadata stubs.

The stopped Audiotools 3.60 extended Lyme table is now supported (see
`LYME_SFX.md`). Other unverified extended Lyme variants and the OSL2000 checksum
mismatch remain outside the validated subset. The older Fox SQZ layout is now supported (see `FOX_SQZ.md`).
The sample previously labeled an unsupported LDS variant uses a distinct STOR
resource layout, now supported by `stor_resource` (see `STOR_RESOURCE.md`).
Its first indexed container ends before an explicitly reported overlay; trailing
media and incomplete fragments are not presented as indexed archive members.
A file mislabeled CFD containing RSS is not treated as a CFD stream. A rejection
does not by itself establish that a file is corrupt.

## Validation evidence

Development evidence is preserved under the build directory:

- `arc9-native-streams`: all 2,469 corpus inputs, independent hashes of 13,865
  decoded members, plus malformed, checksum, cancellation and memory controls.
- `arc9-native-compressed`: 375 compressed inputs and 24 supported legacy
  inputs, independent decoded size/CRC checks and 74 negative controls.
- `arc9-tests/games-probe`: 151 game/resource/PSARC inputs, independent names,
  sizes and SHA256 for 20,215 records, plus 46 negative controls.
- `arc9-additions-20261009`: vendor-container tests, independent Python hashes
  of 3,248 members, independent extraction comparison for all 286 MetaProducts members,
  RAM-only tests, extraction and traversal/checksum/cancellation controls.

Positive corpus checks retain original source hashes. Archive TEST checks use
blocked temporary-directory paths as well as the library's RAM-only I/O scope.
Reference extraction comparisons use dedicated output directories and never
execute extracted members.

Layout evidence came from the input bytes, independent reference extraction
results, recovered reference-decoder routine structure and existing native codec behavior.
Relevant primary specifications include Chromium's
[CRX3 protobuf](https://chromium.googlesource.com/chromium/src.git/+/62.0.3202.58/components/crx_file/crx3.proto)
and the [Metakit documentation](https://www.equi4.com/metakit/docs.html).

InstallShield OBL libraries with the pOdA directory are supported by
`installshield_obl` (see `INSTALLSHIELD_OBL.md`). Stored compiled OBS
objects are extracted as opaque bytes with bounded directory and payload extents.

Standalone encoded PackageForTheWeb CAB payloads are supported by `pftw_pkg`.
See `PFTW_PKG.md` for key recovery, verified subset and block checksum checks.

AutoPlay IR_ZCD launcher ZIP credentials are derived from bounded project GUID
metadata by the SFX ZIP reader and accepted only after full member CRC checks.
See `AUTOPLAY_SFX.md`.

InstallJammer CRAP02 indexed resources are supported by `installjammer`.
See `INSTALLJAMMER.md` for directory framing, duplicate-entry handling and
size-delimited LZMA/raw Deflate decoding.

PatchWise ZSB chunk archives are supported by `patchwise`. See `PATCHWISE.md`
for bzip2 framing, inner records, checksum checks and resource limits.

Secura SAC1 version-2 stored/LZSS archives are supported by `secura`.
See `SECURA.md` for directory/block framing and PE launcher trailers.

Aladdin DOS Self-UnStuffer stored archives are supported by `self_unstuffer`.
See `SELF_UNSTUFFER.md` for the DOS extent, index and bounded trailing padding.

StarForce OVL version-2 localized resources are supported by `starforce_ovl`.
See `STARFORCE_OVL.md` for the zlib directory, language variants and PE certificate framing.

StuffIt 5 BD05FEEF self-extractor envelopes are handled by `stuffit5`.
See `STUFFIT5_SFX.md` for wrapper bounds, source offsets and delegated CRC validation.

Tarma QuickInstall tiz1/tiz2 solid zlib archives are handled by `tarma_installer`.
See `TARMA_LEGACY.md` for named tzff records, framing checks and resource bounds.

Spear of Destiny dated stored-block installer volumes are handled by `sod_installer`.
See `SOD_INSTALLER.md` for framing, detection requirements and limitations.

KiriKiri XP3 stored/zlib indexes and segmented members are handled by `kirikiri_xp3`.
See `XP3_COMPRESSED.md` for checksum validation, protected-empty storage and limits.
