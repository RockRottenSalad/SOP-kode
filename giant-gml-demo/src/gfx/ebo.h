#ifndef EBO_H
#define EBO_H

/*
 * EBO.H
 *
 * Defines VAO struct
 * Used to bind and configure EBO
 * Only supports single EBO
 *
 */

#include<glad/glad.h>
#include<stdlib.h>
#include<string.h>
#include <stdio.h>

typedef void(*EBOFunc_ptr)(void);
typedef void(*EBOConfigureFunc_ptr)(unsigned int*, int);

struct EBO
{
    unsigned int ptr;
    EBOFunc_ptr bind, delete;
    EBOConfigureFunc_ptr configure;
};

extern struct EBO ebo;

void EBO_init(void);
void EBO_bind(void);
void EBO_configure(unsigned int* indices, int n);
void EBO_delete(void);

#endif
