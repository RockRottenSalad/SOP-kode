
#ifndef GIANT_MAT2_H
#define GIANT_MAT2_H
#include "types.h"
#include<stdio.h>

#define MAT2_INIT {{0.0f, 0.0f}, {0.0f, 0.0f}}
#define MAT2_IDENTITY_INIT {{1.0f, 0.0f}, {0.0f, 1.0f}}

void giant_mat2_init(mat2_t* restrict mat);

void giant_mat2_identity_init(mat2_t* restrict mat);

void giant_mat2_copy(mat2_t mat1, mat2_t* restrict mat2);

void giant_mat2_mult(mat2_t* restrict mat1, mat2_t mat2);

void giant_mat2_translate(mat2_t* restrict mat, vec3_t vec);

void giant_mat2_scale(mat2_t* restrict mat, vec3_t vec);

void giant_mat2_rotate(mat2_t* mat, float angle);

void giant_mat2_mult_vec4(mat2_t mat, vec4_t* restrict vec);

void giant_mat2_mult_vec3(mat2_t mat, vec3_t* restrict vec);

void giant_mat2_print(mat2_t mat);

#endif
