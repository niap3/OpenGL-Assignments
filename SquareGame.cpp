#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float SQUARE_SIZE = 0.1f;
const float SQUARE_SPEED = 0.02f;

float playerX = 0.0f;
float playerY = 0.0f;
float targetX = 0.0f;
float targetY = 0.0f;
float targetSpeedX = 0.01f;
float targetSpeedY = 0.01f;
bool gameEnded = false;

void drawSquare(float x, float y) {
    glColor3f(1.0f, 0.3f, 0.02f);
    glBegin(GL_QUADS);
    glVertex2f(x - SQUARE_SIZE, y - SQUARE_SIZE);
    glVertex2f(x + SQUARE_SIZE, y - SQUARE_SIZE);
    glVertex2f(x + SQUARE_SIZE, y + SQUARE_SIZE);
    glVertex2f(x - SQUARE_SIZE, y + SQUARE_SIZE);
    glEnd();
    
    if (!gameEnded) {
        glColor3f(0.3f, 0.6f, 0.9f);
        glBegin(GL_QUADS);
        glVertex2f(targetX - SQUARE_SIZE, targetY - SQUARE_SIZE);
        glVertex2f(targetX + SQUARE_SIZE, targetY - SQUARE_SIZE);
        glVertex2f(targetX + SQUARE_SIZE, targetY + SQUARE_SIZE);
        glVertex2f(targetX - SQUARE_SIZE, targetY + SQUARE_SIZE);
        glEnd();
    }
}

void checkCollision() {
    if (!gameEnded) {
        float dx = playerX - targetX;
        float dy = playerY - targetY;
        float distance = sqrt(dx * dx + dy * dy);

        if (distance < SQUARE_SIZE * 2) {
            gameEnded = true;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    checkCollision();
    
    if (!gameEnded) {

        targetX += targetSpeedX;
        targetY += targetSpeedY;
        
        if (targetX + SQUARE_SIZE > 1.0f || targetX - SQUARE_SIZE < -1.0f) {
            targetSpeedX = -targetSpeedX;
        }
        if (targetY + SQUARE_SIZE > 1.0f || targetY - SQUARE_SIZE < -1.0f) {
            targetSpeedY = -targetSpeedY;
        }
    }
    
    drawSquare(playerX, playerY);
    
    if (gameEnded) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2f(-0.2f, 0.0f);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)"Game Over!");
    }

    glutSwapBuffers();
}

void handleKeypress(unsigned char key, int x, int y) {
    if (!gameEnded) {
        if (key == 'w' || key == 'W') {
            playerY += SQUARE_SPEED;
        } else if (key == 's' || key == 'S') {
            playerY -= SQUARE_SPEED;
        } else if (key == 'a' || key == 'A') {
            playerX -= SQUARE_SPEED;
        } else if (key == 'd' || key == 'D') {
            playerX += SQUARE_SPEED;
        }
    }
}

void update(int value) {
    if (!gameEnded) {
        glutPostRedisplay();
        glutTimerFunc(16, update, 0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Catch the Square Game");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    srand(time(NULL));
    targetX = (rand() / (float)RAND_MAX) * 3 - 1;
    targetY = (rand() / (float)RAND_MAX) * 3 - 1;

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}