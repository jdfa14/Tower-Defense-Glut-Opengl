#pragma once
#include "addGlut.h"

class PlaceableObject
{
public:

	PlaceableObject()
	{
		setPositions(0, 0, 0);
		setSizes(1, 1, 1);
	}

	void setPositions(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void setSizes(double height, double width, double volume){
		this->height = height;
		this->width = width;
		this->volume = volume;
	}

	virtual void draw() = 0;

protected:
	double x;
	double y;
	double z;
	double height;
	double width;
	double volume;
};

