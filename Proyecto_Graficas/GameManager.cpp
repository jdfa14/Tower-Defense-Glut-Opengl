#include "GameManager.h"

GameManager::GameManager() : sellButton("Sell Tower"), upgradeButton("Upgrade Tower")
{
	showingGrid = false;
	playing = false;
	screenState = 0;
	selectedPlayer = NULL;
	selectedIndexes[0] = -1;
	selectedIndexes[1] = -1;
	selectedIndexes[2] = -1;
	selectedIndexes[3] = -1;
	selectedTower = NULL;
}

GameManager::~GameManager(){
	towers.clear();
	enemies.clear();
	for (int i = 0; i < NUMBER_OF_SCREENS; i++){
		delete hereYouAre[i];
	}
	delete hereYouAre;
}

GlutWindow* GameManager::getWin(){
	return &win;
}


