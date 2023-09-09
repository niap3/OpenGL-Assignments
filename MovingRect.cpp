#include <stdlib.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <GL/glut.h>
// #include "C:\MinGW\include\GL\glut.h"

#define LBoundry -1
#define RBoundry 1
#define BBoundry -1
#define TBoundry 1

class Rect
{
	protected:
		float x,y,h,w;
		float velocityX,velocityY;
		// float cr,cg,cb;
	public:
		Rect(float X,float Y, float H, float W,float vx = 0, float vy = 0)
		{
			x = X;
			y = Y;
			h = H;
			w = W;
			velocityX = vx;
			velocityY = vy;
		}
		void setColor(float R, float G, float B)
		{
			glColor3f(R, G, B);
		}
		void setVelocity(float xx,float yy)
		{
			velocityX = xx;
			velocityY = yy;
		}
		void display()
		{
			x += velocityX; 
			y += velocityY; 
			glBegin(GL_POLYGON);
				glVertex2f(x, y);
				glVertex2f( x + w, y);
				glVertex2f( x + w,  y + h);
				glVertex2f(x,  y + h);
			glEnd();
		}
};

class mainRect : public Rect
{
	float speed=.03;
	public:
	mainRect(float X,float Y, float H, float W,float vx = 0, float vy = 0) : Rect(X,Y,H,W,vx,vy)
	{
		
	}
	void MoveRight()
	{
		setVelocity(speed,0);
	}
	void MoveLeft()
	{
		setVelocity(-speed,0);
	}
	void MoveUp()
	{
		velocityY = speed; 
	}
	void MoveDown()
	{
		velocityY = -speed; 
	}
	void stop()
	{
		setVelocity(0,0);
	}
};

class BoundingRect : public Rect
{
	public:
	void display()
	{
		int flag = touchingBoundry();
		if(flag)
		{
			if (flag == -1)
				velocityY = -velocityY;
			if (flag == 1)
				velocityX = -velocityX;
		}	
		Rect::display();
	}
	int touchingBoundry()
	{
		if(x < LBoundry || x + w > RBoundry)
			return 1;
		if (y < BBoundry || y + h > TBoundry)
			return -1;
		return 0;
	}
	BoundingRect(float X,float Y, float H, float W,float vx = 0, float vy = 0) : Rect(X,Y,H,W,vx,vy)
	{
		
	}
};
 
mainRect pc = mainRect(-0.25,-0.5,0.20,0.20,0,0);
BoundingRect r1 = BoundingRect(-0.5,-0.5,0.25,0.25,0.01,.02);
BoundingRect r2 = BoundingRect(-0.5,-0.5,0.25,0.25,-0.02,.01);

void timeOut(int a)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timeOut,0);
}
void init()
{
	glViewport(0,0,500,500);
	glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(LBoundry,RBoundry,BBoundry,TBoundry);
}

void keypress(unsigned char key, int x, int y)
{
	// if (key == 'a')
		pc.MoveLeft();
}

void keypressUp(unsigned char key, int x, int y)
{
	pc.stop();
}

void display()
{
	

  glClear(GL_COLOR_BUFFER_BIT);
	
	r1.setColor(1.0,0,0);
	r1.display();

	r2.setColor(0,1.0,0);
	r2.display();


	pc.setColor(0,0,1.0);
	// pc.MoveLeft();
	// pc.setVelocity(.03,0);
	pc.display();

  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  int mode = GLUT_RGB|GLUT_SINGLE; 
  glutInitWindowSize(500,500);  
  glutInitDisplayMode(mode);
  glutCreateWindow("GLUT Test");
  init();
  glutDisplayFunc(&display);
  glutKeyboardFunc(&keypress);
  glutKeyboardUpFunc(&keypressUp);
  glutTimerFunc(1000/60,timeOut,0);
  glutMainLoop();

  return EXIT_SUCCESS;
}
