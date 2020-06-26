#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include <math.h>
#include<ctype.h>
#include<iostream>
using namespace std;

float tx=50.0,ty=50.0,sx=3.0,sy=3.0,theta=30.0;
int choice,n,vertex,shx=2,shy=2;
float xd[10],yd[10],X1[10],Y1[10];
float SX, SY, TX, TY;

void initt()
{
	glClearColor(1.0,1.0,0.0,1.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D(-800,800,-800,800);
}

void translation(){
	 int i;
	for(i=1;i<=vertex;i++){
		X1[i]=xd[i]+tx;
		Y1[i]=yd[i]+ty;
	}
}

void scaling(){
	float xh[10],yh[10]; int i=1;

    for(i=1;i<=vertex;i++){
    	xh[i]=xd[i]-xd[1];
    	yh[i]=yd[i]-yd[1];
    }

	for(i=1;i<=vertex;i++){
		xh[i]=xh[i]*sx;
		yh[i]=yh[i]*sy;
	}
 	for(i=1;i<=vertex;i++){
   		X1[i]=xh[i]+2*xd[1];
   		Y1[i]=yh[i]+yd[1];
	}
}

void rotation(){

	float t,xh[10],yh[10];
	int i;
	t= -1*(theta * 3.14/180);
	double coss = cos(t);
	double sinn = sin(t);

	for(i=1;i<=vertex;i++){
    			X1[i] = xd[1] + (xd[i]*coss - yd[i]*sinn);
    			Y1[i] = yd[1] + (xd[i]*sinn + yd[i]*coss);
    	}
}

void shearX(){
	int i;
	for(i=0;i<=vertex;i++){
		X1[i]=xd[i]+shx*yd[i];
		Y1[i]=yd[i];
	}
}

void shearY(){
	int i;
	for(i=0;i<=vertex;i++){
		Y1[i]=yd[i]+shy*xd[i];
		X1[i]=xd[i];
	}
}

void reflectionX(){
	int i;
	for(i=0;i<=vertex;i++){
		Y1[i]= -yd[i];
		X1[i]=xd[i];
	}
}

void reflectionY(){
	int i;
	for(i=0;i<=vertex;i++){
		X1[i]=-xd[i];
		Y1[i]= yd[i];
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
	glColor3f(0,0,0);
	bitmap_char(-750, 665, "2D-TRANSFORMATION",GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_char(-750, 625, "PRESS GIVEN KEYS FOR DIFFERENT OPERATIONS",GLUT_BITMAP_9_BY_15);
	bitmap_char(-750, 585, "Press t for Translation",GLUT_BITMAP_9_BY_15);
    bitmap_char(-750, 555, "Press s for Scaling",GLUT_BITMAP_9_BY_15);
    bitmap_char(-750, 525, "Press r for Rotation",GLUT_BITMAP_9_BY_15);
    bitmap_char(-750, 495, "Press x for Reflection in x-direction",GLUT_BITMAP_9_BY_15);
    bitmap_char(-750, 465, "Press y for Reflection in y-direction",GLUT_BITMAP_9_BY_15);
    bitmap_char(-750, 435, "Press X for Shearing in x-direction",GLUT_BITMAP_9_BY_15);
    bitmap_char(-750, 405, "Press Y for Shearing in y-direction",GLUT_BITMAP_9_BY_15);

    glColor3f(1.0,0,0);
    bitmap_char(-750, 350, "-:RITIK AGARWAL",GLUT_BITMAP_TIMES_ROMAN_24);

}




void display(){
    int i;
    glClear(GL_COLOR_BUFFER_BIT);

    display_char();
    glColor3f(0.0, 0.0, 1.0);
    if(vertex==2){
		glBegin(GL_LINES);
		for(i=1;i<=vertex;i++){
        	glVertex2f(xd[i], yd[i]);
		}
   }
    else{
	glBegin(GL_POLYGON);
		for(i=1;i<=vertex;i++){
	    	glVertex2f(xd[i], yd[i]);
		}
    }
    glEnd();
    glColor3f(1.0, 0.0, 0.0);

    if(vertex==2){
	glBegin(GL_LINES);
	for(i=1;i<=vertex;i++){
        	glVertex2f(X1[i], Y1[i]);
	}
   }
    else{
	glBegin(GL_POLYGON);
	for(i=1;i<=vertex;i++){
        	glVertex2f(X1[i], Y1[i]);
	}
    }

    glEnd();
    glutSwapBuffers();
    glFlush();
}

void operation(GLubyte key, GLint x, GLint y)
{
	float currentX,currentY;
	switch(key)
	{
		case 't':
				translation();
				glutPostRedisplay();
				break;
		case 's':
				scaling();
                glutPostRedisplay();
				break;
		case 'r':
				rotation();
				glutPostRedisplay();
				break;
		case 'x':
				reflectionX();
				glutPostRedisplay();
				break;
		case 'y':
				reflectionY();
				glutPostRedisplay();
				break;
		case 'X':
				shearX();
				glutPostRedisplay();
				break;
		case 'Y':
				shearY();
				glutPostRedisplay();
				break;
	}
}

int main(int argc, char **argv){
	int i;
	printf("ENTER NO. OF VERTICES:-\n");
	scanf("%d",&vertex);
	if(vertex<2 || vertex>10){
		printf("Invalid Input......Exiting......\n");
		exit(0);
	}

	for(i=1;i<=vertex;i++){
		printf("Enter coordinates(x,y):-\n");
		scanf("%f %f", &xd[i], &yd[i]);
	}

/*
   printf("Translation Factors:- ");

	scanf("%f %f",&tx,&ty);

	printf("Scaling Factors:- ");
	scanf("%f %f",&sx,&sy);

	printf("Angle of Rotation:-\n");
	scanf("%f",&theta);

	printf("Shearing Factors:-");
	scanf("%d %d",&shx,&shy);
*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("2D TRANSFORMATION ");
	initt();
	glutDisplayFunc(display);
	glutKeyboardFunc(operation);

	glutMainLoop();
	return 0;
}
