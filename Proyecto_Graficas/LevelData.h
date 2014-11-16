#pragma once
#include <iostream>
#include "Globals.h"
#include "Grid.h"
#include "json\json.h"
#include "cData.h"

class LevelData
{
private:
	std::vector<Grid> gridData;
	bool isLoaded;

public:
	LevelData();
	bool loadData(std::string filename);

	std::vector<Grid> *getGridData();
};

