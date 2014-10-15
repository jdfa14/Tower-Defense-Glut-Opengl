#pragma once
#include <iostream>
#include <string>
#include "addGlut.h"
class PlaceableObject
{
public:

	PlaceableObject()
	{
	}

	virtual void draw() = 0;

private:
	double x;
	double y;
	double h;
	double w;
};

