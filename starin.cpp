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
   
lineB(0,0,0.5,0.8);
lineB(1,0,0.5,0.8);
lineB(0,0,1,0);

glColor3f(0,0,1);


lineB(0.25,0.2,0.5,0.6);

lineB(0.25,0.2,0.75,0.2);

lineB(0.5,0.6,0.75,0.2);

glColor3f(0,1,0);


lineB(0.375,0.4,0.5,0.2);

lineB(0.625,0.4,0.375,0.4);

lineB(0.625,0.4,0.5,0.2);
glColor3f(0,0,1);



lineB(0,0.6,0.5,-0.2);
lineB(1,0.6,0.5,-0.2);
lineB(0,0.6,1,0.6);


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
