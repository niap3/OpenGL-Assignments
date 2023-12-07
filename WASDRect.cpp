#include <GL/freeglut.h>
#include <cmath>
#include <stdlib.h>
#include <GL/glu.h>
#include <GL/glut.h>

float RectX = 0.0f;
float RectY = 0.0f;
float RectWidth = 0.2f;
float RectHeight = 0.2f;

void drawRect() {
    glColor3f(1.0f, 0.5f, 0.6f); 
    glBegin(GL_QUADS);
    glVertex2f(RectX, RectY);
    glVertex2f(RectX + RectWidth, RectY);      
    glVertex2f(RectX + RectWidth, RectY + RectHeight); 
    glVertex2f(RectX, RectY + RectHeight);      
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawRect();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}


void keyPress(unsigned char key, int x, int y) {
    float dist = 0.1f; 

    switch (key) {
        case 'w':
            RectY += dist; 
            break;
        case 's':
            RectY -= dist; 
            break;
        case 'a':
            RectX -= dist; 
            break;
        case 'd':
            RectX += dist; 
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("WASD");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();

    return 0;
}