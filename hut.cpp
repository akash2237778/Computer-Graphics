#include <GL/glut.h>
void lineB(float x1 , float y1 , float x2 , float y2){

glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
 glEnd();
}

void displayMe(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
glColor3f(0,1,0);
    glVertex2f(0,0);
    glVertex2f(0,0.4);
    glEnd();
glBegin(GL_LINES);
    glVertex2f(0.5,0);
    glVertex2f(0.5,0.4);
 glEnd();
glBegin(GL_LINES);
    glVertex2f(0,0.4);
    glVertex2f(0.25,0.6);
 glEnd();

glBegin(GL_LINES);
    glVertex2f(0.5,0.4);
    glVertex2f(0.25,0.6);
 glEnd();

glBegin(GL_LINES);
    glVertex2f(0,0);
    glVertex2f(0.5,0);
 glEnd();

lineB(0.2,0,0.2,0.2);

lineB(0.3,0,0.3,0.2);

lineB(0.2,0.2,0.3,0.2);
lineB(0.5,0.4,0.7,0.4);

lineB(0.25,0.6,0.45,0.6);

lineB(0.45,0.6,0.7,0.4);

lineB(0.7,0.4,0.7,0.075);

lineB(0.5,0,0.7,0.075);

 glFlush();
}


int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_RGB);
 glutInitWindowSize(600, 600);
 glutCreateWindow("Akash");
 glutDisplayFunc(displayMe);
 glutMainLoop();
 return 0;
}

