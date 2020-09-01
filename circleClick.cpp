#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int onMouse;
int R,G,B;
void displayMe(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_TRIANGLES);
glColor3f(R,G,B);
glVertex3f(1, 0, 0);
glVertex3f(0, 1, 0);
glVertex3f(0, 0, 0);
 glEnd();
 glFlush();
}
void mouseClicks(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        R=0;
        B=1;
        G=0;
        glutDisplayFunc(displayMe);
    }
}

void keyboard(unsigned char key, int x, int y)
{
	//-------- spin --------
	if(key=='x')
	{
	R=1;
        B=0;
        G=0;
 glutInitDisplayMode(GLUT_SINGLE);
 glutInitWindowSize(400, 300);
 glutCreateWindow("Akash");
 glutDisplayFunc(displayMe);
 glutMainLoop();

	}
}
void drawFilledSun(){
    //static float angle;
 glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -10);
    int i, x, y;
    double radius = 0.30;
    //glColor3ub(253, 184, 19);     
    glColor3ub(255, 0, 0);
    double twicePi = 2.0 * 3.142;
    x = 0, y = 0;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }
    glEnd(); //END
}
void DrawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}
void main_loop_function() {
    int c;
    drawFilledSun();
    DrawCircle(0, 0, 0.7, 100);
    glutSwapBuffers();
    c = getchar();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE);
 glutInitWindowSize(400, 300);
 glutCreateWindow("Akash");
 glutDisplayFunc(main_loop_function);
glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}

