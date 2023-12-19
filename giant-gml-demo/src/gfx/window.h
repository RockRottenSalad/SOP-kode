#ifndef WINDOW_H
#define WINDOW_H

/*
 * WINDOW.H
 *
 * Defines the window struct
 * Used to create a GLFW window, load GLAD and create an OpenGL context on init
 * Sets glClearColor
 * Terminates GLFW
 *
 */

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "giant-gml/giant-gml.h"
#include<stdio.h>
#include<stdbool.h>

typedef void (*winFunc_ptr)(void);

struct Window
{
    GLFWwindow* ptr;
    ivec2_t size;
    winFunc_ptr init, loop, destroy, events; 
    float deltaA, deltaB, deltaTime;

    unsigned int strips, vertsPrStrip;
};

extern struct Window window;

void window_init(const char* winTitle, ivec2_t sizearg);
void window_destroy(void);
void window_events(void);

#endif
