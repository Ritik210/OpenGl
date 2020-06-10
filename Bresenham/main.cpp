#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;


double x_1, y_1, x_2, y_2;  // x_1 and y_1 x and y coordinates for 1st point
                           // x_2 and y_2 x and y coordinates for 2nd point
int flag {1};             // it is used to take coordinates in mouse functionality (go down)

//For slope print on screen.
void renderbitmap(float x, float y, void *font, char *string)
 {
    char *c;
    glRasterPos2f(x, y);
    for(c = string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void displaySlope(float z) {
    glColor3f(0.0f, 0.0f, 1.0f);
	char str[] = "Slope: ";
	renderbitmap(200, 450, GLUT_BITMAP_TIMES_ROMAN_10, str);
    char buf[100] = {0};
	gcvt(z, 6, buf);
    renderbitmap(230, 450, GLUT_BITMAP_TIMES_ROMAN_10, buf);
	glFlush();
}



void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
    glClearColor(1, 1, 1, 1);
}

void display()
{

    float m;  //slope
    int dy, dx;

    dy=(y_2-y_1);
    dx=(x_2-x_1);

    m=(y_2-y_1)/(x_2-x_1);   // calculating slope of a line
    displaySlope(m);
    cout << "Value of m is : " << m << endl;

    int P{0}, x=0, y=0;

    x=x_1;
    y=y_1;

    if(m >= 0 && m<=1)   // 1st octant
    {
      if(x <= x_2 && y<= y_2)
      {
        P=(2*dy)-dx;
        cout << "This is 3rd "<< P << endl;
        while(x <= x_2 && y<= y_2)
        {
            x++;


            if (P < 0){
                P=P+(2*dy);
            }

            else{
                P=P+(2*dy)-(2*dx);
                y++;
            }

            glColor3f(1, 0, 0);
            glPointSize(3);
            glBegin(GL_POINTS);

            glVertex2f(x, y);
            glEnd();

        }
      }

      else if(x >= x_2 && y>= y_2)   //5th octant
        {
            P=dx-(2*dy);
            cout << "This is 5th" << endl;

            while(x >= x_2 && y >= y_2)
            {
                --x;
                if (P < 0){
                    P=P-(2*dy);
                }

                else{
                    P=P-(2*dy)+(2*dx);
                    y--;
                }

                glColor3f(0, 1, 1);
                glPointSize(3);
                glBegin(GL_POINTS);
                glVertex2f(x, y);
                glEnd();

            }
        }
    }

    else if(m > 1)   // 2nd octant
    {
        if(x<=x_2 && y<=y_2)
        {

        P=(2*dx)-dy;
      cout << "This is 2nd "<< P << endl;
        while(x <= x_2 && y<= y_2)
        {
            y++;


            if (P < 0){
                P=P+(2*dx);
            }

            else{
                P=P+(2*dx)-(2*dy);
                x++;
            }

            glColor3f(0, 1, 0);
            glPointSize(3);
            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();

        }


    }
     /*else if(x >= x_2 && y>= y_2)   //6th octant
        {
            P=dy-(2*dx);
            cout << "i am in 6th" << endl;

            while(x >= x_2 && y >= y_2)
            {
                y--;

                if (P < 0){
                    P=P-(2*dx);
                }

                else{
                    P=P-(2*dx)+(2*dy);
                    x--;
                }

                glColor3f(1, 0, 1);
                glPointSize(3);
                glBegin(GL_POINTS);
                glVertex2f(x, y);
                glEnd();*/
               // glFlush();

            }





    else if(m < -1)   // 3rd octant
    {


        P=(2*dx)+dy;
         cout << "This is 3rd "<< P << endl;
        while(x >= x_2 && y<= y_2)
        {
            y++;


            if (P < 0){
                x--;
                P=P+(2*dx)+(2*dy);
               }

            else{
                P=P+(2*dx);
                }

            glColor3f(0, 0, 1);
            glPointSize(3);
            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();

            }

    }

    else if(m <= 0 && m >=(-1))   // 4th octant
    {
        if(x>=x_2 && y<= y_2)
        {
        cout << "This is 4th" << endl;
        P=-(2*dy)-dx;

        while(x >= x_2 && y<= y_2)
        {
            x--;


            if (P < 0){
                P=P+(2*dy);
            }

            else{
                P=P+(2*dy)+(2*dx);
                y++;
            }

            glColor3f(1, 1, 0);
            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();
        }
        }



      else if(x <= x_2 && y >= y_2)     //8th octant
        {
            cout << "i am in 8th" << endl;
            P=-(2*dy)-dx;

            while(x <= x_2 && y >= y_2)
            {
                x++;


                if (P < 0){
                    P=P-(2*dy);
                }

                else{
                    P=P-(2*dy)-(2*dx);
                    y--;
                }

                glColor3f(1, 1, 1);
                glBegin(GL_POINTS);
                glVertex2f(x, y);
                glEnd();

            }
        }
    }


 glFlush();
}

void mouse(int button, int state, int mousex, int mousey)
{

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {

        if(flag == 1)
        {
            x_1 = mousex;       // first point x coordinate
            y_1 = 500-mousey;   // first point y coordinate
            flag = 0;

            cout << "x and y coordinates for 1st point " << x_1 << " " << y_1 << endl;


        }

        else
        {   x_2 = mousex;       // second point x coordinate
            y_2 = 500-mousey;   // second point y coordinate
            flag = 1;

            cout << "x and y coordinates for 2nd point " << x_2 << " " << y_2 << endl;

            glClear(GL_COLOR_BUFFER_BIT);
            glutPostRedisplay();
        }

    }


    else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)  // clear buffer  // reset
    {
        glClearColor(0, 0, 0, 1);

        flag = 1;
        x_1 = 0;
        y_1 = 0;
        x_2 = 0;
        y_2 = 0;
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();

    }

}



int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham Line");
    init();
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
