#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstring> // Para std::strlen

// Dimensiones de la ventana
const GLint WIDTH = 800, HEIGHT = 600;

// Posición inicial de la caja
GLfloat boxPosX = 0.0f;
GLfloat boxPosY = 0.0f;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // Movimiento de la caja
    const GLfloat moveSpeed = 0.1f;

    if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
        boxPosY += moveSpeed;
    else if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
        boxPosY -= moveSpeed;
    else if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
        boxPosX -= moveSpeed;
    else if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
        boxPosX += moveSpeed;
    else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void render() {
    // Dibujar el piso
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);    // Color gris
    glVertex2f(-1.0f, 0.0f);        // Vértice izquierdo
    glVertex2f(1.0f, 0.0f);         // Vértice derecho
    glVertex2f(1.0f, -0.1f);        // Vértice superior derecho
    glVertex2f(-1.0f, -0.1f);       // Vértice superior izquierdo
    glEnd();
}

int main() {
    // Inicializar GLFW
    if (!glfwInit()) {
        std::cerr << "Error al inicializar GLFW\n";
        return -1;
    }

    // Crear una ventana GLFW
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "MyOpenGLGame", NULL, NULL);
    if (!window) {
        std::cerr << "Error al crear la ventana GLFW\n";
        glfwTerminate();
        return -1;
    }

    // Hacer que la ventana sea el contexto OpenGL actual
    glfwMakeContextCurrent(window);

    // Inicializar GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Error al inicializar GLEW\n";
        return -1;
    }

    // Establecer la función de callback para las teclas
    glfwSetKeyCallback(window, key_callback);

    // Bucle principal de renderizado
    while (!glfwWindowShouldClose(window)) {
        // Renderizar
        glClear(GL_COLOR_BUFFER_BIT);

        // Llamar a la función de renderizado
        render();

        // Intercambiar los buffers
        glfwSwapBuffers(window);

        // Verificar eventos
        glfwPollEvents();
    }

    // Terminar GLFW
    glfwTerminate();
    return 0;
}
