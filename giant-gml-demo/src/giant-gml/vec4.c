
#include "giant-gml/vec4.h"


inline
void giant_vec4_init(vec4_t* restrict vec)
{
    (*vec)[X] = 0.0f;
    (*vec)[Y] = 0.0f;
    (*vec)[Z] = 0.0f;
    (*vec)[W] = 0.0f;
}

inline
void giant_vec4_copy(vec4_t vec1, vec4_t* restrict vec2)
{
    (*vec2)[X] = vec1[X];
    (*vec2)[Y] = vec1[Y];
    (*vec2)[Z] = vec1[Z];
    (*vec2)[W] = vec1[W];
}

inline
void giant_vec4_add(vec4_t* restrict vec, vec4_t arg)
{
    (*vec)[X] += arg[X];
    (*vec)[Y] += arg[Y];
    (*vec)[Z] += arg[Z];
    (*vec)[W] += arg[W];
}

inline
void giant_vec4_add_to(vec4_t vec, vec4_t arg, vec4_t* restrict dest)
{
    (*dest)[X] = vec[X] + arg[X];
    (*dest)[Y] = vec[Y] + arg[Y];
    (*dest)[Z] = vec[Z] + arg[Z];
    (*dest)[W] = vec[W] + arg[W];
}

inline
void giant_vec4_sub(vec4_t* restrict vec, vec4_t arg)
{
    (*vec)[X] -= arg[X];
    (*vec)[Y] -= arg[Y];
    (*vec)[Z] -= arg[Z];
    (*vec)[W] -= arg[W];
}

inline
void giant_vec4_sub_to(vec4_t vec, vec4_t arg, vec4_t* restrict dest)
{
    (*dest)[X] = vec[X] - arg[X];
    (*dest)[Y] = vec[Y] - arg[Y];
    (*dest)[Z] = vec[Z] - arg[Z];
    (*dest)[W] = vec[W] - arg[W];
}

inline
void giant_vec4_scale(vec4_t* restrict vec, float scale)
{
    (*vec)[X] *= scale;
    (*vec)[Y] *= scale;
    (*vec)[Z] *= scale;
}

inline
void giant_vec4_scale_to(vec4_t vec, float scale, vec4_t* restrict dest)
{
    giant_vec4_copy(vec, dest);

    (*dest)[X] *= scale;
    (*dest)[Y] *= scale;
    (*dest)[Z] *= scale;
    (*dest)[W] *= scale;
}

// 3D cross product, W gets set to 1
inline
void giant_vec4_cross(vec4_t* restrict vec1, vec4_t vec2)
{
    vec4_t tmp;
    giant_vec4_copy(*vec1, &tmp);

    (*vec1)[X] = (tmp[Y] * vec2[Z]) - (tmp[Z] * vec2[Y]);
    (*vec1)[Y] = (tmp[Z] * vec2[X]) - (tmp[X] * vec2[Z]);
    (*vec1)[Z] = (tmp[X] * vec2[Y]) - (tmp[Y] * vec2[X]);
    (*vec1)[W] = 1.0f;

}

inline
void giant_vec4_cross_to(vec4_t vec1, vec4_t vec2, vec4_t* restrict dest)
{
    (*dest)[X] = (vec1[Y] * vec2[Z]) - (vec1[Z] * vec2[Y]);
    (*dest)[Y] = (vec1[Z] * vec2[X]) - (vec1[X] * vec2[Z]);
    (*dest)[Z] = (vec1[X] * vec2[Y]) - (vec1[Y] * vec2[X]);
    (*dest)[W] = 1.0f;
}

inline
float giant_vec4_length(vec4_t vec)
{
    return sqrt( (vec[X]*vec[X]) + (vec[Y]*vec[Y]) + (vec[Z]*vec[Z]) + (vec[W]*vec[W]));
}

inline
float giant_vec4_dot(vec4_t vec1, vec4_t vec2)
{
    return (vec1[X] * vec2[X]) + (vec1[Y] * vec2[Y]) + (vec1[Z] * vec2[Z]) + (vec1[W] * vec2[W]);
}

inline
void giant_vec4_normalize(vec4_t* restrict vec)
{
    float tmp = giant_vec4_length(*vec);

    (*vec)[X] /= tmp;
    (*vec)[Y] /= tmp;
    (*vec)[Z] /= tmp;
    (*vec)[W] /= tmp;
}

inline
void giant_vec4_normalize_to(vec4_t vec, vec4_t* restrict dest)
{
    float tmp = giant_vec4_length(vec);

    giant_vec4_copy(vec, dest);

    (*dest)[X] /= tmp;
    (*dest)[Y] /= tmp;
    (*dest)[Z] /= tmp;
    (*dest)[W] /= tmp;
}

inline 
void giant_vec4_print(vec4_t vec)
{
    printf("%f %f %f %f\n", vec[X], vec[Y], vec[Z], vec[W]);
}
