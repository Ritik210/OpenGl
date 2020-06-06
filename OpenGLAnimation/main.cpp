
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
int carStatus = 1;
float carX = -800;
float carY = 0;

void DrawCar();

void display()
{
 glPushMatrix();
glClear(GL_COLOR_BUFFER_BIT);

  //Upper Rectangle
  glBegin(GL_QUADS);
  glColor4f(0.0,1.0,1.0,1.0);
  glVertex2f(-800.0,400.0);
  glVertex2f(800.0,400.0);
  glVertex2f(800.0,800.0);
  glVertex2f(-800.0,800.0);
  glEnd();

  //Hut 1

  glBegin(GL_QUADS);
  glColor4f(0.5,0.3,0.0,1.0);
  glVertex2f(-50.0,100.0);
  glVertex2f(50.0,100.0);
  glVertex2f(50.0,180.0);
  glVertex2f(-50.0,180.0);
  glEnd();

  glBegin(GL_QUADS);
  glColor4f(0.5,0.0,0.0,1.0);
  glVertex2f(50.0,100.0);
  glVertex2f(200.0,100.0);
  glVertex2f(200.0,180.0);
  glVertex2f(50.0,180.0);
  glEnd();

  glBegin(GL_QUADS);
  glColor4f(0.5,0.0,1.0,1.0);
  glVertex2f(50.0,180.0);
  glVertex2f(200.0,180.0);
  glVertex2f(150.0,300.0);
  glVertex2f(0.0,300.0);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor4f(0.5,0.3,0.0,1.0);
  glVertex2f(-50.0,180.0);
  glVertex2f(50.0,180.0);
  glVertex2f(0.0,300.0);
  glEnd();

  //Hut 2
  glBegin(GL_QUADS);
  glColor4f(0.5,0.3,0.0,1.0);
  glVertex2f(-750.0,200.0);
  glVertex2f(-700.0,200.0);
  glVertex2f(-700.0,275.0);
  glVertex2f(-750.0,275.0);
  glEnd();


  glBegin(GL_QUADS);
  glColor4f(0.5,0.0,0.0,1.0);
  glVertex2f(-700.0,200.0);
  glVertex2f(-600.0,200.0);
  glVertex2f(-600.0,275.0);
  glVertex2f(-700.0,275.0);
  glEnd();


  glBegin(GL_QUADS);
  glColor4f(0.5,0.0,1.0,1.0);
  glVertex2f(-700.0,275.0);
  glVertex2f(-600.0,275.0);
  glVertex2f(-625.0,300.0);
  glVertex2f(-725.0,300.0);
  glEnd();


  glBegin(GL_TRIANGLES);
  glColor4f(0.5,0.3,0.0,1.0);
  glVertex2f(-700.0,275.0);
  glVertex2f(-725.0,300.0);
  glVertex2f(-750.0,275.0);
  glEnd();


  //Hut 3
  glBegin(GL_QUADS);
  glColor4f(0.5,0.3,0.0,1.0);
  glVertex2f(-650.0,-750.0);
  glVertex2f(-550.0,-750.0);
  glVertex2f(-550.0,-500.0);
  glVertex2f(-650.0,-500.0);
  glEnd();


  glBegin(GL_QUADS);
  glColor4f(0.5,0.0,0.0,1.0);
  glVertex2f(-550.0,-750.0);
  glVertex2f(-400.0,-750.0);
  glVertex2f(-400.0,-500.0);
  glVertex2f(-550.0,-500.0);
  glEnd();


  glBegin(GL_QUADS);
  glColor4f(0.5,0.0,1.0,1.0);
  glVertex2f(-550.0,-500.0);
  glVertex2f(-400.0,-500.0);
  glVertex2f(-450.0,-350.0);
  glVertex2f(-600.0,-350.0);
  glEnd();


  glBegin(GL_TRIANGLES);
  glColor4f(0.5,0.3,0.0,1.0);
  glVertex2f(-650.0,-500.0);
  glVertex2f(-550.0,-500.0);
  glVertex2f(-600.0,-350.0);
  glEnd();

  { //Sun
      float x1,y1,x2,y2;
     float angle;
    double r = 100.0;
    x1 = -430.0;
    y1 = 600.0;
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

  }

// Mountains

  glBegin(GL_TRIANGLES);
  glColor4f(0.0,1.0,0.0,1.0);
  glVertex2f(-800.0,400.0);
  glVertex2f(-400.0,400.0);
  glVertex2f(-600.0,700.0);
  glEnd();




  glBegin(GL_QUADS);
  glColor4f(0.0,1.0,0.0,1.0);
  glVertex2f(-400.0,400.0);
  glVertex2f(0.0,400.0);
  glVertex2f(-200.0,700.0);
  glVertex2f(-450.0,450.0);
  glEnd();


  glBegin(GL_QUADS);
  glColor4f(0.0,1.0,0.0,1.0);
  glVertex2f(0.0,400.0);
  glVertex2f(400.0,400.0);
  glVertex2f(200.0,700.0);
  glVertex2f(-50.0,450.0);
  glEnd();

  glBegin(GL_QUADS);
  glColor4f(0.0,1.0,0.0,1.0);
  glVertex2f(400.0,400.0);
  glVertex2f(800.0,400.0);
  glVertex2f(600.0,700.0);
  glVertex2f(350.0,450.0);
  glEnd();


  glBegin(GL_QUADS);
  glColor4f(0.5,0.3,0.0,1.0);
  glVertex2f(325.0,0.0);
  glVertex2f(350.0,0.0);
  glVertex2f(350.0,100.0);
  glVertex2f(325.0,100.0);
  glEnd();


  glBegin(GL_TRIANGLES);
  glColor4f(0.0,1.0,0.0,1.0);
  glVertex2f(300.0,100.0);
  glVertex2f(375.0,100.0);
  glVertex2f(337.5,180.0);
  glEnd();


  glBegin(GL_TRIANGLES);
  glColor4f(0.0,1.0,0.0,1.0);
  glVertex2f(300.0,150.0);
  glVertex2f(375.0,150.0);
  glVertex2f(337.5,230.0);
  glEnd();


  glBegin(GL_TRIANGLES);
  glColor4f(0.0,1.0,0.0,1.0);
  glVertex2f(300.0,200.0);
  glVertex2f(375.0,200.0);
  glVertex2f(337.5,260.0);
  glEnd();



  glBegin(GL_LINES);
  glColor4f(1.0,0.0,0.0,1.0);
  glVertex2f(-800.0,-175.0);
  glVertex2f(800.0,-175.0);
  glEnd();
  glPopMatrix();
}

void Drawcar()
{
   glPushMatrix();
  glBegin(GL_POLYGON);
  glColor4f(0.0,0.0,1.0,1.0);
  glVertex2f(-770.0,-150.0);
  glVertex2f(-800.0,-150.0);
  glVertex2f(-785.0,-100.0);
  glVertex2f(-760.0,-100.0);
  glVertex2f(-745.0,-50.0);
  glVertex2f(-655.0,-50.0);
  glVertex2f(-640.0,-100.0);
  glVertex2f(-615.0,-100.0);
  glVertex2f(-600.0,-150.0);
  glVertex2f(-630.0,-150.0);
  glEnd();

  {
      float x1,y1,x2,y2;
     float angle;
    double r = 25.0;
    x1 = -755.0;
    y1 = -150.0;
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

  }
  {

  float x1,y1,x2,y2;
  float angle;
  double r = 25.0;

  x1 = -645.0;
  y1 = -150.0;
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
  }

  glBegin(GL_QUADS);
  glColor4f(1.0,1.0,1.0,1.0);
  glVertex2f(-655.0,-100.0);
  glVertex2f(-655.0,-65.0);
  glVertex2f(-680.0,-65.0);
  glVertex2f(-680.0,-100.0);
  glEnd();


  glBegin(GL_QUADS);
  glColor4f(1.0,1.0,1.0,1.0);
  glVertex2f(-745.0,-100.0);
  glVertex2f(-720.0,-100.0);
  glVertex2f(-720.0,-65.0);
  glVertex2f(-745.0,-65.0);
  glEnd();
  glPopMatrix();

}
void car()
{
    if(carStatus == 1)
    {
        carX += 0.8;
    }
    if(carX>1600)
    {
        carX = 0;
    }
    glPushMatrix();
    glTranslatef(carX, carY, 0);
    Drawcar();
    glPopMatrix();


}
void Mydisplay()
{
    display();
    //Drawcar();
    car();
    glFlush();

    glutPostRedisplay();
    glutSwapBuffers();
}












void init()
{
   glClearColor(0.0,0.0,0.0,1.0);
   glColor3f(1.0f,1.0f,1.0f);
   glPointSize(0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
    gluOrtho2D(-800.0, 800.0, -800.0, 800.0);
}


int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(00,00);
  glutInitWindowSize(500,500);
  glutCreateWindow("Car Animation");

  glutDisplayFunc(Mydisplay);
  init();
 // glutDisplayFunc(Drawcar);



  glutMainLoop();
  return 0;
}


