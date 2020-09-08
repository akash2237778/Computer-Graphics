#include <GL/glut.h>
#include <math.h>
void lineB(float x1 , float y1 , float x2 , float y2){

glBegin(GL_LINES);
    glVertex2f(150 + x1, 150 +y1);
    glVertex2f(150 + x2, 150 + y2);
 glEnd();
}
void createCircle(float radius , float xShift , float yShift){
    float theta;
   glBegin(GL_LINES);
    for(int i = 0; i< 360; i++){
        theta = i*3.142/180;
        glVertex2f(xShift + radius*cos(theta), yShift +radius*sin(theta));
    }
   glEnd();
}



void displayMe(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
glColor3f(0,1,0);



glColor3f(0,0,1);

createCircle(115.47,150+ 57.735, 150+57.735);
createCircle(15 ,150 , 250);
createCircle(15 , 250, 250);



lineB(55,75,55, 30);

lineB(20,5,90, 5);


glColor3f(1,0,0);

 glFlush();
}

void init(){
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}


int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(500,500);
 glutCreateWindow("Akash");
 init();
 glutDisplayFunc(displayMe);
 glutMainLoop();
 return 0;
}

