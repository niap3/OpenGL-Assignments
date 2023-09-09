#include <iostream>
#include <cmath>
#include <GL/freeglut.h>

const int numLines = 12;  // Number of lines in the spiderweb
const float webRadius = 0.8f;  // Radius of the spiderweb

void drawSpiderWeb() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set background color to black
    glColor3f(1.0f, 1.0f, 1.0f); // Set line color to white

    // Draw the radial lines radiating from the center
    glBegin(GL_LINES);
    for (int i = 0; i < numLines; ++i) {
        float angle = 2 * M_PI * i / numLines;
        float x1 = 0.0f;
        float y1 = 0.0f;
        float x2 = webRadius * cos(angle);
        float y2 = webRadius * sin(angle);

        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();

    // Draw the cross lines in white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-webRadius, 0.0f);
    glVertex2f(webRadius, 0.0f);
    glVertex2f(0.0f, -webRadius);
    glVertex2f(0.0f, webRadius);
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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Spiderweb with Cross");

    glutDisplayFunc(drawSpiderWeb);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
