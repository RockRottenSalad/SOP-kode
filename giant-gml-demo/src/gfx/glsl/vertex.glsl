#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

uniform vec3 colarg;
out vec3 color;

void main()
{
    color = colarg;
    gl_Position = proj * view * model * vec4(aPos, 1.0);
}
