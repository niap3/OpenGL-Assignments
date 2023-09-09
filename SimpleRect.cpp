/*
 * This is a very basic Windows C application for testing GLUT (and compatible
 * implementations such as freeglut). It displays a red square, and exits when
 * the escape key is pressed.
 */
#include <stdlib.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include <GL/glu.h>

/* Keyboard callback function */
void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    /* Exit on escape key press */
    case '\x1B':
    {
      exit(EXIT_SUCCESS);
      break;
    }
  }
}

/* Display callback function */



void display()
{
	// glViewport(0,0,50,100);
glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
// gluOrtho2D(-1,1,-1,1); 
// gluOrtho2D(-0.5,0.5,-0.5,0.5);
gluOrtho2D(-1,1,-1,1);

  glClear(GL_COLOR_BUFFER_BIT);

  /* Display a red square */
  glColor3f(1.0f, 0.0f, 0.0f);

  glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f(-0.5f,  0.5f);
  glEnd();

  glFlush();
}
void timer(int id) {

   glutPostRedisplay();
}

/* Main method */
int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  int mode = GLUT_RGB|GLUT_SINGLE; 
  glutInitDisplayMode(mode);
  glutCreateWindow("GLUT Test");
  glutInitWindowSize(1000,500);  
  // glutReshapeWindow(1000, 500);
  /* Create a single window with a keyboard and display callback */
  glutKeyboardFunc(&keyboard);
  glutDisplayFunc(&display);
	// glutTimerFunc(1000/60,timer,1);
  /* Run the GLUT event loop */
  glutMainLoop();

  return EXIT_SUCCESS;
}
