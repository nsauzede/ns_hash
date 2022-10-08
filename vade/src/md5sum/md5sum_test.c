/*
 * md5sum test for naive reimplementation of classic tool (using custom md5 lib)
 * Copyright (C) 2022 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#define _POSIX_C_SOURCE 2       // for popen

#include "test/test.h"

#include <stdio.h>

static int exec_command_and_get_output(char *output, int output_size, const char *command) {
    FILE *fp;
    fp = popen(command, "r");
    if (!fp) return 1;
    void *res = fgets(output, output_size, fp);
    pclose(fp);
    if (!res) return 1;
    return 0;
}

TEST_F(md5sum, Md5sum) {
    const char ref_empty[] = "d41d8cd98f00b204e9800998ecf8427e";
    char buf[1024];
    int res;
    memset(buf, 0, sizeof(buf));
    res = exec_command_and_get_output(buf, sizeof(buf), "echo -n '' | md5sum | cut -f 1 -d ' ' -z");
    EXPECT_TRUE(res == 0);
    EXPECT_STREQ(buf, ref_empty);
    memset(buf, 0, sizeof(buf));
    res = exec_command_and_get_output(buf, sizeof(buf), "echo -n '' | vade/bin/md5sum/md5sum.exe | cut -f 1 -d ' ' -z");
    EXPECT_TRUE(res == 0);
    EXPECT_STREQ(buf, ref_empty);
}
