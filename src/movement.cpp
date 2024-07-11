// movement.cpp
#include <GLFW/glfw3.h>
#include "../include/movement.h"

GLfloat moveSpeedX = 0.0f;
GLfloat moveSpeedY = 0.0f;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_W) {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
            moveSpeedY = moveSpeed;
        else
            moveSpeedY = 0.0f;
    } else if (key == GLFW_KEY_S) {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
            moveSpeedY = -moveSpeed;
        else
            moveSpeedY = 0.0f;
    } else if (key == GLFW_KEY_A) {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
            moveSpeedX = -moveSpeed;
        else
            moveSpeedX = 0.0f;
    } else if (key == GLFW_KEY_D) {
        if (action == GLFW_PRESS || action == GLFW_REPEAT)
            moveSpeedX = moveSpeed;
        else
            moveSpeedX = 0.0f;
    } else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
