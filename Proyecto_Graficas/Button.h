#pragma once
#include "StaticObject.h"
class Button : 
	public StaticObject
{
public:

	Button()
	{
	}

	~Button()
	{
	}

	void draw(){// another draw with text

	}

	void action(){}
private:
	std::string text;
};

