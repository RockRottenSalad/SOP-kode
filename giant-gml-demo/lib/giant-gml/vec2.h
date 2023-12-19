
#ifndef GIANT_VEC2_H
#define GIANT_VEC2_H

#include "types.h"

#define VEC2_INIT {0.0f, 0.0f}

void giant_vec2_init(vec2_t* restrict vec);

void giant_vec2_copy(vec2_t vec1, vec2_t* restrict vec2);

void giant_vec2_add(vec2_t* restrict vec, vec2_t arg);

void giant_vec2_add_to(vec2_t vec, vec2_t arg, vec2_t* restrict dest);

void giant_vec2_sub(vec2_t* restrict vec, vec2_t arg);

void giant_vec2_sub_to(vec2_t vec, vec2_t arg, vec2_t* restrict dest);

void giant_vec2_scale(vec2_t* vec, float scale);

void giant_vec2_scale_to(vec2_t vec, float scale, vec2_t* restrict dest);

// 2D cross product is a scalar
float giant_vec2_cross(vec2_t* restrict vec1, vec2_t vec2);

float giant_vec2_length(vec2_t vec);

float giant_vec2_dot(vec2_t vec1, vec2_t vec2);

void giant_vec2_normalize(vec2_t* restrict vec);

void giant_vec2_normalize_to(vec2_t vec, vec2_t* restrict dest);

void giant_vec2_print(vec2_t vec);

#endif
