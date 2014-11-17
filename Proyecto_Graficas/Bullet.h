#pragma once
#include "Globals.h"
#include "Mobile.h"
#include "BadAgent.h"
class Bullet : public Mobile
{
private:
	//int pos;
	//std::vector<BadAgent> *enemies;
	BadAgent *enemyToChase;
	double antiVDmg;
	double antiBDmg;
	double timeToArrive;
	double rangeOfAction;
	double xDif;
	double yDif;
	int type;
	double time;
	bool readyToDestroy;
	bool hit;

public:

	Bullet(BadAgent *toChase, double antiViral, double antiBacterial, int type = 1, double time = 3);
	Bullet& operator=(const Bullet& element);
	//get
	inline bool isReadyToDestroy(){
		return readyToDestroy;
	}

	//sets
	void setDamages(double antiViral, double antiBacterial);
	void setTimeToArrive(double timeInSeconds);
	void setSizes(double width, double height,double volume);

	void chaseHim(BadAgent *toChase);
	void update(double elapsedTimeMiliSeconds);// update positions and do magic to chase
};