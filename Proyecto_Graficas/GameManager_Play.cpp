#include "GameManager.h"

void GameManager::selectGrid(double x, double y){
	double ratioX = 750.0 / rc;
	double ratioY = 857.0 / rc;

	int gridX = (x + 500) * rc / 750;
	int gridY = (357 - y) * rc / 857;
	int index = gridX + gridY * rc;


	if (index < rc){
		index += rc;
	}
	if (index % rc == 0){
		index++;
	}

	if (index > rc * rc){
		return;
	}

	if (selectedIndexes[0] != -1){
		grids[selectedIndexes[0]].state = grids[selectedIndexes[0]].placeable ? GRD_STATE_PLACEABLE : GRD_STATE_NOTPLACEABLE;
		grids[selectedIndexes[1]].state = grids[selectedIndexes[1]].placeable ? GRD_STATE_PLACEABLE : GRD_STATE_NOTPLACEABLE;
		grids[selectedIndexes[2]].state = grids[selectedIndexes[2]].placeable ? GRD_STATE_PLACEABLE : GRD_STATE_NOTPLACEABLE;
		grids[selectedIndexes[3]].state = grids[selectedIndexes[3]].placeable ? GRD_STATE_PLACEABLE : GRD_STATE_NOTPLACEABLE;
	}
	selectedIndexes[0] = index - (rc + 1);
	selectedIndexes[1] = index - rc;
	selectedIndexes[2] = index - 1;
	selectedIndexes[3] = index;
	bool canAfford = false;
	switch (typeOfPlacingTower)
	{
	case WHITE_TOWER:
		canAfford = dnaInLevel - PRICE_TOWER_TYPE_1 > 0;
		break;
	case YELLOW_TOWER:
		canAfford = dnaInLevel - PRICE_TOWER_TYPE_2 > 0;
		break;
	case PILL_TOWER:
		canAfford = dnaInLevel - PRICE_TOWER_TYPE_3 > 0;
		break;
	}


	if (grids[selectedIndexes[0]].placeable &&
		grids[selectedIndexes[1]].placeable &&
		grids[selectedIndexes[2]].placeable &&
		grids[selectedIndexes[3]].placeable && canAfford){

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