#pragma once
#include "Mobile.h"
#include "BadAgent.h"
class Bullet : public Mobile
{
private:
	BadAgent *toChase;
	double antiVDmg;
	double antiBDmg;
	double timeToArrive;

public:
	Bullet();
	Bullet(BadAgent &toChase, double antiViral, double antiBacterial);

	//sets
	void setDamages(double antiViral, double antiBacterial);
	void setTimeToArrive(double timeInSeconds);

	void chaseHim(BadAgent &toBeChased);
	void update(double elapsedTimeMiliSeconds);// update positions and do magic to chase
};