#include <GL/freeglut.h>
#include <iostream>
#include <cmath>

float triangleAngle = 0.0f;
float squareScale = 1.0f;
float linePosition = -0.9f;
float lineSpeed = 0.01f;
bool lineDirection = true; 

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    glTranslatef(-0.5f, 0.0f, 0.0f);
    glRotatef(triangleAngle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.6f, 0.7f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.1f, 0.2f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7f, 0.8f, 0.9f);
    glScalef(squareScale, squareScale, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();

    glBegin(GL_LINES);
    glColor3f(0.4f, 0.3f, 1.0f);
    glVertex2f(linePosition, -0.8f);
    glVertex2f(linePosition, -0.7f);
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

void update(int value) {

    triangleAngle += 1.0f;
    if (triangleAngle > 360.0f)
        triangleAngle -= 360.0f;

  
    if (squareScale < 0.2f || squareScale > 1.0f)
        squareScale = 1.0f;
    else
        squareScale += 0.01f;

    // Update line position and direction
    if (lineDirection) {
        linePosition += lineSpeed;
        if (linePosition > 0.9f) {
            linePosition = 0.9f;
            lineDirection = false;
        }
    } else {
        linePosition -= lineSpeed;
        if (linePosition < -0.9f) {
            linePosition = -0.9f;
            lineDirection = true;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
} 

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Animation");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
