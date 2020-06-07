#include <stdio.h>
#include <GL/freeglut.h>
#include <time.h>
#include <math.h>
int r=25,flag;

static void Circledec(int value)
{
    if(r<500 && flag==0)
    {
        r+=20;
        if(r>=500)
        {flag++;
      glClear(GL_COLOR_BUFFER_BIT);

        }

        glutPostRedisplay();
    }
    else if(r>0 && flag==1)
        {

            r=r-25;
            printf("%d",r);
            if(r<=0)
            {flag--;}
            glutPostRedisplay();
        }

    glutTimerFunc(100, Circledec, 0);}




void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-500,500,-500,500);
    glClearColor(0,1,1,0);
}

void display()
{
    float o,m,n;
    glBegin(GL_POINTS);
    for(o=6.28;o>0;o=o-0.001)
    {

        m=r*cos(o);
        n=r*sin(o);
        glColor4f(1,0,0,0);
        glVertex2f(m,n);
    }
    glEnd();
    glFlush();
}



int main(int argc,char** argvgluOrtho2d)
{
 glutInit(&argc,argvgluOrtho2d);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(800,800);
 glutInitWindowPosition(00,00);
 glutCreateWindow("GLTimer");
 init();
 glutDisplayFunc(display);
 glutTimerFunc(100,Circledec,0);
 glClear(GL_COLOR_BUFFER_BIT);
 glutPostRedisplay();
 glutMainLoop();
 return 0;
}
