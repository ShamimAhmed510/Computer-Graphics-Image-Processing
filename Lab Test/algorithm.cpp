#include<GL/gl.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
using namespace std;



void direct_line_equation(int x1, int y1, int x2, int y2)
{
    double x = x1;
    double y = y1;

    double slope = (double)(y2-y1)/(x2-x1);
    double b = y1 - slope * x1;

    glBegin(GL_POINTS);
    glVertex2d(x,y);

    while( y < y2)
    {
        y+=1;
        x = (y-b) / slope ;
        glVertex2i(x,y);
    }
    glEnd();
}

void dda(int x1, int y1, int x2, int y2)
{
    int dx = x2-x1;
    int dy = y2-y1;
    int steps = max(abs(dx),abs(dy));

    float xinc = (float) dx/steps;
    float yinc = (float) dy/steps;
    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);

    for(int i=0; i<=steps; i++)
    {
        glVertex2f(x,y);
        x+=xinc;
        y+=yinc;
    }
    glEnd();

}


void bresenham_line(int x1, int y1, int x2, int y2)
{
    int dx = x2-x1;
    int dy = y2-y1;
    int d = 2 * dy - dx;
    int dT = 2 * (dy-dx);
    int dS = 2 * dy;
    int x = x1;
    int y = y1;

    glPointSize(3.0f);
    glBegin(GL_POINTS);
    while(x <= x2)
    {
        glVertex2i(x,y);
        if(d < 0)
        {
            d+=dS;
        }
        else {
            d+=dT;
            y++;
        }
        x++;

    }
    glEnd();

}

void bresenham_circle(int r)
{
    int d = 3-2*r;
    int x = 0;
    int y = r;

    glPointSize(3.0f);
    glBegin(GL_POINTS);

    while(x < y)
    {
        glVertex2i(x,y);
        glVertex2i(-x,y);
        glVertex2i(x,-y);
        glVertex2i(-x,-y);

        glVertex2i(y,x);
        glVertex2i(-y,x);
        glVertex2i(y,-x);
        glVertex2i(-y,-x);

        if( d < 0)
        {
            d+=4*x+6;
        }
        else
        {
            d+=4*(x-y)+10;
            y--;
        }
        x++;
    }
    glEnd();
}


void midpoint_circle(int r)
{
    int d = 1-r;
    int x = 0;
    int y = r;

    glPointSize(3.0f);
    glBegin(GL_POINTS);

    while(x < y)
    {
        glVertex2i(x,y);
        glVertex2i(-x,y);
        glVertex2i(x,-y);
        glVertex2i(-x,-y);

        glVertex2i(y,x);
        glVertex2i(-y,x);
        glVertex2i(y,-x);
        glVertex2i(-y,-x);

        if( d < 0)
        {
            d+=2*x+3;
        }
        else
        {
            d+=3*(x-y)+5;
            y--;
        }
        x++;
    }
    glEnd();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0, 1.0);

    glBegin(GL_LINES);
    glVertex2i(-100, 0);
    glVertex2i(100, 0);
    glVertex2i(0, -100);
    glVertex2i(0, 100);
    glEnd();
    // function call
    // direct_line_equation(-50, -50, 50, 50);
    //dda(-50, -50, 50, 50);

    // bresenham_line(-50, -50, 50, 50);

    //bresenham_circle(50);
    // midpoint_circle(80);

    glFlush();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100,100, -100, 100, -10, 10);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,10);
    glutCreateWindow("CG_Lab");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
