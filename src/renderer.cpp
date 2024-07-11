// render.cpp

#include "../include/renderer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void render(GLFWwindow* window) {
    // Configuración de materiales y luz (ejemplo)
    GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat mat_diffuse[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat mat_shininess[] = {50.0f};
    
    GLfloat light_position[] = {2.0f, 6.0f, 3.0f, 0.0f};
    GLfloat light_intensity[] = {0.7f, 0.7f, 0.7f, 1.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_intensity);

    // Configuración de la proyección y la vista (ejemplo)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double winlet = 1.0;
    glOrtho(-winlet * 64 / 48, winlet * 64 / 48.0, -winlet * 64 / 48, winlet * 64 / 48, 0.6, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.3, 1.38, 2.0, 0.0, 0.25, 0.0, 0.0, 1.0, 0.0);

    // Limpieza de buffers y configuración inicial
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Renderización de objetos
    glPushMatrix();
        glTranslated(0.0, 0.0, -1.0); // Mover el triángulo hacia atrás para que sea visible

        // Renderizar un triángulo simple
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);   // Color rojo
            glVertex3f(0.0f, 0.5f, 0.0f);  // Vértice superior
            glColor3f(0.0f, 1.0f, 0.0f);   // Color verde
            glVertex3f(-0.5f, -0.5f, 0.0f); // Vértice inferior izquierdo
            glColor3f(0.0f, 0.0f, 1.0f);   // Color azul
            glVertex3f(0.5f, -0.5f, 0.0f);  // Vértice inferior derecho
        glEnd();

        // Habilitar texturas y configurar la textura (opcional, según tu aplicación)
        // glEnable(GL_TEXTURE_2D);
        // GLuint textureID = loadTexture("path_to_your_texture.png"); // Cargar tu textura aquí
        // glBindTexture(GL_TEXTURE_2D, textureID);
        // glBegin(GL_QUADS);
        //     // Renderizar el cubo con textura
        // glEnd();
        // Desactivar texturas después de su uso
        // glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    
    // Finalización y renderizado de la escena
    glFlush();
}

GLuint loadTexture(const char* path) {
    GLuint textureID;
    glGenTextures(1, &textureID);

    // Cargar la textura
    // Aquí implementa tu lógica para cargar la textura desde un archivo

    return textureID;
}
