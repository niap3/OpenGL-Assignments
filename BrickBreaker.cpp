#include <GL/freeglut.h>
#include <cmath>

GLfloat ballRadius = 0.05f;
GLfloat ballX = 0.5f;
GLfloat ballY = 0.5f;
GLfloat ballSpeedX = 0.02f;
GLfloat ballSpeedY = 0.007f;

GLfloat rectWidth = 0.2f;
GLfloat rectHeight = 0.02f;
GLfloat rectX = 0.0f;

bool keyLeftPressed = false;
bool keyRightPressed = false;

void drawBall() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float radian = i * 3.14159 / 180.0;
        glVertex2f(ballX + ballRadius * cos(radian), ballY + ballRadius * sin(radian));
    }
    glEnd();
}

void drawRectangle() {
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(rectX, 0.0f);
    glVertex2f(rectX + rectWidth, 0.0f);
    glVertex2f(rectX + rectWidth, rectHeight);
    glVertex2f(rectX, rectHeight);
    glEnd();
}

void update(int value) {
    if (keyLeftPressed) {
        rectX -= 0.02f;
    }
    if (keyRightPressed) {
        rectX += 0.02f;
    }

    ballX += ballSpeedX;
    ballY += ballSpeedY;

    if (ballX > 1.0f || ballX < 0.0f) {
        ballSpeedX = -ballSpeedX;
    }
    if (ballY > 1.0f) {
        ballSpeedY = -ballSpeedY;
    }

    if (ballY < rectHeight && ballX > rectX && ballX < rectX + rectWidth) {
        ballSpeedY = -ballSpeedY;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawBall();
    drawRectangle();

    glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            keyLeftPressed = true;
            break;
        case 'd':
            keyRightPressed = true;
            break;
    }
}

void keyReleased(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            keyLeftPressed = false;
            break;
        case 'd':
            keyRightPressed = false;
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Pinball Game");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutTimerFunc(25, update, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glutMainLoop();

    return 0;
}
