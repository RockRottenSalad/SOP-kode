#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

/*
 * EVENTHANDLER.H
 * 
 * Used to handle keyboard and mouse input
 * Don't know what else to write here ¯\_(ツ)_/¯
 *
 */

#include<GLFW/glfw3.h>
#include "camera.h"

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void keyboard_callback(GLFWwindow* window);

#endif
