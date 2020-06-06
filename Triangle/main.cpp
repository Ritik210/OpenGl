

#include <GL/glut.h>
#include<stdio.h>
void display()
{

 glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
  glColor4f(0.0,0.0,1.0,1);
    glVertex2f(0.0,0.5);
    glColor4f(0.0,0.0,1.0,1);
    glVertex2f(0.5,-0.5);
    glColor4f(0.0,0.0,1.0,1);
    glVertex2f(-0.5,-0.5);
  glEnd();
  glFlush();
}

int
main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutCreateWindow("Triangle");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
