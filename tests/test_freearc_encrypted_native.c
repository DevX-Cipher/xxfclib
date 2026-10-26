/* Copyright (c) 2026 hors<horsicq@gmail.com>. SPDX-License-Identifier: MIT */
#include "xxfclib/formats/archive/freearc/xx_freearc.h"
#include "xxfclib/io/xx_io.h"
#include "xxfclib/memory/xx_memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(x) do { if (!(x)) { fprintf(stderr, "FreeArc encrypted line %d: %s\n", __LINE__, #x); exit(1); } } while (0)

struct freearc_cipher_vector {
    const char *name, *method, *password_utf8;
    const unsigned char *ciphertext;
    size_t ciphertext_size;
    const unsigned char *expected;
    size_t expected_size;
};
#include "fixtures/freearc_encrypted/cipher_vectors.inc"

static unsigned char *copy_bytes(const unsigned char *data, size_t size)
{
    unsigned char *p = (unsigned char *)xx_mem_alloc(size ? size : 1U);
    CHECK(p);
    if (size) memcpy(p, data, size);
    return p;
}

static bool cancel_kdf(const xx_pd_struct *pd, void *context)
{
    unsigned *calls = (unsigned *)context;
    (void)pd;
    return ++*calls >= 4U;
}

static void test_vectors(void)
{
    size_t i;
    for (i = 0U; i < sizeof(freearc_cipher_vectors) / sizeof(freearc_cipher_vectors[0]); ++i) {
        const struct freearc_cipher_vector *v = &freearc_cipher_vectors[i];
        unsigned char *out = NULL;
        size_t size = 0U;
        xx_pd_struct pd = xx_pd_init();
        CHECK(xx_freearc_method_supported(v->method));
        if (!xx_freearc_decode_chain_password(v->method, copy_bytes(v->ciphertext, v->ciphertext_size), v->ciphertext_size,
                                               (int64_t)v->expected_size, v->password_utf8, &out, &size, &pd)) {
            fprintf(stderr, "vector %s: %s\n", v->name, pd.error_string);
            CHECK(false);
        }
        CHECK(size == v->expected_size && (!size || !memcmp(out, v->expected, size)));
        xx_mem_free(out);
        out = NULL;
        CHECK(!xx_freearc_decode_chain(v->method, copy_bytes(v->ciphertext, v->ciphertext_size), v->ciphertext_size,
                                      (int64_t)v->expected_size, &out, &size, NULL));
        CHECK(!out && !size);
        /* The intentionally verifier-free upstream variant relies on the
         * surrounding archive CRC, so it cannot reject a password itself. */
        if (!strstr(v->method, ":c:")) {
            CHECK(!xx_freearc_decode_chain_password(v->method, copy_bytes(v->ciphertext, v->ciphertext_size), v->ciphertext_size,
                                                    (int64_t)v->expected_size, "incorrect", &out, &size, NULL));
            CHECK(!out && !size);
        }
    }
    CHECK(!xx_freearc_method_supported("aes-256/ctr:n1000001:s00:c0000:i00000000000000000000000000000000"));
    CHECK(!xx_freearc_method_supported("aes-256/ctr:r13:s00:c0000:i00000000000000000000000000000000"));
    CHECK(!xx_freearc_method_supported("aes-256/ctr:n1:n2:s00:c0000:i00000000000000000000000000000000"));
    CHECK(!xx_freearc_method_supported("aes-256/ctr:s0z:c0000:i00000000000000000000000000000000"));
    CHECK(!xx_freearc_method_supported("aes-256/ctr:s00:c0000:i0000"));
    {
        xx_pd_struct pd = xx_pd_init();
        xx_pd_observer old;
        unsigned calls = 0U;
        unsigned char *out = NULL;
        size_t size = 0U;
        old = xx_pd_set_observer(&pd, cancel_kdf, &calls);
        CHECK(!xx_freearc_decode_chain_password("aes-256/ctr:n1000000:s00:c0000:i00000000000000000000000000000000",
                                                copy_bytes((const unsigned char *)"x", 1U), 1U, 1, "password", &out, &size, &pd));
        CHECK(calls >= 4U && !out && !size);
        xx_pd_set_observer(old.progress, old.callback, old.user_data);
    }
}

static void test_archive(const char *root, const char *filename, bool metadata, bool members)
{
    char path[4096];
    xx_io_device *device;
    xx_freearc *archive;
    xx_archive_record_state *state, *second;
    const xx_archive_record *record;
    xx_pd_struct pd = xx_pd_init();
    snprintf(path, sizeof(path), "%s/%s", root, filename);
    device = xx_io_file_open(path, "rb");
    CHECK(device);
    archive = xx_freearc_create(device, 0);
    CHECK(archive && xx_freearc_check_is_valid(&archive->format, NULL));
    CHECK(xx_freearc_handle_base_info(&archive->format, NULL));
    CHECK(archive->format.is_crypted == metadata);
    if (metadata) {
        CHECK(!xx_freearc_create_archive_records_reading(&archive->format, NULL, &pd));
        CHECK(strstr(pd.error_string, "requires a password"));
        CHECK(xx_format_set_password(&archive->format, "incorrect"));
        pd = xx_pd_init();
        CHECK(!xx_freearc_create_archive_records_reading(&archive->format, NULL, &pd));
        CHECK(strstr(pd.error_string, "incorrect"));
    }
    CHECK(xx_format_set_password(&archive->format, "FreeArc-fixture-password"));
    CHECK(xx_freearc_get_number_of_archive_records(&archive->format, NULL) == 2U);
    state = xx_freearc_create_archive_records_reading(&archive->format, NULL, NULL);
    CHECK(state);
    record = xx_freearc_get_current_archive_record(&archive->format, state);
    CHECK(record && !strcmp(xx_archive_record_get_original_name(record), "first.txt"));
    CHECK(xx_archive_record_get_meta_bool(record, XX_META_ID_IS_ENCRYPTED, false) == members);
    CHECK(xx_freearc_unpack_current_archive_record(&archive->format, state, NULL));
    CHECK(xx_format_set_password(&archive->format, "incorrect"));
    CHECK(xx_freearc_get_number_of_archive_records(&archive->format, NULL) == (metadata ? 0U : 2U));
    CHECK(xx_freearc_unpack_current_archive_record(&archive->format, state, NULL) == !members);
    CHECK(xx_format_set_password(&archive->format, "FreeArc-fixture-password"));
    CHECK(xx_freearc_get_number_of_archive_records(&archive->format, NULL) == 2U);
    /* The first stream remains alive while the reader replaces its cached
     * index after password changes. Both lifetimes must remain valid. */
    second = xx_freearc_create_archive_records_reading(&archive->format, NULL, NULL);
    CHECK(second && xx_freearc_unpack_current_archive_record(&archive->format, second, NULL));
    CHECK(xx_freearc_archive_record_move_to_next(&archive->format, state, NULL));
    record = xx_freearc_get_current_archive_record(&archive->format, state);
    CHECK(record && !strcmp(xx_archive_record_get_original_name(record), "second.bin"));
    CHECK(xx_freearc_unpack_current_archive_record(&archive->format, state, NULL));
    xx_freearc_free_archive_records_reading(&archive->format, state);
    CHECK(xx_format_set_password(&archive->format, NULL));
    CHECK(xx_freearc_unpack_current_archive_record(&archive->format, second, NULL) == !members);
    xx_freearc_free_archive_records_reading(&archive->format, second);
    xx_freearc_free(archive);
    xx_io_close(device);
}

int main(int argc, char **argv)
{
    CHECK(argc == 2);
    test_vectors();
    test_archive(argv[1], "legacy_headers_and_members.arc", true, true);
    test_archive(argv[1], "fixed_headers_and_members.arc", true, true);
    test_archive(argv[1], "legacy_members_only.arc", false, true);
    test_archive(argv[1], "plain.arc", false, false);
    puts("FreeArc encrypted known answers, containers, password changes and cancellation passed");
    return 0;
}
