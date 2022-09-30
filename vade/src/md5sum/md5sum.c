/*
 * md5sum - naive reimplementation of classic tool (using custom md5 lib)
 * Copyright (C) 2022 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "md5/md5.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    int size = fread(buf, sizeof(buf), 1, stdin);
    unsigned char digest[16];
    int res = md5(digest, buf, size);
    if (res == 0) {
        for (int i = 0; i < sizeof(digest); i++) {
            printf("%02x", digest[i]);
        }
        printf(" - \n");
    }
    return !(res == 0);
}
