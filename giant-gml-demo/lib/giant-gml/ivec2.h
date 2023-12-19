
#ifndef GIANT_ivec2_H
#define GIANT_ivec2_H

#include "types.h"

#define iVEC2_INIT {0, 0}

void giant_ivec2_init(ivec2_t* restrict vec);

void giant_ivec2_copy(ivec2_t vec1, ivec2_t* restrict ivec2);

void giant_ivec2_add(ivec2_t* restrict vec, ivec2_t arg);

void giant_ivec2_add_to(ivec2_t vec, ivec2_t arg, ivec2_t* restrict dest);

void giant_ivec2_sub(ivec2_t* restrict vec, ivec2_t arg);

void giant_ivec2_sub_to(ivec2_t vec, ivec2_t arg, ivec2_t* restrict dest);

void giant_ivec2_scale(ivec2_t* vec, float scale);

void giant_ivec2_scale_to(ivec2_t vec, float scale, ivec2_t* restrict dest);

void giant_ivec2_print(ivec2_t vec);

#endif
