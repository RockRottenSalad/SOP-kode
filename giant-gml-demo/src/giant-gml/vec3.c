
#include "giant-gml/vec3.h"

// usage: vec3_t x = VEC3_INIT;
#define VEC3_INIT {0.0f, 0.0f, 0.0f}

void giant_vec3_init(vec3_t* restrict vec)
{
    (*vec)[X] = 0.0f;
    (*vec)[Y] = 0.0f;
    (*vec)[Z] = 0.0f;
}

void giant_vec3_copy(vec3_t vec1, vec3_t* restrict vec2)
{
    (*vec2)[X] = vec1[X];
    (*vec2)[Y] = vec1[Y];
    (*vec2)[Z] = vec1[Z];
}

void giant_vec3_add(vec3_t* restrict vec, vec3_t arg)
{
    (*vec)[X] += arg[X];
    (*vec)[Y] += arg[Y];
    (*vec)[Z] += arg[Z];
}

void giant_vec3_add_to(vec3_t vec, vec3_t arg, vec3_t* restrict dest)
{
    (*dest)[X] = vec[X] + arg[X];
    (*dest)[Y] = vec[Y] + arg[Y];
    (*dest)[Z] = vec[Z] + arg[Z];
}

void giant_vec3_sub(vec3_t* restrict vec, vec3_t arg)
{
    (*vec)[X] -= arg[X];
    (*vec)[Y] -= arg[Y];
    (*vec)[Z] -= arg[Z];
}

void giant_vec3_sub_to(vec3_t vec, vec3_t arg, vec3_t* restrict dest)
{
    (*dest)[X] = vec[X] - arg[X];
    (*dest)[Y] = vec[Y] - arg[Y];
    (*dest)[Z] = vec[Z] - arg[Z];
}

void giant_vec3_scale(vec3_t* restrict vec, float scale)
{
    (*vec)[X] *= scale;
    (*vec)[Y] *= scale;
    (*vec)[Z] *= scale;
}

void giant_vec3_scale_to(vec3_t vec, float scale, vec3_t* restrict dest)
{
//    dest = vec;
    giant_vec3_copy(vec, dest);

    (*dest)[X] *= scale;
    (*dest)[Y] *= scale;
    (*dest)[Z] *= scale;
}

void giant_vec3_cross(vec3_t* restrict vec1, vec3_t vec2)
{
    vec3_t tmp;
    giant_vec3_copy(*vec1, &tmp);

    (*vec1)[X] = (tmp[Y] * vec2[Z]) - (tmp[Z] * vec2[Y]);
    (*vec1)[Y] = (tmp[Z] * vec2[X]) - (tmp[X] * vec2[Z]);
    (*vec1)[Z] = (tmp[X] * vec2[Y]) - (tmp[Y] * vec2[X]);

}

void giant_vec3_cross_to(vec3_t vec1, vec3_t vec2, vec3_t* restrict dest)
{
    (*dest)[X] = (vec1[Y] * vec2[Z]) - (vec1[Z] * vec2[Y]);
    (*dest)[Y] = (vec1[Z] * vec2[X]) - (vec1[X] * vec2[Z]);
    (*dest)[Z] = (vec1[X] * vec2[Y]) - (vec1[Y] * vec2[X]);
}

float giant_vec3_length(vec3_t vec)
{
    return sqrt( (vec[X]*vec[X]) + (vec[Y]*vec[Y]) + (vec[Z]*vec[Z]) );
}

float giant_vec3_dot(vec3_t vec1, vec3_t vec2)
{
    return (vec1[X] * vec2[X]) + (vec1[Y] * vec2[Y]) + (vec1[Z] * vec2[Z]);
}

void giant_vec3_normalize(vec3_t* restrict vec)
{
    float tmp = giant_vec3_length(*vec);

    (*vec)[X] /= tmp;
    (*vec)[Y] /= tmp;
    (*vec)[Z] /= tmp;
}

void giant_vec3_normalize_to(vec3_t vec, vec3_t* restrict dest)
{
    float tmp = giant_vec3_length(vec);

    giant_vec3_copy(vec, dest);

    (*dest)[X] /= tmp;
    (*dest)[Y] /= tmp;
    (*dest)[Z] /= tmp;
}

inline void giant_vec3_print(vec3_t vec)
{
    printf("%f %f %f\n", vec[X], vec[Y], vec[Z]);
}
