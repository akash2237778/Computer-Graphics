#include <GL/glut.h>
void drawString(float x, float y, float z, char *string) {
   glRasterPos2f(x,y);

  for (char* c = string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
  }
}

void displayMe(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_TRIANGLES);
glColor3f(0,1,0);
glTranslatef(50, 50, 0);
glRotatef(45, 0, 0, 1);
glTranslatef(-50, -50, 0);
glVertex3f(1, 0, 0);
glVertex3f(0, 1, 0);
glVertex3f(0, 0, 0);
char g[] = "Akash";
drawString(0.5,0.5,0, g);
 glEnd();
 glFlush();
}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE);
 glutInitWindowSize(400, 300);
 glutCreateWindow("Akash");
 glutDisplayFunc(displayMe);
 glutMainLoop();
 return 0;
}

