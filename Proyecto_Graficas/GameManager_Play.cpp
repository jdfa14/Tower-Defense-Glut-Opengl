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

void GameManager::getReadyToPlay(){
	playing = true;
	wavesStarted = false;
	finished = false;
	victory = false;
	scoreInLevel = 0;
	dnaInLevel = 0;
	timeInLevel = 0;
	playerHitPoints = 100;
	dnaInLevel = 375;
	towers.clear();
	enemies.clear();
}

void GameManager::gameFinished(){
	playing = false;
	Level data = selectedPlayer->getLevel(levelSelected);
	Level newData;
	selectedTower = NULL;
	sellButton.setEnable(false);
	upgradeButton.setEnable(false);
	if (victory){// only if victory
		newData.completed = true;
		newData.score = scoreInLevel;
		newData.locked = false;

		if (!data.completed){// if the leve was not completed
			if (levelSelected < 4)// just 0 1 2 3
			selectedPlayer->unlock(levelSelected + 1);// unlock the next level
			(*selectedPlayer->getLevelButtons())[levelSelected].setEnable(true);
			(*selectedPlayer->getLevelButtons())[levelSelected].setScore(scoreInLevel);
			selectedPlayer->setNewLevelScore(levelSelected, newData);// has to be after, since this has the savePlayer included

		}
		else if (data.score < scoreInLevel){// or if was completed but a higger score has been reached
			selectedPlayer->setNewLevelScore(levelSelected, newData);
			(*selectedPlayer->getLevelButtons())[levelSelected].setScore(scoreInLevel);
		}
	}
	std::vector<Button> *levelbuttons;
	levels = selectedPlayer->getAllLevels();
	levelbuttons = selectedPlayer->getLevelButtons();
	loadScreen(LEVELSELECT);
	if (buttons->size() > 1)//delete previous buttons if the case
	for (unsigned int i = 0; i < levelbuttons->size(); i++)
		buttons->pop_back();

	for (unsigned int i = 0; i < levelbuttons->size(); i++){
		buttons->push_back((*levelbuttons)[i]);
	}
}
