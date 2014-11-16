#pragma once

#include "Globals.h"
#include "Location.h"
#include "Mobile.h"
#include "cData.h"

#define BA_STATE_NORMAL 0
#define BA_STATE_GOTHIT 1

class BadAgent : public Mobile
{
private:
	double hitPoints;
	double defAntiV;
	double defAntiB;
	cData *data;
	std::vector<Location> path;
	void goTo(double toX, double toY);// change direction with the same speed
	int type;
	int img;
	int state; // not implementated 
	int waitForMultipleObjects;
	bool vulnerable;//if not, you will not be able to shot him
	bool destroying;
	bool readyToDestroy;

public:
	BadAgent(cData &data, int type);

	//sets
	void setDefs(double defAntiVirus, double defAntiBacterial);
	void setType(int type);

	//gets
	void getPositions(double &x, double &y);
	void getSizes(double &w, double &h);
	double getHP();
	bool isReadyToDestroy();
	bool isAlive();

	void takeDamaged(double antiVDMG, double antiBDMG);//do damage and reduce life
	void update(double elapsedTimeMiliSec);// move and verify arriving to the location
	//Display
	void draw();//draw himself and Hp bar

	//editions
	void addChaser();
	void chaserHasDoneHisJob();
};