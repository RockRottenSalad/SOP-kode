

#include "giant-gml/mat3.h"
#include "giant-gml/vec3.h"

inline
void giant_mat3_init(mat3_t* restrict mat)
{
    (*mat)[0][0] = 0.0;
    (*mat)[0][1] = 0.0;
    (*mat)[0][2] = 0.0;

    (*mat)[1][0] = 0.0;
    (*mat)[1][1] = 0.0;
    (*mat)[1][2] = 0.0;

    (*mat)[2][0] = 0.0;
    (*mat)[2][1] = 0.0;
    (*mat)[2][2] = 0.0;

}

inline
void giant_mat3_identity_init(mat3_t* restrict mat)
{
    (*mat)[0][0] = 1.0;
    (*mat)[0][1] = 0.0;
    (*mat)[0][2] = 0.0;

    (*mat)[1][0] = 0.0;
    (*mat)[1][1] = 1.0;
    (*mat)[1][2] = 0.0;

    (*mat)[2][0] = 0.0;
    (*mat)[2][1] = 0.0;
    (*mat)[2][2] = 1.0;
}

inline
void giant_mat3_copy(mat3_t mat1, mat3_t* restrict mat2)
{
    (*mat2)[0][0] = mat1[0][0];
    (*mat2)[0][1] = mat1[0][1];
    (*mat2)[0][2] = mat1[0][2];

    (*mat2)[1][0] = mat1[1][0];
    (*mat2)[1][1] = mat1[1][1];
    (*mat2)[1][2] = mat1[1][2];

    (*mat2)[2][0] = mat1[2][0];
    (*mat2)[2][1] = mat1[2][1];
    (*mat2)[2][2] = mat1[2][2];
}

inline
void giant_mat3_mult(mat3_t* restrict mat1, mat3_t mat2)
{
    mat3_t tmp = MAT3_INIT;

    for(int i = 0; i < 3; i++)
        for(int n = 0; n < 3; n++)
            for(int y = 0; y < 3; y++)
                tmp[i][n] += (*mat1)[i][y] * mat2[y][n];

    giant_mat3_copy(tmp, mat1);
}


inline
void giant_mat3_scale(mat3_t* restrict mat, vec3_t vec)
{
    giant_mat3_identity_init(mat);

    (*mat)[0][0] = vec[X];
    (*mat)[1][1] = vec[Y];
    (*mat)[2][2] = vec[Z];
}

inline
void giant_mat3_rotate(mat3_t* restrict mat, vec3_t vec, float angle)
{
    giant_mat3_identity_init(mat);

    vec3_t vecn = VEC3_INIT;

    giant_vec3_copy(vec, &vecn);
    giant_vec3_normalize(&vecn);

    float cos_angle = cos(angle * DEG2RAD);
    float sin_angle = sin(angle * DEG2RAD);

    (*mat)[0][0] = vecn[X] * vecn[X] * (1.0f - cos_angle) + cos_angle;
    (*mat)[0][1] = vecn[Y] * vecn[X] * (1.0f - cos_angle) - vecn[Z] * sin_angle;
    (*mat)[0][2] = vecn[Z] * vecn[X] * (1.0f - cos_angle) - vecn[X] * sin_angle;

    (*mat)[1][0] = vecn[X] * vecn[Y] * (1.0f - cos_angle) + vecn[Z] * sin_angle;
    (*mat)[1][1] = vecn[Y] * vecn[Y] * (1.0f - cos_angle) + cos_angle;
    (*mat)[1][2] = vecn[Z] * vecn[Y] * (1.0f - cos_angle) - vecn[X] * sin_angle;

    (*mat)[2][0] = vecn[X] * vecn[Z] * (1.0f - cos_angle) - vecn[Y] * sin_angle;
    (*mat)[2][1] = vecn[Y] * vecn[Z] * (1.0f - cos_angle) + vecn[X] * sin_angle;
    (*mat)[2][2] = vecn[Z] * vecn[Z] * (1.0f - cos_angle) + cos_angle;
}

inline
void giant_mat3_mult_vec3(mat3_t mat, vec3_t* restrict vec)
{
    vec3_t a = VEC3_INIT;

    for(int i = 0; i < 3; i++)
        for(int n = 0; n < 3; n++)
            a[i] += mat[n][i] * (*vec)[n];

    (*vec)[X] = a[X];
    (*vec)[Y] = a[Y];
    (*vec)[Z] = a[Z];
}

inline
void giant_mat3_print(mat3_t mat)
{
    printf("%f\t%f\t%f\n",mat[0][0],mat[0][1],mat[0][2]);
    printf("%f\t%f\t%f\n",mat[1][0],mat[1][1],mat[1][2]);
    printf("%f\t%f\t%f\n",mat[2][0],mat[2][1],mat[2][2]);
}

