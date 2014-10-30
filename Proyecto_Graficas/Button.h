#pragma once
#include "addGlut.h"
#include "StaticObject.h"
#include "Image.h"
class Button : 
	public StaticObject
{
public:

	Button(std::string text)
	{
		this->text = text;
		img.setPath("Imagenes/background.bmp");
		setPositions(0, 0, 0);
		setSizes(100, 100, 1);
	}

	~Button()
	{
	}

	void draw(){// another draw with text
		img.draw2D();
		writeText(text, x, y, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	void action(){}
private:
	std::string text;

	void writeText(std::string text, double x, double y, void *font){
		glutbitmapStr
		glColor3ub(255, 255, 255);
		glRasterPos2f((GLfloat) (x - glutBitmapLength(font,(unsigned char*)text.c_str())), (GLfloat)y);
		for (unsigned int i = 0; i < text.length(); i++) {
			glutBitmapCharacter(font, text[i]);
		}
	}
};

