#pragma once
#include "Globals.h"
#include <cmath>
#include <ctgmath>
#include "cTexture.h"
#include "PlaceableObject.h"

#define RAD_TO_DEG (180.0 / 3.141592)
#define DEG_TO_RAD (3.141592 / 180.0)


class Mobile : public PlaceableObject
{
protected:
	double speedX;
	double speedY;
	double acc; // total acc ^2
	double accX;
	double accY; 
	double maxSpeed;// max Speed ^2
	double actualSpeed; // total speed ^2
	double direction; // in Degrees
	//display
	

public:

	Mobile();
	
	//display
	void update(double elapsedTimeMiliSec);// update the position (draw included)
	void draw(int tex_id);

	//sets
	void setInitialSpeeds(double speedX, double speedY);
	void setAccelerations(double accX, double accY);
	void setMaxSpeed(double maxSpeed);
};

