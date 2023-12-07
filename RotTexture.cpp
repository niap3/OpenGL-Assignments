#include <GL/freeglut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
GLfloat angle = 0.0f;
GLuint textureID;

void loadTexture() {
    int width, height, channels;
    unsigned char* image = stbi_load("tiles_0006_sphere_600-1628486856.png", &width, &height, &channels, 3);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    stbi_image_free(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void drawSphere() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(0.5, 50, 50);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glTranslatef(0.0f, 0.0f, -2.0f);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    drawSphere();

    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}

void update(int value) {
    angle += 1.0f;
    if (angle > 360) {
        angle -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Rotating Sphere with Texture");

    glEnable(GL_DEPTH_TEST);

    loadTexture();

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    glutMainLoop();

    return 0;
}