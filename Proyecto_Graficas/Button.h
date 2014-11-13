#pragma once
#include "addGlut.h"
#include <stack>
#include "StaticObject.h"
#include "Button.h"


class Button : 
	public StaticObject
{
public:

	Button(std::string text){
		this->text = text;
		// pred values
		//image.load("Images/BotonNormal.png");
		//hover.load("Images/BotonHover.png");
		//click.load("Images/BotonPressed.png");

		setPositions(0, 0, 0);
		setSizes(glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text.c_str()) * 2, 100, 1);
		state = NORMAL;
		enable = true;
		toDo = false;
	}

	//void setImageNormal(std::string path){ image.load(path); }
	//void setImageHover(std::string path){ hover.load(path); }
	//void setImageClick(std::string path){ click.load(path); }

	std::string getText(){
		return text;
	}
	bool isEnable(){
		return enable;
	}

	void setEnable(bool enable){
		this->enable = enable;
	}

	//void draw(){// another draw with text
	//	//need to remove this switch and use pointers instead
	//	switch (state)
	//	{
	//	case Button::HOVER:
	//		hover.draw();
	//		break;
	//	case Button::NORMAL:
	//		image.draw();
	//		break;
	//	case Button::CLICK:
	//		click.draw();
	//		break;
	//	default:
	//		break;
	//	}
	//	writeText(text, x, y, GLUT_BITMAP_TIMES_ROMAN_24);
	//}

	void drawText(int normal, int hover, int pressed){
		switch (state)
		{
		case HOVER: StaticObject::drawText(hover); break;
		case CLICK: StaticObject::drawText(pressed); break;
		default: StaticObject::drawText(normal);break;
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
					toDo = true;
				}
				else
				{
					state = HOVER;
					//std::cout << "Hover \n";
					if (toDo){
						toDo = false;
						action();
					}
				}
				return;
			}
			if (toDo){
				toDo = false;
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
	bool enable;

	std::string text;
	buttonState state;
	int ID;
	
	std::stack<int> *events;

	//controls flags for click
	bool toDo;

	void writeText(std::string text, double x, double y, void *font){
		glColor3ub(255, 255, 255);
		glRasterPos2f((GLfloat)(x - glutBitmapLength(font, (unsigned char*)text.c_str())* 0.85), (GLfloat)y);
		for (unsigned int i = 0; i < text.length(); i++) {
			glutBitmapCharacter(font, text[i]);
		}
	}
};

