#pragma once
#include "addGlut.h"
#include <stack>
#include <algorithm>
#include "StaticObject.h"
#include "Button.h"
#include "cData.h"

#define BTN_TYPE_NORMAL  0
#define BTN_TYPE_LEVEL  1

class Button : 
	public StaticObject
{
private:
	bool enable;
	bool tooltip; // if has tooltip
	int tooltipImg;
	int type;
	int score;
	int progress;

	std::string text;
	std::string tooltipMessage;
	static enum buttonState { HOVER, NORMAL, CLICK };
	buttonState state;
	int ID;
	int hover;
	int normal;
	int locked;
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
	void setImages(int normal, int hover, int tooltipImg, int locked);
	void setID(int ID);
	void setEventsStack(std::stack<int> *pointer);
	void setToolTip(std::string tooltip);
	void setType(int type);
	void setScore(int score);
	void setProgress(int progress);

	//gets
	bool isEnable();

	//edits
	void mouseState(int xMouse, int yMouse, bool isClicked);
	void action();
	void drawText();
	
};