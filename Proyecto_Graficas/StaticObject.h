#pragma once
#include "PlaceableObject.h"
class StaticObject :
	public PlaceableObject
{
public:

	StaticObject()
	{
	}

	~StaticObject()
	{
	}

	void draw(){//draw image in position override
	}
private:
	GLuint image; // imagen del objeto estatico	
};

