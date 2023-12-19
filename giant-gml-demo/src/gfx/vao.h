#ifndef VAO_H
#define VAO_H

/*
 * VAO.H
 *
 * Defines VAO struct
 * Used to bind and configure VAO
 * Only supports single VAO
 *
 */

#include "vbo.h"
#include<stdio.h>

struct Attribute
{
    int attribute;
    int vertices;
    int totalVertices;
    int offset;
};

typedef void(*VAOFunc_ptr)(void);
typedef void(*VAOConfigureFunc_ptr)(struct Attribute);

struct VAO
{
    unsigned int ptr;
    VAOFunc_ptr bind, delete;
    VAOConfigureFunc_ptr configure;
};

extern struct VAO vao;

void VAO_init(void);
void VAO_bind(void);
void VAO_configure(struct Attribute attrib);
void VAO_delete(void);

#endif
