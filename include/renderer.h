// render.h

#ifndef RENDER_H
#define RENDER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void render(GLFWwindow* window);
GLuint loadTexture(const char* path);

#endif // RENDER_H
