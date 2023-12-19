#ifndef SHADER_H
#define SHADER_H

/*
 * SHADER.H
 *
 * Defines the shader struct
 * The struct contains function pointer to all shader functinos
 * Shaders get compiled on init
 * Uniforms are set with their corresponding functions
 *
 * */

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<glad/glad.h>
#include<string.h>

#include "giant-gml/giant-gml.h"

extern char buffer[256];

char* read_file(const char* file_path);

typedef void (*shaderSetTransFunc_ptr)(mat4_t* modelArg, mat4_t* viewArg, mat4_t* projArg);
typedef void(*shaderSetVecFunc_ptr)(vec3_t);
typedef void(*shaderFunc_ptr)(void);

typedef struct
{
    unsigned int ptr;
    unsigned int vertexShader, fragmentShader;

    unsigned int modelLoc, viewLoc, projLoc;
    unsigned int colorLoc;
    
    shaderSetTransFunc_ptr setTransFunc;
    shaderFunc_ptr use, delete;
    shaderSetVecFunc_ptr set_color;
} shader_t;

extern shader_t shader;

void shader_init(void);

// Set uniform transformation matrices in vertex shader
void shader_setModelViewProj(mat4_t* modelArg, mat4_t* viewArg, mat4_t* projArg);

// Set color in fragment shader
void shader_setColor(vec3_t);

void shader_useProgram(void);
void shader_delete(void);

#endif
