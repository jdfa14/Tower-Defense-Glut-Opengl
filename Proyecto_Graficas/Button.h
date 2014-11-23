#pragma once
#include "addGlut.h"
#include <stack>
#include "StaticObject.h"
#include "Button.h"
#include "cData.h"


class Button : 
	public StaticObject
{
public:
	Button(std::string text);

	bool isEnable();

	void setEnable(bool enable);

	void setImages(int normal, int hover);

	void drawText();

	void mouseState(int xMouse, int yMouse, bool isClicked);

	void action();

	static enum buttonState {HOVER,NORMAL,CLICK};

	void setID(int ID);

	void setEventsStack(std::stack<int> *pointer);

private:
	bool enable;
	bool tooltip; // if has tooltip

	std::string text;
	std::string tooltip;
	buttonState state;
	int ID;
	int hover;
	int normal;
	
	std::stack<int> *events;

	//controls flags for click
	bool toDo;

	void writeText(std::string text, double x, double y, void *font);
};