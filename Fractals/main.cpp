#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

//#define BARNSLEY 3
int points=50000;

void myinit(void)
{
      /* attributes */
      glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
      glColor3f(0.133,0.545,0.133);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, 500.0, 0.0, 500.0);
      glMatrixMode(GL_MODELVIEW);
}

/* Where the fractal is drawn-FERN*/
void barnsleyFern(void)
{
	typedef GLfloat point2[2];
	point2 p = {0.0,50.0},newPoint;

	/*Probability table of the 3 transformations*/
	double prob[3] = {85, 92, 99};

	glClear ( GL_COLOR_BUFFER_BIT );

	/*main drawing loop*/
    for(int i=0; i<points; i++)
	{
	   GLfloat prevx=p[0];
	   GLfloat randnum=rand()%100 +1;
	   if (randnum<prob[0])
       {
            p[0]=p[0]*0.85+0.04*p[1];
            p[1]=prevx*(-0.04)+0.85*p[1]+1.6;
	   }
	   else if(randnum<prob[1])
	   {
            p[0]=0.2*p[0]-0.26*p[1];
            p[1]=0.23*prevx+0.22*p[1]+1.6;
	   }
	   else if(randnum<prob[2])
	   {
            p[0]=-0.15*p[0]+0.28*p[1];
            p[1]=0.26*prevx+0.24*p[1]+0.44;
	   }
	   else
	   {
            p[0]= 0.00 * p[0] + 0.00 * p[1] + 0.0;;
            p[1]= 0.00 * p[0] + 0.16 * p[1] + 0.0;;
	   }

	newPoint[0]=p[0]*50+250;
	   newPoint[1]=p[1]*50;
	   if(i>100)
	   {
		  /*Plot new point*/
		  glBegin(GL_POINTS);
               glVertex2fv(newPoint);
          glEnd();
	   }
  }

	//  Clear all buffers.
	glFlush ( );
	glutSwapBuffers();
}

/* myDisplay */
void myDisplay()
{
            barnsleyFern();
}
int main(int argc, char** argv)
{
    /* Standard GLUT initialization */
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); /* double buffering */
    glutInitWindowSize(500,500); /* 500 x 500 pixel window */
    glutInitWindowPosition(0,0); /* place window top left on display */
    glutCreateWindow("Fractals"); /* window title */
    glutDisplayFunc(myDisplay);
    myinit();

    glutMainLoop(); /* enter event loop */

    return 0;
}
