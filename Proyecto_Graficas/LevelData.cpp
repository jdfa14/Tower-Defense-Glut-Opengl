#include "LevelData.h"


LevelData::LevelData(cData &imgData, LinkedList<BadAgent> &toSpawn, std::vector<Location> **pathToWalk)
{
	this->imgData = &imgData;
	this->toSpawn = &toSpawn;
	this->pathToWalk = pathToWalk;
}

bool LevelData::loadData(std::string filename, std::vector<Grid> &positionsInMap){
	int errorH;
	json::Object json;
	json::Object data;
	json::Array map;
	json::Array pPath;
	json::Array sPath;
	json::Array jWaves;

	std::string mapTile;
	std::cout << "\b\b1%";
	json = json::loadJson(filename, errorH);
	std::cout << "\b\b6%";
	if (errorH > 0){
		std::cout << "Error loading level: " << errorH << std::endl;
		return false;
	}
	
	data = json["data"];
	pPath = data["pathPrimary"];
	sPath = data["pathSecondary"];
	jWaves = data["waves"];
	std::cout << "\b\b7%";

	double cellsInRows = sqrt(positionsInMap.size());
	for (unsigned int i = 0; i < pPath.size(); i++){
		json::Array auxLoc = pPath[i];
		path.push_back(positionsInMap[(int)auxLoc[0] + (int)auxLoc[1] * cellsInRows].posXY);
	}
	std::cout << "\b\b8%";
	//loading waves

	for (unsigned int i = 0; i < jWaves.size(); i++){
		json::Object daWave = jWaves[i];
		Wave newWave(*imgData, pathToWalk, daWave["timeStart"], daWave["timeSpawn"]);
		newWave.setVectorToSpawn(toSpawn);
		newWave.addMoob(daWave["quantity"], daWave["kind"], daWave["difficulty"], daWave["speed"]);
		waves.push_back(newWave);
	}

	//loading map data
	map = data["map"];
	std::cout << "\b\b9%";
	for (unsigned int i = 0; i < map.size(); i++){
		Grid newGrid;
		mapTile = (std::string) map[i];
		if (mapTile == "x"){
			newGrid.placeable = true;
			newGrid.state = GRD_STATE_PLACEABLE;
			newGrid.img = IMG_TILE_X;
		}
		else{
			newGrid.placeable = false;
			newGrid.state = GRD_STATE_NOTPLACEABLE;
			newGrid.img = IMG_TILE_A + mapTile[0] - 'a';
		}
		newGrid.tileType = mapTile[0];
		gridData.push_back(newGrid);
	}
	return true;
}

std::vector<Grid> *LevelData::getGridData(){
	return &gridData;
}

std::vector<Location>* LevelData::getPathData(){
	return &path;
}

std::vector<Wave> * LevelData::getWaves(){
	return &waves;
}