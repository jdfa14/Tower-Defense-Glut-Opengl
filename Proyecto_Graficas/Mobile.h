#pragma once
#include "Globals.h"
#include <cmath>
#include <ctgmath>
#include "cTexture.h"
#include "PlaceableObject.h"


class Mobile : public PlaceableObject
{
protected:
	double timeSinceLastTime;
	double speedX;
	double speedY;
	double acc;
	double accX;
	double accY;
	double maxSpeed;
	double actualSpeed;
	double toX;
	double toY;

	bool accelerating;
	bool turning;
	double direction;
	const double RAD_DEG = 180 / 3.1415926535;
	//display
	

public:

	Mobile();
	
	//display
	void update(double timeInMiliSec);// update the position (draw included)
	void draw(int tex_id);

	//sets
	void setInitialSpeeds(double speedX, double speedY);
	void setAccelerations(double accX, double accY);
	void setMaxSpeed(double maxSpeed);

};

