#include "Globals.h"
#include "BadAgent.h"
#include "cData.h"

class Wave
{
private:

	cData *data;
	std::vector<Location> *path;
	std::vector<BadAgent> *toSpawn; // vector to put the nw moob
	std::vector<BadAgent> enemies;
	int pos; // position in enemies vector
	double timeToStart;// time to start since activated
	double timeSLM;// time since last moob spawned
	double timeTNM;// time to wait until spawn next moob

	bool finished;

public:
	Wave(cData &data, std::vector<Location> &path, double timeToStart = 3, double timeBetweenMobs = 1);

	//sets
	void setVectorToSpawn(std::vector<BadAgent> *toSpawn);
	
	//gets
	bool isReadyToSpawn();
	bool hasFinished();

	//mods
	void wait(double elapsedTimeMiliSec);// it will consume timeToStaet
	void spawn(double elapsedTimeMiliSec); // WIll consume timeSLM and then spawn
	void addMoob(int howMany, int kind = BA_TYPE_BACTERIA, int dificulty = BA_DIF_EASY, int speed = BA_MOV_NORMAL);

};
