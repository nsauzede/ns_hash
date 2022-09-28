/*
 * md5 - MD5 hash, based on algorithm found on Wikipedia
 * Copyright (C) 2022 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef MD5_H__
#define MD5_H__

#include <stddef.h>

int md5(char digest[16], const char *data, size_t size);

#endif/*MD5_H__*/
