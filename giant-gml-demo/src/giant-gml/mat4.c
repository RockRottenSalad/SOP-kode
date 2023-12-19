
#include "giant-gml/mat4.h"
#include "giant-gml/vec4.h"
#include "giant-gml/vec3.h"

inline
void giant_mat4_init(mat4_t* restrict mat)
{
    (*mat)[0][0] = 0.0;
    (*mat)[0][1] = 0.0;
    (*mat)[0][2] = 0.0;
    (*mat)[0][3] = 0.0;

    (*mat)[1][0] = 0.0;
    (*mat)[1][1] = 0.0;
    (*mat)[1][2] = 0.0;
    (*mat)[1][3] = 0.0;

    (*mat)[2][0] = 0.0;
    (*mat)[2][1] = 0.0;
    (*mat)[2][2] = 0.0;
    (*mat)[2][3] = 0.0;

    (*mat)[3][3] = 0.0;
    (*mat)[3][1] = 0.0;
    (*mat)[3][2] = 0.0;
    (*mat)[3][3] = 0.0;
}

inline
void giant_mat4_identity_init(mat4_t* restrict mat)
{
    (*mat)[0][0] = 1.0;
    (*mat)[0][1] = 0.0;
    (*mat)[0][2] = 0.0;
    (*mat)[0][3] = 0.0;

    (*mat)[1][0] = 0.0;
    (*mat)[1][1] = 1.0;
    (*mat)[1][2] = 0.0;
    (*mat)[1][3] = 0.0;

    (*mat)[2][0] = 0.0;
    (*mat)[2][1] = 0.0;
    (*mat)[2][2] = 1.0;
    (*mat)[2][3] = 0.0;

    (*mat)[3][0] = 0.0;
    (*mat)[3][1] = 0.0;
    (*mat)[3][2] = 0.0;
    (*mat)[3][3] = 1.0;

}

inline
void giant_mat4_copy(mat4_t mat1, mat4_t* restrict mat2)
{
    (*mat2)[0][0] = mat1[0][0];
    (*mat2)[0][1] = mat1[0][1];
    (*mat2)[0][2] = mat1[0][2];
    (*mat2)[0][3] = mat1[0][3];

    (*mat2)[1][0] = mat1[1][0];
    (*mat2)[1][1] = mat1[1][1];
    (*mat2)[1][2] = mat1[1][2];
    (*mat2)[1][3] = mat1[1][3];

    (*mat2)[2][0] = mat1[2][0];
    (*mat2)[2][1] = mat1[2][1];
    (*mat2)[2][2] = mat1[2][2];
    (*mat2)[2][3] = mat1[2][3];

    (*mat2)[3][0] = mat1[3][0];
    (*mat2)[3][1] = mat1[3][1];
    (*mat2)[3][2] = mat1[3][2];
    (*mat2)[3][3] = mat1[3][3];
}

inline
void giant_mat4_mult(mat4_t* restrict mat1, mat4_t mat2)
{
    mat4_t tmp = MAT4_INIT;

    for(int i = 0; i < 4; i++)
        for(int n = 0; n < 4; n++)
            for(int y = 0; y < 4; y++)
                tmp[i][n] += (*mat1)[i][y] * mat2[y][n];

    giant_mat4_copy(tmp, mat1);
}

inline
void giant_mat4_translate(mat4_t* restrict mat, vec3_t vec)
{
    (*mat)[3][0] = vec[X];
    (*mat)[3][1] = vec[Y];
    (*mat)[3][2] = vec[Z];
}

inline
void giant_mat4_scale(mat4_t* restrict mat, vec3_t vec)
{
    giant_mat4_identity_init(mat);

    (*mat)[0][0] = vec[X];
    (*mat)[1][1] = vec[Y];
    (*mat)[2][2] = vec[Z];
}

inline
void giant_mat4_rotate(mat4_t* restrict mat, vec3_t vec, float angle)
{
    giant_mat4_identity_init(mat);

    vec3_t vec_normal;
    giant_vec3_copy(vec, &vec_normal);
    giant_vec3_normalize(&vec_normal);

    float cos_angle = cos(angle * DEG2RAD);
    float sin_angle = sin(angle * DEG2RAD);

    (*mat)[0][0] = cos_angle + (vec_normal[X]*vec_normal[X]) * (1.0f - cos_angle);
    (*mat)[0][1] = vec_normal[X] * vec_normal[Y] * (1.0 - cos_angle) - vec_normal[Z] * sin_angle;
    (*mat)[0][2] = vec_normal[X] * vec_normal[Z] * (1.0 - cos_angle) + vec_normal[Y] * sin_angle;

    (*mat)[1][0] = vec_normal[Y] * vec_normal[X] * (1.0 - cos_angle) + vec_normal[Z] * sin_angle;
    (*mat)[1][1] = cos_angle + (vec_normal[Y] * vec_normal[Y]) * (1.0 - cos_angle);
    (*mat)[1][2] = vec_normal[Y] * vec_normal[Z] * (1.0 - cos_angle) - vec_normal[X] * sin_angle;

    (*mat)[2][0] = vec_normal[Z] * vec_normal[X] * (1.0 - cos_angle) - vec_normal[Y] * sin_angle;
    (*mat)[2][1] = vec_normal[Z] * vec_normal[Y] * (1.0 - cos_angle) + vec_normal[X] * sin_angle;
    (*mat)[2][2] = cos_angle + (vec_normal[Z] * vec_normal[Z]) * (1.0 - cos_angle);

    (*mat)[3][3] = 1.0;
}

inline
void giant_mat4_mult_vec4(mat4_t mat, vec4_t* restrict vec)
{
    vec4_t a = VEC4_INIT;

    for(int i = 0; i < 4; i++)
        for(int n = 0; n < 4; n++)
            a[i] += mat[n][i] * (*vec)[n];

    (*vec)[X] = a[X];
    (*vec)[Y] = a[Y];
    (*vec)[Z] = a[Z];
    (*vec)[W] = a[W];
}

inline
void giant_mat4_mult_vec3(mat4_t mat, vec3_t* restrict vec)
{
    vec4_t tmp = {(*vec)[X], (*vec)[Y], (*vec)[Z], 1.0f};

    giant_mat4_mult_vec4(mat, &tmp);

    (*vec)[X] = tmp[X];
    (*vec)[Y] = tmp[Y];
    (*vec)[Z] = tmp[Z];
}

inline
void giant_mat4_perspective(mat4_t* restrict mat, float n_z, float f_z, float aspect)
{ 
    giant_mat4_init(mat);

    float left = -aspect;
    float right = aspect;
    float top = 1.0f;
    float bottom = -1.0f;

    (*mat)[0][0] = 2.0f*n_z / (right - left);
    (*mat)[0][2] = (right + left) / (right - left);
    (*mat)[1][1] = 2.0f*n_z / (top - bottom);
    (*mat)[1][2] = (top + bottom) / (top - bottom);
    (*mat)[2][2] = -(f_z + n_z) / (f_z - n_z);
    (*mat)[2][3] = -2.0f*f_z*n_z / (f_z - n_z);
    (*mat)[3][2] = -1.0f;
}

inline
void giant_mat4_perspective_fov(mat4_t* restrict mat, float n_z, float f_z, float aspect, float fov)
{
    giant_mat4_init(mat);

    float tangent = tanf(fov / 2.0f * DEG2RAD);
    float half_height = n_z * tangent;
    float half_width = half_height * aspect; 

    float left   =  -half_width;
    float right  =  half_width;
    float top    =  half_height;
    float bottom = -half_height;

    (*mat)[0][0] = 2.0f*n_z / (right - left);
    (*mat)[0][2] = (right + left) / (right - left);
    (*mat)[1][1] = 2.0f*n_z / (top - bottom);
    (*mat)[1][2] = (top + bottom) / (top - bottom);
    (*mat)[2][2] = -(f_z + n_z) / (f_z - n_z);
    (*mat)[2][3] = -2.0f*f_z*n_z / (f_z - n_z);
    (*mat)[3][2] = -1.0f;

}

inline
void giant_mat4_lookat(mat4_t* restrict mat, vec3_t pos, vec3_t direction)
{
    vec3_t dir_normal, side, up;

    giant_vec3_copy(direction, &dir_normal);
    giant_vec3_normalize(&dir_normal);

    giant_vec3_cross_to(dir_normal, (vec3_t){0.0f, 1.0f, 0.0f}, &side);
    giant_vec3_normalize(&side);

    giant_vec3_cross_to(side, dir_normal, &up);
    giant_vec3_normalize(&up);

    giant_mat4_identity_init(mat);

    (*mat)[0][0] = side[X];
    (*mat)[1][0] = side[Y];
    (*mat)[2][0] = side[Z];

    (*mat)[0][1] = up[X];
    (*mat)[1][1] = up[Y];
    (*mat)[2][1] = up[Z];

    (*mat)[0][2] = -dir_normal[X];
    (*mat)[1][2] = -dir_normal[Y];
    (*mat)[2][2] = -dir_normal[Z];

    (*mat)[3][0] = -giant_vec3_dot(side, pos);
    (*mat)[3][1] = -giant_vec3_dot(up, pos);
    (*mat)[3][2] = giant_vec3_dot(dir_normal, pos);
}


inline
void giant_mat4_print(mat4_t mat)
{
    printf("%f\t%f\t%f\t%f\n",mat[0][0],mat[0][1],mat[0][2],mat[0][3]);
    printf("%f\t%f\t%f\t%f\n",mat[1][0],mat[1][1],mat[1][2],mat[1][3]);
    printf("%f\t%f\t%f\t%f\n",mat[2][0],mat[2][1],mat[2][2],mat[2][3]);
    printf("%f\t%f\t%f\t%f\n",mat[3][0],mat[3][1],mat[3][2],mat[3][3]);
}

