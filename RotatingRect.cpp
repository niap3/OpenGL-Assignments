#include <iostream>
#include <cmath>
#include <GL/freeglut.h>

float angle = 0.0f; // Initial rotation angle

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Apply rotation
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Draw a rectangle
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.2f); // Set color to orange
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    angle += 0.5f; // Rotate at a fixed speed
    if (angle >= 360.0f) {
        angle -= 360.0f; // Reset angle after a full rotation
    }
    glutPostRedisplay(); // Trigger a redisplay
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotating Rectangle");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
