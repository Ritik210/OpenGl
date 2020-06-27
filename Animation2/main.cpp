#include<stdio.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>

float cloud_X = 0;
float cloud_Y = 0;
float cloud_X2 = 0;
float cloud_Y2 = 0;
int cloudStatus = 1;
int boatStatus = 1;
float boatX = 0;
float boatY = 0;

void drawBoat();
void tree();
void scene();
void drawSun();
void cloud();
void cloud2();

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.14 * float(ii) / float(num_segments);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x+cx, y+cy);
    }
    glEnd();
}

void tree()
{
    glPushMatrix();

    glBegin(GL_POLYGON); //tree
    glColor3f(1.2, 0.5, 0.4);
    glVertex2i(339, 385);
    glVertex2i(340, 440);
    glVertex2i(338, 510);
    glVertex2i(358, 510);
    glVertex2i(358, 385);
    glVertex2i(362, 380);
    glEnd();

    glColor3f(0.0, 0.8, 0.1); //1
    DrawCircle(328, 505, 20, 1000);
    glColor3f(0.0, 0.8, 0.1);
    DrawCircle(348, 505, 20, 1000);
    glColor3f(0.0, 0.8, 0.1);
    DrawCircle(368, 505, 20, 1000);
    glColor3f(0.0, 0.8, 0.1); //2
    DrawCircle(318, 525, 20, 1000);
    glColor3f(0.0, 0.8, 0.1);
    DrawCircle(338, 525, 20, 1000);
    glColor3f(0.0, 0.8, 0.1);
    DrawCircle(358, 525, 20, 1000);
    glColor3f(0.0, 0.8, 0.1);
    DrawCircle(378, 525, 20, 1000);
    glColor3f(0.0, 0.8, 0.1); //3
    DrawCircle(328, 545, 20, 1000);
    glColor3f(0.0, 0.8, 0.1);
    DrawCircle(348, 545, 20, 1000);
    glColor3f(0.0, 0.8, 0.1);
    DrawCircle(368, 545, 20, 1000);
    glColor3f(0.0, 0.8, 0.1); //4
    DrawCircle(348, 560, 20, 1000);

    glPopMatrix();
}

void scene()
{
    glPushMatrix();

    glBegin(GL_POLYGON); //sky
    glColor3f(0.4, 0.5, 1.0);
    glVertex2i(0, 800);
    glVertex2i(1200, 800);
    glColor3f(0.7, 0.7, 1.0);
    glVertex2i(1200, 0);
    glVertex2i(0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON); //middle ground
    glColor3f(0.0, 0.5, 0.0);
    glVertex2i(0, 200);
    glVertex2i(200, 350);
    glVertex2i(400, 400);
    glVertex2i(600, 350);
    glVertex2i(800, 320);
    glVertex2i(1000, 300);
    glVertex2i(1200, 200);
    glVertex2i(1200, 100);
    glVertex2i(0, 100);
    glEnd();

    glBegin(GL_POLYGON); //river
    glColor3f(0.2, 0.3, 1.0);
    glVertex2i(0, 100);
    glVertex2i(200, 120);
    glVertex2i(400, 140);
    glVertex2i(600, 150);
    glVertex2i(800, 140);
    glVertex2i(1000, 120);
    glVertex2i(1200, 100);
    glVertex2i(1200, 0);
    glVertex2i(0, 0);
    glEnd();

    tree();

    glBegin(GL_POLYGON); //house
    glColor3f(0.9, 0.7, 0.1);
    glVertex2i(350, 380);
    glVertex2i(350, 460);
    glVertex2i(430, 460);
    glVertex2i(430, 380);
    glEnd();

    glBegin(GL_POLYGON); //mushroom
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(910, 315);
    glVertex2i(920, 330);
    glVertex2i(930, 330);
    glVertex2i(940, 315);
    glEnd();

    glBegin(GL_POLYGON); //mushroom
    glColor3f(0.9, 0.8, 0.0);
    glVertex2i(922, 300);
    glVertex2i(919, 315);
    glVertex2i(931, 315);
    glVertex2i(928, 300);
    glEnd();

    glBegin(GL_POLYGON); //roof
    glColor3f(0.9, 0.0, 0.0);
    glVertex2i(340, 460);
    glVertex2i(390, 500);
    glVertex2i(440, 460);
    glEnd();

    glBegin(GL_POLYGON); //door
    glColor3f(1.0, 1.0, 0.0);
    glVertex2i(370, 380);
    glVertex2i(370, 430);
    glVertex2i(410, 430);
    glVertex2i(410, 380);
    glEnd();

    glPopMatrix();
}

void drawSun()
{
    glPushMatrix();

    glColor3f(3.0, 1.0, 0.5);
    DrawCircle(900, 700, 40, 1000);

    glPopMatrix();
}

void drawCloud()
{
    glPushMatrix();

    glColor3f(0.8, 0.8, 0.8);
    DrawCircle(200, 690, 25, 1000);
    DrawCircle(230, 700, 25, 1000);
    DrawCircle(180, 700, 25, 1000);
    DrawCircle(210, 720, 25, 1000);

    DrawCircle(600, 590, 25, 1000);
    DrawCircle(630, 600, 25, 1000);
    DrawCircle(580, 600, 25, 1000);
    DrawCircle(610, 620, 25, 1000);

    glPopMatrix();
}

void drawBoat()
{
    glPushMatrix();

    glBegin(GL_POLYGON); //boat start
    glColor3f(0.9, 0.8, 0.1);
    glVertex2i(270, 155);
    glVertex2i(375, 165);
    glVertex2i(480, 155);
    glColor3f(1.9, 0.9, 0.1);
    glVertex2i(480, 20);
    glVertex2i(270, 20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.1, 0.1);
    glVertex2i(250, 20);
    glVertex2i(180, 100);
    glVertex2i(380, 80);
    glColor3f(0.8, 0.3, 0.1);
    glVertex2i(600, 100);
    glVertex2i(500, 20);
    glEnd();

    glPopMatrix();
}

void myInit(void)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0.0, 800.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key){
    case 'b':           //boat start
        boatStatus = 1;
        break;
    case 't':           //boat stop
        boatStatus = 0;
        break;
    case 'c':           //cloud start
        cloudStatus = 1;
        break;
    case 'd':           //cloud stop
        cloudStatus = 0;
        break;
    default:
        break;
    }
}

void boat()
{
    if(boatStatus ==1)
    {
        boatX += 0.5;
    }
    if(boatX > 1000)
    {
        boatX = -600;
    }
    glPushMatrix();
    glTranslatef(boatX, boatY, 0);
    drawBoat();
    glPopMatrix();
}

void cloud()
{
    if(cloudStatus == 1)
    {
        cloud_X += 0.2;
    }
    if(cloud_X > 1100)
    {
        cloud_X = -650;
    }

    glPushMatrix();
    glTranslatef(cloud_X, cloud_Y, 0.0);
    drawCloud();

    glPopMatrix();
}

void cloud2()
{
    if(cloudStatus == 1)
    {
        cloud_X2 += 0.3;
    }
    if(cloud_X2 > 600)
    {
        cloud_X2 = -1150;
    }
    glPushMatrix();
    glTranslatef(cloud_X2 + 500, cloud_Y2 + 50, 0.0);
    drawCloud();

    glPopMatrix();
}

void myDisplay(void)
{
    scene();
    drawSun();
    boat();
    cloud();
    cloud2();
    glFlush();

    glutPostRedisplay();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1350, 700);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Ship Animation");
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
