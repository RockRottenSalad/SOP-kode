
#include "giant-gml/vec2.h"

inline
void giant_vec2_init(vec2_t* restrict vec)
{
    (*vec)[X] = 0.0f;
    (*vec)[Y] = 0.0f;
}

inline
void giant_vec2_copy(vec2_t vec1, vec2_t* restrict vec2)
{
    (*vec2)[X] = vec1[X];
    (*vec2)[Y] = vec1[Y];
}

inline
void giant_vec2_add(vec2_t* restrict vec, vec2_t arg)
{
    (*vec)[X] += arg[X];
    (*vec)[Y] += arg[Y];
}

inline
void giant_vec2_add_to(vec2_t vec, vec2_t arg, vec2_t* restrict dest)
{
    (*dest)[X] = vec[X] + arg[X];
    (*dest)[Y] = vec[Y] + arg[Y];
}

inline
void giant_vec2_sub(vec2_t* restrict vec, vec2_t arg)
{
    (*vec)[X] -= arg[X];
    (*vec)[Y] -= arg[Y];
}

inline
void giant_vec2_sub_to(vec2_t vec, vec2_t arg, vec2_t* restrict dest)
{
    (*dest)[X] = vec[X] - arg[X];
    (*dest)[Y] = vec[Y] - arg[Y];
}

inline
void giant_vec2_scale(vec2_t* restrict vec, float scale)
{
    (*vec)[X] *= scale;
    (*vec)[Y] *= scale;
}

inline
void giant_vec2_scale_to(vec2_t vec, float scale, vec2_t* restrict dest)
{
    giant_vec2_copy(vec, dest);

    (*dest)[X] *= scale;
    (*dest)[Y] *= scale;
}

// 3D cross product, W gets set to 1
inline
float giant_vec2_cross(vec2_t* restrict vec1, vec2_t vec2)
{
    return ((*vec1)[X] * vec2[Y]) - (vec2[X] * (*vec1)[Y]);
}

inline
float giant_vec2_length(vec2_t vec)
{
    return sqrt( (vec[X]*vec[X]) + (vec[Y]*vec[Y]) );
}

inline
float giant_vec2_dot(vec2_t vec1, vec2_t vec2)
{
    return (vec1[X] * vec2[X]) + (vec1[Y] * vec2[Y]);
}

inline
void giant_vec2_normalize(vec2_t* restrict vec)
{
    float tmp = giant_vec2_length(*vec);

    (*vec)[X] /= tmp;
    (*vec)[Y] /= tmp;
}

inline
void giant_vec2_normalize_to(vec2_t vec, vec2_t* restrict dest)
{
    float tmp = giant_vec2_length(vec);

    giant_vec2_copy(vec, dest);

    (*dest)[X] /= tmp;
    (*dest)[Y] /= tmp;
}

inline 
void giant_vec2_print(vec2_t vec)
{
    printf("%f %f\n", vec[X], vec[Y]);
}
