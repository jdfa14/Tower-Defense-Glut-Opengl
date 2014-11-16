#include "LevelData.h"


LevelData::LevelData()
{
}

bool LevelData::loadData(std::string filename){
	int errorH;
	json::Object json;
	json::Object data;
	json::Array map;
	std::string mapTile;
	std::cout << "\b\b1%";
	json = json::loadJson(filename, errorH);
	std::cout << "\b\b6%";
	if (errorH > 0){
		std::cout << "Error loading level: " << errorH << std::endl;
		return false;
	}
	std::cout << "\b\b7%";
	data = json["data"];
	std::cout << "\b\b8%";
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
