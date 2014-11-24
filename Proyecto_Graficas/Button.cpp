#include "Button.h"

Button::Button(std::string text){
	std::replace(text.begin(), text.end(), '_', ' ');
	this->text = text;
	setPositions(0, 0, 0);
	setSizes(glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text.c_str()) * 2, 100, 1);
	state = NORMAL;
	enable = true;
	toDo = false;
	xMouse = yMouse = 0;
	score = 0;
	progress = 0;
	type = BTN_TYPE_NORMAL;
}

bool Button::isEnable(){
	return enable;
}

void Button::setType(int type){
	this->type = type;
}

void Button::setScore(int score){
	this->score = score;
}

void Button::setProgress(int progress){
	this->progress = progress;
}

void Button::setEnable(bool enable){
	this->enable = enable;
}

void Button::setImages(int normal, int hover, int tooltipImg, int locked){
	this->normal = normal;
	this->hover = hover;
	this->tooltipImg = tooltipImg;
	this->locked = locked;
}

void Button::setToolTip(std::string tooltip){
	std::replace(tooltip.begin(), tooltip.end(), '_', ' ');
	this->tooltipMessage = tooltip;
	this->tooltip = true;
}

void Button::drawText(){
	if (enable){
		switch (state)
		{
		case HOVER:
		case CLICK:
			StaticObject::drawText(hover);
			if (tooltip)
				writeTooltip();
			break;
		default: StaticObject::drawText(normal); break;
		}
		writeText(text, x, y, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else{
		StaticObject::drawText(locked);
	}
}

void Button::mouseState(int xMouse, int yMouse, bool isClicked){
	if (enable){
		if (x + width / 2.0 > xMouse && xMouse > x - width / 2.0 &&
			y + height / 2.0 > yMouse && yMouse > y - height / 2.0){
			if (isClicked)
			{
				state = CLICK;
				toDo = true;
			}
			else
			{
				state = HOVER;
				if (toDo){
					toDo = false;
					action();
				}
			}
			this->xMouse = xMouse;
			this->yMouse = yMouse;
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
	std::string *auxStr;
	switch (type)
	{
	case BTN_TYPE_NORMAL:
		glRasterPos2f((GLfloat)(x - glutBitmapLength(font, (unsigned char*)text.c_str())* 0.85), (GLfloat)y);
		for (unsigned int i = 0; i < text.length(); i++) {
			glutBitmapCharacter(font, text[i]);
		}
		break;
	case BTN_TYPE_LEVEL:
		glRasterPos2f((GLfloat)x + width / 10.0, (GLfloat)y + height / 10.0);
		for (unsigned int i = 0; i < text.length(); i++) {
			glutBitmapCharacter(font, text[i]);
		}
		auxStr = new std::string(std::to_string(score));
		glRasterPos2f((GLfloat)(x - glutBitmapLength(font, (unsigned char*)auxStr->c_str())* 0.75), (GLfloat)y - 50);
		for (unsigned int i = 0; i < auxStr->length(); i++) {
			glutBitmapCharacter(font, (*auxStr)[i]);
		}
		free(auxStr);
	default:
		break;
	}
	
}

void Button::writeTooltip(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tooltipImg);
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex3i(xMouse - 200	, yMouse - 120, 0);
	glTexCoord2f(1, 0);	glVertex3i(xMouse		, yMouse - 120, 0);
	glTexCoord2f(1, 1);	glVertex3i(xMouse		, yMouse	 , 0);
	glTexCoord2f(0, 1);	glVertex3i(xMouse - 200	, yMouse	 , 0);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glColor3ub(0, 0, 0);
	double initX = xMouse - 190;
	double initY = yMouse - 15;
	glRasterPos3f((GLfloat)initX , (GLfloat)initY,1);
	for (unsigned int i = 0; i < tooltipMessage.length(); i++) {
		if (tooltipMessage[i] == '\n'){
			initY -= ( 8 +glutBitmapWidth(GLUT_BITMAP_HELVETICA_12, 'X'));
			glRasterPos3f((GLfloat)initX, (GLfloat)initY,1);
		}
		else{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, tooltipMessage[i]);
		}
	}
}