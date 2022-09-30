/*
 * md5 test for MD5 hash, based on algorithm found on Wikipedia
 * Copyright (C) 2022 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "md5.h"
#include "test/test.h"

TEST_F(md5, Md5) {
    char iv[] = "\xd4\x1d\x8c\xd9\x8f\x00\xb2\x04\xe9\x80\x09\x98\xec\xf8\x42\x7e";
    char data0[16] = {0};
    char digest[16] = {0};
    size_t size = sizeof(data0);
    EXPECT_EQ(1, md5(0, 0, 0));
    EXPECT_EQ(1, md5(0, 0, size));
    EXPECT_EQ(1, md5(0, data0, 0));
    EXPECT_EQ(1, md5(0, data0, size));
    EXPECT_EQ(0, md5(digest, 0, 0));
    EXPECT_MEMEQ(iv, digest, sizeof(digest));
    EXPECT_EQ(1, md5(digest, 0, size));
    EXPECT_EQ(0, md5(digest, data0, 0));
    EXPECT_MEMEQ(iv, digest, sizeof(digest));
    char digest0[] = "\x4a\xe7\x13\x36\xe4\x4b\xf9\xbf\x79\xd2\x75\x2e\x23\x48\x18\xa5";
    EXPECT_EQ(0, md5(digest, data0, size));
    EXPECT_MEMEQ(digest0, digest, sizeof(digest));
    char digest1[] = "\x23\xdb\x69\x82\xca\xef\x9e\x91\x52\xf1\xa5\xb2\x58\x9e\x6c\xa3";
    char data1[] = "They are deterministic";
    size = sizeof(data1) - 1;
    EXPECT_EQ(0, md5(digest, data1, size));
    EXPECT_MEMEQ(digest1, digest, sizeof(digest));
}
