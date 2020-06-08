#include<GL/freeglut.h>
#include<stdio.h>
#include<math.h>
float a,b,c,radius=0.1;
void init()
  { glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

  }
void mouse(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
   {
    printf("X axis is %d and Y axis is %d\n",x,y);
      if (radius<1)
      {radius=radius+0.1;}
      else
        {radius = 1;}
    }
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
      printf("x axis is %d and Y axis is %d\n",x,y);
       if (radius<1)
       {
        radius=radius-0.05;
       }
       else
       {radius = 1;}

glutPostRedisplay();
    }

}
void bitmap_char(int x, int y, char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}
void display_char()
{
    glColor3f(1.0,0,0);
    bitmap_char(-0.8,0.8 , "-:RITIK AGARWAL",GLUT_BITMAP_TIMES_ROMAN_24);

}

void display()
{
    display_char();
    glBegin(GL_POINTS);
    glVertex2f(0,0);
    for(a=0;a<6.28;a+=0.005)
    {b=0+sin(a)*radius;
    c=0+cos(a)*radius;
    glColor3f(0,1,1);
    glVertex2f(b,c);
    }
  glEnd();
  glFlush();
}

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(00,00);
 glutCreateWindow("Increasing Circle");
 init();

 glutDisplayFunc(display);
  glutMouseFunc(mouse);
 glutMainLoop();
 return 0;
}
