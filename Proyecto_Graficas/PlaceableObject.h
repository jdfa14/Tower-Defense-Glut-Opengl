#pragma once
#include "addGlut.h"

class PlaceableObject
{
public:

	PlaceableObject()
	{
		setPositions(0, 0, 0);
		setSizes(100, 100, 1);
	}

	void setPositions(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void setSizes(double width, double height, double volume){
		this->height = height;
		this->width = width;
		this->volume = volume;
	}

protected:
	double x;
	double y;
	double z;
	double height;
	double width;
	double volume;
};

