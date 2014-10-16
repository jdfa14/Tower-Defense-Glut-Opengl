#include "addGlut.h"
#include <stdlib.h>
#include "GameManager.h"


void reshape(int width, int height){
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1000, 0, 1000, 15, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Al inicio
	glutSwapBuffers();
}

void init(){
}

void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	default: break;
	}
}

void mouseFunc(int button, int state, int x, int y){//when user clicks
	if (state == GLUT_DOWN){
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
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Tower Defense");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseFunc);
	glutMainLoop();
	return 0;
}