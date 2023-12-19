
#ifndef GIANT_VEC3_H
#define GIANT_VEC3_H

#include "types.h"

#define VEC3_INIT {0.0f, 0.0f, 0.0f}

void giant_vec3_init(vec3_t* restrict vec);

void giant_vec3_copy(vec3_t vec1, vec3_t* restrict vec2);

void giant_vec3_add(vec3_t* restrict vec, vec3_t arg);

void giant_vec3_add_to(vec3_t vec, vec3_t arg, vec3_t* restrict dest);

void giant_vec3_sub(vec3_t* restrict vec, vec3_t arg);

void giant_vec3_sub_to(vec3_t vec, vec3_t arg, vec3_t* restrict dest);

void giant_vec3_scale(vec3_t* vec, float scale);

void giant_vec3_scale_to(vec3_t vec, float scale, vec3_t* restrict dest);

void giant_vec3_cross(vec3_t* restrict vec1, vec3_t vec2);

void giant_vec3_cross_to(vec3_t vec1, vec3_t vec2, vec3_t* restrict dest);

float giant_vec3_length(vec3_t vec);

float giant_vec3_dot(vec3_t vec1, vec3_t vec2);

void giant_vec3_normalize(vec3_t* restrict vec);

void giant_vec3_normalize_to(vec3_t vec, vec3_t* restrict dest);

void giant_vec3_print(vec3_t vec);

#endif
