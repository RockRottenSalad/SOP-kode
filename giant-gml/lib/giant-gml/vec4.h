
#ifndef GIANT_VEC4_H
#define GIANT_VEC4_H

#include "types.h"

#define VEC4_INIT {0.0f, 0.0f, 0.0f, 0.0f}

void giant_vec4_init(vec4_t* restrict vec);

void giant_vec4_copy(vec4_t vec1, vec4_t* restrict vec2);

void giant_vec4_add(vec4_t* restrict vec, vec4_t arg);

void giant_vec4_add_to(vec4_t vec, vec4_t arg, vec4_t* restrict dest);

void giant_vec4_sub(vec4_t* restrict vec, vec4_t arg);

void giant_vec4_sub_to(vec4_t vec, vec4_t arg, vec4_t* restrict dest);

void giant_vec4_scale(vec4_t* vec, float scale);

void giant_vec4_scale_to(vec4_t vec, float scale, vec4_t* restrict dest);

// 3D cross product, W gets set to 1
void giant_vec4_cross(vec4_t* restrict vec1, vec4_t vec2);

void giant_vec4_cross_to(vec4_t vec1, vec4_t vec2, vec4_t* restrict dest);

float giant_vec4_length(vec4_t vec);

float giant_vec4_dot(vec4_t vec1, vec4_t vec2);

void giant_vec4_normalize(vec4_t* restrict vec);

void giant_vec4_normalize_to(vec4_t vec, vec4_t* restrict dest);

void giant_vec4_print(vec4_t vec);

#endif
