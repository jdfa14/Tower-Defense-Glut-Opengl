#pragma once
#include <iostream>
#include "Globals.h"
#include "Grid.h"
#include "Location.h"
#include "json\json.h"
#include "cData.h"
#include "wave.h"
#include "BadAgent.h"
#include "LinkedList.h"

class LevelData
{
private:
	cData *imgData;
	LinkedList<BadAgent> *toSpawn;
	std::vector<Grid> gridData;
	std::vector<Location> path;
	std::vector<Location> **pathToWalk;//the pointer of a pointer
	std::vector<Wave> waves;
	bool isLoaded;

public:
	LevelData(cData &data, LinkedList<BadAgent> &toSpawn, std::vector<Location> **pathToWalk);
	bool loadData(std::string filename, std::vector<Grid> &positionsInMap);
	std::vector<Grid> *getGridData();
	std::vector<Location> *getPathData();
	std::vector<Wave> *getWaves();
};

