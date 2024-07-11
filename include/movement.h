// movement.h
#ifndef MOVEMENT_H
#define MOVEMENT_H

extern GLfloat moveSpeedX;
extern GLfloat moveSpeedY;
const GLfloat moveSpeed = 0.1f;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif // MOVEMENT_H
