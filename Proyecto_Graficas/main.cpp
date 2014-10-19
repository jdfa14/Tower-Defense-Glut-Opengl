#include "addGlut.h"
#include <stdlib.h>
#include "GameManager.h"
#include "Window.h"


Window win;
double x2 = 200, y2 = 200;

void reshape(int width, int height){
	glViewport(0, 0, width, height);
	win.setWindowSize(0, width, 0, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(win.getLeft(), win.getRigth(), win.getBottom(), win.getTop(), 10, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 0, 0, 0, -5, 0, 1, 0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Al inicio

	glPushMatrix();
		glTranslated(x2, y2, 0);
		glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glVertex2f(100, 100);
		glVertex2f(100, 0);
		glEnd();
		glPopMatrix();
	glutSwapBuffers();
}

void init(){
	glClearColor(254, 254, 254, 1);//color
	glColor3ub(200, 50, 100);//color de linea
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	default: break;
	}
}

void mouseFunc(int button, int state, int x, int y){//when user clicks
	double xMapped = win.getXMapped(x);
	double yMapped = win.getYMapped(y);
	if (state == GLUT_DOWN){
		int asdasd = 3;
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			cout << "Left button";
			x2 = xMapped;
			y2 = yMapped;
			break;
		case GLUT_MIDDLE_BUTTON:
			cout << "Middle button";
			break;
		case GLUT_RIGHT_BUTTON:
			cout << "Middle button";
			break;
		default:
			break;
		}
		cout << " pressed at ";
	}
	else{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			cout << "Left button";
			break;
		case GLUT_MIDDLE_BUTTON:
			cout << "Middle button";
			break;
		case GLUT_RIGHT_BUTTON:
			cout << "Middle button";
			break;
		default:
			break;
		}
		cout << " unpressed at ";
	}

	cout << "[" << x << ", " << y << "]" << endl;
	cout << " Mapp: " << "[" << xMapped << ", " << yMapped << "]" << endl;
}

int main(int argc, char **argv){
	win.setWindowSize(0, 500, 0, 500);
	win.setOrthoSize(0, 1000, 0, 1000);
	win.setName("Tower Defense");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(win.getWindowWidth(), win.getWindowsHeight());
	glutInitWindowPosition(50, 50);
	glutCreateWindow(win.getName().c_str());

	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseFunc);
	glutMainLoop();

	return 0;
}