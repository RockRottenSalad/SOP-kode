
#include "eventhandler.h"
#include "camera.h"

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    camera.updateDirection(xpos, ypos);
}

void keyboard_callback(GLFWwindow* window)
{
    // Camera movement
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.moveForward();
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.moveBack();
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.moveLeft();
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.moveRight();

    // Unlocks mouse from window capture
    if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        // Prevent camera from rotating while mouse is unlocked
        camera.camSens = 0.0f;
    }
        
    // Locks mouse
    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        camera.camSens = 0.01f;
    }
}
