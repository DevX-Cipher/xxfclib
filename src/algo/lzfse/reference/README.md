LZFSE encoder sources from https://github.com/lzfse/lzfse
Commit: e634ca58b4821d9f3d560cdc6df5dec02ffc93fd
BSD-3-Clause; see LICENSE. Sources are retained as .inc with one local correctness fix: FSE delta1
initialization avoids shifting by -1 when one symbol occupies all states
(k=0; delta1 is unreachable).
xx_lzfse_reference.h maps symbols and runtime calls into xxfclib.
Only encoder/FSE units are compiled; decoding uses the existing bounded native decoder.
