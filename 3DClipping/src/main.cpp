#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>

#include "algorithm.h"
#include "static_display.h"

using namespace std;

static GLfloat COLOR_WHITE[] = { 1.0, 1.0, 1.0, 1.0 };

void main_display() {
	static_display();
	dynamic_display();
	glFlush();
	glutSwapBuffers();
}

void init() {
	glClearColor(COLOR_WHITE[0], COLOR_WHITE[1], COLOR_WHITE[2],
			COLOR_WHITE[3]);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2.0, 2.0, -2.0, 2.0, 4.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char ** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("3D clipping");
	init();
	glutDisplayFunc(main_display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(mouse_motion);
	glutMainLoop();

	return 0;
}
