#pragma once
#include "Image.h"
#include "PlaceableObject.h"
class StaticObject :
	public PlaceableObject
{
public:

	StaticObject() : PlaceableObject()
	{
		img.setPositions(x, y, z);
		img.setSizes(height, width, volume);
	}

	~StaticObject()
	{
		//img.~Image();//Mmm... this make me think
	}

	void setImagePath(std::string imagePath){
		img.setPath(imagePath);
	}

	void setPositions(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;
		img.setPositions(x, y, z);
	}

	void setSizes(double width, double height, double volume){
		this->height = height;
		this->width = width;
		this->volume = volume;
		img.setSizes(width,height,volume);
	}

	void draw(){//draw image in position override
		img.draw2D();
	}
protected:
	Image img;
};

