#pragma once

#include "Globals.h"
#include "Location.h"
#include "Mobile.h"
class BadAgent : public Mobile
{
private:
	double hitPoints;
	double defAntiV;
	double defAntiB;
	std::vector<Location> path;
	void goTo(double toX, double toY);// change direction with the same speed
	int waitForMultipleObjects;
	bool vulnerable;//if not, you will not be able to shot him
	bool destroying;
	bool readyToDestroy;

public:
	BadAgent();

	//sets
	void setDefs(double defAntiVirus, double defAntiBacterial);

	//gets
	void getPositions(double &x, double &y);
	void getSizes(double &w, double &h);
	double getHP();
	bool isReadyToDestroy();
	bool isAlive();

	void takeDamaged(double antiVDMG, double antiBDMG);//do damage and reduce life
	void update(double elapsedTimeMiliSec);// move and verify arriving to the location
	//Display
	void draw(int tex_id);//draw himself and Hp bar

	//editions
	void addChaser();
	void chaserHasDoneHisJob();
};