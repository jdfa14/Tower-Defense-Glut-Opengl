#pragma once
#include <iostream>
#include "Globals.h"
#include "Grid.h"
#include "Location.h"
#include "json\json.h"
#include "cData.h"

class LevelData
{
private:
	std::vector<Grid> gridData;
	std::vector<Location> path;
	bool isLoaded;

public:
	LevelData();
	bool loadData(std::string filename, std::vector<Grid> &positionsInMap);
	std::vector<Grid> *getGridData();
	std::vector<Location> *getPathData();
};

