#pragma once
#include "addGlut.h"
#include <stack>
#include "StaticObject.h"
#include "Image.h"
#include "Button.h"


class Button : 
	public StaticObject
{
public:

	Button(std::string text){
		this->text = text;
		// pred values
		image.load("Images/BotonNormal.png");
		hover.setPath("Images/BotonHover.bmp");
		click.setPath("Images/BotonPressed.bmp");

		setPositions(0, 0, 0);
		setSizes(glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text.c_str()) * 2, 100, 1);
		state = NORMAL;
		enable = true;
	}

	void setImageNormal(std::string path){ image.load(path); }
	void setImageHover(std::string path){ hover.setPath(path); }
	void setImageClick(std::string path){ click.setPath(path); }

	void setPositions(double x, double y, double z){
		StaticObject::setPositions(x, y, z);
		hover.setPositions(x, y, z);
		click.setPositions(x, y, z);
	}

	void setSizes(double width, double height, double volume){
		StaticObject::setSizes(width, height, volume);
		hover.setSizes(width, height, volume);
		click.setSizes(width, height, volume);
	}

	std::string getText(){
		return text;
	}
	bool isEnable(){
		return enable;
	}

	void setEnable(bool enable){
		this->enable = enable;
	}

	void draw(){// another draw with text
		//need to remove this switch and use pointers instead
		switch (state)
		{
		case Button::HOVER:
			hover.draw2D();
			break;
		case Button::NORMAL:
			image.draw();
			break;
		case Button::CLICK:
			click.draw2D();
			break;
		default:
			break;
		}
		writeText(text, x, y, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	void mouseState(int xMouse, int yMouse, bool isClicked){
		if (enable){
			if (x + width / 2.0 > xMouse && xMouse > x - width / 2.0 &&
				y + height / 2.0 > yMouse && yMouse > y - height / 2.0){
				if (isClicked)
				{
					state = CLICK;
					//std::cout << "Clicked \n";
					//perform action and controls pendings
					//activate flag, that will be deactivated when the action is performed
					action();
				}
				else
				{
					state = HOVER;
					//std::cout << "Hover \n";
				}
				return;
			}
			state = NORMAL;
		}
		//std::cout << "Normal \n";
	}

	void action(){
		if (events)
			events->push(ID);
		else
			std::cout << "No stack of events declared" << std::endl;
	}

	static enum buttonState
	{
		HOVER,
		NORMAL,
		CLICK
	};

	void setID(int ID){
		this->ID = ID;
	}

	void setEventsStack(std::stack<int> *pointer){
		events = pointer;
	}

private:
	

	//auxiliar images
	Image hover;
	Image click;
	bool enable;

	std::string text;
	buttonState state;
	int ID;
	
	std::stack<int> *events;

	//controls flags for click
	//bool toDo;

	void writeText(std::string text, double x, double y, void *font){
		glColor3ub(255, 255, 255);
		glRasterPos2f((GLfloat)(x - glutBitmapLength(font, (unsigned char*)text.c_str())* 0.85), (GLfloat)y);
		for (unsigned int i = 0; i < text.length(); i++) {
			glutBitmapCharacter(font, text[i]);
		}
	}
};

