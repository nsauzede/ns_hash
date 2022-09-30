/*
 * md5 test for MD5 hash, based on algorithm found on Wikipedia
 * Copyright (C) 2022 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "md5.h"
#include "test/test.h"
#include <stdio.h>

TEST_F(md5, Coll) {
    TEST_LOG("Hello collision\n");
#if 1
    char digest1[16] = {0};
    char digest2[16] = {0};
#define NB 4
#define SZ ((NB * 64 - 1 - 8))
    char M1[SZ] = "The quick brown fox jumps over the lazy dog";
    char M2[SZ] = "The quick brown fox jumps over the lazy dog";
    size_t size = sizeof(M1);
    EXPECT_EQ(0, md5(digest1, M1, size));
    EXPECT_EQ(0, md5(digest2, M2, size));
    EXPECT_MEMEQ(digest1, digest2, sizeof(digest1));
#endif

    for (int i = 0; i < 256; i++) {
        unsigned long x1 = i;
        unsigned long x2 = x1 + (1 << 6);
        unsigned long xx = x1 ^ x2;
        fprintf(stderr, "x1=%lx x2=%lx xx=%lx\n", x1, x2, xx);
    }
}
