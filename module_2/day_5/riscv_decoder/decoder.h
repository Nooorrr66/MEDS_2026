#ifndef DECODER_H
#define DECODER_H
#include <stdio.h>
#include <stdint.h>
#include "common.h"

#ifdef RV64
typedef uint64_t reg_t;
#else
typedef uint32_t reg_t;
#endif


void decode(uint32_t instruction);

#endif
