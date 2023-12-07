#include <GL/freeglut.h>
#include <iostream>

float RotAngle = 0.0f;

void drawRectangle() {
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -1.0f);

    glRotatef(RotAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(0.91f, 0.66f, 0.22f);
    drawRectangle();

    glutSwapBuffers();
}

void idle() {
    RotAngle += 1.0f;
    if (RotAngle > 360.0f) {
        RotAngle -= 360.0f;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotating Rectangle");

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();
    
    return 0;
}
