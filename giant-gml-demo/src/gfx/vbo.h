
#ifndef VBO_H
#define VBO_H

/*
 * VBO.H
 *
 * Defines VBO struct
 * Used to bind and configure VBO
 * Only supports single VBO
 *
 */

#include "ebo.h"
#include <stdio.h>

typedef void(*VBOFunc_ptr)(void);
typedef void(*VBOConfigureFunc_ptr)(float*, int);

struct VBO
{
    unsigned int ptr;
    VBOFunc_ptr bind, delete;
    VBOConfigureFunc_ptr configure;
};

extern struct VBO vbo;

void VBO_init(void);
void VBO_bind(void);
void VBO_configure(float* vertices, int n);
void VBO_delete(void);

#endif
