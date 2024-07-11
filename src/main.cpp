// main.cpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../include/renderer.h"

const GLint WIDTH = 800, HEIGHT = 600;

GLfloat moveSpeedX = 0.0f;
GLfloat moveSpeedY = 0.0f;
const GLfloat moveSpeed = 0.1f;

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

int main() {
    if (!glfwInit()) {
        std::cerr << "Error al inicializar GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4 muestras por píxel para multisampling

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "MyOpenGLGame", NULL, NULL);
    if (!window) {
        std::cerr << "Error al crear la ventana GLFW\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glEnable(GL_MULTISAMPLE); // Habilitar multisampling

    if (glewInit() != GLEW_OK) {
        std::cerr << "Error al inicializar GLEW\n";
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Movimiento diagonal
        boxPosX += moveSpeedX;
        boxPosY += moveSpeedY;

        // Set up projection matrix
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);

        // Set up view matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0.0f, 0.0f, 5.0f, // Eye position
                  0.0f, 0.0f, 0.0f, // Look-at position
                  0.0f, 1.0f, 0.0f); // Up direction

        render();

        glfwSwapBuffers(window);
        glfwPollEvents();

        // Incrementa el ángulo de rotación para que el cubo gire continuamente
        rotationAngle += 0.5f;
    }

    glfwTerminate();
    return 0;
}
