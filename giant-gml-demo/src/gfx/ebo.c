
#include "ebo.h"

struct EBO ebo;

void EBO_init(void)
{
    ebo.bind = EBO_bind;
    ebo.delete = EBO_delete;
    ebo.configure = EBO_configure;
    glGenBuffers(1, &ebo.ptr);
}

void EBO_bind(void)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.ptr);
}

void EBO_configure(unsigned int* indices, int n)
{
    printf("EBO loading: %d indices\n", n);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * n, indices, GL_STATIC_DRAW);
}

void EBO_delete(void)
{
    glDeleteBuffers(1, &ebo.ptr);
}
