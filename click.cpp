#include <GL/glut.h>
void drawString(float x, float y, float z, char *string) {
   glRasterPos2f(x,y);

  for (char* c = string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
  }
}

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

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE);
 glutInitWindowSize(400, 300);
 glutCreateWindow("Akash");
 R=0;
 B=1;
 G=0;
 glutDisplayFunc(displayMe);
glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
}

