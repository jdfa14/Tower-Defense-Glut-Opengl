#include "addGlut.h"
#include <stdlib.h>
#include "GameManager.h"

void reshape(int width, int height){
}


void display(){
}

void init(){
}


void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	default: break;
	}
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Auto en movimiento");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}