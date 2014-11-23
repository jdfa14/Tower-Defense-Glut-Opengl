#pragma once
#include "Globals.h"
#include "cData.h"
#include "BadAgent.h"
#include "Wave.h"
#include "LinkedList.h"

class WavesManager
{
private:
	LinkedList<Wave> active;
	LinkedList<Wave> waiting;

	bool start;
	bool levelFinished;

public:
	WavesManager();

	void reset();//clear all vectors
	void update(double elapsedTimeMili);
	void addWave(Wave &wave);
	void nextWave();//the first waiting wave will became an active and will start to spawn enemies
	bool hasNextWave();// True if there is one or more waiting waves

	void loadLevel(LinkedList<Wave> *allWaves);
	void loadLevel(std::vector<Wave> *allWaves);
};

