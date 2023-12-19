
#ifndef GIANT_MAT3_H
#define GIANT_MAT3_H
#include "types.h"
#include<stdio.h>

#define MAT3_INIT {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}
#define MAT3_IDENTITY_INIT {{1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}}

void giant_mat3_init(mat3_t* restrict mat);

void giant_mat3_identity_init(mat3_t* restrict mat);

void giant_mat3_copy(mat3_t mat1, mat3_t* restrict mat2);

void giant_mat3_mult(mat3_t* restrict mat1, mat3_t mat2);

void giant_mat3_scale(mat3_t* restrict mat, vec3_t vec);

void giant_mat3_rotate(mat3_t* mat, vec3_t vec, float angle);

void giant_mat3_mult_vec4(mat3_t mat, vec4_t* restrict vec);

void giant_mat3_mult_vec3(mat3_t mat, vec3_t* restrict vec);

void giant_mat3_print(mat3_t mat);

#endif
