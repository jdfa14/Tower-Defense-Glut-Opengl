#include "GameManager.h"

void GameManager::selectGrid(double x, double y){
	double ratioX = 750.0 / 30.0;
	double ratioY = 857.0 / 30.0;

	int gridX = (x + 500) * 30 / 750;
	int gridY = (357 - y) * 30 / 857;
	int index = gridX + gridY * 30;


	if (index < 30){
		index += 30;
	}
	if (index % 30 == 0){
		index++;
	}

	if (index > 900){
		return;
	}

	if (selectedIndexes[0] != -1){
		grids[selectedIndexes[0]].state = grids[selectedIndexes[0]].placeable ? GRD_STATE_PLACEABLE : GRD_STATE_NOTPLACEABLE;
		grids[selectedIndexes[1]].state = grids[selectedIndexes[1]].placeable ? GRD_STATE_PLACEABLE : GRD_STATE_NOTPLACEABLE;
		grids[selectedIndexes[2]].state = grids[selectedIndexes[2]].placeable ? GRD_STATE_PLACEABLE : GRD_STATE_NOTPLACEABLE;
		grids[selectedIndexes[3]].state = grids[selectedIndexes[3]].placeable ? GRD_STATE_PLACEABLE : GRD_STATE_NOTPLACEABLE;
	}
	selectedIndexes[0] = index - 31;
	selectedIndexes[1] = index - 30;
	selectedIndexes[2] = index - 1;
	selectedIndexes[3] = index;


	if (grids[selectedIndexes[0]].placeable &&
		grids[selectedIndexes[1]].placeable &&
		grids[selectedIndexes[2]].placeable &&
		grids[selectedIndexes[3]].placeable){

		grids[selectedIndexes[0]].state = GRD_STATE_SELECTED;
		grids[selectedIndexes[1]].state = GRD_STATE_SELECTED;
		grids[selectedIndexes[2]].state = GRD_STATE_SELECTED;
		grids[selectedIndexes[3]].state = GRD_STATE_SELECTED;
		canPlace = true;
	}
	else{
		grids[selectedIndexes[0]].state = GRD_STATE_NOTPLACEABLE;
		grids[selectedIndexes[1]].state = GRD_STATE_NOTPLACEABLE;
		grids[selectedIndexes[2]].state = GRD_STATE_NOTPLACEABLE;
		grids[selectedIndexes[3]].state = GRD_STATE_NOTPLACEABLE;
		canPlace = false;
	}

}