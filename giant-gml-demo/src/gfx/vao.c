
#include "vao.h"

struct VAO vao;

void VAO_init(void)
{
    vao.bind = VAO_bind;
    vao.delete = VAO_delete;
    vao.configure = VAO_configure;
    glGenVertexArrays(1, &vao.ptr);
}

void VAO_bind(void)
{
    glBindVertexArray(vao.ptr);
}

void VAO_configure(struct Attribute attrib)
{
    glVertexAttribPointer(attrib.attribute, attrib.vertices, GL_FLOAT, GL_FALSE,
            attrib.totalVertices * sizeof(float), (void*)0);
    glEnableVertexAttribArray(attrib.attribute);
    printf("VAO loading attribute %d, with %d vertices, %d total vertices and %d offset\n",
            attrib.attribute, attrib.vertices, attrib.totalVertices, attrib.offset);
}

void VAO_delete(void)
{
    glDeleteVertexArrays(1, &vao.ptr);
}
