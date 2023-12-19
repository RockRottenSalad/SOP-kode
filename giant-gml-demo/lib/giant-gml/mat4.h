
#ifndef GIANT_MAT4_H
#define GIANT_MAT4_H
#include "types.h"
#include<stdio.h>

#define MAT4_INIT {{0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}}
#define MAT4_IDENTITY_INIT {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}}

void giant_mat4_init(mat4_t* restrict mat);

void giant_mat4_identity_init(mat4_t* restrict mat);

void giant_mat4_copy(mat4_t mat1, mat4_t* restrict mat2);

void giant_mat4_mult(mat4_t* restrict mat1, mat4_t mat2);

void giant_mat4_translate(mat4_t* restrict mat, vec3_t vec);

void giant_mat4_scale(mat4_t* restrict mat, vec3_t vec);

void giant_mat4_rotate(mat4_t* mat, vec3_t vec, float angle);

void giant_mat4_mult_vec4(mat4_t mat, vec4_t* restrict vec);

void giant_mat4_mult_vec3(mat4_t mat, vec3_t* restrict vec);

void giant_mat4_perspective(mat4_t* restrict mat, float n_z, float f_z, float aspect);

void giant_mat4_perspective_fov(mat4_t* restrict mat, float n_z, float f_z, float aspect, float fov);

void giant_mat4_lookat(mat4_t* restrict mat, vec3_t pos, vec3_t direction);

void giant_mat4_print(mat4_t mat);

#endif
