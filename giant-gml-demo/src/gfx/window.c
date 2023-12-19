
#include "window.h"

struct Window window;

void window_init(const char* winTitle, ivec2_t sizearg)
{
    window.destroy = window_destroy;
    window.events = window_events;
    giant_ivec2_copy(sizearg, &window.size);


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_FLOATING, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window.ptr = glfwCreateWindow(window.size[Y], window.size[X], winTitle, NULL, NULL);

    glfwMakeContextCurrent(window.ptr);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        printf("GLAD failed to load\n");

    glViewport(0, 0, window.size[Y], window.size[X]);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

}

void window_events(void)
{
    if(glfwGetKey(window.ptr, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window.ptr, true);
}

void window_destroy(void)
{
    glfwTerminate();
}
