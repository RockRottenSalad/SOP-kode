
#ifndef GIANT_TYPES_H
#define GIANT_TYPES_H

#include<stdio.h>
#include<math.h>

#define X 0
#define Y 1
#define Z 2
#define W 3

#define DEG2RAD M_PI/180.0f
#define RAD2DEG 180.0f/M_PI

typedef int      ivec2_t[2];

typedef float    vec2_t[2];
typedef float    vec3_t[3];
typedef float    vec4_t[4];

typedef vec2_t   mat2_t[3];
typedef vec3_t   mat3_t[3];
typedef vec4_t   mat4_t[4];

#endif
