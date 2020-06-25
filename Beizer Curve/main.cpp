
#define GL_SILENCE_DEPRECATION
#include<GL/glut.h>
#include<iostream>
#include<math.h>

using namespace std;

int cx[6],cy[6];

int clicks=6;
int count1=0;
void myInit(void)
{
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,600.0,0.0,600.0);
}

void drawcontrolpoints(int a,int b)
{
glColor3f(1,0,0);
glPointSize(4.0);
glBegin(GL_POINTS);
glVertex2f(a,b);
glEnd();
glFlush();
}

int factorial(int n)
{
if(n<=1)
return 1;

else
n=n*factorial(n-1);
return n;
}

float combination(float n,float r)
{
float res;
res=factorial(n)/(factorial(n-r)*factorial(r));
return res;
}

void drawline(double a,double b,double c,double d)
{
glColor3f(0,0,1);
glLineWidth(2.0);
glBegin(GL_LINES);
glVertex2f(a,b);
glVertex2f(c,d);
glEnd();
glFlush();
}

double* bezierCurveStandard(double t)
{
static double pt[2];

    pt[0]=0;
    pt[1]=0;

for(int i=0;i<clicks;i++)
{
pt[0]=pt[0]+combination((float)(clicks-1),(float)i)*pow(t,(double)i)*pow((1-t),(clicks-1-i))*cx[i];

pt[1]=pt[1]+combination((float)(clicks-1),(float)i)*pow(t,(double)i)*pow((1-t),(clicks-1-i))*cy[i];
}

return pt;
}

void display()
{
//glClear(GL_COLOR_BUFFER_BIT);


glFlush();
}

void mouse(int button, int state, int mousex, int mousey)
{
if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{
cx[count1]=mousex;
cy[count1]=600-mousey;


drawcontrolpoints(cx[count1],cy[count1]);

count1++;

if(count1==clicks)
{
cout<<"Control Points:"<<endl<<endl;
for(int j=0;j<clicks;j++)
{
cout<<cx[j]<<","<<cy[j]<<endl<<endl;
}

double ps_x=cx[0];
double ps_y=cy[0];

for(double t=0.0;t<=1.0;t+=0.02)
{

double* pt=bezierCurveStandard(t);
cout<<"Next Point:"<<endl;
cout<<pt[0]<<","<<pt[1]<<endl;

drawline(ps_x,ps_y,pt[0],pt[1]);
ps_x=pt[0];
ps_y=pt[1];
}
drawline(ps_x,ps_y,cx[5],cy[5]);



count1=0;
}

}
/*else if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
{
    if (verts.size() > 0)
        {
            verts.pop_back();
            selectedvert = -1;
            currentlymoving = false;
            glutPostRedisplay();
        }
}*/
}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(600,600);
glutCreateWindow("Bezier Curve");
glutDisplayFunc(display);
glutMouseFunc(mouse);
myInit();
glutMainLoop();
return 0;
}
