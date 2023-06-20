#include <windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>
 // Car ride program - Kadi Al-Rwaishdi
 // You can move the car on the street clicking left & right arrow
 // You can show stars on different positions clicking 's'
 // You can change car colors clicking 'c'


float posX = 0, posY = 0;
float move_unit = 10;
float m,c,r,g,b;


void road(){
  glBegin(GL_POLYGON);
     glColor3f(0.1, 0.1, 0.0);
 glVertex2f(0, 0);
  glVertex2f(700, 0);
   glVertex2f(700, 50);
    glVertex2f(0, 50);
  glEnd();
    glEnable(GL_LINE_STIPPLE);
  glLineStipple(10,0x5555);
    glBegin(GL_LINES);
    glColor3f(0.8, 0.7, 0.0);
    glVertex2f(0, 30);
    glVertex2f(700, 30);
  glEnd();

}
//source of wheel function: https://www.youtube.com/watch?v=_RrC536eGqA
void wheel(int x, int y){
 glBegin(GL_TRIANGLE_FAN);
 glColor3f(0.3,0.3,0.3);
 for (int i=0;i<360;i++){
         float theta=i*3.142/180;

    glVertex2f(x+15*cos(theta), y+15*sin(theta));
}
glEnd();
}
void car() {
  glBegin(GL_POLYGON);
  glColor3f(r,g,b);
 glVertex2f(240, 40);
  glVertex2f(240, 70);
  glVertex2f(210, 70);
  glVertex2f(200, 100);
  glColor3f(g,b,r);
  glVertex2f(120, 100);
  glColor3f(r,b,g);
  glVertex2f(100, 70);
  glColor3f(r,g,b);
  glVertex2f(100, 40);
   glEnd();
   wheel(200,40);
   wheel(140,40);
}
void star(void){
      glBegin(GL_POLYGON);
   glColor3f(1.0, 1.0, 1.0);
     glVertex2f(m*185, m*445);
     glVertex2f(m*190, m*420);
     glVertex2f(m*195, m*445);
     glVertex2f(m*210, m*450);
     glVertex2f(m*195, m*455);
     glVertex2f(m*190, m*480);
     glVertex2f(m*185, m*455);
     glVertex2f(m*170, m*450);
   glEnd();
}

void display() {
  //Clear Window
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_QUADS);
  //Background
    glColor3f(0.0, 0.2, 0.4);
    glVertex2i(0,0);
    glColor3f(0.0, 0.2, 0.4);
    glVertex2i(500,0);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(500,500);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(0,500);
    glEnd();
       road();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity(); //transform from current position
  glPushMatrix();
  glTranslatef(posX, posY, 0.0);
  car();
  glPopMatrix();
     star();
  glFlush();
}


void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,500,0,500);
}

void keyboard(unsigned char c, int x, int y)
{
  switch (c) {
  case 's':
     m = ((float)rand() / RAND_MAX) * (1.5 - 0.1) + 0.1;    //((float)rand() / RAND_MAX) * (max - min) + min;
     break;

  case 'c':
      r = ((float)rand() / RAND_MAX) * (1.0 - 0.1) + 0.1;
      g = ((float)rand() / RAND_MAX) * (1.0 - 0.1) + 0.1;
      b = ((float)rand() / RAND_MAX) * (1.0 - 0.1) + 0.1;
      break;
  default:
      break;
  }
  glutPostRedisplay();
}

void keyboardown(int key, int x, int y)
{
  switch (key) {
  case GLUT_KEY_RIGHT:
    posX += move_unit;
    break;

  case GLUT_KEY_LEFT:
    posX -= move_unit;;
    break;

  default:
    break;
  }

  glutPostRedisplay();

}

int main(int argc, char** argv) {
  glutInit(&argc, argv);     					// initialize the toolkit
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(700, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Car ride");
  glutDisplayFunc(display);
  init();
  glutSpecialFunc(keyboardown);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;

}
