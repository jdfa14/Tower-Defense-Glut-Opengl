#pragma once
#include "addGlut.h"
#include <stack>
#include "StaticObject.h"
#include "Button.h"
#include "cData.h"


class Button : 
	public StaticObject
{
private:
	bool enable;
	bool tooltip; // if has tooltip
	int tooltipImg;

	std::string text;
	std::string tooltipMessage;
	static enum buttonState { HOVER, NORMAL, CLICK };
	buttonState state;
	int ID;
	int hover;
	int normal;
	double xMouse, yMouse;

	std::stack<int> *events;

	//controls flags for click
	bool toDo;
	void writeText(std::string text, double x, double y, void *font);
	void writeTooltip();
	
public:
	Button(std::string text);

	// sets
	void setEnable(bool enable);
	void setImages(int normal, int hover, int tooltipImg);
	void setID(int ID);
	void setEventsStack(std::stack<int> *pointer);
	void setToolTip(std::string tooltip);

	//gets
	bool isEnable();

	//edits
	void mouseState(int xMouse, int yMouse, bool isClicked);
	void action();
	void drawText();
	
};