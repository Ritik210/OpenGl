#include<GL/Glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;



float xstart,ystart,xend, yend;

bool flag=true;


void init(){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

}


void renderbitmap(float x, float y, void *font, char *string) {
    char *c=0;
    glRasterPos2f(x, y);
    for(c = string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void displaySlope(float z) {
    glColor3f(0.0f, 1.0f, 1.0f);
	char str[] = "Slope: ";
	renderbitmap(300, 400, GLUT_BITMAP_TIMES_ROMAN_10, str);
    char buf[100] = {0};
	gcvt(z, 6, buf);
    renderbitmap(335, 400, GLUT_BITMAP_TIMES_ROMAN_10, buf);
	glFlush();
}


void display(void)
{
    float dy=0.0,dx=0.0,slope=0.0;

    float i,j;


        dy = yend - ystart;
        dx = xend - xstart;

        slope = dy/dx;

        displaySlope(slope);
        cout<<slope<<endl;


         glColor3f(0,1,0);
         glPointSize(3);

       if(slope<=1 && slope>0) //1st octant
       {
        cout<<"I am in first Octant"<<endl;
        for(i=xstart, j=ystart; i<=xend && j<=yend ; i+=1, j= j+slope)
         {
         glBegin(GL_POINTS);
         glVertex2f(i,j);
         glEnd();
         }

         if(xend<=xstart && yend<=ystart) //5th octant
         {
          cout<<"I am in fifth Octant"<<endl;
          for(i=xstart, j=ystart; i>=xend && j>=yend ; i-=1, j= j-slope)
          {
           glBegin(GL_POINTS);
           glVertex2f(i,j);
           glEnd();
          }
          }
        }

        else if(slope>1) //2nd Octant
       {

         cout<<"I am in Second Octant"<<endl;
         for(i=xstart, j=ystart; i<=xend && j<=yend ; i=i+(1/slope), j+=1)
         {
         glBegin(GL_POINTS);
         glVertex2f(i,j);
         glEnd();
         }



       }

        else if(slope < (-1)) //3rd Octant
       {
           cout<<"I am in third Octant"<<endl;
         for(i=xstart, j=ystart; i>=xend && j<=yend ; i=i+(1/slope), j+=1)
         {
         glBegin(GL_POINTS);
         glVertex2f(i,j);
         glEnd();
         }


       }

        else if(slope >= (-1) && slope <=0) //4th Octant
       {
           cout<<"I am in fourth Octant"<<endl;
         for(i=xstart, j=ystart; i>=xend && j<=yend ; i=i-1, j=j-slope)
         {
         glBegin(GL_POINTS);
         glVertex2f(i,j);
         glEnd();
         }
         if(xend>xstart && yend<ystart) //7th octant
       {
        cout<<"I am in 8th Octant"<<endl;
        for(i=xstart, j=ystart; i<=xend && j>=yend ; i=i+1, j= j+slope)
         {
         glBegin(GL_POINTS);
         glVertex2f(i,j);

         glEnd();
         }
       }
       }

    glFlush();

}


void mouse(int button, int state, int mousex, int mousey)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
      if(flag == true)
      {
        xstart=mousex;
        ystart=500-mousey;
        flag = false;
        cout << "coordinates of first point: " << xstart << "\t" << ystart << endl;
      }
      else
      {
        xend=mousex;
        yend=500-mousey;
        flag = true;


        cout << "coordinates of second point: " << xend << "\t" << yend << endl;

        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();

      }
  }

  else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
      glClearColor(0,0,0,1);
      flag=true;
      xstart = 0;
      ystart = 0;
      xend = 0;
      yend = 0;

      glClear(GL_COLOR_BUFFER_BIT);
      glutPostRedisplay();
  }
}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("DD Line");
    init();
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
