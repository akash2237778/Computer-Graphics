#include <GL/glut.h>
#include<iostream>
using namespace std;


 int ww = 600, wh = 500;  

 float borderCol[3] = {0.0,1.0,0.0};  

 float fillCol[3] = {1,0.0,0.0};

void lineB(float x1 , float y1 , float x2 , float y2){

glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
 glEnd();
}

 void setPixel(int pointx, int pointy, float f[3])  
 {  
      glBegin(GL_POINTS);  
           glColor3fv(f);  
           glVertex2f(pointx,pointy);  
       glEnd();  
       glFlush();  
  }  
  void getPixel(int x, int y, float pixels[3])  
  {  
       glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);  
  } 

   void boundaryFill4(int x,int y,float fillColor[3],float borderColor[3])  
  {  
       float interiorColor[3];  
       getPixel(x,y,interiorColor);  
       if((interiorColor[0]!=borderColor[0] && (interiorColor[1])!=borderColor[1] && (interiorColor[2])!=borderColor[2]) && (interiorColor[0]!=fillColor[0] && (interiorColor[1])!=fillColor[1] && (interiorColor[2])!=fillColor[2]))  
       {  
            setPixel(x,y,fillColor);  
            boundaryFill4(x+1,y,fillColor,borderColor);  
            boundaryFill4(x-1,y,fillColor,borderColor);  
            boundaryFill4(x,y+1,fillColor,borderColor);  
            boundaryFill4(x,y-1,fillColor,borderColor);  
       }  
  }  


void mouse(int btn, int state, int x, int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
       {  
            int xi = x;  
            int yi = (wh-y);  
            cout<<xi;
            cout<<yi;
            boundaryFill4(xi,yi,fillCol,borderCol);  
       }  
  }  

void displayMe(void)
{
   glClearColor(0.4,0.6,0.5, 1.0);  
 glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
   glColor3f(0.0,1.0,0.0);  
lineB(0,0,50,80);
lineB(100,0,50,80);
lineB(0,0,100,0);


 glFlush();
}

  void myinit()  
  {        
       glViewport(0,0,ww,wh);  
       glMatrixMode(GL_PROJECTION);  
       glLoadIdentity();  
       gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);  
       glMatrixMode(GL_MODELVIEW);  
  } 

int main(int argc, char** argv)
{
 glutInit(&argc,argv);  
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
       glutInitWindowSize(ww,wh);  
       glutCreateWindow("Bountry-Fill-Recursive");  
 glutDisplayFunc(displayMe);
  myinit(); 
   boundaryFill4(2,wh-2,fillCol,borderCol); 
glutMouseFunc(mouse);  
 glutMainLoop();
 return 0;
}

