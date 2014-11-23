#include "GameManager.h"

GameManager::GameManager() 
{
	
	showingGrid = false;
	playing = false;
	screenState = 0;
	selectedPlayer = NULL;
	selectedIndexes[0] = -1;
	selectedIndexes[1] = -1;
	selectedIndexes[2] = -1;
	selectedIndexes[3] = -1;
}

GlutWindow* GameManager::getWin(){
	return &win;
}

