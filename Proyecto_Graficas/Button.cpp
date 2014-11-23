#include "Button.h"

Button::Button(std::string text){
	this->text = text;
	setPositions(0, 0, 0);
	setSizes(glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text.c_str()) * 2, 100, 1);
	state = NORMAL;
	enable = true;
	toDo = false;
}

bool Button::isEnable(){
	return enable;
}

void Button::setEnable(bool enable){
	this->enable = enable;
}

void Button::setImages(int normal, int hover){
	this->normal = normal;
	this->hover = hover;
}

void Button::drawText(){
	switch (state)
	{
	case HOVER: StaticObject::drawText(hover); break;
	default: StaticObject::drawText(normal); break;
	}
	writeText(text, x, y, GLUT_BITMAP_TIMES_ROMAN_24);
}

void Button::mouseState(int xMouse, int yMouse, bool isClicked){
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
}

void Button::action(){
	if (events)
		events->push(ID);
	else
		std::cout << "No stack of events declared" << std::endl;
}

void Button::setID(int ID){
	this->ID = ID;
}

void Button::setEventsStack(std::stack<int> *pointer){
	events = pointer;
}

void Button::writeText(std::string text, double x, double y, void *font){
	glColor3ub(255, 255, 255);
	glRasterPos2f((GLfloat)(x - glutBitmapLength(font, (unsigned char*)text.c_str())* 0.85), (GLfloat)y);
	for (unsigned int i = 0; i < text.length(); i++) {
		glutBitmapCharacter(font, text[i]);
	}
}