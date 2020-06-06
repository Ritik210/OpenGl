#include <GL/glut.h>
#include<stdio.h>
#include<math.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  float x1,y1,x2,y2;
  float angle;
 // double radius= 0.2;
  double r = 0.15;

  x1 = 0.8;
  y1 = 0.8;
  glColor4f(0.9,0.5,0.0,1.0);

  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x1,y1);
  for(angle=1.0f; angle<361.0f ; angle+= 0.2)
  {
      x2 = x1+sin(angle)*r;
      y2 = y1+cos(angle)*r;
      glVertex2f(x2,y2);
  }
  glEnd();
// Grass
{glColor4f(0.0,1.0,0.0,0.0);
  glBegin(GL_POLYGON);

    glVertex2f(-0.8,-0.6);

    glVertex2f(-1.0,-0.6);

    glVertex2f(-1.0,-1.0);

    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,-0.6);
    glVertex2f(-0.8,-0.6);
  glEnd();
  }
// Ground gate wall
  {glColor4f(1.0,1.0,0.0,0.0);
  glBegin(GL_QUADS);

    glVertex2f(-0.2,-0.8);

    glVertex2f(0.2,-0.8);

    glVertex2f(0.2,-0.2);

    glVertex2f(-0.2,-0.2);
  glEnd();
  }
  { // Ground wall left
      glColor4f(0.5,0.3,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,-0.8);
    glVertex2f(-0.2,-0.8);
    glVertex2f(-0.2,-0.2);
    glVertex2f(-0.8,-0.2);
  glEnd();
  }
  { // Ground wall right
   glColor4f(0.5,0.3,0.0,1.0);
  glBegin(GL_QUADS);
   glVertex2f(0.2,-0.8);
   glVertex2f(0.8,-0.8);
   glVertex2f(0.8,-0.2);

    glVertex2f(0.2,-0.2);
  glEnd();
  }
  {// 1st floor wall
  glColor4f(0.5,0.3,0.0,1.0);
  glBegin(GL_QUADS);

    glVertex2f(0.2,0.0);

    glVertex2f(0.2,0.5);

    glVertex2f(-0.7,0.5);

    glVertex2f(-0.7,0.0);
  glEnd();
  }

  {
  glColor4f(0.0,1.0,0.0,1.0);
  glBegin(GL_QUADS);

    glVertex2f(0.2,-0.2);

    glVertex2f(1.0,-0.2);

    glVertex2f(0.7,0.0);

    glVertex2f(0.06,0.0);
  glEnd();
  }
  {
  glColor4f(0.0,1.0,0.0,1.0);
  glBegin(GL_QUADS);

    glVertex2f(-0.2,-0.2);

    glVertex2f(-1.0,-0.2);

    glVertex2f(-0.7,0.0);

    glVertex2f(-0.06,0.0);
  glEnd();
  }
  {// lower gate triangle
  glColor4f(0.3,0.7,0.1,1.0);
  glBegin(GL_TRIANGLES);

    glVertex2f(-0.2,-0.2);

    glVertex2f(0.2,-0.2);

    glVertex2f(0.0,0.1);
  glEnd();
  }
  // UPPER QUAD WITHOUT WINDOW
  {glColor4f(1.0,1.0,0.0,1.0);
  glBegin(GL_QUADS);

    glVertex2f(0.2,0.0);

    glVertex2f(0.7,0.0);

    glVertex2f(0.7,0.5);

    glVertex2f(0.2,0.5);
  glEnd();
  glColor4f(0.0,0.0,0.0,1.0);
  glBegin(GL_LINES);

    glVertex2f(0.45,0.0);

    glVertex2f(0.45,0.5);
  glEnd();
  }
{
// MOST UPPER QUAD
  glColor4f(0.0,1.0,0.0,1.0);
  glBegin(GL_QUADS);

    glVertex2f(0.2,0.5);

    glVertex2f(0.4,0.7);

    glVertex2f(0.0,1.0);

    glVertex2f(-0.9,0.5);
  glEnd();
}
{ //UPPER TRIANGLE
  glColor4f(0.6,0.3,0.2,1.0);
  glBegin(GL_TRIANGLES);

    glVertex2f(0.2,0.5);

    glVertex2f(0.7,0.5);

    glVertex2f(0.45,0.8);

    //glVertex2f(0.0,0.6);
  glEnd();
}
{ glColor4f(0.5,0.3,0.0,1.0);
  glBegin(GL_QUADS);

    glVertex2f(0.0,-0.3);

    glVertex2f(0.15,-0.3);

    glVertex2f(0.15,-0.7);

    glVertex2f(0.0,-0.7);
  glEnd();
}
 // Window RIGHT
 {
  glColor4f(1.0,1.0,1.0,1.0);
  glBegin(GL_QUADS);

    glVertex2f(0.3,-0.3);

    glVertex2f(0.7,-0.3);

    glVertex2f(0.7,-0.7);

    glVertex2f(0.3,-0.7);
  glEnd();
  glColor4f(0.0,0.0,0.0,1.0);
  glBegin(GL_LINES);

    glVertex2f(0.3,-0.4);

    glVertex2f(0.7,-0.4);

    glVertex2f(0.3,-0.5);

    glVertex2f(0.7,-0.5);

     glVertex2f(0.3,-0.6);

    glVertex2f(0.7,-0.6);

    glVertex2f(0.4,-0.3);

    glVertex2f(0.4,-0.7);

    glVertex2f(0.5,-0.3);

    glVertex2f(0.5,-0.7);

     glVertex2f(0.6,-0.3);

    glVertex2f(0.6,-0.7);
  glEnd();
}
  //Window LEFT
  {
   glColor4f(1.0,1.0,1.0,1.0);
   glBegin(GL_QUADS);
    glVertex2f(-0.3,-0.3);
    glVertex2f(-0.7,-0.3);
    glVertex2f(-0.7,-0.7);
    glVertex2f(-0.3,-0.7);
  glEnd();
  glColor4f(0.0,0.0,0.0,1.0);
  glBegin(GL_LINES);
    glVertex2f(-0.3,-0.4);
    glVertex2f(-0.7,-0.4);
    glVertex2f(-0.3,-0.5);
    glVertex2f(-0.7,-0.5);
    glVertex2f(-0.3,-0.6);
    glVertex2f(-0.7,-0.6);
    glVertex2f(-0.4,-0.3);
    glVertex2f(-0.4,-0.7);
    glVertex2f(-0.5,-0.3);
    glVertex2f(-0.5,-0.7);
    glVertex2f(-0.6,-0.3);
    glVertex2f(-0.6,-0.7);
  glEnd();
  }
  //wINDOW uPPER
    {
   glColor4f(1.0,1.0,1.0,1.0);
   glBegin(GL_QUADS);
    glVertex2f(-0.1,0.1);
    glVertex2f(-0.4,0.1);
    glVertex2f(-0.4,0.4);
    glVertex2f(-0.1,0.4);
  glEnd();
  glColor4f(0.0,0.0,0.0,1.0);
  glBegin(GL_LINES);
    glVertex2f(-0.2,0.1);
    glVertex2f(-0.2,0.4);
    glVertex2f(-0.3,0.1);
    glVertex2f(-0.3,0.4);
    glVertex2f(-0.1,0.2);
    glVertex2f(-0.4,0.2);
    glVertex2f(-0.1,0.3);
    glVertex2f(-0.4,0.3);
  glEnd();
  }

  glFlush();

}

void init()
{
    //glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(0.0,1.0,1.0,1.0);
    //glColor4f(1.0,0.0,0.0,0.0);
}


int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(800,800);
  glutCreateWindow("Hut");
  init();
  glutDisplayFunc(display);


  glutMainLoop();
  return 0;
}


