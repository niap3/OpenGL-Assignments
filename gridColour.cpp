
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

const int rows = 5;
const int cols = 5;
const float cellSize = 0.2f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            float x = j * cellSize;
            float y = i * cellSize;
            glColor3f(static_cast<float>(rand()) / RAND_MAX,
                static_cast<float>(rand()) / RAND_MAX,
                static_cast<float>(rand()) / RAND_MAX);

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + cellSize, y);
            glVertex2f(x + cellSize, y + cellSize);
            glVertex2f(x, y + cellSize); 
            glEnd();
        }
    }

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    srand(static_cast<unsigned int>(time(NULL)));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Randomly Colored Grid");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

