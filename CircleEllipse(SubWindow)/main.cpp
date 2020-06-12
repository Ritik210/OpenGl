#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>

void display()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void display_s1()
{
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
float p;
int r=10;
p=5.0/4.0-r;
int x=0,y=200;
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);
while(x<=y)
{
	glVertex2i(x,y);
	glVertex2i(y,x);
	glVertex2i(-1*x,-1*y);
	glVertex2i(-1*y,-1*x);
	glVertex2i(x,-1*y);
	glVertex2i(-1*y,x);
	glVertex2i(-1*x,y);
	glVertex2i(y,-1*x);
	if(p>=0)
	{
		p=2*x-2*y+5+p;
		x++;
		y--;
	}
	else
	{
	   p=2*x+3+p;
		x++;
    }

}
glEnd();
glFlush();

}

void display_s4()
{glClearColor(1.0,1.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 int a=100,b=200;
 double p;
 float root2=pow(2,0.5);
 int x=0,y=b;
 int xn,yn;
 p=b*b-a*a*b+a*a/4.0;
 glColor3ub(100,0,0);
 glBegin(GL_POINTS);
	 while(b*b*x<=a*a*y)
	 {
	 	glVertex2i(x,y);
	 	glVertex2i(x,-1*y);
	 	glVertex2i(-1*x,y);
	 	glVertex2i(-1*x,-1*y);
	 	if(p>0)
	 	{
	 		p=p+b*b*(2*x+3)-a*a*(2*y-2);
	 		x++;
	 		y--;
	 	}
	 	else
	 	{
	 		p=p+b*b*(2*x+3);
	 		x++;
	 	}
	 	xn=x;
	 	yn=y;
	 }

	 p=(double)b*b*(xn+0.5)*(xn+0.5)+(double)a*a*(yn-1)*(yn-1)-(double)a*a*b*b;

	 x=xn;
	 y=yn;

	while(y>=0)
	 {

	 	glVertex2i(x,y);
	 	glVertex2i(x,-1*y);
	 	glVertex2i(-1*x,y);
	 	glVertex2i(-1*x,-1*y);

	 	if(p<=0)
	 	{
	 		p=p-2*a*a*(y-1)+a*a+b*b*(2*x+2);
	 		x++;
	 		y--;
	 	}
	 	else
	 	{
	 		p=p-2*a*a*(y-1)+a*a;
	 		y--;
	 	}

	 }
 glEnd();

 glFlush();

}

void myinit()
{glClearColor(1.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-400.0,400.0,-350.0,350.0);
 }

void init()
{

 glLoadIdentity();

 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-400.0,400.0,-350.0,350.0);
}







int m,s1,s2,s3,s4;

void initdisplay()
{
	int w=glutGetWindow();
        if(w==s1)
		{
			glClearColor(1.0,0.0,0.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT);
		}

		else if(w==s4)
		{
			glClearColor(0.0,1.0,1.0,1.0);
		    glClear(GL_COLOR_BUFFER_BIT);
		}

}

void mouse(int button,int state,int x,int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int w=glutGetWindow();

		 if(w==s1)
		{
			glutDisplayFunc(display_s1);
			glutPostRedisplay();

		}


		else if(w==s4)
		{
			glutDisplayFunc(display_s4);
			glutPostRedisplay();

		}

	}
}

void resize(int width,int height)
{
    myinit();
    glutSetWindow(s1);
     init();
	 glutReshapeWindow(397,397);
	 glutPositionWindow(0,0);
	 glutPostRedisplay();

   glutSetWindow(s4);
     init();
	 glutReshapeWindow(397,397);
	 glutPositionWindow(401,0);
	 glutPostRedisplay();

}






int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,400);
 	glutInitWindowPosition(100,200);
 	m=glutCreateWindow("Circles");
 	myinit();
    glutDisplayFunc(display);
    glutReshapeFunc(resize);

    s1=glutCreateSubWindow(m,0,0,400,400);
	init();
	glutDisplayFunc(initdisplay);
    glutMouseFunc(mouse);




    s4=glutCreateSubWindow(m,400,0,400,400);
    init();
    glutDisplayFunc(initdisplay);
    glutMouseFunc(mouse);

 	glutMainLoop();
	return 0;
}

