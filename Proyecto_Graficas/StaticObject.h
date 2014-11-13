#pragma once
#include "Texture.h"
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
		image.load(imagePath);
	}

	void setPositions(double x, double y, double z){
		PlaceableObject::setPositions(x, y, z);
		image.setPositions(x, y, z);
	}

	void setSizes(double width, double height, double volume){
		PlaceableObject::setSizes(width, height, volume);
		image.setSizes(width, height, volume);
	}

	void draw(){//draw image in position override
		image.draw();
	}
protected:
	Texture image;
};

