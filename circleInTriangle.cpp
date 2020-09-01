#include <GL/glut.h>
#include <math.h>
void lineB(float x1 , float y1 , float x2 , float y2){

glBegin(GL_LINES);
    glVertex2f(150 + x1, 150 +y1);
    glVertex2f(150 + x2, 150 + y2);
 glEnd();
}
void createCircle(){
    float theta;
   glBegin(GL_LINES);
    for(int i = 0; i< 360; i++){
        theta = i*3.142/180;
        glVertex2f(150+42 + 57.735 + 115.47*cos(theta), 150+57.735 +115.47*sin(theta));
    }
   glEnd();
}
void triangleLine(int y){
    lineB( y*0.5780, y , (y-346.4) /(-1.732), 150);
}


void displayMe(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
glColor3f(0,1,0);
   
lineB(100,173.2,200,0);
lineB(0,0,200,0);
lineB(0,0,100,173.2);



glColor3f(0,0,1);

createCircle();
lineB(0.5,0.8,0.5,0);


glColor3f(1,0,0);
lineB(14.45 , 25 , 185.56, 25);

lineB( 50*0.5780, 50 , (50-346.4) /(-1.732), 50);

lineB( 100*0.5780, 100 , (100-346.4) /(-1.732), 100);

lineB( 75*0.5780, 75 , (75-346.4) /(-1.732), 75);

lineB( 125*0.5780, 125 , (125-346.4) /(-1.732), 125);

lineB( 150*0.5780, 150 , (150-346.4) /(-1.732), 150);



lineB(100,0 , 100,173.2);
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

