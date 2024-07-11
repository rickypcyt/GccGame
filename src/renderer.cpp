#include "../include/renderer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLuint VBO, VAO, shaderProgram;

// Shader sources
const char* vertexShaderSource = R"glsl(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
)glsl";

const char* fragmentShaderSource = R"glsl(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 0.5, 0.2, 1.0); // Color naranja
    }
)glsl";

void setupShaders() {
    // Compilar shaders
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    // Vincular shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Liberar shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void createSquare() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,  // Abajo izquierda
         0.5f, -0.5f, 0.0f,  // Abajo derecha
         0.5f,  0.5f, 0.0f,  // Arriba derecha
        -0.5f,  0.5f, 0.0f   // Arriba izquierda
    };

    unsigned int indices[] = {
        0, 1, 2,   // Primer triángulo
        2, 3, 0    // Segundo triángulo
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Configurar atributos de vértice
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Configurar el buffer de índices
    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Desvincular VBO y VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void renderSquare(GLFWwindow* window, float posX, float posY) {
    glUseProgram(shaderProgram);

    // Transformación para mover el cuadrado
    glm::mat4 model = glm::mat4(1.0f);  // Inicializar como matriz identidad
    model = glm::translate(model, glm::vec3(posX, posY, 0.0f));

    // Obtener la ubicación de la matriz de modelo en el shader
    unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    // Dibujar el cuadrado
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

