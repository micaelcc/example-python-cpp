#include <GL/glut.h>

void draw() {
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 10, 0, 10, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glColor3f(1.0, 0, 0);
  glBegin(GL_POINTS);
  glVertex2f(5, 5);
  glEnd();

  glFlush();
}

int main(int argc, char ** argv) {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Example");

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glPointSize(5);

  glutDisplayFunc(draw);

  glutMainLoop();

  return 0;
}
