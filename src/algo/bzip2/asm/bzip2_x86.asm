; Copyright (c) 2026 hors<horsicq@gmail.com>
; SPDX-License-Identifier: MIT
;
; MSVC x86 (32-bit) BZip2 Decompressor Acceleration Engine

.386
.MODEL FLAT, C
OPTION CASEMAP:NONE

_TEXT SEGMENT

PUBLIC xx_bzip2_bwt_traverse_x86
xx_bzip2_bwt_traverse_x86 PROC C USES ebx esi edi ebp, \
    tt:DWORD, \
    tt_count:DWORD, \
    orig_ptr:DWORD, \
    dest:DWORD, \
    dest_cap:DWORD, \
    out_written:DWORD

    mov     edx, tt_count
    test    edx, edx
    jle     @@fail
    mov     eax, orig_ptr
    cmp     eax, edx
    jae     @@fail
    mov     edi, dest
    test    edi, edi
    jz      @@fail

    mov     esi, tt
    mov     ebx, dest               ; base
    mov     eax, [esi + eax*4]      ; t = tt[orig_ptr]

    xor     edx, edx                ; rle_count = 0
    mov     ecx, 100h               ; prev_byte = 0x100

@@loop:
    movzx   ebp, al                 ; ob = t & 0xFF
    shr     eax, 8                  ; index = t >> 8
    mov     eax, [esi + eax*4]      ; t = tt[index]

    cmp     edx, 4
    je      @@is_rle4

    cmp     ebp, ecx
    jne     @@diff_byte
    inc     edx                     ; rle_count++
    mov     [edi], bpl
    inc     edi
    dec     tt_count
    jnz     @@loop
    jmp     @@success

@@diff_byte:
    mov     ecx, ebp                ; prev_byte = ob
    mov     edx, 1                  ; rle_count = 1
    mov     [edi], bpl
    inc     edi
    dec     tt_count
    jnz     @@loop
    jmp     @@success

@@is_rle4:
    test    ebp, ebp
    jz      @@rle_fill_done
    push    eax
    mov     eax, ecx
    mov     ecx, ebp
@@fill_loop:
    mov     [edi], al
    inc     edi
    dec     ecx
    jnz     @@fill_loop
    mov     ecx, eax
    pop     eax

@@rle_fill_done:
    xor     edx, edx                ; rle_count = 0
    mov     ecx, 100h               ; prev_byte = 0x100
    dec     tt_count
    jnz     @@loop

@@success:
    sub     edi, ebx
    mov     eax, out_written
    test    eax, eax
    jz      @@ret_true
    mov     [eax], edi
@@ret_true:
    mov     eax, 1
    ret

@@fail:
    xor     eax, eax
    ret
xx_bzip2_bwt_traverse_x86 ENDP

PUBLIC xx_bzip2_bwt_build_x86
xx_bzip2_bwt_build_x86 PROC C USES ebx esi edi ebp, \
    bwt_bytes:DWORD, \
    tt:DWORD, \
    freq:DWORD, \
    tt_count:DWORD

    LOCAL cum[256]:DWORD

    mov     cum[0], 0
    mov     esi, freq
    xor     ecx, ecx
    xor     edx, edx
@@cum_loop:
    mov     eax, [esi + ecx*4]
    add     edx, eax
    inc     ecx
    mov     cum[ecx*4], edx
    cmp     ecx, 255
    jl      @@cum_loop

    mov     esi, bwt_bytes
    mov     edi, tt
    xor     ecx, ecx
    mov     ebx, tt_count
    test    ebx, ebx
    jle     @@done

@@scatter_loop:
    movzx   eax, byte ptr [esi + ecx]
    mov     edx, cum[eax*4]
    inc     cum[eax*4]
    mov     ebp, ecx
    shl     ebp, 8
    or      ebp, eax
    mov     [edi + edx*4], ebp

    inc     ecx
    cmp     ecx, ebx
    jl      @@scatter_loop

@@done:
    ret
xx_bzip2_bwt_build_x86 ENDP

_TEXT ENDS
END
