#pragma once
#include "Image.h"
#include "PlaceableObject.h"
class StaticObject :
	public PlaceableObject
{
public:

	StaticObject() : PlaceableObject()
	{
		setPositions(0, 0, 0);
		setSizes(100, 100, 1);
	}

	~StaticObject()
	{
		//img.~Image();//Mmm... this make me think
	}

	void setImagePath(std::string imagePath){
		image.setPath(imagePath);
	}

	void setPositions(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;
		image.setPositions(x, y, z);
	}

	void setSizes(double width, double height, double volume){
		this->height = height;
		this->width = width;
		this->volume = volume;
		image.setSizes(width, height, volume);
	}

	void draw(){//draw image in position override
		image.draw2D();
	}
protected:
	Image image;
};

