#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

#ifdef DEBUG

#define LOG(fmt, ...) \
fprintf(stderr, "[DEBUG] " fmt "\n", ##__VA_ARGS__)

#else

#define LOG(fmt, ...)

#endif

#endif
