#include "addGlut.h"
#include <stdlib.h>
#include <iostream>
#include "GameManager.h"
#include "GlutWindow.h"
#include "Image.h"


GlutWindow win;
GameManager gameManager;
Image img;

double angulo = 0;
double x2 = 200, y2 = 200;

void reshape(int width, int height){
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	win.setWindowSize(0, width, 0, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(win.getLeft(), win.getRigth(), win.getBottom(), win.getTop(), win.getNear(), win.getFar());
	//glFrustum(win.getLeft(), win.getRigth(), win.getBottom(), win.getTop(), win.getNear(), win.getFar());
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(win.getEyeX(), win.getEyeY(), win.getEyeZ(), win.getOrigX(), win.getOrigY(), win.getOrigZ(), win.getCamX(), win.getCamY(), win.getCamZ());
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Al inicio

	glPushMatrix();
		glTranslated(x2, y2, +49);
		glScaled(100.0, 100.0, 100.0);
		glRotated(angulo, 0, 1, 0);
		glutWireCube(1);
	glPopMatrix();

	glutSwapBuffers();
}

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
			cout << "Rigth button";
			angulo++;
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

void time(int x){
	angulo++;
	glutPostRedisplay();
	glutTimerFunc(5, time, 1);
}

void begin(){
	glClearColor(0.5, 0.0, 1.0, 0.0);
	glColor3ub(255, 255, 255);//color de linea
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glShadeModel(GL_SMOOTH);//sombreado plano

}

int main(int argc, char **argv){
	//win = gameManager.getWin();
	win.setWindowSize(0, 600, 0, 600);
	win.setOrthoSize(-500, 500, -500, 500, 100,300);
	win.setCamera(0, 0, 200, 0, 0, 0, 0, 1, 0);
	win.setName("Tower Defense");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	begin();
	glEnable(GL_DEPTH_TEST); //para diferenciar que vertices estan al frente y detras ver ejemplo del documento de word

	glutDisplayFunc(display);
	glutTimerFunc(5, time, 1);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseFunc);
	glutMainLoop();
	return 0;
}