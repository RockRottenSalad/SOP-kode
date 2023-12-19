

#include "giant-gml/mat2.h"
#include "giant-gml/vec2.h"

inline
void giant_mat2_init(mat2_t* restrict mat)
{
    (*mat)[0][0] = 0.0;
    (*mat)[0][1] = 0.0;

    (*mat)[1][0] = 0.0;
    (*mat)[1][1] = 0.0;
}

inline
void giant_mat2_identity_init(mat2_t* restrict mat)
{
    (*mat)[0][0] = 1.0;
    (*mat)[0][1] = 0.0;

    (*mat)[1][0] = 0.0;
    (*mat)[1][1] = 1.0;
}

inline
void giant_mat2_copy(mat2_t mat1, mat2_t* restrict mat2)
{
    (*mat2)[0][0] = mat1[0][0];
    (*mat2)[0][1] = mat1[0][1];

    (*mat2)[1][0] = mat1[1][0];
    (*mat2)[1][1] = mat1[1][1];
}

inline
void giant_mat2_mult(mat2_t* restrict mat1, mat2_t mat2)
{
    mat2_t tmp = MAT2_INIT;

    for(int i = 0; i < 2; i++)
        for(int n = 0; n < 2; n++)
            for(int y = 0; y < 2; y++)
                tmp[i][n] += (*mat1)[i][y] * mat2[y][n];

    giant_mat2_copy(tmp, mat1);
}


inline
void giant_mat2_scale(mat2_t* restrict mat, vec3_t vec)
{
    giant_mat2_identity_init(mat);

    (*mat)[0][0] = vec[X];
    (*mat)[1][1] = vec[Y];
}

inline
void giant_mat2_rotate(mat2_t* restrict mat,  float angle)
{
    giant_mat2_identity_init(mat);

    float cos_angle = cos(angle * DEG2RAD);
    float sin_angle = sin(angle * DEG2RAD);

    (*mat)[0][0] = cos_angle;
    (*mat)[0][1] = sin_angle;

    (*mat)[1][0] = -sin_angle; 
    (*mat)[1][1] = cos_angle;
}

inline
void giant_mat2_mult_vec2(mat2_t mat, vec2_t* restrict vec)
{
    vec2_t a = VEC2_INIT;

    for(int i = 0; i < 2; i++)
        for(int n = 0; n < 2; n++)
            a[i] += mat[n][i] * (*vec)[n];

    (*vec)[X] = a[X];
    (*vec)[Y] = a[Y];
}

inline
void giant_mat2_print(mat2_t mat)
{
    printf("%f\t%f\n",mat[0][0],mat[0][1]);
    printf("%f\t%f\n",mat[1][0],mat[1][1]);
}

