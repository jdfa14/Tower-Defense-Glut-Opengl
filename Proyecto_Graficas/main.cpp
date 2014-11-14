#include "addGlut.h"
#include <stdlib.h>
#include <iostream>
#include "GameManager.h"
#include "GlutWindow.h"
#include "Texture.h"
#include "StaticObject.h"
#include "Button.h"
#include "Texture.h"
#include "Mobile.h"


GlutWindow *win;
GameManager gameManager;
cData Data;

Mobile mobileTest;
Mobile second;

void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 27:
		exit(1);
		break;
	default: 
		break;
	}
}

void mousePassive(int x, int y)
{
	double xMapped = win->getXMapped(x);
	double yMapped = win->getYMapped(y);
	//std::cout << "Im moving" << std::endl;
	gameManager.pasiveMouse(xMapped,yMapped);
	//test3.mouseState(xMapped, yMapped,false);
}

void mouseFunc(int button, int state, int x, int y){//when user clicks
	double xMapped = win->getXMapped(x);
	double yMapped = win->getYMapped(y);
	
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		gameManager.leftClick(xMapped, yMapped, state);
		mobileTest.setPositions(xMapped, yMapped,0);
		second.setPositions(xMapped, yMapped, 0);
		break;
	case GLUT_RIGHT_BUTTON:
		gameManager.rigthClick(xMapped, yMapped, state);
		break;
	default:
		gameManager.middleClick(xMapped, yMapped, state);
		break;
	}
}

void reshape(int width, int height){
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	win->setWindowSize(0, width, 0, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(win->getLeft(), win->getRigth(), win->getBottom(), win->getTop(), win->getNear(), win->getFar());
	//glFrustum(win->getLeft(), win->getRigth(), win->getBottom(), win->getTop(), win->getNear(), win->getFar());

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(win->getEyeX(), win->getEyeY(), win->getEyeZ(), win->getOrigX(), win->getOrigY(), win->getOrigZ(), win->getCamX(), win->getCamY(), win->getCamZ());
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Al inicio
	//real code

	gameManager.draw(glutGet(GLUT_ELAPSED_TIME));
	mobileTest.draw(Data.GetID(IMG_BGCREDITS));
	second.draw(Data.GetID(IMG_BGCREDITS));
	glutSwapBuffers();
}

void time(int x){
	glutPostRedisplay();

	gameManager.refresh(glutGet(GLUT_ELAPSED_TIME));
	mobileTest.update(glutGet(GLUT_ELAPSED_TIME));
	second.update(glutGet(GLUT_ELAPSED_TIME));
	glutTimerFunc(50, time, 1);
}

void begin(){
	gameManager.begin();
	Data.Load();
	mobileTest.setInitialSpeeds(0, 0);
	mobileTest.setAccelerations(0, -100);
	mobileTest.setMaxSpeed(30);
	second.setInitialSpeeds(0, 0);
	second.setAccelerations(-100, 0);
	second.setMaxSpeed(30);
}

int main(int argc, char **argv){
	win = gameManager.getWin();
	//Data = &gameManager.data;
	win->setWindowSize(0, 900, 0, 700);
	win->setOrthoSize(-500, 500, -500, 500, 100,300);
	win->setCamera(0, 0, 200, 0, 0, 0, 0, 1, 0);
	win->setName("Tower Defense");

	gameManager.init();// loading images, positions, sizes

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(win->getWindowWidth(), win->getWindowsHeight());
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);
	begin();
	glEnable(GL_DEPTH_TEST); //para diferenciar que vertices estan al frente y detras ver ejemplo del documento de word
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutDisplayFunc(display);
	glutTimerFunc(5, time, 1);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseFunc);
	glutPassiveMotionFunc(mousePassive);
	glutMainLoop();
	return 0;
}