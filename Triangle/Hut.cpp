#include <GL/glut.h>
#include<stdio.h>

void display();
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("Hut");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
 void display()
 {

 }
