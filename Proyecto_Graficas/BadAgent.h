#pragma once

#include "Globals.h"
#include "Location.h"
#include "Mobile.h"
#include "cData.h"

#define BA_STATE_NORMAL 0
#define BA_STATE_GOTHIT 1

#define BA_DIF_EASY		0
#define BA_DIF_NORMAL	1
#define BA_DIF_HARD		2

#define BA_TYPE_VIRUS			0
#define BA_TYPE_BACTERIA		1
#define BA_TYPE_BOSS_VIRUS		2
#define BA_TYPE_BOSS_BACTERIA	3

#define BA_MOV_SLOW		0
#define BA_MOV_NORMAL	1
#define BA_MOV_FAST		3

class BadAgent : public Mobile
{
private:
	double hitPoints;
	double defAntiV;// in %
	double defAntiB;// in % of reduction
	cData *data;
	
	int img;
	int state; // not necesary if you see this comment
	int waitForMultipleObjects; //:B
	bool vulnerable;//if not, you will not be able to shot him
	bool destroying;
	bool readyToDestroy;

	//Autobot...MOVE!
	bool nextStept();
	bool amICloseEnought();
	void goTo(double toX, double toY);// change direction with the same speed

	//Movement stuff for the autobot
	std::vector<Location> *path;
	int pathIndex;
	double distanceToTarget; // distance ^2

	void getReadyToFight(int type, int dificulty, int speed);

public:
	BadAgent(cData &data, std::vector<Location> &path, int type = BA_TYPE_VIRUS, int dificulty = BA_DIF_EASY, int speed = BA_MOV_SLOW);

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
	void draw();//draw himself and Hp bar

	//editions
	void addChaser();
	void chaserHasDoneHisJob();
	
};