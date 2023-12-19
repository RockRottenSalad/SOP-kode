
#include "shader.h"

shader_t shader;
char buffer[256];

char* read_file(const char* file_path)
{
    FILE* fp;
    char* src;
    int len;
    size_t check;
    
    fp = fopen(file_path, "r");
    assert(fp != NULL && "Shader not found");

    // Getting length of file
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    rewind(fp);

    src = malloc(sizeof(char)*len);

    check = fread(src, sizeof(char)*len, len, fp);
    assert(check != 0);

    fclose(fp);

    return src;
}

void shader_init(void)
{
    shader.setTransFunc = shader_setModelViewProj;
    shader.delete = shader_delete;
    shader.use = shader_useProgram;
    shader.set_color = shader_setColor;

    // Loading and compiling shaders
    char* src;

    shader.vertexShader = glCreateShader(GL_VERTEX_SHADER);
    src = read_file("src/gfx/glsl/vertex.glsl");
    glShaderSource(shader.vertexShader, 1, (const char**)&src, NULL);
    glCompileShader(shader.vertexShader);
    free(src);

    shader.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    src = read_file("src/gfx/glsl/fragment.glsl");
    glShaderSource(shader.fragmentShader, 1, (const char**)&src, NULL);
    glCompileShader(shader.fragmentShader);
    free(src);

    shader.ptr = glCreateProgram();
    glAttachShader(shader.ptr, shader.vertexShader);
    glAttachShader(shader.ptr, shader.fragmentShader);
    glLinkProgram(shader.ptr);

    // Check for shader errors
    int check;
    glGetShaderiv(shader.vertexShader, GL_COMPILE_STATUS, &check);
    if(!check)
    {
        glGetShaderInfoLog(shader.vertexShader, 256, NULL, buffer);
        printf("%s\n", buffer);

    }
    glGetShaderiv(shader.fragmentShader, GL_COMPILE_STATUS, &check);
    if(!check)
    {
        glGetShaderInfoLog(shader.fragmentShader, 256, NULL, buffer);
        printf("%s\n", buffer);

    }
    glGetProgramiv(shader.ptr, GL_LINK_STATUS, &check);
    if(!check)
    {
        glGetProgramInfoLog(shader.ptr, 256, NULL, buffer);
        printf("%s\n", buffer);
    }

    glUseProgram(shader.ptr);

    // Fetch uniform pointers
    shader.modelLoc = glGetUniformLocation(shader.ptr, "model");
    shader.viewLoc = glGetUniformLocation(shader.ptr, "view");
    shader.projLoc = glGetUniformLocation(shader.ptr, "proj");
    shader.colorLoc = glGetUniformLocation(shader.ptr, "colarg");

}

// Set uniform transformation matrices in vertex shader
void shader_setModelViewProj(mat4_t* modelArg, mat4_t* viewArg, mat4_t* projArg)
{
    glUniformMatrix4fv(shader.modelLoc, 1, GL_FALSE, (const GLfloat *)(*modelArg));
    glUniformMatrix4fv(shader.viewLoc, 1, GL_FALSE, (const GLfloat *)(*viewArg));
    glUniformMatrix4fv(shader.projLoc, 1, GL_FALSE, (const GLfloat *)(*projArg) );
}

// Set color in fragment shader
void shader_setColor(vec3_t colorArg)
{
    glUniform3fv(shader.colorLoc, 1, (const GLfloat *)colorArg);
}

void shader_useProgram(void)
{
    glUseProgram(shader.ptr);
}

void shader_delete(void)
{
    glDeleteProgram(shader.ptr);
    glDeleteShader(shader.vertexShader);
    glDeleteShader(shader.fragmentShader);
}

